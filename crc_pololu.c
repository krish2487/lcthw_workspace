#include <stdio.h>


/*
CRC calculations.
CRC is calculated by iterating through each of the message bytes
and in each of the iteration - 
XOR the existing CRC with the present message byte, 
Loop for 8 times, for each bit in the byte -
  If the lowest bit is a '1'
  then XOR the CRC with the polynomial (which is 1001 0001 or 0x91)
  Then shift the CRC to the right by 1 bit.


*/

uint16_t CRC7_POLY = 0xa001;
 
unsigned char getCRC(unsigned char message[], unsigned char length)
{
  unsigned char i, j, crc = 0;
 
  for (i = 0; i < length; i++)
  {
    // printf("Outer loop -  Byte # %d : %#4x, crc : %#4x\n", i, message[i], crc);

    crc ^= message[i];
    for (j = 0; j < 8; j++)
    {
      if (crc & 1)
        crc ^= CRC7_POLY;
      crc >>= 1;
      // printf("Inner loop -  crc : %#4x\n", crc);
    }
    // printf("Inner loop exit - crc : %#4x\n", crc);

  }
  return crc;
}
 
int main()
{
  // create a message array that has one extra byte to hold the CRC:
  unsigned char message[7] = {0x83, 0xAA, 0x12, 0xC3, 0x92};
  char *buff2 = "$OWMWV,0.0,R,0.03,M,A";

  // message[5] = getCRC(message, 5);
  // printf("CRC is %#4x\n", message[5]);
  // message[6] = getCRC(message, 6);
  // printf("CRC verification check is %#4x\n", message[6]);
  // // send this message to the Simple Motor Controller

  printf("CRC for buffer 2 is %d\n", getCRC(buff2,21));
  // for (int i = 0; i < 7; ++i)
  // {
  //   /* code */
  //   printf("message byte #%d : %#4x\n", i,message[i]);
  // }
}