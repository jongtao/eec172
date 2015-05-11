/**
 * @file           rsi_config.h
 * @version        3.6
 * @date           2013-May-16
 *
 * Copyright(C) Redpine Signals 2013
 * All rights reserved by Redpine Signals.
 *
 * @section License
 * This program should be used on your own responsibility.
 * Redpine Signals assumes no responsibility for any losses
 * incurred by customers or third parties arising from the use of this file.
 *
 * @brief CONFIG INIT contains the default configurations used in the api's
 *
 * @section Description
 * USER is supposed to configure the module/API's  by using the following defines 
 *
 *
 */

#ifndef _INITSTRUCT_H_
#define _INITSTRUCT_H_


#include "rsi_api.h"
/*==============================================*/
/**
 * Global Defines
 */
#define HOST_INTERACTION_MODE      ENABLE                     //@ ENABLE or DISABLE host interaction for bootloader
#define BOOTLOADER_VERSION         0x15                        //@ Bootloader version 
#define USB_DUAL_ENUMERATION       DISABLE                     //@ ENABLE or DISABLE dual enumeration for USB mode

#define RSI_BTLE_ONLY_MODE         DISABLE                     //@ ENABLE to quit wlan application after opermode


#define RSI_TCP_IP_BYPASS          DISABLE                     //@ ENABLE or DISABLE TCP/IP bypass mode
#define WFU_UPGRADE                DISABLE                     //@ ENABLE or DISABLE Wireless firmware upgradation
#define FW_UPGRADE                 DISABLE                     //@ ENABLE or DISABLE firmware upgrade from host
#define RSI_UPGRADE_IMAGE_TYPE     RSI_UPGRADE_WLAN_FW         //@ RSI_UPGRADE_WLAN_FW or RSI_UPGRADE_BT_FW or RSI_UPGRADE_BL              
#define RSI_LOAD_IMAGE_TYPE        RSI_LOAD_WLAN_FW            //@ RSI_LOAD_WLAN_FW or RSI_LOAD_BT_ZIGBEE_FW or RSI_LOAD_WLAN_ACTIVE_LOW_FW or RSI_LOAD_BT_ZIGBEE_ACTIVE_LOW_FW
#define RSI_DEFAULT_IMAGE_SELECT   RSI_SELECT_WLAN_BY_DEFAULT  //@ RSI_SELECT_WLAN_BY_DEFAULT or RSI_SELECT_BT_ZIGBEE_BY_DEFAULT   
#define RSI_BOOT_BYPASS_SELECT     RSI_ENABLE_BOOT_BYPASS      //@ RSI_ENABLE_BOOT_BYPASS or RSI_DISABLE_BOOT_BYPASS 
#define RSI_HOST_BOOTUP_OPTION     RSI_LOAD_IMAGE_TYPE         //@ RSI_LOAD_IMAGE_TYPE or RSI_DEFAULT_IMAGE_SELECT or RSI_HOST_BOOTUP_CMD

#define FIPS_MODE_ENABLE           DISABLE
#if FIPS_MODE_ENABLE
#define RSI_RECHECK_PMK            "661cb4a09ddffbb778372f302900919d57b5e065a261234de7b2962ca7a0d830"                          //@ PMK "661cb4a09ddffbb778372f302900919d57b5e065a261234de7b2962ca7a0d830"//"1d55d6ad23a22b46af91b222348e9a195341204320fed8b6b4193ce557c0d555"
#define RSI_RECHECK_KEY_TYPE       CHECK_PMK                   //@ CHECK_PMK or CHECK_EAP_PASSWORD
#define RSI_ENABLE_UPGRADATION_FROM_HOST DISABLE
#define RECHECK_PASSWORD           "\"test123\""               //@ Password
#define RSI_LOAD_FWUPGRADATION_KEY ENABLE
#if RSI_LOAD_FWUPGRADATION_KEY            
#define RSI_FWUPGRADATION_KEY      "123456789061234de7b2962ca7a0d830"                         //@ secret key to be loaded for DSA  
#endif
#endif
#define RSI_BAND                   RSI_BAND_2P4GHZ             //@ RSI_BAND_2P4GHZ or RSI_BAND_5GHZ or RSI_DUAL_BAND
#define RSI_ANTENNA                1                           //@ 1 for internal antenna 2 for external antenna
#define RSI_DATA_RATE              RSI_DATA_RATE_AUTO          //@ RSI_DATA_RATE_AUTO or RSI_DATA_RATE_(1, 2, 5P5, 11, 6, 9, 12)
#define RSI_POWER_LEVEL            RSI_POWER_LEVEL_HIGH        //@ RSI_POWER_LEVEL_LOW or RSI_POWER_LEVEL_MEDIUM or RSI_POWER_LEVEL_HIGH
#define RSI_STORE_CONFIG           DISABLE                     //@ ENABLE or DISABLE store configuration

