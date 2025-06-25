#include <stdio.h>
#include <stdlib.h>

int main(void) {
    // Nhập số phần tử của mảng
    int n;
    printf("Nhap vao so phan tu cua mang: ");
    scanf("%d", &n);

    // Cấp phát bộ nhớ động cho mảng
    int *arr = (int *)malloc(n * sizeof(int));

    // Nhập các phần tử vào mảng
    printf("Nhap vao tung phan tu cua mang:\n");
    for (int i = 0; i < n; i++) {
        printf("Phan tu thu %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    // Nhập giá trị cần tìm
    int num;
    printf("Nhap vao phan tu bat ky: ");
    scanf("%d", &num);

    // Biến check để kiểm tra có tìm thấy không
    int check = 0;

    // Duyệt qua mảng để tìm tất cả vị trí xuất hiện của num
    for (int i = 0; i < n; i++) {
        if (arr[i] == num) {
            printf("Tim thay tai vi tri index: %d\n", i);
            check = 1;
        }
    }

    // Nếu không tìm thấy phần tử nào khớp
    if (check == 0) {
        printf("Khong tim thay phan tu\n");
    }

    // Giải phóng bộ nhớ đã cấp phát
    free(arr);

    return 0;
}
