/**
 * @file     WyzBeeWiFi.c
 * @version  1.0
 * @date     2014-Oct-21
 *
 *
 * @brief : This file contains C based functions for wifi
 *
 * @section Description :These functions used in application development and these will invoke the RSI API's to communicate with the WiFi module.
 *
 *
 * @section Improvements :
 *
 */


/*
 * Includes
 */
#include <WyzBeeWiFi.h>
#include <string.h>
#include <spi.h>
#include "rsi_global.h"
#include <rsi_api.h>



int conn_status      =0;
int conn_status_dhcp =0;
int static_config    =0;

NetWrk_Parms              nw_parms;
rsi_app_cb_t              rsi_app_cb;				              		 //@  structure variable to the rsi_app_cb_t.
rsi_api                  *ptrStrApi = &rsi_app_cb.rsi_strApi;   //@ ponter to the rsi_api structure.
rsi_scanResponse          ScanResp; //  structure variable for the rsi_scanResponse




/*===================================================*/
/**
 * @fn			  	 :  WyzBeeWiFi_Init()
 * @brief		     : This initializes the wifi module.
 * @param 1[in]	 : none
 * @param 2[in]	 : none
 * @param[out]	 : none
 * @return		   : 0- on success , error code - on failure
 * @description  : This initializes the WiFi module by executing commands in a sequence of order. this function should call at very first time before using any
 * 				         WiFi related APIs.
 */
int16  WyzBeeWiFi_Init()
{
	int16 retval;
	uint16 response_type = 0;
	uint8 wificonf_done = 0;
	WyzBee_spi_init();
	retval=rsi_sys_init();
	if(retval==0)
	{
		rsi_waitfor_boardready();
		rsi_select_option(RSI_HOST_BOOTUP_OPTION);
		rsi_init_struct(&rsi_app_cb.rsi_strApi);
		rsi_irq_start();
		while (1)
		{
			if ( rsi_app_cb.pkt_pending == RSI_TRUE )
			{
				{

					retval = rsi_frame_read(rsi_app_cb.read_packet_buffer);
					rsi_app_cb.uCmdRspFrame = rsi_parse_response(rsi_app_cb.read_packet_buffer);
					if (retval == 0)
					{
						response_type    	    = *(uint16 *)(rsi_app_cb.uCmdRspFrame->rspCode);
						rsi_app_cb.error_code = *(uint16 *)rsi_app_cb.uCmdRspFrame->status;

						/* Switch between type of packet received */
						switch (response_type)
						{
						case RSI_RSP_CARD_READY:
							if (!rsi_app_cb.error_code)
							{
								retval = rsi_oper_mode(&rsi_app_cb.rsi_strApi.opermode);
							}
							else
							{
								return -1;
							}
							break;
						case RSI_RSP_OPERMODE:
							/*If opermode command response is success */
							if (!rsi_app_cb.error_code)
							{
								retval = rsi_query_fw_version();
							}
							/*If opermode command fails */
							else
							{
								return -1;
							}
							break;

						case RSI_RSP_FWVERSION_QUERY:
							/*If Firmware Version query command is success */
							if (!rsi_app_cb.error_code)
							{
								/* False: Proceed with band */
								retval = rsi_band(rsi_app_cb.rsi_strApi.band);
							}
							/*If Firmware Version query command if fail*/
							else
							{
								return -1;
							}
							break;


						case RSI_RSP_BAND:
							/*If Band command response is success */
							if (!rsi_app_cb.error_code)
							{
								/*send the Init command*/
								retval = rsi_init();

							}
							/*If Band command is failed*/
							else
							{
								return -1;
							}
							break;


						case RSI_RSP_INIT:
							/*If Init command response is success */
							if (!rsi_app_cb.error_code)
							{
								memcpy(rsi_app_cb.mac_addr, rsi_app_cb.uCmdRspFrame->uCmdRspPayLoad.initResponse.macAddress, 6);
								wificonf_done=1;
							}
							/* If MAC Query Response is fail */
							else
							{
								return -1;
							}
							break;
						default:
							break;

						}
					}
				}
				if (rsi_irq_status() == RSI_FALSE)
				{
					rsi_app_cb.pkt_pending = RSI_FALSE;
					rsi_irq_enable();
				}
			}

			if (wificonf_done == 1)
			{
				break;
			}
		}
	}
	else
	{
		return -1;
	}

	return 0;
}


/*===================================================*/
/**
 * @fn					: WyzBeeWiFi_FirmwareVersion
 * @brief				: This is used to know the WiFi module's firmware.
 * @param 1[in]	: none
 * @param 2[in]	: none
 * @param[out]	:	fw_ver pointer to the buffer to hold the firmware version.
 * @return	    : errCode
 *                -2 = Command execution failure
 *                -1 = Buffer Full
 *                0  = SUCCESS
 * @description : This function will query the Firmware version  by executing the RSI command and returns pointer to the firmware version  it
 */

int16  WyzBeeWiFi_FirmwareVersion(int8 * fw_ver)
{
	uint16 retval;
	uint8 Respone_Type;
	uint8 Status;
	rsi_irq_enable();
	retval=rsi_query_fw_version();
	if(retval==0)
	{
		WyzBeeWiFi_getResponse (rsi_app_cb.uCmdRspFrame);
		Respone_Type = *(uint16 *)(rsi_app_cb.uCmdRspFrame->rspCode);
		Status       = *(uint16 *)rsi_app_cb.uCmdRspFrame->status;
		if((Respone_Type==RSI_RSP_FWVERSION_QUERY) && Status==0)
		{
			memcpy(fw_ver,rsi_app_cb.uCmdRspFrame->uCmdRspPayLoad.qryFwversionFrameRcv.fwversion,10);
		}
	}
	return Status;
}

/*===================================================*/
/**
 * @fn					: int  WyzBeeWiFi_ConnectAccessPoint(int8* ssid, const int8 *passphrase)
 * @brief				: This function is used to connect with access point in WPA/WAP2 modes and open mode
 * @param 1[in]	: ssid, pointer to the buffer which contains the ssid of the AP to connect
 * @param 2[in]	: passphrase , password of the AP to connect in WPA/WPA2 mode.
 * @param[out]	: none
 * @return			: errCode
 *              	-2 = Command execution failure
 *              	-1 = Buffer Full
 *              	 0 = SUCCESS
 * @description : This function is used to connect with access point in WPA/WPA2 mode, and on successful connection it fills the network parameters in "nw_parms" global structure.
 */
