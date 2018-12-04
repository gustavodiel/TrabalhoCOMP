//
// Created by Gustavo Diel on 27/11/18.
//

#include "Main.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Lista tabelaSimbolos;
Lista listaInstrucoes;
Lista listaFuncoes;

unsigned VALUE_POSITION_AMOUNT = 0;
unsigned LABEL_AMOUNT = 0;
unsigned INSTRUCTION_AMOUNT = 0;
unsigned FUNCTION_AMOUNT = 0;
unsigned PARAMETER_AMOUNT = 0;

unsigned STACK_SIZE = 0;
unsigned BIGGEST_STACK_SIZE = 0;

char className[200];

void StartCompiler() {
	CleanList(&tabelaSimbolos, sizeof(struct Simbolo));
	CleanList(&listaInstrucoes, sizeof(struct Instrucao));
	CleanList(&listaFuncoes, sizeof(struct Funcao));

}

void AllocIDList(Lista *l) {
	CleanList(l, sizeof(char) * 32);
}

void AllocParameterList(Lista *l) {
	CleanList(l, sizeof(struct Parametro));
}

void CreateBooleanList(Lista *v, Lista *f) {
	CleanList(v, sizeof(unsigned));
	CleanList(f, sizeof(unsigned));

	unsigned proxPos = INSTRUCTION_AMOUNT + 1;
	InsertAtEnd(v, &INSTRUCTION_AMOUNT);
	InsertAtEnd(f, &proxPos);

}

void CreateBooleanListWIthoutInclude(Lista *v, Lista *f) {
	CleanList(v, sizeof(unsigned));
	CleanList(f, sizeof(unsigned));
}

void MoveBooleanList(Lista *v, Lista *f, Lista *v_old, Lista *f_old) {
	CleanList(v, sizeof(unsigned));
	CleanList(f, sizeof(unsigned));

	unsigned i;

	while (!IsListEmpty(v_old)) {
		RemoveFromList(v_old, &i);
		InsertAtStart(v, &i);
	}

	while (!IsListEmpty(f_old)) {
		RemoveFromList(f_old, &i);
		InsertAtStart(f, &i);
	}

}

void CreateSymbol(Lista *l, int tipo) {
	char info[32];
	while (!IsListEmpty(l)) {
		RemoveFromListStart(l, info);
		struct Simbolo s;
		strcpy(s.id, info);
		s.tipo = tipo;

		if (ElementExists(&tabelaSimbolos, &s, CompareSymbol)) {
			printf("ID %s ja existe na tabela de simbolos!\n", info);
			perror("Symbol already exists");
			exit(-1);
		}

		s.pos = VALUE_POSITION_AMOUNT++;

		InsertAtEnd(&tabelaSimbolos, &s);
	}
}

void CreateID(Lista *l, char id[32]) {
	InsertAtEnd(l, id);
}

void ShowTableSymbol() {
	printf("Tabela de Simbolos:\n");
	printf("%-3s %-6s %s\n", "POS", "TIPO", "ID");
	PrintList(tabelaSimbolos, ShowSymbol);
	printf("\n");
}

void ShowSymbol(void *info) {
	struct Simbolo *s = (struct Simbolo *) info;

	printf("%3d ", s->pos);

	if (s->tipo == TIPO_INT)
		printf("%6s", "INT");
	else if (s->tipo == TIPO_STRING)
		printf("%6s", "STRING");

	printf(" %s\n", s->id);
}

int CompareSymbol(void *a, void *b) {
	struct Simbolo *s1 = (struct Simbolo *) a;
	struct Simbolo *s2 = (struct Simbolo *) b;

	return strcmp(s1->id, s2->id);
}

int CompareFunction(void *a, void *b) {
	struct Funcao *f1 = (struct Funcao *) a;
	struct Funcao *f2 = (struct Funcao *) b;

	return strcmp(f1->id, f2->id);
}

