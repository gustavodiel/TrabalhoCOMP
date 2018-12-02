
#include "gram.h"

extern FILE *yyin;

int posValGlobal = 1;
int possuiErro = 0;

int main(int argc, char const *argv[])
{
	int i;
	for( i = 0; i < 200; i++){
		ptrInstructionList[ i] = NULL;
	}

	ptrLiteralList = NULL;

	ptrMainList = (AttributeList*)malloc(sizeof(AttributeList));
	ptrMainList -> listOfAttributes = NULL;

	yyin = fopen( argv[1], "r");
	if( yyin != NULL){
		yyparse();
		fclose(yyin);
	}else{
		perror("File not found!\n");
		exit(-1);
	}

	ShowAllIDs(ptrMainList);
	ShowAllLiterals();
	ShowAllInstructions();

    if(!possuiErro)
        createJar(argv[1]);
    else
        perror("There are errors in the code!\n");

	printf("\n");
	return 0;
}


void writeCabecalho(FILE *arq){
	fprintf( arq, ".class public Main\n");
	fprintf( arq, ".super java/lang/Object\n\n");
	fprintf( arq, ".method public <init>()V\n");
	fprintf( arq, "  aload_0\n\n");
	fprintf( arq, "  invokevirtual java/lang/Object/<init>()V\n");
	fprintf( arq, "  return\n");
	fprintf( arq, ".end method\n\n");
}

void writeMethodMain( FILE *arq){
	fprintf( arq, ".method public static main([Ljava/lang/String;)V\n");
	fprintf( arq, ".limit stack 10\n");

	int numVariaveisLocais = 0;
	pAttribute aux;
	if( ptrMainList -> listOfAttributes != NULL){
		pAttribute aux = ptrMainList -> listOfAttributes;
		do{
			if( aux -> valuePosition != -1)
				numVariaveisLocais++;
			aux = aux->ptrNext;
		}while( aux != NULL);
	}
	fprintf( arq, ".limit locals %i\n", numVariaveisLocais);
}

void writeEndMethodMain( FILE *arq){
	fprintf( arq, "\n  return\n.end method");
}

void ShowAllIDs(pAttributeList listOfAttributes){
	printf("\nSymbols Table %p:\n", (void*)listOfAttributes);
	printf("\tSymbol\tPosition\n\n");
	if( listOfAttributes->listOfAttributes != NULL){
		pAttribute aux = listOfAttributes->listOfAttributes;
		do{
			printf("\t%s\t%i", aux->nameID, aux->valuePosition);
			if( aux-> type == T_INT){
				printf("\tint\n");
			} else if( aux -> type == T_STR){
				printf("\tstring\n");
			} else if( aux -> type == T_VOID){
				printf("\tvoid\n");
			} else {
				printf("\tunkown/no type\n");
			}
			aux = aux->ptrNext;
		}while( aux != NULL);
	}
	printf("\n");
}

void ShowAllInstructions(){
	int instructionsNumber = 0;
	while( ptrInstructionList[ instructionsNumber] != NULL){
		printf("\n%i", instructionsNumber);
		if( ptrInstructionList[ instructionsNumber] -> label != 0)
			printf("  ");
		printf("  %s", ptrInstructionList[ instructionsNumber]->byteCode);
		if( ptrInstructionList[ instructionsNumber] -> parameterAmount > 0){
			printf(" %s", ptrInstructionList[ instructionsNumber] -> firstParameter);
			if( ptrInstructionList[ instructionsNumber] -> parameterAmount > 1)
				printf(" %s", ptrInstructionList[ instructionsNumber] -> secondParameter);
		}
		instructionsNumber++;
	}
}

void writeListaInstrucao( FILE *arq){
	int instructionsNumber = 0;
	while( ptrInstructionList[ instructionsNumber] != NULL){
		if( ptrInstructionList[ instructionsNumber] -> label != 0)
			fprintf( arq, "\t");
		fprintf( arq, "\n  %s", ptrInstructionList[ instructionsNumber]->byteCode);
		if( ptrInstructionList[ instructionsNumber] -> parameterAmount > 0){
			fprintf( arq, " %s", ptrInstructionList[ instructionsNumber] -> firstParameter);

			if( ptrInstructionList[ instructionsNumber] -> parameterAmount > 1)
				fprintf( arq, " %s", ptrInstructionList[ instructionsNumber] -> secondParameter);

		}
		instructionsNumber++;
	}
}

