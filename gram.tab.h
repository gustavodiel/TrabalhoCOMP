/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     TOKEN_ID = 258,
     TOKEN_INT = 259,
     TOKEN_STRING = 260,
     TOKEN_VOID = 261,
     TOKEN_MAIS = 262,
     TOKEN_MAIS_MAIS = 263,
     TOKEN_MENOS = 264,
     TOKEN_MENOS_MENOS = 265,
     TOKEN_MULT = 266,
     TOKEN_DIV = 267,
     TOKEN_IGUAL = 268,
     TOKEN_MAIOR_IGUAL = 269,
     TOKEN_MENOR_IGUAL = 270,
     TOKEN_MAIOR = 271,
     TOKEN_MENOR = 272,
     TOKEN_DIFERENTE = 273,
     TOKEN_NEGACAO = 274,
     TOKEN_E = 275,
     TOKEN_OU = 276,
     TOKEN_NUM_REAL = 277,
     TOKEN_TEXTO = 278,
     TOKEN_IF = 279,
     TOKEN_ELSE = 280,
     TOKEN_WHILE = 281,
     TOKEN_READ = 282,
     TOKEN_PRINT = 283,
     TOKEN_ATRIBUICAO = 284,
     TOKEN_FECHA_PAR = 285,
     TOKEN_ABRE_PAR = 286,
     TOKEN_VIRGULA = 287,
     TOKEN_ABRE_CHAVES = 288,
     TOKEN_FECHA_CHAVES = 289,
     TOKEN_RETURN = 290,
     TOKEN_PONTO_VIRGULA = 291,
     TFIM = 292,
     TOKEN_MAIS_IGUAL = 293
   };
#endif
/* Tokens.  */
#define TOKEN_ID 258
#define TOKEN_INT 259
#define TOKEN_STRING 260
#define TOKEN_VOID 261
#define TOKEN_MAIS 262
#define TOKEN_MAIS_MAIS 263
#define TOKEN_MENOS 264
#define TOKEN_MENOS_MENOS 265
#define TOKEN_MULT 266
#define TOKEN_DIV 267
#define TOKEN_IGUAL 268
#define TOKEN_MAIOR_IGUAL 269
#define TOKEN_MENOR_IGUAL 270
#define TOKEN_MAIOR 271
#define TOKEN_MENOR 272
#define TOKEN_DIFERENTE 273
#define TOKEN_NEGACAO 274
#define TOKEN_E 275
#define TOKEN_OU 276
#define TOKEN_NUM_REAL 277
#define TOKEN_TEXTO 278
#define TOKEN_IF 279
#define TOKEN_ELSE 280
#define TOKEN_WHILE 281
#define TOKEN_READ 282
#define TOKEN_PRINT 283
#define TOKEN_ATRIBUICAO 284
#define TOKEN_FECHA_PAR 285
#define TOKEN_ABRE_PAR 286
#define TOKEN_VIRGULA 287
#define TOKEN_ABRE_CHAVES 288
#define TOKEN_FECHA_CHAVES 289
#define TOKEN_RETURN 290
#define TOKEN_PONTO_VIRGULA 291
#define TFIM 292
#define TOKEN_MAIS_IGUAL 293




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

