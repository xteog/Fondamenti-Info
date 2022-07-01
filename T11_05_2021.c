/***********************************************************************
 * 
 * FONDAMENTI DI INFORMATICA
 * =========================
 * 
 *
 * Prova dell'11/5/2021
 * --------------------
 *
 * NOME:
 * COGNOME:
 * MATRICOLA:
 *
 ***********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_RIGHE 80


typedef struct biga
{
	int tempo;
	char stazione;
	int bicicletta;
	int azione;
} t_biga;

t_biga* leggifile(char* nomefile, int* len)
{
	t_biga *bike, ciao;
	int i;
	char action[MAX_RIGHE + 1];

	FILE *f;
	f=fopen(nomefile,"r");
	if(f==NULL)
		exit(1);


	for(i=0; feof(f)==0; i++)
	{
		fscanf(f,"%d %c %d %s\n", &ciao.tempo, &ciao.stazione, &ciao.bicicletta, action);
	}
	
	bike= malloc(sizeof(t_biga) * i);

	if(bike==NULL)
	{
		printf("Errore di allocazione\n");
		fclose(f);
		exit(1);
	}
	
	rewind(f);
	
	for(i=0; feof(f)==0; i++)
	{
		fscanf(f,"%d %c %d %s\n", &bike[i].tempo, &bike[i].stazione, &bike[i].bicicletta, action);
		if(strcmp(action,"PICK")==0)
			bike[i].azione=1;
		else if (strcmp(action,"DROP")==0)
			bike[i].azione=0;
	}
	*len=i;
	fclose(f);
	return bike;
}


void complessivi(t_biga *bike, int len, int* cont1, int* cont2)
{
	int i;
	for(i=0; i<len; i++)
	{
		if(bike[i].azione==1)
			(*cont1)++;
		else
			(*cont2)++;
	}
}


void non_restituite(t_biga *bike, int len)
{
	int i,j,flag;
	
	for(i=0;i<len;i++)
	{
		if(bike[i].azione==1)
		{
		flag=1;
			for(j=1+i;j<len && flag==1;j++)
			{
				if(bike[i].bicicletta==bike[j].bicicletta  && bike[j].azione==0)	
					flag=0;
				
			}
			if(flag==1)
			{
				printf("%d\n",bike[i].bicicletta);
			}
		}
	}
}

int stessa_stazione(t_biga *bike, int len)
{
	int i,j,flag,cont;
	cont=0;
	for(i=0; i<len;i++)
	{
		if(bike[i].azione==1)
		{
		flag=1;
			for(j=i+1; j<len && flag==1;j++)
			{
				if(bike[i].stazione==bike[j].stazione && bike[i].bicicletta==bike[j].bicicletta && bike[j].azione==0)
				{
					cont++;
					flag=0;
				}
			}
		}
	}
	return cont;
}

int media(t_biga *bike, int len)
{
	int i,j,somma,contatore; 
	int flag;
	float media;

	contatore=0;
	somma=0;
	for(i=0; i<len;i++)
	{
		if(bike[i].azione==1)
		{
			flag=1;
			for(j=i+1; j<len && flag==1; j++)
			{
				if(bike[i].bicicletta==bike[j].bicicletta && bike[j].azione==0)
				{
					somma+=(bike[j].tempo-bike[i].tempo);
					contatore++;
					flag=0;
				}
			}
		}
	}

	if(contatore==0)
		media=0.0;
	else
		media=somma/contatore;

	return media;
}

int main(int argc, char* argv[])
{
	t_biga *bike;
	int len;
	int cont1;
	int cont2;
	cont1=0;
	cont2=0;

	
	bike=leggifile(argv[1], &len);
	
	printf("[AZIONI]\n");
	complessivi(bike, len, &cont1, &cont2);
	printf("%d\n",cont2);
	printf("%d\n",cont1);
	
	printf("[PERSE]\n");
	non_restituite(bike,len);
	
	printf("[STESSA_STAZIONE]\n");
	printf("%d\n",stessa_stazione(bike,len));
	
	printf("[INTERVALLO]\n");
	printf("%.2f\n",media(bike, len));
	
	free(bike);
	return 0;
}
