#include <stdio.h>

//json functions
//-----------------
void AssignStr(char* key, char* value) 
{ printf("\n\"%s\": \"%s\",", key, value); }

void AssignQuoted(char* key, char* value)
{ printf("\n\"%s\": %s,", key, value); }

void AssignFloat(char* key, double value) 
{ printf("\n\"%s\": %f,", key, value); }

void AssignInt(char* key, int value) 
{ printf("\n\"%s\": %d,", key, value); }


void StartObj(char* key) 
{ printf("\n\n\"%s\": { ", key); }

void EndObj(char* key) 
{ printf("\b \n},"); }

void prefix() { printf("{ \n"); }
void postfix() { printf("\b}\n"); }

//void flush();
