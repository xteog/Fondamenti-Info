/***********************************************************************
 * 
 * FONDAMENTI DI INFORMATICA
 * =========================
 * 
 *
 * Prova del 30/11/2020
 * -------------------
 *
 * NOME:
 * COGNOME:
 * MATRICOLA:
 *
 ***********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>   /* Serve per poter usare la funzione sqrt */

#define MAXRIGA 80  /* limite definito nel testo */

struct posizione
{
	double spostamento_x;
	double spostamento_y;
	double spostamento_z;
};


/* Funzione che legge i dati nel file. */
struct posizione* leggi_traiettoria(char *nomefile, int *len )
{
   struct posizione *ds, ciao;
   int i;
   FILE *f;
   double spostamento_x;
   double spostamento_y;
   double spostamento_z;
  
   f = fopen(nomefile, "r");
   if (f == NULL) 
   {
      printf("Errore nell'apertura del file\n");
      exit(1);
   }
   for(i=0; feof(f)==0;i++)
   {
      fscanf(f,"%lf %lf %lf", &ciao.spostamento_x, &ciao.spostamento_y, &ciao.spostamento_z);
   }

   ds=malloc(sizeof(struct posizione)*i);
   if(ds==NULL)
   {
      printf("Errore di allocazione\n");
      fclose(f);
      exit(1);
   }
   rewind(f);
   for(i=0; feof(f)==0;i++)
   {
      fscanf(f,"%lf %lf %lf", &ds[i].spostamento_x, &ds[i].spostamento_y, &ds[i].spostamento_z);
   }
   *len=i;
   fclose(f);
   return ds;

  /* SE NECESSARIO AGGIUNGERE L'ISTRUZIONE RETURN. */
}


/* AGGIUNGERE LE FUNZIONI NECESSARIE PER RISPONDERE ALLE DOMANDE E LE
   EVENTUALI FUNZIONI DI APPOGGIO. */


/* Funzione principale. */
int main(int argc, char *argv[])
{
   struct posizione *ds;
   int len;
   if (argc != 2) {
      printf("UTILIZZO: ./programma FILE_DATI\n");
      return 1;
   }

   leggi_traiettoria(argv[1], &len);

  /* Prima domanda. */
  /* printf("[LUNGHEZZA]\n"); */

  /* Seconda domanda. */
  /* printf("[ALTEZZA]\n"); */

  /* Terza domanda. */
  /* printf("[DISTANZA]\n"); */

  /* Quarta domanda. */
  /* printf("[MASSIMA]\n"); */
   free(ds);
   return 0;
}
