%%%%%%%%%%%   analisador lexico   %%%%%%%%%%


%{
#include "expr.tab.h"
%}

delim	[ \t]
ws	{delim}+
digito	[0-9]
num	{digito}+(\.{digito}*(E[+-]?{digito}+)?)?
int {digito}+
caractere [A-Za-z]
id {caractere}+[{digito}{caractere}]*
literal \".*\"
/*"*/

%%
{ws}	        {}

"+"	          { return T_ADD; }
"-"	          { return T_SUB; }
"*"	          { return T_MULT; }
"/"	          { return T_DIV; }

"("           { return T_INI_PAR; }
")"           { return T_FIM_PAR; }
"{"           { return T_INI_COL; }
"}"           { return T_FIM_COL; }

"\n"	          { return T_FIM;}

{int}         { yylval=atof(yytext); return T_INT; }
{num}         { yylval=atof(yytext); return T_FLOAT; }
{literal}     { yylval=atof(yytext); return T_LITERAL; }

"string"      { return T_STRING_N; }
"int"         { return T_INT_N; }
"float"       { return T_FLOAT_N; }
"void"        { return T_VOID; }

"return"      { return T_RETURN; }

";"           { return T_PNT_VIRG; }
","           { return T_VIRG; }

"if"          { return T_IF; }
"else"        { return T_ELSE; }
"while"       { return T_WHILE; }

"printf"      { return T_PRINT; }
"read"        { return T_READ; }

">"           { return T_MAIOR_Q; }
"<"           { return T_MENOR_Q; }
">="          { return T_MAIOR_IG; }
"<="          { return T_MENOR_IG; }
"=="          { return T_IGUAL; }
"!="          { return T_DIFF; }
"&&"          { return T_AND; }
"||"          { return T_OR; }
"!"           { return T_NOT; }

"="           { return T_ATTR; }


{id}          { return T_ID; }
