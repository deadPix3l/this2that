%{
#include "ini.tab.h"

char* stripQuotes(char* words);
%}

alnum           [a-zA-Z0-9]
letter          [a-zA-Z]
digit           [0-9]
sym             [-!$@%^&*()_+|~\\`:;'<>?\.\/,]
ValidName       {letter}{alnum}*
Float           {digit}+\.{digit}+
String          ({alnum}|" "|{sym})*({alnum}|{sym})
QuotedString    \"{String}\"
%%

^;.*$               { ; } // comments
\[{String}+\]       { yylval.sval = strdup(stripQuotes(yytext)); return START_OBJ; }
{Float}             { yylval.fval = atof(yytext); return FLOAT; }
{digit}+            { yylval.ival = atoi(yytext); return INT; }
{QuotedString}      { yylval.sval = strdup(stripQuotes(yytext)); return STRING; }
{String}            { yylval.sval = strdup(yytext); return STRING; }
"="                 { return EQ; }
[ \t\n]             { ; } //strip whitespace
.                   { printf("lexxer error! (%s)\n", yytext); exit(127); }

%%

char* stripQuotes(char* words)
{
    int x = strlen(words);
    words[x-1] = '\0';
    return ++words;
}
