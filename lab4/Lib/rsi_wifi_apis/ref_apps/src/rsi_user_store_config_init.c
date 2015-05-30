/**
 * @file       rsi_store_config_init.c
 * @version	   3.6
 * @date 	   2013-Aug-2
 *
 * Copyright(C) Redpine Signals 2013
 * All rights reserved by Redpine Signals.
 *
 * @section License
 * This program should be used on your own responsibility.
 * Redpine Signals assumes no responsibility for any losses
 * incurred by customers or third parties arising from the use of this file.
 *
 * @brief INIT STRUCT: Initializes the user store configuration structure
 * @section Description
 * This file contains function to initialize the user store configuration,and supporting API's
 * @Fuunctions defined
 * reverse_translate_channel
 * get_frequency
 * rsi_userstorecfg_init
 */



/**
 * Includes
 */
#include "rsi_global.h"
#include "rsi_app_util.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#if ENABLE_USER_STORE_CONFIGURATION
/*====================================================*/
/**
 * @fn			    void rsi_userstorecfg_init(struct sc_params_s *ptr_usercfg)
 * @brief		    Initialize the user store configuration parameters structure
 * @param[in]	    struct sc_params_s *ptr_usercfg, pointer to the sc_params_s structure
 * @param[out]	    none
 * @return		    none
 * @description
 * This function is used to initialize the user store configuration structure
 *  with the configuration provided by the user
 */

