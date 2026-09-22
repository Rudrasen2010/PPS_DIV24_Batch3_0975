#include<stdio.h>
int main()
{
	int n , sum = 0 ;
	printf("Enter n : ") ;
	scanf("%d" , &n ) ; 
	for ( int i = 1 ; i<=n ; i ++ )
	{
		sum+=i ; 
	} // end of for loop 
	printf(" Sum = %d " , sum );
	return 0 ;


} // end of main function
