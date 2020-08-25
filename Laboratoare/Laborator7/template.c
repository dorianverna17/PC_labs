#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

void swap(int *pa, int *pb)
{
	int aux;
	aux = *pa;
	*pa = *pb;
	*pb = aux;
}
void pb1()
{
	printf("pb1\n");
	int a, b;
	scanf("%d%d", &a, &b);
	swap(&a, &b);
	printf("%d %d\n", a, b);
}
void count(int n, int *v, int *zero, int *poz, int *neg)
{
	int i;
	for(i = 0; i < n; i++)
	{
		if(v[i] == 0) (*zero)++;
		else if(v[i] < 0) (*neg)++;
		else (*poz)++;
	}
}
void pb2()
{
	printf("pb2\n");
	int i, n, v[100];
	scanf("%d", &n);
	for(i = 0; i < n; i++)
	{
		scanf("%d", &v[i]);
	}
	int poz = 0, neg = 0, zero = 0;
	count(n,v,&zero,&poz,&neg);
	printf("nule: %d\npozitive: %d\nnegative: %d\n", zero, poz, neg);
}
char *strdel(char *p, int n)
{
	char aux[3000];
	strcpy(aux, p+n);
	strcpy(p, aux);
	return p;
}
char *strins(char *p, char *s)
{
	char aux[3000];
	strcpy(aux, p);
	strcpy(p, s);
	strcat(p, aux);
	return p;
}
void pb3()
{
	printf("pb3\n");
	getchar();
	char s1[3000], s2[20], s3[20];
	fgets(s1, 3000, stdin);
	scanf("%s", s2);
	scanf("%s", s3);
	char *p = strstr(s1,s2);
	while(p != NULL)
		{
		strins(strdel(strstr(p, s2), strlen(s2)), s3);
		p = strstr(p + strlen(s3), s2);
		}
	printf("%s", s1);
}
char *substr(char *src, int n, char *dest)
{
	char aux[100];
	strcpy(aux, src);
	strcpy(aux+n,"\0");
	strcpy(dest,aux);	
	return dest;
}
void pb4()
{
	printf("pb4\n");
	char s1[100], dest[100];
	int poz, n;
	getchar();
	fgets(s1, 100, stdin);
	strdel(s1 + strlen(s1) - 1, 1);
	scanf("%d%d", &poz, &n);
	printf("%s\n", substr(s1+poz, n, dest));
}
void panta(int x1, int y1, int x2, int y2, float *m, float *n)
{
	if(x2 != x1)
	(*m) = (float)(y2 - y1) / (x2 - x1);
	else (*m) = INT_MAX;
	(*n) = y1 - (*m) * x1;
}
void pb5()
{
	printf("pb5\n");
	int x1, x2, x3, y1, y2, y3;
	float m, n;
	scanf("%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &x3, &y3);
	panta(x1, y1, x2, y2, &m, &n);
	if(m * x3 + n == y3) printf("DA\n");
	else printf("NU\n");
}
char *next(char *from, char *word)
{
	int i = 0, j, k, ok, s;
	while(i <= strlen(from))
	{
	if(from[i] < 'A' || from[i] > 'z')
		{
		i++;
		}
	else
	{
		strcpy(word, from + i);
		j = 0; ok = 0; s = i;
		while(from[i] >= 'A' && from[i] <= 'z')
			{
			j++;
			i++;
			}
		strncpy(word, from + s,j);
		word[j] = '\0';
		for(k = 0; k < strlen(word); k++)
		{
			if(word[k] <= 'Z' && word[k] >= 'A')
				ok = 1;
		}
		if(ok == 0)
		{
			printf("%s ", word);
			return from + i;
		}
	}
	}
	return NULL;
}
void pb6()
{
	printf("pb6\n");
	char s[100], word[100];
	getchar();
	fgets(s, 100, stdin);
	strdel(s + strlen(s) - 1, 1);
	char *p = next(s, word);
	while(p != NULL)
		{
		p = next(p, word); 
		}
	printf("\n");
}
int main()
{
	int n;
	printf("Da-mi numarul problemei: ");
	scanf("%d", &n);
	switch(n)
	{
		case 1: pb1(); break;
		case 2: pb2(); break;
		case 3: pb3(); break;
		case 4: pb4(); break;
		case 5: pb5(); break;
		case 6: pb6(); break;
		default: printf("Nu s-a gasit problema\n"); break;
	}
	return 0;
}