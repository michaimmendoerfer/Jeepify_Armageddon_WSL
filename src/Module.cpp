#include "Module.h"
#include "PeerClass.h"

extern PeerClass Module;
extern MyLinkedList<PeriphClass*> SwitchList;
extern MyLinkedList<PeriphClass*> SensorList;
extern MyLinkedList<PeriphClass*> PeriphList;

const char *ArrNullwert[MAX_PERIPHERALS] = {"N0",  "N1",  "N2",  "N3",  "N4",  "N5",  "N6",  "N7",  "N8"};
const char *ArrRaw[MAX_PERIPHERALS]      = {"R0", "R1", "R2", "R3", "R4", "R5", "R6", "R7", "R8"};
const char *ArrRawVolt[MAX_PERIPHERALS]  = {"RaV0", "RaV1", "RaV2", "RaV3", "RaV4", "RaV5", "RaV6", "RaV7", "RaV8"};
const char *ArrVperAmp[MAX_PERIPHERALS]  = {"VpA0", "VpA1", "VpA2", "VpA3", "VpA4", "VpA5", "VpA6", "VpA7", "VpA8"};
const char *ArrVin[MAX_PERIPHERALS]      = {"Vin0", "Vin1", "Vin2", "Vin3", "Vin4", "Vin5", "Vin6", "Vin7", "Vin8"};
const char *ArrPeriph[MAX_PERIPHERALS]   = {"P0", "P1", "P2", "P3", "P4", "P5", "P6", "P7", "P8"};

