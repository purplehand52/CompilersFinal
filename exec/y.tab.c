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
   FILE * fp;
// comment
   int yylex();
   void yyerror(char* str);

   int classical_registers,quantum_registers,iterations,temp_type;
   int * classical_states,classical_index=0,quantum_index=0;
   struct Quantum* quantum_states;
   int isInBlock=0;
   int outputLevel = 0;
   bool isInOutput = false;
   bool isDeclaration = false;

   struct List* head = NULL;
   struct List* id_list = NULL;
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

#line 122 "./exec/y.tab.c"

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
#define YYLAST   1063

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
       0,    82,    82,    86,    86,    89,    89,    92,    92,   100,
     104,   105,   106,   107,   108,   111,   114,   117,   123,   128,
     134,   139,   143,   143,   144,   147,   148,   151,   159,   160,
     162,   170,   172,   173,   175,   176,   179,   179,   182,   183,
     186,   186,   203,   204,   207,   208,   211,   212,   213,   216,
     217,   220,   221,   224,   237,   238,   241,   242,   244,   245,
     246,   246,   247,   248,   249,   250,   253,   260,   265,   266,
     267,   268,   269,   277,   287,   288,   291,   292,   295,   296,
     299,   300,   303,   304,   305,   308,   309,   323,   331,   334,
     337,   338,   341,   342,   345,   346,   347,   348,   349,   350,
     351,   354,   355,   356,   357,   358,   359,   360,   361,   362,
     363,   364,   368,   369,   372,   373,   376,   377,   380,   395,
     412,   412,   423,   423,   431,   431,   439,   448,   449,   450,
     453,   454,   455,   456,   457,   458,   459,   460,   463,   470,
     471,   474,   475,   476,   477,   479,   482,   492,   501,   504,
     507,   508,   511,   512,   515,   518,   519,   522,   523,   524,
     525,   526,   527,   528,   529,   530,   533,   544,   563,   571,
     584,   597,   619,   631,   643,   655,   667,   679,   696,   704,
     715,   716,   723,   752,   791,   831,   861,   867,   868,   877,
     886,   895,   905,   915,   933,   943,   962,   974,  1005,  1016,
    1027,  1041,  1058,  1073,  1090,  1093,  1094,  1098,  1102,  1102,
    1103,  1104,  1105,  1106,  1109,  1109,  1112,  1113,  1116,  1117,
    1120,  1125,  1120,  1129,  1134,  1129,  1137,  1142,  1137,  1145,
    1145,  1150,  1151,  1154,  1155,  1156,  1157,  1157,  1158,  1158
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