int16  WyzBeeWiFi_ConnectAccessPoint (int8* ssid, const int8 *passphrase)
{
	uint16 retval;
	uint8 Respone_Type;
	uint8 Status;

	memset(&rsi_app_cb.rsi_strApi.uJoinFrame,0,sizeof(rsi_app_cb.rsi_strApi.uJoinFrame));
	rsi_app_cb.rsi_strApi.uJoinFrame.joinFrameSnd.dataRate=RSI_DATA_RATE;
	rsi_app_cb.rsi_strApi.uJoinFrame.joinFrameSnd.powerLevel=RSI_POWER_LEVEL;
	if (passphrase != NULL) {
		strcpy((char *)rsi_app_cb.rsi_strApi.uJoinFrame.joinFrameSnd.psk,passphrase);
		rsi_app_cb.rsi_strApi.uJoinFrame.joinFrameSnd.securityType=6;
	} else {
		strcpy((char *)rsi_app_cb.rsi_strApi.uJoinFrame.joinFrameSnd.psk,"");
		rsi_app_cb.rsi_strApi.uJoinFrame.joinFrameSnd.securityType=0;
	}
	strcpy((char *) rsi_app_cb.rsi_strApi.uJoinFrame.joinFrameSnd.ssid,ssid);
	rsi_app_cb.rsi_strApi.uJoinFrame.joinFrameSnd.ssid_len=(strlen(ssid));

	rsi_irq_enable();
	retval=rsi_join(&rsi_app_cb.rsi_strApi.uJoinFrame);

	if(retval==0)
	{
		WyzBeeWiFi_getResponse (rsi_app_cb.uCmdRspFrame);
		Respone_Type = *(uint16 *)(rsi_app_cb.uCmdRspFrame->rspCode);
		Status       = *(uint16 *)rsi_app_cb.uCmdRspFrame->status;
		if((Respone_Type==RSI_RSP_JOIN) && Status==0)
		{
			conn_status=1;

			if(static_config==1)
			{
				rsi_app_cb.rsi_strApi.uIpparamFrame.ipparamFrameSnd.dhcpMode=0;
			}
			else
			{
				rsi_app_cb.rsi_strApi.uIpparamFrame.ipparamFrameSnd.dhcpMode=1;
			}
			rsi_irq_enable();
			retval=rsi_ip_param_set(&rsi_app_cb.rsi_strApi.uIpparamFrame);

			if(retval==0)
			{
				conn_status_dhcp=1;

				WyzBeeWiFi_getResponse (rsi_app_cb.uCmdRspFrame);
				Respone_Type = *(uint16 *)(rsi_app_cb.uCmdRspFrame->rspCode);
				Status       = *(uint16 *)rsi_app_cb.uCmdRspFrame->status;
				if((Respone_Type==RSI_REQ_IPPARAM_CONFIG) && Status==0)
				{
					conn_status_dhcp=1;
					memcpy(nw_parms.ip_addr,rsi_app_cb.uCmdRspFrame->uCmdRspPayLoad.ipparamFrameRcv.ipaddr,4);
					memcpy(nw_parms.subnet,rsi_app_cb.uCmdRspFrame->uCmdRspPayLoad.ipparamFrameRcv.netmask,4);
					memcpy(nw_parms.gateway_ip,rsi_app_cb.uCmdRspFrame->uCmdRspPayLoad.ipparamFrameRcv.gateway,4);
					return Status;
				}
			}
		}
		else
		{
			return Status;
		}
	}
	return Status;
}


/*===================================================*/
/**
 * @fn					: int16  WyzBeeWiFi_config(int8* local_ip, int8* dns_server, int8* gateway, int8* subnet)
 * @brief				: This function is used to configure static IP or dhcp
 * @param 1[in]	: int8* local_ip, pointer to the local ip
 * @param 2[in]	: int8* dns_server, pointer to the dns server
 * @param 3[in]	: int8* gateway, pointer to the gateway of AP
 * @param 4[in]	: int8* subnet, pointer to the subnetmask 
 * @param[out]	: none
 * @return	    : errCode
 *                -2 = Command execution failure
 *                -1 = Buffer Full
 *                 0  = SUCCESS
 * @description : This function is used to configure loal ip, gate way, subnetmak and dns server when static IP or dhcp ip is required
 */
int16  WyzBeeWiFi_config(int8* local_ip, int8* dns_server, int8* gateway, int8* subnet)
{

	uint8  Status;
	uint8  temp_gateway[4];
	uint8  temp_subnet[4] = {255, 255, 255, 1};
	
	
	temp_gateway[0] = local_ip[0];
	temp_gateway[1] = local_ip[1];
	temp_gateway[2] = local_ip[2];
	temp_gateway[3] = 1;

	memset(&rsi_app_cb.rsi_strApi.uIpparamFrame,0,sizeof(rsi_app_cb.rsi_strApi.uIpparamFrame));
	rsi_app_cb.rsi_strApi.uIpparamFrame.ipparamFrameSnd.dhcpMode=0;
	if (gateway != NULL) {
		memcpy(rsi_app_cb.rsi_strApi.uIpparamFrame.ipparamFrameSnd.gateway,gateway,4);
	} else {
		memcpy(rsi_app_cb.rsi_strApi.uIpparamFrame.ipparamFrameSnd.gateway,temp_gateway,4);
	}
	
	if (subnet != NULL) {
		memcpy(rsi_app_cb.rsi_strApi.uIpparamFrame.ipparamFrameSnd.netmask,subnet,4);
	} else {
		memcpy(rsi_app_cb.rsi_strApi.uIpparamFrame.ipparamFrameSnd.netmask,temp_subnet,4);
	}
	memcpy(rsi_app_cb.rsi_strApi.uIpparamFrame.ipparamFrameSnd.ipaddr,local_ip,4);

	static_config=1;


	return Status;
}

/*===================================================*/
/**
 * @fn			 		: int16 WyzBeeWiFi_setDNS(int8* dns_server1, int8* dns_server2)
 * @brief				: sets the DNS server
 * @param 1[in]	: int8* dns_server1, pointer to the primary DNS serevr address
 * @param 2[in]	: int8* dns_server2, pointer to the secondary DNS serevr address
 * @param[out]	:
* @return				: errCode
 *               -2 = Command execution failure
 *               -1 = Buffer Full
 *                0 = SUCCESS
 * @description : This function sets the Primary and secondary IP address of the module.
 */
int16 WyzBeeWiFi_setDNS(int8* dns_server1, int8* dns_server2)
{
	uint16 retval;
	uint8 Respone_Type;
	uint8 Status;
	memset(&rsi_app_cb.rsi_strApi.uDnsServer,0,sizeof(rsi_app_cb.rsi_strApi.uDnsServer));
	*(uint16 *)rsi_app_cb.rsi_strApi.uDnsServer.dnsServerFrameSnd.DNSMode=RSI_DNS_CFG_MODE;
	*(uint16 *)rsi_app_cb.rsi_strApi.uDnsServer.dnsServerFrameSnd.ip_version=RSI_IP_VERSION;
	memcpy(rsi_app_cb.rsi_strApi.uDnsServer.dnsServerFrameSnd.primary_dns_ip.ipv4_address,dns_server1,4);
	if (dns_server2 != NULL) {
		memcpy(rsi_app_cb.rsi_strApi.uDnsServer.dnsServerFrameSnd.secondary_dns_ip.ipv4_address,dns_server2,4);
	} else {
		memset(rsi_app_cb.rsi_strApi.uDnsServer.dnsServerFrameSnd.secondary_dns_ip.ipv4_address,0,4);
	}
	rsi_irq_enable();
	retval=rsi_dns_server(&rsi_app_cb.rsi_strApi.uDnsServer);
	if(retval==0)
	{
		WyzBeeWiFi_getResponse (rsi_app_cb.uCmdRspFrame);
		Respone_Type = *(uint16 *)(rsi_app_cb.uCmdRspFrame->rspCode);
		Status       = *(uint16 *)rsi_app_cb.uCmdRspFrame->status;
		if(Respone_Type==RSI_REQ_DNS_QRY && Status==0)
		{
			return Status;
		}
	}
	return Status;
}

/*===================================================*/
/**
 * @fn					:	int16 WyzBeeWiFi_disconnect(void)
 * @brief				:	This will disconnect the RS9113module from AP
 * @param 1[in]	: none
 * @param 2[in]	: none
 * @param[out]	: none
 * @return			: 0 success 
 * @description : This function is used to disconnect form the AP
 */