void CreateFunctionWithParameter(Lista *lParam, unsigned tipoRetorno, char id[32]) {
	struct Funcao f;
	strcpy(f.id, id);
	f.tipoRetorno = tipoRetorno;
	f.pos = FUNCTION_AMOUNT;
	f.nParametros = PARAMETER_AMOUNT;

	if (GetElement(&listaFuncoes, &f, CompareFunction) != ERRO_ELEMENTO_NAO_ENCONTRADO) {
		printf("Funcao %s ja foi declarada em outro local!\n", id);
		exit(-1);
	}

	CleanList(&(f.listaParametros), sizeof(struct Parametro));

	while (!IsListEmpty(lParam)) {
		struct Parametro p;
		RemoveFromList(lParam, &p);
		InsertAtStart(&(f.listaParametros), &p);
	}

	InsertAtEnd(&listaFuncoes, &f);
	PARAMETER_AMOUNT = 0;
	FUNCTION_AMOUNT++;
}

void CreateFunctionWithoutParameter(unsigned tipoRetorno, char id[32]) {
	struct Funcao f;
	strcpy(f.id, id);
	f.tipoRetorno = tipoRetorno;
	f.pos = FUNCTION_AMOUNT;
	f.nParametros = PARAMETER_AMOUNT;
	f.nStack = BIGGEST_STACK_SIZE;

	if (GetElement(&listaFuncoes, &f, CompareFunction) != ERRO_ELEMENTO_NAO_ENCONTRADO) {
		printf("Funcao %s ja foi declarada!\n", id);
		exit(-1);
	}

	InsertAtEnd(&listaFuncoes, &f);
	PARAMETER_AMOUNT = 0;
	FUNCTION_AMOUNT++;
}

void CreateParameter(Lista *l, unsigned tipo, char id[32]) {
	struct Parametro p;
	p.tipo = tipo;
	p.pos = PARAMETER_AMOUNT;
	strcpy(p.id, id);
	InsertAtEnd(l, &p);
	PARAMETER_AMOUNT++;

	struct Simbolo s;
	strcpy(s.id, id);
	s.tipo = tipo;
	s.pos = VALUE_POSITION_AMOUNT;
	InsertAtEnd(&tabelaSimbolos, &s);
	VALUE_POSITION_AMOUNT++;
}

void AddSimpleParameter(Lista *l, unsigned tipo) {
	struct Parametro p;
	p.tipo = tipo;
	InsertAtEnd(l, &p);
}

void BeginFunction() {
	CreateInstruction(NULO, INST_DELIMITADORFUNC, NULO, NULO, NULO_STR);

	ClearList(&tabelaSimbolos);
}

void CreateInstruction(unsigned label, int inst, int p1, int p2, char str[256]) {
	struct Instrucao i;
	i.label = label;
	i.inst = inst;
	i.p1 = p1;
	i.p2 = p2;

	if (str[0] != '\0') {
		strcpy(i.literal, str);
	}

	InsertAtEnd(&listaInstrucoes, &i);

	INSTRUCTION_AMOUNT++;
}

void CreateAttribuition(char var[32], unsigned tipo1, unsigned tipo2) {
	DecreaseStack(1);

	if (tipo1 == tipo2) {
		if (tipo1 == TIPO_INT)
			CreateInstruction(NULO, INST_ISTORE, GetValuePosition(var), NULO, NULO_STR);
		else
			CreateInstruction(NULO, INST_ASTORE, GetValuePosition(var), NULO, NULO_STR);
	} else {
		printf("Atribuicao na variavel %s com tipos diferentes!\n", var);
		exit(-1);
	}
}