#define YYPACT_NINF (-387)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-237)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -51,    33,   139,     7,  -387,  -387,   132,    86,    94,  -387,
     161,  -387,   178,    98,  -387,  -387,   190,   203,  -387,   122,
     164,   106,  -387,   168,    17,   174,   267,   243,  -387,   253,
    -387,    -1,  -387,   239,   262,   311,   283,   288,   292,   133,
     176,    29,  -387,  -387,   351,   300,  -387,    26,  -387,  -387,
    -387,  -387,  -387,  -387,   592,   381,   380,   384,   322,   371,
     402,  -387,   267,   400,   406,    34,   392,   403,   176,  -387,
     421,   421,    52,  -387,  -387,  -387,  -387,   -57,   176,  -387,
     408,   352,  -387,  -387,    32,   239,    29,   429,   357,   362,
     366,   373,   120,  -387,  -387,  -387,   432,  -387,  -387,  -387,
    -387,  -387,   453,   711,   395,   444,   461,   454,   483,   371,
    -387,  -387,    10,  -387,   176,  -387,   176,   176,   467,   470,
    -387,   -49,   -26,  -387,  -387,  -387,  -387,    52,   413,   350,
     176,   412,    56,    38,  -387,    52,   472,   478,   408,  -387,
     421,   421,    52,   231,  -387,   450,   426,  -387,   433,  -387,
    -387,  -387,  -387,  -387,  -387,  -387,  -387,  -387,   434,   453,
     453,  -387,   499,   435,   510,  -387,   456,  -387,  -387,   531,
     518,    73,  -387,  -387,   176,   465,   537,   528,   529,   393,
     227,   227,   227,   227,   227,    52,    52,    52,    52,    52,
      52,    52,   469,  -387,  -387,  -387,   176,  -387,  -387,   597,
     176,   176,  -387,   534,   134,   148,   785,  -387,  -387,  -387,
    -387,  -387,   477,   479,   480,   482,   485,   494,   500,   501,
    -387,  -387,  -387,  -387,  -387,   231,   438,   150,   286,   502,
    -387,  -387,  -387,  -387,  -387,  -387,  -387,   971,   152,  -387,
     231,   231,   998,  -387,  -387,   567,   509,  -387,  -387,   511,
    -387,   -24,   512,   507,    36,  -387,  -387,  -387,   279,  -387,
     515,   520,  -387,   232,   232,  -387,  -387,  -387,   817,   503,
     555,  -387,   149,   117,   299,  -387,   153,   513,  -387,  -387,
     523,   576,   586,   532,   231,   231,   231,   231,   231,   231,
     231,   231,   318,   136,   156,   129,  -387,  -387,   274,  -387,
    -387,  -387,  -387,  -387,  -387,   538,   540,   542,   547,   548,
     549,   606,   231,   231,   231,   231,   231,   231,   231,   231,
     231,   231,   231,   231,   231,   231,  -387,   621,   971,   535,
     552,   435,   510,   533,   553,  -387,   531,  -387,   554,   630,
    -387,   559,  -387,  -387,   560,   561,   279,   279,     8,  -387,
    -387,   279,   566,   568,  -387,   885,   908,   928,   647,   662,
     671,   951,   712,   150,  -387,  -387,   304,  -387,   569,  -387,
     466,  -387,   150,   156,  -387,   826,   974,   800,   612,  -387,
     994,   994,   187,   187,   451,   244,   130,   318,   971,   571,
    -387,   648,  -387,  -387,   150,   327,   150,   -28,  -387,   630,
     577,   431,   279,   581,  -387,   169,   183,   634,  -387,   276,
     580,   279,   279,  -387,   231,   231,   231,  -387,  -387,  -387,
      41,  -387,   150,  -387,  -387,   569,  -387,   583,   582,   596,
    -387,   620,   332,  -387,   603,  -387,   184,   614,  -387,  -387,
    -387,   622,   431,   615,  -387,   279,  -387,  -387,  -387,   625,
     185,   211,   476,   721,   736,   762,   619,   231,  -387,  -387,
    -387,   231,  -387,   701,   150,  -387,   150,  -387,   150,  -387,
    -387,   279,   331,  -387,   635,   640,   683,  -387,  -387,  -387,
     660,  -387,  -387,  -387,  -387,  -387,   219,   971,   844,   498,
     646,  -387,   389,   235,  -387,  -387,  -387,  -387,   228,  -387,
    -387,   643,   644,   231,   642,   661,  -387,   739,  -387,  -387,
     342,   369,  -387,    52,   504,  -387,  -387,   971,  -387,   231,
     723,  -387,  -387,  -387,   372,   803,  -387,  -387,  -387,   867,
     241,  -387,  -387,   672,   525,   539,  -387,  -387,   231,  -387,
    -387,  -387,   565,   777,   411,  -387,   675,  -387,  -387,   578,
    -387
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
    -387,  -387,  -387,  -387,  -387,  -387,  -387,  -387,  -387,  -387,
     728,   737,  -387,  -387,   439,  -387,  -387,  -387,   658,  -387,
    -387,  -387,  -378,  -387,  -387,   710,  -387,  -387,  -387,   441,
    -387,  -315,   344,    78,  -273,  -387,  -283,  -387,    51,  -387,
     707,   669,   -74,  -387,    88,  -387,  -387,  -387,  -387,  -387,
    -387,   157,  -127,  -386,  -244,  -300,   -14,  -387,  -387,  -387,
    -387,  -387,  -387,  -387,  -387,   570,  -387,  -387,  -218,  -220,
    -387,  -387,   440,  -387,   391,  -162,  -224,  -221,  -387,  -387,
    -387,  -387,  -219,    31,  -387,  -387,  -387,  -387,  -387,  -387,
    -387,  -387,  -387,  -387,  -387,  -387,  -387,  -387,  -387,  -387,
    -387,  -387,  -387,  -387,  -387,  -339,  -387,  -387,  -387
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
     310,    31,    32,   168,   345,   206,   443,   130,   436,   -82,
       1,   327,   328,   131,   400,   176,    33,    56,    57,    84,
      34,   177,    75,    32,    35,    36,    37,    75,    32,   338,
     171,    75,    32,    38,    85,   456,   437,   406,   176,     4,
     438,   333,   -82,   334,   178,   123,   124,   122,   268,   269,
     270,   271,   272,   273,   274,   355,   356,   357,   358,   359,
     360,   361,   362,   365,   452,   364,   310,   409,     6,   407,
     -67,    65,   125,   126,   439,   494,   408,    40,   492,   169,
     493,    76,    79,   375,   376,   377,   378,   379,   380,   381,
     382,   383,   384,   385,   386,   387,   388,   410,    78,    31,
      32,   450,   451,   114,    65,   339,   115,   196,   442,   118,
     457,    67,   276,   489,    33,    86,   204,   205,    34,    76,
     130,   127,    35,    36,    37,   144,   195,    79,   112,     5,
     299,    38,   300,   365,     9,   364,    73,   130,   427,   426,
     187,   188,   304,   256,   299,   428,   300,    10,    74,   442,
     299,   514,   300,   315,   316,    76,    12,   172,   173,   392,
      17,   472,   136,   137,   304,    15,   304,    39,   145,    75,
      32,   193,   187,   188,   197,    40,   191,    16,   534,   535,
     243,   244,   301,   302,    27,   453,   454,   455,   542,   324,
      23,   473,   365,   368,   364,   369,   301,   302,   176,   549,
      24,   363,   301,   302,   281,   294,   313,   190,   191,   314,
     315,   316,   176,   510,   511,   257,   325,   130,   282,   294,
     123,   124,   326,   349,   207,   208,    29,   209,   487,   524,
     491,    55,   488,   445,   304,   -24,   304,    76,   304,   446,
      63,   278,   279,   321,   322,   323,   324,   445,   464,   445,
      64,   210,   211,   447,   467,   478,   544,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   315,   316,    31,
      32,   222,   342,   343,   517,   445,    60,   223,   224,   207,
     306,   479,   307,   503,    33,   182,   183,   184,    34,   504,
     529,   225,    35,    36,    37,   512,   226,   513,   227,   464,
     228,    38,   323,   324,    69,   509,   210,   211,   537,   543,
     538,    65,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   187,   188,    31,    32,   222,   263,   264,   265,
     266,   267,   308,   309,    68,    31,    32,   407,   370,    33,
     371,   315,   316,    34,   448,    40,   225,    35,    36,    37,
      33,   226,    70,   227,    34,   228,    38,    71,    35,    36,
      37,    72,    31,    32,    81,    31,    32,    38,   422,   185,
     423,    83,   186,   187,   188,   104,   525,    33,   105,   108,
      33,    34,   106,   107,    34,    35,    36,    37,    35,    36,
      37,   434,   407,   435,    38,   111,   464,    38,   465,   495,
      40,    57,   116,   407,    31,    32,    56,   189,   190,   191,
     522,    40,   185,   117,   120,   186,   187,   188,   133,    33,
     192,   135,   139,    34,    31,    32,   140,    35,    36,    37,
     407,   141,   208,   407,   209,   142,    38,   523,    40,    33,
     532,    40,   143,    34,   -60,   146,   148,    35,    36,    37,
     189,   190,   191,   464,   163,   508,    38,   162,   210,   211,
     208,   165,   209,   262,   180,   181,   182,   183,   184,  -236,
     313,   164,   407,   314,   315,   316,   166,   174,   222,   547,
      40,   175,   200,   194,   223,   224,   210,   211,   201,  -208,
     239,  -236,    87,    88,    89,   240,   241,  -236,   245,   242,
      40,    90,   227,   293,   248,   227,   222,   294,   322,   323,
     324,  -208,   223,   224,    87,    88,    89,  -208,  -236,   251,
      87,    88,    89,    90,   252,    91,   187,   188,   254,    90,
     259,   425,  -236,   227,   258,   294,   275,   480,  -208,   260,
     261,    87,    88,    89,   481,   280,   284,    91,   285,   286,
      90,   287,  -208,    91,   288,    87,    88,    89,  -236,   480,
     189,   190,   191,   289,    90,   480,   506,   312,   330,   290,
     291,  -236,   526,   331,    91,   332,   336,   337,  -208,   188,
     350,    87,    88,    89,   346,  -236,   480,   352,    91,   347,
      90,  -208,   351,   540,    87,    88,    89,   353,   394,   354,
     480,   390,   372,    90,  -144,  -208,  -142,   541,    87,    88,
      89,  -141,  -143,   373,    91,   391,   185,    90,   399,   186,
     187,   188,   396,   338,   401,   313,   480,    91,   314,   315,
     316,   403,   402,   545,   363,   411,   316,   412,   430,   480,
     313,    91,   431,   314,   315,   316,   550,   440,   444,    74,
     449,   459,   460,    92,   189,   190,   191,   317,   318,   319,
     320,   461,   321,   322,   323,   324,   313,   277,   466,   314,
     315,   316,   317,   318,   319,   320,   374,   321,   322,   323,
     324,   313,   463,   468,   314,   315,   316,   471,   469,   485,
     313,   389,   477,   314,   315,   316,   490,   498,   317,   318,
     319,   320,   496,   321,   322,   323,   324,   497,   145,   507,
     515,   516,   518,   317,   318,   319,   320,   417,   321,   322,
     323,   324,   317,   318,   319,   320,   519,   321,   322,   323,
     324,   313,   418,   521,   314,   315,   316,   530,    30,   539,
     313,   419,   548,   314,   315,   316,    28,   150,   151,   152,
     153,   154,   155,   156,   157,   313,   158,   167,   314,   315,
     316,   393,   113,   317,   318,   319,   320,   398,   321,   322,
     323,   324,   317,   318,   319,   320,   470,   321,   322,   323,
     324,   313,   421,   138,   314,   315,   316,   317,   318,   319,
     320,   482,   321,   322,   323,   324,   313,   202,   424,   314,
     315,   316,   329,   458,   185,     0,   483,   186,   187,   188,
       0,     0,     0,   317,   318,   319,   320,     0,   321,   322,
     323,   324,   185,   315,   316,   186,   187,   188,   317,   318,
     319,   320,   484,   321,   322,   323,   324,     0,     0,   186,
     187,   188,   189,   190,   191,   313,     0,   546,   314,   315,
     316,     0,     0,     0,     0,   283,     0,   322,   323,   324,
     189,   190,   191,   313,     0,     0,   314,   315,   316,     0,
       0,     0,     0,   533,   189,   190,   191,   317,   318,   319,
     320,     0,   321,   322,   323,   324,   313,     0,     0,   314,
     315,   316,   429,     0,     0,   317,   318,   319,   320,     0,
     321,   322,   323,   324,   313,     0,     0,   314,   315,   316,
     505,     0,     0,     0,     0,     0,     0,     0,   317,   318,
     319,   320,     0,   321,   322,   323,   324,   313,     0,     0,
     314,   315,   316,   536,     0,     0,   317,   318,   319,   320,
       0,   321,   322,   323,   324,     0,     0,   313,     0,   414,
     314,   315,   316,     0,     0,     0,     0,     0,     0,   317,
     318,   319,   320,     0,   321,   322,   323,   324,     0,     0,
     313,     0,   415,   314,   315,   316,     0,     0,     0,   317,
     318,   319,   320,     0,   321,   322,   323,   324,     0,     0,
     313,     0,   416,   314,   315,   316,   314,   315,   316,     0,
       0,     0,   317,   318,   319,   320,     0,   321,   322,   323,
     324,     0,     0,   313,     0,   420,   314,   315,   316,     0,
       0,     0,   317,   318,   319,   320,     0,   321,   322,   323,
     324,   322,   323,   324,   150,   151,   152,   153,   154,   155,
     156,   157,     0,     0,     0,     0,     0,   319,   320,     0,
     321,   322,   323,   324
};

