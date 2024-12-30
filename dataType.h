#include <stdbool.h>

struct User {
    char id[20];         // ID
    char name[50];       // Name
    char phone[15];      // Phone
    char email[50];      // Email
    char password[50];   // Password
    char status[10];     // Status (open/closed)
    char username[50];   // Username
};

struct Date {
    int month, day, year;
};

struct User* users = NULL;
struct User newUser;
