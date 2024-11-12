#include <stdio.h>

int main(){
	int n;
	do{
	printf("Nhap so gio trong ngay(24h):\n");
	scanf("%d", &n);} while (0<n & n>23);
	
	if (n<19){
		printf("Have a good day!"); }else{ printf("Have a good night!");
	}
	return 0;
}
