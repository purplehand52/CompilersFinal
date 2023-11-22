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
  YYSYMBOL_150_11 = 150,                   /* @11  */
  YYSYMBOL_bool_const = 151,               /* bool_const  */
  YYSYMBOL_num = 152,                      /* num  */
  YYSYMBOL_complex_const = 153,            /* complex_const  */
  YYSYMBOL_matrix_const = 154,             /* matrix_const  */
  YYSYMBOL_row_list = 155,                 /* row_list  */
  YYSYMBOL_row = 156,                      /* row  */
  YYSYMBOL_comps = 157,                    /* comps  */
  YYSYMBOL_compatible_const = 158,         /* compatible_const  */
  YYSYMBOL_state_const = 159,              /* state_const  */
  YYSYMBOL_temp = 160,                     /* temp  */
  YYSYMBOL_prim_const = 161,               /* prim_const  */
  YYSYMBOL_vec_const = 162,                /* vec_const  */
  YYSYMBOL_vec_list = 163,                 /* vec_list  */
  YYSYMBOL_calls = 164,                    /* calls  */
  YYSYMBOL_uint_list = 165,                /* uint_list  */
  YYSYMBOL_out_rhs = 166,                  /* out_rhs  */
  YYSYMBOL_out_expr = 167,                 /* out_expr  */
  YYSYMBOL_decl = 168,                     /* decl  */
  YYSYMBOL_echo_stmt = 169,                /* echo_stmt  */
  YYSYMBOL_echo_list = 170,                /* echo_list  */
  YYSYMBOL_save_stmt = 171,                /* save_stmt  */
  YYSYMBOL_out_control = 172,              /* out_control  */
  YYSYMBOL_173_12 = 173,                   /* $@12  */
  YYSYMBOL_out_cond_stmt = 174,            /* out_cond_stmt  */
  YYSYMBOL_175_13 = 175,                   /* $@13  */
  YYSYMBOL_176_14 = 176,                   /* $@14  */
  YYSYMBOL_out_other_list = 177,           /* out_other_list  */
  YYSYMBOL_178_15 = 178,                   /* $@15  */
  YYSYMBOL_out_other_final = 179,          /* out_other_final  */
  YYSYMBOL_180_16 = 180,                   /* $@16  */
  YYSYMBOL_out_for_stmt = 181,             /* out_for_stmt  */
  YYSYMBOL_182_17 = 182,                   /* $@17  */
  YYSYMBOL_183_18 = 183,                   /* $@18  */
  YYSYMBOL_out_for_lex_stmt = 184,         /* out_for_lex_stmt  */
  YYSYMBOL_185_19 = 185,                   /* $@19  */
  YYSYMBOL_186_20 = 186,                   /* $@20  */
  YYSYMBOL_out_for_zip_stmt = 187,         /* out_for_zip_stmt  */
  YYSYMBOL_188_21 = 188,                   /* $@21  */
  YYSYMBOL_189_22 = 189,                   /* $@22  */
  YYSYMBOL_out_while_stmt = 190,           /* out_while_stmt  */
  YYSYMBOL_191_23 = 191,                   /* $@23  */
  YYSYMBOL_out_main = 192,                 /* out_main  */
  YYSYMBOL_out_stmt = 193,                 /* out_stmt  */
  YYSYMBOL_194_24 = 194,                   /* $@24  */
  YYSYMBOL_195_25 = 195                    /* $@25  */
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
#define YYLAST   1068

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  83
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  113
/* YYNRULES -- Number of rules.  */
#define YYNRULES  243
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  555

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
     367,   368,   372,   373,   376,   377,   380,   388,   398,   413,
     430,   430,   441,   441,   449,   449,   457,   466,   467,   468,
     471,   472,   473,   474,   475,   476,   477,   478,   481,   481,
     488,   489,   492,   493,   494,   495,   497,   500,   510,   519,
     522,   525,   526,   529,   530,   533,   536,   537,   540,   545,
     549,   554,   555,   556,   557,   558,   559,   562,   579,   603,
     614,   631,   648,   674,   689,   704,   719,   735,   750,   770,
     782,   794,   795,   803,   833,   876,   921,   957,   963,   969,
     981,   995,  1008,  1022,  1036,  1058,  1072,  1095,  1111,  1146,
    1161,  1176,  1194,  1214,  1231,  1248,  1253,  1258,  1265,  1269,
    1269,  1270,  1271,  1272,  1273,  1276,  1276,  1276,  1279,  1279,
    1280,  1283,  1283,  1284,  1287,  1292,  1287,  1296,  1302,  1296,
    1314,  1320,  1314,  1324,  1324,  1329,  1330,  1333,  1334,  1335,
    1336,  1336,  1337,  1337
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
  "while_stmt", "out_id", "prim_type", "list_type", "@11", "bool_const",
  "num", "complex_const", "matrix_const", "row_list", "row", "comps",
  "compatible_const", "state_const", "temp", "prim_const", "vec_const",
  "vec_list", "calls", "uint_list", "out_rhs", "out_expr", "decl",
  "echo_stmt", "echo_list", "save_stmt", "out_control", "$@12",
  "out_cond_stmt", "$@13", "$@14", "out_other_list", "$@15",
  "out_other_final", "$@16", "out_for_stmt", "$@17", "$@18",
  "out_for_lex_stmt", "$@19", "$@20", "out_for_zip_stmt", "$@21", "$@22",
  "out_while_stmt", "$@23", "out_main", "out_stmt", "$@24", "$@25", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-428)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-241)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -45,    15,    89,    38,  -428,  -428,    84,    62,    28,  -428,
     146,  -428,   155,   115,  -428,  -428,   192,   222,  -428,   171,
     186,   426,  -428,   203,   127,   211,   289,   308,  -428,   316,
    -428,    35,  -428,   245,   249,   293,   253,   259,   270,   114,
     191,    20,  -428,  -428,   327,   276,  -428,    19,  -428,  -428,
    -428,  -428,  -428,  -428,   582,   354,   360,   361,   313,   371,
     390,  -428,   289,   387,   391,    29,   385,   393,   191,  -428,
     405,   405,     9,  -428,  -428,  -428,  -428,   -24,   191,  -428,
     400,   342,  -428,  -428,   -16,   245,    20,   419,   345,   346,
     349,   355,    10,  -428,  -428,  -428,   410,  -428,  -428,  -428,
    -428,  -428,   432,   980,   373,   423,   435,   440,   460,   371,
    -428,  -428,    25,  -428,   191,  -428,   191,   191,   448,   451,
     407,   403,   404,  -428,  -428,  -428,  -428,     9,   415,   287,
     191,   406,    40,    42,  -428,     9,   470,   478,   400,  -428,
     405,   405,   247,   247,  -428,   450,   422,  -428,   429,  -428,
    -428,  -428,  -428,  -428,  -428,  -428,  -428,  -428,   437,   432,
     432,  -428,   495,   430,   509,  -428,   443,  -428,  -428,   514,
     501,    54,  -428,  -428,   191,   446,   405,   507,   508,   531,
     221,   221,   221,   221,   221,     9,     9,     9,     9,     9,
       9,     9,   453,  -428,  -428,  -428,   191,  -428,  -428,   821,
     191,   191,  -428,   511,   454,   456,  -428,  -428,  -428,  -428,
    -428,   459,   462,   471,   472,   474,   477,   480,   487,  -428,
    -428,  -428,  -428,  -428,   247,   381,   109,   303,   482,  -428,
    -428,  -428,  -428,  -428,  -428,  -428,   595,   984,    82,  -428,
     247,   247,  -428,  -428,  -428,   536,   475,  -428,  -428,   488,
    -428,   -28,   503,   490,    32,  -428,  -428,  -428,   236,  -428,
     500,   505,  -428,   230,   230,  -428,  -428,  -428,   159,   268,
     541,  -428,   163,    98,   214,  -428,   132,   519,  -428,  -428,
     512,   576,   581,   247,   247,   247,   247,   247,   247,   247,
     247,   277,    79,   147,    81,  -428,   529,   530,  -428,  -428,
    -428,  -428,  -428,  -428,   533,   538,   539,   544,   556,   557,
     616,   247,   247,   247,   247,   247,   247,   247,   247,   247,
     247,   247,   247,   247,   542,   247,  -428,   636,   984,  1015,
     559,   430,   509,   540,   560,  -428,   514,  -428,   561,   631,
    -428,   563,  -428,  -428,   554,   562,   236,   236,    16,  -428,
    -428,   236,   564,   567,   907,   916,   932,   657,   677,   698,
     975,   718,   109,  -428,  -428,   131,  -428,   565,  -428,   458,
    -428,   109,   147,  -428,   850,   231,   553,   613,  -428,   991,
     991,   296,   296,   212,   167,   185,   277,  -428,   984,   574,
     578,   648,  -428,  -428,   109,   305,   109,   -26,  -428,   631,
     575,   447,   236,   583,   592,   587,   591,   647,  -428,   195,
     593,   236,   236,   247,   247,   247,  -428,  -428,  -428,    14,
    -428,   109,  -428,  -428,   565,  -428,   596,   601,   612,  -428,
    -428,  -428,   604,   323,  -428,   617,  -428,   135,   609,  -428,
    -428,  -428,   618,   447,   611,  -428,   236,  -428,  -428,  -428,
     624,   615,   627,   739,   759,   780,   628,   247,  -428,  -428,
    -428,   247,   468,  -428,   707,   109,  -428,   109,  -428,   109,
    -428,  -428,   236,   234,  -428,   637,   638,   689,  -428,  -428,
    -428,  -428,  -428,  -428,  -428,   136,   984,   866,   659,  -428,
     483,   649,  -428,   328,   140,  -428,  -428,  -428,  -428,    13,
    -428,  -428,   651,   652,   247,   653,   660,  -428,   730,  -428,
    -428,   348,   368,  -428,     9,   496,  -428,  -428,   984,  -428,
     247,  -428,  -428,  -428,  -428,   388,   841,  -428,  -428,  -428,
     891,   712,  -428,   665,   517,   545,  -428,   330,  -428,  -428,
    -428,  -428,  -428,   247,   414,  -428,   800,  -428,   555,   671,
    -428,  -428,  -428,   566,  -428
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     3,     1,     0,     0,     0,     5,
       0,     2,     0,    14,    55,     7,     0,     0,    36,    12,
      13,    60,   236,     0,     0,    22,    39,     0,    10,     0,
      11,    53,    66,    82,     0,     0,     0,     0,     0,     0,
       0,     0,    54,    56,     0,     0,    58,     0,    59,    57,
      62,    63,    64,    65,   242,     0,     0,     0,     0,     0,
       0,    37,    39,     0,     0,     0,     0,     0,     0,   120,
       0,     0,     0,     6,    88,    67,    79,     0,     0,    74,
      76,     0,    61,    80,    53,    82,     0,     0,     0,     0,
       0,     0,     0,   239,   238,   237,     0,   211,   212,   213,
     214,   235,     0,     0,     0,     0,     0,     0,     0,    23,
      26,    53,     0,    38,     0,    83,     0,     0,     0,     0,
     119,     0,     0,    99,   100,   110,   111,     0,   109,     0,
       0,     0,     0,     0,    73,     0,     0,     0,    76,   224,
       0,     0,     0,     0,     8,     0,     0,   210,     0,   241,
     130,   131,   132,   133,   134,   135,   136,   137,     0,     0,
       0,   243,     0,     0,     0,     4,     0,    25,    42,     0,
      46,     0,    71,    70,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    78,    81,    75,     0,    85,    77,     0,
       0,     0,    72,     0,     0,     0,   127,   162,   163,   140,
     141,     0,     0,     0,     0,     0,     0,     0,     0,   128,
     129,   166,   164,   165,     0,     0,     0,     0,   183,   158,
     159,   160,   161,   181,   182,   187,     0,   207,     0,   208,
       0,     0,   138,   203,   204,     0,    15,    18,    21,    16,
      20,     0,    45,     0,     0,    40,    84,    87,     0,   118,
       0,     0,   108,    94,    95,    96,    97,    98,   101,   102,
     103,   104,   106,   105,   107,    55,     0,     0,    69,    68,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   189,     0,     0,     0,   149,   169,     0,   145,   143,
     142,   144,   157,   156,     0,   162,   163,   164,   165,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   205,     0,   202,     0,
       0,     0,     0,     0,     0,    27,     0,    43,    50,     0,
      48,     0,   113,   112,     0,     0,     0,     0,    60,    86,
      55,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   154,   153,     0,   152,     0,   147,     0,
     167,     0,     0,   188,     0,   192,   193,   190,   191,   196,
     197,   194,   195,   198,   199,   200,   201,   233,   206,     0,
       0,     0,    17,    19,     0,     0,     0,     0,    44,     0,
       0,    51,     0,     0,   117,     0,     0,     0,   126,    60,
       0,     0,     0,     0,     0,     0,   173,   174,   178,     0,
     177,     0,   150,   148,     0,   168,     0,     0,   184,   236,
     215,   139,     0,     0,    35,     0,    28,     0,     0,    29,
      49,    47,     0,    51,   114,    55,     0,   122,   124,    91,
       0,     0,     0,     0,     0,     0,     0,     0,   151,   155,
     146,     0,   242,   236,     0,     0,    31,     0,    33,     0,
      41,    52,     0,    60,   116,     0,     0,    93,   225,   227,
     230,   170,   171,   172,   175,     0,   180,     0,     0,   234,
     242,     0,    34,     0,     0,   115,   121,    55,    55,     0,
      89,   236,     0,     0,     0,     0,   185,   216,     0,    30,
      32,    60,    60,    55,     0,   242,   228,   231,   179,   176,
       0,   220,     9,   123,   125,    60,     0,   226,   236,   236,
       0,   223,    92,     0,   242,   242,   186,     0,   217,    55,
     229,   232,   221,     0,    60,   236,     0,    90,   242,     0,
     222,   218,   236,   242,   219
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -428,  -428,  -428,  -428,  -428,  -428,  -428,  -428,  -428,  -428,
     729,   734,  -428,  -428,   424,  -428,  -428,  -428,   645,  -428,
    -428,  -428,  -343,  -428,  -428,   693,  -428,  -428,  -428,   427,
    -428,  -329,   315,    11,  -264,  -428,  -374,  -428,   -11,  -428,
     683,   632,   -73,  -428,    45,  -428,  -428,  -428,  -428,  -428,
    -428,   722,  -126,  -381,  -241,  -339,   -64,  -428,  -428,  -428,
    -428,  -428,  -428,  -428,  -428,   445,  -428,  -428,  -428,  -213,
    -210,  -428,  -428,   408,  -428,   356,  -148,  -223,  -219,  -428,
     420,  -428,  -428,  -143,   108,  -428,  -428,  -428,  -428,  -428,
    -428,  -428,  -428,  -428,  -428,  -428,  -428,  -428,  -428,  -428,
    -428,  -428,  -428,  -428,  -428,  -428,  -428,  -428,  -428,  -427,
    -428,  -428,  -428
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     2,     3,     8,     7,    14,    11,    22,    13,    18,
      19,    20,   246,   249,   250,    58,    59,   109,   110,   335,
     395,   397,   433,    25,    26,    61,    62,   341,   170,   253,
     255,   340,   442,    41,    21,    42,    43,    44,    45,    46,
      80,   134,    77,    47,    66,   198,    48,    49,    82,   477,
     500,   128,   129,   344,   404,   405,   121,    50,   119,    51,
     475,    52,   476,    53,   228,   159,   160,   329,   229,   302,
     230,   231,   294,   295,   365,   366,   232,   434,   233,   234,
     297,   235,   485,   236,   149,   161,    93,   238,    94,    95,
      96,   147,   463,   521,   531,   552,   538,   545,    97,   203,
     501,    98,   502,   528,    99,   503,   529,   100,   429,    54,
     101,   102,   103
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     237,   179,   462,   304,   -82,   132,   296,   122,   406,   199,
     400,   348,   123,   124,   309,   247,   303,   345,   456,    31,
      32,   444,    84,    75,    32,   144,     1,   443,   168,    76,
      79,     4,    75,    32,    33,   338,   490,    85,    34,   125,
     126,   171,    35,    36,    37,    75,    32,   333,   438,   334,
     130,    38,   439,   437,   115,   -82,   131,   118,    86,   268,
     269,   270,   271,   272,   273,   274,    65,    76,   145,   443,
     440,   112,   451,   452,   515,    79,   204,   205,    67,   363,
     309,   291,   364,   298,   310,   299,   409,   407,   127,     5,
     513,   495,   514,   457,   408,    40,     9,   327,   328,    78,
      12,   534,   535,    76,   169,   172,   173,   474,   114,     6,
     410,   339,   259,   298,   130,   299,   -67,    65,   548,   193,
     195,   196,   197,   276,   493,   553,   494,    73,   130,   136,
     137,   187,   188,    10,   256,   300,   301,    56,    57,    74,
     354,   355,   356,   357,   358,   359,   360,   361,   426,   363,
     296,   298,   364,   299,   362,   367,   325,   368,   293,   427,
      15,   303,   326,   257,    16,   300,   301,   191,   374,   375,
     376,   377,   378,   379,   380,   381,   382,   383,   384,   385,
     386,   473,   388,   392,   303,    76,   303,    17,   293,   278,
     279,   186,   187,   188,    75,    32,   187,   188,    31,    32,
     314,   315,    23,   300,   301,   421,   130,   422,   363,   465,
     504,   364,   349,    33,   465,   468,   505,    34,   314,   315,
     510,    35,    36,    37,   123,   124,   189,   190,   191,    24,
      38,   190,   191,   511,   512,   322,   323,    31,    32,   342,
     343,   312,   492,    27,   313,   314,   315,   187,   188,   525,
     206,   207,    33,   208,   323,   303,    34,   303,    29,   303,
      35,    36,    37,   313,   314,   315,   407,   243,   244,    38,
     453,   454,   455,   449,    40,   544,    55,   209,   210,   321,
     322,   323,   -24,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   182,   183,   184,    69,   221,   321,   322,
     323,   187,   188,   222,   223,   407,   206,   305,    60,   306,
     314,   315,   496,    40,   486,    63,   185,   224,   487,   186,
     187,   188,   225,    64,   226,   312,   227,    65,   313,   314,
     315,    68,    70,   209,   210,   189,   190,   191,    71,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,    72,
      81,    31,    32,   221,   189,   190,   191,    83,   104,   307,
     308,   518,   320,   321,   322,   323,    33,   192,   105,   106,
      34,    31,    32,   224,    35,    36,    37,   530,   225,   435,
     226,   436,   227,    38,   107,   207,    33,   208,   526,   108,
      34,    31,    32,   111,    35,    36,    37,   465,    57,   466,
     546,    56,   465,    38,   509,   116,    33,   542,   120,   543,
      34,   209,   210,   117,    35,    36,    37,    31,    32,   407,
     133,   135,   139,    38,   140,   141,   523,    40,   142,    31,
      32,   221,    33,   146,   143,   148,    34,   222,   223,   407,
      35,    36,    37,   163,    33,   162,   524,    40,    34,    38,
      31,    32,    35,    36,    37,   164,   292,   165,   226,   407,
     293,    38,   207,   166,   208,    33,   532,    40,   174,    34,
     -60,  -240,   175,    35,    36,    37,   180,   181,   182,   183,
     184,   176,    38,   177,   178,   407,  -240,   194,   209,   210,
     200,  -209,   547,    40,    87,    88,    89,    39,   201,  -240,
     239,   240,   241,    90,   245,    40,  -209,   226,   221,    87,
      88,    89,   242,   248,   222,   223,   251,   252,    90,  -209,
    -240,   254,    87,    88,    89,   258,    40,    91,   260,   261,
     275,    90,   280,   424,   281,   226,   282,   293,   283,   488,
    -209,   284,    91,    87,    88,    89,   489,   330,  -240,   331,
     285,   286,    90,   287,   488,    91,   288,   311,  -240,   289,
     185,   507,   332,   186,   187,   188,   290,   488,  -209,  -240,
     337,    87,    88,    89,   527,   188,    91,   336,  -209,   346,
      90,    87,    88,    89,   347,  -240,   314,   315,   488,  -209,
      90,   351,    87,    88,    89,   540,   350,   352,   189,   190,
     191,    90,   353,   369,    91,  -209,   370,   371,    87,    88,
      89,   262,  -145,  -143,    91,   394,   488,    90,  -142,   387,
     321,   322,   323,   541,   312,    91,   488,   313,   314,   315,
    -144,   372,   391,   550,   338,   399,   402,   488,   401,   396,
     362,    91,   403,   411,   554,   312,   412,   315,   313,   314,
     315,   430,   432,    92,   431,   441,   316,   317,   318,   319,
     445,   320,   321,   322,   323,   312,   446,   447,   313,   314,
     315,   448,    74,   450,   459,   324,   464,   316,   317,   318,
     319,   460,   320,   321,   322,   323,   312,   461,   469,   313,
     314,   315,   467,   472,   470,   479,   373,   316,   317,   318,
     319,   478,   320,   321,   322,   323,   312,   480,   484,   313,
     314,   315,   491,   499,   497,   498,   389,   145,   316,   317,
     318,   319,   508,   320,   321,   322,   323,   312,   516,   517,
     313,   314,   315,   519,   522,   520,   537,   416,   316,   317,
     318,   319,   539,   320,   321,   322,   323,   312,   551,    30,
     313,   314,   315,    28,   167,   113,   393,   417,   471,   316,
     317,   318,   319,   398,   320,   321,   322,   323,   312,   138,
     202,   313,   314,   315,   390,   423,     0,   458,   418,   316,
     317,   318,   319,     0,   320,   321,   322,   323,   312,   425,
       0,   313,   314,   315,     0,     0,     0,     0,   420,     0,
     316,   317,   318,   319,     0,   320,   321,   322,   323,   312,
       0,     0,   313,   314,   315,     0,     0,     0,     0,   481,
     316,   317,   318,   319,     0,   320,   321,   322,   323,   312,
       0,     0,   313,   314,   315,     0,     0,     0,     0,   482,
       0,   316,   317,   318,   319,     0,   320,   321,   322,   323,
     185,     0,     0,   186,   187,   188,     0,     0,     0,     0,
     483,   316,   317,   318,   319,     0,   320,   321,   322,   323,
     185,     0,     0,   186,   187,   188,     0,     0,     0,   312,
     549,     0,   313,   314,   315,     0,     0,     0,   189,   190,
     191,     0,     0,     0,     0,   312,     0,     0,   313,   314,
     315,   277,   263,   264,   265,   266,   267,     0,   189,   190,
     191,   316,   317,   318,   319,     0,   320,   321,   322,   323,
     312,   533,     0,   313,   314,   315,   428,   316,   317,   318,
     319,     0,   320,   321,   322,   323,   312,     0,     0,   313,
     314,   315,   506,     0,     0,   312,     0,     0,   313,   314,
     315,     0,   316,   317,   318,   319,     0,   320,   321,   322,
     323,   312,     0,     0,   313,   314,   315,   536,   316,   317,
     318,   319,     0,   320,   321,   322,   323,   316,   317,   318,
     319,   413,   320,   321,   322,   323,     0,     0,     0,     0,
     414,     0,     0,   316,   317,   318,   319,     0,   320,   321,
     322,   323,     0,     0,   312,     0,   415,   313,   314,   315,
       0,     0,     0,   312,     0,     0,   313,   314,   315,     0,
     312,     0,     0,   313,   314,   315,   150,   151,   152,   153,
     154,   155,   156,   157,     0,   158,   316,   317,   318,   319,
       0,   320,   321,   322,   323,   316,   317,   318,   319,   419,
     320,   321,   322,   323,   318,   319,     0,   320,   321,   322,
     323,   150,   151,   152,   153,   154,   155,   156,   157
};

