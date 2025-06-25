#include <stdio.h>
#include <string.h>

// Khai báo cấu trúc Student để lưu thông tin sinh viên
struct Student {
    int id;
    char name[50];
    int age;
};

int main(void) {
    // Nhập số lượng sinh viên cần quản lý
    int n;
    printf("Nhap so luong phan tu sinh vien: ");
    scanf("%d", &n);

    // Khai báo mảng student gồm n sinh viên
    struct Student student[n];

    // Nhập thông tin cho từng sinh viên
    for (int i = 0; i < n; i++) {
        printf("Nhap thong tin sv thu %d\n", i + 1);

        // Gán ID tự động theo thứ tự nhập
        student[i].id = i + 1;

        // Nhập tên sinh viên (dùng fgets để đọc cả dòng có khoảng trắng)
        printf("Name: ");
        getchar(); // Đọc ký tự '\n' còn sót lại từ lần nhập trước
        fgets(student[i].name, 50, stdin);

        // Xóa ký tự newline '\n' do fgets thêm vào cuối chuỗi
        student[i].name[strcspn(student[i].name, "\n")] = '\0';

        // Nhập tuổi sinh viên
        printf("Age: ");
        scanf("%d", &student[i].age);
    }

    // Tìm sinh viên theo ID
    int findId, check = 0;
    printf("Nhap ID can tim: ");
    scanf("%d", &findId);

    // Duyệt qua mảng để tìm sinh viên có ID khớp
    for (int i = 0; i < n; i++) {
        if (student[i].id == findId) {
            check = 1;  // Đánh dấu là tìm thấy
            printf("ID: %d\n", student[i].id);
            printf("Name: %s\n", student[i].name);
            printf("Age: %d\n", student[i].age);
        }
    }

    // Nếu không tìm thấy sinh viên nào có ID phù hợp
    if (check == 0) {
        printf("Sinh vien khong ton tai\n");
    }

    return 0;
}
