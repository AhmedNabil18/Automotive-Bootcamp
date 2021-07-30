#ifndef _TEST_CASES_CFG_H_
#define _TEST_CASES_CFG_H_

#define TC_PAYSYS_NUM             5


#define TC_STRT_PAY_SYS_01             0
#define TC_CHK_EXPIRY_01               1
#define TC_SEND_TRANS_SERVER_01        2
#define TC_SEND_TRANS_SERVER_02        3
#define TC_PROCESS_TERMINAL_01         4


/**
 ** MACROS and CONSTANTS
 **/
#define PS_TERMINAL_DENIED              0x00
#define PS_TERMINAL_APPROVED            0x01
#define PS_CHECK_EXPIRATION_ERROR       0x02
#define PS_CARD_EXPIRED                 0x03
#define PS_CARD_NOT_EXPIRED             0x04
#define PS_MAX_AMOUNT_EXCEEDED          0x05


#define PS_SERVER_DENIED                0x10
#define PS_SERVER_APPROVED              0x11
#define PS_BALANCE_LOW                  0x12
#define PS_PAN_NOT_FOUND                0x13

#define PS_ERROR_OK                     0xFF
#define PS_ERROR_NOK                    0xAA

#endif // _TEST_CASES_CFG_H_
