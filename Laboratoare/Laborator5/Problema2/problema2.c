#include <stdio.h>

int cifra(int n,int c)
{
	int x;
	while(n!=0)
	{
		x=n%10;
		if(x==c)return 1;
		n=n/10;
	}
	return 0;
}
int main()
{
	int n,c;
	scanf("%d%d",&n,&c);
	if(cifra(n,c))printf("DA\n");
	else printf("NU\n");
	return 0;
}