void CreateCompare(int comp, unsigned t1, unsigned t2) {
	if (t1 != TIPO_INT || t2 != TIPO_INT) {
		printf("Comparacao de variaveis com tipos incosistentes!\n");
		exit(-1);
	}

	DecreaseStack(2);

	switch (comp) {
		case CMP_EQUAL:
			CreateInstruction(NULO, INST_IF_ICMPEQ, NULO, NULO, NULO_STR);
			break;
		case CMP_NEQUAL:
			CreateInstruction(NULO, INST_IF_ICMPNE, NULO, NULO, NULO_STR);
			break;
		case CMP_LTHAN:
			CreateInstruction(NULO, INST_IF_ICMPLT, NULO, NULO, NULO_STR);
			break;
		case CMP_LEQUAL:
			CreateInstruction(NULO, INST_IF_ICMPLE, NULO, NULO, NULO_STR);
			break;
		case CMP_GTHAN:
			CreateInstruction(NULO, INST_IF_ICMPGT, NULO, NULO, NULO_STR);
			break;
		case CMP_GEQUAL:
			CreateInstruction(NULO, INST_IF_ICMPGE, NULO, NULO, NULO_STR);
			break;
		default:
			printf("Comparacao nao existente!\n");
			exit(-1);
	}

}

void CreateGOTO() {
	CreateInstruction(NULO, INST_GOTO, NULO, NULO, NULO_STR);
}

void CreateGOTOLabel(unsigned label) {
	CreateInstruction(label, INST_GOTO, NULO, NULO, NULO_STR);
}

void CreateOperation(int comp) {
	DecreaseStack(1);

	switch (comp) {
		case OP_ADD:
			CreateInstruction(NULO, INST_IADD, NULO, NULO, NULO_STR);
			break;
		case OP_SUB:
			CreateInstruction(NULO, INST_ISUB, NULO, NULO, NULO_STR);
			break;
		case OP_DIV:
			CreateInstruction(NULO, INST_IDIV, NULO, NULO, NULO_STR);
			break;
		case OP_MUL:
			CreateInstruction(NULO, INST_IMUL, NULO, NULO, NULO_STR);
			break;
		default:
			printf("Puts :x\n");
	}
}

void InsertStaticRead(int tipo, int pos) {
	IncreaseStack(3);

	CreateInstruction(NULO, INST_NEWSCANNER, NULO, NULO, NULO_STR);
	CreateInstruction(NULO, INST_DUP, NULO, NULO, NULO_STR);
	CreateInstruction(NULO, INST_GETINPUTSTREAM, NULO, NULO, NULO_STR);
	CreateInstruction(NULO, INST_INVOKEINPUTSTR, NULO, NULO, NULO_STR);
	if (tipo == TIPO_INT) {
		CreateInstruction(NULO, INST_NEXTINT, NULO, NULO, NULO_STR);
		CreateInstruction(NULO, INST_ISTORE, pos, NULO, NULO_STR);
	} else if (tipo == TIPO_STRING) {
		CreateInstruction(NULO, INST_NEXTLINE, NULO, NULO, NULO_STR);
		CreateInstruction(NULO, INST_ASTORE, pos, NULO, NULO_STR);
	}

	DecreaseStack(3);
}

void CreateFunctionWithoutParameters(char id[32]) {
	struct Funcao f;
	strcpy(f.id, id);
	if (GetElement(&listaFuncoes, &f, CompareFunction) == ERRO_ELEMENTO_NAO_ENCONTRADO) {
		printf("Funcao %s não declarada!\n", id);
		exit(-1);
	}

	if (f.nParametros != 0) {
		printf("Funcao %s chamada sem parametros!\n", id);
		exit(-1);
	}

	CreateInstruction(NULO, INST_INVOKESTATIC, f.pos, NULO, f.id);
}

