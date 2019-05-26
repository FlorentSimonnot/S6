%{
/* PROJET L3 ANALYSE SYNTAXIQUE */
/* NENSY SAM & FLORENT SIMONNOT*/ 
/* GROUPE 3*/
#include <stdlib.h>
#include <stdio.h>
#include "../bin/ex2.tab.h"

int line_num = 1; 
%}

%option nounput
%option noinput
%option yylineno

lettre [a-zA-Z]
majuscule [A-Z]
chiffre [0-9]
text {lettre}[-\.\'éèàêâa-zA-Z0-9 ]*
nombre {chiffre}+ 
%%

{nombre} { yylval.num = atoi(yytext); return NUM;}

{text}	{ 
			if( (yylval.text = malloc(sizeof(char) * strlen(yytext) + 1)) == NULL){
				exit(EXIT_FAILURE);
			}
			strcpy(yylval.text, yytext);
			return TEXT;}

"-"		{return yytext[0];}

[ \t] {;}

"\n" {line_num++;}

"EOF"	{
		return 0; 
	}

.	{
	printf("ERROR lexical line %d near %s\n",line_num, yytext);
	}

