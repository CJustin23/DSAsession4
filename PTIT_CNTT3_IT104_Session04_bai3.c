#include <stdio.h>
#include <stdlib.h>

int main(void) {
    // Nhập số lượng phần tử của mảng
    int n;
    printf("Nhap so phan tu cua mang: ");
    scanf("%d", &n);

    // Cấp phát bộ nhớ động cho mảng có n phần tử
    int *arr = (int *)malloc(n * sizeof(int));

    // Nhập từng phần tử cho mảng
    for (int i = 0; i < n; i++) {
        printf("Phan tu thu %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    // Khởi tạo biến min là phần tử đầu tiên, temp là chỉ số của min
    int min = arr[0], temp = 0;

    // Tìm phần tử nhỏ nhất và chỉ số của nó
    for (int i = 0; i < n; i++) {
        if (min > arr[i]) {
            min = arr[i];   // cập nhật giá trị nhỏ nhất
            temp = i;       // lưu lại chỉ số của phần tử nhỏ nhất
        }
    }

    // In ra chỉ số của phần tử nhỏ nhất
    printf("Chi so cua phan tu nho nhat la: %d\n", temp);

    // Giải phóng vùng nhớ đã cấp phát
    free(arr);

    return 0;
}
