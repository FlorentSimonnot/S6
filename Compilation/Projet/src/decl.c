/* decl-var.c */
/* Traduction descendante récursive des déclarations de variables en C */
/* Compatible avec decl-var.lex */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../header/decl.h"

STStack symbol_table = NULL;
CStack cs = NULL;
ArrayTab array_table; 
Mtable macro_table;
Ftable  function_table;
extern int line_num;

static void createFunTable(){
    if (NULL == (function_table.Ftable = (FUNentry*)malloc(sizeof(FUNentry)*MAXNBSYMBOL))){
        fprintf(stderr, "Allocation error on function_table\n");
        exit(EXIT_FAILURE);
    }
    function_table.Fmax = MAXNBSYMBOL;
    function_table.Fsize = 0;
}

static void createMacroTable(){
    
    if(NULL == (macro_table.Mtable = (MACROentry*)malloc(MAXNBSYMBOL*sizeof(MACROentry)))){
        fprintf(stderr, "Allocation error\n");
        exit(EXIT_FAILURE);
    } 
    macro_table.Msize = 0; 
    macro_table.Mmax = MAXNBSYMBOL;
}

void initProg(){
	createStack();
    createMacroTable();
    createFunTable();
}

void createStack() {
    STStackCel *new_cell = NULL;

    if (NULL == (new_cell = (STStackCel*)malloc(sizeof(STStackCel)))){
        fprintf(stderr, "Allocation error\n");
        exit(EXIT_FAILURE);
    }
    if (NULL == (new_cell->STtable = (STentry*)malloc(MAXNBSYMBOL*sizeof(STentry)))){
        fprintf(stderr, "Allocation error\n");
        exit(EXIT_FAILURE);        
    }
    if (NULL == (new_cell->Ctable = (CONSTentry*)malloc(MAXNBSYMBOL*sizeof(CONSTentry)))){
        fprintf(stderr, "Allocation error\n");
        exit(EXIT_FAILURE);        
    }
    if (NULL == (new_cell->Atable = (Arrayentry*)malloc(MAXNBSYMBOL*sizeof(Arrayentry)))){
        fprintf(stderr, "Allocation error\n");
        exit(EXIT_FAILURE);        
    }
    new_cell->STmax = MAXNBSYMBOL;
    new_cell->STsize = 0;
    new_cell->Cmax = MAXNBSYMBOL;
    new_cell->Csize = 0;
    new_cell->Amax = MAXNBSYMBOL;
    new_cell->Asize = 0;
    new_cell->next = symbol_table;
    new_cell->current_stack_address = 0;
    symbol_table = new_cell;
}

int getType(const char *type){
	if(strcmp(type, "int") == 0){
		return INTEGER;
	}
	else if(strcmp(type, "char") == 0){
		return CHAR;
	}
	else if(strcmp(type, "float") == 0){
		return REAL;
	}
    else if(strcmp(type, "long") == 0){
        return LONG;
    }
    else if(strcmp(type, "void") == 0){
        return VOIDTYPE;
    }
	return ERR_TYPE;
}

static int checkName(const char name[]){
    int i;
    for (i = 0; i < symbol_table->STsize; i++) {
        if (strcmp(symbol_table->STtable[i].name, name) == 0) {
            fprintf(stderr, "\033[31mError : \033[0mSemantic error, redefinition of variable %s near line %d\n", name, line_num);
        	return 0;
        }
    }
    for (i = 0; i < symbol_table->Csize; i++){
        if (strcmp(symbol_table->Ctable[i].name, name) == 0) {
            fprintf(stderr, "\033[31mError : \033[0mSemantic error, redefinition of variable %s near line %d\n", name, line_num);
        	return 0;
        }
    }
    for (i = 0; i < symbol_table->Asize; i++){
        if (strcmp(symbol_table->Atable[i].name, name) == 0) {
            fprintf(stderr, "\033[31mError : \033[0mSemantic error, redefinition of array %s near line %d\n", name, line_num);
        	return 0;
        }
    }
    for (i = 0; i < macro_table.Msize; i++){
        if (strcmp(macro_table.Mtable[i].name, name) == 0) {
            fprintf(stderr, "\033[31mError : \033[0mSemantic error, redefinition of variable %s near line %d\n", name, line_num);
            return 0;
        }
    }
    return 1;
}

