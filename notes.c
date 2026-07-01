#include <stdio.h>
#include <stdlib.h>
#include "func.h"

struct Notes *note = NULL;
int count = 0;
int ram = 1;

int main(void) {
    int choice;
    char file[MAX_TITLE];
    struct Notes *note = malloc(ram * sizeof(struct Notes));
    do {
    printf("=== Notes ===\n");
    printf("1. Add note\n");
    printf("2. Show all notes\n");
    printf("3. Search note by keyword\n");
    printf("4. Delete note\n");
    printf("5. Load from file\n");
    printf("6. Quit\n");
    if (scanf("%d", &choice) != 1) {
        return 1;
    }
    switch (choice) {
    case 1:
        note = addNT(note);
        break;
    case 2:
        shAll(note);
        break;
    case 3:
        srchKeyWord(note);
        break;
    case 4:
        deleteNT(note);
        break;
    case 5:
        note = loadFile(note);
        break;
    default:
        break;
    }
    } while (choice != 6);
    free(note);
    return 0;
}