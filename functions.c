#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

// Bien toan cuc
int userCount = 0;

// In ra menu dau tien
void printHello() {
    printf("\n   *** Bank Management System Using C ***\n");
    printf("               CHOOSE YOUR ROLE \n");
    printf("      ==============================\n");
    printf("      [1]. Admin \n");
    printf("      [2]. User \n");
    printf("      [3]. Exit the Program \n");
    printf("      ==============================\n");
}

// In ra menu quan ly nguoi dung cho Admin
void managerMenu() {
    printf("\n   ===== User Management System =====\n");
    printf("           User Management Menu:\n");
    printf("       [1]. Display user list \n");
    printf("       [2]. Add new user\n");
    printf("       [3]. Delete user\n");
    printf("       [4]. Edit user information \n");
    printf("       [5]. Search for user\n");
    printf("       [0]. Exit\n");
}

// Hien thi danh sach nguoi dung
void printUsers() {
    if (userCount == 0) {
        printf("No users available.\n");
        return;
    }
    printf("\nUser List:\n");
    printf("Name\t|\tPhone Number\t|\tEmail\t|\tStatus\n");
    for (int i = 0; i < userCount; i++) {
        printf("-------------------------------------------------------------------------------------------\n");
        printf("%s\t|\t%s\t|\t%s\t|\t%s\n", users[i].name, users[i].phone, users[i].email, users[i].status);
    }
}

// Them nguoi dung moi
void addUser() {
    int result = 0;
    // Cap phat lai bo nho cho mang nguoi dung khi them nguoi dung moi
    users = realloc(users, (userCount + 1) * sizeof(struct User));
    if (users == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    // Nhap thong tin nguoi dung moi
    printf("Enter user name: ");
    getchar();  // Loai bo ky tu '\n' con lai trong bo dem
    fgets(newUser.name, sizeof(newUser.name), stdin);
    newUser.name[strcspn(newUser.name, "\n")] = '\0'; // Xoa ky tu '\n' cuoi
    checkForDuplicationAndValidity(newUser.name, newUser.name, &result);
    if (result == 1) return;
    printf("Enter user phone number: ");
    scanf("%s", newUser.phone);
    getchar();  // Loai bo ky tu '\n' con lai trong bo dem sau scanf
    checkForDuplicationAndValidity(newUser.phone, newUser.phone, &result);
    if (result == 1) return;
    printf("Enter user email: ");
    fgets(newUser.email, sizeof(newUser.email), stdin);
    newUser.email[strcspn(newUser.email, "\n")] = '\0'; // Xoa ky tu '\n' cuoi
    checkForDuplicationAndValidity(newUser.email, newUser.email, &result);
    if (result == 1) return;
    strcpy(newUser.password, newUser.phone);
    strcpy(newUser.status, "open");
    users[userCount] = newUser;
    userCount++;
    printf("User added successfully!\n");
}

// Menu quan ly nguoi dung cho Admin
void adminMenu() {
    int choiceAdmin;
    int exitLoop = 0;

    while (!exitLoop) {
        managerMenu();
        printf("Enter The Choice: ");
        scanf("%d", &choiceAdmin);

        switch(choiceAdmin) {
            case 1:
                printUsers();
                break;
            case 2:
                addUser();
                break;
            case 3:
                // Xay dung chuc nang xoa nguoi dung o day
                break;
            case 4:
                // Xay dung chuc nang chinh sua nguoi dung o day
                break;
            case 5:
                {
                    // Khai bao cac bien
                    char value[50];
                    int result = 0; // Mac dinh la khong trung lap
                    char input[50];

                    printf("Enter the value to check for duplication: ");
                    scanf("%s", value);

                    // Nhap thong tin can kiem tra
                    printf("Enter some information to validate: ");
                    scanf("%s", input);

                    // Kiem tra trung lap va kiem tra do dai thong tin
                    checkForDuplicationAndValidity(value, input, &result);

                    // Neu khong co trung lap va thong tin hop le
                    if (result == 0) {
                        printf("No duplication or invalid input detected.\n");
                    }
                }
                break;
            case 0:
                exitLoop = 1;
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}

// Ham kiem tra trung lap va kiem tra thong tin
void checkForDuplicationAndValidity(char* value, char* input, int* result) {
    // Kiem tra trung lap voi cac gia tri nhu ID, phone, email, username
    int fieldTypes[] = {1, 2, 3, 4};  // ID, phone, email, username
    for (int i = 0; i < 4; i++) {
        isDuplicate(value, fieldTypes[i], result);  // Kiem tra trung lap cho moi truong
        if (*result == 1) {
            printf("Duplicate found for value: %s\n", value);
            return;  // Thoat khoi ham neu tim thay trung lap
        }
    }

    // Kiem tra do dai thong tin
    isValidInput(input, 50, result);  // Neu tra ve 0, thong tin khong hop le
    if (*result == 0) {
        printf("Invalid information length.\n");
        return;  // Thong bao loi va thoat
    }
}

// Ham kiem tra do dai hop le
void isValidInput(char* input, int maxLength, int* isValid) {
    if (input == NULL || strlen(input) == 0 || strlen(input) > maxLength) {
        *isValid = 0;  // Khong hop le
    } else {
        *isValid = 1;  // Hop le
    }
}

// Ham kiem tra trung lap (Ban can xay dung logic o day)
void isDuplicate(char* value, int fieldType, int* result) {
    // Xay dung logic kiem tra trung lap (VD: tim kiem trong mang 'users')
    *result = 0;  // Gi? s? không có trung lap
}

// Ham tim kiem nguoi dung theo ten
void searchUser() {
    char searchName[50];
    int found = 0;

    printf("Enter the name of the user you want to search: ");
    getchar();  // Doc ky tu '\n' con lai sau khi nhap so
    fgets(searchName, sizeof(searchName), stdin);
    searchName[strcspn(searchName, "\n")] = '\0';  // Xoa ky tu '\n' cuoi chuoi

    for (int i = 0; i < userCount; i++) {
        if (strstr(users[i].name, searchName) != NULL) {  // Tim kiem nguoi dung theo ten
            if (!found) {
                printf("List of users found:\n");
                printf("ID\t\tName\t\tPhone\t\tEmail\t\tUsername\n");
            }
            printf("%s\t%s\t%s\t%s\t%s\n", users[i].id, users[i].name, users[i].phone, users[i].email, users[i].username);
            found = 1;
        }
    }

    if (!found) {
        printf("No user found with the name \"%s\".\n", searchName);
    }
}