void rsi_user_store_config_init(rsi_user_store_config_t *ptr_usercfg)
{

    uint8 i = 0,j = 0;
	memset((uint8 *)ptr_usercfg,'\0',sizeof(rsi_user_store_config_t));
	ptr_usercfg->cfg_enable = USER_CFG_CFG_ENABLE;
#ifdef RSI_LITTLE_ENDIAN
	*(uint32 *)ptr_usercfg->opermode = (uint32)USER_CFG_OPERMODE;
	*(uint32 *)ptr_usercfg->feature_bit_map = (uint32)USER_CFG_FEATURE_BIT_MAP;
	*(uint32 *)ptr_usercfg->tcp_ip_feature_bit_map =(uint32)USER_CFG_TCP_IP_FEATURE_BIT_MAP;
	*(uint32 *)ptr_usercfg->custom_feature_bit_map =(uint32)USER_CFG_CUSTOM_FEATURE_BIT_MAP;
#else
	rsi_uint32_to_4bytes(ptr_usercfg->opermode, USER_CFG_OPERMODE);
	rsi_uint32_to_4bytes(ptr_usercfg->feature_bit_map, USER_CFG_FEATURE_BIT_MAP);
	rsi_uint32_to_4bytes(ptr_usercfg->tcp_ip_feature_bit_map, USER_CFG_TCP_IP_FEATURE_BIT_MAP);
	rsi_uint32_to_4bytes(ptr_usercfg->custom_feature_bit_map, USER_CFG_CUSTOM_FEATURE_BIT_MAP);
#endif
	ptr_usercfg->band =  USER_CFG_BAND;
	ptr_usercfg->NetworkType = USER_CFG_NETWORK_TYPE;
	strcpy((char *)ptr_usercfg->join_ssid,USER_CFG_JOIN_SSID);
	ptr_usercfg->uRate     =  USER_CFG_URATE;
	ptr_usercfg->uTxPower  = USER_CFG_UTX_POWER;
	ptr_usercfg->csec_mode = USER_CFG_CHANNEL_SECURITY_MODE;
#if (USER_CFG_OPERMODE == 0 ||USER_CFG_OPERMODE == 2)
	ptr_usercfg->scan_ssid_len = strlen(USER_CFG_SCAN_SSID);
	strcpy((char *)ptr_usercfg->psk,USER_CFG_PSK);
	strcpy((char *)ptr_usercfg->scan_ssid,USER_CFG_SCAN_SSID);
	ptr_usercfg->scan_cnum = USER_CFG_SCAN_CHANN_NUM;
#endif
#if(USER_CFG_TCP_STACK_USED == 1 ||USER_CFG_TCP_STACK_USED == 3 )
	ptr_usercfg->dhcp_enable = USER_CFG_DHCP_ENABLE;


	rsi_ascii_dot_address_to_4bytes((uint8 *)ptr_usercfg->ip, (int8 *)USER_CFG_IPV4_ADDRESS);
	rsi_ascii_dot_address_to_4bytes((uint8 *)ptr_usercfg->sn_mask, (int8 *)USER_CFG_SUBNETMASKV4_ADDRESS);
	rsi_ascii_dot_address_to_4bytes((uint8 *)ptr_usercfg->dgw, (int8 *)USER_CFG_GATEWAYV4_ADDRESS);
#endif
#if (USER_CFG_OPERMODE == 2)
	strcpy((char *)ptr_usercfg->eap_method,USER_CFG_EAP_METHOD);
	strcpy((char *)ptr_usercfg->inner_method,USER_CFG_INNER_METHOD);

	strcpy((char *)ptr_usercfg->user_identity,USER_CFG_USER_IDENTITY);
	strcpy((char *)ptr_usercfg->passwd,USER_CFG_PASSWORD);
#endif

#if (USER_CFG_OPERMODE == 1)
#ifdef RSI_LITTLE_ENDIAN
	*(uint16 *)ptr_usercfg->go_intent    =   USER_CFG_GO_INTENT;
#else
    rsi_uint16_to_2bytes(ptr_usercfg->go_intent,  USER_CFG_GO_INTENT);
#endif
	strcpy((char *)ptr_usercfg->device_name,USER_CFG_DEVICE_NAME);
#ifdef RSI_LITTLE_ENDIAN
   *(uint16 *)ptr_usercfg->operating_channel = USER_CFG_OPERATING_CHANNEL;
#else
    rsi_uint16_to_2bytes(ptr_usercfg->operating_channel ,USER_CFG_OPERATING_CHANNEL);
#endif
	strcpy((char *)ptr_usercfg->ssid_postfix, USER_CFG_SSID_POSTFIX);
	strcpy((char *)ptr_usercfg->psk_key, USER_CFG_PSK_KEY);
#endif
#if (USER_CFG_OPERMODE == 0 ||USER_CFG_OPERMODE == 2)
#if RSI_STORE_PMK_SUPPORT
	for(i=0 ,j=0 ; i < 64 && j < 32; i+=2,j++)
	        {
	          if(USER_CFG_PMK[i] && USER_CFG_PMK[i + 1])
	          {
	            ptr_usercfg->pmk[j]  = ((uint16 )convert_lower_case_to_upper_case(USER_CFG_PMK[i])) * 16;
	            ptr_usercfg->pmk[j] += convert_lower_case_to_upper_case(USER_CFG_PMK[i + 1]);
	          }
	          else
	          {
	              ptr_usercfg->pmk[j]=0 ;
	          }
	       }
#endif
#endif
#if (USER_CFG_OPERMODE == 6)
#ifdef RSI_LITTLE_ENDIAN
	*(uint16 *)ptr_usercfg->apconfig.dtim_period = USER_CFG_APCONFIG_DTIM_PERIOD;
	*(uint16 *)ptr_usercfg->apconfig.beacon_interval = USER_CFG_APCONFIG_BEACON_INTERVAL;
	*(uint16 *)ptr_usercfg->apconfig.channel_no = USER_CFG_APCONFIG_CHANNEL_NUM;
	*(uint16 *)ptr_usercfg->apconfig.max_sta_support =  USER_CFG_APCONFIG_MAX_STA_SUPPORT;
#else
	rsi_uint16_to_2bytes(ptr_usercfg->apconfig.dtim_period,USER_CFG_APCONFIG_DTIM_PERIOD);
	rsi_uint16_to_2bytes(ptr_usercfg->apconfig.beacon_interval,USER_CFG_APCONFIG_BEACON_INTERVAL);
	rsi_uint16_to_2bytes(ptr_usercfg->apconfig.channel_no,USER_CFG_APCONFIG_CHANNEL_NUM);
	rsi_uint16_to_2bytes(ptr_usercfg->apconfig.max_sta_support, USER_CFG_APCONFIG_MAX_STA_SUPPORT);
#endif
	strcpy((char *)ptr_usercfg->apconfig.ssid,USER_CFG_APCONFIG_SSID);
	ptr_usercfg->apconfig.security_type = USER_CFG_APCONFIG_SECURITY_TYPE;
	ptr_usercfg->apconfig.encryp_mode = USER_CFG_APCONFIG_ENCRYP_MODE;
	strcpy((char *)ptr_usercfg->apconfig.psk,USER_CFG_APCONFIG_PSK);
#endif
	rsi_ascii_mac_address_to_6bytes((uint8 *)&ptr_usercfg->module_mac, (int8 *)USER_CFG_MODULE_MAC);
#ifdef RSI_LITTLE_ENDIAN
  *(uint16 *)ptr_usercfg->antenna_select = USER_CFG_ANTENNA_SELECT;
#else
	rsi_uint16_to_2bytes(ptr_usercfg->antenna_select,USER_CFG_ANTENNA_SELECT);
#endif
#if( USER_CFG_OPERMODE == 0)
#if	RSI_STORE_WEP_KEY_SUPPORT
#ifdef RSI_LITTLE_ENDIAN
	*(uint16 *)ptr_usercfg->wep_key.index = USER_CFG_WEPKEY_INDEX;
#else
	rsi_uint16_to_2bytes(ptr_usercfg->wep_key.index,RSI_WEP_INDEX);
#endif
	strcpy((char *)ptr_usercfg->wep_key.key[0],(char *)USER_CFG_WEPKEY_KEY0);
 	strcpy((char *)ptr_usercfg->wep_key.key[1],(char *)USER_CFG_WEPKEY_KEY1);
	strcpy((char *)ptr_usercfg->wep_key.key[2],(char *)USER_CFG_WEPKEY_KEY2);
	strcpy((char *)ptr_usercfg->wep_key.key[3],(char *)USER_CFG_WEPKEY_KEY3);
#endif
#endif
#if(USER_CFG_TCP_STACK_USED == 2 ||USER_CFG_TCP_STACK_USED == 3 )

#if RSI_STORE_IPV6_ENABLE
#ifdef RSI_LITTLE_ENDIAN
	*(uint16 *)ptr_usercfg->dhcp6_enable = USER_CFG_DHCPV6_ENABLE;
	*(uint16 *)ptr_usercfg->prefix_length = USER_CFG_PREFIX_LENGTH;
#else
	rsi_uint16_to_2bytes(ptr_usercfg->dhcp6_enable,USER_CFG_DHCPV6_ENABLE);
	rsi_uint16_to_2bytes(ptr_usercfg->prefix_length,USER_CFG_PREFIX_LENGTH);
#endif
	parse_ipv6_address((uint32 *)ptr_usercfg->ip6, (uint8 *)USER_CFG_IPV6_ADDRESS);
	parse_ipv6_address((uint32 *)ptr_usercfg->dgw6, (uint8 *)USER_CFG_GATEWAYV6_ADDRESS);
#endif
#endif
	ptr_usercfg->tcp_stack_used = USER_CFG_TCP_STACK_USED;
#if (USER_CFG_OPERMODE == 0 ||USER_CFG_OPERMODE == 2)

#ifdef RSI_LITTLE_ENDIAN
	*(uint16 *)ptr_usercfg->chan_bitmap_magic_code = RSI_MAGIC_CODE;
	*(uint32 *)ptr_usercfg->scan_chan_bitmap_stored_2_4_GHz =(uint32 )USER_CFG_SCAN_CHAN_BITMAP_STORED_2_4_GHZ;
	*(uint32 *)ptr_usercfg->scan_chan_bitmap_stored_5_GHz  = (uint32 )USER_CFG_SCAN_SCAN_CHAN_BITMAP_STORED_5_GHZ;
#else
	rsi_uint16_to_2bytes(ptr_usercfg->chan_bitmap_magic_code , RSI_MAGIC_CODE);
	rsi_uint32_to_4bytes(ptr_usercfg->scan_chan_bitmap_stored_2_4_GHz ,(uint32 )USER_CFG_SCAN_CHAN_BITMAP_STORED_2_4_GHZ);
	rsi_uint32_to_4bytes(ptr_usercfg->scan_chan_bitmap_stored_5_GHz  , (uint32 )USER_CFG_SCAN_SCAN_CHAN_BITMAP_STORED_5_GHZ);

#endif
#endif

#if (USER_CFG_OPERMODE == 0 || USER_CFG_OPERMODE == 2 )
	ptr_usercfg->multi_probe =  USER_CFG_BGSCAN_MULTI_PROBE;

#ifdef RSI_LITTLE_ENDIAN
	*(uint16 *)ptr_usercfg->bgscan_magic_code = RSI_MAGIC_CODE;
	*(uint16 *)ptr_usercfg->bgscan_enable = USER_CFG_BGSCAN_ENABLE;
	*(uint16 *)ptr_usercfg->bgscan_threshold =  USER_CFG_BGSCAN_THRESHOLD;
	*(uint16 *)ptr_usercfg->rssi_tolerance_threshold =  USER_CFG_BGSCAN_RSSI_TOLERANCE_THRESHOLD;
	*(uint16 *)ptr_usercfg->bgscan_periodicity =  USER_CFG_BGSCAN_PERIODICITY;
	*(uint16 *)ptr_usercfg->active_scan_duration = USER_CFG_BGSCAN_ACTIVE_SCAN_DURATION;
	*(uint16 *)ptr_usercfg->passive_scan_duration =  USER_CFG_BGSCAN_PASSIVE_SCAN_DURATION;
#else
	rsi_uint16_to_2bytes(ptr_usercfg->bgscan_magic_code , RSI_MAGIC_CODE);
	rsi_uint16_to_2bytes(ptr_usercfg->bgscan_enable , USER_CFG_BGSCAN_ENABLE);
	rsi_uint16_to_2bytes(ptr_usercfg->bgscan_threshold ,  USER_CFG_BGSCAN_THRESHOLD);
	rsi_uint16_to_2bytes(ptr_usercfg->rssi_tolerance_threshold ,  USER_CFG_BGSCAN_RSSI_TOLERANCE_THRESHOLD);
	rsi_uint16_to_2bytes(ptr_usercfg->bgscan_periodicity ,  USER_CFG_BGSCAN_PERIODICITY);
	rsi_uint16_to_2bytes(ptr_usercfg->active_scan_duration , USER_CFG_BGSCAN_ACTIVE_SCAN_DURATION);
	rsi_uint16_to_2bytes(ptr_usercfg->passive_scan_duration ,  USER_CFG_BGSCAN_PASSIVE_SCAN_DURATION);
#endif
#endif
#if (USER_CFG_OPERMODE == 0 || USER_CFG_OPERMODE == 2)
#ifdef RSI_LITTLE_ENDIAN
	*(uint16 *)ptr_usercfg->roam_magic_code = RSI_MAGIC_CODE;
#else
	rsi_uint16_to_2bytes(ptr_usercfg->roam_magic_code , RSI_MAGIC_CODE);

#endif
#ifdef RSI_LITTLE_ENDIAN
  *(uint32 *)ptr_usercfg->roam_params_stored.roamParamsFrameSnd.roam_enable   =(uint32)USER_CFG_ROAM_ENABLE;
  *(uint32 *)ptr_usercfg->roam_params_stored.roamParamsFrameSnd.roam_threshold  = (uint32)USER_CFG_ROAM_THRESHOLD;
  *(uint32 *)ptr_usercfg->roam_params_stored.roamParamsFrameSnd.roam_hysteresis   = (uint32 )USER_CFG_ROAM_HYSTERESIS;
#else
  rsi_uint32_to_4bytes(ptr_usercfg->roam_params_stored.roamParamsFrameSnd.roam_enable, USER_CFG_ROAM_ENABLE);
  rsi_uint32_to_4bytes(ptr_usercfg->roam_params_stored.roamParamsFrameSnd.roam_threshold,  USER_CFG_ROAM_THRESHOLD);
  rsi_uint32_to_4bytes(ptr_usercfg->roam_params_stored.roamParamsFrameSnd.roam_hysteresis, USER_CFG_ROAM_HYSTERESIS);
#endif
#endif
#if(USER_CFG_OPERMODE == 0|| USER_CFG_OPERMODE == 2)
#ifdef RSI_LITTLE_ENDIAN
  *(uint16 *)ptr_usercfg->rejoin_magic_code = RSI_MAGIC_CODE;
#else
  rsi_uint16_to_2bytes(ptr_usercfg->rejoin_magic_code,RSI_MAGIC_CODE);
#endif
#ifdef RSI_LITTLE_ENDIAN
    *(uint32 *)ptr_usercfg->rejoin_param_stored.rsi_max_try = (uint32 )USER_CFG_REJOIN_MAX_RETRY_COUNT;
    *(uint32 *)ptr_usercfg->rejoin_param_stored.rsi_scan_interval  = (uint32 )USER_CFG_REJOIN_SCAN_INTERVAL;
    *(uint32 *)ptr_usercfg->rejoin_param_stored.rsi_beacon_missed_count  = (uint32 )USER_CFG_REJOIN_BEACON_MISSED_COUNT;
    *(uint32 *)ptr_usercfg->rejoin_param_stored.rsi_first_time_retry_enable  = (uint32 )USER_CFG_REJOIN_FIRST_TIME_RETRY_ENABLE;
#else
    rsi_uint32_to_4bytes(ptr_usercfg->rejoin_param_stored.rsi_max_try, USER_CFG_REJOIN_MAX_RETRY_COUNT);
    rsi_uint32_to_4bytes(ptr_usercfg->rejoin_param_stored.rsi_scan_interval, RSI_REJOIN_SCAN_INTERVAL);
    rsi_uint32_to_4bytes(ptr_usercfg->rejoin_param_stored.rsi_beacon_missed_count, USER_CFG_REJOIN_BEACON_MISSED_COUNT);
    rsi_uint32_to_4bytes(ptr_usercfg->rejoin_param_stored.rsi_first_time_retry_enable, USER_CFG_REJOIN_FIRST_TIME_RETRY_ENABLE);
#endif

#endif
    ptr_usercfg->region_request_from_host  = USER_CFG_REGION_REQUEST_FROM_HOST;
    ptr_usercfg->rsi_region_code_from_host = USER_CFG_REGION_CODE_FROM_HOST;
    ptr_usercfg->region_code               = USER_CFG_REGION_CODE;

return;
}
#endif
