// #include<stdio.h>

// union tagname
// {
// 	unsigned int a;
// 	unsigned char s[4];
// };

// union tagname object;

// int main()
// {
// 	char i; //for loop counter

// 	//assign an integer number
// 	object.a=0xAABBCCDD;

// 	printf("Integer number: %ld, hex: %X\n",object.a,object.a);

// 	printf("Individual bytes: ");
// 	for(i=3;i>=0;i--)
// 		printf("%02X ",object.s[i]);

// 	printf("\n");
// 	return 0;
// }

#include <stdio.h>
#include <stdint.h>

void main()
{

uint32_t test_var = 0xAABBCCDD;

union test_union {
uint8_t bits_8[4];
uint16_t bits_16[2];
uint32_t bits_32;
} union_member;

union_member.bits_32 = test_var;

printf("32 bit value : %ld, hex : %X\n", union_member.bits_32, union_member.bits_32);
printf("16 bit value 0: %04X , 16 bit value 1: %04X\n", union_member.bits_16[1], union_member.bits_16[0]);
printf("8 bit 0 :%02X , 8 bit 1 :%02X , 8 bit 2 :%02X, 8 bit 3 :%02X\n",union_member.bits_8[3], union_member.bits_8[2], union_member.bits_8[1], union_member.bits_8[0]); 
}