void CreateFunctionWithParameters(char id[32], Lista *l) {
	struct Funcao f;
	strcpy(f.id, id);
	if (GetElement(&listaFuncoes, &f, CompareFunction) == ERRO_ELEMENTO_NAO_ENCONTRADO) {
		printf("Funcao %s não declarada!\n", id);
		exit(-1);
	}

	if (f.nParametros != 0) {
		int i = 0;
		for (i = 0; i < f.nParametros; i++) {
			struct Parametro p1, p2;
			GetPosition(&f.listaParametros, &p1, i);
			if (RemoveFromListStart(l, &p2) == ERRO_LISTA_VAZIA) {
				printf("Numero de parametros da funcao %s incosistente!\n", id);
				exit(-1);
			}
			if (p1.tipo != p2.tipo) {
				printf("Chamada de funcao %s com parametros de tipos diferentes!\n", id);
				exit(-1);
			}
		}
		if (!IsListEmpty(l)) {
			printf("Chamada de funcao %s com argumentos a mais que o correto!\n", id);
			exit(-1);
		}

	} else {
		printf("Funcao %s nao tem parametros mas esta sendo chamada com!\n", id);
		exit(-1);
	}

	CreateInstruction(NULO, INST_INVOKESTATIC, f.pos, NULO, f.id);
}

void CreateReturn(unsigned tipo) {
	if (tipo == TIPO_INT)
		CreateInstruction(NULO, INST_IRETURN, NULO, NULO, NULO_STR);
	else if (tipo == TIPO_STRING)
		CreateInstruction(NULO, INST_ARETURN, NULO, NULO, NULO_STR);
	else
		CreateInstruction(NULO, INST_RETURN, NULO, NULO, NULO_STR);
}

void GenerateIncrementFunction(char id[32], unsigned tipo, int n) {
	unsigned tipoID = GetType(id);

	if (tipoID == tipo) {
		unsigned posID = GetValuePosition(id);
		if (n == OP_IINC) {
			CreateInstruction(NULO, INST_IINC, posID, 1, NULO_STR);
		} else {
			CreateInstruction(NULO, INST_IADD, NULO, NULO, NULO_STR);
			CreateInstruction(NULO, INST_ISTORE, posID, NULO, NULO_STR);
		}
	} else {
		printf("Tentando incrementar %s com tipos diferentes!\n", id);
	}
}

void GenerateDecrementFunction(char id[32], unsigned tipo, int n) {
	unsigned tipoID = GetType(id);

	if (tipoID == tipo) {
		unsigned posID = GetValuePosition(id);
		if (n == OP_IINC) {
			CreateInstruction(NULO, INST_IINC, posID, -1, NULO_STR);
		} else {
			CreateInstruction(NULO, INST_ISUB, NULO, NULO, NULO_STR);
			CreateInstruction(NULO, INST_ISTORE, posID, NULO, NULO_STR);
		}
	} else {
		printf("Tentando incrementar %s com tipos diferentes!\n", id);
	}
}

void InsertInteger(int num) {
	IncreaseStack(1);

	int inst, p1;
	p1 = NULO;

	if (num >= 0 && num <= 5) {
		switch (num) {
			case 0:
				inst = INST_ICONST0;
				break;
			case 1:
				inst = INST_ICONST1;
				break;
			case 2:
				inst = INST_ICONST2;
				break;
			case 3:
				inst = INST_ICONST3;
				break;
			case 4:
				inst = INST_ICONST4;
				break;
			case 5:
				inst = INST_ICONST5;
				break;
		}
	} else if (num >= -127 && num <= 127) {
		p1 = num;
		inst = INST_BIPUSH;
	} else {
		inst = INST_LDC;
		p1 = num;
	}

	CreateInstruction(NULO, inst, p1, NULO, NULO_STR);
}

void CreateLiteral(char str[256]) {
	IncreaseStack(1);

	CreateInstruction(NULO, INST_LDCSTRING, NULO, NULO, str);
}

void CorrectLabel(Lista *l, int label) {
	unsigned u;

	while (!IsListEmpty(l)) {
		RemoveFromListStart(l, &u);
		struct Instrucao i;
		GetPosition(&listaInstrucoes, &i, u);
		i.label = label;
		ChangePosition(&listaInstrucoes, &i, u);
	}
}

void CorrectMainIDs() {
	VALUE_POSITION_AMOUNT++;
}

