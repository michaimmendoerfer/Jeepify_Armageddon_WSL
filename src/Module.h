#ifndef MODULE_H
#define MODULE_H

#include "Jeepify.h"

#define MODULE_JL_BATTERY_SENSOR      // (tut)
//#define MODULE_SENSORDRAGON_V1_0
//#define MODULE_SENSIBLEDRAGON_V1_2
//#define MODULE_POWERDRAGON4_V1_0
//#define MODULE_1WAY_C6
//#define MODULE_4_TAILED_FIRINGDRAGON_V1_0
//#define MODULE_4WAY_ESP32_MONSTER
//#define MODULE_4WAY_ESP32_BIGGY
//#define MODULE_TERMINATOR_PRO         // ESP32-3248S035C, 480x320 Display
//#define MODULE_4WAY_INTEGRATED_8266   // (tut)
//#define MODULE_4WAY_INTEGRATED_C3     // (tut)
//#define MODULE_4WAY_INTEGRATED_ESP01  // 

void InitModule();

#define MODULE_VERSION          "4.11"  
#define PROTOKOLL_VERSION       "3.10"

#ifdef MODULE_JL_BATTERY_SENSOR // locked
    // JL-Battery-Sensor hinten (tut)
    // ESP32-C3 Mini Plus (RGB)
    // 3 AMP-Sensors (ACS712)
    // 1 AMP-Sensor  (ACS756)
    // 1 VOLT-Sensor (VoltageDevider 5)
    // Pin 3:   Voltage mit 5/1 Devider
    // Pin 5/6: ADS1115 (0x48)
    // Pin 8:   LED (RGB)
    // Pin 9:   Pairing Button

    #define ADC_USED            0x48
    #define PAIRING_BUTTON      9
//    #define RGBLED_PIN          8
    #define LED_PIN             10
    #define LED_OFF             0
    #define LED_ON              1
    #define SDA_PIN             5
    #define SCL_PIN             6
    #define VOLTAGE_PIN         1 //3
    #define VOLTAGE_DEVIDER_V   5.0
    #define VOLTAGE_DEVIDER_A   1.0
    #define MODULE_NAME         "JL_BAT"
    #define BOARD_VOLTAGE       3.3
    #define BOARD_ANALOG_MAX    4095
#endif
#ifdef MODULE_POWERDRAGON4_V1_0 // locked
    // blue PCB PowerDragon V1.0 
    // ESP32- 39 pin 
    // 4 latching switches (50A)
    // 1 VOLT-Sensor 
    // Pin 0:     Pairing Button
    // Pin 33:    Voltage
    
    #define PAIRING_BUTTON       0
    #define LED_PIN             10
    #define LED_OFF             0
    #define LED_ON              1
    #define VOLTAGE_PIN         33
    #define VOLTAGE_DEVIDER_V   4.829787 //18k-4,7k
    #define VOLTAGE_DEVIDER_A   5
    #define MODULE_NAME         "PD_1.0"
    #define BOARD_VOLTAGE       3.3
    #define BOARD_ANALOG_MAX    4095
#endif

#ifdef MODULE_1WAY_C6 // locked
    // Single-Relay
    // ESP32-C6 Mini 
    // 1 switches (10A)
    // Pin 0:     Pairing Button
    // Pin 19:    Relay
    
    #define PAIRING_BUTTON      9
    #define LED_PIN             2
    #define LED_OFF             0
    #define LED_ON              1
    #define MODULE_NAME         "C6_1"
    #define VOLTAGE_DEVIDER_V   4.829787 //18k-4,7k
    #define VOLTAGE_DEVIDER_A   5
    #define BOARD_VOLTAGE       3.3
    #define BOARD_ANALOG_MAX    4095
#endif


#ifdef MODULE_4_TAILED_FIRINGDRAGON_V1_0 // auch V2_0
    // blue PCB 
    // ESP32-C3 Mini 
    // 4 latching switches (50A)
    // 1 VOLT-Sensor 
    // Pin 00:    Pairing Button
    // Pin 01:    Voltage
    
    #define PAIRING_BUTTON       0
    #define LED_PIN             10
    #define LED_OFF             0
    #define LED_ON              1
    #define RGBLED_PIN          8
    #define SDA_PIN             20
    #define SCL_PIN             21
    #define PORT0               0x20
    #define ADC0                0x48
    #define ADC1                0x49
    #define VOLTAGE_PIN         1
    #define VOLTAGE_DEVIDER_V   4.82978 //18k-4,7k
    #define VOLTAGE_DEVIDER_A   4.46938
    #define MODULE_NAME         "4TF_2.0"
    #define BOARD_VOLTAGE       3.3
    #define BOARD_ANALOG_MAX    4095
    #define IS_REPEATER         1
#endif

#ifdef MODULE_SENSIBLEDRAGON_V1_2 // locked
    // blue PCB SensibleDragon V1.2 
    // ESP32-C3 Mini 
    // 4 AMP-Sensors (ACS712) 30A
    // 1 VOLT-Sensor (VoltageDevider 4.58333)
    // Pin 10:    LED extern
    // Pin 0:     Pairing Button
    // Pin 1:     Voltage
    // Pin 20/21: SDA/SCL I2C
    // I2C 0x48:  ADS1115 
    
    #define ADC0                0x48
    #define PAIRING_BUTTON      0
    #define LED_PIN             10
    //#define RGBLED_PIN          8
    #define LED_OFF             0
    #define LED_ON              1
    #define SDA_PIN             20
    #define SCL_PIN             21
    #define VOLTAGE_PIN         1
    #define VOLTAGE_DEVIDER_V   4.829787 //18k-4,7k
    #define VOLTAGE_DEVIDER_A   1.0
    #define MODULE_NAME         "JLSDT1"
    #define BOARD_VOLTAGE       3.3
    #define BOARD_ANALOG_MAX    4095
    #define IS_REPEATER         1
