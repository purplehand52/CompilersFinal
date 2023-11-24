/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser_main.y"

   #include<stdio.h>
   #include<stdlib.h>
   extern FILE* yyin,*fp2;

   int yylex();
   void yyerror();

#line 80 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
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
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_REGISTERS = 3,                  /* REGISTERS  */
  YYSYMBOL_QUANTUM = 4,                    /* QUANTUM  */
  YYSYMBOL_CLASSICAL = 5,                  /* CLASSICAL  */
  YYSYMBOL_NUMBER = 6,                     /* NUMBER  */
  YYSYMBOL_ITERS = 7,                      /* ITERS  */
  YYSYMBOL_SET = 8,                        /* SET  */
  YYSYMBOL_STATES = 9,                     /* STATES  */
  YYSYMBOL_MAIN_BEGIN = 10,                /* MAIN_BEGIN  */
  YYSYMBOL_MAIN_END = 11,                  /* MAIN_END  */
  YYSYMBOL_OUTPUT_BEGIN = 12,              /* OUTPUT_BEGIN  */
  YYSYMBOL_OUTPUT_END = 13,                /* OUTPUT_END  */
  YYSYMBOL_INIT_BEGIN = 14,                /* INIT_BEGIN  */
  YYSYMBOL_INIT_END = 15,                  /* INIT_END  */
  YYSYMBOL_GATE = 16,                      /* GATE  */
  YYSYMBOL_ID = 17,                        /* ID  */
  YYSYMBOL_BLOCK = 18,                     /* BLOCK  */
  YYSYMBOL_ARROW = 19,                     /* ARROW  */
  YYSYMBOL_IN = 20,                        /* IN  */
  YYSYMBOL_MEASURE = 21,                   /* MEASURE  */
  YYSYMBOL_CONDITION = 22,                 /* CONDITION  */
  YYSYMBOL_OTHERWISE = 23,                 /* OTHERWISE  */
  YYSYMBOL_BARRIER = 24,                   /* BARRIER  */
  YYSYMBOL_FOR = 25,                       /* FOR  */
  YYSYMBOL_FOR_LEX = 26,                   /* FOR_LEX  */
  YYSYMBOL_FOR_ZIP = 27,                   /* FOR_ZIP  */
  YYSYMBOL_COMP = 28,                      /* COMP  */
  YYSYMBOL_TRUE = 29,                      /* TRUE  */
  YYSYMBOL_FALSE = 30,                     /* FALSE  */
  YYSYMBOL_EQUALITY = 31,                  /* EQUALITY  */
  YYSYMBOL_AND = 32,                       /* AND  */
  YYSYMBOL_OR = 33,                        /* OR  */
  YYSYMBOL_WHILE = 34,                     /* WHILE  */
  YYSYMBOL_ADD = 35,                       /* ADD  */
  YYSYMBOL_SUB = 36,                       /* SUB  */
  YYSYMBOL_DOT = 37,                       /* DOT  */
  YYSYMBOL_STD_DEV = 38,                   /* STD_DEV  */
  YYSYMBOL_VAR = 39,                       /* VAR  */
  YYSYMBOL_AVG = 40,                       /* AVG  */
  YYSYMBOL_CONDENSE = 41,                  /* CONDENSE  */
  YYSYMBOL_SUM = 42,                       /* SUM  */
  YYSYMBOL_COUT = 43,                      /* COUT  */
  YYSYMBOL_QOUT = 44,                      /* QOUT  */
  YYSYMBOL_INT = 45,                       /* INT  */
  YYSYMBOL_UINT = 46,                      /* UINT  */
  YYSYMBOL_FLOAT = 47,                     /* FLOAT  */
  YYSYMBOL_COMPLEX = 48,                   /* COMPLEX  */
  YYSYMBOL_STRING = 49,                    /* STRING  */
  YYSYMBOL_MATRIX = 50,                    /* MATRIX  */
  YYSYMBOL_STATE = 51,                     /* STATE  */
  YYSYMBOL_BOOL = 52,                      /* BOOL  */
  YYSYMBOL_IMAG = 53,                      /* IMAG  */
  YYSYMBOL_LIST = 54,                      /* LIST  */
  YYSYMBOL_NEG = 55,                       /* NEG  */
  YYSYMBOL_DEC = 56,                       /* DEC  */
  YYSYMBOL_EXP = 57,                       /* EXP  */
  YYSYMBOL_SAVE = 58,                      /* SAVE  */
  YYSYMBOL_ECHO = 59,                      /* ECHO  */
  YYSYMBOL_RETURN = 60,                    /* RETURN  */
  YYSYMBOL_61_ = 61,                       /* '+'  */
  YYSYMBOL_62_ = 62,                       /* '-'  */
  YYSYMBOL_63_ = 63,                       /* '*'  */
  YYSYMBOL_64_ = 64,                       /* '/'  */
  YYSYMBOL_65_ = 65,                       /* '%'  */
  YYSYMBOL_66_ = 66,                       /* '@'  */
  YYSYMBOL_67_ = 67,                       /* '&'  */
  YYSYMBOL_68_ = 68,                       /* '^'  */
  YYSYMBOL_69_ = 69,                       /* '|'  */
  YYSYMBOL_70_ = 70,                       /* '!'  */
  YYSYMBOL_71_ = 71,                       /* '\\'  */
  YYSYMBOL_72_ = 72,                       /* '#'  */
  YYSYMBOL_73_ = 73,                       /* '='  */
  YYSYMBOL_74_ = 74,                       /* ','  */
  YYSYMBOL_75_ = 75,                       /* '('  */
  YYSYMBOL_76_ = 76,                       /* ')'  */
  YYSYMBOL_77_ = 77,                       /* '['  */
  YYSYMBOL_78_ = 78,                       /* ']'  */
  YYSYMBOL_79_ = 79,                       /* '{'  */
  YYSYMBOL_80_ = 80,                       /* '}'  */
  YYSYMBOL_81_ = 81,                       /* '?'  */
  YYSYMBOL_82_ = 82,                       /* ':'  */
  YYSYMBOL_YYACCEPT = 83,                  /* $accept  */
  YYSYMBOL_prgm = 84,                      /* prgm  */
  YYSYMBOL_init_section = 85,              /* init_section  */
  YYSYMBOL_main_section = 86,              /* main_section  */
  YYSYMBOL_output_section = 87,            /* output_section  */
  YYSYMBOL_mandatory_init = 88,            /* mandatory_init  */
  YYSYMBOL_set_states = 89,                /* set_states  */
  YYSYMBOL_set_quantum_states = 90,        /* set_quantum_states  */
  YYSYMBOL_set_classical_states = 91,      /* set_classical_states  */
  YYSYMBOL_quantum_state_list = 92,        /* quantum_state_list  */
  YYSYMBOL_classical_state_list = 93,      /* classical_state_list  */
  YYSYMBOL_quantum_state = 94,             /* quantum_state  */
  YYSYMBOL_classical_state = 95,           /* classical_state  */
  YYSYMBOL_gate_defn_section = 96,         /* gate_defn_section  */
  YYSYMBOL_gate_defn_list = 97,            /* gate_defn_list  */
  YYSYMBOL_gate_defn = 98,                 /* gate_defn  */
  YYSYMBOL_rhs = 99,                       /* rhs  */
  YYSYMBOL_tuple_list = 100,               /* tuple_list  */
  YYSYMBOL_tuple_list2 = 101,              /* tuple_list2  */
  YYSYMBOL_id_list = 102,                  /* id_list  */
  YYSYMBOL_variable = 103,                 /* variable  */
  YYSYMBOL_var = 104,                      /* var  */
  YYSYMBOL_block_defns_list = 105,         /* block_defns_list  */
  YYSYMBOL_block_defn = 106,               /* block_defn  */
  YYSYMBOL_params = 107,                   /* params  */
  YYSYMBOL_param_id_list = 108,            /* param_id_list  */
  YYSYMBOL_target_params = 109,            /* target_params  */
  YYSYMBOL_target_param_list = 110,        /* target_param_list  */
  YYSYMBOL_block_body = 111,               /* block_body  */
  YYSYMBOL_block_id = 112,                 /* block_id  */
  YYSYMBOL_main_stmt_list = 113,           /* main_stmt_list  */
  YYSYMBOL_main_stmt = 114,                /* main_stmt  */
  YYSYMBOL_stmts = 115,                    /* stmts  */
  YYSYMBOL_register = 116,                 /* register  */
  YYSYMBOL_call_stmt = 117,                /* call_stmt  */
  YYSYMBOL_parameters = 118,               /* parameters  */
  YYSYMBOL_optional = 119,                 /* optional  */
  YYSYMBOL_register_list = 120,            /* register_list  */
  YYSYMBOL_classic_control = 121,          /* classic_control  */
  YYSYMBOL_quantum_control = 122,          /* quantum_control  */
  YYSYMBOL_target = 123,                   /* target  */
  YYSYMBOL_measure_stmt = 124,             /* measure_stmt  */
  YYSYMBOL_barrier_stmt = 125,             /* barrier_stmt  */
  YYSYMBOL_condition_stmt = 126,           /* condition_stmt  */
  YYSYMBOL_otherwise_list = 127,           /* otherwise_list  */
  YYSYMBOL_otherwise_final = 128,          /* otherwise_final  */
  YYSYMBOL_arithmetic_expr = 129,          /* arithmetic_expr  */
  YYSYMBOL_expr = 130,                     /* expr  */
  YYSYMBOL_value = 131,                    /* value  */
  YYSYMBOL_range = 132,                    /* range  */
  YYSYMBOL_range_list = 133,               /* range_list  */
  YYSYMBOL_var_list = 134,                 /* var_list  */
  YYSYMBOL_for_stmt = 135,                 /* for_stmt  */
  YYSYMBOL_for_lex_stmt = 136,             /* for_lex_stmt  */
  YYSYMBOL_for_zip_stmt = 137,             /* for_zip_stmt  */
  YYSYMBOL_while_stmt = 138,               /* while_stmt  */
  YYSYMBOL_out_id = 139,                   /* out_id  */
  YYSYMBOL_prim_type = 140,                /* prim_type  */
  YYSYMBOL_list_type = 141,                /* list_type  */
  YYSYMBOL_bool_const = 142,               /* bool_const  */
  YYSYMBOL_uint_const = 143,               /* uint_const  */
  YYSYMBOL_nint_const = 144,               /* nint_const  */
  YYSYMBOL_float_const = 145,              /* float_const  */
  YYSYMBOL_complex_const = 146,            /* complex_const  */
  YYSYMBOL_string_const = 147,             /* string_const  */
  YYSYMBOL_matrix_const = 148,             /* matrix_const  */
  YYSYMBOL_row_list = 149,                 /* row_list  */
  YYSYMBOL_row = 150,                      /* row  */
  YYSYMBOL_comps = 151,                    /* comps  */
  YYSYMBOL_state_const = 152,              /* state_const  */
  YYSYMBOL_prim_const = 153,               /* prim_const  */
  YYSYMBOL_vec_const = 154,                /* vec_const  */
  YYSYMBOL_vec_list = 155,                 /* vec_list  */
  YYSYMBOL_calls = 156,                    /* calls  */
  YYSYMBOL_var2 = 157,                     /* var2  */
  YYSYMBOL_uint_list = 158,                /* uint_list  */
  YYSYMBOL_out_rhs = 159,                  /* out_rhs  */
  YYSYMBOL_out_expr = 160,                 /* out_expr  */
  YYSYMBOL_decl = 161,                     /* decl  */
  YYSYMBOL_echo_stmt = 162,                /* echo_stmt  */
  YYSYMBOL_echo_list = 163,                /* echo_list  */
  YYSYMBOL_save_stmt = 164,                /* save_stmt  */
  YYSYMBOL_out_control = 165,              /* out_control  */
  YYSYMBOL_out_cond_stmt = 166,            /* out_cond_stmt  */
  YYSYMBOL_out_other_list = 167,           /* out_other_list  */
  YYSYMBOL_out_other_final = 168,          /* out_other_final  */
  YYSYMBOL_out_for_stmt = 169,             /* out_for_stmt  */
  YYSYMBOL_out_for_lex_stmt = 170,         /* out_for_lex_stmt  */
  YYSYMBOL_out_for_zip_stmt = 171,         /* out_for_zip_stmt  */
  YYSYMBOL_out_while_stmt = 172,           /* out_while_stmt  */
  YYSYMBOL_out_main = 173,                 /* out_main  */
  YYSYMBOL_out_stmt = 174                  /* out_stmt  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1008

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  83
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  92
/* YYNRULES -- Number of rules.  */
#define YYNRULES  221
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  535

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   315


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    70,     2,    72,     2,    65,    67,     2,
      75,    76,    63,    61,    74,    62,     2,    64,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    82,     2,
       2,    73,     2,    81,    66,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    77,    71,    78,    68,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    79,    69,    80,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    38,    38,    42,    45,    46,    49,    50,    58,    62,
      63,    64,    65,    66,    69,    72,    75,    76,    79,    80,
      83,    86,    90,    91,    94,    95,    98,   101,   102,   104,
     105,   107,   108,   110,   111,   113,   114,   116,   117,   118,
     119,   121,   122,   125,   128,   129,   132,   133,   136,   137,
     138,   141,   142,   145,   146,   149,   157,   158,   161,   162,
     164,   165,   166,   167,   168,   169,   170,   173,   174,   179,
     180,   181,   182,   185,   186,   189,   190,   193,   194,   197,
     198,   201,   202,   203,   206,   207,   221,   224,   227,   230,
     231,   234,   235,   238,   239,   240,   241,   242,   243,   244,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   261,   262,   265,   266,   269,   270,   273,   274,   277,
     280,   283,   286,   295,   295,   295,   297,   298,   299,   300,
     301,   302,   303,   304,   307,   314,   315,   318,   321,   325,
     326,   329,   334,   337,   340,   341,   344,   347,   348,   351,
     354,   355,   356,   357,   358,   359,   360,   361,   364,   367,
     368,   372,   373,   374,   375,   376,   377,   378,   379,   380,
     384,   385,   388,   389,   393,   394,   395,   396,   397,   398,
     399,   400,   401,   402,   403,   404,   405,   406,   407,   408,
     409,   410,   411,   415,   417,   418,   419,   423,   426,   427,
     431,   435,   436,   437,   438,   439,   442,   445,   446,   449,
     450,   453,   456,   459,   462,   467,   468,   471,   472,   473,
     474,   475
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "REGISTERS", "QUANTUM",
  "CLASSICAL", "NUMBER", "ITERS", "SET", "STATES", "MAIN_BEGIN",
  "MAIN_END", "OUTPUT_BEGIN", "OUTPUT_END", "INIT_BEGIN", "INIT_END",
  "GATE", "ID", "BLOCK", "ARROW", "IN", "MEASURE", "CONDITION",
  "OTHERWISE", "BARRIER", "FOR", "FOR_LEX", "FOR_ZIP", "COMP", "TRUE",
  "FALSE", "EQUALITY", "AND", "OR", "WHILE", "ADD", "SUB", "DOT",
  "STD_DEV", "VAR", "AVG", "CONDENSE", "SUM", "COUT", "QOUT", "INT",
  "UINT", "FLOAT", "COMPLEX", "STRING", "MATRIX", "STATE", "BOOL", "IMAG",
  "LIST", "NEG", "DEC", "EXP", "SAVE", "ECHO", "RETURN", "'+'", "'-'",
  "'*'", "'/'", "'%'", "'@'", "'&'", "'^'", "'|'", "'!'", "'\\\\'", "'#'",
  "'='", "','", "'('", "')'", "'['", "']'", "'{'", "'}'", "'?'", "':'",
  "$accept", "prgm", "init_section", "main_section", "output_section",
  "mandatory_init", "set_states", "set_quantum_states",
  "set_classical_states", "quantum_state_list", "classical_state_list",
  "quantum_state", "classical_state", "gate_defn_section",
  "gate_defn_list", "gate_defn", "rhs", "tuple_list", "tuple_list2",
  "id_list", "variable", "var", "block_defns_list", "block_defn", "params",
  "param_id_list", "target_params", "target_param_list", "block_body",
  "block_id", "main_stmt_list", "main_stmt", "stmts", "register",
  "call_stmt", "parameters", "optional", "register_list",
  "classic_control", "quantum_control", "target", "measure_stmt",
  "barrier_stmt", "condition_stmt", "otherwise_list", "otherwise_final",
  "arithmetic_expr", "expr", "value", "range", "range_list", "var_list",
  "for_stmt", "for_lex_stmt", "for_zip_stmt", "while_stmt", "out_id",
  "prim_type", "list_type", "bool_const", "uint_const", "nint_const",
  "float_const", "complex_const", "string_const", "matrix_const",
  "row_list", "row", "comps", "state_const", "prim_const", "vec_const",
  "vec_list", "calls", "var2", "uint_list", "out_rhs", "out_expr", "decl",
  "echo_stmt", "echo_list", "save_stmt", "out_control", "out_cond_stmt",
  "out_other_list", "out_other_final", "out_for_stmt", "out_for_lex_stmt",
  "out_for_zip_stmt", "out_while_stmt", "out_main", "out_stmt", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-393)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-69)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -42,    22,    60,    -1,    58,  -393,    84,    77,   196,   163,
     334,   215,  -393,   226,   232,  -393,   181,   194,  -393,   192,
     216,   206,   243,   307,   252,   255,   258,    29,    35,    28,
     377,  -393,  -393,   253,  -393,   155,  -393,  -393,  -393,  -393,
    -393,  -393,  -393,   751,   265,    81,    47,   335,  -393,   340,
    -393,    62,   330,    35,    44,   332,   341,   341,    44,  -393,
    -393,  -393,  -393,   146,    35,  -393,   338,    40,  -393,  -393,
     192,  -393,    28,   280,   291,   346,   292,   300,   301,  -393,
    -393,  -393,  -393,  -393,  -393,  -393,  -393,   310,   317,    19,
     362,   380,  -393,  -393,  -393,  -393,  -393,  -393,  -393,  -393,
    -393,  -393,   787,  -393,   390,   392,   399,   397,   402,   356,
     412,  -393,  -393,   441,   447,    35,  -393,    35,   453,  -393,
    -393,  -393,  -393,    44,   398,   176,   400,  -393,   203,   230,
     353,    35,   393,   249,    63,  -393,  -393,   458,   338,   401,
     401,   434,   341,   341,    44,   742,   401,  -393,   432,  -393,
     409,    31,  -393,   413,   471,   472,   422,    13,   484,  -393,
     288,  -393,    35,   858,    61,    61,    61,    61,    61,    44,
      44,    44,    44,    44,    44,    44,   407,   158,   479,   485,
     493,   425,  -393,  -393,  -393,    35,  -393,  -393,    35,  -393,
    -393,  -393,  -393,  -393,   439,   448,   459,   460,   461,   462,
     464,   465,  -393,  -393,  -393,  -393,  -393,  -393,   401,   401,
     445,   466,   454,  -393,  -393,  -393,  -393,  -393,  -393,  -393,
    -393,  -393,  -393,   939,   834,   468,   296,   297,   918,   476,
     939,   304,  -393,   536,  -393,   552,   491,   553,   235,  -393,
     550,   549,  -393,  -393,  -393,  -393,   238,   238,  -393,  -393,
    -393,   357,   169,   557,  -393,   239,   178,   217,   467,  -393,
    -393,   509,   516,  -393,   520,   524,   467,   336,  -393,     6,
       6,     6,     6,     6,     6,     6,     6,   251,   526,   852,
     466,   -16,  -393,   122,   527,   596,   401,   401,   401,   401,
     401,   401,   401,   401,   401,   401,   401,   401,   525,   158,
     583,   587,   529,  -393,   401,  -393,    27,  -393,  -393,   604,
     605,   538,  -393,  -393,   540,  -393,   533,   551,  -393,  -393,
     339,    18,   554,   603,    21,   158,   556,   158,   158,   171,
    -393,  -393,  -393,   562,   563,   564,   567,   569,   570,   565,
     574,   122,  -393,  -393,    33,   445,  -393,   526,   466,   584,
     496,   193,   595,  -393,   616,   616,   114,   114,   684,   263,
     260,   251,   823,   588,   592,   597,   823,   939,  -393,    54,
     590,   566,   491,   553,   200,    66,   200,    89,   654,  -393,
    -393,   656,   481,  -393,   593,   467,  -393,   358,   373,  -393,
       6,     6,     6,  -393,  -393,  -393,    25,  -393,   598,   466,
    -393,  -393,   601,   599,   628,   499,   619,   158,   158,   535,
      27,  -393,   693,   694,  -393,  -393,  -393,  -393,  -393,  -393,
     159,    92,  -393,  -393,   626,  -393,   379,   632,  -393,  -393,
    -393,   435,   630,   481,   686,   158,   207,   158,   631,   639,
     635,   644,   645,   596,   646,  -393,  -393,  -393,   596,  -393,
     823,   436,   443,  -393,  -393,   647,   658,   661,   200,  -393,
     200,  -393,   200,   719,  -393,  -393,  -393,   110,  -393,  -393,
    -393,  -393,   467,   467,  -393,  -393,  -393,  -393,   444,  -393,
     665,   716,   571,   666,   667,   737,  -393,   159,  -393,   117,
     456,  -393,    44,   467,   242,   264,   596,   671,  -393,   137,
    -393,  -393,   823,   823,   675,   678,  -393,  -393,   928,   294,
    -393,  -393,  -393,  -393,   401,   823,   607,   643,   749,  -393,
     677,  -393,   876,   679,  -393,  -393,  -393,   467,   691,  -393,
     320,   823,  -393,   715,  -393
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     1,     0,     0,     0,    13,
       0,     0,     2,     0,     0,    42,    11,    12,    67,    81,
      55,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    57,    58,     0,    60,     0,    61,    59,    62,    63,
      64,    65,    66,     0,     0,     0,    23,     0,     9,     0,
      10,     0,     0,     0,     0,     0,     0,     0,     0,     5,
      87,    68,    78,     0,     0,    73,    75,     0,    56,    79,
      81,    55,     0,     0,     0,     0,     0,     0,     0,   126,
     127,   128,   129,   130,   131,   132,   133,     0,     0,     0,
       0,     0,   220,   221,   219,   218,   217,   201,   202,   203,
     204,   205,     0,   216,     0,     0,     0,     0,     0,     0,
      22,    25,    41,     0,     0,     0,    82,     0,     0,    99,
      98,   109,   110,     0,   108,     0,     0,   118,     0,     0,
       0,     0,     0,     0,     0,    72,     4,     0,    75,     0,
       0,     0,     0,     0,     0,     0,     0,     7,     0,   194,
       0,     0,   215,     0,     0,     0,     0,     0,     0,    24,
       0,    71,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    77,    80,    74,     0,    84,    76,     0,    70,
     137,   123,   135,   136,     0,     0,     0,     0,     0,     0,
       0,     0,   124,   125,   142,   138,   139,   140,     0,     0,
       0,     0,   175,   150,   151,   152,   153,   154,   155,   156,
     157,   174,   178,   193,     0,     0,     0,     0,     0,     0,
     199,     0,   200,     0,     6,     0,     0,     0,     0,    44,
       0,    48,     3,    83,    86,   107,    93,    94,    95,    96,
      97,   100,   101,   102,   103,   105,   104,   106,     0,   111,
     112,     0,     0,   117,     0,     0,     0,     0,    69,     0,
       0,     0,     0,     0,     0,     0,     0,   180,   153,     0,
       0,     0,   145,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   134,     0,   197,     0,   195,   196,     0,
       0,    14,    17,    21,    15,    19,     0,     0,    26,    47,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      85,   170,   171,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   179,   148,     0,     0,   143,     0,     0,     0,
     183,   184,   181,   182,   187,   188,   185,   186,   189,   190,
     191,   192,     0,     0,     0,     0,     0,   198,   160,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    45,
      49,     0,    53,    90,   113,     0,   116,     0,     0,   122,
       0,     0,     0,   164,   165,   169,     0,   168,     0,     0,
     146,   144,     0,   176,     0,     0,     0,     0,     0,     0,
       0,   158,     0,     0,    16,    18,    37,    38,    39,    40,
       0,     0,    34,    35,     0,    27,     0,     0,    28,    46,
      52,     0,     0,    53,    92,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   141,   147,   149,     0,   208,
       0,     0,     0,   214,   159,     0,     0,     0,     0,    30,
       0,    32,     0,     0,    50,    43,    54,     0,    88,   114,
     119,   115,     0,     0,   161,   162,   163,   173,     0,   166,
       0,   210,     0,     0,     0,     0,    20,     0,    33,     0,
       0,    51,     0,     0,     0,     0,     0,     0,   177,     0,
     206,   211,     0,     0,     0,     0,    29,    31,     0,     0,
     120,   121,   172,   167,     0,     0,     0,     0,     0,    36,
       0,    91,     0,     0,   212,   213,     8,     0,     0,   209,
       0,     0,    89,     0,   207
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -393,  -393,  -393,  -393,  -393,  -393,  -393,   740,   755,  -393,
    -393,   386,   406,  -393,  -393,   662,  -393,  -393,  -393,  -352,
     322,  -392,  -393,  -393,  -393,  -393,  -393,  -393,   342,    -9,
    -254,   -30,  -328,    69,  -393,   709,   668,   -56,  -393,   712,
    -393,  -393,  -393,  -393,  -393,  -393,   302,   -57,  -312,  -172,
    -317,   -18,  -393,  -393,  -393,  -393,  -393,   638,  -393,  -393,
    -275,  -393,  -202,  -205,  -393,  -393,  -393,   463,  -393,  -393,
    -284,  -393,  -393,   578,  -256,  -393,  -137,   717,  -393,  -393,
    -393,  -393,  -393,  -393,  -393,  -393,  -393,  -393,  -393,  -393,
    -341,  -100
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     2,     3,     7,    12,     9,    15,    16,    17,   311,
     314,   312,   315,   109,   110,   111,   318,   375,   377,   421,
     422,   423,    46,   112,   241,   320,   322,   431,   432,    29,
      30,    31,    32,    33,    34,    66,   135,    63,    35,    52,
     187,    36,    37,    38,   434,   468,   124,   125,   261,   386,
     387,   128,    39,    40,    41,    42,   212,    90,    91,   213,
     214,   215,   216,   217,   218,   219,   281,   282,   344,   220,
     221,   307,   369,   222,   333,   478,   223,    92,    93,    94,
     231,    95,    96,    97,   481,   500,    98,    99,   100,   101,
     102,   103
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      68,   130,   152,   224,   324,   262,   284,   278,   133,   230,
     349,   388,   329,   384,   334,   335,   336,   337,   338,   339,
     340,   405,   368,   331,   426,   409,    72,    18,   457,     1,
     239,   190,   147,   190,    18,   380,     4,    19,    20,   129,
      59,    18,    21,    22,   234,    61,    23,    24,    25,   332,
     119,   136,    61,    60,   433,    26,   192,   193,   345,   160,
       5,   120,   346,   107,    60,   108,   163,   119,    18,    18,
       6,   277,   279,   121,   122,   343,   204,   148,   120,    61,
      61,   347,   205,   206,   207,   105,   106,   228,   240,   148,
     451,   452,   323,   381,    10,   505,    28,    62,    65,   157,
     443,   383,   283,    64,   210,   433,   211,   399,   489,   482,
     490,   400,   251,   252,   253,   254,   255,   256,   257,   123,
     116,   444,   118,   469,   226,   227,   454,   363,   410,   267,
       8,   436,   411,    62,   440,   441,   442,   115,   185,   398,
     424,    65,   286,   402,   425,   287,   288,   289,    11,   350,
     351,   352,   353,   354,   355,   356,   357,   358,   359,   360,
     361,   516,   517,   427,   259,   416,   458,   367,   477,   428,
     459,    70,    71,   480,   523,   260,   417,    18,   206,   207,
     294,   295,   296,   297,    62,   492,   161,    19,    20,   493,
     533,   458,    21,    22,   446,   506,    23,    24,    25,    13,
     182,   171,   172,   186,   169,    26,   416,   170,   171,   172,
     171,   172,   514,    18,   418,   419,   515,   417,   494,   495,
     131,   512,   132,    19,    20,   288,   289,    43,    21,    22,
      44,   244,    23,    24,    25,    14,   173,   174,   175,   509,
      45,    26,   323,   173,   174,   175,    28,   175,    18,   171,
     172,   389,   176,    47,    62,   418,   419,   268,    19,    20,
     295,   296,   297,    21,    22,   471,    49,    23,    24,    25,
      18,   171,   172,   530,    51,   420,    26,   178,   323,   179,
      19,    20,    28,   288,   289,    21,    22,   470,    53,    23,
      24,    25,   288,   289,    68,   288,   289,   -68,    26,    68,
      18,   166,   167,   168,   178,   152,   180,   174,   175,   152,
      19,    20,   316,   323,   317,    21,    22,    28,    54,    23,
      24,    25,   510,   131,    55,   184,    18,    56,    26,   297,
      57,   296,   297,    58,    69,   323,    19,    20,   104,    28,
      18,    21,    22,   113,   511,    23,    24,    25,   114,   117,
      19,    20,   126,   139,    26,    21,    22,   134,   127,    23,
      24,    25,   131,   141,   243,   323,   140,   142,    26,    28,
     178,   178,   300,   301,   521,   143,   144,   522,   304,    73,
     305,   169,   152,    18,   170,   171,   172,   145,   170,   171,
     172,   323,   146,    19,    20,    28,   153,   150,    21,    22,
     532,   154,    23,    24,    25,    27,    68,   190,   155,    28,
     131,    26,   330,   378,   156,   379,   152,   152,   191,    71,
     173,   174,   175,   152,   173,   174,   175,   158,   107,   181,
     192,   193,   437,   152,   438,   508,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   106,   437,    67,   439,
     204,   105,    28,   458,   225,   461,   205,   206,   207,   164,
     165,   166,   167,   168,    68,    68,   246,   247,   248,   249,
     250,   208,   162,    18,   183,   177,   209,   188,   210,    68,
     211,   232,   233,    19,    20,   235,   258,    18,    21,    22,
     236,   237,    23,    24,    25,   238,   263,    19,    20,   242,
      68,    26,    21,    22,   266,   264,    23,    24,    25,   463,
     437,   464,   483,   265,   269,    26,    73,   437,   496,   484,
     497,    74,   280,   270,    75,    76,    77,   287,   288,   289,
     458,   285,   507,    78,   271,   272,   273,   274,   323,   275,
     276,   283,    28,   299,    79,    80,    81,    82,    83,    84,
      85,    86,    73,    87,   303,   309,    28,    74,    88,   313,
      75,    76,    77,   295,   296,   297,   310,   319,   321,    78,
     404,   194,   195,   196,   197,   198,   199,   200,   201,   449,
      79,    80,    81,    82,    83,    84,    85,    86,    73,    87,
     172,   325,   326,    74,    88,   327,    75,    76,    77,   328,
     341,   348,   190,   364,   362,    78,   404,   365,   366,   370,
     374,   371,   372,   306,   373,   453,    79,    80,    81,    82,
      83,    84,    85,    86,    73,    87,   376,    60,   289,    74,
      88,   382,    75,    76,    77,   385,   390,   391,   392,   396,
     413,    78,   404,   393,   286,   394,   395,   287,   288,   289,
     397,   501,    79,    80,    81,    82,    83,    84,    85,    86,
      73,    87,   403,   412,   406,    74,    88,   407,    75,    76,
      77,   429,   408,   430,   445,   435,   448,    78,   404,   292,
     293,   447,   294,   295,   296,   297,   148,   524,    79,    80,
      81,    82,    83,    84,    85,    86,    73,    87,   450,   455,
     456,    74,    88,   460,    75,    76,    77,   462,   465,   467,
     472,   474,   286,    78,   404,   287,   288,   289,   473,   485,
     475,   476,   479,   525,    79,    80,    81,    82,    83,    84,
      85,    86,    73,    87,   486,   487,   491,    74,    88,   499,
      75,    76,    77,   498,   504,   502,   503,   513,   518,    78,
     404,   295,   296,   297,   519,   526,   527,    50,   414,   529,
      79,    80,    81,    82,    83,    84,    85,    86,    73,    87,
     531,    48,   159,    74,    88,   466,    75,    76,    77,   415,
     488,   138,   137,   229,     0,    78,   404,    79,    80,    81,
      82,    83,    84,    85,    86,   534,    79,    80,    81,    82,
      83,    84,    85,    86,    73,    87,   189,   149,   401,    74,
      88,   308,    75,    76,    77,     0,     0,     0,     0,     0,
       0,    78,    89,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    79,    80,    81,    82,    83,    84,    85,    86,
      73,    87,     0,     0,     0,    74,    88,     0,    75,    76,
      77,     0,     0,     0,     0,     0,     0,    78,   151,     0,
       0,     0,   286,     0,     0,   287,   288,   289,    79,    80,
      81,    82,    83,    84,    85,    86,     0,    87,     0,     0,
     286,     0,    88,   287,   288,   289,   169,     0,     0,   170,
     171,   172,     0,     0,   404,   290,   291,   292,   293,     0,
     294,   295,   296,   297,   286,     0,     0,   287,   288,   289,
     298,     0,     0,   290,   291,   292,   293,     0,   294,   295,
     296,   297,     0,     0,     0,   173,   174,   175,   342,     0,
       0,     0,     0,     0,   245,     0,     0,   290,   291,   292,
     293,     0,   294,   295,   296,   297,   169,     0,     0,   170,
     171,   172,   528,     0,     0,     0,   169,     0,     0,   170,
     171,   172,     0,     0,     0,     0,     0,   286,     0,     0,
     287,   288,   289,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   173,   174,   175,     0,     0,
       0,     0,     0,     0,   302,   173,   174,   175,     0,     0,
     290,   291,   292,   293,   520,   294,   295,   296,   297
};

