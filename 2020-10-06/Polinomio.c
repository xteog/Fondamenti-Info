/*
Scrivere un programma in C in grado di calcolare il valore di 
polinomi di grado massimo 8. Il programma richiede all'utente il 
grado n del polinomio desiderato (un intero compreso tra 0 e 8 
inclusi). Successivamente, chiede all'utente i coefficienti di tutti 
i monomi che compongono il polinomio. Infine, chiede all'utente il 
valore x per cui fornire la soluzione del polinomio, la calcola e la 
stampa a video.
*/

#include<stdio.h>
#define MAXG 8

int main(){
    int p[MAXG+1], n, i, x, pot, ris;
    do
        scanf("%d", &n);
    while(n < 0 || n > MAXG);
    
    for(i = n; i >= 0; i--)
        scanf("%d", &p[i]);

    scanf("%d", &x);

    for(ris = p[0], pot = 1, i = 1; i <= n; i++){
        pot = pot * x;
        ris = pot * p[i];
    }
    printf("%\n", ris);
    
    return 0;
}