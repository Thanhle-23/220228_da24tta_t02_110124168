#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// C?u trúc ngày tháng
struct NGAY_THANG {
    int ngay;
    int thang;
    int nam;
};

typedef struct NGAY_THANG ngaysinh;

// C?u trúc môn h?c
struct MON_HOC {
    char mamon[10];
    float diem;
};

// C?u trúc l?p h?c
struct LOP_HOC {
    char malop[10];
    char tenlop[30];  // Ðã tang kích thu?c t? 10 lên 30
    int siso;
};

typedef struct LOP_HOC lophoc;

// C?u trúc sinh viên
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

// Hàm nh?p thông tin sinh viên
void nhap(SINH_VIEN *sv) {
    // Nh?p h? tên
    printf("\nNhap vao ho ten: ");
    fflush(stdin);
    fgets(sv->hoten, sizeof(sv->hoten), stdin);
    sv->hoten[strcspn(sv->hoten, "\n")] = '\0'; // Xóa ký t? newline

    // Nh?p mã s? sinh viên
    printf("\nHay cho biet mssv: ");
    scanf("%s", sv->mssv);

    // Nh?p d?a ch?
    printf("\nNhap vao dia chi: ");
    fflush(stdin);
    fgets(sv->diachi, sizeof(sv->diachi), stdin);
    sv->diachi[strcspn(sv->diachi, "\n")] = '\0'; // Xóa ký t? newline

    // Nh?p gi?i tính
    printf("\nNhap vao gioi tinh: ");
    fflush(stdin);
    fgets(sv->gioitinh, sizeof(sv->gioitinh), stdin);
    sv->gioitinh[strcspn(sv->gioitinh, "\n")] = '\0'; // Xóa ký t? newline

    // Nh?p ngày sinh
    printf("\nHay cho biet ngay sinh (ngay thang nam): ");
    scanf("%d %d %d", &sv->ngaysinh.ngay, &sv->ngaysinh.thang, &sv->ngaysinh.nam);

    // Nh?p s? môn h?c
    printf("\nNhap vao so mon hoc: ");
    scanf("%d", &sv->somon);

    // Nh?p thông tin môn h?c
    for (int i = 0; i < sv->somon; i++) {
        printf("Nhap ma mon hoc thu %d: ", i + 1);
        scanf("%s", sv->monhoc[i].mamon);
        printf("Nhap diem mon thu %d: ", i + 1);
        scanf("%f", &sv->monhoc[i].diem);
    }
}

// Hàm nh?p thông tin danh sách sinh viên
void nhapnsv(SINH_VIEN *ds, int n) {
    for (int i = 0; i < n; i++) {
        printf("\nNhap thong tin sinh vien thu %d: ", i + 1);
        nhap(&ds[i]);
    }
}

// Hàm nh?p thông tin l?p h?c
void nhapThongTinLop(lophoc *l) {
    printf("Nhap ma lop: ");
    scanf("%s", l->malop);

    printf("Nhap ten lop: ");
    fflush(stdin);
    fgets(l->tenlop, sizeof(l->tenlop), stdin);
    l->tenlop[strcspn(l->tenlop, "\n")] = '\0'; // Xóa ký t? newline

    printf("Nhap si so: ");
    scanf("%d", &l->siso);
}

// Hàm ghi danh sách l?p vào file
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

// Hàm nh?p danh sách l?p h?c
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

    // C?p phát b? nh? cho danh sách sinh viên
    SINH_VIEN *danh_sach = (SINH_VIEN *)malloc(n * sizeof(SINH_VIEN));
    if (danh_sach == NULL) {
        printf("Khong du bo nho\n");
        return 1;
    }

    // Nh?p danh sách sinh viên
    nhapnsv(danh_sach, n);

    // Nh?p tên t?p
    char tenTep[50];
    printf("\nNhap ten tep (vi du: phanso.dat): ");
    scanf("%s", tenTep);

    // Nh?p và ghi danh sách l?p vào file
    int nLop;
    printf("Nhap so lop: ");
    scanf("%d", &nLop);
    // Cấp phát bộ nhớ động cho danh sách lớp
    lophoc *dsLop = (lophoc *)malloc(nLop * sizeof(lophoc));
    if (dsLop == NULL) {
        printf("Khong du bo nho de cap phat cho danh sach lop.\n");
        return 1;
    }
    nhapDanhSachLop(dsLop, nLop);

    ghiDanhSachLopVaoFile(dsLop, nLop, tenTep);

    // Gi?i phóng b? nh?
    free(danh_sach);

    return 0;
}

