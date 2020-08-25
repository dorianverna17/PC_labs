#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

void pb1()
{
	printf("pb1\n");
	int n,v[100],i,n5;
	float procent;
	scanf("%d", &n);
	for(i=0;i<n;i++)
	{
	scanf("%d", &v[i]);  
	}
	n5=0;
	for(i=0;i<n;i++)
	{
	if(v[i]<5)
	{
	n5++;
	}
	} 
	procent=(float)n5*100/n; 
	printf("%.3f\n",procent);
}
void pb2()
{
	printf("pb2\n");
	int i,n,v[100];
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&v[i]);
	}
	int neg=0,poz=0;
	for(i=0;i<n;i++)
	{
		if(v[i]<0)neg++;
		else poz++;
	}
	printf("%d ",neg);
	printf("%d\n",poz);
}
void pb3()
{
	//punct sa
	printf("pb3\n");
	int n,m,i,j,A[100][100];
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
			scanf("%d",&A[i][j]);
	int maxim=A[0][0],minim;
	for(i=0;i<m;i++)
		if(maxim<A[0][i])maxim=A[0][i];
	minim=maxim;
	for(i=0;i<n;i++)
		{
		maxim=A[i][0];
		for(j=0;j<m;j++)
		{
			if(maxim<A[i][j])maxim=A[i][j];
		}
		if(minim>maxim)minim=maxim;
		}
	printf("%d\n",minim);
}
void pb4()
{
	printf("pb4\n");
	int m,n,p,q,i,j;
	int A[100][100],B[100][100];
	scanf("%d%d",&m,&n);
	for(i=0;i<m;i++)
		for(j=0;j<n;j++)
			scanf("%d",&A[i][j]);
	scanf("%d%d",&p,&q);
	for(i=0;i<p;i++)
		for(j=0;j<q;j++)
			scanf("%d",&B[i][j]);
	if(n==p)
		{
		int C[100][100]={0},k,l;
		for(i=0;i<m;i++)
			for(k=0;k<q;k++)
				for(j=0;j<n;j++)
					//for(l=0;l<p;l++)
						C[i][k]=C[i][k]+A[i][j]*B[j][k];
		printf("\n");
		printf("%d %d\n",m,q);
		for(i=0;i<m;i++)
		{
			for(l=0;l<q;l++)
				printf("%d ",C[i][l]);
			printf("\n");
		}
		}
	else
		printf("imposibil\n");

}
void pb5()
{
	printf("pb5\n");
	int v[100],u[100];
	int n1,n2,i,j;
	scanf("%d",&n1);
	for(i=0;i<n1;i++)
		scanf("%d",&v[i]);
	scanf("%d",&n2);
	for(i=0;i<n2;i++)
		scanf("%d",&u[i]);
	int nr=0;
	i=0;
	j=0;
	int w[100];
	while(nr<n1+n2)
	{
		if(i<n1 && j<n2)
		{
			if(v[i]<u[j])
			{
				w[nr]=v[i];
				i++;
			}
			else
			{
				w[nr]=u[j];
				j++;
			}
		}
		else
			if(i==n1 && j<n2)
			{
				w[nr]=u[j];
				j++;
			}
			else
				if(i<n1 && j==n2)
				{
					w[nr]=v[i];
					i++;
				}
		nr++;
	}
	for(i=0;i<nr;i++)
	{
		printf("%d ",w[i]);
	}
	printf("\n");
}
void pb6()
{
	printf("pb6\n");
	int A[100][100];
	int n,i,j;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%d",&A[i][j]);
	for(i=0;i<n;i++)
		for(j=n-i;j<n;j++)
			printf("%d ",A[j][i]);
	printf("\n");
}
void pb7()
{
	printf("pb7\n");
	int i,n,v[100];
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&v[i]);
	int maxim=0,nr,poz;
	i=0;
	poz=0;
	while(i<n)
	{
		nr=0;
		while(v[i]<=v[i+1])
		{
			nr++;
			i++;
		}
		if(nr>maxim)
		{
			maxim=nr;
			poz=i-nr;
		}
		i++;	
	}
	for(i=poz;i<=poz+maxim;i++)
		printf("%d ",v[i]);
	printf("\n");
}
void pb8()
{
	printf("pb8\n");
	int n,v[100],i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&v[i]);
	int j,poz,S,nr,maxim=v[0];
	for(i=0;i<n;i++)
	{
		j=i;
		S=0;
		while(j<n)
		{
			S=S+v[j];
			if(S>maxim)
			{
				maxim=S;
				poz=i;
				nr=j-i;
			}
			j++;
		}
	}
	for(i=poz;i<=poz+nr;i++)
		printf("%d ",v[i]);
	printf("\n");
}
void pb9()
{
	printf("pb9\n");
	int n,v[100],i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&v[i]);
	int ok1=0,ok2=0,ok3=0;
	i=0;
	while(i<n-1)
	{
		if(v[i]!=v[i+1])ok1=1;
		if(v[i]<v[i+1])ok2=1;
		if(v[i]>v[i+1])ok3=1;
		i++;
	}
	if(ok1==1 && ok2==1 && ok3==1)
		printf("neordonat\n");
	else
	{
	if(ok1==0)printf("constant\n");
	else
		if(ok2==0)printf("descrescator\n");
		else
			if(ok3==0)printf("crescator\n");
	}
}
void pb10()
{
	printf("pb10\n");
	int j,n,i,m,u[100];
	float v[100];
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%f",&v[i]);
	scanf("%d",&m);
	for(i=0;i<m;i++)
		scanf("%d",&u[i]);
	int nr=0;
	for(i=0;i<m-1;i++)
		if(u[i]>u[i+1])nr=1;
	if(nr==0)
	for(i=0;i<m-1;i++)
		{
		nr=0;
		for(j=0;j<n;j++)
			if(v[j]<u[i+1] && v[j]>u[i])
				nr++;
		printf("%d ",nr);
		}
	else printf("Error");
	printf("\n");
}
void pb11a()
{
	int n,i;
	float x,P=0,c[100];
	scanf("%f",&x);
	scanf("%d",&n);
	for(i=0;i<n+1;i++)
		scanf("%f",&c[i]);
	for(i=n;i>=0;i--)
		P=P+c[n-i]*pow(x,i);
	printf("%.2f\n",P);
}
void pb11b()
{
	int n,i;
	float x,P,c[100];
	scanf("%f",&x);
	scanf("%d",&n);
	for(i=0;i<n+1;i++)
		scanf("%f",&c[i]);
	i=0;P=0;
	while(i<=n)
	{
		P=P*x+c[i];
		i++;
	}
	printf("%.2f\n",P);
}
void pb11()
{
	printf("pb11\n");
	int n;
	printf("Alege metoda:");
	scanf("%d",&n);
	switch(n)
	{
		case 1: pb11a();break;
		case 2: pb11b();break;
		default: printf("Nu s-a gasit metoda\n");break;
	}
}
void pb12()
{
	printf("pb12\n");
	int n,m,i=0,v[100]={0};
	int beg,end,val;
	scanf("%d",&n);
	scanf("%d",&m);
	int j;
	while(i<m)
	{
		scanf("%d%d%d",&beg,&end,&val);
		for(j=0;j<n;j++)
			if(j>=beg && j<=end)
				v[j]=v[j]+val;
		i++;
	}
	for(i=0;i<n;i++)
		printf("%d ",v[i]);
	printf("\n");
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
		case 11: pb11();break;
		case 12: pb12();break;
		default: printf("Nu s-a gasit problema!\n");break;
	}
	return 0;
}