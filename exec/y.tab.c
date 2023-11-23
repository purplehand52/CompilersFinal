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
#line 1 "./Parser/parser_main.y"

   #define YYSTYPE struct st
   #include<stdio.h>
   #include<stdbool.h>
   #include<stdlib.h>
   #include "st.h"

   #define HELLO printf("HELLO\n");

   extern FILE* yyin,*fp2;
   extern int line;
   FILE * fp,*out;
// comment
   int yylex();
   void yyerror(char* str);
   char * IntToString(int num);
   void printForLex(int num);
   void printForZip(int num);

   int classical_registers,quantum_registers,iterations,temp_type,indent;
   int * classical_states,classical_index=0,quantum_index=0;
   int isInBlock=0;
   int outputLevel = 0;
   bool isInOutput = false;
   bool isDeclaration = false;

   struct List* head = NULL;
   struct List* id_list = NULL;
   struct List2* range_list = NULL;
   struct BlockTable* BlockSymbolTable = NULL;
   struct GateTable* GateSymbolTable = NULL;

   /* Output Section */
   struct OutputSymbolEntry* OutputSymbolTable = NULL;

   bool firstLetterCapital(char *str);
   struct OutputSymbolEntry* getOutputSymbolEntry(struct OutputSymbolEntry** Head, char* id, int level, int findFlag); // declaration
   void exitOutputSymbolScope(struct OutputSymbolEntry** Head, int level);
   int insertInGateTable(struct GateTable ** Head,char * data,int rows,int cols);
   int insertInBlockTable(struct BlockTable** Head,char * data,int len,struct List* params);
   void insertInOutputTable(struct OutputSymbolEntry** Head, char* id, int level, int type, bool primitive, int matrix_dim, int dim, bool isLoopId);
   int BlockCallSemanticCheck(char *block_id,int num_params);
   int BlockSemanticCheck(char *block_id);
   void insertInList(struct List** Head,char * data);
   bool inList(struct List** Head, char* data);
   void removeTopKFromList(struct List** Head, int k);
   int compatibleCheck(int t1, int t2);
   int compatibleCheckAdv(int t1, int t2, int p1, int p2, int d1, int d2);
   int condenser(int size, int lim);
   int InBlock(struct BlockTable** Head,char * data,int len);
   void assignString(char* str1, char* str2);
   void printOutputTable(struct OutputSymbolEntry ** OutputSymbolTable);

#line 125 "./exec/y.tab.c"

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

