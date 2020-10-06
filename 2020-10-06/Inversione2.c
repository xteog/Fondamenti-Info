/*
Scrivere un programma in C che chiede all'utente di inserire 5 
numeri interi e li salva in un array. Il programma inverte di ordine 
i numeri nell'array e poi li visualizza.
*/

#include<stdio.h>
#define DIM 5

int main(){
    int arr[DIM], i, swap;
    for(i = 0; i < DIM; i++)
        scanf("%d", &arr[i]);
    for(i = 0; i < DIM / 2; i++){
        swap = arr[i];
        arr[i] = arr[DIM-i-1];
        arr[DIM-i-1] = swap;
    }
    for(i = 0; i < DIM; i++)
        printf("%d ", arr[i]);
    printf("\n");
    return 0;
}