int addVar(const char name[], int type, int is_parameter, int value, float valueFloat){
    int i;
    
    if(checkName(name) == 0){
    	return 0;
    }

    /*Verif taille*/
    if (symbol_table->STsize >= symbol_table->STmax) {
        symbol_table->STmax *= 2;
        if (NULL == (symbol_table->STtable = realloc(symbol_table->STtable, symbol_table->STmax * sizeof(STentry)))){
            fprintf(stderr, "Allocation error\n");
            exit(EXIT_FAILURE);
        }
    }

    i = symbol_table->STsize;
    strcpy(symbol_table->STtable[i].name, name);
    symbol_table->STtable[i].type = type;
    symbol_table->STtable[i].size = 0;
    symbol_table->current_stack_address += 8;
    symbol_table->STtable[i].address = symbol_table->current_stack_address;
    if(type != 2){
        symbol_table->STtable[i].value = value;
    }
    else{
        symbol_table->STtable[i].valueFloat = valueFloat;
    }
    symbol_table->STsize++;
    
    return 1;
}

int addConst(const char name[], int type, int value, float valueFloat){
    int i;

    if(checkName(name) == 0)
    	return 0;

    if (symbol_table->Csize >= symbol_table->Cmax) {
        symbol_table->Cmax *= 2;
        if (NULL == (symbol_table->Ctable = realloc(symbol_table->Ctable, symbol_table->Cmax * sizeof(CONSTentry)))){
            fprintf(stderr, "Allocation error on realloc Ctable\n");
            exit(EXIT_FAILURE);
        }
    }
    i = symbol_table->Csize;
    strcpy(symbol_table->Ctable[i].name, name);
    symbol_table->Ctable[i].type = type;
    if(type != 2){
        symbol_table->Ctable[i].value = value;
    }
    else{
        symbol_table->Ctable[i].valueFloat = valueFloat;
    }
    symbol_table->Csize++;
    return 1;
}

int addMacro(const char name[], int type, int value, float valueFloat){
    int i;
    if(checkName(name) == 0)
        return 0;

    if (macro_table.Msize >= macro_table.Mmax) {
        macro_table.Mmax *= 2;
        if (NULL == (macro_table.Mtable = realloc(macro_table.Mtable, macro_table.Mmax * sizeof(MACROentry)))){
            fprintf(stderr, "Allocation error on realloc Ctable\n");
            exit(EXIT_FAILURE);
        }
    }

    i = macro_table.Msize;
    strcpy(macro_table.Mtable[i].name, name);
    macro_table.Mtable[i].type = type;
    if(type != 2){
        macro_table.Mtable[i].value = value;
    }
    else{
        macro_table.Mtable[i].valueFloat = valueFloat;
    }
    macro_table.Msize++;
    return 1;
}

void addTab(const char name[], int type, int *size, int dimension, int is_global){
    int i, j, k;
    if (size == NULL){
        fprintf(stderr, "Invalid tab size %d near line %d\n", 0, line_num);
    }

    if (dimension <= 0){
        fprintf(stderr, "Invalid tab dimension %d near line %d\n", dimension, line_num);
    }
    
    checkName(name);

    if (symbol_table->Asize >= symbol_table->Amax) {
        symbol_table->Amax *= 2;
        if (NULL == (symbol_table->Atable = realloc(symbol_table->Atable, symbol_table->Amax * sizeof(Arrayentry)))){
            fprintf(stderr, "Allocation error on realloc Arraytable\n");
            exit(EXIT_FAILURE);
        }
    }
    i = symbol_table->Asize;
    strcpy(symbol_table->Atable[i].name, name);
    symbol_table->Atable[i].type = type;
    symbol_table->Atable[i].size_par_dim = (int *) malloc(sizeof(int) * dimension);
    symbol_table->Atable[i].dimension = dimension; 
    for(j = 0; j < dimension; j++)
        symbol_table->Atable[i].size_par_dim[j] = size[j];
    symbol_table->Atable[i].address = symbol_table->current_stack_address+8;
    symbol_table->Asize++;
    for (j = 0; j < dimension; j++){
        for(k = 0; k < size[j]; k++){
            symbol_table->current_stack_address += (j*8) + (k*8);
            if (symbol_table->next != NULL){
                fprintf(stdout, "    push QWORD 0\n");
            }
        }
    }
}

