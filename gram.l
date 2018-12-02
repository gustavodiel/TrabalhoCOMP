%{
#include "gram.tab.h"
#include "Globals.h"
%}

delim[\t ]
ws {delim}+
digito [0-9]
caractere [A-Za-z]
num {digito}+
id {caractere}+
literal \".*\"
/*"*/

%%
{ws}	    {}
"if"	    { return TOKEN_IF;}
"else"	  	{ return TOKEN_ELSE;}
"while"   	{ return TOKEN_WHILE;}
"int"     	{ return TOKEN_INT;}
"String"  	{ return TOKEN_STRING;}
"void"    	{ return TOKEN_VOID;}
"read"    	{ return TOKEN_READ;}
"print"   	{ return TOKEN_PRINT;}
"return"  	{ return TOKEN_RETURN;}
"<="      	{ return TOKEN_MENOR_IGUAL;}
">="      	{ return TOKEN_MAIOR_IGUAL;}
"!="      	{ return TOKEN_DIFERENTE;}
"<"       	{ return TOKEN_MENOR;}
">"       	{ return TOKEN_MAIOR;}
"=="      	{ return TOKEN_IGUAL;}

"+="	    {return TOKEN_MAIS_IGUAL;}

"&&"      	{ return TOKEN_E;}
"||"      	{ return TOKEN_OU;}
"!"       	{ return TOKEN_NEGACAO;}
"="       	{ return TOKEN_ATRIBUICAO;}
"++"		{ return TOKEN_MAIS_MAIS;}
"--"		{ return TOKEN_MENOS_MENOS;}
"+"			{ return TOKEN_MAIS;}
"-"       	{ return TOKEN_MENOS;}
"*"       	{ return TOKEN_MULT;}
"/"       	{ return TOKEN_DIV;}
"("       	{ return TOKEN_ABRE_PAR;}
")"       	{ return TOKEN_FECHA_PAR;}
"{"       	{ return TOKEN_ABRE_CHAVES;}
"}"       	{ return TOKEN_FECHA_CHAVES;}
","       	{ return TOKEN_VIRGULA;}
";"       	{ return TOKEN_PONTO_VIRGULA;}
{literal} 	{ yylval = CreateLiteral( yytext); return TOKEN_TEXTO;}
{num}     	{ yylval = CreateNumeral( atoi(yytext)); return TOKEN_NUM_REAL;}
{id}      	{ yylval = CreateID( yytext); return TOKEN_ID;}
"\n"	  	{ lineNumber++;}
