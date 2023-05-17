#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct user_login {
    char username[25];
    char password[25];
};

struct quiz {
    char question[100];
    char answer[4][50];
    char correct_answer;
};

void print_question(struct quiz q) {
    printf("%s\n", q.question);
    for (int i = 0; i < 4; i++) {
        printf("%s\n", q.answer[i]);
    }
}

int main (int argc, char *argv[]) {
    if (argc < 2) {
        printf("Use login.bin behind %s\n", argv[0]);
        exit(1);
    }

    struct user_login u;
    char username[25];
    char password[25];
    int logged_in = 0;


    FILE *file = fopen(argv[1], "ab");
    if (file == NULL) {
        printf("Error creating log file!\n");
        exit(1);
    }

    int registered = 0;
    printf("Do you want to register? (y/n) : " );
    char choice;
    scanf("%c", &choice);

    if (choice == 'y') {
        registered = 1;

        printf("enter username: ");
        scanf("%s", u.username);

        printf("enter password: ");
        scanf("%s", u.password);

        fwrite(&u, sizeof(struct user_login), 1, file);

        printf("User data has been saved saved to log file.\n");
        fclose(file);
    } if(registered) {
        printf("Please login to continue.\n");
        file = fopen(argv[1], "rb");
        
        if(file == NULL) {
            printf("Error opening log file!.\n");
            exit(1);
        }
        printf("enter username: ");
        scanf("%s", username);

        while(fread(&u, sizeof(struct user_login), 1, file)) {
            if(strcmp(u.username, username) == 0) {
                printf("enter password: ");
                scanf("%s", password);

                if(strcmp(u.password, password) == 0) {
                    printf("login successful!\n\n");
                    logged_in = 1;
                    break;
                } else {
                    printf("Invalid password!\n\n");
                    break;
                }
            }
        }
        if (!logged_in) {
            printf("User not faound!\n");
        } fclose(file);
    } if (!logged_in) {
        return 0;
    } fclose(file);
