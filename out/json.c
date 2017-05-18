#include <stdio.h>

//globals
int RS = 0;

//json functions
//-----------------
void AssignStr(char* key, char* value) {
    if(RS) printf(",");
    printf("\n\"%s\": \"%s\"", key, value);
    RS = 1;
}

//void AssignQuoted(char* key, char* value)
//{ printf("\n\"%s\": \"%s\",", key, value); }

void AssignFloat(char* key, double value) {
    if(RS) printf(",");
    printf("\n\"%s\": %f", key, value);
    RS = 1;
}

void AssignInt(char* key, int value) {
    if(RS) printf(",");
    printf("\n\"%s\": %d", key, value);
    RS = 1;
}

void StartObj(char* key) {
    if(RS) printf(",");
    printf("\n\n\"%s\": {", key);
    RS = 0;
}

void EndObj(char* key) {
    printf("\n}");
    RS = 1;
}

void prefix() { printf("{"); }
void postfix() { printf("\n}"); }

//void flush();