int16 WyzBeeWiFi_disconnect(void)
{
	uint16 retval;
	uint8 Respone_Type;
	uint8 Status;
	memset(&rsi_app_cb.rsi_strApi.disassoc_frame,0,sizeof(rsi_app_cb.rsi_strApi.disassoc_frame));
	*(uint16 *)rsi_app_cb.rsi_strApi.disassoc_frame.mode_flag=0;
	memset(rsi_app_cb.rsi_strApi.disassoc_frame.client_mac_addr,0,6);
	rsi_irq_enable();
	retval=rsi_disconnect(&rsi_app_cb.rsi_strApi.disassoc_frame);
	if(retval==0)
	{
		WyzBeeWiFi_getResponse (rsi_app_cb.uCmdRspFrame);
		Respone_Type = *(uint16 *)(rsi_app_cb.uCmdRspFrame->rspCode);
		Status       = *(uint16 *)rsi_app_cb.uCmdRspFrame->status;
		if(Respone_Type==RSI_RSP_DISCONNECT && Status==0)
		{
			return Status;
		}
	}
	
	return retval;
}

/*===================================================*/
/**
 * @fn					: int16 WyzBeeWiFi_macAddress(int8* mac)
 * @brief				: This function will provide the RS9113 module's MAC address
 * @param 1[in]	: uint8* mac , fills the MAC address in the input pointer
 * @param 2[in]	: none
 * @param[out]	: none
 * @return			: errCode
 *              	-2 = Command execution failure
 *              	-1 = Buffer Full
 *               	 0 = SUCCESS
 * @description : This function will provide the RS9113 module's MAC address by executing the RSI command
 */
int16 WyzBeeWiFi_macAddress(int8* mac)
{
	uint16 retval;
	uint8 Respone_Type;
	uint8 Status;

	rsi_irq_enable();
	retval=rsi_query_mac_address();
	if(retval==0)
	{
		WyzBeeWiFi_getResponse (rsi_app_cb.uCmdRspFrame);
		Respone_Type = *(uint16 *)(rsi_app_cb.uCmdRspFrame->rspCode);
		Status       = *(uint16 *)rsi_app_cb.uCmdRspFrame->status;
		if(Respone_Type==RSI_RSP_MAC_QUERY && Status==0)
		{
			memcpy(mac,rsi_app_cb.uCmdRspFrame->uCmdRspPayLoad.qryMacaddress.macAddress,6);
		}
	}
	return Status;
}

/*===================================================*/
/**
 * @fn					: int16 WyzBeeWiFi_localIP(uint8* ip)
 * @brief				: This function is get the IP address
 * @param 1[in]	: uint8* ip, pointer to the local IP
 * @param 2[in]	: none
 * @param[out]	: none
 * @return			: errCode
 *              	-2 = Command execution failure
 *              	-1 = Buffer Full
 *              	 0 = SUCCESS
 * @description : This function is get the module local IP address when it is connected to the AP
 */
int16 WyzBeeWiFi_localIP(uint8* ip)
{
	uint16 retval;
	uint8 Respone_Type;
	uint8 Status;
	if((conn_status_dhcp==1)  &&  (conn_status))
	{
		memcpy(ip,nw_parms.ip_addr,4);
	}
	else
	{
		rsi_irq_enable();
		retval=rsi_query_net_parms();
		if(retval==0)
		{
			WyzBeeWiFi_getResponse (rsi_app_cb.uCmdRspFrame);
			Respone_Type = *(uint16 *)(rsi_app_cb.uCmdRspFrame->rspCode);
			Status       = *(uint16 *)rsi_app_cb.uCmdRspFrame->status;
			if(Respone_Type==RSI_RSP_NETWORK_PARAMS && Status==0)
			{
				memcpy(ip,rsi_app_cb.uCmdRspFrame->uCmdRspPayLoad.qryNetParmsFrameRcv.ipaddr,4);
			}
		}
	}
	return Status;
}

/*===================================================*/
/**
 * @fn					: int16 WyzBeeWiFi_subnetMask(uint8* ip)
 * @brief				: This function is provide the local IP of the module which is connected to AP 
 * @param 1[in]	: uint8* subnet, pointer to the subnet
 * @param 2[in]	: none
 * @param[out]	: none
 * @return			: errCode
 *              	-2 = Command execution failure
 *              	-1 = Buffer Full
 *              	0  = SUCCESS
 * @description : This function returns the connected AP subnet
 */
int16 WyzBeeWiFi_subnetMask(uint8* subnet)
{
	uint16 retval;
	uint8 Respone_Type;
	uint8 Status;
	if((conn_status_dhcp==1)  &&  (conn_status))
	{
		memcpy(subnet,nw_parms.subnet,4);
	}
	else
	{
		rsi_irq_enable();
		retval=rsi_query_net_parms();
		if(retval==0)
		{
			WyzBeeWiFi_getResponse (rsi_app_cb.uCmdRspFrame);
			Respone_Type = *(uint16 *)(rsi_app_cb.uCmdRspFrame->rspCode);
			Status       = *(uint16 *)rsi_app_cb.uCmdRspFrame->status;
			if(Respone_Type==RSI_RSP_NETWORK_PARAMS && Status==0)
			{
				memcpy(subnet,rsi_app_cb.uCmdRspFrame->uCmdRspPayLoad.qryNetParmsFrameRcv.subnetMask,4);
			}
		}
	}
	return Status;
}

//===================================================*/
/**
 * @fn					: int16 WyzBeeWiFi_gatewayIP(uint8* gateway)
 * @brief				: This function get the connected AP gateway
 * @param 1[in]	: uint8* gateway, pointer to the gateway IP
 * @param 2[in]	: none
 * @param[out]	: none
 * @return      : errCode
 *              	-2 = Command execution failure
 *              	-1 = Buffer Full
 *              	 0 = SUCCESS
 * @description : This function returns the connected AP IP
 */
int16 WyzBeeWiFi_gatewayIP(uint8* gateway)
{
	uint16 retval;
	uint8 Respone_Type;
	uint8 Status;

	if((conn_status_dhcp==1)  &&  (conn_status))
	{
		memcpy(gateway,nw_parms.gateway_ip,4);
	}
	else
	{
		rsi_irq_enable();
		retval=rsi_query_net_parms();
		if(retval==0)
		{
			WyzBeeWiFi_getResponse (rsi_app_cb.uCmdRspFrame);
			Respone_Type = *(uint16 *)(rsi_app_cb.uCmdRspFrame->rspCode);
			Status       = *(uint16 *)rsi_app_cb.uCmdRspFrame->status;
			if(Respone_Type==RSI_RSP_NETWORK_PARAMS && Status==0)
			{
				memcpy(gateway,rsi_app_cb.uCmdRspFrame->uCmdRspPayLoad.qryNetParmsFrameRcv.gateway,4);
			}
		}
	}
	return Status;
}

/*===================================================*/
/**
 * @fn					: int8* WyzBeeWiFi_SSID()
 * @brief				: this function is used to connect RS9113 station module to the AP with the SSID
 * @param 1[in]	: none
 * @param 2[in]	: none
 * @param[out]	: none
 * @return			: errCode
 *              	-2 = Command execution failure
 *              	-1 = Buffer Full
 *              	 0 = SUCCESS
 * @description : This function will return the ssid of the connected AP 
 *	          
 */

