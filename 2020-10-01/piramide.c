/*
Scrivere un programma che riceve in ingresso un numero positivo pari n;
il programma continuerà a richiedere il numero n finché la condizione
non sarà soddisfatta.  In seguito, il programma disegna a video un
triangolo con base n utilizzando il carattere * come mostrato nel
seguente esempio.
Esempio: Sia n=10, il disegno da mostrare è    
    **
   ****
  ******
 ********
********** 
*/

#include <stdio.h>

int main(){
	int n, i, j = 0;
	scanf("%d", &n);

	if(n % 2 == 0)
		i = 2;
	else
		i = 1;

	while(i <= n){
		while(j < n - i / 2){
			printf(" ");
			j++;
		}
		j = 0;
		while(j < i){
			printf("*");
			j++;
		}
		j = 0;
		i += 2;
		printf("\n");
	}

	return 0;
}

/*
i = 1 se dispari, i= 2 se pari

1 riga, n = 10 
=> i+=2 => 2 '*'
=> n - i = 8 ' '

2 riga, n = 10 
=> i+=2 => 4 '*'
=> n - i = 6 ' '

3 riga, n = 10 
=> i+=2 => 6 '*'
=> n - i = 4 ' '
*/