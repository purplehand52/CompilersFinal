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
   struct Quantum* quantum_states;
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

#line 126 "./exec/y.tab.c"

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
  YYSYMBOL_init_section = 85,              /* init_section  */
  YYSYMBOL_86_1 = 86,                      /* $@1  */
  YYSYMBOL_main_section = 87,              /* main_section  */
  YYSYMBOL_88_2 = 88,                      /* $@2  */
  YYSYMBOL_output_section = 89,            /* output_section  */
  YYSYMBOL_90_3 = 90,                      /* $@3  */
  YYSYMBOL_mandatory_init = 91,            /* mandatory_init  */
  YYSYMBOL_set_states = 92,                /* set_states  */
  YYSYMBOL_set_quantum_states = 93,        /* set_quantum_states  */
  YYSYMBOL_set_classical_states = 94,      /* set_classical_states  */
  YYSYMBOL_quantum_state_list = 95,        /* quantum_state_list  */
  YYSYMBOL_classical_state_list = 96,      /* classical_state_list  */
  YYSYMBOL_classical_state = 97,           /* classical_state  */
  YYSYMBOL_gate_defn_section = 98,         /* gate_defn_section  */
  YYSYMBOL_99_4 = 99,                      /* $@4  */
  YYSYMBOL_gate_defn_list = 100,           /* gate_defn_list  */
  YYSYMBOL_gate_defn = 101,                /* gate_defn  */
  YYSYMBOL_rhs = 102,                      /* rhs  */
  YYSYMBOL_tuple_list = 103,               /* tuple_list  */
  YYSYMBOL_tuple_list2 = 104,              /* tuple_list2  */
  YYSYMBOL_id_list = 105,                  /* id_list  */
  YYSYMBOL_block_defn_section = 106,       /* block_defn_section  */
  YYSYMBOL_107_5 = 107,                    /* $@5  */
  YYSYMBOL_block_defns_list = 108,         /* block_defns_list  */
  YYSYMBOL_block_defn = 109,               /* block_defn  */
  YYSYMBOL_110_6 = 110,                    /* $@6  */
  YYSYMBOL_params = 111,                   /* params  */
  YYSYMBOL_param_id_list = 112,            /* param_id_list  */
  YYSYMBOL_target_params = 113,            /* target_params  */
  YYSYMBOL_target_param_list = 114,        /* target_param_list  */
  YYSYMBOL_block_body = 115,               /* block_body  */
  YYSYMBOL_block_id = 116,                 /* block_id  */
  YYSYMBOL_main_stmt_list = 117,           /* main_stmt_list  */
  YYSYMBOL_main_stmt = 118,                /* main_stmt  */
  YYSYMBOL_stmts = 119,                    /* stmts  */
  YYSYMBOL_120_7 = 120,                    /* $@7  */
  YYSYMBOL_register = 121,                 /* register  */
  YYSYMBOL_call_stmt = 122,                /* call_stmt  */
  YYSYMBOL_parameters = 123,               /* parameters  */
  YYSYMBOL_optional = 124,                 /* optional  */
  YYSYMBOL_register_list = 125,            /* register_list  */
  YYSYMBOL_classic_control = 126,          /* classic_control  */
  YYSYMBOL_quantum_control = 127,          /* quantum_control  */
  YYSYMBOL_target = 128,                   /* target  */
  YYSYMBOL_measure_stmt = 129,             /* measure_stmt  */
  YYSYMBOL_barrier_stmt = 130,             /* barrier_stmt  */
  YYSYMBOL_condition_stmt = 131,           /* condition_stmt  */
  YYSYMBOL_otherwise_list = 132,           /* otherwise_list  */
  YYSYMBOL_otherwise_final = 133,          /* otherwise_final  */
  YYSYMBOL_arithmetic_expr = 134,          /* arithmetic_expr  */
  YYSYMBOL_expr = 135,                     /* expr  */
  YYSYMBOL_value = 136,                    /* value  */
  YYSYMBOL_range = 137,                    /* range  */
  YYSYMBOL_range_list = 138,               /* range_list  */
  YYSYMBOL_var_list = 139,                 /* var_list  */
  YYSYMBOL_for_stmt = 140,                 /* for_stmt  */
  YYSYMBOL_141_8 = 141,                    /* $@8  */
  YYSYMBOL_for_lex_stmt = 142,             /* for_lex_stmt  */
  YYSYMBOL_143_9 = 143,                    /* $@9  */
  YYSYMBOL_for_zip_stmt = 144,             /* for_zip_stmt  */
  YYSYMBOL_145_10 = 145,                   /* $@10  */
  YYSYMBOL_while_stmt = 146,               /* while_stmt  */
  YYSYMBOL_out_id = 147,                   /* out_id  */
  YYSYMBOL_prim_type = 148,                /* prim_type  */
  YYSYMBOL_list_type = 149,                /* list_type  */
  YYSYMBOL_bool_const = 150,               /* bool_const  */
  YYSYMBOL_num = 151,                      /* num  */
  YYSYMBOL_complex_const = 152,            /* complex_const  */
  YYSYMBOL_matrix_const = 153,             /* matrix_const  */
  YYSYMBOL_row_list = 154,                 /* row_list  */
  YYSYMBOL_row = 155,                      /* row  */
  YYSYMBOL_comps = 156,                    /* comps  */
  YYSYMBOL_compatible_const = 157,         /* compatible_const  */
  YYSYMBOL_state_const = 158,              /* state_const  */
  YYSYMBOL_temp = 159,                     /* temp  */
  YYSYMBOL_prim_const = 160,               /* prim_const  */
  YYSYMBOL_vec_const = 161,                /* vec_const  */
  YYSYMBOL_vec_list = 162,                 /* vec_list  */
  YYSYMBOL_calls = 163,                    /* calls  */
  YYSYMBOL_uint_list = 164,                /* uint_list  */
  YYSYMBOL_out_rhs = 165,                  /* out_rhs  */
  YYSYMBOL_out_expr = 166,                 /* out_expr  */
  YYSYMBOL_decl = 167,                     /* decl  */
  YYSYMBOL_echo_stmt = 168,                /* echo_stmt  */
  YYSYMBOL_echo_list = 169,                /* echo_list  */
  YYSYMBOL_save_stmt = 170,                /* save_stmt  */
  YYSYMBOL_out_control = 171,              /* out_control  */
  YYSYMBOL_172_11 = 172,                   /* $@11  */
  YYSYMBOL_out_cond_stmt = 173,            /* out_cond_stmt  */
  YYSYMBOL_174_12 = 174,                   /* $@12  */
  YYSYMBOL_out_other_list = 175,           /* out_other_list  */
  YYSYMBOL_out_other_final = 176,          /* out_other_final  */
  YYSYMBOL_out_for_stmt = 177,             /* out_for_stmt  */
  YYSYMBOL_178_13 = 178,                   /* $@13  */
  YYSYMBOL_179_14 = 179,                   /* $@14  */
  YYSYMBOL_out_for_lex_stmt = 180,         /* out_for_lex_stmt  */
  YYSYMBOL_181_15 = 181,                   /* $@15  */
  YYSYMBOL_182_16 = 182,                   /* $@16  */
  YYSYMBOL_out_for_zip_stmt = 183,         /* out_for_zip_stmt  */
  YYSYMBOL_184_17 = 184,                   /* $@17  */
  YYSYMBOL_185_18 = 185,                   /* $@18  */
  YYSYMBOL_out_while_stmt = 186,           /* out_while_stmt  */
  YYSYMBOL_187_19 = 187,                   /* $@19  */
  YYSYMBOL_out_main = 188,                 /* out_main  */
  YYSYMBOL_out_stmt = 189,                 /* out_stmt  */
  YYSYMBOL_190_20 = 190,                   /* $@20  */
  YYSYMBOL_191_21 = 191                    /* $@21  */
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
#define YYLAST   1128

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  83
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  109
/* YYNRULES -- Number of rules.  */
#define YYNRULES  239
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  551

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
       0,    86,    86,    90,    90,    93,    93,    96,    96,   104,
     108,   109,   110,   111,   112,   115,   118,   121,   127,   132,
     138,   143,   147,   147,   148,   151,   152,   155,   163,   164,
     166,   174,   176,   177,   179,   180,   183,   183,   186,   187,
     190,   190,   207,   208,   211,   212,   215,   216,   217,   220,
     221,   224,   225,   228,   241,   242,   245,   246,   248,   249,
     250,   250,   251,   252,   253,   254,   257,   264,   269,   270,
     271,   272,   273,   281,   291,   292,   295,   296,   299,   300,
     303,   304,   307,   308,   309,   312,   313,   327,   335,   338,
     341,   342,   345,   346,   349,   350,   351,   352,   353,   354,
     355,   358,   359,   360,   361,   362,   363,   364,   365,   366,
     367,   368,   372,   373,   376,   377,   380,   388,   398,   414,
     432,   432,   443,   443,   451,   451,   459,   468,   469,   470,
     473,   474,   475,   476,   477,   478,   479,   480,   483,   490,
     491,   494,   495,   496,   497,   499,   502,   512,   521,   524,
     527,   528,   531,   532,   535,   538,   539,   542,   543,   544,
     545,   546,   547,   548,   549,   550,   553,   564,   583,   591,
     604,   617,   639,   651,   663,   675,   687,   699,   716,   724,
     735,   736,   743,   773,   812,   852,   882,   888,   889,   898,
     907,   916,   926,   936,   954,   964,   983,   995,  1026,  1037,
    1048,  1062,  1082,  1099,  1116,  1119,  1120,  1124,  1128,  1128,
    1129,  1130,  1131,  1132,  1135,  1135,  1138,  1139,  1142,  1143,
    1146,  1151,  1146,  1155,  1161,  1155,  1173,  1179,  1173,  1183,
    1183,  1188,  1189,  1192,  1193,  1194,  1195,  1195,  1196,  1196
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
  "prgm", "init_section", "$@1", "main_section", "$@2", "output_section",
  "$@3", "mandatory_init", "set_states", "set_quantum_states",
  "set_classical_states", "quantum_state_list", "classical_state_list",
  "classical_state", "gate_defn_section", "$@4", "gate_defn_list",
  "gate_defn", "rhs", "tuple_list", "tuple_list2", "id_list",
  "block_defn_section", "$@5", "block_defns_list", "block_defn", "$@6",
  "params", "param_id_list", "target_params", "target_param_list",
  "block_body", "block_id", "main_stmt_list", "main_stmt", "stmts", "$@7",
  "register", "call_stmt", "parameters", "optional", "register_list",
  "classic_control", "quantum_control", "target", "measure_stmt",
  "barrier_stmt", "condition_stmt", "otherwise_list", "otherwise_final",
  "arithmetic_expr", "expr", "value", "range", "range_list", "var_list",
  "for_stmt", "$@8", "for_lex_stmt", "$@9", "for_zip_stmt", "$@10",
  "while_stmt", "out_id", "prim_type", "list_type", "bool_const", "num",
  "complex_const", "matrix_const", "row_list", "row", "comps",
  "compatible_const", "state_const", "temp", "prim_const", "vec_const",
  "vec_list", "calls", "uint_list", "out_rhs", "out_expr", "decl",
  "echo_stmt", "echo_list", "save_stmt", "out_control", "$@11",
  "out_cond_stmt", "$@12", "out_other_list", "out_other_final",
  "out_for_stmt", "$@13", "$@14", "out_for_lex_stmt", "$@15", "$@16",
  "out_for_zip_stmt", "$@17", "$@18", "out_while_stmt", "$@19", "out_main",
  "out_stmt", "$@20", "$@21", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-386)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-237)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      40,    26,    47,    57,  -386,  -386,   123,    75,    78,  -386,
     169,  -386,   151,   136,  -386,  -386,   207,   215,  -386,   160,
     164,   438,  -386,   172,    17,   194,   267,   290,  -386,   292,
    -386,    33,  -386,   225,   227,   302,   233,   236,   239,    16,
     223,    28,  -386,  -386,   309,   252,  -386,    21,  -386,  -386,
    -386,  -386,  -386,  -386,   159,   340,   343,   344,   277,   332,
     359,  -386,   267,   356,   361,    31,   354,   360,   223,  -386,
     376,   376,    53,  -386,  -386,  -386,  -386,   -31,   223,  -386,
     364,   306,  -386,  -386,    -2,   225,    28,   385,   310,   313,
     314,   322,   132,  -386,  -386,  -386,   382,  -386,  -386,  -386,
    -386,  -386,   403,   860,   336,   391,   392,   402,   419,   332,
    -386,  -386,     8,  -386,   223,  -386,   223,   223,   404,   413,
     351,   352,   377,  -386,  -386,  -386,  -386,    53,   450,   807,
     223,   355,   -30,    34,  -386,    53,   424,   432,   364,  -386,
     376,   376,    53,   231,  -386,   408,   384,  -386,   388,  -386,
    -386,  -386,  -386,  -386,  -386,  -386,  -386,  -386,   399,   403,
     403,  -386,   458,   407,   472,  -386,   406,  -386,  -386,   477,
     461,   -29,  -386,  -386,   223,   415,   376,   464,   474,   814,
     274,   274,   274,   274,   274,    53,    53,    53,    53,    53,
      53,    53,   409,  -386,  -386,  -386,   223,  -386,  -386,   821,
     223,   223,  -386,   478,   423,   428,   863,  -386,  -386,  -386,
    -386,  -386,   425,   439,   440,   441,   445,   446,   447,   453,
    -386,  -386,  -386,  -386,  -386,   231,   466,   121,   286,   454,
    -386,  -386,  -386,  -386,  -386,  -386,  -386,  1052,   -28,  -386,
     231,   231,   874,  -386,  -386,   496,   462,  -386,  -386,   475,
    -386,    49,   479,   484,    10,  -386,  -386,  -386,   279,  -386,
     473,   480,  -386,   147,   147,  -386,  -386,  -386,   506,   124,
     524,  -386,   -14,    97,   262,  -386,    59,   488,  -386,  -386,
     489,   555,   559,   504,   231,   231,   231,   231,   231,   231,
     231,   231,   280,    84,   150,    77,  -386,  -386,   125,  -386,
    -386,  -386,  -386,  -386,  -386,   508,   509,   510,   512,   517,
     518,   609,   231,   231,   231,   231,   231,   231,   231,   231,
     231,   231,   231,   231,   231,   231,  -386,   624,  1052,   519,
     523,   407,   472,   529,   531,  -386,   477,  -386,   533,   595,
    -386,   536,  -386,  -386,   526,   540,   279,   279,   276,  -386,
    -386,   279,   537,   542,  -386,   948,   991,  1000,   634,   676,
     686,  1009,   696,   121,  -386,  -386,   129,  -386,   538,  -386,
     471,  -386,   121,   150,  -386,   885,   556,   146,   593,  -386,
    1059,  1059,   187,   187,   349,   195,   216,   280,  1052,   551,
    -386,   625,  -386,  -386,   121,   167,   121,   -48,  -386,   595,
     550,   465,   279,   554,   558,   557,   560,   610,  -386,   331,
     564,   279,   279,  -386,   231,   231,   231,  -386,  -386,  -386,
      29,  -386,   121,  -386,  -386,   538,  -386,   561,   566,   572,
    -386,   562,   183,  -386,   573,  -386,    62,   570,  -386,  -386,
    -386,   575,   465,   577,  -386,   279,  -386,  -386,  -386,   578,
     580,   581,   400,   738,   748,   758,   584,   231,  -386,  -386,
    -386,   231,  -386,   631,   121,  -386,   121,  -386,   121,  -386,
    -386,   279,   342,  -386,   588,   597,   630,  -386,  -386,  -386,
     621,  -386,  -386,  -386,  -386,  -386,    64,  1052,   926,   507,
     607,  -386,   184,    90,  -386,  -386,  -386,  -386,   154,  -386,
    -386,   604,   605,   231,   603,   619,  -386,   680,  -386,  -386,
     369,   372,  -386,    53,   528,  -386,  -386,  1052,  -386,   231,
     675,  -386,  -386,  -386,   411,   870,  -386,  -386,  -386,   937,
     214,  -386,  -386,   629,   534,   544,  -386,  -386,   231,  -386,
    -386,  -386,   574,   800,   427,  -386,   635,  -386,  -386,   591,
    -386
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     3,     1,     0,     0,     0,     5,
       0,     2,     0,    14,    55,     7,     0,     0,    36,    12,
      13,    60,   232,     0,     0,    22,    39,     0,    10,     0,
      11,    53,    66,    82,     0,     0,     0,     0,     0,     0,
       0,     0,    54,    56,     0,     0,    58,     0,    59,    57,
      62,    63,    64,    65,   238,     0,     0,     0,     0,     0,
       0,    37,    39,     0,     0,     0,     0,     0,     0,   120,
       0,     0,     0,     6,    88,    67,    79,     0,     0,    74,
      76,     0,    61,    80,    53,    82,     0,     0,     0,     0,
       0,     0,     0,   235,   234,   233,     0,   210,   211,   212,
     213,   231,     0,     0,     0,     0,     0,     0,     0,    23,
      26,    53,     0,    38,     0,    83,     0,     0,     0,     0,
     119,     0,     0,    99,   100,   110,   111,     0,   109,     0,
       0,     0,     0,     0,    73,     0,     0,     0,    76,   220,
       0,     0,     0,     0,     8,     0,     0,   209,     0,   237,
     130,   131,   132,   133,   134,   135,   136,   137,     0,     0,
       0,   239,     0,     0,     0,     4,     0,    25,    42,     0,
      46,     0,    71,    70,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    78,    81,    75,     0,    85,    77,     0,
       0,     0,    72,     0,     0,     0,     0,   127,   161,   162,
     139,   140,     0,     0,     0,     0,     0,     0,     0,     0,
     128,   129,   165,   163,   164,     0,     0,     0,     0,   182,
     157,   158,   159,   160,   180,   181,   186,   206,     0,   207,
       0,     0,     0,   202,   203,     0,    15,    18,    21,    16,
      20,     0,    45,     0,     0,    40,    84,    87,     0,   118,
       0,     0,   108,    94,    95,    96,    97,    98,   101,   102,
     103,   104,   106,   105,   107,    55,     0,     0,    69,    68,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   188,     0,     0,     0,   148,   168,     0,   144,
     142,   141,   143,   156,   155,     0,   161,   162,   163,   164,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   204,     0,   201,     0,
       0,     0,     0,     0,     0,    27,     0,    43,    50,     0,
      48,     0,   113,   112,     0,     0,     0,     0,    60,    86,
      55,     0,     0,     0,   229,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   153,   152,     0,   151,     0,   146,
       0,   166,     0,     0,   187,     0,   191,   192,   189,   190,
     195,   196,   193,   194,   197,   198,   199,   200,   205,     0,
     138,     0,    17,    19,     0,     0,     0,     0,    44,     0,
       0,    51,     0,     0,   117,     0,     0,     0,   126,    60,
       0,     0,     0,   232,     0,     0,     0,   172,   173,   177,
       0,   176,     0,   149,   147,     0,   167,     0,     0,   183,
     214,     0,     0,    35,     0,    28,     0,     0,    29,    49,
      47,     0,    51,   114,    55,     0,   122,   124,    91,     0,
       0,     0,   238,     0,     0,     0,     0,     0,   150,   154,
     145,     0,   232,     0,     0,    31,     0,    33,     0,    41,
      52,     0,    60,   116,     0,     0,    93,   221,   223,   226,
       0,   230,   169,   170,   171,   174,     0,   179,     0,   238,
       0,    34,     0,     0,   115,   121,    55,    55,     0,    89,
     232,     0,     0,     0,     0,   184,   217,     0,    30,    32,
      60,    60,    55,     0,   238,   224,   227,   178,   175,     0,
     219,     9,   123,   125,    60,     0,   222,   232,   232,     0,
       0,   215,    92,     0,   238,   238,   185,   232,     0,    55,
     225,   228,   238,     0,    60,   218,     0,    90,   232,   238,
     216
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -386,  -386,  -386,  -386,  -386,  -386,  -386,  -386,  -386,  -386,
     687,   692,  -386,  -386,   381,  -386,  -386,  -386,   608,  -386,
    -386,  -386,  -348,  -386,  -386,   654,  -386,  -386,  -386,   386,
    -386,  -314,   281,   -24,  -273,  -386,  -267,  -386,    51,  -386,
     638,   583,   -74,  -386,    88,  -386,  -386,  -386,  -386,  -386,
    -386,   157,  -127,  -385,  -242,  -333,   -59,  -386,  -386,  -386,
    -386,  -386,  -386,  -386,  -386,   485,  -386,  -386,  -218,  -220,
    -386,  -386,   358,  -386,   311,  -162,  -224,  -221,  -386,  -386,
    -386,  -386,  -219,   161,  -386,  -386,  -386,  -386,  -386,  -386,
    -386,  -386,  -386,  -386,  -386,  -386,  -386,  -386,  -386,  -386,
    -386,  -386,  -386,  -386,  -386,  -339,  -386,  -386,  -386
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     2,     3,     8,     7,    14,    11,    22,    13,    18,
      19,    20,   246,   249,   250,    58,    59,   109,   110,   335,
     395,   397,   432,    25,    26,    61,    62,   341,   170,   253,
     255,   340,   441,    41,    21,    42,    43,    44,    45,    46,
      80,   134,    77,    47,    66,   198,    48,    49,    82,   476,
     499,   128,   129,   344,   404,   405,   121,    50,   119,    51,
     474,    52,   475,    53,   229,   159,   160,   230,   303,   231,
     232,   295,   296,   366,   367,   233,   433,   234,   235,   298,
     236,   486,   237,   149,   161,    93,   238,    94,    95,    96,
     147,   462,   520,   531,    97,   203,   500,    98,   501,   527,
      99,   502,   528,   100,   413,    54,   101,   102,   103
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     179,   247,   348,   305,   132,   297,   292,   304,   199,   311,
     310,   168,   122,   338,   406,   206,   345,   443,   -82,   187,
     188,   327,   328,    86,    84,   400,   437,    56,    57,    73,
     438,    75,    32,   456,    75,    32,   112,    75,    32,    85,
     171,    74,     4,   130,   130,   130,   325,     5,   436,   131,
     195,   256,   326,   -82,   190,   191,   123,   124,   268,   269,
     270,   271,   272,   273,   274,   355,   356,   357,   358,   359,
     360,   361,   362,   365,   452,   364,   310,   409,   450,   451,
      65,   204,   205,   125,   126,   439,   494,   169,   299,   339,
     300,    76,    79,   375,   376,   377,   378,   379,   380,   381,
     382,   383,   384,   385,   386,   387,   388,    78,   457,   410,
     114,     1,   473,   196,   -67,    65,   115,   259,   492,   118,
     493,    67,   276,   489,   333,   299,   334,   300,     6,    76,
     187,   188,   127,   130,   442,     9,   464,    79,   503,   349,
     301,   302,   467,   365,   504,   364,    10,   144,   427,   426,
      12,   368,   304,   369,   299,   428,   300,   187,   188,   363,
      16,   514,  -236,   294,   464,    76,   191,   172,   173,   392,
     509,   472,   136,   137,   304,   442,   304,   301,   302,   315,
     316,   193,  -208,    15,   197,    87,    88,    89,   534,   535,
     145,   189,   190,   191,    90,   453,   454,   455,   542,   370,
     294,   371,   365,   422,   364,   423,   301,   302,    17,   549,
     182,   183,   184,   322,   323,   324,   313,    23,    91,   314,
     315,   316,    24,   510,   511,   257,    75,    32,   315,   316,
      92,   512,    27,   513,   207,   208,    29,   209,   487,   524,
     491,   434,   488,   435,   304,    55,   304,    76,   304,   315,
     316,   278,   279,   321,   322,   323,   324,   464,   464,   465,
     508,   210,   211,   323,   324,   -24,   544,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   123,   124,    31,
      32,   222,   342,   343,   517,   324,    60,   223,   224,   207,
     306,   537,   307,   538,    33,   187,   188,    63,    34,    64,
     529,   225,    35,    36,    37,    69,   226,    65,   227,    68,
     228,    38,    70,   315,   316,    71,   210,   211,    72,   543,
     243,   244,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,    81,    83,    31,    32,   222,   263,   264,   265,
     266,   267,   308,   309,   104,    31,    32,   407,   107,    33,
     108,   105,   106,    34,   408,    40,   225,    35,    36,    37,
      33,   226,   111,   227,    34,   228,    38,    57,    35,    36,
      37,    56,    31,    32,   116,    31,    32,    38,   313,   120,
     117,   314,   315,   316,   133,   135,   525,    33,   139,   140,
      33,    34,   141,   142,    34,    35,    36,    37,    35,    36,
      37,   143,   407,  -236,    38,   146,   148,    38,   162,   448,
      40,   163,   164,   407,    31,    32,   322,   323,   324,   165,
     495,    40,   166,  -208,   174,   176,    87,    88,    89,    33,
      31,    32,   177,    34,   175,    90,   194,    35,    36,    37,
     407,    31,    32,   407,   200,    33,    38,   522,    40,    34,
     523,    40,   201,    35,    36,    37,    33,   178,   239,    91,
      34,   241,    38,   240,    35,    36,    37,   245,    31,    32,
     208,   480,   209,    38,   242,   208,   248,   209,   481,   251,
     252,   254,   407,    33,   227,   260,   275,    34,   -60,   532,
      40,    35,    36,    37,   258,   261,   210,   211,   407,   280,
      38,   210,   211,   281,   284,   547,    40,   330,   282,    39,
    -236,   180,   181,   182,   183,   184,   222,    40,   285,   286,
     287,   222,   223,   224,   288,   289,   290,   223,   224,   312,
    -208,  -236,   291,    87,    88,    89,   331,  -236,   186,   187,
     188,   293,    90,   227,    40,   294,   425,  -236,   227,   332,
     294,  -208,   346,   336,    87,    88,    89,  -208,   188,   347,
      87,    88,    89,    90,   337,   350,    91,  -208,   351,    90,
      87,    88,    89,   189,   190,   191,   352,  -236,   480,    90,
     353,   354,   372,  -144,  -142,   506,  -141,    91,   314,   315,
     316,  -143,   373,    91,  -236,   390,   391,  -208,   338,   480,
      87,    88,    89,    91,   394,   480,   526,   399,   402,    90,
     396,   401,   540,   363,  -208,   480,   411,    87,    88,    89,
     403,   412,   541,   322,   323,   324,    90,   316,   430,   431,
     440,   444,   445,    91,   463,    74,   490,   446,   313,   459,
     447,   314,   315,   316,   449,   480,   460,   461,   466,   468,
      91,   469,   545,   313,   498,   477,   314,   315,   316,   471,
     478,   479,   480,   313,   485,   496,   314,   315,   316,   550,
     317,   318,   319,   320,   497,   321,   322,   323,   324,   145,
     507,   515,   516,   518,   521,   317,   318,   319,   320,   374,
     321,   322,   323,   324,   519,   317,   318,   319,   320,   530,
     321,   322,   323,   324,   389,   313,   539,    30,   314,   315,
     316,    28,   548,   393,   417,   313,   113,   167,   314,   315,
     316,   202,   398,   470,   138,   313,   424,   329,   314,   315,
     316,     0,     0,   458,     0,     0,     0,   317,   318,   319,
     320,     0,   321,   322,   323,   324,     0,   317,   318,   319,
     320,     0,   321,   322,   323,   324,   418,   317,   318,   319,
     320,     0,   321,   322,   323,   324,   419,   313,     0,     0,
     314,   315,   316,     0,     0,     0,   421,   313,     0,     0,
     314,   315,   316,     0,     0,     0,     0,   313,     0,     0,
     314,   315,   316,     0,     0,     0,     0,     0,     0,   317,
     318,   319,   320,     0,   321,   322,   323,   324,     0,   317,
     318,   319,   320,     0,   321,   322,   323,   324,   482,   317,
     318,   319,   320,     0,   321,   322,   323,   324,   483,   313,
       0,     0,   314,   315,   316,     0,   185,     0,   484,   186,
     187,   188,     0,   185,     0,     0,   186,   187,   188,     0,
     185,     0,     0,   186,   187,   188,     0,     0,     0,     0,
       0,   317,   318,   319,   320,     0,   321,   322,   323,   324,
       0,     0,     0,     0,   189,   190,   191,     0,     0,     0,
     546,   189,   190,   191,     0,     0,     0,   192,   189,   190,
     191,     0,   185,     0,   262,   186,   187,   188,     0,   185,
       0,   277,   186,   187,   188,     0,   150,   151,   152,   153,
     154,   155,   156,   157,   313,   158,     0,   314,   315,   316,
     150,   151,   152,   153,   154,   155,   156,   157,     0,     0,
     189,   190,   191,     0,     0,     0,     0,   189,   190,   191,
       0,     0,     0,   283,     0,     0,   317,   318,   319,   320,
     533,   321,   322,   323,   324,   313,     0,     0,   314,   315,
     316,   429,     0,     0,     0,     0,   313,     0,     0,   314,
     315,   316,     0,     0,     0,     0,     0,   313,     0,     0,
     314,   315,   316,     0,     0,     0,     0,   317,   318,   319,
     320,     0,   321,   322,   323,   324,     0,     0,   317,   318,
     319,   320,   505,   321,   322,   323,   324,     0,     0,   317,
     318,   319,   320,   536,   321,   322,   323,   324,     0,     0,
     313,     0,   414,   314,   315,   316,     0,     0,     0,   313,
       0,     0,   314,   315,   316,     0,     0,     0,   313,     0,
       0,   314,   315,   316,     0,     0,     0,     0,     0,     0,
       0,     0,   317,   318,   319,   320,     0,   321,   322,   323,
     324,   317,   318,   319,   320,   415,   321,   322,   323,   324,
     317,   318,   319,   320,   416,   321,   322,   323,   324,     0,
       0,   313,     0,   420,   314,   315,   316,     0,   313,     0,
       0,   314,   315,   316,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   317,   318,   319,   320,     0,   321,   322,
     323,   324,   319,   320,     0,   321,   322,   323,   324
};

