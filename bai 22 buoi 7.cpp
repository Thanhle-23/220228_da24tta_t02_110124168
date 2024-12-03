#include<stdio.h>
#include<stdlib.h>

void nhapDanhSach(int *a, int n);
void xuatDanhSach(int *a, int n);
int tongNGiaTri(int *a,int n);
int Max(int *a,int n);
void demMax(int *a, int n);
void demX(int *a, int n, int x);
int ktSoDuong(int *a,int n);

int main(){
	int n, x;
	//Nhap so luong phan tu
	do{
		printf("Nhap so luong phan tu trong danh sach: ");
		scanf("%d",&n);
	}while(n<=0 || n>=50);
	
	//Cap phat bo nho dong
	int*P=(int*)malloc(n*sizeof(int));
	
	//Goi ham cau a
	nhapDanhSach(P, n);
	
	//Goi ham cau b
	xuatDanhSach(P, n);
	
	//Goi ham cau c
	int kqc=tongNGiaTri(P, n);
	printf("\nTong n gia tri tu ban phim la: %d",kqc);
	
	//Goi ham cau d
	int kqd=Max(P,n);
	printf("\nSo lon nhat trong %d gia tri la: %d",n,kqd);
	
	//Goi ham cau e
	demMax(P, n);
	
	//Goi ham cau f
	demX(P, n, x);
	
	//Goi ham cau g
	if(ktSoDuong(P, n)){
		printf("\nCo ton tai so duong trong mang");
	}else{printf("\nKhong ton tai so duong trong mang");
	
	}
	
	//Giai phong bo nho
	free(P);
	return 0;
}

//Ham nhap n gia tri tu ban phim
void nhapDanhSach(int *a, int n){
	printf("\nNhap %d so nguyen: ",n);
	for(int i=0; i<n; i++){
		printf("\nNhap so thu %d: ",i+1);
		scanf("%d",&a[i]);
	}
}

//Ham xuat n gia tri tu ban phim
void xuatDanhSach(int *a, int n){
	printf("\nDanh sach so nguyen: ");
	for(int i=0; i<n; i++){
		printf(" %d ",a[i]);
	}
}

//Ham tinh tong n gia tri tu ban phim
int tongNGiaTri(int *a,int n){
	int tongN=0;
	for(int i=0; i<n; i++){
		tongN+=a[i];
	}
	return tongN;
}

//Ham tim gia tri lon nhat trong n gia tri
int Max(int *a,int n){
	int LN=a[0];
	for (int i=1; i<n;i++){
		if(a[i]>LN){
			LN=a[i];
		}
	}
	return LN;
}

//Ham dem so lan xuat hien cua gia tri lon nhat trong n gia tri
void demMax(int *a, int n){
	int demM=0;
	int LN2=a[0];
	for (int i=1; i<n;i++){
		if(a[i]>LN2){
			LN2=a[i];
		}
	}
	for(int i=0; i<n;i++){
		if(LN2==a[i]){
			demM++;
		}
	}
	printf("\nSo lan xuat hien cua gia tri lon nhat la: %d", demM);
}

//Ham dem so lan xuat hien cua x
void demX(int *a, int n, int x){
	printf("\nNhap so X de kiem tra ");
	scanf("%d",&x);
	int dX=0;
	for(int i=0; i<n; i++){
		if(x==a[i]){
			dX++;
		}
	}
	printf("\nSo lan xuat hien cua %d la: %d", x, dX);
}

//Ham kiem tra trong mang co ton tai so duong hay khong
int ktSoDuong(int *a,int n){
	for(int i=0; i<n; i++){
		if(a[i]>0){
			return 1;
		}
	}
	return 0;
}
