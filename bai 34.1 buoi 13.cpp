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
    char tenlop[30];
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

// H�m hi?n th? th�ng tin sinh vi�n
void hienThiSinhVien(sv *sv) {
    printf("\nHo ten: %s", sv->hoten);
    printf("\nMSSV: %s", sv->mssv);
    printf("\nDia chi: %s", sv->diachi);
    printf("\nGioi tinh: %s", sv->gioitinh);
    printf("\nNgay sinh: %d/%d/%d", sv->ngaysinh.ngay, sv->ngaysinh.thang, sv->ngaysinh.nam);
    printf("\nDanh sach mon hoc: ");
    for (int i = 0; i < sv->somon; i++) {
        printf("\n  - Mon %d: %s, Diem: %.2f", i + 1, sv->monhoc[i].mamon, sv->monhoc[i].diem);
    }
}

// H�m d?c danh s�ch l?p t? file
void docDanhSachLopTuFile(lophoc *ds, int *n, const char *tenTep) {
    FILE *f = fopen(tenTep, "rb");
    if (f == NULL) {
        printf("Khong the mo file.\n");
        return;
    }

    fread(n, sizeof(int), 1, f);
    for (int i = 0; i < *n; i++) {
        fread(&ds[i], sizeof(lophoc), 1, f);
    }

    fclose(f);
}

// H�m d?c danh s�ch sinh vi�n t? file
void docDanhSachSinhVienTuFile(sv *ds, int *n, const char *tenTep) {
    FILE *f = fopen(tenTep, "rb");
    if (f == NULL) {
        printf("Khong the mo file.\n");
        return;
    }

    fread(n, sizeof(int), 1, f);
    for (int i = 0; i < *n; i++) {
        fread(&ds[i], sizeof(sv), 1, f);
    }

    fclose(f);
}

// H�m hi?n th? danh s�ch sinh vi�n c?a l?p theo m� l?p
void hienThiSinhVienCuaLop(sv *ds, int n, char *maLop) {
    printf("\nDanh sach sinh vien cua lop %s:\n", maLop);
    int found = 0;
    for (int i = 0; i < n; i++) {
        if (strcmp(ds[i].lophoc.malop, maLop) == 0) {
            hienThiSinhVien(&ds[i]);
            found = 1;
        }
    }
    if (!found) {
        printf("\nKhong co sinh vien trong lop %s.", maLop);
    }
}

int main() {
    int n, nLop;
    char tenTep[50];
    char maLop[10];

    // Nh?p t�n file ch?a d? li?u
    printf("\nNhap ten tep (vi du: phanso.dat): ");
    scanf("%s", tenTep);

    // �?c danh s�ch l?p v� sinh vi�n t? file
    lophoc dsLop[10];
    sv dsSinhVien[100];
    docDanhSachLopTuFile(dsLop, &nLop, tenTep);
    docDanhSachSinhVienTuFile(dsSinhVien, &n, tenTep);

    // Nh?p m� l?p c?n t�m
    printf("\nNhap ma lop can tim: ");
    scanf("%s", maLop);

    // Hi?n th? danh s�ch sinh vi�n c?a l?p d�
    hienThiSinhVienCuaLop(dsSinhVien, n, maLop);

    return 0;
}

