#include <stdio.h>
#include <vector>
#include <stack>

//xml globals
int indent = 1;
int tablen = 4;
std::stack<char*> mystack;

//helper functions
//------------------
void printIndent(int indent) {
    printf("%*s", indent*tablen, "");
}

// need to write an escapeKey() function.
// <the key> is invalid; it's a <the> element with an incomplete 'key' attr
// needs to be turned into <the-key>

//xml functions
//-----------------
extern "C" void AssignStr(char* key, char* value) {
    printIndent(indent);
    printf("<%s>%s</%s>\n", key, value, key);
}

//extern "C" void AssignQuoted(char* key, char* value)
//{ printf("%*s<%s>%s\b</%s>\n", (indent)*4, "", key, value+1, key); }

extern "C" void AssignFloat(char* key, double value) {
    printIndent(indent);
    printf("<%s>%f</%s>\n", key, value, key);
}

extern "C" void AssignInt(char* key, int value) {
    printIndent(indent);
    printf("<%s>%d</%s>\n", key, value, key);
}

extern "C" void StartObj(char* key) {
    printf("\n");
    printIndent(indent++);
    printf("<%s>\n", key);
    mystack.push(key);
}

extern "C" void EndObj(char* key) {
    printIndent(--indent);
    printf("</%s>\n", mystack.top());
    mystack.pop();
}

extern "C" void prefix() 
{ printf("<?xml version=\"1.1\" encoding=\"UTF-8\"?>\n<root>\n"); }

extern "C" void postfix() { printf("</root>\n"); }
