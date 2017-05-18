%{
/* includes here */  
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
%}

%error-verbose

%union {
    int ival;
    double fval;
    char* sval;
}

%token END_OBJ EQ
%token START_LIST END_LIST
%token <sval> START_OBJ
%token <sval> STRING
%token <sval> QUOTE
%token <ival> INT
%token <fval> FLOAT

%%
file: assigns sections
    | sections
    | assigns
    ;

sections: sections section { EndObj(""); }
        | section          { EndObj(""); }
        ;

section: section assignment
       | START_OBJ { StartObj($1); }
       ;
        
assigns: assigns assignment 
       | assignment
       ;

assignment: STRING EQ STRING { AssignStr($1, $3); }
          | STRING EQ FLOAT  { AssignFloat($1, $3); }
          | STRING EQ INT    { AssignInt($1, $3); }
          ;
%%

/* needed for every bison file */
int yywrap() { 
    return 1; 
}

int yyerror (char const *s) { 
    fprintf (stderr, "%s\n", s); 
}

int main() {
    
    prefix();
    yyparse();
    postfix();
    
    return 0;
}
