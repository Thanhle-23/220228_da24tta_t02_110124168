#include <stdio.h>
//tinh tong tu 1 den n
int tongcacso(int n){
	int tong=0;
	for (int i=1; i<=n; i++){
		tong=tong+i;
	}
	return tong;
}
int main(){
	
	int n;
	Do{
		printf("Nhap n de tinh tong tu 1 den n:\n");
		scanf("%d", &n);
	} while (n<=0);
	int ketqua=tongcacso(n);
	printf("tong tu 1 den %d la :%d\n",n,ketqua);
	return 0;
}