#endif

#ifdef MODULE_SENSORDRAGON_V1_0
    // blue PCB SensorDragon V1.0 
    // ESP32-C3 Mini 
    // 4 AMP-Sensors (ACS712) 30A
    // 1 VOLT-Sensor (VoltageDevider 5.3)
    // Pin 10:    LED extern
    // Pin 6:     Pairing Button
    // Pin 2:     Voltage mit 5/1 Devider
    // Pin 21/20: SDA/SCL I2C
    // I2C 0x48:  ADS1115 

    #define ADC0                0x48
    #define PAIRING_BUTTON      6
    #define LED_PIN             5
    #define LED_OFF             LOW
    #define LED_ON              HIGH
    #define SDA_PIN             21
    #define SCL_PIN             20
    #define VOLTAGE_PIN         2
    #define VOLTAGE_DEVIDER_V   5.3
    #define VOLTAGE_DEVIDER_A   1.0
    #define MODULE_NAME         "JL_PCB"
    #define BOARD_VOLTAGE       3.3
    #define BOARD_ANALOG_MAX    4095
#endif

#ifdef MODULE_4WAY_ESP32_MONSTER
// 4-Kanal mit ESP32 mit Latching 30A, AMP/V-Sensor
// 4 Switches

   #define PAIRING_BUTTON      0
//  #define SDA_PIN             6
//  #define SCL_PIN             7
//  #define ADC_USED            0x48
    #define LED_PIN             2
    #define LED_OFF             0
    #define LED_ON              1
    #define VOLTAGE_PIN         32
    #define VOLTAGE_DEVIDER_V   4.5454
    #define VOLTAGE_DEVIDER_A   1.0
    #define MODULE_NAME         "Mons_2"
    #define BOARD_VOLTAGE       3.3
    #define BOARD_ANALOG_MAX    4095
#endif

// x-Kanal mit ESP32 mit Latching 30A, AMP/V-Sensor
// x Switches
// ESP32-C3 Mini
// Pin 0:   Pairing Button
// Pin 8:   LED

#ifdef MODULE_4WAY_ESP32_BIGGY
   #define PAIRING_BUTTON       0
    #define ADC0                0x48
    #define PORT0               0x20
    #define SDA_PIN             5
    #define SCL_PIN             6
    #define LED_PIN             2
    #define LED_OFF             0
    #define LED_ON              1
    #define VOLTAGE_PIN         32
    #define VOLTAGE_DEVIDER     4.5454
    #define MODULE_NAME         "Biggy1"
    #define BOARD_VOLTAGE       3.3
    #define BOARD_ANALOG_MAX    4095
#endif

#ifdef MODULE_4WAY_INTEGRATED_8266
// fertiges 4-Kanal mit ESP8266 (tut)
// 4 Switches

    #define PROZ_ESP8266
    #define PAIRING_BUTTON      4 
    #define LED_PIN             LED_BUILTIN
    #define LED_OFF             LOW
    #define LED_ON              HIGH
    #define MODULE_NAME         "8266_4S"
    #define BOARD_VOLTAGE       3.3
    #define BOARD_ANALOG_MAX    1023
#endif

#ifdef MODULE_4WAY_INTEGRATED_C3
// fertiges 4-Kanal (30A) mit ESP-C3-Upgrade
// ESP32-C3 Mini
// Pin 4:   Pairing Button
// Pin 5:   Switch(0) - 30A
// Pin 6:   Switch(1) - 30A
// Pin 7:   Switch(2) - 30A
// Pin 8:   LED
// Pin 10:  Switch(3) - 30A

    #define PROZ_ESP32_C3       1
    #define PAIRING_BUTTON      4 
    #define LED_PIN             8
    #define LED_OFF             LOW
    #define LED_ON              HIGH
    #define MODULE_NAME         "C3_4S"
    #define VOLTAGE_DEVIDER     1.0
    #define BOARD_VOLTAGE       3.3
    #define BOARD_ANALOG_MAX    4095
#endif

#ifdef MODULE_TERMINATOR_PRO
// Jeepify-Terminator-Pro (ESP32-3248S035C)
// 4 Switches
// 4 AMP-Sensors (ACS712)
// 1 VOLT-Sensor
// 480x320 Display

    #define PROZ_ESP32
    #define MODULA_HAS_DISPLAY  1
    #define PORT0               0x20
    #define ADC0                0x48
    #define PAIRING_BUTTON      9
    #define LED_PIN             8
    #define LED_OFF             HIGH
    #define LED_ON              LOW
    #define SDA_PIN             6
    #define SCL_PIN             7
    #define MODULE_NAME         "Term_1"
    #define VOLTAGE_DEVIDER     5
    #define BOARD_VOLTAGE       3.3
    #define BOARD_ANALOG_MAX    4095
#endif

extern const char *ArrNullwert[MAX_PERIPHERALS];
extern const char *ArrRawVolt [MAX_PERIPHERALS];
extern const char *ArrVperAmp [MAX_PERIPHERALS];
extern const char *ArrVin     [MAX_PERIPHERALS];
extern const char *ArrPeriph  [MAX_PERIPHERALS];

#ifdef PORT0
    #include "PCF8575.h"
    extern PCF8575 *IOBoard[4];
#endif
#endif
