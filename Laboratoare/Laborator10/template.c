#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

double integrala(double (*func) (double x), double a, double b, int n)
{
	double i, S = 0, pas = (double) (b - a) / n;
	for(i = a; i < b; i = i + pas)
	{
		S = S + (double) ((func(i + pas) + func(i)) * pas) / 2;
	}
	return S;
}
void pb1()
{
	printf("pb1\n");
	double a, b;
	int n;
	scanf("%lf%lf", &a, &b);
	scanf("%d", &n);
	printf("%f\n", integrala(sin, a, b, n));
	printf("%f\n", integrala(cos, a, b, n));
}
struct multime{
	unsigned char a;
};
void init(struct multime *m) // iniţializează mulţimea m cu mulţimea vidă
{
	m->a = 0;
}
int contains(struct multime *m, int x)
{
	unsigned char mask = 1;
	mask = mask << x;
	if(mask & (m->a)) return 1;
	else return 0;
}
void add(struct multime *m, int x) // adaugă pe x la mulţimea m
{
	unsigned char mask = 1;
	mask = mask << x;
	m->a = m->a | mask;
}
void del(struct multime *m, int x) // şterge pe x din mulţimea m
{
	unsigned char mask;
	mask = ~(1 << x);
	m->a = m->a & mask;
}
void print(struct multime *m) // afişează mulţimea m
{
	unsigned char mask;
	int i;
	for(i = 0; i <= 7; i++)
	{
		if(contains(m,i))
			printf("%d ", i);
	}
	printf("\n");
}

void pb2A()
{
	printf("pb2A\n");
	struct multime m;
	init(&m);
	add(&m, 2);
	add(&m, 5);
	add(&m, 6);
	print(&m);
	del(&m, 6);
	print(&m);
}
typedef struct {
	unsigned int n;
	unsigned char *a;
} Multime;
void initI(Multime *m, int x)
{
	int i;
	for(i = 0; i <= x / 8 + 1; i++)
		*(m->a + i) = 0;
}

void printI(Multime *m, int x)
{
	unsigned char mask;
	int i, j;
	for(i = 0; i < x / 8 + 1; i++)
	{
		for(j = 0; j < 8; j++)
		{
		mask = 1;
		mask = mask << j;
		if((mask & *(m->a + i)) > 0)
			printf("%d ", 8 * i + j);
		}
	}
	printf("\n");
}
void addI(Multime *m, int p)
{
	unsigned char mask;
	int i;
	i = p / 8;
	mask = 1;
	mask = mask << (p - i * 8);
	m->a[i] = (m->a[i] | mask);
}
void delI(Multime *m, int p)
{
	unsigned char mask;
	int i;
	i = p / 8;
	mask = 1;
	mask = mask << (p - i * 8);
	mask = ~mask;
	m->a[i] = (m->a[i] & mask);
}
int containsI(Multime *m, int p)
{
	unsigned char mask;
	int i;
	i = p / 8;
	mask = 1;
	mask = mask << (p - i * 8);
	if((m->a[i] & mask) > 0)
		return 1;
	return 0;
}
void pb2B()
{
	printf("pb2B\n");
	Multime m;
	int x;
	if(scanf("%d", &x) != 0)
	{
		m.n = x;
		m.a = malloc((x / 8 + 1) * sizeof(unsigned char));
		initI(&m, x);
		FILE* file;
		file = fopen("lab-10-01.in", "r");
		if(!file)
			printf("Nu se poate deschide fisierul\n");
		else
		{
			char string[10], aux[10];
			int i, n, p;
			while(fgets(string,9,file) != NULL)
			{
				strcpy(aux, "");
				n = 0;
				for(i = 2; i < strlen(string); i++)
					if(string[i] >= '0' && string[i] <= '9')
						n++;
				strncat(aux, string + 2, n);
				if(string[0] == 'P')
				{
					printI(&m, x); 
				}
				else
				{
					p = atoi(aux);
					if(string[0] == 'A')
					{
						addI(&m, p);
					}
					else if(string[0]=='D')
						{
							delI(&m, p);
						}
						else if(string[0]=='C')
							{
							if(containsI(&m, p))
								printf("Da");
							else printf("Nu");
							printf("\n");
							}
				}		
			}
			fclose(file);
		}
	}
	else
		printf("Nu s-a dat un numar care sa convina\n");
}

