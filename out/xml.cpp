#include <stdio.h>
#include <vector>
#include <stack>

//xml globals
int indent = 1;
std::stack<char*> mystack;


//xml functions
//-----------------
extern "C" void AssignStr(char* key, char* value) 
{ printf("%*s<%s>%s</%s>\n", (indent)*4, "", key, value, key); }

extern "C" void AssignQuoted(char* key, char* value)
{ printf("%*s<%s>%s\b</%s>\n", (indent)*4, "", key, value+1, key); }

extern "C" void AssignFloat(char* key, double value) 
{ printf("%*s<%s>%.2f</%s>", (indent)*4, "", key, value, key); }

extern "C" void AssignInt(char* key, int value) 
{ printf("%*s<%s>%d</%s>\n", (indent)*4, "", key, value, key); }

extern "C" void StartObj(char* key) { 
    printf("%*s<%s>\n", (indent++)*4, "", key); 
    mystack.push(key);
}

extern "C" void EndObj(char* key) { 
    printf("%*s</%s>\n\n", (--indent)*4, "", mystack.top()); 
    mystack.pop();
}

extern "C" void prefix() 
{ printf("<?xml version=\"1.1\" encoding=\"UTF-8\"?>\n<root>\n"); }

extern "C" void postfix() { printf("</root>\n"); }
