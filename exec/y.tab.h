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

#ifndef YY_YY_EXEC_Y_TAB_H_INCLUDED
# define YY_YY_EXEC_Y_TAB_H_INCLUDED
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
    ID = 258,                      /* ID  */
    NUMBER = 259,                  /* NUMBER  */
    ITERS = 260,                   /* ITERS  */
    NEG = 261,                     /* NEG  */
    SET = 262,                     /* SET  */
    STATES = 263,                  /* STATES  */
    REGISTERS = 264,               /* REGISTERS  */
    QUANTUM = 265,                 /* QUANTUM  */
    CLASSICAL = 266,               /* CLASSICAL  */
    MAIN_BEGIN = 267,              /* MAIN_BEGIN  */
    MAIN_END = 268,                /* MAIN_END  */
    OUTPUT_BEGIN = 269,            /* OUTPUT_BEGIN  */
    OUTPUT_END = 270,              /* OUTPUT_END  */
    INIT_BEGIN = 271,              /* INIT_BEGIN  */
    INIT_END = 272,                /* INIT_END  */
    GATE = 273,                    /* GATE  */
    BLOCK = 274,                   /* BLOCK  */
    ARROW = 275,                   /* ARROW  */
    IN = 276,                      /* IN  */
    MEASURE = 277,                 /* MEASURE  */
    CONDITION = 278,               /* CONDITION  */
    OTHERWISE = 279,               /* OTHERWISE  */
    BARRIER = 280,                 /* BARRIER  */
    FOR = 281,                     /* FOR  */
    FOR_LEX = 282,                 /* FOR_LEX  */
    FOR_ZIP = 283,                 /* FOR_ZIP  */
    COMP = 284,                    /* COMP  */
    TRUE = 285,                    /* TRUE  */
    FALSE = 286,                   /* FALSE  */
    EQUALITY = 287,                /* EQUALITY  */
    AND = 288,                     /* AND  */
    OR = 289,                      /* OR  */
    WHILE = 290,                   /* WHILE  */
    ADD = 291,                     /* ADD  */
    SUB = 292,                     /* SUB  */
    DOT = 293,                     /* DOT  */
    STD_DEV = 294,                 /* STD_DEV  */
    VAR = 295,                     /* VAR  */
    AVG = 296,                     /* AVG  */
    CONDENSE = 297,                /* CONDENSE  */
    SUM = 298,                     /* SUM  */
    COUT = 299,                    /* COUT  */
    QOUT = 300,                    /* QOUT  */
    INT = 301,                     /* INT  */
    UINT = 302,                    /* UINT  */
    FLOAT = 303,                   /* FLOAT  */
    COMPLEX = 304,                 /* COMPLEX  */
    STRING = 305,                  /* STRING  */
    MATRIX = 306,                  /* MATRIX  */
    STATE = 307,                   /* STATE  */
    BOOL = 308,                    /* BOOL  */
    IMAG = 309,                    /* IMAG  */
    LIST = 310,                    /* LIST  */
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
#define MEASURE 277
#define CONDITION 278
#define OTHERWISE 279
#define BARRIER 280
#define FOR 281
#define FOR_LEX 282
#define FOR_ZIP 283
#define COMP 284
#define TRUE 285
#define FALSE 286
#define EQUALITY 287
#define AND 288
#define OR 289
#define WHILE 290
#define ADD 291
#define SUB 292
#define DOT 293
#define STD_DEV 294
#define VAR 295
#define AVG 296
#define CONDENSE 297
#define SUM 298
#define COUT 299
#define QOUT 300
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

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_EXEC_Y_TAB_H_INCLUDED  */
