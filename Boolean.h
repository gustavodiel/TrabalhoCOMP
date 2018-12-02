//
// Created by Gustavo Diel on 2018-12-02.
//

#ifndef TRABALHO_FINAL_BOOLEAN_H
#define TRABALHO_FINAL_BOOLEAN_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "Defines.h"
#include "Structs.h"

pAttributeList ProcessBooleanNOT(pAttributeList listOfAttributes);
pAttributeList ProcessBooleanAND( pAttributeList firstValue, pAttributeList secondValue);
pAttributeList ProcessBooleanOR( pAttributeList firstValue, pAttributeList secondValue);

pAttributeList CreateBooleanList( char byteCode[21], int lineNumber);

#endif //TRABALHO_FINAL_BOOLEAN_H
