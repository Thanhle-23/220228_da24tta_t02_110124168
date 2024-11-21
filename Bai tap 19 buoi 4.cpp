#define SIZE 100
#include <stdio.h>

void nhapMang(int a[], int n);
void xuatMang(int a[], int n);
int tongMang(int a[], int n);
int tongDuong(int a[], int n);
int tongViTriLe(int a[], int n);
int demSoAm(int a[],int n);
int demSoLe(int a[],int n);
int demSNT(int a[],int n);
int timSNTfirst(int a[],int n);
void inSoDuongLe(int a[],int n);
void kiemTraSoAm(int a[],int n);
void kiemTraSoX(int a[],int n,int x);

int main()
{
	int A[SIZE];
	int n, kq, x;
	
	do
	{
		printf("\nNhap vao so phan tu: ");
		scanf("%d", &n);
	}while(n<=0||n>100);
	
	//n hop le
	//goi ham cau a
	nhapMang(A,n);
	
	//Goi ham cau b
	printf("\nMang vua nhap la: ");
	xuatMang(A,n);
	
	//Goi ham cau c
	int kqc = tongMang(A,n);
	printf("\nTong cac gia tri trong mang la %d", kqc);

	//Goi ham cau d
	int kqd = tongDuong(A,n);
	printf("\nTong cac gia tri duong trong mang la %d", kqd);
	
	//Goi ham cau e
	int kqe = tongViTriLe(A,n);
	printf("\nTong cac gia tri tai vi tri le trong mang la %d", kqe);	
	
	//Goi ham cau f
	int kqf = demSoAm(A,n);
	printf("\nSo phan tu am trong mang la %d", kqf);				
	
	//Goi ham cau g
	int kqg = demSoLe(A,n);
	printf("\nSo phan tu le trong mang la %d", kqg);
	
	//Goi ham cau h
	int kqh = demSNT(A,n);
	printf("\nSo phan tu la so nguyen to trong mang la %d", kqh);	

	//Goi ham cau i
	int kqi = timSNTfirst(A,n);
	printf("\nSo nguyen to dau tien trong mang la %d", kqi);
		
	//Goi ham cau j
	inSoDuongLe(A,n);
	
	//Goi ham cau k
	kiemTraSoAm(A,n);	
	
	//Goi ham cau i
	kiemTraSoX(A,n,x);
	
	return 0;	
}
//ham nhap mang a 
void nhapMang(int a[], int n)
{
	int i;
	
	i = 0;
	while(i<=n-1)
	{
		printf("\nNhap gia tri tai vi tri %d: ", i);
		scanf("%d", &a[i]); //a+i
		i++;
	}
}

//ham xuat mang a
void xuatMang(int a[], int n)
{
	int i;
	for(i=0; i<=n-1; i++)
	{
		printf("%3d", a[i]);
	}
}

//ham tinh tong cac phan tu cua mang a
int tongMang(int a[], int n)
{
	int tong = 0;
	int i=0;
	do
	{
		tong = tong + a[i];
		i++;
	}while(i<=n-1);
	return tong;
}

//ham tinh tong cac phan tu duong 
int tongDuong(int a[], int n)
{
	int tongd=0;
	for (int i=0; i<n; i++){
		if (a[i]>0){
			tongd+=a[i];
		}
	}
	return tongd;
}

//ham tinh tong cac phan tu tai vi tri le
int tongViTriLe(int a[], int n)
{
	int tongVTL=0;
	for (int i=0; i<n;i++){
		if (i%2!=0){
			tongVTL+=a[i];
		}
	}
	return tongVTL;
}

//ham dem so phan tu am 
int demSoAm(int a[],int n){
	int demAm=0;
	for (int i=0; i<n; i++){
		if(a[i]<0){
			demAm++;
		}
	}
	return demAm;
}

//ham dem so phan tu le 
int demSoLe(int a[],int n){
	int demLe=0;
	for (int i=0; i<n; i++){
		if(a[i]%2!=0){
			demLe++;
		}
	}
	return demLe;
}

//ham kiem tra so nguyen to
int kiemTraSNT(int n){
	if(n>=2){
		for(int i=2; i*i<=n; i++){
			if(n%i==0)	return 0;
		}
		return 1;
	}
}
//ham dem so nguyen to
int demSNT(int a[],int n){
	int demSNT=0;
	for (int i=0; i<n; i++){
		if(kiemTraSNT(a[i])){
			demSNT++;
		}
	}
	return demSNT;
}

//ham kiem tra so nguyen to
int kiemTraSNT2(int n){
	if(n>=2){
		for(int i=2; i*i<=n; i++){
			if(n%i==0)	return 0;
		}
		return 1;
	}
}
//ham tim so nguyen to dau tien trong mang
int timSNTfirst(int a[],int n){
	int tim;
	for (int i=0; i<n; i++){
		if(kiemTraSNT2(a[i])){
			tim= a[i];
			break;
		}	
	}
	return tim;
}

//ham in ra cac so duong le
void inSoDuongLe(int a[], int n)
{
	int i;
	printf("\nSo duong le trong mang la:");
	for(i=0; i<=n-1; i++)
	{
		if(a[i]>0 && a[i]%2!=0){
			printf("%3d", a[i]);
		}
	}
}

//ham kiem tra trong mang co ton tai so am khong
void kiemTraSoAm(int a[],int n){
	for (int i=0; i<n; i++){
		if(a[i]<0){
			printf("\nCo ton tai so am trong mang");
			break;
		}else{
			printf("\nKhong ton tai so am trong mang");
			break;
		}
	}
}

//ham kiem tra trong mang co ton tai gia tri x khong
void kiemTraSoX(int a[],int n, int x){
	printf("\nNhap so X de kiem tra ");
	scanf("%d",&x);
	for (int i=0; i<n; i++){
		if(a[i]==x) return 1	
	}
	return 0;
}
void inKiemTra(int a[],int n, int x){
	if(kiemTraSoX)
}
