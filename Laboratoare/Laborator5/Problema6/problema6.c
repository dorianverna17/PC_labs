#include <stdio.h>
#include <math.h>

float dist(int x1,int y1,int x2,int y2)
{
	return sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
}
int main()
{
	int n;
	scanf("%d",&n);
	int x[100],y[100],j,k,l,i;
	float maxim=0;
	for(i=0;i<n;i++)
		scanf("%d%d",&x[i],&y[i]);	
	for(i=0;i<n-1;i++)
		for(j=i;j<n;j++)
		if(dist(x[i],y[i],x[j],y[j])>maxim)
		{
			maxim=dist(x[i],y[i],x[j],y[j]);
			l=i;
			k=j;
		}
	printf("\n");
	printf("%d %d\n%d %d\n%f\n",x[l],y[l],x[k],y[k],maxim);
	return 0;	
}