static const yytype_int16 yycheck[] =
{
     143,   127,   429,   226,    20,    78,   225,    71,   347,   135,
     339,   275,     3,     4,   227,   163,   226,   258,     4,     3,
       4,   402,     3,     3,     4,    15,    71,   401,     3,    40,
      41,    16,     3,     4,    18,     3,   463,    18,    22,    30,
      31,   114,    26,    27,    28,     3,     4,    75,    74,    77,
      74,    35,    78,   396,    65,    20,    80,    68,    47,   185,
     186,   187,   188,   189,   190,   191,    82,    78,    58,   443,
     399,    60,   411,   412,   501,    86,   140,   141,    33,   292,
     293,   224,   292,     4,   227,     6,   350,    71,    79,     0,
      77,   472,    79,    79,    78,    79,    12,   240,   241,    79,
      72,   528,   529,   114,    79,   116,   117,   446,    79,    71,
     351,    79,   176,     4,    74,     6,    81,    82,   545,   130,
      80,    79,   133,   196,   467,   552,   469,    13,    74,    84,
      85,    33,    34,    71,    80,    56,    57,    10,    11,    25,
     283,   284,   285,   286,   287,   288,   289,   290,   371,   362,
     369,     4,   362,     6,    75,    74,    74,    76,    79,   372,
      14,   371,    80,   174,     9,    56,    57,    69,   311,   312,
     313,   314,   315,   316,   317,   318,   319,   320,   321,   322,
     323,   445,   325,   331,   394,   196,   396,    72,    79,   200,
     201,    32,    33,    34,     3,     4,    33,    34,     3,     4,
      33,    34,    10,    56,    57,    74,    74,    76,   421,    74,
      74,   421,    80,    18,    74,    80,    80,    22,    33,    34,
      80,    26,    27,    28,     3,     4,    67,    68,    69,     7,
      35,    68,    69,   497,   498,    68,    69,     3,     4,     3,
       4,    29,   465,    72,    32,    33,    34,    33,    34,   513,
       3,     4,    18,     6,    69,   465,    22,   467,    72,   469,
      26,    27,    28,    32,    33,    34,    71,   159,   160,    35,
     413,   414,   415,    78,    79,   539,    73,    30,    31,    67,
      68,    69,    71,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    63,    64,    65,     3,    50,    67,    68,
      69,    33,    34,    56,    57,    71,     3,     4,    19,     6,
      33,    34,    78,    79,   457,     7,    29,    70,   461,    32,
      33,    34,    75,     7,    77,    29,    79,    82,    32,    33,
      34,    82,    79,    30,    31,    67,    68,    69,    79,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    79,
      23,     3,     4,    50,    67,    68,    69,    81,     4,    56,
      57,   504,    66,    67,    68,    69,    18,    80,     8,     8,
      22,     3,     4,    70,    26,    27,    28,   520,    75,    74,
      77,    76,    79,    35,    71,     4,    18,     6,   514,    18,
      22,     3,     4,     3,    26,    27,    28,    74,    11,    76,
     543,    10,    74,    35,    76,    20,    18,    77,     3,    79,
      22,    30,    31,    20,    26,    27,    28,     3,     4,    71,
      20,    79,     3,    35,    79,    79,    78,    79,    79,     3,
       4,    50,    18,    23,    79,     3,    22,    56,    57,    71,
      26,    27,    28,    20,    18,    72,    78,    79,    22,    35,
       3,     4,    26,    27,    28,    20,    75,    17,    77,    71,
      79,    35,     4,     3,     6,    18,    78,    79,    20,    22,
      23,     3,    21,    26,    27,    28,    61,    62,    63,    64,
      65,    74,    35,    80,    80,    71,     3,    81,    30,    31,
      20,    23,    78,    79,    26,    27,    28,    71,    20,     3,
      50,    79,    73,    35,     9,    79,    23,    77,    50,    26,
      27,    28,    75,     4,    56,    57,    73,     3,    35,    23,
       3,    20,    26,    27,    28,    79,    79,    59,    21,    21,
      77,    35,    21,    75,    80,    77,    80,    79,    79,    71,
      23,    79,    59,    26,    27,    28,    78,    11,     3,    74,
      79,    79,    35,    79,    71,    59,    79,    75,     3,    79,
      29,    78,    74,    32,    33,    34,    79,    71,    23,     3,
      80,    26,    27,    28,    78,    34,    59,    74,    23,    79,
      35,    26,    27,    28,    79,     3,    33,    34,    71,    23,
      35,    79,    26,    27,    28,    78,    77,    21,    67,    68,
      69,    35,    21,    74,    59,    23,    76,    74,    26,    27,
      28,    80,    74,    74,    59,    75,    71,    35,    74,    77,
      67,    68,    69,    78,    29,    59,    71,    32,    33,    34,
      74,    74,    73,    78,     3,    74,    82,    71,    75,    79,
      75,    59,    80,    79,    78,    29,    79,    34,    32,    33,
      34,    77,     4,    71,    76,    80,    61,    62,    63,    64,
      77,    66,    67,    68,    69,    29,    74,    80,    32,    33,
      34,    80,    25,    80,    78,    80,    72,    61,    62,    63,
      64,    80,    66,    67,    68,    69,    29,    75,    79,    32,
      33,    34,    75,    82,    76,    80,    80,    61,    62,    63,
      64,    77,    66,    67,    68,    69,    29,    80,    80,    32,
      33,    34,     5,    24,    77,    77,    80,    58,    61,    62,
      63,    64,    73,    66,    67,    68,    69,    29,    77,    77,
      32,    33,    34,    80,     4,    75,    24,    80,    61,    62,
      63,    64,    77,    66,    67,    68,    69,    29,    77,    20,
      32,    33,    34,    19,   109,    62,   332,    80,   443,    61,
      62,    63,    64,   336,    66,    67,    68,    69,    29,    86,
     138,    32,    33,    34,   329,   367,    -1,   421,    80,    61,
      62,    63,    64,    -1,    66,    67,    68,    69,    29,   369,
      -1,    32,    33,    34,    -1,    -1,    -1,    -1,    80,    -1,
      61,    62,    63,    64,    -1,    66,    67,    68,    69,    29,
      -1,    -1,    32,    33,    34,    -1,    -1,    -1,    -1,    80,
      61,    62,    63,    64,    -1,    66,    67,    68,    69,    29,
      -1,    -1,    32,    33,    34,    -1,    -1,    -1,    -1,    80,
      -1,    61,    62,    63,    64,    -1,    66,    67,    68,    69,
      29,    -1,    -1,    32,    33,    34,    -1,    -1,    -1,    -1,
      80,    61,    62,    63,    64,    -1,    66,    67,    68,    69,
      29,    -1,    -1,    32,    33,    34,    -1,    -1,    -1,    29,
      80,    -1,    32,    33,    34,    -1,    -1,    -1,    67,    68,
      69,    -1,    -1,    -1,    -1,    29,    -1,    -1,    32,    33,
      34,    80,   180,   181,   182,   183,   184,    -1,    67,    68,
      69,    61,    62,    63,    64,    -1,    66,    67,    68,    69,
      29,    80,    -1,    32,    33,    34,    76,    61,    62,    63,
      64,    -1,    66,    67,    68,    69,    29,    -1,    -1,    32,
      33,    34,    76,    -1,    -1,    29,    -1,    -1,    32,    33,
      34,    -1,    61,    62,    63,    64,    -1,    66,    67,    68,
      69,    29,    -1,    -1,    32,    33,    34,    76,    61,    62,
      63,    64,    -1,    66,    67,    68,    69,    61,    62,    63,
      64,    74,    66,    67,    68,    69,    -1,    -1,    -1,    -1,
      74,    -1,    -1,    61,    62,    63,    64,    -1,    66,    67,
      68,    69,    -1,    -1,    29,    -1,    74,    32,    33,    34,
      -1,    -1,    -1,    29,    -1,    -1,    32,    33,    34,    -1,
      29,    -1,    -1,    32,    33,    34,    46,    47,    48,    49,
      50,    51,    52,    53,    -1,    55,    61,    62,    63,    64,
      -1,    66,    67,    68,    69,    61,    62,    63,    64,    74,
      66,    67,    68,    69,    63,    64,    -1,    66,    67,    68,
      69,    46,    47,    48,    49,    50,    51,    52,    53
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
     140,   142,   144,   146,   192,    73,    10,    11,    98,    99,
      19,   108,   109,     7,     7,    82,   127,   127,    82,     3,
      79,    79,    79,    13,    25,     3,   121,   125,    79,   121,
     123,    23,   131,    81,     3,    18,   116,    26,    27,    28,
      35,    59,    71,   169,   171,   172,   173,   181,   184,   187,
     190,   193,   194,   195,     4,     8,     8,    71,    18,   100,
     101,     3,   116,   108,    79,   121,    20,    20,   121,   141,
       3,   139,   139,     3,     4,    30,    31,    79,   134,   135,
      74,    80,   125,    20,   124,    79,   127,   127,   123,     3,
      79,    79,    79,    79,    15,    58,    23,   174,     3,   167,
      46,    47,    48,    49,    50,    51,    52,    53,    55,   148,
     149,   168,    72,    20,    20,    17,     3,   101,     3,    79,
     111,   125,   121,   121,    20,    21,    74,    80,    80,   135,
      61,    62,    63,    64,    65,    29,    32,    33,    34,    67,
      68,    69,    80,   121,    81,    80,    79,   121,   128,   135,
      20,    20,   124,   182,   139,   139,     3,     4,     6,    30,
      31,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    50,    56,    57,    70,    75,    77,    79,   147,   151,
     153,   154,   159,   161,   162,   164,   166,   166,   170,    50,
      79,    73,    75,   167,   167,     9,    95,   159,     4,    96,
      97,    73,     3,   112,    20,   113,    80,   121,    79,   139,
      21,    21,    80,   134,   134,   134,   134,   134,   135,   135,
     135,   135,   135,   135,   135,    77,   125,    80,   121,   121,
      21,    80,    80,    79,    79,    79,    79,    79,    79,    79,
      79,   166,    75,    79,   155,   156,   161,   163,     4,     6,
      56,    57,   152,   153,   160,     4,     6,    56,    57,   152,
     166,    75,    29,    32,    33,    34,    61,    62,    63,    64,
      66,    67,    68,    69,    80,    74,    80,   166,   166,   150,
      11,    74,    74,    75,    77,   102,    74,    80,     3,    79,
     114,   110,     3,     4,   136,   137,    79,    79,   117,    80,
      77,    79,    21,    21,   166,   166,   166,   166,   166,   166,
     166,   166,    75,   152,   153,   157,   158,    74,    76,    74,
      76,    74,    74,    80,   166,   166,   166,   166,   166,   166,
     166,   166,   166,   166,   166,   166,   166,    77,   166,    80,
     148,    73,   159,    97,    75,   103,    79,   104,   112,    74,
     114,    75,    82,    80,   137,   138,   138,    71,    78,   117,
     137,    79,    79,    74,    74,    74,    80,    80,    80,    74,
      80,    74,    76,   156,    75,   163,   160,   152,    76,   191,
      77,    76,     4,   105,   160,    74,    76,   105,    74,    78,
     114,    80,   115,   119,   136,    77,    74,    80,    80,    78,
      80,   138,   138,   166,   166,   166,     4,    79,   158,    78,
      80,    75,   192,   175,    72,    74,    76,    75,    80,    79,
      76,   115,    82,   117,   138,   143,   145,   132,    77,    80,
      80,    80,    80,    80,    80,   165,   166,   166,    71,    78,
     192,     5,   160,   105,   105,   136,    78,    77,    77,    24,
     133,   183,   185,   188,    74,    80,    76,    78,    73,    76,
      80,   117,   117,    77,    79,   192,    77,    77,   166,    80,
      75,   176,     4,    78,    78,   117,   135,    78,   186,   189,
     166,   177,    78,    80,   192,   192,    76,    24,   179,    77,
      78,    78,    77,    79,   117,   180,   166,    78,   192,    80,
      78,    77,   178,   192,    78
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
     148,   148,   148,   148,   148,   148,   148,   148,   150,   149,
     151,   151,   152,   152,   152,   152,   153,   154,   155,   155,
     156,   157,   157,   158,   158,   159,   160,   160,   161,   161,
     161,   161,   161,   161,   161,   161,   161,   162,   163,   163,
     164,   164,   164,   164,   164,   164,   164,   164,   164,   165,
     165,   166,   166,   166,   166,   166,   166,   166,   166,   166,
     166,   166,   166,   166,   166,   166,   166,   166,   166,   166,
     166,   166,   167,   168,   168,   169,   170,   170,   171,   173,
     172,   172,   172,   172,   172,   175,   176,   174,   178,   177,
     177,   180,   179,   179,   182,   183,   181,   185,   186,   184,
     188,   189,   187,   191,   190,   192,   192,   193,   193,   193,
     194,   193,   195,   193
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
       1,     1,     1,     1,     1,     1,     1,     1,     0,     5,
       1,     1,     1,     1,     1,     1,     5,     3,     3,     1,
       3,     3,     1,     1,     1,     5,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     3,     1,
       6,     6,     6,     4,     4,     6,     8,     4,     4,     3,
       1,     1,     1,     1,     4,     7,    10,     1,     3,     2,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     2,     2,     4,     3,     1,     3,     0,
       2,     1,     1,     1,     1,     0,     0,    11,     0,     9,
       0,     0,     5,     0,     0,     0,    11,     0,     0,    13,
       0,     0,    13,     0,     8,     2,     0,     1,     1,     1,
       0,     2,     0,     2
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
                                                                   {fprintf(fp,"\nParsing successful!\n");}
#line 1802 "./exec/y.tab.c"
    break;

  case 3: /* $@1: %empty  */
#line 90 "./Parser/parser_main.y"
                                           {fprintf(fp,"\nInit section begins\n\n");}
#line 1808 "./exec/y.tab.c"
    break;

  case 4: /* init_section: '\\' INIT_BEGIN $@1 mandatory_init set_states block_defn_section gate_defn_section '\\' INIT_END  */
#line 90 "./Parser/parser_main.y"
                                                                                                                                                                   {fprintf(fp,"\nInit section ends\n");}
#line 1814 "./exec/y.tab.c"
    break;

  case 5: /* $@2: %empty  */
#line 93 "./Parser/parser_main.y"
                                            {fprintf(fp,"\nMain section begins\n\n");}
#line 1820 "./exec/y.tab.c"
    break;

  case 6: /* main_section: '\\' MAIN_BEGIN $@2 main_stmt_list '\\' MAIN_END  */
#line 93 "./Parser/parser_main.y"
                                                                                                                    {fprintf(fp,"\nMain section ends\n");}
#line 1826 "./exec/y.tab.c"
    break;

  case 7: /* $@3: %empty  */
#line 96 "./Parser/parser_main.y"
                                             {fprintf(fp,"\nOutput section begins\n\n"); isInOutput = true; outputLevel = 1;}
#line 1832 "./exec/y.tab.c"
    break;

  case 8: /* output_section: '\\' OUTPUT_BEGIN $@3 out_main '\\' OUTPUT_END  */
#line 96 "./Parser/parser_main.y"
                                                                                                                                                        {fprintf(fp,"\nOutput section ends\n");exitOutputSymbolScope(&OutputSymbolTable,outputLevel);}
#line 1838 "./exec/y.tab.c"
    break;

  case 9: /* mandatory_init: '#' REGISTERS QUANTUM '=' NUMBER '#' REGISTERS CLASSICAL '=' NUMBER '#' ITERS '=' NUMBER  */
#line 104 "./Parser/parser_main.y"
                                                                                                                    {  fprintf(fp,"Register and iteration initialization section\n");classical_registers = yyvsp[-4].num;quantum_registers = yyvsp[-9].num;iterations = yyvsp[0].num;}
#line 1844 "./exec/y.tab.c"
    break;

  case 15: /* set_quantum_states: '#' SET QUANTUM STATES ARROW quantum_state_list  */
#line 115 "./Parser/parser_main.y"
                                                                            {fprintf(fp,"Setting initial state of quantum registers\n");}
#line 1850 "./exec/y.tab.c"
    break;

  case 16: /* set_classical_states: '#' SET CLASSICAL STATES ARROW classical_state_list  */
#line 118 "./Parser/parser_main.y"
                                                                                {fprintf(fp,"Setting initial state of classical registers\n");}
#line 1856 "./exec/y.tab.c"
    break;

  case 17: /* quantum_state_list: quantum_state_list ',' state_const  */
#line 121 "./Parser/parser_main.y"
                                                                     {  if(quantum_index == quantum_registers){
                                                                           yyerror("semantic error: quantum registers out of bounds");
                                                                           return 1;
                                                                        }  
                                                                        quantum_states[quantum_index++] = yyvsp[0].q;
                                                                     }
#line 1867 "./exec/y.tab.c"
    break;

  case 18: /* quantum_state_list: state_const  */
#line 127 "./Parser/parser_main.y"
                                                                     {  quantum_states = (struct Quantum*)malloc(sizeof(struct Quantum)*quantum_registers);
                                                                        quantum_states[quantum_index++] = yyvsp[0].q;
                                                                     }
#line 1875 "./exec/y.tab.c"
    break;

  case 19: /* classical_state_list: classical_state_list ',' classical_state  */
#line 132 "./Parser/parser_main.y"
                                                                     { if(classical_index == classical_registers){
                                                                           yyerror("semantic error: classical registers out of bounds");
                                                                           return 1;
                                                                        }
                                                                        classical_states[classical_index++] = yyvsp[0].num;
                                                                     }
#line 1886 "./exec/y.tab.c"
    break;

  case 20: /* classical_state_list: classical_state  */
#line 138 "./Parser/parser_main.y"
                                                                     {  classical_states = (int *)malloc(sizeof(int)*classical_registers);
                                                                        classical_states[classical_index++] = yyvsp[0].num;
                                                                     }
#line 1894 "./exec/y.tab.c"
    break;

  case 21: /* classical_state: NUMBER  */
#line 143 "./Parser/parser_main.y"
                                                                     {yyval.num = yyvsp[0].num;}
#line 1900 "./exec/y.tab.c"
    break;

  case 22: /* $@4: %empty  */
#line 147 "./Parser/parser_main.y"
                           {fprintf(fp,"Gate definition section begins\n");}
#line 1906 "./exec/y.tab.c"
    break;

  case 23: /* gate_defn_section: $@4 gate_defn_list  */
#line 147 "./Parser/parser_main.y"
                                                                                            {fprintf(fp,"Gate definition section ends\n");}
#line 1912 "./exec/y.tab.c"
    break;

  case 27: /* gate_defn: GATE ID '=' rhs  */
#line 155 "./Parser/parser_main.y"
                                             {  fprintf(fp,"Gate definition\n");
                                                if(!insertInGateTable(&GateSymbolTable,yyvsp[-2].str,yyvsp[0].rows,yyvsp[0].cols)){
                                                   yyerror("semantic error: gate definition requires square matrix");
                                                   return 1;
                                                }
                                             }
#line 1923 "./exec/y.tab.c"
    break;

  case 28: /* rhs: '[' tuple_list ']'  */
#line 163 "./Parser/parser_main.y"
                                                {yyval.rows = yyvsp[-1].rows;yyval.cols = yyvsp[-1].cols;}
#line 1929 "./exec/y.tab.c"
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
#line 1942 "./exec/y.tab.c"
    break;

  case 31: /* tuple_list: '[' id_list ']'  */
#line 174 "./Parser/parser_main.y"
                                                         {yyval.rows = 1;yyval.cols = yyvsp[-1].cols;}
#line 1948 "./exec/y.tab.c"
    break;

  case 34: /* id_list: id_list ',' temp  */
#line 179 "./Parser/parser_main.y"
                                             {yyval.cols += 1;}
#line 1954 "./exec/y.tab.c"
    break;

  case 35: /* id_list: temp  */
#line 180 "./Parser/parser_main.y"
                                             {yyval.cols = 1;}
#line 1960 "./exec/y.tab.c"
    break;

  case 36: /* $@5: %empty  */
#line 183 "./Parser/parser_main.y"
                           {fprintf(fp,"Block definition section begins\n");}
#line 1966 "./exec/y.tab.c"
    break;

  case 37: /* block_defn_section: $@5 block_defns_list  */
#line 183 "./Parser/parser_main.y"
                                                                                               {fprintf(fp,"Block definition section ends\n");}
#line 1972 "./exec/y.tab.c"
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
#line 1984 "./exec/y.tab.c"
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
#line 1997 "./exec/y.tab.c"
    break;

  case 42: /* params: ID  */
#line 207 "./Parser/parser_main.y"
                                                {insertInList(&head,yyvsp[0].str);yyval.num = 1;}
#line 2003 "./exec/y.tab.c"
    break;

  case 43: /* params: '(' param_id_list ')'  */
#line 208 "./Parser/parser_main.y"
                                                {yyval.num = yyvsp[-1].num;}
#line 2009 "./exec/y.tab.c"
    break;

  case 44: /* param_id_list: ID ',' param_id_list  */
#line 211 "./Parser/parser_main.y"
                                                {insertInList(&head,yyvsp[-2].str);yyval.num = 1 + yyvsp[0].num;}
#line 2015 "./exec/y.tab.c"
    break;

  case 45: /* param_id_list: ID  */
#line 212 "./Parser/parser_main.y"
                                                {insertInList(&head,yyvsp[0].str);yyval.num = 1;}
#line 2021 "./exec/y.tab.c"
    break;

  case 53: /* block_id: ID  */
#line 228 "./Parser/parser_main.y"
                                 {  if(!firstLetterCapital(yyvsp[0].str)){
                                       yyerror("lexical error: block identifiers start with uppercase letter");
                                       return 1;
                                    } 
                                    assignString(yyval.str,yyvsp[0].str);
                                 }
#line 2032 "./exec/y.tab.c"
    break;

  case 57: /* main_stmt: barrier_stmt  */
#line 246 "./Parser/parser_main.y"
                                          {fprintf(fp,"barrier statement\n");}
#line 2038 "./exec/y.tab.c"
    break;

  case 59: /* stmts: measure_stmt  */
#line 249 "./Parser/parser_main.y"
                                          {fprintf(fp,"Measure statement\n");}
#line 2044 "./exec/y.tab.c"
    break;

  case 60: /* $@7: %empty  */
#line 250 "./Parser/parser_main.y"
                          {fprintf(fp,"Conditional statement begin\n");}
#line 2050 "./exec/y.tab.c"
    break;

  case 61: /* stmts: $@7 condition_stmt  */
#line 250 "./Parser/parser_main.y"
                                                                                        {fprintf(fp,"Conditional statement end\n");}
#line 2056 "./exec/y.tab.c"
    break;

  case 62: /* stmts: for_stmt  */
#line 251 "./Parser/parser_main.y"
                                          {fprintf(fp,"For statement\n");}
#line 2062 "./exec/y.tab.c"
    break;

  case 63: /* stmts: for_lex_stmt  */
#line 252 "./Parser/parser_main.y"
                                          {fprintf(fp,"For - Lex statement\n");}
#line 2068 "./exec/y.tab.c"
    break;

  case 64: /* stmts: for_zip_stmt  */
#line 253 "./Parser/parser_main.y"
                                          {fprintf(fp,"For - Zip statement\n");}
#line 2074 "./exec/y.tab.c"
    break;

  case 65: /* stmts: while_stmt  */
#line 254 "./Parser/parser_main.y"
                                          {fprintf(fp,"while statement\n");}
#line 2080 "./exec/y.tab.c"
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
#line 2092 "./exec/y.tab.c"
    break;

  case 67: /* register: ID  */
#line 264 "./Parser/parser_main.y"
                                  {if(isInBlock){insertInList(&id_list,yyvsp[0].str);}yyval.flag = 1;}
#line 2098 "./exec/y.tab.c"
    break;

  case 68: /* call_stmt: classic_control GATE quantum_control ARROW register  */
#line 269 "./Parser/parser_main.y"
                                                                              {fprintf(fp,"Pre - defined Gate call statement\n");}
#line 2104 "./exec/y.tab.c"
    break;

  case 69: /* call_stmt: classic_control ID quantum_control ARROW register  */
#line 270 "./Parser/parser_main.y"
                                                                              {fprintf(fp,"user - defined Gate call statement\n");}
#line 2110 "./exec/y.tab.c"
    break;

  case 70: /* call_stmt: GATE quantum_control ARROW register  */
#line 271 "./Parser/parser_main.y"
                                                                              {fprintf(fp,"Pre - defined Gate call statement\n");}
#line 2116 "./exec/y.tab.c"
    break;

  case 71: /* call_stmt: ID quantum_control ARROW register  */
#line 272 "./Parser/parser_main.y"
                                                                              {fprintf(fp,"User - defined Gate call statement\n");}
#line 2122 "./exec/y.tab.c"
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
#line 2135 "./exec/y.tab.c"
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
#line 2148 "./exec/y.tab.c"
    break;

  case 74: /* parameters: register  */
#line 291 "./Parser/parser_main.y"
                                                   {yyval.num = 1;}
#line 2154 "./exec/y.tab.c"
    break;

  case 75: /* parameters: '(' register_list ')'  */
#line 292 "./Parser/parser_main.y"
                                                   {yyval.num = yyvsp[-1].num;}
#line 2160 "./exec/y.tab.c"
    break;

  case 78: /* register_list: register_list ',' register  */
#line 299 "./Parser/parser_main.y"
                                                      {yyval.num = 1 + yyvsp[-2].num;}
#line 2166 "./exec/y.tab.c"
    break;

  case 79: /* register_list: register  */
#line 300 "./Parser/parser_main.y"
                                                      {yyval.num = 1;}
#line 2172 "./exec/y.tab.c"
    break;

  case 87: /* measure_stmt: MEASURE ':' register ARROW register  */
#line 327 "./Parser/parser_main.y"
                                                              {
                           if((!yyvsp[-2].flag && (yyvsp[-2].num < 0 || yyvsp[-2].num >= quantum_registers)) || (!yyvsp[0].flag && (yyvsp[0].num < 0 || yyvsp[0].num >= classical_registers))){
                              yyerror("semantic error: register number out of bounds"); 
                              return 1;
                           }
                        }
#line 2183 "./exec/y.tab.c"
    break;

  case 112: /* value: NUMBER  */
#line 372 "./Parser/parser_main.y"
                                             {yyval.str = IntToString(yyvsp[0].num);}
#line 2189 "./exec/y.tab.c"
    break;

  case 113: /* value: ID  */
#line 373 "./Parser/parser_main.y"
                                             {yyval.str = yyvsp[0].str;}
#line 2195 "./exec/y.tab.c"
    break;

  case 114: /* range: value ':' value  */
#line 376 "./Parser/parser_main.y"
                                             {yyval.start = IntToString(yyvsp[-2].num); yyval.end = IntToString(yyvsp[0].num); yyval.step = IntToString(1);}
#line 2201 "./exec/y.tab.c"
    break;

  case 115: /* range: value ':' value ':' value  */
#line 377 "./Parser/parser_main.y"
                                                      {yyval.start = IntToString(yyvsp[-4].num); yyval.end = IntToString(yyvsp[-2].num); yyval.step = IntToString(yyvsp[0].num);}
#line 2207 "./exec/y.tab.c"
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
#line 2220 "./exec/y.tab.c"
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
#line 2233 "./exec/y.tab.c"
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
                                                   insertInList(&head,yyvsp[-2].str);
                                                } 
                                                else {
                                                   yyerror("semantic error: loop variable redeclaration");
                                                   return 1;
                                                } 
                                                yyval.num = 1 + yyvsp[0].num;
                                             }
