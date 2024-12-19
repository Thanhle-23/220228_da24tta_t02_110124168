#include <stdio.h>

int main() {
    // Khai bao v� khoi tao mang mot chieu kieu so nguy�n
    int arr[] = {10, 20, 30, 40, 50};  // Mang vi du
    int n = sizeof(arr) / sizeof(arr[0]); // T�nh so phan tu cua mang

    // Mo file de ghi
    FILE *file = fopen("output.txt", "w");
    
    if (file == NULL) {
        printf("Khong the mo file de ghi.\n");
        return 1;
    }

    // Ghi so phan tu v�o d�ng dau ti�n
    fprintf(file, "%d\n", n);

    // Ghi danh s�ch c�c gi� tri cua mang v�o d�ng thu hai, moi gi� tri ph�n c�ch boi 2 khoang trang
    for (int i = 0; i < n; i++) {
        fprintf(file, "%d", arr[i]);
        if (i < n - 1) {
            fprintf(file, "  "); // Th�m 2 khoang trang giua c�c gi� tri
        }
    }
    
    // ��ng file sau khi ghi
    fclose(file);
    
    printf("Da ghi thanh cong vao file.\n");
    return 0;
}
