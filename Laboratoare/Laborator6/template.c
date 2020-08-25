#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

void bubblesort(int n,int v[])
{
	int schimb,i,aux;
	do{
		schimb=0;
		for(i=0;i<n-1;i++)
			if(v[i]>v[i+1])
			{
				aux=v[i];
				v[i]=v[i+1];
				v[i+1]=aux;
				schimb=1;
			}
	}while(schimb==1);
}
void pb1()
{
	printf("pb1\n");
	int n,v[100],i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&v[i]);
	bubblesort(n,v);
	for(i=0;i<n;i++)
		printf("%d ",v[i]);
	printf("\n");
}
void calcul1(float v[],float u[])
{
	u[0]=(float)(acos((float)(-v[0]*v[0]+v[1]*v[1]+v[2]*v[2])/(2*v[1]*v[2]))*180)/M_PI;
	u[1]=(float)(acos((float)(-v[1]*v[1]+v[0]*v[0]+v[2]*v[2])/(2*v[0]*v[2]))*180)/M_PI;
	u[2]=(float)(acos((float)(-v[2]*v[2]+v[1]*v[1]+v[0]*v[0])/(2*v[1]*v[0]))*180)/M_PI;
}
void pb2a()
{
	float v[3],u[3];
	scanf("%f%f%f",&v[0],&v[1],&v[2]);
	calcul1(v,u);
	printf("%.3f %.3f %.3f\n",u[0],u[1],u[2]);
}
void calcul2(float x,float y,float z,float *x1,float *y1,float *z1)
{
	(*x1)=(float)(acos((float)(-x*x+y*y+z*z)/(2*y*z))*180)/M_PI;
	(*y1)=(float)(acos((float)(-y*y+x*x+z*z)/(2*x*z))*180)/M_PI;
	(*z1)=(float)(acos((float)(-z*z+x*x+y*y)/(2*y*x))*180)/M_PI;
}
void pb2b()
{
	float x,y,z,x1,y1,z1;
	scanf("%f%f%f",&x,&y,&z);
	calcul2(x,y,z,&x1,&y1,&z1);
	printf("%.3f %.3f %.3f\n",x1,y1,z1);	
}
void pb2()
{
	printf("pb2\n");
	int n;
	printf("Ce varianta de rezolvare alegeti?\n");
	scanf("%d",&n);	
	switch(n)
	{
		case 1: pb2a();break;
		case 2: pb2b();break;
		default: printf("Nu a fost gasita varianta\n");break;
	}
}
void citire3(int *n,int *m,int v[],int u[])
{
	int i;
	scanf("%d",n);
	for(i=0;i<(*n);i++)
		scanf("%d",&v[i]);
	scanf("%d",m);
	for(i=0;i<(*	m);i++)
		scanf("%d",&u[i]);
}
int extrag(int *v,int *u,int n,int m,int *c)
{
	int i,j,k=0;
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
			if(*(u+j)==*(v+i))
				{
				*(c+k)=*(u+j);
				k++;
				}
	return k; 
}
void pb3()
{
	printf("pb3\n");
	int i,n,m;
	int v[100],u[100],c[100];
	citire3(&n,&m,v,u);
	extrag(v,u,n,m,c);
	for(i=0;i<extrag(v,u,n,m,c);i++)
		printf("%d ",c[i]);
	printf("\n");
}
int compare(char s1[],char s2[])
{
	int i=0,j=0;
	while(i<strlen(s1) && i<strlen(s2))
	{
		if(s1[i]>s2[i])return 1;
		else
			if(s1[i]<s2[i])return -1;
			else if(s1[i]==s2[i])
			{
				i++;
			}
	}
	if(i==strlen(s1) && i<strlen(s2))
		return -1;
	else
		if(i<strlen(s1) && i==strlen(s2))
			return 1;
	return 0;
}
void pb4()
{
	printf("pb4\n");
	char s1[100],s2[100];
	scanf("%s%s",s1,s2);
	printf("%d\n",compare(s1,s2));
}
void transform(int v[],int n,int x)
{
	int i,nr=0,j,aux;
	for(i=0;i<n;i++)
		if(v[i]<x)nr++;
	for(i=nr;i<n;i++)
		if(v[i]<x)
			for(j=0;j<nr;j++)
				if(v[j]>=x)
				{
					aux=v[i];
					v[i]=v[j];
					v[j]=aux;
				}
}
void pb5()
{
	printf("pb5\n");
	int n,x,i,v[100];
	scanf("%d%d",&n,&x);
	for(i=0;i<n;i++)
		scanf("%d",&v[i]);
	transform(v,n,x);
	for(i=0;i<n;i++)
		printf("%d ",v[i]);
	printf("\n");
}
void spirala(int A[][100],int n,int m,int v[])
{
	int k=0,i;
	int a=0,b=1;
	int x=m,y=n;
	while(k<x*y)
	{
		for(i=a;i<n;i++)
		{
			v[k]=A[i][a];
			k++;
		}
		for(i=b;i<m-1;i++)
		{
			v[k]=A[n-1][i];
			k++;
		}
		for(i=n-1;i>=a;i--)
		{
			v[k]=A[i][m-1];
			k++;
		}
		for(i=m-2;i>=b;i--)
		{
			v[k]=A[a][i];
			k++;
		}
		a++;b++;
		n--;m--;
	}
}
void afisare(int v[],int dim)
{
	int i;
	for(i=0;i<dim;i++)
		printf("%d ",v[i]);
	printf("\n");
}
void pb6()
{
	printf("pb6\n");
	int n,m,i,j,A[100][100];
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
			scanf("%d",&A[i][j]);
	int v[n*m];
	spirala(A,n,m,v);
	afisare(v,m*n);
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
		default: printf("Nu s-a gasit problema!\n");break;
	}
	return 0;
}