/*
**  CHECKSUM.C - Compute the checksum of a file
**
**  public somain demo by Bob Stout
*/

#include <stdlib.h>

char buf1[10]={0xAA, 0xBB, 0xCC, 0xDD, 0xEE, 0xFF, 0x00, 0x11, 0x22, 0x55};
char *buff2 = "$OWMWV,0.0,R,0.03,M,A";
unsigned checksum(void *buffer, size_t len, unsigned int seed)
{
      //The following step creates a pointer and points to the array in question.
      //Without the pointer, the arithmetic and increment for checksum wont work.
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
      char buf[4096], *file = "cksum.c";

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

      len = strlen(buff2);
      printf("size of  buff2 : %d \n", len);
      printf("The checksum of buff2 is %d\n", checksum(buff2, len, 0));


      uint16_t chksum =0;
      unsigned char *tmpptr = (unsigned char*)buf1;
      for(int count =0; count < 10;count++)
      {
            chksum += (uint16_t)(*tmpptr++);
      }
      printf("The manual checksum of buf is %#4x\n",chksum);

}

#endif