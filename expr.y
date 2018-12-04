%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Main.h"
#define YYSTYPE struct Atributo
%}

%token TSTRING TVOID TINT TRETURN TPRINT TREAD TIF TWHILE TELSE TMEIGUAL TMAIGUAL TIGUAL TDIFER TATRIB TMAIOR TMENOR TACHAVE TFCHAVE TADD TSUB TMUL TDIV TAPAR TFPAR TFIM TNUM TVIRG TPVIRG TID TLITERAL TNOT TAND TOR TERROR EOP TINC TDEC TINC_N TDEC_N

%%
Inicio:
Programa {
        GenerateBytecode();
    }
    ;

Programa:
    ListaFuncoes CorrecaoID BlocoPrincipal
    | CorrecaoID BlocoPrincipal
    ;

CorrecaoID: {
        CorrectMainIDs();
    }
    ;

ListaFuncoes:
    ListaFuncoes FuncaoGeral {
        BeginFunction();
    }
    | FuncaoGeral {
        BeginFunction();
    }
    ;

FuncaoGeral:
    Funcao BlocoPrincipal {
        if($2.semRetorno == 1 && $1.tipo != TIPO_VOID){
            printf("Funcao %s sem retorno!\n", $1.id);
            exit(-2);
        }
        if($1.tipo != $2.tipo){
            printf("Retorno da funcao %s incorreto!\n", $1.id);
            exit(-2);
        }
        CreateFunctionBody();
    }
    ;

Funcao:
    TipoRetorno TID TAPAR DeclaracaoParametros TFPAR {
        strcpy($$.id, $2.id);
        $$.tipo = $1.tipo;
        CreateFunctionWithParameter(&($4.listaParametros), $1.tipo, $2.id);
    }
    | TipoRetorno TID TAPAR TFPAR {
        strcpy($$.id, $2.id);
        $$.tipo = $1.tipo;
        CreateFunctionWithoutParameter($1.tipo, $2.id);
    }
    ;

TipoRetorno:
    Tipo {
        $$.tipo = $1.tipo;
    }
    | TVOID {
        $$.tipo = TIPO_VOID;
    }
    ;

DeclaracaoParametros:
    DeclaracaoParametros TVIRG Tipo TID {
        CreateParameter(&($$.listaParametros), $3.tipo, $4.id);
    }
    | Tipo TID {
        AllocParameterList(&($$.listaParametros));
        CreateParameter(&($$.listaParametros), $1.tipo, $2.id);
    }
    ;

BlocoPrincipal:
    TACHAVE Declaracoes ListaComandos Retorno TFCHAVE {
        $$.semRetorno = 0;
        $$.tipo = $4.tipo;
    }
    | TACHAVE ListaComandos Retorno TFCHAVE {
        $$.semRetorno = 0;
        $$.tipo = $4.tipo;
    }
    | TACHAVE Declaracoes ListaComandos TFCHAVE {
        $$.semRetorno = 1;
        $$.tipo = TIPO_VOID;
    }
    | TACHAVE ListaComandos TFCHAVE {
        $$.semRetorno = 1;
        $$.tipo = TIPO_VOID;
    }
    ;

Declaracoes:
    Declaracoes Declaracao
    | Declaracao
    ;

Declaracao:
    Tipo ListaId TPVIRG {
        CreateSymbol( (&$2.listaIDs), $1.tipo );
    }
    ;

Tipo:
    TINT {
        $$.tipo = TIPO_INT;
    }
    | TSTRING {
        $$.tipo = TIPO_STRING;
    }
    ;

ListaId:
    ListaId TVIRG TID {
        CreateID( &($$.listaIDs), $3.id);
    }
    | TID {
        AllocIDList(&($$.listaIDs));
        CreateID( &($$.listaIDs), $1.id);
    }
    ;

Bloco:
    TACHAVE ListaComandos TFCHAVE
    ;

ListaComandos:
    ListaComandos Comando
    | Comando
    ;

Comando:
    ComandoIF
    | ComandoWHILE
    | ComandoAttrib
    | ComandoPRINT
    | ComandoREAD
    | ChamadaFuncao
    | ComandoADDUnitario
    | ComandoSUBUnitario
    | ComandoAdicao
    | ComandoSubtracao
    ;

ComandoADDUnitario:
    TID TINC TPVIRG {
        GenerateIncrementFunction($1.id, TIPO_INT, OP_IINC);
    }
    ;

