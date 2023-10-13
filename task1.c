#include <stdio.h>
#include <string.h>

#define MAX_USERS 10

struct User {
    char username[50];
    char password[50];
};


struct User users[MAX_USERS];
int userCount = 0;
void registerUser() {
    if (userCount < MAX_USERS) {
        printf("Enter your username here: ");
        scanf("%s", users[userCount].username);
        printf("Enter your password here: ");
        scanf("%s", users[userCount].password);
        userCount++;
        printf("Registration is done\n");
    } else {
        printf("you can not register.\n");
    }
}
void loginUser() {
    char username[50];
    char password[50];
    printf("Enter your username here: ");
    scanf("%s", username);
    printf("Enter your password here: ");
    scanf("%s", password);

    int i;
    for (i = 0; i < userCount; i++) {
        if (strcmp(username, users[i].username) == 0 && strcmp(password, users[i].password) == 0) {
            printf("Login is successful! Welcome,%s\n", username);
            return;
        }
    }

    printf("Login failed. Invalid username or password.\n");
}


int main() {
    int choice;
    while (1) {
        printf("1.Register page\n2.Login page\n3.Exit of programming \n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                loginUser();
                break;
            case 3:
                printf("Exit!\n");
                return 0;
            default:
                printf("the number is not exist.\nTry again.\n");
                break;
        }
    }
}