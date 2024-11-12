#include <stdio.h>

int main(){
	//khai bao bien
	char a;
	int n, m;
	
	//nhap ky tu va hai so
	printf("Nhap 1 trong cac ky tu + - * / de thuc hien phep toan : \n");
	scanf("%s", &a);
	
	printf("Nhap so nguyen thu 1: \n");
	scanf("%d", &n);
	
	printf("Nhap so nguyen thu 2: \n");
	scanf("%d", &m);
	
	//thuc hien phep tinh
	if (a == '+'){ printf("%d+%d=%d \n", n, m, n+m);}
	if (a == '-'){ printf("%d-%d=%d \n", n, m, n-m);}
	if (a == '*'){ printf("%d*%d=%d \n", n, m, n*m);}
	if (a == '/'){ printf("%d/%d=%d \n", n, m, n/m);}

	return 0;
}
