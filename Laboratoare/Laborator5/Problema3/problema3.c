#include <stdio.h>
#include <math.h>

int prim(int n)
{
	int i;
	for(i=2;i<=sqrt(n);i++)
		if(n%i==0)return 0;
	return 1;
}
void ipo(int n)
{
	int i;
	for(i=1;i<n;i++)
		if(prim(i) && prim(n-i) && i<=n-i)
			printf("%d %d\n",i,n-i);
}
int main()
{
	int N;
	scanf("%d",&N);
	ipo(N);
	return 0;
}