int8* WyzBeeWiFi_SSID()
{
	uint16 retval;
	uint8 Respone_Type;
	uint8 Status;

	rsi_irq_enable();
	retval=rsi_query_net_parms();
	if(retval==0)
	{
		WyzBeeWiFi_getResponse (rsi_app_cb.uCmdRspFrame);
		Respone_Type = *(uint16 *)(rsi_app_cb.uCmdRspFrame->rspCode);
		Status       = *(uint16 *)rsi_app_cb.uCmdRspFrame->status;
		if(Respone_Type==RSI_RSP_NETWORK_PARAMS && Status==0)
		{
			return (char *)rsi_app_cb.uCmdRspFrame->uCmdRspPayLoad.qryNetParmsFrameRcv.ssid;
		}
	}
	
	return NULL;
}

/*===================================================*/
/**
 * @fn					: int16  WyzBeeWiFi_BSSID(uint8* bssid)
 * @brief				: This function is used to get AP MAC address
 * @param 1[in]	: uint8* bssid. pointer to the BSSID
 * @param 2[in]	: none
 * @param[out]	: none
 * @return			: errCode
 *              	-2 = Command execution failure
 *              	-1 = Buffer Full
 *              	 0 = SUCCESS
 * @description : This function will get the MAC address(AP MACaddress) of connected AP
 */


int16  WyzBeeWiFi_BSSID(uint8* bssid)
{
	uint16 retval;
	uint8 Respone_Type;
	uint8 Status;
	uint8 i;

	rsi_irq_enable();
	retval=rsi_query_net_parms();
	if(retval==0)
	{
		WyzBeeWiFi_getResponse (rsi_app_cb.uCmdRspFrame);
		Respone_Type = *(uint16 *)(rsi_app_cb.uCmdRspFrame->rspCode);
		Status       = *(uint16 *)rsi_app_cb.uCmdRspFrame->status;
		if(Respone_Type==RSI_RSP_NETWORK_PARAMS && Status==0)
		{
			for(i=0;i<11;i++)
			{
				//@ search for connected network in scanned list.
				if(!strcmp((int8 *)rsi_app_cb.uCmdRspFrame->uCmdRspPayLoad.qryNetParmsFrameRcv.ssid, ((int8 *)ScanResp.strScanInfo[i].ssid)))
				{
					memcpy(bssid,ScanResp.strScanInfo[i].bssid,6);
					memcpy(nw_parms.BSSID,ScanResp.strScanInfo[i].bssid,6);
					break;
				}
			}
		}
	}
	return Status;
}

/*===================================================*/
/**
 * @fn					: uint16 WyzBeeWiFi_RSSI(void)
 * @brief		   	: This function provide the AP signal strength 
 * @param 1[in]	: none
 * @param 2[in]	: none
 * @param[out]	: none
 * @return			: returns the RSSI value
 * @description : This function provide the signal strength  of AP by executing the RSIcommand
 */


uint16 WyzBeeWiFi_RSSI(void)
{
	uint16 retval;
	uint8 Respone_Type;
	uint8 Status;
	uint32 rssi;
	
	rsi_irq_enable();
	retval=rsi_query_rssi();
	if(retval==0)
	{
		WyzBeeWiFi_getResponse (rsi_app_cb.uCmdRspFrame);
		Respone_Type = *(uint16 *)(rsi_app_cb.uCmdRspFrame->rspCode);
		Status       = *(uint16 *)rsi_app_cb.uCmdRspFrame->status;
		if(Respone_Type==RSI_RSP_RSSI_QUERY && Status==0)
		{
			rssi= *(uint16 *)rsi_app_cb.uCmdRspFrame->uCmdRspPayLoad.rssiFrameRcv.rssiVal;
		}
	}
	return rssi;
}

/*===================================================*/
/**
 * @fn					: int8 WyzBeeWiFi_encryptionType(void)
 * @brief				: This function returns the security type
 * @param 1[in]	: none
 * @param 2[in]	: none
 * @param[out]	: none
* @return	      : 0 = open mode
 *                6 = Mix mode        
 * @description : This function is used to query the security type of the connected AP
 */
int8 WyzBeeWiFi_encryptionType(void)
{
	uint16 retval;
	uint8 Respone_Type;
	uint8 Status;
	uint8 encrtypt_type;

	rsi_irq_enable();
	retval=rsi_query_net_parms();
	if(retval==0)
	{
		WyzBeeWiFi_getResponse (rsi_app_cb.uCmdRspFrame);
		Respone_Type = *(uint16 *)(rsi_app_cb.uCmdRspFrame->rspCode);
		Status       = *(uint16 *)rsi_app_cb.uCmdRspFrame->status;
		if(Respone_Type==RSI_RSP_NETWORK_PARAMS && Status==0)
		{
			encrtypt_type=rsi_app_cb.uCmdRspFrame->uCmdRspPayLoad.qryNetParmsFrameRcv.sec_type;
		}
	}
	return encrtypt_type;
}

/*===================================================*/
/**
 * @fn					: int8_t WyzBeeWiFi_ScanNetworks(rsi_scanInfo *p_scan_resp)
 * @brief				: Scans the All and particular AP in the vicinity
 * @param 1[in]	: rsi_scanInfo *p_scan_resp, pointer to the scan response
 * @param 2[in]	: none
 * @param[out]	: none
 * @return			: scan count
 * @description : scans the surrounding Ap networks and return's number of scanned ap's
 */
int8_t WyzBeeWiFi_ScanNetworks(rsi_scanInfo *p_scan_resp)
{
	uint16 retval;
	uint8 Respone_Type;
	uint8 Status;
	uint8 scan_count;

	memset(&rsi_app_cb.rsi_strApi.uScanFrame,0,sizeof(rsi_app_cb.rsi_strApi.uScanFrame));
	rsi_irq_enable();
	retval=rsi_scan(&rsi_app_cb.rsi_strApi.uScanFrame);
	if(retval==0)
	{
		WyzBeeWiFi_getResponse (rsi_app_cb.uCmdRspFrame);
		Respone_Type = *(uint16 *)(rsi_app_cb.uCmdRspFrame->rspCode);
		Status       = *(uint16 *)rsi_app_cb.uCmdRspFrame->status;
		if(Respone_Type==RSI_RSP_SCAN && Status==0)
		{
			scan_count = rsi_app_cb.uCmdRspFrame->uCmdRspPayLoad.scanResponse.scanCount[0];
			memcpy(&ScanResp,&(rsi_app_cb.uCmdRspFrame->uCmdRspPayLoad.scanResponse),sizeof(rsi_app_cb.uCmdRspFrame->uCmdRspPayLoad.scanResponse));
			memcpy (p_scan_resp,
        			rsi_app_cb.uCmdRspFrame->uCmdRspPayLoad.scanResponse.strScanInfo,
              sizeof(rsi_app_cb.uCmdRspFrame->uCmdRspPayLoad.scanResponse.strScanInfo));
		}
	}
	return scan_count;
}


/*===================================================*/
/**
 * @fn					: uint8 WyzBeeWiFi_status()
 * @brief				: gives connection status
 * @param 1[in]	: none
 * @param 2[in]	: none
 * @param[out]	: none
* @return			  : 1-connected
 *                0-disconnected
 * @description : This API returns connection status of RS9113 module with AP
 */
