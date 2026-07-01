#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "func.h"

struct Notes* addNT(struct Notes *note) {
    char fileName[30];
    char textlong[MAX_TEXT];
    printf("type title: \n");
    if (scanf("%s", fileName) != 1) {return NULL;}
    strcat(fileName, ".txt");
    FILE *f = fopen(fileName, "a");
    printf("type text for note: \n");
    if (scanf(" %[^\n]", textlong) != 1) {return note;}
    fprintf(f, "%s", textlong);
    fclose(f);
    count++;
    ram++;
    note = realloc(note, ram * sizeof(struct Notes));
    strcpy(note[count - 1].title, fileName);
    return note;
}

void shAll(struct Notes *note) {
    char longg[MAX_TEXT];
    for (int i = 0;i != count;i++) {
        FILE *f = fopen(note[i].title, "r");
        printf("==============================\n");
        printf("%s\n", note[i].title);
        while (fgets(longg, sizeof(longg), f) != NULL) {printf("%s\n", longg);}
        printf("==============================\n");
        fclose(f);
    }
}

void srchKeyWord(struct Notes *note) {
    char txtlong[MAX_TEXT];
    char word[100];
    printf("type key word that you want find in file: \n");
    if (scanf("%s", word) != 1) {return;}
    for (int i = 0;i != count;i++) {
        FILE *f = fopen(note[i].title, "r");
        while (fgets(txtlong, sizeof(txtlong), f) != NULL) {
            if (strstr(txtlong, word) != NULL) {
                printf("founded\n");
                printf("%s\n", note[i].title);
            }
        }
        fclose(f);
    }
}

void deleteNT(struct Notes *note) {
    char word[MAX_TITLE];
    printf("type file name that you want to delete: \n");
    if (scanf("%s", word) != 1) {return;}
    strcat(word, ".txt");
    for (int i = 0;i != count;i++) {
        if (strcmp(note[i].title, word) == 0) {
            if (remove(word) != 0) {
                printf("error when deleting\n");
            }
            for (int a = i;a != count - 1;a++) {
                note[a] = note[a + 1];
            }
            count--;
            ram--;
            note = realloc(note, ram * sizeof(struct Notes));
            break;
        }
    }
}

struct Notes* loadFile(struct Notes *note) {
    char name[MAX_TITLE];
    printf("type file name(without .txt): \n");
    if (scanf("%s", name) != 1) {return NULL;}
    strcat(name, ".txt");
    FILE *f = fopen(name, "r");
    fclose(f);
    ram++;
    count++;
    note = realloc(note, ram * sizeof(struct Notes));
    strcpy(note[count - 1].title, name);
    return note;
}