/**
 * @file       rsi_config_init.c
 * @version    3.6
 * @date       2013-May-16
 *
 * Copyright(C) Redpine Signals 2013
 * All rights reserved by Redpine Signals.
 *
 * @section License
 * This program should be used on your own responsibility.
 * Redpine Signals assumes no responsibility for any losses
 * incurred by customers or third parties arising from the use of this file.
 *
 * @brief INIT STRUCT: Initializes the global parameter structure to the values in the #define statements in main.h
 *
 * @section Description
 * This file contains function to initialize the main structure which defines
 * system operation
 *
 *
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
#include "rsi_user_store_config_init.h"
#endif

#if FIPS_MODE_ENABLE
#include "rsi_fips.h"
#endif
/**
 * Global Variables
 */


/*====================================================*/
/**
 * @fn             int16 rsi_init_struct(rsi_api *ptrStrApi)
 * @brief          Initialize the global parameter structure
 * @param[in]      rsi_api *ptrStrApi, pointer to the global parameter structure
 * @param[out]     none
 * @return         status
 *                 0  = SUCCESS
 * @description	
	* This function is used to initialize the global parameter structure with parameters
 * used to configure the Wi-Fi module.
 * 
 * @prerequisite 
	* rsi_sys_init should be done successfully. 		
 */