uint8 WyzBeeWiFi_status()
{
	uint16 retval;
	uint8 Respone_Type;
	uint8 Status;
	uint16 conn_status;
	rsi_irq_enable();
	retval=rsi_query_conn_status();
	if(retval==0)
	{
		WyzBeeWiFi_getResponse (rsi_app_cb.uCmdRspFrame);
		Respone_Type = *(uint16 *)(rsi_app_cb.uCmdRspFrame->rspCode);
		Status       = *(uint16 *)rsi_app_cb.uCmdRspFrame->status;
		if(Respone_Type==RSI_RSP_CONNECTION_STATUS && Status==0)
		{
			conn_status=*(uint16 *)rsi_app_cb.uCmdRspFrame->uCmdRspPayLoad.conStatusFrameRcv.state;
		}
	}
	return conn_status;
}

/*===================================================*/
/**
 * @fn					: int16 WyzBeeWiFi_hostByName(const int8* aHostname, uint8* aResult)
 * @brief				: returns DNS IP address
 * @param 1[in]	: const int8* aHostname
 * @param 2[in]	: uint8* aResult
 * @param[out]	:
 * @return			: errCode
 *               -2 = Command execution failure
 *               -1 = Buffer Full
 *                0 = SUCCESS
 * @description : This function is returns the DNS server IP of the website
 */
int16 WyzBeeWiFi_hostByName(const int8* aHostname, uint8* aResult)
{
	uint16 retval;
	uint8 Respone_Type;
	uint8 Status;
	memset(&rsi_app_cb.rsi_strApi.uDnsQry,0,sizeof(rsi_app_cb.rsi_strApi.uDnsQry));
	memcpy(rsi_app_cb.rsi_strApi.uDnsQry.dnsQryFrameSnd.aDomainName,aHostname,strlen(aHostname));
	*(uint16 *)rsi_app_cb.rsi_strApi.uDnsQry.dnsQryFrameSnd.ip_version=4;
	*(uint16 *)rsi_app_cb.rsi_strApi.uDnsQry.dnsQryFrameSnd.uDNSServerNumber=2;
	rsi_irq_enable();
	retval=rsi_dns_query(&rsi_app_cb.rsi_strApi.uDnsQry);
	if(retval==0)
	{
		WyzBeeWiFi_getResponse (rsi_app_cb.uCmdRspFrame);
		Respone_Type = *(uint16 *)(rsi_app_cb.uCmdRspFrame->rspCode);
		Status       = *(uint16 *)rsi_app_cb.uCmdRspFrame->status;
		if(Respone_Type==RSI_REQ_DNS_QRY && Status==0)
		{
			memcpy(aResult,rsi_app_cb.uCmdRspFrame->uCmdRspPayLoad.dnsqryresponse.aIPaddr[0].ipv4_address,4);
		}
	}
	return Status;
}


/*===================================================*/
/**
 * @fn					: int16  WyzBeeWiFi_NetParms(NetWrk_Parms *ptr_net_parms)
 * @brief				: This function gives the module's IP parameters
 * @param 1[in]	: (rsi_qryNetParmsFrameRcv  *p_nw_params) , fills the network parameter in  p_nw_params
 * @param 2[in]	: none
 * @param[out]	: none
 * @return			: errCode
 *              	-2 = Command execution failure
 *              	-1 = Buffer Full
 *              	 0 = SUCCESS
 * @description : This function is used to get the currently alloted network parameters like IP, GATEWAY, SUNETMASK
 */
int16  WyzBeeWiFi_NetParms(NetWrk_Parms *ptr_net_parms)
{
	uint16 retval;
	uint8 Respone_Type;
	uint8 Status;

	rsi_irq_enable();
	retval=rsi_query_net_parms();
	if(retval==0)
	{
		WyzBeeWiFi_getResponse (rsi_app_cb.uCmdRspFrame);
		Respone_Type = *(uint16 *)(rsi_app_cb.uCmdRspFrame->rspCode);
		Status       = *(uint16 *)rsi_app_cb.uCmdRspFrame->status;
		if(Respone_Type==RSI_RSP_NETWORK_PARAMS && Status==0)
		{
			memcpy(ptr_net_parms->ip_addr,rsi_app_cb.uCmdRspFrame->uCmdRspPayLoad.qryNetParmsFrameRcv.ipaddr,4);
			memcpy(ptr_net_parms->gateway_ip,rsi_app_cb.uCmdRspFrame->uCmdRspPayLoad.qryNetParmsFrameRcv.gateway,4);
			memcpy(ptr_net_parms->subnet,rsi_app_cb.uCmdRspFrame->uCmdRspPayLoad.qryNetParmsFrameRcv.subnetMask,4);
			ptr_net_parms->channel=rsi_app_cb.uCmdRspFrame->uCmdRspPayLoad.qryNetParmsFrameRcv.Chn_no;
			strcpy((char *) ptr_net_parms->SSID,(char *)rsi_app_cb.uCmdRspFrame->uCmdRspPayLoad.qryNetParmsFrameRcv.ssid);
			ptr_net_parms->security_mode=rsi_app_cb.uCmdRspFrame->uCmdRspPayLoad.qryNetParmsFrameRcv.sec_type;
		}
	}
	return Status;
}



/*===================================================*/
/**
 * @fn					: int16 WyzBeeWiFi_SocketOpen(uint8  mode, uint8  *p_dest_ipaddr, uint16  dest_port_nbr)
 * @brief				: This function will open a socket
 * @param 1[in]	: uint8  mode, TCP/UDP socket
 * @param 2[in]	: uint8  *p_dest_ipaddr, pointer to the IP address of the server
 * @param 3[in]	: uint16  dest_port_nbr, server port number
 * @param[out]	: none
 * @return			: errCode
 *              	-2 = Command execution failure
 *              	-1 = Buffer Full
 *              	 0 = SUCCESS
 * @description : This function will open TCP/UDP based sockets to send data to the server
 */
int16 WyzBeeWiFi_SocketOpen(uint8  mode, uint8  *p_dest_ipaddr, uint16  dest_port_nbr)
{
	uint16 retval;
	uint8 Respone_Type;
	uint8 Status;

	memset(&rsi_app_cb.rsi_strApi.uSocketFrame,0,sizeof(rsi_app_cb.rsi_strApi.uSocketFrame));

	/*if(p_dest_ipaddr!=NULL)
	{
		rsi_app_cb.rsi_strApi.uSocketFrame.socketFrameSnd.destIpaddr.ipv4_address;
	}*/
	*(uint16 *)rsi_app_cb.rsi_strApi.uSocketFrame.socketFrameSnd.destSocket=dest_port_nbr;
	*(uint16 *)rsi_app_cb.rsi_strApi.uSocketFrame.socketFrameSnd.ip_version=RSI_IP_VERSION;
	*(uint16 *)rsi_app_cb.rsi_strApi.uSocketFrame.socketFrameSnd.max_count=1;
	//*(uint16 *)rsi_app_cb.rsi_strApi.uSocketFrame.socketFrameSnd.moduleSocket;
	*(uint16 *)rsi_app_cb.rsi_strApi.uSocketFrame.socketFrameSnd.socketType=mode;

	*(uint32 *)rsi_app_cb.rsi_strApi.uSocketFrame.socketFrameSnd.tos=0;

	rsi_irq_enable();
	retval=rsi_socket(&rsi_app_cb.rsi_strApi.uSocketFrame);
	if(retval==0)
	{
		WyzBeeWiFi_getResponse (rsi_app_cb.uCmdRspFrame);
		Respone_Type = *(uint16 *)(rsi_app_cb.uCmdRspFrame->rspCode);
		Status       = *(uint16 *)rsi_app_cb.uCmdRspFrame->status;
		if(Respone_Type==RSI_REQ_SOCKET_CREATE && Status==0)
		{
			return (*((uint16 *)rsi_app_cb.uCmdRspFrame->uCmdRspPayLoad.socketFrameRcv.socketDescriptor));
		}
	}
	return Status;
}

