%{
#include <stdio.h>
#include <string.h>

#define RIGHT 0
#define DOWN 1
#define LEFT 2
#define UP 3

int yylex(void);
void yyerror(char* s);
void print_position(int tab[5]); 
void move(int num, int tab[5]); 
void changer_direction(int nouvelle, int tab[5]);
void copier_tab(int dest[5], int src[5]);
extern int line_num;
%}

%union{
    char *instruction; 
    int num; 
    int position[5];
}

%token <num> NUM
%token <instruction> TOURNER_A_DROITE TOURNER_A_GAUCHE AVANCER COULEUR DECOLLER ATTERRIR 

%type <position> S suiteD D

%%

S   :   suiteD {$$[0] = $$[1] = $$[2] = $$[3] = $$[4] = RIGHT;}

suiteD  :   suiteD D {copier_tab($$, $2);}
        |   D {copier_tab($$, $1);}
        ; 

D   :   
        AVANCER NUM {copier_tab($$, $<position>0); move($2, $$);}
    |   COULEUR NUM {copier_tab($$, $<position>0); $$[3] = $2;}
    |   TOURNER_A_GAUCHE {copier_tab($$, $<position>0); changer_direction(LEFT, $$); }
    |   TOURNER_A_DROITE {copier_tab($$, $<position>0); changer_direction(RIGHT, $$); }
    |   ATTERRIR {copier_tab($$, $<position>0); $$[4] = 0;}
    |   DECOLLER {copier_tab($$, $<position>0); $$[4] = 1;}
    ;

%%
void yyerror(char *s){
    printf("Erreur %s near line %d \n", s, line_num);
}

void print_position(int tab[5]){
    printf("x = %d | y = %d | direction = %d | couleur = %d \n", tab[0], tab[1], tab[2], tab[3]); 
}

void move(int num, int tab[5]){
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
    if(tab[4] != 1)
        printf("TRACE_TRAIT  %d %d %d %d %d\n", old_coords[0], old_coords[1], tab[0], tab[1], tab[3]);
}

void changer_direction(int nouvelle, int tab[5]){
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

void copier_tab(int dest[5], int src[5]){
    int i; 

    for(i = 0; i < 5; i++)
        dest[i] = src[i];
}
 
int main(){
    return yyparse();
}
