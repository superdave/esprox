# Location (relative to here) of the NXP library in use.
NXP_LIB_DIR := NxpNfcRdLib_PN5180_LPC1769_v05.21.00_Full

# Include directories for the local libs.
COMPONENT_ADD_INCLUDEDIRS := include \
	$(NXP_LIB_DIR)/DAL/inc \
	$(NXP_LIB_DIR)/phOsal/inc \
	$(NXP_LIB_DIR)/NxpNfcRdLib/types \
	$(NXP_LIB_DIR)/NxpNfcRdLib/intfs \
	
COMPONENT_SRCDIRS := . \
	$(NXP_LIB_DIR)/phOsal/src/Freertos

CFLAGS += -DPH_OSAL_FREERTOS -DxPortIsInsideInterrupt=xPortInIsrContext -isystem $(IDF_PATH)/components/freertos/include/freertos -Dmain=notmain