#define RSI_WIFI_OPER_MODE             0                       //@ 0-For legacy client , 1-P2p mode , 2-Enterprise security mode, 6- AP mode, 8-per mode 
#define RSI_COEX_MODE                  5                       //@ 0-wlan only, 3- wlan+zigbee coex 5- wlan+bt coex  13- wlan+btle coex
#define RSI_OPERMODE               (RSI_WIFI_OPER_MODE | ( RSI_COEX_MODE << 16))            
#define RSI_FEATURE_BIT_MAP        FEAT_SECURITY_OPEN          //@ To set wlan feature select bit map
#define RSI_TCP_IP_FEATURE_BIT_MAP (TCP_IP_FEAT_DHCPV4_CLIENT | TCP_IP_FEAT_HTTP_SERVER | TCP_IP_FEAT_SSL)

#define RSI_NO_OF_CLIENTS_SUPPORTED 1                          //@ Number of clients to support possible values 1 to 8            
#define RSI_CUSTOM_FEATURE_BIT_MAP ((RSI_NO_OF_CLIENTS_SUPPORTED << 13))                           //@ To set custom feature select bit map 

#define RSI_SECURITY_MODE          SECURITY_MODE_OPEN          //@ For selecting different security mode APs.
#define RSI_PSK_SUPPORT            DISABLE                     //@ ENABLE or DISABLE PSK support
#define RSI_PSK                    ""                          //@ PSK.If we are using WPA2, this is the key, In open mode NULL
#define RSI_PMK                    ""                          //@ PMK "661cb4a09ddffbb778372f302900919d57b5e065a261234de7b2962ca7a0d830"//"1d55d6ad23a22b46af91b222348e9a195341204320fed8b6b4193ce557c0d555"
#define RSI_PSK_TYPE               RSI_PSK_FROM_HOST           //@ RSI_PSK_FROM_HOST or RSI_PMK_FROM_HOST or RSI_GENERATE_PMK
#define RSI_SCAN_SSID              "TPLINK"                    //@ SSID to scan, null string ("") to scans all ssids
#define RSI_SCAN_CHANNEL           0                           //@ scan channel number.0 to scans all channels
#define RSI_SCAN_CHANNEL_BIT_MAP_2_4    31                     //@ scan channle bit map,valid if RSI_SCAN_CHANNEL is 0
#define RSI_SCAN_CHANNEL_BIT_MAP_5      15                     //@ scan channle bit map,valid if RSI_SCAN_CHANNEL is 0
#define RSI_JOIN_SSID              "TPLINK"                    //@ SSID to join
#define SEND_PSK_IN_JOIN           1                           //@ 1-to send PSK in join frame, 0 - not to send PSK in join
#define RSI_MAC_ADDRESS            "00:17:34:51:68:85"         //@ MAC address of the module
//@ Power save Parameters
#define RSI_POWER_MODE             RSI_POWER_MODE_0            //@ RSI_POWER_MODE_0 or RSI_POWER_MODE_1 or RSI_POWER_MODE_2 or  
                                                               //@ RSI_POWER_MODE_3 or RSI_POWER_MODE_8 or RSI_POWER_MODE_9 
/* sleep timer value */
#define RSI_TIMEVAL                10                          //@ Sleep time value in seconds used in power save mode 9

/* WEPKEY support */
#define RSI_WEP_INDEX              0                           //@ WEP key index to use. Possible values are 0 to 3
#define RSI_WEPKEY0                "1234567890"                //@ WEP KEY1 
#define RSI_WEPKEY1                "1234567980"                //@ WEP KEY2
#define RSI_WEPKEY2                "1234567120"                //@ WEP KEY3
#define RSI_WEPKEY3                "1234567130"                //@ WEP KEY4

//@ DEBUG prints support
#define RSI_DEBUG_PRINTS_ENABLE        DISABLE                 //@ ENABLE or DISABLE debug prints
#define RSI_DEBUG_ASSERTION_TYPE       4                       //@ type 1 to 4
#define RSI_DEBUG_ASSERTION_LEVEL      15                      //@ level 1 to 15

//@ Roaming related info
#define RSI_ROAMING_SUPPORT            DISABLE                 //@ ENABLE or DISABLE roaming support
#define RSI_ROAMING_THRESHOLD          10                      //@ roaming threshold value 
#define RSI_ROAMING_HYSTERISIS         4                       //@ roaming hysterisis value

//@ Rejoin params related info
#define RSI_ENABLE_REJOIN_PARAMS       DISABLE                 //@ ENABLE or DISABLE rejoin params
#define RSI_REJOIN_MAX_RETRY           0                       //@ Rejoin retry count. If 0 retries infinity times
#define RSI_REJOIN_SCAN_INTERVAL       4                       //@ Periodicity of rejoin attempt
#define RSI_REJOIN_BEACON_MISSED_CNT   40                      //@ Beacon missed count
#define RSI_REJOIN_FIRST_TIME_RETRY    DISABLE                 //@ ENABLE or DISABLE retry for first time join failure

