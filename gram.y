%{
#include "gram.h"

#define YYSTYPE pAttributeList


%}

%token TOKEN_ID TOKEN_INT TOKEN_STRING TOKEN_VOID TOKEN_MAIS TOKEN_MAIS_MAIS TOKEN_MENOS TOKEN_MENOS_MENOS TOKEN_MULT TOKEN_DIV TOKEN_IGUAL TOKEN_MAIOR_IGUAL TOKEN_MENOR_IGUAL TOKEN_MAIOR TOKEN_MENOR TOKEN_DIFERENTE TOKEN_NEGACAO TOKEN_E TOKEN_OU TOKEN_NUM_REAL TOKEN_TEXTO TOKEN_IF TOKEN_ELSE TOKEN_WHILE TOKEN_READ TOKEN_PRINT TOKEN_ATRIBUICAO TOKEN_FECHA_PAR TOKEN_ABRE_PAR TOKEN_VIRGULA TOKEN_ABRE_CHAVES TOKEN_FECHA_CHAVES TOKEN_RETURN TOKEN_PONTO_VIRGULA TFIM TOKEN_MAIS_IGUAL

%%
Prog :
	ListaFuncoes BlocoPrincipal
	| BlocoPrincipal
	;

ListaFuncoes:
	ListaFuncoes Function {
			AddAtributeToMainList( $2, 0, $2 -> tempType);
		}
	| Function {
			AddAtributeToMainList( $1, 0, $1 -> tempType);
		}
	;

Function:
	TipoRetorno TOKEN_ID TOKEN_ABRE_PAR DeclParametros TOKEN_FECHA_PAR  {
			AddIDToMainList( $4, $2);
			AddAtributeToMainList($4, 0, T_TODEF);
		}
	| TipoRetorno TOKEN_ID TOKEN_ABRE_PAR TOKEN_FECHA_PAR   {
			AddIDToMainList( $4, $2);
			AddAtributeToMainList($4, 0, T_TODEF);
		}
	;

TipoRetorno:
	Tipo {
			$$ = $1;
		}
	| TOKEN_VOID {
	  		$$ = CreateType( T_VOID);
		}
	;

DeclParametros:
	DeclParametros TOKEN_VIRGULA Parametro
	| Parametro
	;

Parametro:
	Tipo TOKEN_ID {
			AddIDToMainList( $2, $2);
			AddAtributeToMainList($2, 1, $1 -> tempType);
		}
	;

BlocoPrincipal:
	TOKEN_ABRE_CHAVES Declaracoes ListaCmd TOKEN_FECHA_CHAVES
	| TOKEN_ABRE_CHAVES ListaCmd TOKEN_FECHA_CHAVES
	;

Declaracoes:
	Declaracoes Declaracao {
			AddAtributeToMainList( $2, 1, $2 -> tempType);
		}
	| Declaracao {
			AddAtributeToMainList( $1, 1, $1 -> tempType);
		}
	;

Declaracao:
	Tipo ListaID TOKEN_PONTO_VIRGULA {
			$2 -> tempType = $1 -> tempType;
			$$ = $2;
			free($1);
		}
	;

Tipo:
	TOKEN_INT {
			$$ = CreateType( T_INT);
		}
	| TOKEN_STRING {
			$$ = CreateType( T_STR);
		}
	;

ListaID:
	ListaID TOKEN_VIRGULA TOKEN_ID {
			AddIDToMainList($1, $3);
		}
	| TOKEN_ID {
			AddIDToMainList($$, $1);
		}
	;

Bloco:
	TOKEN_ABRE_CHAVES ListaCmd TOKEN_FECHA_CHAVES
	;

ListaCmd:
	ListaCmd Comando
	| Comando
	;

Comando:
	ComandoIF
	| ComandoWHILE
	| ComandoATTRIB
	| ComandoREAD
	| ComandoWRITE
	| CallProc
	| Return
	;

Return:
	TOKEN_RETURN ExpressaoAritmetica TOKEN_PONTO_VIRGULA
	| TOKEN_RETURN TOKEN_TEXTO TOKEN_PONTO_VIRGULA
	;

