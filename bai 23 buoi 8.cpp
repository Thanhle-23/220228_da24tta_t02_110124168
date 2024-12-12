
#include<stdio.h>
#include<string.h>

struct MON_HOC{
	char mamon[10];
	float diem;
};

struct SINH_VIEN{
	char hoten[30], diachi[100], gioitinh[4];
	int ngaysinh, mssv, somon;
	MON_HOC monhoc[10];
} ;
typedef struct SINH_VIEN sv;

void nhap(SINH_VIEN *sv);
void xuat(SINH_VIEN sv);
int main()
{
	SINH_VIEN sv;
	
	nhap(&sv);
	
	printf("\nThong tin vua nhap la: \n");
	xuat(sv);
	
	return 0;
}

void xuat(SINH_VIEN sv)
{
	printf("%s\t%s\t%s\t%d\t%d\t", sv.hoten, sv.diachi, sv.gioitinh, sv.ngaysinh, sv.somon);
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
	scanf("%d", &sv->ngaysinh);
	
	//Nhap thanh phan mon hoc
	printf("\nNhap vao so mon hoc: ");
	scanf("%d",&sv->somon);
	
	for(int i=0; i < sv->somon; i++){
		printf("Nhap ma mon hoc thu %d ", i+1);
		scanf("%s",sv->monhoc[i].mamon);
		printf("Nhap diem mon thu %d ", i+1);
		scanf("%f",sv->monhoc[i].diem);
	}
}
