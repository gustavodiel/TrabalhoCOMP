//
// Created by Gustavo Diel on 2018-12-02.
//

#include "Initializers.h"

pAttribute CreateAttribute( char* nameID, int valuePosition, int type){
    pAttribute new = (Attribute*)malloc(sizeof(Attribute));
    strncpy(new->nameID, nameID, 20);
    new -> ptrNext = NULL;
    new -> valuePosition = valuePosition;
    new -> type = type;
    return new;
}

pAttributeList CreateType( int type){
    pAttributeList new = (AttributeList*)malloc(sizeof(AttributeList));
    new -> tempType = type;
    printf("New type created: %d\n", type);
    return new;
}

pAttributeList CreateList(){
    pAttributeList new = (AttributeList*)malloc(sizeof(AttributeList));
    new->listOfAttributes = NULL;
    new -> tempType = T_TODEF;
    return new;
}

pAttributeList CreateID( char *nameID){
    pAttributeList new = (AttributeList*)malloc(sizeof(AttributeList));
    new->listOfAttributes = NULL;
    strncpy(new->tempIDName, nameID, 20);
    printf("New ID created: %s\n", nameID);
    return new;
}

pAttributeList CreateNumeral( int num){
    pAttributeList new = (AttributeList*)malloc(sizeof(AttributeList));
    new->listOfAttributes = NULL;
    new->tempNumber =  num;
    printf("New Numeral created: %d\n", num);
    return new;
}

pAttributeList CreateLiteral(char* text){
    pAttributeList new = ( AttributeList*)malloc( sizeof(AttributeList));
    new -> listOfAttributes = NULL;
    new->literal = ( char*)malloc( sizeof(strlen(text)+1));
    strcpy( new -> literal, text);
    printf("New String created: %s\n", new->literal);
    return new;
}