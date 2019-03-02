#ifndef NFC_FREERTOS_H
#define NFC_FREERTOS_H


#include "freertos/FreeRTOS.h"


#undef portYIELD_FROM_ISR
#define portYIELD_FROM_ISR(...)        {traceISR_EXIT_TO_SCHEDULER(); _frxt_setup_switch();}

#endif /* NFC_FREERTOS_H */
