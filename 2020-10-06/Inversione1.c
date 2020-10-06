/*
Scrivere un programma in C che chiede all'utente di inserire 5
numeri interi e poi li visualizza in ordine inverso.
*/

#include<stdio.h>
#define DIM 5

int main(){
    int arr[DIM], i;
    for(i = 0; i < DIM; i++)
        scanf("%d", &arr[i]);
    for(i = DIM - 1; i >= 0; i--)
        printf("%d ", arr[i]);
    return 0;
}