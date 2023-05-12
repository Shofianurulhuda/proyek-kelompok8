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
}

struct user u;
char username[25];
char password[25];
