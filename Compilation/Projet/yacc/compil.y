%{
#include <stdio.h>
#include <string.h>
#include "../header/decl.h"
#include "../header/input-output.h"

/*COMMIT*/
int yylex(void);
void yyerror(char* s);
int flag_error = 0;
int flag_start = 1; 
int flag_return = 0; 
int type_const = -1; 
int type_var = -1;
int type_define = -1;
int type_macro_assign = -1;
int parameters = 0;
int *args = NULL;
char name_function[MAXNAME];
char name_called_function[MAXNAME];
%}

%union{
	char *typeval;
	int intval; 
	float reelval; 
	char charval; 
	char addsubval; 
	char divstarval; 
	char identval[64];
	char eqval[2];
	char andval[2]; 
	char orval[2];
	char incrementval[2];
	char defineval[7];
	char* printval; 
	char* returnval; 
	char* ifval;
	char* elseval; 
	char* whileval; 
	char* forval;
	char* voidval;  
	char* constval;
	char* readeval; 
	char* readcval; 
	char* orderval; 
	char* includeval; 
	char* enteteval; 
	char* doval; 
	char name_defineval[MAXNAME];
    char *cast;
}

%token <identval> IDENT
%token <intval>	NUM
%token <constval> CONST 
%token <charval> CARACTERE
%token <typeval> TYPE
%token <addsubval> ADDSUB 
%token <voidval> VOID 
%token <readeval> READE 
%token <readcval> READC 
%token <printval> PRINT 
%token <ifval> IF 
%token <elseval> ELSE 
%token <whileval> WHILE 
%token <forval> FOR
%token <returnval> RETURN 
%token <andval> AND 
%token <orval> OR 
%token <divstarval> DIVSTAR 
%token <eqval> EQ 
%token <orderval> ORDER
%token <incrementval> INCREMENT
%token <includeval> INCLUDE
%token <enteteval> ENTETE
%token <reelval> FLOAT
%token <doval> DO
%token <defineval> DEFINE
%token <name_defineval> NAME_DEFINE
%token <cast> CAST

%type <intval> F Exp EB TB FB M E T NombreSigne Litteral LitteralDefine ListExp DeclInit
%type <identval> LValue
%type <reelval> ReelSigne LitteralReel

%left ','
%precedence ')'
%precedence ELSE

%%

Prog: DeclInclude DeclDefine DeclConsts DeclVars DeclFoncts {print_end();}
    ;

DeclInclude:
        DeclInclude INCLUDE ENTETE
    |
    ;

DeclDefine:
        DeclDefine DEFINE NAME_DEFINE LitteralDefine    {
                                                            addMacro($3, type_define, $4, .0);
                                                        }
    |   DeclDefine DEFINE NAME_DEFINE LitteralReel {addMacro($3, type_define, 0, $4);}                                               
    |   DeclDefine DEFINE error LitteralDefine
    |   DeclDefine error NAME_DEFINE LitteralDefine
    |
    ;

LitteralDefine:
       NUM {type_define = INTEGER; $$ = $1;}
    |  CARACTERE {type_define = CHAR; $$ = $1;}
    
LitteralReel : ReelSigne {type_define = REAL; $$ = $1;}
    ;

DeclConsts:
       DeclConsts CONST ListConst ';' 
    |  DeclConsts error ListConst ';'
    |  DeclConsts CONST ListConst error
    |
    ;

ListConst:
       ListConst ',' IDENT '=' Litteral {
       										if(addConst($3, type_const, $5, .0) == 0){
       											flag_error = 1;
       										}
       									}
    |  ListConst ',' IDENT '=' ReelSigne {
                                            type_const = REAL;
                                            if(addConst($3, type_const, 0, $5) == 0){
                                                flag_error = 1;
                                            }
                                        }
    |  IDENT '=' Litteral               {
                                            if(addConst($1, type_const, $3, .0) == 0){
                                                flag_error = 1;
                                            }
                                        }
    |  IDENT '=' ReelSigne              {   type_const = REAL;
                                            if(addConst($1, type_const, 0, $3) == 0){
                                                flag_error = 1;
                                            }
                                        }
    ;

Litteral:
       NombreSigne {type_const = INTEGER;}
    |  CARACTERE {type_const = CHAR;}
    ;

NombreSigne:
       NUM {$$ = $1;}
    |  ADDSUB NUM {if($1 == '-'){$$ = -($2);}}
    ;

ReelSigne:
       FLOAT {$$ = $1;}
    |  ADDSUB FLOAT {if($1 == '-') $$ = -($2);}
    ;

DeclVars:
       DeclVars TYPE Declarateurs ';'
    |  DeclVars TYPE DeclInitVars ';'
    |  DeclVars error Declarateur ';'
    |  DeclVars TYPE Declarateur error
    |
    ;

