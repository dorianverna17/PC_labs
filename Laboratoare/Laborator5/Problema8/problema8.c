#include <stdio.h>

int arie_intersectie(int x11,int y11,int x12,int y12,int x21,int y21,int x22,int y22)
{
	int x1=x11,x2=x12,x3=x21,x4=x22;
	int y1=y11,y2=y12,y3=y21,y4=y22;
	int deltax,deltay;
	if(x1<x3 && x4<x2)deltax=x4-x3;
	else if(x3<x1 && x1<x4 && x4<x2)deltax=x4-x1;
	else if(x1<x3 && x3<x2 && x2<x4)deltax=x2-x1;
	else return 0;
	if(y2<y4 && y3<y1)deltay=y3-y4;
	else if(y4<y2 && y2<y3 && y3<y1)deltay=y3-y2;
	else if(y2<y4 && y4<y1 && y1<y3)deltay=y1-y2;
	else return 0;
	return deltay*deltax;
}
int main()
{
	int x11,y11,x12,y12,x21,y21,x22,y22;
	scanf("%d%d%d%d%d%d%d%d",&x11,&y11,&x12,&y12,&x21,&y21,&x22,&y22);
	printf("%d\n",arie_intersectie(x11,y11,x12,y12,x21,y21,x22,y22));
	return 0;
}