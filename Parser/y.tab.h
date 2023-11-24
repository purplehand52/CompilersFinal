/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    REGISTERS = 258,               /* REGISTERS  */
    QUANTUM = 259,                 /* QUANTUM  */
    CLASSICAL = 260,               /* CLASSICAL  */
    NUMBER = 261,                  /* NUMBER  */
    ITERS = 262,                   /* ITERS  */
    SET = 263,                     /* SET  */
    STATES = 264,                  /* STATES  */
    MAIN_BEGIN = 265,              /* MAIN_BEGIN  */
    MAIN_END = 266,                /* MAIN_END  */
    OUTPUT_BEGIN = 267,            /* OUTPUT_BEGIN  */
    OUTPUT_END = 268,              /* OUTPUT_END  */
    INIT_BEGIN = 269,              /* INIT_BEGIN  */
    INIT_END = 270,                /* INIT_END  */
    GATE = 271,                    /* GATE  */
    ID = 272,                      /* ID  */
    BLOCK = 273,                   /* BLOCK  */
    ARROW = 274,                   /* ARROW  */
    IN = 275,                      /* IN  */
    MEASURE = 276,                 /* MEASURE  */
    CONDITION = 277,               /* CONDITION  */
    OTHERWISE = 278,               /* OTHERWISE  */
    BARRIER = 279,                 /* BARRIER  */
    FOR = 280,                     /* FOR  */
    FOR_LEX = 281,                 /* FOR_LEX  */
    FOR_ZIP = 282,                 /* FOR_ZIP  */
    COMP = 283,                    /* COMP  */
    TRUE = 284,                    /* TRUE  */
    FALSE = 285,                   /* FALSE  */
    EQUALITY = 286,                /* EQUALITY  */
    AND = 287,                     /* AND  */
    OR = 288,                      /* OR  */
    WHILE = 289,                   /* WHILE  */
    ADD = 290,                     /* ADD  */
    SUB = 291,                     /* SUB  */
    DOT = 292,                     /* DOT  */
    STD_DEV = 293,                 /* STD_DEV  */
    VAR = 294,                     /* VAR  */
    AVG = 295,                     /* AVG  */
    CONDENSE = 296,                /* CONDENSE  */
    SUM = 297,                     /* SUM  */
    COUT = 298,                    /* COUT  */
    QOUT = 299,                    /* QOUT  */
    INT = 300,                     /* INT  */
    UINT = 301,                    /* UINT  */
    FLOAT = 302,                   /* FLOAT  */
    COMPLEX = 303,                 /* COMPLEX  */
    STRING = 304,                  /* STRING  */
    MATRIX = 305,                  /* MATRIX  */
    STATE = 306,                   /* STATE  */
    BOOL = 307,                    /* BOOL  */
    IMAG = 308,                    /* IMAG  */
    LIST = 309,                    /* LIST  */
    NEG = 310,                     /* NEG  */
    DEC = 311,                     /* DEC  */
    EXP = 312,                     /* EXP  */
    SAVE = 313,                    /* SAVE  */
    ECHO = 314,                    /* ECHO  */
    RETURN = 315                   /* RETURN  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define REGISTERS 258
#define QUANTUM 259
#define CLASSICAL 260
#define NUMBER 261
#define ITERS 262
#define SET 263
#define STATES 264
#define MAIN_BEGIN 265
#define MAIN_END 266
#define OUTPUT_BEGIN 267
#define OUTPUT_END 268
#define INIT_BEGIN 269
#define INIT_END 270
#define GATE 271
#define ID 272
#define BLOCK 273
#define ARROW 274
#define IN 275
#define MEASURE 276
#define CONDITION 277
#define OTHERWISE 278
#define BARRIER 279
#define FOR 280
#define FOR_LEX 281
#define FOR_ZIP 282
#define COMP 283
#define TRUE 284
#define FALSE 285
#define EQUALITY 286
#define AND 287
#define OR 288
#define WHILE 289
#define ADD 290
#define SUB 291
#define DOT 292
#define STD_DEV 293
#define VAR 294
#define AVG 295
#define CONDENSE 296
#define SUM 297
#define COUT 298
#define QOUT 299
#define INT 300
#define UINT 301
#define FLOAT 302
#define COMPLEX 303
#define STRING 304
#define MATRIX 305
#define STATE 306
#define BOOL 307
#define IMAG 308
#define LIST 309
#define NEG 310
#define DEC 311
#define EXP 312
#define SAVE 313
#define ECHO 314
#define RETURN 315

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
