#include "SerialCommand.h"

uint16_t DataObject::_allocated = 0;
DataObject DeviceToken(21);
DataObject DeviceId(21);
DataObject Debug(1);
DataObject Demo(1);
DataObject TXMode(1);

uint8_t cmdExecute(char cmd[10], char params[20]) {
  if (strcmp(cmd, CMD_REBOOT) == 0) {                     // reboot
    // reboot
    return 1;
  } else if (strcmp(cmd, CMD_SET_DEVICE_ID) == 0) {       // set device id
    char *devID = params;
    Serial.print("New deiviceID: ");
    Serial.println(devID);
    return DeviceId.putData(devID);
    // return DeviceId.putData("devID0123456");
  } else if (strcmp(cmd, CMD_SET_DEVICE_TOKEN) == 0) {    // set device token
    return DeviceToken.putData(params);
  } else if (strcmp(cmd, CMD_MEM_CLEAR) == 0) {           // clean EEPROM
    Serial.println("start cleaning the memory.");
    cleanMemory();
    Serial.println("memory has cleaned.");
    return 1;
  } else if (strcmp(cmd, CMD_PARAMS_CHECK) == 0) {     
    checkDefaultParams();
    return 1;
  } else if (strcmp(cmd, CMD_GET_CONFIG) == 0) {     
    getConfigure();
    return 1;
  } else if (strcmp(cmd, CMD_GET_INDEX) == 0) {     
    getIndex();
    return 1;
  } else {
    Serial.println("Command not found!");
    return 0;
  }
}

/*************************************************************************************************
 * @brief: If the parameter is null and then this function will put a default parameter to it.
**************************************************************************************************/
void checkDefaultParams() {
  if (DeviceId.getData() == '\0') {
    DeviceId.putData(DEFAULT_DEVICE_ID);
    Serial.println("DEFAULT_DEVICE_ID has applied!");
  }
  if (DeviceToken.getData() == '\0') {
    DeviceToken.putData(DEFAULT_DEVICE_TOKEN);
    Serial.println("DEFAULT_DEVICE_TOKEN has applied!");
  }
  if (Debug.getData() == 0) {
    Debug.putData(DEFAULT_DEBUG_MODE);
    Serial.println("Debug mode has disabled!");
  }
  if (Demo.getData() == 0) {
    Demo.putData(DEFAULT_DEMO_MODE);
    Serial.println("Demo mode has disabled!");
  }
  if (TXMode.getData() == 0) {
    TXMode.putData(DEFAULT_TXEN);
    Serial.println("TX mode has enabled!");
  }
}

void getConfigure() {
  String msg = "Device ID: ";
  msg += DeviceId.getData();
  Serial.println(msg);

  msg = "Device Token: ";
  msg += DeviceToken.getData();
  Serial.println(msg);

  msg = "Debug mode: ";
  uint8_t mode;
  Debug.getData(mode);
  msg += mode;
  Serial.println(msg);

  msg = "Demo mode: ";
  Demo.getData(mode);
  msg += mode;
  Serial.println(msg);

  msg = "TX mode: ";
  TXMode.getData(mode);
  msg += mode;
  Serial.println(msg);
  // msg.
}

void getIndex() {
  Serial.println(DeviceId.getFirstIndex());
  Serial.println(DeviceToken.getFirstIndex());
  Serial.println(Demo.getFirstIndex());
  Serial.println(Debug.getFirstIndex());
  Serial.println(TXMode.getFirstIndex());
}