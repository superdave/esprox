#include <stdint.h>

#include "esp_log.h"

#include "nfc/dal.h"

#include "phDriver.h"
#include "phDriver_gpio.h"
#include "phDriver_spi.h"

static const char *TAG = "NFC";

static spi_device_handle_t g_spi_dev;

phStatus_t phbalReg_Init(void     *pDataParams,
                         uint16_t  wSizeOfDataParams) {
    phbalReg_Type_t *params = (phbalReg_Type_t *)pDataParams;
    params->wId = PH_COMP_DRIVER;
    params->bBalType = PHBAL_REG_TYPE_SPI;

    ESP_ERROR_CHECK( init_spi(&g_spi_dev) );

    phDriver_GPIOInit();
    return PH_DRIVER_SUCCESS;
}

phStatus_t phbalReg_SetConfig(void     *pDataParams,
                              uint16_t  wConfig,
                              uint16_t  wValue) {
    return PH_DRIVER_SUCCESS;
}

phStatus_t phbalReg_GetConfig(void     *pDataParams,
                              uint16_t  wConfig,
                              uint16_t *pValue) {
    return PH_DRIVER_SUCCESS;
}

phStatus_t phbalReg_Exchange(void     *pDataParams,
                             uint16_t  wOption,
                             uint8_t  *pTxBuffer,
                             uint16_t  wTxLength,
                             uint16_t  wRxBufSize,
                             uint8_t  *pRxBuffer,
                             uint16_t *pRxLength) {
    uint16_t len = wTxLength ? wTxLength : wRxBufSize; 
    ESP_LOGD(TAG, "SPI transaction: write %d read %d options 0x%08x",
             wTxLength, wRxBufSize, wOption);

    if(wTxLength && pTxBuffer != NULL) {
        ESP_LOGD(TAG, "Write data:");
        ESP_LOG_BUFFER_HEX_LEVEL(TAG, pTxBuffer, wTxLength, ESP_LOG_DEBUG);

        // Do the write transaction.
        ESP_ERROR_CHECK( dal_spi_transact(g_spi_dev,
                                          pTxBuffer,
                                          NULL,
                                          wTxLength) );
    }

    if(wRxBufSize && pRxBuffer != NULL) {
        ESP_LOGD(TAG, "Initing %d bytes of read buffer %p", wRxBufSize, pRxBuffer);
        // Fill the read buffer, which will be outgoing, with FF.
        //memset(pRxBuffer, 0xff, wRxBufSize);

        ESP_LOGD(TAG, "Reading %d bytes", wRxBufSize);
        // Do the read transaction.
        ESP_ERROR_CHECK( dal_spi_transact(g_spi_dev,
                                          pRxBuffer,
                                          pRxBuffer,
                                          wRxBufSize) );

        ESP_LOGD(TAG, "Read data:\n");
        ESP_LOG_BUFFER_HEX_LEVEL(TAG, pRxBuffer, wTxLength, ESP_LOG_DEBUG);
        *pRxLength = len;
    }

    return PH_DRIVER_SUCCESS;
}
