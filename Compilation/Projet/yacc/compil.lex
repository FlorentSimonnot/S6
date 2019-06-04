%{
/* PROJET L3 ANALYSE SYNTAXIQUE */
/* NENSY SAM & FLORENT SIMONNOT*/ 
/* GROUPE 3*/
#include <stdlib.h>
#include <stdio.h>
#include "../header/decl.h"
#include "../bin/compil.tab.h"

int line_num = 1; 
extern int type_var;
%}

%option nounput
%option noinput
%option yylineno

%x COMMENT

lettre [a-zA-Z]
majuscule [A-Z]
chiffre [0-9]
identificateur {lettre}[a-zA-Z0-9_]*
ponctuation [.,;:!?/]
nombre {chiffre}+ 
reel {chiffre}\.{chiffre}+
en_tete <{lettre}+\.[hc]>
%%

\/\* 			BEGIN(COMMENT);
<COMMENT>"*"+"/"	BEGIN(INITIAL); 
<COMMENT>.  	; 
<COMMENT>\n 	{line_num++;}; 

#include {return INCLUDE;}

#define {return DEFINE;}

{majuscule}+ {strcpy(yylval.name_defineval, yytext); return NAME_DEFINE;}

{en_tete} {return ENTETE;}

cast 	{ return CAST;}

int 	{	yylval.typeval = malloc(sizeof(char) * strlen(yytext)) + 1; 
			strcpy(yylval.typeval, yytext);
			type_var = INTEGER;
			return TYPE; }	

char	{ 	yylval.typeval = malloc(sizeof(char) * strlen(yytext)) + 1; 
			strcpy(yylval.typeval, yytext);
			type_var = CHAR;
			return TYPE; }

float { 	yylval.typeval = malloc(sizeof(char) * strlen(yytext)) + 1; 
			strcpy(yylval.typeval, yytext);
			type_var = FLOAT;
			return TYPE;}	

double {	yylval.typeval = malloc(sizeof(char) * strlen(yytext)) + 1; 
			strcpy(yylval.typeval, yytext);
			return TYPE;}

long 	{	yylval.typeval = malloc(sizeof(char) * strlen(yytext)) + 1; 
			strcpy(yylval.typeval, yytext);
			type_var = LONG;
			return TYPE;}

if		{	yylval.ifval = malloc(sizeof(char) * strlen(yytext)) + 1; 
			strcpy(yylval.ifval, yytext);
			return IF;
		}

else	{
			yylval.elseval = malloc(sizeof(char) * strlen(yytext)) + 1; 
			strcpy(yylval.elseval, yytext);
			return ELSE;
		}

do 		{
			yylval.doval = malloc(sizeof(char) * strlen(yytext)) + 1; 
			strcpy(yylval.doval, yytext);
			return DO;
		}

while 	{	yylval.whileval = malloc(sizeof(char) * strlen(yytext))+1;
			strcpy(yylval.whileval, yytext);
			return WHILE;
		} 

for 	{	yylval.forval = malloc(sizeof(char) * strlen(yytext))+1;
			strcpy(yylval.forval, yytext);
			return FOR; 
		}

print 	{	yylval.printval = malloc(sizeof(char) * strlen(yytext))+1;
			strcpy(yylval.printval, yytext);
			return PRINT;
			}   

return 	{	yylval.returnval = malloc(sizeof(char) * strlen(yytext))+1;
			strcpy(yylval.returnval, yytext);
			return RETURN;
			} 

const 	{	yylval.constval = malloc(sizeof(char) * strlen(yytext))+1;
			strcpy(yylval.constval, yytext); 
			return CONST; 		
		}

void	{	yylval.voidval = malloc(sizeof(char) * strlen(yytext))+1;
			strcpy(yylval.voidval, yytext); 
			return VOID;
		}

reade 	{	yylval.readeval = malloc(sizeof(char) * strlen(yytext))+1;
			strcpy(yylval.readeval, yytext);
			return READE;
		}

readc 	{	yylval.readcval = malloc(sizeof(char) * strlen(yytext)) + 1; 
			strcpy(yylval.readcval, yytext);
			return READC;
		}

{reel}	{yylval.reelval = atof(yytext); return FLOAT;}


{nombre}	{	yylval.intval = atoi(yytext); return NUM;}

{identificateur}	{
						if(yyleng <= MAXNAME){
							strcpy(yylval.identval, yytext); 
							return IDENT;
				  		}
					}

\'{lettre}\' 	{	yylval.charval = yytext[1]; 
					return CARACTERE;}

\'{ponctuation}\' 	{	yylval.charval = yytext[1]; 
					return CARACTERE;}

"=" 	{return *yytext;}

"++"	{	strcpy(yylval.incrementval, yytext); 
			return INCREMENT;
		}

"--"	{	strcpy(yylval.incrementval, yytext);
					return INCREMENT;
		}

[+-]		{	yylval.addsubval = yytext[0];
				return ADDSUB;}

[%/*]		{	yylval.divstarval = yytext[0]; 
				return DIVSTAR;}

"==" {strcpy(yylval.eqval, yytext); return EQ;}

"!=" {strcpy(yylval.eqval, yytext); return EQ;}

"&&"	{	strcpy(yylval.andval, yytext); 
			return AND;
		}
 
"||"	{	strcpy(yylval.orval, yytext); 
			return OR;
		}
 
"<=" 	{	yylval.orderval = malloc(sizeof(char) * strlen(yytext)) + 1; 
			strcpy(yylval.orderval, yytext); 
			return ORDER;
		}

">=" 	{	yylval.orderval = malloc(sizeof(char) * strlen(yytext)) + 1; 
			strcpy(yylval.orderval, yytext); 
			return ORDER;
		}

["<"|">"] 	{	yylval.orderval = malloc(sizeof(char) * strlen(yytext)) + 1; 
				strcpy(yylval.orderval, yytext); 
				return ORDER;
			}

[\{\}\(\)\[\]\!] {return *yytext; }

"\;" {return *yytext; }

[ \t] {;}

, {return ',';}

"\n" {line_num++;}

.	{
	printf("ERROR lexical line %d near %s\n",line_num, yytext);
	}

