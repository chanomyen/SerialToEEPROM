// #include "Memory.h"
#include <Arduino.h>
#include <EEPROM.h>
#include "Memory.h"

#define CMD_SET_DEVICE_ID       "setdevid"
#define CMD_SET_DEVICE_TOKEN    "setdevtoken"
#define CMD_DEMO_ENABLE         "demo_enable"
#define CMD_DEMO_DISABLE        "demo_disable"
#define CMD_DEBUG_ENABLE        "debug_enable"
#define CMD_DEBUG_DISABLE       "debug_disable"
#define CMD_TX_ENABLE           "tx_enable"
#define CMD_TX_DISABLE          "tx_disable"
#define CMD_REBOOT              "reboot"
#define CMD_MEM_CLEAR           "memclean"
#define CMD_PARAMS_CHECK        "check_params"
#define CMD_GET_CONFIG          "getconf"
#define CMD_GET_INDEX           "getindex"

/**
 * @default configuration
*/
#define DEFAULT_DEMO_MODE       (uint8_t)0
#define DEFAULT_DEBUG_MODE      (uint8_t)0
#define DEFAULT_TXEN            (uint8_t)1
#define DEFAULT_DEVICE_TOKEN    (char*)"$defaultdevicetoken$"
#define DEFAULT_DEVICE_ID       (char*)"$defaultdeviceid$"


uint8_t cmdExecute(char cmd[10], char params[20]); // execute serial command
void checkDefaultParams();
void getConfigure();
void getIndex();