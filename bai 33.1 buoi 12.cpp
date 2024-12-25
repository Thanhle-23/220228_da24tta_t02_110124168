#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Phanso {
    int tuSo;
    int mauSo;
};
typedef struct Phanso Phanso;

// Khai bao ham
void xuatPhanSo(Phanso ps);
void rutGonPhanSo(Phanso *ps);
int docDanhSachPhanSo(const char *tenTep, Phanso **ds);
Phanso timPhanSoNhoNhat(Phanso ds[], int n);

int main() {
    Phanso *ds = NULL;
    int n;
    char tenTep[50];

    printf("Nhap ten tep (tep nhi phan): ");
    scanf("%s", tenTep);

    // Doc danh sach phan so tu file
    n = docDanhSachPhanSo(tenTep, &ds);
    if (n <= 0) {
        printf("Khong co phan so nao trong tep hoac loi doc tep.\n");
        return 1;
    }

    // Rut gon va hien thi danh sach phan so
    printf("\nDanh sach phan so sau khi rut gon:\n");
    for (int i = 0; i < n; i++) {
        rutGonPhanSo(&ds[i]);
        xuatPhanSo(ds[i]);
    }

    // Tim phan so nho nhat
    Phanso phanSoNhoNhat = timPhanSoNhoNhat(ds, n);
    printf("\nPhan so nho nhat: %d/%d\n", phanSoNhoNhat.tuSo, phanSoNhoNhat.mauSo);

    // Giai phong bo nho
    free(ds);
    return 0;
}

void xuatPhanSo(Phanso ps) {
    if (ps.mauSo == 1) {
        printf("%d\n", ps.tuSo);
    } else {
        printf("%d/%d\n", ps.tuSo, ps.mauSo);
    }
}

int ucln(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return abs(a);
}

void rutGonPhanSo(Phanso *ps) {
    int ucln2 = ucln(ps->tuSo, ps->mauSo);
    ps->tuSo /= ucln2;
    ps->mauSo /= ucln2;
    if (ps->mauSo < 0) { // Dam bao mau so luon duong
        ps->tuSo = -ps->tuSo;
        ps->mauSo = -ps->mauSo;
    }
}

int docDanhSachPhanSo(const char *tenTep, Phanso **ds) {
    FILE *file = fopen(tenTep, "rb");
    if (file == NULL) {
        printf("Loi mo tep: %s\n", tenTep);
        return -1;
    }

    // Tinh so luong phan so trong tep
    fseek(file, 0, SEEK_END);
    int fileSize = ftell(file);
    fseek(file, 0, SEEK_SET);

    int n = fileSize / sizeof(Phanso);
    if (n <= 0) {
        fclose(file);
        return 0;
    }

    // Cap phat bo nho cho danh sach phan so
    *ds = (Phanso *)malloc(n * sizeof(Phanso));
    if (*ds == NULL) {
        printf("Loi cap phat bo nho.\n");
        fclose(file);
        return -1;
    }

    // Doc danh sach phan so tu file
    fread(*ds, sizeof(Phanso), n, file);
    fclose(file);
    return n;
}

Phanso timPhanSoNhoNhat(Phanso ds[], int n) {
    Phanso min = ds[0];
    for (int i = 1; i < n; i++) {
        if ((double)ds[i].tuSo / ds[i].mauSo < (double)min.tuSo / min.mauSo) {
            min = ds[i];
        }
    }
    return min;
}
