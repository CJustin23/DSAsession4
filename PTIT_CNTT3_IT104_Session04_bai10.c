#include <stdio.h>
#include <string.h>
#include <ctype.h>
struct Student {
    int id;
    char name[20];
    int age;
};

void toLowerCase(char str[]) {
    for (int i = 0; str[i] != '\0'; i++)
        str[i] = tolower(str[i]);
}
int main(void) {
    struct Student student [5];
    for (int i = 0; i < 5; i++) {
        printf("Nhap trong tin sin vien thu %d \n", i+1);
        student[i].id = i+1;
        printf("Name: ");
        fgets(student[i].name,20,stdin);
        student[i].name[strcspn(student[i].name,"\n")]='\0';
        printf("Age: ");
        scanf("%d", &student[i].age);
        getchar();
    }
    for (int i = 0; i < 5; i++) {
        printf(" \n Nhap trong tin sin vien thu %d", i+1);
        printf("ID: %d", student[i].id);
        printf("Name: %s", student[i].name);
        printf("Age: %d", student[i].age);
    }

    char searchName[20];
    printf("\nNhap ten can tim: ");
    fgets(searchName, sizeof(searchName), stdin);
    searchName[strcspn(searchName, "\n")] = '\0';
    toLowerCase(searchName);

    int find =0;
    for (int i = 0; i < 5; i++) {
        char nameLower[20];
        strcpy(nameLower, student[i].name);
        toLowerCase(nameLower);
        if (strstr(nameLower, searchName) != NULL) {
            printf("\nID: %d\n", student[i].id);
            printf("Name: %s\n", student[i].name);
            printf("Age: %d\n", student[i].age);
            find = 1;
        }
    }
    if (!find) {
        printf("Khong tim thay sinh vien nao co ten chua '%s'\n", searchName);
    }
    return 0;
}