static const yytype_int16 yycheck[] =
{
     127,   163,   275,   227,    78,   226,   225,   227,   135,   228,
     228,     3,    71,     3,   347,   142,   258,   402,    20,    33,
      34,   240,   241,    47,     3,   339,    74,    10,    11,    13,
      78,     3,     4,     4,     3,     4,    60,     3,     4,    18,
     114,    25,    16,    74,    74,    74,    74,     0,   396,    80,
      80,    80,    80,    20,    68,    69,     3,     4,   185,   186,
     187,   188,   189,   190,   191,   284,   285,   286,   287,   288,
     289,   290,   291,   293,   413,   293,   294,   350,   411,   412,
      82,   140,   141,    30,    31,   399,   471,    79,     4,    79,
       6,    40,    41,   312,   313,   314,   315,   316,   317,   318,
     319,   320,   321,   322,   323,   324,   325,    79,    79,   351,
      79,    71,   445,    79,    81,    82,    65,   176,   466,    68,
     468,    33,   196,   462,    75,     4,    77,     6,    71,    78,
      33,    34,    79,    74,   401,    12,    74,    86,    74,    80,
      56,    57,    80,   363,    80,   363,    71,    15,   372,   370,
      72,    74,   372,    76,     4,   373,     6,    33,    34,    75,
       9,   500,     3,    79,    74,   114,    69,   116,   117,   331,
      80,   444,    84,    85,   394,   442,   396,    56,    57,    33,
      34,   130,    23,    14,   133,    26,    27,    28,   527,   528,
      58,    67,    68,    69,    35,   414,   415,   416,   537,    74,
      79,    76,   422,    74,   422,    76,    56,    57,    72,   548,
      63,    64,    65,    67,    68,    69,    29,    10,    59,    32,
      33,    34,     7,   496,   497,   174,     3,     4,    33,    34,
      71,    77,    72,    79,     3,     4,    72,     6,   457,   512,
     464,    74,   461,    76,   464,    73,   466,   196,   468,    33,
      34,   200,   201,    66,    67,    68,    69,    74,    74,    76,
      76,    30,    31,    68,    69,    71,   539,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,     3,     4,     3,
       4,    50,     3,     4,   503,    69,    19,    56,    57,     3,
       4,    77,     6,    79,    18,    33,    34,     7,    22,     7,
     519,    70,    26,    27,    28,     3,    75,    82,    77,    82,
      79,    35,    79,    33,    34,    79,    30,    31,    79,   538,
     159,   160,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    23,    81,     3,     4,    50,   180,   181,   182,
     183,   184,    56,    57,     4,     3,     4,    71,    71,    18,
      18,     8,     8,    22,    78,    79,    70,    26,    27,    28,
      18,    75,     3,    77,    22,    79,    35,    11,    26,    27,
      28,    10,     3,     4,    20,     3,     4,    35,    29,     3,
      20,    32,    33,    34,    20,    79,   513,    18,     3,    79,
      18,    22,    79,    79,    22,    26,    27,    28,    26,    27,
      28,    79,    71,     3,    35,    23,     3,    35,    72,    78,
      79,    20,    20,    71,     3,     4,    67,    68,    69,    17,
      78,    79,     3,    23,    20,    74,    26,    27,    28,    18,
       3,     4,    80,    22,    21,    35,    81,    26,    27,    28,
      71,     3,     4,    71,    20,    18,    35,    78,    79,    22,
      78,    79,    20,    26,    27,    28,    18,    80,    50,    59,
      22,    73,    35,    79,    26,    27,    28,     9,     3,     4,
       4,    71,     6,    35,    75,     4,     4,     6,    78,    73,
       3,    20,    71,    18,    77,    21,    77,    22,    23,    78,
      79,    26,    27,    28,    79,    21,    30,    31,    71,    21,
      35,    30,    31,    80,    79,    78,    79,    11,    80,    71,
       3,    61,    62,    63,    64,    65,    50,    79,    79,    79,
      79,    50,    56,    57,    79,    79,    79,    56,    57,    75,
      23,     3,    79,    26,    27,    28,    74,     3,    32,    33,
      34,    75,    35,    77,    79,    79,    75,     3,    77,    74,
      79,    23,    79,    74,    26,    27,    28,    23,    34,    79,
      26,    27,    28,    35,    80,    77,    59,    23,    79,    35,
      26,    27,    28,    67,    68,    69,    21,     3,    71,    35,
      21,    77,    74,    74,    74,    78,    74,    59,    32,    33,
      34,    74,    74,    59,     3,    76,    73,    23,     3,    71,
      26,    27,    28,    59,    75,    71,    78,    74,    82,    35,
      79,    75,    78,    75,    23,    71,    79,    26,    27,    28,
      80,    79,    78,    67,    68,    69,    35,    34,    77,     4,
      80,    77,    74,    59,    72,    25,     5,    80,    29,    78,
      80,    32,    33,    34,    80,    71,    80,    75,    75,    79,
      59,    76,    78,    29,    24,    77,    32,    33,    34,    82,
      80,    80,    71,    29,    80,    77,    32,    33,    34,    78,
      61,    62,    63,    64,    77,    66,    67,    68,    69,    58,
      73,    77,    77,    80,     4,    61,    62,    63,    64,    80,
      66,    67,    68,    69,    75,    61,    62,    63,    64,    24,
      66,    67,    68,    69,    80,    29,    77,    20,    32,    33,
      34,    19,    77,   332,    80,    29,    62,   109,    32,    33,
      34,   138,   336,   442,    86,    29,   368,   242,    32,    33,
      34,    -1,    -1,   422,    -1,    -1,    -1,    61,    62,    63,
      64,    -1,    66,    67,    68,    69,    -1,    61,    62,    63,
      64,    -1,    66,    67,    68,    69,    80,    61,    62,    63,
      64,    -1,    66,    67,    68,    69,    80,    29,    -1,    -1,
      32,    33,    34,    -1,    -1,    -1,    80,    29,    -1,    -1,
      32,    33,    34,    -1,    -1,    -1,    -1,    29,    -1,    -1,
      32,    33,    34,    -1,    -1,    -1,    -1,    -1,    -1,    61,
      62,    63,    64,    -1,    66,    67,    68,    69,    -1,    61,
      62,    63,    64,    -1,    66,    67,    68,    69,    80,    61,
      62,    63,    64,    -1,    66,    67,    68,    69,    80,    29,
      -1,    -1,    32,    33,    34,    -1,    29,    -1,    80,    32,
      33,    34,    -1,    29,    -1,    -1,    32,    33,    34,    -1,
      29,    -1,    -1,    32,    33,    34,    -1,    -1,    -1,    -1,
      -1,    61,    62,    63,    64,    -1,    66,    67,    68,    69,
      -1,    -1,    -1,    -1,    67,    68,    69,    -1,    -1,    -1,
      80,    67,    68,    69,    -1,    -1,    -1,    80,    67,    68,
      69,    -1,    29,    -1,    80,    32,    33,    34,    -1,    29,
      -1,    80,    32,    33,    34,    -1,    46,    47,    48,    49,
      50,    51,    52,    53,    29,    55,    -1,    32,    33,    34,
      46,    47,    48,    49,    50,    51,    52,    53,    -1,    -1,
      67,    68,    69,    -1,    -1,    -1,    -1,    67,    68,    69,
      -1,    -1,    -1,    80,    -1,    -1,    61,    62,    63,    64,
      80,    66,    67,    68,    69,    29,    -1,    -1,    32,    33,
      34,    76,    -1,    -1,    -1,    -1,    29,    -1,    -1,    32,
      33,    34,    -1,    -1,    -1,    -1,    -1,    29,    -1,    -1,
      32,    33,    34,    -1,    -1,    -1,    -1,    61,    62,    63,
      64,    -1,    66,    67,    68,    69,    -1,    -1,    61,    62,
      63,    64,    76,    66,    67,    68,    69,    -1,    -1,    61,
      62,    63,    64,    76,    66,    67,    68,    69,    -1,    -1,
      29,    -1,    74,    32,    33,    34,    -1,    -1,    -1,    29,
      -1,    -1,    32,    33,    34,    -1,    -1,    -1,    29,    -1,
      -1,    32,    33,    34,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    61,    62,    63,    64,    -1,    66,    67,    68,
      69,    61,    62,    63,    64,    74,    66,    67,    68,    69,
      61,    62,    63,    64,    74,    66,    67,    68,    69,    -1,
      -1,    29,    -1,    74,    32,    33,    34,    -1,    29,    -1,
      -1,    32,    33,    34,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    61,    62,    63,    64,    -1,    66,    67,
      68,    69,    63,    64,    -1,    66,    67,    68,    69
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    71,    84,    85,    16,     0,    71,    87,    86,    12,
      71,    89,    72,    91,    88,    14,     9,    72,    92,    93,
      94,   117,    90,    10,     7,   106,   107,    72,    94,    72,
      93,     3,     4,    18,    22,    26,    27,    28,    35,    71,
      79,   116,   118,   119,   120,   121,   122,   126,   129,   130,
     140,   142,   144,   146,   188,    73,    10,    11,    98,    99,
      19,   108,   109,     7,     7,    82,   127,   127,    82,     3,
      79,    79,    79,    13,    25,     3,   121,   125,    79,   121,
     123,    23,   131,    81,     3,    18,   116,    26,    27,    28,
      35,    59,    71,   168,   170,   171,   172,   177,   180,   183,
     186,   189,   190,   191,     4,     8,     8,    71,    18,   100,
     101,     3,   116,   108,    79,   121,    20,    20,   121,   141,
       3,   139,   139,     3,     4,    30,    31,    79,   134,   135,
      74,    80,   125,    20,   124,    79,   127,   127,   123,     3,
      79,    79,    79,    79,    15,    58,    23,   173,     3,   166,
      46,    47,    48,    49,    50,    51,    52,    53,    55,   148,
     149,   167,    72,    20,    20,    17,     3,   101,     3,    79,
     111,   125,   121,   121,    20,    21,    74,    80,    80,   135,
      61,    62,    63,    64,    65,    29,    32,    33,    34,    67,
      68,    69,    80,   121,    81,    80,    79,   121,   128,   135,
      20,    20,   124,   178,   139,   139,   135,     3,     4,     6,
      30,    31,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    50,    56,    57,    70,    75,    77,    79,   147,
     150,   152,   153,   158,   160,   161,   163,   165,   169,    50,
      79,    73,    75,   166,   166,     9,    95,   158,     4,    96,
      97,    73,     3,   112,    20,   113,    80,   121,    79,   139,
      21,    21,    80,   134,   134,   134,   134,   134,   135,   135,
     135,   135,   135,   135,   135,    77,   125,    80,   121,   121,
      21,    80,    80,    80,    79,    79,    79,    79,    79,    79,
      79,    79,   165,    75,    79,   154,   155,   160,   162,     4,
       6,    56,    57,   151,   152,   159,     4,     6,    56,    57,
     151,   165,    75,    29,    32,    33,    34,    61,    62,    63,
      64,    66,    67,    68,    69,    74,    80,   165,   165,   148,
      11,    74,    74,    75,    77,   102,    74,    80,     3,    79,
     114,   110,     3,     4,   136,   137,    79,    79,   117,    80,
      77,    79,    21,    21,    77,   165,   165,   165,   165,   165,
     165,   165,   165,    75,   151,   152,   156,   157,    74,    76,
      74,    76,    74,    74,    80,   165,   165,   165,   165,   165,
     165,   165,   165,   165,   165,   165,   165,   165,   165,    80,
      76,    73,   158,    97,    75,   103,    79,   104,   112,    74,
     114,    75,    82,    80,   137,   138,   138,    71,    78,   117,
     137,    79,    79,   187,    74,    74,    74,    80,    80,    80,
      74,    80,    74,    76,   155,    75,   160,   159,   151,    76,
      77,     4,   105,   159,    74,    76,   105,    74,    78,   114,
      80,   115,   119,   136,    77,    74,    80,    80,    78,    80,
     138,   138,   188,   165,   165,   165,     4,    79,   157,    78,
      80,    75,   174,    72,    74,    76,    75,    80,    79,    76,
     115,    82,   117,   138,   143,   145,   132,    77,    80,    80,
      71,    78,    80,    80,    80,    80,   164,   165,   165,   188,
       5,   159,   105,   105,   136,    78,    77,    77,    24,   133,
     179,   181,   184,    74,    80,    76,    78,    73,    76,    80,
     117,   117,    77,    79,   188,    77,    77,   165,    80,    75,
     175,     4,    78,    78,   117,   135,    78,   182,   185,   165,
      24,   176,    78,    80,   188,   188,    76,    77,    79,    77,
      78,    78,   188,   165,   117,    78,    80,    78,    77,   188,
      78
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    83,    84,    86,    85,    88,    87,    90,    89,    91,
      92,    92,    92,    92,    92,    93,    94,    95,    95,    96,
      96,    97,    99,    98,    98,   100,   100,   101,   102,   102,
     103,   103,   104,   104,   105,   105,   107,   106,   108,   108,
     110,   109,   111,   111,   112,   112,   113,   113,   113,   114,
     114,   115,   115,   116,   117,   117,   118,   118,   119,   119,
     120,   119,   119,   119,   119,   119,   121,   121,   122,   122,
     122,   122,   122,   122,   123,   123,   124,   124,   125,   125,
     126,   126,   127,   127,   127,   128,   128,   129,   130,   131,
     132,   132,   133,   133,   134,   134,   134,   134,   134,   134,
     134,   135,   135,   135,   135,   135,   135,   135,   135,   135,
     135,   135,   136,   136,   137,   137,   138,   138,   139,   139,
     141,   140,   143,   142,   145,   144,   146,   147,   147,   147,
     148,   148,   148,   148,   148,   148,   148,   148,   149,   150,
     150,   151,   151,   151,   151,   152,   153,   154,   154,   155,
     156,   156,   157,   157,   158,   159,   159,   160,   160,   160,
     160,   160,   160,   160,   160,   160,   161,   162,   162,   163,
     163,   163,   163,   163,   163,   163,   163,   163,   164,   164,
     165,   165,   165,   165,   165,   165,   165,   165,   165,   165,
     165,   165,   165,   165,   165,   165,   165,   165,   165,   165,
     165,   166,   167,   167,   168,   169,   169,   170,   172,   171,
     171,   171,   171,   171,   174,   173,   175,   175,   176,   176,
     178,   179,   177,   181,   182,   180,   184,   185,   183,   187,
     186,   188,   188,   189,   189,   189,   190,   189,   191,   189
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     3,     0,     9,     0,     6,     0,     6,    14,
       2,     2,     1,     1,     0,     6,     6,     3,     1,     3,
       1,     1,     0,     2,     0,     2,     1,     4,     3,     3,
       5,     3,     5,     3,     3,     1,     0,     2,     2,     0,
       0,     8,     1,     3,     3,     1,     0,     4,     2,     3,
       1,     0,     2,     1,     2,     0,     1,     1,     1,     1,
       0,     2,     1,     1,     1,     1,     1,     1,     5,     5,
       4,     4,     4,     3,     1,     3,     0,     2,     3,     1,
       2,     4,     0,     2,     4,     1,     3,     5,     2,     9,
       8,     0,     4,     0,     3,     3,     3,     3,     3,     1,
       1,     3,     3,     3,     3,     3,     3,     3,     3,     1,
       1,     1,     1,     1,     3,     5,     3,     1,     3,     1,
       0,    10,     0,    12,     0,    12,     7,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     4,     1,
       1,     1,     1,     1,     1,     5,     3,     3,     1,     3,
       3,     1,     1,     1,     5,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     3,     1,     6,
       6,     6,     4,     4,     6,     8,     4,     4,     3,     1,
       1,     1,     1,     4,     7,    10,     1,     3,     2,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     2,     2,     4,     3,     1,     3,     0,     2,
       1,     1,     1,     1,     0,    10,     8,     0,     4,     0,
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
  case 2: /* prgm: init_section main_section output_section  */
#line 86 "./Parser/parser_main.y"
                                                                   {fprintf(fp,"\nParsing successful!\n");printOutputTable(&OutputSymbolTable);}
#line 1805 "./exec/y.tab.c"
    break;

  case 3: /* $@1: %empty  */
#line 90 "./Parser/parser_main.y"
                                           {fprintf(fp,"\nInit section begins\n\n");}
#line 1811 "./exec/y.tab.c"
    break;

  case 4: /* init_section: '\\' INIT_BEGIN $@1 mandatory_init set_states block_defn_section gate_defn_section '\\' INIT_END  */
#line 90 "./Parser/parser_main.y"
                                                                                                                                                                   {fprintf(fp,"\nInit section ends\n");}
#line 1817 "./exec/y.tab.c"
    break;

  case 5: /* $@2: %empty  */
#line 93 "./Parser/parser_main.y"
                                            {fprintf(fp,"\nMain section begins\n\n");}
#line 1823 "./exec/y.tab.c"
    break;

  case 6: /* main_section: '\\' MAIN_BEGIN $@2 main_stmt_list '\\' MAIN_END  */
#line 93 "./Parser/parser_main.y"
                                                                                                                    {fprintf(fp,"\nMain section ends\n");}
#line 1829 "./exec/y.tab.c"
    break;

  case 7: /* $@3: %empty  */
#line 96 "./Parser/parser_main.y"
                                             {fprintf(fp,"\nOutput section begins\n\n"); isInOutput = true; outputLevel = 1;}
#line 1835 "./exec/y.tab.c"
    break;

  case 8: /* output_section: '\\' OUTPUT_BEGIN $@3 out_main '\\' OUTPUT_END  */
#line 96 "./Parser/parser_main.y"
                                                                                                                                                        {fprintf(fp,"\nOutput section ends\n");exitOutputSymbolScope(&OutputSymbolTable,outputLevel);}
#line 1841 "./exec/y.tab.c"
    break;

  case 9: /* mandatory_init: '#' REGISTERS QUANTUM '=' NUMBER '#' REGISTERS CLASSICAL '=' NUMBER '#' ITERS '=' NUMBER  */
#line 104 "./Parser/parser_main.y"
                                                                                                                    {  fprintf(fp,"Register and iteration initialization section\n");classical_registers = yyvsp[-4].num;quantum_registers = yyvsp[-9].num;iterations = yyvsp[0].num;}
#line 1847 "./exec/y.tab.c"
    break;

  case 15: /* set_quantum_states: '#' SET QUANTUM STATES ARROW quantum_state_list  */
#line 115 "./Parser/parser_main.y"
                                                                            {fprintf(fp,"Setting initial state of quantum registers\n");}
#line 1853 "./exec/y.tab.c"
    break;

  case 16: /* set_classical_states: '#' SET CLASSICAL STATES ARROW classical_state_list  */
#line 118 "./Parser/parser_main.y"
                                                                                {fprintf(fp,"Setting initial state of classical registers\n");}
#line 1859 "./exec/y.tab.c"
    break;

  case 17: /* quantum_state_list: quantum_state_list ',' state_const  */
#line 121 "./Parser/parser_main.y"
                                                                     {  if(quantum_index == quantum_registers){
                                                                           yyerror("semantic error: quantum registers out of bounds");
                                                                           return 1;
                                                                        }  
                                                                        quantum_states[quantum_index++] = yyvsp[0].q;
                                                                     }
#line 1870 "./exec/y.tab.c"
    break;

  case 18: /* quantum_state_list: state_const  */
#line 127 "./Parser/parser_main.y"
                                                                     {  quantum_states = (struct Quantum*)malloc(sizeof(struct Quantum)*quantum_registers);
                                                                        quantum_states[quantum_index++] = yyvsp[0].q;
                                                                     }
#line 1878 "./exec/y.tab.c"
    break;

  case 19: /* classical_state_list: classical_state_list ',' classical_state  */
#line 132 "./Parser/parser_main.y"
                                                                     { if(classical_index == classical_registers){
                                                                           yyerror("semantic error: classical registers out of bounds");
                                                                           return 1;
                                                                        }
                                                                        classical_states[classical_index++] = yyvsp[0].num;
                                                                     }
#line 1889 "./exec/y.tab.c"
    break;

  case 20: /* classical_state_list: classical_state  */
#line 138 "./Parser/parser_main.y"
                                                                     {  classical_states = (int *)malloc(sizeof(int)*classical_registers);
                                                                        classical_states[classical_index++] = yyvsp[0].num;
                                                                     }
#line 1897 "./exec/y.tab.c"
    break;

  case 21: /* classical_state: NUMBER  */
#line 143 "./Parser/parser_main.y"
                                                                     {yyval.num = yyvsp[0].num;}
#line 1903 "./exec/y.tab.c"
    break;

  case 22: /* $@4: %empty  */
#line 147 "./Parser/parser_main.y"
                           {fprintf(fp,"Gate definition section begins\n");}
#line 1909 "./exec/y.tab.c"
    break;

  case 23: /* gate_defn_section: $@4 gate_defn_list  */
#line 147 "./Parser/parser_main.y"
                                                                                            {fprintf(fp,"Gate definition section ends\n");}
#line 1915 "./exec/y.tab.c"
    break;

  case 27: /* gate_defn: GATE ID '=' rhs  */
#line 155 "./Parser/parser_main.y"
                                             {  fprintf(fp,"Gate definition\n");
                                                if(!insertInGateTable(&GateSymbolTable,yyvsp[-2].str,yyvsp[0].rows,yyvsp[0].cols)){
                                                   yyerror("semantic error: gate definition requires square matrix");
                                                   return 1;
                                                }
                                             }
#line 1926 "./exec/y.tab.c"
    break;

  case 28: /* rhs: '[' tuple_list ']'  */
#line 163 "./Parser/parser_main.y"
                                                {yyval.rows = yyvsp[-1].rows;yyval.cols = yyvsp[-1].cols;}
#line 1932 "./exec/y.tab.c"
    break;

  case 30: /* tuple_list: tuple_list ',' '[' id_list ']'  */
#line 166 "./Parser/parser_main.y"
                                                         {  if(yyvsp[-4].cols != yyvsp[-1].cols){
                                                               yyerror("semantic error: rows of different length cannot form matrix");
                                                               return 1;
                                                            }
                                                            int temp = yyvsp[-4].rows + 1;
                                                            yyval.rows = temp;
                                                            yyval.cols = yyvsp[-4].cols;
                                                         }
#line 1945 "./exec/y.tab.c"
    break;

  case 31: /* tuple_list: '[' id_list ']'  */
#line 174 "./Parser/parser_main.y"
                                                         {yyval.rows = 1;yyval.cols = yyvsp[-1].cols;}
#line 1951 "./exec/y.tab.c"
    break;

  case 34: /* id_list: id_list ',' temp  */
#line 179 "./Parser/parser_main.y"
                                             {yyval.cols += 1;}
#line 1957 "./exec/y.tab.c"
    break;

  case 35: /* id_list: temp  */
#line 180 "./Parser/parser_main.y"
                                             {yyval.cols = 1;}
#line 1963 "./exec/y.tab.c"
    break;

  case 36: /* $@5: %empty  */
#line 183 "./Parser/parser_main.y"
                           {fprintf(fp,"Block definition section begins\n");}
#line 1969 "./exec/y.tab.c"
    break;

  case 37: /* block_defn_section: $@5 block_defns_list  */
#line 183 "./Parser/parser_main.y"
                                                                                               {fprintf(fp,"Block definition section ends\n");}
#line 1975 "./exec/y.tab.c"
    break;

  case 40: /* $@6: %empty  */
#line 190 "./Parser/parser_main.y"
                                                               {  if(!insertInBlockTable(&BlockSymbolTable,yyvsp[-2].str,yyvsp[-1].num,head)){
                                                                     yyerror("semantic error: incorrect block definition");
                                                                     return 1;
                                                                  }
                                                                  head = NULL;
                                                                  isInBlock = 1;
                                                               }
#line 1987 "./exec/y.tab.c"
    break;

  case 41: /* block_defn: BLOCK block_id params target_params $@6 '[' block_body ']'  */
#line 197 "./Parser/parser_main.y"
                                                               {  fprintf(fp,"Block definition\n");
                                                                  if(!BlockSemanticCheck(yyvsp[-6].str)){
                                                                     yyerror("semantic error: incorrect block definition");
                                                                     return 1;
                                                                  }
                                                                  id_list = NULL;
                                                                  isInBlock = 0;
                                                               }
#line 2000 "./exec/y.tab.c"
    break;

  case 42: /* params: ID  */
#line 207 "./Parser/parser_main.y"
                                                {insertInList(&head,yyvsp[0].str);yyval.num = 1;}
#line 2006 "./exec/y.tab.c"
    break;

  case 43: /* params: '(' param_id_list ')'  */
#line 208 "./Parser/parser_main.y"
                                                {yyval.num = yyvsp[-1].num;}
#line 2012 "./exec/y.tab.c"
    break;

  case 44: /* param_id_list: ID ',' param_id_list  */
#line 211 "./Parser/parser_main.y"
                                                {insertInList(&head,yyvsp[-2].str);yyval.num = 1 + yyvsp[0].num;}
#line 2018 "./exec/y.tab.c"
    break;

  case 45: /* param_id_list: ID  */
#line 212 "./Parser/parser_main.y"
                                                {insertInList(&head,yyvsp[0].str);yyval.num = 1;}
#line 2024 "./exec/y.tab.c"
    break;

  case 53: /* block_id: ID  */
#line 228 "./Parser/parser_main.y"
                                 {  if(!firstLetterCapital(yyvsp[0].str)){
                                       yyerror("lexical error: block identifiers start with uppercase letter");
                                       return 1;
                                    } 
                                    assignString(yyval.str,yyvsp[0].str);
                                 }
#line 2035 "./exec/y.tab.c"
    break;

  case 57: /* main_stmt: barrier_stmt  */
#line 246 "./Parser/parser_main.y"
                                          {fprintf(fp,"barrier statement\n");}
#line 2041 "./exec/y.tab.c"
    break;

  case 59: /* stmts: measure_stmt  */
#line 249 "./Parser/parser_main.y"
                                          {fprintf(fp,"Measure statement\n");}
#line 2047 "./exec/y.tab.c"
    break;

  case 60: /* $@7: %empty  */
#line 250 "./Parser/parser_main.y"
                          {fprintf(fp,"Conditional statement begin\n");}
#line 2053 "./exec/y.tab.c"
    break;

  case 61: /* stmts: $@7 condition_stmt  */
#line 250 "./Parser/parser_main.y"
                                                                                        {fprintf(fp,"Conditional statement end\n");}
#line 2059 "./exec/y.tab.c"
    break;

  case 62: /* stmts: for_stmt  */
#line 251 "./Parser/parser_main.y"
                                          {fprintf(fp,"For statement\n");}
#line 2065 "./exec/y.tab.c"
    break;

  case 63: /* stmts: for_lex_stmt  */
#line 252 "./Parser/parser_main.y"
                                          {fprintf(fp,"For - Lex statement\n");}
#line 2071 "./exec/y.tab.c"
    break;

  case 64: /* stmts: for_zip_stmt  */
#line 253 "./Parser/parser_main.y"
                                          {fprintf(fp,"For - Zip statement\n");}
#line 2077 "./exec/y.tab.c"
    break;

  case 65: /* stmts: while_stmt  */
#line 254 "./Parser/parser_main.y"
                                          {fprintf(fp,"while statement\n");}
#line 2083 "./exec/y.tab.c"
    break;

  case 66: /* register: NUMBER  */
#line 257 "./Parser/parser_main.y"
                                  { if(yyvsp[0].num < 0){
                                       yyerror("semantic error: register numbers are non-negative");
                                       return 1;
                                    } 
                                    yyval.num = yyvsp[0].num;
                                    yyval.flag=0;
                                 }
#line 2095 "./exec/y.tab.c"
    break;

  case 67: /* register: ID  */
#line 264 "./Parser/parser_main.y"
                                  {if(isInBlock){insertInList(&id_list,yyvsp[0].str);}yyval.flag = 1;}
#line 2101 "./exec/y.tab.c"
    break;

  case 68: /* call_stmt: classic_control GATE quantum_control ARROW register  */
#line 269 "./Parser/parser_main.y"
                                                                              {fprintf(fp,"Pre - defined Gate call statement\n");}
#line 2107 "./exec/y.tab.c"
    break;

  case 69: /* call_stmt: classic_control ID quantum_control ARROW register  */
#line 270 "./Parser/parser_main.y"
                                                                              {fprintf(fp,"user - defined Gate call statement\n");}
#line 2113 "./exec/y.tab.c"
    break;

  case 70: /* call_stmt: GATE quantum_control ARROW register  */
#line 271 "./Parser/parser_main.y"
                                                                              {fprintf(fp,"Pre - defined Gate call statement\n");}
#line 2119 "./exec/y.tab.c"
    break;

  case 71: /* call_stmt: ID quantum_control ARROW register  */
#line 272 "./Parser/parser_main.y"
                                                                              {fprintf(fp,"User - defined Gate call statement\n");}
#line 2125 "./exec/y.tab.c"
    break;

  case 72: /* call_stmt: classic_control block_id parameters optional  */
#line 273 "./Parser/parser_main.y"
                                                                              {  fprintf(fp,"Block call statement\n");
                                                                                 if(!isInBlock){
                                                                                    if(!BlockCallSemanticCheck(yyvsp[-2].str,yyvsp[-1].num)){
                                                                                       yyerror("semantic error: block not defined");
                                                                                       return 1;
                                                                                    }
                                                                                 }
                                                                              }
#line 2138 "./exec/y.tab.c"
    break;

  case 73: /* call_stmt: block_id parameters optional  */
#line 281 "./Parser/parser_main.y"
                                                                              {  fprintf(fp,"Block call statement\n");
                                                                                 if(!isInBlock){
                                                                                    if(!BlockCallSemanticCheck(yyvsp[-2].str,yyvsp[-1].num)){
                                                                                       yyerror("semantic error: block not defined");
                                                                                       return 1;
                                                                                    }
                                                                                 }
                                                                              }
#line 2151 "./exec/y.tab.c"
    break;

  case 74: /* parameters: register  */
#line 291 "./Parser/parser_main.y"
                                                   {yyval.num = 1;}
#line 2157 "./exec/y.tab.c"
    break;

  case 75: /* parameters: '(' register_list ')'  */
#line 292 "./Parser/parser_main.y"
                                                   {yyval.num = yyvsp[-1].num;}
#line 2163 "./exec/y.tab.c"
    break;

  case 78: /* register_list: register_list ',' register  */
#line 299 "./Parser/parser_main.y"
                                                      {yyval.num = 1 + yyvsp[-2].num;}
#line 2169 "./exec/y.tab.c"
    break;

  case 79: /* register_list: register  */
#line 300 "./Parser/parser_main.y"
                                                      {yyval.num = 1;}
#line 2175 "./exec/y.tab.c"
    break;

  case 87: /* measure_stmt: MEASURE ':' register ARROW register  */
#line 327 "./Parser/parser_main.y"
                                                              {
                           if((!yyvsp[-2].flag && (yyvsp[-2].num < 0 || yyvsp[-2].num >= quantum_registers)) || (!yyvsp[0].flag && (yyvsp[0].num < 0 || yyvsp[0].num >= classical_registers))){
                              yyerror("semantic error: register number out of bounds"); 
                              return 1;
                           }
                        }
#line 2186 "./exec/y.tab.c"
    break;

  case 112: /* value: NUMBER  */
#line 372 "./Parser/parser_main.y"
                                             {yyval.str = IntToString(yyvsp[0].num);}
#line 2192 "./exec/y.tab.c"
    break;

  case 113: /* value: ID  */
#line 373 "./Parser/parser_main.y"
                                             {yyval.str = yyvsp[0].str;}
#line 2198 "./exec/y.tab.c"
    break;

  case 114: /* range: value ':' value  */
#line 376 "./Parser/parser_main.y"
                                             {yyval.start = IntToString(yyvsp[-2].num); yyval.end = IntToString(yyvsp[0].num); yyval.step = IntToString(1);}
#line 2204 "./exec/y.tab.c"
    break;

  case 115: /* range: value ':' value ':' value  */
#line 377 "./Parser/parser_main.y"
                                                      {yyval.start = IntToString(yyvsp[-4].num); yyval.end = IntToString(yyvsp[-2].num); yyval.step = IntToString(yyvsp[0].num);}
#line 2210 "./exec/y.tab.c"
    break;

  case 116: /* range_list: range ',' range_list  */
#line 380 "./Parser/parser_main.y"
                                                   {  yyval.num = 1 + yyvsp[0].num;
                                                      struct List2* newNode = (struct List2*)malloc(sizeof(struct List2));
                                                      newNode->start = yyvsp[-2].start;
                                                      newNode->end = yyvsp[-2].end;
                                                      newNode->step = yyvsp[-2].step;
                                                      newNode->next = range_list;
                                                      range_list = newNode;
                                                   }
#line 2223 "./exec/y.tab.c"
    break;

  case 117: /* range_list: range  */
#line 388 "./Parser/parser_main.y"
                                                   {  yyval.num = 1;
                                                      struct List2* newNode = (struct List2*)malloc(sizeof(struct List2));
                                                      newNode->start = yyvsp[0].start;
                                                      newNode->end = yyvsp[0].end;
                                                      newNode->step = yyvsp[0].step;
                                                      newNode->next = NULL;
                                                      range_list = newNode;
                                                   }
#line 2236 "./exec/y.tab.c"
    break;

  case 118: /* var_list: ID ',' var_list  */
#line 398 "./Parser/parser_main.y"
                                            {  if(isInOutput){
                                                   if(getOutputSymbolEntry(&OutputSymbolTable,yyvsp[-2].str,outputLevel + 1,1) == NULL){
                                                      yyerror("semantic error: variable used without declaration");
                                                      return 1;
                                                   }
                                                }     
                                                if(!inList(&head,yyvsp[-2].str)){
                                                   printf("hi2\n");
                                                   insertInList(&head,yyvsp[-2].str);
                                                } 
                                                else {
                                                   yyerror("semantic error: loop variable redeclaration");
                                                   return 1;
                                                } 
                                                yyval.num = 1 + yyvsp[0].num;
                                             }
#line 2257 "./exec/y.tab.c"
    break;

  case 119: /* var_list: ID  */
#line 414 "./Parser/parser_main.y"
                                             {  if(isInOutput){
                                                   if(getOutputSymbolEntry(&OutputSymbolTable,yyvsp[0].str,outputLevel + 1,1) == NULL){
                                                      yyerror("semantic error: variable redeclaration");
                                                      return 1;
                                                   }
                                                } 
                                                if(!inList(&head,yyvsp[0].str)){
                                                   printf("hi\n");
                                                   insertInList(&head,yyvsp[0].str);
                                                } 
                                                else{
                                                   yyerror("semantic error: loop variable redeclaration");
                                                   return 1;
                                                } 
                                                yyval.num = 1;
                                             }
#line 2278 "./exec/y.tab.c"
    break;

  case 120: /* $@8: %empty  */
#line 432 "./Parser/parser_main.y"
                                 {  if(!inList(&head,yyvsp[0].str)){
                                       insertInList(&head,yyvsp[0].str);
                                    } 
                                    else{
                                       yyerror("semantic error: loop variable redeclaration"); 
                                       return 1;
                                    }
                                 }
#line 2291 "./exec/y.tab.c"
    break;

  case 121: /* for_stmt: FOR ID $@8 IN '(' range ')' '{' main_stmt_list '}'  */
#line 440 "./Parser/parser_main.y"
                                                                  {removeTopKFromList(&head,1);}
#line 2297 "./exec/y.tab.c"
    break;

  case 122: /* $@9: %empty  */
#line 443 "./Parser/parser_main.y"
                                                                         { if(yyvsp[-5].num != yyvsp[-1].num){
                                                                              yyerror("semantic error: mismatch in loop variables and ranges"); 
                                                                              return 1;
                                                                           }
                                                                         }
#line 2307 "./exec/y.tab.c"
    break;

  case 123: /* for_lex_stmt: FOR_LEX '(' var_list ')' IN '(' range_list ')' $@9 '{' main_stmt_list '}'  */
#line 448 "./Parser/parser_main.y"
                                                 {removeTopKFromList(&head,yyvsp[-9].num);}
#line 2313 "./exec/y.tab.c"
    break;

  case 124: /* $@10: %empty  */
#line 451 "./Parser/parser_main.y"
                                                                         { if(yyvsp[-5].num != yyvsp[-1].num){
                                                                              yyerror("semantic error: mismatch in loop variables and ranges"); 
                                                                              return 1;
                                                                           }
                                                                         }
#line 2323 "./exec/y.tab.c"
    break;

  case 125: /* for_zip_stmt: FOR_ZIP '(' var_list ')' IN '(' range_list ')' $@10 '{' main_stmt_list '}'  */
#line 456 "./Parser/parser_main.y"
                                                 {removeTopKFromList(&head,yyvsp[-9].num);}
#line 2329 "./exec/y.tab.c"
    break;

  case 127: /* out_id: ID  */
#line 468 "./Parser/parser_main.y"
                               {yyval.out_flag = 0; yyval.str = yyvsp[0].str;}
#line 2335 "./exec/y.tab.c"
    break;

  case 128: /* out_id: COUT  */
#line 469 "./Parser/parser_main.y"
                               {yyval.out_flag = 1; yyval.type = Int; yyval.prim = false; yyval.dim = (1 << classical_registers); yyval.rows = 0;yyval.str = yyvsp[0].str;}
#line 2341 "./exec/y.tab.c"
    break;

  case 129: /* out_id: QOUT  */
#line 470 "./Parser/parser_main.y"
                               {yyval.out_flag = 2; yyval.type = State; yyval.prim = false; yyval.dim = quantum_registers; yyval.rows = 0;yyval.str = yyvsp[0].str;}
#line 2347 "./exec/y.tab.c"
    break;

  case 130: /* prim_type: INT  */
#line 473 "./Parser/parser_main.y"
                                    {yyval.type = Int; yyval.prim = true;fprintf(out,"int ");}
#line 2353 "./exec/y.tab.c"
    break;

  case 131: /* prim_type: UINT  */
#line 474 "./Parser/parser_main.y"
                                    {yyval.type = Uint; yyval.prim = true;fprintf(out,"unsigned int ");}
#line 2359 "./exec/y.tab.c"
    break;

  case 132: /* prim_type: FLOAT  */
#line 475 "./Parser/parser_main.y"
                                    {yyval.type = Float; yyval.prim = true;fprintf(out,"float ");}
#line 2365 "./exec/y.tab.c"
    break;

  case 133: /* prim_type: COMPLEX  */
#line 476 "./Parser/parser_main.y"
                                    {yyval.type = Complex; yyval.prim = true;fprintf(out,"Complex ");}
#line 2371 "./exec/y.tab.c"
    break;

  case 134: /* prim_type: STRING  */
#line 477 "./Parser/parser_main.y"
                                    {yyval.type = String; yyval.prim = true;fprintf(out,"string ");}
#line 2377 "./exec/y.tab.c"
    break;

  case 135: /* prim_type: MATRIX  */
#line 478 "./Parser/parser_main.y"
                                    {yyval.type = Matrix; yyval.prim = true;fprintf(out,"Matrix ");}
#line 2383 "./exec/y.tab.c"
    break;

  case 136: /* prim_type: STATE  */
#line 479 "./Parser/parser_main.y"
                                    {yyval.type = State; yyval.prim = true;fprintf(out,"StateVec ");}
#line 2389 "./exec/y.tab.c"
    break;

  case 137: /* prim_type: BOOL  */
#line 480 "./Parser/parser_main.y"
                                    {yyval.type = Bool; yyval.prim = true;fprintf(out,"bool ");}
#line 2395 "./exec/y.tab.c"
    break;

  case 138: /* list_type: LIST '[' prim_type ']'  */
#line 483 "./Parser/parser_main.y"
                                                 {yyval.type = yyvsp[-1].type; yyval.prim = false;}
#line 2401 "./exec/y.tab.c"
    break;

  case 139: /* bool_const: TRUE  */
#line 490 "./Parser/parser_main.y"
                                    {yyval.num = 1;}
#line 2407 "./exec/y.tab.c"
    break;

  case 140: /* bool_const: FALSE  */
#line 491 "./Parser/parser_main.y"
                                    {yyval.num = 0;}
#line 2413 "./exec/y.tab.c"
    break;

  case 141: /* num: DEC  */
#line 494 "./Parser/parser_main.y"
                                    {yyval.real = yyvsp[0].real;}
#line 2419 "./exec/y.tab.c"
    break;

  case 142: /* num: NEG  */
#line 495 "./Parser/parser_main.y"
                                    {yyval.real = yyvsp[0].real;}
#line 2425 "./exec/y.tab.c"
    break;

  case 143: /* num: EXP  */
#line 496 "./Parser/parser_main.y"
                                    {yyval.real = yyvsp[0].real;}
#line 2431 "./exec/y.tab.c"
    break;

  case 144: /* num: NUMBER  */
#line 497 "./Parser/parser_main.y"
                                    {yyval.real = yyvsp[0].num;}
#line 2437 "./exec/y.tab.c"
    break;

  case 145: /* complex_const: '(' num ',' num ')'  */
#line 499 "./Parser/parser_main.y"
                                                   {yyval.cpx.real = yyvsp[-3].real; yyval.cpx.imag = yyvsp[-1].real;}
#line 2443 "./exec/y.tab.c"
    break;

  case 146: /* matrix_const: '[' row_list ']'  */
#line 502 "./Parser/parser_main.y"
                                                   { if(yyvsp[-1].rows == yyvsp[-1].cols) {
                                                         yyval.rows = yyvsp[-1].rows;
                                                     } 
                                                     else{
                                                         yyerror("semantic error: only square matrices permitted"); 
                                                         return 1;
                                                     }
                                                   }
#line 2456 "./exec/y.tab.c"
    break;

  case 147: /* row_list: row_list ',' row  */
#line 512 "./Parser/parser_main.y"
                                                   {  yyval.rows = yyvsp[-2].rows + 1; 
                                                      if(yyvsp[-2].cols == yyvsp[0].cols){
                                                         yyval.cols = yyvsp[-2].cols;
                                                      } 
                                                      else{
                                                         yyerror("semantic error: rows of different length cannot form matrix"); 
                                                         return 1;
                                                      }
                                                   }
#line 2470 "./exec/y.tab.c"
    break;

  case 148: /* row_list: row  */
#line 521 "./Parser/parser_main.y"
                                                      {yyval.rows = 1; yyval.cols = yyvsp[0].cols;}
#line 2476 "./exec/y.tab.c"
    break;

  case 149: /* row: '[' comps ']'  */
#line 524 "./Parser/parser_main.y"
                                                      {yyval.cols = yyvsp[-1].cols;}
#line 2482 "./exec/y.tab.c"
    break;

  case 150: /* comps: comps ',' compatible_const  */
#line 527 "./Parser/parser_main.y"
                                                      {yyval.cols = yyvsp[-2].cols + 1;}
#line 2488 "./exec/y.tab.c"
    break;

  case 151: /* comps: compatible_const  */
#line 528 "./Parser/parser_main.y"
                                                      {yyval.cols = 1;}
#line 2494 "./exec/y.tab.c"
    break;

  case 154: /* state_const: '{' temp ',' temp '}'  */
#line 535 "./Parser/parser_main.y"
                                                      {yyval.q.first = yyvsp[-3].cpx; yyval.q.second = yyvsp[-1].cpx;}
#line 2500 "./exec/y.tab.c"
    break;

  case 155: /* temp: complex_const  */
#line 538 "./Parser/parser_main.y"
                                                      {yyval.cpx = yyvsp[0].cpx;}
#line 2506 "./exec/y.tab.c"
    break;

  case 156: /* temp: num  */
#line 539 "./Parser/parser_main.y"
                                                      {yyval.cpx.real = yyvsp[0].real; yyval.cpx.imag = 0;}
#line 2512 "./exec/y.tab.c"
    break;

  case 157: /* prim_const: bool_const  */
#line 542 "./Parser/parser_main.y"
                                         {yyval.type = Bool;yyval.str = (char *)malloc(sizeof(char)*6);if(yyval.num)snprintf(yyval.str,6,"true");else snprintf(yyval.str,6,"false");}
#line 2518 "./exec/y.tab.c"
    break;

  case 158: /* prim_const: complex_const  */
#line 543 "./Parser/parser_main.y"
                                         {yyval.type = Complex;yyval.str = (char *)malloc(sizeof(char)*20);snprintf(yyval.str,20,"Complex(%f,%f)",yyvsp[0].cpx.real,yyvsp[0].cpx.imag);}
#line 2524 "./exec/y.tab.c"
    break;

  case 159: /* prim_const: matrix_const  */
#line 544 "./Parser/parser_main.y"
                                         {yyval.type = Matrix; yyval.rows = yyvsp[0].rows;yyval.str = (char *)malloc(sizeof(char)*20);snprintf(yyval.str,15,"Matrix(%d)",yyvsp[0].rows);}
#line 2530 "./exec/y.tab.c"
    break;

  case 160: /* prim_const: state_const  */
#line 545 "./Parser/parser_main.y"
                                         {yyval.type = State;}
#line 2536 "./exec/y.tab.c"
    break;

  case 161: /* prim_const: NUMBER  */
#line 546 "./Parser/parser_main.y"
                                         {yyval.type = Uint;yyval.str = (char *)malloc(sizeof(char)*20);snprintf(yyval.str,20,"%d",yyvsp[0].num);}
#line 2542 "./exec/y.tab.c"
    break;

  case 162: /* prim_const: NEG  */
#line 547 "./Parser/parser_main.y"
                                         {yyval.type = Int;yyval.str = (char *)malloc(sizeof(char)*20);snprintf(yyval.str,20,"%d",yyvsp[0].num);}
#line 2548 "./exec/y.tab.c"
    break;

  case 163: /* prim_const: DEC  */
#line 548 "./Parser/parser_main.y"
                                         {yyval.type = Float;yyval.str = (char *)malloc(sizeof(char)*20);snprintf(yyval.str,20,"%f",yyvsp[0].real);}
#line 2554 "./exec/y.tab.c"
    break;

  case 164: /* prim_const: EXP  */
#line 549 "./Parser/parser_main.y"
                                         {yyval.type = Float;yyval.str = (char *)malloc(sizeof(char)*20);snprintf(yyval.str,20,"%f",yyvsp[0].real);}
#line 2560 "./exec/y.tab.c"
    break;

  case 165: /* prim_const: STRING  */
#line 550 "./Parser/parser_main.y"
                                         {yyval.type = String;yyval.str = (char *)malloc(sizeof(char)*25);snprintf(yyval.str,20,"%s",yyvsp[0].str);}
#line 2566 "./exec/y.tab.c"
    break;

  case 166: /* vec_const: '[' vec_list ']'  */
#line 553 "./Parser/parser_main.y"
                                                {  yyval.dim = yyvsp[-1].dim; 
                                                   yyval.type = yyvsp[-1].type; 
                                                   if(yyval.type == Matrix){
                                                      yyval.rows = yyvsp[-1].rows;
                                                   } 
                                                   else{
                                                      yyval.rows = 0;
                                                   } 
                                                }
#line 2580 "./exec/y.tab.c"
    break;

  case 167: /* vec_list: vec_list ',' prim_const  */
#line 564 "./Parser/parser_main.y"
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
                                                   }