Declarateurs:
       Declarateurs ',' Declarateur 
    |  Declarateurs ',' DeclInitVars
    |  Declarateur 
    ;

Declarateur:
       IDENT 	{
					if(addVar($1, type_var, 0, 0, .0) == 0){
						flag_error = 1;
					}
				}
    |  IDENT DeclarateurTableau
    |  error DeclarateurTableau
    ;

DeclInitVars:
	   DeclInitVars ',' DeclInitVar
	|  DeclInitVars ',' Declarateurs
	|  DeclInitVar
	;

DeclInitVar:
	  IDENT '=' DeclInit
	;

DeclInit:
	  NUM {addVar($<identval>-1, type_var, 0, $1, .0); fprintf(stdout, "    push QWORD %d\n", $$);}
	| ADDSUB NUM {
					if($1 == '-'){
						$$ = -($2);
					}
					addVar($<identval>-1, type_var, 0, $$, .0);
                    fprintf(stdout, "    push QWORD %d\n", $$);
				  }
    | FLOAT {addVar($<identval>-1, type_var, 0, 0, $1);}
    | ADDSUB FLOAT {
                    if($1 == '-'){
                        $$ = -($2);
                    }
                    addVar($<identval>-1, type_var, 0, 0, $$);
                  }
	| CARACTERE {
					addVar($<identval>-1, type_var, 0, $1, .0);
                    fprintf(stdout, "    push QWORD %d\n", $1);
				  }
	;

DeclarateurTableau:
	   '[' NUM ']' 
    |  '[' error ']' 
    |   DeclarateurTableau '[' NUM ']'
	|   DeclarateurTableau '[' error ']' 
	;

DeclFoncts:
       DeclFoncts DeclFonct 
    |  DeclFonct 
    ;

DeclFonct:
       EnTeteFonct Corps 
    |  EnTeteFonct
    ;

EnTeteFonct:
       TYPE IDENT '(' 
                    {   
                        strcpy(name_function, $2);
                        flag_return = 0;
                        addFun($2, getType($1));
                        if (flag_start) {
                            print_start(get_globals_size());
                            flag_start = 0;
                        }
                        fprintf(stdout, "%s:\n    push rbp\n    mov rbp, rsp\n", $2);
                        createStack();
                        parameters = 0;
                    } 
                    Parametres ')'   
                    {
                        int i;
                        for (i = parameters; i > 0; i--)
                            fprintf(stdout, "    push QWORD [rbp+%d]\n", (i+1) * 8);
                    }
    |  VOID IDENT '(' 
                    {   
                        strcpy(name_function, $2);
                        addFun($2, VOIDTYPE);
                        if (flag_start) {
                            print_start(get_globals_size()); 
                            flag_start = 0;
                        }
                        fprintf(stdout, "%s:\n    push rbp\n    mov rbp, rsp\n", $2);
                        createStack();
                        parameters = 0;
                    }
    
                    Parametres ')'   
                    {
                        int i;
                        for (i = parameters; i > 0; i--)
                            fprintf(stdout, "    push QWORD [rbp+%d]\n", (i+1) * 8);
                    }
    |  TYPE IDENT '(' error ')' 
    |  VOID IDENT '(' error ')' 
    |  error IDENT '(' Parametres ')' 
    |  TYPE error '(' Parametres ')' 
    ;

Parametres:
       VOID 
    |  ListTypVar 
    |
    ;

ListTypVar:
       ListTypVar ',' TYPE IDENT {  addVar($4, type_var, 1, 0, .0); 
                                    parameters++; 
                                    addArg(name_function, type_var);
                                 }
    |  TYPE IDENT                {  addVar($2, type_var, 1, 0, .0); 
                                    parameters++; 
                                    addArg(name_function, type_var);
                                 }
    |  ListTypVar error TYPE IDENT
    |  error IDENT
    |  TYPE error
    ;

Corps: '{' DeclConsts DeclVars SuiteInstr '}'   {                
                                                    if (lookupFunction(name_function) != VOIDTYPE && flag_return == 0)
                                                        yyerror("Function is non-void and should return a value");
                                                    fprintf(stdout, "fin_%s:\n", name_function); 
                                                    remove_st_cell();
                                                }
    ;

SuiteInstr:
       SuiteInstr Instr 
    |  ;