ComandoIF:
	TOKEN_IF TOKEN_ABRE_PAR ExpressaoLogica TOKEN_FECHA_PAR MUpdateLabel Bloco {
			CorrectLabel( $3 -> ptrTrue, $5 -> label);

			labelAmount++;

			currentLabel = labelAmount;
			AddLabelToMainList( currentLabel);

			CorrectLabel( $3 -> ptrFalse, currentLabel);
			free($3);
			free($5);
		}
	| TOKEN_IF TOKEN_ABRE_PAR ExpressaoLogica TOKEN_FECHA_PAR MUpdateLabel Bloco UpdateLabel TOKEN_ELSE MUpdateLabel Bloco  {
			CorrectLabel( $3 -> ptrTrue, $5 -> label);
			CorrectLabel( $3 -> ptrFalse, $9 -> label);

			labelAmount++;

			currentLabel = labelAmount;
			AddLabelToMainList( currentLabel);

			CorrectLabel( $7 -> ptrTrue, currentLabel);

			free($3);
			free($5);
			free($7);
			free($9);
		}
	;

MUpdateLabel: {
	labelAmount++;
			currentLabel = labelAmount;
			$$ = AddLabelToMainList( currentLabel);
		}
	;

UpdateLabel: {
			int lineNumber = GetInstructionListSize();
			AddGOTO( currentLabel);

			$$ = CreateBooleanList( GOTO, lineNumber);
			$$ -> label = currentLabel;
		}
	;

ComandoWHILE:
	TOKEN_WHILE MUpdateLabel TOKEN_ABRE_PAR ExpressaoLogica TOKEN_FECHA_PAR MUpdateLabel Bloco    {
			CorrectLabel( $4 -> ptrTrue, $6 -> label);
			AddGOTO($2 -> label);

			labelAmount++;

			currentLabel = labelAmount;
			AddLabelToMainList( currentLabel);

			CorrectLabel( $4 -> ptrFalse, currentLabel);

			free($2);
			free($4);
			free($6);
		}
	;


ComandoATTRIB:
	TOKEN_ID TOKEN_ATRIBUICAO ExpressaoAritmetica TOKEN_PONTO_VIRGULA {
			AddPositionValueToInstruction( ISTORE, GetPositionValue( $1 -> tempIDName), -1, currentLabel);
		}
	| TOKEN_ID TOKEN_ATRIBUICAO TOKEN_TEXTO TOKEN_PONTO_VIRGULA     {
			AddLDCInstruction( AddLiteralToMainList( $3), currentLabel);
			AddPositionValueToInstruction( ISTORE, GetPositionValue( $1 -> tempIDName), -1, currentLabel);
		}
	;

ComandoREAD:
	TOKEN_READ TOKEN_ABRE_PAR TOKEN_ID TOKEN_FECHA_PAR TOKEN_PONTO_VIRGULA {
			int type = GetType( $3->tempIDName);
			if( type == T_INT){
				AddNumeralToMainList( 3, currentLabel);
			} else if( type == T_STR){
				AddLDCInstruction( "\"Frase sem copyright\"", currentLabel);
			} else {
				printf("\nErro %s %i\n", $3->tempIDName, type);
				setPossuiErro();
			}
			if( IDExists( GetMainListPointer(), $3) == 1){
				setPossuiErro();
			}
			AddPositionValueToInstruction( ISTORE, GetPositionValue($3->tempIDName), -1, currentLabel);
		}
	;

ComandoWRITE:
	TOKEN_PRINT ComandoPRINT TOKEN_ABRE_PAR ExpressaoAritmetica TOKEN_FECHA_PAR TOKEN_PONTO_VIRGULA {
		if( $4 -> tempType == T_INT)
				AddPrintInteger( currentLabel);
			else if( $4 -> tempType == T_STR)
				AddPrintString(currentLabel);
			else{
				setPossuiErro();
				printf("\nTipo incompativel para escrita\n");
			}
		}
	| TOKEN_PRINT ComandoPRINT TOKEN_ABRE_PAR TOKEN_TEXTO TOKEN_FECHA_PAR TOKEN_PONTO_VIRGULA {
			AddLDCInstruction( AddLiteralToMainList( $4), currentLabel);
			AddPrintString( currentLabel);
		}
	;

ComandoPRINT: {
			AddGETSTATICPrint( currentLabel);
		}
	;

CallProc:
	TOKEN_ID TOKEN_ABRE_PAR ListaParametros TOKEN_FECHA_PAR
	| TOKEN_ID TOKEN_ABRE_PAR TOKEN_FECHA_PAR
	;

ListaParametros:
	ListaParametros TOKEN_VIRGULA ExpressaoAritmetica
	| ListaParametros TOKEN_VIRGULA TOKEN_TEXTO {
			AddLiteralToMainList($3);
		}
	| ExpressaoAritmetica
	| TOKEN_TEXTO {
			AddLiteralToMainList($1);
		}
	;

