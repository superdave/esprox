#ifndef NFC_CONFIG_H
#define NFC_CONFIG_H


#define BOARD_DEVKITC

#ifdef BOARD_DEVKITC
#define PIN_MOSI  26
#define PIN_MISO  27
#define PIN_SSEL  25
#define PIN_SCLK  14
#define PIN_BUSY  12
#define PIN_RESET 33
#define PIN_IRQ   23
#define PIN_AUX1  22
#define PIN_DWL   21
#define PIN_GPO1  19
#endif

#define PIN_MASK(n) ((uint64_t)1 << (n))

#define PINS_OUT (PIN_MASK(PIN_MOSI)  | \
                  PIN_MASK(PIN_SSEL)  | \
                  PIN_MASK(PIN_SCLK)  | \
                  PIN_MASK(PIN_RESET) | \
                  PIN_MASK(PIN_DWL))

#define PINS_OD (0)

#define PINS_IN (PIN_MASK(PIN_MISO) | \
                 PIN_MASK(PIN_IRQ)  | \
                 PIN_MASK(PIN_AUX1) | \
                 PIN_MASK(PIN_GPO1) | \
                 PIN_MASK(PIN_BUSY))

#endif /* NFC_CONFIG_H */

