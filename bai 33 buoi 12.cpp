#include <stdio.h>
#include <stdlib.h>

// Dinh nghia cau truc phan so
struct Phanso {
    int tuSo;
    int mauSo;
};
typedef struct Phanso Phanso;

// Khai bao ham
void nhapPhanSo(Phanso *ps);
void ghiPhanSo(Phanso *ds, int n, const char *tenTep);

int main() {
    int n;
    printf("\nNhap so luong phan so: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("\nSo luong phan so phai lon hon 0.\n");
        return 1;
    }

    // Cap phat bo nho cho danh sach phan so
    Phanso *ds = (Phanso *)malloc(n * sizeof(Phanso));
    if (ds == NULL) {
        printf("\nKhong cap phat duoc bo nho.\n");
        return 1;
    }

    // Nhap phan so
    for (int i = 0; i < n; i++) {
        printf("\nNhap phan so thu %d:", i + 1);
        nhapPhanSo(&ds[i]);
    }

    // Nhap ten tep
    char tenTep[50];
    printf("\nNhap ten tep (vi du: phanso.dat): ");
    scanf("%s", tenTep);

    // Ghi phan so vao tep
    ghiPhanSo(ds, n, tenTep);

    // Giai phong bo nho
    free(ds);
    return 0;
}

// Ham nhap phan so
void nhapPhanSo(Phanso *ps) {
    printf(" Nhap tu so: ");
    scanf("%d", &ps->tuSo);
    do {
        printf(" Nhap mau so khac 0: ");
        scanf("%d", &ps->mauSo);
        if (ps->mauSo == 0) {
            printf(" Mau so khong duoc bang 0. Vui long nhap lai.\n");
        }
    } while (ps->mauSo == 0);
}

// Ham ghi danh sach phan so vao tep
void ghiPhanSo(Phanso *ds, int n, const char *tenTep) {
    FILE *file = fopen(tenTep, "wb");
    if (file == NULL) {
        printf("\nLoi mo tep de ghi: %s\n", tenTep);
        return;
    }

    // Ghi du lieu
    size_t ghiDuoc = fwrite(ds, sizeof(Phanso), n, file);
    if (ghiDuoc == n) {
        printf("\nDa ghi danh sach %d phan so vao tep: %s\n", n, tenTep);
    } else {
        printf("\nLoi khi ghi du lieu vao tep.\n");
    }
    fclose(file);
}