ComandoSUBUnitario:
    TID TDEC TPVIRG {
        GenerateDecrementFunction($1.id, TIPO_INT, OP_IINC);
    }
  ;

ComandoAdicao:
    CarregaID TINC_N ExpressaoAritmetica TPVIRG {
        GenerateIncrementFunction($1.id, $3.tipo, 0);
    }
    ;

ComandoSubtracao:
    CarregaID TDEC_N ExpressaoAritmetica TPVIRG {
        GenerateDecrementFunction($1.id, $3.tipo, 0);
    }
    ;

CarregaID:
    TID {
        strcpy($$.id, $1.id);
        if (GetType($1.id) == TIPO_INT) {
            InsertIntegerVariable($1.id);
        } else {
            error();
        }
    }
    ;

Retorno:
    TRETURN ExpressaoAritmetica TPVIRG {
        CreateReturn($2.tipo);
        $$.tipo = $2.tipo;
    }
    ;

ComandoIF:
    TIF TAPAR ExpressaoLogica TFPAR NL Bloco {
        CorrectLabel(&$3.listav, $5.label);
        CorrectLabel(&$3.listaf, CreateLabel());
    }
    | TIF TAPAR ExpressaoLogica TFPAR NL Bloco N TELSE NL Bloco {
        CorrectLabel(&$3.listav, $5.label);
        CorrectLabel(&$3.listaf, $9.label);
        CorrectLabel(&$7.listav, CreateLabel());
    }
    ;

N: {
        CreateBooleanList(&$$.listav, &$$.listaf);
        CreateGOTO();
    }
    ;

ComandoWHILE:
    TWHILE NL TAPAR ExpressaoLogica TFPAR NL Bloco
    {
        CorrectLabel(&$4.listav, $6.label);
        CreateGOTOLabel($2.label);
        CorrectLabel(&$4.listaf, CreateLabel());
    }
    ;

ComandoAttrib:
    TID TATRIB ExpressaoAritmetica TPVIRG {
        CreateAttribuition( $1.id, GetType($1.id), $3.tipo);
    }
    | TID TATRIB TLITERAL TPVIRG {
        CreateLiteral($3.literal);
        CreateAttribuition( $1.id, GetType($1.id), TIPO_STRING); }
    ;

ComandoPRINT:
    TPRINT TAPAR M ExpressaoAritmetica TFPAR TPVIRG {
        if ($4.tipo == TIPO_INT)
            CallStaticMethod(TIPO_INT);
        else
            CallStaticMethod(TIPO_STRING);
    }
    | TPRINT TAPAR M TLITERAL TFPAR TPVIRG {
        CreateLiteral($4.literal);
        CallStaticMethod(TIPO_STRING);
    }
    ;

M: {
        GetStaticPrint(); }
  ;

ComandoREAD
      : TREAD TAPAR TID TFPAR TPVIRG
        {
          InsertStaticRead(GetType($3.id), GetValuePosition($3.id));
        }
      ;

ChamadaFuncao:
    TID TAPAR ListaParametros TFPAR TPVIRG {
        CreateFunctionWithParameters($1.id, &$3.listaParametros);
    }
    | TID TAPAR TFPAR TPVIRG {
        CreateFunctionWithoutParameters($1.id);
    }
    ;

ChamadaFuncaoSemPVIRG:
    TID TAPAR ListaParametros TFPAR {
        $$.tipo = GetFunctionType($1.id);
        CreateFunctionWithParameters($1.id, &$3.listaParametros);
    }
    | TID TAPAR TFPAR {
        $$.tipo = GetFunctionType($1.id);
        CreateFunctionWithoutParameters($1.id);
    }
    ;

ListaParametros:
    ListaParametros TVIRG ExpressaoAritmetica {
        AddSimpleParameter(&$$.listaParametros, $3.tipo);
    }
    | ExpressaoAritmetica {
        AllocParameterList(&$$.listaParametros);
        AddSimpleParameter(&$$.listaParametros, $1.tipo);
    }
    ;

ExpressaoAritmetica:
    ExpressaoAritmetica TADD TermoAritmetico {
        CreateOperation(OP_ADD);
    }
    | ExpressaoAritmetica TSUB TermoAritmetico {
        CreateOperation(OP_SUB);
    }
    | TermoAritmetico {
        $$.tipo = $1.tipo;
    }
    ;

