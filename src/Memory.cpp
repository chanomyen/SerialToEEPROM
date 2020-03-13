#include "Memory.h"

// uint8_t isEmptryDeviceID(void) {
//   char deviceID[20];
//   EEPROM.get(EEPROM_INDEX_DEVICE_ID, deviceID);
//   // EEPROM.put(EEPROM_INDEX_DEVICE_ID, DEFAULT_DEVICE_ID);
//   if (strcmp(deviceID, '\0') == 0) {
//     EEPROM.put(EEPROM_INDEX_DEVICE_ID, DEFAULT_DEVICE_ID);
//     return 1;
//   } else {
//     Serial.println(deviceID);
//     return 0;
//   }
// }

void cleanMemory() {
  for (int i = 0 ; i < EEPROM.length() ; i++) {
    EEPROM.write(i, 0);
  }
}

// the size must more than 0 if the size is 0 it would be 1 automatically and by default.
DataObject::DataObject(uint16_t size = 1)
{
  if (size < 1) _size = 1;
  else _size = size;
  _first_index = _allocated;
  _allocated += _size;
}

uint16_t DataObject::getFirstIndex() {
  return _first_index;
}

// Space size in bytes
static uint16_t DataObject::getFreeSpace() {
  return EEPROM_SIZE - _allocated;
}

// Allocated block
static uint16_t DataObject::getAllocated() {
  return _allocated;
}

// Memory report
// return size of free space
static uint16_t DataObject::memoryReport() {
  Serial.print("Used space: ");
  Serial.println(DataObject::getAllocated());
  Serial.print("Free space: ");
  uint16_t space = DataObject::getFreeSpace();
  Serial.println(space);
  return space;
}

// put data in EEPROM.
// return: 0 is mean data too big and 1 is fit.
uint8_t DataObject::putData(uint8_t data) {
  if (sizeof(data) > _size) return 0;
  EEPROM.put(_first_index, data);
  return 1;
}

// put data in EEPROM.
// return: 0 is mean data too big and 1 is fit.
uint8_t DataObject::putData(uint16_t data) {
  if (sizeof(data) > _size) return 0;
  EEPROM.put(_first_index, data);
  return 1;
}

// put data in EEPROM.
// return: 0 is mean data too big and 1 is fit.
uint8_t DataObject::putData(uint32_t data) {
  if (sizeof(data) > _size) return 0;
  EEPROM.put(_first_index, data);
  return 1;
}

// put data in EEPROM.
// return: 0 is mean data too big and 1 is fit.
uint8_t DataObject::putData(uint64_t data) {
  if (sizeof(data) > _size) return 0;
  EEPROM.put(_first_index, data);
  return 1;
}

// put data in EEPROM.
// return: 0 is mean data too big and 1 is fit.
uint8_t DataObject::putData(int data) {
  if (sizeof(data) > _size) return 0;
  EEPROM.put(_first_index, data);
  return 1;
}

// put data in EEPROM.
// return: 0 is mean data too big and 1 is fit.
uint8_t DataObject::putData(long data) {
  if (sizeof(data) > _size) return 0;
  EEPROM.put(_first_index, data);
  return 1;
}

// put data in EEPROM.
// return: 0 is mean data too big and 1 is fit.
uint8_t DataObject::putData(float data) {
  if (sizeof(data) > _size) return 0;
  EEPROM.put(_first_index, data);
  return 1;
}

// put data in EEPROM.
// return: 0 is mean data too big and 1 is mean fit.
uint8_t DataObject::putData(double data) {
  if (sizeof(data) > _size) return 0;
  EEPROM.put(_first_index, data);
  return 1;
}

// put data in EEPROM.
// note: if data bigger than the specified size then the data would be cut to fit with the specified size.
// return: 0 is mean data too big and 1 is fit.
uint8_t DataObject::putData(char data[]) {
  uint8_t ret = 1;
  if (data[_size-1] != '\0') {
    data[_size-1] = '\0';
    ret = 0;
  }
  EEPROM.put(_first_index, data);
  return ret;
}

// get data from EEPROM
void DataObject::getData(uint8_t &ret) {
  EEPROM.get(_first_index, ret);
}

// get data from EEPROM
void DataObject::getData(uint16_t &ret) {
  EEPROM.get(_first_index, ret);
}

// get data from EEPROM
void DataObject::getData(uint32_t &ret) {
  EEPROM.get(_first_index, ret);
}

// get data from EEPROM
void DataObject::getData(uint64_t &ret) {
  EEPROM.get(_first_index, ret);
}

// get data from EEPROM
void DataObject::getData(float &ret) {
  EEPROM.get(_first_index, ret);
}

// get data from EEPROM
void DataObject::getData(double &ret) {
  EEPROM.get(_first_index, ret);
}

// get data from EEPROM
void DataObject::getData(int &ret) {
  EEPROM.get(_first_index, ret);
}

// get data from EEPROM
void DataObject::getData(long &ret) {
  EEPROM.get(_first_index, ret);
}

// get data from EEPROM
// return data
char * DataObject::getData() {
  char * val;
  EEPROM.get(_first_index, val);
  return val;
}

// free its memory.
void DataObject::free() {
  for (uint16_t i = 0; i < _size; i++) {
    EEPROM.write(i+_first_index, 0);
  }
}

DataObject::~DataObject()
{
}