#line 2604 "./exec/y.tab.c"
    break;

  case 168: /* vec_list: prim_const  */
#line 583 "./Parser/parser_main.y"
                                                   {  yyval.type = yyvsp[0].type; yyval.dim = 1; 
                                                      if(yyval.type == Matrix){
                                                         yyval.rows = yyvsp[0].rows;
                                                      }
                                                   }
#line 2614 "./exec/y.tab.c"
    break;

  case 169: /* calls: ADD '(' out_rhs ',' out_rhs ')'  */
#line 592 "./Parser/parser_main.y"
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
                     }
#line 2631 "./exec/y.tab.c"
    break;

  case 170: /* calls: SUB '(' out_rhs ',' out_rhs ')'  */
#line 605 "./Parser/parser_main.y"
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
                     }
#line 2648 "./exec/y.tab.c"
    break;

  case 171: /* calls: DOT '(' out_rhs ',' out_rhs ')'  */
#line 618 "./Parser/parser_main.y"
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
                     }
#line 2674 "./exec/y.tab.c"
    break;

  case 172: /* calls: STD_DEV '(' out_rhs ')'  */
#line 640 "./Parser/parser_main.y"
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
                     }
#line 2690 "./exec/y.tab.c"
    break;

  case 173: /* calls: VAR '(' out_rhs ')'  */
