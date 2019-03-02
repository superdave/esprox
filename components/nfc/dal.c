#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "driver/spi_master.h"

#include "nfc/dal.h"
#include "nfc/config.h"

esp_err_t dal_nfc_reset(int delay) {
    printf("resetting PN5180\n");
    gpio_set_level(PIN_RESET, 0);

    // If there's any non-negative delay set, delay and release reset.
    if(delay >= 0) {
        vTaskDelay(delay / portTICK_PERIOD_MS);
        gpio_set_level(PIN_RESET, 1);
    }

    return ESP_OK;
}

esp_err_t dal_spi_transact(spi_device_handle_t dev,
                           const void *tx,
                           void       *rx,
                           int        n) {
    spi_transaction_t txn = {
        .length = n * 8,
        .tx_buffer = tx,
        .rx_buffer = rx,
    };

    return spi_device_transmit(dev, &txn);
}

