%{
/* PROJET L3 ANALYSE SYNTAXIQUE */
/* NENSY SAM & FLORENT SIMONNOT*/ 
/* GROUPE 3*/
#include <stdlib.h>
#include <stdio.h>
#include "../bin/ex3.tab.h"

int line_num = 1; 
%}

%option nounput
%option noinput
%option yylineno

chiffre [0-9]
nombre {chiffre}+ 
%%

{nombre} {yylval.num = atoi(yytext); return NUM;}

"AVANCER"	{
				if((yylval.instruction = malloc(sizeof(char) * strlen(yytext))) == NULL)
					exit(EXIT_FAILURE); 
				strcpy(yylval.instruction, yytext);
				return AVANCER;
			}

"TOURNER_A_GAUCHE" {	if((yylval.instruction = malloc(sizeof(char) * strlen(yytext))) == NULL)
					exit(EXIT_FAILURE); 
				strcpy(yylval.instruction, yytext);
				return TOURNER_A_GAUCHE;
			}

"TOURNER_A_DROITE" {	if((yylval.instruction = malloc(sizeof(char) * strlen(yytext))) == NULL)
					exit(EXIT_FAILURE); 
				strcpy(yylval.instruction, yytext);
				return TOURNER_A_DROITE;
			}

"COULEUR"	{
				if((yylval.instruction = malloc(sizeof(char) * strlen(yytext))) == NULL)
					exit(EXIT_FAILURE); 
				strcpy(yylval.instruction, yytext);
				return COULEUR;
			}

"DECOLLER"	{
				if((yylval.instruction = malloc(sizeof(char) * strlen(yytext))) == NULL)
					exit(EXIT_FAILURE); 
				strcpy(yylval.instruction, yytext);
				return DECOLLER;
			}

"ATTERRIR"	{
				if((yylval.instruction = malloc(sizeof(char) * strlen(yytext))) == NULL)
					exit(EXIT_FAILURE); 
				strcpy(yylval.instruction, yytext);
				return ATTERRIR;
			}

[ \t] {;}

"\n" {line_num++;}

.	{
	printf("ERROR lexical line %d near %s\n",line_num, yytext);
	}