//@ High Throughput Capabilies related information
#define RSI_MODE_11N_ENABLE            DISABLE                 //@ ENABLE or DISABLE 11n mode in AP mode
#define RSI_HT_CAPS_BIT_MAP            10                      //@ HT caps bit map.

//@ WMM PS parameters
#define RSI_WMM_PS_SUPPORT             DISABLE                 //@ ENABLE or DISABLE WMM PS support
#define RSI_WMM_PS_TYPE                0                       //@ 0 - wmm_ps tx based, 1- wmm ps periodic
#define RSI_WMM_PS_WAKEUP_INTERVAL     0                       //@ wmm ps wakeup interval
#define RSI_WMM_PS_UAPSD_BITMAP        0                       //@ wmm ps uapsd bit map. Possible values are 0 to 15

//@ WPS Method params
#define RSI_WPS_SUPPORT                DISABLE                 //@ ENABLE or DISABLE WPS support
#define RSI_WPS_METHOD                 RSI_WPS_PIN_METHOD      //@ RSI_WPS_PIN_METHOD or RSI_WPS_PUSH_METHOD
#define RSI_GENERATE_PIN               DISABLE                 //@ ENABLE-GENERATE or DISABLE-VALIDATE WPS PIN
#define RSI_WPS_PIN                    ""                      //@ WPS pin 

/* Enable or Disable BG scan command */
#define RSI_BG_SCAN_ENABLE             DISABLE                 //@ ENABLE or DISABLE BG scan
#define RSI_INSTANT_BG                 DISABLE                 //@ ENABLE or DISABLE instant BG scan
#define RSI_BG_SCAN_THRESHOLD          10                      //@ BG scan threshold value
#define RSI_RSSI_TOLERANCE_THRESHOLD   4                       //@ RSSI tolerance Threshold
#define RSI_BG_SCAN_PERIODICITY        10                      //@ BG scan periodicity 
#define RSI_ACTIVE_SCAN_DURATION       15                      //@ Active scan duration
#define RSI_PASSIVE_SCAN_DURATION      20                      //@ Passive scan duration
#define RSI_MULTIPROBE                 DISABLE

/*For Disconnect command*/
#define MODE_FLAG                      1                       //@ Disconnect mode.0 for client and 1 for AP
#define CLIENT_MAC_ADDRESS             "00:17:34:51:68:86"     //@ MAC address of the client to be disconnected

/*Mac address filter*/
#define RSI_MULTICAST_FILTER_ENABLE    DISABLE                   //@ ENABLE or DIABLE multicast filter   
#define RSI_MULTICAST_MAC_CMD_TYPE     RSI_MULTICAST_MAC_SET_ALL //@ RSI_MULTICAST_MAC_ADD_BIT or RSI_MULTICAST_MAC_CLEAR_BIT or RSI_MULTICAST_MAC_CLEAR_ALL or RSI_MULTICAST_MAC_SET_ALL
#define RSI_MULTICAST_MAC_ADDRESS      "01:00:5E:7F:FF:FA"       //@ MAC address used to calculate hash value for multicast filtering

#define CLIENT_MODE                    (RSI_WIFI_OPER_MODE == 0)
#define P2P_MODE                       (RSI_WIFI_OPER_MODE == 1)
#define ENTERPRISE_MODE                (RSI_WIFI_OPER_MODE == 2)
#define AP_MODE                        (RSI_WIFI_OPER_MODE == 6)
#define PER_MODE                       (RSI_WIFI_OPER_MODE == 8)


#if (RSI_WIFI_OPER_MODE == 0|| RSI_WIFI_OPER_MODE == 2)
//Set region parameters
#define SET_REGION_SUPPORT             DISABLE                 //@ ENABLE or DISABLE set region
#define SET_REGION_FROM_USER_OR_BEACON 1                       //@ IF 1:region configurations taken from user ;0:region configurations taken from beacon
#define REGION_CODE                    1                       //@ 0-Default Region domain ,1-US, 2-EUROPE, 3-JAPAN
#endif

#if(RSI_WIFI_OPER_MODE == 6)
#define SET_REGION_AP_SUPPORT          DISABLE                 //@ ENABLE or DISABLE set region AP
#define SET_REGION_AP_FROM_USER        ENABLE                  //@ IF 1:region configurations taken from user ;0:region configurations taken from firmware
#define RSI_COUNTRY_CODE               "US "                   //@ "US" or "EU" or "JP" or other region codes
#endif

/* P2P mode Configurations */
#define P2P_DEVICE_NAME                "WSC1.1"                //@ P2P device name
#define POST_FIX_SSID                  "WSC_1_0_0"             //@ P2P prefix name
#define GO_INTENT_VALUE                15                      //@ P2P go intent value.possible value are 0 to 16
#define P2P_OPER_CHANNEL               11                      //@ P2P operating channel 

