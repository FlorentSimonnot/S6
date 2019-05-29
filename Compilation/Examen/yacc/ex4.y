/*

---------QUESTION 1--------
La notation polonaise inversé à les avantages suivants :
- Écriture raccourcie car par de parenthèsage. 
- Détection des erreurs plus facile grâce aux calculs intermédiaire. 
- Calcul intermédiaire gérés dans une pile. 

 */
%{
#include <stdio.h>
#include <string.h>


int yylex(void);
void yyerror(char* s);
extern int line_num;
int getOffset(char *ident);

/*Juste pour tester. Ne pas écrire*/
int getOffset(char *ident){
    return 8; 
}

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
                            fprintf(stdout, "    pop rcx\n    pop rax\n    add rax, rcx\n    push rax\n");
                        }
                        if($3 == '-'){
                            $$ = $1 - $2; 
                            fprintf(stdout, "    pop rcx\n    pop rax\n    sub rax, rcx\n    push rax\n");
                        }
                    }
    |   T   {$$ = $1;}
    ; 

T   :   T F DIVSTAR 
                    {   
                        fprintf(stdout, "    pop rcx\n    pop rax\n");
                        if($3 == '*'){
                            $$ = $1 * $2; 
                            fprintf(stdout, "    imul rcx\n    push rax\n"); break;
                        }
                        if($3 == '/'){
                            $$ = $1 / $2; 
                            fprintf(stdout, "    mov rdx,0\n    idiv rcx\n    push rax\n");
                        }
                    }
    |   F   {$$ = $1;}
    ; 

F   :   NUM {$$ = $1; fprintf(stdout, "    push QWORD %d\n", $1);}
    |   Const       {   int offset; 
                        if ((offset = getOffset($1)) >= 0){
                            fprintf(stderr, "Variable undeclared\n");
                        }
                        else{
                            fprintf(stdout, "   push QWORD [rbp-%d]\n", offset);
                        }
                    }
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
