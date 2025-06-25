#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n;
    printf("Nhap so phan tu cua mang: ");
    scanf("%d", &n);
    int *arr=(int *)malloc(n*sizeof(int));
    for(int i=0;i<n;i++) {
        scanf("%d", &arr[i]);
    }
    int max=arr[0], temp=0;

    for (int i=0;i<n;i++) {
        if (max<arr[i]) {
            max=arr[i];
            temp=i;
        }
    }
    printf("%d", temp);
    free(arr);

    return 0;
}