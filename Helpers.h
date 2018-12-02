//
// Created by Gustavo Diel on 2018-12-02.
//

#ifndef TRABALHO_FINAL_HERLPERS_H
#define TRABALHO_FINAL_HERLPERS_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "Defines.h"
#include "Structs.h"

int IDExists( pAttributeList listOfAttributes, char* nameID);
char* SearchID( char* nameID);
int GetPositionValue( char* nameID);
int GetType( char* nameID);
int CorrectLabel( pBooleanValue linhaInstrucao, int label);

#endif //TRABALHO_FINAL_HERLPERS_H
