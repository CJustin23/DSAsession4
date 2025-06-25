#include <stdio.h>
#include <stdlib.h>

int main(void) {
    // Nhập số lượng phần tử của mảng
    int n;
    printf("Nhap so phan tu cua mang: ");
    scanf("%d", &n);

    // Cấp phát bộ nhớ động cho mảng với n phần tử
    int *arr = (int *)malloc(n * sizeof(int));

    // Nhập các phần tử vào mảng
    for (int i = 0; i < n; i++) {
        printf("Phan tu thu %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    // Khởi tạo biến max là phần tử đầu tiên, temp là chỉ số của max
    int max = arr[0], temp = 0;

    // Tìm phần tử lớn nhất và chỉ số của nó
    for (int i = 0; i < n; i++) {
        if (max < arr[i]) {
            max = arr[i];   // cập nhật giá trị lớn nhất
            temp = i;       // lưu lại chỉ số của phần tử lớn nhất
        }
    }

    // In ra chỉ số của phần tử lớn nhất
    printf("Chi so cua phan tu lon nhat la: %d\n", temp);

    // Giải phóng bộ nhớ đã cấp phát
    free(arr);

    return 0;
}
