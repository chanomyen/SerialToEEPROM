#include <Arduino.h>
// #include "Memory.h"
#include "SerialCommand.h"

#define UART_BUFFER_SIZE    64
char    UART_BUFFER[UART_BUFFER_SIZE];
uint8_t UART_RX_COUNTER = 0;
uint8_t UART_RX_COMPLETED = 0;

void replaceComma();

void setup() {
  Serial.begin(115200);
  char * devID;
  EEPROM.get(21, devID);
  Serial.print("Device ID: ");
  Serial.println(devID);
}

void loop() {

}

void serialEvent() {
  char buff;
  while (Serial.available()) {
    buff = Serial.read();
    UART_BUFFER[UART_RX_COUNTER++] = buff;
  }
  if (buff == '\n') {
    char cmd[10];
    char params[20];

    memset(cmd, 0, sizeof(cmd));
    memset(params, 0, sizeof(params));

    replaceComma();
    sscanf(UART_BUFFER, "$%s %s \n", cmd, params);  //parse the parameters

    Serial.print("cmd:");
    Serial.println(cmd);
    Serial.print("params:");
    Serial.println(params);

    if (cmdExecute(cmd, params) > 0) {
      Serial.println("CMD FAILED!");
    } else {
      Serial.println("CMD OK!");
    }

    // clear UART RX buffer and counter
    UART_RX_COUNTER = 0;
    memset(UART_BUFFER, 0, sizeof(UART_BUFFER));
  }
}

void replaceComma() {
  uint8_t i = 0;
  while (UART_BUFFER[i] != ',') {
    i++;
  }
  UART_BUFFER[i] = ' ';
}