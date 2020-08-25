#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#include "Produs.h"

void creare_fisier(char *nume_fisier)
{
	FILE *pb2;
	pb2 = fopen(nume_fisier,"wb");
	if( pb2 == NULL)
		printf("EROARE!\n");
	else
	{
	int i;
	time_t seed;
	seed = time(NULL);
	srand(seed);
	for(i = 0;i < 100; i++)
	{
	Produs prod;
	long X = rand();
	char p[200];
	sprintf(p,"%ld",X);
	strcpy(prod.nume_produs,p);
	prod.cantitate = X % 100;
	if(X <= 100)
	prod.pret_produs = X;
	else
	prod.pret_produs = X % 100;
	fwrite(&prod, sizeof(Produs), 1, pb2); 
	}
	fclose(pb2);
	}
}
void afisare_pb3(char *nume_fisier)
{
	FILE *pb2;
	pb2 = fopen(nume_fisier,"rb");
	if(pb2 == NULL)
		printf("EROARE!\n");
	else
	{
		Produs prod;
		while(fread(&prod, sizeof(Produs), 1, pb2) == 1)
			{
			printf("NUME: PRODUS%s\nCANTITATE: %d\nPRET: %.2f\n", prod.nume_produs, prod.cantitate, prod.pret_produs);
			printf("\n");
			}
		fclose(pb2);
	}
}
void bublesort(Produs v[])
{
	int i, schimb;
	Produs aux;
	do{
		schimb = 0;
		for(i = 0; i < 100; i++)
			if(v[i].cantitate > v[i+1].cantitate)
			{
				aux = v[i];
				v[i] = v[i+1];
				v[i+1] = aux;
				schimb =1;
			}
	}while(schimb == 1);
}

void citire_vector(char *nume_fisier, Produs v[])
{
	FILE *pb2;
	char s[20];
	Produs prod;
	pb2 = fopen(nume_fisier,"rb");
	if(pb2 == NULL)
		printf("EROARE!\n");
	else
	{
	int i = 0;
	while(i < 100)
	{
	while(fread(&v[i] , sizeof(Produs), 1, pb2) == 1)
	i++;
	}
	fclose(pb2);
	}
}
void afisare_pb4(char *nume_fisier, Produs v[])
{
	FILE *pb2;
	pb2 = fopen(nume_fisier, "wb");
	if(pb2 == NULL)
		printf("EROARE!\n");
	else
	{
		int i = 0;
		while(i < 100)
		{
		fwrite(&v[i], sizeof(Produs), 1, pb2);	
		i++;
		}
	fclose(pb2);
	}
}
void cautare(char *nume_fisier, Produs v[])
{
 	FILE *pb2;
 	Produs prod;
 	char s[100];
 	scanf("%s", s);
 	pb2 = fopen("pb2.txt","rb");
 	if(pb2 == NULL)
 		printf("EROARE!\n");
 	else
 	{
 		int i = 0, ok = 0;
 		while(i < 100)
 		{
 			fread(&prod, sizeof(Produs), 1, pb2);	
 			if(6 <= strlen(s))
 			if(strcmp(s + 6, prod.nume_produs) == 0)
 				ok = 1;
 			i++;
 		}
 		if(ok == 1)
 			printf("NUME: PRODUS%s\nCANTITATE: %d\nPRET: %.2f\n", prod.nume_produs, prod.cantitate, prod.pret_produs);
 		else 
 			printf("Nu s-a gasit acest produs\n");
 	fclose(pb2);
 	}
}
int cautare_pb6(char * nume_fisier)
{
	FILE *file;
	Produs prod;
	char str[100];
	scanf("%s", str);
	getchar(); //Intreaba-l pe Razvan la asta
	long pos;
	int ok = 0;
	file = fopen(nume_fisier, "r+");
	if(file == NULL)
		{
			printf("Fisierul nu a putut fi deschis\n");
			return 1;
		}
		else
		{
		while(fread(&prod, sizeof(Produs), 1, file) == 1)
			{
				if(6 <= strlen(str))
				if(strcmp(str + 6, prod.nume_produs) == 0)
				{
					ok = 1;
					printf("NUME: PRODUS%s\nCANTITATE: %d\nPRET: %.2f\n", prod.nume_produs, prod.cantitate, prod.pret_produs);
					pos = ftell(file) - sizeof(Produs);
					fseek(file, pos, 0);
					scanf("%s", prod.nume_produs);
					getchar();//si pe asta
					scanf("%d%f", &prod.cantitate, &prod.pret_produs);
					fwrite(&prod, sizeof(Produs), 1, file);
				}
			}
			if(ok == 0)
					printf("Nu a fost gasit acest produs!!\n\n");
			fclose(file);
		}
}
int main(int argc, char **argv)
{
	//pb1
	Produs prod;
	//pb2
	char nume_fisier[] = "pb2.txt";
	creare_fisier(nume_fisier);
	//pb3
	afisare_pb3(nume_fisier);
	//pb4
	Produs v[100];
	citire_vector(nume_fisier, v);
	bublesort(v);
	afisare_pb4(nume_fisier, v);
	afisare_pb3(nume_fisier);
	//pb5
	//char s[100];
	//scanf("%s", s);
	// Boss deci de ce nu pot sa declar aici, si doar in functia de cautare
	//imi creeaza un fisiere random binar
	//Nu merege declarat in main
	//Intreab-o pe ODUBASTEANU SA VEZI CAT DE TARE E!!!!
	cautare(nume_fisier, v);
	//pb6
	cautare_pb6(nume_fisier);
	afisare_pb3(nume_fisier);
	return 0;	
}