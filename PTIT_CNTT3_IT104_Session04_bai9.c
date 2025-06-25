#include <stdio.h>
#include <stdlib.h>

// Hàm tìm kiếm nhị phân đệ quy
int searchNumber(int arr[], int left, int right, int num) {
    // Nếu vùng tìm kiếm không hợp lệ
    if (left > right) return -1;

    int mid = left + (right - left) / 2;

    if (arr[mid] == num) {
        return mid; // Tìm thấy -> trả về vị trí
    }
    if (arr[mid] < num) {
        // Tìm bên phải
        return searchNumber(arr, mid + 1, right, num);
    } else {
        // Tìm bên trái
        return searchNumber(arr, left, mid - 1, num);
    }
}

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

    // Sắp xếp mảng bằng thuật toán Bubble Sort
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    // Nhập giá trị cần kiểm tra
    int num;
    printf("Nhap vao phan tu can kiem tra: ");
    scanf("%d", &num);

    int left = 0;
    int right = n - 1;

    // Gọi hàm tìm kiếm nhị phân
    int result = searchNumber(arr, left, right, num);

    // Kiểm tra kết quả
    if (result != -1) {
        printf("Phan tu co trong mang tai vi tri index: %d\n", result);
    } else {
        printf("Phan tu khong co trong mang\n");
    }

    // Giải phóng bộ nhớ
    free(arr);

    return 0;
}