static int checkNameFun(const char name[]){
    int i;
    for (i = 0; i < symbol_table->STsize; i++) {
        if (strcmp(symbol_table->STtable[i].name, name) == 0) {
            fprintf(stderr, "\033[31mError : \033[0mSemantic error, redefinition of variable %s near line %d\n", name, line_num);
            return 0;
        }
    }

    return 1;
}

int addFun(const char name[], int type){
    int i; 

    if(checkNameFun(name) == 0)
        return 0;

    if (function_table.Fsize == function_table.Fmax){
        function_table.Fmax *= 2;
        if (NULL == (function_table.Ftable = realloc(function_table.Ftable, function_table.Fmax*sizeof(FUNentry)))){
            fprintf(stderr, "Reallocation error on ftable\n");
            exit(EXIT_FAILURE);
        }
    }

    if (NULL == (function_table.Ftable[function_table.Fsize].args = (int *) malloc(MAXNBSYMBOL*sizeof(int)))){
        fprintf(stderr, "Allocation error on function args\n");
        exit(EXIT_FAILURE);
    }

    i = function_table.Fsize;
    function_table.Ftable[i].return_type = type;
    strcpy(function_table.Ftable[i].name, name);
    function_table.Ftable[i].Nargs = 0;
    function_table.Ftable[i].MAXargs = MAXNBSYMBOL;
    function_table.Fsize++;
    return 1;
}

void displayTable(){
    int i;
    STStackCel * curs = symbol_table;

    fprintf(stderr, "\n=====================TABLE DES VARIABLES================\n\n");

    while (curs != NULL){
        for (i = 0; i < curs->STsize; i++){
            if(curs->STtable[i].type == INTEGER || curs->STtable[i].type == LONG)
                fprintf(stderr, "%s %d %d %ld\n", curs->STtable[i].name, curs->STtable[i].type, curs->STtable[i].address, curs->STtable[i].value);
            else if(curs->STtable[i].type == CHAR)
                fprintf(stderr, "%s %d %d %c\n", curs->STtable[i].name, curs->STtable[i].type, curs->STtable[i].address, (char) curs->STtable[i].value);
            else if(curs->STtable[i].type == REAL)
                fprintf(stderr, "%s %d %d %f\n", curs->STtable[i].name, curs->STtable[i].type, curs->STtable[i].address, curs->STtable[i].valueFloat);
        }
        curs = curs->next;
    }
}

void displayArray(){
    int i;
    STStackCel * curs = symbol_table;

    fprintf(stderr, "\n=====================TABLE DES TABLEAUX================\n\n");

    while (curs != NULL){
        for (i = 0; i < curs->Asize; i++){
            if(curs->Atable[i].type == INTEGER || curs->Atable[i].type == LONG)
                fprintf(stderr, "%s %d %d \n", curs->Atable[i].name, curs->Atable[i].type, curs->Atable[i].address);
            else if(curs->Atable[i].type == CHAR)
                fprintf(stderr, "%s %d %d \n", curs->Atable[i].name, curs->Atable[i].type, curs->Atable[i].address);
        }
        curs = curs->next;
    }
    fprintf(stderr, "\n");
}

int isTab(const char name[]){
    int i;
    STStackCel * curs = symbol_table;

    while (curs != NULL){
        for (i = 0; i < curs->STsize; i++){
            if(strcmp(name, curs->STtable[i].name) == 0 && curs->STtable[i].size >= 1){
                return 1;
            }
        }
        curs = curs->next;
    } 
    return 0;
}

