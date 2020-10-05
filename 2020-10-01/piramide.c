#include <stdio.h>

int main(){
	int n, i, j = 0;
	scanf("%d", &n);

	if(n % 2 == 0)
		i = 2;
	else
		i = 1;

	while(i <= n){
		while(j < n - i / 2){
			printf(" ");
			j++;
		}
		j = 0;
		while(j < i){
			printf("*");
			j++;
		}
		j = 0;
		i += 2;
		printf("\n");
	}

	return 0;
}

/*
i = 1 se dispari, i= 2 se pari

1 riga, n = 10 
=> i+=2 => 2 '*'
=> n - i = 8 ' '

2 riga, n = 10 
=> i+=2 => 4 '*'
=> n - i = 6 ' '

3 riga, n = 10 
=> i+=2 => 6 '*'
=> n - i = 4 ' '
*/