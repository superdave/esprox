# Location (relative to here) of the NXP library in use.
NXP_LIB_DIR := NxpNfcRdLib_PN5180_LPC1769_v05.21.00_Full

# Include directories for the local libs.
COMPONENT_ADD_INCLUDEDIRS := include \
	$(NXP_LIB_DIR)/DAL/inc \
	$(NXP_LIB_DIR)/phOsal/inc \
	$(NXP_LIB_DIR)/NxpNfcRdLib/types \
	$(NXP_LIB_DIR)/NxpNfcRdLib/intfs \
	
COMPONENT_PRIV_INCLUDEDIRS := \
	$(NXP_LIB_DIR)/NxpNfcRdLib/comps/phhalHw/src/pn5180 \
	$(NXP_LIB_DIR)/NfcrdlibEx2_AdvancedDiscoveryLoop/intfs

COMPONENT_SRCDIRS := . \
	$(NXP_LIB_DIR)/phOsal/src/Freertos \
	$(NXP_LIB_DIR)/NxpNfcRdLib/comps/phacDiscLoop/src \
	$(NXP_LIB_DIR)/NxpNfcRdLib/comps/phacDiscLoop/src/Sw \
	$(NXP_LIB_DIR)/NxpNfcRdLib/comps/phalFelica/src \
	$(NXP_LIB_DIR)/NxpNfcRdLib/comps/phalFelica/src/Sw \
	$(NXP_LIB_DIR)/NxpNfcRdLib/comps/phalI18000p3m3/src \
	$(NXP_LIB_DIR)/NxpNfcRdLib/comps/phalI18000p3m3/src/Sw \
	$(NXP_LIB_DIR)/NxpNfcRdLib/comps/phalICode/src \
	$(NXP_LIB_DIR)/NxpNfcRdLib/comps/phalICode/src/Sw \
	$(NXP_LIB_DIR)/NxpNfcRdLib/comps/phalMfc/src \
	$(NXP_LIB_DIR)/NxpNfcRdLib/comps/phalMfc/src/Sw \
	$(NXP_LIB_DIR)/NxpNfcRdLib/comps/phalMfdf/src \
	$(NXP_LIB_DIR)/NxpNfcRdLib/comps/phalMfdf/src/Sw \
	$(NXP_LIB_DIR)/NxpNfcRdLib/comps/phalMfdfEv2/src \
	$(NXP_LIB_DIR)/NxpNfcRdLib/comps/phalMfdfEv2/src/Sw \
	$(NXP_LIB_DIR)/NxpNfcRdLib/comps/phalMfp/src \
	$(NXP_LIB_DIR)/NxpNfcRdLib/comps/phalMfp/src/Sw \
	$(NXP_LIB_DIR)/NxpNfcRdLib/comps/phalMfpEv1/src \
	$(NXP_LIB_DIR)/NxpNfcRdLib/comps/phalMfpEv1/src/Sw \
	$(NXP_LIB_DIR)/NxpNfcRdLib/comps/phalMful/src \
	$(NXP_LIB_DIR)/NxpNfcRdLib/comps/phalMful/src/Sw \
	$(NXP_LIB_DIR)/NxpNfcRdLib/comps/phalT1T/src \
	$(NXP_LIB_DIR)/NxpNfcRdLib/comps/phalT1T/src/Sw \
	$(NXP_LIB_DIR)/NxpNfcRdLib/comps/phalTop/src \
	$(NXP_LIB_DIR)/NxpNfcRdLib/comps/phalTop/src/Sw \
	$(NXP_LIB_DIR)/NxpNfcRdLib/comps/phalVca/src \
	$(NXP_LIB_DIR)/NxpNfcRdLib/comps/phalVca/src/Sw \
	$(NXP_LIB_DIR)/NxpNfcRdLib/comps/phceT4T/src \
	$(NXP_LIB_DIR)/NxpNfcRdLib/comps/phceT4T/src/Sw \
	$(NXP_LIB_DIR)/NxpNfcRdLib/comps/phCidManager/src \
	$(NXP_LIB_DIR)/NxpNfcRdLib/comps/phCidManager/src/Sw \
	$(NXP_LIB_DIR)/NxpNfcRdLib/comps/phCryptoRng/src \
	$(NXP_LIB_DIR)/NxpNfcRdLib/comps/phCryptoRng/src/Sw \
	$(NXP_LIB_DIR)/NxpNfcRdLib/comps/phCryptoSym/src \
	$(NXP_LIB_DIR)/NxpNfcRdLib/comps/phCryptoSym/src/Sw \
	$(NXP_LIB_DIR)/NxpNfcRdLib/comps/phhalHw/src \
	$(NXP_LIB_DIR)/NxpNfcRdLib/comps/phhalHw/src/pn5180 \
	$(NXP_LIB_DIR)/NxpNfcRdLib/comps/phKeyStore/src \
	$(NXP_LIB_DIR)/NxpNfcRdLib/comps/phKeyStore/src/Rc663 \
	$(NXP_LIB_DIR)/NxpNfcRdLib/comps/phKeyStore/src/SamAV2 \
	$(NXP_LIB_DIR)/NxpNfcRdLib/comps/phKeyStore/src/Sw \
	$(NXP_LIB_DIR)/NxpNfcRdLib/comps/phInLlcp/src \
	$(NXP_LIB_DIR)/NxpNfcRdLib/comps/phLog/src \
	$(NXP_LIB_DIR)/NxpNfcRdLib/comps/phNfcLib/src \
	$(NXP_LIB_DIR)/NxpNfcRdLib/comps/phnpSnep/src \
	$(NXP_LIB_DIR)/NxpNfcRdLib/comps/phnpSnep/src/Sw \
	$(NXP_LIB_DIR)/NxpNfcRdLib/comps/phpalEpcUid/src \
	$(NXP_LIB_DIR)/NxpNfcRdLib/comps/phpalEpcUid/src/Sw \
	$(NXP_LIB_DIR)/NxpNfcRdLib/comps/phpalFelica/src \
	$(NXP_LIB_DIR)/NxpNfcRdLib/comps/phpalFelica/src/Sw \
	$(NXP_LIB_DIR)/NxpNfcRdLib/comps/phpalI14443p3a/src \
	$(NXP_LIB_DIR)/NxpNfcRdLib/comps/phpalI14443p3a/src/Sw \
	$(NXP_LIB_DIR)/NxpNfcRdLib/comps/phpalI14443p3b/src \
	$(NXP_LIB_DIR)/NxpNfcRdLib/comps/phpalI14443p3b/src/Sw \
	$(NXP_LIB_DIR)/NxpNfcRdLib/comps/phpalI14443p4/src \
	$(NXP_LIB_DIR)/NxpNfcRdLib/comps/phpalI14443p4/src/Sw \
	$(NXP_LIB_DIR)/NxpNfcRdLib/comps/phpalI14443p4a/src \
	$(NXP_LIB_DIR)/NxpNfcRdLib/comps/phpalI14443p4a/src/Sw \
	$(NXP_LIB_DIR)/NxpNfcRdLib/comps/phpalI14443p4mC/src \
	$(NXP_LIB_DIR)/NxpNfcRdLib/comps/phpalI14443p4mC/src/Sw \
	$(NXP_LIB_DIR)/NxpNfcRdLib/comps/phpalI18000p3m3/src \
	$(NXP_LIB_DIR)/NxpNfcRdLib/comps/phpalI18000p3m3/src/Sw \
	$(NXP_LIB_DIR)/NxpNfcRdLib/comps/phpalI18092mPI/src \
	$(NXP_LIB_DIR)/NxpNfcRdLib/comps/phpalI18092mPI/src/Sw \
	$(NXP_LIB_DIR)/NxpNfcRdLib/comps/phpalI18092mT/src \
	$(NXP_LIB_DIR)/NxpNfcRdLib/comps/phpalI18092mT/src/Sw \
	$(NXP_LIB_DIR)/NxpNfcRdLib/comps/phpalMifare/src \
	$(NXP_LIB_DIR)/NxpNfcRdLib/comps/phpalMifare/src/sw \
	$(NXP_LIB_DIR)/NxpNfcRdLib/comps/phpalSli15693/src \
	$(NXP_LIB_DIR)/NxpNfcRdLib/comps/phpalSli15693/src/sw \
	$(NXP_LIB_DIR)/NxpNfcRdLib/comps/phTMIUtils/src \
	$(NXP_LIB_DIR)/NxpNfcRdLib/comps/phTools/src \
	$(NXP_LIB_DIR)/NfcrdlibEx2_AdvancedDiscoveryLoop   \
	$(NXP_LIB_DIR)/NfcrdlibEx2_AdvancedDiscoveryLoop/src

CFLAGS += -DxPortIsInsideInterrupt=xPortInIsrContext -isystem $(IDF_PATH)/components/freertos/include/freertos -Dmain=notmain -DNXPBUILD__PHHAL_HW_PN5180 -DNXPBUILD__PH_LOG