void CreateFunctionBody() {
	struct Funcao f;
	GetPosition(&listaFuncoes, &f, FUNCTION_AMOUNT - 1);
	f.nStack = BIGGEST_STACK_SIZE;
	f.nLocals = VALUE_POSITION_AMOUNT;
	ChangePosition(&listaFuncoes, &f, FUNCTION_AMOUNT - 1);
	VALUE_POSITION_AMOUNT = 0;
	BIGGEST_STACK_SIZE = 0;
	STACK_SIZE = 0;
}

void ProcessBooleanOperation(Lista *l_dest, Lista *l1, Lista *l2) {
	unsigned u;
	while (!IsListEmpty(l1)) {
		RemoveFromListStart(l1, &u);
		InsertAtEnd(l_dest, &u);
	}

	while (!IsListEmpty(l2)) {
		RemoveFromListStart(l2, &u);
		InsertAtEnd(l_dest, &u);
	}
}

void ProcessBooleanOperation2(Lista *l_dest, Lista *l1) {
	unsigned u;
	while (!IsListEmpty(l1)) {
		RemoveFromListStart(l1, &u);
		InsertAtEnd(l_dest, &u);
	}
}

int CreateLabel() {
	LABEL_AMOUNT++;
	CreateInstruction(LABEL_AMOUNT, INST_NEWLABEL, NULO, NULO, NULO_STR);
	return LABEL_AMOUNT;
}

void InsertIntegerVariable(char id[32]) {
	IncreaseStack(1);

	int pos = GetValuePosition(id);

	CreateInstruction(NULO, INST_ILOAD, pos, NULO, NULO_STR);
}

void InsertStringVariable(char id[32]) {
	IncreaseStack(1);

	int pos = GetValuePosition(id);

	CreateInstruction(NULO, INST_ALOAD, pos, NULO, NULO_STR);
}

void GetStaticPrint() {
	IncreaseStack(1);

	CreateInstruction(NULO, INST_GETPRINT, NULO, NULO, NULO_STR);
}

void CallStaticMethod(int TIPO) {
	DecreaseStack(2);

	if (TIPO == TIPO_INT)
		CreateInstruction(NULO, INST_INVOKEPRINT_INT, NULO, NULO, NULO_STR);
	else if (TIPO == TIPO_STRING)
		CreateInstruction(NULO, INST_INVOKEPRINT_STR, NULO, NULO, NULO_STR);
}


unsigned GetType(char id[32]) {
	struct Simbolo s;
	strcpy(s.id, id);

	if (GetElement(&tabelaSimbolos, &s, CompareSymbol) == ERRO_ELEMENTO_NAO_ENCONTRADO) {
		printf("Variavel \"%s\" nao foi declarada!\n", id);
		exit(-1);
	}

	return s.tipo;
}

unsigned GetValuePosition(char id[32]) {
	struct Simbolo s;
	strcpy(s.id, id);

	if (GetElement(&tabelaSimbolos, &s, CompareSymbol) == ERRO_ELEMENTO_NAO_ENCONTRADO) {
		printf("Variavel \"%s\" nao foi declarada!\n", id);
		exit(-1);
	}

	return s.pos;
}

unsigned GetFunctionType(char id[32]) {
	struct Funcao f;
	strcpy(f.id, id);

	if (GetElement(&listaFuncoes, &f, CompareSymbol) == ERRO_ELEMENTO_NAO_ENCONTRADO) {
		printf("Funcao \"%s\" nao foi declarada!\n", id);
		exit(-1);
	}

	return f.tipoRetorno;
}

