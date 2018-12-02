//
// Created by Gustavo Diel on 2018-12-02.
//

#include "Helpers.h"

#include "Globals.h"

#include "gram.h"

int IDExists( pAttributeList listOfAttributes, char* nameID){
    if( listOfAttributes -> listOfAttributes == NULL){
        return 1;
    }else{
        pAttribute aux = listOfAttributes -> listOfAttributes;
        do{
            if( strncmp( aux -> nameID, nameID, 20) == 0){
                return 0;
            }
            aux = aux -> ptrNext;
        }while( aux != NULL);
    }
    return 1;
}

char* SearchID( char* nameID){
    pAttributeList listOfAttributes = GetMainListPointer();
    if( listOfAttributes -> listOfAttributes == NULL){
        return INVAL;
    }else{
        pAttribute aux = listOfAttributes -> listOfAttributes;
        while( aux -> ptrNext != NULL){
            if( strncmp( aux -> nameID, nameID, 20) == 0)
                return INVAL;
            aux = aux -> ptrNext;
        }
        char* ret = (char*)malloc( sizeof( strlen( aux->nameID) + 1));
        strcpy( ret, aux->nameID);
        return ret;
    }
}

int GetPositionValue( char* nameID){
    pAttributeList listOfAttributes = GetMainListPointer();
    if( listOfAttributes -> listOfAttributes == NULL){
        return -1;
    }else{
        pAttribute aux = listOfAttributes -> listOfAttributes;
        while( aux != NULL){
            if( strncmp( aux -> nameID, nameID, 20) == 0){
                return aux -> valuePosition;
            }
            aux = aux -> ptrNext;
        }
        return -1;
    }
}

int GetType( char* nameID){
    pAttributeList listOfAttributes = GetMainListPointer();
    if( listOfAttributes -> listOfAttributes == NULL){
        return -1;
    }else{
        pAttribute aux = listOfAttributes -> listOfAttributes;
        while( aux != NULL){
            if( strncmp( aux -> nameID, nameID, 20) == 0){
                return aux -> type;
            }
            aux = aux -> ptrNext;
        }
        return -1;
    }
}

int CorrectLabel( pBooleanValue linhaInstrucao, int label){
    pInstruction* listaInstrucao = GetInstructionsList();
    if( linhaInstrucao != NULL){
        pBooleanValue aux = linhaInstrucao;

        do{
            if( listaInstrucao[ aux -> lineNumber] != NULL){
                sprintf( listaInstrucao[ aux -> lineNumber] -> firstParameter, "l%i", label);
            }else
                return 0;
            aux = aux -> ptrNext;
        }while(aux != NULL);
    }
    else
        return 0;
    return 1;
}

