#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

typedef struct Punct {
   float x, y;
} Punct;

typedef struct vector {
	int *v;
	int cap;
	int n;	
} vector;

typedef struct complex {
	float re, im;
} complex;

typedef struct Pereche {
	char *cuv;
	int nr_ap;
} Pereche;

void pb1()
{
	printf("pb1\n");
	Punct p;
	printf("Introduceti x: ");
	scanf("%f", &p.x);
	printf("Introduceti y: ");
	scanf("%f", &p.y);
	printf("(%.2f,%.2f)\n", p.x, p.y);
}
void pb2()
{
	printf("pb2\n");
	time_t t;
	struct tm *area;
	t = time(NULL);
	area = localtime(&t);
	printf("Local time is: %s", asctime(area));
}
char* timestr(struct tm t, char* time)
{
	sprintf(time, "%d:%d:%d", t.tm_hour, t.tm_min, t.tm_sec);
	return time;
}
void pb3()
{
	printf("pb3\n");
	time_t t;
	char s[200];
	struct tm *area;
	t = time(NULL);
	area = localtime(&t);
	printf("%s\n", timestr(*area, s));
}
void init_vector(vector *a, int nr)
{
	(*a).v = malloc(nr * sizeof(int));
}
void adauga_vector(vector *a, int x)
{
	int i;
	for(i = 0; i < x; i++)
	{
		if(i >= (*a).cap)
		{
			(*a).cap = (*a).cap + 3;
			(*a).v = realloc((*a).v, (*a).cap * sizeof(int));
		}
		scanf("%d", &((*a).v[i]));
	}
}
void scrie_vector(vector a)
{
	int i;
	for(i = 0; i < a.n; i++)
	{
		printf("%d ", a.v[i]);
	}
	printf("\n");
}
void pb4()
{
	printf("pb4\n");
	vector a;
	scanf("%d%d",&(a.cap),&(a.n));
	init_vector(&a, a.cap);
	adauga_vector(&a, a.n);
	scrie_vector(a);
}
complex adunare(complex a, complex b)
{
	a.re = a.re + b.re;
	a.im = a.im + b.im;
	return a;
}
complex inmultire(complex a, complex b)
{
	float x = a.re, y = a.im;
	a.re = x * b.re - y * b.im;
	a.im = y * b.re + x * b.im;
	return a;
}
complex inmul_coef(float c, complex a)
{
	a.re = c * a.re;
	a.im = c * a.im;
	return a;
}
complex putere(complex a, int putere)
{
	if(putere == 0)
	{
		a.re = 1;
		a.im = 0;
		return a;
	}
	complex aux;
	aux = a;
	int i;
	for(i = 1; i < putere; i++)
	{
		a = inmultire(a, aux);
	}
	return a;
}
void scrie_complex(complex a)
{
	printf("(%.2f, %.2f)\n", a.re, a.im);
}
void pb5()
{
	printf("pb5\n");
	complex numar, S;
	complex final;
	int n, i;
	float *c;
	scanf("%f%f", &(numar.re), &(numar.im));
	scanf("%d", &n);
	c = malloc((n + 1) * sizeof(float));
	for(i = 0; i <= n; i++)
		scanf("%f", &c[i]);
	S.re = 0;
	S.im = 0;
	final.re = 0;
	final.im = 0;
	for(i = 0; i <= n; i++)
	{
		S = adunare(S, inmul_coef(c[i], putere(numar, i)));
	}
	scrie_complex(S);
	free(c);
}
void pb6a()
{
	char aux[100], **cuvinte;
	int *v;
	int n = 0, i, cap = 3, ok;
	cuvinte = malloc(cap * sizeof(char));
	v = calloc(cap, sizeof(int));
	scanf("%s", aux);
	if(strcmp(aux, "exit") != 0)
	{
		while(strcmp(aux, "exit") != 0)
		{
			ok = 0;
			for(i = 0; i < n; i++)
			{
				if(strcmp(aux, cuvinte[i]) == 0)
				{
					v[i]++;
					ok = 1;
				}
			}
			if(ok == 0)
				{
					if(n >= cap)
					{
						cap = cap + 3;
						cuvinte = realloc(cuvinte, cap * sizeof(char));
						v = realloc(v, cap * sizeof(int));
					}
					cuvinte[n] = malloc((strlen(aux) + 1) * sizeof(char));
					strcpy(cuvinte[n], aux);
					v[n]++;
					n++;
				}
			scanf("%s", aux);
		}
		for(i = 0; i < n; i++)
		{
			printf("%s %d\n", cuvinte[i], v[i]);
		}
	}
	else 
		printf("Nu s-au dat cuvinte\n");
	for(i = 0; i < n; i++)
		free(cuvinte[i]);
	free(v);
	free(cuvinte);
}
void pb6b()
{
	Pereche *pair;
	int cap = 3, n = 0, i, ok;
	pair = malloc(cap * sizeof(Pereche));
	char aux[200];
	scanf("%s", aux);
	if(strcmp(aux, "exit") == 0)
		printf("Nu s-au dat cuvinte\n");
	else
	{
		while(strcmp(aux, "exit") != 0)
		{
			ok = 0;
			for(i = 0; i < n; i++)
			{
				if(strcmp(aux, pair[i].cuv) == 0)
					{
					pair[i].nr_ap++;
					ok = 1;
					}
			}
			if(ok == 0)
			{
				if(n >= cap)
				{
					cap += 3;
					pair = realloc(pair, cap * sizeof(Pereche));
				}
				pair[n].cuv = malloc((strlen(aux) + 1) * sizeof(char));
				strcpy(pair[n].cuv, aux);
				pair[n].nr_ap = 1;
				n++;
			}
			scanf("%s", aux);
		}
		for(i = 0; i < n; i++)
			printf("%s %d\n", pair[i].cuv, pair[i].nr_ap);
	}
}
void pb6()
{
	printf("pb6\n");
	int n;
	printf("Alege rezolvarea: ");
	scanf("%d", &n);
	switch(n)
	{
		case 1: pb6a(); break;
		case 2: pb6b(); break;
		default: break;
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
		default: printf("Nu s-a gasit problema!\n");break;
	}
	return 0;
}