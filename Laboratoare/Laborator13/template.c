#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_VALUE 200

// Problema 1 - qsort
// void qsort ( void * base, size_t num, size_t size, int ( * comparator ) ( const void *, const void * ) );

int cmp(const void * a, const void *b)
{
	return (*(int*)a - *(int*)b);
	//return value
	//<0	The element pointed to by a goes before the element pointed to by b
	//0	The element pointed to by a is equivalent to the element pointed to by b
	//>0	The element pointed to by a goes after the element pointed to by b
}
void pb1()
{
	printf("pb1\n");
	int N, i;
	int *v;
	printf("Introduceti dimensiunea vectorului:\n");
	scanf("%d", &N);
	v = calloc(N, sizeof(int));
	if (!v) printf("Nu am putut aloca memorie pentru v!\n");
	srand(time(NULL));
	for (i = 0; i < N; ++i)
    	v[i] = (rand() % MAX_VALUE)+1;
	for (i = 0; i < N; ++i)
    	printf("%d ", *(v+i));
	printf("\n");
	qsort(v, N, sizeof(int), cmp);
	for (i = 0; i < N; ++i)
    	printf("%d ", *(v+i));
	printf("\n");
	free(v);
}

// Problema 2 - bsearch
// void *bsearch ( const void * key, void * base, size_t num, size_t size, int ( * comparator ) ( const void *, const void * ) )

void pb2()
{
	printf("pb2\n");
		printf("pb1\n");
	int N, i;
	int *v;
	printf("Introduceti dimensiunea vectorului:\n");
	scanf("%d", &N);
	v = calloc(N, sizeof(int));
	if (!v) printf("Nu am putut aloca memorie pentru v!\n");
	srand(time(NULL));
	for (i = 0; i < N; ++i)
    	v[i] = (rand() % MAX_VALUE)+1;
	for (i = 0; i < N; ++i)
    	printf("%d ", *(v+i));
	printf("\n");
	qsort(v, N, sizeof(int), cmp);
	for (i = 0; i < N; ++i)
    	printf("%d ", *(v+i));
	printf("\n");
	int x;
	printf("Numarul pe care vrei sa il gasesti: \n");
	scanf("%d", &x);
	int *s = bsearch(&x, v, N, sizeof(int), cmp);
	// bsearch returns an adress
	// you have to put that adress in a variable
	// bsearch returns NULL if that element is not found

	// in order to be found an element, the compare function must return 0
	if(s != NULL)
	{
		printf("Numarul %d este pe pozitia %ld\n", *s, s - v + 1);
	}
	else
		printf("Nu a fost gasit numarul in vector\n");
	free(v);
}

// Problema 3

typedef struct entry {
	void * key;
	void * value;
} entry;

typedef struct map {
	entry ** elem; // vectorul de elemente; este alocat si realocat dinamic
	int n_elem; // numarul de elemente din vector
	int cap; // capacitatea vectorului
} map;

//  Funcţia ce compară între ele 2 structuri entry* ţinând cont de faptul că în acest caz particular
// cheia va fi char *. Funcţia de comparare nu trebuie să ţină cont şi de valorile asociate.
int compareEntry( const void *, const void *); 

// Funcţie ce compară 2 chei (în cazul de faţă, 2 şiruri de caractere). Funcţia va apela _strcmp_.
int compareKey( const void *, const void *); 

// Funcţie ce afişează cheia şi valoarea asociată pe cazul particular când sunt şiruri de caractere.
void printEntry( const entry *); 

// aloca initial memorie pentru cap elemente de tip entry*
void init(map *m, int cap);

// adauga la vectorul de elemente din m noua intrare (pointerul primit) si eventual
// realoca pe m->elem OBS: se considera ca nu se adauga chei duplicate!
void add(map *m, entry *e);

// afiseaza pe m folosind functia pentru afisarea unui entry primita ca parametru
void print(map *m, void ( *printEntry) ( const entry *) );

// sorteaza elementele din m folosind functia primita ca parametru si functia de biblioteca qsort.
// Observatie: fc va trebui sa compare între ele 2 structuri entry* (se va face conversie la
// entry ** in functia de comparatie!! DE CE?)
void sort(map *m, int ( * fc ) ( const void *, const void * ) ); 

// sterge intrarea corespunzatoare cheii k din m. Atentie! Nu veti compara pointerii pentru a
// testa daca 2 elemente sunt egale, ci veti folosi functia primita ca parametru, ce se considera
// ca întoarce 0 pentru elemente egale. Observatie: fc2 va trebui sa compare între ele 2 chei (void *).
void del(map *m, void *k, int ( * fc2 ) ( const void *, const void * )); 

// functie ce întoarce valoarea asociata unei chei. Se va folosi functia bsearch! Observatie:
// fc va trebui sa compare între ele 2 structuri entry* (se va face conversie la entry ** in
// functia de comparatie!! DE CE?). Vectorul tb sortat in prealabil! Dar, atentie el nu tb sa
// iasa modificat, se va lucra pe o copie a lui!
void *find(map *m, void *k, int ( * fc ) ( const void *, const void * )); 

void init(map *m, int cap)
{
	((*m).elem) = malloc(cap * sizeof(entry)); 
}

void printEntry( const entry *)
{

}

void pb3()
{
	printf("pb3\n");
	int n, ok;
	int cap = 3;
	map m;
	init(&m, cap);
	printf("1 - Afisare dictionar\n");
	printf("2 - Cauta cuvant in dictionar\n");
	printf("3 - Adauga cuvant in dictionar\n");
	printf("4 - Sterge cuvant din dictionar\n");
	printf("5 - Sortare dictionar\n");
	printf("0 - Iesire din program\n");
	printf("Alege o optiune: \n");
	scanf("%d", &n);
	do{
		ok = 0;
		switch(n)
		{
			case 1:
				print(&m, printEntry); 
				break;
			case 2: break;
			case 3: break;
			case 4: break;
			case 5: break;
			case 0:
				ok = 1;
				break;
			default: printf("Aceasta nu este o optiune\n"); break;
		}
	}while(ok == 0);
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
		default: printf("Nu s-a gasit problema!\n");break;
	}
	return 0;
}