#line 652 "./Parser/parser_main.y"
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
                     }
#line 2706 "./exec/y.tab.c"
    break;

  case 174: /* calls: CONDENSE '(' out_rhs ',' NUMBER ')'  */
#line 664 "./Parser/parser_main.y"
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
                     }
#line 2722 "./exec/y.tab.c"
    break;

  case 175: /* calls: CONDENSE '(' out_rhs ',' '(' uint_list ')' ')'  */
#line 676 "./Parser/parser_main.y"
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
                     }
#line 2738 "./exec/y.tab.c"
    break;

  case 176: /* calls: SUM '(' out_rhs ')'  */
#line 688 "./Parser/parser_main.y"
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
                     }
#line 2754 "./exec/y.tab.c"
    break;

  case 177: /* calls: AVG '(' out_rhs ')'  */
#line 700 "./Parser/parser_main.y"
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
                     }
#line 2770 "./exec/y.tab.c"
    break;

  case 178: /* uint_list: uint_list ',' out_rhs  */
#line 716 "./Parser/parser_main.y"
                                                 { if(yyvsp[-2].type <= Int){
                                                      yyval.cond_count = yyvsp[-2].cond_count + 1;
                                                   } 
                                                   else{
                                                      yyerror("semantic error: only integer elements permitted"); 
                                                      return 1;
                                                   }
                                                 }
