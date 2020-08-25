#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

char* my_replace(char* s, char* s1, char* s2)
{
	char *p, *aux;
	p = strstr(s, s1);
	aux = malloc((strlen(s)+1) * sizeof(char));
	while(p != NULL)
	{
		strcpy(aux, s2);
		strcat(aux, p + strlen(s1));
		strcpy(p, aux);
		p = strstr(p + strlen(s2), s1);
		strcpy(aux, "");
	}
	void free(void* aux);
	return s;
}
void pb1()
{
	printf("pb1\n");
	char aux[200];
	char *s = malloc((strlen(aux) + 1) * sizeof(char));
	getchar();
	fgets(s, 100, stdin);
	char *s1 = malloc((strlen(aux) + 1) * sizeof(char));
	char *s2 = malloc((strlen(aux) + 1) * sizeof(char));
	scanf("%s", s1);
	scanf("%s", s2);
	printf("%s", my_replace(s, s1, s2));
	void free(void* s);
	void free(void* s1);
	void free(void* s2);
}
void pb2()
{
	printf("pb2\n");
	int n = 0, cap = 5;
	int *v;
	v = malloc(cap * sizeof(int));
	scanf("%d", v + n);
	while(*(v + n) != 0)
	{
		n++;
		if(n==cap)
		{
			cap = cap * 2;
			v = realloc(v, cap * sizeof(int));
		}
		scanf("%d", (v + n));
	}
	int i;
	for(i=0;i<n;i++)
		printf("%d ",*(v+i));
	printf("\n");
	void free(void* v);
}
void vectoria(char *v[], int *u, char *s1, int *m)
{
	int i, ok = 0;
	for(i = 0; i < (*m); i++)
		if(strcmp(v[i], s1) == 0)
			{
			ok = 1;
			u[i]++;
			}
	if(ok == 0)
	{
		v[*m] = malloc(19 * sizeof(char));
		strcpy(v[(*m)], s1);
		(u[(*m)])++;
		(*m)++;
	}
}
void pb3a()
{
	printf("pb3a\n");
	int n, i = 0, m = 0;
	char *v[100], *w[100];
	int *u;
	u = calloc(100, sizeof(int)); 
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		{
		*(w + i) = malloc(19 * sizeof(char));
		scanf("%s", w[i]);
		}
	for(i = 0; i < n; i++)
	{
		vectoria(v, u, w[i], &m);
	}
	for(i = 0; i < m; i++)
	{
		printf("%s %d", v[i], u[i]);
		printf("\n");
	}
	for(i=0;i<m;i++)
		{
		free(v[i]);
		free(w[i]);
		}
	free(u);
}
void vectorib(char **v, int *u, char *s1, int *m, int *cap)
{
	int i, ok = 0;
	for(i = 0; i < (*m); i++)
		if(strcmp(v[i], s1) == 0)
			{
			ok = 1;
			u[i]++;
			}
	if(ok == 0)
	{
		if(*m == *cap)
		{
		*cap = *cap + 3;
		v = realloc(v, *cap * sizeof(char));
		u = realloc(u, *cap * sizeof(int));
		}
		v[*m] = malloc(19 * sizeof(char));
		strcpy(v[(*m)], s1);
		(u[(*m)])++;
		(*m)++;
	}
}
void pb3b()
{
	printf("pb3b\n");
	int n, i = 0, m = 0, cap=3;
	char **v, **w;
	int *u;
	w = malloc(100 * sizeof(char)); 
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		{
		*(w + i) = malloc(19 * sizeof(char));
		scanf("%s", w[i]);
		}
		v = malloc(cap * sizeof(char));
	u = calloc(cap, sizeof(int));
	for(i = 0; i < n; i++)
	{
		vectorib(v, u, w[i], &m, &cap);
	}
	for(i = 0; i < m; i++)
	{
		printf("%s %d", v[i], u[i]);
		printf("\n");
	}
	for(i=0;i<m;i++)
		{
		free(v[i]);
		free(w[i]);
		}
	free(u);
	free(v);
}
void pb3()
{
	printf("pb3\n");
	int n;
	printf("Da-mi varianta de rezolvare: ");
	scanf("%d", &n);
	switch(n)
	{
		case 1: pb3a(); break;
		case 2: pb3b(); break;
		default: printf("Nu s-a gasit aceasta varianta!\n"); break;
	}
}
void pb4()
{
	printf("pb4\n");
	
}
void pb5()
{
	printf("pb5\n");
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
		default: printf("Nu s-a gasit problema!\n");break;
	}
	return 0;
}