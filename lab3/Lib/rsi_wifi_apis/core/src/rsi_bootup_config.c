/**
 * @file     rsi_bootup_config.c
 * @version  1.0
 * @date     2014-Apr-13
 *
 * Copyright(C) Redpine Signals 2014
 * All rights reserved by Redpine Signals.
 *
 * @section License
 * This program should be used on your own responsibility.
 * Redpine Signals assumes no responsibility for any losses
 * incurred by customers or third parties arising from the use of this file.
 *
 * @brief BOOTUP: Bootup configuration file 
 *
 * @section Description
 * This file contains the Bootup functionality.
 * @functions Defined: 
 * rsi_waitfor_boardready
 * rsi_select_option
 * rsi_upgrade_fw
 */

/**
 * Includes
 */
#include "rsi_global.h"


/*==============================================*/
/**
 * @fn          int16 rsi_waitfor_boardready(void)
 * @brief       Waits to receive board ready from WiFi module
 * @param[in]   none
 * @param[out]  none
 * @return      errCode
 *              0  = SUCCESS
 * @section description 
 * This API is used to check board ready from WiFi module.
 */
int16 rsi_waitfor_boardready(void)
{
  int16 retval = 0;
  uint16 read_value = 0;
  while(1)
  {
    retval = rsi_boot_insn(REG_READ, (uint32 *)&read_value);
#ifdef RSI_DEBUG_PRINT
    RSI_DPRINT(RSI_PL3,"WAITING TO RECEIVE BOARD READY\n");
#endif
    if ((read_value & 0xFF00) == (HOST_INTERACT_REG_VALID & 0xFF00))
    {
      if((read_value & 0xFF) == BOOTLOADER_VERSION)
      {
#ifdef RSI_DEBUG_PRINT      
    RSI_DPRINT(RSI_PL3,"BOOTLOADER VERSION CORRECT\n");
#endif
      }
      else
      {
#ifdef RSI_DEBUG_PRINT      
    RSI_DPRINT(RSI_PL3,"BOOTLOADER VERSION NOT MATCHING\n");
#endif
      }

#ifdef RSI_DEBUG_PRINT      
    RSI_DPRINT(RSI_PL3,"RECIEVED BOARD READY\n");
#endif
      break;
    }
  }
  return retval;
}

/*==============================================*/
/**
 * @fn          int16 rsi_select_option(uint8 cmd)
 * @brief       Sends cmd to select option to load or update configuration 
 * @param[in]   uint8 cmd, type of configuration to be saved
 * @param[out]  none
 * @return      errCode
 *              0  = SUCCESS
 * @section description 
 * This API is used to send firmware load request to WiFi module or update default configurations.
 */
int16 rsi_select_option(uint8 cmd)
{
  uint32   boot_cmd = 0;
  int16    retval =0;
  uint16   read_value = 0;

  boot_cmd = HOST_INTERACT_REG_VALID | cmd;
  retval   = rsi_boot_insn(REG_WRITE, &boot_cmd);

  while(cmd != RSI_LOAD_IMAGE_TYPE)
  {
    retval = rsi_boot_insn(REG_READ, (uint32 *)&read_value);
    if (read_value == (HOST_INTERACT_REG_VALID | cmd))
    {
      break;
    }
  }
  return retval;
}
/*==============================================*/
/**
 * @fn          int16 rsi_upgrade_fw(uint8 image_type, uint8 *fw_image, uint32 fw_image_size)
 * @brief       Upgrades firmware to WiFi module
 * @param[in]   uint8 image_type, type of firmware image to upgrade
 * @param[in]   uint8* fw_image, pointer to firmware
 * @param[in]   uint32 fw_image_size, size of firmware image
 * @param[out]  none
 * @return      errCode
 *              0  = SUCCESS
 * @section description 
 * This API is used to upgrade firmware to WiFi module.
 */
int16 rsi_upgrade_fw(uint8 image_type, uint8 *fw_image , uint32 fw_image_size)
{
  uint32 boot_cmd = HOST_INTERACT_REG_VALID | image_type;
  uint32 read_value = 0;
  uint32 offset = 0;
  int16  retval;
  uint32 boot_insn = 0,poll_resp = 0;

  retval = rsi_boot_insn(REG_WRITE, &boot_cmd);
  while(1)
  {
    retval = rsi_boot_insn(REG_READ, &read_value);
    if (read_value == (HOST_INTERACT_REG_VALID | SEND_RPS_FILE))
    {
      break;
    }
  }
  boot_cmd = HOST_INTERACT_REG_VALID | PONG_VALID;
  while(offset <= fw_image_size){
    switch (boot_cmd){
      case (HOST_INTERACT_REG_VALID | PING_VALID):
        boot_insn = PONG_WRITE;
        poll_resp = PING_AVAIL;
        boot_cmd = HOST_INTERACT_REG_VALID |PONG_VALID;
        break;
      case (HOST_INTERACT_REG_VALID | PONG_VALID):
        boot_insn = PING_WRITE;
        poll_resp = PONG_AVAIL;
        boot_cmd = HOST_INTERACT_REG_VALID |PING_VALID;
        break;
    }

#ifdef RSI_DEBUG_PRINT
    RSI_DPRINT(RSI_PL3,"Burning from %x to %x of %x\n", offset, (offset + 4096), fw_image_size);
#endif
    retval = rsi_boot_insn(boot_insn, (uint32 *)((uint8 *)fw_image + offset));
    while(1)
    {
      retval = rsi_boot_insn(REG_READ, &read_value);
      if (read_value == (HOST_INTERACT_REG_VALID | poll_resp))
      {
        break;
      }
    }
    offset += 1024*4;
  }
  boot_cmd = HOST_INTERACT_REG_VALID | EOF_REACHED;
#ifdef RSI_DEBUG_PRINT
  RSI_DPRINT(RSI_PL3,"EOF REACHED\n");
#endif
  retval = rsi_boot_insn(REG_WRITE, &boot_cmd);
  while(1){
    retval = rsi_boot_insn(REG_READ, &read_value);
#ifdef RSI_DEBUG_PRINT
    RSI_DPRINT(RSI_PL3,"WAITING TO RECEIVE FIRMWARE UPGRADATION STATUS\n");
#endif
    if (read_value == (HOST_INTERACT_REG_VALID | FWUP_SUCCESSFUL))
    {
#ifdef RSI_DEBUG_PRINT
      
    RSI_DPRINT(RSI_PL3,"FIRMWARE UPGRADATION SUCCESSFUL\n");
#endif
    
      break;
    }
  }
  return retval;
}


