/*
 * Includes
 */
 
#ifndef WyzBee_BT_h
#define WyzBee_BT_h
#ifdef __cplusplus
extern "C"{
#endif

#include <rsi_bt_generic.h>
#include <rsi_bt_global.h>
#include <rsi_bt_config.h>
#include <rsi_global.h>


#define  ERR_NONE  0

typedef union {
    struct {
       uint32    select_mode;                       //@ operating mode 0-client, 1-p2p, 2-EAP, 6-AP, 8-PER
       uint32    feature_bit_map;                 //@ BIT(0)-Open mode security, BIT(1)-PSK security, BIT(2) JSON objects
       uint32    tcp_ip_feature_bit_map;          //@ BIT(0)-tcp/ip bypass, BIT(1)-HTTP server,BIT(2)-DHCPV4 client, 
                                                  //@ BIT(3)-DHCPV6 client, BIT(4)-DHCPV4 server, BIT(5)-DHCPV6 server
       uint32   custom_feature_bit_map; 
    } operModeFrameSnd;
    uint8    uSelectModeBuf[16];                
} rsi_uSelectMode;



void  BT_BDAddrToStr (uint8   *p_hex_addr,
                      uint8   *p_str_addr);


//extern  RSI_BT_EVENT_INQUIRY_RESPONSE  InquiryResults[5];



uint16 WyzBee_BT_init (void);
uint16 WyzBee_SetLocalName (uint8 *p_name);
uint16 WyzBee_GetLocalName (uint8 *p_name);
uint16 WyzBee_SetLocalCOD (uint32  local_cod);
uint16 WyzBee_GetLocalCOD (uint32  *p_local_cod);
uint16 WyzBee_GetRSSI (uint8  *p_remote_bdaddr, uint8  *p_rssi);
uint16 WyzBee_GetLinkQuality (uint8  *p_remote_bdaddr, uint8  *p_link_qa);
uint16 WyzBee_GetLocalBDAddress (uint8  *p_remote_bdaddr);


uint16 WyzBee_InitSppProfile (void);
uint16 WyzBee_SetDiscoverMode (uint8 mode, uint32  timeout);
uint16 WyzBee_GetDiscoverMode (uint8  *p_mode);
uint16 WyzBee_SetConnMode (uint8 mode);
uint16 WyzBee_GetConnMode (uint8  *p_mode);
uint16 WyzBee_SetPairMode (uint8 mode);
uint16 WyzBee_GetPairMode (uint8 *p_mode);
uint16 WyzBee_RemoteNameReq (uint8  *p_remote_bd_addr);
uint16 WyzBee_RemoteNameReqCancel (uint8  *p_remote_bd_addr);
uint16 WyzBee_Inquiry (uint8  inquiry_type, uint32  time_out);
uint16 WyzBee_InquiryCancel (void);
uint16 WyzBee_Bond (uint8  *p_remote_addr);
uint16 WyzBee_BondCancel (uint8  *p_remote_addr);
uint16 WyzBee_UnBond (uint8  *p_remote_addr);
uint16 WyzBee_SetPinType (uint8  pin_type);
uint16 WyzBee_GetPinType (uint8  *p_pin_type);
uint16 WyzBee_PinCodeReply (uint8  *p_remote_bdaddr, uint8  replytype, uint32  pincode);
uint16 WyzBee_GetDeviceRole (uint8  *p_remote_addr, uint8  *p_role);
uint16 WyzBee_SetDeviceRole (uint8  *p_remote_addr, uint8  role);
uint16 WyzBee_GetRemoteDeviceServices (uint8  *p_remote_addr, uint32  *p_services, uint8 nbr_services, uint8  *p_nbr_found_sevices);
uint16 WyzBee_SearchForServicce (uint8  *p_remote_addr, uint32  service_uuid);
uint16 WyzBee_SPPConnet (uint8  *p_remote_addr);
uint16 WyzBee_SPPDisconnet (uint8  *p_remote_addr);
uint16 WyzBee_SPPTransfer (uint8  *p_remote_addr, uint8  *p_data, uint16  data_len);
uint16 WyzBee_SPPReceive (uint8  *p_data, uint16  data_size);
uint16 WyzBee_BT_AcceptSppConnect (void);
uint16 WaitForSPPConnComplete (void);

uint16 WyzBee_GetInquiryResults (RSI_BT_EVENT_INQUIRY_RESPONSE  *p_scan_res, uint8 size);
#ifdef __cplusplus
}
#endif
#endif
