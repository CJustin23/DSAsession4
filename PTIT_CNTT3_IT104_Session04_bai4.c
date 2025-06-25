#include <stdio.h>
#include <stdlib.h>
int main(void) {
    int n;
    printf("Nhap vao so phan tu cua mang: ");
    scanf("%d", &n);
    int *arr=(int *)malloc(n*sizeof(int));
    printf("Nhap vao tung phan tu cua mang: \n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int num;
    printf("Nhap vao phan tu bat ky: ");
    scanf("%d", &num);
    int check=0, temp;
    for (int i = 0; i < n; i++) {
        if (arr[i] == num) {
            temp=i;
            check=1;
        }
    }
    if (check==0) {
        printf("Khong tim thay phan tu \n");
    }else {
        printf("%d", temp);
    }
    free(arr);
    return 0;
}