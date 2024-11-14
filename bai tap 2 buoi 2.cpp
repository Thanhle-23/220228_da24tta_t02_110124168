#include <stdio.h>

int tichcacso(int n){
	int tich=1;
	for (int i=1; i<=n; i++){
		tich*=i;
	}
	return tich;
}
int main(){
	
	int n;
	do{
		printf("Nhap n de tinh tong tu 1 den n:\n");
		scanf("%d", &n);
	}while (n<1);
	int ketqua=tichcacso(n);
	printf("tich tu 1 den %d la :%d\n",n,ketqua);
	return 0;
}
