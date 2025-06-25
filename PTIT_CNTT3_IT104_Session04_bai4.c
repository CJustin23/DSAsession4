#include <stdio.h>
#include <stdlib.h>

int main(void) {
    // Nhập số lượng phần tử của mảng
    int n;
    printf("Nhap vao so phan tu cua mang: ");
    scanf("%d", &n);

    // Cấp phát bộ nhớ động cho mảng với n phần tử
    int *arr = (int *)malloc(n * sizeof(int));

    // Nhập các phần tử vào mảng
    printf("Nhap vao tung phan tu cua mang:\n");
    for (int i = 0; i < n; i++) {
        printf("Phan tu thu %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    // Nhập giá trị cần tìm trong mảng
    int num;
    printf("Nhap vao phan tu bat ky: ");
    scanf("%d", &num);

    // Biến check dùng để kiểm tra có tìm thấy hay không
    // Biến temp lưu lại vị trí cuối cùng tìm thấy
    int check = 0, temp;

    // Tìm kiếm trong mảng
    for (int i = 0; i < n; i++) {
        if (arr[i] == num) {
            temp = i;   // lưu lại vị trí tìm thấy
            check = 1;  // đánh dấu là đã tìm thấy
        }
    }

    // Kiểm tra kết quả tìm kiếm
    if (check == 0) {
        printf("Khong tim thay phan tu\n");
    } else {
        printf("Phan tu %d xuat hien cuoi cung tai chi so %d\n", num, temp);
    }

    // Giải phóng vùng nhớ đã cấp phát
    free(arr);

    return 0;
}
