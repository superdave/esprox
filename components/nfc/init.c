
#include "nfc/dal.h"

#include "phOsal.h"

nfc_status_t nfc_init(nfc_context_t *ctx) {
    nfc_status_t status;

    phOsal_Init();

    status = phbalReg_Init(&ctx->balreg, sizeof(ctx->balreg));
    
    return status;
}
