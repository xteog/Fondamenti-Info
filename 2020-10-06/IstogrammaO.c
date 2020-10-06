/*
Scrivere un programma in C che legge una sequenza di numeri interi 
di lunghezza indefinita composta da elementi nell'intervallo [0;9] e 
terminata da un qualsiasi numero non incluso in tale intervallo. Il 
programma visualizza l'istogramma a barre orizzontali delle 
frequenze di ciascun numero nell'intervallo [0;9], disegnandolo 
tramite il carattere *.
*/

#include<stdio.h>
#define DIM 9

int main(){
    int arr[DIM], n, i, j;
    
    for(i = 0; i <= DIM; i++)
        arr[i] = 0;
    
    scanf("%d", &n);
    while(n > 0 && n <= 9){
        arr[n]++;
        scanf("%d", &n);
    }
    
    for(i = 0; i <= DIM; i++){
        printf("%d ", i);
        for(j = 0; arr[i] > j; j++)
            printf("#");
        printf("\n");
    }
    
    return 0;
}