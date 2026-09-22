#include<stdio.h>
int main()
{
	int n , fact = 1 , i=1 ;
	printf("Enter n : ");
	scanf("%d" , &n ) ; 
	while(i<=n)
	{
		fact *=i ;
		i++ ;
	}//end of while loop
	printf( " Factorial = %d " , fact) ;
	return 0 ; 

} // end of main function
