//
// Created by Gustavo Diel on 27/11/18.
//

#ifndef COMP_H
#define COMP_H

#include "Lista.h"

#define NULO         0
#define NULO_STR     ""

#define TIPO_INT     1000
#define TIPO_STRING  1001
#define TIPO_VOID    1002

#define INST_IDIV            2000
#define INST_IMUL            2001
#define INST_IADD            2002
#define INST_ISUB            2003
#define INST_ICONST0         2004
#define INST_ICONST1         2005
#define INST_ICONST2         2006
#define INST_ICONST3         2007
#define INST_ICONST4         2008
#define INST_ICONST5         2009
#define INST_BIPUSH          2010
#define INST_ILOAD           2011
#define INST_ISTORE          2012
#define INST_GETPRINT        2013
#define INST_INVOKEPRINT_INT 2014
#define INST_INVOKEPRINT_STR 2015
#define INST_IF_ICMPEQ       2016
#define INST_IF_ICMPNE       2017
#define INST_IF_ICMPLT       2018
#define INST_IF_ICMPLE       2019
#define INST_IF_ICMPGT       2020
#define INST_IF_ICMPGE       2021
#define INST_GOTO            2022
#define INST_NEWLABEL        2023
#define INST_LDC             2024
#define INST_DUP             2025
#define INST_NEWSCANNER      2026
#define INST_GETINPUTSTREAM  2027
#define INST_INVOKEINPUTSTR  2028
#define INST_NEXTINT         2029
#define INST_LDCSTRING       2030
#define INST_ASTORE          2031
#define INST_ALOAD           2032
#define INST_NEXTLINE        2033
#define INST_DELIMITADORFUNC 2034
#define INST_INVOKESTATIC    2035
#define INST_IRETURN         2036
#define INST_ARETURN         2037
#define INST_RETURN          2038
#define INST_IINC            2039

#define CMP_EQUAL            3000
#define CMP_NEQUAL           3001
#define CMP_LTHAN            3002
#define CMP_LEQUAL           3003
#define CMP_GTHAN            3004
#define CMP_GEQUAL           3005
#define OP_MUL               3006
#define OP_ADD               3007
#define OP_DIV               3008
#define OP_SUB               3009
#define OP_IINC              3010

struct Atributo {
	unsigned tipo;
	unsigned label;
	char id[32];
	char literal[256];
	int constante;
	unsigned nParametros;
	Lista listaIDs;
	Lista listaParametros;
	Lista listav;
	Lista listaf;
};

struct Simbolo {
	char id[32];
	unsigned tipo, pos;
};

struct Instrucao {
	unsigned label;
	int inst;
	int p1, p2;
	char literal[256];
};

struct Parametro {
	char id[32];
	int tipo;
	int pos;

};

struct Funcao {
	char id[32];
	unsigned tipoRetorno;
	unsigned pos;
	unsigned nParametros;
	unsigned nStack;
	unsigned nLocals;
	Lista listaParametros;
};

void StartCompiler();

void CreateSymbol(Lista *l, int tipo);

void CreateParameter(Lista *l, unsigned tipo, char id[32]);

void AddSimpleParameter(Lista *l, unsigned tipo);

void CreateFunctionWithParameter(Lista *lParam, unsigned tipoRetorno, char id[32]);

void CreateFunctionWithoutParameter(unsigned tipoRetorno, char id[32]);

void CreateID(Lista *l, char id[32]);

void BeginFunction();

void AllocIDList(Lista *l);

void AllocParameterList(Lista *l);

void CreateBooleanList(Lista *v, Lista *f);

void CreateBooleanListWIthoutInclude(Lista *v, Lista *f);

void MoveBooleanList(Lista *v, Lista *f, Lista *v_old, Lista *f_old);

void ShowTableSymbol();

void ShowSymbol(void *info);

int CompareSymbol(void *a, void *b);

unsigned GetType(char id[32]);

unsigned GetValuePosition(char id[32]);

unsigned GetFunctionType(char id[32]);

// Gerar instrucoes
void GenerateBytecode();

void CreateAttribuition(char var[32], unsigned tipo1, unsigned tipo2);

void CreateCompare(int comp, unsigned tipo1, unsigned tipo2);

void CreateGOTO();

void CreateGOTOLabel(unsigned label);

void CreateOperation(int comp);

void InsertStaticRead(int tipo, int pos);

void CreateInstruction(unsigned label, int inst, int p1, int p2, char str[256]);

void CreateFunctionWithoutParameters(char id[32]);

void CreateFunctionWithParameters(char id[32], Lista *l);

void CreateReturn(unsigned tipo);

void GenerateIncrementFunction(char id[32], unsigned tipo, int n);

void GenerateDecrementFunction(char id[32], unsigned tipo, int n);

void InsertInteger(int num);

void CreateLiteral(char str[256]);

void InsertIntegerVariable(char id[32]);

void InsertStringVariable(char id[32]);

void GetStaticPrint();

void CallStaticMethod(int TIPO);

void error();

void IncreaseStack(int i);

void DecreaseStack(int i);

void CorrectLabel(Lista *l, int label);

void CorrectMainIDs();

void CreateFunctionBody();

void ProcessBooleanOperation(Lista *l_dest, Lista *l1, Lista *l2);

void ProcessBooleanOperation2(Lista *l_dest, Lista *l1);

int CreateLabel();

#endif