void pb2()
{
	printf("pb2\n");
	int n;
	printf("A (1) sau B (2)?\n");
	scanf("%d", &n);
	switch(n)
	{
		case 1:
			pb2A();
			break;
		case 2:
			pb2B();
			break;
		default:
			printf("Eroare!!!\n");
			break;
	}
}
typedef struct MATERIA {
	char nume[15];
	int ore_curs;
//	enum tip_examen{'C', 'S', 'A'} tip_examen;
} MATERIA;
void pb3()
{
	printf("pb3\n");
}
typedef struct MATRICE {
	int n, m;
	int **a;
} MATRICE;
// creează o matrice de dimensiuni n x m. Funcţia va aloca
// memorie pentru o nouă variabilă de tip MATRICE şi pentru
// tabloul conţinut în această structură (referit prin membrul
// a). Funcţia va returna adresa noii variabile de tip MATRICE create.
MATRICE* creeaza_MATRICE(int x, int y)
{
	MATRICE* A;
	A = malloc( 1 * sizeof(MATRICE));
	A->n = x;
	A->m = y;
	A->a = malloc(x * sizeof(int));
	int i;
	for(i = 0; i < x; i++)
	(A->a[i]) = calloc(y, sizeof(int));
	return A;
}
// citeşte de la tastatură o matrice. Dimensiunile se regăsesc în
// cadrul matricei transmise ca parametru, urmând a se citi de la
// tastatură doar elementele tabloului. Funcţia va returna tot adresa ma.
MATRICE* citeste_MATRICE(MATRICE* ma)
{
	int i, j;
	for(i = 0; i < ma->n; i++)
		for(j = 0; j < ma->m; j++)
			scanf("%d", (ma->a[i] + j));
	return ma;
}
// afiseaza pe ecran matricea transmisă ca parametru.
void scrie_MATRICE(MATRICE* ma)
{
	int i, j;
	printf("Matricea este:\n");
	for(i = 0; i < ma->n; i++)
		{
		for(j = 0; j < ma->m; j++)
			printf("%d ", *(ma->a[i] + j));	
		printf("\n");
		}
}
// dacă matricile ma şi mb au aceleaşi dimensiuni, atunci funcţia
// returnează adresa unei noi matrici care va conţine suma matricelor ma
// şi mb. În caz contrar, funcţia va returna NULL (adunarea nu se poate
// face, deci rezultatul nu există).
MATRICE* aduna_MATRICE(MATRICE* ma, MATRICE* mb)
{
	MATRICE* A = creeaza_MATRICE(ma->n, ma->m);
	if(ma->m != mb->m && ma->n != mb->n)
		return NULL;
	int i,j;
	for(i = 0; i < ma->n; i++)
		for(j = 0; j < ma->m; j++)
			A->a[i][j] = ma->a[i][j] + mb->a[i][j];
	return A;
}
// dacă matricile ma şi mb se pot înmulţi, atunci funcţia returnează
// adresa unei noi matrici care va conţine produsul matricelor ma şi
// mb. În caz contrar, funcţia va returna NULL (înmulţirea nu se poate
// face, deci rezultatul nu există).
MATRICE* inmulteste_MATRICE(MATRICE* ma, MATRICE* mb)
{
	MATRICE* A = creeaza_MATRICE(ma->n, mb->m);
	int i, j, k, l, S;
	if(ma->m != mb->n)
		return NULL;
	for(i = 0; i < ma->n; i++)
	{
		for(k = 0; k < mb->m; k++)
			{
			S = 0;
			for(j = 0; j < ma->m; j++)
					S = S + ma->a[i][j] * mb->a[j][k];
			A->a[i][k] = S;
			}
	}
	return A;
}
void pb4()
{
	printf("pb4\n");
	int n, m;
	scanf("%d%d", &n, &m);
	MATRICE *A = creeaza_MATRICE(n, m);
	citeste_MATRICE(A);
	scrie_MATRICE(A);
	printf("\n");
	MATRICE *B = creeaza_MATRICE(n, m);
	citeste_MATRICE(B);
	scrie_MATRICE(B);
	printf("\n");
	MATRICE* C = aduna_MATRICE(A, B);
	MATRICE* D = inmulteste_MATRICE(A, B);
	if(C != NULL)
		scrie_MATRICE(C);
	else
		printf("EROARE!!!\n");
	if(D != NULL)
		scrie_MATRICE(D);
	else
		printf("EROARE!!!\n");
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
		default: printf("Nu s-a gasit problema!\n");break;
	}
	return 0;
}