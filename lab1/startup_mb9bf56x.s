;                                    USE AGREEMENT
; 
; By using the program contain in this document, file location or subdirectory
;  (the "Deliverables"), you ("Licensee" are deemed to have agreed to the terms and conditions
; set forth below (the "AGREEMENT") with Fujitsu Semiconductor Limited ("FUJITSU"). If Licensee
; does not agree to this AGREEMENT then Licensee shall not use the Deliverables. 
; 
; 1. Permitted Use
; 
; The Deliverables are intended for and must only be used for reference and in an evaluation
; laboratory environment. The Deliverables are provided on an "AS-IS" basis without any charge
; and is subject to this AGREEMENT.  FUJITSU may modify the Deliverables without notice to
; Licensee.  It is Licensee's obligation to fully test the Deliverables in its environment and
; to ensure proper functionality, qualification and compliance with component specifications.
; In the event the Deliverables include open source components, the provisions of the governing
; open source license agreement shall apply with respect to such Deliverables, and such open
; source license agreement shall prevail over this AGREEMNT if there is any contradiction
; between this AGREEMENT and such open source license agreement.
; 
; 2. Disclaimer on Use
; 
; FUJITSU MAKES NO WARRANTIES, EITHER EXPRESS OR IMPLIED, REGARDING THE DELIVERABLES, INCLUDING
; BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY OR FITNESS FOR ANY PARTICULAR PURPOSE. 
; 
; FUJITSU DOES NOT WARRANT THAT THE DELIVERABLES DO NOT INFRINGE ANY THIRD PARTY’S INTELLECTUAL
; PROPERTY RIGHTS ("IPRs"), INCLUDING BUT NOT LIMITED TO PATENTS, UTILITY MODELS, DESIGNS,
; TRADEMARKS, TRADE SECRETS, COPYRIGHTS, AND MASK WORK RIGHTS.
; 
; In the event that the Deliverables infringe a third party's IPRs, it is the sole
; responsibility of the LICENSEE to obtain necessary licenses to continue the usage of the
; Deliverable and to pay any and all damages for its use of the Deliverables.
; 
; FUJITSU SHALL NOT BE OBLIGATED TO MAKE ANY BUG-FIXES, UPDATES, OR MODIFICATIONS OR TO PROVIDE
; SUPPORT WITH RESPECT TO THE DELIVERABLES. 
; 
; Except as otherwise expressly provided herein, nothing in this AGREEMENT shall be construed
; as obligating FUJITSU to grant licenses for the Deliverables to LICENSEE.
; 
; 3. LIMITATION OF LIABILITY
; 
; THE DELIVERABLES ARE PROVIDED "AS-IS" FOR FREE AND IN NO EVENT WILL FUJITSU BE LIABLE FOR
; LICENSEE’S USE OF THE DELIVERABLES. 
; 
; IN NO EVENT WILL FUJITSU BE LIABLE TO LICENSEE, CUSTOMERS, END USERS, OR ANY THIRD PARTIES FOR
; ANY DIRECT, INDIRECT, SPECIAL, INCIDENTAL, PUNITIVE, CONSEQUENTIAL OR SIMILAR DAMAGE OF ANY
; KIND OR CHARACTER, WHETHER IN CONTRACT OR TORT, ARISING OUT OF OR RELATING TO THIS AGREEMENT,
; INCLUDING WITHOUT LIMITATION, LOST REVENUE OR PROFITS, LOST DATA OR USE, DAMAGE TO EQUIPMENT,
; DOWNTIME COSTS AND CLAIMS BY ANY THIRD PARTY, REGARDLESS OF WHETHER FUJITSU HAS BEEN ADVISED
; OF THE POSSIBILITY OF SUCH DAMAGES AND NOTWITHSTANDING THE FAILURE OF ANY REMEDY FOR AN
; ESSENTIAL PURPOSE.
; 
; ALL LIABILITIES OF FUJITSUWHETHER IN CONTRACT, TORT, OR OTHERWISE, ARISING OUT OF OR IN
; CONNECTION WITH THIS AGREEMENT, SHALL NOT EXCEED THE TOTAL AMOUNTS PAID TO FUJITSU BY
; LICENSEE FOR THE DELIVERABLES UNDER THIS AGREEMENT. 
; 
; 4. GOVERNING LAW AND ARBITRATION
; 
; It is expressly agreed that the validity and construction of this AGREEMENT, and performance
; hereunder, shall be governed by the laws of Japan, without regard to its conflicts of laws
; rules.  THE UNITED NATIONS CONVENTION ON CONTRACTS FOR THE INTERNATIONAL SALE OF GOODS AND
; UNIFORM COMPUTER INFORMATION TRANSACTION ACT (UCITA) SHALL NOT APPLY.
; 
; In the event of any dispute, controversy or claim (collectively referred to as "Dispute")
; arising out of or relating to this AGREEMENT, or the breach thereof, the parties shall use
; their best endeavors to amicably settle any such disputes, controversies or within thirty (30)
; days a party receives notice of a Dispute from the other party ("Complaining Party"). Any such
; disputes, controversies or claim that cannot be settled between the parties within thirty (30)
; days after a party received notice of the Dispute from Complaining Party, such Dispute shall
; be finally settled under the Rules of Arbitration of the Japan Commercial Arbitration
; Association ("Rules") by three arbitrators appointed in accordance with the said Rules.
; The place of arbitration shall be Tokyo, Japan. The arbitration shall be conducted in English,
; with Japanese translation used at the request of either party. The award rendered by the
; arbitrators shall be final and binding upon both parties.
; 
; In addition to the remedies that parties may seek from an arbitration tribunal, each party
; shall have the right to obtain, from a court of competent jurisdiction at any time, any and
; all forms of equitable relief to prevent the infringement of an intellectual property right of
; a party, including but not limited to injunctive relief and specific performance.  The seeking
; of and/or the obtaining of such equitable relief will not be deemed to be incompatible with
; the agreement to arbitrate.
; 
; 5. Indemnity 
; 
; Licensee will hold harmless and indemnify FUJITSU and its affiliates, officers, agents, and
; employees from any claim, suit or action arising from or related to the use of the
; Deliverables or violation of the terms of this Agreement, including any liability or expense
; arising from claims, losses, damages, suits, judgments, litigation costs and attorneys' fees.
; 
; 6. General  
; 
; FUJITSU may modify this AGREEMENT and such modification will become effective 14 days after
; the date FUJITSU provides notice of such modification to Licensee. If Licensee does not want
; to accept any of such modifications then Licensee should discontinue the use of Deliverables
; before the modification becomes effective.  If there is a conflict between the terms of this
; AGREEMENT and the modified terms as made by FUJITSU, then the modified terms will control
; for that conflict.
; 
; This AGREEMENT does not create any third party beneficiary rights. 
; 
; FUJITSU If you do not comply with these terms, and we don't take action right away, this
; doesn't mean that we are giving up any rights that we may have (such as taking action in the
; future). 
; 
; Licensee shall comply with all then-current applicable laws, regulations and other legal
; requirements in its performance in connection with this AGREEMENT, including without
; limitation, all applicable export control laws, rules and regulations of the United States,
; Japan and any other relevant countries.
; 
; If any proper arbitration tribunal or court determines that a term in this AGREEMENT term is
; not enforceable, then this determination will not affect any other terms in this AGREEMENT. 
; 
; The failure by FUJITSU to enforce or exercise any rights under or in connection with any term
; and/or condition of this AGREEMENT shall not be construed as constituting a waiver of such
; rights.

