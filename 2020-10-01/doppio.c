#include <stdio.h>

int main(){
	int n, prec;

	while(n != 0){
		scanf("%d", &n);
		if(prec * 2 == n)
			printf("%d %d\n", prec, n);
		prec = n;
	}

	return 0;
}