#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
	float suprafata;
	int nr_locatari;
} Apartament;

typedef struct {
	char *nume;
	char *adresa;
	int nr_apart;
	Apartament *apart;
} Bloc;

void afisare(Bloc b) {
	printf("%s\n", b.nume);
	printf("%s\n", b.adresa);
	printf("%d\n", b.nr_apart);

	int i = 0;
	for(i = 0; i < b.nr_apart; i++) {
		printf("%f %c\n", b.apart[i].suprafata, b.apart[i].nr_locatari);
	}
}

void citire(Bloc *b, char *nume_fisier) {
	FILE *f;
	int i;

	f = fopen(nume_fisier, "rb");
	int nr_car_nume, nr_car_adresa;

	fread(&nr_car_nume, sizeof(int), 1, f);
	b->nume = (char*) malloc((nr_car_nume + 1) * sizeof(char));
	for(i = 0; i < nr_car_nume; i++) {
		fread(&(b->nume[i]), sizeof(char), 1, f);
	}
	b->nume[nr_car_nume] = '\0';

	fread(&nr_car_adresa, sizeof(int), 1, f);
	b->apart = (Apartament *) malloc(b->nr_apart * sizeof(Apartament));
	for(i = 0; i < b->nr_apart; i++) {
		fread((*b).apart + i, sizeof(Apartament), 1, f);
	}
	fclose(f);
}

void sortare(Bloc *b, int (*cmp)(const void*, const void*)) {
	qsort(b->apart, b->nr_apart, sizeof(Apartament), cmp);
}

int cmp(const void *a1, const void *a2) {
	Apartament *ap1, *ap2;
	ap1 = (Apartament *) a1;
	ap2 = (Apartament *) a2;

	if ((ap1->nr_locatari) != (ap2->nr_locatari)) {
		return (ap2->nr_locatari) - (ap1->nr_locatari);
	} else {
		return (ap1->suprafata) - (ap2->suprafata);
	}
}

int main() {
	
	return 0;
}