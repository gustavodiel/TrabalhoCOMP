//
// Created by Gustavo Diel on 2018-12-02.
//

#ifndef TRABALHO_FINAL_INITIALIZERS_H
#define TRABALHO_FINAL_INITIALIZERS_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "Defines.h"
#include "Structs.h"

pAttributeList CreateMainList();

pAttribute CreateAttribute( char* nameID, int valuePosition, int type);

pAttributeList CreateList();
pAttributeList CreateType( int type);
pAttributeList CreateID( char* nameID);
pAttributeList CreateNumeral( int num);
pAttributeList CreateLiteral( char* literal);

#endif //TRABALHO_FINAL_INITIALIZERS_H