/* Enterprise client mode configurations */
#define CERT_LEN                       6522                    //@ Certificate length, ZERO in case of clearing the certificate
#define EAP_METHOD                     "TTLS"                  //@ Eap method TTLS, TLS, PEAP, FAST
#define EAP_CERTIFICATE_TYPE		       RSI_EAP_TLS_CERTIFICATE //@ certificate to be loaded RSI_EAP_TLS_CERTIFICATE or RSI_EAP_FAST_PAC_CERTIFICATE
#define INNER_METHOD                   "\"auth=MSCHAPV2\""     //@ Inner method MSCHAPV2
#define USER_IDENTITY                  "\"user1\""             //@ user name 
#define PASSWORD                       "\"test123\""           //@ Password
#define KEY_PASSWORD                   "\"wifi\""              //@ Key Pass word
#define EAP_OKC_ENABLE                 ENABLE                  //@ ENABLE or DISABLE Opportunistic Key Caching

/* AP mode Configurations */
#define RSI_DTIM_PERIOD                4                       //@ AP DTIM Period to configure 
#define RSI_BEACON_INTERVAL            100                     //@ AP beacon interval
#define RSI_AP_CHANNEL_NUM             1                       //@ AP channel number
#define RSI_SECURITY_TYPE              RSI_SECURITY_NONE       //@ AP security type
#define RSI_ENCRYPTION_MODE            RSI_ENCRYPTION_NONE     //@ AP Encryption type 
#define MAX_NO_OF_CLIENTS              4                       //@ AP:Maximum number of clients can connect.Possible values are 1 to 4

/* PER mode configurations */
#define RSI_PER_MODE_SUPPORT           DISABLE                 //@ ENABLE or DISABLE PER mode
#define RSI_PER_MODE_POWER             0                       //@ PER MODE power 
#define RSI_PER_MODE_RATE              RSI_RATE_1              //@ PER MODE rate
#define RSI_PER_MODE_LENGTH            30                      //@ PER MODE length
#define RSI_PER_MODE_MODE              RSI_PER_BURST_MODE      //@ PER MODE mode
#define RSI_PER_MODE_CHANNEL           1                       //@ PER MODE channel
#define RSI_PER_MODE_RATE_FLAGS        0                       //@ PER MODE rate flags
#define RSI_PER_MODE_PER_CH_BW         0                       //@ PER MODE per channel bandwidth
#define RSI_PER_MODE_AGGR_ENABLE       DISABLE                 //@ PER MODE aggregation enable or disable
#define RSI_PER_MODE_AGGR_COUNT        0                       //@ PER MODE aggregation count
#define RSI_PER_MODE_NO_OF_PKTS        0                       //@ PER MODE number of packets to send
#define RSI_PER_MODE_DELAY             0                       //@ PER MODE delay

/* PER stats configuration */
#define RSI_PER_STATS                  1                       //@ Start/Stop PER stats. 0-start, 1-stop
#define RSI_PER_STATS_CHANNEL          11                      //@ PER stats channel number


/* TCP/IP configurations */
//@ Module IP Parameters
#define RSI_IP_CFG_MODE                RSI_DHCP_IP_MODE        //@ RSI_DHCP_IP_MODE or RSI_STATIC_IP_MODE .static or DHCPV4 mode for IPv4,RSI_FEAT_DHCP_HOST_NAME for dhcp client host name from host.
#define RSI_DHCP_HOST_NAME             "dhcp_client"           //@ DHCP HOST NAME
#define RSI_IPV6_CFG_MODE              RSI_STATIC_IP_MODE      //@ RSI_DHCP_IP_MODE or RSI_STATIC_IP_MODE.static or DHCPV6 mode for IPv6
#define IPV6_SUPPORT                   DISABLE                 //@ ENABLE or DISABLE IPV6 support
#define RSI_IP_VERSION                 IP_VERSION_4            //@ IP_VERSION_4 or IP_VERSION_6. IP version to use.
#define RSI_ICMP_FROM_MODULE           DISABLE                 //@ ENABLE or DISABLE ICMP from module support

/* IPv4 parameterrs */
#define RSI_MODULE_IP_ADDRESS          "192.168.100.67"        //@ IP Address of the WiFi Module
#define RSI_GATEWAY                    "192.168.100.1"         //@ Default Gateway
#define RSI_TARGET_IP_ADDRESS          "192.168.100.120"       //@ IP Address we will connect to
#define RSI_NETMASK                    "255.255.255.0"         //@ Netmask

/* IPV6 address parameters */
#define RSI_IPV6_PREFIX_LENGTH         64                      //@ IPV6 prefix length  
#define RSI_MODULE_IPV6_ADDRESS        "2001.db8.1.0.0.0.0.123"   //@ module IPv6 address
#define RSI_TARGET_IPV6_ADDRESS        "2001.db8.1.0.0.0.0.124"   //@ Target IPv6 address
#define RSI_DEFAULT_ROUTER_IPV6_ADDRESS "2001.db8.1.0.0.0.0.1" //@ Router IPv6 address

