#include <stdio.h>

int factorial(int n);
double putere(double x,int n);
double taylor(double x,int n)
{
	double S=0;
	int i;	
	for(i=0;i<=n;i++)
		S=S+(double)putere(x,i)/factorial(int);
	return S;
}
int factorial(int n)
{
	int i;
	double P=1;
	for(i=2;i<=n;i++)
		P=P*i;
	return P;
}
double putere(double x,int n)
{
	int i;
	double P=1;
	for(i=1;i<=n;i++)
		P=P*x;
	return P;
}
int main()
{
	float x;
	int n;
	scanf("%f%d",&x,&n);
	taylor(x,n);
	printf("%lf	\n",taylor(x,n));
	return 0;
}