#include <stdio.h>
#include <stdlib.h>

#include "Produs.h"
int main()
{
	FILE *f;
	Produs prod;
	f = fopen("pb2.txt", "return");
	while(fread(&prod, sizeof(Produs), 1, f) == 1)
			{
			printf("NUME: PRODUS%s\nCANTITATE: %d\nPRET: %.2f\n", prod.nume_produs, prod.cantitate, prod.pret_produs);
			printf("\n");
			}
	fclose(f);
	return 0;
}