void ShowAllLiterals(){
	printf("\nLiterals Table\n");
	pLiteralList aux = ptrLiteralList;
	while( aux != NULL){
		printf("\t%s\n", aux -> literal);
		aux = aux -> ptrNext;
	}
	printf("\n");
}

int createJar(char* argc){
	FILE *newArquivo;
	char nomeNew[strlen(argc) + 3];
	int i = 0;
	while( argc[ i] != '.' && argc[ i] != '\0' && i < strlen(argc)){
		nomeNew[ i] = argc[ i];
		i++;
	}
	nomeNew[ i++] = '.';
	nomeNew[ i++] = 'j';
	nomeNew[ i++] = '\0';
	printf("\n\nFile created: %s\n", nomeNew);

	newArquivo = fopen( nomeNew, "w");
	if( newArquivo == NULL){
		perror("Failed to create new file");
		exit(-2);
	}
	writeCabecalho(newArquivo);
	writeMethodMain(newArquivo);
	writeListaInstrucao(newArquivo);
	writeEndMethodMain(newArquivo);

	fclose(newArquivo);

	return 1;
}

void setPossuiErro(){
	possuiErro = 1;
}

pAttributeList GetMainListPointer(){
	return ptrMainList;
}

pInstruction* GetInstructionsList(){
	return ptrInstructionList;
}

pLiteralList GetLiteralList(){
	return ptrLiteralList;
}

int AddGOTO( int label){
	int instructionsNumber = 0;

	pInstruction* listaInstrucao = GetInstructionsList();

	while( (listaInstrucao[instructionsNumber] != NULL) && (instructionsNumber < 200)){
		instructionsNumber++;
	}

	if( instructionsNumber == 200){
		perror("Instruction List Full!\n");
		return 0;
	}

	listaInstrucao[ instructionsNumber] = (Instruction*)malloc(sizeof(Instruction));
	listaInstrucao[ instructionsNumber] -> firstParameter = ( char*)malloc( sizeof( 5));

	strcpy( listaInstrucao[ instructionsNumber] -> byteCode, GOTO);
	sprintf( listaInstrucao[ instructionsNumber] -> firstParameter, "l%i", label);

	listaInstrucao[ instructionsNumber] -> label = label;
	listaInstrucao[ instructionsNumber] -> parameterAmount = 1;

	return 1;
}


int AddPrintString( int label){
	int instructionsNumber = 0;

	pInstruction* listaInstrucao = GetInstructionsList();

	while( (listaInstrucao[instructionsNumber] != NULL) && (instructionsNumber < 200)){
		instructionsNumber++;
	}

	if( instructionsNumber == 200){
		perror("Instruction List Full!\n");
		return 0;
	}

	listaInstrucao[ instructionsNumber] = (Instruction*)malloc(sizeof(Instruction));

	strcpy( listaInstrucao[ instructionsNumber] -> byteCode, INVOKEVIRTUAL);

	listaInstrucao[ instructionsNumber] -> firstParameter = (char*)malloc( strlen(PRINT_STR) + 1);
	strncpy( listaInstrucao[ instructionsNumber] -> firstParameter, PRINT_STR, strlen(PRINT_STR));

	listaInstrucao[ instructionsNumber] -> label = label;
	listaInstrucao[ instructionsNumber] -> parameterAmount = 1;

	return 1;

}

int AddPrintInteger( int label){
	int instructionsNumber = 0;

	pInstruction* listaInstrucao = GetInstructionsList();

	while( (listaInstrucao[instructionsNumber] != NULL) && (instructionsNumber < 200)){
		instructionsNumber++;
	}

	if( instructionsNumber == 200){
		perror("Instruction List Full!\n");
		return 0;
	}

	listaInstrucao[ instructionsNumber] = (Instruction*)malloc(sizeof(Instruction));

	strcpy( listaInstrucao[ instructionsNumber] -> byteCode, INVOKEVIRTUAL);

	listaInstrucao[ instructionsNumber] -> firstParameter = (char*)malloc( strlen(PRINT_INT) + 1);
	strncpy( listaInstrucao[ instructionsNumber] -> firstParameter, PRINT_INT, strlen(PRINT_INT));

	listaInstrucao[ instructionsNumber] -> label = label;
	listaInstrucao[ instructionsNumber] -> parameterAmount = 1;

	return 1;
}