static const yytype_int16 yycheck[] =
{
     127,   163,   275,   227,    78,   226,   225,   227,   135,   228,
     228,     3,     4,     3,   258,   142,   402,    74,   396,    20,
      71,   240,   241,    80,   339,    74,    18,    10,    11,     3,
      22,    80,     3,     4,    26,    27,    28,     3,     4,     3,
     114,     3,     4,    35,    18,     4,    74,   347,    74,    16,
      78,    75,    20,    77,    80,     3,     4,    71,   185,   186,
     187,   188,   189,   190,   191,   284,   285,   286,   287,   288,
     289,   290,   291,   293,   413,   293,   294,   350,    71,    71,
      81,    82,    30,    31,   399,   471,    78,    79,   466,    79,
     468,    40,    41,   312,   313,   314,   315,   316,   317,   318,
     319,   320,   321,   322,   323,   324,   325,   351,    79,     3,
       4,   411,   412,    79,    82,    79,    65,    79,   401,    68,
      79,    33,   196,   462,    18,    47,   140,   141,    22,    78,
      74,    79,    26,    27,    28,    15,    80,    86,    60,     0,
       4,    35,     6,   363,    12,   363,    13,    74,   372,   370,
      33,    34,   372,    80,     4,   373,     6,    71,    25,   442,
       4,   500,     6,    33,    34,   114,    72,   116,   117,   331,
      72,   444,    84,    85,   394,    14,   396,    71,    58,     3,
       4,   130,    33,    34,   133,    79,    69,     9,   527,   528,
     159,   160,    56,    57,    72,   414,   415,   416,   537,    69,
      10,   445,   422,    74,   422,    76,    56,    57,    74,   548,
       7,    75,    56,    57,    80,    79,    29,    68,    69,    32,
      33,    34,    74,   496,   497,   174,    74,    74,    80,    79,
       3,     4,    80,    80,     3,     4,    72,     6,   457,   512,
     464,    73,   461,    74,   464,    71,   466,   196,   468,    80,
       7,   200,   201,    66,    67,    68,    69,    74,    74,    74,
       7,    30,    31,    80,    80,    80,   539,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    33,    34,     3,
       4,    50,     3,     4,   503,    74,    19,    56,    57,     3,
       4,    80,     6,    74,    18,    63,    64,    65,    22,    80,
     519,    70,    26,    27,    28,    77,    75,    79,    77,    74,
      79,    35,    68,    69,     3,    80,    30,    31,    77,   538,
      79,    82,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    33,    34,     3,     4,    50,   180,   181,   182,
     183,   184,    56,    57,    82,     3,     4,    71,    74,    18,
      76,    33,    34,    22,    78,    79,    70,    26,    27,    28,
      18,    75,    79,    77,    22,    79,    35,    79,    26,    27,
      28,    79,     3,     4,    23,     3,     4,    35,    74,    29,
      76,    81,    32,    33,    34,     4,   513,    18,     8,    18,
      18,    22,     8,    71,    22,    26,    27,    28,    26,    27,
      28,    74,    71,    76,    35,     3,    74,    35,    76,    78,
      79,    11,    20,    71,     3,     4,    10,    67,    68,    69,
      78,    79,    29,    20,     3,    32,    33,    34,    20,    18,
      80,    79,     3,    22,     3,     4,    79,    26,    27,    28,
      71,    79,     4,    71,     6,    79,    35,    78,    79,    18,
      78,    79,    79,    22,    23,    23,     3,    26,    27,    28,
      67,    68,    69,    74,    20,    76,    35,    72,    30,    31,
       4,    17,     6,    80,    61,    62,    63,    64,    65,     3,
      29,    20,    71,    32,    33,    34,     3,    20,    50,    78,
      79,    21,    20,    81,    56,    57,    30,    31,    20,    23,
      50,     3,    26,    27,    28,    79,    73,     3,     9,    75,
      79,    35,    77,    75,     4,    77,    50,    79,    67,    68,
      69,    23,    56,    57,    26,    27,    28,    23,     3,    73,
      26,    27,    28,    35,     3,    59,    33,    34,    20,    35,
       3,    75,     3,    77,    79,    79,    77,    71,    23,    21,
      21,    26,    27,    28,    78,    21,    79,    59,    79,    79,
      35,    79,    23,    59,    79,    26,    27,    28,     3,    71,
      67,    68,    69,    79,    35,    71,    78,    75,    11,    79,
      79,     3,    78,    74,    59,    74,    74,    80,    23,    34,
      77,    26,    27,    28,    79,     3,    71,    21,    59,    79,
      35,    23,    79,    78,    26,    27,    28,    21,    75,    77,
      71,    76,    74,    35,    74,    23,    74,    78,    26,    27,
      28,    74,    74,    74,    59,    73,    29,    35,    74,    32,
      33,    34,    79,     3,    75,    29,    71,    59,    32,    33,
      34,    80,    82,    78,    75,    79,    34,    79,    77,    71,
      29,    59,     4,    32,    33,    34,    78,    80,    77,    25,
      80,    78,    80,    71,    67,    68,    69,    61,    62,    63,
      64,    75,    66,    67,    68,    69,    29,    80,    75,    32,
      33,    34,    61,    62,    63,    64,    80,    66,    67,    68,
      69,    29,    72,    79,    32,    33,    34,    82,    76,    80,
      29,    80,    77,    32,    33,    34,     5,    24,    61,    62,
      63,    64,    77,    66,    67,    68,    69,    77,    58,    73,
      77,    77,    80,    61,    62,    63,    64,    80,    66,    67,
      68,    69,    61,    62,    63,    64,    75,    66,    67,    68,
      69,    29,    80,     4,    32,    33,    34,    24,    20,    77,
      29,    80,    77,    32,    33,    34,    19,    46,    47,    48,
      49,    50,    51,    52,    53,    29,    55,   109,    32,    33,
      34,   332,    62,    61,    62,    63,    64,   336,    66,    67,
      68,    69,    61,    62,    63,    64,   442,    66,    67,    68,
      69,    29,    80,    86,    32,    33,    34,    61,    62,    63,
      64,    80,    66,    67,    68,    69,    29,   138,   368,    32,
      33,    34,   242,   422,    29,    -1,    80,    32,    33,    34,
      -1,    -1,    -1,    61,    62,    63,    64,    -1,    66,    67,
      68,    69,    29,    33,    34,    32,    33,    34,    61,    62,
      63,    64,    80,    66,    67,    68,    69,    -1,    -1,    32,
      33,    34,    67,    68,    69,    29,    -1,    80,    32,    33,
      34,    -1,    -1,    -1,    -1,    80,    -1,    67,    68,    69,
      67,    68,    69,    29,    -1,    -1,    32,    33,    34,    -1,
      -1,    -1,    -1,    80,    67,    68,    69,    61,    62,    63,
      64,    -1,    66,    67,    68,    69,    29,    -1,    -1,    32,
      33,    34,    76,    -1,    -1,    61,    62,    63,    64,    -1,
      66,    67,    68,    69,    29,    -1,    -1,    32,    33,    34,
      76,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    61,    62,
      63,    64,    -1,    66,    67,    68,    69,    29,    -1,    -1,
      32,    33,    34,    76,    -1,    -1,    61,    62,    63,    64,
      -1,    66,    67,    68,    69,    -1,    -1,    29,    -1,    74,
      32,    33,    34,    -1,    -1,    -1,    -1,    -1,    -1,    61,
      62,    63,    64,    -1,    66,    67,    68,    69,    -1,    -1,
      29,    -1,    74,    32,    33,    34,    -1,    -1,    -1,    61,
      62,    63,    64,    -1,    66,    67,    68,    69,    -1,    -1,
      29,    -1,    74,    32,    33,    34,    32,    33,    34,    -1,
      -1,    -1,    61,    62,    63,    64,    -1,    66,    67,    68,
      69,    -1,    -1,    29,    -1,    74,    32,    33,    34,    -1,
      -1,    -1,    61,    62,    63,    64,    -1,    66,    67,    68,
      69,    67,    68,    69,    46,    47,    48,    49,    50,    51,
      52,    53,    -1,    -1,    -1,    -1,    -1,    63,    64,    -1,
      66,    67,    68,    69
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
      97,    73,     3,   112,    20,   113,    80,   121,    79,     3,
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
     115,    82,   117,   137,   143,   145,   132,    77,    80,    80,
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
#line 82 "./Parser/parser_main.y"
                                                                   {fprintf(fp,"\nParsing successful!\n");printOutputTable(&OutputSymbolTable);}
#line 1789 "./exec/y.tab.c"
    break;

  case 3: /* $@1: %empty  */
#line 86 "./Parser/parser_main.y"
                                           {fprintf(fp,"\nInit section begins\n\n");}
#line 1795 "./exec/y.tab.c"
    break;

  case 4: /* init_section: '\\' INIT_BEGIN $@1 mandatory_init set_states block_defn_section gate_defn_section '\\' INIT_END  */
#line 86 "./Parser/parser_main.y"
                                                                                                                                                                   {fprintf(fp,"\nInit section ends\n");}
#line 1801 "./exec/y.tab.c"
    break;

  case 5: /* $@2: %empty  */
#line 89 "./Parser/parser_main.y"
                                            {fprintf(fp,"\nMain section begins\n\n");}
#line 1807 "./exec/y.tab.c"
    break;

  case 6: /* main_section: '\\' MAIN_BEGIN $@2 main_stmt_list '\\' MAIN_END  */
#line 89 "./Parser/parser_main.y"
                                                                                                                    {fprintf(fp,"\nMain section ends\n");}
#line 1813 "./exec/y.tab.c"
    break;

  case 7: /* $@3: %empty  */
#line 92 "./Parser/parser_main.y"
                                             {fprintf(fp,"\nOutput section begins\n\n"); isInOutput = true; outputLevel = 1;}
#line 1819 "./exec/y.tab.c"
    break;

  case 8: /* output_section: '\\' OUTPUT_BEGIN $@3 out_main '\\' OUTPUT_END  */
#line 92 "./Parser/parser_main.y"
                                                                                                                                                        {fprintf(fp,"\nOutput section ends\n");exitOutputSymbolScope(&OutputSymbolTable,outputLevel);}
#line 1825 "./exec/y.tab.c"
    break;

  case 9: /* mandatory_init: '#' REGISTERS QUANTUM '=' NUMBER '#' REGISTERS CLASSICAL '=' NUMBER '#' ITERS '=' NUMBER  */
#line 100 "./Parser/parser_main.y"
                                                                                                                    {  fprintf(fp,"Register and iteration initialization section\n");classical_registers = yyvsp[-4].num;quantum_registers = yyvsp[-9].num;iterations = yyvsp[0].num;}
#line 1831 "./exec/y.tab.c"
    break;

  case 15: /* set_quantum_states: '#' SET QUANTUM STATES ARROW quantum_state_list  */
#line 111 "./Parser/parser_main.y"
                                                                            {fprintf(fp,"Setting initial state of quantum registers\n");}
#line 1837 "./exec/y.tab.c"
    break;

  case 16: /* set_classical_states: '#' SET CLASSICAL STATES ARROW classical_state_list  */
#line 114 "./Parser/parser_main.y"
                                                                                {fprintf(fp,"Setting initial state of classical registers\n");}
#line 1843 "./exec/y.tab.c"
    break;

  case 17: /* quantum_state_list: quantum_state_list ',' state_const  */
#line 117 "./Parser/parser_main.y"
                                                                     {  if(quantum_index == quantum_registers){
                                                                           yyerror("semantic error: quantum registers out of bounds");
                                                                           return 1;
                                                                        }  
                                                                        quantum_states[quantum_index++] = yyvsp[0].q;
                                                                     }
#line 1854 "./exec/y.tab.c"
    break;

  case 18: /* quantum_state_list: state_const  */
#line 123 "./Parser/parser_main.y"
                                                                     {  quantum_states = (struct Quantum*)malloc(sizeof(struct Quantum)*quantum_registers);
                                                                        quantum_states[quantum_index++] = yyvsp[0].q;
                                                                     }
#line 1862 "./exec/y.tab.c"
    break;

  case 19: /* classical_state_list: classical_state_list ',' classical_state  */
#line 128 "./Parser/parser_main.y"
                                                                     { if(classical_index == classical_registers){
                                                                           yyerror("semantic error: classical registers out of bounds");
                                                                           return 1;
                                                                        }
                                                                        classical_states[classical_index++] = yyvsp[0].num;
                                                                     }
#line 1873 "./exec/y.tab.c"
    break;

  case 20: /* classical_state_list: classical_state  */
#line 134 "./Parser/parser_main.y"
                                                                     {  classical_states = (int *)malloc(sizeof(int)*classical_registers);
                                                                        classical_states[classical_index++] = yyvsp[0].num;
                                                                     }
#line 1881 "./exec/y.tab.c"
    break;

  case 21: /* classical_state: NUMBER  */
#line 139 "./Parser/parser_main.y"
                                                                     {yyval.num = yyvsp[0].num;}
#line 1887 "./exec/y.tab.c"
    break;

  case 22: /* $@4: %empty  */
#line 143 "./Parser/parser_main.y"
                           {fprintf(fp,"Gate definition section begins\n");}
#line 1893 "./exec/y.tab.c"
    break;

  case 23: /* gate_defn_section: $@4 gate_defn_list  */
#line 143 "./Parser/parser_main.y"
                                                                                            {fprintf(fp,"Gate definition section ends\n");}
#line 1899 "./exec/y.tab.c"
    break;

  case 27: /* gate_defn: GATE ID '=' rhs  */
#line 151 "./Parser/parser_main.y"
                                             {  fprintf(fp,"Gate definition\n");
                                                if(!insertInGateTable(&GateSymbolTable,yyvsp[-2].str,yyvsp[0].rows,yyvsp[0].cols)){
                                                   yyerror("semantic error: gate definition requires square matrix");
                                                   return 1;
                                                }
                                             }
#line 1910 "./exec/y.tab.c"
    break;

  case 28: /* rhs: '[' tuple_list ']'  */
#line 159 "./Parser/parser_main.y"
                                                {yyval.rows = yyvsp[-1].rows;yyval.cols = yyvsp[-1].cols;}
#line 1916 "./exec/y.tab.c"
    break;

  case 30: /* tuple_list: tuple_list ',' '[' id_list ']'  */
#line 162 "./Parser/parser_main.y"
                                                         {  if(yyvsp[-4].cols != yyvsp[-1].cols){
                                                               yyerror("semantic error: rows of different length cannot form matrix");
                                                               return 1;
                                                            }
                                                            int temp = yyvsp[-4].rows + 1;
                                                            yyval.rows = temp;
                                                            yyval.cols = yyvsp[-4].cols;
                                                         }
#line 1929 "./exec/y.tab.c"
    break;

  case 31: /* tuple_list: '[' id_list ']'  */
#line 170 "./Parser/parser_main.y"
                                                         {yyval.rows = 1;yyval.cols = yyvsp[-1].cols;}
#line 1935 "./exec/y.tab.c"
    break;

  case 34: /* id_list: id_list ',' temp  */
#line 175 "./Parser/parser_main.y"
                                             {yyval.cols += 1;}
#line 1941 "./exec/y.tab.c"
    break;

  case 35: /* id_list: temp  */
#line 176 "./Parser/parser_main.y"
                                             {yyval.cols = 1;}
#line 1947 "./exec/y.tab.c"
    break;

  case 36: /* $@5: %empty  */
#line 179 "./Parser/parser_main.y"
                           {fprintf(fp,"Block definition section begins\n");}
#line 1953 "./exec/y.tab.c"
    break;

  case 37: /* block_defn_section: $@5 block_defns_list  */
#line 179 "./Parser/parser_main.y"
                                                                                               {fprintf(fp,"Block definition section ends\n");}
#line 1959 "./exec/y.tab.c"
    break;

  case 40: /* $@6: %empty  */
#line 186 "./Parser/parser_main.y"
                                                               {  if(!insertInBlockTable(&BlockSymbolTable,yyvsp[-2].str,yyvsp[-1].num,head)){
                                                                     yyerror("semantic error: incorrect block definition");
                                                                     return 1;
                                                                  }
                                                                  head = NULL;
                                                                  isInBlock = 1;
                                                               }
#line 1971 "./exec/y.tab.c"
    break;

  case 41: /* block_defn: BLOCK block_id params target_params $@6 '[' block_body ']'  */
#line 193 "./Parser/parser_main.y"
                                                               {  fprintf(fp,"Block definition\n");
                                                                  if(!BlockSemanticCheck(yyvsp[-6].str)){
                                                                     yyerror("semantic error: incorrect block definition");
                                                                     return 1;
                                                                  }
                                                                  id_list = NULL;
                                                                  isInBlock = 0;
                                                               }
#line 1984 "./exec/y.tab.c"
    break;

  case 42: /* params: ID  */
#line 203 "./Parser/parser_main.y"
                                                {insertInList(&head,yyvsp[0].str);yyval.num = 1;}
#line 1990 "./exec/y.tab.c"
    break;

  case 43: /* params: '(' param_id_list ')'  */
#line 204 "./Parser/parser_main.y"
                                                {yyval.num = yyvsp[-1].num;}
#line 1996 "./exec/y.tab.c"
    break;

  case 44: /* param_id_list: ID ',' param_id_list  */
#line 207 "./Parser/parser_main.y"
                                                {insertInList(&head,yyvsp[-2].str);yyval.num = 1 + yyvsp[0].num;}
#line 2002 "./exec/y.tab.c"
    break;

  case 45: /* param_id_list: ID  */
#line 208 "./Parser/parser_main.y"
                                                {insertInList(&head,yyvsp[0].str);yyval.num = 1;}
#line 2008 "./exec/y.tab.c"
    break;

  case 53: /* block_id: ID  */
#line 224 "./Parser/parser_main.y"
                                 {  if(!firstLetterCapital(yyvsp[0].str)){
                                       yyerror("lexical error: block identifiers start with uppercase letter");
                                       return 1;
                                    } 
                                    assignString(yyval.str,yyvsp[0].str);
                                 }
#line 2019 "./exec/y.tab.c"
    break;

  case 57: /* main_stmt: barrier_stmt  */
#line 242 "./Parser/parser_main.y"
                                          {fprintf(fp,"barrier statement\n");}
#line 2025 "./exec/y.tab.c"
    break;

  case 59: /* stmts: measure_stmt  */
#line 245 "./Parser/parser_main.y"
                                          {fprintf(fp,"Measure statement\n");}
#line 2031 "./exec/y.tab.c"
    break;

  case 60: /* $@7: %empty  */
#line 246 "./Parser/parser_main.y"
                          {fprintf(fp,"Conditional statement begin\n");}
#line 2037 "./exec/y.tab.c"
    break;

  case 61: /* stmts: $@7 condition_stmt  */
#line 246 "./Parser/parser_main.y"
                                                                                        {fprintf(fp,"Conditional statement end\n");}
#line 2043 "./exec/y.tab.c"
    break;

  case 62: /* stmts: for_stmt  */
#line 247 "./Parser/parser_main.y"
                                          {fprintf(fp,"For statement\n");}
#line 2049 "./exec/y.tab.c"
    break;

  case 63: /* stmts: for_lex_stmt  */
#line 248 "./Parser/parser_main.y"
                                          {fprintf(fp,"For - Lex statement\n");}
#line 2055 "./exec/y.tab.c"
    break;

  case 64: /* stmts: for_zip_stmt  */
#line 249 "./Parser/parser_main.y"
                                          {fprintf(fp,"For - Zip statement\n");}
#line 2061 "./exec/y.tab.c"
    break;

  case 65: /* stmts: while_stmt  */
#line 250 "./Parser/parser_main.y"
                                          {fprintf(fp,"while statement\n");}
#line 2067 "./exec/y.tab.c"
    break;

  case 66: /* register: NUMBER  */
#line 253 "./Parser/parser_main.y"
                                  { if(yyvsp[0].num < 0){
                                       yyerror("semantic error: register numbers are non-negative");
                                       return 1;
                                    } 
                                    yyval.num = yyvsp[0].num;
                                    yyval.flag=0;
                                 }
#line 2079 "./exec/y.tab.c"
    break;

  case 67: /* register: ID  */
#line 260 "./Parser/parser_main.y"
                                  {if(isInBlock){insertInList(&id_list,yyvsp[0].str);}yyval.flag = 1;}
#line 2085 "./exec/y.tab.c"
    break;

  case 68: /* call_stmt: classic_control GATE quantum_control ARROW register  */
#line 265 "./Parser/parser_main.y"
                                                                              {fprintf(fp,"Pre - defined Gate call statement\n");}
#line 2091 "./exec/y.tab.c"
    break;

  case 69: /* call_stmt: classic_control ID quantum_control ARROW register  */
#line 266 "./Parser/parser_main.y"
                                                                              {fprintf(fp,"user - defined Gate call statement\n");}
#line 2097 "./exec/y.tab.c"
    break;

  case 70: /* call_stmt: GATE quantum_control ARROW register  */
#line 267 "./Parser/parser_main.y"
                                                                              {fprintf(fp,"Pre - defined Gate call statement\n");}
#line 2103 "./exec/y.tab.c"
    break;

  case 71: /* call_stmt: ID quantum_control ARROW register  */
#line 268 "./Parser/parser_main.y"
                                                                              {fprintf(fp,"User - defined Gate call statement\n");}
#line 2109 "./exec/y.tab.c"
    break;

  case 72: /* call_stmt: classic_control block_id parameters optional  */
#line 269 "./Parser/parser_main.y"
                                                                              {  fprintf(fp,"Block call statement\n");
                                                                                 if(!isInBlock){
                                                                                    if(!BlockCallSemanticCheck(yyvsp[-2].str,yyvsp[-1].num)){
                                                                                       yyerror("semantic error: block not defined");
                                                                                       return 1;
                                                                                    }
                                                                                 }
                                                                              }
#line 2122 "./exec/y.tab.c"
    break;

  case 73: /* call_stmt: block_id parameters optional  */
#line 277 "./Parser/parser_main.y"
                                                                              {  fprintf(fp,"Block call statement\n");
                                                                                 if(!isInBlock){
                                                                                    if(!BlockCallSemanticCheck(yyvsp[-2].str,yyvsp[-1].num)){
                                                                                       yyerror("semantic error: block not defined");
                                                                                       return 1;
                                                                                    }
                                                                                 }
                                                                              }
#line 2135 "./exec/y.tab.c"
    break;

  case 74: /* parameters: register  */
#line 287 "./Parser/parser_main.y"
                                                   {yyval.num = 1;}
#line 2141 "./exec/y.tab.c"
    break;

  case 75: /* parameters: '(' register_list ')'  */
#line 288 "./Parser/parser_main.y"
                                                   {yyval.num = yyvsp[-1].num;}
#line 2147 "./exec/y.tab.c"
    break;

  case 78: /* register_list: register_list ',' register  */
#line 295 "./Parser/parser_main.y"
                                                      {yyval.num = 1 + yyvsp[-2].num;}
#line 2153 "./exec/y.tab.c"
    break;

  case 79: /* register_list: register  */
#line 296 "./Parser/parser_main.y"
                                                      {yyval.num = 1;}
#line 2159 "./exec/y.tab.c"
    break;

  case 87: /* measure_stmt: MEASURE ':' register ARROW register  */
#line 323 "./Parser/parser_main.y"
                                                              {
                           if((!yyvsp[-2].flag && (yyvsp[-2].num < 0 || yyvsp[-2].num >= quantum_registers)) || (!yyvsp[0].flag && (yyvsp[0].num < 0 || yyvsp[0].num >= classical_registers))){
                              yyerror("semantic error: register number out of bounds"); 
                              return 1;
                           }
                        }
#line 2170 "./exec/y.tab.c"
    break;

  case 116: /* range_list: range_list ',' range  */
#line 376 "./Parser/parser_main.y"
                                                   {yyval.num = 1 + yyvsp[-2].num;}
#line 2176 "./exec/y.tab.c"
    break;

  case 117: /* range_list: range  */
#line 377 "./Parser/parser_main.y"
                                                   {yyval.num = 1;}
#line 2182 "./exec/y.tab.c"
    break;

  case 118: /* var_list: var_list ',' ID  */
#line 380 "./Parser/parser_main.y"
                                             {  if(isInOutput){
                                                   if(getOutputSymbolEntry(&OutputSymbolTable,yyvsp[0].str,outputLevel + 1,1) == NULL){
                                                      yyerror("semantic error: variable used without declaration");
                                                      return 1;
                                                   }
                                                }     
                                                else if(!inList(&head,yyvsp[0].str)){
                                                   insertInList(&head,yyvsp[0].str);
                                                } 
                                                else {
                                                   yyerror("semantic error: loop variable redeclaration");
                                                   return 1;
                                                } 
                                                yyval.num = 1 + yyvsp[-2].num;
                                             }
#line 2202 "./exec/y.tab.c"
    break;

  case 119: /* var_list: ID  */
#line 395 "./Parser/parser_main.y"
                                             {  if(isInOutput){
                                                   if(getOutputSymbolEntry(&OutputSymbolTable,yyvsp[0].str,outputLevel + 1,1) == NULL){
                                                      yyerror("semantic error: variable redeclaration");
                                                      return 1;
                                                   }
                                                } 
                                                else if(!inList(&head,yyvsp[0].str)){
                                                   insertInList(&head,yyvsp[0].str);
                                                } 
                                                else{
                                                   yyerror("semantic error: loop variable redeclaration");
                                                   return 1;
                                                } 
                                                yyval.num = 1;
                                             }
#line 2222 "./exec/y.tab.c"
    break;

  case 120: /* $@8: %empty  */
#line 412 "./Parser/parser_main.y"
                                 {  if(!inList(&head,yyvsp[0].str)){
                                       insertInList(&head,yyvsp[0].str);
                                    } 
                                    else{
                                       yyerror("semantic error: loop variable redeclaration"); 
                                       return 1;
                                    }
                                 }
#line 2235 "./exec/y.tab.c"
    break;

  case 121: /* for_stmt: FOR ID $@8 IN '(' range ')' '{' main_stmt_list '}'  */
#line 420 "./Parser/parser_main.y"
                                                                  {removeTopKFromList(&head,1);}
#line 2241 "./exec/y.tab.c"
    break;

  case 122: /* $@9: %empty  */
#line 423 "./Parser/parser_main.y"
                                                                         { if(yyvsp[-5].num != yyvsp[-1].num){
                                                                              yyerror("semantic error: mismatch in loop variables and ranges"); 
                                                                              return 1;
                                                                           }
                                                                         }
#line 2251 "./exec/y.tab.c"
    break;

  case 123: /* for_lex_stmt: FOR_LEX '(' var_list ')' IN '(' range_list ')' $@9 '{' main_stmt_list '}'  */
#line 428 "./Parser/parser_main.y"
                                                 {removeTopKFromList(&head,yyvsp[-9].num);}
#line 2257 "./exec/y.tab.c"
    break;

  case 124: /* $@10: %empty  */
#line 431 "./Parser/parser_main.y"
                                                                         { if(yyvsp[-5].num != yyvsp[-1].num){
                                                                              yyerror("semantic error: mismatch in loop variables and ranges"); 
                                                                              return 1;
                                                                           }
                                                                         }
#line 2267 "./exec/y.tab.c"
    break;

  case 125: /* for_zip_stmt: FOR_ZIP '(' var_list ')' IN '(' range_list ')' $@10 '{' main_stmt_list '}'  */
#line 436 "./Parser/parser_main.y"
                                                 {removeTopKFromList(&head,yyvsp[-9].num);}
#line 2273 "./exec/y.tab.c"
    break;

  case 127: /* out_id: ID  */
#line 448 "./Parser/parser_main.y"
                               {yyval.out_flag = 0; assignString(yyval.str,yyvsp[0].str);}
#line 2279 "./exec/y.tab.c"
    break;

  case 128: /* out_id: COUT  */
#line 449 "./Parser/parser_main.y"
                               {yyval.out_flag = 1; yyval.type = Int; yyval.prim = false; yyval.dim = (1 << classical_registers); yyval.rows = 0;}
#line 2285 "./exec/y.tab.c"
    break;

  case 129: /* out_id: QOUT  */
#line 450 "./Parser/parser_main.y"
                               {yyval.out_flag = 2; yyval.type = State; yyval.prim = false; yyval.dim = quantum_registers; yyval.rows = 0;}
#line 2291 "./exec/y.tab.c"
    break;

  case 130: /* prim_type: INT  */
#line 453 "./Parser/parser_main.y"
                                    {yyval.type = Int; yyval.prim = true;}
#line 2297 "./exec/y.tab.c"
    break;

  case 131: /* prim_type: UINT  */
#line 454 "./Parser/parser_main.y"
                                    {yyval.type = Uint; yyval.prim = true;}
#line 2303 "./exec/y.tab.c"
    break;

  case 132: /* prim_type: FLOAT  */
#line 455 "./Parser/parser_main.y"
                                    {yyval.type = Float; yyval.prim = true;}
#line 2309 "./exec/y.tab.c"
    break;

  case 133: /* prim_type: COMPLEX  */
#line 456 "./Parser/parser_main.y"
                                    {yyval.type = Complex; yyval.prim = true;}
#line 2315 "./exec/y.tab.c"
    break;

  case 134: /* prim_type: STRING  */
#line 457 "./Parser/parser_main.y"
                                    {yyval.type = String; yyval.prim = true;}
#line 2321 "./exec/y.tab.c"
    break;

  case 135: /* prim_type: MATRIX  */
#line 458 "./Parser/parser_main.y"
                                    {yyval.type = Matrix; yyval.prim = true;}
#line 2327 "./exec/y.tab.c"
    break;

  case 136: /* prim_type: STATE  */
#line 459 "./Parser/parser_main.y"
                                    {yyval.type = State; yyval.prim = true;}
#line 2333 "./exec/y.tab.c"
    break;

  case 137: /* prim_type: BOOL  */
#line 460 "./Parser/parser_main.y"
                                    {yyval.type = Bool; yyval.prim = true;}
#line 2339 "./exec/y.tab.c"
    break;

  case 138: /* list_type: LIST '[' prim_type ']'  */
#line 463 "./Parser/parser_main.y"
                                                 {yyval.type = yyvsp[-1].type; yyval.prim = false;}
#line 2345 "./exec/y.tab.c"
    break;

  case 141: /* num: DEC  */
#line 474 "./Parser/parser_main.y"
                                    {yyval.real = yyvsp[0].real;}
#line 2351 "./exec/y.tab.c"
    break;

  case 142: /* num: NEG  */
#line 475 "./Parser/parser_main.y"
                                    {yyval.real = yyvsp[0].real;}
#line 2357 "./exec/y.tab.c"
    break;

  case 143: /* num: EXP  */
#line 476 "./Parser/parser_main.y"
                                    {yyval.real = yyvsp[0].real;}
#line 2363 "./exec/y.tab.c"
    break;

  case 144: /* num: NUMBER  */
#line 477 "./Parser/parser_main.y"
                                    {yyval.real = yyvsp[0].num;}
#line 2369 "./exec/y.tab.c"
    break;

  case 145: /* complex_const: '(' num ',' num ')'  */
#line 479 "./Parser/parser_main.y"
                                                   {yyval.cpx.real = yyvsp[-3].real; yyval.cpx.imag = yyvsp[-1].real;}
#line 2375 "./exec/y.tab.c"
    break;

  case 146: /* matrix_const: '[' row_list ']'  */
#line 482 "./Parser/parser_main.y"
                                                   { if(yyvsp[-1].rows == yyvsp[-1].cols) {
                                                         yyval.rows = yyvsp[-1].rows;
                                                     } 
                                                     else{
                                                         yyerror("semantic error: only square matrices permitted"); 
                                                         return 1;
                                                     }
                                                   }
#line 2388 "./exec/y.tab.c"
    break;

  case 147: /* row_list: row_list ',' row  */
#line 492 "./Parser/parser_main.y"
                                                   {  yyval.rows = yyvsp[-2].rows + 1; 
                                                      if(yyvsp[-2].cols == yyvsp[0].cols){
                                                         yyval.cols = yyvsp[-2].cols;
                                                      } 
                                                      else{
                                                         yyerror("semantic error: rows of different length cannot form matrix"); 
                                                         return 1;
                                                      }
                                                   }
#line 2402 "./exec/y.tab.c"
    break;

  case 148: /* row_list: row  */
#line 501 "./Parser/parser_main.y"
                                                      {yyval.rows = 1; yyval.cols = yyvsp[0].cols;}
#line 2408 "./exec/y.tab.c"
    break;

  case 149: /* row: '[' comps ']'  */
#line 504 "./Parser/parser_main.y"
                                                      {yyval.cols = yyvsp[-1].cols;}
#line 2414 "./exec/y.tab.c"
    break;

  case 150: /* comps: comps ',' compatible_const  */
#line 507 "./Parser/parser_main.y"
                                                      {yyval.cols = yyvsp[-2].cols + 1;}
#line 2420 "./exec/y.tab.c"
    break;

  case 151: /* comps: compatible_const  */
#line 508 "./Parser/parser_main.y"
                                                      {yyval.cols = 1;}
#line 2426 "./exec/y.tab.c"
    break;

  case 154: /* state_const: '{' temp ',' temp '}'  */
#line 515 "./Parser/parser_main.y"
                                                      {yyval.q.first = yyvsp[-3].cpx; yyval.q.second = yyvsp[-1].cpx;}
#line 2432 "./exec/y.tab.c"
    break;

  case 155: /* temp: complex_const  */
#line 518 "./Parser/parser_main.y"
                                                      {yyval.cpx = yyvsp[0].cpx;}
#line 2438 "./exec/y.tab.c"
    break;

  case 156: /* temp: num  */
#line 519 "./Parser/parser_main.y"
                                                      {yyval.cpx.real = yyvsp[0].real; yyval.cpx.imag = 0;}
#line 2444 "./exec/y.tab.c"
    break;

  case 157: /* prim_const: bool_const  */
#line 522 "./Parser/parser_main.y"
                                          {yyval.type = Bool;}
#line 2450 "./exec/y.tab.c"
    break;

  case 158: /* prim_const: complex_const  */
#line 523 "./Parser/parser_main.y"
                                          {yyval.type = Complex;}
#line 2456 "./exec/y.tab.c"
    break;

  case 159: /* prim_const: matrix_const  */
#line 524 "./Parser/parser_main.y"
                                          {yyval.type = Matrix; yyval.rows = yyvsp[0].rows;}
#line 2462 "./exec/y.tab.c"
    break;

  case 160: /* prim_const: state_const  */
#line 525 "./Parser/parser_main.y"
                                          {yyval.type = State;}
#line 2468 "./exec/y.tab.c"
    break;

  case 161: /* prim_const: NUMBER  */
#line 526 "./Parser/parser_main.y"
                                          {yyval.type = Uint;}
#line 2474 "./exec/y.tab.c"
    break;

  case 162: /* prim_const: NEG  */
#line 527 "./Parser/parser_main.y"
                                          {yyval.type = Int;}
#line 2480 "./exec/y.tab.c"
    break;

  case 163: /* prim_const: DEC  */
#line 528 "./Parser/parser_main.y"
                                          {yyval.type = Float;}
#line 2486 "./exec/y.tab.c"
    break;

  case 164: /* prim_const: EXP  */
#line 529 "./Parser/parser_main.y"
                                          {yyval.type = Float;}
#line 2492 "./exec/y.tab.c"
    break;

  case 165: /* prim_const: STRING  */
#line 530 "./Parser/parser_main.y"
                                          {yyval.type = String;}
#line 2498 "./exec/y.tab.c"
    break;

  case 166: /* vec_const: '[' vec_list ']'  */
#line 533 "./Parser/parser_main.y"
                                                {  yyval.dim = yyvsp[-1].dim; 
                                                   yyval.type = yyvsp[-1].type; 
                                                   if(yyval.type == Matrix){
                                                      yyval.rows = yyvsp[-1].rows;
                                                   } 
                                                   else{
                                                      yyval.rows = 0;
                                                   } 
                                                }
#line 2512 "./exec/y.tab.c"
    break;

  case 167: /* vec_list: vec_list ',' prim_const  */
#line 544 "./Parser/parser_main.y"
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
#line 2536 "./exec/y.tab.c"
    break;

  case 168: /* vec_list: prim_const  */
#line 563 "./Parser/parser_main.y"
                                                   {  yyval.type = yyvsp[0].type; yyval.dim = 1; 
                                                      if(yyval.type == Matrix){
                                                         yyval.rows = yyvsp[0].rows;
                                                      }
                                                   }
#line 2546 "./exec/y.tab.c"
    break;

  case 169: /* calls: ADD '(' out_rhs ',' out_rhs ')'  */
#line 572 "./Parser/parser_main.y"
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
#line 2563 "./exec/y.tab.c"
    break;

  case 170: /* calls: SUB '(' out_rhs ',' out_rhs ')'  */
#line 585 "./Parser/parser_main.y"
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
#line 2580 "./exec/y.tab.c"
    break;

  case 171: /* calls: DOT '(' out_rhs ',' out_rhs ')'  */
#line 598 "./Parser/parser_main.y"
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
#line 2606 "./exec/y.tab.c"
    break;

  case 172: /* calls: STD_DEV '(' out_rhs ')'  */
#line 620 "./Parser/parser_main.y"
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
#line 2622 "./exec/y.tab.c"
    break;

  case 173: /* calls: VAR '(' out_rhs ')'  */
#line 632 "./Parser/parser_main.y"
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
#line 2638 "./exec/y.tab.c"
    break;

  case 174: /* calls: CONDENSE '(' out_rhs ',' NUMBER ')'  */
#line 644 "./Parser/parser_main.y"
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
#line 2654 "./exec/y.tab.c"
    break;

  case 175: /* calls: CONDENSE '(' out_rhs ',' '(' uint_list ')' ')'  */
#line 656 "./Parser/parser_main.y"
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
#line 2670 "./exec/y.tab.c"
    break;

  case 176: /* calls: SUM '(' out_rhs ')'  */
#line 668 "./Parser/parser_main.y"
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
#line 2686 "./exec/y.tab.c"
    break;

  case 177: /* calls: AVG '(' out_rhs ')'  */
#line 680 "./Parser/parser_main.y"
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
#line 2702 "./exec/y.tab.c"
    break;

  case 178: /* uint_list: uint_list ',' out_rhs  */
#line 696 "./Parser/parser_main.y"
                                                 { if(yyvsp[-2].type <= Int){
                                                      yyval.cond_count = yyvsp[-2].cond_count + 1;
                                                   } 
                                                   else{
                                                      yyerror("semantic error: only integer elements permitted"); 
                                                      return 1;
                                                   }
                                                 }
#line 2715 "./exec/y.tab.c"
    break;

  case 179: /* uint_list: out_rhs  */
#line 704 "./Parser/parser_main.y"
                                                 { if(yyvsp[0].type <= Int){
                                                      yyval.cond_count = 1;
                                                   } 
                                                   else{
                                                      yyerror("semantic error: only integer elements permitted"); 
                                                      return 1;
                                                   }
                                                 }
#line 2728 "./exec/y.tab.c"
    break;

  case 180: /* out_rhs: prim_const  */
#line 715 "./Parser/parser_main.y"
                                                {yyval.prim = true; yyval.type = yyvsp[0].type;}
#line 2734 "./exec/y.tab.c"
    break;

  case 181: /* out_rhs: vec_const  */
#line 716 "./Parser/parser_main.y"
                                                { yyval.prim = false; yyval.dim = yyvsp[0].dim; 
                                                  yyval.type = yyvsp[0].type; 
                                                  if(yyval.type == Matrix){
                                                      yyval.rows = yyvsp[0].rows;
                                                  } 
                                                  else yyval.rows = 0;
                                                }
#line 2746 "./exec/y.tab.c"
    break;

  case 182: /* out_rhs: out_id  */
#line 723 "./Parser/parser_main.y"
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
                                                }
