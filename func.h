#ifndef NOTES_H
#define NOTES_H

#define MAX_TEXT 1000
#define MAX_TITLE 30


extern struct Notes *note;
extern int count;
extern int ram;

struct Notes {
    char title[MAX_TITLE];
    char size;
};

struct Notes* addNT(struct Notes *note);
void shAll(struct Notes *note);
void srchKeyWord(struct Notes *note);
void deleteNT(struct Notes *note);
struct Notes* loadFile(struct Notes *note);

#endif 