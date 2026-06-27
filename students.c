#include <stdio.h>

// global (for func)
int count = 0;

// data
struct Students {
    char name[20];
    int grade;
};

// prototype
void addST(struct Students *st);
void showST(struct Students *st);
void FindMax(struct Students *st);
void pass(struct Students *st);

int main(void) {
    // hm students
    printf("How many students in your class: \n");
    if (scanf("%d", &count) != 1) {
        return 1;
    }
    // massive created
    struct Students st[count];
    // Menu
    int choice = 0;
    do {
    printf("=== Student Journal ===\n");
    printf("1. Add student\n");
    printf("2. Show all students\n");
    printf("3. Find best student (max grade)\n");
    printf("4. Count passing students (grade > 60)\n");
    printf("5. Quit\n");
    if (scanf("%d", &choice) != 1) {
        return 1;
    }
    (choice == 6) ? printf("пошол нахуй\n") : printf("\n");
    switch (choice) { // choices
    case 1:
        addST(st);
        break;
    case 2:
        showST(st);
        break;
    case 3:
        FindMax(st);
        break;
    case 4:
        pass(st);
        break;
    default:
        break;
    }
    } while (choice != 5);
    return 0;
}

void addST(struct Students *st) {
    for (int i = 0;i != count;i++) {
        printf("Enter name: \n");
        if (scanf("%s", st[i].name) != 1) {
            return;
        }
        printf("Enter grade: \n");
        if (scanf("%d", &st[i].grade) != 1) {
            return;
        }
    }
}

void showST(struct Students *st) {
    for (int i = 0;i != count;i++) {
        printf("=====================\n");
        printf("%s\n", st[i].name);
        printf("%d\n", st[i].grade);
        printf("=====================\n");
    }
}

void FindMax(struct Students *st) {
    char *name = st[0].name;
    int grade = st[0].grade;
    for (int i = 0;i != count;i++) {
        if (st[i].grade > grade) {
            grade = st[i].grade;
            name = st[i].name;
        }
    }
    printf("=====================\n");
    printf("%s\n", name);
    printf("%d\n", grade);
    printf("=====================\n");
}

void pass(struct Students *st) {
    for (int i = 0;i != count;i++) {
        if (st[i].grade > 60) {
            printf("=====================\n");
            printf("%s\n", st[i].name);
            printf("%d\n", st[i].grade);
            printf("=====================\n");
        }
    }
}