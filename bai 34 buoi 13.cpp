#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// C?u tr�c ng�y th�ng
struct NGAY_THANG {
    int ngay;
    int thang;
    int nam;
};

typedef struct NGAY_THANG ngaysinh;

// C?u tr�c m�n h?c
struct MON_HOC {
    char mamon[10];
    float diem;
};

// C?u tr�c l?p h?c
struct LOP_HOC {
    char malop[10];
    char tenlop[30];  // �� tang k�ch thu?c t? 10 l�n 30
    int siso;
};

typedef struct LOP_HOC lophoc;

// C?u tr�c sinh vi�n
struct SINH_VIEN {
    char hoten[30];
    char diachi[100];
    char gioitinh[4];
    char mssv[10];
    int somon;
    NGAY_THANG ngaysinh;
    MON_HOC monhoc[10];
    LOP_HOC lophoc;
};

typedef struct SINH_VIEN sv;

// H�m nh?p th�ng tin sinh vi�n
void nhap(SINH_VIEN *sv) {
    // Nh?p h? t�n
    printf("\nNhap vao ho ten: ");
    fflush(stdin);
    fgets(sv->hoten, sizeof(sv->hoten), stdin);
    sv->hoten[strcspn(sv->hoten, "\n")] = '\0'; // X�a k� t? newline

    // Nh?p m� s? sinh vi�n
    printf("\nHay cho biet mssv: ");
    scanf("%s", sv->mssv);

    // Nh?p d?a ch?
    printf("\nNhap vao dia chi: ");
    fflush(stdin);
    fgets(sv->diachi, sizeof(sv->diachi), stdin);
    sv->diachi[strcspn(sv->diachi, "\n")] = '\0'; // X�a k� t? newline

    // Nh?p gi?i t�nh
    printf("\nNhap vao gioi tinh: ");
    fflush(stdin);
    fgets(sv->gioitinh, sizeof(sv->gioitinh), stdin);
    sv->gioitinh[strcspn(sv->gioitinh, "\n")] = '\0'; // X�a k� t? newline

    // Nh?p ng�y sinh
    printf("\nHay cho biet ngay sinh (ngay thang nam): ");
    scanf("%d %d %d", &sv->ngaysinh.ngay, &sv->ngaysinh.thang, &sv->ngaysinh.nam);

    // Nh?p s? m�n h?c
    printf("\nNhap vao so mon hoc: ");
    scanf("%d", &sv->somon);

    // Nh?p th�ng tin m�n h?c
    for (int i = 0; i < sv->somon; i++) {
        printf("Nhap ma mon hoc thu %d: ", i + 1);
        scanf("%s", sv->monhoc[i].mamon);
        printf("Nhap diem mon thu %d: ", i + 1);
        scanf("%f", &sv->monhoc[i].diem);
    }
}

// H�m nh?p th�ng tin danh s�ch sinh vi�n
void nhapnsv(SINH_VIEN *ds, int n) {
    for (int i = 0; i < n; i++) {
        printf("\nNhap thong tin sinh vien thu %d: ", i + 1);
        nhap(&ds[i]);
    }
}

// H�m nh?p th�ng tin l?p h?c
void nhapThongTinLop(lophoc *l) {
    printf("Nhap ma lop: ");
    scanf("%s", l->malop);

    printf("Nhap ten lop: ");
    fflush(stdin);
    fgets(l->tenlop, sizeof(l->tenlop), stdin);
    l->tenlop[strcspn(l->tenlop, "\n")] = '\0'; // X�a k� t? newline

    printf("Nhap si so: ");
    scanf("%d", &l->siso);
}

// H�m ghi danh s�ch l?p v�o file
void ghiDanhSachLopVaoFile(lophoc *ds, int n, const char *tenTep) {
    FILE *f = fopen(tenTep, "wb");
    if (f == NULL) {
        printf("Khong the mo file.\n");
        return;
    }

    fwrite(&n, sizeof(int), 1, f);
    for (int i = 0; i < n; i++) {
        fwrite(&ds[i], sizeof(lophoc), 1, f);
    }

    fclose(f);
}

// H�m nh?p danh s�ch l?p h?c
void nhapDanhSachLop(lophoc *ds, int n) {
    for (int i = 0; i < n; i++) {
        printf("\nNhap thong tin lop thu %d:\n", i + 1);
        nhapThongTinLop(&ds[i]);
    }
}

int main() {
    int n;
    printf("Nhap so luong sinh vien: ");
    scanf("%d", &n);

    // C?p ph�t b? nh? cho danh s�ch sinh vi�n
    SINH_VIEN *danh_sach = (SINH_VIEN *)malloc(n * sizeof(SINH_VIEN));
    if (danh_sach == NULL) {
        printf("Khong du bo nho\n");
        return 1;
    }

    // Nh?p danh s�ch sinh vi�n
    nhapnsv(danh_sach, n);

    // Nh?p t�n t?p
    char tenTep[50];
    printf("\nNhap ten tep (vi du: phanso.dat): ");
    scanf("%s", tenTep);

    // Nh?p v� ghi danh s�ch l?p v�o file
    lophoc dsLop[10];
    int nLop;
    printf("Nhap so lop: ");
    scanf("%d", &nLop);
    nhapDanhSachLop(dsLop, nLop);

    ghiDanhSachLopVaoFile(dsLop, nLop, tenTep);

    // Gi?i ph�ng b? nh?
    free(danh_sach);

    return 0;
}

