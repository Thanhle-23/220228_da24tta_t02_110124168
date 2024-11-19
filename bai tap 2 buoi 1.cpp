#include <stdio.h>
int main(){
	int n, m;
	
	printf("Nhap so nguyen thu 1: \n");
	scanf("%d", &n);
	fflush(stdin);
	
	printf("Nhap so nguyen thu 2:\n");
	scanf("%d", &m);
	
	if (n<m){
		printf("So nguyen nho hon la: %d", n);} 
		else{ printf("So nguyen nho hon la: %d", m);
	}
	return 0;
}
