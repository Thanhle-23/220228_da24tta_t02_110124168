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

struct LOP_HOC{
	char malop[10];
	char tenlop[10];
	int siso;
};
typedef struct LOP_HOC lophoc;

struct SINH_VIEN{
	char hoten[30], diachi[100], gioitinh[4], mssv[10];
	int somon;
	NGAY_THANG ngaysinh;
	MON_HOC monhoc[10];
	LOP_HOC lophoc;
} ;
typedef struct SINH_VIEN sv;

void nhapnsv(SINH_VIEN *ds, int n);

void ghiDanhSachLopVaoFile(lop *ds, int n, const char *filename);
void nhapDanhSachLop(lop *ds, int n);

int main()
{
	
	int n;
	
	SINH_VIEN *danh_sach = (SINH_VIEN *)malloc(n * sizeof(SINH_VIEN));
	nhapnsv(danh_sach, n);
	
   
    free(danh_sach);

	return 0;
}
void nhapThongTinLop(lophoc *l) {
   
    printf("Nhap ma lop: ");
    scanf("%s", l->malop);

    printf("Nhap ten lop: ");
    fflush(stdin);
	gets(l->hoten);
  
    printf("Nhap si so: ");
    scanf("%d", &l->siso);

 
    l->danhsachsinhvien = (sv *)malloc(l->siso * sizeof(sv));

    for (int i = 0; i < l->siso; i++) {
        printf("\nNhap thong tin sinh vien thu %d:\n", i + 1);
        nhap(&l->danhsachsinhvien[i]);
    }
}

void xuatThongTinLop(lophoc l) {
    printf("\nMa lop: %s\n", l.malop);
    printf("Ten lop: %s\n", l.tenlop);
    printf("Si so: %d\n", l.siso);

    printf("\nDanh sach sinh vien:\n");
    for (int i = 0; i < l.siso; i++) {
        printf("\nSinh vien %d:\n", i + 1);
        xuat(l.danhsachsinhvien[i]);
    }
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

void nhapnsv(SINH_VIEN *ds, int n){
	printf("\nnhap so luong sinh vien: ");
	scanf("%d",&n);
	for(int i=0; i<n;i++){
		printf("\nnhap thong tin sinh vien thu %d: ",i+1);
		nhap(&ds[i]);
	}
}

void ghiDanhSachLopVaoFile(lop *ds, int n, const char *filename) {
    FILE *f = fopen(filename, "wb");
    if (f == NULL) {
        printf("Khong the mo file.\n");
        return;
    }

    // Ghi s? lu?ng l?p h?c vào file
    fwrite(&n, sizeof(int), 1, f);

    // Ghi t?ng l?p vào file
    for (int i = 0; i < n; i++) {
        fwrite(&ds[i], sizeof(lop), 1, f);
    }

    fclose(f);
}

void nhapDanhSachLop(lop *ds, int n) {
    for (int i = 0; i < n; i++) {
        printf("\nNhap thong tin lop thu %d:\n", i + 1);
        nhapThongTinLop(&ds[i]);
    }
}

