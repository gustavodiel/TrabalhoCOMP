#include <stdio.h>

#include "expr.tab.c"

extern FILE *yyin;

int main()
{
	yyin = stdin;
	printf("Digite uma express�o:");
	yyparse();
	return 0;
}

