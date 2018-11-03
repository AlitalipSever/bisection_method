#include "stdio.h"
#include "stdlib.h"
#include "math.h"

float function(float x)
{
	return x*x*x+4*x*x-10;
}

float bisection_method(float A, float B, float error)
{
	printf("\t\t    Range [%f,%f] | Error %f\n\n",A,B,error);
	int MAX=log2((B-A)/error);
	float values[MAX][5];

	float _A,P,_P,_B;

	int i,k;

	for(i=1; i<=MAX; i++)
	{
		P=(A+B)/2;
		_A=function(A);
		_P=function(P);
		values[i-1][0] = A;
		values[i-1][1] = B;
		values[i-1][2] = P;
		values[i-1][3] = _P;

		if(_A*_P<0)
			B=P;
		else
			A=P;

		values[i-1][4] = B-A;
	}

	printf("ID\t   An\t\t   Bn\t\t   Pn\t\t  F(Pn)\t\t  ERROR\n");
	printf("__\t________\t________\t________\t________\t________\n");
	for(k=0; k<i-1; k++)
	{
		printf("%d\t%f\t%f\t%f\t%f\t%f\n",k+1,values[k][0],values[k][1],values[k][2],values[k][3],values[k][4]);
	}

	printf("\n\t\t\tRoot of function is %f \n",values[i-2][2]);
	printf("\t\t\t____________________________\n");
	printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n");
}

int main()
{
	printf("\a\n\t\t\t\tBisection Method\n");
	printf("\t\t\t    Function: x^3 + 4*x^2 - 10\n\n");
	bisection_method(1,2,0.005);
	printf("\t\t\t\t\t\t\t\t\t");
	return 0;
}
