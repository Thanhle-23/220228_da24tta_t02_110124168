#include <stdio.h>
#include <stdlib.h>

int main() {
    int *p, n;
    FILE *file;

    // Mo file de doc
    file = fopen("output.txt", "r");

    if (file == NULL) {
        printf("Khong the mo file de doc.\n");
        return 1;
    }

    // Doc so phan tu tu dong dau tien cua file
    fscanf(file, "%d", &n);

    // Cap phat vung nho dong cho mang
    p = (int *)malloc(n * sizeof(int));

    if (p == NULL) {
        printf("Cap phat bo nho that bai.\n");
        fclose(file);
        return 1;
    }

    // Doc danh sach cac gia tri tu file vao vung nho da cap phat
    for (int i = 0; i < n; i++) {
        fscanf(file, "%d", &p[i]);
    }

    // In cac gia tri vua doc ra man hinh
    printf("Danh sach cac gia tri trong mang:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", p[i]);
    }
    printf("\n");

    // Giai phong bo nho da cap phat
    free(p);

    // Dong file
    fclose(file);

    return 0;
}

