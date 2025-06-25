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
    int min=arr[0], temp=0;

    for (int i=0;i<n;i++) {
        if (min>arr[i]) {
            min=arr[i];
            temp=i;
        }
    }
    printf("%d", temp);
    free(arr);
    return 0;
}