#ifndef NFC_DAL_H
#define NFC_DAL_H

#include "driver/spi_master.h"

#include "ph_Status.h"
#include "phDriver.h"
#include "phNfcLib.h"

typedef struct {
    phNfcLib_AppContext_t ctx;
    phbalReg_Type_t balreg;
} nfc_context_t;

typedef phNfcLib_Status_t nfc_status_t;

nfc_status_t nfc_init(nfc_context_t *ctx);

esp_err_t dal_nfc_reset(int delay);

esp_err_t dal_spi_transact(spi_device_handle_t dev,
                           const void *tx,
                           void       *rx,
                           int        n);

#endif /* NFC_DAL_H */
