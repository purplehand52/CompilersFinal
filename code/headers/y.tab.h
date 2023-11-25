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
     ID = 258,
     NUMBER = 259,
     ITERS = 260,
     NEG = 261,
     SET = 262,
     STATES = 263,
     REGISTERS = 264,
     QUANTUM = 265,
     CLASSICAL = 266,
     MAIN_BEGIN = 267,
     MAIN_END = 268,
     OUTPUT_BEGIN = 269,
     OUTPUT_END = 270,
     INIT_BEGIN = 271,
     INIT_END = 272,
     GATE = 273,
     BLOCK = 274,
     ARROW = 275,
     IN = 276,
     GATE_DEF = 277,
     MEASURE = 278,
     CONDITION = 279,
     OTHERWISE = 280,
     BARRIER = 281,
     FOR = 282,
     FOR_LEX = 283,
     FOR_ZIP = 284,
     COMP = 285,
     TRUE = 286,
     FALSE = 287,
     EQUALITY = 288,
     AND = 289,
     OR = 290,
     WHILE = 291,
     ADD = 292,
     SUB = 293,
     DOT = 294,
     STD_DEV = 295,
     VAR = 296,
     AVG = 297,
     CONDENSE = 298,
     SUM = 299,
     COUT = 300,
     INT = 301,
     UINT = 302,
     FLOAT = 303,
     COMPLEX = 304,
     STRING = 305,
     MATRIX = 306,
     STATE = 307,
     BOOL = 308,
     IMAG = 309,
     LIST = 310,
     DEC = 311,
     EXP = 312,
     SAVE = 313,
     ECHO = 314,
     RETURN = 315
   };
#endif
/* Tokens.  */
#define ID 258
#define NUMBER 259
#define ITERS 260
#define NEG 261
#define SET 262
#define STATES 263
#define REGISTERS 264
#define QUANTUM 265
#define CLASSICAL 266
#define MAIN_BEGIN 267
#define MAIN_END 268
#define OUTPUT_BEGIN 269
#define OUTPUT_END 270
#define INIT_BEGIN 271
#define INIT_END 272
#define GATE 273
#define BLOCK 274
#define ARROW 275
#define IN 276
#define GATE_DEF 277
#define MEASURE 278
#define CONDITION 279
#define OTHERWISE 280
#define BARRIER 281
#define FOR 282
#define FOR_LEX 283
#define FOR_ZIP 284
#define COMP 285
#define TRUE 286
#define FALSE 287
#define EQUALITY 288
#define AND 289
#define OR 290
#define WHILE 291
#define ADD 292
#define SUB 293
#define DOT 294
#define STD_DEV 295
#define VAR 296
#define AVG 297
#define CONDENSE 298
#define SUM 299
#define COUT 300
#define INT 301
#define UINT 302
#define FLOAT 303
#define COMPLEX 304
#define STRING 305
#define MATRIX 306
#define STATE 307
#define BOOL 308
#define IMAG 309
#define LIST 310
#define DEC 311
#define EXP 312
#define SAVE 313
#define ECHO 314
#define RETURN 315




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

