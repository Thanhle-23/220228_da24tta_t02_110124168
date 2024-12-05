#include <stdio.h>
#include <string.h>
struct Phanso{
	int tuSo;
	int mauSo;
};
typedef struct Phanso ps;

void nhapPhanSo(Phanso *ps);
void xuatPhanSo(Phanso ps);
void rutGonPhanSo(Phanso *ps);
Phanso congPhanSo(Phanso ps1, Phanso ps2);
Phanso nhanPhanSo(Phanso ps1, Phanso ps2);
Phanso chiaPhanSo(Phanso ps1, Phanso ps2);

int main(){
	Phanso ps, ps1, ps2, psTong, psTich, psThuong;
	
	nhapPhanSo(&ps);
	
	xuatPhanSo(ps);
	
	rutGonPhanSo(&ps);
	
	printf("\nPhan so sau khi rut gon: ");
	xuatPhanSo(ps);
	
	printf("\nNhap phan so thu nhat:");
    nhapPhanSo(&ps1);

    printf("\nNhap phan so thu hai:");
    nhapPhanSo(&ps2);
    
    psTong = congPhanSo(ps1, ps2);
    printf("\nTong hai phan so: ");
    xuatPhanSo(psTong);
    
    psTich = nhanPhanSo(ps1, ps2);
    printf("\nTich hai phan so: ");
    xuatPhanSo(psTich);
    
    psThuong = chiaPhanSo(ps1, ps2);
    printf("\nThuong hai phan so: ");
    xuatPhanSo(psThuong);
    
	return 0;
}
void nhapPhanSo(Phanso *ps){
	printf("\nNhap tu so: ");
	scanf("%d",&ps->tuSo);
	do{
		printf("\nNhap mau so khac 0: ");
		scanf("%d",&ps->mauSo);
	}while(ps->mauSo==0);
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

Phanso congPhanSo(Phanso ps1, Phanso ps2) {
    Phanso psTong;
    psTong.tuSo = ps1.tuSo * ps2.mauSo + ps1.mauSo * ps2.tuSo; 
    psTong.mauSo = ps1.mauSo * ps2.mauSo; 
    rutGonPhanSo(&psTong);  
    return psTong;
}

Phanso nhanPhanSo(Phanso ps1, Phanso ps2) {
    Phanso psTich;
    psTich.tuSo = ps1.tuSo * ps2.tuSo;
    psTich.mauSo = ps1.mauSo * ps2.mauSo; 
    rutGonPhanSo(&psTich);  
    return psTich;
}

Phanso chiaPhanSo(Phanso ps1, Phanso ps2) {
    Phanso psThuong;
    psThuong.tuSo = ps1.tuSo * ps2.mauSo;
    psThuong.mauSo = ps1.mauSo * ps2.tuSo; 
    rutGonPhanSo(&psThuong);  
    return psThuong;
}
