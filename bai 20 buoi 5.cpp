#define SIZE 100
#include <stdio.h>

void nhapMang(int a[], int n);
void xuatMang(int a[], int n);
float tongMang(int a[], int n);
int trungBinhCongLe(int a[], int n);
void demSoDuong(int a[], int n);
int sapXepTang(int a[], int n);
void inLe(int a[], int n);
void in0(int a[], int n);
int timLonNhat(int a[],int n);
int timFLonNhat(int a[],int n);
void  inViTriLN(int a[],int n);
int main()
{
	int A[SIZE];
	int n, kq, x;
	
	do
	{
		printf("\nNhap vao so phan tu: ");
		scanf("%d", &n);
	}while(n<=0||n>100);
	
	//goi ham cau a
	nhapMang(A,n);
	
	//Goi ham cau b
	printf("\nMang vua nhap la: ");
	xuatMang(A,n);
	
	//Goi ham cau c
	tongMang(A,n);
	
	//Goi ham cau d
	trungBinhCongLe(A,n);
	
	//Goi ham cau e
	demSoDuong(A,n);
	
	//Goi ham cau f
	sapXepTang(A,n);
	
	//Goi ham cau g
	inLe(A,n);
	
	//Goi ham cau h
	in0(A,n);
	
	//Goi ham cau i
	timLonNhat(A,n);
	
	//Goi ham cau j
	timFLonNhat(A,n);
	
	//Goi ham cau k
	inViTriLN(A,n);
}

//ham nhap mang a 
void nhapMang(int a[], int n)
{
	int i;	
	i = 0;
	while(i<n)
	{
		printf("\nNhap gia tri tai vi tri %d: ", i);
		scanf("%d", &a[i]);
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
float tongMang(int a[], int n)
{
	float tong = 0;
	int i=0;
	do
	{
		tong = tong + a[i];
		i++;
	}while(i<=n-1);
	printf("\nTong cac gia tri trong mang la %f", tong);
}

//ham tinh trung binh cong cac so o vi tri le
int trungBinhCongLe(int a[],int n){
	float demle=0,tongletbc=0;
	float TBCl;
	for(int i=1; i<n; i++){
		if (i%2!=0){
			tongletbc+=a[i];
			demle++;
		}
	}
	TBCl=tongletbc/demle;
	printf("\nTrung binh cong cac so o vi tri le la: %f",TBCl);
	return TBCl;
}

//ham dem so duong trong mang a
void demSoDuong(int a[], int n){
	int dem=0;
	for(int i=0;i<=n;i++){
		if(i>0){
			dem++;
		}
	}
	printf("\nSo phan tu duong trong mang la %d", dem);
}

//ham sap xep cac phan tu trong mang a theo thu tu tang dan
int sapXepTang(int a[], int n){
	for(int i=0; i<n-1;i++){
		for(int j=i+1; j<n; j++){
			if (a[i]>a[j]){
				int tam=a[i];
				a[i]=a[j];
				a[j]=tam;
			}
		}
	}
	printf("\nMang da sap xep lai: ");
	for(int i=0;i<n;i++){
		printf("%3d",a[i]);
	}
}

//ham in ra cac gia tri tai vi tri le
void inLe(int a[],int n){
	printf("\nCac gia tri tai vi tri le la:");
	for(int i=1;i<=n-1;i++){
		if(i%2!=0){
			printf("%3d",a[i]);
		}
	}
}

//ham in ra cac vi tri co gia tri la 0
void in0(int a[],int n){
	printf("\nVi tri co gia tri 0 la: ");
	for(int i=0;i<=n-1;i++){
		if(a[i]==0){
			printf("%3d",i);
		}else{
		printf("Khong co gia tri 0 trong mang");
		break;
		}
	}
}

//ham tim ra so lon nhat
int timLonNhat(int a[],int n){
	int max=a[0];
	for (int i=1; i<n;i++){
		if(a[i]>max){
			max=a[i];
		}
	}
	printf("\nSo lon nhat trong mang la: %d",max);
	return max;
}

//ham tim ra vi tri co gia tri lon nhat dau tien trong mang
int timFLonNhat(int a[],int n){
	fflush(stdin);
	int maxF=a[0],maxi=0;
	printf("\nVi tri so lon nhat dau tien trong mang la: ");
	for (int i=0; i<=n-1;i++){
		if(a[i]>maxF){
			maxF=a[i];
			maxi=i;
		}
		
	}printf("%3d",maxi);
	return maxi;
}

//ham in ra vi tri cac gia tri lon nhat
void  inViTriLN(int a[],int n){
	int maxv=a[0],maxi1;
	printf("\nVi tri cac so lon nhat trong mang la: ");
	for (int i=1; i<=n-1;i++){
		if(a[i]>maxv){
			maxv=a[i];
			maxi1=i;
		}
	}
	printf("%3d",maxi1);
	for(int i=0;i<n;i++){
		if(a[i]==maxv){
			printf("%3d",i);
		}
	}
}
