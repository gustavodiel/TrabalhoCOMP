%%%%%%%%%%%%  analisador sintatico e semantico %%%%%%%%%%%%

%{
#include <stdio.h>
#include <stdlib.h>
#define YYSTYPE char*
%}

%token T_ID T_INT_N T_STRING_N T_FLOAT_N T_INI_PAR T_FIM_PAR T_INI_COL T_FIM_COL T_INT T_FLOAT T_LITERAL T_RETURN T_VOID T_PNT_VIRG T_VIRG T_WHILE T_IF T_ELSE T_PRINT T_READ T_ADD T_SUB T_MULT T_DIV T_MAIOR_Q T_MENOR_Q T_MAIOR_IG T_MENOR_IG T_IGUAL T_DIFF T_ATTR T_AND T_OR T_NOT T_FIM

%%
Programa:
    ListaFuncoes BlocoPrincipal
    | BlocoPrincipal
    ;

ListaFuncoes:
    ListaFuncoes Funcao
    | Funcao
    ;

Funcao:
    TipoRetorno T_ID T_INI_PAR DeclParametros T_FIM_PAR BlocoPrincipal
    | TipoRetorno T_ID T_INI_PAR T_FIM_PAR BlocoPrincipal
    ;

TipoRetorno:
    Tipo
    | T_VOID
    ;

DeclParametros:
    DeclParametros T_VIRG Parametro
    | Parametro
    ;

Parametro:
    Tipo T_ID
    ;

BlocoPrincipal:
    T_INI_COL Declaracoes ListaCmd T_FIM_COL
    | T_INI_COL ListaCmd T_FIM_COL
    ;

Declaracoes:
    Declaracoes Declaracao
    | Declaracao
    ;

Declaracao:
    Tipo ListaID T_PNT_VIRG
    ;

Tipo:
    T_INT_N
    | T_STRING_N
    | T_FLOAT_N
    ;

ListaID:
    ListaID T_VIRG T_ID
    | T_ID
    ;

Bloco:
    T_INI_COL ListaCmd T_FIM_COL
    ;

ListaCmd:
    ListaCmd Comando
    | Comando
    ;

Comando:
    ComandoIF
    | ComandoWHILE
    | ComandoATTRIB
    | ComandoWRITE
    | ComandoREAD
    | CallProc
    | Return
    ;

Return:
    T_RETURN ExpressaoAritmetica T_PNT_VIRG
    | T_RETURN T_LITERAL
    ;

ComandoIF:
    T_IF T_INI_PAR ExpressaoLogica T_FIM_PAR Bloco
    | T_IF T_INI_PAR ExpressaoLogica T_FIM_PAR Bloco T_ELSE Bloco
    ;

ComandoWHILE:
    T_WHILE T_INI_PAR ExpressaoLogica T_FIM_PAR Bloco
    ;

ComandoATTRIB:
    TVAR TEQ Expr TFIM {assignvar($1.txt, $3.num);}
    ;

ComandoWRITE:
    T_PRINT T_INI_PAR ExpressaoAritmetica T_FIM_PAR T_PNT_VIRG
    | T_PRINT T_INI_PAR T_LITERAL T_FIM_PAR T_PNT_VIRG
    ;

ComandoREAD:
    T_READ T_INI_PAR T_LITERAL T_FIM_PAR T_PNT_VIRG
    ;

CallProc:
    ChamadaFuncao T_PNT_VIRG
    ;

ChamadaFuncao:
    T_ID T_INI_PAR ListaParametros T_FIM_PAR
    | T_ID T_INI_PAR T_FIM_PAR
    ;

ListaParametros:
    ListaParametros T_VIRG ExpressaoAritmetica
    | ListaParametros T_VIRG T_LITERAL
    | ExpressaoAritmetica
    | T_LITERAL

ExpressaoLogica:
    "true"
    ;

ExpressaoAritmetica:
    T_INT T_ADD T_INT
    ;

%%
#include "lex.yy.c"

int yyerror (char *str)
{
	printf("%s - antes %s\n", str, yytext);

}

int yywrap()
{
	return 1;
}
