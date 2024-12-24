#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct Phanso{
	int tuSo;
	int mauSo;
};
typedef struct Phanso ps;

void xuatPhanSo(Phanso ps);
void rutGonPhanSo(Phanso *ps);
void hienThiDSPhanSo(const char *tenTep);

int main(){
	Phanso ps,n,*ds;
	char tenTep[20];
	printf("\nNhap ten tep: ");
	scanf("%s",&tenTep);
	
	rutGonPhanSo(&ps);
	
	hienThiDSPhanSo(tenTep);
	
	
	return 0;
}

void xuatPhanSo(Phanso ps){
	printf("\nphan so la: %d/%d",ps.tuSo, ps.mauSo);
}

int ucln(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

void rutGonPhanSo(Phanso *ps) {
    int ucln2 = ucln(ps->tuSo, ps->mauSo);  
    ps->tuSo /= ucln2;  
    ps->mauSo /= ucln2; 
}

void hienThiDSPhanSo(const char *tenTep){
	FILE *file = fopen(tenTep,"rb");
	if(file==NULL){
		printf("\nLoi mo file");
		return;
	}
	Phanso ps;
	while (fread(&ps,sizeof(Phanso),1,file)){
		xuatPhanSo(ps);
	}
	fclose(file);
}