#line 2780 "./exec/y.tab.c"
    break;

  case 183: /* out_rhs: out_id '[' out_rhs ']'  */
#line 752 "./Parser/parser_main.y"
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
#line 2824 "./exec/y.tab.c"
    break;

  case 184: /* out_rhs: out_id '[' out_rhs ']' '[' out_rhs ']'  */
#line 792 "./Parser/parser_main.y"
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
#line 2868 "./exec/y.tab.c"
    break;

  case 185: /* out_rhs: out_id '[' out_rhs ']' '[' out_rhs ']' '[' out_rhs ']'  */
#line 832 "./Parser/parser_main.y"
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
#line 2902 "./exec/y.tab.c"
    break;

  case 186: /* out_rhs: calls  */
#line 861 "./Parser/parser_main.y"
                                                {  yyval.prim = yyvsp[0].prim; 
                                                   yyval.type = yyvsp[0].type; 
                                                   if(yyvsp[0].type == Matrix) yyval.rows = yyvsp[0].rows; 
                                                   if(!yyval.prim) yyval.dim = yyvsp[0].dim; 
                                                   printf("%d %d\n", yyval.prim, yyval.type);
                                                }
#line 2913 "./exec/y.tab.c"
    break;

  case 187: /* out_rhs: '(' out_rhs ')'  */
