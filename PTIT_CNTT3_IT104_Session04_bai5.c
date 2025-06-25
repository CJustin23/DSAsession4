#include <stdio.h>
#include <stdlib.h>

int main(void) {
    // Nhập số phần tử của mảng
    int n;
    printf("Nhap vao so phan tu cua mang: ");
    scanf("%d", &n);

    // Cấp phát bộ nhớ động cho mảng có n phần tử
    int *arr = (int *)malloc(n * sizeof(int));

    // Nhập giá trị từng phần tử của mảng
    printf("Nhap vao tung phan tu cua mang:\n");
    for (int i = 0; i < n; i++) {
        printf("Phan tu thu %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    // Sắp xếp mảng tăng dần bằng thuật toán Bubble Sort
    for (int i = 0; i < n - 1; i++) {               // Duyệt qua n-1 lần
        for (int j = 0; j < n - 1 - i; j++) {       // So sánh từng cặp kế nhau
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];                  // Đổi chỗ nếu chưa đúng thứ tự
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    // Nhập giá trị cần kiểm tra trong mảng đã sắp xếp
    int num;
    printf("Nhap vao phan tu can kiem tra: ");
    scanf("%d", &num);

    // Tìm kiếm nhị phân (binary search)
    int left = 0;
    int right = n - 1;
    int check = 0;

    while (left <= right) {
        int mid = left + (right - left) / 2; // Tìm chỉ số giữa

        if (arr[mid] == num) {
            check = 1;     // Tìm thấy phần tử
            break;
        }

        if (arr[mid] < num)
            left = mid + 1;   // Tìm ở nửa bên phải
        else
            right = mid - 1;  // Tìm ở nửa bên trái
    }

    // Thông báo kết quả tìm kiếm
    if (check == 1) {
        printf("Phan tu co trong mang\n");
    } else {
        printf("Phan tu khong co trong mang\n");
    }

    // Giải phóng vùng nhớ đã cấp phát
    free(arr);

    return 0;
}