Instr:
    Exp ';'         {                
                        if ($1 != VOIDTYPE) 
                            fprintf(stdout, "    pop rcx\n");
                    }
    |  ';' 
    |  RETURN Exp ';'   {  
                            int type_fun = lookupFunction(name_function); 
                            if(type_fun == -1)
                                flag_error = 1; 
                            if(check_types($2, type_fun) == 0){
                                fprintf(stderr, "The function must return a value of this type %d\n", type_fun);
                                flag_error = 1;
                            }
                            flag_return = 1;
                            fprintf(stdout, "    pop rax\n    jmp fin_%s\n", name_function);
                        }
    |  RETURN ';'   {
                            int type_fun = lookupFunction(name_function); 
                            if(type_fun == -1)
                                flag_error = 1; 
                            if(check_types(VOIDTYPE, type_fun) == 0){
                                fprintf(stderr, "The function must return a void value\n");
                                flag_error = 1;
                            }
                            fprintf(stdout, "    pop rax\n    jmp fin_%s\n", name_function);
                    }
    |  READE '(' IDENT ')' ';' 
                    {
                        if (check_types(lookup($3, 0), INTEGER) == 0){
                            fprintf(stderr, "Reade is only for variables of type entier\n"); 
                            flag_error = 1;
                        }
                        int address[2]; 
                        get_address($3, address);
                        switch (address[1]) {
                            case 0: fprintf(stdout, "    mov rsi, rbp\n    sub rsi, %d\n", address[0]); break;
                            case 1: fprintf(stdout, "    mov rsi, globals\n    add rsi, %d\n", address[0]); break;
                            case 2: fprintf(stderr, "Assignment to a const variable impossible\n"); break;
                            default: fprintf(stderr, "Impossible\n"); break;
                        }
                        fprintf(stdout, "    call _reade\n");
                    }
    |  READC '(' IDENT ')' ';'
                    {
                        if (check_types(lookup($3, 0), CHAR) == 0){
                            fprintf(stderr, "Readc is only for variables of type caractere\n");  
                            flag_error = 1;
                        }
                        int address[2]; 
                        get_address($3, address);
                        switch (address[1]) {
                            case 0: fprintf(stdout, "    mov rsi, rbp\n    sub rsi, %d\n", address[0]); break;
                            case 1: fprintf(stdout, "    mov rsi, globals\n    add rsi, %d\n", address[0]); break;
                            case 2: fprintf(stderr, "Assignment to a const variable impossible\n"); break;
                            default: fprintf(stderr, "Impossible\n"); break;
                        }
                        fprintf(stdout, "    call _reade\n");
                    }
    |  PRINT '(' Exp ')' ';'  {
                                        switch ($3) {
                                            case INTEGER: fprintf(stdout, "    pop rsi\n    call _print_ent\n"); break;
                                            case CHAR: fprintf(stdout, "    pop rsi\n    call _print_car\n"); break;
                                            case VOIDTYPE: yyerror("Can't print void value"); break;
                                        }
                                    }
    |  IF '(' Exp ')' Instr 
    |  IF '(' Exp ')' Instr ELSE Instr
    |  WHILE '(' Exp ')' Instr
    |  FOR '(' IDENT '=' NUM ';' Exp ';' Exp ')' Instr
    |  DO '{' SuiteInstr '}' WHILE '(' Exp ')' ';'
    |  '{' SuiteInstr '}' 
    |  IF error Exp ')' Instr
    |  IF '(' Exp error  Instr
    |  FOR '(' error '=' NUM ';' Exp ';' Exp ')' Instr
    |  FOR '(' IDENT '=' error ';' Exp ';' Exp ')' Instr
    |  FOR '(' IDENT '=' NUM ';' Exp ';' error ')' Instr
    |  FOR '(' IDENT error NUM ';' Exp ';' Exp ')' Instr
    |  READE '(' error ')' ';'
    |  READC '(' error ')' ';'
    ;

Exp :  LValue '=' Exp {
                        if(isConstante($1) == 1){flag_error = 1;}
                        $$ = lookup($1, 0); 
                        if($$ == -1){flag_error = 1;} 
                        $$ = cast_type($$, $3, 0);
                        if($$ == -1){flag_error = 1;}
                        int addr[2]; 
                        get_address($1, addr);
                        switch (addr[1]) {
                            case 0: fprintf(stdout, "    pop QWORD [rbp-%d]\n    push QWORD [rbp-%d]\n", addr[0], addr[0]); break;
                            case 1: fprintf(stdout, "    pop QWORD [globals+%d]\n    push QWORD [globals+%d]\n", addr[0], addr[0]); break;
                            case 2: fprintf(stderr, "%s is a const variable near line %d\n", $1, line_num); break;
                            default: yyerror("impossible"); break;
                        }
                    }
    |   LValue '=' '(' TYPE ')' Exp {
                        if(isConstante($1) == 1){flag_error = 1;}
                        $$ = lookup($1, 0); 
                        if($$ == -1){flag_error = 1;} 
                        $$ = cast_type($$, $6, getType($4));
                        if($$ == -1){flag_error = 1;}
                    }
    |  LValue '=' NAME_DEFINE   {   if(isConstante($1) == 1){flag_error = 1;}
                                    $$ = lookup($1, 0); 
                                    if($$ == -1){flag_error = 1;}
                                    type_macro_assign = lookup($3, 0); 
                                    if(type_macro_assign == -1){flag_error = 1;}
                                    check_types($$, type_macro_assign);
                                }
    |  EB {$$ = $1;}
    ; 


