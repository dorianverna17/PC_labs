#include <stdio.h>
#include <math.h>

int cmmdc(int a,int b)
{
	int r;
	int a1=a,b1=b;
	while(b1!=0)
	{
		r=a1%b1;
		a1=b1;
		b1=r;
	}
	return a1;
}
int cmmmc(int a,int b)
{
	return (a*b)/cmmdc(a,b);
}
int main()
{
	int x1,y1,x2,y2;
	scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
	printf("%d %d\n",x1*(cmmmc(y1,y2)/y1),cmmmc(y1,y2));
	printf("%d %d\n",x2*(cmmmc(y1,y2)/y2),cmmmc(y1,y2));
	return 0;
}