#line 2783 "./exec/y.tab.c"
    break;

  case 179: /* uint_list: out_rhs  */
#line 724 "./Parser/parser_main.y"
                                                 { if(yyvsp[0].type <= Int){
                                                      yyval.cond_count = 1;
                                                   } 
                                                   else{
                                                      yyerror("semantic error: only integer elements permitted"); 
                                                      return 1;
                                                   }
                                                 }
#line 2796 "./exec/y.tab.c"
    break;

  case 180: /* out_rhs: prim_const  */
#line 735 "./Parser/parser_main.y"
                                                { yyval.prim = true; yyval.type = yyvsp[0].type;yyval.str = yyvsp[0].str;}
#line 2802 "./exec/y.tab.c"
    break;

  case 181: /* out_rhs: vec_const  */
#line 736 "./Parser/parser_main.y"
                                                { yyval.prim = false; yyval.dim = yyvsp[0].dim; 
                                                  yyval.type = yyvsp[0].type; 
                                                  if(yyval.type == Matrix){
                                                      yyval.rows = yyvsp[0].rows;
                                                  } 
                                                  else yyval.rows = 0;
                                                }
#line 2814 "./exec/y.tab.c"
    break;

  case 182: /* out_rhs: out_id  */
#line 743 "./Parser/parser_main.y"
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
                                                   fprintf(out,"%s",yyvsp[0].str);
                                                }
