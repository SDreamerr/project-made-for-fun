#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ram = 1;
int count = 0;

struct taskmgr {
    /* data */
    char taskNM[30];
    int done;
};

struct taskmgr* addTsk(struct taskmgr *task);
void shAll(struct taskmgr *task);
void mrkdone(struct taskmgr *task);
void onlydone(struct taskmgr *task);
void deletetsk(struct taskmgr *task);

int main(void) {
    int choice = 0;
    // menu
    struct taskmgr *task = malloc(ram * sizeof(struct taskmgr));
    do {
    printf("=== Task Manager ===\n");
    printf("1. Add task\n");
    printf("2. Show all task\n");
    printf("3. Mark task as done\n");
    printf("4. Show only done tasks\n");
    printf("5. Delete task\n");
    printf("6. Quit\n");
    if (scanf("%d", &choice) != 1) {return 1;}
    switch (choice) {
    case 1:
        /* code */
        task = addTsk(task);
        break;
    case 2:
        shAll(task);
        break;
    case 3:
        mrkdone(task);
        break;
    case 4:
        onlydone(task);
        break;
    case 5:
        deletetsk(task);
        break;
    default:
        break;
    }
    } while (choice != 6);
    free(task);
    return 0;
}

struct taskmgr* addTsk(struct taskmgr *task) {
    char *txtx = task[ram - 1].taskNM;
    FILE *f = fopen("tasks.txt", "a");
    printf("type task name:\n");
    if (scanf("%s", txtx) != 1) {return NULL;} 
    fprintf(f, "%s ", txtx);
    fclose(f);
    count++;
    ram++;
    task = realloc(task, ram * sizeof(struct taskmgr));
    return task;
}

void shAll(struct taskmgr *task) {
    for (int i = 0;i < count;i++) {
        printf("====================\n");
        printf("%s\n", task[i].taskNM);
        printf("%d\n", task[i].done);
        printf("====================\n");
    }
}

void mrkdone(struct taskmgr *task) {
    char srcName[30]; 
    printf("type name of task: \n");
    if (scanf("%s", srcName) != 1) {return;}
    for (int a = 0;a < count;a++) {
        if (strcmp(task[a].taskNM, srcName) == 0) {
            task[a].done = 1;
        }
    }
    
}

void onlydone(struct taskmgr *task) {
    for (int i = 0;i < count;i++) {
        if (task[i].done == 1) {
            printf("====================\n");
            printf("%s\n", task[i].taskNM);
            printf("%d\n", task[i].done);
            printf("====================\n");
        }
    }
}

void deletetsk(struct taskmgr *task) {
    char srch[30];
    FILE *fi = fopen("tasks.txt", "a");
    printf("type task name that you want to delete: \n");
    if (scanf("%s", srch) != 1) {return;}
    for (int i = 0;i < count;i++) {
        if (strcmp(task[i].taskNM, srch) == 0) {
            for (int a = i;a < count - 1;a++) {
                task[a] = task[a + 1];
            }
            count--;
            break;
        }
    }
    fclose(fi);
    task = realloc(task, count * sizeof(struct taskmgr)); 
}