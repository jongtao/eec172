/**
 * @file       rsi_send_boot_insn.c
 * @version    1.0
 * @date       2014-Apr-13
 *
 * Copyright(C) Redpine Signals 2014
 * All rights reserved by Redpine Signals.
 *
 * @section License
 * This program should be used on your own responsibility.
 * Redpine Signals assumes no responsibility for any losses
 * incurred by customers or third parties arising from the use of this file.
 *
 * @brief SEND BOOT INSN: send boot instructions to WiFi module 
 *
 * @section Description
 * This file contains boot instructions exchanges with WiFi module.
 *
 *
 */

/**
 * Includes
 */
#include "stdint.h"
#include "rsi_global.h"
#include <rsi_spi_cmd.h>

/*==============================================*/
/**
 * @fn          int16 rsi_boot_insn(uint8 type, uint32 *data)
 * @brief       Sends boot instructions to WiFi module
 * @param[in]   uint8 type, type of the insruction to perform
 * @param[in]   uint32 *data, pointer to data which is to be read/write
 * @param[out]  none
 * @return      errCode
 *              0  = SUCCESS
 * @section description 
 * This API is used to send boot instructions to WiFi module.
 */
#ifdef USB_INTERFACE
extern int32 rsi_mem_rd(uint32 reg_address, uint16 len, uint8 *value);
extern int32 rsi_mem_wr(uint32 reg_address, uint16 len, uint8 *value);

#endif
int16 rsi_boot_insn(uint8 type, uint32 *data)
{
  int16   retval = 0;
  uint16  local = 0;
  uint32  j = 0;
  uint32  cmd = 0; 
  uint32  read_data = 0;

#ifdef RSI_DEBUG_PRINT
  RSI_DPRINT(RSI_PL3,"\nBootInsn\n");
#endif

  switch(type)
  {
    case REG_READ:
      rsi_mem_rd(HOST_INTF_REG_OUT,2,(uint8 *)&read_data);
      retval = read_data;
#if !(defined(LINUX) || defined(LINUX_PLATFORM))
      *(uint16 *)data = read_data;
#endif
      break;

    case REG_WRITE:
      read_data = *(uint32*)(data);
      rsi_mem_wr(HOST_INTF_REG_IN,2, (uint8 *)data);
      break;

    case PING_WRITE:

      for (j = 0; j<2048; j++){
        rsi_mem_wr(0x19000 + (j*2), 2, (uint8 *)((uint32)data + (j*2)));
      }

      local = 0xab49;
      rsi_mem_wr(HOST_INTF_REG_IN, 2, (uint8 *)&local);
      break;

    case PONG_WRITE:

      for (j = 0; j<2048; j++){
        rsi_mem_wr(0x1a000 + (j*2), 2 ,(uint8 *)((uint32)data + (j*2)));
      }
      // Perform the write operation
      local = 0xab4f;
      rsi_mem_wr(HOST_INTF_REG_IN, 2, (uint8 *)&local);
      break;

    case RSI_UPGRADE_WLAN_FW:
      cmd = RSI_UPGRADE_WLAN_FW | HOST_INTERACT_REG_VALID;
      rsi_mem_wr(HOST_INTF_REG_IN, 2, (uint8 *)&cmd);

      while(1){
        rsi_mem_rd(HOST_INTF_REG_OUT, 2, (uint8 *)&read_data);
        if (read_data == (SEND_RPS_FILE | HOST_INTERACT_REG_VALID)){
          break;
        }
      }
      break;

    case RSI_UPGRADE_BT_FW:
      cmd = RSI_UPGRADE_BT_FW | HOST_INTERACT_REG_VALID;
      rsi_mem_wr(HOST_INTF_REG_IN, 2, (uint8 *)&cmd);
      while(1){
        rsi_mem_rd(HOST_INTF_REG_OUT, 2, (uint8 *)&read_data);
        if (read_data == (SEND_RPS_FILE | HOST_INTERACT_REG_VALID)){
          break;
        }
      }
      break;
    case RSI_LOAD_WLAN_FW:
      cmd = RSI_LOAD_WLAN_FW | HOST_INTERACT_REG_VALID;
      rsi_mem_wr(HOST_INTF_REG_IN, 2, (uint8 *)&cmd);
      break;
    case RSI_LOAD_BT_FW:
      cmd = RSI_LOAD_BT_FW | HOST_INTERACT_REG_VALID;
      rsi_mem_wr(HOST_INTF_REG_IN, 2, (uint8 *)&cmd);
      break;
    case RSI_LOAD_WLAN_ACTIVE_LOW_FW:
      cmd = RSI_LOAD_WLAN_ACTIVE_LOW_FW | HOST_INTERACT_REG_VALID;
      rsi_mem_wr(HOST_INTF_REG_IN, 2, (uint8 *)&cmd);
      break;
    case RSI_LOAD_BT_ACTIVE_LOW_FW:
      cmd = RSI_LOAD_BT_ACTIVE_LOW_FW | HOST_INTERACT_REG_VALID;
      rsi_mem_wr(HOST_INTF_REG_IN, 2, (uint8 *)&cmd);
      break;
    case RSI_UPGRADE_BL:
      cmd = RSI_UPGRADE_BL | HOST_INTERACT_REG_VALID;
      rsi_mem_wr(HOST_INTF_REG_IN, 2, (uint8 *)&cmd);
      while(1){
        rsi_mem_rd(HOST_INTF_REG_OUT,  2, (uint8 *)&read_data);
        if (read_data == (SEND_RPS_FILE | HOST_INTERACT_REG_VALID)){
          break;
        }
      }
      break;
    default:
      retval = -2;
      break;
  }
  return retval;
}