#line 2849 "./exec/y.tab.c"
    break;

  case 183: /* out_rhs: out_id '[' out_rhs ']'  */
#line 773 "./Parser/parser_main.y"
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
                                                            yyerror("semantic error"); 
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
                                                }
#line 2893 "./exec/y.tab.c"
    break;

  case 184: /* out_rhs: out_id '[' out_rhs ']' '[' out_rhs ']'  */
#line 813 "./Parser/parser_main.y"
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
                                                               yyerror("semantic error"); 
                                                               return 1;
                                                            }
                                                         }
                                                      } 
                                                      else{
                                                         yyerror("semantic error"); 
                                                         return 1;
                                                      }
                                                   } 
                                                   else if(yyval.out_flag == 1){
                                                      yyerror("semantic error");
                                                      return 1;
                                                   } 
                                                   else{
                                                      yyval.type = Complex; 
                                                      yyval.prim = true;
                                                   }
                                                }
#line 2937 "./exec/y.tab.c"
    break;

  case 185: /* out_rhs: out_id '[' out_rhs ']' '[' out_rhs ']' '[' out_rhs ']'  */
#line 853 "./Parser/parser_main.y"
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
                                                               yyerror("semantic error"); 
                                                               return 1;
                                                            }
                                                         }
                                                      } 
                                                      else{
                                                         yyerror("semantic error");
                                                         return 1;
                                                      }
                                                   } 
                                                   else{
                                                      yyerror("semantic error"); 
                                                      return 1;
                                                   }
                                                }