//@ Socket Info
#define RSI_SOCKET_TYPE                RSI_SOCKET_LUDP         //@ Set type of socket to open
#define SOCKET_FEATURE                 DISABLE                 //@ DISABLE or RSI_SSL_SUPPORT or RSI_WEBS_SUPPORT or RSI_SSL_WEBS_SUPPORT or RSI_SSL_TLS_V_1 or RSI_SSL_TLS_V_1_2
#define SSL_CIPHERS                    SSL_ALL_CIPHERS         //@ Set SSL cipher 
#define RSI_MAX_LTCP_CONNECTIONS       5                       //@ Set maximum clients can connect to a LTCP socket.Possible values are 1 to 9
#define RSI_TOS                        0                       //@ Type of service. possible values are 0 to 7
#define DATA_TRANSFER_TYPE             DATA_TX                 //@ Set data transfer type DATA_TX or DATA_RX
#define WEBS_RESOURCE_NAME             "/websocket"            //@ WEBS resource name
#define WEBS_HOST_NAME                 "localhost"             //@ WEBS host name
//@ Socket Info
#define RSI_MODULE_SOCKET_ONE          5001                    //@ Module Socket/Port Number
#define RSI_TARGET_SOCKET_ONE          5001                    //@ Port Number of we will connect to

//@ Socket Info
#define RSI_MODULE_SOCKET_TWO          50000                   //@ Module Socket/Port Number
#define RSI_TARGET_SOCKET_TWO          50000                   //@ Port Number of we will connect to

//@ Socket Info
#define RSI_MODULE_SOCKET_THREE        55500                   //@ Module Socket/Port Number
#define RSI_TARGET_SOCKET_THREE        55000                   //@ Port Number of we will connect to

//@ Socket Info
#define RSI_MODULE_SOCKET_FOUR         18046                   //@ Module Socket/Port Number
#define RSI_TARGET_SOCKET_FOUR         18046                   //@ Port Number of we will connect to

//@ Socket Info
#define RSI_MODULE_SOCKET_FIVE         15046                   //@ Module Socket/Port Number
#define RSI_TARGET_SOCKET_FIVE         15046                   //@ Port Number of we will connect to

//@ Socket Info
#define RSI_MODULE_SOCKET_SIX          16046                   //@ Module Socket/Port Number
#define RSI_TARGET_SOCKET_SIX          16046                   //@ Port Number of we will connect to

//@ Socket Info
#define RSI_MODULE_SOCKET_SEVEN        17046                   //@ Module Socket/Port Number
#define RSI_TARGET_SOCKET_SEVEN        17046                   //@ Port Number of we will connect to

/* Webpage bypass */
#define WEBPAGE_BYPASS_SUPPORT         DISABLE                  //@ Enable or Disable webpage bypass feature

//@ multicast params
#define RSI_MULTICAST_SUPPORT              DISABLE             //@ ENABLE or DISABLE multicast support
#define RSI_MULTICAST_MESSAGE_TYPE         RSI_MULTICAST_JOIN  //@ RSI_MULTICAST_JOIN or RSI_MULTICAST_LEAVE
#define RSI_MULTICAST_GROUP_IPV4_ADDRESS   "239.255.0.1"       //@ Multicast IPv4 address
#define RSI_MULTICAST_GROUP_IPV6_ADDRESS   "FF01:0:0:0:0:0:0:1"//@ Multicast IPv6 address

/* HTTP GET/POST REQ */
#define RSI_HTTP_URL                 "/index.html"             //@ HTTP URL name
#define RSI_HTTP_IP                  "192.168.1.2"             //@ HTTP server IPv4 address
#define RSI_HTTP_IPV6                "2001.db8.1.0.0.0.0.124"  //@ HTTP server IPv6 address
#define RSI_HTTP_DATA                "START+++Readpine Signals String+++END" //@ HTTP data to send
#define RSI_HTTPS_SUPPORT             0                        //@ 1 to enable HTTPS support or RSI_SSL_TLS_V_1 or RSI_SSL_TLS_V_1_2
#define RSI_HTTP_USERNAME            "username"                //@ set HTTP user name
#define RSI_HTTP_PASSWORD            "password"                //@ set HTTP password
#define RSI_HTTP_HOSTNAME            "192.168.1.101"           //@ set HTTP hostname
#define RSI_HTTP_SERVER_PORT         80                        //@ set HTTP port number

