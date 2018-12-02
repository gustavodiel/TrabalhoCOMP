#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Defines.h"
//#define

#include "Structs.h"
#include "Initializers.h"
#include "Boolean.h"
#include "Helpers.h"
#include "Globals.h"

#ifndef __gramv3__
#define __gramv3__


void ShowAllIDs(pAttributeList listOfAttributes);
void ShowAllInstructions();
void ShowAllLiterals();


void writeCabecalho(FILE *arq);
void writeMethodMain(FILE *arq);
void writeEndMethodMain(FILE *arq);
void writeListaInstrucao(FILE *arq);
int createJar(char* argc);

void setPossuiErro();


void setPossuiErro();


pAttributeList GetMainListPointer();

pInstruction* GetInstructionsList();


pLiteralList GetLiteralList();

int AddGOTO( int label);


int AddPrintString( int label);
int AddPrintInteger( int label);
int AddGETSTATICPrint( int label);


int GetInstructionListSize();

int AddInstructionToMainList( char byteCode[21], char* firstParameter, char* secondParameter, int label, int parameterAmount);
int AddPositionValueToInstruction( char byteCode[21], int posVal_1, int posVal_2, int label);
int AddLDCInstruction( char* literal, int label);

int AddNumeralToMainList(int num, int label);

pAttributeList AddLabelToMainList( int label);
int AddIfToMainList( char byteCode[21], int label_1, int label_2, int currentLabel);


char* AddLiteralToMainList( pAttributeList literal);

void AddAtributeToMainList( pAttributeList newlista, int sePosVal, int type);

void AddIDToMainList( pAttributeList listaFinal, pAttributeList listOfAttributes);

#endif
