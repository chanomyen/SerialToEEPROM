/****************************************************************
 *                    Arduino Storage Library
 * @version: 0.1 Beta
 * @author: Chanon Sermpol
 * @modified: 26 February 2020
 * ****************************************************************
*/


#include <Arduino.h>
#include <EEPROM.h>

#define EEPROM_SIZE     EEPROM.length()

uint8_t isEmptryDeviceID(void);   //For the first run of MCU, it's needed to set a default value.
void    cleanMemory(void);        //clear EEPROM

class DataObject
{
    private:
        uint16_t _size;  // byte(s)
        uint16_t _first_index;

        // Shared parameters
        static uint16_t _allocated;
    public:
        DataObject(uint16_t size);
        ~DataObject();

        uint16_t getFirstIndex();
        void free();

        uint8_t putData(char *data);
        uint8_t putData(uint8_t data);
        uint8_t putData(uint16_t data);
        uint8_t putData(uint32_t data);
        uint8_t putData(uint64_t data);
        uint8_t putData(int data);
        uint8_t putData(long data);
        uint8_t putData(float data);
        uint8_t putData(double data);

        char *getData();
        void getData(uint8_t &ret);
        void getData(uint16_t &ret);
        void getData(uint32_t &ret);
        void getData(uint64_t &ret);
        void getData(int &ret);
        void getData(long &ret);
        void getData(float &ret);
        void getData(double &ret);

        /* Shared methods */

        static uint16_t getFreeSpace();
        static uint16_t getAllocated();
        static uint16_t memoryReport();
};