/*===================================================*/
/**
 * @fn					: int16 WyzBeeWiFi_SocketClose(uint16  sock_desc, uint16  dest_port_nbr)
 * @brief				: This function will close the socket
 * @param 1[in]	: uint16  sock_desc, socket desritor to close
 * @param 2[in]	: uint16  dest_port_nbr, port number of the socket
 * @param[out]	:none
 * @return			:errCode
 *               -2 = Command execution failure
 *               -1 = Buffer Full
 *                0 = SUCCESS
 * @description : This function closes the particular socket , based on Socket descriptor and port number to which it was bounded.
 *
*/
int16 WyzBeeWiFi_SocketClose(uint16  sock_desc, uint16  dest_port_nbr)
{
	uint16 retval;
	uint8 Respone_Type;
	uint8 Status;

	rsi_irq_enable();
	retval=rsi_socket_close(sock_desc,dest_port_nbr);
	if(retval==0)
	{
		WyzBeeWiFi_getResponse (rsi_app_cb.uCmdRspFrame);
		Respone_Type = *(uint16 *)(rsi_app_cb.uCmdRspFrame->rspCode);
		Status       = *(uint16 *)rsi_app_cb.uCmdRspFrame->status;
		if(Respone_Type==RSI_REQ_SOCKET_CLOSE && Status==0)
		{
			return Status;
		}
	}
	return Status;
}

//===================================================*/
/**
 * @fn					: int16 WyzBeeWiFi_WireLesFwUpgrade()
 * @brief				: wireless firmware upgradation
 * @param 1[in]	: none
 * @param 2[in]	: none
 * @param[out]	: none
 * @return			: errCode
 *               -2 = Command execution failure
 *               -1 = Buffer Full
 *                0 = SUCCESS
 * @description : This function is used to device firmware upgrading through wirelessly 
 */
int16 WyzBeeWiFi_WireLesFwUpgrade()
{
	uint16 retval;
	uint8 Respone_Type;
	uint8 Status;

	rsi_irq_enable();
	while(1)
	{
		if(rsi_app_cb.pkt_pending == RSI_TRUE)
		{
			WyzBeeWiFi_getResponse (rsi_app_cb.uCmdRspFrame);
			Respone_Type = *(uint16 *)(rsi_app_cb.uCmdRspFrame->rspCode);
			Status       = *(uint16 *)rsi_app_cb.uCmdRspFrame->status;
			if((Respone_Type==0x59)&&(Status==0))
			{
				retval=rsi_wireless_fwupgrade();
				if(retval==0)
				{
					break;
				}
			}
		}
	}
	return Status;
}

/*===================================================*/
/**
 * @fn					: int16 WyzBee_PrepairHttpData (int8  *http_buf, uint16  http_data_size, int8  *p_http_url, HttpRequest  *p_http_req)
 * @brief				: prepair the data to the HTTP format
 * @param 1[in]	: int8  *http_buf, pointer to the HTTP buffer
 * @param 2[in]	: uint16  http_data_size, HTTP data size
 * @param 3[in]	: int8  *p_http_url, pointer to the url link
 * @param 4[in]	: HttpRequest  *p_http_req, pointer to the HTTP request
 * @param[out]	: none
 * @return		  :	0-failer
                  success returns the http_data_length

 * @description :This function is used to pass the data as HHTP format for HTTP purpose
 */

int16 WyzBeePrepairHttpData (int8  *http_buf, uint16  http_data_size, int8  *p_http_url, HttpRequest  *p_http_req)
{
	int16  http_data_len;
	int8   host_ip[4];
	int8  *p_buf;

	if ((http_buf   == NULL) ||
      (p_http_url == NULL)) {
				
				return 0;
	}
	
	http_data_len = 0;

	//prepair user name
		if (((p_http_req != NULL)) && (p_http_req->p_username != NULL)) {
			// memcpy (http_buf + http_data_len, p_http_req->p_username, strlen((const int8 *)p_http_req->p_username));
			// http_data_len += strlen((const int8 *)p_http_req->p_username);
			 memcpy (http_buf + http_data_len, "user", 4);
			 http_data_len += 4;
		} else {
			 memcpy (http_buf + http_data_len, "user", 4);
			 http_data_len += 4;
		}
		http_buf [http_data_len++] = ',';
		
//prepair password
		 if ((p_http_req != NULL) && (p_http_req->p_password != NULL)) {
			 //memcpy (http_buf + http_data_len, p_http_req->p_password, strlen((const int8 *)p_http_req->p_password));
			 //http_data_len += strlen((const int8 *)p_http_req->p_password);
		 	 memcpy (http_buf + http_data_len, "pwd", 4);
			 http_data_len += 3;
		 } else {
			 memcpy (http_buf + http_data_len, "pwd", 4);
			 http_data_len += 3;
		 }
		 http_buf [http_data_len++] = ',';
	
	p_buf = strtok (p_http_url, ":/\0");   //http
//prepair host name
	p_buf = strtok (NULL, ":/\0");
	memcpy (http_buf + http_data_len, p_buf, strlen((const int8 *)p_buf));
	http_data_len += strlen((const int8 *)p_buf);
	http_buf [http_data_len++] = ',';		 
	
//prepaie host ip		
	WyzBeeWiFi_hostByName ((const int8 *)p_buf, (uint8 *)host_ip);
	sprintf (http_buf + http_data_len,"%d.%d.%d.%d,", host_ip[0], host_ip[1], host_ip[2], host_ip[3]);
	http_data_len = strlen ((const int8 *)http_buf);

//url 
  p_buf = strtok (NULL, "\0");   //host name
	memcpy ((http_buf + http_data_len), p_buf, strlen((const int8 *)p_buf));
	http_data_len += strlen((const int8 *)p_buf);	
	http_buf [http_data_len++] = ',';		 
	
//http header
  if ((p_http_req != NULL) && (p_http_req->p_headers != NULL)) {
			memcpy (http_buf + http_data_len, p_http_req->p_headers, strlen((const int8 *)p_http_req->p_headers));
			http_data_len += strlen((const int8 *)p_http_req->p_headers);	
	} else {
		 rsi_buildHttpExtendedHeader((uint8 *)(http_buf + http_data_len),0);
		 http_data_len = strlen ((const int8 *)http_buf);
	}
	http_buf [http_data_len++] = ',';
	
//http data
	if ((p_http_req       != NULL) &&
      (p_http_req->p_data != NULL)) {
	  memcpy (http_buf + http_data_len, p_http_req->p_data, strlen((const int8 *)p_http_req->p_data));
	  http_data_len += strlen((const int8 *)p_buf);	
	} else {
		http_buf [http_data_len++] = '?';
	}

	
	return http_data_len; 
}

/*===================================================*/
/**
 * @fn					: int16 WyzBeeWiFi_HttpPost (int8  *p_http_url, HttpRequest  *p_http_req)
 * @brief				: This function post data to server
 * @param 1[in]	: int8  *p_http_url, pointer to the url link
 * @param 2[in]	: HttpRequest  *p_http_req, pointer to the HTTP request
 * @param[out]	: none
 * @return			: errCode
 *               -2 = Command execution failure
 *               -1 = Buffer Full
 *                0 = SUCCESS
 * @description : posts the data to the particular webserver.
 */

