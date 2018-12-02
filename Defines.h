//
// Created by Gustavo Diel on 2018-12-02.
//


#define T_GREAT_LIST 0
#define T_INT 1
#define T_STR 2
#define T_VOID 3
#define T_TODEF -1

#define AND 1
#define OR 2

#define INVAL "-1"

#define IADD "iadd"//0x60 	//adicao
#define ISUB "isub"//0x64	//subtracao
#define IMUL "imul"//0x68	//multiplicacao
#define IDIV "idiv"//0x6C	//divisao

#define INEG "ineg"//0x74	//multiplicar por -1

#define ISTORE "istore"//0x36	//armazena em memoria (ISTORE PAR1)
#define ILOAD "iload"//0x15	//carrega da memoria (ILOAD PAR1)

#define BIPUSH "bipush"//0x10	//adiciona valor na pilha (BIPUSH PAR1) (6 =< PAR1 =< 127)
#define LDC "ldc"//0x12	//adiciona valor na pilha (LDC PAR1) ( 127 < PAR1)

#define ICONST_0 "iconst_0"//0x03	//adiciona 0 na pilha
#define ICONST_1 "iconst_1"//0x04	//adiciona 1 na pilha
#define ICONST_2 "iconst_2"//0x05	//adiciona 2 na pilha
#define ICONST_3 "iconst_3"//0x06 	//adiciona 3 na pilha
#define ICONST_4 "iconst_4"//0x07	//adiciona 4 na pilha
#define ICONST_5 "iconst_5"//0x08	//adiciona 5 na pilha

#define IFEQ "if_icmpeq" 	// if( E == E)
#define IFDIF "if_icmpne" 	// if( E != E)
#define IFMAEQ "if_icmpge" 	// if( E >= E)
#define IFMA "if_icmpgt"		// if( E > E)
#define IFMEEQ "if_icmple" 	// if( E <= E)
#define IFME "if_icmplt"		// if( E < E)

#define GOTO "goto"

#define GETSTATIC "getstatic"//0xB2
#define INVOKEVIRTUAL "invokevirtual"//0xB6
#define SYSTEM_OUT "java/lang/System/out"
#define PRINTSTREAM "Ljava/io/PrintStream;"
#define PRINT_STR "java/io/PrintStream/println(Ljava/lang/String;)V"
#define PRINT_INT "java/io/PrintStream/println(I)V"
