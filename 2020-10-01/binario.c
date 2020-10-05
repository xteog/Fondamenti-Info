/*
Scrivere un programma in C che chiede all'utente un numero intero
positivo. Il programma converte il numero in binario naturale
mediante il metodo dei resti mostrando il risultato dall'ultima
cifra alla prima.
*/

#include <stdio.h>

int main(){
	int dec, bin = 0, i = 1;
	scanf("%d", &dec);

	while(dec > 0){
		bin = bin + (dec % 2) * i;
		dec /= 2;
		i *= 10;
	}
	printf("%d\n", bin);

	return 0;
}

/*
44 | 0
22 | 0
11 | 1
5  | 1
2  | 0
1  | 1
0  |
*/