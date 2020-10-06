/*
Scrivere un programma che chiede all'utente di inserire una sequenza 
10 numeri interi, quindi visualizza tutti i pari, poi tutti i 
dispari.
*/

#include<stdio.h>
#define DIM 10

int main(){
    int arr[DIM], i;
    for(i = 0; i < DIM; i++)
        scanf("%d", &arr[i]);
        
    for(i = 0; i < DIM; i++){
        if(arr[i] % 2 == 0)
            printf("%d ", arr[i]);
    }
    for(i = 0; i < DIM; i++){
        if(arr[i] % 2 != 0)
            printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}