int isConstante(const char name[]){
    int i;
    STStackCel * curs = symbol_table;

    while (curs != NULL){
        for (i = 0; i < curs->Csize; i++){
            if(strcmp(name, curs->Ctable[i].name) == 0){
                fprintf(stderr, "%sError:%s %s is a constante. We can't assign a value.\n",RED, DEFAULT, name);
                return 1;
            }
        }
        curs = curs->next;
    } 
    return 0;
}

void displayConst(){
    int i;
    STStackCel * curs = symbol_table;

    fprintf(stderr, "\n=====================TABLE DES CONSTANTES================\n\n");

    while (curs != NULL){
        for (i = 0; i < curs->Csize; i++){
            if(curs->Ctable[i].type == INTEGER)
                fprintf(stderr, "%s %d %d\n", curs->Ctable[i].name, curs->Ctable[i].type, curs->Ctable[i].value);
            else if(curs->Ctable[i].type == CHAR)
                fprintf(stderr, "%s %d %c\n", curs->Ctable[i].name, curs->Ctable[i].type, curs->Ctable[i].value);
            else if(curs->Ctable[i].type == REAL)
                fprintf(stderr, "%s %d %f\n", curs->Ctable[i].name, curs->Ctable[i].type, curs->Ctable[i].valueFloat);
        }
        curs = curs->next;
    }
}

void displayMacro(){
    int i;

    fprintf(stderr, "\n=====================TABLE DES MACROS================\n\n");

    for (i = 0; i < macro_table.Msize; i++){
        if(macro_table.Mtable[i].type == INTEGER)
            fprintf(stderr, "%s %d %d\n", macro_table.Mtable[i].name, macro_table.Mtable[i].type, macro_table.Mtable[i].value);
        else if(macro_table.Mtable[i].type == CHAR)
            fprintf(stderr, "%s %d %c\n", macro_table.Mtable[i].name, macro_table.Mtable[i].type, macro_table.Mtable[i].value);
        else if(macro_table.Mtable[i].type == REAL)
            fprintf(stderr, "%s %d %f\n", macro_table.Mtable[i].name, macro_table.Mtable[i].type, macro_table.Mtable[i].valueFloat);
    }
}

void displayFunTable(){
    int i,j;

    fprintf(stderr, "\n=====================TABLE DES FONCTIONS================\n\n");

    for (i = 0; i < function_table.Fsize; i++){
        fprintf(stderr, "Func __%s %d args : %d\n", function_table.Ftable[i].name, function_table.Ftable[i].Nargs, function_table.Ftable[i].return_type);
        for (j = 0; j < function_table.Ftable[i].Nargs; j++)
            fprintf(stderr, "    (%d) -> %d\n", j, function_table.Ftable[i].args[j]);
        fprintf(stderr, "\n");
    }
}


int lookup(const char name[], int is_tab){
    int i;
    STStackCel * curs = symbol_table;

    while (curs != NULL){
        for (i = 0; i < curs->STsize; i++){
            if (strcmp(curs->STtable[i].name, name) == 0){
                if (is_tab != (curs->STtable[i].size > 0)){
                    fprintf(stderr, "Invalid use of variable %s near line %d\n", name, line_num);
                    exit(EXIT_FAILURE);
                }
                return curs->STtable[i].type;
            }
        }
        for (i = 0; i < curs->Csize; i++){
            if (strcmp(curs->Ctable[i].name, name) == 0){
                return curs->Ctable[i].type;
            }
        }
        for (i = 0; i < curs->Asize; i++){
            if (strcmp(curs->Atable[i].name, name) == 0){
                return curs->Atable[i].type;
            }
        }
        curs = curs->next;
    }
    for(i = 0; i < macro_table.Msize; i++){
        if(strcmp(macro_table.Mtable[i].name, name) == 0){
            return macro_table.Mtable[i].type;
        }
    }
    fprintf(stderr, "%sError : %sUndeclared variable %s near line %d\n", RED, DEFAULT, name, line_num);
    return -1;
}