#line 2971 "./exec/y.tab.c"
    break;

  case 186: /* out_rhs: calls  */
#line 882 "./Parser/parser_main.y"
                                                {  yyval.prim = yyvsp[0].prim; 
                                                   yyval.type = yyvsp[0].type; 
                                                   if(yyvsp[0].type == Matrix) yyval.rows = yyvsp[0].rows; 
                                                   if(!yyval.prim) yyval.dim = yyvsp[0].dim; 
                                                   printf("%d %d\n", yyval.prim, yyval.type);
                                                }
#line 2982 "./exec/y.tab.c"
    break;

  case 187: /* out_rhs: '(' out_rhs ')'  */
#line 888 "./Parser/parser_main.y"
                                                  {fprintf(out,")");yyval.type = yyvsp[-1].type;}
#line 2988 "./exec/y.tab.c"
    break;

  case 188: /* out_rhs: '!' out_rhs  */
#line 889 "./Parser/parser_main.y"
                                                  {  if(yyvsp[0].type==Bool && yyvsp[0].prim){
                                                         yyval.prim = true; 
                                                         yyval.type = Bool;
                                                      } 
                                                      else{
                                                         yyerror("semantic error"); 
                                                         return 1;
                                                      }  
                                                   }
#line 3002 "./exec/y.tab.c"
    break;

  case 189: /* out_rhs: out_rhs AND out_rhs  */
#line 898 "./Parser/parser_main.y"
                                                {  if(yyvsp[-2].type==Bool && yyvsp[-2].prim && yyvsp[0].type==Bool && yyvsp[0].prim){
                                                      yyval.prim = true; 
                                                      yyval.type = Bool;
                                                   } 
                                                   else{
                                                      yyerror("semantic error"); 
                                                      return 1;
                                                   } 
                                                }
#line 3016 "./exec/y.tab.c"
    break;

  case 190: /* out_rhs: out_rhs OR out_rhs  */
#line 907 "./Parser/parser_main.y"
                                                {  if(yyvsp[-2].type==Bool && yyvsp[-2].prim && yyvsp[0].type==Bool && yyvsp[0].prim){
                                                      yyval.prim = true; 
                                                      yyval.type = Bool;
                                                   } 
                                                   else{
                                                      yyerror("semantic error"); 
                                                      return 1;
                                                   } 
                                                }
#line 3030 "./exec/y.tab.c"
    break;

  case 191: /* out_rhs: out_rhs COMP out_rhs  */
#line 916 "./Parser/parser_main.y"
                                                 {  temp_type = compatibleCheckAdv(yyvsp[-2].type, yyvsp[0].type, yyvsp[-2].prim, yyvsp[0].prim, yyvsp[-2].dim, yyvsp[0].dim); 
                                                   if(temp_type != -1 && temp_type < COMPARABLE){
                                                      yyval.prim = true; 
                                                      yyval.type = Bool;
                                                   } 
                                                   else{
                                                      yyerror("semantic error"); 
                                                      return 1;
                                                   }
                                                }
#line 3045 "./exec/y.tab.c"
    break;

  case 192: /* out_rhs: out_rhs EQUALITY out_rhs  */
#line 926 "./Parser/parser_main.y"
                                                   { temp_type = compatibleCheckAdv(yyvsp[-2].type, yyvsp[0].type, yyvsp[-2].prim, yyvsp[0].prim, yyvsp[-2].dim, yyvsp[0].dim); 
                                                      if(temp_type != -1 && temp_type < COMPARABLE){
                                                         yyval.prim = true; 
                                                         yyval.type = Bool;
                                                      } 
                                                      else{
                                                         yyerror("semantic error"); 
                                                         return 1;
                                                      }  
                                                   }
#line 3060 "./exec/y.tab.c"
    break;

  case 193: /* out_rhs: out_rhs '*' out_rhs  */
#line 936 "./Parser/parser_main.y"
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
                                                         yyerror("semantic error"); 
                                                         return 1;
                                                      }
                                                   }
#line 3083 "./exec/y.tab.c"
    break;

  case 194: /* out_rhs: out_rhs '/' out_rhs  */
#line 954 "./Parser/parser_main.y"
                                                   {  temp_type = compatibleCheckAdv(yyvsp[-2].type, yyvsp[0].type, yyvsp[-2].prim, yyvsp[0].prim, yyvsp[-2].dim, yyvsp[0].dim); 
                                                      if(yyvsp[-2].prim && (temp_type <= Complex && temp_type >= 0)){
                                                         yyval.prim = true; 
                                                         yyval.type = temp_type;
                                                      } 
                                                      else{
                                                         yyerror("semantic error"); 
                                                         return 1;
                                                      }
                                                   }
