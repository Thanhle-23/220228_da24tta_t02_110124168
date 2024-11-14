#include <stdio.h>

void inbangcuuchuong(int n){
	printf("Bang cuu chuong %d:\n",n);
	for (int i=1; i<=10; i++){
		printf("%d*%d=%d\n",n,i,n*i);
	}
}
int main(){
	int n;
	do{
		printf("Nhap bang cuu chuong so:\n");
		scanf("%d",&n);
	} while (2>n || n>9);
	inbangcuuchuong(n);
	return 0;
}
