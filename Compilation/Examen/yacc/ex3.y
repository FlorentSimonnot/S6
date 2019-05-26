%{
#include <stdio.h>
#include <string.h>

#define RIGHT 0
#define DOWN 1
#define LEFT 2
#define UP 3

int yylex(void);
void yyerror(char* s);
void print_position(int tab[4]); 
void move(int num, int tab[4]); 
void changer_direction(int nouvelle, int tab[4]);
void copier_tab(int dest[4], int src[4]);
extern int line_num;
%}

%union{
    char *instruction; 
    int num; 
    int position[4];
}

%token <num> NUM
%token <instruction> TOURNER_A_DROITE TOURNER_A_GAUCHE AVANCER COULEUR

%type <position> S suiteD D

%%

S   :   suiteD {$$[0] = $$[1] = $$[2] = $$[3] = RIGHT;}
    ;

suiteD  :   suiteD D {copier_tab($$, $2);}
        |   D {copier_tab($$, $1);}
        ; 

D   :   
        AVANCER NUM {copier_tab($$, $<position>0); move($2, $$);}
    |   COULEUR NUM {copier_tab($$, $<position>0); $$[3] = $2;}
    |   TOURNER_A_GAUCHE {copier_tab($$, $<position>0); changer_direction(LEFT, $$); }
    |   TOURNER_A_DROITE {copier_tab($$, $<position>0); changer_direction(RIGHT, $$); }
    ;

%%
void yyerror(char *s){
    printf("Erreur %s near line %d \n", s, line_num);
}

void print_position(int tab[4]){
    printf("x = %d | y = %d | direction = %d | couleur = %d \n", tab[0], tab[1], tab[2], tab[3]); 
}

void move(int num, int tab[4]){
    int old_coords[2]; 
    old_coords[0] = tab[0]; 
    old_coords[1] = tab[1];
    switch(tab[2]){
        case 3 : tab[1] += num; break; 
        case 0 : tab[0] += num; break; 
        case 1 : tab[1] -= num; break; 
        case 2 : tab[0] -= num; break; 
        default :  break; 
    }
    printf("TRACE_TRAIT  %d %d %d %d %d\n", old_coords[0], old_coords[1], tab[0], tab[1], tab[3]);
}

void changer_direction(int nouvelle, int tab[4]){
    switch(tab[2]){
        case UP :   if(nouvelle == LEFT){tab[2] = LEFT;} 
                    else if(nouvelle == RIGHT){tab[2] = RIGHT;}
                    break; 
        case RIGHT : if(nouvelle == LEFT){tab[2] = UP;} 
                    else if(nouvelle == RIGHT){tab[2] = DOWN;}
                    break; 
        case DOWN : if(nouvelle == LEFT){tab[2] = RIGHT;} 
                    else if(nouvelle == RIGHT){tab[2] = LEFT;}
                    break; 
        case LEFT : if(nouvelle == LEFT){tab[2] = DOWN;} 
                    else if(nouvelle == RIGHT){tab[2] = UP;}
                    break; 
        default : break; 
    }
}

void copier_tab(int dest[4], int src[4]){
    int i; 

    for(i = 0; i < 4; i++)
        dest[i] = src[i];
}
 
int main(){
    return yyparse();
}
