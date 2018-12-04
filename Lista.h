//
// Created by Gustavo Diel on 27/11/18.
//

#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#include <stdlib.h>

#define ERRO_ALOCACAO -1
#define ERRO_LISTA_VAZIA -2
#define ERRO_POSICAO_INVALIDA -3
#define ERRO_ELEMENTO_NAO_ENCONTRADO -4

typedef struct elemento {
	void *info;
	struct elemento *proximo;
} Elemento;

typedef struct {
	size_t tamInfo;
	Elemento *cabeca;
} Lista;

void CleanList(Lista *l, size_t t);

void PrintList(Lista l, void (*mostra_info)(void *));

int InsertAtStart(Lista *l, void *info);

int InsertAtEnd(Lista *l, void *info);

int InsertAt(Lista *l, void *info, int pos);

int GetElement(Lista *l, void *info, int (*compara_info)(void *, void *));

int RemoveFromListStart(Lista *l, void *info);

int RemoveFromList(Lista *l, void *info);

int ChangePosition(Lista *l, void *info, int pos);

int GetPosition(Lista *l, void *info, int pos);

int ClearList(Lista *l);

int IsListEmpty(Lista *l);

int ElementExists(Lista *l, void *info, int (*compara_info)(void *, void *));

Elemento *CreateElementAllocation(size_t t, void *info);

#endif // LISTA_H_INCLUDED
