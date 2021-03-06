//ESP32_LCD_Receiver_Board_Definitions.h

/*
*******************************************************************************************************************************
  Easy Build Tracker Programs for Arduino

  Copyright of the author Stuart Robinson - 18/08/18

  

  These programs may be used free of charge for personal, recreational and educational purposes only.

  This program, or parts of it, may not be used for or in connection with any commercial purpose without the explicit permission
  of the author Stuart Robinson.

  The programs are supplied as is, it is up to individual to decide if the programs are suitable for the intended purpose and
  free from errors.

  This is the hardware definitions for the ESP32_Mikrobus_Shield

  To Do:

*******************************************************************************************************************************
*/

#define UsingESP32                   //some drivers need to be different for the ESP32

#define MB1_RX 3
#define MB1_TX 1
#define MB1_INT1 35
#define MB1_PWM  15
#define MB1_INT2 34
#define MB1_RESET 27
#define MB1_CS  5
#define SWITCH1 0

#define MB2_INT1 33
#define MB2_TX  17
#define MB2_RX  16
#define MB2_PWM  32
#define MB2_CS  24
#define MB2_AN 26
#define MB2_POWER 12

#define SD_CS 13
#define Audio_Out 15                 //pin number for Audio tone generation (AFSK) on MB1_PWM
#define LED1 2                       //pin number for LED
#define BUZZ 2                       //some test programs use this pin for a buzzer, shared with LED1
#define SupplyAD  36                 //measure supply voltage here
#define BAT 36
#define GPSPOWER 12
#define ADMultiplier 10              //multiplier for supply volts calculation


#ifdef GPS_in_MB2
#define GPSTX MB2_TX
#define GPSRX MB2_RX
#endif

#ifdef GPS_in_MB1
#define GPSTX MB1_TX
#define GPSRX MB1_RX
#endif


#ifdef LoRa_Device_in_MB1            //if the LoRa device is in MB1
#define lora_TonePin MB1_PWM
#define lora_NReset MB1_RESET
#define lora_NSS MB1_CS
#define lora_DIO0 MB1_INT1
#define lora_DIO1 MB1_INT2
#define lora_DIO2 MB1_PWM
#endif


#ifdef LoRa_Device_in_MB2            //if the LoRa device is in MB1
#define lora_TonePin MB2_PWM
#define lora_NReset -1               //pin not used
#define lora_NSS MB2_CS
#define lora_DIO0 MB1_INT1
#endif


#define SWITCH2 39
#define SWITCHU 39


#define SCK 18
#define MISO 19
#define MOSI 23
#define SS -1
#define DIO0 35
#define DIO1 34
#define DIO2 15
#define SCL 22
#define SDA 21