#line 867 "./Parser/parser_main.y"
                                                {yyval.type = yyvsp[-1].type;}
#line 2919 "./exec/y.tab.c"
    break;

  case 188: /* out_rhs: '!' out_rhs  */
#line 868 "./Parser/parser_main.y"
                                                {  if(yyvsp[0].type==Bool && yyvsp[0].prim){
                                                      yyval.prim = true; 
                                                      yyval.type = Bool;
                                                   } 
                                                   else{
                                                      yyerror("semantic error"); 
                                                      return 1;
                                                   }  
                                                }
#line 2933 "./exec/y.tab.c"
    break;

  case 189: /* out_rhs: out_rhs AND out_rhs  */
#line 877 "./Parser/parser_main.y"
                                                {  if(yyvsp[-2].type==Bool && yyvsp[-2].prim && yyvsp[0].type==Bool && yyvsp[0].prim){
                                                      yyval.prim = true; 
                                                      yyval.type = Bool;
                                                   } 
                                                   else{
                                                      yyerror("semantic error"); 
                                                      return 1;
                                                   } 
                                                }
#line 2947 "./exec/y.tab.c"
    break;

  case 190: /* out_rhs: out_rhs OR out_rhs  */
#line 886 "./Parser/parser_main.y"
                                                {  if(yyvsp[-2].type==Bool && yyvsp[-2].prim && yyvsp[0].type==Bool && yyvsp[0].prim){
                                                      yyval.prim = true; 
                                                      yyval.type = Bool;
                                                   } 
                                                   else{
                                                      yyerror("semantic error"); 
                                                      return 1;
                                                   } 
                                                }