int AddGETSTATICPrint( int label){
	int instructionsNumber = 0;

	pInstruction* listaInstrucao = GetInstructionsList();

	while( (listaInstrucao[instructionsNumber] != NULL) && (instructionsNumber < 200)){
		instructionsNumber++;
	}

	if( instructionsNumber == 200){
		perror("Instruction List Full!\n");
		return 0;
	}

	listaInstrucao[ instructionsNumber] = (Instruction*)malloc(sizeof(Instruction));

	strcpy( listaInstrucao[ instructionsNumber] -> byteCode, GETSTATIC);

	listaInstrucao[ instructionsNumber] -> firstParameter = (char*)malloc( strlen(SYSTEM_OUT) + 1);
	strncpy( listaInstrucao[ instructionsNumber] -> firstParameter, SYSTEM_OUT, strlen(SYSTEM_OUT));

	listaInstrucao[ instructionsNumber] -> secondParameter = (char*)malloc( PRINTSTREAM);
	strcpy( listaInstrucao[ instructionsNumber] -> secondParameter ,PRINTSTREAM);

	listaInstrucao[ instructionsNumber] -> label = label;
	listaInstrucao[ instructionsNumber] -> parameterAmount = 2;

	return 1;
}

int GetInstructionListSize(){
	int instructionsNumber = 0;

	pInstruction* listaInstrucao = GetInstructionsList();

	while( (listaInstrucao[instructionsNumber] != NULL) && (instructionsNumber < 200)){
		instructionsNumber++;
	}

	if( instructionsNumber == 200){
		perror("Instruction List Full!\n");
		return -1;
	}
	return instructionsNumber;
}

int AddInstructionToMainList( char byteCode[21], char* firstParameter, char* secondParameter, int label, int parameterAmount){
	int instructionsNumber = 0;
	pInstruction* listaInstrucao = GetInstructionsList();
	while( (listaInstrucao[ instructionsNumber] != NULL) && ( instructionsNumber < 200)){
		instructionsNumber++;
	}

	if( instructionsNumber == 200){
		perror("Instruction List Full!\n");
		return 0;
	}

	listaInstrucao[ instructionsNumber] = (Instruction*)malloc(sizeof(Instruction));
	strcpy( listaInstrucao[ instructionsNumber] -> byteCode, byteCode);

	if( parameterAmount > 0){
		listaInstrucao[ instructionsNumber] -> firstParameter = ( char*)malloc( sizeof( strlen( firstParameter) + 1));
		strncpy(listaInstrucao[ instructionsNumber] -> firstParameter, firstParameter, strlen( firstParameter));
		listaInstrucao[ instructionsNumber] -> firstParameter[ strlen(firstParameter) + 1] = '\0';

		if( parameterAmount > 1){
			listaInstrucao[ instructionsNumber] -> secondParameter = ( char*)malloc( sizeof( strlen( secondParameter) + 1));
			strncpy(listaInstrucao[ instructionsNumber] -> secondParameter, secondParameter, strlen( secondParameter));
			listaInstrucao[ instructionsNumber] -> secondParameter[ strlen(secondParameter) + 1] = '\0';
		}
	}

	listaInstrucao[ instructionsNumber] -> label = label;
	listaInstrucao[ instructionsNumber] -> parameterAmount = parameterAmount;

	return 1;
}

int AddPositionValueToInstruction( char byteCode[21], int posVal_1, int posVal_2, int label){
	int instructionsNumber = 0;

	pInstruction* listaInstrucao = GetInstructionsList();

	while( (listaInstrucao[instructionsNumber] != NULL) && (instructionsNumber < 200)){
		instructionsNumber++;
	}

	if( instructionsNumber == 200){
		perror("Instruction List Full!\n");
		return 0;
	}

	listaInstrucao[ instructionsNumber] = (Instruction*)malloc(sizeof(Instruction));
	listaInstrucao[ instructionsNumber] -> firstParameter = ( char*)malloc( sizeof( 4));
	listaInstrucao[ instructionsNumber] -> secondParameter = ( char*)malloc( sizeof( 4));

	strcpy( listaInstrucao[instructionsNumber] -> byteCode, byteCode);
	if( posVal_1 != -1){
		listaInstrucao[ instructionsNumber] -> parameterAmount = 1;
		sprintf( listaInstrucao[ instructionsNumber] -> firstParameter, "%i", posVal_1);
		if( posVal_2 != -1){
			listaInstrucao[ instructionsNumber] -> parameterAmount = 2;
			sprintf( listaInstrucao[ instructionsNumber] -> secondParameter, "%i", posVal_2);
		}else{
			strcpy( listaInstrucao[ instructionsNumber] -> secondParameter, INVAL);
		}
	}
	else{
		listaInstrucao[ instructionsNumber] -> parameterAmount = 0;
		strcpy( listaInstrucao[ instructionsNumber] -> firstParameter, INVAL);
		strcpy( listaInstrucao[ instructionsNumber] -> secondParameter, INVAL);
	}

	listaInstrucao[ instructionsNumber] -> label = label;
	return 1;
}


