//
// Created by Gustavo Diel on 2018-12-02.
//

#ifndef TRABALHO_FINAL_STRUCTS_H
#define TRABALHO_FINAL_STRUCTS_H

typedef struct
{
    char nameID[21];
    int valuePosition;
    struct Attribute* ptrNext;
    int type;
} Attribute, *pAttribute;

typedef struct
{
    char functionName[21];
    int finalPosition;
    int returnType;
    int *parameters;
    struct Function *ptrNext;
} Function, *pFunction;

typedef struct
{
    int lineNumber;
    struct BooleanValue* ptrNext;
} BooleanValue, *pBooleanValue;

typedef struct
{
    char tempIDName[21];
    int tempNumber;
    char* literal;
    int tempType;

    pBooleanValue ptrTrue;
    pBooleanValue ptrFalse;

    int label;

    char tempByteCode[21];

    pAttribute listOfAttributes;
} AttributeList, *pAttributeList;

typedef struct
{
    int label;
    int parameterAmount;
    char byteCode[21];
    char* firstParameter;
    char* secondParameter;
} Instruction, *pInstruction;

typedef struct
{
    char* literal;
    struct LiteralList* ptrNext;
} LiteralList, *pLiteralList;

#endif //TRABALHO_FINAL_STRUCTS_H
