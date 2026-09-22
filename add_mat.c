#include<stdio.h>
int main()
{
	int r , c , i , j ;
	printf("Enter Rows and Columns :" );
	scanf("%d%d" , &r , &c ) ;
	int sensor1[r][c];
	int sensor2[r][c];
	int sensor3[r][c];
	
	printf("Enter Sensor1 Elements = \n");
	for( i=0 ; i<r ; i++)
	{	for(j=0 ; j<c ; j++){
		scanf("%d" , &sensor1[i] [j] ) ;
		}
	}

	printf("sensor1 Elements = \n");
	for( i=0 ; i<r ; i++)
	{	for(j=0 ; j<c ; j++){
		printf("%d \t " , sensor1[i] [j] ) ;
		}
	printf("\n");
	}

	printf("Enter Sensor2 Elements = \n");
	for( i=0 ; i<r ; i++)
	{	for(j=0 ; j<c ; j++){
		scanf("%d" , &sensor2[i] [j] ) ;}}
	printf("sensor2 Elements = \n");
	for( i=0 ; i<r ; i++)
	{	for(j=0 ; j<c ; j++){
		printf("%d \t " , sensor2[i] [j] ) ;}
	printf("\n");}
	for( i=0 ; i<r ; i++)
	{	for(j=0 ; j<c ; j++){
		sensor3[i][j] = sensor1[i][j] + sensor2[i][j] ; }}
	printf("sensor3 Elements = \n");
	for( i=0 ; i<r ; i++)
	{	for(j=0 ; j<c ; j++){
		printf("%d \t" , sensor3[i] [j] ) ;
		}printf("\n");}
	return 0 ;
}//end of main function