int lookupFunction(const char name[64]){
    int i;
    
    for (i = 0; i < function_table.Fsize; i++){
        if (strcmp(function_table.Ftable[i].name,name) == 0)
            return function_table.Ftable[i].return_type;
    }

    fprintf(stderr, "%sError : %sUndeclared function %s near line %d\n", RED, DEFAULT, name, line_num);
    return -1;
}

int check_types(int a, int b){
    if (a != b){
        fprintf(stderr, "%sWarning : %sconflicting type line %d : ", CYAN, DEFAULT, line_num);
        switch (a){
        	case INTEGER:
        		fprintf(stderr, "integer"); break;
        	case CHAR:
        		fprintf(stderr, "character"); break;
        	case VOIDTYPE:
        		fprintf(stderr, "void"); break;
        	default:
        		fprintf(stderr, "unknown"); break;
        }
        fprintf(stderr, " and ");
        switch (b){
        	case INTEGER:
        		fprintf(stderr, "integer:\n"); break;
        	case CHAR:
        		fprintf(stderr, "character:\n"); break;
        	case VOIDTYPE:
        		fprintf(stderr, "void:\n"); break;
        	default:
        		fprintf(stderr, "unknown:\n"); break;
        }
        return 0;
    }
    return 1;
}

int cast_type(int a, int b, int flag_cast){
    //Cast b with the same type of a
    if(flag_cast == 1){
        return a;
    }
    //a and b have the same type
    else if(a == b){
        return a;
    }
    else if(a == CHAR && b == INTEGER){
        fprintf(stderr, "%sWarning : %sconflicting type line %d : char and int\n", CYAN, DEFAULT, line_num);
        return ERR_TYPE;
    }
    else if(a == INTEGER && b == LONG){
        fprintf(stderr, "%sWarning : %sconflicting type line %d : int and long\n", CYAN, DEFAULT, line_num);
        return ERR_TYPE;
    }
    else if(a == CHAR && b == LONG){
        fprintf(stderr, "%sWarning : %sconflicting type line %d : char and long\n", CYAN, DEFAULT, line_num);
        return ERR_TYPE;
    }
    else if(a == INTEGER && b == CHAR){
        return INTEGER;
    }
    else if(a == LONG && b == INTEGER){
        return LONG;
    }
    else if(a == INTEGER && b == REAL){
        fprintf(stderr, "%sWarning : %sconflicting type line %d : integer and real\n", CYAN, DEFAULT, line_num);
        return ERR_TYPE;
    }
    return ERR_TYPE;
}

int max_type(int a, int b){
    return (a > b) ? a : b;
}

int get_address(const char *name, int address[2]){
    int i;
    STStackCel * curs = symbol_table;

    while (curs != NULL){
        /*Symbol Table*/
        for (i = 0; i < curs->STsize; i++){
            if (strcmp(curs->STtable[i].name, name) == 0){
                address[0] = curs->STtable[i].address;
                /*Variable globale */
                if (curs->next == NULL)
                    address[1] = 1;
                else
                    address[1] = 0;
                return 0;
            }
        }
        /*Constant Table*/
        for (i = 0; i < curs->Csize; i++){
            if (strcmp(curs->Ctable[i].name, name) == 0){
                address[0] = curs->Ctable[i].value;
                address[1] = 2;
                return 0;
            }
        }
        /*Array */
        for (i = 0; i < curs->Asize; i++){
            if (strcmp(curs->Atable[i].name, name) == 0){
                address[0] = curs->Atable[i].address;
                address[1] = 3;
                return 0;
            }
        }
        curs = curs->next;
    }
    return -1;
}

void add_call_cell(const char name[]){
    CStack nouv = NULL;

    if (NULL == (nouv = (CStack)malloc(sizeof(Call)))){
        fprintf(stderr, "Allocation error on callstack\n");
        exit(EXIT_FAILURE);
    }
    nouv->next = cs;
    cs = nouv;
    strcpy(nouv->name, name);
    nouv->i_arg = 0;
}