#line 2253 "./exec/y.tab.c"
    break;

  case 119: /* var_list: ID  */
#line 413 "./Parser/parser_main.y"
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
#line 2273 "./exec/y.tab.c"
    break;

  case 120: /* $@8: %empty  */
#line 430 "./Parser/parser_main.y"
                                 {  if(!inList(&head,yyvsp[0].str)){
                                       insertInList(&head,yyvsp[0].str);
                                    } 
                                    else{
                                       yyerror("semantic error: loop variable redeclaration"); 
                                       return 1;
                                    }
                                 }
#line 2286 "./exec/y.tab.c"
    break;

  case 121: /* for_stmt: FOR ID $@8 IN '(' range ')' '{' main_stmt_list '}'  */
#line 438 "./Parser/parser_main.y"
                                                                  {removeTopKFromList(&head,1);}
#line 2292 "./exec/y.tab.c"
    break;

  case 122: /* $@9: %empty  */
#line 441 "./Parser/parser_main.y"
                                                                         { if(yyvsp[-5].num != yyvsp[-1].num){
                                                                              yyerror("semantic error: mismatch in loop variables and ranges"); 
                                                                              return 1;
                                                                           }
                                                                         }
#line 2302 "./exec/y.tab.c"
    break;

  case 123: /* for_lex_stmt: FOR_LEX '(' var_list ')' IN '(' range_list ')' $@9 '{' main_stmt_list '}'  */
