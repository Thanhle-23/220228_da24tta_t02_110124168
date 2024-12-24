#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct Phanso{
	int tuSo;
	int mauSo;
};
typedef struct Phanso ps;

void nhapPhanSo(Phanso *ps);
void ghiPhanSo(Phanso*ds,int n, const char *tenTep);

int main(){
	Phanso ps;
	int n;
	printf("\nNhap so luong phan so: ");
	scanf("%d",&n);
	Phanso*ds=(Phanso*)malloc(n*sizeof(Phanso));
	if(ds==NULL){
		printf("\nKhong cap duoc bo nho");
		return 1;
	}
	for(int i=0;i<n;i++){
		printf("Nhap phan so thu %d ",i+1);
		nhapPhanSo(&ds[i]);
	}
	char tenTep[20];
	printf("\nNhap ten tep: ");
	scanf("%s",&tenTep);
	ghiPhanSo(ds,n,tenTep);
	free(ds);
		
	return 0;
}
void nhapPhanSo(Phanso *ps){
	printf("\nNhap tu so: ");
	scanf("%d",&ps->tuSo);
	do{
		printf("Nhap mau so khac 0: ");
		scanf("%d",&ps->mauSo);
	}while(ps->mauSo==0);
}
void ghiPhanSo(Phanso*ds,int n, const char *tenTep){
	FILE *file = fopen(tenTep,"wb");
	if(file==NULL){
		printf("\nLoi mo file");
		return;
	}
	fwrite(ds,sizeof(Phanso),n,file);
	fclose(file);
	printf("\nDa ghi vao tep");
}

