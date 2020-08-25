#include <stdio.h>

int nrcf(long n)
{
	if(n==0)
		return 1;
	int nr=0;
	while(n)
	{
		n=n/10;
		nr++;
	}
	return nr;
}
int main()
{
	long N;
	printf("N= ");
	scanf("%ld",&N);
	printf("Numarul %ld are %d cifre\n",N,nrcf(N));
	return(0);
}	