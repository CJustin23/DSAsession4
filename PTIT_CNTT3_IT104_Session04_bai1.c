#include <stdio.h>
#include <stdlib.h>

int main(void) {
    // Nhập số phần tử của mảng
    int n;
    printf("Nhap vao so phan tu cua mang: ");
    scanf("%d", &n);

    // Cấp phát bộ nhớ động cho mảng có n phần tử
    int *arr = (int *)malloc(n * sizeof(int));

    // Nhập các phần tử cho mảng
    printf("Nhap vao tung phan tu cua mang:\n");
    for (int i = 0; i < n; i++) {
        printf("Phan tu thu %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    // Nhập giá trị cần tìm
    int num;
    printf("Nhap vao phan tu bat ky: ");
    scanf("%d", &num);

    // Biến kiểm tra xem có tìm thấy không
    int check = 0;

    // Tìm kiếm phần tử trong mảng
    for (int i = 0; i < n; i++) {
        if (arr[i] == num) {
            printf("Phan tu %d nam tai vi tri index %d\n", num, i);
            check = 1;
            break;
        }
    }

    // Nếu không tìm thấy
    if (check == 0) {
        printf("Khong tim thay phan tu %d trong mang.\n", num);
    }

    // Giải phóng vùng nhớ
    free(arr);

    return 0;
}
