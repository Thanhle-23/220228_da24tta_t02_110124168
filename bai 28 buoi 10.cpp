#include <stdio.h>

int main() {
    // Khai bao và khoi tao mang mot chieu kieu so nguyên
    int arr[] = {10, 20, 30, 40, 50};  // Mang vi du
    int n = sizeof(arr) / sizeof(arr[0]); // Tính so phan tu cua mang

    // Mo file de ghi
    FILE *file = fopen("output.txt", "w");
    
    if (file == NULL) {
        printf("Khong the mo file de ghi.\n");
        return 1;
    }

    // Ghi so phan tu vào dòng dau tiên
    fprintf(file, "%d\n", n);

    // Ghi danh sách các giá tri cua mang vào dòng thu hai, moi giá tri phân cách boi 2 khoang trang
    for (int i = 0; i < n; i++) {
        fprintf(file, "%d", arr[i]);
        if (i < n - 1) {
            fprintf(file, "  "); // Thêm 2 khoang trang giua các giá tri
        }
    }
    
    // Ðóng file sau khi ghi
    fclose(file);
    
    printf("Da ghi thanh cong vao file.\n");
    return 0;
}
