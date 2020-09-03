#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Persoana {
	char *nume;
	char *prenume;
	int varsta;
} Persoana;

void creare_fisier() {
	FILE *file = fopen("binaryfile", "wb");
	char *v[] = {"Dragos", "Dorian", "Florin"};
	char *w[] = {"Popescu", "Verna", "Ionescu"};
	int n[] = {18, 20, 32}, i;

	if (file == NULL) {
		printf("Nu s-a putut crea fisierul\n");
	} else {
		for (i = 0; i < 3; i++) {
			int a = strlen(v[i]), b = strlen(w[i]); 

			fwrite(&a, sizeof(int), 1, file);
			fwrite(v[i], sizeof(char), a, file);
			fwrite(&b, sizeof(int), 1, file);
			fwrite(w[i], sizeof(char), b, file);
			fwrite(n + i, sizeof(int), 1, file);
		}
	}
	fclose(file);
}

Persoana* creare_vector() {
	FILE *file = fopen("binaryfile", "rb");
	Persoana *vector = malloc(3 * sizeof(Persoana));
	int i, a, b;

	for (i = 0; i < 3; i++) {
		fread(&a, sizeof(int), 1, file);
		vector[i].nume = malloc((a + 1) * sizeof(char));
		fread(vector[i].nume, sizeof(char), a, file);
		fread(&b, sizeof(int), 1, file);
		vector[i].prenume = malloc((b + 1) * sizeof(char));
		fread(vector[i].prenume, sizeof(char), b, file);
		vector[i].nume[a + 1] = '\0';
		vector[i].prenume[b + 1] = '\0';
		fread(&vector[i].varsta, sizeof(int), 1, file);
	}
	fclose(file);
	return vector;
}

void afisare(Persoana *vector) {
	int i;
	for (i = 0; i < 3; i++) {
		printf("%s %s %d\n", vector[i].nume, vector[i].prenume, vector[i].varsta);
	}
}

int compare(const void *a, const void *b) {
	Persoana aux1 = *(Persoana*)a;
	Persoana aux2 = *(Persoana*)b;
	return aux1.varsta - aux2.varsta;
}

int compare1(const void *a, const void *b) {
	Persoana aux1 = *(Persoana*)a;
	Persoana aux2 = *(Persoana*)b;

	if (strcmp(aux1.prenume, aux2.prenume) == 0 && strcmp(aux1.nume, aux2.nume) == 0 &&
		aux1.varsta == aux2.varsta)
		return 0;
	return aux1.varsta - aux2.varsta;
}

int main() {
	creare_fisier();
	Persoana *vector = creare_vector();
	afisare(vector);
	qsort(vector, 3, sizeof(Persoana), compare);
	printf("\n");
	afisare(vector);

	Persoana da = {.nume = "Florin", .prenume = "Ionescu", .varsta = 32};
	Persoana *a = bsearch(&da, vector, 3, sizeof(Persoana), compare1);
	if (a != NULL)
		printf("%ld\n", a - vector);
	return 0;
}