#line 446 "./Parser/parser_main.y"
                                                 {removeTopKFromList(&head,yyvsp[-9].num);}
#line 2308 "./exec/y.tab.c"
    break;

  case 124: /* $@10: %empty  */
#line 449 "./Parser/parser_main.y"
                                                                         { if(yyvsp[-5].num != yyvsp[-1].num){
                                                                              yyerror("semantic error: mismatch in loop variables and ranges"); 
                                                                              return 1;
                                                                           }
                                                                         }
#line 2318 "./exec/y.tab.c"
    break;

  case 125: /* for_zip_stmt: FOR_ZIP '(' var_list ')' IN '(' range_list ')' $@10 '{' main_stmt_list '}'  */
#line 454 "./Parser/parser_main.y"
                                                 {removeTopKFromList(&head,yyvsp[-9].num);}
#line 2324 "./exec/y.tab.c"
    break;

  case 127: /* out_id: ID  */
#line 466 "./Parser/parser_main.y"
                               {yyval.out_flag = 0; yyval.str = yyvsp[0].str;}
#line 2330 "./exec/y.tab.c"
    break;

  case 128: /* out_id: COUT  */
#line 467 "./Parser/parser_main.y"
                               {yyval.out_flag = 1; yyval.type = Int; yyval.prim = false; yyval.dim = (1 << classical_registers); yyval.rows = 0;yyval.str = yyvsp[0].str;}