#line 2961 "./exec/y.tab.c"
    break;

  case 191: /* out_rhs: out_rhs COMP out_rhs  */
#line 895 "./Parser/parser_main.y"
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
#line 2976 "./exec/y.tab.c"
    break;

  case 192: /* out_rhs: out_rhs EQUALITY out_rhs  */
#line 905 "./Parser/parser_main.y"
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
#line 2991 "./exec/y.tab.c"
    break;

  case 193: /* out_rhs: out_rhs '*' out_rhs  */
#line 915 "./Parser/parser_main.y"
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
#line 3014 "./exec/y.tab.c"
    break;

  case 194: /* out_rhs: out_rhs '/' out_rhs  */
#line 933 "./Parser/parser_main.y"
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
#line 3029 "./exec/y.tab.c"
    break;

  case 195: /* out_rhs: out_rhs '+' out_rhs  */
#line 944 "./Parser/parser_main.y"
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
#line 3052 "./exec/y.tab.c"
    break;

  case 196: /* out_rhs: out_rhs '-' out_rhs  */
#line 962 "./Parser/parser_main.y"
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
#line 3069 "./exec/y.tab.c"
    break;

  case 197: /* out_rhs: out_rhs '@' out_rhs  */
#line 974 "./Parser/parser_main.y"
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
#line 3105 "./exec/y.tab.c"
    break;

  case 198: /* out_rhs: out_rhs '&' out_rhs  */