/* set DNS sever */
#define RSI_DNS_CFG_MODE                RSI_DNS_MODE_DISABLE   //@ RSI_DNS_MODE_DISABLE - DNS IP takes from User or RSI_DNS_MODE_ENABLE - DNS IP takes through DHCP
#define RSI_PRIMARY_DNS_IP_ADDRESS      "4.2.2.2"              //@ Primary DNS IPv4 address
#define RSI_SECONDARY_DNS_IP_ADDRESS    "8.8.8.8"              //@ Secondary DNS IPv4 address
#define RSI_PRIMARY_DNS_IPV6_ADDRESS    "2001.db8.1.0.0.0.0.4" //@ Primary DNS IPv6 address
#define RSI_SECONDARY_DNS_IPV6_ADDRESS  "2001.db8.1.0.0.0.0.5" //@ Secondary DNS IPv6 address
#define DNS_QRY_URL                     "www.google.com"       //@ DNS URL to query  
#define DNS_SERVER_NUM                  1                      //@ 1 or 2.Primary or secondary DNS server to use for quering DNS request

/* Webpage related configuration */
#define WEB_PAGE_LOAD                 DISABLE                  //@ ENABLE or DISABLE web page load support
#define WEB_PAGE_FILENAME             "sample.html"            //@ web page file name to load
#define WEB_PAGE_LENGTH               2783                     //@ Length of the webpage to load
#define WEB_PAGE_HAS_JSON             1                        //@ 0 or 1. 1 - web page contains JSON, 0 -web page does not contain JSON
#define WEB_PAGE_CLEAR_ALL_FILES      1

/* JSON data configuration */
#define JSON_LOAD                     DISABLE                  //@ ENABLE or DISABLE JSON load
#define JSON_FILENAME                 "sample.html"            //@ file name for which JSON has to be load

/*Ping command params*/
#define RSI_PING_VERSION              IP_VERSION_4             //@ PING IP version to use 
#define RSI_PING_DATA_SIZE            40                       //@ PING size. Possible values are 1 to 300
#define RSI_PING_TARGET_IP            "192.168.1.104"          //@ PING target IPv4 address  
#define RSI_PING_TARGET_IPV6          "2001.db8.1.0.0.0.0.120" //@ PING target IPv6 address

/* SNMP PARAMTERS */
#define SNMP_SUPPORT                  DISABLE                  //@ ENABLE or DISABLE SNMP support
#define RSI_SNMP_ENABLE               DISABLE                  //@ ENABLE or DISABLE SNMP agent functionality
#define RSI_SNMP_OBJ_TYPE             SNMP_ANS1_OCTET_STRING   //@ SNMP object type
#define RSI_SNMP_OBJ_VALUE            "sample snmp object"     //@ SNMP object value 

#define RSI_SNMP_VERSION              SNMP_VERSION_2           //@ SNMP version to use
#define RSI_SNMP_TARGET_IP_ADDRESS    "192.168.10.10"          //@ SNMMP target IPv4 address
#define RSI_SNMP_TARGET_IPV6_ADDRESS  "2001.db8.1.0.0.0.0.123" //@ SNMP target IPv6 address
#define RSI_SNMP_COMMUNITY            "public"                 //@ SNMP community
#define RSI_SNMP_TRAP_TYPE            SNMP_TRAP_WARM_START     //@ SNMP trap type
#define RSI_SNMP_ELAPSED_TIME         1234                     //@ SNMP Elapsed time

//@ User Store configuration
#define  ENABLE_USER_STORE_CONFIGURATION     DISABLE                 //@ ENABLE or DISABLE User store configuration support
#define  RSI_STORE_PMK_SUPPORT               ENABLE                  //@ ENABLE or DISABLE storing PMK
#define  RSI_STORE_WEP_KEY_SUPPORT           ENABLE                  //@ ENABLE or DISABLE storing WEP key
#define  RSI_STORE_IPV6_ENABLE               ENABLE                  //@ ENABLE or DISABLE IPV6 related paramerters
//! Enable or disable Auto join/Auto create
#define  USER_CFG_CFG_ENABLE                 DISABLE                 //@ Enable or disable store configuration
//!Opermode parameters
#define  USER_CFG_WLAN_OPERMODE              0                       //@ 0-For legacy client , 1-P2p mode , 2-Enterprise security mode, 6- AP mode, 8-per mode  
#define  USER_CFG_COEX_MODE                  0                       //@ 0-wlan only, 3- wlan+zigbee coex 5- wlan+bt coex  13- wlan+btle coex    
#define  USER_CFG_OPERMODE                   (USER_CFG_WLAN_OPERMODE|(USER_CFG_COEX_MODE << 16))                           //@ opermode
#define  USER_CFG_FEATURE_BIT_MAP            FEAT_SECURITY_OPEN      //@ Station Security type
#define  USER_CFG_TCP_IP_FEATURE_BIT_MAP     (TCP_IP_FEAT_DHCPV4_CLIENT | TCP_IP_FEAT_HTTP_SERVER)
#define  USER_CFG_NO_OF_CLIENTS_SUPPORTED    1                       //@ Number of clients to support possible values 1 to 8
#define  USER_CFG_CUSTOM_FEATURE_BIT_MAP     (USER_CFG_NO_OF_CLIENTS_SUPPORTED << 13)                       //@ Custom
//! Band
#define  USER_CFG_BAND                       0                       //@ Band
//! Tcp ip stack used
#define  USER_CFG_TCP_STACK_USED             1                       //@ 1 - ipv4, 2 - ipv6, 3 - BOTH
//! network type
#define  USER_CFG_NETWORK_TYPE               STA_INFRASTRUCTURE      //@ Network type
//! Join parameters
#define  USER_CFG_JOIN_SSID                  "TPLINK"                //@ SSid to join in station mode
#define  USER_CFG_URATE                      RSI_DATA_RATE_AUTO      //@ join data rate
#define  USER_CFG_UTX_POWER                  RSI_POWER_LEVEL_HIGH    //@ Join @power level
#define  USER_CFG_CHANNEL_SECURITY_MODE      SECURITY_MODE_OPEN      //@ Type of security 

