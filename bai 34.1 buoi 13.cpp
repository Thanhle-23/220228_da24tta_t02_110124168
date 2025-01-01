#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Cấu trúc ngày tháng
struct NGAY_THANG {
    int ngay;
    int thang;
    int nam;
};

typedef struct NGAY_THANG ngaysinh;

// Cấu trúc môn học
struct MON_HOC {
    char mamon[10];
    float diem;
};

// Cấu trúc lớp học
struct LOP_HOC {
    char malop[10];
    char tenlop[30];
    int siso;
};

typedef struct LOP_HOC lophoc;

// Cấu trúc sinh viên
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

// Hàm hiển thị thông tin sinh viên
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

// Hàm hiển thị thông tin lớp học
void hienThiLopHoc(lophoc *lop) {
    printf("\nMa lop: %s", lop->malop);
    printf("\nTen lop: %s", lop->tenlop);
    printf("\nSi so: %d", lop->siso);
}

// Hàm đọc danh sách lớp từ file
void docDanhSachLopTuFile(lophoc **ds, int *n, const char *tenTep) {
    FILE *f = fopen(tenTep, "rb");
    if (f == NULL) {
        printf("Khong the mo file.\n");
        return;
    }

    fread(n, sizeof(int), 1, f);
    *ds = (lophoc *)malloc(*n * sizeof(lophoc));
    if (*ds == NULL) {
        printf("Khong du bo nho de cap phat danh sach lop.\n");
        fclose(f);
        return;
    }

    for (int i = 0; i < *n; i++) {
        fread(&(*ds)[i], sizeof(lophoc), 1, f);
    }

    fclose(f);
}
void hienThiSinhVienCuaLop(sv *ds, int n, const char *maLop) {
    printf("\nDanh sach sinh vien cua lop %s:\n", maLop);
    int found = 0;
    for (int i = 0; i < n; i++) {
        if (strcmp(ds[i].lophoc.malop, maLop) == 0) {
            hienThiSinhVien(&ds[i]);
            found = 1;
        }
    }
    if (!found) {
        printf("Khong co sinh vien nao trong lop %s.\n", maLop);
    }
}

// Hàm đọc danh sách sinh viên từ file
void docDanhSachSinhVienTuFile(sv **ds, int *n, const char *tenTep) {
    FILE *f = fopen(tenTep, "rb");
    if (f == NULL) {
        printf("Khong the mo file.\n");
        return;
    }

    fread(n, sizeof(int), 1, f);
    *ds = (sv *)malloc(*n * sizeof(sv));
    if (*ds == NULL) {
        printf("Khong du bo nho de cap phat danh sach sinh vien.\n");
        fclose(f);
        return;
    }

    for (int i = 0; i < *n; i++) {
        fread(&(*ds)[i], sizeof(sv), 1, f);
    }

    fclose(f);
}
void thongKeGioiTinhTheoLop(sv *ds, int n, lophoc *dsLop, int nLop) {
    printf("\nThong ke so sinh vien nam, nu cua moi lop:\n");
    for (int i = 0; i < nLop; i++) {
        int nam = 0, nu = 0;
        for (int j = 0; j < n; j++) {
            if (strcmp(ds[j].lophoc.malop, dsLop[i].malop) == 0) {
                if (strcmp(ds[j].gioitinh, "Nam") == 0) {
                    nam++;
                } else if (strcmp(ds[j].gioitinh, "Nu") == 0) {
                    nu++;
                }
            }
        }
        printf("\nLop %s (%s):\n", dsLop[i].malop, dsLop[i].tenlop);
        printf("  - So sinh vien nam: %d\n", nam);
        printf("  - So sinh vien nu: %d\n", nu);
    }
}

// Hàm thống kê danh sách sinh viên còn nợ môn học
void thongKeNoMon(sv *ds, int n) {
    printf("\nDanh sach sinh vien con no mon hoc (diem < 5):\n");
    int found = 0;
    for (int i = 0; i < n; i++) {
        int soMonNo = 0;
        for (int j = 0; j < ds[i].somon; j++) {
            if (ds[i].monhoc[j].diem < 5) {
                soMonNo++;
            }
        }

        if (soMonNo > 0) {
            found = 1;
            printf("\nSinh vien: %s (MSSV: %s)", ds[i].hoten, ds[i].mssv);
            printf("\nSo mon no: %d", soMonNo);
            printf("\nDanh sach mon no:");
            for (int j = 0; j < ds[i].somon; j++) {
                if (ds[i].monhoc[j].diem < 5) {
                    printf("\n  - Mon: %s, Diem: %.2f", ds[i].monhoc[j].mamon, ds[i].monhoc[j].diem);
                }
            }
            printf("\n");
        }
    }

    if (!found) {
        printf("\nKhong co sinh vien nao con no mon hoc.");
    }
}

int main() {
    int n, nLop;
    char tenTep[50];
    char maLop[10];

    // Nhập tên file chứa dữ liệu
    printf("\nNhap ten tep (vi du: phanso.dat): ");
    scanf("%s", tenTep);

    // Đọc danh sách lớp và sinh viên từ file
    lophoc *dsLop;
    sv *dsSinhVien;
    docDanhSachLopTuFile(&dsLop, &nLop, tenTep);
    docDanhSachSinhVienTuFile(&dsSinhVien, &n, tenTep);

    // Hiển thị danh sách lớp học
    printf("\nDanh sach cac lop hoc:\n");
    for (int i = 0; i < nLop; i++) {
        hienThiLopHoc(&dsLop[i]);
    }

    // Thống kê số sinh viên nam, nữ của mỗi lớp
    thongKeGioiTinhTheoLop(dsSinhVien, n, dsLop, nLop);

    // Thống kê danh sách sinh viên còn nợ môn
    thongKeNoMon(dsSinhVien, n);

    // Nhập mã lớp cần tìm
    printf("\nNhap ma lop can tim: ");
    scanf("%s", maLop);

    // Hiển thị danh sách sinh viên của lớp đó
    hienThiSinhVienCuaLop(dsSinhVien, n, maLop);

    // Giải phóng bộ nhớ
    free(dsLop);
    free(dsSinhVien);

    return 0;
}
