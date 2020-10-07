/*
Scrivere un programma in C che acquisisce 10 numeri interi. Il 
programma calcola i primi due valori massimi e li visualizza.
*/

#include<stdio.h>
#define DIM 10

int main(){
    int arr[DIM], i, max1 = 0, max2 = 0;
    
    for(i = 0; i < DIM; i++){
        scanf("%d", &arr[i]);
    }
    
    for(i = 0; i < DIM; i++){
        if(arr[i] > max2){
            if(arr[i] > max1){
                max2 = max1;
                max1 = arr[i];
            }else
                max2 = arr[i];
        }
    }
    printf("%d %d\n", max1, max2);
    
    return 0;
}