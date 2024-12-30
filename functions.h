#include "dataType.h"

// Nguyen mau ham
void printHello();                         // In ra menu chon vai tro
void managerMenu();                        // In ra menu quan ly nguoi dung
void printUsers();                         // Hien thi danh sach nguoi dung
void addUser();                            // Them nguoi dung moi
void adminMenu();                          // Menu quan li cua Admin
void checkForDuplicationAndValidity(char* value, char* input, int* result);  // Ham kiem tra trung lap
void isValidInput(char* input, int maxLength, int* isValid);  // Ham kiem tra do dai hop le
void searchUser();                         // Tim kiem nguoi dung theo ten
