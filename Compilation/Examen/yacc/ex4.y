%{
#include <stdio.h>
#include <string.h>


int yylex(void);
void yyerror(char* s);
extern int line_num;
%}

%union{
    int num; 
    char operatoradd;
    char operatordiv;
    char ident[64];
}

%token <num> NUM
%token <operatoradd> ADDSUB
%token <operatordiv> DIVSTAR
%token <ident> IDENT CONST

%type <num> F E T S NombreSigne
%type <ident> Const
%%

S   :   DeclConsts E {$$ = $2; printf("%d\n", $$);}
    ;

DeclConsts:
       DeclConsts CONST ListConst ';' 
    |  DeclConsts error ListConst ';'
    |  DeclConsts CONST ListConst error
    |  
    ;

ListConst:
       ListConst ',' IDENT '=' Litteral 
    |  IDENT '=' Litteral              
    ;

Litteral:
       NombreSigne
    ;

NombreSigne:
       NUM {$$ = $1;}
    |  ADDSUB NUM {if($1 == '-'){$$ = -($2);}}
    ;


E   :   E T ADDSUB 
                    {    
                        if($3 == '+'){
                            $$ = $1 + $2; 
                        }
                        if($3 == '-'){
                            $$ = $1 - $2; 
                        }
                    }
    |   T   {$$ = $1;}
    ; 

T   :   T F DIVSTAR 
                    {   
                        if($3 == '*'){
                            $$ = $1 * $2; 
                        }
                        if($3 == '/'){
                            $$ = $1 / $2; 
                        }
                    }
    |   F   {$$ = $1;}
    ; 

F   :   NUM {$$ = $1;}
    |   Const 
    ;

Const   :   IDENT
        ;

%%
void yyerror(char *s){
    printf("Erreur %s near line %d \n", s, line_num);
}


int main(){
    return yyparse();
}
