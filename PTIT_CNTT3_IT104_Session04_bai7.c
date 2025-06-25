#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n;
    printf("Nhap vao so luong phan tu cua mang: ");
    scanf("%d", &n);
    int *arr=(int *)malloc(n*sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int check=0;
    for (int i=0; i<(n/2); i++) {
        if (arr[i]==arr[n-i-1]) {
            check=1;
            printf("Cap doi xung: (%d)(%d) \n", arr[i], arr[n-i-1]);
        }
    }
    if (!check) {
        printf("Khong co phan tu doi xung \n");
    }
    free(arr);
    return 0;
}