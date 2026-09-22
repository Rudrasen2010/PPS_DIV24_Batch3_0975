#include<stdio.h>
#include<math.h>
int main()
{
	int num1 , num2 , choice , result ; 
	printf(" Enter Two Numbers = ");
	scanf(" %d , %d " , &num1 , &num2 ) ;
	printf(" Operation = \n");
	printf("1. Addition \n ");
	printf("2. Subtraction \n ");
	printf("3. Multiplication \n ");
	printf("4. Division \n ");
	printf("5. Modulus \n");
	printf(" Enter Choice = ");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1 : result = num1+num2 ;
			printf("Addition = %d", result );
			break ;
		case 2 : result = num1-num2 ;
			printf("Subtraction = %d", result);
			break ; 
		case 3 : result = num1*num2 ; 
			printf("Multiplication = %d ", result);
			break ; 
		case 4 : result = num1/num2 ;
			printf("Divison  = %d ", result);
			break ; 
		case 5 : result = num1%num2 ;
			printf("Modulus = %d ",result);
			break ;
		default : printf(" Invalid Operator ! " ) ;
	
	} // end of switch case
	
	return 0 ;




} // end of main function 
