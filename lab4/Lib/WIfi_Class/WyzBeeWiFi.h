/**
 * @file     WyzBeeWiFi.h
 * @version  1.0
 * @date     2014-Oct-21
 *
 *
 * @brief : This file contains function prototypes of CPP based class functions for wifi
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
#ifndef WyzBeeWiFi_h
#define WyzBeeWiFi_h

#ifdef __cplusplus
extern "C"{
#endif

#include <inttypes.h>
#include <string.h>
#include "spi.h"



typedef struct 
{
	uint8 ip_addr[4];
	uint8 gateway_ip[4];
	uint8 subnet[4];
	uint8 BSSID[6];
	uint8 SSID[32];
	int32 rssi;
	int8 channel;
	int8 security_mode;
}NetWrk_Parms;

typedef struct 
{
	uint8 ip_addr[4];
	uint8 gateway_ip[4];
	uint8 subnet[4];
	uint8 dnssrver1[4];
	uint8 dnsserver2[4];
}IP_Parms;


typedef struct {
	uint8  *p_username;
	uint8  *p_password;
	uint8  *p_headers;
	uint8  *p_data;	
} HttpRequest;

extern NetWrk_Parms nw_parms;
extern rsi_scanResponse          ScanResp; //  structure variable for the rsi_scanResponse


int16   WyzBeeWiFi_Init               (void);
int16   WyzBeeWiFi_firmwareVersion    (int8 *);
void    WyzBeeWiFi_getResponse        (rsi_uCmdRsp *cmd_resp);
int16   WyzBeeWiFi_ConnectAccessPoint (int8* ssid, const int8 *passphrase);
int16   WyzBeeWiFi_config(int8* local_ip, int8* dns_server, int8* gateway, int8* subnet);
int16   WyzBeeWiFi_setDNS(int8* dns_server1, int8* dns_server2);
int16   WyzBeeWiFi_disconnect         (void);
int16   WyzBeeWiFi_macAddress         (int8* );
int16   WyzBeeWiFi_localIP            (uint8* ip);
int16   WyzBeeWiFi_subnetMask         (uint8* subnet);
int16   WyzBeeWiFi_gatewayIP          (uint8* gateway);
int8*   WyzBeeWiFi_SSID               (void);
int16   WyzBeeWiFi_BSSID              (uint8* bssid);
uint16  WyzBeeWiFi_RSSI               (void);
int8    WyzBeeWiFi_encryptionType     (void);
int8_t  WyzBeeWiFi_ScanNetworks       (rsi_scanInfo *p_scan_resp);
uint8   WyzBeeWiFi_status             (void);
int16   WyzBeeWiFI_hostByName         (const int8* aHostname, uint8* aResult);
int16   WyzBeeWiFi_NetParms           (NetWrk_Parms *ptr_net_parms);
int16   WyzBeeWiFi_HttpPost           (int8  *p_http_url, HttpRequest  *p_http_data);
//int16   WyzBeeWiFi_HttpPost           (HttpRequest  *p_http_data);
int16   WyzBeeWiFi_HttpGet            (int8  *p_http_url, HttpRequest  *p_http_data, int8  *p_resp, uint16  resp_size);
int16   WyzBeeWiFi_SocketOpen         (uint8  mode, uint8  *p_dest_ipaddr, uint16  dest_port_nbr);
int16   WyzBeeWiFi_SocketClose        (uint16  sock_desc, uint16  dest_port_nbr);
int16   WyzBeePrepairHttpData (int8  *http_buf, uint16  http_data_size, int8  *p_http_url, HttpRequest  *p_http_req);
void    WyzBeeWiFi_getResponse(rsi_uCmdRsp *cmd_resp);
int16   WyzBeeWiFi_WireLesFwUpgrade   (void);

uint8 *rsi_wrapper_to_rsp      (uint8 *rsp, uint8 rsp_type);
rsi_uCmdRsp *rsi_parse_response(uint8 *rsp);
void   rsi_receive_data_packet (uint8 *rx_pkt_payload, uint16 pkt_length);

#ifdef __cplusplus
}
#endif

#endif  // WyzBeeWiFi_h

