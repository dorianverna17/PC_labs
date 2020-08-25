#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

void pb1()
{
	printf("pb1\n");
	int seed,n1,n2,n3;
	printf("Da-mi seed: ");
	scanf("%d",&seed);
	srand(seed);
	n1=rand();
	n2=rand();
	n3=rand();
	printf("%d %d %d",n1,n2,n3);
	printf("\n");
}
void pb2()
{
	printf("pb2\n");
	float n1,n2,n3;
	scanf("%f%f%f",&n1,&n2,&n3);
	printf("%.2f %.2f %.2f\n",n1,n2,n3);
	printf("%.2e %.2e %.2e\n",n1,n2,n3);
	printf("%g %g %g\n",n1,n2,n3);
}
void pb3()
{
	printf("pb3\n");
	printf("|");
	printf("%*s|",8,"x");
	printf("%*s|",8,"sin(x)");
	printf("%*s|",8,"cos(x)");
	printf("\n");
	printf("|");
	int i;
	for(i=0;i<26;i++)
	{
	printf("=");
	}
	printf("|");
	printf("\n");
	double x,PI=M_PI;
    for (x=0;x<=2*PI;x=x+PI/20)
    {
    	printf("|");
    	printf("%+*.3lf",8,x);
    	printf("|");
    	printf("%+*.3lf",8,sin(x));
    	printf("|");
    	printf("%+*.3lf",8,cos(x)); 
		printf("|");
		printf("\n");    
    }
}
void pb4()
{
	printf("pb4\n");
	float X,Y;
	scanf("%f%f",&X,&Y);
	if(X==0)
		if(Y==0)printf("Punctul coincide cu originea\n");
		else printf("Punctul este pe axa Y\n");
	else
		if(Y==0) printf("Punctul este pe axa X\n");
		else
			if(X<0)
				if(Y<0)
					printf("3\n");
				else
					printf("2\n");
			else
				if(Y>0)
					printf("1\n");
				else
					printf("4\n");	
}
void pb5()
{
	printf("pb5\n");
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	if(a<1000000000 && b<1000000000 && c<1000000000 && a>-1000000000 && b>-1000000000 && c>-1000000000 && a+b+c!=0)
	if(a+b>=c && a+c>=b && b+c>=a)printf("DA\n");
	else printf("NU\n");
	else printf("NU\n");
}
void pb6()
{
	printf("pb6\n");
	float a,b,c;
	scanf("%f%f%f",&a,&b,&c);
	if(a+b+c!=0)
	if(a+b>=c && a+c>=b && b+c>=a)
	{
		if(a==b && b==c)printf("echilateral\n");
		else
			if(a==b || b==c || a==c)
				if(a*a+b*b-c*c<=0.001 || c*c+b*b-a*a<=0.001 || a*a+c*c-b*b<=0.001)
					printf("Isoscel dreptunghic\n");
				else printf("Isoscel\n");
			else
				if(a*a+b*b-c*c<=0.001 || c*c+b*b-a*a<=0.001 || a*a+c*c-b*b<=0.001)
					printf("Dreptunghic\n");
				else printf("Oarecare\n");
	}
	else printf("Nu este triunghi\n");
	else printf("Nu este triunghi\n");
}
void pb7()
{
	printf("pb7\n");
	int A,B,C,D;
	scanf("%d%d%d%d",&A,&B,&C,&D);
	if(A>B)
		if(B>C)
			if(C>D)
				printf("%d %d\n",D,A);
			else
				if(B>D)
					printf("%d %d\n",C,A);
				else 
					if(A>D)
						printf("%d %d\n",C,A);
					else
						printf("%d %d\n",C,D);
		else
			if(B>D)
				printf("%d %d\n",D,A);
			else
				if(C>D)
					printf("%d %d\n",B,A);
				else
					if(A>D)
						printf("%d %d\n",B,A);
					else
						printf("%d %d\n",B,D);
	else
		if(A>C)
			if(C>D)
				printf("%d %d\n",D,B);
			else
				if(A>D)
					printf("%d %d\n",C,B);
				else 
					if(B>D)
						printf("%d %d\n",C,B);
					else
						printf("%d %d\n",C,D);
		else
			if(A>D)
				printf("%d %d\n",D,B);
			else
				if(C>D)
					printf("%d %d\n",A,B);
				else
					if(B>D)
						printf("%d %d\n",A,B);
					else
						printf("%d %d\n",A,D);
}
void pb8()
{
	printf("pb8\n");
	int A,B,C;
	scanf("%d%d%d",&A,&B,&C);
	if(A>=B && B>=C){printf("%d %d %d",C,B,A);goto da;}
	if(B>=A && A>=C){printf("%d %d %d",C,A,B);goto da;}
	if(C>=B && B>=A){printf("%d %d %d",A,B,C);goto da;}
	if(B>=C && C>=A){printf("%d %d %d",A,C,B);goto da;}
	if(A>=C && C>=B){printf("%d %d %d",B,C,A);goto da;}
	if(C>=A && A>=B){printf("%d %d %d",B,A,C);goto da;}
	da: printf("\n");
}
void pb9()
{
	printf("pb9\n");
	int H,M,S;
	scanf("%d%d%d",&H,&M,&S);
	printf("%02d:",H);
	printf("%02d:",M);
	printf("%02d",S);
	printf("\n");
}
void pb10()
{
	printf("pb10\n");
	int H,M,S;
	if(scanf("%d%d%d",&H,&M,&S)==3)
	{
	printf("%02d:",H);
	printf("%02d:",M);
	printf("%02d",S);
	printf("\n");
	}
	else printf("Date incorect introduse!\n");
}
void pb11()
{
	printf("pb11\n");
	printf("pb2\n");
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	if(a==0)
		if(b!=0)printf("Solutia este %f\n",(float)-c/b);
		else
			if(c!=0) printf("Nu exista solutii reale\n");
			else printf("Infinit\n");
	else
	{
		int delta;
		delta=b*b-4*a*c;
		if(delta==0)printf("Solutia este %f\n",(float)-b/(2*a));
		else if(delta<0) printf("Nu exista solutii reale\n");
		else printf("Solutiile sunt %f si %f\n",((-b+sqrt(delta))/(2*a)),((-b-sqrt(delta))/(2*a))); 
	}
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
		default: printf("Nu s-a gasit problema!\n");break;
	}
	return 0;
}