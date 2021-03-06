////Receiver2_Board_Definitions.h
/*
*******************************************************************************************************************************
  Easy Build Tracker Programs for Arduino

  Copyright of the author Stuart Robinson - 2/10/17

  

  These programs may be used free of charge for personal, recreational and educational purposes only.

  This program, or parts of it, may not be used for or in connection with any commercial purpose without the explicit permission
  of the author Stuart Robinson.

  The programs are supplied as is, it is up to individual to decide if the programs are suitable for the intended purpose and
  free from errors.

  This is the hardware definitions for the Receiver2 board, based on the ATMEGA 1284P

  To Do:

*******************************************************************************************************************************
*/


#define RXD 0
#define TXD 1
#define MB2_RX  2
#define MB2_TX  3
#define MB1_CS  4
#define DISP_DC  5
#define SWITCH1 6
#define DISP_RESET 7

#define MB2_PWM  8
#define MB2_CS  9
#define SD_CS  10
#define MOSI  11
#define MIS0  12
#define SCK  13

#define SCL  22
#define SDA  23
#define MB1_RX  24
#define MB1_TX  25
#define Bluetooth_RX  26
#define Bluetooth_TX  27
#define MB2_INT 28
#define MB1_INT2 29
#define MB1_PWM  30           //same as LED2
#define Audio_Out 30
#define LED2  30              //hardware pin 18 
#define LED1 31               //hardware pin 21
#define WDI 31


#define SupplyAD  A0
#define MB1_AN A1
#define MB2_AN A2
#define BUZZ A3
#define MB1_RESET A4
#define DISP_CS A5
#define SWITCH2 A6
#define SWITCH_U A6
#define MB1_INT  A7
#define ADMultiplier 10

#define GPSPOWER -1           //not used
#define LED3 13               //LED on SCK Pin
#define SWITCH_L -1           //not used  
#define SWITCH_R -1           //not used 
#define SWITCH_D -1           //not used 
#define MEMORY_CS -1          //not used

#ifdef GPS_in_MB1
#define GPSTX 25
#define GPSRX 24
#endif

#ifdef GPS_in_MB2
#define GPSserial Serial1
#define GPSTX 3
#define GPSRX 2
#endif

#ifdef LoRa_Device_in_MB1       //if the LoRa device is in MB1
#define lora_TonePin MB1_PWM
#define lora_NReset MB1_RESET
#define lora_NSS MB1_CS
#define lora_DIO0 MB1_INT
#endif

#ifdef LoRa_Device_in_MB2       //if the LoRa device is in MB2 
#define lora_TonePin MB2_PWM
#define lora_NReset -1
#define lora_NSS MB2_CS
#define lora_DIO0 MB2_INT
#endif

