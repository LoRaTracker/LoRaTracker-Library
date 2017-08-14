//I2CFRAM_MB85RC16PNF.h
/*
*******************************************************************************************************************************
  Easy Build LoRaTracker Programs for Arduino

  Copyright of the author Stuart Robinson - 14/08/17

  http://www.LoRaTracker.uk

  These programs may be used free of charge for personal, recreational and educational purposes only.

  This program, or parts of it, may not be used for or in connection with any commercial purpose without the explicit permission
  of the author Stuart Robinson.

  The programs are supplied as is, it is up to individual to decide if the programs are suitable for the intended purpose and
  free from errors.

  This program provides a standard set of memory read and write routines for an I2C FRAM. Tested with Fujitsu MB85RC16PNF.

  To Do:


*******************************************************************************************************************************
*/

#include <Wire.h>

const int Memory_I2C_Addr = 0x50;                     //base address of FRAM

void Memory_Start()
{
  Wire.begin();
}


void Memory_End()
{
  //left empty for future use
}


/***************************************************************************
  Write Routines
  /***************************************************************************/

void Memory_WriteByte(unsigned int addr, byte x)
{
  byte msb_addr = (highByte(addr) & 0x07);            //mask off bottom 3 bytes of address top 3 bits of addr only are used, 2K FRAM
  byte lsb_addr = lowByte(addr);

  Wire.beginTransmission(Memory_I2C_Addr + msb_addr);
  Wire.write(lsb_addr);
  Wire.write(x);
  Wire.endTransmission();
}


void Memory_WriteFloat(unsigned int addr, float x)
{
  byte index, val;
  byte msb_addr = (highByte(addr) & 0x07);            //mask off bottom 3 bytes of address top 3 bits of addr only are used, 2K FRAM
  byte lsb_addr = lowByte(addr);

  union
  {
    byte b[4];
    float f;
  } data;

  data.f = x;

  Wire.beginTransmission(Memory_I2C_Addr + msb_addr);
  Wire.write(lsb_addr);

  for (index = 0; index < 4; index++)
  {
    val = data.b[index];
    Wire.write(val);                                   //write the data
  }

  Wire.endTransmission();
}


void Memory_WriteInt(unsigned int addr, int x)
{

  byte msb_addr = (highByte(addr) & 0x07);              //mask off bottom 3 bytes of address top 3 bits of addr only are used, 2K FRAM
  byte lsb_addr = lowByte(addr);
  byte msb_data = highByte(x);
  byte lsb_data = lowByte(x);


  Wire.beginTransmission(Memory_I2C_Addr + msb_addr);
  Wire.write(lsb_addr);
  Wire.write(lsb_data);
  Wire.write(msb_data);
  Wire.endTransmission();
}


void Memory_WriteUInt(unsigned int addr, unsigned int x)
{

  byte msb_addr = (highByte(addr) & 0x07);              //mask off bottom 3 bytes of address top 3 bits of addr only are used, 2K FRAM
  byte lsb_addr = lowByte(addr);
  byte msb_data = highByte(x);
  byte lsb_data = lowByte(x);


  Wire.beginTransmission(Memory_I2C_Addr + msb_addr);
  Wire.write(lsb_addr);
  Wire.write(lsb_data);
  Wire.write(msb_data);
  Wire.endTransmission();
}


void Memory_WriteULong(unsigned int addr, unsigned long x)
{
  byte index, val;
  byte msb_addr = (highByte(addr) & 0x07);            //mask off bottom 3 bytes of address top 3 bits of addr only are used, 2K FRAM
  byte lsb_addr = lowByte(addr);

  union
  {
    byte b[4];
    unsigned long f;
  } data;

  data.f = x;

  Wire.beginTransmission(Memory_I2C_Addr + msb_addr);
  Wire.write(lsb_addr);

  for (index = 0; index < 4; index++)
  {
    val = data.b[index];
    Wire.write(val);                                   //write the data
  }

  Wire.endTransmission();
}



/***************************************************************************
  Read Routines
  /***************************************************************************/

