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
	printf("Nhap n de tinh tong tu 1 den n:\n");
	scanf("%d", &n);
	int ketqua=tongcacso(n);
	printf("tong tu 1 den %d la :%d\n",n,ketqua);
	return 0;
}
