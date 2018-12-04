//
// Created by Gustavo Diel on 01/12/18.
//

#include "Lista.h"

#include <stdio.h>

void CleanList(Lista *l, size_t t) {
	l->tamInfo = t;
	l->cabeca = NULL;
}

int IsListEmpty(Lista *l) {
	return l->cabeca == NULL;
}

void PrintList(Lista l, void (*mostra_info)(void *)) {
	Elemento *aux = l.cabeca;
	if (aux == NULL)
		return;

	while (aux != NULL) {
		mostra_info(aux->info);
		aux = aux->proximo;
	}
	printf("\n");
}

int ClearList(Lista *l) {
	Elemento *aux = l->cabeca;
	if (aux == NULL)
		return 1;

	while (aux != NULL) {
		if (aux->proximo == NULL) {
			l->cabeca = NULL;
			free(aux->info);
			free(aux);
			return 1;
		}

		while (aux->proximo->proximo != NULL) {
			aux = aux->proximo;
		}

		free(aux->proximo->info);
		free(aux->proximo);

		aux->proximo = NULL;
		aux = l->cabeca;
	}
	return 1;
}