; Stack Configuration
;  Stack Size (in Bytes) <0x0-0xFFFFFFFF:8>

Stack_Size      EQU     0x00000200

                AREA    STACK, NOINIT, READWRITE, ALIGN=3
Stack_Mem       SPACE   Stack_Size
__initial_sp


; Heap Configuration
;  Heap Size (in Bytes) <0x0-0xFFFFFFFF:8>

Heap_Size       EQU     0x00000000

                AREA    HEAP, NOINIT, READWRITE, ALIGN=3
__heap_base
Heap_Mem        SPACE   Heap_Size
__heap_limit


                PRESERVE8
                THUMB


; Vector Table Mapped to Address 0 at Reset

                AREA    RESET, DATA, READONLY
                EXPORT  __Vectors
                EXPORT  __Vectors_End
                EXPORT  __Vectors_Size
						;IMPORT  TimeTick_Increment

__Vectors       DCD     __initial_sp              ; Top of Stack
                DCD     Reset_Handler             ; Reset Handler
                DCD     NMI_Handler               ; NMI Handler
                DCD     HardFault_Handler         ; Hard Fault Handler
                DCD     MemManage_Handler         ; MPU Fault Handler
                DCD     BusFault_Handler          ; Bus Fault Handler
                DCD     UsageFault_Handler        ; Usage Fault Handler
                DCD     0                         ; Reserved
                DCD     0                         ; Reserved
                DCD     0                         ; Reserved
                DCD     0                         ; Reserved
                DCD     SVC_Handler               ; SVCall Handler
                DCD     DebugMon_Handler          ; Debug Monitor Handler
                DCD     0                         ; Reserved
                DCD     PendSV_Handler            ; PendSV Handler
                DCD     SysTick_Handler           ; SysTick Handler
						;DCD     TimeTick_Increment         ; SysTick Handler