#line 2336 "./exec/y.tab.c"
    break;

  case 129: /* out_id: QOUT  */
#line 468 "./Parser/parser_main.y"
                               {yyval.out_flag = 2; yyval.type = State; yyval.prim = false; yyval.dim = quantum_registers; yyval.rows = 0;yyval.str = yyvsp[0].str;}
#line 2342 "./exec/y.tab.c"
    break;

  case 130: /* prim_type: INT  */
#line 471 "./Parser/parser_main.y"
                                    {yyval.type = Int; yyval.prim = true;fprintf(out,"int ");}
#line 2348 "./exec/y.tab.c"
    break;

  case 131: /* prim_type: UINT  */
#line 472 "./Parser/parser_main.y"
                                    {yyval.type = Uint; yyval.prim = true;fprintf(out,"unsigned int ");}
#line 2354 "./exec/y.tab.c"
    break;

  case 132: /* prim_type: FLOAT  */
#line 473 "./Parser/parser_main.y"
                                    {yyval.type = Float; yyval.prim = true;fprintf(out,"float ");}
#line 2360 "./exec/y.tab.c"
    break;

  case 133: /* prim_type: COMPLEX  */
#line 474 "./Parser/parser_main.y"
                                    {yyval.type = Complex; yyval.prim = true;fprintf(out,"Complex ");}
