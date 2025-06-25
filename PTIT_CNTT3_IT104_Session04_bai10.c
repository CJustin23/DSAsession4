#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Khai báo cấu trúc sinh viên
struct Student {
    int id;
    char name[20];
    int age;
};

// Hàm chuyển chuỗi sang chữ thường (dùng để so sánh không phân biệt hoa/thường)
void toLowerCase(char str[]) {
    for (int i = 0; str[i] != '\0'; i++)
        str[i] = tolower(str[i]);
}

int main(void) {
    // Khai báo mảng chứa 5 sinh viên
    struct Student student[5];

    // Nhập thông tin từng sinh viên
    for (int i = 0; i < 5; i++) {
        printf("Nhap thong tin sinh vien thu %d\n", i + 1);

        // Gán ID tự động
        student[i].id = i + 1;

        // Nhập tên sinh viên
        printf("Name: ");
        fgets(student[i].name, 20, stdin);
        student[i].name[strcspn(student[i].name, "\n")] = '\0'; // Xoá ký tự xuống dòng

        // Nhập tuổi sinh viên
        printf("Age: ");
        scanf("%d", &student[i].age);
        getchar(); // Đọc ký tự '\n' còn lại
    }

    // In lại toàn bộ danh sách sinh viên
    for (int i = 0; i < 5; i++) {
        printf("\nThong tin sinh vien thu %d:\n", i + 1);
        printf("ID: %d\n", student[i].id);
        printf("Name: %s\n", student[i].name);
        printf("Age: %d\n", student[i].age);
    }

    // Nhập tên cần tìm (tìm gần đúng, không phân biệt hoa/thường)
    char searchName[20];
    printf("\nNhap ten can tim: ");
    fgets(searchName, sizeof(searchName), stdin);
    searchName[strcspn(searchName, "\n")] = '\0';
    toLowerCase(searchName); // Chuyển tên cần tìm về chữ thường

    int find = 0; // Biến kiểm tra có tìm thấy không

    // Duyệt qua tất cả sinh viên để tìm theo tên (gần đúng)
    for (int i = 0; i < 5; i++) {
        char nameLower[20];
        strcpy(nameLower, student[i].name); // Sao chép tên sinh viên sang biến tạm
        toLowerCase(nameLower);             // Chuyển sang chữ thường

        // Nếu tên sinh viên có chứa chuỗi cần tìm
        if (strstr(nameLower, searchName) != NULL) {
            printf("\nTim thay sinh vien:\n");
            printf("ID: %d\n", student[i].id);
            printf("Name: %s\n", student[i].name);
            printf("Age: %d\n", student[i].age);
            find = 1;
        }
    }

    // Nếu không tìm thấy
    if (!find) {
        printf("Khong tim thay sinh vien nao co ten chua '%s'\n", searchName);
    }

    return 0;
}
