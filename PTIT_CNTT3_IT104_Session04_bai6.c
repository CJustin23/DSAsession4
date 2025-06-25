#include <stdio.h>
#include <string.h>

struct Student {
    int id;
    char name[50];
    int age;
};
int main(void) {
    int n;
    printf("Nhap so luong phan tu sinh vien: ");
    scanf("%d", &n);
    struct Student student[n];
    for (int i = 0; i < n; i++) {
        printf("Nhap thong tin sv thu %d \n", i+1);
        student[i].id=i+1;
        printf("Name: ");
        getchar();
        fgets(student[i].name, 50, stdin);
        student[i].name[strcspn(student[i].name, "\n")] = '\0';
        printf("Age: ");
        scanf("%d", &student[i].age);
    }

    int findId, check=0;
    printf("Nhap ID can tim: ");
    scanf("%d", &findId);
    for (int i = 0; i < n; i++) {
        if (student[i].id == findId) {
            check=1;
            printf("ID: %d\n", student[i].id);
            printf("Name: %s\n", student[i].name);
            printf("Age: %d\n", student[i].age);
        }
    }
    if (check==0) {
        printf("Sinh vien khong ton tai");
    }
    return 0;
}