#include "y.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_ID = 3,                         /* ID  */
  YYSYMBOL_NUMBER = 4,                     /* NUMBER  */
  YYSYMBOL_ITERS = 5,                      /* ITERS  */
  YYSYMBOL_NEG = 6,                        /* NEG  */
  YYSYMBOL_SET = 7,                        /* SET  */
  YYSYMBOL_STATES = 8,                     /* STATES  */
  YYSYMBOL_REGISTERS = 9,                  /* REGISTERS  */
  YYSYMBOL_QUANTUM = 10,                   /* QUANTUM  */
  YYSYMBOL_CLASSICAL = 11,                 /* CLASSICAL  */
  YYSYMBOL_MAIN_BEGIN = 12,                /* MAIN_BEGIN  */
  YYSYMBOL_MAIN_END = 13,                  /* MAIN_END  */
  YYSYMBOL_OUTPUT_BEGIN = 14,              /* OUTPUT_BEGIN  */
  YYSYMBOL_OUTPUT_END = 15,                /* OUTPUT_END  */
  YYSYMBOL_INIT_BEGIN = 16,                /* INIT_BEGIN  */
  YYSYMBOL_INIT_END = 17,                  /* INIT_END  */
  YYSYMBOL_GATE = 18,                      /* GATE  */
  YYSYMBOL_BLOCK = 19,                     /* BLOCK  */
  YYSYMBOL_ARROW = 20,                     /* ARROW  */
  YYSYMBOL_IN = 21,                        /* IN  */
  YYSYMBOL_MEASURE = 22,                   /* MEASURE  */
  YYSYMBOL_CONDITION = 23,                 /* CONDITION  */
  YYSYMBOL_OTHERWISE = 24,                 /* OTHERWISE  */
  YYSYMBOL_BARRIER = 25,                   /* BARRIER  */
  YYSYMBOL_FOR = 26,                       /* FOR  */
  YYSYMBOL_FOR_LEX = 27,                   /* FOR_LEX  */
  YYSYMBOL_FOR_ZIP = 28,                   /* FOR_ZIP  */
  YYSYMBOL_COMP = 29,                      /* COMP  */
  YYSYMBOL_TRUE = 30,                      /* TRUE  */
  YYSYMBOL_FALSE = 31,                     /* FALSE  */
  YYSYMBOL_EQUALITY = 32,                  /* EQUALITY  */
  YYSYMBOL_AND = 33,                       /* AND  */
  YYSYMBOL_OR = 34,                        /* OR  */
  YYSYMBOL_WHILE = 35,                     /* WHILE  */
  YYSYMBOL_ADD = 36,                       /* ADD  */
  YYSYMBOL_SUB = 37,                       /* SUB  */
  YYSYMBOL_DOT = 38,                       /* DOT  */
  YYSYMBOL_STD_DEV = 39,                   /* STD_DEV  */
  YYSYMBOL_VAR = 40,                       /* VAR  */
  YYSYMBOL_AVG = 41,                       /* AVG  */
  YYSYMBOL_CONDENSE = 42,                  /* CONDENSE  */
  YYSYMBOL_SUM = 43,                       /* SUM  */
  YYSYMBOL_COUT = 44,                      /* COUT  */
  YYSYMBOL_QOUT = 45,                      /* QOUT  */
  YYSYMBOL_INT = 46,                       /* INT  */
  YYSYMBOL_UINT = 47,                      /* UINT  */
  YYSYMBOL_FLOAT = 48,                     /* FLOAT  */
  YYSYMBOL_COMPLEX = 49,                   /* COMPLEX  */
  YYSYMBOL_STRING = 50,                    /* STRING  */
  YYSYMBOL_MATRIX = 51,                    /* MATRIX  */
  YYSYMBOL_STATE = 52,                     /* STATE  */
  YYSYMBOL_BOOL = 53,                      /* BOOL  */
  YYSYMBOL_IMAG = 54,                      /* IMAG  */
  YYSYMBOL_LIST = 55,                      /* LIST  */
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
  YYSYMBOL_75_ = 75,                       /* '['  */
  YYSYMBOL_76_ = 76,                       /* ']'  */
  YYSYMBOL_77_ = 77,                       /* '{'  */
  YYSYMBOL_78_ = 78,                       /* '}'  */
  YYSYMBOL_79_ = 79,                       /* '('  */
  YYSYMBOL_80_ = 80,                       /* ')'  */
  YYSYMBOL_81_ = 81,                       /* '?'  */
  YYSYMBOL_82_ = 82,                       /* ':'  */
  YYSYMBOL_YYACCEPT = 83,                  /* $accept  */
  YYSYMBOL_prgm = 84,                      /* prgm  */
  YYSYMBOL_85_1 = 85,                      /* $@1  */
  YYSYMBOL_86_2 = 86,                      /* $@2  */
  YYSYMBOL_init_section = 87,              /* init_section  */
  YYSYMBOL_88_3 = 88,                      /* $@3  */
  YYSYMBOL_main_section = 89,              /* main_section  */
  YYSYMBOL_90_4 = 90,                      /* $@4  */
  YYSYMBOL_output_section = 91,            /* output_section  */
  YYSYMBOL_92_5 = 92,                      /* $@5  */
  YYSYMBOL_mandatory_init = 93,            /* mandatory_init  */
  YYSYMBOL_set_states = 94,                /* set_states  */
  YYSYMBOL_set_quantum_states = 95,        /* set_quantum_states  */
  YYSYMBOL_set_classical_states = 96,      /* set_classical_states  */
  YYSYMBOL_quantum_state_list = 97,        /* quantum_state_list  */
  YYSYMBOL_classical_state_list = 98,      /* classical_state_list  */
  YYSYMBOL_classical_state = 99,           /* classical_state  */
  YYSYMBOL_gate_defn_section = 100,        /* gate_defn_section  */
  YYSYMBOL_101_6 = 101,                    /* $@6  */
  YYSYMBOL_gate_defn_list = 102,           /* gate_defn_list  */
  YYSYMBOL_gate_defn = 103,                /* gate_defn  */
  YYSYMBOL_rhs = 104,                      /* rhs  */
  YYSYMBOL_tuple_list = 105,               /* tuple_list  */
  YYSYMBOL_tuple_list2 = 106,              /* tuple_list2  */
  YYSYMBOL_id_list = 107,                  /* id_list  */
  YYSYMBOL_block_defn_section = 108,       /* block_defn_section  */
  YYSYMBOL_109_7 = 109,                    /* $@7  */
  YYSYMBOL_block_defns_list = 110,         /* block_defns_list  */
  YYSYMBOL_block_defn = 111,               /* block_defn  */
  YYSYMBOL_112_8 = 112,                    /* $@8  */
  YYSYMBOL_params = 113,                   /* params  */
  YYSYMBOL_param_id_list = 114,            /* param_id_list  */
  YYSYMBOL_target_params = 115,            /* target_params  */
  YYSYMBOL_target_param_list = 116,        /* target_param_list  */
  YYSYMBOL_block_body = 117,               /* block_body  */
  YYSYMBOL_block_id = 118,                 /* block_id  */
  YYSYMBOL_main_stmt_list = 119,           /* main_stmt_list  */
  YYSYMBOL_main_stmt = 120,                /* main_stmt  */
  YYSYMBOL_stmts = 121,                    /* stmts  */
  YYSYMBOL_122_9 = 122,                    /* $@9  */
  YYSYMBOL_register = 123,                 /* register  */
  YYSYMBOL_call_stmt = 124,                /* call_stmt  */
  YYSYMBOL_parameters = 125,               /* parameters  */
  YYSYMBOL_optional = 126,                 /* optional  */
  YYSYMBOL_register_list = 127,            /* register_list  */
  YYSYMBOL_classic_control = 128,          /* classic_control  */
  YYSYMBOL_quantum_control = 129,          /* quantum_control  */
  YYSYMBOL_target = 130,                   /* target  */
  YYSYMBOL_register_expr = 131,            /* register_expr  */
  YYSYMBOL_register_expr_list = 132,       /* register_expr_list  */
  YYSYMBOL_measure_stmt = 133,             /* measure_stmt  */
  YYSYMBOL_barrier_stmt = 134,             /* barrier_stmt  */
  YYSYMBOL_condition_stmt = 135,           /* condition_stmt  */
  YYSYMBOL_otherwise_list = 136,           /* otherwise_list  */
  YYSYMBOL_otherwise_final = 137,          /* otherwise_final  */
  YYSYMBOL_arithmetic_expr = 138,          /* arithmetic_expr  */
  YYSYMBOL_expr = 139,                     /* expr  */
  YYSYMBOL_value = 140,                    /* value  */
  YYSYMBOL_range = 141,                    /* range  */
  YYSYMBOL_range_list = 142,               /* range_list  */
  YYSYMBOL_var_list = 143,                 /* var_list  */
  YYSYMBOL_for_stmt = 144,                 /* for_stmt  */
  YYSYMBOL_145_10 = 145,                   /* $@10  */
  YYSYMBOL_for_lex_stmt = 146,             /* for_lex_stmt  */
  YYSYMBOL_147_11 = 147,                   /* $@11  */
  YYSYMBOL_for_zip_stmt = 148,             /* for_zip_stmt  */
  YYSYMBOL_149_12 = 149,                   /* $@12  */
  YYSYMBOL_while_stmt = 150,               /* while_stmt  */
  YYSYMBOL_out_id = 151,                   /* out_id  */
  YYSYMBOL_prim_type = 152,                /* prim_type  */
  YYSYMBOL_list_type = 153,                /* list_type  */
  YYSYMBOL_154_13 = 154,                   /* @13  */
  YYSYMBOL_bool_const = 155,               /* bool_const  */
  YYSYMBOL_num = 156,                      /* num  */
  YYSYMBOL_complex_const = 157,            /* complex_const  */
  YYSYMBOL_matrix_const = 158,             /* matrix_const  */
  YYSYMBOL_row_list = 159,                 /* row_list  */
  YYSYMBOL_row = 160,                      /* row  */
  YYSYMBOL_comps = 161,                    /* comps  */
  YYSYMBOL_compatible_const = 162,         /* compatible_const  */
  YYSYMBOL_state_const = 163,              /* state_const  */
  YYSYMBOL_temp = 164,                     /* temp  */
  YYSYMBOL_prim_const = 165,               /* prim_const  */
  YYSYMBOL_vec_const = 166,                /* vec_const  */
  YYSYMBOL_vec_list = 167,                 /* vec_list  */
  YYSYMBOL_calls = 168,                    /* calls  */
  YYSYMBOL_uint_list = 169,                /* uint_list  */
  YYSYMBOL_out_rhs = 170,                  /* out_rhs  */
  YYSYMBOL_out_expr = 171,                 /* out_expr  */
  YYSYMBOL_decl = 172,                     /* decl  */
  YYSYMBOL_echo_stmt = 173,                /* echo_stmt  */
  YYSYMBOL_echo_list = 174,                /* echo_list  */
  YYSYMBOL_save_stmt = 175,                /* save_stmt  */
  YYSYMBOL_out_control = 176,              /* out_control  */
  YYSYMBOL_177_14 = 177,                   /* $@14  */
  YYSYMBOL_out_cond_stmt = 178,            /* out_cond_stmt  */
  YYSYMBOL_179_15 = 179,                   /* $@15  */
  YYSYMBOL_180_16 = 180,                   /* $@16  */
  YYSYMBOL_out_other_list = 181,           /* out_other_list  */
  YYSYMBOL_182_17 = 182,                   /* $@17  */
  YYSYMBOL_out_other_final = 183,          /* out_other_final  */
  YYSYMBOL_184_18 = 184,                   /* $@18  */
  YYSYMBOL_out_for_stmt = 185,             /* out_for_stmt  */
  YYSYMBOL_186_19 = 186,                   /* $@19  */
  YYSYMBOL_187_20 = 187,                   /* $@20  */
  YYSYMBOL_out_for_lex_stmt = 188,         /* out_for_lex_stmt  */
  YYSYMBOL_189_21 = 189,                   /* $@21  */
  YYSYMBOL_190_22 = 190,                   /* $@22  */
  YYSYMBOL_out_for_zip_stmt = 191,         /* out_for_zip_stmt  */
  YYSYMBOL_192_23 = 192,                   /* $@23  */
  YYSYMBOL_193_24 = 193,                   /* $@24  */
  YYSYMBOL_out_while_stmt = 194,           /* out_while_stmt  */
  YYSYMBOL_195_25 = 195,                   /* $@25  */
  YYSYMBOL_out_main = 196,                 /* out_main  */
  YYSYMBOL_out_stmt = 197,                 /* out_stmt  */
  YYSYMBOL_198_26 = 198,                   /* $@26  */
  YYSYMBOL_199_27 = 199                    /* $@27  */
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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1130

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  83
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  117
/* YYNRULES -- Number of rules.  */
#define YYNRULES  249
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  563

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
      79,    80,    63,    61,    74,    62,     2,    64,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    82,     2,
       2,    73,     2,    81,    66,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    75,    71,    76,    68,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    77,    69,    78,     2,     2,     2,     2,
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
       0,    85,    85,    94,    85,   101,   101,   104,   104,   107,
     107,   115,   127,   128,   129,   130,   131,   134,   139,   144,
     152,   159,   167,   173,   177,   177,   178,   181,   182,   185,
     193,   194,   196,   204,   206,   207,   209,   210,   213,   213,
     216,   217,   220,   220,   237,   238,   241,   242,   245,   246,
     247,   250,   251,   254,   255,   258,   271,   272,   275,   276,
     278,   279,   280,   280,   281,   282,   283,   284,   287,   296,
     303,   310,   313,   316,   319,   327,   337,   338,   341,   342,
     345,   346,   349,   355,   363,   364,   365,   368,   369,   373,
     378,   385,   391,   399,   407,   410,   413,   414,   417,   418,
     421,   422,   423,   424,   425,   426,   427,   430,   431,   432,
     433,   434,   435,   436,   437,   438,   439,   440,   444,   445,
     448,   449,   452,   460,   470,   485,   502,   502,   513,   513,
     521,   521,   529,   538,   539,   540,   543,   544,   545,   546,
     547,   548,   549,   550,   553,   553,   560,   561,   564,   565,
     566,   567,   569,   572,   582,   591,   594,   597,   598,   601,
     602,   605,   608,   609,   612,   617,   621,   626,   627,   628,
     629,   630,   631,   634,   648,   672,   683,   700,   717,   743,
     758,   773,   788,   804,   819,   839,   851,   863,   864,   872,
     902,   945,   990,  1026,  1032,  1038,  1050,  1064,  1077,  1091,
    1105,  1127,  1141,  1164,  1180,  1215,  1230,  1245,  1263,  1283,
    1300,  1318,  1323,  1328,  1335,  1339,  1339,  1340,  1341,  1342,
    1343,  1346,  1346,  1346,  1349,  1349,  1350,  1353,  1353,  1354,
    1357,  1362,  1357,  1366,  1372,  1366,  1384,  1390,  1384,  1394,
    1394,  1399,  1400,  1403,  1404,  1405,  1406,  1406,  1407,  1407
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
  "\"end of file\"", "error", "\"invalid token\"", "ID", "NUMBER",
  "ITERS", "NEG", "SET", "STATES", "REGISTERS", "QUANTUM", "CLASSICAL",
  "MAIN_BEGIN", "MAIN_END", "OUTPUT_BEGIN", "OUTPUT_END", "INIT_BEGIN",
  "INIT_END", "GATE", "BLOCK", "ARROW", "IN", "MEASURE", "CONDITION",
  "OTHERWISE", "BARRIER", "FOR", "FOR_LEX", "FOR_ZIP", "COMP", "TRUE",
  "FALSE", "EQUALITY", "AND", "OR", "WHILE", "ADD", "SUB", "DOT",
  "STD_DEV", "VAR", "AVG", "CONDENSE", "SUM", "COUT", "QOUT", "INT",
  "UINT", "FLOAT", "COMPLEX", "STRING", "MATRIX", "STATE", "BOOL", "IMAG",
  "LIST", "DEC", "EXP", "SAVE", "ECHO", "RETURN", "'+'", "'-'", "'*'",
  "'/'", "'%'", "'@'", "'&'", "'^'", "'|'", "'!'", "'\\\\'", "'#'", "'='",
  "','", "'['", "']'", "'{'", "'}'", "'('", "')'", "'?'", "':'", "$accept",
  "prgm", "$@1", "$@2", "init_section", "$@3", "main_section", "$@4",
  "output_section", "$@5", "mandatory_init", "set_states",
  "set_quantum_states", "set_classical_states", "quantum_state_list",
  "classical_state_list", "classical_state", "gate_defn_section", "$@6",
  "gate_defn_list", "gate_defn", "rhs", "tuple_list", "tuple_list2",
  "id_list", "block_defn_section", "$@7", "block_defns_list", "block_defn",
  "$@8", "params", "param_id_list", "target_params", "target_param_list",
  "block_body", "block_id", "main_stmt_list", "main_stmt", "stmts", "$@9",
  "register", "call_stmt", "parameters", "optional", "register_list",
  "classic_control", "quantum_control", "target", "register_expr",
  "register_expr_list", "measure_stmt", "barrier_stmt", "condition_stmt",
  "otherwise_list", "otherwise_final", "arithmetic_expr", "expr", "value",
  "range", "range_list", "var_list", "for_stmt", "$@10", "for_lex_stmt",
  "$@11", "for_zip_stmt", "$@12", "while_stmt", "out_id", "prim_type",
  "list_type", "@13", "bool_const", "num", "complex_const", "matrix_const",
  "row_list", "row", "comps", "compatible_const", "state_const", "temp",
  "prim_const", "vec_const", "vec_list", "calls", "uint_list", "out_rhs",
  "out_expr", "decl", "echo_stmt", "echo_list", "save_stmt", "out_control",
  "$@14", "out_cond_stmt", "$@15", "$@16", "out_other_list", "$@17",
  "out_other_final", "$@18", "out_for_stmt", "$@19", "$@20",
  "out_for_lex_stmt", "$@21", "$@22", "out_for_zip_stmt", "$@23", "$@24",
  "out_while_stmt", "$@25", "out_main", "out_stmt", "$@26", "$@27", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-442)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-247)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -442,    27,   -41,  -442,   100,  -442,  -442,   -28,    62,   127,
      80,   179,   119,  -442,   207,  -442,   233,   264,  -442,   222,
     229,  -442,  -442,   258,   193,   268,   316,   335,  -442,   341,
    -442,   469,  -442,   343,   374,   381,   289,   372,   389,  -442,
     316,   383,   386,     1,  -442,   322,   323,   395,   327,   328,
     330,   263,    37,    77,    19,  -442,  -442,   392,  -442,  -442,
      17,   339,  -442,  -442,  -442,  -442,  -442,  -442,   599,   344,
     404,   409,   416,   432,   372,  -442,  -442,    12,  -442,    30,
     421,   422,   263,  -442,   450,   450,    25,  -442,  -442,  -442,
    -442,  -442,   -21,   263,  -442,   435,   333,  -442,     4,   322,
      19,  -442,   453,   378,   380,   387,   397,    31,  -442,  -442,
    -442,   442,  -442,  -442,  -442,  -442,  -442,   471,  1060,   473,
     413,   482,  -442,   420,  -442,  -442,   491,   479,   263,  -442,
     263,   263,   485,   487,   437,   430,   433,  -442,  -442,  -442,
    -442,    25,   385,   317,    77,   431,  -442,    64,    41,  -442,
      25,   501,   503,   435,  -442,   450,   450,   195,   195,  -442,
     476,   451,  -442,   458,  -442,  -442,  -442,  -442,  -442,  -442,
    -442,  -442,  -442,   462,   471,   471,  -442,   532,   111,   475,
    -442,  -442,   478,  -442,   -23,   481,   477,    28,  -442,    68,
    -442,  -442,   263,   474,   450,   538,   539,   840,   282,   282,
     282,   282,   282,    25,    25,    25,    25,    25,    25,    25,
     489,  -442,  -442,   263,  -442,   263,  -442,  -442,   860,   263,
     263,  -442,   543,   488,   492,  -442,  -442,  -442,  -442,  -442,
     495,   496,   504,   507,   508,   510,   513,   514,  -442,  -442,
    -442,  -442,  -442,   195,   223,   284,   520,  -442,  -442,  -442,
    -442,  -442,  -442,  -442,   610,  1036,    72,  -442,   195,   195,
    -442,  -442,  -442,   509,  -442,  -442,  -442,  -442,   137,  -442,
    -442,   493,   413,   482,   521,   522,  -442,   491,  -442,   524,
     596,  -442,   525,  -442,  -442,   314,  -442,   528,   540,  -442,
     101,   101,  -442,  -442,  -442,   181,   434,   569,  -442,   173,
     186,   319,  -442,  -442,   122,   527,  -442,  -442,   549,   597,
     608,   195,   195,   195,   195,   195,   195,   195,   195,   331,
      54,    18,  -442,  -442,    47,   556,   558,   559,   561,   562,
     635,   195,   195,   195,   195,   195,   195,   195,   195,   195,
     195,   195,   195,   195,   560,   195,  -442,   655,  1036,   259,
     634,   111,  -442,  -442,   111,    50,   111,   185,  -442,   596,
     565,    14,  -442,  -442,   564,   568,   314,   314,   340,  -442,
    -442,   314,   570,   571,   950,   969,   993,   676,   696,   717,
    1012,   737,   111,  -442,  -442,   154,  -442,   576,  -442,   494,
    -442,   137,  -442,   883,   224,   587,   606,  -442,  1055,  1055,
     103,   103,  1061,   235,   227,   331,  -442,  1036,   575,   581,
     589,   584,   170,  -442,   590,  -442,   131,   601,  -442,  -442,
    -442,   605,    14,   314,   586,   609,   595,   602,   660,  -442,
     352,   611,   314,   314,   195,   195,   195,  -442,  -442,  -442,
      35,  -442,   111,  -442,  -442,   576,  -442,   612,   618,  -442,
    -442,  -442,   681,  -442,   111,  -442,   111,  -442,   111,  -442,
    -442,   613,  -442,   314,  -442,  -442,  -442,   617,   620,   626,
     758,   778,   799,   627,   195,  -442,  -442,   195,   310,  -442,
     638,  -442,   188,   144,   314,   373,  -442,   636,   637,   688,
    -442,  -442,  -442,  -442,  -442,  -442,  -442,   201,  1036,   909,
     662,  -442,   506,   722,  -442,  -442,  -442,  -442,  -442,  -442,
     205,  -442,  -442,   650,   654,   195,   652,   658,  -442,  -442,
     399,   410,  -442,    25,   519,  -442,  -442,  1036,  -442,   195,
    -442,  -442,  -442,   436,   868,  -442,  -442,  -442,   928,   710,
    -442,   659,   535,   553,  -442,   253,  -442,  -442,  -442,  -442,
    -442,   195,   457,  -442,   819,  -442,   582,   664,  -442,  -442,
    -442,   588,  -442
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     0,     1,     0,     3,     5,     0,     0,     0,
       0,     0,    16,     7,     0,     4,     0,     0,    38,    14,
      15,    57,     9,     0,     0,    24,    41,     0,    12,     0,
      13,    62,   242,     0,     0,     0,     0,     0,     0,    39,
      41,     0,     0,    55,    68,    84,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    56,    58,     0,    89,    60,
       0,     0,    61,    59,    64,    65,    66,    67,   248,     0,
       0,     0,     0,     0,    25,    28,    55,     0,    40,     0,
       0,     0,     0,   126,     0,     0,     0,    69,    90,     8,
      94,    92,     0,     0,    76,    78,     0,    63,    55,    84,
       0,    82,     0,     0,     0,     0,     0,     0,   245,   244,
     243,     0,   217,   218,   219,   220,   241,     0,     0,     0,
       0,     0,     6,     0,    27,    44,     0,    48,     0,    85,
       0,     0,     0,     0,   125,     0,     0,   105,   106,   116,
     117,     0,   115,     0,     0,     0,    81,     0,     0,    75,
       0,     0,     0,    78,   230,     0,     0,     0,     0,    10,
       0,     0,   216,     0,   247,   136,   137,   138,   139,   140,
     141,   142,   143,     0,     0,     0,   249,     0,     0,    17,
      20,    23,    18,    22,     0,    47,     0,     0,    42,     0,
      73,    72,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    91,    83,     0,    77,     0,    87,    79,     0,     0,
       0,    74,     0,     0,     0,   133,   168,   169,   146,   147,
       0,     0,     0,     0,     0,     0,     0,     0,   134,   135,
     172,   170,   171,     0,     0,     0,   189,   164,   165,   166,
     167,   187,   188,   193,     0,   213,     0,   214,     0,     0,
     144,   209,   210,     0,   151,   149,   148,   150,     0,   163,
     162,     0,     0,     0,     0,     0,    29,     0,    45,    52,
       0,    50,     0,    86,    93,     0,   124,     0,     0,   114,
     100,   101,   102,   103,   104,   107,   108,   109,   110,   112,
     111,   113,    57,    80,     0,     0,    71,    70,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   195,
       0,     0,   155,   175,     0,   168,   169,   170,   171,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   211,     0,   208,     0,
       0,     0,    19,    21,     0,     0,     0,     0,    46,     0,
       0,    53,   119,   118,     0,     0,     0,     0,    62,    88,
      57,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   160,   159,     0,   158,     0,   153,     0,
     173,     0,   194,     0,   198,   199,   196,   197,   202,   203,
     200,   201,   204,   205,   206,   207,   239,   212,     0,     0,
       0,     0,     0,    37,     0,    30,     0,     0,    31,    51,
      49,     0,    53,     0,     0,   123,     0,     0,     0,   132,
      62,     0,     0,     0,     0,     0,     0,   179,   180,   184,
       0,   183,     0,   156,   154,     0,   174,     0,   190,   242,
     221,   145,     0,   161,     0,    33,     0,    35,     0,    43,
      54,   120,    57,     0,   128,   130,    97,     0,     0,     0,
       0,     0,     0,     0,     0,   157,   152,     0,   248,   242,
       0,    36,     0,     0,     0,    62,   122,     0,     0,    99,
     231,   233,   236,   176,   177,   178,   181,     0,   186,     0,
       0,   240,   248,     0,    32,    34,   121,   127,    57,    57,
       0,    95,   242,     0,     0,     0,     0,   191,   222,    11,
      62,    62,    57,     0,   248,   234,   237,   185,   182,     0,
     226,   129,   131,    62,     0,   232,   242,   242,     0,   229,
      98,     0,   248,   248,   192,     0,   223,    57,   235,   238,
     227,     0,    62,   242,     0,    96,   248,     0,   228,   224,
     242,   248,   225
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -442,  -442,  -442,  -442,  -442,  -442,  -442,  -442,  -442,  -442,
    -442,  -442,   727,   729,  -442,  -442,   480,  -442,  -442,  -442,
     678,  -442,  -442,  -442,  -350,  -442,  -442,   714,  -442,  -442,
    -442,   484,  -442,  -271,   345,   -13,  -300,  -442,  -304,  -442,
      -3,  -442,   668,   619,  -116,  -442,    32,  -442,   -39,  -442,
    -442,  -442,  -442,  -442,  -442,   318,  -140,  -362,  -269,  -360,
     -81,  -442,  -442,  -442,  -442,  -442,  -442,  -442,  -442,   406,
    -442,  -442,  -442,  -242,  -159,  -442,  -442,   388,  -442,   332,
    -109,  -165,  -239,  -442,  -442,  -442,  -442,  -158,   198,  -442,
    -442,  -442,  -442,  -442,  -442,  -442,  -442,  -442,  -442,  -442,
    -442,  -442,  -442,  -442,  -442,  -442,  -442,  -442,  -442,  -442,
    -442,  -442,  -442,  -441,  -442,  -442,  -442
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     1,     2,     7,     5,     8,    10,    21,    15,    32,
      12,    18,    19,    20,   179,   182,   183,    36,    37,    74,
      75,   276,   355,   357,   412,    25,    26,    39,    40,   282,
     127,   186,   188,   281,   421,    54,    31,    55,    56,    57,
      58,    59,    95,   149,   147,    60,    80,   217,    61,    92,
      62,    63,    97,   489,   511,   142,   143,   364,   425,   426,
     135,    64,   133,    65,   487,    66,   488,    67,   246,   174,
     175,   349,   247,   269,   248,   249,   321,   322,   385,   386,
     250,   413,   251,   252,   324,   253,   497,   254,   164,   176,
     108,   256,   109,   110,   111,   162,   479,   530,   539,   560,
     546,   553,   112,   222,   512,   113,   513,   536,   114,   514,
     537,   115,   449,    68,   116,   117,   118
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     255,   197,   368,   329,   136,   323,   416,   427,   478,   360,
     218,   180,   189,   271,    91,   125,   365,    43,    44,   270,
      98,   -84,    87,    44,   -84,    77,   329,     3,   137,   138,
       4,   279,    45,    87,    44,    99,    46,   -62,   502,   473,
      47,    48,    49,     9,    87,    44,   159,   100,    88,    50,
      89,    94,   274,   144,   275,   139,   140,   422,   264,   145,
     265,   461,    90,   295,   296,   297,   298,   299,   300,   301,
     430,   524,   468,   469,   223,   224,   129,    81,   383,   132,
      87,    44,   -69,    79,    51,   319,    79,   330,   419,   160,
     146,   126,   387,    53,   388,   542,   543,    94,    93,   304,
     347,   348,   431,   486,   141,   211,   482,   280,   483,   128,
     266,   267,   556,   286,   474,   264,     6,   265,   422,   561,
     215,   389,   506,   390,   414,   146,   415,   190,   191,   382,
     151,   152,   332,   268,    11,   333,   334,   335,   213,    13,
     383,   264,   213,   265,   214,   216,   345,    51,   283,   447,
     446,    14,   346,   374,   375,   376,   377,   378,   379,   380,
     381,   384,   485,   352,   200,   201,   202,   266,   267,   340,
     341,   342,   343,   393,   394,   395,   396,   397,   398,   399,
     400,   401,   402,   403,   404,   405,   411,   407,    16,   284,
     268,    17,   270,   266,   267,   270,   213,   270,   225,   226,
     383,   227,   369,    34,    35,   454,   205,   206,   520,   521,
     303,   457,   146,   204,   205,   206,   306,   307,   454,   205,
     206,    22,   533,   384,   505,   228,   229,   226,   442,   227,
     443,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   208,   209,    23,   454,   240,   455,   552,   207,   208,
     209,   241,   242,   228,   229,   209,   333,   334,   335,   417,
     334,   335,   454,   418,   504,   243,    87,    44,   334,   335,
     244,    24,   178,   240,   245,   515,   470,   471,   472,   241,
     242,   516,   522,   384,   523,   137,   138,   225,   325,   481,
     326,   341,   342,   343,    27,   270,   343,   270,   320,   270,
     178,    29,   268,   342,   343,   165,   166,   167,   168,   169,
     170,   171,   172,  -246,   228,   229,   498,   362,   363,   499,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     550,    33,   551,  -215,   240,    38,   102,   103,   104,   -26,
     327,   328,    41,    43,    44,   105,   203,    69,    42,   204,
     205,   206,   205,   206,   243,    43,    44,   527,    45,   244,
      72,   178,    46,   245,   334,   335,    47,    48,    49,   106,
      45,   538,   261,   262,    46,    50,    43,    44,    47,    48,
      49,   500,    70,   534,   207,   208,   209,    50,   501,    71,
      73,    45,    76,   554,    35,    46,    34,   210,    83,    47,
      48,    49,    43,    44,    79,    82,    84,    85,    50,    86,
      51,   428,   150,    43,    44,    96,   119,    45,   429,    53,
     101,    46,    51,   428,   120,    47,    48,    49,    45,   121,
     466,    53,    46,   122,    50,   123,    47,    48,    49,    43,
      44,   130,   131,    51,   428,    50,   198,   199,   200,   201,
     202,   507,    53,   134,    45,   148,   154,   155,    46,   156,
      43,    44,    47,    48,    49,   161,   157,   205,   206,    51,
     428,    50,    43,    44,   163,    45,   158,   531,    53,    46,
      51,   428,   177,    47,    48,    49,   181,    45,   532,    53,
     178,    46,    50,   184,   185,    47,    48,    49,   226,   187,
     227,   207,   208,   209,    50,   192,    51,   428,   193,  -246,
     195,   194,   212,   196,   540,    53,   290,   291,   292,   293,
     294,   219,  -246,   220,   228,   229,   257,    51,   428,  -215,
     258,   259,   102,   103,   104,   555,    53,   260,  -246,    51,
      52,   105,  -215,   263,   240,   102,   103,   104,    53,   272,
     241,   242,   273,   285,   105,   277,  -246,   278,  -215,   287,
     288,   102,   103,   104,   308,   106,   302,   351,   309,   445,
     105,   178,   310,   268,   311,   312,  -215,   500,   106,   102,
     103,   104,   350,   313,   518,  -246,   314,   315,   105,   316,
     500,  -246,   317,   318,   106,   331,   354,   535,   359,   279,
     361,   356,  -246,   206,   370,  -215,   500,   366,   102,   103,
     104,  -215,   106,   548,   102,   103,   104,   105,   372,   367,
     334,   335,  -215,   105,   500,   102,   103,   104,   371,   373,
    -151,   549,  -149,  -148,   105,  -150,   391,   406,   410,   332,
     335,   106,   333,   334,   335,   420,   423,   106,   424,   432,
     433,   382,   450,   500,   341,   342,   343,   451,   106,   500,
     558,   452,   453,   462,   332,   456,   562,   333,   334,   335,
     107,   336,   337,   338,   339,   464,   340,   341,   342,   343,
     458,   459,   465,   463,   332,    90,   480,   333,   334,   335,
     344,   467,   476,   477,   490,   484,   336,   337,   338,   339,
     491,   340,   341,   342,   343,   332,   492,   496,   333,   334,
     335,   503,   510,   508,   509,   392,   336,   337,   338,   339,
     160,   340,   341,   342,   343,   332,   519,   525,   333,   334,
     335,   526,   528,   529,   545,   408,   547,   336,   337,   338,
     339,   559,   340,   341,   342,   343,   332,    30,    28,   333,
     334,   335,   124,   353,    78,   409,   437,   336,   337,   338,
     339,   358,   340,   341,   342,   343,   332,   460,   153,   333,
     334,   335,   221,     0,   475,   444,   438,     0,   336,   337,
     338,   339,     0,   340,   341,   342,   343,   332,     0,     0,
     333,   334,   335,     0,     0,     0,     0,   439,   336,   337,
     338,   339,     0,   340,   341,   342,   343,   332,     0,     0,
     333,   334,   335,     0,     0,     0,     0,   441,     0,   336,
     337,   338,   339,     0,   340,   341,   342,   343,   332,     0,
       0,   333,   334,   335,     0,     0,     0,     0,   493,   336,
     337,   338,   339,     0,   340,   341,   342,   343,   332,     0,
       0,   333,   334,   335,     0,     0,     0,     0,   494,     0,
     336,   337,   338,   339,     0,   340,   341,   342,   343,   203,
       0,     0,   204,   205,   206,     0,     0,     0,     0,   495,
     336,   337,   338,   339,     0,   340,   341,   342,   343,   203,
       0,     0,   204,   205,   206,     0,     0,   203,     0,   557,
     204,   205,   206,     0,     0,     0,     0,   207,   208,   209,
       0,     0,   332,     0,     0,   333,   334,   335,     0,     0,
     289,     0,     0,     0,     0,     0,     0,   207,   208,   209,
       0,     0,     0,     0,     0,   207,   208,   209,   332,     0,
     305,   333,   334,   335,   336,   337,   338,   339,   541,   340,
     341,   342,   343,     0,     0,     0,     0,   332,     0,   448,
     333,   334,   335,     0,     0,     0,     0,     0,     0,     0,
     336,   337,   338,   339,     0,   340,   341,   342,   343,   332,
       0,     0,   333,   334,   335,   517,     0,     0,     0,   336,
     337,   338,   339,     0,   340,   341,   342,   343,   332,     0,
       0,   333,   334,   335,   544,     0,     0,     0,     0,     0,
       0,   336,   337,   338,   339,     0,   340,   341,   342,   343,
       0,     0,   332,     0,   434,   333,   334,   335,     0,     0,
     336,   337,   338,   339,     0,   340,   341,   342,   343,     0,
       0,   332,     0,   435,   333,   334,   335,     0,     0,     0,
       0,     0,     0,     0,   336,   337,   338,   339,     0,   340,
     341,   342,   343,     0,     0,   332,     0,   436,   333,   334,
     335,     0,     0,   336,   337,   338,   339,     0,   340,   341,
     342,   343,     0,     0,   332,     0,   440,   333,   334,   335,
     332,     0,     0,   333,   334,   335,     0,   336,   337,   338,
     339,     0,   340,   341,   342,   343,   165,   166,   167,   168,
     169,   170,   171,   172,     0,   173,     0,     0,   338,   339,
       0,   340,   341,   342,   343,     0,     0,     0,   341,   342,
     343
};