#line 1006 "./Parser/parser_main.y"
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
#line 3120 "./exec/y.tab.c"
    break;

  case 199: /* out_rhs: out_rhs '^' out_rhs  */
#line 1017 "./Parser/parser_main.y"
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
#line 3135 "./exec/y.tab.c"
    break;

  case 200: /* out_rhs: out_rhs '|' out_rhs  */
#line 1028 "./Parser/parser_main.y"
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
#line 3150 "./exec/y.tab.c"
    break;

  case 201: /* out_expr: ID '=' out_rhs  */
#line 1041 "./Parser/parser_main.y"
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
                                                   }
#line 3170 "./exec/y.tab.c"
    break;

  case 202: /* decl: prim_type out_expr  */
#line 1058 "./Parser/parser_main.y"
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
                                                   }
#line 3189 "./exec/y.tab.c"
    break;

  case 203: /* decl: list_type out_expr  */
#line 1073 "./Parser/parser_main.y"
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
#line 3208 "./exec/y.tab.c"
    break;

  case 204: /* echo_stmt: ECHO '(' echo_list ')'  */
#line 1090 "./Parser/parser_main.y"
                                                      {fprintf(fp,"Echo statement\n");}
#line 3214 "./exec/y.tab.c"
    break;

  case 207: /* save_stmt: '\\' SAVE STRING  */
