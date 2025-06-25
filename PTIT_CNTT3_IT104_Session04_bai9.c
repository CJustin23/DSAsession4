#include <stdio.h>
#include <stdlib.h>
int searchNumber( int arr[],int left,int right,int num) {
    int mid = left + (right - left) / 2;
    if (arr[mid] == num) {
        return mid;
    }
    if (arr[mid] < num) {
        return searchNumber(arr, mid+1,right,num);
    }else {
        return searchNumber(arr, left,mid-1,num);
    }
}
int main(void) {
    int n;
    printf("Nhap vao so phan tu cua mang: ");
    scanf("%d", &n);
    int *arr=(int *)malloc(n*sizeof(int));

    printf("Nhap vao tung phan tu cua mang: \n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (arr[j]>arr[j+1]) {
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    int num;
    printf("Nhap vao phan tu can kiem tra: ");
    scanf("%d", &num);
    int left = 0;
    int right = n - 1;

    if (searchNumber(arr, left, right, num)) {
        printf("Phan tu co trong mang");
    }else {
        printf("Phan tu khong co trong mang");
    }
    free(arr);
    return 0;
}