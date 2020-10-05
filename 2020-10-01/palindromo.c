/*
Un numero intero è palindromo quando le sue cifre rappresentano lo 
stesso valore sia che siano lette da destra che da sinistra. Esempi 
di numeri palindromi sono 111, 121, 13431.
Scrivere un programma in C che chiede all'utente un numero intero 
positivo. Il programma verifica se il numero è palindromo; in caso 
affermativo stampa a video 1 altrimenti 0.
*/

#include <stdio.h>
#define POW 10

int main(){
	int n, j = 1, i = 1, cond = 1;
	scanf("%d", &n);

	while(j < n / 10)
		j *= 10;
	
	while(cond && j >= 1){
		if((n / j) % POW != (n / i) % POW)
			cond = 0;
		i *= 10;
		j /= 10;
	}
	if(cond)
		printf("Palindromo\n");
	else
		printf("Non Palindromo\n");
	return 0;
}