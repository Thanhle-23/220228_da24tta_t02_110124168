#include <stdio.h>

int main(){
	//khai bao bien
	char mssv[10], ten[50], lop[10];
	int ns;
	float dxt;
	
	//nhap thong tin
	printf("\n nhap ho va ten:");
	fflush(stdin);
	gets(ten);
	
	printf("\n nhap mssv:");
	fflush(stdin);
	scanf("%d", mssv);
	
	printf("\n nhap lop:");
	fflush(stdin);
	gets(lop);
	
	printf("\n nhap nam sinh:");
	fflush(stdin);
	scanf("%d", &ns);
	
	printf("\n nhap diem xet tuyen:");
	fflush(stdin);
	scanf("%f", &dxt);
	
	//in thong tin
	printf("Ho va ten:%s\n",ten);
	printf("Mssv:%s\n", mssv);
	printf("Nam sinh:%d\n", ns);
	printf("Lop:%s\n", lop);
	printf("Diem xet tuyen:%f\n", dxt);
	
	return 0;
}