#line 1098 "./Parser/parser_main.y"
                                                      {fprintf(fp,"Save statement\n");}
#line 3220 "./exec/y.tab.c"
    break;

  case 208: /* $@11: %empty  */
#line 1102 "./Parser/parser_main.y"
                          {fprintf(fp,"Output section conditional statement begins\n");}
#line 3226 "./exec/y.tab.c"
    break;

  case 209: /* out_control: $@11 out_cond_stmt  */
#line 1102 "./Parser/parser_main.y"
                                                                                                       {fprintf(fp,"Output section conditional statement ends\n");}
#line 3232 "./exec/y.tab.c"
    break;

  case 210: /* out_control: out_for_stmt  */
#line 1103 "./Parser/parser_main.y"
                                                      {fprintf(fp,"For statement in output section\n");}
#line 3238 "./exec/y.tab.c"
    break;

  case 211: /* out_control: out_for_lex_stmt  */
#line 1104 "./Parser/parser_main.y"
                                                      {fprintf(fp,"For - lex statement in output section\n");}
#line 3244 "./exec/y.tab.c"
    break;

  case 212: /* out_control: out_for_zip_stmt  */
#line 1105 "./Parser/parser_main.y"
                                                      {fprintf(fp,"For - zip statement in output section\n");}
#line 3250 "./exec/y.tab.c"
    break;

  case 213: /* out_control: out_while_stmt  */
#line 1106 "./Parser/parser_main.y"
                                                      {fprintf(fp,"while statement in output section\n");}
#line 3256 "./exec/y.tab.c"
    break;

  case 214: /* $@12: %empty  */
#line 1109 "./Parser/parser_main.y"
                                                        {outputLevel++;}
#line 3262 "./exec/y.tab.c"
    break;

  case 215: /* out_cond_stmt: CONDITION '(' out_rhs ')' '{' $@12 out_main '}' out_other_list out_other_final  */
#line 1109 "./Parser/parser_main.y"
                                                                                                                     {outputLevel--;}
#line 3268 "./exec/y.tab.c"
    break;

  case 220: /* $@13: %empty  */
#line 1120 "./Parser/parser_main.y"
                                 {  if(getOutputSymbolEntry(&OutputSymbolTable,yyvsp[0].str,outputLevel + 1,1) == NULL){
                                       yyerror("semantic error: variable used without declaration"); 
                                       return 1;
                                    }
                                 }
#line 3278 "./exec/y.tab.c"
    break;

  case 221: /* $@14: %empty  */
#line 1125 "./Parser/parser_main.y"
                                               {outputLevel++;printf("Entered loop\n");}
#line 3284 "./exec/y.tab.c"
    break;

  case 222: /* out_for_stmt: FOR ID $@13 IN '(' range ')' '{' $@14 out_main '}'  */
#line 1126 "./Parser/parser_main.y"
                                               {exitOutputSymbolScope(&OutputSymbolTable,outputLevel);printf("exited loop\n") ;outputLevel--;}
#line 3290 "./exec/y.tab.c"
    break;

  case 223: /* $@15: %empty  */
#line 1129 "./Parser/parser_main.y"
                                                                          {   if(yyvsp[-5].num != yyvsp[-1].num){
                                                                                 yyerror("semantic error: mismatch in loop variables and ranges"); 
                                                                                 return 1;
                                                                              }
                                                                          }
#line 3300 "./exec/y.tab.c"
    break;

  case 224: /* $@16: %empty  */
#line 1134 "./Parser/parser_main.y"
                              {outputLevel++;}
#line 3306 "./exec/y.tab.c"
    break;

  case 225: /* out_for_lex_stmt: FOR_LEX '(' var_list ')' IN '(' range_list ')' $@15 '{' $@16 out_main '}'  */
#line 1134 "./Parser/parser_main.y"
                                                                          {exitOutputSymbolScope(&OutputSymbolTable,outputLevel); outputLevel--;}
#line 3312 "./exec/y.tab.c"
    break;

  case 226: /* $@17: %empty  */
#line 1137 "./Parser/parser_main.y"
                                                                          {   if(yyvsp[-5].num != yyvsp[-1].num){
                                                                                 yyerror("semantic error: mismatch in loop variables and ranges"); 
                                                                                 return 1;
                                                                              }
                                                                          }
#line 3322 "./exec/y.tab.c"
    break;

  case 227: /* $@18: %empty  */
#line 1142 "./Parser/parser_main.y"
                              {outputLevel++;}
#line 3328 "./exec/y.tab.c"
    break;

  case 228: /* out_for_zip_stmt: FOR_ZIP '(' var_list ')' IN '(' range_list ')' $@17 '{' $@18 out_main '}'  */
#line 1142 "./Parser/parser_main.y"
                                                                          {exitOutputSymbolScope(&OutputSymbolTable,outputLevel); outputLevel--;}
#line 3334 "./exec/y.tab.c"
    break;

  case 229: /* $@19: %empty  */
#line 1145 "./Parser/parser_main.y"
                                                 {outputLevel++;}
#line 3340 "./exec/y.tab.c"
    break;

  case 230: /* out_while_stmt: WHILE '(' expr ')' '{' $@19 out_main '}'  */
#line 1145 "./Parser/parser_main.y"
                                                                               {exitOutputSymbolScope(&OutputSymbolTable,outputLevel); outputLevel--;}
#line 3346 "./exec/y.tab.c"
    break;

  case 236: /* $@20: %empty  */
#line 1157 "./Parser/parser_main.y"
                          {isDeclaration = false;}
#line 3352 "./exec/y.tab.c"
    break;

  case 238: /* $@21: %empty  */
#line 1158 "./Parser/parser_main.y"
                          {isDeclaration = true;}
#line 3358 "./exec/y.tab.c"
    break;


#line 3362 "./exec/y.tab.c"

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

#line 1160 "./Parser/parser_main.y"


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
   printf("Insertion : %s %d %d %d %d\n", newNode->id, newNode->level, newNode->primitive, newNode->dim, newNode->matrix_dim);
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
  yyparse();

  return 0;
}

void yyerror(char* err){
   printf("At line %d: %s\n", line, err);
   fprintf(fp,"At line %d: %s\n",line, err);
}
