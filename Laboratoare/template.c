#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

void pb1()
{
	printf("pb1\n");
}
void pb2()
{
	printf("pb2\n");
}
void pb3()
{
	printf("pb3\n");
}
void pb4()
{
	printf("pb4\n");
}
void pb5()
{
	printf("pb5\n");
}
void pb6()
{
	printf("pb6\n");
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