void InitModule()
{   
    //------------------------------------------------------------------------------------------------------------------------------
    //----------------------------------------------- MODULE_JL_BATTERY_SENSOR -----------------------------------------------------
    //----------------------------------------------- fertig - nicht mehr ändern ---------------------------------------------------
    //------------------------------------------------------------------------------------------------------------------------------
    
    #ifdef MODULE_JL_BATTERY_SENSOR           
        #define SWITCHES_PER_SCREEN 4
        #define VIN BOARD_ANALOG_MAX/BOARD_VOLTAGE
        //                Name        Type         Version        Address   sleep  debug  demo  pair  vMon RelayType       SCA      SCL      voltagedevier 
        //Module.Setup(MODULE_NAME, BATTERY_SENSOR, MODULE_VERSION, NULL,     false, true, false, false, 4,  RELAY_NORMAL, SDA_PIN,  SCL_PIN, VOLTAGE_DEVIDER);
        Module.Setup(MODULE_NAME, BATTERY_SENSOR, MODULE_VERSION, NULL,     false, true, false, false);
        //                      Name     Type                   I2C                    IO(0/1)    VOLT  AMP   NULL     VpA    Vin  PeerID  
        Module.PeriphSetup(0, "Load",   SENS_TYPE_AMP,    -1, -1, -1, 0,  -1, -1,     -1,      3,   2.5410,  0.040,  0,    0);
        Module.PeriphSetup(1, "Extern", SENS_TYPE_AMP,    -1, -1, -1, 0,  -1, -1,     -1,      2,   2.4954,  0.066,  0,    0);
        Module.PeriphSetup(2, "Solar",  SENS_TYPE_AMP,    -1, -1, -1, 0,  -1, -1,     -1,      1,   2.5005,  0.066,  0,    0);
        Module.PeriphSetup(3, "Intern", SENS_TYPE_AMP,    -1, -1, -1, 0,  -1, -1,     -1,      0,   2.5005,  0.066,  0,    0);
        Module.PeriphSetup(4, "VMon",   SENS_TYPE_VOLT,   -1, -1, -1, -1, -1, -1, VOLTAGE_PIN, -1,     0,    0,    VIN, 0);  
    #endif
    
    //------------------------------------------------------------------------------------------------------------------------------
    //----------------------------------------------- MODULE_POWERDRAGON4_V1_0 -----------------------------------------------------
    //----------------------------------------------- fertig - nicht mehr ändern ---------------------------------------------------
    //------------------------------------------------------------------------------------------------------------------------------
    
    #ifdef MODULE_POWERDRAGON4_V1_0           
        #define VIN BOARD_ANALOG_MAX/BOARD_VOLTAGE
        //                Name        Type         Version        Address   sleep  debug  demo   pair
        Module.Setup(MODULE_NAME, SWITCH_4_WAY, MODULE_VERSION,     NULL,   false, true,  false, false);
        //                      Name     Type                   I2C         IO(0/1)  VOLT        AMP   NULL     VpA    Vin  PeerID  
        Module.PeriphSetup(0, "Rel0",  SENS_TYPE_LT_AMP,     -1, -1, -1, -1, 14, 13, 32, 39,  1.666,  0.040,  0,    0);
        Module.PeriphSetup(1, "Rel1",  SENS_TYPE_LT_AMP,     -1, -1, -1, -1, 26, 27, 25, 36,  1.666,  0.040,  0,    0);
        Module.PeriphSetup(2, "Rel2",  SENS_TYPE_LT_AMP,     -1, -1, -1, -1, 22, 23, 21, 34,  1.666,  0.040,  0,    0);
        Module.PeriphSetup(3, "Rel3",  SENS_TYPE_LT_AMP,     -1, -1, -1, -1, 18, 19, 17, 35,  1.666,  0.040,  0,    0);
        Module.PeriphSetup(4, "VMon",  SENS_TYPE_VOLT,       -1, -1, -1, -1, -1, -1, VOLTAGE_PIN, -1,     0,    0,      VIN,  0);  
    #endif

    //------------------------------------------------------------------------------------------------------------------------------
    //----------------------------------------- MODULE_4_TAILED_FIRINGDRAGON_V1_0 --------------------------------------------------
    //----------------------------------------------- fertig - nicht mehr ändern ---------------------------------------------------
    //------------------------------------------------------------------------------------------------------------------------------
    
    #ifdef MODULE_4_TAILED_FIRINGDRAGON_V1_0           
        #define VIN BOARD_ANALOG_MAX/BOARD_VOLTAGE
        //                Name        Type         Version        Address   sleep  debug  demo   pair
        Module.Setup(MODULE_NAME, SWITCH_4_WAY, MODULE_VERSION,     NULL,   false, true,  false, false);
        //                      Name     Type                 I2C:PCF  I2C-ADC    IO(0/1)  VOLT AMP   NULL    VpA   Vin  PeerID  
        Module.PeriphSetup(0, "Rel0",  SENS_TYPE_LT_AMP,      0,  0,   0,  0,     1, 0,    1,   0,   1.666,  0.040,  0,    0);
        Module.PeriphSetup(1, "Rel1",  SENS_TYPE_LT_AMP,      0,  0,   1,  1,     3, 2,    2,   3,   1.666,  0.040,  0,    0);
        Module.PeriphSetup(2, "Rel2",  SENS_TYPE_LT_AMP,      0,  0,   0,  0,     5, 4,    2,   3,   1.666,  0.040,  0,    0);
        Module.PeriphSetup(3, "Rel3",  SENS_TYPE_LT_AMP,      0,  0,   1,  1,     7, 6,    1,   0,   1.666,  0.040,  0,    0);

        Module.PeriphSetup(4, "VMon",  SENS_TYPE_VOLT,       -1, -1,  -1, -1,    -1, -1, VOLTAGE_PIN, -1,      0,    0,      VIN,  0);  
    #endif

    //------------------------------------------------------------------------------------------------------------------------------
    //----------------------------------------------- MODULE_1WAY_C6 ---------------------------------------------------------------
    //----------------------------------------------- fertig - nicht mehr ändern ---------------------------------------------------
    //------------------------------------------------------------------------------------------------------------------------------
    
    #ifdef MODULE_1WAY_C6           
        #define VIN BOARD_ANALOG_MAX/BOARD_VOLTAGE
        //                Name        Type         Version        Address   sleep  debug  demo   pair
        Module.Setup(MODULE_NAME, SWITCH_1_WAY, MODULE_VERSION,     NULL,   false, true,  false, false);
        //                      Name     Type                   I2C         IO(0/1)  VOLT        AMP   NULL     VpA    Vin  PeerID  
        Module.PeriphSetup(0, "sc6",   SENS_TYPE_SWITCH,      -1, -1, -1, -1, 19, -1, -1, -1,     0,  0,  0,  0);
        Module.SetRelayType(RELAY_NORMAL);
    #endif
    

    #ifdef MODULE_SENSORDRAGON_V1_0           
        #define VIN BOARD_ANALOG_MAX/BOARD_VOLTAGE
        //                Name        Type         Version        Address   sleep  debug  demo  pair  vMon RelayType       SCA      SCL      voltagedevier 
        //Module.Setup(MODULE_NAME, BATTERY_SENSOR, MODULE_VERSION, NULL,     false, true, false, false, 4,  RELAY_NORMAL, SDA_PIN,  SCL_PIN, VOLTAGE_DEVIDER);
        Module.Setup(MODULE_NAME, BATTERY_SENSOR, MODULE_VERSION, NULL,     false, true, false, false);
        //                      Name     Type                    I2C       IO(0/1)    VOLT      AMP   NULL     VpA    Vin  PeerID  
        Module.PeriphSetup(0, "PCB_S0",  SENS_TYPE_AMP,    -1, -1, -1,  0, -1, -1,     -1,      0,   1.635,  0.066,  0,    0);
        Module.PeriphSetup(1, "PCB_S1",  SENS_TYPE_AMP,    -1, -1, -1,  0, -1, -1,     -1,      1,   1.635,  0.066,  0,    0);
        Module.PeriphSetup(2, "PCB_S2",  SENS_TYPE_AMP,    -1, -1, -1,  0, -1, -1,     -1,      2,   1.635,  0.066,  0,    0);
        Module.PeriphSetup(3, "PCB_S3",  SENS_TYPE_AMP,    -1, -1, -1,  0, -1, -1,     -1,      3,   1.635,  0.066,  0,    0);
        Module.PeriphSetup(4, "VMon",    SENS_TYPE_VOLT,   -1, -1, -1, -1, -1, -1, VOLTAGE_PIN, -1,     0,    0,    VIN,   0);  
    #endif

    #ifdef MODULE_SENSIBLEDRAGON_V1_2           
        #define VIN BOARD_ANALOG_MAX/BOARD_VOLTAGE
        //                Name        Type         Version        Address   sleep  debug  demo  pair  vMon RelayType       SCA      SCL      voltagedevier 
        //Module.Setup(MODULE_NAME, BATTERY_SENSOR, MODULE_VERSION, NULL,     false, true, false, false, 4,  RELAY_NORMAL, SDA_PIN,  SCL_PIN, VOLTAGE_DEVIDER);
        Module.Setup(MODULE_NAME, BATTERY_SENSOR, MODULE_VERSION, NULL,     false, true, false, false);
        //                      Name     Type              I2C              IO(0/1)   VOLT      AMP   NULL     VpA    Vin  PeerID  
        Module.PeriphSetup(0, "Load",    SENS_TYPE_AMP,   -1, -1, -1,  0, -1, -1,       -1,     3,   2.493,  0.066,  0,    0);
        Module.PeriphSetup(1, "Extern",  SENS_TYPE_AMP,   -1, -1, -1,  0, -1, -1,       -1,     2,   2.478,  0.066,  0,    0);
        Module.PeriphSetup(2, "Solar",   SENS_TYPE_AMP,   -1, -1, -1,  0, -1, -1,       -1,     0,   2.493,  0.066,  0,    0);
        Module.PeriphSetup(3, "Intern",  SENS_TYPE_AMP,   -1, -1, -1,  0, -1, -1,       -1,     1,   2.505,  0.066,  0,    0);
        Module.PeriphSetup(4, "VMon",    SENS_TYPE_VOLT,  -1, -1, -1, -1, -1, -1, VOLTAGE_PIN, -1,     0,    0,     VIN,   0);  
    #endif
 
    #ifdef MODULE_4WAY_ESP32_MONSTER   
        #define SWITCHES_PER_SCREEN 4
        //                Name        Type         Version        Address   sleep  debug  demo  pair  vMon RelayType       SCA      SCL      voltagedevier 
        Module.Setup(MODULE_NAME, SWITCH_2_WAY, MODULE_VERSION, NULL,     false, true,  false, false);
        //                      Name     Type             I2C               IO(0/1)        VOLT  AMP   NULL     VpA      Vin  PeerID  
        Module.PeriphSetup(0, "Sw 0",   SENS_TYPE_LT_AMP,  -1, -1, -1, -1,  27, 26,          33, 34,   0,       0.040,  1241,   0);
        Module.PeriphSetup(1, "Sw 1",   SENS_TYPE_LT_AMP,  -1, -1, -1, -1,  16, 17,          35, 39,   0,       0.040,  1241,   0); //39=vn
        Module.PeriphSetup(2, "VMon",   SENS_TYPE_VOLT,    -1, -1, -1, -1,  -1, -1, VOLTAGE_PIN, -1,   0,       0,      1241,   0);
    #endif

    #ifdef ESP8266_MODULE_4S_INTEGRATED       
        #define SWITCHES_PER_SCREEN 4
        //                Name        Type         Version        Address   sleep  debug  demo  pair  vMon   RelayType      sda    scl  voltagedevier 
        Module.Setup(MODULE_NAME, BATTERY_SENSOR, MODULE_VERSION, NULL,     false, true,  true, false, -1,  RELAY_NORMAL,   -1,   -1,     -1);
        //                      Name     Type             ADS  IO    NULL     VpA      Vin  PeerID
        Module.PeriphSetup(0, "Sw 1",   SENS_TYPE_SWITCH,   0,  15,    0,      0,       0,    0);
        Module.PeriphSetup(1, "Sw 2",   SENS_TYPE_SWITCH,   0,  14,    0,      0,       0,    0);
        Module.PeriphSetup(2, "Sw 3",   SENS_TYPE_SWITCH,   0,  12,    0,      0,       0,    0);
        Module.PeriphSetup(3, "Sw 4",   SENS_TYPE_SWITCH,   0,  13,    0,      0,       0,    0);
    #endif

    #ifdef MODULE_4WAY_INTEGRATED_C3      
        #define SWITCHES_PER_SCREEN 4
        //                      Name     Type             I2C               IO(0/1)        VOLT  AMP   NULL     VpA      Vin  PeerID  
        Module.Setup(MODULE_NAME, SWITCH_4_WAY, MODULE_VERSION,   NULL,     false, true, false, false);
        //                      Name     Type             I2C               IO(0/1)        VOLT  AMP   NULL     VpA      Vin  PeerID  
        Module.PeriphSetup(0, "Sw 1",   SENS_TYPE_SWITCH,   -1, -1, -1, -1,  5, -1,          -1, -1,    0,       0,       0,     0);
        Module.PeriphSetup(1, "Sw 2",   SENS_TYPE_SWITCH,   -1, -1, -1, -1,  6, -1,          -1, -1,    0,       0,       0,     0);
        Module.PeriphSetup(2, "Sw 3",   SENS_TYPE_SWITCH,   -1, -1, -1, -1,  7, -1,          -1, -1,    0,       0,       0,     0);
        Module.PeriphSetup(3, "Sw 4",   SENS_TYPE_SWITCH,   -1, -1, -1, -1, 10, -1,          -1, -1,    0,       0,       0,     0);
        Module.SetRelayType(RELAY_NORMAL);
    #endif

    // Register Periphs
    for (int SNr=0; SNr<MAX_PERIPHERALS; SNr++)
    {
        if (Module.isPeriphSensor(SNr)) 
        {
            SensorList.add(Module.GetPeriphPtr(SNr));
            PeriphList.add(Module.GetPeriphPtr(SNr));
        }
        else if (Module.isPeriphSwitch(SNr)) 
        {
            SwitchList.add(Module.GetPeriphPtr(SNr));
            PeriphList.add(Module.GetPeriphPtr(SNr));
        }
    }

    // Set pinModes
    for (int SNr=0; SNr<MAX_PERIPHERALS; SNr++) 
    { 
        if (Module.GetPeriphIOPort(SNr, 0) >= 0) 
        {
            #ifdef PORT0
                if (PORT_Module >= 0) IOBoard[PORT_Module]->pinMode(Module.GetPeriphIOPort(SNr, 0), OUTPUT);
            #else
                pinMode(Module.GetPeriphIOPort(SNr, 0), OUTPUT);  // off(lt) oder on/off 
            #endif
        }

        if (Module.GetPeriphIOPort(SNr, 1) >= 0) 
        {
            #ifdef PORT0
                if (PORT_Module >= 0) IOBoard[PORT_Module]->pinMode(Module.GetPeriphIOPort(SNr, 1), OUTPUT);
            #else
                pinMode(Module.GetPeriphIOPort(SNr, 1), OUTPUT);  // on(lt)
            #endif
        }

        if (Module.GetPeriphIOPort(SNr, 2) >= 0)   
        {
            if (Module.GetPeriphI2CPort(SNr,2) == -1)
            {
                pinMode(Module.GetPeriphIOPort(SNr,2), INPUT);
                Serial.printf("setze %d auf INPUT\n\r", Module.GetPeriphIOPort(SNr,2));
            }
        }

        if (Module.GetPeriphIOPort(SNr, 3) >= 0)     
        {
            if (Module.GetPeriphI2CPort(SNr,3) == -1)
            {
                pinMode(Module.GetPeriphIOPort(SNr,3), INPUT);
            }
        }
    }
    
    #ifdef PAIRING_BUTTON
        pinMode(PAIRING_BUTTON, INPUT_PULLUP); 
    #endif
    
    #ifdef LED_PIN
        pinMode(LED_PIN, OUTPUT);
    #endif

    #ifdef LED_ONBOARD
        pinMode(LED_ONBOARD, OUTPUT);
    #endif
    
    #ifdef RGBLED_PIN
        //pinMode(RGBLED_PIN, OUTPUT);
    #endif

    
}