TermoAritmetico:
    TermoAritmetico TMUL FatorAritmetico {
        if ($1.tipo == $3.tipo)
            CreateOperation(OP_MUL);
        else
            error();
    }
    | TermoAritmetico TDIV FatorAritmetico {
        if ($1.tipo == $3.tipo)
            CreateOperation(OP_DIV);
        else
            error();
    }
    | FatorAritmetico {
        $$.tipo = $1.tipo;
    }
    ;

FatorAritmetico:
    TNUM {
        InsertInteger($1.constante);
        $$.tipo = TIPO_INT;
    }
    | TSUB FatorAritmetico {
        $$.tipo = $2.tipo;
    }
    | ChamadaFuncaoSemPVIRG {
        $$.tipo = $1. tipo;
    }
    | TID
        {
            if( GetType($1.id) == TIPO_INT ) {
                InsertIntegerVariable($1.id);
                $$.tipo = TIPO_INT;
            }
            else if (GetType($1.id) == TIPO_STRING) {
                InsertStringVariable($1.id);
                $$.tipo = TIPO_STRING;
            }
        }
    | TAPAR ExpressaoAritmetica TFPAR
    ;


ExpressaoLogica:
    ExpressaoLogica TAND NL FatorLogico {
        CorrectLabel(&$1.listav, $3.label);
        CreateBooleanListWIthoutInclude(&$$.listav, &$$.listaf);
        ProcessBooleanOperation(&$$.listaf, &$1.listaf, &$4.listaf);
        ProcessBooleanOperation2(&$$.listav, &$4.listav);
    }
    | ExpressaoLogica TOR NL FatorLogico {
        CorrectLabel(&$1.listaf, $3.label);
        CreateBooleanListWIthoutInclude(&$$.listav, &$$.listaf);
        ProcessBooleanOperation(&$$.listav, &$1.listav, &$4.listav);
        ProcessBooleanOperation2(&$$.listaf, &$4.listaf);
    }
    | FatorLogico {
        MoveBooleanList(&$$.listav, &$$.listaf, &$1.listav, &$1.listaf);
    }
    ;

NL: {
        $$.label = CreateLabel();
    }
    ;

FatorLogico:
    TNOT FatorLogico {
        MoveBooleanList(&$$.listav, &$$.listaf, &$2.listav, &$2.listaf);
    }
    | TAPAR ExpressaoLogica TFPAR {
        MoveBooleanList(&$$.listav, &$$.listaf, &$2.listav, &$2.listaf);
    }
    | ExpressaoRelacional {
        MoveBooleanList(&$$.listav, &$$.listaf, &$1.listav, &$1.listaf);
    }
    ;

ExpressaoRelacional:
    ExpressaoAritmetica TMAIOR ExpressaoAritmetica {
        CreateBooleanList(&$$.listav, &$$.listaf);
        CreateCompare(CMP_GTHAN, $1.tipo, $3.tipo);
        CreateGOTO();
    }
    | ExpressaoAritmetica TMENOR ExpressaoAritmetica {
        CreateBooleanList(&$$.listav, &$$.listaf);
        CreateCompare(CMP_LTHAN, $1.tipo, $3.tipo);
        CreateGOTO();
    }
    | ExpressaoAritmetica TMAIGUAL ExpressaoAritmetica {
        CreateBooleanList(&$$.listav, &$$.listaf);
        CreateCompare(CMP_GEQUAL, $1.tipo, $3.tipo);
        CreateGOTO();
    }
    | ExpressaoAritmetica TMEIGUAL ExpressaoAritmetica {
        CreateBooleanList(&$$.listav, &$$.listaf);
        CreateCompare(CMP_LEQUAL, $1.tipo, $3.tipo);
        CreateGOTO();
    }
    | ExpressaoAritmetica TIGUAL ExpressaoAritmetica {
        CreateBooleanList(&$$.listav, &$$.listaf);
        CreateCompare(CMP_EQUAL, $1.tipo, $3.tipo);
        CreateGOTO();
    }
    | ExpressaoAritmetica TDIFER ExpressaoAritmetica {
        CreateBooleanList(&$$.listav, &$$.listaf);
        CreateCompare(CMP_NEQUAL, $1.tipo, $3.tipo);
        CreateGOTO();
    }
    ;

%%
#include "lex.yy.c"

int yyerror (char *str)
{
    printf("%s - antes %s\n", str, yytext);

    return 0;
}

int yywrap()
{
    return 1;
}
