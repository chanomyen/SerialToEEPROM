#include <Arduino.h>
#include "Memory.h"
#include "SerialCommand.h"

/**
 * @default configuration
*/
#define DEFAULT_DEMO_MODE       0
#define DEFAULT_TXEN            1
#define DEFAULT_DEVICE_TOKEN    "$defaultdevicetoken$"
#define DEFAULT_DEVICE_ID       "$defaultdeviceid$"

#define UART_BUFFER_SIZE    64
char    UART_BUFFER[UART_BUFFER_SIZE];
uint8_t UART_RX_COUNTER = 0;
uint8_t UART_RX_COMPLETED = 0;

uint16_t DataObject::_allocated = 0;
DataObject DeviceToken(21);
DataObject DeviceId(21);
DataObject Debug(1);
DataObject Demo(1);
DataObject TXMode(1);

void checkDefaultParams();