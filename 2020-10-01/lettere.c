#include <stdio.h>

int main(){
	char let;
	scanf("%c", &let);
	while(let >= 'a' && let <= 'z'){
		if(let != 'z')
			printf("%c\n", let + 1);
		else
			printf("a\n");
		scanf(" %c", &let);
	}
	
	return 0;
}
