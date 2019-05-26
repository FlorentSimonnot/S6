%{
#include <stdlib.h>
#include <stdio.h>
#include "../bin/ex4.tab.h"

int line_num = 1; 
%}

%option nounput
%option noinput
%option yylineno

lettre [a-zA-Z]
chiffre [0-9]
nombre {chiffre}+ 
ident {lettre}[a-zA-Z0-9_]*
%%

{nombre} {yylval.num = atoi(yytext); return NUM;}

const	{return CONST;}

{ident}	{strcpy(yylval.ident, yytext); return IDENT;}

"+"|"-"   {yylval.operatoradd = yytext[0]; return ADDSUB;}

"*"|"/"    {yylval.operatordiv = yytext[0]; return DIVSTAR;}

"="	{return yytext[0];}

";"	{return yytext[0];}

[ \t] {;}

"\n" {line_num++;}

.	{
		printf("ERROR lexical line %d near %s\n",line_num, yytext);
	}

