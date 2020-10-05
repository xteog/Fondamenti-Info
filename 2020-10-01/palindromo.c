#include <stdio.h>
#define POW 10

int main(){
	int n, j = 1, i = 1, cond = 1;
	scanf("%d", &n);

	while(j < n / 10)
		j *= 10;
	
	while(cond && j >= 1){
		if((n / j) % POW != (n / i) % POW)
			cond = 0;
		i *= 10;
		j /= 10;
	}
	if(cond)
		printf("Palindromo\n");
	else
		printf("Non Palindromo\n");
	return 0;
}