; Numbered IRQ handler vectors				
				
; Note: renaming to device dependent ISR function names are done in
;       pdl.h (section "IRQ name definition for all type MCUs"

                DCD     CSV_IRQHandler
                DCD     SWDT_IRQHandler
                DCD     LVD_IRQHandler
                DCD     IRQ003SEL_IRQHandler
                DCD     IRQ004SEL_IRQHandler
                DCD     IRQ005SEL_IRQHandler
                DCD     IRQ006SEL_IRQHandler
                DCD     IRQ007SEL_IRQHandler
                DCD     IRQ008SEL_IRQHandler
                DCD     IRQ009SEL_IRQHandler
                DCD     IRQ010SEL_IRQHandler
                DCD     EXINT0_IRQHandler
                DCD     EXINT1_IRQHandler
                DCD     EXINT2_IRQHandler
                DCD     EXINT3_IRQHandler
                DCD     EXINT4_IRQHandler
                DCD     EXINT5_IRQHandler
                DCD     EXINT6_IRQHandler
                DCD     EXINT7_IRQHandler
                DCD     QPRC0_IRQHandler
                DCD     QPRC1_IRQHandler
                DCD     WFG0_DTIF0_IRQHandler
                DCD     WFG1_DTIF1_IRQHandler
                DCD     WFG2_DTIF2_IRQHandler
                DCD     FRT0_PEAK_IRQHandler
                DCD     FRT0_ZERO_IRQHandler
                DCD     ICU0_IRQHandler
                DCD     OCU0_IRQHandler
                DCD     FRT1_PEAK_IRQHandler
                DCD     FRT1_ZERO_IRQHandler
                DCD     ICU1_IRQHandler
                DCD     OCU1_IRQHandler
                DCD     FRT2_PEAK_IRQHandler
                DCD     FRT2_ZERO_IRQHandler
                DCD     ICU2_IRQHandler
                DCD     OCU2_IRQHandler
                DCD     PPG00_02_04_IRQHandler
                DCD     PPG08_10_12_IRQHandler
                DCD     PPG16_18_20_IRQHandler
                DCD     BT0_IRQHandler
                DCD     BT1_IRQHandler
                DCD     BT2_IRQHandler
                DCD     BT3_IRQHandler
                DCD     BT4_IRQHandler
                DCD     BT5_IRQHandler
                DCD     BT6_IRQHandler
                DCD     BT7_IRQHandler
                DCD     DT1_2_IRAHandler
                DCD     WC_IRQHandler
                DCD     EXTBUS_ERR_Handler
                DCD     RTC_IRQHandler
                DCD     EXTINT8_IRQHandler
                DCD     EXTINT9_IRQHandler
                DCD     EXTINT10_IRQHandler
                DCD     EXTINT11_IRQHandler
                DCD     EXTINT12_IRQHandler
                DCD     EXTINT13_IRQHandler
                DCD     EXTINT14_IRQHandler
                DCD     EXTINT15_IRQHandler
                DCD     TIM_IRQHandler
                DCD     MFS0_RX_IRQHandler
                DCD     MFS0_TX_IRQHandler
                DCD     MFS1_RX_IRQHandler
                DCD     MFS1_TX_IRQHandler
                DCD     MFS2_RX_IRQHandler
                DCD     MFS2_TX_IRQHandler
                DCD     MFS3_RX_IRQHandler
                DCD     MFS3_TX_IRQHandler
                DCD     MFS4_RX_IRQHandler
                DCD     MFS4_TX_IRQHandler
                DCD     MFS5_RX_IRQHandler
                DCD     MFS5_TX_IRQHandler
                DCD     MFS6_RX_IRQHandler
                DCD     MFS6_TX_IRQHandler
                DCD     MFS7_RX_IRQHandler
                DCD     MFS7_TX_IRQHandler
                DCD     ADC0_IRQHandler
                DCD     ADC1_IRQHandler
                DCD     USB0_IRQHandler
                DCD     USB0_HOST_IRQHandler
                DCD     CAN0_IRQHandler
                DCD     CAN1_IRQHandler
                DCD     ETHER0_IRQHandler
                DCD     DMAC0_IRQHandler
                DCD     DMAC1_IRQHandler
                DCD     DMAC2_IRQHandler
                DCD     DMAC3_IRQHandler
                DCD     DMAC4_IRQHandler
                DCD     DMAC5_IRQHandler
                DCD     DMAC6_IRQHandler
                DCD     DMAC7_IRQHandler
                DCD     DSTC_IRQHandler
                DCD     EXINT16_17_18_19_IRQHandler
                DCD     EXINT20_21_22_23_IRQHandler
                DCD     EXINT24_25_26_27_IRQHandler
                DCD     EXINT28_29_30_31_IRQHandler
                DCD     QPRC2_IRQHandler
                DCD     QPRC3_IRQHandler
                DCD     BT8_IRQHandler
                DCD     BT9_IRQHandler
                DCD     BT10_IRQHandler
                DCD     BT11_IRQHandler
                DCD     BT12_15_IRQHandler
                DCD     MFS8_RX_IRQHandler
                DCD     MFS8_TX_IRQHandler
                DCD     MFS9_RX_IRQHandler
                DCD     MFS9_TX_IRQHandler
                DCD     MFS10_RX_IRQHandler
                DCD     MFS10_TX_IRQHandler
                DCD     MFS11_RX_IRQHandler
                DCD     MFS11_TX_IRQHandler
                DCD     ADC2_IRQHandler
                DCD     Dummy
                DCD     USB1_IRQHandler
                DCD     USB1_HOST_IRQHandler
                DCD     Dummy
                DCD     Dummy
                DCD     Dummy
                DCD     SD_IRQHandler
                DCD     FLASHIF_IRQHandler
                DCD     MFS12_RX_IRQHandler
                DCD     MFS12_TX_IRQHandler
                DCD     MFS13_RX_IRQHandler
                DCD     MFS13_TX_IRQHandler
                DCD     MFS14_RX_IRQHandler
                DCD     MFS14_TX_IRQHandler
                DCD     MFS15_RX_IRQHandler
                DCD     MFS15_TX_IRQHandler
__Vectors_End

__Vectors_Size 	EQU 	__Vectors_End - __Vectors

                AREA    |.text|, CODE, READONLY


; Reset Handler

Reset_Handler   PROC
                EXPORT  Reset_Handler             [WEAK]
                IMPORT  SystemInit
                IMPORT  __main

                LDR.W R0, =0xE000ED88            ; CPACR is located at address 0xE000ED88
                LDR R1, [R0]                     ; Read CPACR
                ORR R1, R1, #(0xF << 20)         ; Set bits 20-23 to enable CP10 and CP11 coprocessors
                STR R1, [R0]                     ; Write back the modified value to the CPACR

                LDR     R0, =SystemInit
                BLX     R0
                LDR     R0, =__main
                BX      R0
                ENDP


; Dummy Exception Handlers (infinite loops which can be modified)

NMI_Handler     PROC
                EXPORT  NMI_Handler               [WEAK]
                B       .
                ENDP
HardFault_Handler\
                PROC
                EXPORT  HardFault_Handler         [WEAK]
                B       .
                ENDP
MemManage_Handler\
                PROC
                EXPORT  MemManage_Handler         [WEAK]
                B       .
                ENDP
BusFault_Handler\
                PROC
                EXPORT  BusFault_Handler          [WEAK]
                B       .
                ENDP
UsageFault_Handler\
                PROC
                EXPORT  UsageFault_Handler        [WEAK]
                B       .
                ENDP
SVC_Handler     PROC
                EXPORT  SVC_Handler               [WEAK]
                B       .
                ENDP
DebugMon_Handler\
                PROC
                EXPORT  DebugMon_Handler          [WEAK]
                B       .
                ENDP
PendSV_Handler  PROC
                EXPORT  PendSV_Handler            [WEAK]
                B       .
                ENDP
SysTick_Handler PROC
                EXPORT  SysTick_Handler           [WEAK]
                B       .
                ENDP

Default_Handler PROC

                EXPORT  CSV_IRQHandler	          [WEAK]
                EXPORT  SWDT_IRQHandler	          [WEAK]
                EXPORT  LVD_IRQHandler	          [WEAK]
                EXPORT  IRQ003SEL_IRQHandler	          [WEAK]
                EXPORT  IRQ004SEL_IRQHandler	          [WEAK]
                EXPORT  IRQ005SEL_IRQHandler	          [WEAK]
                EXPORT  IRQ006SEL_IRQHandler	          [WEAK]
                EXPORT  IRQ007SEL_IRQHandler	          [WEAK]
                EXPORT  IRQ008SEL_IRQHandler	          [WEAK]
                EXPORT  IRQ009SEL_IRQHandler	          [WEAK]
                EXPORT  IRQ010SEL_IRQHandler	          [WEAK]
                EXPORT  EXINT0_IRQHandler	          [WEAK]
                EXPORT  EXINT1_IRQHandler	          [WEAK]
                EXPORT  EXINT2_IRQHandler	          [WEAK]
                EXPORT  EXINT3_IRQHandler	          [WEAK]
                EXPORT  EXINT4_IRQHandler	          [WEAK]
                EXPORT  EXINT5_IRQHandler	          [WEAK]
                EXPORT  EXINT6_IRQHandler	          [WEAK]
                EXPORT  EXINT7_IRQHandler	          [WEAK]
                EXPORT  QPRC0_IRQHandler	          [WEAK]
                EXPORT  QPRC1_IRQHandler	          [WEAK]
                EXPORT  WFG0_DTIF0_IRQHandler	          [WEAK]
                EXPORT  WFG1_DTIF1_IRQHandler	          [WEAK]
                EXPORT  WFG2_DTIF2_IRQHandler	          [WEAK]
                EXPORT  FRT0_PEAK_IRQHandler	          [WEAK]
                EXPORT  FRT0_ZERO_IRQHandler	          [WEAK]
                EXPORT  ICU0_IRQHandler	          [WEAK]
                EXPORT  OCU0_IRQHandler	          [WEAK]
                EXPORT  FRT1_PEAK_IRQHandler	          [WEAK]
                EXPORT  FRT1_ZERO_IRQHandler	          [WEAK]
                EXPORT  ICU1_IRQHandler	          [WEAK]
                EXPORT  OCU1_IRQHandler	          [WEAK]
                EXPORT  FRT2_PEAK_IRQHandler	          [WEAK]
                EXPORT  FRT2_ZERO_IRQHandler	          [WEAK]
                EXPORT  ICU2_IRQHandler	          [WEAK]
                EXPORT  OCU2_IRQHandler	          [WEAK]
                EXPORT  PPG00_02_04_IRQHandler	          [WEAK]
                EXPORT  PPG08_10_12_IRQHandler	          [WEAK]
                EXPORT  PPG16_18_20_IRQHandler	          [WEAK]
                EXPORT  BT0_IRQHandler	          [WEAK]
                EXPORT  BT1_IRQHandler	          [WEAK]
                EXPORT  BT2_IRQHandler	          [WEAK]
                EXPORT  BT3_IRQHandler	          [WEAK]
                EXPORT  BT4_IRQHandler	          [WEAK]
                EXPORT  BT5_IRQHandler	          [WEAK]
                EXPORT  BT6_IRQHandler	          [WEAK]
                EXPORT  BT7_IRQHandler	          [WEAK]
                EXPORT  DT1_2_IRAHandler	          [WEAK]
                EXPORT  WC_IRQHandler	          [WEAK]
                EXPORT  EXTBUS_ERR_Handler	          [WEAK]
                EXPORT  RTC_IRQHandler	          [WEAK]
                EXPORT  EXTINT8_IRQHandler	          [WEAK]
                EXPORT  EXTINT9_IRQHandler	          [WEAK]
                EXPORT  EXTINT10_IRQHandler	          [WEAK]
                EXPORT  EXTINT11_IRQHandler	          [WEAK]
                EXPORT  EXTINT12_IRQHandler	          [WEAK]
                EXPORT  EXTINT13_IRQHandler	          [WEAK]
                EXPORT  EXTINT14_IRQHandler	          [WEAK]
                EXPORT  EXTINT15_IRQHandler	          [WEAK]
                EXPORT  TIM_IRQHandler	          [WEAK]
                EXPORT  MFS0_RX_IRQHandler	          [WEAK]
                EXPORT  MFS0_TX_IRQHandler	          [WEAK]
                EXPORT  MFS1_RX_IRQHandler	          [WEAK]
                EXPORT  MFS1_TX_IRQHandler	          [WEAK]
                EXPORT  MFS2_RX_IRQHandler	          [WEAK]
                EXPORT  MFS2_TX_IRQHandler	          [WEAK]
                EXPORT  MFS3_RX_IRQHandler	          [WEAK]
                EXPORT  MFS3_TX_IRQHandler	          [WEAK]
                EXPORT  MFS4_RX_IRQHandler	          [WEAK]
                EXPORT  MFS4_TX_IRQHandler	          [WEAK]
                EXPORT  MFS5_RX_IRQHandler	          [WEAK]
                EXPORT  MFS5_TX_IRQHandler	          [WEAK]
                EXPORT  MFS6_RX_IRQHandler	          [WEAK]
                EXPORT  MFS6_TX_IRQHandler	          [WEAK]
                EXPORT  MFS7_RX_IRQHandler	          [WEAK]
                EXPORT  MFS7_TX_IRQHandler	          [WEAK]
                EXPORT  ADC0_IRQHandler	          [WEAK]
                EXPORT  ADC1_IRQHandler	          [WEAK]
                EXPORT  USB0_IRQHandler	          [WEAK]
                EXPORT  USB0_HOST_IRQHandler	          [WEAK]
                EXPORT  CAN0_IRQHandler	          [WEAK]
                EXPORT  CAN1_IRQHandler	          [WEAK]
                EXPORT  ETHER0_IRQHandler	          [WEAK]
                EXPORT  DMAC0_IRQHandler	          [WEAK]
                EXPORT  DMAC1_IRQHandler	          [WEAK]
                EXPORT  DMAC2_IRQHandler	          [WEAK]
                EXPORT  DMAC3_IRQHandler	          [WEAK]
                EXPORT  DMAC4_IRQHandler	          [WEAK]
                EXPORT  DMAC5_IRQHandler	          [WEAK]
                EXPORT  DMAC6_IRQHandler	          [WEAK]
                EXPORT  DMAC7_IRQHandler	          [WEAK]
                EXPORT  DSTC_IRQHandler	          [WEAK]
                EXPORT  EXINT16_17_18_19_IRQHandler	          [WEAK]
                EXPORT  EXINT20_21_22_23_IRQHandler	          [WEAK]
                EXPORT  EXINT24_25_26_27_IRQHandler	          [WEAK]
                EXPORT  EXINT28_29_30_31_IRQHandler	          [WEAK]
                EXPORT  QPRC2_IRQHandler	          [WEAK]
                EXPORT  QPRC3_IRQHandler	          [WEAK]
                EXPORT  BT8_IRQHandler	          [WEAK]
                EXPORT  BT9_IRQHandler	          [WEAK]
                EXPORT  BT10_IRQHandler	          [WEAK]
                EXPORT  BT11_IRQHandler	          [WEAK]
                EXPORT  BT12_15_IRQHandler	          [WEAK]
                EXPORT  MFS8_RX_IRQHandler	          [WEAK]
                EXPORT  MFS8_TX_IRQHandler	          [WEAK]
                EXPORT  MFS9_RX_IRQHandler	          [WEAK]
                EXPORT  MFS9_TX_IRQHandler	          [WEAK]
                EXPORT  MFS10_RX_IRQHandler	          [WEAK]
                EXPORT  MFS10_TX_IRQHandler	          [WEAK]
                EXPORT  MFS11_RX_IRQHandler	          [WEAK]
                EXPORT  MFS11_TX_IRQHandler	          [WEAK]
                EXPORT  ADC2_IRQHandler	          [WEAK]
                EXPORT  USB1_IRQHandler	          [WEAK]
                EXPORT  USB1_HOST_IRQHandler	          [WEAK]
                EXPORT  SD_IRQHandler	          [WEAK]
                EXPORT  FLASHIF_IRQHandler	          [WEAK]
                EXPORT  MFS12_RX_IRQHandler	          [WEAK]
                EXPORT  MFS12_TX_IRQHandler	          [WEAK]
                EXPORT  MFS13_RX_IRQHandler	          [WEAK]
                EXPORT  MFS13_TX_IRQHandler	          [WEAK]
                EXPORT  MFS14_RX_IRQHandler	          [WEAK]
                EXPORT  MFS14_TX_IRQHandler	          [WEAK]
                EXPORT  MFS15_RX_IRQHandler	          [WEAK]
                EXPORT  MFS15_TX_IRQHandler	          [WEAK]
                EXPORT  Dummy	          [WEAK]



CSV_IRQHandler
SWDT_IRQHandler
LVD_IRQHandler
IRQ003SEL_IRQHandler
IRQ004SEL_IRQHandler
IRQ005SEL_IRQHandler
IRQ006SEL_IRQHandler
IRQ007SEL_IRQHandler
IRQ008SEL_IRQHandler
IRQ009SEL_IRQHandler
IRQ010SEL_IRQHandler
EXINT0_IRQHandler
EXINT1_IRQHandler
EXINT2_IRQHandler
EXINT3_IRQHandler
EXINT4_IRQHandler
EXINT5_IRQHandler
EXINT6_IRQHandler
EXINT7_IRQHandler
QPRC0_IRQHandler
QPRC1_IRQHandler
WFG0_DTIF0_IRQHandler
WFG1_DTIF1_IRQHandler
WFG2_DTIF2_IRQHandler
FRT0_PEAK_IRQHandler
FRT0_ZERO_IRQHandler
ICU0_IRQHandler
OCU0_IRQHandler
FRT1_PEAK_IRQHandler
FRT1_ZERO_IRQHandler
ICU1_IRQHandler
OCU1_IRQHandler
FRT2_PEAK_IRQHandler
FRT2_ZERO_IRQHandler
ICU2_IRQHandler
OCU2_IRQHandler
PPG00_02_04_IRQHandler
PPG08_10_12_IRQHandler
PPG16_18_20_IRQHandler
BT0_IRQHandler
BT1_IRQHandler
BT2_IRQHandler
BT3_IRQHandler
BT4_IRQHandler
BT5_IRQHandler
BT6_IRQHandler
BT7_IRQHandler
DT1_2_IRAHandler
WC_IRQHandler
EXTBUS_ERR_Handler
RTC_IRQHandler
EXTINT8_IRQHandler
EXTINT9_IRQHandler
EXTINT10_IRQHandler
EXTINT11_IRQHandler
EXTINT12_IRQHandler
EXTINT13_IRQHandler
EXTINT14_IRQHandler
EXTINT15_IRQHandler
TIM_IRQHandler
MFS0_RX_IRQHandler
MFS0_TX_IRQHandler
MFS1_RX_IRQHandler
MFS1_TX_IRQHandler
MFS2_RX_IRQHandler
MFS2_TX_IRQHandler
MFS3_RX_IRQHandler
MFS3_TX_IRQHandler
MFS4_RX_IRQHandler
MFS4_TX_IRQHandler
MFS5_RX_IRQHandler
MFS5_TX_IRQHandler
MFS6_RX_IRQHandler
MFS6_TX_IRQHandler
MFS7_RX_IRQHandler
MFS7_TX_IRQHandler
ADC0_IRQHandler
ADC1_IRQHandler
USB0_IRQHandler
USB0_HOST_IRQHandler
CAN0_IRQHandler
CAN1_IRQHandler
ETHER0_IRQHandler
DMAC0_IRQHandler
DMAC1_IRQHandler
DMAC2_IRQHandler
DMAC3_IRQHandler
DMAC4_IRQHandler
DMAC5_IRQHandler
DMAC6_IRQHandler
DMAC7_IRQHandler
DSTC_IRQHandler
EXINT16_17_18_19_IRQHandler
EXINT20_21_22_23_IRQHandler
EXINT24_25_26_27_IRQHandler
EXINT28_29_30_31_IRQHandler
QPRC2_IRQHandler
QPRC3_IRQHandler
BT8_IRQHandler
BT9_IRQHandler
BT10_IRQHandler
BT11_IRQHandler
BT12_15_IRQHandler
MFS8_RX_IRQHandler
MFS8_TX_IRQHandler
MFS9_RX_IRQHandler
MFS9_TX_IRQHandler
MFS10_RX_IRQHandler
MFS10_TX_IRQHandler
MFS11_RX_IRQHandler
MFS11_TX_IRQHandler
ADC2_IRQHandler
USB1_IRQHandler
USB1_HOST_IRQHandler
SD_IRQHandler
FLASHIF_IRQHandler
MFS12_RX_IRQHandler
MFS12_TX_IRQHandler
MFS13_RX_IRQHandler
MFS13_TX_IRQHandler
MFS14_RX_IRQHandler
MFS14_TX_IRQHandler
MFS15_RX_IRQHandler
MFS15_TX_IRQHandler
Dummy


                B       .

                ENDP


                ALIGN


; User Initial Stack & Heap

                IF      :DEF:__MICROLIB
                
                EXPORT  __initial_sp
                EXPORT  __heap_base
                EXPORT  __heap_limit
                
                ELSE
                
                IMPORT  __use_two_region_memory
                EXPORT  __user_initial_stackheap
__user_initial_stackheap

                LDR     R0, = Heap_Mem
                LDR     R1, = (Stack_Mem + Stack_Size)
                LDR     R2, = (Heap_Mem + Heap_Size)
                LDR     R3, = Stack_Mem
                BX      LR

                ALIGN

                ENDIF


                END
