#include <stdio.h>

//ham tinh tong cac chu so cua n
int tongChuSo(int n){
	int tongCS=0;
	while(n>0){
		tongCS+=n%10;
		n/=10;
	}
	printf("\nTong cac chu so la: %d",tongCS);
	return tongCS;
}

//ham tinh tong cac chu so le cua n
int tongChuSoLe(int n){
	int tongCSL=0,c;
	while(n>0){
		c=n%10;
		if(c%2!=0){
			tongCSL+=c;
		}
		n/=10;
	}
	printf("\nTong cac chu so le la: %d",tongCSL);
	return tongCSL;
}

//ham tinh tong cac chu so la so nguyen to
int kiemTraSoNguyenTo(int b){
	if(b<2) {return 0;}
		for (int i=2; i*i<=b; i++){
			if (b%i==0) {
			return 0;}
		}
		return 1;
}
int tongChuSoSNT(int n){
	int tongCSsnt=0,b;
	while(n>0){
		b=n%10;
		if(kiemTraSoNguyenTo(b)){
			tongCSsnt+=b;
		}
		n/=10;
	}
	printf("\nTong cac chu so la so nguyen to : %d",tongCSsnt);
	return tongCSsnt;
}

//ham dem chu so 0 cua n
int demChuSo0(int n){
	int dem0=0,e;
	while(n>0){
		e=n%10;
		if(e==0){
			dem0++;
		}
		n/=10;
	}
	printf("\nSo chu so 0 la: %d",dem0);
	return dem0;
}

//ham dem so chu so chia het cho 3
int demChuSoCH3(int n){
	int dem3=0,g;
	while(n>0){
		g=n%10;
		if(g!=0){
			if(g%3==0){
				dem3++;
		}	}
		n/=10;
	}
	printf("\nSo chu chia het cho 3 la: %d",dem3);
	return dem3;
}
//ham dem so chu so chia het cho 5
int demChuSoCH5(int n){
	int dem5=0,k;
	while(n>0){
		k=n%10;
		if(k!=0){
			if(k%5==0){
				dem5++;
			}
		}
		n/=10;
	}
	printf("\nSo chu chia het cho 5 la: %d",dem5);
	return dem5;
}

int main(){
	int n;
	do{
		printf("Nhap so nguyen duong n:");
		scanf("%d",&n);
	}while(n<100 || n>=1000);
		
	tongChuSo(n);
	tongChuSoLe(n);
	tongChuSoSNT(n);
	demChuSo0(n);
	demChuSoCH3(n);
	demChuSoCH5(n);
	return 0;
}