#line 2366 "./exec/y.tab.c"
    break;

  case 134: /* prim_type: STRING  */
#line 475 "./Parser/parser_main.y"
                                    {yyval.type = String; yyval.prim = true;fprintf(out,"string ");}
#line 2372 "./exec/y.tab.c"
    break;

  case 135: /* prim_type: MATRIX  */
#line 476 "./Parser/parser_main.y"
                                    {yyval.type = Matrix; yyval.prim = true;fprintf(out,"Matrix ");}
#line 2378 "./exec/y.tab.c"
    break;

  case 136: /* prim_type: STATE  */
#line 477 "./Parser/parser_main.y"
                                    {yyval.type = State; yyval.prim = true;fprintf(out,"StateVec ");}
#line 2384 "./exec/y.tab.c"
    break;

  case 137: /* prim_type: BOOL  */
#line 478 "./Parser/parser_main.y"
                                    {yyval.type = Bool; yyval.prim = true;fprintf(out,"bool ");}
#line 2390 "./exec/y.tab.c"
    break;

  case 138: /* @11: %empty  */
#line 481 "./Parser/parser_main.y"
                                   {fprintf(out,"list[");}
#line 2396 "./exec/y.tab.c"
    break;

  case 139: /* list_type: LIST '[' @11 prim_type ']'  */
#line 481 "./Parser/parser_main.y"
                                                                         {yyval.type = yyvsp[-2].type; yyval.prim = false;fprintf(out,"]");}
#line 2402 "./exec/y.tab.c"
    break;

  case 140: /* bool_const: TRUE  */
#line 488 "./Parser/parser_main.y"
                                    {yyval.num = 1;}
#line 2408 "./exec/y.tab.c"
    break;

  case 141: /* bool_const: FALSE  */
#line 489 "./Parser/parser_main.y"
                                    {yyval.num = 0;}
#line 2414 "./exec/y.tab.c"
    break;

  case 142: /* num: DEC  */
#line 492 "./Parser/parser_main.y"
                                    {yyval.real = yyvsp[0].real;}
#line 2420 "./exec/y.tab.c"
    break;

  case 143: /* num: NEG  */
#line 493 "./Parser/parser_main.y"
                                    {yyval.real = yyvsp[0].real;}
#line 2426 "./exec/y.tab.c"
    break;

  case 144: /* num: EXP  */
#line 494 "./Parser/parser_main.y"
                                    {yyval.real = yyvsp[0].real;}
#line 2432 "./exec/y.tab.c"
    break;

  case 145: /* num: NUMBER  */
#line 495 "./Parser/parser_main.y"
                                    {yyval.real = yyvsp[0].num;}
#line 2438 "./exec/y.tab.c"
    break;

  case 146: /* complex_const: '(' num ',' num ')'  */
#line 497 "./Parser/parser_main.y"
                                                   {yyval.cpx.real = yyvsp[-3].real; yyval.cpx.imag = yyvsp[-1].real;}
#line 2444 "./exec/y.tab.c"
    break;

  case 147: /* matrix_const: '[' row_list ']'  */
#line 500 "./Parser/parser_main.y"
                                                   { if(yyvsp[-1].rows == yyvsp[-1].cols) {
                                                         yyval.rows = yyvsp[-1].rows;
                                                     } 
                                                     else{
                                                         yyerror("semantic error: only square matrices permitted"); 
                                                         return 1;
                                                     }
                                                   }
#line 2457 "./exec/y.tab.c"
    break;

  case 148: /* row_list: row_list ',' row  */
#line 510 "./Parser/parser_main.y"
                                                   {  yyval.rows = yyvsp[-2].rows + 1; 
                                                      if(yyvsp[-2].cols == yyvsp[0].cols){
                                                         yyval.cols = yyvsp[-2].cols;
                                                      } 
                                                      else{
                                                         yyerror("semantic error: rows of different length cannot form matrix"); 
                                                         return 1;
                                                      }
                                                   }
#line 2471 "./exec/y.tab.c"
    break;

  case 149: /* row_list: row  */
#line 519 "./Parser/parser_main.y"
                                                      {yyval.rows = 1; yyval.cols = yyvsp[0].cols;}
#line 2477 "./exec/y.tab.c"
    break;

  case 150: /* row: '[' comps ']'  */
#line 522 "./Parser/parser_main.y"
                                                      {yyval.cols = yyvsp[-1].cols;}
#line 2483 "./exec/y.tab.c"
    break;

  case 151: /* comps: comps ',' compatible_const  */
#line 525 "./Parser/parser_main.y"
                                                      {yyval.cols = yyvsp[-2].cols + 1;}
#line 2489 "./exec/y.tab.c"
    break;

  case 152: /* comps: compatible_const  */
#line 526 "./Parser/parser_main.y"
                                                      {yyval.cols = 1;}
#line 2495 "./exec/y.tab.c"
    break;

  case 155: /* state_const: '{' temp ',' temp '}'  */
#line 533 "./Parser/parser_main.y"
                                                      {yyval.q.first = yyvsp[-3].cpx; yyval.q.second = yyvsp[-1].cpx;}
#line 2501 "./exec/y.tab.c"
    break;

  case 156: /* temp: complex_const  */
#line 536 "./Parser/parser_main.y"
                                                      {yyval.cpx = yyvsp[0].cpx;}
#line 2507 "./exec/y.tab.c"
    break;

  case 157: /* temp: num  */
#line 537 "./Parser/parser_main.y"
                                                      {yyval.cpx.real = yyvsp[0].real; yyval.cpx.imag = 0;}
#line 2513 "./exec/y.tab.c"
    break;

  case 158: /* prim_const: bool_const  */
#line 540 "./Parser/parser_main.y"
                                          {  yyval.type = Bool;
                                             yyval.str = (char *)malloc(sizeof(char)*6);
                                             if(yyval.num)snprintf(yyval.str,6,"true");
                                             else snprintf(yyval.str,6,"false");
                                          }
#line 2523 "./exec/y.tab.c"
    break;

  case 159: /* prim_const: complex_const  */
#line 545 "./Parser/parser_main.y"
                                          {  yyval.type = Complex;
                                             yyval.str = (char *)malloc(sizeof(char)*20);yyval.str = yyvsp[0].str;
                                             snprintf(yyval.str,20,"Complex(%f,%f)",yyvsp[0].cpx.real,yyvsp[0].cpx.imag);
                                          }
#line 2532 "./exec/y.tab.c"
    break;

  case 160: /* prim_const: matrix_const  */
#line 549 "./Parser/parser_main.y"
                                          {  yyval.type = Matrix; 
                                             yyval.rows = yyvsp[0].rows;
                                             yyval.str = (char *)malloc(sizeof(char)*20);
                                             snprintf(yyval.str,15,"Matrix(%d)",yyvsp[0].rows);
                                          }
#line 2542 "./exec/y.tab.c"
    break;

  case 161: /* prim_const: state_const  */
#line 554 "./Parser/parser_main.y"
                                          {yyval.type = State;}
#line 2548 "./exec/y.tab.c"
    break;

  case 162: /* prim_const: NUMBER  */
#line 555 "./Parser/parser_main.y"
                                          {yyval.type = Uint;yyval.str = (char *)malloc(sizeof(char)*20);snprintf(yyval.str,20,"%d",yyvsp[0].num);}
