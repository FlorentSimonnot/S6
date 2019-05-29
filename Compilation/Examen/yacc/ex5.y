%{
#include <stdio.h>
#include <string.h>


int yylex(void);
void yyerror(char* s);
extern int line_num;
%}

%union{
    char ident;
}

%token <ident> ID

%%

D : L ';' {printf(";\n");}
L : ID  {printf("%c ", $1);}
    | ID {printf("%c ", $1);} ',' L 
    ;
%%
void yyerror(char *s){
    printf("Erreur %s near line %d \n", s, line_num);
}


int main(){
    return yyparse();
}