int AddLDCInstruction( char* literal, int label){
	int instructionsNumber = 0;

	pInstruction* listaInstrucao = GetInstructionsList();
	while( (listaInstrucao[ instructionsNumber] != NULL) && ( instructionsNumber < 200)){
		instructionsNumber++;
	}

	if( instructionsNumber == 200){
		perror("Instruction List Full!\n");
		return 0;
	}

	listaInstrucao[ instructionsNumber] = (Instruction*)malloc(sizeof(Instruction));
	strcpy( listaInstrucao[ instructionsNumber] -> byteCode, LDC);

	listaInstrucao[ instructionsNumber] -> firstParameter = ( char*)malloc( sizeof( strlen( literal) + 1));
	strncpy(listaInstrucao[ instructionsNumber] -> firstParameter, literal, strlen( literal));
	listaInstrucao[ instructionsNumber] -> firstParameter[ strlen(literal)] = '\0';

	listaInstrucao[ instructionsNumber] -> label = label;
	listaInstrucao[ instructionsNumber] -> parameterAmount = 1;
}

int AddNumeralToMainList(int num, int label){
	char str[20];
	switch (num){
		case 0:
			if( AddInstructionToMainList(ICONST_0, INVAL, INVAL, label, 0) == 1)
				return 1;
			return 0;
		case 1:
			if( AddInstructionToMainList(ICONST_1, INVAL, INVAL, label, 0) == 1)
				return 1;
			return 0;
		case 2:
			if( AddInstructionToMainList(ICONST_2, INVAL, INVAL, label, 0) == 1)
				return 1;
			return 0;
		case 3:
			if( AddInstructionToMainList(ICONST_3, INVAL, INVAL, label, 0) == 1)
				return 1;
			return 0;
		case 4:
			if( AddInstructionToMainList(ICONST_4, INVAL, INVAL, label, 0) == 1)
				return 1;
			return 0;
		case 5:
			if( AddInstructionToMainList(ICONST_5, INVAL, INVAL, label, 0) == 1)
				return 1;
			return 0;
		default:
			sprintf(str, "%d", num);
			if( num > 127){
				if( AddInstructionToMainList(LDC, str, INVAL, label, 1) == 1)
					return 1;
				return 0;
			}
			if( num > 5){
				if( AddInstructionToMainList(BIPUSH, str, INVAL, label, 1) == 1)
					return 1;
				return 0;
			}
	}
	return 0;
}

pAttributeList AddLabelToMainList( int label){
	int instructionsNumber = 0;

	pAttributeList new = (AttributeList*)malloc(sizeof(AttributeList));
	new->listOfAttributes = NULL;
	new -> label = label;

	pInstruction* listaInstrucao = GetInstructionsList();

	while( (listaInstrucao[instructionsNumber] != NULL) && (instructionsNumber < 200)){
		instructionsNumber++;
	}

	if( instructionsNumber == 200){
		perror("Instruction List Full!\n");
		return 0;
	}

	listaInstrucao[ instructionsNumber] = (Instruction*)malloc(sizeof(Instruction));

	sprintf( listaInstrucao[ instructionsNumber] -> byteCode, "l%i:", label);

	listaInstrucao[ instructionsNumber] -> label = 0;
	listaInstrucao[ instructionsNumber] -> parameterAmount = 0;

	return new;
}

