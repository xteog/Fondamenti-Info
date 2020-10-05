#include <stdio.h>

int main(){
	int n, i = 1, j = 1;
	scanf("%d", &n);

	while(i < n){
		while(j < n){
			printf("%3d", j * i);
			j++;
		}
		j = 0;
		i++;
		printf("\n");
	}

	return 0;
}