#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

void pb1()
{
	printf("pb1\n");
	int ch,i,nr=0;
	for(i=32;i<=127;i++)
	{
		ch=i;
		printf("%c = %d ",ch,ch);
		nr++;
		if(nr==10){printf("\n");nr=0;}
	}
	if(nr!=0)printf("\n");
}
void pb2()
{
	printf("pb2\n");
	int n,m;
	scanf("%d%d",&n,&m);
	int nr=0,i,nrl=0;
	for(i=1;i<n;i++)
	{
		nr++;
		if(nr!=m)
		printf("%d ",i);
		else
		{
			printf("%d\n",i);
			nr=0;
			nrl++;
		}
		if(nrl==24)
		{
			getchar();
			getchar();
			nrl=0;
		}
	}
	printf("%d\n",i);
}
void pb3()
{
	printf("pb3\n");
	int n,nr=0,i;
	float x,sx=0;
	double y,sy=0;
	scanf("%d%f%lf",&n,&x,&y);
	for(i=1;i<=n;i++)
	{
		sx=sx+x;
		sy=sy+y;
		nr++;
		if(nr==10)
		{
			printf("%f %e %f %e\n",sx,sx,sy,sy);
			nr=0;
		}
	}
}
void pb4()
{
	printf("pb4\n");
	int n,v[100],nr=1;
	scanf("%d",&n);
	v[0]=n;
	while(n!=0)
	{
		scanf("%d",&n);
		v[nr]=n;
		nr++;
	}
	int i,x,S;
	for(i=0;i<nr-1;i++)
	{
		x=v[i];
		S=0;
		while(x!=0)
		{
			S=S+x%10;
			x=x/10;
		}
		if(v[i]%S==v[i+1])
			printf("(%d, %d)\n",v[i],v[i+1]);
	}
}
void pb5()
{
	printf("pb5\n");
	int P,ok;
	scanf("%d",&P);
	int i,j,k;
	for(i=1;i<P-1;i++)
		for(j=1;j<P-1;j++)
		{
			k=P-i-j;
			ok=0;
			if(i+j>k && k+j>i && i+k>j)ok=1;
			if(i+j+k==P && ok==1 && i<=j && j<=k)
				printf("%d %d %d\n",i,j,k);
		}
}
void pb6a()
{
	printf("pb6a\n");
	int i,n,m;
	int C=1;
	scanf("%d",&n);
	scanf("%d",&m);
	for(i=1;i<=m;i++)
	{
		C=C*((float)(n-i+1)/i);
	}
	printf("%d\n",C);
}
void pb6b()
{
	printf("pb6b\n");
	int n,m,i,P1=1,P2=1,P3=1;
	int C;
	scanf("%d",&n);
	scanf("%d",&m);
	for(i=2;i<=n;i++)
		P1=P1*i;
	for(i=2;i<=m;i++)
		P2=P2*i;
	for(i=2;i<=n-m;i++)
		P3=P3*i;
	C=(float)P1/(P2*P3);
	printf("%d\n",C);
}
void pb6()
{
	printf("pb6\n");
	int n;
	printf("Care varianta de rezolvare? ");
	scanf("%d",&n);
	switch(n)
	{
		case 1: pb6a();break;
		case 2: pb6b();break;
		default: printf("Nu exista aceasta varianta de rezolvare\n");break;
	}
}
void pb7()
{
	printf("pb7\n");
	int n;
	double x,EPS;
	scanf("%d",&n);
	scanf("%lf%lf",&x,&EPS);
	int i,k=1;
	double t=1;
	double S1=0,S2=1;
	while(t>EPS)
	{
		S1=S1+t;
		t=(float)(t*x)/k;
		k++;
	}
	int j,P=1,F=1;
	for(i=1;i<n;i++)
	{
		P=1;F=1;
		for(j=1;j<=i;j++)
			{
			P=P*x;
			F=F*j;
			}
		S2=S2+(float)P/F;
	}
	printf("%lf %lf %lf %lf\n",S2,S1,exp(x),pow(2.718,x));
}
void pb8()
{
	printf("pb8\n");
	float x,eps;
	scanf("%f%f",&x,&eps);
	float r1=(float)x/2;
	//printf("%f\n",r1);
	float r2=(float)(r1+x/r1)/2;
	while(fabs(r1-r2)>=eps)
	{
		if(r2<r1)r1=r1-(float)r1/2;
		else r1=r1+(float)r1/2;
		r2=(float)(r1+(float)x/r1)/2;
	}
	printf("%f ",r2);
	printf("%f\n",sqrt(x));
}
int prim(int x)
{
	int i;
	for(i=2;i<=sqrt(x);i++)
		if(x%i==0)return 0;
	return 1;
}
void pb9()
{
	printf("pb9\n");
	int n,nr=4;
	scanf("%d",&n);
	int a=1,b=1,c;
	while(nr<=n)
	{
		c=a+b;
		if(prim(c))
			printf("%d\n",c);
		a=b;
		b=c;
		nr++;
	}
}
void pb10()
{
	printf("pb10\n");
	int n;
	scanf("%d",&n);
	int i,x,nr,S=0;
	for(i=1;i<=	n;i++)
	{
		x=i;
		nr=0;
		while(x!=0)
		{
			nr++;
			x=x/10;
		}
		S=S+nr;
	}
	printf("%d\n",S);
}
int main()
{
	int n;
	printf("Da-mi numarul problemei: ");
	scanf("%d",&n);
	switch(n)
	{
		case 1: pb1();break;
		case 2: pb2();break;
		case 3: pb3();break;
		case 4: pb4();break;
		case 5: pb5();break;
		case 6: pb6();break;
		case 7: pb7();break;
		case 8: pb8();break;
		case 9: pb9();break;
		case 10: pb10();break;
		default: printf("Nu s-a gasit problema!\n");break;
	}
	return 0;
}