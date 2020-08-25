#include <stdio.h>

int	transforma(int n)
{
	int x=n,c,ok=0;
	int i,v[10]={0};
	while(x!=0)
	{
		c=x%10;
		if(c==0)ok=1;
		v[c]++;
		x=x/10;
	}
	int j;
	if(ok==1)
	{
		for(i=9;i>=0;i--)
			if(v[i]!=0)
				for(j=1;j<=v[i];j++)
				printf("%d",i);
		printf("\n");
	}
	else
	{
		for(i=0;i<=9;i++)
			if(v[i]!=0)
				for(j=1;j<=v[i];j++)
				printf("%d",i);
		printf("\n");
	}
}
int main()
{
	int N;
	scanf("%d",&N);
	transforma(N);
	return 0;
}