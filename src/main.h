#ifndef MAIN_H
#define MAIN_H

// DEBUG_LEVEL: 0 = nothing, 1 = only Errors, 2 = relevant changes, 3 = all
#define DEBUG1(...) if ((Module.GetDebugMode()) and (DEBUG_LEVEL > 0)) Serial.printf(__VA_ARGS__)
#define DEBUG2(...) if ((Module.GetDebugMode()) and (DEBUG_LEVEL > 1)) Serial.printf(__VA_ARGS__)
#define DEBUG3(...) if ((Module.GetDebugMode()) and (DEBUG_LEVEL > 2)) Serial.printf(__VA_ARGS__)

#define DEBUG_COM(...) if (DEBUG_LVL_COM) Serial.printf(__VA_ARGS__)
#define DEBUG_SYS(...) if (DEBUG_LVL_SYS) Serial.printf(__VA_ARGS__)
#define DEBUG_MAX(...) if (DEBUG_LVL_MAX) Serial.printf(__VA_ARGS__)
#define DEBUG_HW(...) if (DEBUG_LVL_HW) Serial.printf(__VA_ARGS__)

#define DEBUGS1(...) if ((Module.GetDebugMode()) and (DEBUG_LEVEL == 3)) Serial.printf(__VA_ARGS__)
#define JX(...) (doc[__VA_ARGS__].is<JsonVariant>())

struct struct_Status {
  String    Msg;
  uint32_t  TSMsg;
};
struct ReceivedMessagesStruct_old {
    uint8_t  From[6];
    uint32_t TS;
    uint32_t SaveTime;
};
struct ReceivedMessagesStruct {
    uint8_t  From[6];
    uint32_t TS;
    uint32_t SaveTime;

    ~ReceivedMessagesStruct() = default; 
};
struct RepeatMessagesStruct {
    char Msg[260];
    uint32_t TS;
    int TTL;
};

void   InitSCL();

float  ReadAmp (int SNr);
float  ReadVolt(int SNr);
void   SendStatus (int Pos=-1);
void   SendPairingRequest();

bool   GetRelayState(int SNr);
void   SetRelayState(int SNr, bool State);

void   UpdateDataFromSwitches();

void   SetDemoMode (bool Mode);
void   SetSleepMode(bool Mode);
void   SetDebugMode(bool Mode);
void   SetPairMode(bool Mode);

void   SaveModule();
void   AddStatus(String Msg);
void   GoToSleep();
void   SetMessageLED(int Color);
void   LEDBlink(int Color, int n, uint8_t ms);
void   MacCharToByte(uint8_t *mac, char *MAC);
void   MacByteToChar(char *MAC, uint8_t *mac);
bool   MACequals( uint8_t *MAC1, uint8_t *MAC2);

#ifdef ESP32 
    #include <esp_now.h>
    #include <WiFi.h>
    #include <nvs_flash.h>
    #define u8 unsigned char
    
    void OnDataRecv(const esp_now_recv_info *info, const uint8_t* incomingData, int len);
    void OnDataSent(const uint8_t *mac_addr, esp_now_send_status_t status); 
#elif defined(ESP8266)
    #include <ESP8266WiFi.h>
    #include <espnow.h>

    void OnDataRecv(uint8_t * mac, uint8_t *incomingData, uint8_t len);
    void OnDataSent(uint8_t *mac_addr, uint8_t sendStatus);
#endif

void   OnDataRecvCommon(const uint8_t * mac, const uint8_t *incomingData, int len);

#include <LinkedList.h>
#include "Jeepify.h"
#include "PeerClass.h"
#include "pref_manager.h"
#include <Preferences.h>
#include <ArduinoJson.h>
#endif