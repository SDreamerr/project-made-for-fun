#include <stdio.h>
#include <string.h>

int count = 0;

struct bank {
    char name[20];
    int balance;
};

void createAcc(struct bank *b);
void depo(struct bank *b);
void withdraw(struct bank *b);
void shAll(struct bank *b);
void fndMax(struct bank *b);

int main (void) {
    struct bank b[1000];
    // menu
    int choice = 0;
    do {
    printf("=== Bank === \n");
    printf("1. Create account (name, balance)\n");
    printf("2. Deposit\n");
    printf("3. Withdraw\n");
    printf("4. Show all accounts\n");
    printf("5. Find richest account\n");
    printf("6. Quit\n");
    if (scanf("%d", &choice) != 1) {
        return 1;
    }
    (choice == 7) ? printf("bro its only 1-6 tho\n") : printf("\n");
    switch (choice) {
    case 1:
        createAcc(b); 
        count++;
        break;
    case 2:
        depo(b);
        break;
    case 3:
        withdraw(b);
        break;
    case 4:
        shAll(b);
        break;
    case 5:
        fndMax(b);
        break;
    }
    } while (choice != 6);
    
    return 0;
}

void createAcc(struct bank *b) {
    printf("type name of account:\n");
    if (scanf("%s", b[count].name) != 1) {
        return;
    }
    printf("type balance of the account:\n");
    if (scanf("%d", &b[count].balance) != 1) {
        return;
    }
}

void depo(struct bank *b) {
    char srchname[20];
    int hm = 0;
    printf("name of the acc:\n");
    if (scanf("%s", srchname) != 1) {
        return;
    }
    for (int i = 0;i != count;i++) {
    if (strcmp(b[i].name, srchname) == 0) {
        printf("how many want to deposit:\n");
        if (scanf("%d", &hm) != 1) {
            return;
        }
        b[i].balance += hm;
    } 
    }
}

void withdraw(struct bank *b) {
    char srchname[20];
    int hm = 0;
    printf("name of the acc:\n");
    if (scanf("%s", srchname) != 1) {
        return;
    }
    for (int i = 0;i != count;i++) {
    if (strcmp(b[i].name, srchname) == 0) {
        printf("how many want to withdraw:\n");
        if (scanf("%d", &hm) != 1) {
            return;
        }
        b[i].balance -= hm;
    } 
    }
}

void shAll(struct bank *b) {
    for (int i = 0;i != count;i++) {
        printf("=====================\n");
        printf("%s\n", b[i].name);
        printf("%d\n", b[i].balance);
        printf("=====================\n");
    }
}

void fndMax(struct bank *b) {
    int balance = b[0].balance;
    char *name = b[0].name;
    for (int i = 0;i != count;i++) {
        if (b[i].balance > balance) {
            name = b[i].name;
            balance = b[i].balance;
        }
    }
    printf("=====================\n");
    printf("%s\n", name);
    printf("%d\n", balance);
    printf("=====================\n");
}