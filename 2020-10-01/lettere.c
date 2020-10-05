/*
Scrivere un programma in C che acquisisce uno alla volta una serie
di caratteri minuscoli (cioè "carattere INVIO, carattere INVIO") 
appartenenti all'alfabeto inglese; per ogni carattere acquisito il 
programma visualizza il carattere successivo (o più in generale N 
posizioni dopo con N=1); per esempio se l'utente inserisce una 'z' 
il programma visualizza 'a'. Il programma termina quando l'utente 
inserisce un carattere non appartenente all'alfabeto inglese senza 
visualizzare alcun output.
*/

#include <stdio.h>

int main(){
	char let;
	scanf("%c", &let);
	while(let >= 'a' && let <= 'z'){
		if(let != 'z')
			printf("%c\n", let + 1);
		else
			printf("a\n");
		scanf(" %c", &let);
	}
	
	return 0;
}
