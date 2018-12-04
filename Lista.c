//
// Created by Gustavo Diel on 27/11/18.
//

#include "Lista.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int InsertAtStart(Lista *l, void *info) {
	Elemento *p = CreateElementAllocation(l->tamInfo, info);
	p->proximo = l->cabeca;
	l->cabeca = p;

	return 1;
}

int RemoveFromListStart(Lista *l, void *info) {
	if (l->cabeca == NULL) {
		return ERRO_LISTA_VAZIA;
	}

	Elemento *p = l->cabeca;
	l->cabeca = p->proximo;
	memcpy(info, p->info, l->tamInfo);
	free(p->info);
	free(p);

	return 1;
}

int InsertAtEnd(Lista *l, void *info) {
	if (l->cabeca == NULL) {
		return InsertAtStart(l, info);
	}

	Elemento *aux = l->cabeca;
	while (aux->proximo != NULL) {
		aux = aux->proximo;
	}

	Elemento *p = CreateElementAllocation(l->tamInfo, info);
	p->proximo = NULL;
	aux->proximo = p;

	return 1;
}

int RemoveFromList(Lista *l, void *info) {
	if (l->cabeca == NULL)
		return ERRO_LISTA_VAZIA;

	if (l->cabeca->proximo == NULL)
		return RemoveFromListStart(l, info);

	Elemento *aux = l->cabeca;
	while (aux->proximo->proximo != NULL) {
		aux = aux->proximo;
	}

	memcpy(info, aux->proximo->info, l->tamInfo);
	free(aux->proximo->info);
	free(aux->proximo);
	aux->proximo = NULL;

	return 1;
}

int ChangePosition(Lista *l, void *info, int pos) {
	if (pos < 0)
		return ERRO_POSICAO_INVALIDA;

	Elemento *aux = l->cabeca;
	int cont = 0;
	while (cont != pos && aux->proximo != NULL) {
		aux = aux->proximo;
		cont++;
	}

	if (cont != pos)
		return ERRO_POSICAO_INVALIDA;

	memcpy(aux->info, info, l->tamInfo);

	return 1;
}

int GetPosition(Lista *l, void *info, int pos) {
	if (pos < 0)
		return ERRO_POSICAO_INVALIDA;

	Elemento *aux = l->cabeca;
	int cont = 0;
	while (cont != pos && aux->proximo != NULL) {
		aux = aux->proximo;
		cont++;
	}

	if (cont != pos)
		return ERRO_POSICAO_INVALIDA;

	memcpy(info, aux->info, l->tamInfo);

	return 1;
}

Elemento *CreateElementAllocation(size_t t, void *info) {
	Elemento *p;
	p = (Elemento *) malloc(sizeof(Elemento));

	if (p == NULL)
		return NULL;

	p->info = malloc(t);
	if (p->info == NULL) {
		free(p);
		return NULL;
	}

	memcpy(p->info, info, t);

	return p;
}

int ElementExists(Lista *l, void *info, int (*compara_info)(void *, void *)) {
	Elemento *aux = l->cabeca;
	if (aux == NULL)
		return 0;

	while (aux != NULL) {
		if (compara_info(aux->info, info) == 0) {
			return 1;
		}
		aux = aux->proximo;
	}

	return 0;
}

int GetElement(Lista *l, void *info, int (*compara_info)(void *, void *)) {
	Elemento *aux = l->cabeca;
	if (aux == NULL)
		return ERRO_ELEMENTO_NAO_ENCONTRADO;

	while (aux != NULL) {
		if (compara_info(info, aux->info) == 0) {
			memcpy(info, aux->info, l->tamInfo);
			return 1;
		}
		aux = aux->proximo;
	}

	return ERRO_ELEMENTO_NAO_ENCONTRADO;
}