int get_arg_type(const char name[], int i_arg){
    int i;

    for (i = 0; i < function_table.Fsize; i++){
        if (!strcmp(function_table.Ftable[i].name,name)){
            if (i_arg > function_table.Ftable[i].Nargs){
                fprintf(stderr, "Too many arguments to function call %s near line %d\n", name, line_num);
                exit(EXIT_FAILURE);
            }
            return function_table.Ftable[i].args[i_arg];
        }
    }
    return -1;
}

int get_globals_vars_size(){
    STStackCel * curs = symbol_table;
    if (curs == NULL)
        return 0;
    while (curs->next != NULL){
        curs = curs->next;
    }
    return curs->STsize;
}

int get_globals_const_size(){
    STStackCel *curs = symbol_table;
    if (curs == NULL)
        return 0;
    while (curs->next != NULL){
        curs = curs->next;
    }
    return curs->Csize;
}

int get_globals_array_size(){
    STStackCel *curs = symbol_table;
    if (curs == NULL)
        return 0;
    while (curs->next != NULL){
        curs = curs->next;
    }
    return curs->Asize;
}

int get_globals_size(){
    STStackCel * curs = symbol_table;
    if (curs == NULL)
        return 0;
    while (curs->next != NULL){
        curs = curs->next;
    }
    return curs->current_stack_address;
}

int get_globals_var(char vars[64][64], long vals[64]){
    STStackCel * curs = symbol_table;
    int i = 0;
    if (curs == NULL)
        return 0;
    while (curs->next != NULL){
        curs = curs->next;
    }
    for(i = 0; i < curs->STsize; i++){
        strcpy(vars[i], curs->STtable[i].name); 
        vals[i] = curs->STtable[i].value;
    }
    return 1;
}

int get_globals_const(char consts[64][64], long vals[64]){
    STStackCel * curs = symbol_table;
    int i = 0;
    if (curs == NULL)
        return 0;
    while (curs->next != NULL){
        curs = curs->next;
    }
    for(i = 0; i < curs->Csize; i++){
        strcpy(consts[i], curs->Ctable[i].name); 
        vals[i] = curs->Ctable[i].value;
    }
    return 1;
}

int get_globals_array(char array[64][64], int dimension[64], int *size_par_dim[64]){
    STStackCel * curs = symbol_table;
    int i = 0, j = 0;
    if (curs == NULL)
        return 0;
    while (curs->next != NULL){
        curs = curs->next;
    }
    for(i = 0; i < curs->Asize; i++){
        strcpy(array[i], curs->Atable[i].name); 
        dimension[i] = curs->Atable[i].dimension;
        size_par_dim[i] = curs->Atable[i].size_par_dim; 
    }
    return 1;
}

int get_dimensions(char name[MAXNAME]){
    int i;
    STStackCel *curs = symbol_table;

    if (curs == NULL)
        return 0;
    if(globale_array(name) == 1){
        while (curs->next != NULL){
                curs = curs->next;
        }
        for(i = 0; i < curs->Asize; i++){
            if(strcmp(curs->Atable[i].name, name) == 0)
                return curs->Atable[i].dimension;
        }
    }   
    else{
        while (curs->next != NULL){
            for(i = 0; i < curs->Asize; i++){
                if(strcmp(curs->Atable[i].name, name) == 0)
                    return curs->Atable[i].dimension;
            }
                curs = curs->next;
        }
    } 
    return -1;
}