byte Memory_ReadByte(unsigned int addr)
{
  byte data;
  byte msb_addr = (highByte(addr) & 0x07);            //mask off bottom 3 bytes of address top 3 bits of addr only are used, 2K FRAM
  byte lsb_addr = lowByte(addr);

  byte val;
  Wire.beginTransmission(Memory_I2C_Addr + msb_addr);
  Wire.write(lsb_addr);
  Wire.endTransmission();
  Wire.requestFrom((Memory_I2C_Addr + msb_addr), 1);
  data = Wire.read();
  return data;
}


int Memory_ReadInt(unsigned int addr)
{

  byte lsb_data, msb_data;

  byte msb_addr = (highByte(addr) & 0x07);            //mask off bottom 3 bytes of address top 3 bits of addr only are used, 2K FRAM
  byte lsb_addr = lowByte(addr);


  Wire.beginTransmission(Memory_I2C_Addr + msb_addr);
  Wire.write(addr);
  Wire.endTransmission();
  Wire.requestFrom(Memory_I2C_Addr + msb_addr, 2);
  lsb_data = Wire.read();
  msb_data = Wire.read();

  return (lsb_data + (msb_data * 256));
}


unsigned int Memory_ReadUInt(unsigned int addr)
{

  byte lsb_data, msb_data;

  byte msb_addr = (highByte(addr) & 0x07);            //mask off bottom 3 bytes of address top 3 bits of addr only are used, 2K FRAM
  byte lsb_addr = lowByte(addr);


  Wire.beginTransmission(Memory_I2C_Addr + msb_addr);
  Wire.write(addr);
  Wire.endTransmission();
  Wire.requestFrom(Memory_I2C_Addr + msb_addr, 2);
  lsb_data = Wire.read();
  msb_data = Wire.read();

  return (lsb_data + (msb_data * 256));
}




float Memory_ReadFloat(unsigned int addr)
{
  byte index, val;

  byte msb_addr = (highByte(addr) & 0x07);            //mask off bottom 3 bytes of address top 3 bits of addr only are used, 2K FRAM
  byte lsb_addr = lowByte(addr);

  Wire.beginTransmission(Memory_I2C_Addr + msb_addr);
  Wire.write(lsb_addr);
  Wire.endTransmission();
  Wire.requestFrom(Memory_I2C_Addr + msb_addr, 4);

  union
  {
    byte b[4];
    float f;
  } readdata;


  for (int index = 0; index < 4; index++)
  {
    val = Wire.read();          // read the byte
    readdata.b[index] = val;
  }
  return readdata.f;
}

unsigned long Memory_ReadULong(unsigned int addr)
{
  byte index, val;
  byte msb_addr = (highByte(addr) & 0x07);            //mask off bottom 3 bytes of address top 3 bits of addr only are used, 2K FRAM
  byte lsb_addr = lowByte(addr);

  Wire.beginTransmission(Memory_I2C_Addr + msb_addr);
  Wire.write(lsb_addr);
  Wire.endTransmission();
  Wire.requestFrom(Memory_I2C_Addr + msb_addr, 4);

  union
  {
    byte b[4];
    unsigned long f;
  } readdata;

  for (int index = 0; index < 4; index++)
  {
    val = Wire.read();          // read the byte
    readdata.b[index] = val;
  }

  return readdata.f;
}




/***************************************************************************
  Start of general purpose memory routines
***************************************************************************/

unsigned int Memory_CRC(unsigned int startaddr, unsigned int endaddr)
{
  unsigned int i, CRC;

  CRC = 0xffff;                                              //start value for CRC16
  byte j;

  for (i = startaddr; i <= endaddr; i++)                     //element 4 is first character after $$$$ at start
  {
    CRC ^= ((uint16_t)Memory_ReadByte(i) << 8);
    for (j = 0; j < 8; j++)
    {
      if (CRC & 0x8000)
        CRC = (CRC << 1) ^ 0x1021;
      else
        CRC <<= 1;
    }
  }
  return CRC;

}


void Memory_Set(unsigned int startaddr, unsigned int endaddr, byte lval)
{
  unsigned int i;
  for (i = startaddr; i <= endaddr; i++)
  {
    Memory_WriteByte(i, lval);
  }
}




