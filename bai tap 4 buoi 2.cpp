#include <stdio.h>

int main(){
	for (int n=2; n<=9; n++){
		printf("Bang cuu chuong %d:\n",n);
		for (int i=1; i<=10; i++){
			printf("%d*%d=%d\n",n,i,n*i);
		}
	}	
	return 0;
}
