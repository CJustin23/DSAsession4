#include <stdio.h>
#include <stdlib.h>

int main(void) {
    // Nhập số lượng phần tử của mảng
    int n;
    printf("Nhap vao so luong phan tu cua mang: ");
    scanf("%d", &n);

    // Cấp phát bộ nhớ động cho mảng với n phần tử
    int *arr = (int *)malloc(n * sizeof(int));

    // Nhập các phần tử vào mảng
    for (int i = 0; i < n; i++) {
        printf("Phan tu thu %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    // Biến kiểm tra có tồn tại cặp đối xứng hay không
    int check = 0;

    // Duyệt từ đầu đến giữa mảng, so sánh cặp đối xứng với cuối
    for (int i = 0; i < (n / 2); i++) {
        if (arr[i] == arr[n - i - 1]) {
            check = 1; // Đánh dấu đã tìm thấy cặp đối xứng
            printf("Cap doi xung: (%d)(%d)\n", arr[i], arr[n - i - 1]);
        }
    }

    // Nếu không có cặp đối xứng nào được tìm thấy
    if (!check) {
        printf("Khong co phan tu doi xung\n");
    }

    // Giải phóng vùng nhớ đã cấp phát
    free(arr);

    return 0;
}