int AddIfToMainList( char byteCode[21], int label_1, int label_2, int currentLabel){
	int instructionsNumber = 0;

	pInstruction* listaInstrucao = GetInstructionsList();

	while( (listaInstrucao[instructionsNumber] != NULL) && (instructionsNumber < 200)){
		instructionsNumber++;
	}

	if( instructionsNumber == 200){
		perror("Instruction List Full!\n");
		return 0;
	}

	listaInstrucao[ instructionsNumber] = (Instruction*)malloc(sizeof(Instruction));
	listaInstrucao[ instructionsNumber] -> firstParameter = ( char*)malloc( sizeof( 5));

	strcpy( listaInstrucao[ instructionsNumber] -> byteCode, byteCode);
	sprintf( listaInstrucao[ instructionsNumber] -> firstParameter, "l%i", label_1);

	listaInstrucao[ instructionsNumber] -> label = currentLabel;
	listaInstrucao[ instructionsNumber] -> parameterAmount = 1;

	instructionsNumber++;
	if( instructionsNumber == 200){
		perror("Instruction List Full!\n");
		return 0;
	}

	listaInstrucao[ instructionsNumber] = (Instruction*)malloc(sizeof(Instruction));
	listaInstrucao[ instructionsNumber] -> firstParameter = ( char*)malloc( sizeof( 5));

	strcpy( listaInstrucao[ instructionsNumber] -> byteCode, GOTO);
	sprintf( listaInstrucao[ instructionsNumber] -> firstParameter, "l%i", label_2);

	listaInstrucao[ instructionsNumber] -> label = currentLabel;
	listaInstrucao[ instructionsNumber] -> parameterAmount = 1;

	return 1;
}

char* AddLiteralToMainList( pAttributeList literal){
	pLiteralList new = ( LiteralList*)malloc( sizeof( LiteralList));
	new -> literal = ( char*)malloc( sizeof( strlen( literal -> literal) + 1));
	strcpy( new -> literal, literal -> literal);
	new -> literal [ strlen( literal -> literal) + 1] = '\0';
	new -> ptrNext = NULL;
	pLiteralList aux = GetLiteralList();

	if( aux == NULL){
		ptrLiteralList = new;
		aux = GetLiteralList();
	} else{
		while( aux -> ptrNext != NULL)
			aux = (pLiteralList) aux -> ptrNext;
		aux -> ptrNext = new;
		aux = (pLiteralList) aux -> ptrNext;
	}

	free(literal);

	return aux -> literal;
}

void AddAtributeToMainList( pAttributeList newlista, int sePosVal, int type){ // addAttributesToMainList
	pAttributeList greatList = GetMainListPointer();

	if( newlista -> listOfAttributes == NULL){
		perror("Instruction List Full!\n");
		return;
	}

	pAttribute aux = newlista -> listOfAttributes;
	pAttribute auxGreat = greatList -> listOfAttributes;
	pAttribute auxDel;
	int valuePosition = 0;

	do{
		if( greatList -> listOfAttributes == NULL){
			if( IDExists( greatList, aux)){
				if(sePosVal != 1)
					valuePosition = -1;
				greatList -> listOfAttributes = CreateAttribute( aux -> nameID, valuePosition, type);
				auxGreat = greatList -> listOfAttributes;
				auxGreat -> ptrNext = NULL;
				valuePosition++;
				//printf("\tprimeiro simbolo da ptrMainList: %s %i\n", auxGreat->nameID, auxGreat -> valuePosition);
			}
		}else{

			while( auxGreat -> ptrNext != NULL){
				//printf("\tGreatList : %s\n", auxGreat->nameID);
				if( auxGreat -> valuePosition != -1){
					valuePosition++;
				}
				auxGreat = auxGreat -> ptrNext;
			}
			if( IDExists( greatList, aux)){
				if(sePosVal != 1)
					valuePosition = -1;
				/*else
					valuePosition++;*/
				if( auxGreat -> valuePosition != -1){
					valuePosition = auxGreat -> valuePosition +1;
				}
				auxGreat -> ptrNext = CreateAttribute( aux -> nameID, valuePosition, type);
				auxGreat = auxGreat -> ptrNext;
				//printf("\tnovo simbolo na ptrMainList: %s %i\n", auxGreat->nameID, auxGreat->valuePosition);
				valuePosition++;
			}
		}

		auxDel = aux;
		aux = aux -> ptrNext;
		free( auxDel);
	}while( aux != NULL);

	free(newlista);
}

void AddIDToMainList( pAttributeList listaFinal, pAttributeList listOfAttributes){
	pAttribute new = CreateAttribute( listOfAttributes -> tempIDName, 0, listOfAttributes -> tempType);
	if( listaFinal -> listOfAttributes == NULL){
		listaFinal -> listOfAttributes = new;
	}else{
		pAttribute aux = listaFinal -> listOfAttributes;
		while( aux -> ptrNext != NULL)
			aux = aux -> ptrNext;
		aux -> ptrNext = new;
	}
}