void GenerateBytecode() {
	struct Instrucao i;

	char nomeArquivoFinal[250];
	strcpy(nomeArquivoFinal, className);
	strcat(nomeArquivoFinal, ".jout");
	FILE *fp = fopen(nomeArquivoFinal, "w");

	int estouMain = 0;
	int sairInstrucoes = 0;
	int contadorFuncao = 0;

	fprintf(fp, ".class public %s\n"
	            ".super java/lang/Object\n\n"
	            ".method public <init>()V\n"
	            "\taload_0\n\n"
	            "\tinvokenonvirtual java/lang/Object/<init>()V\n"
	            "\treturn\n"
	            ".end method\n\n", className);

	while (!estouMain) {
		struct Funcao f;
		if (contadorFuncao == FUNCTION_AMOUNT) {
			fprintf(fp, ".method public static main([Ljava/lang/String;)V\n");
			estouMain = 1;
		} else {
			GetPosition(&listaFuncoes, &f, contadorFuncao);
			contadorFuncao++;
			fprintf(fp, ".method public static %s(", f.id);
			struct Parametro p;
			int contAux;
			for (contAux = 0; contAux < f.nParametros; contAux++) {
				GetPosition(&(f.listaParametros), &p, contAux);
				if (p.tipo == TIPO_INT)
					fprintf(fp, "I");
				else if (p.tipo == TIPO_STRING)
					fprintf(fp, "Ljava/lang/String;");
				else if (p.tipo == TIPO_VOID)
					fprintf(fp, "V");
			}
			fprintf(fp, ")");
			if (f.tipoRetorno == TIPO_INT)
				fprintf(fp, "I");
			else if (f.tipoRetorno == TIPO_STRING)
				fprintf(fp, "Ljava/lang/String;");
			else if (f.tipoRetorno == TIPO_VOID)
				fprintf(fp, "V");
			fprintf(fp, "\n");
		}

		if (estouMain) {
			fprintf(fp, "\t.limit stack %d\n", BIGGEST_STACK_SIZE);
			fprintf(fp, "\t.limit locals %d\n", VALUE_POSITION_AMOUNT);
		} else {
			fprintf(fp, "\t.limit stack %d\n", f.nStack);
			fprintf(fp, "\t.limit locals %d\n", f.nLocals);
		}


		while (!IsListEmpty(&listaInstrucoes)) {
			RemoveFromListStart(&listaInstrucoes, &i);

			switch (i.inst) {

				case INST_IDIV:
					fprintf(fp, "\tidiv\n");
					break;
				case INST_IMUL:
					fprintf(fp, "\timul\n");
					break;
				case INST_IADD:
					fprintf(fp, "\tiadd\n");
					break;
				case INST_ISUB:
					fprintf(fp, "\tisub\n");
					break;
				case INST_ICONST0:
					fprintf(fp, "\ticonst_0\n");
					break;
				case INST_ICONST1:
					fprintf(fp, "\ticonst_1\n");
					break;
				case INST_ICONST2:
					fprintf(fp, "\ticonst_2\n");
					break;
				case INST_ICONST3:
					fprintf(fp, "\ticonst_3\n");
					break;
				case INST_ICONST4:
					fprintf(fp, "\ticonst_4\n");
					break;
				case INST_ICONST5:
					fprintf(fp, "\ticonst_5\n");
					break;
				case INST_BIPUSH:
					fprintf(fp, "\tbipush %d\n", i.p1);
					break;
				case INST_ILOAD:
					fprintf(fp, "\tiload %d\n", i.p1);
					break;
				case INST_ISTORE:
					fprintf(fp, "\tistore %d\n", i.p1);
					break;
				case INST_GETPRINT:
					fprintf(fp, "\tgetstatic java/lang/System/out Ljava/io/PrintStream;\n");
					break;
				case INST_INVOKEPRINT_INT:
					fprintf(fp, "\tinvokevirtual java/io/PrintStream/println(I)V\n");
					break;
				case INST_INVOKEPRINT_STR:
					fprintf(fp, "\tinvokevirtual java/io/PrintStream/println(Ljava/lang/String;)V\n");
					break;
				case INST_IF_ICMPEQ:
					fprintf(fp, "\tif_icmpeq l%u\n", i.label);
					break;
				case INST_IF_ICMPNE:
					fprintf(fp, "\tif_icmpne l%u\n", i.label);
					break;
				case INST_IF_ICMPLT:
					fprintf(fp, "\tif_icmplt l%u\n", i.label);
					break;
				case INST_IF_ICMPLE:
					fprintf(fp, "\tif_icmple l%u\n", i.label);
					break;
				case INST_IF_ICMPGT:
					fprintf(fp, "\tif_icmpgt l%u\n", i.label);
					break;
				case INST_IF_ICMPGE:
					fprintf(fp, "\tif_icmpge l%u\n", i.label);
					break;
				case INST_GOTO:
					fprintf(fp, "\tgoto l%u\n", i.label);
					break;
				case INST_NEWLABEL:
					fprintf(fp, "l%u:\n", i.label);
					break;
				case INST_LDC:
					fprintf(fp, "\tldc %d\n", i.p1);
					break;
				case INST_DUP:
					fprintf(fp, "\tdup\n");
					break;
				case INST_NEWSCANNER:
					fprintf(fp, "\tnew java/util/Scanner\n");
					break;
				case INST_GETINPUTSTREAM:
					fprintf(fp, "\tgetstatic java/lang/System/in Ljava/io/InputStream;\n");
					break;
				case INST_INVOKEINPUTSTR:
					fprintf(fp, "\tinvokespecial java/util/Scanner/<init>(Ljava/io/InputStream;)V\n");
					break;
				case INST_NEXTINT:
					fprintf(fp, "\tinvokevirtual java/util/Scanner/nextInt()I\n");
					break;
				case INST_LDCSTRING:
					fprintf(fp, "\tldc %s\n", i.literal);
					break;
				case INST_ASTORE:
					fprintf(fp, "\tastore %d\n", i.p1);
					break;
				case INST_ALOAD:
					fprintf(fp, "\taload %d\n", i.p1);
					break;
				case INST_NEXTLINE:
					fprintf(fp, "\tinvokevirtual java/util/Scanner/nextLine()Ljava/lang/String;\n");
					break;
				case INST_DELIMITADORFUNC:
					sairInstrucoes = 1;
					break;
				case INST_INVOKESTATIC:
					fprintf(fp, "\tinvokestatic %s/%s(", className, i.literal);
					struct Funcao f;
					GetPosition(&listaFuncoes, &f, i.p1);
					int cont = 0;
					for (cont = 0; cont < f.nParametros; cont++) {
						struct Parametro p;
						GetPosition(&(f.listaParametros), &p, cont);
						if (p.tipo == TIPO_INT)
							fprintf(fp, "I");
						else if (p.tipo == TIPO_STRING)
							fprintf(fp, "V");
					}
					fprintf(fp, ")");
					if (f.tipoRetorno == TIPO_INT)
						fprintf(fp, "I");
					else if (f.tipoRetorno == TIPO_STRING)
						fprintf(fp, "Ljava/lang/String;");
					else if (f.tipoRetorno == TIPO_VOID)
						fprintf(fp, "V");
					fprintf(fp, "\n");
					break;
				case INST_IRETURN:
					fprintf(fp, "\tireturn\n");
					break;
				case INST_ARETURN:
					fprintf(fp, "\tareturn\n");
					break;
				case INST_RETURN:
					fprintf(fp, "\treturn\n");
					break;
				case INST_IINC:
					fprintf(fp, "\tiinc %u %d\n", i.p1, i.p2);
					break;

				default:
					printf("[ERROR] Instrução não definida: %d!\n", i.inst);
					perror("ERROR!");
					break;
			}
			if (sairInstrucoes) {
				sairInstrucoes = 0;
				break;
			}
		}

		fprintf(fp, "\treturn\n");
		fprintf(fp, ".end method\n\n");
	}
	fclose(fp);
}

void error() {
	perror("Erro!");
	exit(-1);
}

void IncreaseStack(int i) {
	STACK_SIZE += i;
	if (STACK_SIZE > BIGGEST_STACK_SIZE)
		BIGGEST_STACK_SIZE = STACK_SIZE;
}

void DecreaseStack(int i) {
	if (STACK_SIZE == 0) {
		printf("TENTOU REDUZIR %d\n", i);
		perror("Tried to reduce Stack of 0!");
		exit(-1);
	}
	STACK_SIZE -= i;
}