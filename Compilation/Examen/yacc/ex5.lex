%{
#include <stdlib.h>
#include <stdio.h>
#include "../bin/ex5.tab.h"

int line_num = 1; 
%}

%option nounput
%option noinput
%option yylineno

lettre [a-zA-Z]
chiffre [0-9]
nombre {chiffre}+ 
ident {lettre}
%%

[ \t] {;}

{ident}	{yylval.ident = yytext[0]; return ID;}

.	{return yytext[0];}

"\n" {return 0;}
