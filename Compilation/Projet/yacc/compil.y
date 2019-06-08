%{
#include <stdio.h>
#include <string.h>
#include "../header/decl.h"
#include "../header/input-output.h"

int yylex(void);
void yyerror(char* s);
int flag_error = 0;
int flag_start = 1; 
int flag_return = 0; 
int type_const = -1; 
int type_var = -1;
int jump_label = 0;
int parameters = 0;
int dimension_array = 0;
int is_global_variable = 1;
int is_const_variable = 1;
int current_num_array = 0;
int call_num_array = 0;
int array_size[10000];
int lvalue_called_is_array = 0;
int num_array_called[10000];
int dim_array_called = 0;
int *args = NULL;
char name_function[MAXNAME];
char name_called_function[MAXNAME];
char name_called_array[MAXNAME];
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

%type <intval> F Exp EB TB FB M E T NombreSigne Litteral ListExp DeclInit TradIF FinTradIF DeclarateurTableau
%type <identval> LValue

%left ','
%precedence ')'
%precedence ELSE

%%

Prog: DeclConsts DeclVars DeclFoncts {print_end();}
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
    |  IDENT '=' Litteral               {
                                            if(addConst($1, type_const, $3, .0) == 0){
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
                    if(is_global_variable == 0)
                        fprintf(stdout, "     push QWORD 0\n");
				}
    |  IDENT    {   int j; 
                    for(j = 0; j < 1000; j++){
                        array_size[j] = 0;
                    }
                    current_num_array = 0;
                }
        DeclarateurTableau {
                                    dimension_array = $3;
                                    addTab($1, type_var, array_size, dimension_array, is_global_variable); 
                                }
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
	  NUM   { 
                addVar($<identval>-1, type_var, 0, $1, .0); 
                if(is_global_variable == 0)
                    fprintf(stdout, "    push QWORD %d\n", $$);
            }
	| ADDSUB NUM {
					if($1 == '-'){
						$$ = -($2);
					}
					addVar($<identval>-1, type_var, 0, $$, .0);
                    if(is_global_variable == 0)
                        fprintf(stdout, "    push QWORD %d\n", $$);
				  }
	| CARACTERE {
					addVar($<identval>-1, type_var, 0, $1, .0);
                    if(is_global_variable == 0)
                        fprintf(stdout, "    push QWORD %d\n", $$);
				  }
	;

DeclarateurTableau:
	   '[' NUM ']' {$$ = 1; array_size[current_num_array] = $2; current_num_array++;}
    |  '[' error ']' {$$ = 0;}
    |   DeclarateurTableau '[' NUM ']' {$$ = $1 + 1; array_size[current_num_array] = $3; current_num_array++;}
	|   DeclarateurTableau '[' error ']' {$$ = 0;}
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
                            is_global_variable = 0;
                            char vars[64][64]; 
                            long vals[64];
                            char consts[64][64];
                            long cvals[64];
                            char arrays[MAXNAME][MAXNAME];
                            int dimensions[MAXNAME]; 
                            int *size_par_dim[MAXNAME];
                            get_globals_var(vars, vals);
                            get_globals_const(consts, cvals);
                            get_globals_array(arrays, dimensions, size_par_dim);
                            print_start(get_globals_vars_size(), get_globals_const_size(), get_globals_array_size(), vars, vals, consts, cvals, arrays, dimensions, size_par_dim);
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
                            is_global_variable = 0;
                            char vars[64][64]; 
                            long vals[64];
                            char consts[64][64];
                            long cvals[64];
                            char arrays[MAXNAME][MAXNAME];
                            int dimensions[MAXNAME]; 
                            int *size_par_dim[MAXNAME];
                            get_globals_var(vars, vals);
                            get_globals_const(consts, cvals);
                            get_globals_array(arrays, dimensions, size_par_dim);
                            print_start(get_globals_vars_size(), get_globals_const_size(), get_globals_array_size(), vars, vals, consts, cvals, arrays, dimensions, size_par_dim);
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

ListTypVar: ListTypVar ',' TYPE IDENT {  addVar($4, type_var, 1, 0, .0); 
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
                        fprintf(stdout, "    call _readc\n");
                    }
    |  PRINT '(' Exp ')' ';'  {
                                        switch ($3) {
                                            case INTEGER: fprintf(stdout, "    pop rsi\n    call _print_ent\n"); break;
                                            case LONG: fprintf(stdout, "    pop rsi\n    call _print_long\n"); break;
                                            case CHAR: fprintf(stdout, "    pop rsi\n    call _print_car\n"); break;
                                            case VOIDTYPE: fprintf(stderr, "Can't print void value"); break;
                                            default : fprintf(stderr, "Error\n");
                                        }
                                    }
    |  IF '(' Exp TradIF ')' Instr FinTradIF
        {
            fprintf(stdout, "fin_if%d:\n", $<intval>4);
        }
        ;
    |  IF '(' Exp TradIF ')' Instr FinTradIF ELSE Instr FinELSE
    |  WHILE
            {fprintf(stdout, "debut_while%d:\n", $<intval>$ = jump_label++);} 
       '(' Exp ')' 
            {fprintf(stdout, "    pop rax\n    cmp rax, 0\n    je fin_while%d\n", $<intval>2);}
       Instr 
            {fprintf(stdout, "    jmp debut_while%d\nfin_while%d:\n", $<intval>2, $<intval>2);}
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

TradIF:
        {fprintf(stdout, "    pop rax\n    cmp rax,0\n    je else_no%d\n",$<intval>$=jump_label++);};

FinTradIF :
        {fprintf(stdout, "    jmp fin_if%d\nelse_no%d:\n", $<intval>-2,$<intval>-2);}; 

FinELSE :
        {fprintf(stdout, "fin_if%d:\n", $<intval>-5);};


Exp :  LValue '=' Exp {
                        if(lvalue_called_is_array == 1){
                            if(globale_array($1)){
                                $$ = lookup($1, 1);
                                check_types($$, $3);
                                if(dim_array_called >= 1){
                                    fprintf(stdout, "   pop rdx\n      mov QWORD [%s+rbx], QWORD rdx\n     push 1\n", $1);      
                                }
                            }
                            else{
                                $$ = lookup($1, 1);
                                check_types($$, $3);
                                int addr[2];
                                get_address($1, addr);
                                if(addr[1] == 3){
                                    //fprintf(stdout, "    pop rdx\nmov rbx, rbp\n      add rax, %d\n      sub rbx, rax\n      mov QWORD [rbx], rdx\n     push QWORD [rbx]\n", addr[0]);
                                }
                            }
                        }
                        else{
                            if(isConstante($1) == 1){flag_error = 1;}
                            $$ = lookup($1, 0); 
                            if($$ == -1){
                                flag_error = 1;
                            } 
                            $$ = cast_type($$, $3, 0);
                            if($$ == -1){
                                flag_error = 1;
                            }
                            if(globale_variable($1) == 1){
                                fprintf(stdout, "    pop rdx\n    mov QWORD [%s], QWORD rdx\n    push QWORD rdx\n", $1);
                            }
                            else if(globale_const($1) == 1){
                                fprintf(stderr, " %s is a const variable near line %d\n", $1, line_num);
                            }
                        }
                    }
    |   LValue '=' '(' TYPE ')' Exp {
                        if(isConstante($1) == 1){flag_error = 1;}
                        $$ = lookup($1, 0); 
                        if($$ == -1){flag_error = 1;} 
                        $$ = cast_type($$, $6, getType($4));
                        if($$ == -1){flag_error = 1;}
                        int addr[2]; 
                        get_address($1, addr);
                        switch (addr[1]) {
                            case 0: fprintf(stdout, "    pop QWORD [rbp-%d]\n    push QWORD [rbp-%d]\n", addr[0], addr[0]); break;
                            case 2: fprintf(stderr, "%s is a const variable near line %d\n", $1, line_num); break;
                            default: flag_error = 1; fprintf(stderr, "Impossible\n"); break;
                        }
                    }
    |  EB 
    ; 


EB  :  EB 
            {
                if (check_types($1, INTEGER) == 0)
                    fprintf(stderr, "Can only apply || to entier values\n"); 
                fprintf(stdout, "    pop rax\n    cmp rax,0\n    jne go_end%d\n", $<intval>$=jump_label++);
            }
       OR TB 
            {
                if (check_types($1, $4) == 0)
                    fprintf(stderr, "Can only apply || to entier values\n"); 
                fprintf(stdout, "    pop rcx\n    mov rax,rcx\ngo_end%d:\n    push rax\n",$<intval>2);
                $$ = INTEGER;
            }
    |  TB {$$ = $1;}
    ;
TB  :  TB   { 
                if (check_types($1, INTEGER) == 0)
                    fprintf(stderr, "Can only apply && to entier values\n"); 
                fprintf(stdout, "    pop rax\n    cmp rax,0\n    je go_end%d\n",$<intval>$=jump_label++);
            }
       AND FB
            {
                if (check_types($1, $4) == 0)
                    fprintf(stderr, "Can only apply && to entier values\n"); 
                fprintf(stdout, "    pop rcx\n    mov rax,rcx\ngo_end%d:\n    push rax\n",$<intval>2);          
                $$ = INTEGER;
            }
    |  FB {$$ = $1;}
    ;

FB  :  FB EQ M
        {
            if (check_types($1, $3) == 0){
                fprintf(stderr, "Can only apply == to values of same type\n"); 
                flag_error = 1;
            }
            fprintf(stdout, "    pop rcx\n    pop rax\n    cmp rax,rcx\n    mov rax,0\n");
            if (strcmp($2,"==") == 0){
                fprintf(stdout, "    jne cond_eq%d\n",jump_label);
            }
            else if (strcmp($2,"!=") == 0){
                fprintf(stdout, "    je cond_eq%d\n",jump_label);
            }
            fprintf(stdout, "    mov rax,1\ncond_eq%d:\n    push rax\n",jump_label++);
            $$ = INTEGER;
        } 
    |  M {$$ = $1;}
    ;
M   :  M ORDER E {
                if(check_types($1, $3) == 0)
                    fprintf(stderr, "Can only apply >=, <=, > and < to entier values\n"); 
                fprintf(stdout,"    pop rcx\n    pop rax\n    cmp rax, rcx\n    mov rax,1\n");
                if (strcmp($2, ">") == 0) {
                    fprintf(stdout,"    jg cond_ord%d\n",jump_label); 
                    fprintf(stdout, "    mov rax,0\n");
                }
                else if (strcmp($2, "<=") == 0) {
                    fprintf(stdout,"    jng cond_ord%d \n", jump_label);
                    fprintf(stdout,"    je cond_ord%d \n", jump_label);
                    fprintf(stdout,"    mov rax, 0 \n");
                }
                else if (strcmp($2, "<") == 0) {
                    fprintf(stdout,"    mov rax, 0 \n");
                    fprintf(stdout,"    jg cond_ord%d \n", jump_label);
                    fprintf(stdout,"    je cond_ord%d \n", jump_label);
                    fprintf(stdout,"    mov rax, 1 \n");
                }
                else if (strcmp($2, ">=") == 0) {
                    fprintf(stdout,"    jg cond_ord%d \n", jump_label);
                    fprintf(stdout,"    je cond_ord%d \n", jump_label);
                    fprintf(stdout,"    mov rax, 0 \n");
                }
                fprintf(stdout, "cond_ord%d:\n    push rax\n",jump_label++);
                $$ = INTEGER;
            }
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

F   :  ADDSUB F  
            {
                if (check_types($2, INTEGER) == 0)
                    fprintf(stderr, "Can only apply - + to entier values\n"); 
                $$ = $2;
                if ($1 == '-')
                    fprintf(stdout, "    pop rax\n     mov rcx, -1\n    imul rcx\n   push rax\n");
            }
    |  '!' F             
            {
                if (check_types($2, INTEGER) == 0)
                    fprintf(stderr, "Can only apply ! to entier values\n"); 
                $$ = $2;
                fprintf(stdout,"    pop rax\n    cmp rax, 0\n    mov rax,1\n    je if_no%d\n", jump_label);
                fprintf(stdout, "    mov rax,0\nif_no%d:\n    push rax\n", jump_label++);
            }
    |  '(' Exp ')' {$$ = $2;}
    |  IDENT  {
    				$$ = lookup($1, 0);
    				if($$ == -1){
    					flag_error = 1;
                    }
                    if(globale_variable($1) == 1){
                        fprintf(stdout, "    push QWORD [%s]\n", $1);
                    }
                    else if(globale_const($1) == 1){
                        fprintf(stdout, "    push QWORD %s\n", $1);
                    }
                    else{                       
                        int address[2]; 
                        if(get_address($1, address) == -1)
                            flag_error = 1; 
                        switch(address[1]){
                            case 0: fprintf(stdout, "    push QWORD [rbp-%d]\n", address[0]); break;
                            case 2: fprintf(stdout, "    push QWORD %d\n", address[0]); break;
                        }
                    }

    			}
    |  '(' TYPE ')' IDENT  {
    				$$ = lookup($4, 0);
    				if($$ == -1){
    					flag_error = 1;
                    }
                    int address[2]; 
                    if(get_address($4, address) == -1)
                        flag_error = 1; 
                    switch(address[1]){
                        case 0: fprintf(stdout, "    push QWORD [rbp-%d]\n", address[0]); break;
                        case 1: fprintf(stdout, "    push QWORD [globals+%d]\n", address[0]); break;
                        case 2: fprintf(stdout, "    push QWORD %d\n", address[0]); break;
                    }

    			}
    |  LValue
                {   
                    $$ = lookup($1, 1);
                    if(lvalue_called_is_array == 1){
                        if(globale_array($1) == 1){
                            fprintf(stdout, "    push QWORD [%s+rbx]\n", $1);
                        }
                        else{
                            int addr[2]; 
                            get_address($1, addr);
                            if(addr[1] == 3){
                                //fprintf(stdout, "mov rbx, rbp\n      add rax, %d\n      sub rbx, rax\n      mov QWORD [rbx], rdx\n     push QWORD [rbx]\n", addr[0]);
                            }
                        }
                    }
                }
    |  NUM {$$ = INTEGER; fprintf(stdout, "    push QWORD %d\n", $1);}
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
       IDENT 
       {
            call_num_array = 0; 
            lvalue_called_is_array = 0; 
            dim_array_called = 0; 
            strcpy(name_called_array, $1);
        } 
       Tableau      {
                        strcpy($$, $1);
                        if(dim_array_called > get_dimensions(name_called_array)){
                            fprintf(stderr, "%sError : %s%s is an array of dimension %d on line %d\n", RED, DEFAULT, $1, get_dimensions($1), line_num);
                            flag_error = 1;
                        }
                        if(dim_array_called < get_dimensions(name_called_array)){
                            fprintf(stderr, "%sError : %s%s is an array of dimension %d but you get %d dimensions on line %d\n", RED, DEFAULT, $1, get_dimensions($1), dim_array_called, line_num);
                            flag_error = 1;
                        }
                        if(call_num_array >= 1){
                            lvalue_called_is_array = 1;
                        }
                        int i; 
                        if(globale_array(name_called_array) == 1){
                            for(i = 1; i < dim_array_called; i++)
                                fprintf(stdout, "    pop rdx\n");
                        }
                        else{
                            for(i = 0; i < dim_array_called; i++)
                                fprintf(stdout, "    pop rdx\n");
                        }
                    }
    ;

Tableau: 
	  '[' Exp ']' Tableau   {   dim_array_called++; 
                                call_num_array++;
                                if(dim_array_called == get_dimensions(name_called_array) && globale_array(name_called_array) == 1)
                                    fprintf(stdout, "    push QWORD %d\n    pop rax\n      imul QWORD [__size___tab__]\n     pop rbx\n     imul rbx\n     sub rax, QWORD [__size___tab__]\n    mov QWORD rbx, QWORD rax\n", dim_array_called); 
                            }
	| '[' error ']' Tableau
	|
	;

Arguments:
       ListExp 
    | 
    ;

ListExp:
       ListExp ',' Exp  {
                            
                            if (check_types(get_arg_type(name_called_function, *args), $3) == 0)
                                fprintf(stderr, "%d argument type does not match the expected type\n", (*args));
                            (*args)++;
                        }
    |  Exp      {
                    if (check_types(get_arg_type(name_called_function, *args), $1) == 0)
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
