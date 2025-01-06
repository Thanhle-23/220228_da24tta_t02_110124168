#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Ð?nh nghia c?u trúc Sinh viên
typedef struct {
    int id;              // Mã sinh viên
    char hoTen[50];      // H? và tên
    float diemTB;        // Ði?m trung bình
} SinhVien;

void nhapsv(SinhVien *sinhvien){
	printf("ten: ");
	fflush(stdin);
	gets(sinhvien->hoTen);
	printf("id");
	scanf("%d",&sinhvien->id);
	printf("diem:");
	scanf("%f",&sinhvien->diemTB);
}
void nhapdssv(SinhVien *danhsach, int n){
	for (int i=0;i<n;i++){
		nhapsv(&danhsach[i]);
	}
}
void ghifile(const char *tenTep, SinhVien *danhsach, int n){
	FILE *file = fopen(tenTep,"wb");
	if(tenTep==NULL){
		printf("loi");
	}
	else{
		fwrite(danhsach, sizeof(SinhVien),n, file);
		fclose(file);
	}
}
void docfile(const char *tenTep){
	FILE *file = fopen(tenTep,"rb");
	if(file==NULL){
		printf("loi");
	}
	else{
		SinhVien sv;
		fread(&sv, sizeof(SinhVien),1,file);
		printf("%d""%s""%f",sv.id,sv.hoTen,sv.diemTB);
	}
}
int main(){
	int n;
	const char *tenTep="sinhvien.out";
	scanf("%d",&n);
	SinhVien *danhsach = (SinhVien*)malloc(sizeof(SinhVien)*n);
	nhapdssv(danhsach,n);
	ghifile(tenTep,danhsach,n);
	docfile(tenTep);
	free(danhsach);
	return 0;
	
}