EB  :  EB OR TB {$$ = INTEGER;}
    |  TB {$$ = $1;}
    ;
TB  :  TB AND FB {$$ = INTEGER;}
    |  FB {$$ = $1;}
    ;

FB  :  FB EQ M {$$ = INTEGER;}
    |  M {$$ = $1;}
    ;
M   :  M ORDER E {$$ = INTEGER;}
    |  E {$$ = $1;}
    ;
E   :  E ADDSUB T   {
                        $$ = max_type($1, $3);
                        switch ($2) {
                            case '+': fprintf(stdout, "    pop rcx\n    pop rax\n    add rax, rcx\n    push rax\n"); break;
                            case '-': fprintf(stdout, "    pop rcx\n    pop rax\n    sub rax, rcx\n    push rax\n"); break;
                        }
                        
                    }
    |  T {$$ = $1;}
    ;    
T   :  T DIVSTAR F  {
                        $$ = max_type($1, $3);
                        fprintf(stdout, "    pop rcx\n    pop rax\n");
                        switch ($2) {
                            case '*': fprintf(stdout, "    imul rcx\n    push rax\n"); break;
                            case '/': fprintf(stdout, "    mov rdx,0\n    idiv rcx\n    push rax\n"); break;
                            case '%': fprintf(stdout, "    mov rdx,0\n    idiv rcx\n    push rdx\n"); break;
                        }
                    }
    |  F {$$ = $1;}
    ;

F   :  ADDSUB F {$$ = $2;}
    |  '!' F {$$ = INTEGER;}
    |  '(' Exp ')' {$$ = $2;}
    |  IDENT  {
    				$$ = lookup($1, 0);
    				if($$ == -1){
    					flag_error = 1;
                    }
                    int address[2]; 
                    if(get_address($1, address) == -1)
                        flag_error = 1; 
                    switch(address[1]){
                        case 0: fprintf(stdout, "    push QWORD [rbp-%d]\n", address[0]); break;
                        case 1: fprintf(stdout, "    push QWORD [globals+%d]\n", address[0]); break;
                        case 2: fprintf(stdout, "    push QWORD %d\n", address[0]); break;
                        default: fprintf(stderr, "Impossible\n"); break;
                    }

    			}
    |  NAME_DEFINE {if(($$ = lookup($1, 0)) == -1){flag_error = 1;}}
    |  NUM {$$ = INTEGER; fprintf(stdout, "    push QWORD %d\n", $1);}
    |  FLOAT {$$ = REAL;}
    |  CARACTERE {$$ = CHAR; fprintf(stdout, "    push QWORD %d\n", $1);}
    |  IDENT   
                {
                    add_call_cell($1);
                    args = get_func_i_arg();
                    get_func_call_name(name_called_function);
                }       
                '(' 
    
                    Arguments  ')' 
                {
                    if(($$ = lookupFunction($1)) == -1)
                        flag_error = 1;
                    fprintf(stdout, "    call %s\n",$1);
                    check_nargs($1, *args);
                    int i;
                    for (i = 0; i < *args; i++){
                        fprintf(stdout, "    pop rbx\n");
                    }
                    if (lookupFunction(name_called_function) != VOIDTYPE)
                        fprintf(stdout, "    push rax\n");
                    remove_call_cell();
                    args = get_func_i_arg();
                    get_func_call_name(name_called_function);
                }
    |  error '(' Arguments ')'
    ;

LValue:
       IDENT Tableau {strcpy($$, $1);}
    ;

Tableau: 
	  '[' Exp ']' Tableau
	| '[' error ']' Tableau
	|
	;

Arguments:
       ListExp 
    | 
    ;

ListExp:
       ListExp ',' Exp  {
                            
                            if (!check_types(get_arg_type(name_called_function, *args), $3))
                                fprintf(stderr, "%d argument type does not match the expected type\n", (*args));
                            (*args)++;
                        }
    |  Exp      {
                    if (!check_types(get_arg_type(name_called_function, *args), $1))
                       fprintf(stderr, "%d argument type does not match the expected type\n", (*args));
                    (*args)++; 
                }
    |  ListExp error Exp
    ;

%%

void yyerror(char *s){
    printf("Erreur %s near line %d \n", s, line_num);
    flag_error = 1;
}
 
int main(int argc, char* argv[]){
    option_parsing(argc, argv);
	initProg();
    yyparse();
    return flag_error;
}