void remove_st_cell() {
    int i, j, k, m;
    for (i = 0; i < symbol_table->STsize && symbol_table->next != NULL; i++){
        for (j = 0; j < symbol_table->STtable[i].size; j++){
            fprintf(stdout, "    pop rbx\n");
        }
        if (symbol_table->STtable[i].size == 0){
            fprintf(stdout, "    pop rbx\n");
        }
    }
    for(m = 0; m < symbol_table->Asize && symbol_table->next != NULL; m++){

        for (j = 0; j < symbol_table->Atable[m].dimension; j++){
            for(k = 0; k < symbol_table->Atable[m].size_par_dim[j]; k++){
                fprintf(stdout, "    pop rbx\n");
            }
        }
    }
    if (symbol_table->next != NULL)
        fprintf(stdout, "    pop rbp\n    ret\n\n");

    STStack tmp = symbol_table->next;
    free(symbol_table->STtable);
    free(symbol_table->Ctable);
    free(symbol_table);
    symbol_table = tmp;

}

void remove_call_cell(){
    CStack tmp = cs;
    cs = cs->next;
    free(tmp);
}

void addArg(char name[], int type){
    int i;
    
    for (i = 0; i < function_table.Fsize; i++){
        if (!strcmp(function_table.Ftable[i].name, name))
            break;
    }

    if (i == function_table.Fsize){
        fprintf(stderr, "Impossible error on function_table args\n");
        exit(EXIT_FAILURE);
    }
    

    if (function_table.Ftable[i].Nargs == function_table.Ftable[i].MAXargs){
        function_table.Ftable[i].MAXargs *= 2;
        if (NULL == (function_table.Ftable[i].args = realloc(function_table.Ftable[i].args, function_table.Ftable[i].MAXargs * sizeof(int)))){
            fprintf(stderr, "Reallocation error on ftable args\n");
            exit(EXIT_FAILURE);
        }
    }
    function_table.Ftable[i].args[function_table.Ftable[i].Nargs] = type;
    function_table.Ftable[i].Nargs++;
}

int globale_variable(char name[64]){
    STStackCel * curs = symbol_table;
    int i = 0;
    if (curs == NULL)
        return 0;
    /*Table actuelle*/
    for(i = 0; i < curs->STsize; i++){
        if(strcmp(curs->STtable[i].name, name) == 0)
            return 0;
    }
    while (curs->next != NULL){
        curs = curs->next;
    }
    /*Table des variables globales*/
    for(i = 0; i < curs->STsize; i++){
        if(strcmp(curs->STtable[i].name, name) == 0)
            return 1;
    }
    return 0; 
}

int globale_const(char name[64]){
    STStackCel * curs = symbol_table;
    int i = 0;
    if (curs == NULL)
        return 0;
    /*Table actuelle*/
    for(i = 0; i < curs->Csize; i++){
        if(strcmp(curs->Ctable[i].name, name) == 0)
            return 0;
    }
    while (curs->next != NULL){
        curs = curs->next;
    }
    /*Tables des globales */
    for(i = 0; i < curs->Csize; i++){
        if(strcmp(curs->Ctable[i].name, name) == 0)
            return 1;
    }
    return 0; 
}

int globale_array(char name[64]){
    STStackCel * curs = symbol_table;
    int i = 0;
    if (curs == NULL)
        return 0;
    /*Table actuelle*/
    for(i = 0; i < curs->Asize; i++){
        if(strcmp(curs->Atable[i].name, name) == 0)
            return 0;
    }
    while (curs->next != NULL){
        curs = curs->next;
    }
    /*Tables des globales */
    for(i = 0; i < curs->Asize; i++){
        if(strcmp(curs->Atable[i].name, name) == 0)
            return 1;
    }
    return 0; 
}

void freeStack(){
    free(symbol_table);
}

void get_func_call_name(char name[]){
    if (cs != NULL)
        strcpy(name, cs->name);
}

int *get_func_i_arg(){
    if (cs != NULL)
        return &(cs->i_arg);
    return NULL;
}

void check_nargs(const char name[], int nb){
    int i;

    for (i = 0; i < function_table.Fsize; i++){
        if (!strcmp(function_table.Ftable[i].name,name)){
            if (nb != function_table.Ftable[i].Nargs){
                fprintf(stderr, "%s expected %d arguments but only %d arguments given near line %d\n", name, function_table.Ftable[i].Nargs, nb, line_num);
                exit(EXIT_FAILURE);
            }
        }
    }
}