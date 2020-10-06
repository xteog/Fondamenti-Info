/*
Scrivere un programma in C che chiede all'utente di inserire 5 
numeri interi e li salva in un array. Il programma verifica se la 
sequenza è palindroma stampando a video l'esito del test.
*/

#include<stdio.h>
#define DIM 5

int main(){
    int arr[DIM], i, cond = 1;
    for(i = 0; i < DIM; i++)
        scanf("%d", &arr[i]);
        
    for(i = 0, cond = 1; i < DIM / 2 && cond; i++){
        if(arr[i] != arr[DIM-1-i])
            cond = 0;
    }
    
    if(cond)
        printf("Palindormo\n");
    else
        printf("Non palindromo\n");
    
    return 0;
}