
#include "Test_Cases.h"


/************************************************************************************
 * Description: Structures holds the test cases of the function Alg_binarySearch.
************************************************************************************/
str_TC_PaymentSys_t  astr_TC_PaymentSys_TestData[TC_PAYSYS_NUM] =
{
    {"TC_PaymentSys_StartPaymentSystem_01",       PS_ERROR_OK,            NULL, {{"Ahmed Nabil", "456789123", "12/19"}, {20.5,   5000.0, "27/11/2019"}, TRANS_APPROVED}  , NULL},
    {"TC_PaymentSys_checkExpiration_01",          PS_CARD_EXPIRED,        NULL, {{"Ahmed Nabil", "456789123", "10/19"}, {20.5,   5000.0, "27/11/2019"}, TRANS_APPROVED}  , NULL},
    {"TC_PaymentSys_sendTransactionToServer_01",  PS_BALANCE_LOW,         NULL, {{"Ahmed Nabil", "456789123", "12/19"}, {2000.0, 5000.0, "27/11/2019"}, TRANS_APPROVED}  , NULL},
    {"TC_PaymentSys_sendTransactionToServer_02",  PS_PAN_NOT_FOUND,       NULL, {{"Ahmed Nabil", "456789124", "12/19"}, {20.5,   5000.0, "27/11/2019"}, TRANS_APPROVED}  , NULL},
    {"TC_PaymentSys_processTerminal_01",          PS_MAX_AMOUNT_EXCEEDED, NULL, {{"Ahmed Nabil", "456789123", "12/19"}, {6000.0, 5000.0, "27/11/2019"}, TRANS_APPROVED}  , NULL}
};

