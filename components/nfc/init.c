#include "esp_log.h"

const char *TAG = "NFC_INIT";

#include "nfc/dal.h"

#include "phOsal.h"

#define CHECK_STATUS(status) {\
    const nfc_status_t s = (status);\
    if(s != PH_DRIVER_SUCCESS) {\
        ESP_LOGE(TAG, "Failure at "__FILE__", line %d: %04x", __LINE__, s);\
        return s;\
    }}

nfc_status_t nfc_init(nfc_context_t *ctx) {
    nfc_status_t status;

    phOsal_Init();

    printf("Init phbal\n");
    CHECK_STATUS(phbalReg_Init(&ctx->balreg, sizeof(ctx->balreg)));
    
    printf("Setting context\n");
    ctx->ctx.pBalDataparams = &ctx->balreg;
    CHECK_STATUS(phNfcLib_SetContext(&ctx->ctx));

    printf("Init NfcLib\n");
    CHECK_STATUS(phNfcLib_Init());

    printf("Done init\n");
    return PH_DRIVER_SUCCESS;
}