int16 WyzBeeWiFi_HttpPost (int8  *p_http_url, HttpRequest  *p_http_req)
{
	uint16  retval;
	uint8   Respone_Type;
	uint8   Status;
	uint16  http_data_len;
	uint16	len, len_2;
	
	memset(&rsi_app_cb.rsi_strApi.uHttpPostReq,0,sizeof(rsi_app_cb.rsi_strApi.uHttpPostReq));
  if (!strncmp ((const int8 *)p_http_url, "https:", 6)) {
	  *(uint8 *)rsi_app_cb.rsi_strApi.uHttpPostReq.HttpReqFrameSnd.https_enable = 1;	//@ HTTPS enabled
	} else if (!strncmp ((const int8 *)p_http_url, "http:", 5)) {
	  *(uint8 *)rsi_app_cb.rsi_strApi.uHttpPostReq.HttpReqFrameSnd.https_enable = 0;	//@ HTTPS disable
	}	
	rsi_app_cb.rsi_strApi.uHttpPostReq.HttpReqFrameSnd.http_port=RSI_HTTP_SERVER_PORT;
	rsi_app_cb.rsi_strApi.uHttpPostReq.HttpReqFrameSnd.ip_version[0]=4;
	
	http_data_len = WyzBeePrepairHttpData ((int8 *)rsi_app_cb.rsi_strApi.uHttpPostReq.HttpReqFrameSnd.buffer,
                                 	 sizeof (rsi_app_cb.rsi_strApi.uHttpPostReq.HttpReqFrameSnd.buffer),
																	 p_http_url,
																	 p_http_req);
																	 
	rsi_irq_enable();												//@ enabling interrupt
	retval = rsi_http_post(&rsi_app_cb.rsi_strApi.uHttpPostReq);						//@ issuing post request to the RS-9113 module
	if (retval == 0)
	{
		WyzBeeWiFi_getResponse (rsi_app_cb.uCmdRspFrame);
		Respone_Type = *(uint16 *)(rsi_app_cb.uCmdRspFrame->rspCode);
		Status       = *(uint16 *)rsi_app_cb.uCmdRspFrame->status;
		if(Respone_Type==RSI_REQ_HTTP_POST && Status==0)
		{
			len	   = 0; 		//@ initial data lengths
			len_2  = 0 ;		//@ initial data length
			while (1)
			{
				rsi_irq_enable();
				len = (uint16)rsi_app_cb.uCmdRspFrame->uCmdRspPayLoad.httpFrameRcv.data_len;					//@ extract the data length from the response
				if((len_2<=2500)&&(p_http_url!=NULL))
				{
					// memcpy(data_dummy + (uint16) len_2, rsi_app_cb.uCmdRspFrame->uCmdRspPayLoad.httpFrameRcv.data, len); //@ copy received data into the local buffer
				}
				else
				{
					// return -1; // buffer over flow of twilio
				}
				len_2 = len_2 + len;
				if (rsi_app_cb.uCmdRspFrame->uCmdRspPayLoad.httpFrameRcv.more == 1)	//@ check for mode bit in the HTTP frame receive packet
				{
					break; 																//@ break if more bit is 1
				}
				else
				{
					WyzBeeWiFi_getResponse (rsi_app_cb.uCmdRspFrame);					//@ read  remaining response from the module
				}
			}
		}
		else
		{
			return Status;
		}
	}
	return Status;
}



/*===================================================*/
/**	
 * @fn					: int16  WyzBeeWiFi_HttpGet(int8  *p_http_url, HttpRequest  *p_http_req, int8  *p_resp, uint16  resp_size)
 * @brief				: This function get data from the server
 * @param 1[in]	: int8  *p_http_url, pointer to the url link
 * @param 2[in]	: HttpRequest  *p_http_req, pointer to the HTTP request
 * @param 3[in]	: int8  *p_resp, pointer to the response buffer
 * @param 4[in]	: uint16  resp_size, responce buffer size
 * @param[out]	: none
 * @return      : errCode
 *              	-2 = Command execution failure
 *              	-1 = Buffer Full
 *              	 0 = SUCCESS
 * @description : Gets the data from the particular web server 
 */
int16  WyzBeeWiFi_HttpGet(int8  *p_http_url, HttpRequest  *p_http_req, int8  *p_resp, uint16  resp_size)
{
	uint16 retval;
	uint8 Respone_Type;
	uint8 Status;
	uint16	len, len_2;
	uint16  http_data_len;
	
	memset(&rsi_app_cb.rsi_strApi.uHttpGetReq,0,sizeof(rsi_app_cb.rsi_strApi.uHttpGetReq));

	*(uint8 *)rsi_app_cb.rsi_strApi.uHttpGetReq.HttpReqFrameSnd.https_enable = RSI_HTTPS_SUPPORT;	

	rsi_app_cb.rsi_strApi.uHttpGetReq.HttpReqFrameSnd.http_port=RSI_HTTP_SERVER_PORT;
	rsi_app_cb.rsi_strApi.uHttpGetReq.HttpReqFrameSnd.ip_version[0]=4;
	
	http_data_len = WyzBeePrepairHttpData ((int8 *)rsi_app_cb.rsi_strApi.uHttpGetReq.HttpReqFrameSnd.buffer,
                                 	 sizeof (rsi_app_cb.rsi_strApi.uHttpGetReq.HttpReqFrameSnd.buffer),
																	 p_http_url,
																	 p_http_req);
																	 
	rsi_irq_enable();												//@ enabling interrupt
	retval = rsi_http_get(&rsi_app_cb.rsi_strApi.uHttpGetReq);						//@ issuing post request to the RS-9113 module
	if (retval == 0)
	{
		WyzBeeWiFi_getResponse (rsi_app_cb.uCmdRspFrame);
		Respone_Type = *(uint16 *)(rsi_app_cb.uCmdRspFrame->rspCode);
		Status       = *(uint16 *)rsi_app_cb.uCmdRspFrame->status;
		if(Respone_Type==RSI_REQ_HTTP_GET && Status==0)
		{
			len	   = 0; 		//@ initial data lengths
			len_2  = 0 ;		//@ initial data length
			while (1)
			{
				rsi_irq_enable();
				len = (uint16)rsi_app_cb.uCmdRspFrame->uCmdRspPayLoad.httpFrameRcv.data_len;					//@ extract the data length from the response
				if((len_2<=2500)&&(p_resp!=NULL))
				{
					memcpy(p_resp + (uint16) len_2, rsi_app_cb.uCmdRspFrame->uCmdRspPayLoad.httpFrameRcv.data, len); //@ copy received data into the local buffer
				}
				else
				{
					return -1; // buffer over flow of twilio
				}
				len_2 = len_2 + len;
				if (rsi_app_cb.uCmdRspFrame->uCmdRspPayLoad.httpFrameRcv.more == 1)	//@ check for mode bit in the HTTP frame receive packet
				{
					break; 																//@ break if more bit is 1
				}
				else
				{
					WyzBeeWiFi_getResponse (rsi_app_cb.uCmdRspFrame);					//@ read  remaining response from the module
				}
			}
		}
		else
		{
			return Status;
		}
	}
	return 0;
}


