#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

void pb1()
{
	//Interschimbul a doua variabilea si b
	printf("pb1\n");
	int a,b;
	scanf("%d",&a);
	scanf("%d",&b);
	int aux;
	aux=b;
	b=a;
	a=aux;
	printf("%d %d\n",a,b);
}
void pb2()
{
	//rezolvarea ecuatiei de gradul 2
	printf("pb2\n");
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	if(a==0)
		if(b!=0)printf("Solutia este %f\n",(float)-c/b);
		else
			if(c!=0) printf("Nu exista solutii reale\n");
			else printf("Solutia este multimea numerelor reale\n");
	else
	{
		int delta;
		delta=b*b-4*a*c;
		if(delta==0)printf("Solutia este %f\n",(float)-b/(2*a));
		else if(delta<0) printf("Nu exista solutii reale\n");
		else printf("Solutiile sunt %f si %f\n",((-b+sqrt(delta))/(2*a)),((-b-sqrt(delta))/(2*a))); 
	}
}
void pb3()
{
	//Afisarea in ordine crescatoare a 3 variabile
	printf("pb3\n");
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	if(a<b)
		if(b<c)
			printf("%d %d %d\n",a,b,c);
		else 
			if(c>a)
				printf("%d %d %d\n",a,c,b);
			else
				printf("%d %d %d\n",c,a,b);
	else
		if(b>c)
			printf("%d %d %d\n",c,b,a);
		else 
			if(a>c)
				printf("%d %d %d\n",b,c,a);
			else
				printf("%d %d %d\n",b,a,c);
}
void pb4()
{
	//Calculatul sumei S=1+1*2+1*2*3+...n!
	printf("pb4\n");
	int i,S,P,n;
	scanf("%d",&n);	
	P=1;S=0;
	for(i=1;i<=n;i++)
	{
		P=P*i;
		S=S+P;
	}
	printf("%d\n",S);
}
void pb5()
{
	//Suma cifrelor unui numar natural n
	printf("pb5\n");
	int n,S=0;
	scanf("%d",&n);
	while(n!=0)
	{
		S=S+n%10;
		n=n/10;
	}
	printf("Suma cifrelor este: %d\n",S);
}
void pb6()
{
	//inversul unui numar natural n
	printf("pb6\n");
	int n,inv=0;
	scanf("%d",&n);
	while(n!=0)
	{
		inv=inv*10+n%10;
		n=n/10;
	}
	printf("Inversul este: %d\n",inv);
}
void pb7()
{
	//daca un numar natural n este prim
	printf("pb7\n");
	int n;
	scanf("%d",&n);
	int i,ok=0;
	if(n!=1 && n!=0)
	{
	for(i=2;i<=sqrt(n);i++)
		if(n%i==0)ok=1;
	if(ok==1)printf("Numarul nu este prim\n");
	else printf("Numarul este prim\n");
	}
	else printf("Numarul nu este prim\n");
}
void pb8()
{
	//Primele n numere naturale prime
	printf("pb8\n");
	int n,ok;
	scanf("%d",&n);
	int i=2,j,nr=0;
	while(nr<n)
	//for(i=0;i<n && nr<=n;i++)
		{
		ok=0;
		//if(i!=1 && i!=0)
			for(j=2;j<=sqrt(i);j++)
				if(i%j==0)ok=1;
		if(ok==0)
			{
				printf("%d ",i);
				nr++;
			}
		i++;
		}
	printf("\n");
}
void pb9()
{
	//Descompunere in factori primi
	printf("pb9\n");
	int n;
	scanf("%d",&n);
	int i=2,nr,j;
	if(n==1)
		printf("1 la puterea 1\n");
	while(n!=1)
	{
		nr=0;
		while(n%i==0)
		{
			nr++;
			n=n/i;
		}
		if(nr!=0)printf("%d la puterea %d\n",i,nr);
		i++;
	}
}
void pb10()
{
	//valoarea minima si maxima dintr-o secventa de n numere
	printf("pb10\n");
	int n;
	scanf("%d",&n);
	int v[100];
	int i;
	for(i=0;i<n;i++)
		scanf("%d",&v[i]);
	int maxim=v[0],minim=v[0];
	for(i=0;i<n;i++)
	{
		if(v[i]>maxim)maxim=v[i];
		if(v[i]<minim)minim=v[i];
	}
	printf("Minimul este:%d\n",minim);
	printf("Maximul este:%d\n",maxim);
}
void pb11()
{
	//Toate numerele mai mici decat n care pot sa se scrie in doua moduri 
	//diferite ca suma de patrare
	printf("pb11\n");
	int n,i,j,nr;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		nr=0;
		for(j=1;j<=i-1	;j++)
		{
			if(sqrt(j)==(int)sqrt(j) && sqrt(i-j)==(int)sqrt(i-j))nr++;
		}
		//printf("%d\n",nr);
		if(nr==4)printf("%d ",i);
	}
	printf("\n");
}
void pb12()
{
	//cele mai mari doua numere de doua cifre care nu sunt intr-o
	//secventa de numere
	printf("pb12\n");
	int n,i,j,v[100];
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&v[i]);
	}
	int ok,nr=0;
	for(i=99;i>=10;i--)
		{
			ok=0;
			for(j=0;j<n;j++)
				if(v[j]==i)ok=1;
			if(ok==0)
			{
			printf("%d ",i);
			nr++;
			}
			if(nr==2)break;
		}
	printf("\n");
}
void pb13()
{
	//Valorile care apar cel mai des intr-un vector
	printf("pb13\n");
	int n,j,i,v[100];
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&v[i]);
	int a[100]={0};
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			if(v[i]==v[j])a[i]++;
	}
	int maxim=0;
	int ok;
	for(i=0;i<n;i++)
		if(a[i]>maxim)maxim=a[i];
	for(i=0;i<n;i++)
		{
		ok=0;
		for(j=0;j<i;j++)
		{
			if(v[i]==v[j])ok=1;
		}
		if(a[i]==maxim && ok==0)
			printf("%d ",v[i]);
		}
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
		case 13: pb13();break;
		default: printf("Nu s-a gasit aceasta problema\n");break;
	}
	return 0;
}