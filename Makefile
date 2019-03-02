#
# This is a project Makefile. It is assumed the directory this Makefile resides in is a
# project subdirectory.
#

PROJECT_NAME := esprox

CFLAGS += -DPH_OSAL_FREERTOS 

include $(IDF_PATH)/make/project.mk