int16 rsi_init_struct(rsi_api *ptrStrApi)
{
  uint16 i,j;
  uint8 temp[20];
	uint32 http_len = 0;
  uint8 http_feature = 0;
  /* Module Parameters */

  /* Band Parameters */
  ptrStrApi->band     = RSI_BAND;


  /* User store config init */
#if ENABLE_USER_STORE_CONFIGURATION
  rsi_user_store_config_init(&(ptrStrApi->userstorecfg));
#endif

  /* Debug params */
#ifdef RSI_LITTLE_ENDIAN
  ptrStrApi->uDebugFrame.debugFrameSnd.assertion_type = (uint32)RSI_DEBUG_ASSERTION_TYPE;
  ptrStrApi->uDebugFrame.debugFrameSnd.assertion_level = (uint32)RSI_DEBUG_ASSERTION_LEVEL;
#else
  rsi_uint32_to_4bytes(ptrStrApi->uDebugFrame.debugFrameSnd.assertion_type, RSI_DEBUG_ASSERTION_TYPE);
  rsi_uint32_to_4bytes(ptrStrApi->uDebugFrame.debugFrameSnd.assertion_level, RSI_DEBUG_ASSERTION_LEVEL);
#endif

  /* operating mode parameters */
#ifdef RSI_LITTLE_ENDIAN
  ptrStrApi->opermode.operModeFrameSnd.oper_mode = (uint32)RSI_OPERMODE;
  ptrStrApi->opermode.operModeFrameSnd.feature_bit_map = (uint32)RSI_FEATURE_BIT_MAP;
  ptrStrApi->opermode.operModeFrameSnd.tcp_ip_feature_bit_map = (uint32)RSI_TCP_IP_FEATURE_BIT_MAP;
  ptrStrApi->opermode.operModeFrameSnd.custom_feature_bit_map = (uint32)RSI_CUSTOM_FEATURE_BIT_MAP;
#else
  rsi_uint32_to_4bytes(ptrStrApi->opermode.operModeFrameSnd.oper_mode, RSI_OPERMODE);
  rsi_uint32_to_4bytes(ptrStrApi->opermode.operModeFrameSnd.feature_bit_map, RSI_FEATURE_BIT_MAP);
  rsi_uint32_to_4bytes(ptrStrApi->opermode.operModeFrameSnd.tcp_ip_feature_bit_map, RSI_TCP_IP_FEATURE_BIT_MAP);
  rsi_uint32_to_4bytes(ptrStrApi->opermode.operModeFrameSnd.custom_feature_bit_map, RSI_CUSTOM_FEATURE_BIT_MAP);
#endif

  //! FIPS
#ifdef RSI_LITTLE_ENDIAN
  *(uint32 *)ptrStrApi->uFipsmode.fipsModeFrameSnd.fips_mode_enable = (uint32)FIPS_MODE_ENABLE;
#else
  rsi_uint32_to_4bytes(ptrStrApi->uFipsmode.fipsModeFrameSnd.fips_mode_enable, FIPS_MODE_ENABLE);
#endif

  ptrStrApi->antSel   = RSI_ANTENNA;

  /* Module IP Parameters */
  rsi_ascii_dot_address_to_4bytes((uint8 *)&ptrStrApi->uIpparamFrame.ipparamFrameSnd.ipaddr, (int8 *)	RSI_MODULE_IP_ADDRESS);
  rsi_ascii_dot_address_to_4bytes((uint8 *)&ptrStrApi->uIpparamFrame.ipparamFrameSnd.netmask, (int8 *)	RSI_NETMASK);
  rsi_ascii_dot_address_to_4bytes((uint8 *)&ptrStrApi->uIpparamFrame.ipparamFrameSnd.gateway, (int8 *)	RSI_GATEWAY);
  ptrStrApi->uIpparamFrame.ipparamFrameSnd.dhcpMode = RSI_IP_CFG_MODE;
  strcpy((char *)ptrStrApi->uIpparamFrame.ipparamFrameSnd.hostname,RSI_DHCP_HOST_NAME);


  /* IPV6 Parameters */
  *(uint16 *)ptrStrApi->uIpconf6Frame.ipconf6FrameSnd.mode = (uint16)RSI_IPV6_CFG_MODE;
  *(uint16 *)ptrStrApi->uIpconf6Frame.ipconf6FrameSnd.prefixLength = (uint16)RSI_IPV6_PREFIX_LENGTH;
  parse_ipv6_address(ptrStrApi->uIpconf6Frame.ipconf6FrameSnd.ipaddr6, (uint8 *)RSI_MODULE_IPV6_ADDRESS);
  parse_ipv6_address(ptrStrApi->uIpconf6Frame.ipconf6FrameSnd.gateway6, (uint8 *)RSI_DEFAULT_ROUTER_IPV6_ADDRESS);

  /*Set region parameters*/
#if SET_REGION_SUPPORT
  ptrStrApi->SetRegion.setRegionFrameSnd.setregion_code_from_user_cmd = SET_REGION_FROM_USER_OR_BEACON;
  ptrStrApi->SetRegion.setRegionFrameSnd.region_code				  = REGION_CODE;
#endif

  /*Set region in AP mode*/
#if SET_REGION_AP_SUPPORT
  ptrStrApi->SetRegionAp.setRegionApFrameSnd.setregion_code_from_user_cmd = SET_REGION_AP_FROM_USER;
  strcpy((char *)ptrStrApi->SetRegionAp.setRegionApFrameSnd.country_code,RSI_COUNTRY_CODE);
#if SET_REGION_AP_FROM_USER
  extract_setregionap_country_info(&ptrStrApi->SetRegionAp);
#endif
#endif

  /* Roaming parameters */
#if RSI_ROAMING_SUPPORT
#ifdef RSI_LITTLE_ENDIAN
  *(uint32 *)ptrStrApi->uRoamParams.roamParamsFrameSnd.roam_enable   = RSI_ROAMING_SUPPORT;
  *(uint32 *)ptrStrApi->uRoamParams.roamParamsFrameSnd.roam_threshold   = RSI_ROAMING_THRESHOLD;
  *(uint32 *)ptrStrApi->uRoamParams.roamParamsFrameSnd.roam_hysteresis   = RSI_ROAMING_HYSTERISIS;
#else
  rsi_uint32_to_4bytes(ptrStrApi->uRoamParams.roamParamsFrameSnd.roam_enable, RSI_ROAMING_SUPPORT);
  rsi_uint32_to_4bytes(ptrStrApi->uRoamParams.roamParamsFrameSnd.roam_threshold,  RSI_ROAMING_THRESHOLD);
  rsi_uint32_to_4bytes(ptrStrApi->uRoamParams.roamParamsFrameSnd.roam_hysteresis, RSI_ROAMING_HYSTERISIS);
#endif
#endif

  /* HT CAPS parameters*/
#if AP_MODE
#ifdef RSI_LITTLE_ENDIAN
  *(uint16 *)ptrStrApi->uHtCaps.htCapsFrameSnd.mode_11n_enable = RSI_MODE_11N_ENABLE;
  *(uint16 *)ptrStrApi->uHtCaps.htCapsFrameSnd.ht_caps_bitmap = RSI_HT_CAPS_BIT_MAP;
#else
  rsi_uint16_to_2bytes(ptrStrApi->uHtCaps.htCapsFrameSnd.mode_11n_enable ,RSI_MODE_11N_ENABLE);
  rsi_uint16_to_2bytes(ptrStrApi->uHtCaps.htCapsFrameSnd.ht_caps_bitmap ,RSI_HT_CAPS_BIT_MAP);
#endif
#endif

  /* WMM PS parameters*/ 
#if RSI_WMM_PS_SUPPORT
  ptrStrApi->uWmmPs.wmmPsFrameSnd.wmm_ps_uapsd_bitmap = RSI_WMM_PS_UAPSD_BITMAP;
#ifdef RSI_LITTLE_ENDIAN
  *(uint16 *)ptrStrApi->uWmmPs.wmmPsFrameSnd.wmm_ps_enable = RSI_WMM_PS_SUPPORT;
  *(uint16 *)ptrStrApi->uWmmPs.wmmPsFrameSnd.wmm_ps_type   = RSI_WMM_PS_TYPE;
  *(uint32 *)ptrStrApi->uWmmPs.wmmPsFrameSnd.wmm_ps_wakeup_interval = RSI_WMM_PS_WAKEUP_INTERVAL;
#else
  rsi_uint16_to_2bytes(ptrStrApi->uWmmPs.wmmPsFrameSnd.wmmPsFrameSnd.wmm_ps_enable, RSI_WMM_PS_SUPPORT);
  rsi_uint16_to_2bytes(ptrStrApi->uWmmPs.wmmPsFrameSnd.wmmPsFrameSnd.wmm_ps_type, RSI_WMM_PS_TYPE);
  rsi_uint32_to_4bytes(ptrStrApi->uWmmPs.wmmPsFrameSnd.wmm_ps_wakeup_interval, RSI_WMM_PS_WAKEUP_INTERVAL);
#endif
#endif

  /* WPS METHOD */
#if RSI_WPS_SUPPORT
#ifdef RSI_LITTLE_ENDIAN
  *(uint16 *)ptrStrApi->uWpsMethod.wpsMethodFrameSnd.wps_method = RSI_WPS_METHOD;
  *(uint16 *)ptrStrApi->uWpsMethod.wpsMethodFrameSnd.generate_pin = RSI_GENERATE_PIN;
#else
  rsi_uint16_to_2bytes(ptrStrApi->uWpsMethod.wpsMethodFrameSnd.wps_method ,RSI_WPS_METHOD);
  rsi_uint16_to_2bytes(ptrStrApi->uWpsMethod.wpsMethodFrameSnd.generate_pin ,RSI_GENERATE_PIN);
#endif
  memcpy((char *)ptrStrApi->uWpsMethod.wpsMethodFrameSnd.wps_pin , RSI_WPS_PIN, sizeof(RSI_WPS_PIN));
#endif


#if RSI_MULTICAST_SUPPORT
#ifdef RSI_LITTLE_ENDIAN
  *(uint16 *)ptrStrApi->uMulticastFrame.multicastFrameSnd.ip_version = RSI_IP_VERSION;
  *(uint16 *)ptrStrApi->uMulticastFrame.multicastFrameSnd.req_Type   = RSI_MULTICAST_MESSAGE_TYPE;
#else
  rsi_uint16_to_2bytes(ptrStrApi->uMulticastFrame.multicastFrameSnd.ip_version, RSI_IP_VERSION);
  rsi_uint16_to_2bytes(ptrStrApi->uMulticastFrame.multicastFrameSnd.req_Type, RSI_MULTICAST_MESSAGE_TYPE);
#endif
  if(*(uint16 *)ptrStrApi->uMulticastFrame.multicastFrameSnd.ip_version == IP_VERSION_4)
  {
    rsi_ascii_dot_address_to_4bytes((uint8 *)ptrStrApi->uMulticastFrame.multicastFrameSnd.group_address.ipv4_address, (int8 *)RSI_MULTICAST_GROUP_IPV4_ADDRESS);
  }
  else
  {
    parse_ipv6_address(ptrStrApi->uMulticastFrame.multicastFrameSnd.group_address.ipv6_address, (uint8 *)RSI_MULTICAST_GROUP_IPV6_ADDRESS);
  }
#endif

  /* PER MODE*/
#if RSI_PER_MODE_SUPPORT
#ifdef RSI_LITTLE_ENDIAN
  *(uint16 *)ptrStrApi->uPerMode.perModeFrameSnd.per_mode_enable = RSI_PER_MODE_SUPPORT;
  *(uint16 *)ptrStrApi->uPerMode.perModeFrameSnd.power = RSI_PER_MODE_POWER;
  *(uint32 *)ptrStrApi->uPerMode.perModeFrameSnd.rate = RSI_PER_MODE_RATE;
  *(uint16 *)ptrStrApi->uPerMode.perModeFrameSnd.length = RSI_PER_MODE_LENGTH;
  *(uint16 *)ptrStrApi->uPerMode.perModeFrameSnd.mode = RSI_PER_MODE_MODE;
  *(uint16 *)ptrStrApi->uPerMode.perModeFrameSnd.channel = RSI_PER_MODE_CHANNEL;
  *(uint16 *)ptrStrApi->uPerMode.perModeFrameSnd.rate_flags = RSI_PER_MODE_RATE_FLAGS;
  *(uint16 *)ptrStrApi->uPerMode.perModeFrameSnd.per_ch_bw = RSI_PER_MODE_PER_CH_BW;
  *(uint16 *)ptrStrApi->uPerMode.perModeFrameSnd.aggr_enable = RSI_PER_MODE_AGGR_ENABLE;
  *(uint16 *)ptrStrApi->uPerMode.perModeFrameSnd.aggr_count = RSI_PER_MODE_AGGR_COUNT;
  *(uint16 *)ptrStrApi->uPerMode.perModeFrameSnd.no_of_pkts = RSI_PER_MODE_NO_OF_PKTS;
  *(uint32 *)ptrStrApi->uPerMode.perModeFrameSnd.delay = RSI_PER_MODE_DELAY;

#else
  rsi_uint16_to_2bytes(ptrStrApi->uPerMode.perModeFrameSnd.per_mode_enable,RSI_PER_MODE_SUPPORT);
  rsi_uint16_to_2bytes(ptrStrApi->uPerMode.perModeFrameSnd.power, RSI_PER_MODE_POWER);
  rsi_uint32_to_4bytes(ptrStrApi->uPerMode.perModeFrameSnd.rate, RSI_PER_MODE_RATE);
  rsi_uint16_to_2bytes(ptrStrApi->uPerMode.perModeFrameSnd.length, RSI_PER_MODE_LENGTH);
  rsi_uint16_to_2bytes(ptrStrApi->uPerMode.perModeFrameSnd.mode, RSI_PER_MODE_MODE);
  rsi_uint16_to_2bytes(ptrStrApi->uPerMode.perModeFrameSnd.channel, RSI_PER_MODE_CHANNEL);
  rsi_uint16_to_2bytes(ptrStrApi->uPerMode.perModeFrameSnd.rate_flags, RSI_PER_MODE_RATE_FLAGS);
  rsi_uint16_to_2bytes(ptrStrApi->uPerMode.perModeFrameSnd.per_ch_bw, RSI_PER_MODE_PER_CH_BW);
  rsi_uint16_to_2bytes(ptrStrApi->uPerMode.perModeFrameSnd.aggr_enable, RSI_PER_MODE_AGGR_ENABLE);
  rsi_uint16_to_2bytes(ptrStrApi->uPerMode.perModeFrameSnd.aggr_count, RSI_PER_MODE_AGGR_COUNT);
  rsi_uint16_to_2bytes(ptrStrApi->uPerMode.perModeFrameSnd.no_of_pkts, RSI_PER_MODE_NO_OF_PKTS);
  rsi_uint32_to_4bytes(ptrStrApi->uPerMode.perModeFrameSnd.delay, RSI_PER_MODE_DELAY);
#endif
#endif

  /* PER stats */
#ifdef RSI_LITTLE_ENDIAN
  *(uint16 *)ptrStrApi->uPerStats.perStatsFrameSnd.per_stats_enable  = RSI_PER_STATS;
  *(uint16 *)ptrStrApi->uPerStats.perStatsFrameSnd.per_stats_channel = RSI_PER_STATS_CHANNEL;
#else
  rsi_uint16_to_2bytes(ptrStrApi->uPerStats.perStatsFrameSnd.per_stats_enable, RSI_PER_STATS);
  rsi_uint16_to_2bytes(ptrStrApi->uPerStats.perStatsFrameSnd.per_stats_channel, RSI_PER_STATS_CHANNEL);
#endif

  /* SNMP GET/GET NEXT parameters */
  ptrStrApi->snmp_enable  = RSI_SNMP_ENABLE;

  ptrStrApi->uSnmp.snmpFrameSnd.type  = RSI_SNMP_OBJ_TYPE;
  if(RSI_SNMP_OBJ_TYPE == SNMP_ANS1_OCTET_STRING)
  {
    strcpy((char *)ptrStrApi->uSnmp.snmpFrameSnd.value, (char *)RSI_SNMP_OBJ_VALUE);
  }
  else
  {
#ifdef RSI_LITTLE_ENDIAN
    *(uint32 *)ptrStrApi->uSnmp.snmpFrameSnd.value  = (uint32 )RSI_SNMP_OBJ_VALUE;
#else
    rsi_uint32_to_4bytes(ptrStrApi->uSnmp.snmpFrameSnd.value, RSI_SNMP_OBJ_VALUE);
#endif	
  }

  /* SNMP TRAP parameters */
  *(uint32 *)ptrStrApi->uSnmptrap.snmptrapFrameSnd.snmp_version  = RSI_SNMP_VERSION;

#ifdef RSI_LITTLE_ENDIAN
  *(uint32 *)ptrStrApi->uSnmptrap.snmptrapFrameSnd.ip_version    = RSI_IP_VERSION;
#else
  rsi_uint32_to_4bytes(ptrStrApi->uSnmptrap.snmptrapFrameSnd.ip_version, RSI_IP_VERSION);
#endif
  if(*(uint32 *)ptrStrApi->uSnmptrap.snmptrapFrameSnd.ip_version == IP_VERSION_4)
  {
    rsi_ascii_dot_address_to_4bytes(&temp[0],(int8 *)RSI_SNMP_TARGET_IP_ADDRESS);
    ptrStrApi->uSnmptrap.snmptrapFrameSnd.destIPaddr.ipv4_address[3]=temp[0];
    ptrStrApi->uSnmptrap.snmptrapFrameSnd.destIPaddr.ipv4_address[2]=temp[1];
    ptrStrApi->uSnmptrap.snmptrapFrameSnd.destIPaddr.ipv4_address[1]=temp[2];
    ptrStrApi->uSnmptrap.snmptrapFrameSnd.destIPaddr.ipv4_address[0]=temp[3];
  }
  else
  {
    parse_ipv6_address(ptrStrApi->uSnmptrap.snmptrapFrameSnd.destIPaddr.ipv6_address, (uint8 *)RSI_SNMP_TARGET_IPV6_ADDRESS);
  }
  strcpy((char *)ptrStrApi->uSnmptrap.snmptrapFrameSnd.community, RSI_SNMP_COMMUNITY);
  ptrStrApi->uSnmptrap.snmptrapFrameSnd.trap_type     = RSI_SNMP_TRAP_TYPE;
#ifdef RSI_LITTLE_ENDIAN
  *(uint32 *)ptrStrApi->uSnmptrap.snmptrapFrameSnd.elapsed_time = RSI_SNMP_ELAPSED_TIME;
#else
  rsi_uint32_to_4bytes(ptrStrApi->uSnmptrap.snmptrapFrameSnd.elapsed_time, RSI_SNMP_ELAPSED_TIME);
#endif	

  /* Join Parameters */
  ptrStrApi->uJoinFrame.joinFrameSnd.securityType = RSI_SECURITY_MODE;
  ptrStrApi->uJoinFrame.joinFrameSnd.dataRate   = RSI_DATA_RATE;
  ptrStrApi->uJoinFrame.joinFrameSnd.powerLevel = RSI_POWER_LEVEL;
  ptrStrApi->uJoinFrame.joinFrameSnd.ssid_len   = (sizeof(RSI_JOIN_SSID) - 1);

  if(SEND_PSK_IN_JOIN)
  {
    strcpy((char *)ptrStrApi->uJoinFrame.joinFrameSnd.psk, RSI_PSK);
  }
  strcpy((char *)ptrStrApi->uJoinFrame.joinFrameSnd.ssid, RSI_JOIN_SSID);

  /*SleepTimer Parameters*/
#ifdef RSI_LITTLE_ENDIAN
  *(uint16 *)ptrStrApi->uSleepTimer.SleepTimerFrameSnd.TimeVal = RSI_TIMEVAL;
#else
  rsi_uint16_to_2bytes(ptrStrApi->uSleepTimer.SleepTimerFrameSnd.TimeVal,RSI_TIMEVAL);
#endif

  /* Scan Parameters */
#ifdef RSI_LITTLE_ENDIAN
  *(uint8 *)ptrStrApi->uScanFrame.scanFrameSnd.channel = RSI_SCAN_CHANNEL;
#else
  ptrStrApi->uScanFrame.scanFrameSnd.channel[0] = RSI_SCAN_CHANNEL;
#endif	
  strcpy((char *)&ptrStrApi->uScanFrame.scanFrameSnd.ssid, RSI_SCAN_SSID);
#ifdef RSI_LITTLE_ENDIAN
  if(RSI_BAND == RSI_DUAL_BAND)
  {
    *(uint16 *)ptrStrApi->uScanFrame.scanFrameSnd.channel_bit_map_2_4 = RSI_SCAN_CHANNEL_BIT_MAP_2_4;
    *(uint32 *)ptrStrApi->uScanFrame.scanFrameSnd.channel_bit_map_5 = RSI_SCAN_CHANNEL_BIT_MAP_5;
  }
  else if (RSI_BAND == RSI_BAND_5GHZ)
  {
    *(uint32 *)ptrStrApi->uScanFrame.scanFrameSnd.channel_bit_map_5 = RSI_SCAN_CHANNEL_BIT_MAP_5;
  }
  else
  {
    *(uint16 *)ptrStrApi->uScanFrame.scanFrameSnd.channel_bit_map_2_4 = RSI_SCAN_CHANNEL_BIT_MAP_2_4;
  }
#else
  if(RSI_BAND == RSI_DUAL_BAND)
  {
    rsi_uint16_to_2bytes(ptrStrApi->uScanFrame.scanFrameSnd.channel_bit_map_2_4, RSI_SCAN_CHANNEL_BIT_MAP_2_4);
    rsi_uint32_to_4bytes(ptrStrApi->uScanFrame.scanFrameSnd.channel_bit_map_5, RSI_SCAN_CHANNEL_BIT_MAP_5);
  }
  else if (RSI_BAND == RSI_BAND_5GHZ)
  {
    rsi_uint32_to_4bytes(ptrStrApi->uScanFrame.scanFrameSnd.channel_bit_map_5, RSI_SCAN_CHANNEL_BIT_MAP_5);
  }
  else
  {
    rsi_uint16_to_2bytes(ptrStrApi->uScanFrame.scanFrameSnd.channel_bit_map_2_4, RSI_SCAN_CHANNEL_BIT_MAP_2_4);
  }
#endif	

  /* BG Scan Parameters */
#if RSI_BG_SCAN_ENABLE    
#ifdef RSI_LITTLE_ENDIAN
  *(uint16 *)ptrStrApi->ubgScanFrame.bgscanFrameSnd.bgscan_enable = RSI_BG_SCAN_ENABLE;
  *(uint16 *)ptrStrApi->ubgScanFrame.bgscanFrameSnd.enable_instant_bgscan = RSI_INSTANT_BG;
  *(uint16 *)ptrStrApi->ubgScanFrame.bgscanFrameSnd.bgscan_threshold = RSI_BG_SCAN_THRESHOLD;
  *(uint16 *)ptrStrApi->ubgScanFrame.bgscanFrameSnd.rssi_tolerance_threshold = RSI_RSSI_TOLERANCE_THRESHOLD;
  *(uint16 *)ptrStrApi->ubgScanFrame.bgscanFrameSnd.bgscan_periodicity = RSI_BG_SCAN_PERIODICITY;
  *(uint16 *)ptrStrApi->ubgScanFrame.bgscanFrameSnd.active_scan_duration = RSI_ACTIVE_SCAN_DURATION;
  *(uint16 *)ptrStrApi->ubgScanFrame.bgscanFrameSnd.passive_scan_duration = RSI_PASSIVE_SCAN_DURATION;
#else
  rsi_uint16_to_2bytes(ptrStrApi->ubgScanFrame.bgscanFrameSnd.bgscan_enable, RSI_BG_SCAN_ENABLE);
  rsi_uint16_to_2bytes(ptrStrApi->ubgScanFrame.bgscanFrameSnd.enable_instant_bgscan, RSI_INSTANT_BG);
  rsi_uint16_to_2bytes(ptrStrApi->ubgScanFrame.bgscanFrameSnd.bgscan_threshold,RSI_BG_SCAN_THRESHOLD );
  rsi_uint16_to_2bytes(ptrStrApi->ubgScanFrame.bgscanFrameSnd.rssi_tolerance_threshold, RSI_RSSI_TOLERANCE_THRESHOLD);
  rsi_uint16_to_2bytes(ptrStrApi->ubgScanFrame.bgscanFrameSnd.bgscan_periodicity,RSI_BG_SCAN_PERIODICITY );
  rsi_uint16_to_2bytes(ptrStrApi->ubgScanFrame.bgscanFrameSnd.active_scan_duration, RSI_ACTIVE_SCAN_DURATION );
  rsi_uint16_to_2bytes(ptrStrApi->ubgScanFrame.bgscanFrameSnd.passive_scan_duration,RSI_PASSIVE_SCAN_DURATION );
#endif	
  ptrStrApi->ubgScanFrame.bgscanFrameSnd.multi_probe = RSI_MULTIPROBE;
#endif	

  /*Socket Parameters */
#ifdef RSI_LITTLE_ENDIAN	
  *(uint16 *)ptrStrApi->uSocketFrame.socketFrameSnd.ip_version   = RSI_IP_VERSION; 
  *(uint16 *)ptrStrApi->uSocketFrame.socketFrameSnd.moduleSocket = RSI_MODULE_SOCKET_ONE; 
  *(uint16 *)ptrStrApi->uSocketFrame.socketFrameSnd.destSocket   = RSI_TARGET_SOCKET_ONE;
  *(uint16 *)ptrStrApi->uSocketFrame.socketFrameSnd.socketType   = RSI_SOCKET_TYPE; 
  *(uint16 *)ptrStrApi->uSocketFrame.socketFrameSnd.max_count    = RSI_MAX_LTCP_CONNECTIONS; 
  *(uint32 *)ptrStrApi->uSocketFrame.socketFrameSnd.tos          = RSI_TOS; 
#else
  rsi_uint16_to_2bytes(ptrStrApi->uSocketFrame.socketFrameSnd.ip_version,RSI_IP_VERSION);
  rsi_uint16_to_2bytes(ptrStrApi->uSocketFrame.socketFrameSnd.moduleSocket,RSI_MODULE_SOCKET_ONE);
  rsi_uint16_to_2bytes(ptrStrApi->uSocketFrame.socketFrameSnd.destSocket,RSI_TARGET_SOCKET_ONE); 
  rsi_uint16_to_2bytes(ptrStrApi->uSocketFrame.socketFrameSnd.socketType,RSI_SOCKET_TYPE); 
  rsi_uint16_to_2bytes(ptrStrApi->uSocketFrame.socketFrameSnd.max_count, RSI_MAX_LTCP_CONNECTIONS); 
  rsi_uint32_to_4bytes(ptrStrApi->uScanFrame.scanFrameSnd.tos, RSI_TOS);
#endif
  ptrStrApi->uSocketFrame.socketFrameSnd.ssl_bitmap   = SOCKET_FEATURE;
  ptrStrApi->uSocketFrame.socketFrameSnd.ssl_ciphers  = SSL_CIPHERS;
  strcpy((char *)ptrStrApi->uSocketFrame.socketFrameSnd.webs_resource_name, WEBS_RESOURCE_NAME);
  strcpy((char *)ptrStrApi->uSocketFrame.socketFrameSnd.webs_host_name, WEBS_HOST_NAME);

  if(*(uint16 *)ptrStrApi->uSocketFrame.socketFrameSnd.ip_version == IP_VERSION_4)
  { 
    rsi_ascii_dot_address_to_4bytes((uint8 *)ptrStrApi->uSocketFrame.socketFrameSnd.destIpaddr.ipv4_address, (int8 *)RSI_TARGET_IP_ADDRESS);
  }
  else
  {
    parse_ipv6_address(ptrStrApi->uSocketFrame.socketFrameSnd.destIpaddr.ipv6_address, (uint8 *)RSI_TARGET_IPV6_ADDRESS);
  }

  /* Mac Address */
  rsi_ascii_mac_address_to_6bytes((uint8 *)&ptrStrApi->macAddress, (int8 *)RSI_MAC_ADDRESS);

  /* Power mode setting */
  ptrStrApi->powerMode = RSI_POWER_MODE;

  /*Web Server Parameters*/
  memset((char *)&ptrStrApi->uWebData, '\0', sizeof(rsi_uWebServer));
#ifdef RSI_LITTLE_ENDIAN 
  *(uint16 *)ptrStrApi->uWebData.webServFrameSnd.Webpage_info.total_len = WEB_PAGE_LENGTH; 
#else
  rsi_uint16_to_2bytes(ptrStrApi->uWebData.webServFrameSnd.Webpage_info.total_len,WEB_PAGE_LENGTH);
#endif
  strcpy((char*)&ptrStrApi->uWebData.webServFrameSnd.Webpage_info.filename, WEB_PAGE_FILENAME);
  ptrStrApi->uWebData.webServFrameSnd.Webpage_info.has_json_data = WEB_PAGE_HAS_JSON;

  /* JSON */
  strcpy(ptrStrApi->json.filename, JSON_FILENAME);

  /* Clear files */
  ptrStrApi->clear_files.clear = WEB_PAGE_CLEAR_ALL_FILES;

  /*URL response Parameters*/
  memset((char *)&ptrStrApi->UrlRsp, '\0', sizeof(HostWebpageSnd_t));

  /*PSK and PMK parameters*/
  ptrStrApi->uPskFrame.PskFrameSnd.TYPE = RSI_PSK_TYPE ;
  memset(ptrStrApi->uPskFrame.PskFrameSnd.psk_or_pmk, '\0', RSI_PSK_LEN);
  if (RSI_PSK_TYPE == RSI_PMK_FROM_HOST)
  {
    for(i=0 ,j=0 ; i < 64 && j < 32; i+=2,j++)
    {
      if(RSI_PMK[i] && RSI_PMK[i + 1])
      {
        ptrStrApi->uPskFrame.PskFrameSnd.psk_or_pmk[j]  = ((uint16 )convert_lower_case_to_upper_case(RSI_PMK[i])) * 16;
        ptrStrApi->uPskFrame.PskFrameSnd.psk_or_pmk[j] += convert_lower_case_to_upper_case(RSI_PMK[i + 1]); 
      }
      else
      {
        ptrStrApi->uPskFrame.PskFrameSnd.psk_or_pmk[j]=0 ;
      }
    }
  }
  else if(RSI_PSK_TYPE == RSI_GENERATE_PMK)
  {
    strcpy((char *)ptrStrApi->uPskFrame.PskFrameSnd.psk_or_pmk, RSI_PSK);
    strcpy((char *)ptrStrApi->uPskFrame.PskFrameSnd.ap_ssid, RSI_JOIN_SSID);
  }
  else if(RSI_PSK_TYPE == RSI_PSK_FROM_HOST)
  {
    strcpy((char *)ptrStrApi->uPskFrame.PskFrameSnd.psk_or_pmk, RSI_PSK);
  }
  else
  {
    memset(ptrStrApi->uPskFrame.PskFrameSnd.psk_or_pmk, '\0', RSI_PSK_LEN);
  }
#if FIPS_MODE_ENABLE
#ifdef RSI_LITTLE_ENDIAN	
  ptrStrApi->re_key.RecheckkeyFrameSnd.type =  RSI_RECHECK_KEY_TYPE;
#else
  rsi_uint16_to_2bytes(ptrStrApi->re_key.uRecheckKeyBuf.type,RSI_RECHECK_KEY_TYPE);
#endif
  memset(ptrStrApi->re_key.RecheckkeyFrameSnd.key, '\0', 128);
  if(RSI_RECHECK_KEY_TYPE == CHECK_PMK)
  {
    for(i=0 ,j=0 ; i < 64 && j < 32; i+=2,j++)
    {
      if(RSI_RECHECK_PMK[i] && RSI_RECHECK_PMK[i + 1])
      {
        ptrStrApi->re_key.RecheckkeyFrameSnd.key[j]  = ((uint16 )convert_lower_case_to_upper_case(RSI_RECHECK_PMK[i])) * 16;
        ptrStrApi->re_key.RecheckkeyFrameSnd.key[j] += convert_lower_case_to_upper_case(RSI_RECHECK_PMK[i + 1]); 
      }
      else
      {
        ptrStrApi->re_key.RecheckkeyFrameSnd.key[j]=0 ;
      }
    }
  }
  else if(RSI_RECHECK_KEY_TYPE == CHECK_EAP_PASSWORD)
  {
    strcpy((char *)ptrStrApi->re_key.RecheckkeyFrameSnd.key, RECHECK_PASSWORD);
  }
#endif

#if RSI_LOAD_FWUPGRADATION_KEY
  memset(ptrStrApi->fwupgradation_key.FwupgradationkeyFrameSnd.key, '\0', 16);
  for(i=0 ,j=0 ; i < 32 && j < 16; i+=2,j++)
  {
    if(RSI_FWUPGRADATION_KEY[i] && RSI_FWUPGRADATION_KEY[i + 1])
    {
      ptrStrApi->fwupgradation_key.FwupgradationkeyFrameSnd.key[j]  = ((uint16 )convert_lower_case_to_upper_case(RSI_FWUPGRADATION_KEY[i])) * 16;
      ptrStrApi->fwupgradation_key.FwupgradationkeyFrameSnd.key[j] += convert_lower_case_to_upper_case(RSI_FWUPGRADATION_KEY[i + 1]); 
    }
    else
    {
      ptrStrApi->fwupgradation_key.FwupgradationkeyFrameSnd.key[j]=0 ;
    }
  }
#endif
  /*EAP parameters*/
  strcpy((char *)ptrStrApi->usetEap.setEapFrameSnd.eapMethod, EAP_METHOD);
  strcpy((char *)ptrStrApi->usetEap.setEapFrameSnd.innerMethod, INNER_METHOD);
  strcpy((char *)ptrStrApi->usetEap.setEapFrameSnd.userIdentity, USER_IDENTITY);
  strcpy((char *)ptrStrApi->usetEap.setEapFrameSnd.password, PASSWORD);
#ifdef RSI_LITTLE_ENDIAN	
  *(int32*)ptrStrApi->usetEap.setEapFrameSnd.okc_enable = (int32)EAP_OKC_ENABLE; 
#else
  rsi_uint32_to_4bytes(ptrStrApi->usetEap.setEapFrameSnd.okc_enable, EAP_OKC_ENABLE);
#endif		
  /*P2p Parameters*/
#ifdef RSI_LITTLE_ENDIAN	
  *(uint16 *)ptrStrApi->uconfigP2p.configP2pFrameSnd.GOIntent    = GO_INTENT_VALUE;
  *(uint16 *)ptrStrApi->uconfigP2p.configP2pFrameSnd.operChannel = P2P_OPER_CHANNEL;
#else
  rsi_uint16_to_2bytes(ptrStrApi->uconfigP2p.configP2pFrameSnd.GOIntent,GO_INTENT_VALUE);
  rsi_uint16_to_2bytes(ptrStrApi->uconfigP2p.configP2pFrameSnd.operChannel,OPER_CHANNEL);
#endif		
	strcpy((char *)ptrStrApi->uconfigP2p.configP2pFrameSnd.deviceName, P2P_DEVICE_NAME);
	strcpy((char *)ptrStrApi->uconfigP2p.configP2pFrameSnd.ssidPostFix, POST_FIX_SSID);
	strcpy((char *)ptrStrApi->uconfigP2p.configP2pFrameSnd.psk, RSI_PSK);
	

	
	/*http get */
#ifdef RSI_LITTLE_ENDIAN
  *(uint16 *)ptrStrApi->uHttpGetReq.HttpReqFrameSnd.ip_version = RSI_IP_VERSION;
  *(uint16 *)ptrStrApi->uHttpGetReq.HttpReqFrameSnd.https_enable  = RSI_HTTPS_SUPPORT;
   ptrStrApi->uHttpGetReq.HttpReqFrameSnd.http_port            = RSI_HTTP_SERVER_PORT;
#else
	rsi_uint16_to_2bytes(ptrStrApi->uHttpGetReq.HttpReqFrameSnd.https_enable, RSI_HTTPS_SUPPORT);
	rsi_uint16_to_2bytes(ptrStrApi->uHttpGetReq.HttpReqFrameSnd.http_port, RSI_HTTP_SERVER_PORT);
#endif


  http_feature = RSI_HTTPS_SUPPORT;
  if(!(http_feature & RSI_HTTP_NULL_DELIMITER))
  {
    strcpy((char *)&ptrStrApi->uHttpGetReq.HttpReqFrameSnd.buffer, RSI_HTTP_USERNAME);
    strcat((char *)&ptrStrApi->uHttpGetReq.HttpReqFrameSnd.buffer, ",");
    strcat((char *)&ptrStrApi->uHttpGetReq.HttpReqFrameSnd.buffer, RSI_HTTP_PASSWORD);
    strcat((char *)&ptrStrApi->uHttpGetReq.HttpReqFrameSnd.buffer, ",");
    strcat((char *)&ptrStrApi->uHttpGetReq.HttpReqFrameSnd.buffer, RSI_HTTP_HOSTNAME);
    strcat((char *)&ptrStrApi->uHttpGetReq.HttpReqFrameSnd.buffer, ",");
    if(*(uint16 *)ptrStrApi->uHttpGetReq.HttpReqFrameSnd.ip_version == IP_VERSION_4)
    {
      strcat((char *)&ptrStrApi->uHttpGetReq.HttpReqFrameSnd.buffer, RSI_HTTP_IP);
    }else{
      strcat((char *)&ptrStrApi->uHttpGetReq.HttpReqFrameSnd.buffer, RSI_HTTP_IPV6);
    }
    strcat((char *)&ptrStrApi->uHttpGetReq.HttpReqFrameSnd.buffer, ",");
    strcat((char *)&ptrStrApi->uHttpGetReq.HttpReqFrameSnd.buffer, RSI_HTTP_URL);
    strcat((char *)&ptrStrApi->uHttpGetReq.HttpReqFrameSnd.buffer, ",");
    rsi_buildHttpExtendedHeader((uint8 *)ptrStrApi->uHttpGetReq.HttpReqFrameSnd.buffer, 0);


    /* URL to be configured */

    /*HTTP post*/
#ifdef RSI_LITTLE_ENDIAN
    *(uint16 *)ptrStrApi->uHttpPostReq.HttpReqFrameSnd.ip_version = RSI_IP_VERSION;
    *(uint16 *)ptrStrApi->uHttpPostReq.HttpReqFrameSnd.https_enable  = RSI_HTTPS_SUPPORT;
    ptrStrApi->uHttpPostReq.HttpReqFrameSnd.http_port           = RSI_HTTP_SERVER_PORT;
#else
    rsi_uint16_to_2bytes(ptrStrApi->uHttpPostReq.HttpReqFrameSnd.ip_version,RSI_IP_VERSION);
    rsi_uint16_to_2bytes(ptrStrApi->uHttpPostReq.HttpReqFrameSnd.https_enable, RSI_HTTPS_SUPPORT);
    rsi_uint16_to_2bytes(ptrStrApi->uHttpPostReq.HttpReqFrameSnd.http_port, RSI_HTTP_SERVER_PORT);
#endif


    strcpy((char *)&ptrStrApi->uHttpPostReq.HttpReqFrameSnd.buffer, RSI_HTTP_USERNAME);
    strcat((char *)&ptrStrApi->uHttpPostReq.HttpReqFrameSnd.buffer, ",");
    strcat((char *)&ptrStrApi->uHttpPostReq.HttpReqFrameSnd.buffer, RSI_HTTP_PASSWORD);
    strcat((char *)&ptrStrApi->uHttpPostReq.HttpReqFrameSnd.buffer, ",");
    strcat((char *)&ptrStrApi->uHttpPostReq.HttpReqFrameSnd.buffer, RSI_HTTP_HOSTNAME);
    strcat((char *)&ptrStrApi->uHttpPostReq.HttpReqFrameSnd.buffer, ",");
    if(*(uint16 *)ptrStrApi->uHttpPostReq.HttpReqFrameSnd.ip_version == IP_VERSION_4)
    {
      strcat((char *)&ptrStrApi->uHttpPostReq.HttpReqFrameSnd.buffer, RSI_HTTP_IP);
    }else {
      strcat((char *)&ptrStrApi->uHttpPostReq.HttpReqFrameSnd.buffer, RSI_HTTP_IPV6);
    }
    strcat((char *)&ptrStrApi->uHttpPostReq.HttpReqFrameSnd.buffer, ",");
    strcat((char *)&ptrStrApi->uHttpPostReq.HttpReqFrameSnd.buffer, RSI_HTTP_URL);
    strcat((char *)&ptrStrApi->uHttpPostReq.HttpReqFrameSnd.buffer, ",");
    rsi_buildHttpExtendedHeader((uint8 *)ptrStrApi->uHttpPostReq.HttpReqFrameSnd.buffer, 0);
    strcat((char *)&ptrStrApi->uHttpPostReq.HttpReqFrameSnd.buffer, ",");
    strcat((char *)&ptrStrApi->uHttpPostReq.HttpReqFrameSnd.buffer, RSI_HTTP_DATA);
  }
  else
  {
    strcpy((char *)&ptrStrApi->uHttpGetReq.HttpReqFrameSnd.buffer, RSI_HTTP_USERNAME);
    http_len = sizeof(RSI_HTTP_USERNAME);

    strcpy(((char *)&ptrStrApi->uHttpGetReq.HttpReqFrameSnd.buffer) + http_len, RSI_HTTP_PASSWORD);
    http_len += sizeof(RSI_HTTP_PASSWORD);

    strcpy(((char *)&ptrStrApi->uHttpGetReq.HttpReqFrameSnd.buffer) + http_len, RSI_HTTP_HOSTNAME);
    http_len += sizeof(RSI_HTTP_HOSTNAME);

    if(*(uint16 *)ptrStrApi->uHttpGetReq.HttpReqFrameSnd.ip_version == IP_VERSION_4)
    {
      strcpy(((char *)&ptrStrApi->uHttpGetReq.HttpReqFrameSnd.buffer) + http_len, RSI_HTTP_IP);
      http_len += sizeof(RSI_HTTP_IP);
    }else{
      strcpy(((char *)&ptrStrApi->uHttpGetReq.HttpReqFrameSnd.buffer) + http_len, RSI_HTTP_IPV6);
      http_len += sizeof(RSI_HTTP_IPV6);
    }
    strcpy(((char *)&ptrStrApi->uHttpGetReq.HttpReqFrameSnd.buffer) + http_len, RSI_HTTP_URL);
    http_len += sizeof(RSI_HTTP_URL);

    rsi_buildHttpExtendedHeader((uint8 *)&(ptrStrApi->uHttpGetReq.HttpReqFrameSnd.buffer) + http_len, 1);

    /* URL to be configured */

    /*HTTP post*/
#ifdef RSI_LITTLE_ENDIAN 
    *(uint16 *)ptrStrApi->uHttpPostReq.HttpReqFrameSnd.ip_version = RSI_IP_VERSION;
    *(uint16 *)ptrStrApi->uHttpPostReq.HttpReqFrameSnd.https_enable  = RSI_HTTPS_SUPPORT;
    ptrStrApi->uHttpPostReq.HttpReqFrameSnd.http_port           = RSI_HTTP_SERVER_PORT;
#else
    rsi_uint16_to_2bytes(ptrStrApi->uHttpPostReq.HttpReqFrameSnd.ip_version,RSI_IP_VERSION);
    rsi_uint16_to_2bytes(ptrStrApi->uHttpPostReq.HttpReqFrameSnd.https_enable, RSI_HTTPS_SUPPORT);
    rsi_uint16_to_2bytes(ptrStrApi->uHttpPostReq.HttpReqFrameSnd.http_port, RSI_HTTP_SERVER_PORT);
#endif 


    strcpy((char *)&ptrStrApi->uHttpPostReq.HttpReqFrameSnd.buffer, RSI_HTTP_USERNAME);
    http_len = sizeof(RSI_HTTP_USERNAME);

    strcpy(((char *)&ptrStrApi->uHttpPostReq.HttpReqFrameSnd.buffer) + http_len, RSI_HTTP_PASSWORD);
    http_len += sizeof(RSI_HTTP_PASSWORD);

    strcpy(((char *)&ptrStrApi->uHttpPostReq.HttpReqFrameSnd.buffer) + http_len, RSI_HTTP_HOSTNAME);
    http_len += sizeof(RSI_HTTP_HOSTNAME);

    if(*(uint16 *)ptrStrApi->uHttpPostReq.HttpReqFrameSnd.ip_version == IP_VERSION_4)
    {
      strcpy(((char *)&ptrStrApi->uHttpPostReq.HttpReqFrameSnd.buffer) + http_len, RSI_HTTP_IP);
      http_len += sizeof(RSI_HTTP_IP);
    }else {
      strcpy(((char *)&ptrStrApi->uHttpPostReq.HttpReqFrameSnd.buffer) + http_len, RSI_HTTP_IPV6);
      http_len += sizeof(RSI_HTTP_IPV6);
    }
    strcpy(((char *)&ptrStrApi->uHttpPostReq.HttpReqFrameSnd.buffer) + http_len, RSI_HTTP_URL);
    http_len += sizeof(RSI_HTTP_URL);

    rsi_buildHttpExtendedHeader((uint8 *)ptrStrApi->uHttpPostReq.HttpReqFrameSnd.buffer + http_len, 1);

    http_len += strlen((char *)&(ptrStrApi->uHttpPostReq.HttpReqFrameSnd.buffer) + http_len) + 1;
    strcpy(((char *)&ptrStrApi->uHttpPostReq.HttpReqFrameSnd.buffer) + http_len, RSI_HTTP_DATA);
  }





  
  /* Dns server Params*/
  *(uint16 *)ptrStrApi->uDnsServer.dnsServerFrameSnd.ip_version = RSI_IP_VERSION;
  *(uint16 *)ptrStrApi->uDnsServer.dnsServerFrameSnd.DNSMode = RSI_DNS_CFG_MODE;
  if (*(uint16 *)ptrStrApi->uDnsServer.dnsServerFrameSnd.ip_version == IP_VERSION_4)
  {
    rsi_ascii_dot_address_to_4bytes((uint8 *)ptrStrApi->uDnsServer.dnsServerFrameSnd.primary_dns_ip.ipv4_address, (int8 *)RSI_PRIMARY_DNS_IP_ADDRESS);
    rsi_ascii_dot_address_to_4bytes((uint8 *)ptrStrApi->uDnsServer.dnsServerFrameSnd.secondary_dns_ip.ipv4_address, (int8 *)RSI_SECONDARY_DNS_IP_ADDRESS);
  }
  else
  {

    parse_ipv6_address(ptrStrApi->uDnsServer.dnsServerFrameSnd.primary_dns_ip.ipv6_address, (uint8 *)RSI_TARGET_IPV6_ADDRESS);
    parse_ipv6_address(ptrStrApi->uDnsServer.dnsServerFrameSnd.secondary_dns_ip.ipv6_address, (uint8 *)RSI_TARGET_IPV6_ADDRESS);
  }
  /* DNS Get get */  
  *(uint16 *)ptrStrApi->uDnsQry.dnsQryFrameSnd.ip_version = RSI_IP_VERSION;
  strcpy((char *)ptrStrApi->uDnsQry.dnsQryFrameSnd.aDomainName,DNS_QRY_URL);
#ifdef RSI_LITTLE_ENDIAN
  *(uint16 *)ptrStrApi->uDnsQry.dnsQryFrameSnd.uDNSServerNumber = DNS_SERVER_NUM;
#else
  rsi_uint16_to_2bytes(ptrStrApi->uDnsQry.dnsQryFrameSnd.uDNSServerNumber,DNS_SERVER_NUM);
#endif	
  /* Store config enable flag */
  ptrStrApi->cfg_enable = RSI_STORE_CONFIG;

  /* Wepkey data initialisation*/
#ifdef RSI_LITTLE_ENDIAN
  *(uint16 *)ptrStrApi->wepkeys.index = RSI_WEP_INDEX;
#else
  rsi_uint16_to_2bytes(ptrStrApi->wepkeys.index,RSI_WEP_INDEX);
#endif	
  strcpy((char *)ptrStrApi->wepkeys.key[0],(char *)RSI_WEPKEY0);
  strcpy((char *)ptrStrApi->wepkeys.key[1],(char *)RSI_WEPKEY1);
  strcpy((char *)ptrStrApi->wepkeys.key[2],(char *)RSI_WEPKEY2);
  strcpy((char *)ptrStrApi->wepkeys.key[3],(char *)RSI_WEPKEY3);

  /*AP Configuration data Initialisation*/
#ifdef RSI_LITTLE_ENDIAN
  *(uint16 *)ptrStrApi->apconf_data.dtim_period = RSI_DTIM_PERIOD;
  *(uint16 *)ptrStrApi->apconf_data.beacon_interval = RSI_BEACON_INTERVAL;
  *(uint16 *)ptrStrApi->apconf_data.channel_no = RSI_AP_CHANNEL_NUM;
  *(uint16 *)ptrStrApi->apconf_data.max_sta_support = MAX_NO_OF_CLIENTS;
#else
  rsi_uint16_to_2bytes(ptrStrApi->apconf_data.dtim_period,RSI_DTIM_PERIOD);
  rsi_uint16_to_2bytes(ptrStrApi->apconf_data.beacon_interval,RSI_BEACON_INTERVAL);
  rsi_uint16_to_2bytes(ptrStrApi->apconf_data.channel_no,RSI_AP_CHANNEL_NUM);
  rsi_uint16_to_2bytes(ptrStrApi->apconf_data.max_sta_support,MAX_NO_OF_CLIENTS);
#endif		
  strcpy((char *)ptrStrApi->apconf_data.ssid,RSI_JOIN_SSID);
  ptrStrApi->apconf_data.security_type = RSI_SECURITY_TYPE;
  ptrStrApi->apconf_data.encryp_mode = RSI_ENCRYPTION_MODE;
  strcpy((char *)ptrStrApi->apconf_data.psk,RSI_PSK);

  /*Discoonect command */
#ifdef RSI_LITTLE_ENDIAN
  *(uint16 *)ptrStrApi->disassoc_frame.mode_flag = MODE_FLAG;
#else
  rsi_uint16_to_2bytes(ptrStrApi->disassoc_frame.mode_flag,MODE_FLAG);
#endif	
  rsi_ascii_mac_address_to_6bytes((uint8 *)&ptrStrApi->disassoc_frame.client_mac_addr, (int8 *)CLIENT_MAC_ADDRESS);

#if RSI_ICMP_FROM_MODULE
  /*Ping params initialisation*/
#ifdef RSI_LITTLE_ENDIAN
  *(uint16 *)ptrStrApi->ping.ip_version = RSI_PING_VERSION;
#else
  rsi_uint16_to_2bytes(ptrStrApi->ping.ip_version, RSI_PING_VERSION);
#endif
  if(*(uint16 *)ptrStrApi->ping.ip_version == IP_VERSION_4)
  {
    rsi_ascii_dot_address_to_4bytes((uint8 *)&ptrStrApi->ping.ping_address.ipv4_address,(int8 *)RSI_PING_TARGET_IP);
  }
  else
  {
    parse_ipv6_address(ptrStrApi->ping.ping_address.ipv6_address, (uint8 *)RSI_PING_TARGET_IPV6);

  }
#ifdef RSI_LITTLE_ENDIAN
  *(uint16 *)ptrStrApi->ping.ping_size = RSI_PING_DATA_SIZE;
#else
  rsi_uint16_to_2bytes(ptrStrApi->ping.ping_size, RSI_PING_DATA_SIZE);
#endif
#endif

#if RSI_ENABLE_REJOIN_PARAMS 
#ifdef RSI_LITTLE_ENDIAN
  *(uint32 *)ptrStrApi->rejoin_param.rsi_max_try  = (uint32 )RSI_REJOIN_MAX_RETRY;
  *(uint32 *)ptrStrApi->rejoin_param.rsi_scan_interval  = (uint32 )RSI_REJOIN_SCAN_INTERVAL;
  *(uint32 *)ptrStrApi->rejoin_param.rsi_beacon_missed_count  = (uint32 )RSI_REJOIN_BEACON_MISSED_CNT;
  *(uint32 *)ptrStrApi->rejoin_param.rsi_first_time_retry_enable  = (uint32 )RSI_REJOIN_FIRST_TIME_RETRY;
#else
  rsi_uint32_to_4bytes(ptrStrApi->rejoin_param.rsi_max_try, RSI_REJOIN_MAX_RETRY);
  rsi_uint32_to_4bytes(ptrStrApi->rejoin_param.rsi_scan_interval, RSI_REJOIN_SCAN_INTERVAL);
  rsi_uint32_to_4bytes(ptrStrApi->rejoin_param.rsi_beacon_missed_count, RSI_REJOIN_BEACON_MISSED_CNT);
  rsi_uint32_to_4bytes(ptrStrApi->rejoin_param.rsi_first_time_retry_enable, RSI_REJOIN_FIRST_TIME_RETRY);
#endif	
#endif
  return 0;
}
