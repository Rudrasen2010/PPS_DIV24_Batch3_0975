#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
} // end of swap function 

int main() 
{
    int motor1, motor2, *p1, *p2;
    motor1 = 10;
    motor2 = 20;
    
    
    p1 = &motor1; 
    p2 = &motor2;
    
    // Before Swap
    
    printf("Speeds of Motors are: \t%d\t%d\n", *p1, *p2);
    printf("----Before Swappping----\n");
    printf(" \nAddress of p1 : %p , Address of p2 : %p ",(void*)p1,(void*)p2 );
    
    swap(p1, p2);
    
  // After Swap
    
    printf("\nSpeeds of Motors are: \t%d\t%d\n", *p1, *p2);
    printf("----After Swappping----\n");
    printf(" \nAddress of p1 : %p , Address of p2 : %p ",(void*)p1,(void*)p2 );
    
    return 0; 
} // end of main function
