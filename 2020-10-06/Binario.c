/*
Scrivere un programma in C che chiede all'utente un numero intero 
positivo minore di 1024. Il programma converte in binario naturale 
su 10 bit il valore acquisito mediante il metodo dei resti e 
visualizza il risultato.
*/

#include <stdio.h>
#define DIM 10

int main(){
    int dec, bin[DIM], i, a;
    scanf("%d", &dec);
    
    for(i = 0; dec > 0; i++){
        bin[i] = dec % 2;
        dec /= 2;
	   }

    for(a = i; a > DIM; a--){
        printf("%d\n", bin[i]);.1,
	   }
	   
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