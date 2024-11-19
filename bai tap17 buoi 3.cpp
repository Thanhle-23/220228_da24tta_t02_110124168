#include <stdio.h>

// ham in ra man hinh cac gia tri tu 1 den n
void inGiaTriA(int n){
	printf("Cac so tu 1 den %d :",n);
	for (int i=1; i<=n; i++){
		printf("%d ",i);
	}
}

//ham in ra man hinh cac gia tri chan tu 1 den n
void inGiaTriB(int n){
	printf("\nGia tri chan: ");
	for (int i=1; i<=n; i++){
		if (i%2==0){
			printf("%d ",i);
		}
	}
}

//ham in ra man hinh cac gia tri chia het cho 5 trong doan tu 1 den n
void inGiaTriC(int n){
	printf("\nGia tri chia het cho 5: ");
	for (int i=1; i<=n; i++){
		if (i%5==0){
			printf("%d ",i);
		}
	}
}

//ham in ra man hinh cac gia tri la so nguyen to nho hon n
int kiemTraSoNguyenTo(int x){
	if(x<2) {return 0;}
		for (int i=2; i*i<=x; i++){
			if (x%i==0) {
			return 0;}
		}
		return 1;
}
int inGiaTriD(int n){
	printf("\nCac so nguyen to la:");
	for (int i=2; i<=n; i++){
		if(kiemTraSoNguyenTo(i)){
			printf("%d ",i);
		}
	}
	return 0;
}

//ham tinh tong cac gia tri tu 1 den n
int tinhTong(int n){
	int tong=0;
	for(int i=0; i<=n; i++){
		tong+=i;
	}
	printf("\nTong cac so tu 1 den %d la: %d",n,tong);
	return tong;
}

//ham tinh tong cac so le tu 1 den n
int tinhTongLe(int n){
	int tongle=0;
	for(int i=0; i<=n; i++){
		if (i%2!=0){
		tongle+=i;
		}
	}
	printf("\nTong cac so le tu 1 den %d la: %d",n,tongle);
	return tongle;
}

//ham tinh tong cac so nguyen to nho hon n
int tinhTongSNT(int n){
	int tongSNT=0;
	for (int i=2; i<n; i++){
		if(kiemTraSoNguyenTo(i)){
			tongSNT+=i;
		}
	}
	printf("\nTong so nguyen to nho hon %d la: %d",n,tongSNT);
	return tongSNT;
}

//ham tinh trung binh cong cac so le tu 1 den n
float trungBinhCongLe(int n){
	float demle=0,tongletbc=0;
	float TBCl;
	for(int i=0; i<=n; i++){
		if (i%2!=0){
		tongletbc+=i;
		demle++;
		}
	}
	TBCl=tongletbc/demle;
	printf("\nTrung binh cong cac so le tu 1 den %d la: %f",n,TBCl);
	return TBCl;
}

//ham tinh trung binh cong cac so nguyen to nho hon n
float trungBinhCongSNT(int n){
	float demsnt=0,tongSNTtb=0;
	float TBCsnt;
	for (int i=2; i<n; i++){
		if(kiemTraSoNguyenTo(i)){
			tongSNTtb+=i;
			demsnt++;
		}
	}
	TBCsnt=tongSNTtb/demsnt;
	printf("\nTrung binh cong cac so nguyen to nho hon %d la: %f",n,TBCsnt);
	return TBCsnt;
}
//xuat ket qua
int main(){
	int n;
	do{
		printf("Nhap lai so n:");
		scanf("%d",&n);
		} while (n<=0 || n>=100);
		
	inGiaTriA(n);
	inGiaTriB(n);
	inGiaTriC(n);
	inGiaTriD(n);
	tinhTong(n);
	tinhTongLe(n);
	tinhTongSNT(n);
	trungBinhCongLe(n);
	trungBinhCongSNT(n);
	
	return 0;
}
	