static const yytype_int16 yycheck[] =
{
     158,   141,   302,   245,    85,   244,   356,   367,   449,   280,
     150,   120,   128,   178,    53,     3,   285,     3,     4,   178,
       3,    20,     3,     4,    20,    38,   268,     0,     3,     4,
      71,     3,    18,     3,     4,    18,    22,    23,   479,     4,
      26,    27,    28,    71,     3,     4,    15,    60,    51,    35,
      13,    54,    75,    74,    77,    30,    31,   361,     4,    80,
       6,   423,    25,   203,   204,   205,   206,   207,   208,   209,
     370,   512,   432,   433,   155,   156,    79,    45,   320,    82,
       3,     4,    81,    82,    70,   243,    82,   245,   359,    58,
      93,    79,    74,    79,    76,   536,   537,   100,    79,   215,
     258,   259,   371,   463,    79,   144,   456,    79,   458,    79,
      56,    57,   553,   194,    79,     4,    16,     6,   422,   560,
      79,    74,   484,    76,    74,   128,    76,   130,   131,    75,
      98,    99,    29,    79,    72,    32,    33,    34,    74,    12,
     382,     4,    74,     6,    80,   148,    74,    70,    80,   391,
     389,    71,    80,   311,   312,   313,   314,   315,   316,   317,
     318,   320,   462,   272,    63,    64,    65,    56,    57,    66,
      67,    68,    69,   331,   332,   333,   334,   335,   336,   337,
     338,   339,   340,   341,   342,   343,   351,   345,     9,   192,
      79,    72,   351,    56,    57,   354,    74,   356,     3,     4,
     442,     6,    80,    10,    11,    74,    33,    34,   508,   509,
     213,    80,   215,    32,    33,    34,   219,   220,    74,    33,
      34,    14,   522,   382,    80,    30,    31,     4,    74,     6,
      76,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    68,    69,    10,    74,    50,    76,   547,    67,    68,
      69,    56,    57,    30,    31,    69,    32,    33,    34,    74,
      33,    34,    74,    78,    76,    70,     3,     4,    33,    34,
      75,     7,    77,    50,    79,    74,   434,   435,   436,    56,
      57,    80,    77,   442,    79,     3,     4,     3,     4,   454,
       6,    67,    68,    69,    72,   454,    69,   456,    75,   458,
      77,    72,    79,    68,    69,    46,    47,    48,    49,    50,
      51,    52,    53,     3,    30,    31,   474,     3,     4,   477,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      77,    73,    79,    23,    50,    19,    26,    27,    28,    71,
      56,    57,     7,     3,     4,    35,    29,     4,     7,    32,
      33,    34,    33,    34,    70,     3,     4,   515,    18,    75,
      71,    77,    22,    79,    33,    34,    26,    27,    28,    59,
      18,   529,   174,   175,    22,    35,     3,     4,    26,    27,
      28,    71,     8,   523,    67,    68,    69,    35,    78,     8,
      18,    18,     3,   551,    11,    22,    10,    80,     3,    26,
      27,    28,     3,     4,    82,    82,    79,    79,    35,    79,
      70,    71,    79,     3,     4,    23,    72,    18,    78,    79,
      81,    22,    70,    71,    20,    26,    27,    28,    18,    20,
      78,    79,    22,    17,    35,     3,    26,    27,    28,     3,
       4,    20,    20,    70,    71,    35,    61,    62,    63,    64,
      65,    78,    79,     3,    18,    20,     3,    79,    22,    79,
       3,     4,    26,    27,    28,    23,    79,    33,    34,    70,
      71,    35,     3,     4,     3,    18,    79,    78,    79,    22,
      70,    71,     9,    26,    27,    28,     4,    18,    78,    79,
      77,    22,    35,    73,     3,    26,    27,    28,     4,    20,
       6,    67,    68,    69,    35,    20,    70,    71,    21,     3,
      80,    74,    81,    80,    78,    79,   198,   199,   200,   201,
     202,    20,     3,    20,    30,    31,    50,    70,    71,    23,
      79,    73,    26,    27,    28,    78,    79,    75,     3,    70,
      71,    35,    23,    11,    50,    26,    27,    28,    79,    74,
      56,    57,    74,    79,    35,    74,     3,    80,    23,    21,
      21,    26,    27,    28,    21,    59,    77,    74,    80,    75,
      35,    77,    80,    79,    79,    79,    23,    71,    59,    26,
      27,    28,    73,    79,    78,     3,    79,    79,    35,    79,
      71,     3,    79,    79,    59,    75,    75,    78,    74,     3,
      75,    79,     3,    34,    77,    23,    71,    79,    26,    27,
      28,    23,    59,    78,    26,    27,    28,    35,    21,    79,
      33,    34,    23,    35,    71,    26,    27,    28,    79,    21,
      74,    78,    74,    74,    35,    74,    74,    77,     4,    29,
      34,    59,    32,    33,    34,    80,    82,    59,    80,    79,
      79,    75,    77,    71,    67,    68,    69,    76,    59,    71,
      78,    72,    78,    77,    29,    75,    78,    32,    33,    34,
      71,    61,    62,    63,    64,    80,    66,    67,    68,    69,
      79,    76,    80,    74,    29,    25,     5,    32,    33,    34,
      80,    80,    80,    75,    77,    82,    61,    62,    63,    64,
      80,    66,    67,    68,    69,    29,    80,    80,    32,    33,
      34,    73,    24,    77,    77,    80,    61,    62,    63,    64,
      58,    66,    67,    68,    69,    29,     4,    77,    32,    33,
      34,    77,    80,    75,    24,    80,    77,    61,    62,    63,
      64,    77,    66,    67,    68,    69,    29,    20,    19,    32,
      33,    34,    74,   273,    40,   349,    80,    61,    62,    63,
      64,   277,    66,    67,    68,    69,    29,   422,   100,    32,
      33,    34,   153,    -1,   442,   387,    80,    -1,    61,    62,
      63,    64,    -1,    66,    67,    68,    69,    29,    -1,    -1,
      32,    33,    34,    -1,    -1,    -1,    -1,    80,    61,    62,
      63,    64,    -1,    66,    67,    68,    69,    29,    -1,    -1,
      32,    33,    34,    -1,    -1,    -1,    -1,    80,    -1,    61,
      62,    63,    64,    -1,    66,    67,    68,    69,    29,    -1,
      -1,    32,    33,    34,    -1,    -1,    -1,    -1,    80,    61,
      62,    63,    64,    -1,    66,    67,    68,    69,    29,    -1,
      -1,    32,    33,    34,    -1,    -1,    -1,    -1,    80,    -1,
      61,    62,    63,    64,    -1,    66,    67,    68,    69,    29,
      -1,    -1,    32,    33,    34,    -1,    -1,    -1,    -1,    80,
      61,    62,    63,    64,    -1,    66,    67,    68,    69,    29,
      -1,    -1,    32,    33,    34,    -1,    -1,    29,    -1,    80,
      32,    33,    34,    -1,    -1,    -1,    -1,    67,    68,    69,
      -1,    -1,    29,    -1,    -1,    32,    33,    34,    -1,    -1,
      80,    -1,    -1,    -1,    -1,    -1,    -1,    67,    68,    69,
      -1,    -1,    -1,    -1,    -1,    67,    68,    69,    29,    -1,
      80,    32,    33,    34,    61,    62,    63,    64,    80,    66,
      67,    68,    69,    -1,    -1,    -1,    -1,    29,    -1,    76,
      32,    33,    34,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      61,    62,    63,    64,    -1,    66,    67,    68,    69,    29,
      -1,    -1,    32,    33,    34,    76,    -1,    -1,    -1,    61,
      62,    63,    64,    -1,    66,    67,    68,    69,    29,    -1,
      -1,    32,    33,    34,    76,    -1,    -1,    -1,    -1,    -1,
      -1,    61,    62,    63,    64,    -1,    66,    67,    68,    69,
      -1,    -1,    29,    -1,    74,    32,    33,    34,    -1,    -1,
      61,    62,    63,    64,    -1,    66,    67,    68,    69,    -1,
      -1,    29,    -1,    74,    32,    33,    34,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    61,    62,    63,    64,    -1,    66,
      67,    68,    69,    -1,    -1,    29,    -1,    74,    32,    33,
      34,    -1,    -1,    61,    62,    63,    64,    -1,    66,    67,
      68,    69,    -1,    -1,    29,    -1,    74,    32,    33,    34,
      29,    -1,    -1,    32,    33,    34,    -1,    61,    62,    63,
      64,    -1,    66,    67,    68,    69,    46,    47,    48,    49,
      50,    51,    52,    53,    -1,    55,    -1,    -1,    63,    64,
      -1,    66,    67,    68,    69,    -1,    -1,    -1,    67,    68,
      69
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    84,    85,     0,    71,    87,    16,    86,    88,    71,
      89,    72,    93,    12,    71,    91,     9,    72,    94,    95,
      96,    90,    14,    10,     7,   108,   109,    72,    96,    72,
      95,   119,    92,    73,    10,    11,   100,   101,    19,   110,
     111,     7,     7,     3,     4,    18,    22,    26,    27,    28,
      35,    70,    71,    79,   118,   120,   121,   122,   123,   124,
     128,   131,   133,   134,   144,   146,   148,   150,   196,     4,
       8,     8,    71,    18,   102,   103,     3,   118,   110,    82,
     129,   129,    82,     3,    79,    79,    79,     3,   123,    13,
      25,   131,   132,    79,   123,   125,    23,   135,     3,    18,
     118,    81,    26,    27,    28,    35,    59,    71,   173,   175,
     176,   177,   185,   188,   191,   194,   197,   198,   199,    72,
      20,    20,    17,     3,   103,     3,    79,   113,    79,   123,
      20,    20,   123,   145,     3,   143,   143,     3,     4,    30,
      31,    79,   138,   139,    74,    80,   123,   127,    20,   126,
      79,   129,   129,   125,     3,    79,    79,    79,    79,    15,
      58,    23,   178,     3,   171,    46,    47,    48,    49,    50,
      51,    52,    53,    55,   152,   153,   172,     9,    77,    97,
     163,     4,    98,    99,    73,     3,   114,    20,   115,   127,
     123,   123,    20,    21,    74,    80,    80,   139,    61,    62,
      63,    64,    65,    29,    32,    33,    34,    67,    68,    69,
      80,   131,    81,    74,    80,    79,   123,   130,   139,    20,
      20,   126,   186,   143,   143,     3,     4,     6,    30,    31,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      50,    56,    57,    70,    75,    79,   151,   155,   157,   158,
     163,   165,   166,   168,   170,   170,   174,    50,    79,    73,
      75,   171,   171,    11,     4,     6,    56,    57,    79,   156,
     157,   164,    74,    74,    75,    77,   104,    74,    80,     3,
      79,   116,   112,    80,   123,    79,   143,    21,    21,    80,
     138,   138,   138,   138,   138,   139,   139,   139,   139,   139,
     139,   139,    77,   123,   127,    80,   123,   123,    21,    80,
      80,    79,    79,    79,    79,    79,    79,    79,    79,   170,
      75,   159,   160,   165,   167,     4,     6,    56,    57,   156,
     170,    75,    29,    32,    33,    34,    61,    62,    63,    64,
      66,    67,    68,    69,    80,    74,    80,   170,   170,   154,
      73,    74,   163,    99,    75,   105,    79,   106,   114,    74,
     116,    75,     3,     4,   140,   141,    79,    79,   119,    80,
      77,    79,    21,    21,   170,   170,   170,   170,   170,   170,
     170,   170,    75,   156,   157,   161,   162,    74,    76,    74,
      76,    74,    80,   170,   170,   170,   170,   170,   170,   170,
     170,   170,   170,   170,   170,   170,    77,   170,    80,   152,
       4,   164,   107,   164,    74,    76,   107,    74,    78,   116,
      80,   117,   121,    82,    80,   141,   142,   142,    71,    78,
     119,   141,    79,    79,    74,    74,    74,    80,    80,    80,
      74,    80,    74,    76,   160,    75,   165,   156,    76,   195,
      77,    76,    72,    78,    74,    76,    75,    80,    79,    76,
     117,   140,    77,    74,    80,    80,    78,    80,   142,   142,
     170,   170,   170,     4,    79,   162,    80,    75,   196,   179,
       5,   164,   107,   107,    82,   119,   142,   147,   149,   136,
      77,    80,    80,    80,    80,    80,    80,   169,   170,   170,
      71,    78,   196,    73,    76,    80,   140,    78,    77,    77,
      24,   137,   187,   189,   192,    74,    80,    76,    78,     4,
     119,   119,    77,    79,   196,    77,    77,   170,    80,    75,
     180,    78,    78,   119,   139,    78,   190,   193,   170,   181,
      78,    80,   196,   196,    76,    24,   183,    77,    78,    78,
      77,    79,   119,   184,   170,    78,   196,    80,    78,    77,
     182,   196,    78
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    83,    85,    86,    84,    88,    87,    90,    89,    92,
      91,    93,    94,    94,    94,    94,    94,    95,    96,    97,
      97,    98,    98,    99,   101,   100,   100,   102,   102,   103,
     104,   104,   105,   105,   106,   106,   107,   107,   109,   108,
     110,   110,   112,   111,   113,   113,   114,   114,   115,   115,
     115,   116,   116,   117,   117,   118,   119,   119,   120,   120,
     121,   121,   122,   121,   121,   121,   121,   121,   123,   123,
     124,   124,   124,   124,   124,   124,   125,   125,   126,   126,
     127,   127,   128,   128,   129,   129,   129,   130,   130,   131,
     131,   132,   132,   133,   134,   135,   136,   136,   137,   137,
     138,   138,   138,   138,   138,   138,   138,   139,   139,   139,
     139,   139,   139,   139,   139,   139,   139,   139,   140,   140,
     141,   141,   142,   142,   143,   143,   145,   144,   147,   146,
     149,   148,   150,   151,   151,   151,   152,   152,   152,   152,
     152,   152,   152,   152,   154,   153,   155,   155,   156,   156,
     156,   156,   157,   158,   159,   159,   160,   161,   161,   162,
     162,   163,   164,   164,   165,   165,   165,   165,   165,   165,
     165,   165,   165,   166,   167,   167,   168,   168,   168,   168,
     168,   168,   168,   168,   168,   169,   169,   170,   170,   170,
     170,   170,   170,   170,   170,   170,   170,   170,   170,   170,
     170,   170,   170,   170,   170,   170,   170,   170,   171,   172,
     172,   173,   174,   174,   175,   177,   176,   176,   176,   176,
     176,   179,   180,   178,   182,   181,   181,   184,   183,   183,
     186,   187,   185,   189,   190,   188,   192,   193,   191,   195,
     194,   196,   196,   197,   197,   197,   198,   197,   199,   197
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     0,     5,     0,     9,     0,     6,     0,
       6,    14,     2,     2,     1,     1,     0,     6,     6,     3,
       1,     3,     1,     1,     0,     2,     0,     2,     1,     4,
       3,     3,     5,     3,     5,     3,     3,     1,     0,     2,
       2,     0,     0,     8,     1,     3,     3,     1,     0,     4,
       2,     3,     1,     0,     2,     1,     2,     0,     1,     1,
       1,     1,     0,     2,     1,     1,     1,     1,     1,     1,
       5,     5,     4,     4,     4,     3,     1,     3,     0,     2,
       3,     1,     2,     4,     0,     2,     4,     1,     3,     1,
       2,     3,     1,     5,     2,     9,     8,     0,     4,     0,
       3,     3,     3,     3,     3,     1,     1,     3,     3,     3,
       3,     3,     3,     3,     3,     1,     1,     1,     1,     1,
       3,     5,     3,     1,     3,     1,     0,    10,     0,    12,
       0,    12,     7,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     0,     5,     1,     1,     1,     1,
       1,     1,     5,     3,     3,     1,     3,     3,     1,     1,
       1,     5,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     3,     1,     6,     6,     6,     4,
       4,     6,     8,     4,     4,     3,     1,     1,     1,     1,
       4,     7,    10,     1,     3,     2,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     2,
       2,     4,     3,     1,     3,     0,     2,     1,     1,     1,
       1,     0,     0,    11,     0,     9,     0,     0,     5,     0,
       0,     0,    11,     0,     0,    13,     0,     0,    13,     0,
       8,     2,     0,     1,     1,     1,     0,     2,     0,     2
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
  case 2: /* $@1: %empty  */
#line 85 "./Parser/parser_main.y"
                          {fprintf(out,"#include<iostream>\n"
                                        "#include<vector>\n"
                                        "#include\"../CodeGen/Basic/complex.h\"\n"
                                        "#include\"../CodeGen/Basic/matrix.h\"\n"
                                        "#include\"../CodeGen/Basic/type.h\"\n"
                                        "#include\"../CodeGen/Basic/state.h\"\n\n"
                                        "using namespace std;\n\n");
                          }
#line 1829 "./exec/y.tab.c"
    break;

  case 3: /* $@2: %empty  */
#line 94 "./Parser/parser_main.y"
                          {fprintf(out,"\nint main(){\nfor(int i=0; i<quantum_registers; i++) {quantum_register_map[i] = i;}\n");}
#line 1835 "./exec/y.tab.c"
    break;

  case 4: /* prgm: $@1 init_section $@2 main_section output_section  */
#line 97 "./Parser/parser_main.y"
                          {fprintf(out,"}\n");fprintf(fp,"\nParsing successful!\n");}
#line 1841 "./exec/y.tab.c"
    break;

  case 5: /* $@3: %empty  */
#line 101 "./Parser/parser_main.y"
                                           {fprintf(fp,"\nInit section begins\n\n");}
#line 1847 "./exec/y.tab.c"
    break;

  case 6: /* init_section: '\\' INIT_BEGIN $@3 mandatory_init set_states block_defn_section gate_defn_section '\\' INIT_END  */
#line 101 "./Parser/parser_main.y"
                                                                                                                                                                   {fprintf(fp,"\nInit section ends\n");}
#line 1853 "./exec/y.tab.c"
    break;

  case 7: /* $@4: %empty  */
#line 104 "./Parser/parser_main.y"
                                            {fprintf(fp,"\nMain section begins\n\n");}
#line 1859 "./exec/y.tab.c"
    break;

  case 8: /* main_section: '\\' MAIN_BEGIN $@4 main_stmt_list '\\' MAIN_END  */
#line 104 "./Parser/parser_main.y"
                                                                                                                    {fprintf(fp,"\nMain section ends\n");}
#line 1865 "./exec/y.tab.c"
    break;

  case 9: /* $@5: %empty  */
#line 107 "./Parser/parser_main.y"
                                             {fprintf(fp,"\nOutput section begins\n\n"); isInOutput = true; outputLevel = 1;}
#line 1871 "./exec/y.tab.c"
    break;

  case 10: /* output_section: '\\' OUTPUT_BEGIN $@5 out_main '\\' OUTPUT_END  */
#line 107 "./Parser/parser_main.y"
                                                                                                                                                        {fprintf(fp,"\nOutput section ends\n");exitOutputSymbolScope(&OutputSymbolTable,outputLevel);}
#line 1877 "./exec/y.tab.c"
    break;

  case 11: /* mandatory_init: '#' REGISTERS QUANTUM '=' NUMBER '#' REGISTERS CLASSICAL '=' NUMBER '#' ITERS '=' NUMBER  */
#line 115 "./Parser/parser_main.y"
                                                                                                                    {  fprintf(fp,"Register and iteration initialization section\n");
                                                                                                                        classical_registers = yyvsp[-4].num;
                                                                                                                        quantum_registers = yyvsp[-9].num;
                                                                                                                        iterations = yyvsp[0].num;
                                                                                                                        fprintf(out,"int num_iterations = %d;\n", iterations);
                                                                                                                        fprintf(out,"int quantum_registers = %d;\n", quantum_registers);
                                                                                                                        fprintf(out,"int classical_registers = %d;\n\n", classical_registers);
                                                                                                                        fprintf(out, "int quantum_register_map[%d];\n", quantum_registers);
                                                                                                                     }
#line 1891 "./exec/y.tab.c"
    break;

  case 17: /* set_quantum_states: '#' SET QUANTUM STATES ARROW quantum_state_list  */
#line 134 "./Parser/parser_main.y"
                                                                            { fprintf(fp,"Setting initial state of quantum registers\n");
                                                                              fprintf(out, "struct Quantum q[%d] = {%s};\nStateVec q_output = StateVec(%d,q);\n", quantum_registers,yyvsp[0].str, quantum_registers);
                                                                            }
#line 1899 "./exec/y.tab.c"
    break;

  case 18: /* set_classical_states: '#' SET CLASSICAL STATES ARROW classical_state_list  */
#line 139 "./Parser/parser_main.y"
                                                                                {   fprintf(fp,"Setting initial state of classical registers\n");
                                                                                    fprintf(out, "int c_output[%d] = {%s};\n", classical_registers,yyvsp[0].str);
                                                                                }
#line 1907 "./exec/y.tab.c"
    break;

  case 19: /* quantum_state_list: quantum_state_list ',' state_const  */
#line 144 "./Parser/parser_main.y"
                                                                     {  if(quantum_index == quantum_registers){
                                                                           yyerror("semantic error: quantum registers out of bounds");
                                                                           return 1;
                                                                        }  
                                                                        yyval.str = (char *)malloc(sizeof(char)*(strlen(yyvsp[-2].str)+110+2));
                                                                        snprintf(yyval.str,strlen(yyvsp[-2].str)+110+2,"%s,Quantum(Complex(%f,%f),Complex(%f,%f))",yyvsp[-2].str,yyvsp[0].q.first.real,yyvsp[0].q.first.imag,yyvsp[0].q.second.real,yyvsp[0].q.second.imag);
                                                                        quantum_index++;
                                                                     }
#line 1920 "./exec/y.tab.c"
    break;

  case 20: /* quantum_state_list: state_const  */
#line 152 "./Parser/parser_main.y"
                                                                     {  
                                                                        yyval.str = (char *)malloc(sizeof(char)*110);
                                                                        snprintf(yyval.str,110,"Quantum(Complex(%f,%f),Complex(%f,%f))",yyvsp[0].q.first.real,yyvsp[0].q.first.imag,yyvsp[0].q.second.real,yyvsp[0].q.second.imag);
                                                                        quantum_index = 1;
                                                                     }
#line 1930 "./exec/y.tab.c"
    break;

  case 21: /* classical_state_list: classical_state_list ',' classical_state  */
#line 159 "./Parser/parser_main.y"
                                                                     { if(classical_index == classical_registers){
                                                                           yyerror("semantic error: classical registers out of bounds");
                                                                           return 1;
                                                                        }
                                                                        yyval.str = (char *)malloc(sizeof(char)*(strlen(yyvsp[-2].str)+20+2));
                                                                        snprintf(yyval.str,strlen(yyvsp[-2].str)+20+2,"%s,%d",yyvsp[-2].str,yyvsp[0].num);
                                                                        classical_index++;
                                                                     }
#line 1943 "./exec/y.tab.c"
    break;

  case 22: /* classical_state_list: classical_state  */
#line 167 "./Parser/parser_main.y"
                                                                     {  yyval.str = (char *)malloc(sizeof(char)*20);
                                                                        snprintf(yyval.str,20,"%d",yyvsp[0].num);
                                                                        classical_index  = 1;
                                                                     }
#line 1952 "./exec/y.tab.c"
    break;

  case 23: /* classical_state: NUMBER  */
#line 173 "./Parser/parser_main.y"
                                                                     {yyval.num = yyvsp[0].num;}
#line 1958 "./exec/y.tab.c"
    break;

  case 24: /* $@6: %empty  */
#line 177 "./Parser/parser_main.y"
                           {fprintf(fp,"Gate definition section begins\n");}
#line 1964 "./exec/y.tab.c"
    break;

  case 25: /* gate_defn_section: $@6 gate_defn_list  */
#line 177 "./Parser/parser_main.y"
                                                                                            {fprintf(fp,"Gate definition section ends\n");}
#line 1970 "./exec/y.tab.c"
    break;

  case 29: /* gate_defn: GATE ID '=' rhs  */
#line 185 "./Parser/parser_main.y"
                                             {  fprintf(fp,"Gate definition\n");
                                                if(!insertInGateTable(&GateSymbolTable,yyvsp[-2].str,yyvsp[0].rows,yyvsp[0].cols)){
                                                   yyerror("semantic error: gate definition requires square matrix");
                                                   return 1;
                                                }
                                             }
#line 1981 "./exec/y.tab.c"
    break;

  case 30: /* rhs: '[' tuple_list ']'  */
#line 193 "./Parser/parser_main.y"
                                                {yyval.rows = yyvsp[-1].rows;yyval.cols = yyvsp[-1].cols;}
#line 1987 "./exec/y.tab.c"
    break;

  case 32: /* tuple_list: tuple_list ',' '[' id_list ']'  */
#line 196 "./Parser/parser_main.y"
                                                         {  if(yyvsp[-4].cols != yyvsp[-1].cols){
                                                               yyerror("semantic error: rows of different length cannot form matrix");
                                                               return 1;
                                                            }
                                                            int temp = yyvsp[-4].rows + 1;
                                                            yyval.rows = temp;
                                                            yyval.cols = yyvsp[-4].cols;
                                                         }
#line 2000 "./exec/y.tab.c"
    break;

  case 33: /* tuple_list: '[' id_list ']'  */
#line 204 "./Parser/parser_main.y"
                                                         {yyval.rows = 1;yyval.cols = yyvsp[-1].cols;}
#line 2006 "./exec/y.tab.c"
    break;

  case 36: /* id_list: id_list ',' temp  */
#line 209 "./Parser/parser_main.y"
                                             {yyval.cols += 1;}
#line 2012 "./exec/y.tab.c"
    break;

  case 37: /* id_list: temp  */
#line 210 "./Parser/parser_main.y"
                                             {yyval.cols = 1;}
#line 2018 "./exec/y.tab.c"
    break;

  case 38: /* $@7: %empty  */
#line 213 "./Parser/parser_main.y"
                           {fprintf(fp,"Block definition section begins\n");}
#line 2024 "./exec/y.tab.c"
    break;

  case 39: /* block_defn_section: $@7 block_defns_list  */
#line 213 "./Parser/parser_main.y"
                                                                                               {fprintf(fp,"Block definition section ends\n");}
#line 2030 "./exec/y.tab.c"
    break;

  case 42: /* $@8: %empty  */
#line 220 "./Parser/parser_main.y"
                                                               {  if(!insertInBlockTable(&BlockSymbolTable,yyvsp[-2].str,yyvsp[-1].num,head)){
                                                                     yyerror("semantic error: incorrect block definition");
                                                                     return 1;
                                                                  }
                                                                  head = NULL;
                                                                  isInBlock = 1;
                                                               }
#line 2042 "./exec/y.tab.c"
    break;

  case 43: /* block_defn: BLOCK block_id params target_params $@8 '[' block_body ']'  */
#line 227 "./Parser/parser_main.y"
                                                               {  fprintf(fp,"Block definition\n");
                                                                  if(!BlockSemanticCheck(yyvsp[-6].str)){
                                                                     yyerror("semantic error: incorrect block definition");
                                                                     return 1;
                                                                  }
                                                                  id_list = NULL;
                                                                  isInBlock = 0;
                                                               }
#line 2055 "./exec/y.tab.c"
    break;

  case 44: /* params: ID  */
#line 237 "./Parser/parser_main.y"
                                                {insertInList(&head,yyvsp[0].str);yyval.num = 1;}
#line 2061 "./exec/y.tab.c"
    break;

  case 45: /* params: '(' param_id_list ')'  */
#line 238 "./Parser/parser_main.y"
                                                {yyval.num = yyvsp[-1].num;}
#line 2067 "./exec/y.tab.c"
    break;

  case 46: /* param_id_list: ID ',' param_id_list  */
#line 241 "./Parser/parser_main.y"
                                                {insertInList(&head,yyvsp[-2].str);yyval.num = 1 + yyvsp[0].num;}
#line 2073 "./exec/y.tab.c"
    break;

  case 47: /* param_id_list: ID  */
#line 242 "./Parser/parser_main.y"
                                                {insertInList(&head,yyvsp[0].str);yyval.num = 1;}
#line 2079 "./exec/y.tab.c"
    break;

  case 55: /* block_id: ID  */
#line 258 "./Parser/parser_main.y"
                                 {  if(!firstLetterCapital(yyvsp[0].str)){
                                       yyerror("lexical error: block identifiers start with uppercase letter");
                                       return 1;
                                    } 
                                    assignString(yyval.str,yyvsp[0].str);
                                 }
#line 2090 "./exec/y.tab.c"
    break;

  case 59: /* main_stmt: barrier_stmt  */
#line 276 "./Parser/parser_main.y"
                                          {fprintf(fp,"barrier statement\n");}
#line 2096 "./exec/y.tab.c"
    break;

  case 61: /* stmts: measure_stmt  */
#line 279 "./Parser/parser_main.y"
                                          {fprintf(fp,"Measure statement\n");}
#line 2102 "./exec/y.tab.c"
    break;

  case 62: /* $@9: %empty  */
#line 280 "./Parser/parser_main.y"
                          {fprintf(fp,"Conditional statement begin\n");}
#line 2108 "./exec/y.tab.c"
    break;

  case 63: /* stmts: $@9 condition_stmt  */
#line 280 "./Parser/parser_main.y"
                                                                                        {fprintf(fp,"Conditional statement end\n");}
#line 2114 "./exec/y.tab.c"
    break;

  case 64: /* stmts: for_stmt  */
#line 281 "./Parser/parser_main.y"
                                          {fprintf(fp,"For statement\n");}
#line 2120 "./exec/y.tab.c"
    break;

  case 65: /* stmts: for_lex_stmt  */
#line 282 "./Parser/parser_main.y"
                                          {fprintf(fp,"For - Lex statement\n");}
#line 2126 "./exec/y.tab.c"
    break;

  case 66: /* stmts: for_zip_stmt  */
#line 283 "./Parser/parser_main.y"
                                          {fprintf(fp,"For - Zip statement\n");}
#line 2132 "./exec/y.tab.c"
    break;

  case 67: /* stmts: while_stmt  */
#line 284 "./Parser/parser_main.y"
                                          {fprintf(fp,"while statement\n");}
#line 2138 "./exec/y.tab.c"
    break;

  case 68: /* register: NUMBER  */
#line 287 "./Parser/parser_main.y"
                                  { if(yyvsp[0].num < 0){
                                       yyerror("semantic error: register numbers are non-negative");
                                       return 1;
                                    } 
                                    yyval.num = yyvsp[0].num;
                                    yyval.flag=0;
                                    yyval.str = (char *)malloc(sizeof(char)*20);
                                    snprintf(yyval.str,20,"%d",yyvsp[0].num);
                                 }
#line 2152 "./exec/y.tab.c"
    break;

  case 69: /* register: ID  */
#line 296 "./Parser/parser_main.y"
                                  {if(isInBlock){insertInList(&id_list,yyvsp[0].str);}yyval.flag = 1;
                                    assignString(yyval.str,yyvsp[0].str);
                                 }
#line 2160 "./exec/y.tab.c"
    break;

  case 70: /* call_stmt: classic_control GATE quantum_control ARROW register  */
#line 303 "./Parser/parser_main.y"
                                                                              {
                                                                                 fprintf(fp,"Pre - defined Gate call statement\n");
                                                                                 fprintf(out, "if(%s) {\n", yyvsp[-4].str);
                                                                                 free(yyvsp[-4].str);
                                                                                 fprintf(out, "}\n");
                                                                                 //free($5.str);
                                                                              }
#line 2172 "./exec/y.tab.c"
    break;

  case 71: /* call_stmt: classic_control ID quantum_control ARROW register  */
#line 310 "./Parser/parser_main.y"
                                                                              {fprintf(fp,"user - defined Gate call statement\n");
                                                                                 //free($5.str);
                                                                              }
#line 2180 "./exec/y.tab.c"
    break;

  case 72: /* call_stmt: GATE quantum_control ARROW register  */
#line 313 "./Parser/parser_main.y"
                                                                              {fprintf(fp,"Pre - defined Gate call statement\n");
                                                                                 //free($4.str);
                                                                              }
#line 2188 "./exec/y.tab.c"
    break;

  case 73: /* call_stmt: ID quantum_control ARROW register  */
#line 316 "./Parser/parser_main.y"
                                                                              {fprintf(fp,"User - defined Gate call statement\n");
                                                                                 //free($4.str);
                                                                              }
#line 2196 "./exec/y.tab.c"
    break;

  case 74: /* call_stmt: classic_control block_id parameters optional  */
#line 319 "./Parser/parser_main.y"
                                                                              {  fprintf(fp,"Block call statement\n");
                                                                                 if(!isInBlock){
                                                                                    if(!BlockCallSemanticCheck(yyvsp[-2].str,yyvsp[-1].num)){
                                                                                       yyerror("semantic error: block not defined");
                                                                                       return 1;
                                                                                    }
                                                                                 }
                                                                              }
#line 2209 "./exec/y.tab.c"
    break;

  case 75: /* call_stmt: block_id parameters optional  */
#line 327 "./Parser/parser_main.y"
                                                                              {  fprintf(fp,"Block call statement\n");
                                                                                 if(!isInBlock){
                                                                                    if(!BlockCallSemanticCheck(yyvsp[-2].str,yyvsp[-1].num)){
                                                                                       yyerror("semantic error: block not defined");
                                                                                       return 1;
                                                                                    }
                                                                                 }
                                                                              }
#line 2222 "./exec/y.tab.c"
    break;

  case 76: /* parameters: register  */
#line 337 "./Parser/parser_main.y"
                                                   {yyval.num = 1; free(yyvsp[0].str);}
#line 2228 "./exec/y.tab.c"
    break;

  case 77: /* parameters: '(' register_list ')'  */
#line 338 "./Parser/parser_main.y"
                                                   {yyval.num = yyvsp[-1].num;}
#line 2234 "./exec/y.tab.c"
    break;

  case 80: /* register_list: register_list ',' register  */
#line 345 "./Parser/parser_main.y"
                                                      {yyval.num = 1 + yyvsp[-2].num; free(yyvsp[0].str);}
#line 2240 "./exec/y.tab.c"
    break;

  case 81: /* register_list: register  */
#line 346 "./Parser/parser_main.y"
                                                      {yyval.num = 1; free(yyvsp[0].str);}
#line 2246 "./exec/y.tab.c"
    break;

  case 82: /* classic_control: register_expr '?'  */
#line 349 "./Parser/parser_main.y"
                                                            {
                                                               yyval.str = (char *)malloc(sizeof(char)*(strlen(yyvsp[-1].str)+1));
                                                               snprintf(yyval.str,strlen(yyvsp[-1].str)+1,"%s",yyvsp[-1].str); 
                                                               // assignString($$.str,$1.str); 
                                                               free(yyvsp[-1].str); 
                                                            }
#line 2257 "./exec/y.tab.c"
    break;

  case 83: /* classic_control: '(' register_expr_list ')' '?'  */
#line 355 "./Parser/parser_main.y"
                                                            {
                                                               yyval.str = (char *)malloc(sizeof(char)*(strlen(yyvsp[-2].str)+1));
                                                               snprintf(yyval.str,strlen(yyvsp[-2].str)+1,"%s",yyvsp[-2].str);
                                                               // assignString($$.str,$2.str);
                                                               free(yyvsp[-2].str);
                                                            }
#line 2268 "./exec/y.tab.c"
    break;

  case 85: /* quantum_control: ':' register  */
#line 364 "./Parser/parser_main.y"
                                                               {free(yyvsp[0].str);}
#line 2274 "./exec/y.tab.c"
    break;

  case 87: /* target: register  */
#line 368 "./Parser/parser_main.y"
                                                             {free(yyvsp[0].str);}
#line 2280 "./exec/y.tab.c"
    break;

  case 89: /* register_expr: register  */
#line 373 "./Parser/parser_main.y"
                                                                     {
                                                                        yyval.str = (char *)malloc(sizeof(char)*(strlen(yyvsp[0].str)+11));
                                                                        snprintf(yyval.str,strlen(yyvsp[0].str)+11,"c_output[%s]",yyvsp[0].str);
                                                                        free(yyvsp[0].str);
                                                                     }
#line 2290 "./exec/y.tab.c"
    break;

  case 90: /* register_expr: '!' register  */
#line 378 "./Parser/parser_main.y"
                                                                     {
                                                                        yyval.str = (char *)malloc(sizeof(char)*(strlen(yyvsp[0].str)+12));
                                                                        snprintf(yyval.str,strlen(yyvsp[0].str)+12,"!c_output[%s]",yyvsp[0].str);
                                                                        free(yyvsp[0].str);
                                                                     }
#line 2300 "./exec/y.tab.c"
    break;

  case 91: /* register_expr_list: register_expr_list ',' register_expr  */
#line 385 "./Parser/parser_main.y"
                                                                     {
                                                                        yyval.str = (char *)malloc(sizeof(char)*(strlen(yyvsp[-2].str)+strlen(yyvsp[0].str)+7));
                                                                        snprintf(yyval.str,strlen(yyvsp[-2].str)+strlen(yyvsp[0].str)+7,"%s && (%s)",yyvsp[-2].str,yyvsp[0].str);
                                                                        free(yyvsp[-2].str);
                                                                        free(yyvsp[0].str);    
                                                                     }
#line 2311 "./exec/y.tab.c"
    break;

  case 92: /* register_expr_list: register_expr  */
#line 391 "./Parser/parser_main.y"
                                                                     {
                                                                        yyval.str = (char *)malloc(sizeof(char)*(strlen(yyvsp[0].str)+3));
                                                                        snprintf(yyval.str,strlen(yyvsp[0].str)+3,"(%s)",yyvsp[0].str);
                                                                        free(yyvsp[0].str);
                                                                     }
#line 2321 "./exec/y.tab.c"
    break;

  case 93: /* measure_stmt: MEASURE ':' register ARROW register  */
#line 399 "./Parser/parser_main.y"
                                                              {
                           if((!yyvsp[-2].flag && (yyvsp[-2].num < 0 || yyvsp[-2].num >= quantum_registers)) || (!yyvsp[0].flag && (yyvsp[0].num < 0 || yyvsp[0].num >= classical_registers))){
                              yyerror("semantic error: register number out of bounds"); 
                              return 1;
                           }
                        }
#line 2332 "./exec/y.tab.c"
    break;

  case 118: /* value: NUMBER  */
#line 444 "./Parser/parser_main.y"
                                             {yyval.str = IntToString(yyvsp[0].num);}
#line 2338 "./exec/y.tab.c"
    break;

  case 119: /* value: ID  */
#line 445 "./Parser/parser_main.y"
                                             {yyval.str = yyvsp[0].str;}
#line 2344 "./exec/y.tab.c"
    break;

  case 120: /* range: value ':' value  */
#line 448 "./Parser/parser_main.y"
                                             {yyval.start = IntToString(yyvsp[-2].num); yyval.end = IntToString(yyvsp[0].num); yyval.step = IntToString(1);}
#line 2350 "./exec/y.tab.c"
    break;

  case 121: /* range: value ':' value ':' value  */
#line 449 "./Parser/parser_main.y"
                                                      {yyval.start = IntToString(yyvsp[-4].num); yyval.end = IntToString(yyvsp[-2].num); yyval.step = IntToString(yyvsp[0].num);}
#line 2356 "./exec/y.tab.c"
    break;

  case 122: /* range_list: range ',' range_list  */
#line 452 "./Parser/parser_main.y"
                                                   {  yyval.num = 1 + yyvsp[0].num;
                                                      struct List2* newNode = (struct List2*)malloc(sizeof(struct List2));
                                                      newNode->start = yyvsp[-2].start;
                                                      newNode->end = yyvsp[-2].end;
                                                      newNode->step = yyvsp[-2].step;
                                                      newNode->next = range_list;
                                                      range_list = newNode;
                                                   }
#line 2369 "./exec/y.tab.c"
    break;

  case 123: /* range_list: range  */
#line 460 "./Parser/parser_main.y"
                                                   {  yyval.num = 1;
                                                      struct List2* newNode = (struct List2*)malloc(sizeof(struct List2));
                                                      newNode->start = yyvsp[0].start;
                                                      newNode->end = yyvsp[0].end;
                                                      newNode->step = yyvsp[0].step;
                                                      newNode->next = NULL;
                                                      range_list = newNode;
                                                   }
#line 2382 "./exec/y.tab.c"
    break;

  case 124: /* var_list: ID ',' var_list  */
#line 470 "./Parser/parser_main.y"
                                            {  if(isInOutput){
                                                   if(getOutputSymbolEntry(&OutputSymbolTable,yyvsp[-2].str,outputLevel + 1,1) == NULL){
                                                      yyerror("semantic error: variable used without declaration");
                                                      return 1;
                                                   }
                                                }     
                                                if(!inList(&head,yyvsp[-2].str)){
                                                   insertInList(&head,yyvsp[-2].str);
                                                } 
                                                else {
                                                   yyerror("semantic error: loop variable redeclaration");
                                                   return 1;
                                                } 
                                                yyval.num = 1 + yyvsp[0].num;
                                             }
#line 2402 "./exec/y.tab.c"
    break;

  case 125: /* var_list: ID  */
#line 485 "./Parser/parser_main.y"
                                             {  if(isInOutput){
                                                   if(getOutputSymbolEntry(&OutputSymbolTable,yyvsp[0].str,outputLevel + 1,1) == NULL){
                                                      yyerror("semantic error: variable redeclaration");
                                                      return 1;
                                                   }
                                                } 
                                                if(!inList(&head,yyvsp[0].str)){
                                                   insertInList(&head,yyvsp[0].str);
                                                } 
                                                else{
                                                   yyerror("semantic error: loop variable redeclaration");
                                                   return 1;
                                                } 
                                                yyval.num = 1;
                                             }
#line 2422 "./exec/y.tab.c"
    break;

  case 126: /* $@10: %empty  */
#line 502 "./Parser/parser_main.y"
                                 {  if(!inList(&head,yyvsp[0].str)){
                                       insertInList(&head,yyvsp[0].str);
                                    } 
                                    else{
                                       yyerror("semantic error: loop variable redeclaration"); 
                                       return 1;
                                    }
                                 }
#line 2435 "./exec/y.tab.c"
    break;

  case 127: /* for_stmt: FOR ID $@10 IN '(' range ')' '{' main_stmt_list '}'  */
#line 510 "./Parser/parser_main.y"
                                                                  {removeTopKFromList(&head,1);}
#line 2441 "./exec/y.tab.c"
    break;

  case 128: /* $@11: %empty  */
#line 513 "./Parser/parser_main.y"
                                                                         { if(yyvsp[-5].num != yyvsp[-1].num){
                                                                              yyerror("semantic error: mismatch in loop variables and ranges"); 
                                                                              return 1;
                                                                           }
                                                                         }
#line 2451 "./exec/y.tab.c"
    break;

  case 129: /* for_lex_stmt: FOR_LEX '(' var_list ')' IN '(' range_list ')' $@11 '{' main_stmt_list '}'  */
#line 518 "./Parser/parser_main.y"
                                                 {removeTopKFromList(&head,yyvsp[-9].num);}
#line 2457 "./exec/y.tab.c"
    break;

  case 130: /* $@12: %empty  */
#line 521 "./Parser/parser_main.y"
                                                                         { if(yyvsp[-5].num != yyvsp[-1].num){
                                                                              yyerror("semantic error: mismatch in loop variables and ranges"); 
                                                                              return 1;
                                                                           }
                                                                         }
#line 2467 "./exec/y.tab.c"
    break;

  case 131: /* for_zip_stmt: FOR_ZIP '(' var_list ')' IN '(' range_list ')' $@12 '{' main_stmt_list '}'  */
#line 526 "./Parser/parser_main.y"
                                                 {removeTopKFromList(&head,yyvsp[-9].num);}
#line 2473 "./exec/y.tab.c"
    break;

  case 133: /* out_id: ID  */
#line 538 "./Parser/parser_main.y"
                               {yyval.out_flag = 0; yyval.str = yyvsp[0].str;}
#line 2479 "./exec/y.tab.c"
    break;

  case 134: /* out_id: COUT  */
#line 539 "./Parser/parser_main.y"
                               {yyval.out_flag = 1; yyval.type = Int; yyval.prim = false; yyval.dim = (1 << classical_registers); yyval.rows = 0;yyval.str = yyvsp[0].str;}
#line 2485 "./exec/y.tab.c"
    break;

  case 135: /* out_id: QOUT  */
#line 540 "./Parser/parser_main.y"
                               {yyval.out_flag = 2; yyval.type = State; yyval.prim = false; yyval.dim = quantum_registers; yyval.rows = 0;yyval.str = yyvsp[0].str;}
#line 2491 "./exec/y.tab.c"
    break;

  case 136: /* prim_type: INT  */
#line 543 "./Parser/parser_main.y"
                                    {yyval.type = Int; yyval.prim = true;fprintf(out,"int ");}
#line 2497 "./exec/y.tab.c"
    break;

  case 137: /* prim_type: UINT  */
#line 544 "./Parser/parser_main.y"
                                    {yyval.type = Uint; yyval.prim = true;fprintf(out,"unsigned int ");}
#line 2503 "./exec/y.tab.c"
    break;

  case 138: /* prim_type: FLOAT  */
#line 545 "./Parser/parser_main.y"
                                    {yyval.type = Float; yyval.prim = true;fprintf(out,"float ");}
#line 2509 "./exec/y.tab.c"
    break;

  case 139: /* prim_type: COMPLEX  */
#line 546 "./Parser/parser_main.y"
                                    {yyval.type = Complex; yyval.prim = true;fprintf(out,"Complex ");}
#line 2515 "./exec/y.tab.c"
    break;

  case 140: /* prim_type: STRING  */
#line 547 "./Parser/parser_main.y"
                                    {yyval.type = String; yyval.prim = true;fprintf(out,"string ");}
#line 2521 "./exec/y.tab.c"
    break;

  case 141: /* prim_type: MATRIX  */
#line 548 "./Parser/parser_main.y"
                                    {yyval.type = Matrix; yyval.prim = true;fprintf(out,"Matrix ");}
#line 2527 "./exec/y.tab.c"
    break;

  case 142: /* prim_type: STATE  */
#line 549 "./Parser/parser_main.y"
                                    {yyval.type = State; yyval.prim = true;fprintf(out,"StateVec ");}
#line 2533 "./exec/y.tab.c"
    break;

  case 143: /* prim_type: BOOL  */
#line 550 "./Parser/parser_main.y"
                                    {yyval.type = Bool; yyval.prim = true;fprintf(out,"bool ");}
#line 2539 "./exec/y.tab.c"
    break;

  case 144: /* @13: %empty  */
#line 553 "./Parser/parser_main.y"
                                   {fprintf(out,"vector<");}
#line 2545 "./exec/y.tab.c"
    break;

  case 145: /* list_type: LIST '[' @13 prim_type ']'  */
#line 553 "./Parser/parser_main.y"
                                                                           {yyval.type = yyvsp[-2].type; yyval.prim = false;fprintf(out,">");}
#line 2551 "./exec/y.tab.c"
    break;

  case 146: /* bool_const: TRUE  */
#line 560 "./Parser/parser_main.y"
                                    {yyval.num = 1;}
#line 2557 "./exec/y.tab.c"
    break;

  case 147: /* bool_const: FALSE  */
#line 561 "./Parser/parser_main.y"
                                    {yyval.num = 0;}
#line 2563 "./exec/y.tab.c"
    break;

  case 148: /* num: DEC  */
#line 564 "./Parser/parser_main.y"
                                    {yyval.real = yyvsp[0].real;}
#line 2569 "./exec/y.tab.c"
    break;

  case 149: /* num: NEG  */
#line 565 "./Parser/parser_main.y"
                                    {yyval.real = yyvsp[0].real;}
#line 2575 "./exec/y.tab.c"
    break;

  case 150: /* num: EXP  */
#line 566 "./Parser/parser_main.y"
                                    {yyval.real = yyvsp[0].real;}
#line 2581 "./exec/y.tab.c"
    break;

  case 151: /* num: NUMBER  */
#line 567 "./Parser/parser_main.y"
                                    {yyval.real = yyvsp[0].num;}
#line 2587 "./exec/y.tab.c"
    break;

  case 152: /* complex_const: '(' num ',' num ')'  */
#line 569 "./Parser/parser_main.y"
                                                   {yyval.cpx.real = yyvsp[-3].real; yyval.cpx.imag = yyvsp[-1].real;}
#line 2593 "./exec/y.tab.c"
    break;

  case 153: /* matrix_const: '[' row_list ']'  */
#line 572 "./Parser/parser_main.y"
                                                   { if(yyvsp[-1].rows == yyvsp[-1].cols) {
                                                         yyval.rows = yyvsp[-1].rows;
                                                     } 
                                                     else{
                                                         yyerror("semantic error: only square matrices permitted"); 
                                                         return 1;
                                                     }
                                                   }
#line 2606 "./exec/y.tab.c"
    break;

  case 154: /* row_list: row_list ',' row  */
#line 582 "./Parser/parser_main.y"
                                                   {  yyval.rows = yyvsp[-2].rows + 1; 
                                                      if(yyvsp[-2].cols == yyvsp[0].cols){
                                                         yyval.cols = yyvsp[-2].cols;
                                                      } 
                                                      else{
                                                         yyerror("semantic error: rows of different length cannot form matrix"); 
                                                         return 1;
                                                      }
                                                   }
#line 2620 "./exec/y.tab.c"
    break;

  case 155: /* row_list: row  */
#line 591 "./Parser/parser_main.y"
                                                      {yyval.rows = 1; yyval.cols = yyvsp[0].cols;}
#line 2626 "./exec/y.tab.c"
    break;

  case 156: /* row: '[' comps ']'  */
#line 594 "./Parser/parser_main.y"
                                                      {yyval.cols = yyvsp[-1].cols;}
#line 2632 "./exec/y.tab.c"
    break;

  case 157: /* comps: comps ',' compatible_const  */
#line 597 "./Parser/parser_main.y"
                                                      {yyval.cols = yyvsp[-2].cols + 1;}
#line 2638 "./exec/y.tab.c"
    break;

  case 158: /* comps: compatible_const  */
#line 598 "./Parser/parser_main.y"
                                                      {yyval.cols = 1;}
#line 2644 "./exec/y.tab.c"
    break;

  case 161: /* state_const: '{' temp ',' temp '}'  */
#line 605 "./Parser/parser_main.y"
                                                      {yyval.q.first = yyvsp[-3].cpx; yyval.q.second = yyvsp[-1].cpx;}
#line 2650 "./exec/y.tab.c"
    break;

  case 162: /* temp: complex_const  */
#line 608 "./Parser/parser_main.y"
                                                      {yyval.cpx = yyvsp[0].cpx;}
#line 2656 "./exec/y.tab.c"
    break;

  case 163: /* temp: num  */
#line 609 "./Parser/parser_main.y"
                                                      {yyval.cpx.real = yyvsp[0].real; yyval.cpx.imag = 0;}
#line 2662 "./exec/y.tab.c"
    break;

  case 164: /* prim_const: bool_const  */
#line 612 "./Parser/parser_main.y"
                                          {  yyval.type = Bool;
                                             yyval.str = (char *)malloc(sizeof(char)*6);
                                             if(yyval.num)snprintf(yyval.str,6,"true");
                                             else snprintf(yyval.str,6,"false");
                                          }
#line 2672 "./exec/y.tab.c"
    break;

  case 165: /* prim_const: complex_const  */
#line 617 "./Parser/parser_main.y"
                                          {  yyval.type = Complex;
                                             yyval.str = (char *)malloc(sizeof(char)*20);yyval.str = yyvsp[0].str;
                                             snprintf(yyval.str,20,"Complex(%f,%f)",yyvsp[0].cpx.real,yyvsp[0].cpx.imag);
                                          }
#line 2681 "./exec/y.tab.c"
    break;

  case 166: /* prim_const: matrix_const  */
#line 621 "./Parser/parser_main.y"
                                          {  yyval.type = Matrix; 
                                             yyval.rows = yyvsp[0].rows;
                                             yyval.str = (char *)malloc(sizeof(char)*20);
                                             snprintf(yyval.str,15,"Matrix(%d)",yyvsp[0].rows);
                                          }
#line 2691 "./exec/y.tab.c"
    break;

  case 167: /* prim_const: state_const  */
#line 626 "./Parser/parser_main.y"
                                          {yyval.type = State;}
#line 2697 "./exec/y.tab.c"
    break;

  case 168: /* prim_const: NUMBER  */
#line 627 "./Parser/parser_main.y"
                                          {yyval.type = Uint;yyval.str = (char *)malloc(sizeof(char)*20);snprintf(yyval.str,20,"%d",yyvsp[0].num);}
#line 2703 "./exec/y.tab.c"
    break;

  case 169: /* prim_const: NEG  */
#line 628 "./Parser/parser_main.y"
                                          {yyval.type = Int;yyval.str = (char *)malloc(sizeof(char)*20);snprintf(yyval.str,20,"%d",yyvsp[0].num);}
#line 2709 "./exec/y.tab.c"
    break;

  case 170: /* prim_const: DEC  */
#line 629 "./Parser/parser_main.y"
                                          {yyval.type = Float;yyval.str = (char *)malloc(sizeof(char)*20);snprintf(yyval.str,20,"%f",yyvsp[0].real);}
#line 2715 "./exec/y.tab.c"
    break;

  case 171: /* prim_const: EXP  */
#line 630 "./Parser/parser_main.y"
                                          {yyval.type = Float;yyval.str = (char *)malloc(sizeof(char)*20);snprintf(yyval.str,20,"%f",yyvsp[0].real);}
#line 2721 "./exec/y.tab.c"
    break;

  case 172: /* prim_const: STRING  */
#line 631 "./Parser/parser_main.y"
                                          {yyval.type = String;yyval.str = (char *)malloc(sizeof(char)*25);snprintf(yyval.str,25,"%s",yyvsp[0].str);}
#line 2727 "./exec/y.tab.c"
    break;

  case 173: /* vec_const: '[' vec_list ']'  */
#line 634 "./Parser/parser_main.y"
                                                {  yyval.dim = yyvsp[-1].dim; 
                                                   yyval.type = yyvsp[-1].type; 
                                                   if(yyval.type == Matrix){
                                                      yyval.rows = yyvsp[-1].rows;
                                                   } 
                                                   else{
                                                      yyval.rows = 0;
                                                   } 
                                                   yyval.str = (char *)malloc(sizeof(char)*(strlen(yyvsp[-1].str)+3));
                                                   snprintf(yyval.str,strlen(yyvsp[-1].str)+3,"{%s}",yyvsp[-1].str);
                                                   free(yyvsp[-1].str);
                                                }
#line 2744 "./exec/y.tab.c"
    break;

  case 174: /* vec_list: vec_list ',' prim_const  */
#line 648 "./Parser/parser_main.y"
                                                    {  temp_type = compatibleCheck(yyvsp[-2].type, yyvsp[0].type); 
                                                      if(temp_type != -1){
                                                         yyval.type = temp_type;
                                                      } 
                                                      else{
                                                         yyerror("semantic error: incompatible types in list"); 
                                                         return 1;
                                                      } 
                                                      yyval.dim = yyvsp[-2].dim + 1; 
                                                      if(yyval.type == Matrix){
                                                         if(yyvsp[-2].rows != yyvsp[0].rows){
                                                            yyerror("semantic error: incompatible matrix dimensions in list");
                                                            return 1;
                                                         }
                                                         else{
                                                            yyval.rows = yyvsp[-2].rows;
                                                         } 
                                                      }
                                                      insertInList(&head,yyvsp[0].str);
                                                      yyval.str = (char *)malloc(sizeof(char)*(strlen(yyvsp[-2].str)+strlen(yyvsp[0].str)+2));
                                                      snprintf(yyval.str,strlen(yyvsp[-2].str)+strlen(yyvsp[0].str)+2,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
                                                      free(yyvsp[-2].str);
                                                      free(yyvsp[0].str);
                                                   }
#line 2773 "./exec/y.tab.c"
    break;

  case 175: /* vec_list: prim_const  */
#line 672 "./Parser/parser_main.y"
                                                   {  yyval.type = yyvsp[0].type; yyval.dim = 1; 
                                                      if(yyval.type == Matrix){
                                                         yyval.rows = yyvsp[0].rows;
                                                      }
                                                      yyval.str = yyvsp[0].str;
                                                      head = NULL;
                                                      insertInList(&head,yyvsp[0].str);
                                                   }
#line 2786 "./exec/y.tab.c"
    break;

  case 176: /* calls: ADD '(' out_rhs ',' out_rhs ')'  */
#line 684 "./Parser/parser_main.y"
                     {
                        temp_type = compatibleCheckAdv(yyvsp[-1].type, yyvsp[-3].type, yyvsp[-1].prim, yyvsp[-3].prim, yyvsp[-1].dim, yyvsp[-3].dim); printf("%d\n", temp_type); 
                        if((!yyvsp[-3].prim) && (temp_type>= 0) && ((temp_type<=COMPATIBLE) || temp_type==Matrix || temp_type==State)){
                           yyval.prim = false; 
                           yyval.type = temp_type; 
                           yyval.dim = yyvsp[-3].dim;
                        } 
                        else{
                           yyerror("semantic error: incompatible operands");
                           return 1;
                        }
                        yyval.str = (char *)malloc(sizeof(char)*(strlen(yyvsp[-1].str)+strlen(yyvsp[-3].str)+strlen(yyvsp[-5].str)+4));
                        snprintf(yyval.str,strlen(yyvsp[-1].str)+strlen(yyvsp[-3].str)+strlen(yyvsp[-5].str)+4,"%s(%s,%s)",yyvsp[-5].str,yyvsp[-3].str,yyvsp[-1].str);
                        free(yyvsp[-3].str);
                        free(yyvsp[-1].str);
                     }
#line 2807 "./exec/y.tab.c"
    break;

  case 177: /* calls: SUB '(' out_rhs ',' out_rhs ')'  */
#line 701 "./Parser/parser_main.y"
                     {
                        temp_type = compatibleCheckAdv(yyvsp[-1].type, yyvsp[-3].type, yyvsp[-1].prim, yyvsp[-3].prim, yyvsp[-1].dim, yyvsp[-3].dim); 
                        if((!yyvsp[-3].prim) && (temp_type>= 0) && ((temp_type<=COMPATIBLE) || temp_type==Matrix || temp_type==State)){
                           yyval.prim = false; 
                           yyval.type = temp_type; 
                           yyval.dim = yyvsp[-3].dim;
                        } 
                        else{
                           yyerror("semantic error: incompatible operands"); 
                           return 1;
                        }
                        yyval.str = (char *)malloc(sizeof(char)*(strlen(yyvsp[-1].str)+strlen(yyvsp[-3].str)+strlen(yyvsp[-5].str)+4));
                        snprintf(yyval.str,strlen(yyvsp[-1].str)+strlen(yyvsp[-3].str)+strlen(yyvsp[-5].str)+4,"%s(%s,%s)",yyvsp[-5].str,yyvsp[-3].str,yyvsp[-1].str);
                        free(yyvsp[-3].str);
                        free(yyvsp[-1].str);
                     }
#line 2828 "./exec/y.tab.c"
    break;

  case 178: /* calls: DOT '(' out_rhs ',' out_rhs ')'  */
#line 718 "./Parser/parser_main.y"
                     {
                        temp_type = compatibleCheckAdv(yyvsp[-1].type, yyvsp[-3].type, yyvsp[-1].prim, yyvsp[-3].prim, yyvsp[-1].dim, yyvsp[-3].dim); 
                        if((!yyvsp[-3].prim) && (temp_type>= 0) && (temp_type<=COMPATIBLE)){
                           yyval.prim = true; 
                           yyval.type = temp_type; 
                           yyval.dim = yyvsp[-3].dim;
                        } 
                        else if((!yyvsp[-3].prim) && (!yyvsp[-1].prim) && (yyvsp[-3].type<=COMPATIBLE) && (yyvsp[-1].type==Matrix)){
                           yyval.prim = true; 
                           yyval.type = Matrix; 
                           yyval.dim = 0;
                        } 
                        else if(yyvsp[-3].prim && (temp_type==State)){
                           yyval.prim = true; 
                           yyval.type = Complex;
                        } 
                        else{
                           yyerror("semantic error: incompatible operands"); 
                           return 1;
                        }
                        yyval.str = (char *)malloc(sizeof(char)*(strlen(yyvsp[-1].str)+strlen(yyvsp[-3].str)+strlen(yyvsp[-5].str)+4));
                        snprintf(yyval.str,strlen(yyvsp[-1].str)+strlen(yyvsp[-3].str)+strlen(yyvsp[-5].str)+4,"%s(%s,%s)",yyvsp[-5].str,yyvsp[-3].str,yyvsp[-1].str);
                        free(yyvsp[-3].str);
                        free(yyvsp[-1].str);
                     }
#line 2858 "./exec/y.tab.c"
    break;

  case 179: /* calls: STD_DEV '(' out_rhs ')'  */
#line 744 "./Parser/parser_main.y"
                     {
                        if((!yyvsp[-1].prim) && ((yyvsp[-1].type==Uint) || (yyvsp[-1].type==Int) || (yyvsp[-1].type==Float))){
                           yyval.prim = true; 
                           yyval.type = yyvsp[-1].type; 
                           yyval.dim = yyvsp[-1].dim;
                        } 
                        else{
                           yyerror("semantic error: incompatible operands"); 
                           return 1;
                        }
                        yyval.str = (char *)malloc(sizeof(char)*(strlen(yyvsp[-1].str)+strlen(yyvsp[-3].str)+3));
                        snprintf(yyval.str,strlen(yyvsp[-1].str)+strlen(yyvsp[-3].str)+3,"%s(%s)",yyvsp[-3].str,yyvsp[-1].str);
                        free(yyvsp[-1].str);
                     }
#line 2877 "./exec/y.tab.c"
    break;

  case 180: /* calls: VAR '(' out_rhs ')'  */
#line 759 "./Parser/parser_main.y"
                     {
                        if((!yyvsp[-1].prim) && ((yyvsp[-1].type==Uint) || (yyvsp[-1].type==Int) || (yyvsp[-1].type==Float))){
                           yyval.prim = true; 
                           yyval.type = yyvsp[-1].type; 
                           yyval.dim = yyvsp[-1].dim;
                        } 
                        else{
                           yyerror("semantic error: incompatible operands");
                           return 1;
                        }
                        yyval.str = (char *)malloc(sizeof(char)*(strlen(yyvsp[-1].str)+strlen(yyvsp[-3].str)+3));
                        snprintf(yyval.str,strlen(yyvsp[-1].str)+strlen(yyvsp[-3].str)+3,"%s(%s)",yyvsp[-3].str,yyvsp[-1].str);
                        free(yyvsp[-1].str);
                     }
#line 2896 "./exec/y.tab.c"
    break;

  case 181: /* calls: CONDENSE '(' out_rhs ',' NUMBER ')'  */
#line 774 "./Parser/parser_main.y"
                     {
                        if((!yyvsp[-3].prim) && ((yyvsp[-3].type==Uint) || (yyvsp[-3].type==Int))){
                           yyval.prim = false; 
                           yyval.type = yyvsp[-3].type; 
                           yyval.dim = condenser(yyvsp[-3].dim, 1);
                        } 
                        else{
                           yyerror("semantic error: incompatible operands"); 
                           return 1;
                        }
                        yyval.str = (char *)malloc(sizeof(char)*(strlen(yyvsp[-5].str)+strlen(yyvsp[-3].str)+20));
                        snprintf(yyval.str,strlen(yyvsp[-5].str)+strlen(yyvsp[-3].str)+20,"%s(%s,%d)",yyvsp[-5].str,yyvsp[-3].str,yyvsp[-1].num);
                        free(yyvsp[-3].str);
                     }
#line 2915 "./exec/y.tab.c"
    break;

  case 182: /* calls: CONDENSE '(' out_rhs ',' '(' uint_list ')' ')'  */
#line 789 "./Parser/parser_main.y"
                     {
                        if((!yyvsp[-5].prim) && ((yyvsp[-5].type==Uint) || (yyvsp[-5].type==Int))){
                           yyval.prim = false; 
                           yyval.type = yyvsp[-5].type; 
                           yyval.dim = condenser(yyvsp[-5].dim, yyvsp[-2].cond_count);
                        } 
                        else{
                           yyerror("semantic error: incompatible operands"); 
                           return 1;
                        }
                        yyval.str = (char *)malloc(sizeof(char)*(strlen(yyvsp[-7].str)+strlen(yyvsp[-5].str)+strlen(yyvsp[-2].str)));
                        snprintf(yyval.str,strlen(yyvsp[-7].str)+strlen(yyvsp[-5].str)+20,"%s(%s,(%s))",yyvsp[-7].str,yyvsp[-5].str,yyvsp[-2].str);
                        free(yyvsp[-5].str);
                        free(yyvsp[-2].str);
                     }
#line 2935 "./exec/y.tab.c"
    break;

  case 183: /* calls: SUM '(' out_rhs ')'  */
#line 805 "./Parser/parser_main.y"
                     {
                        if((!yyvsp[-1].prim) && ((yyvsp[-1].type<=COMPATIBLE) || yyvsp[-1].type==Matrix)){
                           yyval.prim = true; 
                           yyval.type = yyvsp[-1].type; 
                           yyval.dim = 0;
                        } 
                        else{
                           yyerror("semantic error: incompatible operands"); 
                           return 1;
                        }
                        yyval.str = (char *)malloc(sizeof(char)*(strlen(yyvsp[-1].str)+strlen(yyvsp[-3].str)+3));
                        snprintf(yyval.str,strlen(yyvsp[-1].str)+strlen(yyvsp[-3].str)+3,"%s(%s)",yyvsp[-3].str,yyvsp[-1].str);
                        free(yyvsp[-1].str);
                     }
#line 2954 "./exec/y.tab.c"
    break;

  case 184: /* calls: AVG '(' out_rhs ')'  */
#line 820 "./Parser/parser_main.y"
                     {
                        if((!yyvsp[-1].prim) && ((yyvsp[-1].type<=COMPATIBLE) || yyvsp[-1].type==Matrix)){
                           yyval.prim = true; 
                           yyval.type = yyvsp[-1].type; 
                           yyval.dim = 0;
                        } 
                        else{
                           yyerror("semantic error: incompatible operands"); 
                           return 1;
                        }
                        yyval.str = (char *)malloc(sizeof(char)*(strlen(yyvsp[-1].str)+strlen(yyvsp[-3].str)+3));
                        snprintf(yyval.str,strlen(yyvsp[-1].str)+strlen(yyvsp[-3].str)+3,"%s(%s)",yyvsp[-3].str,yyvsp[-1].str);
                        free(yyvsp[-1].str);
                     }
#line 2973 "./exec/y.tab.c"
    break;

  case 185: /* uint_list: uint_list ',' out_rhs  */
#line 839 "./Parser/parser_main.y"
                                                 { if(yyvsp[-2].type <= Int){
                                                      yyval.cond_count = yyvsp[-2].cond_count + 1;
                                                   } 
                                                   else{
                                                      yyerror("semantic error: only integer elements permitted"); 
                                                      return 1;
                                                   }
                                                   yyval.str = (char *)malloc(sizeof(char)*(strlen(yyvsp[-2].str)+strlen(yyvsp[0].str)+2));
                                                   snprintf(yyval.str,strlen(yyvsp[-2].str)+strlen(yyvsp[0].str)+2,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
                                                   free(yyvsp[-2].str);
                                                   free(yyvsp[0].str);
                                                 }
#line 2990 "./exec/y.tab.c"
    break;

  case 186: /* uint_list: out_rhs  */
#line 851 "./Parser/parser_main.y"
                                                 { if(yyvsp[0].type <= Int){
                                                      yyval.cond_count = 1;
                                                   } 
                                                   else{
                                                      yyerror("semantic error: only integer elements permitted"); 
                                                      return 1;
                                                   }
                                                   yyval.str = yyvsp[0].str;
                                                 }
#line 3004 "./exec/y.tab.c"
    break;

  case 187: /* out_rhs: prim_const  */
#line 863 "./Parser/parser_main.y"
                                                { yyval.prim = true; yyval.type = yyvsp[0].type;yyval.str = yyvsp[0].str;}
#line 3010 "./exec/y.tab.c"
    break;

  case 188: /* out_rhs: vec_const  */
#line 864 "./Parser/parser_main.y"
                                                { yyval.prim = false; yyval.dim = yyvsp[0].dim; 
                                                  yyval.type = yyvsp[0].type; 
                                                  if(yyval.type == Matrix){
                                                      yyval.rows = yyvsp[0].rows;
                                                  } 
                                                  else yyval.rows = 0;
                                                  yyval.str = yyvsp[0].str;
                                                }
#line 3023 "./exec/y.tab.c"
    break;

  case 189: /* out_rhs: out_id  */
#line 872 "./Parser/parser_main.y"
                                                {  if(yyval.out_flag == 0){
                                                      struct OutputSymbolEntry* sample = getOutputSymbolEntry(&OutputSymbolTable,yyvsp[0].str,outputLevel,1); 
                                                      if(sample != NULL){
                                                         yyval.prim = sample->primitive; 
                                                         yyval.type = sample->type; 
                                                         if(yyval.type == Matrix){
                                                            yyval.rows = sample->matrix_dim;
                                                         } 
                                                         if(!yyval.prim){
                                                            yyval.dim = sample->dim;
                                                         }
                                                      } 
                                                      else{
                                                         yyerror("semantic error: variable not declared"); 
                                                         return 1;
                                                      }
                                                   } 
                                                   else if(yyval.out_flag == 1){
                                                      yyval.type = Int; yyval.prim = false; 
                                                      yyval.dim = (1 << classical_registers); 
                                                      yyval.rows = 0;
                                                   } 
                                                   else{
                                                      yyval.type = State; 
                                                      yyval.prim = false; 
                                                      yyval.dim = quantum_registers; 
                                                      yyval.rows = 0;
                                                   }
                                                   yyval.str = yyvsp[0].str;
                                                }
#line 3058 "./exec/y.tab.c"
    break;

  case 190: /* out_rhs: out_id '[' out_rhs ']'  */
#line 902 "./Parser/parser_main.y"
                                                {
                                                   if(yyval.out_flag == 0){
                                                      struct OutputSymbolEntry* sample = getOutputSymbolEntry(&OutputSymbolTable,yyvsp[-3].str,outputLevel,1); 
                                                      if(sample != NULL){
                                                         if(yyvsp[-1].type <= Uint){
                                                            if(sample->primitive){
                                                               if(sample->type==State){
                                                                  yyval.type = Complex; 
                                                                  yyval.prim = true;
                                                               } 
                                                               else{
                                                                  yyerror("semantic error"); 
                                                                  return 1;
                                                               }
                                                            }
                                                            else{
                                                               yyval.type = sample->type; 
                                                               yyval.prim = true;
                                                            }
                                                         } 
                                                         else{
                                                            yyerror("semantic error 2"); 
                                                            return 1;
                                                         }
                                                      } 
                                                      else{
                                                         yyerror("semantic error: variable not declared"); 
                                                         return 1;
                                                      }
                                                   } 
                                                   else if(yyval.out_flag == 1){
                                                      yyval.type = Uint; 
                                                      yyval.prim = true;
                                                   } 
                                                   else{
                                                      yyval.type = State; 
                                                      yyval.prim = true;
                                                   }
                                                   yyval.str = (char *)malloc(sizeof(char)*(strlen(yyvsp[-3].str)+strlen(yyvsp[-1].str)+3)); 
                                                   snprintf(yyval.str,strlen(yyvsp[-3].str)+strlen(yyvsp[-1].str)+3,"%s[%s]",yyvsp[-3].str,yyvsp[-1].str); 
                                                   free(yyvsp[-3].str);
                                                   free(yyvsp[-1].str);
                                                }
#line 3106 "./exec/y.tab.c"
    break;

  case 191: /* out_rhs: out_id '[' out_rhs ']' '[' out_rhs ']'  */
#line 946 "./Parser/parser_main.y"
                                                {
                                                   if(yyval.out_flag == 0){
                                                      struct OutputSymbolEntry* sample = getOutputSymbolEntry(&OutputSymbolTable,yyvsp[-6].str,outputLevel,1); 
                                                      if(sample != NULL){
                                                         if((yyvsp[-4].type <= Uint) && (yyvsp[-2].type <= Uint)){
                                                            if(sample->type) {
                                                               if(sample->type==Matrix){
                                                                  yyval.type = Complex; 
                                                                  yyval.prim = true;
                                                               } 
                                                               else{
                                                                  yyerror("semantic error: variable not declared"); 
                                                                  return 1;
                                                               }
                                                            } 
                                                            else if(sample->type==State){
                                                               yyval.type = Complex; 
                                                               yyval.prim = true;
                                                            } 
                                                            else{
                                                               yyerror("semantic error 3"); 
                                                               return 1;
                                                            }
                                                         }
                                                      } 
                                                      else{
                                                         yyerror("semantic error 4"); 
                                                         return 1;
                                                      }
                                                   } 
                                                   else if(yyval.out_flag == 1){
                                                      yyerror("semantic error 5");
                                                      return 1;
                                                   } 
                                                   else{
                                                      yyval.type = Complex; 
                                                      yyval.prim = true;
                                                   }
                                                   yyval.str = (char *)malloc(sizeof(char)*(strlen(yyvsp[-6].str)+strlen(yyvsp[-4].str)+strlen(yyvsp[-1].str)+5)); 
                                                   snprintf(yyval.str,strlen(yyvsp[-6].str)+strlen(yyvsp[-4].str)+strlen(yyvsp[-1].str)+5,"%s[%s][%s]",yyvsp[-6].str,yyvsp[-4].str,yyvsp[-1].str);    
                                                   free(yyvsp[-6].str);
                                                   free(yyvsp[-4].str);
                                                   free(yyvsp[-1].str);                                                
                                                }
#line 3155 "./exec/y.tab.c"
    break;

  case 192: /* out_rhs: out_id '[' out_rhs ']' '[' out_rhs ']' '[' out_rhs ']'  */
#line 991 "./Parser/parser_main.y"
                                                {
                                                   if(yyval.out_flag == 0){
                                                      struct OutputSymbolEntry* sample = getOutputSymbolEntry(&OutputSymbolTable,yyvsp[-9].str,outputLevel,1); 
                                                      if(sample != NULL){
                                                         if((yyvsp[-7].type <= Uint) && (yyvsp[-5].type <= Uint) && (yyvsp[-3].type <= Uint)){
                                                            if(sample->primitive){
                                                               yyerror("semantic error: variable not declared"); 
                                                               return 1;
                                                            } 
                                                            else if(sample->type==Matrix){
                                                               yyval.type = Complex; 
                                                               yyval.prim = true;
                                                            } 
                                                            else{
                                                               yyerror("semantic error 6"); 
                                                               return 1;
                                                            }
                                                         }
                                                      } 
                                                      else{
                                                         yyerror("semantic error 7");
                                                         return 1;
                                                      }
                                                   } 
                                                   else{
                                                      yyerror("semantic error 8"); 
                                                      return 1;
                                                   }
                                                   yyval.str = (char *)malloc(sizeof(char)*(strlen(yyvsp[-9].str)+strlen(yyvsp[-7].str)+strlen(yyvsp[-4].str)+strlen(yyvsp[-1].str)+5)); 
                                                   snprintf(yyval.str,strlen(yyvsp[-9].str)+strlen(yyvsp[-7].str)+strlen(yyvsp[-4].str)+5,"%s[%s][%s][%s]",yyvsp[-9].str,yyvsp[-7].str,yyvsp[-4].str, yyvsp[-1].str);    
                                                   free(yyvsp[-9].str);
                                                   free(yyvsp[-7].str);
                                                   free(yyvsp[-4].str); 
                                                   free(yyvsp[-1].str);
                                                }
#line 3195 "./exec/y.tab.c"
    break;

  case 193: /* out_rhs: calls  */
#line 1026 "./Parser/parser_main.y"
                                                   {  yyval.prim = yyvsp[0].prim; 
                                                      yyval.type = yyvsp[0].type; 
                                                      if(yyvsp[0].type == Matrix) yyval.rows = yyvsp[0].rows; 
                                                      if(!yyval.prim) yyval.dim = yyvsp[0].dim; 
                                                      printf("%d %d\n", yyval.prim, yyval.type);
                                                   }
#line 3206 "./exec/y.tab.c"
    break;

  case 194: /* out_rhs: '(' out_rhs ')'  */
#line 1032 "./Parser/parser_main.y"
                                                  {   yyval.type = yyvsp[-1].type;
                                                      yyval.prim = yyvsp[-1].prim;
                                                      yyval.str = (char *)malloc(sizeof(char)*(strlen(yyvsp[-1].str)+3));
                                                      snprintf(yyval.str,strlen(yyvsp[-1].str)+3,"(%s)",yyvsp[-1].str);
                                                      free(yyvsp[-1].str);
                                                  }
#line 3217 "./exec/y.tab.c"
    break;

  case 195: /* out_rhs: '!' out_rhs  */
#line 1038 "./Parser/parser_main.y"
                                                  {  if(yyvsp[0].type==Bool && yyvsp[0].prim){
                                                         yyval.prim = true; 
                                                         yyval.type = Bool;
                                                      } 
                                                      else{
                                                         yyerror("semantic error 9"); 
                                                         return 1;
                                                      }  
                                                      yyval.str = (char *)malloc(sizeof(char)*(strlen(yyvsp[0].str)+1));
                                                      snprintf(yyval.str,strlen(yyvsp[0].str)+2,"!%s",yyvsp[0].str);
                                                      free(yyvsp[0].str);
                                                   }
#line 3234 "./exec/y.tab.c"
    break;

  case 196: /* out_rhs: out_rhs AND out_rhs  */
#line 1050 "./Parser/parser_main.y"
                                                   {  if(yyvsp[-2].type==Bool && yyvsp[-2].prim && yyvsp[0].type==Bool && yyvsp[0].prim){
                                                         yyval.prim = true; 
                                                         yyval.type = Bool;
                                                      } 
                                                      else{
                                                         yyerror("semantic error 10"); 
                                                         return 1;
                                                      } 
                                                      yyval.str = (char *)malloc(sizeof(char)*(strlen(yyvsp[-2].str)+strlen(yyvsp[0].str)+5));
                                                      snprintf(yyval.str,strlen(yyvsp[-2].str)+strlen(yyvsp[0].str)+5,"%s && %s",yyvsp[-2].str,yyvsp[0].str);
                                                      free(yyvsp[-2].str);
                                                      free(yyvsp[0].str);

                                                   }
#line 3253 "./exec/y.tab.c"
    break;

  case 197: /* out_rhs: out_rhs OR out_rhs  */
#line 1064 "./Parser/parser_main.y"
                                                {  if(yyvsp[-2].type==Bool && yyvsp[-2].prim && yyvsp[0].type==Bool && yyvsp[0].prim){
                                                      yyval.prim = true; 
                                                      yyval.type = Bool;
                                                   } 
                                                   else{
                                                      yyerror("semantic error 11"); 
                                                      return 1;
                                                   } 
                                                      yyval.str = (char *)malloc(sizeof(char)*(strlen(yyvsp[-2].str)+strlen(yyvsp[0].str)+5));
                                                      snprintf(yyval.str,strlen(yyvsp[-2].str)+strlen(yyvsp[0].str)+5,"%s || %s",yyvsp[-2].str,yyvsp[0].str);
                                                      free(yyvsp[-2].str);
                                                      free(yyvsp[0].str);
                                                }
#line 3271 "./exec/y.tab.c"
    break;

  case 198: /* out_rhs: out_rhs COMP out_rhs  */
#line 1077 "./Parser/parser_main.y"
                                                 {  temp_type = compatibleCheckAdv(yyvsp[-2].type, yyvsp[0].type, yyvsp[-2].prim, yyvsp[0].prim, yyvsp[-2].dim, yyvsp[0].dim); 
                                                   if(temp_type != -1 && temp_type < COMPARABLE){
                                                      yyval.prim = true; 
                                                      yyval.type = Bool;
                                                   } 
                                                   else{
                                                      yyerror("semantic error 12"); 
                                                      return 1;
                                                   }
                                                      yyval.str = (char *)malloc(sizeof(char)*(strlen(yyvsp[-2].str)+strlen(yyvsp[0].str)+strlen(yyvsp[-1].str)+3));
                                                      snprintf(yyval.str,strlen(yyvsp[-2].str)+strlen(yyvsp[0].str)+strlen(yyvsp[-1].str)+3,"%s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
                                                      free(yyvsp[-2].str);
                                                      free(yyvsp[0].str);
                                                }
#line 3290 "./exec/y.tab.c"
    break;

  case 199: /* out_rhs: out_rhs EQUALITY out_rhs  */
#line 1091 "./Parser/parser_main.y"
                                                   { temp_type = compatibleCheckAdv(yyvsp[-2].type, yyvsp[0].type, yyvsp[-2].prim, yyvsp[0].prim, yyvsp[-2].dim, yyvsp[0].dim); 
                                                      if(temp_type != -1 && temp_type < COMPARABLE){
                                                         yyval.prim = true; 
                                                         yyval.type = Bool;
                                                      } 
                                                      else{
                                                         yyerror("semantic error 13"); 
                                                         return 1;
                                                      } 
                                                      yyval.str = (char *)malloc(sizeof(char)*(strlen(yyvsp[-2].str)+strlen(yyvsp[0].str)+strlen(yyvsp[-1].str)+3));
                                                      snprintf(yyval.str,strlen(yyvsp[-2].str)+strlen(yyvsp[0].str)+strlen(yyvsp[-1].str)+3,"%s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
                                                      free(yyvsp[-2].str);
                                                      free(yyvsp[0].str); 
                                                   }
#line 3309 "./exec/y.tab.c"
    break;

  case 200: /* out_rhs: out_rhs '*' out_rhs  */
#line 1105 "./Parser/parser_main.y"
                                                    {  temp_type = compatibleCheckAdv(yyvsp[-2].type, yyvsp[0].type, yyvsp[-2].prim, yyvsp[0].prim, yyvsp[-2].dim, yyvsp[0].dim); 
                                                      if(yyvsp[-2].prim && (temp_type <= Complex && temp_type >= 0)){
                                                         yyval.prim = true; 
                                                         yyval.type = temp_type;
                                                      } 
                                                      else if(yyvsp[-2].prim && yyvsp[0].prim && yyvsp[-2].type<=Complex && yyvsp[0].type==Matrix){
                                                         yyval.prim = true; 
                                                         yyval.type = Matrix;
                                                      } 
                                                      else if ((yyvsp[-2].prim && yyvsp[0].prim) && ((yyvsp[-2].type == String && yyvsp[0].type == Uint) || (yyvsp[0].type == String && yyvsp[-2].type == Uint))) {
                                                         yyval.prim = true; 
                                                         yyval.type = String;
                                                      } 
                                                      else{
                                                         yyerror("semantic error 14"); 
                                                         return 1;
                                                      }
                                                      yyval.str = (char *)malloc(sizeof(char)*(strlen(yyvsp[-2].str)+strlen(yyvsp[0].str)+4));
                                                      snprintf(yyval.str,strlen(yyvsp[-2].str)+strlen(yyvsp[0].str)+4,"%s * %s",yyvsp[-2].str,yyvsp[0].str);
                                                      free(yyvsp[-2].str);
                                                      free(yyvsp[0].str);
                                                   }
#line 3336 "./exec/y.tab.c"
    break;

  case 201: /* out_rhs: out_rhs '/' out_rhs  */
#line 1127 "./Parser/parser_main.y"
                                                   {  temp_type = compatibleCheckAdv(yyvsp[-2].type, yyvsp[0].type, yyvsp[-2].prim, yyvsp[0].prim, yyvsp[-2].dim, yyvsp[0].dim); 
                                                      if(yyvsp[-2].prim && (temp_type <= Complex && temp_type >= 0)){
                                                         yyval.prim = true; 
                                                         yyval.type = temp_type;
                                                      } 
                                                      else{
                                                         yyerror("semantic error 15"); 
                                                         return 1;
                                                      }
                                                      yyval.str = (char *)malloc(sizeof(char)*(strlen(yyvsp[-2].str)+strlen(yyvsp[0].str)+4));
                                                      snprintf(yyval.str,strlen(yyvsp[-2].str)+strlen(yyvsp[0].str)+4,"%s / %s",yyvsp[-2].str,yyvsp[0].str);
                                                      free(yyvsp[-2].str);
                                                      free(yyvsp[0].str);
                                                   }
#line 3355 "./exec/y.tab.c"
    break;

  case 202: /* out_rhs: out_rhs '+' out_rhs  */
#line 1142 "./Parser/parser_main.y"
                                                   {  temp_type = compatibleCheckAdv(yyvsp[-2].type, yyvsp[0].type, yyvsp[-2].prim, yyvsp[0].prim, yyvsp[-2].dim, yyvsp[0].dim); 
                                                      if(temp_type == Matrix || temp_type == State || (temp_type <= Complex && temp_type >= 0)){
                                                         yyval.prim = yyvsp[-2].prim; 
                                                         yyval.type = temp_type; 
                                                         if(temp_type == Matrix){
                                                            yyval.rows=yyvsp[-2].rows;
                                                         } 
                                                         yyval.dim=yyvsp[-2].dim;
                                                      } 
                                                      else if ((yyvsp[-2].prim==true) && (yyvsp[-2].type == String)){
                                                         yyval.prim = true; 
                                                         yyval.type = String;
                                                      } 
                                                      else{
                                                         yyerror("semantic error 16");
                                                         return 1;
                                                      }
                                                      yyval.str = (char *)malloc(sizeof(char)*(strlen(yyvsp[-2].str)+strlen(yyvsp[0].str)+4));
                                                      snprintf(yyval.str,strlen(yyvsp[-2].str)+strlen(yyvsp[0].str)+4,"%s + %s",yyvsp[-2].str,yyvsp[0].str);
                                                      free(yyvsp[-2].str);
                                                      free(yyvsp[0].str);
                                                   }
#line 3382 "./exec/y.tab.c"
    break;

  case 203: /* out_rhs: out_rhs '-' out_rhs  */
#line 1164 "./Parser/parser_main.y"
                                                                                                                                                                             {  temp_type = compatibleCheckAdv(yyvsp[-2].type, yyvsp[0].type, yyvsp[-2].prim, yyvsp[0].prim, yyvsp[-2].dim, yyvsp[0].dim); 
                                                      if(temp_type == Matrix || temp_type == State || (temp_type <= Complex && temp_type >= 0)){
                                                         yyval.prim = yyvsp[-2].prim; 
                                                         yyval.type = temp_type; 
                                                         if(temp_type == Matrix) yyval.rows=yyvsp[-2].rows; 
                                                         yyval.dim=yyvsp[-2].dim;
                                                      } 
                                                      else{
                                                         yyerror("semantic error 17");
                                                         return 1;
                                                      } 
                                                      yyval.str = (char *)malloc(sizeof(char)*(strlen(yyvsp[-2].str)+strlen(yyvsp[0].str)+4));
                                                      snprintf(yyval.str,strlen(yyvsp[-2].str)+strlen(yyvsp[0].str)+4,"%s - %s",yyvsp[-2].str,yyvsp[0].str);
                                                      free(yyvsp[-2].str);
                                                      free(yyvsp[0].str);                                                      
                                                   }
#line 3403 "./exec/y.tab.c"
    break;

  case 204: /* out_rhs: out_rhs '@' out_rhs  */
#line 1180 "./Parser/parser_main.y"
                                                                                                                                                                      {  temp_type = compatibleCheckAdv(yyvsp[-2].type, yyvsp[0].type, yyvsp[-2].prim, yyvsp[0].prim, yyvsp[-2].dim, yyvsp[0].dim); 
                                                      if(yyvsp[-2].prim && temp_type == Matrix){
                                                         if(yyvsp[-2].rows == yyvsp[0].rows){
                                                            yyval.prim = true; 
                                                            yyval.type = temp_type; 
                                                            yyval.rows = yyvsp[-2].rows;
                                                         } 
                                                         else{
                                                            yyerror("semantic error 18"); 
                                                            return 1;
                                                         }
                                                      } 
                                                      else if(yyvsp[-2].prim && temp_type == State){
                                                         yyval.prim = true; 
                                                         yyval.type = Complex;
                                                      } 
                                                      else if(!yyvsp[-2].prim && (temp_type <= COMPATIBLE) && (temp_type >= 0)){
                                                         yyval.prim = true; 
                                                         yyval.type = temp_type; 
                                                         yyval.dim = 0;
                                                      } 
                                                      else if(yyvsp[-2].type<=COMPATIBLE && yyvsp[0].type==Matrix){
                                                         yyval.prim = true; 
                                                         yyval.type = Matrix; 
                                                         yyval.dim = 0;
                                                      } 
                                                      else{
                                                         yyerror("semantic error 19"); 
                                                         return 1;
                                                      }
                                                      yyval.str = (char *)malloc(sizeof(char)*(strlen(yyvsp[-2].str)+strlen(yyvsp[0].str)+4));
                                                      snprintf(yyval.str,strlen(yyvsp[-2].str)+strlen(yyvsp[0].str)+4,"%s @ %s",yyvsp[-2].str,yyvsp[0].str);
                                                      free(yyvsp[-2].str);
                                                      free(yyvsp[0].str);
                                                   }
#line 3443 "./exec/y.tab.c"
    break;

  case 205: /* out_rhs: out_rhs '&' out_rhs  */
#line 1216 "./Parser/parser_main.y"
                                                   {  temp_type = compatibleCheckAdv(yyvsp[-2].type, yyvsp[0].type, yyvsp[-2].prim, yyvsp[0].prim, yyvsp[-2].dim, yyvsp[0].dim); 
                                                      if(temp_type <= Int){
                                                         yyval.prim = yyvsp[-2].prim; 
                                                         yyval.type = temp_type;
                                                      } 
                                                      else{
                                                         yyerror("semantic error: incompatible operands"); 
                                                         return 1;
                                                      }
                                                      yyval.str = (char *)malloc(sizeof(char)*(strlen(yyvsp[-2].str)+strlen(yyvsp[0].str)+4));
                                                      snprintf(yyval.str,strlen(yyvsp[-2].str)+strlen(yyvsp[0].str)+4,"%s & %s",yyvsp[-2].str,yyvsp[0].str);
                                                      free(yyvsp[-2].str);
                                                      free(yyvsp[0].str);
                                                   }
#line 3462 "./exec/y.tab.c"
    break;

  case 206: /* out_rhs: out_rhs '^' out_rhs  */
#line 1231 "./Parser/parser_main.y"
                                                   {  temp_type = compatibleCheckAdv(yyvsp[-2].type, yyvsp[0].type, yyvsp[-2].prim, yyvsp[0].prim, yyvsp[-2].dim, yyvsp[0].dim); 
                                                      if(temp_type <= Int){
                                                         yyval.prim = yyvsp[-2].prim; 
                                                         yyval.type = temp_type;
                                                      } 
                                                      else{
                                                         yyerror("semantic error: incompatible operands"); 
                                                         return 1;
                                                      }
                                                      yyval.str = (char *)malloc(sizeof(char)*(strlen(yyvsp[-2].str)+strlen(yyvsp[0].str)+4));
                                                      snprintf(yyval.str,strlen(yyvsp[-2].str)+strlen(yyvsp[0].str)+4,"%s ^ %s",yyvsp[-2].str,yyvsp[0].str);
                                                      free(yyvsp[-2].str);
                                                      free(yyvsp[0].str);                                                      
                                                   }
#line 3481 "./exec/y.tab.c"
    break;

  case 207: /* out_rhs: out_rhs '|' out_rhs  */
#line 1246 "./Parser/parser_main.y"
                                                   { temp_type = compatibleCheckAdv(yyvsp[-2].type, yyvsp[0].type, yyvsp[-2].prim, yyvsp[0].prim, yyvsp[-2].dim, yyvsp[0].dim); 
                                                      if(temp_type <= Int){
                                                         yyval.prim = yyvsp[-2].prim; 
                                                         yyval.type = temp_type;
                                                      } 
                                                      else{
                                                         yyerror("semantic error: incompatible operands"); 
                                                         return 1;
                                                      }
                                                      yyval.str = (char *)malloc(sizeof(char)*(strlen(yyvsp[-2].str)+strlen(yyvsp[0].str)+4));
                                                      snprintf(yyval.str,strlen(yyvsp[-2].str)+strlen(yyvsp[0].str)+4,"%s | %s",yyvsp[-2].str,yyvsp[0].str);
                                                      free(yyvsp[-2].str);
                                                      free(yyvsp[0].str);                                                      
                                                   }
#line 3500 "./exec/y.tab.c"
    break;

  case 208: /* out_expr: ID '=' out_rhs  */
#line 1263 "./Parser/parser_main.y"
                                                   {  fprintf(fp,"expression statement\n"); 
                                                      if(isDeclaration){
                                                         yyval.type = yyvsp[0].type; 
                                                         assignString(yyval.str,yyvsp[-2].str); 
                                                         yyval.prim = yyvsp[0].prim; 
                                                         if(!yyvsp[0].prim) yyval.dim = yyvsp[0].dim; 
                                                         if(yyvsp[0].type == Matrix) yyval.rows = yyvsp[0].rows; 
                                                      } 
                                                      else{
                                                         struct OutputSymbolEntry* entry = getOutputSymbolEntry(&OutputSymbolTable,yyvsp[-2].str,outputLevel,1); if(entry->type != yyvsp[0].type){
                                                            yyerror("semantic error 20"); 
                                                            return 1;
                                                         }
                                                      }
                                                      
                                                      yyval.str2 = (char *)malloc(sizeof(char)*(strlen(yyvsp[-2].str)+strlen(yyvsp[0].str)+5));
                                                      snprintf(yyval.str2,strlen(yyvsp[-2].str)+strlen(yyvsp[0].str)+10,"%s = %s;",yyvsp[-2].str,yyvsp[0].str);
                                                   }
#line 3523 "./exec/y.tab.c"
    break;

  case 209: /* decl: prim_type out_expr  */
#line 1283 "./Parser/parser_main.y"
                                                   {  fprintf(fp,"Primitive datatype declaration statement\n"); 
                                                      if(getOutputSymbolEntry(&OutputSymbolTable,yyvsp[0].str,outputLevel,0) != NULL){
                                                         yyerror("semantic error: variable redeclaration"); 
                                                         return 1;
                                                      } 
                                                      else if((yyvsp[0].prim==false) || ((yyvsp[-1].type < COMPATIBLE) && (yyvsp[-1].type < yyvsp[0].type)) || ((yyvsp[-1].type >= COMPATIBLE) && (yyvsp[-1].type != yyvsp[0].type))){
                                                         yyerror("semantic error: incompatible types"); 
                                                         return 1;
                                                      } 
                                                      else{
                                                         if(yyvsp[0].type == Matrix) insertInOutputTable(&OutputSymbolTable,yyvsp[0].str,outputLevel,yyvsp[0].type,true,yyvsp[0].rows,0,false);
                                                         else insertInOutputTable(&OutputSymbolTable,yyvsp[0].str,outputLevel,yyvsp[0].type,true,0,0,false);
                                                      }
                                                      // printing declaration statements to cpp file
                                                      fprintf(out,"%s\n",yyvsp[0].str2);
                                                   }
#line 3544 "./exec/y.tab.c"
    break;

  case 210: /* decl: list_type out_expr  */
#line 1300 "./Parser/parser_main.y"
                                                   {  fprintf(fp,"List datatype declaration statement\n"); 
                                                      if(getOutputSymbolEntry(&OutputSymbolTable,yyvsp[0].str,outputLevel,0) != NULL){
                                                         yyerror("semantic error: variable redeclaration"); 
                                                         return 1;
                                                      } 
                                                      else if((yyvsp[0].prim==true) || ((yyvsp[-1].type < COMPATIBLE) && (yyvsp[-1].type < yyvsp[0].type)) || ((yyvsp[-1].type >= COMPATIBLE) && (yyvsp[-1].type != yyvsp[0].type))){
                                                         yyerror("semantic error: incompatible types"); 
                                                         return 1;
                                                      } 
                                                      else{
                                                         if(yyvsp[0].type == Matrix)insertInOutputTable(&OutputSymbolTable,yyvsp[0].str,outputLevel,yyvsp[-1].type,false,yyvsp[0].rows,yyvsp[0].dim,false); 
                                                         else insertInOutputTable(&OutputSymbolTable,yyvsp[0].str,outputLevel,yyvsp[-1].type,false,0,yyvsp[0].dim,false);
                                                      }
                                                      fprintf(out,"%s\n",yyvsp[0].str2);
                                                   }
#line 3564 "./exec/y.tab.c"
    break;

  case 211: /* echo_stmt: ECHO '(' echo_list ')'  */
#line 1318 "./Parser/parser_main.y"
                                                      {  fprintf(fp,"Echo statement\n");
                                                         fprintf(out,"cout<<%s<<endl;\n",yyvsp[-1].str);
                                                      }
#line 3572 "./exec/y.tab.c"
    break;

  case 212: /* echo_list: echo_list ',' out_rhs  */
#line 1323 "./Parser/parser_main.y"
                                                      {  yyval.str = (char *)malloc(sizeof(char)*(strlen(yyvsp[-2].str)+strlen(yyvsp[0].str)+4));
                                                         snprintf(yyval.str,strlen(yyvsp[-2].str)+strlen(yyvsp[0].str)+4,"%s<<%s",yyvsp[-2].str,yyvsp[0].str);
                                                         free(yyvsp[-2].str);
                                                         free(yyvsp[0].str);
                                                      }
#line 3582 "./exec/y.tab.c"
    break;

  case 213: /* echo_list: out_rhs  */
#line 1328 "./Parser/parser_main.y"
                                                      {  yyval.str = (char *)malloc(sizeof(char)*(strlen(yyvsp[0].str)+2));
                                                         snprintf(yyval.str,strlen(yyvsp[0].str)+2,"%s",yyvsp[0].str);
                                                         free(yyvsp[0].str);   
                                                      }
#line 3591 "./exec/y.tab.c"
    break;

  case 214: /* save_stmt: '\\' SAVE STRING  */
#line 1335 "./Parser/parser_main.y"
                                                      {fprintf(fp,"Save statement\n");}
#line 3597 "./exec/y.tab.c"
    break;

  case 215: /* $@14: %empty  */
#line 1339 "./Parser/parser_main.y"
                          {fprintf(fp,"Output section conditional statement begins\n");}
#line 3603 "./exec/y.tab.c"
    break;

  case 216: /* out_control: $@14 out_cond_stmt  */
#line 1339 "./Parser/parser_main.y"
                                                                                                       {fprintf(fp,"Output section conditional statement ends\n");}
#line 3609 "./exec/y.tab.c"
    break;

  case 217: /* out_control: out_for_stmt  */
#line 1340 "./Parser/parser_main.y"
                                                      {fprintf(fp,"For statement in output section\n");}
#line 3615 "./exec/y.tab.c"
    break;

  case 218: /* out_control: out_for_lex_stmt  */
#line 1341 "./Parser/parser_main.y"
                                                      {fprintf(fp,"For - lex statement in output section\n");}
#line 3621 "./exec/y.tab.c"
    break;

  case 219: /* out_control: out_for_zip_stmt  */
#line 1342 "./Parser/parser_main.y"
                                                      {fprintf(fp,"For - zip statement in output section\n");}
#line 3627 "./exec/y.tab.c"
    break;

  case 220: /* out_control: out_while_stmt  */
#line 1343 "./Parser/parser_main.y"
                                                      {fprintf(fp,"while statement in output section\n");}
#line 3633 "./exec/y.tab.c"
    break;

  case 221: /* $@15: %empty  */
#line 1346 "./Parser/parser_main.y"
                                                        {outputLevel++;fprintf(out,"if(%s){\n",yyvsp[-2].str);}
#line 3639 "./exec/y.tab.c"
    break;

  case 222: /* $@16: %empty  */
#line 1346 "./Parser/parser_main.y"
                                                                                                                      {fprintf(out,"}\n");outputLevel--;}
#line 3645 "./exec/y.tab.c"
    break;

  case 224: /* $@17: %empty  */
#line 1349 "./Parser/parser_main.y"
                                                                       {outputLevel++;fprintf(out,"else if(%s){\n",yyvsp[-2].str);}
#line 3651 "./exec/y.tab.c"
    break;

  case 225: /* out_other_list: out_other_list OTHERWISE '(' out_rhs ')' '{' $@17 out_main '}'  */
#line 1349 "./Parser/parser_main.y"
                                                                                                                                          {fprintf(out,"}\n");outputLevel--;}
#line 3657 "./exec/y.tab.c"
    break;

  case 227: /* $@18: %empty  */
#line 1353 "./Parser/parser_main.y"
                                        {outputLevel++;fprintf(out,"else{\n");}
#line 3663 "./exec/y.tab.c"
    break;

  case 228: /* out_other_final: OTHERWISE '{' $@18 out_main '}'  */
#line 1353 "./Parser/parser_main.y"
                                                                                             {outputLevel--;fprintf(out,"}\n");}
#line 3669 "./exec/y.tab.c"
    break;

  case 230: /* $@19: %empty  */
#line 1357 "./Parser/parser_main.y"
                                 {  if(getOutputSymbolEntry(&OutputSymbolTable,yyvsp[0].str,outputLevel + 1,1) == NULL){
                                       yyerror("semantic error: variable used without declaration"); 
                                       return 1;
                                    }
                                 }
#line 3679 "./exec/y.tab.c"
    break;

  case 231: /* $@20: %empty  */
#line 1362 "./Parser/parser_main.y"
                                               {outputLevel++;fprintf(out,"for(%s = %s;%s < %s;%s += %s){\n",yyvsp[-6].str,yyvsp[-2].start,yyvsp[-6].str,yyvsp[-2].end,yyvsp[-6].str,yyvsp[-2].step);}
#line 3685 "./exec/y.tab.c"
    break;

  case 232: /* out_for_stmt: FOR ID $@19 IN '(' range ')' '{' $@20 out_main '}'  */
#line 1363 "./Parser/parser_main.y"
                                               {fprintf(out,"}\n");exitOutputSymbolScope(&OutputSymbolTable,outputLevel);outputLevel--;}
#line 3691 "./exec/y.tab.c"
    break;

  case 233: /* $@21: %empty  */
#line 1366 "./Parser/parser_main.y"
                                                                          {   if(yyvsp[-5].num != yyvsp[-1].num){
                                                                                 yyerror("semantic error: mismatch in loop variables and ranges"); 
                                                                                 return 1;
                                                                              }
                                                                              printForLex(yyvsp[-5].num);
                                                                          }
#line 3702 "./exec/y.tab.c"
    break;

  case 234: /* $@22: %empty  */
#line 1372 "./Parser/parser_main.y"
                              {outputLevel++;}
#line 3708 "./exec/y.tab.c"
    break;

  case 235: /* out_for_lex_stmt: FOR_LEX '(' var_list ')' IN '(' range_list ')' $@21 '{' $@22 out_main '}'  */
#line 1372 "./Parser/parser_main.y"
                                                                          {   int x = indent-1;
                                                                              for(int i=0;i<yyvsp[-10].num;i++){
                                                                                 for(int j=0;j<x;j++){
                                                                                    fprintf(out,"\t");
                                                                                 }
                                                                                 x--;
                                                                                 fprintf(out,"}\n");
                                                                              }
                                                                              exitOutputSymbolScope(&OutputSymbolTable,outputLevel);
                                                                              outputLevel--;}
#line 3723 "./exec/y.tab.c"
    break;

  case 236: /* $@23: %empty  */
#line 1384 "./Parser/parser_main.y"
                                                                          {   if(yyvsp[-5].num != yyvsp[-1].num){
                                                                                 yyerror("semantic error: mismatch in loop variables and ranges"); 
                                                                                 return 1;
                                                                              }
                                                                              printForZip(yyvsp[-5].num);
                                                                          }
#line 3734 "./exec/y.tab.c"
    break;

  case 237: /* $@24: %empty  */
#line 1390 "./Parser/parser_main.y"
                              {outputLevel++;}
#line 3740 "./exec/y.tab.c"
    break;

  case 238: /* out_for_zip_stmt: FOR_ZIP '(' var_list ')' IN '(' range_list ')' $@23 '{' $@24 out_main '}'  */
#line 1391 "./Parser/parser_main.y"
                                                     {exitOutputSymbolScope(&OutputSymbolTable,outputLevel); outputLevel--;}
#line 3746 "./exec/y.tab.c"
    break;

  case 239: /* $@25: %empty  */
#line 1394 "./Parser/parser_main.y"
                                                    {outputLevel++;fprintf(out,"while(%s){\n",yyvsp[-2].str);}
#line 3752 "./exec/y.tab.c"
    break;

  case 240: /* out_while_stmt: WHILE '(' out_rhs ')' '{' $@25 out_main '}'  */
#line 1394 "./Parser/parser_main.y"
                                                                                                                     {fprintf(out,"}\n");exitOutputSymbolScope(&OutputSymbolTable,outputLevel); outputLevel--;}
#line 3758 "./exec/y.tab.c"
    break;

  case 246: /* $@26: %empty  */
#line 1406 "./Parser/parser_main.y"
                          {isDeclaration = false;}
#line 3764 "./exec/y.tab.c"
    break;

  case 247: /* out_stmt: $@26 out_expr  */
#line 1406 "./Parser/parser_main.y"
                                                            {fprintf(out,"%s\n",yyvsp[0].str2);}
#line 3770 "./exec/y.tab.c"
    break;

  case 248: /* $@27: %empty  */
#line 1407 "./Parser/parser_main.y"
                          {isDeclaration = true;}
#line 3776 "./exec/y.tab.c"
    break;


#line 3780 "./exec/y.tab.c"

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

#line 1409 "./Parser/parser_main.y"


void printForZip(int num){
   struct List* temp = head;
   struct List2* temp2 = range_list;

   for(int i=0;i<num;i++){

   }
}

void printForLex(int num){
   struct List* temp = head;
   struct List2* temp2 = range_list;
   int x = outputLevel-1;
   for(int i=0;i<num;i++){
      for(int j=0;j<x;j++){
         fprintf(out,"\t");
      }
      x++;
      fprintf(out,"for(%s = %s;%s < %s;%s += %s){\n",temp->id,temp2->start,temp->id,temp2->end,temp->id,temp2->step);
      temp = temp->next;
      temp2 = temp2->next;
   }
   indent = x;
}

char * IntToString(int n){
   int temp = n,len=0;
   while(temp != 0) {
      temp = temp/10;
      len++;
   }
   len += 1;
   char * str = (char *)malloc(sizeof(char)*len);
   sprintf(str,"%d",n);
   return str;
}

void assignString(char* str1, char* str2){
   str1 = (char*)malloc(sizeof(char)*(strlen(str2)+1));
   for(int i=0;i<strlen(str2);i++){
      str1[i] = str2[i];
   }
}

bool firstLetterCapital(char *str) {
   return (str[0] >= 65 && str[0] <= 90);
}

void insertInList(struct List** Head,char * data){
   struct List* newNode = (struct List*)malloc(sizeof(struct List));
   newNode->id = (char *)malloc(sizeof(char)*(strlen(data)+1));
   for(int i=0;i<strlen(data);i++){
      newNode->id[i] = data[i];
   }
   newNode->id[strlen(data)] = '\0';
   if(*Head == NULL){
      newNode->next = NULL;
   }
   else{
      newNode->next = *Head;
   }
   *Head = newNode;
}

void removeTopKFromList(struct List** Head, int k) {
   if(*Head == NULL) return;

   struct List* temp = *Head;
   while(k--) {
      struct List* toDelete = temp;
      temp = temp->next;
      free(toDelete);
   }
   *Head = temp;
}

bool inList(struct List** Head, char* data) {
   if(*Head == NULL) return false;

   struct List* temp = *Head;
   while(temp != NULL) {
      if(strcmp(temp->id, data) == 0) return true;
      temp = temp->next;
   }
   return false;
}

void printList(struct List** Head){
   struct List* temp = *Head;
   while(temp!=NULL){
      printf("%s ",temp->id);
      temp = temp->next;
   }
   printf("\n");
}

int InBlock(struct BlockTable** Head,char * data,int len){
   struct BlockTable* temp = *Head;
   while(temp != NULL){
      if(strcmp(temp->id,data) == 0 && temp->len == len){
         return 1;
      }
      temp = temp->next;
   }
   return 0;
}

int insertInBlockTable(struct BlockTable** Head,char * data,int len,struct List* params){
   if(InBlock(Head,data,len)) return 0;
   struct BlockTable* newNode = (struct BlockTable*)malloc(sizeof(struct BlockTable));
   newNode->id = (char *)malloc(sizeof(char)*strlen(data));
   for(int i=0;i<strlen(data);i++){
      newNode->id[i] = data[i];
   }
   newNode->params = params;
   newNode->len = len;
   if(*Head == NULL){
      newNode->next = NULL;
   }
   else{
      newNode->next = *Head;
   }
   *Head = newNode;
   return 1;
}

void printBlockTable(){
   struct BlockTable* temp = BlockSymbolTable;
   while(temp != NULL){
      printf("%s \n",temp->id);
      printList(&(temp->params));
      printf("%d\n\n",temp->len);
      temp = temp->next;
   }
}

int insertInGateTable(struct GateTable ** Head,char * data,int rows,int cols){
   if(rows!=cols){return 0;}
   struct GateTable* temp = *Head;
   while(temp != NULL){
      if(strcmp(temp->id,data) == 0){
         return 0;
      }
      temp = temp->next;
   }
   struct GateTable* newNode = (struct GateTable*)malloc(sizeof(struct GateTable));
   newNode->id = (char *)malloc(sizeof(char)*strlen(data));
   for(int i=0;i<strlen(data);i++){
      newNode->id[i] = data[i];
   }
   newNode->rows = rows;
   newNode->cols = cols;
   if(*Head == NULL){
      newNode->next = NULL;
   }
   else{
      newNode->next = *Head;
   }
   *Head = newNode;
   return 1;
}

void printGateTable(struct GateTable ** GateSymbolTable){
   struct GateTable* temp = *GateSymbolTable;
   while(temp != NULL){
      printf("%s ",temp->id);
      printf("%d %d\n",temp->rows,temp->cols);
      temp = temp->next;
   }
}

int BlockSemanticCheck(char *block_id){
   struct BlockTable * temp = BlockSymbolTable;
   while(temp != NULL){
      if(strcmp(temp->id,block_id) == 0){
         break;
      }
      temp = temp->next;
   }

   struct List* temp2 = temp->params;
   struct List* temp4 = id_list;

   while(temp4 != NULL){
      int x=0;
      while(temp2 != NULL){
         if(strcmp(temp4->id,temp2->id) == 0) {
            x = 1;
            break;
         }
         temp2 = temp2->next;
      }
      if(!x) {return 0;}
      temp2 = temp->params;
      temp4 = temp4->next;
   }
   return 1;
}

int BlockCallSemanticCheck(char *block_id,int num_params){
   struct BlockTable* temp = BlockSymbolTable;
   while(temp != NULL){
      if(strcmp(temp->id,block_id) == 0 && temp->len == num_params){
         return 1;
      }
      temp = temp->next;
   }
   return 0;
}

/* Output Section */

/* insert symtab entry at some scope level */
void insertInOutputTable(struct OutputSymbolEntry** Head, char* id, int level, int type, bool primitive, int matrix_dim, int dim, bool isLoopId){
   /* New Entry */
   struct OutputSymbolEntry* newNode = (struct OutputSymbolEntry*)malloc(sizeof(struct OutputSymbolEntry));

   /* ID */
   newNode->id = (char *)malloc(sizeof(char)*strlen(id));
   for(int i=0;i<strlen(id);i++){
      newNode->id[i] = id[i];
   }

   /* Type */
   newNode->type = type;
   
   /* Primitive */
   newNode->primitive = primitive;

   /* Dimensions of Matrix in a list*/
   newNode->matrix_dim = matrix_dim;

   /* Dimensions */
   newNode->dim = dim;

   /* Scope Level */
   newNode->level = level;

   /* is the identifier a loop identifier? */
   newNode->isLoopId = isLoopId;

   /* Append */
   newNode->prev = *Head;  // covers NULL case already

   *Head = newNode;
   /* printf("Insertion : %s %d %d %d %d\n", newNode->id, newNode->level, newNode->primitive, newNode->dim, newNode->matrix_dim); */
}


/* returns matching entry from outmost scope, NULL if not found */
struct OutputSymbolEntry* getOutputSymbolEntry(struct OutputSymbolEntry** Head, char* id, int level, int findFlag){
    struct OutputSymbolEntry* symbolEntry = *Head;
    while(symbolEntry != NULL){
        if(strcmp(id, symbolEntry->id) == 0 && (symbolEntry->level == level || findFlag)) { /* found an exisitng entry that doesn't permit declaration of same identifier */
            break;  // found entry
        }
        symbolEntry = symbolEntry->prev;
    }
    // symtabEntry will be none if no entry is found (including when symtab is empty)
    return (struct OutputSymbolEntry*) symbolEntry;      
}

/* removes all entries from given outermost level */
void exitOutputSymbolScope(struct OutputSymbolEntry** Head, int level){
    struct OutputSymbolEntry* symbolEntry = *Head;
    if(symbolEntry == NULL) {return;}
    struct OutputSymbolEntry* prevEntry;

    while(symbolEntry != NULL && symbolEntry->level == level){
        printf("Deletion : %s %d %d %d %d\n", symbolEntry->id, symbolEntry->level, symbolEntry->primitive, symbolEntry->dim, symbolEntry->matrix_dim);
        prevEntry = symbolEntry->prev;
        free(symbolEntry->id);
        free(symbolEntry);
        symbolEntry = prevEntry;
    }
    *Head = symbolEntry; //update by reference
    return;
}


void printOutputTable(struct OutputSymbolEntry ** OutputSymbolTable){
   struct OutputSymbolEntry* temp = *OutputSymbolTable;
   while(temp != NULL){
      printf("%s ",temp->id);
      printf("%d %d %d %d\n",temp->type, temp->level, temp->primitive, temp->dim);
      /* Check for scopes here! */
      temp = temp->prev;
   }
}


int compatibleCheck(int t1, int t2)
{
   if(t1 == t2) return t1;
   else if((t1 < COMPATIBLE) && (t1 > t2)) return t1;
   else if((t2 < COMPATIBLE) && (t2 > t1)) return t2;
   else return -1;
}

int compatibleCheckAdv(int t1, int t2, int p1, int p2, int d1, int d2)
{
   /* Primitive ? */
   if(p1 == p2)
   {  
      /* Dimension Check (if necessary) */
      if(!p1 && (d1 != d2)) return -1;
      /* Compatibility */
      if(t1 == t2) return t1;
      else if((t1 < COMPATIBLE) && (t1 > t2)) return t1;
      else if((t2 < COMPATIBLE) && (t2 > t1)) return t2;
   }
   else return -1;
}

/* Condenser Helpers */
int condenser(int size, int lim)
{
   int upper = 1;
   while(upper < size) upper = upper << 1;
   return (upper >> lim);
}

/*void cond_init(int** arr_ptr, int n)
{
   int* temp = (int*)malloc(1*sizeof(int));
   temp[0] = n;
   *arr_ptr = temp; 
}

void cond_push(int** arr_ptr, int n, int count)
{
   int* temp = (int*)realloc(*arr_ptr, (count+1)*sizeof(int));
   temp[count] = n;
   *arr_ptr = temp;
}

int cond_chk(int* arr_ptr, int n, int count)
{
   for(int i = 0; i < count; i++) if(arr_ptr[i] == n) return 1;
   return 0;
}*/

int main(int argc,char* argv[])
{
  yyin = fopen(argv[1],"r");
  fp2 = fopen("tokens.txt","w");
  fp = fopen("output.parsed","w");
  out = fopen("out.cpp","w");
  yyparse();

  return 0;
}

void yyerror(char* err){
   printf("At line %d: %s\n", line, err);
   fprintf(fp,"At line %d: %s\n",line, err);
}
