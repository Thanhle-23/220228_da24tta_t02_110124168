
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct NGAY_THANG{
	int ngay;
	int thang;
	int nam;
};

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

void nhap(SINH_VIEN *sv);
void xuat(SINH_VIEN sv);
void nhapnsv(SINH_VIEN *sv);
void timSVmssv(SINH_VIEN *ds, int n, char mssv);
int main()
{
	SINH_VIEN sv;
	
	nhap(&sv);
	
	printf("\nThong tin vua nhap la: \n");
	xuat(sv);
	
	nhapnsv(&sv);
	
	char mssv_tim[10];
    printf("\nNhap MSSV can tim: ");
    scanf("%s", mssv_tim);

    SINH_VIEN *ket_qua = timSVmssv(danh_sach, so_luong, mssv_tim);
    if (ket_qua != NULL) {
        printf("\nThong tin sinh vien tim thay:\n");
        xuat(ket_qua);
    } else {
        printf("\nKhong tim thay sinh vien co MSSV %s.\n", mssv_tim);
    }

    for (int i = 0; i < so_luong; i++) {
        free(danh_sach[i].mon_hoc);
    }
    free(danh_sach);

	return 0;
}

void xuat(SINH_VIEN sv)
{
	printf("%s\t%s\t%s\t%s\t%d\t%d\t", sv.hoten, sv.mssv, sv.diachi, sv.gioitinh, sv.ngaysinh, sv.somon);
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
void nhapnsv(SINH_VIEN *ds, int *n){
		int n;
	printf("\nnhap so luong sinh vien: ");
	scanf("%d",&n);
	*ds=(SINH_VIEN*)malloc((*n)*sizeof(SINH_VIEN));
	for(int i=0; i<*n;i++){
		printf("\nnhap thong tin sinh vien thu %d: ",i+1);
		nhap(&(*ds)[i]);
	}
	printf("\n THong tin danh sach sinh vien");
	for(int i=0; i<n; i++){
		printf("\nSinh vien thu %d: ",i+1);
		xuat(&ds[i])	;
	}
}
void timSVmssv(SINH_VIEN*ds, int n, char *mssv){
	for(int i=0;i<n;i++){
		if(strcmp(ds[i].mssv, mssv)==0){
			return (SINH_VIEN*)&ds[i];
		}
	}
	return NULL;
}
