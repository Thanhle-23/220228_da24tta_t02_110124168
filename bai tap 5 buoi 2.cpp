#include <stdio.h>

void tongcacchuso(int n){
	int tong =0;
	while(n>0){//dieu kien de khi chia ma so be hon 0
		tong += n%10;// lay chu so cuoi cung
		n/=10;//bo chu so cuoi cung
	}
	printf("tong cac chu so la: %d\n",tong);
}
int main(){
	int n;
	do{
		printf("nhap so nguyen duong n:");
		scanf("%d",&n);

	}while(n<=0);
	tongcacchuso(n);
	return 0;
}
