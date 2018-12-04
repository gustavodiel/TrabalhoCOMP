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
     TSTRING = 258,
     TVOID = 259,
     TINT = 260,
     TRETURN = 261,
     TPRINT = 262,
     TREAD = 263,
     TIF = 264,
     TWHILE = 265,
     TELSE = 266,
     TMEIGUAL = 267,
     TMAIGUAL = 268,
     TIGUAL = 269,
     TDIFER = 270,
     TATRIB = 271,
     TMAIOR = 272,
     TMENOR = 273,
     TACHAVE = 274,
     TFCHAVE = 275,
     TADD = 276,
     TSUB = 277,
     TMUL = 278,
     TDIV = 279,
     TAPAR = 280,
     TFPAR = 281,
     TFIM = 282,
     TNUM = 283,
     TVIRG = 284,
     TPVIRG = 285,
     TID = 286,
     TLITERAL = 287,
     TNOT = 288,
     TAND = 289,
     TOR = 290,
     TERROR = 291,
     EOP = 292,
     TINC = 293,
     TDEC = 294,
     TINC_N = 295,
     TDEC_N = 296
   };
#endif
/* Tokens.  */
#define TSTRING 258
#define TVOID 259
#define TINT 260
#define TRETURN 261
#define TPRINT 262
#define TREAD 263
#define TIF 264
#define TWHILE 265
#define TELSE 266
#define TMEIGUAL 267
#define TMAIGUAL 268
#define TIGUAL 269
#define TDIFER 270
#define TATRIB 271
#define TMAIOR 272
#define TMENOR 273
#define TACHAVE 274
#define TFCHAVE 275
#define TADD 276
#define TSUB 277
#define TMUL 278
#define TDIV 279
#define TAPAR 280
#define TFPAR 281
#define TFIM 282
#define TNUM 283
#define TVIRG 284
#define TPVIRG 285
#define TID 286
#define TLITERAL 287
#define TNOT 288
#define TAND 289
#define TOR 290
#define TERROR 291
#define EOP 292
#define TINC 293
#define TDEC 294
#define TINC_N 295
#define TDEC_N 296




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