static const yytype_int16 yycheck[] =
{
      30,    58,   102,   140,   258,   177,   211,   209,    64,   146,
     285,   328,   266,   325,   270,   271,   272,   273,   274,   275,
     276,   362,   306,    17,   376,   366,    35,     6,   420,    71,
      17,     6,    13,     6,     6,    17,    14,    16,    17,    57,
      11,     6,    21,    22,    13,    17,    25,    26,    27,    43,
       6,    11,    17,    24,   382,    34,    29,    30,    74,   115,
       0,    17,    78,    16,    24,    18,   123,     6,     6,     6,
      71,   208,   209,    29,    30,   280,    49,    58,    17,    17,
      17,   283,    55,    56,    57,     4,     5,   144,    75,    58,
     407,   408,    71,    75,    10,   487,    75,    28,    29,   108,
      75,    80,    75,    75,    77,   433,    79,    74,   460,   450,
     462,    78,   169,   170,   171,   172,   173,   174,   175,    75,
      51,   396,    53,   435,   142,   143,   410,   299,    74,   185,
      72,   385,    78,    64,   390,   391,   392,    75,    75,   341,
      74,    72,    28,   348,    78,    31,    32,    33,    71,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   502,   503,    74,     6,     6,    74,   304,   443,    80,
      78,    16,    17,   448,   515,    17,    17,     6,    56,    57,
      66,    67,    68,    69,   115,    75,   117,    16,    17,    79,
     531,    74,    21,    22,   399,    78,    25,    26,    27,     3,
     131,    32,    33,   134,    28,    34,     6,    31,    32,    33,
      32,    33,    75,     6,    55,    56,    79,    17,   472,   473,
      74,   496,    76,    16,    17,    32,    33,    12,    21,    22,
       4,   162,    25,    26,    27,    72,    67,    68,    69,   493,
       8,    34,    71,    67,    68,    69,    75,    69,     6,    32,
      33,    80,    76,    72,   185,    55,    56,   188,    16,    17,
      67,    68,    69,    21,    22,   437,    72,    25,    26,    27,
       6,    32,    33,   527,    82,    75,    34,    74,    71,    76,
      16,    17,    75,    32,    33,    21,    22,    80,    82,    25,
      26,    27,    32,    33,   324,    32,    33,    81,    34,   329,
       6,    63,    64,    65,    74,   405,    76,    68,    69,   409,
      16,    17,    77,    71,    79,    21,    22,    75,    75,    25,
      26,    27,    80,    74,    17,    76,     6,    75,    34,    69,
      75,    68,    69,    75,    81,    71,    16,    17,    73,    75,
       6,    21,    22,     8,    80,    25,    26,    27,     8,    19,
      16,    17,    20,    73,    34,    21,    22,    19,    17,    25,
      26,    27,    74,    17,    76,    71,    75,    75,    34,    75,
      74,    74,    76,    76,    80,    75,    75,   514,    74,    17,
      76,    28,   482,     6,    31,    32,    33,    77,    31,    32,
      33,    71,    75,    16,    17,    75,     6,    17,    21,    22,
      80,     9,    25,    26,    27,    71,   436,     6,     9,    75,
      74,    34,    76,    74,    17,    76,   516,   517,    17,    17,
      67,    68,    69,   523,    67,    68,    69,    71,    16,    76,
      29,    30,    74,   533,    76,   492,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,     5,    74,    71,    76,
      49,     4,    75,    74,    20,    76,    55,    56,    57,    61,
      62,    63,    64,    65,   494,   495,   164,   165,   166,   167,
     168,    70,    19,     6,    81,    75,    75,    19,    77,   509,
      79,    49,    73,    16,    17,    72,    79,     6,    21,    22,
      19,    19,    25,    26,    27,    73,    17,    16,    17,    15,
     530,    34,    21,    22,    79,    20,    25,    26,    27,    74,
      74,    76,    76,    20,    75,    34,    17,    74,    74,    76,
      76,    22,    77,    75,    25,    26,    27,    31,    32,    33,
      74,    77,    76,    34,    75,    75,    75,    75,    71,    75,
      75,    75,    75,    75,    45,    46,    47,    48,    49,    50,
      51,    52,    17,    54,    78,     3,    75,    22,    59,     6,
      25,    26,    27,    67,    68,    69,    75,    17,    19,    34,
      71,    35,    36,    37,    38,    39,    40,    41,    42,    80,
      45,    46,    47,    48,    49,    50,    51,    52,    17,    54,
      33,    82,    76,    22,    59,    75,    25,    26,    27,    75,
      74,    74,     6,    20,    79,    34,    71,    20,    79,     5,
      77,     6,    74,    77,    74,    80,    45,    46,    47,    48,
      49,    50,    51,    52,    17,    54,    75,    24,    33,    22,
      59,    77,    25,    26,    27,    79,    74,    74,    74,    74,
      74,    34,    71,    76,    28,    76,    76,    31,    32,    33,
      76,    80,    45,    46,    47,    48,    49,    50,    51,    52,
      17,    54,    78,    73,    76,    22,    59,    75,    25,    26,
      27,    17,    75,    17,    76,    82,    77,    34,    71,    63,
      64,    80,    66,    67,    68,    69,    58,    80,    45,    46,
      47,    48,    49,    50,    51,    52,    17,    54,    79,     6,
       6,    22,    59,    77,    25,    26,    27,    75,    78,    23,
      79,    76,    28,    34,    71,    31,    32,    33,    79,    72,
      76,    76,    76,    80,    45,    46,    47,    48,    49,    50,
      51,    52,    17,    54,    76,    74,    17,    22,    59,    23,
      25,    26,    27,    78,     7,    79,    79,    76,    73,    34,
      71,    67,    68,    69,    76,     6,    79,    17,   372,    80,
      45,    46,    47,    48,    49,    50,    51,    52,    17,    54,
      79,    16,   110,    22,    59,   433,    25,    26,    27,   373,
     458,    72,    70,   145,    -1,    34,    71,    45,    46,    47,
      48,    49,    50,    51,    52,    80,    45,    46,    47,    48,
      49,    50,    51,    52,    17,    54,   138,    90,   345,    22,
      59,   233,    25,    26,    27,    -1,    -1,    -1,    -1,    -1,
      -1,    34,    71,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    45,    46,    47,    48,    49,    50,    51,    52,
      17,    54,    -1,    -1,    -1,    22,    59,    -1,    25,    26,
      27,    -1,    -1,    -1,    -1,    -1,    -1,    34,    71,    -1,
      -1,    -1,    28,    -1,    -1,    31,    32,    33,    45,    46,
      47,    48,    49,    50,    51,    52,    -1,    54,    -1,    -1,
      28,    -1,    59,    31,    32,    33,    28,    -1,    -1,    31,
      32,    33,    -1,    -1,    71,    61,    62,    63,    64,    -1,
      66,    67,    68,    69,    28,    -1,    -1,    31,    32,    33,
      76,    -1,    -1,    61,    62,    63,    64,    -1,    66,    67,
      68,    69,    -1,    -1,    -1,    67,    68,    69,    76,    -1,
      -1,    -1,    -1,    -1,    76,    -1,    -1,    61,    62,    63,
      64,    -1,    66,    67,    68,    69,    28,    -1,    -1,    31,
      32,    33,    76,    -1,    -1,    -1,    28,    -1,    -1,    31,
      32,    33,    -1,    -1,    -1,    -1,    -1,    28,    -1,    -1,
      31,    32,    33,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    67,    68,    69,    -1,    -1,
      -1,    -1,    -1,    -1,    76,    67,    68,    69,    -1,    -1,
      61,    62,    63,    64,    76,    66,    67,    68,    69
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    71,    84,    85,    14,     0,    71,    86,    72,    88,
      10,    71,    87,     3,    72,    89,    90,    91,     6,    16,
      17,    21,    22,    25,    26,    27,    34,    71,    75,   112,
     113,   114,   115,   116,   117,   121,   124,   125,   126,   135,
     136,   137,   138,    12,     4,     8,   105,    72,    91,    72,
      90,    82,   122,    82,    75,    17,    75,    75,    75,    11,
      24,    17,   116,   120,    75,   116,   118,    71,   114,    81,
      16,    17,   112,    17,    22,    25,    26,    27,    34,    45,
      46,    47,    48,    49,    50,    51,    52,    54,    59,    71,
     140,   141,   160,   161,   162,   164,   165,   166,   169,   170,
     171,   172,   173,   174,    73,     4,     5,    16,    18,    96,
      97,    98,   106,     8,     8,    75,   116,    19,   116,     6,
      17,    29,    30,    75,   129,   130,    20,    17,   134,   134,
     130,    74,    76,   120,    19,   119,    11,   122,   118,    73,
      75,    17,    75,    75,    75,    77,    75,    13,    58,   160,
      17,    71,   174,     6,     9,     9,    17,   112,    71,    98,
     120,   116,    19,   130,    61,    62,    63,    64,    65,    28,
      31,    32,    33,    67,    68,    69,    76,    75,    74,    76,
      76,    76,   116,    81,    76,    75,   116,   123,    19,   119,
       6,    17,    29,    30,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    49,    55,    56,    57,    70,    75,
      77,    79,   139,   142,   143,   144,   145,   146,   147,   148,
     152,   153,   156,   159,   159,    20,   134,   134,   130,   140,
     159,   163,    49,    73,    13,    72,    19,    19,    73,    17,
      75,   107,    15,    76,   116,    76,   129,   129,   129,   129,
     129,   130,   130,   130,   130,   130,   130,   130,    79,     6,
      17,   131,   132,    17,    20,    20,    79,   120,   116,    75,
      75,    75,    75,    75,    75,    75,    75,   159,   145,   159,
      77,   149,   150,    75,   146,    77,    28,    31,    32,    33,
      61,    62,    63,    64,    66,    67,    68,    69,    76,    75,
      76,    76,    76,    78,    74,    76,    77,   154,   156,     3,
      75,    92,    94,     6,    93,    95,    77,    79,    99,    17,
     108,    19,   109,    71,   113,    82,    76,    75,    75,   113,
      76,    17,    43,   157,   157,   157,   157,   157,   157,   157,
     157,    74,    76,   146,   151,    74,    78,   145,    74,   143,
     159,   159,   159,   159,   159,   159,   159,   159,   159,   159,
     159,   159,    79,   132,    20,    20,    79,   159,   153,   155,
       5,     6,    74,    74,    77,   100,    75,   101,    74,    76,
      17,    75,    77,    80,   131,    79,   132,   133,   133,    80,
      74,    74,    74,    76,    76,    76,    74,    76,   145,    74,
      78,   150,   146,    78,    71,   173,    76,    75,    75,   173,
      74,    78,    73,    74,    94,    95,     6,    17,    55,    56,
      75,   102,   103,   104,    74,    78,   102,    74,    80,    17,
      17,   110,   111,   115,   127,    82,   113,    74,    76,    76,
     157,   157,   157,    75,   143,    76,   146,    80,    77,    80,
      79,   133,   133,    80,   153,     6,     6,   104,    74,    78,
      77,    76,    75,    74,    76,    78,   111,    23,   128,   131,
      80,   132,    79,    79,    76,    76,    76,   143,   158,    76,
     143,   167,   173,    76,    76,    72,    76,    74,   103,   102,
     102,    17,    75,    79,   113,   113,    74,    76,    78,    23,
     168,    80,    79,    79,     7,   104,    78,    76,   130,   113,
      80,    80,   143,    76,    75,    79,   173,   173,    73,    76,
      76,    80,   159,   173,    80,    80,     6,    79,    76,    80,
     113,    79,    80,   173,    80
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    83,    84,    85,    86,    86,    87,    87,    88,    89,
      89,    89,    89,    89,    90,    91,    92,    92,    93,    93,
      94,    95,    96,    96,    97,    97,    98,    99,    99,   100,
     100,   101,   101,   102,   102,   103,   103,   104,   104,   104,
     104,   105,   105,   106,   107,   107,   108,   108,   109,   109,
     109,   110,   110,   111,   111,   112,   113,   113,   114,   114,
     115,   115,   115,   115,   115,   115,   115,   116,   116,   117,
     117,   117,   117,   118,   118,   119,   119,   120,   120,   121,
     121,   122,   122,   122,   123,   123,   124,   125,   126,   127,
     127,   128,   128,   129,   129,   129,   129,   129,   129,   129,
     130,   130,   130,   130,   130,   130,   130,   130,   130,   130,
     130,   131,   131,   132,   132,   133,   133,   134,   134,   135,
     136,   137,   138,   139,   139,   139,   140,   140,   140,   140,
     140,   140,   140,   140,   141,   142,   142,   143,   144,   145,
     145,   146,   147,   148,   149,   149,   150,   151,   151,   152,
     153,   153,   153,   153,   153,   153,   153,   153,   154,   155,
     155,   156,   156,   156,   156,   156,   156,   156,   156,   156,
     157,   157,   158,   158,   159,   159,   159,   159,   159,   159,
     159,   159,   159,   159,   159,   159,   159,   159,   159,   159,
     159,   159,   159,   160,   161,   161,   161,   162,   163,   163,
     164,   165,   165,   165,   165,   165,   166,   167,   167,   168,
     168,   169,   170,   171,   172,   173,   173,   174,   174,   174,
     174,   174
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     3,     8,     5,     4,     5,     4,    14,     2,
       2,     1,     1,     0,     6,     6,     3,     1,     3,     1,
       5,     1,     1,     0,     2,     1,     4,     3,     3,     5,
       3,     5,     3,     3,     1,     1,     5,     1,     1,     1,
       1,     2,     0,     7,     1,     3,     3,     1,     0,     2,
       4,     3,     1,     0,     2,     1,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     5,
       4,     4,     3,     1,     3,     0,     2,     3,     1,     2,
       4,     0,     2,     4,     1,     3,     5,     2,     9,     8,
       0,     4,     0,     3,     3,     3,     3,     3,     1,     1,
       3,     3,     3,     3,     3,     3,     3,     3,     1,     1,
       1,     1,     1,     3,     5,     3,     1,     3,     1,     9,
      11,    11,     7,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     4,     1,     1,     1,     1,     1,
       1,     5,     1,     3,     3,     1,     3,     3,     1,     5,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     3,
       1,     6,     6,     6,     4,     4,     6,     8,     4,     4,
       1,     1,     3,     1,     1,     1,     4,     7,     1,     3,
       2,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     2,     4,     4,     4,     3,     1,
       3,     1,     1,     1,     1,     1,     9,     8,     0,     4,
       0,     9,    11,    11,     7,     2,     1,     1,     1,     1,
       1,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* prgm: init_section main_section output_section  */
#line 38 "parser_main.y"
                                                                   {printf("Done\n");}
#line 1865 "y.tab.c"
    break;

  case 3: /* init_section: '\\' INIT_BEGIN mandatory_init set_states block_defns_list gate_defn_section '\\' INIT_END  */
#line 42 "parser_main.y"
                                                                                                                      {printf("init done\n");}
#line 1871 "y.tab.c"
    break;


#line 1875 "y.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 477 "parser_main.y"


int main()
{
  yyin = fopen("in.txt","r");
  fp2 = fopen("tokens.txt","w");
  yyparse();

  return 0;
}

void yyerror(){
   printf("Invalid syntax");
}
