#include <stdint.h>

#include "nfc/dal.h"

#include "phDriver.h"
#include "phDriver_gpio.h"
#include "phDriver_spi.h"

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
    esp_err_t err = dal_spi_transact(g_spi_dev,
                                     pTxBuffer,
                                     pRxBuffer,
                                     wTxLength ? wTxLength : *pRxLength);
    return (err == ESP_OK) ? PH_DRIVER_SUCCESS : PH_DRIVER_ERROR;
}
