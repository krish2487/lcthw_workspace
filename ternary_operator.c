#include <stdio.h> 
  
int main() 
{ 
    printf( "Execute expression using ternary operator\n");
    int a = 2 > 3 ? 2 : 3 > 4 ? 3 : 4; 
    printf("%d\n",a);
      
    printf( "Execute expression using if else statements\n");
    if ( 2 > 3 ) 
        printf( "2\n"); 
    else if ( 3 > 4 ) 
        printf("3\n"); 
    else 
        printf("4\n"); 
    return 0; 
} 