#line 3098 "./exec/y.tab.c"
    break;

  case 195: /* out_rhs: out_rhs '+' out_rhs  */
#line 965 "./Parser/parser_main.y"
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
                                                         yyerror("semantic error");
                                                         return 1;
                                                      }
                                                   }
#line 3121 "./exec/y.tab.c"
    break;

  case 196: /* out_rhs: out_rhs '-' out_rhs  */
#line 983 "./Parser/parser_main.y"
                                                                                                                                                                             {  temp_type = compatibleCheckAdv(yyvsp[-2].type, yyvsp[0].type, yyvsp[-2].prim, yyvsp[0].prim, yyvsp[-2].dim, yyvsp[0].dim); 
                                                      if(temp_type == Matrix || temp_type == State || (temp_type <= Complex && temp_type >= 0)){
                                                         yyval.prim = yyvsp[-2].prim; 
                                                         yyval.type = temp_type; 
                                                         if(temp_type == Matrix) yyval.rows=yyvsp[-2].rows; 
                                                         yyval.dim=yyvsp[-2].dim;
                                                      } 
                                                      else{
                                                         yyerror("semantic error");
                                                         return 1;
                                                      } 
                                                   }
#line 3138 "./exec/y.tab.c"
    break;

  case 197: /* out_rhs: out_rhs '@' out_rhs  */
#line 995 "./Parser/parser_main.y"
                                                                                                                                                                      {  temp_type = compatibleCheckAdv(yyvsp[-2].type, yyvsp[0].type, yyvsp[-2].prim, yyvsp[0].prim, yyvsp[-2].dim, yyvsp[0].dim); 
                                                      if(yyvsp[-2].prim && temp_type == Matrix){
                                                         if(yyvsp[-2].rows == yyvsp[0].rows){
                                                            yyval.prim = true; 
                                                            yyval.type = temp_type; 
                                                            yyval.rows = yyvsp[-2].rows;
                                                         } 
                                                         else{
                                                            yyerror("semantic error"); 
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
                                                         yyerror("semantic error"); 
                                                         return 1;
                                                      }
                                                   }
#line 3174 "./exec/y.tab.c"
    break;

  case 198: /* out_rhs: out_rhs '&' out_rhs  */
#line 1027 "./Parser/parser_main.y"
                                                   {  temp_type = compatibleCheckAdv(yyvsp[-2].type, yyvsp[0].type, yyvsp[-2].prim, yyvsp[0].prim, yyvsp[-2].dim, yyvsp[0].dim); 
                                                      if(temp_type <= Int){
                                                         yyval.prim = yyvsp[-2].prim; 
                                                         yyval.type = temp_type;
                                                      } 
                                                      else{
                                                         yyerror("semantic error: incompatible operands"); 
                                                         return 1;
                                                      }
                                                   }
#line 3189 "./exec/y.tab.c"
    break;

  case 199: /* out_rhs: out_rhs '^' out_rhs  */
#line 1038 "./Parser/parser_main.y"
                                                   {  temp_type = compatibleCheckAdv(yyvsp[-2].type, yyvsp[0].type, yyvsp[-2].prim, yyvsp[0].prim, yyvsp[-2].dim, yyvsp[0].dim); 
                                                      if(temp_type <= Int){
                                                         yyval.prim = yyvsp[-2].prim; 
                                                         yyval.type = temp_type;
                                                      } 
                                                      else{
                                                         yyerror("semantic error: incompatible operands"); 
                                                         return 1;
                                                      }
                                                   }
#line 3204 "./exec/y.tab.c"
    break;

  case 200: /* out_rhs: out_rhs '|' out_rhs  */
#line 1049 "./Parser/parser_main.y"
                                                   { temp_type = compatibleCheckAdv(yyvsp[-2].type, yyvsp[0].type, yyvsp[-2].prim, yyvsp[0].prim, yyvsp[-2].dim, yyvsp[0].dim); 
                                                      if(temp_type <= Int){
                                                         yyval.prim = yyvsp[-2].prim; 
                                                         yyval.type = temp_type;
                                                      } 
                                                      else{
                                                         yyerror("semantic error: incompatible operands"); 
                                                         return 1;
                                                      }
                                                   }
#line 3219 "./exec/y.tab.c"
    break;

  case 201: /* out_expr: ID '=' out_rhs  */
#line 1062 "./Parser/parser_main.y"
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
                                                            yyerror("semantic error"); 
                                                            return 1;
                                                         }
                                                      }
                                                      
                                                      yyval.str2 = (char *)malloc(sizeof(char)*(strlen(yyvsp[-2].str)+strlen(yyvsp[0].str)+5));
                                                      snprintf(yyval.str2,strlen(yyvsp[-2].str)+strlen(yyvsp[0].str)+10,"%s=%s;",yyvsp[-2].str,yyvsp[0].str);
                                                   }
#line 3242 "./exec/y.tab.c"
    break;

  case 202: /* decl: prim_type out_expr  */
#line 1082 "./Parser/parser_main.y"
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
#line 3263 "./exec/y.tab.c"
    break;

  case 203: /* decl: list_type out_expr  */
#line 1099 "./Parser/parser_main.y"
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
                                                   }
#line 3282 "./exec/y.tab.c"
    break;

  case 204: /* echo_stmt: ECHO '(' echo_list ')'  */
#line 1116 "./Parser/parser_main.y"
                                                      {fprintf(fp,"Echo statement\n");}
#line 3288 "./exec/y.tab.c"
    break;

  case 207: /* save_stmt: '\\' SAVE STRING  */
#line 1124 "./Parser/parser_main.y"
                                                      {fprintf(fp,"Save statement\n");}
#line 3294 "./exec/y.tab.c"
    break;

  case 208: /* $@11: %empty  */
#line 1128 "./Parser/parser_main.y"
                          {fprintf(fp,"Output section conditional statement begins\n");}
#line 3300 "./exec/y.tab.c"
    break;

  case 209: /* out_control: $@11 out_cond_stmt  */
#line 1128 "./Parser/parser_main.y"
                                                                                                       {fprintf(fp,"Output section conditional statement ends\n");}
#line 3306 "./exec/y.tab.c"
    break;

  case 210: /* out_control: out_for_stmt  */
#line 1129 "./Parser/parser_main.y"
                                                      {fprintf(fp,"For statement in output section\n");}
#line 3312 "./exec/y.tab.c"
    break;

  case 211: /* out_control: out_for_lex_stmt  */
#line 1130 "./Parser/parser_main.y"
                                                      {fprintf(fp,"For - lex statement in output section\n");}
#line 3318 "./exec/y.tab.c"
    break;

  case 212: /* out_control: out_for_zip_stmt  */
#line 1131 "./Parser/parser_main.y"
                                                      {fprintf(fp,"For - zip statement in output section\n");}
#line 3324 "./exec/y.tab.c"
    break;

  case 213: /* out_control: out_while_stmt  */
#line 1132 "./Parser/parser_main.y"
                                                      {fprintf(fp,"while statement in output section\n");}
#line 3330 "./exec/y.tab.c"
    break;

  case 214: /* $@12: %empty  */
#line 1135 "./Parser/parser_main.y"
                                                        {outputLevel++;}
#line 3336 "./exec/y.tab.c"
    break;

  case 215: /* out_cond_stmt: CONDITION '(' out_rhs ')' '{' $@12 out_main '}' out_other_list out_other_final  */
#line 1135 "./Parser/parser_main.y"
                                                                                                                     {outputLevel--;}
#line 3342 "./exec/y.tab.c"
    break;

  case 220: /* $@13: %empty  */
#line 1146 "./Parser/parser_main.y"
                                 {  if(getOutputSymbolEntry(&OutputSymbolTable,yyvsp[0].str,outputLevel + 1,1) == NULL){
                                       yyerror("semantic error: variable used without declaration"); 
                                       return 1;
                                    }
                                 }
#line 3352 "./exec/y.tab.c"
    break;

  case 221: /* $@14: %empty  */
#line 1151 "./Parser/parser_main.y"
                                               {outputLevel++;fprintf(out,"for(%s = %s;%s < %s;%s += %s){\n",yyvsp[-6].str,yyvsp[-2].start,yyvsp[-6].str,yyvsp[-2].end,yyvsp[-6].str,yyvsp[-2].step);}
#line 3358 "./exec/y.tab.c"
    break;

  case 222: /* out_for_stmt: FOR ID $@13 IN '(' range ')' '{' $@14 out_main '}'  */
#line 1152 "./Parser/parser_main.y"
                                               {fprintf(out,"}\n");exitOutputSymbolScope(&OutputSymbolTable,outputLevel);outputLevel--;}
#line 3364 "./exec/y.tab.c"
    break;

  case 223: /* $@15: %empty  */
#line 1155 "./Parser/parser_main.y"
                                                                          {   if(yyvsp[-5].num != yyvsp[-1].num){
                                                                                 yyerror("semantic error: mismatch in loop variables and ranges"); 
                                                                                 return 1;
                                                                              }
                                                                              printForLex(yyvsp[-5].num);
                                                                          }
#line 3375 "./exec/y.tab.c"
    break;

  case 224: /* $@16: %empty  */
#line 1161 "./Parser/parser_main.y"
                              {outputLevel++;}
#line 3381 "./exec/y.tab.c"
    break;

  case 225: /* out_for_lex_stmt: FOR_LEX '(' var_list ')' IN '(' range_list ')' $@15 '{' $@16 out_main '}'  */
#line 1161 "./Parser/parser_main.y"
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
#line 3396 "./exec/y.tab.c"
    break;

  case 226: /* $@17: %empty  */
#line 1173 "./Parser/parser_main.y"
                                                                          {   if(yyvsp[-5].num != yyvsp[-1].num){
                                                                                 yyerror("semantic error: mismatch in loop variables and ranges"); 
                                                                                 return 1;
                                                                              }
                                                                              printForZip(yyvsp[-5].num);
                                                                          }
#line 3407 "./exec/y.tab.c"
    break;

  case 227: /* $@18: %empty  */
#line 1179 "./Parser/parser_main.y"
                              {outputLevel++;}
#line 3413 "./exec/y.tab.c"
    break;

  case 228: /* out_for_zip_stmt: FOR_ZIP '(' var_list ')' IN '(' range_list ')' $@17 '{' $@18 out_main '}'  */
#line 1180 "./Parser/parser_main.y"
                                                     {exitOutputSymbolScope(&OutputSymbolTable,outputLevel); outputLevel--;}
#line 3419 "./exec/y.tab.c"
    break;

  case 229: /* $@19: %empty  */
#line 1183 "./Parser/parser_main.y"
                                                 {outputLevel++;}
#line 3425 "./exec/y.tab.c"
    break;

  case 230: /* out_while_stmt: WHILE '(' expr ')' '{' $@19 out_main '}'  */
#line 1183 "./Parser/parser_main.y"
                                                                               {exitOutputSymbolScope(&OutputSymbolTable,outputLevel); outputLevel--;}
#line 3431 "./exec/y.tab.c"
    break;

  case 236: /* $@20: %empty  */
#line 1195 "./Parser/parser_main.y"
                          {isDeclaration = false;}
#line 3437 "./exec/y.tab.c"
    break;

  case 238: /* $@21: %empty  */
#line 1196 "./Parser/parser_main.y"
                          {isDeclaration = true;}
#line 3443 "./exec/y.tab.c"
    break;


#line 3447 "./exec/y.tab.c"

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

#line 1198 "./Parser/parser_main.y"


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
   str1 = (char*)malloc(sizeof(char)*strlen(str2));
   for(int i=0;i<strlen(str2);i++){
      str1[i] = str2[i];
   }
}

bool firstLetterCapital(char *str) {
   return (str[0] >= 65 && str[0] <= 90);
}

void insertInList(struct List** Head,char * data){
   struct List* newNode = (struct List*)malloc(sizeof(struct List));
   newNode->id = (char *)malloc(sizeof(char)*strlen(data));
   for(int i=0;i<strlen(data);i++){
      newNode->id[i] = data[i];
   }
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
      printf("%d %d %d %d\n",temp->id, temp->level, temp->primitive, temp->dim);
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
  out = fopen("out.txt","w");
  yyparse();

  return 0;
}

void yyerror(char* err){
   printf("At line %d: %s\n", line, err);
   fprintf(fp,"At line %d: %s\n",line, err);
}
