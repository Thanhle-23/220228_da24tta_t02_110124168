
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct NGAY_THANG{
	int ngay;
	int thang;
	int nam;
};
typedef struct NGAY_THANG ngaysinh;
struct MON_HOC{
	char mamon[10];
	float diem;
};

struct SINH_VIEN{
	char hoten[30], diachi[100], gioitinh[4], mssv[10];
	int somon;
	NGAY_THANG ngaysinh;
	MON_HOC monhoc[10];
} ;
typedef struct SINH_VIEN sv;
void xuat(SINH_VIEN sv);
void nhapnsv(SINH_VIEN *ds, int n);
void xuatnsv(SINH_VIEN *ds, int n);
void giaiPhongSinhVien(SINH_VIEN *ds);
SINH_VIEN *timsvMSSV(SINH_VIEN*ds, int n, const char *mssv);

int main()
{
	
	int n;
	
	SINH_VIEN *danh_sach = (SINH_VIEN *)malloc(n * sizeof(SINH_VIEN));
	nhapnsv(danh_sach, n);
	xuatnsv(danh_sach,n);
	
	char mssv_tim[15];
    printf("\nNhap MSSV can tim: ");
    scanf("%s", mssv_tim);

    SINH_VIEN *sv_tim_duoc = timsvMSSV(danh_sach, n, mssv_tim);
    if (sv_tim_duoc != NULL) {
        printf("\n=== Sinh vien tim thay ===\n");
        xuat(*sv_tim_duoc);
    } else {
        printf("\nKhong tim thay sinh vien voi MSSV: %s\n", mssv_tim);
    }

    // Giai phong bo nho cap phat dong
    for (int i = 0; i < n; i++) {
        giaiPhongSinhVien(&danh_sach[i]);
    }
    
    free(danh_sach);

	return 0;
}

void xuat(SINH_VIEN sv)
{
	printf("%s\t%s\t%s\t%s\t%d%d%d\t%d\t", sv.hoten, sv.mssv, sv.diachi, sv.gioitinh, sv.ngaysinh.ngay, sv.ngaysinh.thang, sv.ngaysinh.nam ,  sv.somon);
	for(int i=0; i<sv.somon; i++){
		printf("Ma mon: %s\n Diem: %f", sv.monhoc[i].mamon, sv.monhoc[i].diem);
	}
}
void nhap(SINH_VIEN *sv)
{
	//Nhap thanh phan ho ten
	printf("\nNhap vao ho ten: ");
	fflush(stdin);
	gets(sv->hoten);
	
	//Nhap thanh phan mssv
	printf("\nHay cho biet mssv: ");
	scanf("%s", &sv->mssv);
	
	//Nhap thanh phan dia chi
	printf("\nNhap vao dia chi: ");
	fflush(stdin);
	gets(sv->diachi);
	
	//Nhap thanh phan gioi tinh
	printf("\nNhap vao gioi tinh: ");
	fflush(stdin);
	gets(sv->gioitinh);
	
	//Nhap thanh phan ngay sinh
	printf("\nHay cho biet ngay sinh: ");
	scanf("%d %d %d", &sv->ngaysinh.ngay, &sv->ngaysinh.thang, &sv->ngaysinh.nam);
	
	//Nhap thanh phan mon hoc
	printf("\nNhap vao so mon hoc: ");
	scanf("%d",&sv->somon);
	
	for(int i=0; i < sv->somon; i++){
		printf("Nhap ma mon hoc thu %d ", i+1);
		scanf("%s",&sv->monhoc[i].mamon);
		printf("Nhap diem mon thu %d ", i+1);
		scanf("%f",&sv->monhoc[i].diem);
	}
}
void giaiPhongSinhVien(SINH_VIEN *sv) {
    free(sv->monhoc);
}
void nhapnsv(SINH_VIEN *ds, int n){
	printf("\nnhap so luong sinh vien: ");
	scanf("%d",&n);
	for(int i=0; i<n;i++){
		printf("\nnhap thong tin sinh vien thu %d: ",i+1);
		nhap(&ds[i]);
	}
}
void xuatnsv(SINH_VIEN *ds, int n){
	printf	("\n THong tin danh sach sinh vien");
	for(int i=0; i<n; i++){
		printf("\nSinh vien thu %d: ",i+1);
		xuat(ds[i])	;
	}
}
SINH_VIEN *timsvMSSV(SINH_VIEN *ds, int n, const char *mssv) {
    for (int i = 0; i < n; i++) {
        if (strcmp(ds[i].mssv, mssv) == 0) {
            return &ds[i]; 
        }
    }
    return NULL; // Khong tim thay
}
