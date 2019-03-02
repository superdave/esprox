#include "freertos/FreeRTOS.h"
#include "esp_wifi.h"
#include "esp_system.h"
#include "esp_event.h"
#include "esp_event_loop.h"
#include "nvs_flash.h"
#include "driver/gpio.h"
#include "driver/spi_master.h"

#include "nfc/dal.h"
#include "nfc/config.h"

esp_err_t event_handler(void *ctx, system_event_t *event)
{
    return ESP_OK;
}

esp_err_t board_setup() {
    esp_err_t rv;

    static gpio_config_t in_cfg = {
        .intr_type    = GPIO_PIN_INTR_DISABLE,
        .mode         = GPIO_MODE_INPUT,
        .pin_bit_mask = PINS_IN,
        .pull_down_en = 0,
        .pull_up_en   = 0
    };
    rv = gpio_config(&in_cfg);
    ESP_ERROR_CHECK(rv);

    static gpio_config_t out_cfg = {
        .intr_type    = GPIO_PIN_INTR_DISABLE,
        .mode         = GPIO_MODE_OUTPUT,
        .pin_bit_mask = PINS_OUT,
        .pull_down_en = 0,
        .pull_up_en   = 0,
    };
    rv = gpio_config(&out_cfg);
    ESP_ERROR_CHECK(rv);

    out_cfg.mode         = GPIO_MODE_OUTPUT_OD;
    out_cfg.pin_bit_mask = PINS_OD;
    //rv = gpio_config(&out_cfg);
    //ESP_ERROR_CHECK(rv);

    return rv;
}

void app_main(void)
{
    nvs_flash_init();
    tcpip_adapter_init();
    ESP_ERROR_CHECK( esp_event_loop_init(event_handler, NULL) );
    wifi_init_config_t cfg = WIFI_INIT_CONFIG_DEFAULT();
    ESP_ERROR_CHECK( esp_wifi_init(&cfg) );
    ESP_ERROR_CHECK( esp_wifi_set_storage(WIFI_STORAGE_RAM) );
    ESP_ERROR_CHECK( esp_wifi_set_mode(WIFI_MODE_STA) );
    wifi_config_t sta_config = {
        .sta = {
            .ssid = CONFIG_ESP_WIFI_SSID,
            .password = CONFIG_ESP_WIFI_PASSWORD,
            .bssid_set = false
        }
    };
    ESP_ERROR_CHECK( esp_wifi_set_config(WIFI_IF_STA, &sta_config) );
    ESP_ERROR_CHECK( esp_wifi_start() );
    ESP_ERROR_CHECK( esp_wifi_connect() );

    nfc_context_t nfc_ctx;
    ESP_ERROR_CHECK( nfc_init(&nfc_ctx) );

    //ESP_ERROR_CHECK( board_setup() );

    /*
    dal_nfc_reset(10);

    printf("waiting for idle IRQ\n");
    while(gpio_get_level(PIN_IRQ)) {}
    printf("IRQ asserted\n");

    for(int i = 0; i < 5; i++) {
        uint8_t buf[512] = {0};
        uint8_t rd_reg[] = {0x04, 0x02};
        while(gpio_get_level(PIN_BUSY)) {}
        ESP_ERROR_CHECK( dal_spi_transact(spi, rd_reg, rd_reg, sizeof(rd_reg)) );

        printf("waiting for busy\n");
        while(!gpio_get_level(PIN_BUSY)) {}
        printf("busy, waiting for idle\n");
        while(gpio_get_level(PIN_BUSY)) {}
        printf("no longer busy\n");

        ESP_ERROR_CHECK( dal_spi_transact(spi, buf, buf, 4) );
        printf("received: ");
        for(int i = 0; i < 4; i++) {
            printf("%02X ", buf[i]);
        }
        printf("\n");
        printf("waiting for busy\n");
        while(!gpio_get_level(PIN_BUSY)) {}
    }
    */
}

