//
// Created by Gustavo Diel on27/11/18.
//

#include <stdio.h>
#include <string.h>

extern FILE *yyin;
extern char className[200];

extern void StartCompiler();
void GenerateClassNameFromFile(char *nomeArquivo);

int main(int argc, char **argv) {
	StartCompiler();

	char filename[50];

	if (argc < 2) {
		printf("Nenhum arquivo especificado, por favor especifique um (Pode ser como \"./compilador ARQUIVO\".\n");
		scanf("%s", filename);
	} else {
		strcpy(filename, argv[1]);
	}

	printf("%s\n", filename);

	GenerateClassNameFromFile(filename);

	printf("%s\n", className);

	FILE *arq = fopen(filename, "r");
	if (arq == NULL) {
		perror("Erro ao abrir arquivo\n");
		return -1;
	}

	yyin = arq;
	yyparse();
	fclose(arq);
	return 0;
}

void GenerateClassNameFromFile(char *nomeArquivo) {
	int i = 0;
	while (nomeArquivo[i] != '.') {
		className[i] = nomeArquivo[i];
		i++;

		if (i == 199)
			break;
	}
	className[i] = '\0';
}