ExpressaoLogica:
	ExpressaoLogica TOKEN_E MUpdateLabel SingleLogica {
			CorrectLabel( $1 -> ptrTrue, $3 -> label);
			$$ = ProcessBooleanAND( $4, $1);
		}
	| ExpressaoLogica TOKEN_OU MUpdateLabel SingleLogica {
			CorrectLabel( $1 -> ptrFalse, $3 -> label);
			$$ = ProcessBooleanOR( $4, $1);
		}
	| SingleLogica {
			$$ = $1;
		}
	;

SingleLogica:
	TOKEN_ABRE_PAR ExpressaoLogica TOKEN_FECHA_PAR {
			$$ = $2;
		}
	| TOKEN_NEGACAO SingleLogica {
			$$ = ProcessBooleanNOT( $2);
		}
	| RelacaoLogica {
			$$ = $1;
		}
	;

RelacaoLogica:
	ExpressaoAritmetica TOKEN_IGUAL ExpressaoAritmetica {
			int lineNumber = GetInstructionListSize();
			$$ = CreateBooleanList( IFEQ, lineNumber);
			AddIfToMainList( IFEQ, -1, -1, currentLabel);
		}
	| ExpressaoAritmetica TOKEN_DIFERENTE ExpressaoAritmetica {
			int lineNumber = GetInstructionListSize();
			$$ = CreateBooleanList( IFDIF, lineNumber);
			AddIfToMainList( IFDIF, -1, -1, currentLabel);
		}
	| ExpressaoAritmetica TOKEN_MAIOR_IGUAL ExpressaoAritmetica {
			int lineNumber = GetInstructionListSize();
			$$ = CreateBooleanList( IFMAEQ, lineNumber);
			AddIfToMainList( IFMAEQ, -1, -1, currentLabel);
		}
	| ExpressaoAritmetica TOKEN_MENOR_IGUAL ExpressaoAritmetica {
			int lineNumber = GetInstructionListSize();
			$$ = CreateBooleanList( IFMEEQ, lineNumber);
			AddIfToMainList( IFMEEQ, -1, -1, currentLabel);
		}
	| ExpressaoAritmetica TOKEN_MAIOR ExpressaoAritmetica {
			int lineNumber = GetInstructionListSize();
			$$ = CreateBooleanList( IFMA, lineNumber);
			AddIfToMainList( IFMA, -1, -1, currentLabel);
		}
	| ExpressaoAritmetica TOKEN_MENOR ExpressaoAritmetica {
			int lineNumber = GetInstructionListSize();
			$$ = CreateBooleanList( IFME, lineNumber);
			AddIfToMainList( IFME, -1, -1, currentLabel);
		}
	;

ExpressaoAritmetica:
	ExpressaoAritmetica TOKEN_MAIS ExpMultDiv {
			AddInstructionToMainList( IADD, INVAL, INVAL, currentLabel, 0);
		}
	| ExpressaoAritmetica TOKEN_MENOS ExpMultDiv {
			AddInstructionToMainList( ISUB, INVAL, INVAL, currentLabel, 0);
		}
	| ExpMultDiv {
			$$ = $1;
		}
	;

ExpMultDiv:
	ExpMultDiv TOKEN_MULT ExpAddSub {
			AddInstructionToMainList( IMUL, INVAL, INVAL, currentLabel, 0);
		}
	| ExpMultDiv TOKEN_DIV ExpAddSub {
			AddInstructionToMainList( IDIV, INVAL, INVAL, currentLabel, 0);
		}
	| ExpAddSub           {
			$$ = $1;
		}
	;

ExpAddSub:
	TOKEN_MENOS ExpAddSub {
			AddInstructionToMainList( INEG, INVAL, INVAL, currentLabel, 0);
		}
	| TOKEN_ABRE_PAR ExpressaoAritmetica TOKEN_FECHA_PAR
	| TOKEN_ID {
			if( IDExists( GetMainListPointer(), $1 -> tempIDName) == 1){
				setPossuiErro();
				printf("ID %s não existente\n", $1 -> tempIDName);
			}
			AddPositionValueToInstruction( ILOAD, GetPositionValue($1->tempIDName), -1, currentLabel);
			$$ -> tempType = GetType( $1 -> tempIDName);

			free($1);
		}
	| CallProc {
			if( IDExists( GetMainListPointer(), $1) == 0){
				printf("\nFuncao nao implemetada\n");
			}
		}
	| TOKEN_NUM_REAL {
			AddNumeralToMainList( $1 -> tempNumber, currentLabel);
		}
	;

%%

#include "lex.yy.c"
int yyerror (char *str){
	printf("Erro em %i - %s; %s\n", lineNumber, yytext, str);
	setPossuiErro();
}
int yywrap(){
	return 1;
}