#line 2554 "./exec/y.tab.c"
    break;

  case 163: /* prim_const: NEG  */
#line 556 "./Parser/parser_main.y"
                                          {yyval.type = Int;yyval.str = (char *)malloc(sizeof(char)*20);snprintf(yyval.str,20,"%d",yyvsp[0].num);}
#line 2560 "./exec/y.tab.c"
    break;

  case 164: /* prim_const: DEC  */
#line 557 "./Parser/parser_main.y"
                                          {yyval.type = Float;yyval.str = (char *)malloc(sizeof(char)*20);snprintf(yyval.str,20,"%f",yyvsp[0].real);}
#line 2566 "./exec/y.tab.c"
    break;

  case 165: /* prim_const: EXP  */
#line 558 "./Parser/parser_main.y"
                                          {yyval.type = Float;yyval.str = (char *)malloc(sizeof(char)*20);snprintf(yyval.str,20,"%f",yyvsp[0].real);}
#line 2572 "./exec/y.tab.c"
    break;

  case 166: /* prim_const: STRING  */
#line 559 "./Parser/parser_main.y"
                                          {yyval.type = String;yyval.str = (char *)malloc(sizeof(char)*25);snprintf(yyval.str,25,"%s",yyvsp[0].str);}
#line 2578 "./exec/y.tab.c"
    break;

  case 167: /* vec_const: '[' vec_list ']'  */
#line 562 "./Parser/parser_main.y"
                                                {  yyval.dim = yyvsp[-1].dim; 
                                                   yyval.type = yyvsp[-1].type; 
                                                   if(yyval.type == Matrix){
                                                      yyval.rows = yyvsp[-1].rows;
                                                   } 
                                                   else{
                                                      yyval.rows = 0;
                                                   } 
                                                   // At this point head contains the list of IDs/constants used in list declaration
                                                   // Take values from here for codegen @Vedant
                                                   printList(&head);
                                                   yyval.str = (char *)malloc(sizeof(char)*(strlen(yyvsp[-1].str)+3));
                                                   snprintf(yyval.str,strlen(yyvsp[-1].str)+3,"[%s]",yyvsp[-1].str);
                                                   free(yyvsp[-1].str);
                                                }
#line 2598 "./exec/y.tab.c"
    break;

  case 168: /* vec_list: prim_const ',' vec_list  */
#line 579 "./Parser/parser_main.y"
                                                   {  temp_type = compatibleCheck(yyvsp[0].type, yyvsp[-2].type); 
                                                      if(temp_type != -1){
                                                         yyval.type = temp_type;
                                                      } 
                                                      else{
                                                         yyerror("semantic error: incompatible types in list"); 
                                                         return 1;
                                                      } 
                                                      yyval.dim = yyvsp[0].dim + 1; 
                                                      if(yyval.type == Matrix){
                                                         if(yyvsp[-2].rows != yyvsp[0].rows){
                                                            yyerror("semantic error: incompatible matrix dimensions in list");
                                                            return 1;
                                                         }
                                                         else{
                                                            yyval.rows = yyvsp[0].rows;
                                                         } 
                                                      }
                                                      insertInList(&head,yyvsp[-2].str);
                                                      yyval.str = (char *)malloc(sizeof(char)*(strlen(yyvsp[-2].str)+strlen(yyvsp[0].str)+2));
                                                      snprintf(yyval.str,strlen(yyvsp[-2].str)+strlen(yyvsp[0].str)+2,"%s,%s",yyvsp[0].str,yyvsp[-2].str);
                                                      free(yyvsp[-2].str);
                                                      free(yyvsp[0].str);
                                                   }
#line 2627 "./exec/y.tab.c"
    break;

  case 169: /* vec_list: prim_const  */
#line 603 "./Parser/parser_main.y"
                                                   {  yyval.type = yyvsp[0].type; yyval.dim = 1; 
                                                      if(yyval.type == Matrix){
                                                         yyval.rows = yyvsp[0].rows;
                                                      }
                                                      yyval.str = yyvsp[0].str;
                                                      head = NULL;
                                                      insertInList(&head,yyvsp[0].str);
                                                   }
#line 2640 "./exec/y.tab.c"
    break;

  case 170: /* calls: ADD '(' out_rhs ',' out_rhs ')'  */
#line 615 "./Parser/parser_main.y"
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
#line 2661 "./exec/y.tab.c"
    break;

  case 171: /* calls: SUB '(' out_rhs ',' out_rhs ')'  */
#line 632 "./Parser/parser_main.y"
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
#line 2682 "./exec/y.tab.c"
    break;

  case 172: /* calls: DOT '(' out_rhs ',' out_rhs ')'  */
#line 649 "./Parser/parser_main.y"
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
#line 2712 "./exec/y.tab.c"
    break;

  case 173: /* calls: STD_DEV '(' out_rhs ')'  */
#line 675 "./Parser/parser_main.y"
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
#line 2731 "./exec/y.tab.c"
    break;

  case 174: /* calls: VAR '(' out_rhs ')'  */
#line 690 "./Parser/parser_main.y"
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
#line 2750 "./exec/y.tab.c"
    break;

  case 175: /* calls: CONDENSE '(' out_rhs ',' NUMBER ')'  */
#line 705 "./Parser/parser_main.y"
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
#line 2769 "./exec/y.tab.c"
    break;

  case 176: /* calls: CONDENSE '(' out_rhs ',' '(' uint_list ')' ')'  */
#line 720 "./Parser/parser_main.y"
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
#line 2789 "./exec/y.tab.c"
    break;

  case 177: /* calls: SUM '(' out_rhs ')'  */
#line 736 "./Parser/parser_main.y"
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
#line 2808 "./exec/y.tab.c"
    break;

  case 178: /* calls: AVG '(' out_rhs ')'  */
#line 751 "./Parser/parser_main.y"
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
#line 2827 "./exec/y.tab.c"
    break;

  case 179: /* uint_list: uint_list ',' out_rhs  */
#line 770 "./Parser/parser_main.y"
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
#line 2844 "./exec/y.tab.c"
    break;

  case 180: /* uint_list: out_rhs  */
#line 782 "./Parser/parser_main.y"
                                                 { if(yyvsp[0].type <= Int){
                                                      yyval.cond_count = 1;
                                                   } 
                                                   else{
                                                      yyerror("semantic error: only integer elements permitted"); 
                                                      return 1;
                                                   }
                                                   yyval.str = yyvsp[0].str;
                                                 }
#line 2858 "./exec/y.tab.c"
    break;

  case 181: /* out_rhs: prim_const  */
#line 794 "./Parser/parser_main.y"
                                                { yyval.prim = true; yyval.type = yyvsp[0].type;yyval.str = yyvsp[0].str;}
#line 2864 "./exec/y.tab.c"
    break;

  case 182: /* out_rhs: vec_const  */
#line 795 "./Parser/parser_main.y"
                                                { yyval.prim = false; yyval.dim = yyvsp[0].dim; 
                                                  yyval.type = yyvsp[0].type; 
                                                  if(yyval.type == Matrix){
                                                      yyval.rows = yyvsp[0].rows;
                                                  } 
                                                  else yyval.rows = 0;
                                                  yyval.str = yyvsp[0].str;
                                                }
#line 2877 "./exec/y.tab.c"
    break;

  case 183: /* out_rhs: out_id  */
#line 803 "./Parser/parser_main.y"
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
#line 2912 "./exec/y.tab.c"
    break;

  case 184: /* out_rhs: out_id '[' out_rhs ']'  */
#line 833 "./Parser/parser_main.y"
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
#line 2960 "./exec/y.tab.c"
    break;

  case 185: /* out_rhs: out_id '[' out_rhs ']' '[' out_rhs ']'  */
#line 877 "./Parser/parser_main.y"
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
#line 3009 "./exec/y.tab.c"
    break;

  case 186: /* out_rhs: out_id '[' out_rhs ']' '[' out_rhs ']' '[' out_rhs ']'  */
#line 922 "./Parser/parser_main.y"
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
#line 3049 "./exec/y.tab.c"
    break;

  case 187: /* out_rhs: calls  */
#line 957 "./Parser/parser_main.y"
                                                   {  yyval.prim = yyvsp[0].prim; 
                                                      yyval.type = yyvsp[0].type; 
                                                      if(yyvsp[0].type == Matrix) yyval.rows = yyvsp[0].rows; 
                                                      if(!yyval.prim) yyval.dim = yyvsp[0].dim; 
                                                      printf("%d %d\n", yyval.prim, yyval.type);
                                                   }
#line 3060 "./exec/y.tab.c"
    break;

  case 188: /* out_rhs: '(' out_rhs ')'  */
#line 963 "./Parser/parser_main.y"
                                                  {   yyval.type = yyvsp[-1].type;
                                                      yyval.prim = yyvsp[-1].prim;
                                                      yyval.str = (char *)malloc(sizeof(char)*(strlen(yyvsp[-1].str)+3));
                                                      snprintf(yyval.str,strlen(yyvsp[-1].str)+3,"(%s)",yyvsp[-1].str);
                                                      free(yyvsp[-1].str);
                                                  }
#line 3071 "./exec/y.tab.c"
    break;

  case 189: /* out_rhs: '!' out_rhs  */
#line 969 "./Parser/parser_main.y"
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
#line 3088 "./exec/y.tab.c"
    break;

  case 190: /* out_rhs: out_rhs AND out_rhs  */
#line 981 "./Parser/parser_main.y"
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
#line 3107 "./exec/y.tab.c"
    break;

  case 191: /* out_rhs: out_rhs OR out_rhs  */
#line 995 "./Parser/parser_main.y"
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
#line 3125 "./exec/y.tab.c"
    break;

  case 192: /* out_rhs: out_rhs COMP out_rhs  */
#line 1008 "./Parser/parser_main.y"
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
#line 3144 "./exec/y.tab.c"
    break;

  case 193: /* out_rhs: out_rhs EQUALITY out_rhs  */
#line 1022 "./Parser/parser_main.y"
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
#line 3163 "./exec/y.tab.c"
    break;

  case 194: /* out_rhs: out_rhs '*' out_rhs  */
#line 1036 "./Parser/parser_main.y"
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
#line 3190 "./exec/y.tab.c"
    break;

  case 195: /* out_rhs: out_rhs '/' out_rhs  */
#line 1058 "./Parser/parser_main.y"
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
#line 3209 "./exec/y.tab.c"
    break;

  case 196: /* out_rhs: out_rhs '+' out_rhs  */
