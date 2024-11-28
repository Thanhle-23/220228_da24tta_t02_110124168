 #include <stdio.h>
 #define ROW 100
 #define COL 100
 #define SIZE 100
 
 void nhapMang(int a[ROW][COL], int m, int n );
 void xuatMang(int a[ROW][COL], int m, int n );
 int tongMang(int a[ROW][COL], int m, int n);
 int tongDongK(int a[ROW][COL], int m, int n, int dk);
 int tongCotK(int a[ROW][COL], int m, int n, int ck);
 void KTDongKAm(int a[ROW][COL], int m, int n, int dk);
 void inKTSNTcK(int a[ROW][COL], int m, int n, int ck);
 
 int main(){
 	int m,n;
 	int a[ROW][COL];
 	
 	//Nhap so dong va so cot
 	do {
 		printf("Nhap so dong m ");
 		scanf("%d",&m);
 		printf("Nhap so cot n ");
 		scanf("%d",&n);
	 }while (m <= 0 || n <= 0 || m > ROW || n > COL);
 	
 	//Goi ham cau a
 	nhapMang(a, m, n);
 	
 	//Goi ham cau b
 	xuatMang(a, m, n);
 	
 	//Goi ham cau c
 	tongMang(a, m, n);
 	
 	//Goi ham cau d
 	int dk;
	do {
 		printf("\nNhap dong k ");
 		scanf("%d",&dk);
 		if (dk < 0 || dk >= m) {
            printf("Dong k khong hop le nhap lai\n");
    	}
	}while (dk < 0 || dk >= m );
	
	if(tongDongK(a, m, n, dk)!=1){
 		int kqd=tongDongK(a, m, n, dk);
 			printf("Tong dong K la: %d\n",kqd);
	}
	
 	//Goi ham cau e
 	int ck;
 	do {
 		printf("\nNhap cot k ");
 		scanf("%d",&ck);
 		if (ck < 0 || ck >= n) {
            printf("Cot k khong hop le nhap lai\n");
    	}
	}while (ck < 0 || ck >= n );
 
 	if(tongCotK(a, m, n, ck)!=2){
 		int kqe=tongCotK(a, m, n, ck);
 		printf("Tong cot K la: %d\n",kqe);
	}
	
	//Goi ham cau f
	KTDongKAm(a, m, n, dk);
	
	//Goi ham cau g
	inKTSNTcK(a, m, n, ck);
	
 	return 0;
 }
 
 //Ham nhap mang
 void nhapMang(int a[ROW][COL], int m, int n){
 	printf("Nhap cac phan tu cua mang(%d dong x %d cot): \n",m,n);
 	for(int i=0;i<m;i++){
 		for(int j=0;j<n;j++){
 			printf("Nhap phan tu a[%d][%d]: ",i,j);
 			scanf("%d",&a[i][j]);
 		}
 	}
 }
 
 //Ham xuat mang
 void xuatMang(int a[ROW][COL], int m, int n){
 	printf("Mang da nhap la:\n");
 	for(int i=0;i<m;i++){
 		for(int j=0;j<n;j++){
 			printf("%d ", a[i][j]);
 		}
 		printf("\n");
 	}
 }
 
 //Ham tinh tong mang
 int tongMang(int a[ROW][COL], int m, int n){
 	int tong=0;
 	for(int i=0;i<m;i++){
 		for(int j=0;j<n;j++){
 			tong+=a[i][j];
 		}
 	}
 	printf("Tong mang la: %d\n",tong);
	return tong;
}

//Ham tinh tong dong k
int tongDongK(int a[ROW][COL], int m, int n, int dk){
	int tongdK=0;
	for(int j=0;j<n;j++){
 		tongdK+=a[dk][j];
 	}
 	if (dk < 0 || dk >= m) {
 	return 1;
	}
 	return tongdK;
}

//Ham tinh tong cot k
int tongCotK(int a[ROW][COL], int m, int n, int ck){
	int tongcK=0;
	for(int i=0;i<m;i++){
 		tongcK+=a[i][ck];
 	}
 	if (ck < 0 || ck >= n ){
 	return 2;
	}
 	return tongcK;
}

//Ham kiem tra dong k co ton tai so am hay khong
void KTDongKAm(int a[ROW][COL], int m, int n, int dk){
	for(int j=0;j<n;j++){
		if(a[j][dk]<0){
			printf("\nDong K co ton tai so am");
		} else{
			printf("\nDong K khong ton tai so am");
		}break;
	}
}

//Ham kiem tra cot k co ton tai so nguyen to hay khong
int kiemTraSNT(int x){
	if(x>=2){
		for(int i=2; i*i<=x; i++){
			if(x%i==0)	return 0;
		}
		return 1;
	}
}
int KTSNTcK(int a[ROW][COL], int m, int n, int ck){
	for(int i=2;i<m;i++){
		if(kiemTraSNT(a[i][ck])){
			return 0;
		}
	}return 1;
}
void inKTSNTcK(int a[ROW][COL], int m, int n, int ck){
	if(KTSNTcK(a, m, n, ck)){
		printf("\nco");
	}else{
		printf("\nkhong");
	}
}
