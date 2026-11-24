#include<stdio.h>

int factorial(int n )
{
	int fact = 1 ;
	for ( int i = 1 ; i <= n  ; i++)
		fact = fact * i ;
		return fact ;
		
}

int main()
{
	int n = 5 ;
	printf("Factorial = %d \n" , factorial(n));
	return 0 ;

}//end of main function 