#if (USER_CFG_OPERMODE == 0 ||USER_CFG_OPERMODE == 2)
#define  USER_CFG_PSK                        ""              		 //@ PSK  12345678
//! PMK key for client
#define  USER_CFG_PMK                        ""                      //@ PMK key 992194d7a6158009bfa25773108291642f28a0c32a31ab2556a15dee97ef0dbb
#endif

#if (USER_CFG_OPERMODE == 0 ||USER_CFG_OPERMODE == 2)
#define  USER_CFG_SCAN_SSID                  "TPLINK"                //@ Scan ssid
#define  USER_CFG_SCAN_CHANN_NUM             1                       //@ Scan channel number
#define  USER_CFG_SCAN_CHAN_BITMAP_STORED_2_4_GHZ      31        	 //@ Scan channel bitmap for 2.4ghz
#define  USER_CFG_SCAN_SCAN_CHAN_BITMAP_STORED_5_GHZ   15    	     //@ scan channel bitmap for 5ghz

#endif

#if((USER_CFG_TCP_STACK_USED == 1 ||USER_CFG_TCP_STACK_USED == 3 ))
//! IPv4 configuration parameters
#define  USER_CFG_DHCP_ENABLE                ENABLE                       //@ Dhcp enable or disable
#define  USER_CFG_IPV4_ADDRESS               "192.168.100.67"         //@ IPv4 address of module
#define  USER_CFG_SUBNETMASKV4_ADDRESS       "255.255.255.0"          //@ IPv4 subnet mask address
#define  USER_CFG_GATEWAYV4_ADDRESS          "192.168.100.1"          //@ IPv4 Gateway address
#endif
#if (USER_CFG_OPERMODE == 2)
//! Enterprise security parameters
#define  USER_CFG_EAP_METHOD                 "TTLS"                  //@ EAP Method to be used
#define  USER_CFG_INNER_METHOD               "\"auth=MSCHAPV2\""     //@ Inner method
#define  USER_CFG_USER_IDENTITY              "\"user1\""             //@ User identity
#define  USER_CFG_PASSWORD                   "\"test123\""           //@ User password
#endif
#if (USER_CFG_OPERMODE == 1)
//! Wifi direct parameters (This feature is not supported in auto join or auto create)
#define  USER_CFG_GO_INTENT                  15                      //@ GO intent value
#define  USER_CFG_DEVICE_NAME                "WSC1.1"                //@ Device name
#define  USER_CFG_OPERATING_CHANNEL          11                      //@ Operating channel
#define  USER_CFG_SSID_POSTFIX               "WSC_1_0_0"             //@ Ssid postfix
#define  USER_CFG_PSK_KEY                    "12345678"              //@ PSK key for AP
#endif


#if (USER_CFG_OPERMODE == 6)
//! AP configuration parameters
#define  USER_CFG_APCONFIG_CHANNEL_NUM       1                       //@ AP configuration channel number
#define  USER_CFG_APCONFIG_SSID              "TPLINK"                //@ SSID of Access point
#define  USER_CFG_APCONFIG_SECURITY_TYPE     RSI_SECURITY_NONE       //@ Security mode of AP
#define  USER_CFG_APCONFIG_ENCRYP_MODE       RSI_ENCRYPTION_NONE     //@ Encryption mode of AP
#define  USER_CFG_APCONFIG_PSK               ""                      //@ PSK of AP
#define  USER_CFG_APCONFIG_BEACON_INTERVAL   100                     //@ Beacon interval
#define  USER_CFG_APCONFIG_DTIM_PERIOD       4                       //@ DTIM period
#define  USER_CFG_APCONFIG_MAX_STA_SUPPORT   4                       //@ Max station support by AP
#endif
//! Module MAC Address
//! Module MAC should be set to 00:00:00:00:00:00
//! if user does not want to change the MAC address
#define  USER_CFG_MODULE_MAC                 "00:00:00:00:00:00"     //@ MAC address of module
#define  USER_CFG_ANTENNA_SELECT             1                       //@ 1 for internal antenna 2 for external antenna 
#if(USER_CFG_OPERMODE == 0)
#if RSI_STORE_WEP_KEY_SUPPORT 
#define  USER_CFG_WEPKEY_INDEX               0                       //@ WEP key index valid values are 0 to 3
#define  USER_CFG_WEPKEY_KEY0                "1234567890"            //@ WEP key0
#define  USER_CFG_WEPKEY_KEY1                "1234567980"            //@ WEP key1
#define  USER_CFG_WEPKEY_KEY2                "1234567120"            //@ WEP key2
#define  USER_CFG_WEPKEY_KEY3                "1234567130"            //@ WEP key3
#endif
#endif