/*===================================================*/
/**
 * @fn					: void  WyzBeeWiFi_getResponse(rsi_uCmdRsp *cmd_resp)
 * @brief				: reads the response payload from RS9113 module
 * @param 1[in]	: rsi_uCmdRsp *cmd_resp, pointer to the command response
 * @param 2[in]	: none
 * @param[out]	: none
 * @return		  :
 * @description :This function returns the payload response from themodule
 */
void  WyzBeeWiFi_getResponse(rsi_uCmdRsp *cmd_resp)
{
	uint16  count = 0;
	while (rsi_app_cb.pkt_pending == RSI_FALSE) {
		count++;
	}
	rsi_frame_read(rsi_app_cb.read_packet_buffer); //@  read data from the module
	cmd_resp = (rsi_uCmdRsp *) rsi_parse_response(rsi_app_cb.read_packet_buffer); //@  copy parsed response to cmd_resp.
	rsi_app_cb.pkt_pending = RSI_FALSE;
	return;
}


/*=================================================*/
/**
* @fn          : rsi_uCmdRsp *rsi_parse_response(uint8 *rsp)
* @brief       : To parse the resposne received from Kernel
* @param[in]   : uint8 *rsp, response buffer pointer
* @param[out]  : none
* @return      : rsi_uCmdRsp *ptr, response pointer
* @description : This API is used to parse the recieved response. This returns the
*                 pointer which points to rsptype, status, response payload in order.
*/
rsi_uCmdRsp *rsi_parse_response(uint8 *rsp)
{
	rsi_uCmdRsp             *temp_uCmdRspPtr = NULL;
	uint8                   temp_rspCode;
	uint16                  temp_status;
	uint8                   *descPtr = rsp ;
	uint8                   *payloadPtr = rsp + RSI_FRAME_DESC_LEN;

	/* In Response received First 24 bytes are header.
	 * And then Desc and Payload of the response is present.
	 * 2nd byte of the Desc is status and 14th byte of the Desc is RspType.
	 */

	/* Retrieve response code from the received packet */
#ifdef RSI_LITTLE_ENDIAN
	temp_status = (*(uint16 *)(descPtr + RSI_STATUS_OFFSET));
	temp_rspCode = *((uint8 *)(descPtr + RSI_RSP_TYPE_OFFSET));
#else
	temp_status = (uint8)rsi_bytes2R_to_uint16(descPtr + RSI_STATUS_OFFSET);
	temp_rspCode = rsi_bytes2R_to_uint16(descPtr + RSI_RSP_TYPE_OFFSET);
#endif

	if (temp_rspCode)
	{
	}
	else
	{
		/* call data receive function */
		rsi_receive_data_packet(payloadPtr, (*(uint16 *)rsp & 0xfff));

	}
	/* this function does re arrange of the reponse
     for the responses where the response structures are padded in between */
	if (!temp_status)
	{
		rsp = rsi_wrapper_to_rsp(rsp, temp_rspCode);
	}

	/* Copy the response type and status to payloadPtr-4, payloadPtr-2
	 * locations respectively.
	 */
#ifdef RSI_LITTLE_ENDIAN
	*((uint16 *)(payloadPtr - 2)) = temp_status;
	*((uint16 *)(payloadPtr - 4)) = temp_rspCode;
#else
	rsi_uint16_to_2bytes((payloadPtr - 2), temp_status);
	rsi_uint16_to_2bytes((payloadPtr - 4), temp_rspCode);
#endif

	temp_uCmdRspPtr = (rsi_uCmdRsp *)(payloadPtr - 4);

	return temp_uCmdRspPtr;
}


/*=================================================*/
/**
* @fn          : uint8 *rsi_wrapper_to_rsp(uint8 *rsp, uint8 rsp_type)
* @brief       : To rearrange the response in response structure
* @param[in]   : uint8 *rsp, response buffer pointer
* @param[in]   : uint8 rsp_type, response type
* @param[out]  : none
* @return      : uint8 *ptr, response pointer
* @description : This API is used to rearrange the response in the response structures when
*                response bytes are shifted because of padding bytes added between the members
*                of the response structure.
*/
uint8 *rsi_wrapper_to_rsp(uint8 *rsp, uint8 rsp_type)
{
	uint8 *descPtr, *payloadPtr, *temp_payloadPtr;
	uint8 ii, scanInfo_size;
	rsi_wfdDevResponse wfdDevResp;
	rsi_scanResponse scanRsp;

	switch (rsp_type)
	{

	case RSI_RESP_WFD_DEV:
		memset(&wfdDevResp, 0, sizeof(rsi_wfdDevResponse));
		descPtr = rsp ;
		temp_payloadPtr = payloadPtr = descPtr + RSI_FRAME_DESC_LEN;
		wfdDevResp.devCount = (descPtr[0] | ((descPtr[1] & 0x0f) << 8)) / 41;
		/* 1 byte(devState) + 32 byte(devName) + 6 byte(macAddress) + 2 byte (devtype)*/

		for (ii = 0; ii < wfdDevResp.devCount; ii++)
		{
			wfdDevResp.strWfdDevInfo[ii].devState = *(payloadPtr);
			payloadPtr += 1;
			memcpy(wfdDevResp.strWfdDevInfo[ii].devName, payloadPtr, 32);
			payloadPtr += 32;
			memcpy(wfdDevResp.strWfdDevInfo[ii].macAddress, payloadPtr, 6);
			payloadPtr += 6;
			memcpy(wfdDevResp.strWfdDevInfo[ii].devtype, payloadPtr, 2);
			payloadPtr += 2;
		}
		memcpy(temp_payloadPtr, (uint8 *)&wfdDevResp, sizeof(rsi_wfdDevResponse));
		break;

#ifdef RSI_BG_SCAN_ENABLE
	case RSI_RSP_BG_SCAN:
#endif
	case RSI_RSP_SCAN:
		scanInfo_size = 46;
		/* 1 + 1 + 1 + 1 + 34 + 6 + 1 + 1 = 46 (sizeof scaninfo structure without padding bytes */
		memset(&scanRsp, 0, sizeof(rsi_scanResponse));
		descPtr = rsp;
		temp_payloadPtr = payloadPtr = descPtr + RSI_FRAME_DESC_LEN;
		scanRsp.scanCount[0] = *(payloadPtr);

		payloadPtr += 8; /* move to  (scan count + reserved bytes) */

		for (ii = 0; ii < scanRsp.scanCount[0]; ii++)
		{
			memcpy(&scanRsp.strScanInfo[ii], payloadPtr, scanInfo_size);
			payloadPtr += scanInfo_size;
		}
		memcpy(temp_payloadPtr, (uint8 *)&scanRsp, sizeof(rsi_scanResponse));
		break;
	default:
		break;
	}

	return rsp;
}

/*=================================================*/
/**
* @fn          : void rsi_receive_data_packet(uint8 *rx_pkt_payload, uint16 pkt_length)
* @brief       : To receive data packet
* @param[in]   : uint8 *rx_pkt_payload, received packet payload
* @param[in]   : uint16 pkt_length,length of the received packet
* @param[out]  : none
* @return      : none
* @description : This API is used to receive data packet from WIFI module
*/
void rsi_receive_data_packet(uint8 *rx_pkt_payload, uint16 pkt_length)
{
	rsi_app_cb.rcvd_data_pkt_count++;

}



/******************************************************************************/
/* EOF (not truncated)                                                        */
/******************************************************************************/
