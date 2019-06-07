/**
 * \file      decl.h
 * \author    SAM Nensy, SIMONNOT Florent
 * \version   1.0
 * \date      23rd March 2019
 * \brief     Define the stack, Symbol Table of Variables, Constantes.
 *
 * \details    
 */
#ifndef __DECL_H__
#define __DECL_H__

#define DEFAULT  "\033[0m"
#define HIGHLIGHT "\033[1m"
#define UNDERLINE "\033[4m"
#define BLINK     "\033[5m"
#define BLACK     "\033[30m"
#define RED       "\033[31m"
#define GREEN     "\033[32m"
#define YELLOW    "\033[33m"
#define BLUE      "\033[34m"
#define PURPLE    "\033[35m"
#define CYAN      "\033[36m"
#define WHITE     "\033[37m"

#define MAXNAME 64
#define MAXNBSYMBOL 32

/*MACROS TYPES*/
#define ERR_TYPE -1
#define CHAR 0
#define INTEGER 1
#define REAL 2
#define VOIDTYPE 3
#define LONG 4

/**
 * \struct STentry
 * \brief define a struct for a variable.
 *
 * STentry is a name (ident) with a type, address and size.
 * If the variable isn't an array, the size is null (0).
 */
typedef struct {
    char name[MAXNAME]; //Nom 
    int type; 			//Type
    int address; 		//Adress
    int size; 			//0 si pas un tableau
    long value;         //To verify the symbol Table
    float valueFloat;   //To verify the symbol Table
}STentry;


/**
 * \struct CONSTentry
 * \brief define a struct for a constante.
 *
 * CONSTentry is a name, a type and a value.
 */
typedef struct {
    char name[MAXNAME]; //Nom
    int type;      //Type
    int value;     //Valeur
    float valueFloat;
}CONSTentry;

/**
 * \struct MACROentry
 * \brief define a struct for a macro constante.
 *
 * MACROentry is a name, a type and a value.
 */
typedef struct {
    char name[MAXNAME]; //Nom
    int type;      //Type
    int value;     //Valeur
    float valueFloat;
}MACROentry;

typedef struct{
   MACROentry *Mtable; /* table des macro constantes */
   int Msize; 
   int Mmax; 
}Mtable;

/* Table des symboles - PILE */
typedef struct cel {
    STentry *STtable;          /* table des variables */
    CONSTentry *Ctable;        /* table des constantes */
    int STmax;                 /* taille max de la table des variables */
    int STsize;                /* taille courante de la table des variables */
    int Cmax;                  /* taille max de la table des constantes */
    int Csize;                 /* taille courante de la table des constantes */
    int current_stack_address; /* adresse de la variable dans la pile */
    struct cel *next;          /* prochaine table dans la pile */
} STStackCel, *STStack;

typedef struct fun{
    char name[MAXNAME]; /*Nom de la fonction*/
    int *args; /*Tableau des arguments*/
    int Nargs; /*Nombre d'arguments*/
    int MAXargs; /*Nombre maximum d'arguments (Taille max du tableau args)*/
    int return_type; /*Type de retour*/
}FUNentry;

typedef struct ftable{
    FUNentry *Ftable;
    int Fsize; 
    int Fmax;
}Ftable;

typedef struct ccel {
    char name[64];     /* Nom de la fonction appelante */
    int i_arg;         /* Indice de l'argument courant */ 
    struct ccel *next; /* Prochain appel */
}Call, *CStack;

extern int line_num;

/**
 * \fn void initProg()
 * \brief Initialize the programm.
 */
void initProg();

/**
 * \fn void createStack()
 * \brief Create the stack.
 */
void createStack();

/**
 * \fn int getType(const char *type)
 * \brief return the integer associated to the type.
 *
 * \param type - a string which is a type (int, char, long, float...)
 * \return the MacroType.
 */
int getType(const char *type);

/**
 * \fn void addVar(const char name[], int type, int is_parameter)
 * \brief add the variable in the symbol Table. 
 *
 * \param name - the ident of variable
 * \param type - the type of variable
 * \param is_tab - if the variable is a parameter > 0. Else 0.
 */
int addVar(const char name[], int type, int is_parameter, int value, float valueFloat);

/**
 * \fn void addConst(const char name[], int type, int value)
 * \brief add the variable in the symbol Table. 
 *
 * \param name - the ident of constante
 * \param type - the type of constante
 * \param value - the value of the constante
 */
int addConst(const char name[], int type, int value, float valueFloat);

int addMacro(const char name[], int type, int value, float valueFloat);

void addTab(const char name[], int type, int size);

int addFun(const char name[], int type);

void addArg(char name[], int type); 

int isConstante(const char name[]);

int isTab(const char name[]);

void displayTable();

void displayConst();

void displayMacro();

void displayFunTable();

/**
 * \fn int lookup(const char name[], int is_tab)
 * \brief verify if a variable or a constante with the same name exists. 
 *
 * \param name - the name of the ident we want check
 * \param is_tab - 0 if this is a variable, else the size of the array.
 * \return the type of the variable or constante in the stack with this name. Else -1.
 */
int lookup(const char name[], int is_tab);

/**
 * \fn int lookupFunction(const char name[], int is_tab)
 * \brief verify if a function with the same name exists. 
 *
 * \param name - the name of the function we want check
 *
 * \return the type of the function with this name in the stack. Else -1.
 */
int lookupFunction(const char name[]);

/**
 * \fn int check_types(int a, int b)
 * \brief verify if a and b is the same type.
 *
 * \param a - the first type
 * \param b - the second type
 * \return 1 a and b is the same type. 0 else.
 */
int check_types(int a, int b);

int max_type(int a, int b);

int cast_type(int a, int b, int flag_cast);

int get_address(const char *name, int address[2]);

void add_call_cell(const char name[]);

int get_arg_type(const char name[], int i_arg);

int get_globals_size(); 

void remove_st_cell();

void remove_call_cell();

void get_func_call_name(char name[]);

int * get_func_i_arg();

void check_nargs(const char name[], int nb);

int get_globals_vars_size();
int get_globals_const_size();
int get_globals_var(char vars[64][64], long vals[64]);
int get_globals_const(char consts[64][64], long vals[64]);

int globale_variable(char name[64]);
int globale_const(char name[64]);

/**
 * \fn void freeStack()
 * \brief free the memory used for the stack
 *
 */
void freeStack();

#endif