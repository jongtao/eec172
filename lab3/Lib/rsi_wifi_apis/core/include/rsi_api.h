/**
 * @file     rsi_api.h
 * @version  3.6
 * @date     2013-May-16
 *
 *
 * @section License
 * This program should be used on your own responsibility.
 * Redpine Signals assumes no responsibility for any losses
 * incurred by customers or third parties arising from the use of this file.
 *
 * @brief HEADER: API specific Defines
 *
 * @section Description
 * This file contains the function prototypes of the APIs defined in library, and defines used in API's.
 * Copyright(C) Redpine Signals 2013
 * All rights reserved by Redpine Signals.
 */


#ifndef _SPIAPI_H_
#define _SPIAPI_H_

#ifdef __cplusplus
extern "C"{
#endif

/**
 * Include Files
 */
#include "rsi_global.h"
#include "rsi_app_util.h"
/**
 * Global Defines
 */

//! Upgrade Image types
#define RSI_UPGRADE_WLAN_FW              '2'
#define RSI_UPGRADE_BT_FW                '4'
#define RSI_UPGRADE_BL                   '#'

//!Load Image types
#define RSI_LOAD_WLAN_FW                  '1'
#define RSI_LOAD_BT_FW                    '3'
#define RSI_LOAD_WLAN_ACTIVE_LOW_FW       0x71 
#define RSI_LOAD_BT_ACTIVE_LOW_FW         0x73

//!Select Default image
#define RSI_SELECT_WLAN_BY_DEFAULT        '5'
#define RSI_SELECT_BT_ZIGBEE_BY_DEFAULT   '6'

// bypass bootup
#define RSI_ENABLE_BOOT_BYPASS            '7'
#define RSI_DISABLE_BOOT_BYPASS           '8'

//!load default
#define RSI_LOAD_DEFAULT                  '9'

#define HOST_INTF_REG_OUT                 0x4105003C
#define HOST_INTF_REG_IN                  0x41050034
#define BOARD_READY                       0xABCD  
#define REG_READ                          0xD1
#define REG_WRITE                         0xD2
#define PONG_WRITE                        0xD4
#define PING_WRITE                        0xD5
#define HOST_INTERACT_REG_VALID           (0xAB << 8)
#define PONG_AVAIL                        'O'
#define PING_AVAIL                        'I'
#define PONG_VALID                        'O'   
#define PING_VALID                        'I'   
#define LOADING_INITIATED                 '1'
#define SEND_RPS_FILE                     '2'
#define FWUP_SUCCESSFUL                   'S'
#define EOF_REACHED                       'E'

#define RSI_SUCCESS                        0
#define RSI_BUSY                           -1
#define RSI_FAIL                           -2
#define RSI_BUFFER_FULL                    -3
#define RSI_IN_SLEEP                       -4


//!SPI Internal Register Offset
#define RSI_SPI_INT_REG_ADDR               0x00      //@ register access method
#define RSI_SPI_MODE_REG_ADDR              0x08      //@ register access method

//!Power Mode Constants
#define RSI_POWER_MODE_0                   0x0000
#define RSI_POWER_MODE_1                   0x0001
#define RSI_POWER_MODE_2                   0x0002
#define RSI_POWER_MODE_3                   0x0003
#define RSI_POWER_MODE_8                   0x0008
#define RSI_POWER_MODE_9                   0x0009

//!Tx Power level
#define RSI_POWER_LEVEL_LOW                0x0000
#define RSI_POWER_LEVEL_MEDIUM             0x0001
#define RSI_POWER_LEVEL_HIGH               0x0002


//!Interrupt Defines
#define RSI_INT_MASK_REG_ADDR              0x41050000      //@ Interrupt mask register
#define RSI_INT_CLR_REG_ADDR               0x22000010      //@ Interrupt clear register
//!bit5=1 to clear the interrupt, must use read-modify-write to preserver the other bits


/*======================================================*/
//!Management Request Frame Codes (Type)
#define RSI_REQ_OPERMODE                   0x10
#define RSI_REQ_BAND                       0x11
#define RSI_REQ_INIT                       0x12
#define RSI_REQ_SCAN                       0x13
#define RSI_REQ_JOIN                       0x14
#define RSI_REQ_PWRMODE                    0x15
#define RSI_REQ_SLEEP_TIMER                0x16
#define RSI_REQ_SET_MAC_ADDR               0x17
#define RSI_REQ_QUERY_NETWORK_PARAMS       0x18
#define RSI_REQ_DISCONNECT                 0x19
#define RSI_REQ_RSSI_QUERY                 0x3A
#define RSI_REQ_ANTENNA_SEL                0x1B
#define RSI_REQ_SET_REG_CODE               0x1D 
#define RSI_REQ_FEATSEL                    0x1E
#define RSI_REQ_SNR                        0x1F
#define RSI_REQ_CFG_SAVE                   0x20
#define RSI_REQ_CFG_ENABLE                 0x21
#define RSI_REQ_CFG_GET                    0x22
#define RSI_REQ_USER_STORE_CFG             0x23
#define RSI_REQ_APCONFIG                   0x24
#define RSI_REQ_SET_WEP_KEY                0x25
#define RSI_REQ_DEBUG_PRINTS               0x26
#define RSI_REQ_GPIO_CONF                  0x28
#define RSI_REQ_PING_PACKET                0x29
#define RSI_REQ_MULTICAST_FILTER           0x40
#define RSI_REQ_HOST_WEBPAGE               0x64
#define RSI_REQ_BG_SCAN                    0x6a
#define RSI_REQ_REJOIN_PARAMS              0x6F

//!IPV6 IPCONFIG REQ
#define RSI_REQ_IPCONF6                    0x90

//!SNMP COMMANDS
#define RSI_REQ_SNMP_GET                   0x80
#define RSI_REQ_SNMP_GETNEXT               0x81
#define RSI_REQ_SNMP_SET                   0x82

#define RSI_REQ_SNMP_ENABLE                0x85
#define RSI_REQ_SNMP_TRAP                  0x86

#define RSI_REQ_CREATE_JSON                0x9C
#define RSI_REQ_CLEAR_FILES                0x7F
#define RSI_REQ_ERASE_FILE                 0x9A
#define RSI_REQ_ERASE_JSON                 0x9B
#define RSI_REQ_HOST_PSK                   0xA5
#define RSI_REQ_MULTICAST                  0xB1
#define RSI_REQ_SET_REG_AP                 0xBD
#define RSI_REQ_IPPARAM_CONFIG             0x41
#define RSI_REQ_SOCKET_CREATE              0x42
#define RSI_REQ_SOCKET_CLOSE               0x43
#define RSI_REQ_DNS_QRY                    0x44
#define RSI_REQ_TCP_CONN_STATUS_QUERY      0x46
#define RSI_REQ_CONNECTION_STATUS          0x48
#define RSI_REQ_FWVERSION_QUERY            0x49
#define RSI_REQ_GET_MAC_ADDR               0x4A
#define RSI_REQ_CFG_P2P                    0x4B
#define RSI_REQ_SET_EAP_CFG                0x4C
#define RSI_REQ_SET_CERT                   0x4D
#define RSI_REQ_QUERY_GO_PARAMS            0x4E
#define RSI_REQ_GET_WEBFIELDS              0x4F
#define RSI_REQ_GET_WEBPAGE                0x50
#define RSI_REQ_HTTP_GET                   0x51
#define RSI_REQ_HTTP_POST                  0x52

//!Roaming parameter request
#define RSI_REQ_ROAM_PARAMS                0x7B

//!HT CAPS request
#define RSI_REQ_AP_HT_CAPS                 0x6D


//!WMM PS request
#define RSI_REQ_WMM_PS                     0x97

//!WPS MEHOD request
#define RSI_REQ_WPS_METHOD                 0x72

//!PER MODE request
#define RSI_REQ_PER_PARAMS                 0x7c

//! PER stats request
#define RSI_REQ_PER_STATS                  0xA2

//!Wireless firmware upgradation 
#define RSI_FWUP_REQ                       0x59

//! Management Response Frame Codes
#define RSI_RSP_CARD_READY                 0x89
#define RSI_RSP_OPERMODE                   0x10
#define RSI_RSP_BAND                       0x11
#define RSI_RSP_INIT                       0x12
#define RSI_RSP_SCAN                       0x13
#define RSI_RSP_JOIN                       0x14
#define RSI_RSP_PWRMODE                    0x15
#define RSI_RSP_SLEEP_TIMER                0x16
#define RSI_RSP_MACADDRESS_SET             0x17
#define RSI_RSP_NETWORK_PARAMS             0x18
#define RSI_RSP_DISCONNECT                 0x19
#define RSI_RSP_RSSI_QUERY                 0x3A
#define RSI_RSP_ANTENNA_SEL                0x1B
#define RSI_RSP_SOFT_RESET                 0x1C
#define RSI_RSP_SET_REG_CODE               0x1D 
#define RSI_RSP_FEATSEL                    0x1E
#define RSI_RSP_SNR                        0x1F
#define RSI_RSP_CFG_SAVE                   0x20
#define RSI_RSP_CFG_ENABLE                 0x21
#define RSI_RSP_CFG_GET                    0x22
#define RSI_RSP_USER_STORE_CFG             0x23
#define RSI_RSP_APCONFIG                   0x24
#define RSI_RSP_SET_WEP_KEY                0x25
#define RSI_RSP_DEBUG_PRINTS               0x26
#define RSI_RSP_GPIO_CONF                  0x28
#define RSI_RSP_PING_PACKET                0x29
#define RSI_RSP_P2P_CONNREQ                0x30
#define RSI_RSP_MULTICAST_FILTER           0x40
#define RSI_RSP_BG_SCAN                    0x6a
#define RSI_RSP_REJOIN_PARAMS              0x6F
#define RSI_RSP_MODULE_STATE               0x70


//!SNMP RESPONSES
#define RSI_RSP_SNMP_GET_RSP               0x83
#define RSI_RSP_SNMP_GETNEXT_RSP           0x84
#define RSI_RSP_SNMP_ENABLE                0x85
#define RSI_RSP_SNMP_TRAP                  0x86

//!IPV6 IPCONFIG RSP
#define RSI_RSP_IPCONF6                    0xa1

//! PER stats RSP
#define RSI_RSP_PER_STATS                  0xA2

//!IP change ASYNC MSG 
#define RSI_RSP_IPCHANGE_NOTIFY            0xaa
#define RSI_RSP_HOST_PSK                   0xA5
#define RSI_RSP_SET_REG_AP                 0xBD
#define RSI_FWUP_OK                        0x5a

//! Control Response Frame Codes
#define RSI_RSP_NULL                       0x00
#define RSI_RSP_IPPARAM_CONFIG             0x41
#define RSI_RSP_SOCKET_CREATE              0x42
#define RSI_RSP_CLOSE                      0x43
#define RSI_RSP_DNS_QRY                    0x44
#define RSI_RSP_TCP_CONN_STATUS_QUERY      0x46
#define RSI_RSP_CONNECTION_STATUS          0x48
#define RSI_RSP_FWVERSION_QUERY            0x49
#define RSI_RSP_MAC_QUERY                  0x4A
#define RSI_RSP_CFG_P2P                    0x4B
#define RSI_RSP_SET_EAP_CFG                0x4C
#define RSI_RSP_SET_CERT                   0x4D
#define RSI_RSP_QUERY_GO_PARAMS            0x4E
#define RSI_RSP_GET_WEBFIELDS              0x4F  
#define RSI_RSP_GET_WEBPAGE                0x50
#define RSI_RSP_HTTP_GET                   0x51
#define RSI_RSP_HTTP_POST                  0x52
#define RSI_RSP_SENT_BYTES                 0xB2


//!Roaming parameter response
#define RSI_RSP_ROAM_PARAMS                0x7B


#define RSI_RESP_WFD_DEV                   0x54
#define RSI_RSP_CONN_ESTABLISH             0x61
#define RSI_RSP_REMOTE_TERMINATE           0x62
#define RSI_RSP_DNS_SERVER                 0x55
#define RSI_RSP_HOST_WEBPAGE               0x56
 
//! HT CAPS response
#define RSI_RSP_AP_HT_CAPS                 0x6D

//! WMM PS response 
#define RSI_RSP_WMM_PS                     0x97

//!WPS MEHOD response
#define RSI_RSP_WPS_METHOD                 0x72

//! PER MODE response
#define RSI_RSP_PER_PARAMS                 0x7c
#define RSI_RSP_CREATE_JSON                0x9c
#define RSI_RSP_CLEAR_FILES                0x7f
#define RSI_RSP_ERASE_FILE                 0x9A
#define RSI_RSP_ERASE_JSON                 0x9B
#define RSI_RSP_JSON_UPDATE                0x9D
#define RSI_RSP_MULTICAST                  0xB1

#define RSI_RSP_SLP                        0xDE
#define RSI_RSP_WKP                        0xDD
/* Ack to received data */
#define RSI_RSP_DATA_PACKET_ACK            0xAC



/*==============================================*/
//! Band Defines
#define RSI_BAND_2P4GHZ                    0x00  
#define RSI_BAND_5GHZ                      0x01  
#define RSI_DUAL_BAND                      0x02  

//! TCPIP Defines
#define RSI_STATIC_IP_MODE                 0x00
#define RSI_DHCP_IP_MODE                   0x01
#define RSI_FEAT_DHCP_HOST_NAME            0x02
#define RSI_DNS_MODE_ENABLE                0x01
#define RSI_DNS_MODE_DISABLE               0x00
#define RSI_AUTO_IP_CFG                    0x02

//!CERTIFICATE defines
#define RSI_EAP_TLS_CERTIFICATE            0x01    //@ WLAN EAP-TLS Client Certificate/Private Key/CA Root
#define RSI_EAP_FAST_PAC_CERTIFICATE       0x02    //@ WLAN EAP-FAST PAC file
#define RSI_SSL_CLIENT_CERTIFICATE         0x03    //@ SSL client certificate
#define RSI_SSL_CLIENT_PRIVATE_KEY         0x04    //@ SSL client private key
#define RSI_SSL_CA_CERTIFICATE             0x05    //@ SSL CA certificate
#define RSI_SSL_SERVER_CERTIFICATE         0x06    //@ SSL server certificate
#define RSI_SSL_SERVER_PRIVATE_KEY         0x07    //@ SSL server private key

//!SOCKET Defines
#define RSI_SOCKET_TCP_CLIENT              0x0000 
#define RSI_SOCKET_UDP_CLIENT              0x0001 
#define RSI_SOCKET_TCP_SERVER              0x0002 
#define RSI_SOCKET_LUDP                    0x0004 

//!SEND Defines
#define RSI_UDP_FRAME_HEADER_LEN           44
//!UDP Frame header is 42 bytes, padding bytes are extra
#define RSI_TCP_FRAME_HEADER_LEN           56                                                
//!TCP Frame header is 54 bytes, padding bytes are extra
#define RSI_UDP_V6_FRAME_HEADER_LEN        64 
//!Frame header is 42 bytes, padding bytes are extra
#define RSI_TCP_V6_FRAME_HEADER_LEN        76
//!TCP Frame header is 54 bytes, padding bytes are extra
#define RSI_UDP_SEND_OFFSET                32                                  
//!Offset of sent UDP payload data
#define RSI_TCP_SEND_OFFSET                44                                
//!Offset of sent TCP payload data
#define RSI_UDP_RECV_OFFSET                26                                
//!Offset of received UDP payload data
#define RSI_TCP_RECV_OFFSET                38                                
//!Offset of received TCP payload data

//!Security types for AP Configuration
//! SECURITY Type Defines
#define RSI_SECURITY_NONE                   0                   
//! Security type NONE and OPEN are alises for each other
#define RSI_SECURITY_OPEN                   0
#define RSI_SECURITY_WPA1                   1
#define RSI_SECURITY_WPA2                   2

//! Encryption type for AP Configuration 
#define RSI_ENCRYPTION_NONE                 0                   
#define RSI_ENCRYPTION_TKIP                 1
#define RSI_ENCRYPTION_AES                  2

//! NETWORK Type
#define RSI_IBSS_OPEN_MODE                  0
#define RSI_INFRASTRUCTURE_MODE             1
#define RSI_IBSS_SEC_MODE                   2
#define RSI_IBSS_JOINER                     0
#define RSI_IBSS_CREATOR                    1

// DATA Rates
#define RSI_DATA_RATE_AUTO                  0
#define RSI_DATA_RATE_1                     1
#define RSI_DATA_RATE_2                     2
#define RSI_DATA_RATE_5P5                   3
#define RSI_DATA_RATE_11                    4
#define RSI_DATA_RATE_6                     5
#define RSI_DATA_RATE_9                     6
#define RSI_DATA_RATE_12                    7
#define RSI_DATA_RATE_54                    12
#define RSI_DATA_RATE_20                    20
#define RSI_DATA_RATE_18                    18


#define RSI_MACADDRLEN                      6

#define RSI_MODE_8BIT                       0
#define RSI_MODE_32BIT                      1

//!PER mode data rates
#define RSI_RATE_1                         0x0
#define RSI_RATE_2                         0x2
#define RSI_RATE_5_5                       0x4
#define RSI_RATE_11                        0x6
#define RSI_RATE_6                         0x8b
#define RSI_RATE_9                         0x8f
#define RSI_RATE_12                        0x8a
#define RSI_RATE_18                        0x8e
#define RSI_RATE_24                        0x89
#define RSI_RATE_36                        0x8d
#define RSI_RATE_48                        0x88
#define RSI_RATE_54                        0x8c
#define RSI_RATE_MCS0                      0x100
#define RSI_RATE_MCS1                      0x101
#define RSI_RATE_MCS2                      0x102
#define RSI_RATE_MCS3                      0x103
#define RSI_RATE_MCS4                      0x104
#define RSI_RATE_MCS5                      0x105
#define RSI_RATE_MCS6                      0x106
#define RSI_RATE_MCS7                      0x107
#define RSI_RATE_MCS7_SG                   0x307

#define RSI_PER_BURST_MODE               0
#define RSI_PER_CONTT_MODE               1

//! WPS
#define RSI_WPS_PUSH_METHOD              0
#define RSI_WPS_PIN_METHOD               1

//!Multicast
#define RSI_MULTICAST_LEAVE              0
#define RSI_MULTICAST_JOIN               1

//!Multicast filter cmds
#define RSI_MULTICAST_MAC_ADD_BIT        0
#define RSI_MULTICAST_MAC_CLEAR_BIT      1
#define RSI_MULTICAST_MAC_CLEAR_ALL      2
#define RSI_MULTICAST_MAC_SET_ALL        3


//!SNMP
#define SNMP_ANS1_INTEGER                0x2
#define SNMP_ANS1_OCTET_STRING           0x4
#define SNMP_ANS1_OBJECT_ID              0x6
#define SNMP_ANS1_IP_ADDRESS             0x40
#define SNMP_ANS1_COUNTER                0x41 
#define SNMP_ANS1_GAUGE                  0x42
#define SNMP_ANS1_TIME_TICS              0x43
#define SNMP_ANS1_IPV6_ADDRESS           0x44
#define SNMP_ANS1_COUNTER64              0x46
#define SNMP_ANS1_NO_SUCH_OBJECT         0x80
#define SNMP_ANS1_NO_SUCH_INSTANCE       0x81
#define SNMP_ANS1_END_OF_MIB_VIEW        0x82

#define SNMP_VERSION_1                   1
#define SNMP_VERSION_2                   2
#define SNMP_VERSION_3                   3

#define IP_VERSION_4                     4                  
#define IP_VERSION_6                     6

#define SNMP_TRAP_COLD_START             0
#define SNMP_TRAP_WARM_START             1
#define SNMP_TRAP_LINK_DOWN              2
#define SNMP_TRAP_LINK_UP                3
#define SNMP_TRAP_AUTH_FAILURE           4
#define SNMP_TRAP_EGP_NEIGHBOURLOSS      5 
 
#define BIT(a) ((long int)1 << a)
//! feature bit map
#define FEAT_SECURITY_OPEN               BIT(0)
#define FEAT_SECURITY_PSK                BIT(1)
#define FEAT_AGGREGATION                 BIT(2)

//! tcp/ip feature bit map
#define TCP_IP_FEAT_BYPASS               BIT(0)
#define TCP_IP_FEAT_HTTP_SERVER          BIT(1)
#define TCP_IP_FEAT_DHCPV4_CLIENT        BIT(2)
#define TCP_IP_FEAT_DHCPV6_CLIENT        BIT(3)
#define TCP_IP_FEAT_DHCPV4_SERVER        BIT(4)
#define TCP_IP_FEAT_DHCPV6_SERVER        BIT(5)
#define TCP_IP_FEAT_JSON_OBJECTS         BIT(6)
#define TCP_IP_FEAT_HTTP_CLIENT          BIT(7)
#define TCP_IP_FEAT_DNS_CLIENT           BIT(8)
#define TCP_IP_FEAT_SNMP_AGENT           BIT(9)
#define TCP_IP_FEAT_SSL                  BIT(10)
#define TCP_IP_FEAT_ICMP                 BIT(11)
#define TCP_IP_FEAT_HTTPS_SERVER         BIT(12)

//!Custom feature select bitmap
#define FEAT_SEL_ENABLE_ASYNC_MESSAGE    BIT(10) 

//! socket feature
#define RSI_SSL_SUPPORT                  BIT(0)
#define RSI_WEBS_SUPPORT                 BIT(1)
#define RSI_SSL_WEBS_SUPPORT             (BIT(0) | BIT(1))
#define RSI_SSL_TLS_V_1                  BIT(2)
#define RSI_SSL_TLS_V_1_2                BIT(3)


//!PMK
#define RSI_PSK_FROM_HOST               1
#define RSI_PMK_FROM_HOST               2
#define RSI_GENERATE_PMK                3


//! SSL
#define SSL_ALL_CIPHERS 0
#define BIT_TLS_RSA_WITH_AES_256_CBC_SHA256    (1<<0)
#define BIT_TLS_RSA_WITH_AES_128_CBC_SHA256    (1<<1)
#define BIT_TLS_RSA_WITH_AES_256_CBC_SHA       (1<<2)
#define BIT_TLS_RSA_WITH_AES_128_CBC_SHA       (1<<3)
#define BIT_TLS_RSA_WITH_AES_128_CCM_8         (1<<4)
#define BIT_TLS_RSA_WITH_AES_256_CCM_8         (1<<5)

/**
 * Enumerations
 */
enum RSI_INTTYPE { 
    RSI_IRQ_NONE             = 0x00,
    RSI_IRQ_BUFFERFULL       = 0x01,
    RSI_IRQ_BUFFEREMPTY      = 0x02,
    RSI_IRQ_MGMTPACKET       = 0x04,
    RSI_IRQ_DATAPACKET       = 0x08,
    RSI_IRQ_10               = 0x10,
    RSI_IRQ_PWRMODE          = 0x20,
    RSI_IRQ_40               = 0x40,
    RSI_IRQ_80               = 0x80,
    RSI_IRQ_ANY              = 0xff
};

/*Network type */
typedef enum NETWORK_TYPE_s {
  IBSS,
  STA_INFRASTRUCTURE,
  IBSS_SEC,
  MODE_AP,
  P2P_GROUP_OWN,
  P2P_CLIENT,
  AutoUnknown,
  InfrastructureMax,
} NETWORK_TYPE;


//! PS defines 
#define PS_CONFIRM              0x2


/*=====================================================================================*/
/**
 *         This is platform dependent operation.Needs to be implemented 
 *         specific to the platform.This timer is mentioned in the following functions
 *             Application/TCPDemo/Source/main.c
 *             WLAN/SPI/Source/spi_functs.c
 *             WLAN/SPI/Source/spi_iface_init.c
 *     
 */

extern uint32            rsi_spiTimer1;
extern uint32            rsi_spiTimer2;
extern uint32            rsi_spiTimer3;

extern volatile rsi_powerstate rsi_pwstate;
/*
 * Function Prototype Definitions
 */
int16 rsi_oper_mode(rsi_uOperMode *uOperMode);
int16 rsi_band(uint8 band);
int16 rsi_init(void);
int16 rsi_scan(rsi_uScan *uScanFrame);
int16 rsi_join(rsi_uJoin *uJoinFrame);
int16 rsi_ip_param_set(rsi_uIpparam *uIpparamFrame);
int16 rsi_ipv6_param_set(rsi_uIPconf6  *uIpconf6Frame);
int16 rsi_query_rssi(void);
int16 rsi_query_snr(void);
int16 rsi_set_mac_addr(uint8 *macAddress);
int16 rsi_query_mac_address(void);
int16 rsi_power_mode(uint8 powermode);
int16 rsi_socket(rsi_uSocket *uSocketFrame);
int16 rsi_socket_close(uint16 socketDescriptor, uint16 port_number);
int16 rsi_query_conn_status(void);
int16 rsi_query_fw_version(void);
int16 rsi_query_net_parms(void);
int16 rsi_select_antenna(uint8 antenna_val);
int16 rsi_query_go_parms(void);
int16 rsi_p2p_config(rsi_uConfigP2p *uConfigP2p);
int16 rsi_set_eap(rsi_uSetEap *uSetEap);
int16 rsi_set_certificate(uint8 certificate_type,uint8 *buffer,uint32 certificate_length, struct SET_CHUNK_S *SetChunks);
int16 rsi_load_web_page(rsi_uWebServer *uWebServer, uint8* webpage_file);
int16 rsi_send_url_rsp(HostWebpageSnd_t *uUrlRsp, uint8 *webpage_morechunks, uint8 *webpage_file , uint32 file_size, uint8 first_chunk);
int16 rsi_web_fields(rsi_uWebFields *uWebFields);
int16 rsi_sleep_timer(rsi_uSleepTimer *uSleepTimer);
int16 rsi_module_soft_reset(void);
int16 rsi_set_ap_config(rsi_apconfig *apconf);
int16 rsi_set_wepkey(rsi_wepkey *wepkey);
int16 rsi_dns_server(rsi_uDnsServer *uDnsServer);
int16 rsi_http_get(rsi_uHttpReq *uHttpGetReqFrame);
int16 rsi_http_post(rsi_uHttpReq *uHttpGetPostFrame);
int16 rsi_dns_query(rsi_uDnsQry  *uDnsQryFrame);
int16 rsi_ltcp_conn_status(uint16 socketDescriptor);
int16 rsi_ping_request(rsi_ping_request_t *pingReq);
int16 rsi_disconnect(rsi_disassoc_t *disassoc_Frame);
int16 rsi_sys_init(void);
/*Multicast api's*/
uint8 lmac_crc8_c(uint8 crc8_din, uint8 crc8_state, uint8 end);
uint8 multicast_mac_hash(uint8 *mac);
int16 rsi_multicast_mac_filter(uint8 cmd, uint8 MAC[6]);
int16 rsi_multicast(rsi_uMulticast *uMulticastFrame);

int16 rsi_rejoin_params(rsi_rejoin_params_t *uRejoinFrame);
int16 rsi_psk(rsi_uPsk *uPskReqFrame);
int16 rsi_bg_scan(rsi_ubgScan *ubgScanFrame);

/* For power save */
int16 rsi_pwrsave_continue(void);
int16 rsi_pwrsave_hold(void);
void config_gpio_output(uint8 value);
void config_gpio_input(void);
uint8 get_gpio_value(void);

int16 rsi_cfg_enable(uint8 cfg_enable_val);
int16 rsi_cfg_get(void);
int16 rsi_cfg_save(void);

int16 rsi_debug_prints(rsi_uDebug *uDebugFrame);

int16 rsi_module_power_cycle(void);
void  rsi_build_frame_descriptor(rsi_uFrameDsc *uFrameDscFrame, uint8 *cmd);
int16 rsi_spi_frame_dsc_wr(rsi_uFrameDsc *uFrmDscFrame);
int16 rsi_spi_frame_data_wr(uint16 bufLen, uint8 *dBuf,uint16 tbufLen,uint8 *tBuf);
int16 rsi_frame_write(rsi_uFrameDsc *uFrameDscFrame,uint8 *payloadparam,uint16 size_param);
int16 rsi_execute_cmd(uint8 *descparam,uint8 *payloadparam,uint16 size_param);
int16 rsi_send_data(uint16 socketDescriptor, uint8 *payload, uint32 payloadLen,uint8 protocol,uint32 *bytes_sent);
int16 rsi_send_raw_data(uint8 *payload, uint32 payloadLen,uint32 *bytes_sent);
int16 rsi_send_ludp_data(uint16 socketDescriptor, uint8 *payload,uint32 payloadLen,uint8 protocol, uint8 *destIp, uint16 destPort,uint32 *bytes_sent);
int16 rsi_frame_read(uint8 *pkt_buffer);
void  rsi_wakeup_from_host(void);
void rsi_req_wakeup(void);
void rsi_wait4wakeup(void);
void rsi_allow_sleep(void);
int16 rsi_wireless_fwupgrade(void);



/* For SNMP */
int16 rsi_snmp_enable(uint8 snmpEnable);
int16 rsi_snmp_get_rsp(rsi_uSnmp *uSnmpGetRsp);
int16 rsi_snmp_get_next_rsp(rsi_uSnmp *uSnmpGetNextRsp);
int16 rsi_snmp_trap(rsi_uSnmptrap *snmpTrapFrame);

/* For IPV6 ipconfig*/
int16 rsi_ipconf6(rsi_uIPconf6  *uIpconf6Frame);

/* Bootup configuration APIs*/
int16 rsi_waitfor_boardready(void);
int16 rsi_upgrade_fw(uint8 image_type, uint8 *fw_image, uint32 fw_image_size);
int16 rsi_boot_insn(uint8 type, uint32* data);
int16 rsi_select_option(uint8 cmd);


/* Roaming parameter set API*/
int16 rsi_roam_params(rsi_uRoamParams *uRoamParamsFrame);

/* HT CAPS parameter wet API*/
int16 rsi_ht_caps(rsi_uHtCaps *uHtCapsFrame);

/* WMM PS parameter wet API*/
int16 rsi_wmm_ps(rsi_uWmmPs *uWmmPsFrame);

/* WPS PIN METHOD parameter API*/
int16 rsi_wps_method(rsi_uWpsMethod *uWpsMethodFrame);

/* PER MODE parameter API*/
int16 rsi_per_mode(rsi_uPerMode *uPerMode);

/* PER stats API */
int16 rsi_per_stats(rsi_uPerStats *uPerStats);

/* JSON & Webpage Related Functionality */
int16 rsi_json_create(rsi_jsonCreateObject_t* json, uint8* buffer);
int16 rsi_json_erase_file(rsi_tfs_erase_file_t* file);
int16 rsi_webpage_clear_files(rsi_tfs_clear_files_t* clear);
int16 rsi_webpage_erase_file(rsi_tfs_erase_file_t* file);

/*set region */
int16 rsi_set_region(rsi_usetregion *uSetRegionReqFrame);
/*Set region AP*/
int16 rsi_set_region_ap(rsi_usetregion_ap_t *uSetRegionApReqFrame);
int16 rsi_send_websocket_data(uint16 socketDescriptor, uint8 *payload, uint32 payloadLen,uint8 protocol, uint8 opcode, uint32 *total_bytes_sent);
int16 rsi_user_store_config(rsi_user_store_config_t  *ptr_userstrcfg);
void rsi_buildHttpExtendedHeader(uint8 *http_header);
int16 rsi_bytes_sent_count(uint16 socketDescriptor);

#ifdef __cplusplus
}
#endif

#endif