#line 1073 "./Parser/parser_main.y"
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
#line 3236 "./exec/y.tab.c"
    break;

  case 197: /* out_rhs: out_rhs '-' out_rhs  */
#line 1095 "./Parser/parser_main.y"
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
#line 3257 "./exec/y.tab.c"
    break;

  case 198: /* out_rhs: out_rhs '@' out_rhs  */
#line 1111 "./Parser/parser_main.y"
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
#line 3297 "./exec/y.tab.c"
    break;

  case 199: /* out_rhs: out_rhs '&' out_rhs  */
#line 1147 "./Parser/parser_main.y"
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
#line 3316 "./exec/y.tab.c"
    break;

  case 200: /* out_rhs: out_rhs '^' out_rhs  */
#line 1162 "./Parser/parser_main.y"
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
#line 3335 "./exec/y.tab.c"
    break;

  case 201: /* out_rhs: out_rhs '|' out_rhs  */
#line 1177 "./Parser/parser_main.y"
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
#line 3354 "./exec/y.tab.c"
    break;

  case 202: /* out_expr: ID '=' out_rhs  */
#line 1194 "./Parser/parser_main.y"
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
#line 3377 "./exec/y.tab.c"
    break;

  case 203: /* decl: prim_type out_expr  */
#line 1214 "./Parser/parser_main.y"
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
#line 3398 "./exec/y.tab.c"
    break;

  case 204: /* decl: list_type out_expr  */
#line 1231 "./Parser/parser_main.y"
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
#line 3417 "./exec/y.tab.c"
    break;

  case 205: /* echo_stmt: ECHO '(' echo_list ')'  */
#line 1248 "./Parser/parser_main.y"
                                                      {  fprintf(fp,"Echo statement\n");
                                                         fprintf(out,"cout<<%s<<endl;\n",yyvsp[-1].str);
                                                      }
#line 3425 "./exec/y.tab.c"
    break;

  case 206: /* echo_list: echo_list ',' out_rhs  */
#line 1253 "./Parser/parser_main.y"
                                                      {  yyval.str = (char *)malloc(sizeof(char)*(strlen(yyvsp[-2].str)+strlen(yyvsp[0].str)+4));
                                                         snprintf(yyval.str,strlen(yyvsp[-2].str)+strlen(yyvsp[0].str)+4,"%s<<%s",yyvsp[-2].str,yyvsp[0].str);
                                                         free(yyvsp[-2].str);
                                                         free(yyvsp[0].str);
                                                      }
#line 3435 "./exec/y.tab.c"
    break;

  case 207: /* echo_list: out_rhs  */
#line 1258 "./Parser/parser_main.y"
                                                      {  yyval.str = (char *)malloc(sizeof(char)*(strlen(yyvsp[0].str)+2));
                                                         snprintf(yyval.str,strlen(yyvsp[0].str)+2,"%s",yyvsp[0].str);
                                                         free(yyvsp[0].str);   
                                                      }
#line 3444 "./exec/y.tab.c"
    break;

  case 208: /* save_stmt: '\\' SAVE STRING  */
#line 1265 "./Parser/parser_main.y"
                                                      {fprintf(fp,"Save statement\n");}
#line 3450 "./exec/y.tab.c"
    break;

  case 209: /* $@12: %empty  */
#line 1269 "./Parser/parser_main.y"
                          {fprintf(fp,"Output section conditional statement begins\n");}
#line 3456 "./exec/y.tab.c"
    break;

  case 210: /* out_control: $@12 out_cond_stmt  */
#line 1269 "./Parser/parser_main.y"
                                                                                                       {fprintf(fp,"Output section conditional statement ends\n");}
#line 3462 "./exec/y.tab.c"
    break;

  case 211: /* out_control: out_for_stmt  */
#line 1270 "./Parser/parser_main.y"
                                                      {fprintf(fp,"For statement in output section\n");}
#line 3468 "./exec/y.tab.c"
    break;

  case 212: /* out_control: out_for_lex_stmt  */
#line 1271 "./Parser/parser_main.y"
                                                      {fprintf(fp,"For - lex statement in output section\n");}
#line 3474 "./exec/y.tab.c"
    break;

  case 213: /* out_control: out_for_zip_stmt  */
#line 1272 "./Parser/parser_main.y"
                                                      {fprintf(fp,"For - zip statement in output section\n");}
#line 3480 "./exec/y.tab.c"
    break;

  case 214: /* out_control: out_while_stmt  */
#line 1273 "./Parser/parser_main.y"
                                                      {fprintf(fp,"while statement in output section\n");}
#line 3486 "./exec/y.tab.c"
    break;

  case 215: /* $@13: %empty  */
#line 1276 "./Parser/parser_main.y"
                                                        {outputLevel++;fprintf(out,"if(%s){\n",yyvsp[-2].str);}
#line 3492 "./exec/y.tab.c"
    break;

  case 216: /* $@14: %empty  */
#line 1276 "./Parser/parser_main.y"
                                                                                                                      {fprintf(out,"}\n");outputLevel--;}
#line 3498 "./exec/y.tab.c"
    break;

  case 218: /* $@15: %empty  */
#line 1279 "./Parser/parser_main.y"
                                                                       {outputLevel++;fprintf(out,"else if(%s){\n",yyvsp[-2].str);}
#line 3504 "./exec/y.tab.c"
    break;

  case 219: /* out_other_list: out_other_list OTHERWISE '(' out_rhs ')' '{' $@15 out_main '}'  */
#line 1279 "./Parser/parser_main.y"
                                                                                                                                          {fprintf(out,"}\n");outputLevel--;}
#line 3510 "./exec/y.tab.c"
    break;

  case 221: /* $@16: %empty  */
#line 1283 "./Parser/parser_main.y"
                                        {outputLevel++;fprintf(out,"else{\n");}
#line 3516 "./exec/y.tab.c"
    break;

  case 222: /* out_other_final: OTHERWISE '{' $@16 out_main '}'  */
#line 1283 "./Parser/parser_main.y"
                                                                                             {outputLevel--;fprintf(out,"}\n");}
#line 3522 "./exec/y.tab.c"
    break;

  case 224: /* $@17: %empty  */
#line 1287 "./Parser/parser_main.y"
                                 {  if(getOutputSymbolEntry(&OutputSymbolTable,yyvsp[0].str,outputLevel + 1,1) == NULL){
                                       yyerror("semantic error: variable used without declaration"); 
                                       return 1;
                                    }
                                 }
#line 3532 "./exec/y.tab.c"
    break;

  case 225: /* $@18: %empty  */
#line 1292 "./Parser/parser_main.y"
                                               {outputLevel++;fprintf(out,"for(%s = %s;%s < %s;%s += %s){\n",yyvsp[-6].str,yyvsp[-2].start,yyvsp[-6].str,yyvsp[-2].end,yyvsp[-6].str,yyvsp[-2].step);}
#line 3538 "./exec/y.tab.c"
    break;

  case 226: /* out_for_stmt: FOR ID $@17 IN '(' range ')' '{' $@18 out_main '}'  */
#line 1293 "./Parser/parser_main.y"
                                               {fprintf(out,"}\n");exitOutputSymbolScope(&OutputSymbolTable,outputLevel);outputLevel--;}
#line 3544 "./exec/y.tab.c"
    break;

  case 227: /* $@19: %empty  */
#line 1296 "./Parser/parser_main.y"
                                                                          {   if(yyvsp[-5].num != yyvsp[-1].num){
                                                                                 yyerror("semantic error: mismatch in loop variables and ranges"); 
                                                                                 return 1;
                                                                              }
                                                                              printForLex(yyvsp[-5].num);
                                                                          }
#line 3555 "./exec/y.tab.c"
    break;

  case 228: /* $@20: %empty  */
#line 1302 "./Parser/parser_main.y"
                              {outputLevel++;}
#line 3561 "./exec/y.tab.c"
    break;

  case 229: /* out_for_lex_stmt: FOR_LEX '(' var_list ')' IN '(' range_list ')' $@19 '{' $@20 out_main '}'  */
#line 1302 "./Parser/parser_main.y"
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
#line 3576 "./exec/y.tab.c"
    break;

  case 230: /* $@21: %empty  */
#line 1314 "./Parser/parser_main.y"
                                                                          {   if(yyvsp[-5].num != yyvsp[-1].num){
                                                                                 yyerror("semantic error: mismatch in loop variables and ranges"); 
                                                                                 return 1;
                                                                              }
                                                                              printForZip(yyvsp[-5].num);
                                                                          }
#line 3587 "./exec/y.tab.c"
    break;

  case 231: /* $@22: %empty  */
#line 1320 "./Parser/parser_main.y"
                              {outputLevel++;}
#line 3593 "./exec/y.tab.c"
    break;

  case 232: /* out_for_zip_stmt: FOR_ZIP '(' var_list ')' IN '(' range_list ')' $@21 '{' $@22 out_main '}'  */
#line 1321 "./Parser/parser_main.y"
                                                     {exitOutputSymbolScope(&OutputSymbolTable,outputLevel); outputLevel--;}
#line 3599 "./exec/y.tab.c"
    break;

  case 233: /* $@23: %empty  */
#line 1324 "./Parser/parser_main.y"
                                                    {outputLevel++;fprintf(out,"while(%s){\n",yyvsp[-2].str);}
#line 3605 "./exec/y.tab.c"
    break;

  case 234: /* out_while_stmt: WHILE '(' out_rhs ')' '{' $@23 out_main '}'  */
#line 1324 "./Parser/parser_main.y"
                                                                                                                     {fprintf(out,"}\n");exitOutputSymbolScope(&OutputSymbolTable,outputLevel); outputLevel--;}
#line 3611 "./exec/y.tab.c"
    break;

  case 240: /* $@24: %empty  */
#line 1336 "./Parser/parser_main.y"
                          {isDeclaration = false;}
#line 3617 "./exec/y.tab.c"
    break;

  case 241: /* out_stmt: $@24 out_expr  */
#line 1336 "./Parser/parser_main.y"
                                                            {fprintf(out,"%s\n",yyvsp[0].str2);}
#line 3623 "./exec/y.tab.c"
    break;

  case 242: /* $@25: %empty  */
#line 1337 "./Parser/parser_main.y"
                          {isDeclaration = true;}
#line 3629 "./exec/y.tab.c"
    break;


#line 3633 "./exec/y.tab.c"

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

#line 1339 "./Parser/parser_main.y"


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
  out = fopen("out.txt","w");
  yyparse();

  return 0;
}

void yyerror(char* err){
   printf("At line %d: %s\n", line, err);
   fprintf(fp,"At line %d: %s\n",line, err);
}
