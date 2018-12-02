//
// Created by Gustavo Diel on 2018-12-02.
//

#include "Boolean.h"

pAttributeList ProcessBooleanNOT(pAttributeList listOfAttributes){
    pBooleanValue aux = listOfAttributes -> ptrFalse;
    listOfAttributes -> ptrFalse = listOfAttributes -> ptrTrue;
    listOfAttributes -> ptrTrue = aux;
    return listOfAttributes;
}

pAttributeList ProcessBooleanAND( pAttributeList firstValue, pAttributeList secondValue){
    pBooleanValue auxF, auxV, auxDel;

    auxV = secondValue -> ptrTrue;
    while( auxF -> ptrNext != NULL){
        auxDel = auxV;
        auxV -> ptrNext;
        free(auxDel);
    }
    free(auxV);

    secondValue -> ptrTrue = firstValue -> ptrTrue;

    auxF = secondValue -> ptrFalse;
    while( auxF -> ptrNext != NULL){
        auxF = auxF -> ptrNext;
    }
    auxF -> ptrNext = firstValue -> ptrFalse;

    free( firstValue);
    return secondValue;
}

pAttributeList ProcessBooleanOR( pAttributeList firstValue, pAttributeList secondValue){
    pBooleanValue auxV, auxF, auxDel;

    auxF = secondValue -> ptrFalse;
    while( auxF -> ptrNext != NULL){
        auxDel = auxF;
        auxF -> ptrNext;
        free(auxDel);
    }
    free(auxF);

    secondValue -> ptrFalse = firstValue -> ptrFalse;

    auxV = secondValue -> ptrTrue;
    while( auxV -> ptrNext != NULL){
        auxV = auxV -> ptrNext;
    }
    auxV -> ptrNext = firstValue -> ptrTrue;

    free( firstValue);
    return secondValue;
}

pAttributeList CreateBooleanList( char byteCode[21], int lineNumber){
    pBooleanValue aux, aux1;

    pAttributeList new = (AttributeList*)malloc(sizeof(AttributeList));
    new->listOfAttributes = NULL;
    new -> ptrTrue = (BooleanValue*)malloc(sizeof(BooleanValue));
    aux = new -> ptrTrue;
    aux -> ptrNext = NULL;
    aux -> lineNumber = lineNumber;

    new -> ptrFalse = (BooleanValue*)malloc(sizeof(BooleanValue));
    aux = new -> ptrFalse;
    aux -> ptrNext = NULL;
    aux-> lineNumber = lineNumber + 1;

    strcpy( new -> tempByteCode, byteCode);

    return new;
}