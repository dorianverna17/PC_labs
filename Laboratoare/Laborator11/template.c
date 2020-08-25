#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

#define BUFMAX 1005

void pb1(int argc, char **argv)
{
	printf("pb1\n");
	FILE * pFile;
	char buffer [BUFMAX];
 	pFile = fopen("myfile.txt" , "r");
	if (pFile == NULL)
      fprintf(stderr, "Eroare! Nu am putut deschide fisierul!");
	else
	{
			while (fgets(buffer, BUFMAX, pFile) != NULL)
			{
            	fputs (buffer, stdout);
            }
        fclose (pFile);
    }
}
int pb2(int argc, char **argv)
{
	printf("pb2\n");
	FILE *dest, *src;
	int i;
	char buffer[BUFMAX];
	dest = fopen(argv[1], "w");
	if (!dest)
	{
		fprintf(stderr, "Eroare! Nu am putut deschide fisierul destinatie!\n");
		return 0;
	}
	for (i = 2; i < argc; ++i) 
	{
		src = fopen(argv[i], "r");
    	if (!src)
    	{
        	fprintf(stderr, "Eroare! Nu am putut deschide fisierul sursa (%d)!\n", i);
        	return 0;
    	}
 		while (fgets(buffer, BUFMAX, src) != NULL)
        fputs(buffer, dest);
    	fclose(src);
   	}
	fclose(dest);
}
int pb3A(int argc, char **argv)
{
	printf("pb3A\n");
	FILE *fp;
	char buffer[BUFMAX];
	fp = fopen(argv[1], "r");
	if(!fp)
	{
		fprintf(stderr, "Eroare! Nu am putut deschide fisierul sursa!\n");
		return 1;
	}
	while(fgets(buffer, BUFMAX, fp) != NULL)
	{
		if(strstr(buffer, argv[2]) != NULL)
			printf("%s", buffer);
	}
	fclose(fp);
}
int pb3B(int argc, char **argv)
{
	printf("pb3B\n");
	FILE *file;
	char buffer[BUFMAX];
	char aux[BUFMAX];
	file = fopen(argv[argc - 2], "r");
	int nr = 0, i, S = 0;
	int ok1 = 0, ok2 = 0, ok3 = 0;
	if(!file)
	{
		fprintf(stderr, "Eroare! Nu am putut deschide fisierul sursa!\n");
		return 1;
	}
	while(fgets(buffer, BUFMAX, file) != NULL)
	{
		nr++;
		for(i = 1; i < argc - 2; i++)
		{
			if(strcmp(argv[i], "-i") == 0) ok1 = 1;
			if(strcmp(argv[i], "-n") == 0) ok2 = 1;
			if(strcmp(argv[i], "-c") == 0) ok3 = 1;
		}
		strcpy(aux, buffer);
		if(ok1 == 1)
			for(i = 0; i < strlen(aux); i++)
				if(aux[i] >= 'A' && aux[i] <= 'Z')
					aux[i] += 32;
		if(strstr(aux, argv[argc - 1]) != NULL)
		{
			S++;
			if(ok2 == 1)
				printf("[%d] %s", nr, buffer);
			else
				printf("%s", buffer);
		}
	}
	if(ok3 == 1)
	printf("Numar total de linii: %d\n", S);
	fclose(file);	
}
int pb4(int argc, char **argv)
{
	printf("pb4\n");
	FILE *file1, *file2, *file3;
	file1 = fopen(argv[1], "r");
	file2 = fopen(argv[2], "r");
	file3 = fopen(argv[3], "a");
	if(file1 == NULL || file2 == NULL || file3 == NULL)
	{
		printf("Nu s-a putut deschide unul dintre fisiere\n");
		return 1;
	}
	else
	{
		char s1[BUFMAX], s2[BUFMAX];
		strcpy(s1, "");
		strcpy(s2, "");
		int i, j;
		char cod[BUFMAX], line[BUFMAX];
		while(fgets(cod, BUFMAX, file1) != NULL)
			{
			strncat(s1, cod, 1);
			strncat(s2, cod + strlen(cod) - 2, 1);
			}
		while(fgets(line, BUFMAX, file2) != NULL)
			{
				for(i = 0; i < strlen(line); i++)
				{
					for(j = 0; j < strlen(s1); j++)
						{
						if(line[i] == s1[j])
							{
							line[i] = s2[j];
							break;
							}
						if(line[i] + 32 == s1[j])
							{
							line[i] = s2[j] - 32;
							break;
							}
						}
				}
				fprintf(file3, "%s", line);
			}
	}
	fclose(file1);
	fclose(file2);
	fclose(file3);
}
int main(int argc, char **argv)
{
	int n;
	printf("Da-mi numarul problemei: ");
	scanf("%d", &n);
	switch(n)
	{
		case 1: pb1(argc, argv); break;
		case 2: pb2(argc, argv); break;
		case 3: pb3A(argc, argv); break;
		case 4: pb3B(argc, argv); break;
		case 5: pb4(argc, argv); break;
		default: printf("Nu s-a gasit problema!\n"); break;
	}
	return 0;
}