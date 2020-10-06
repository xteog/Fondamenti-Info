/*
Scrivere un programma in C che legge una sequenza di numeri interi 
di lunghezza indefinita composta da elementi nell'intervallo [0;9] e 
terminata da un qualsiasi numero non incluso in tale intervallo. Il 
programma visualizza l'istogramma a barre verticali delle 
frequenze di ciascun numero nell'intervallo [0;9], disegnandolo 
tramite il carattere *.
*/

#include<stdio.h>
#define DIM 10

int main(){
    int arr[DIM], n, i, j;
    
    for(i = 0; i < DIM; i++)
        arr[i] = 0;
    
    scanf("%d", &n);
    while(n >= 0 && n <= 9){
        arr[n]++;
        scanf("%d", &n);
    }
    
    for(i = DIM-1; i >= 0; i--){
        for(j = 0; j < DIM; j++){
            if(arr[j] > i)
                printf("# ");
            else
                printf("  ");
        }
        printf("\n");
    }
    for(i = 0; i < DIM; i++)
        printf("%d ", i);
    printf("\n");

    return 0;
}