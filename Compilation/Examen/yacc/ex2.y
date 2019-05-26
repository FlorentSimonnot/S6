%{
#include <stdio.h>
#include <string.h>

int yylex(void);
void yyerror(char* s);
extern int line_num;
%}

%union{
    char *text; 
    int num; 
}

%token <num> NUM
%token <text> TEXT

%type <num> S
%type <num> ST
%type <num> suiteST

%%

S   :   NUM suiteST 
    ;

suiteST     :   
                suiteST ST 
            |   ST 
            ;

ST  :   
        NUM '-' NUM TEXT  { $$ = $<num>0; printf("%d - %d %s\n", $1+$<num>0, $3+$<num>0, $4);}
    ;

%%
void yyerror(char *s){
    printf("Erreur %s near line %d \n", s, line_num);
}
 
int main(){
    return yyparse();
}