#if(USER_CFG_TCP_STACK_USED == 2 ||USER_CFG_TCP_STACK_USED == 3 )
//! IPv6 configuration parameters
#if RSI_STORE_IPV6_ENABLE
#define  USER_CFG_DHCPV6_ENABLE              0                       //@ ENABLE or DISABLE DHCPv6 mode
#define  USER_CFG_PREFIX_LENGTH              64                      //@ Prefix length
#define  USER_CFG_IPV6_ADDRESS               "2001.db8.1.0.0.0.0.123"//@ IPV6 address of module
#define  USER_CFG_GATEWAYV6_ADDRESS          "2001.db8.1.0.0.0.0.120"//@ IPv6 Gateway
#endif
#endif
#define   RSI_MAGIC_CODE                     0x4321                  //@ Magic code
#if (USER_CFG_OPERMODE == 0 || USER_CFG_OPERMODE == 2 )
//!Bg scan Parameters
#define   USER_CFG_BGSCAN_ENABLE                        DISABLE             //@ ENABLE or DISABLE BG scan
#define   USER_CFG_BGSCAN_THRESHOLD                     10                  //@ BG scan threshold value
#define   USER_CFG_BGSCAN_RSSI_TOLERANCE_THRESHOLD      4                   //@ BG scan threshold value
#define   USER_CFG_BGSCAN_PERIODICITY                   10                  //@ BG scan periodicity
#define   USER_CFG_BGSCAN_ACTIVE_SCAN_DURATION          15                  //@ Active scan duration
#define   USER_CFG_BGSCAN_PASSIVE_SCAN_DURATION         20                  //@ Passive scan duration
#define   USER_CFG_BGSCAN_MULTI_PROBE                   ENABLE              //@ Enable or disable multi probe
#endif
#if (USER_CFG_OPERMODE == 0||USER_CFG_OPERMODE == 1 || USER_CFG_OPERMODE == 2)
//!Roaming information
#define   USER_CFG_ROAM_ENABLE                          DISABLE             //@ ENABLE or DISABLE roaming
#define   USER_CFG_ROAM_THRESHOLD                       10                  //@ Roaming threshold value
#define   USER_CFG_ROAM_HYSTERESIS                      4                   //@ Roam hysterisis  value
#endif
#if(USER_CFG_OPERMODE == 0|| USER_CFG_OPERMODE == 2)
//!Rejoin information
#define   USER_CFG_REJOIN_MAX_RETRY_COUNT               0                   //@ Rejoin Max retry count
#define   USER_CFG_REJOIN_SCAN_INTERVAL                 4                   //@ Rejoin scan interval
#define   USER_CFG_REJOIN_BEACON_MISSED_COUNT           40                  //@ Beacon missed count
#define   USER_CFG_REJOIN_FIRST_TIME_RETRY_ENABLE       DISABLE             //@ ENABLE or disable first time retry
#endif
#if(USER_CFG_OPERMODE == 0 || USER_CFG_OPERMODE == 2 || USER_CFG_OPERMODE == 6)
#define   USER_CFG_REGION_REQUEST_FROM_HOST             DISABLE             //@ ENABLE or DISABLE set region
#define   USER_CFG_REGION_CODE_FROM_HOST                DISABLE             //@ IF 1:region configurations taken from user ;0:region configurations taken from beacon(If opermode is 0 or 2)
																			 //@ Should be Disable in AP mode.Disable:Takes the region regulations(from flash) based on the region code
#define   USER_CFG_REGION_CODE                          1                   //@ 0-Default Region domain ,1-US, 2-EUROPE, 3-JAPAN

#define   SECURITY_MODE_OPEN      0             //@ Open mode or Dont care
#define   SECURITY_MODE_WPA       1             //@ Selects only WPA mode AP
#define   SECURITY_MODE_WPA2      2             //@ Selects only WPA2 mode AP
#define   SECURITY_MODE_MIXED     6             //@ For Mixed Mode AP
#endif
/*==============================================*/
/**
 * Function Prototypes
 */
int16 rsi_init_struct(rsi_api *ptrStrApi);
#endif
