/*
**  CHECKSUM.C - Compute the checksum of a file
**
**  public somain demo by Bob Stout
*/

#include <stdlib.h>

char buf1[10]={0xAA, 0xBB, 0xCC, 0xDD, 0xEE, 0xFF, 0x00, 0x11, 0x22, 0x55};

unsigned checksum(void *buffer, size_t len, unsigned int seed)
{
      unsigned char *buf = (unsigned char *)buffer;
      size_t i;

      for (i = 0; i < len; ++i)
            seed += (unsigned int)(*buf++);
      return seed;
}

#ifdef TEST

#include <stdio.h>

main()
{
      FILE *fp;
      size_t len;
      char buf[4096], *file = "checksum.c";

      if (NULL == (fp = fopen(file, "rb")))
      {
            printf("Unable to open %s for reading\n", file);
            return -1;
      }
      len = fread(buf, sizeof(char), sizeof(buf), fp);
      printf("%d bytes read\n", len);
      printf("The checksum of %s is %#x\n", file, checksum(buf, len, 0));

      len = sizeof(buf1);
      printf("size of  buf : %d \n", len);
      printf("The checksum of buf is %#4x\n", checksum(buf1, len, 0));

      uint16_t chksum =0;
      for(int count =0; count < 10;count++)
      {
            chksum += buf1[count];
      }
      printf("The manual checksum of buf is %#4x\n",chksum);

}

#endif