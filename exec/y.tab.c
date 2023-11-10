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
   void yyerror();

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

#line 120 "./exec/y.tab.c"

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
  YYSYMBOL_102_5 = 102,                    /* $@5  */
  YYSYMBOL_rhs = 103,                      /* rhs  */
  YYSYMBOL_tuple_list = 104,               /* tuple_list  */
  YYSYMBOL_tuple_list2 = 105,              /* tuple_list2  */
  YYSYMBOL_id_list = 106,                  /* id_list  */
  YYSYMBOL_block_defn_section = 107,       /* block_defn_section  */
  YYSYMBOL_108_6 = 108,                    /* $@6  */
  YYSYMBOL_block_defns_list = 109,         /* block_defns_list  */
  YYSYMBOL_block_defn = 110,               /* block_defn  */
  YYSYMBOL_111_7 = 111,                    /* $@7  */
  YYSYMBOL_params = 112,                   /* params  */
  YYSYMBOL_param_id_list = 113,            /* param_id_list  */
  YYSYMBOL_target_params = 114,            /* target_params  */
  YYSYMBOL_target_param_list = 115,        /* target_param_list  */
  YYSYMBOL_block_body = 116,               /* block_body  */
  YYSYMBOL_block_id = 117,                 /* block_id  */
  YYSYMBOL_main_stmt_list = 118,           /* main_stmt_list  */
  YYSYMBOL_main_stmt = 119,                /* main_stmt  */
  YYSYMBOL_stmts = 120,                    /* stmts  */
  YYSYMBOL_121_8 = 121,                    /* $@8  */
  YYSYMBOL_register = 122,                 /* register  */
  YYSYMBOL_call_stmt = 123,                /* call_stmt  */
  YYSYMBOL_parameters = 124,               /* parameters  */
  YYSYMBOL_optional = 125,                 /* optional  */
  YYSYMBOL_register_list = 126,            /* register_list  */
  YYSYMBOL_classic_control = 127,          /* classic_control  */
  YYSYMBOL_quantum_control = 128,          /* quantum_control  */
  YYSYMBOL_target = 129,                   /* target  */
  YYSYMBOL_measure_stmt = 130,             /* measure_stmt  */
  YYSYMBOL_barrier_stmt = 131,             /* barrier_stmt  */
  YYSYMBOL_condition_stmt = 132,           /* condition_stmt  */
  YYSYMBOL_otherwise_list = 133,           /* otherwise_list  */
  YYSYMBOL_otherwise_final = 134,          /* otherwise_final  */
  YYSYMBOL_arithmetic_expr = 135,          /* arithmetic_expr  */
  YYSYMBOL_expr = 136,                     /* expr  */
  YYSYMBOL_value = 137,                    /* value  */
  YYSYMBOL_range = 138,                    /* range  */
  YYSYMBOL_range_list = 139,               /* range_list  */
  YYSYMBOL_var_list = 140,                 /* var_list  */
  YYSYMBOL_for_stmt = 141,                 /* for_stmt  */
  YYSYMBOL_142_9 = 142,                    /* $@9  */
  YYSYMBOL_for_lex_stmt = 143,             /* for_lex_stmt  */
  YYSYMBOL_144_10 = 144,                   /* $@10  */
  YYSYMBOL_for_zip_stmt = 145,             /* for_zip_stmt  */
  YYSYMBOL_146_11 = 146,                   /* $@11  */
  YYSYMBOL_while_stmt = 147,               /* while_stmt  */
  YYSYMBOL_out_id = 148,                   /* out_id  */
  YYSYMBOL_prim_type = 149,                /* prim_type  */
  YYSYMBOL_list_type = 150,                /* list_type  */
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
  YYSYMBOL_out_other_list = 176,           /* out_other_list  */
  YYSYMBOL_out_other_final = 177,          /* out_other_final  */
  YYSYMBOL_out_for_stmt = 178,             /* out_for_stmt  */
  YYSYMBOL_179_14 = 179,                   /* $@14  */
  YYSYMBOL_180_15 = 180,                   /* $@15  */
  YYSYMBOL_out_for_lex_stmt = 181,         /* out_for_lex_stmt  */
  YYSYMBOL_182_16 = 182,                   /* $@16  */
  YYSYMBOL_183_17 = 183,                   /* $@17  */
  YYSYMBOL_out_for_zip_stmt = 184,         /* out_for_zip_stmt  */
  YYSYMBOL_185_18 = 185,                   /* $@18  */
  YYSYMBOL_186_19 = 186,                   /* $@19  */
  YYSYMBOL_out_while_stmt = 187,           /* out_while_stmt  */
  YYSYMBOL_188_20 = 188,                   /* $@20  */
  YYSYMBOL_out_main = 189,                 /* out_main  */
  YYSYMBOL_out_stmt = 190,                 /* out_stmt  */
  YYSYMBOL_191_21 = 191,                   /* $@21  */
  YYSYMBOL_192_22 = 192                    /* $@22  */
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
#define YYNNTS  110
/* YYNRULES -- Number of rules.  */
#define YYNRULES  240
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  552

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
       0,    80,    80,    84,    84,    87,    87,    90,    90,    98,
     102,   103,   104,   105,   106,   109,   112,   115,   116,   119,
     120,   123,   127,   127,   128,   131,   132,   135,   135,   138,
     139,   141,   142,   144,   145,   147,   148,   151,   151,   154,
     155,   158,   158,   161,   162,   165,   166,   169,   170,   171,
     174,   175,   178,   179,   182,   190,   191,   194,   195,   197,
     198,   199,   199,   200,   201,   202,   203,   206,   207,   212,
     213,   214,   215,   216,   217,   220,   221,   224,   225,   228,
     229,   232,   233,   236,   237,   238,   241,   242,   256,   259,
     262,   265,   266,   269,   270,   273,   274,   275,   276,   277,
     278,   279,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   296,   297,   300,   301,   304,   305,   308,
     309,   312,   312,   315,   315,   318,   318,   321,   330,   331,
     332,   335,   336,   337,   338,   339,   340,   341,   342,   345,
     352,   353,   356,   357,   358,   359,   361,   364,   367,   368,
     371,   374,   375,   378,   379,   382,   385,   386,   389,   390,
     391,   392,   393,   394,   395,   396,   397,   400,   403,   404,
     408,   409,   410,   411,   412,   413,   414,   415,   416,   422,
     423,   427,   428,   429,   430,   431,   432,   433,   434,   435,
     436,   437,   438,   439,   440,   441,   442,   443,   444,   447,
     448,   449,   453,   456,   458,   462,   465,   466,   470,   474,
     474,   475,   476,   477,   478,   481,   481,   484,   485,   488,
     489,   492,   492,   492,   495,   495,   495,   498,   498,   498,
     501,   501,   506,   507,   510,   511,   512,   513,   513,   514,
     514
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
  "gate_defn", "$@5", "rhs", "tuple_list", "tuple_list2", "id_list",
  "block_defn_section", "$@6", "block_defns_list", "block_defn", "$@7",
  "params", "param_id_list", "target_params", "target_param_list",
  "block_body", "block_id", "main_stmt_list", "main_stmt", "stmts", "$@8",
  "register", "call_stmt", "parameters", "optional", "register_list",
  "classic_control", "quantum_control", "target", "measure_stmt",
  "barrier_stmt", "condition_stmt", "otherwise_list", "otherwise_final",
  "arithmetic_expr", "expr", "value", "range", "range_list", "var_list",
  "for_stmt", "$@9", "for_lex_stmt", "$@10", "for_zip_stmt", "$@11",
  "while_stmt", "out_id", "prim_type", "list_type", "bool_const", "num",
  "complex_const", "matrix_const", "row_list", "row", "comps",
  "compatible_const", "state_const", "temp", "prim_const", "vec_const",
  "vec_list", "calls", "uint_list", "out_rhs", "out_expr", "decl",
  "echo_stmt", "echo_list", "save_stmt", "out_control", "$@12",
  "out_cond_stmt", "$@13", "out_other_list", "out_other_final",
  "out_for_stmt", "$@14", "$@15", "out_for_lex_stmt", "$@16", "$@17",
  "out_for_zip_stmt", "$@18", "$@19", "out_while_stmt", "$@20", "out_main",
  "out_stmt", "$@21", "$@22", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-411)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-238)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -43,    30,   142,   -17,  -411,  -411,   120,   100,    89,  -411,
     185,  -411,   204,   162,  -411,  -411,   216,   231,  -411,   189,
     194,   468,  -411,   184,   140,   198,   259,   296,  -411,   300,
    -411,    54,  -411,   239,   246,   314,   251,   253,   263,     5,
     312,    13,  -411,  -411,   332,   277,  -411,    23,  -411,  -411,
    -411,  -411,  -411,  -411,   594,   358,   357,   368,   309,   353,
     380,  -411,   259,   377,   386,    29,   392,   396,   312,  -411,
     418,   418,    48,  -411,  -411,  -411,  -411,   -24,   312,  -411,
     403,   343,  -411,  -411,     4,   239,    13,   422,   348,   352,
     356,   359,    67,  -411,  -411,  -411,   413,  -411,  -411,  -411,
    -411,  -411,   436,   854,   371,   420,   424,   428,   449,   353,
    -411,  -411,    31,  -411,   312,  -411,   312,   312,   438,   440,
    -411,    66,    73,  -411,  -411,  -411,  -411,    48,   479,   801,
     312,   382,    99,    35,  -411,    48,   445,   446,   403,  -411,
     418,   418,    48,   252,  -411,   417,   389,  -411,   404,  -411,
    -411,  -411,  -411,  -411,  -411,  -411,  -411,  -411,   410,   436,
     436,  -411,   470,   411,   483,  -411,   416,  -411,  -411,   489,
     473,   101,  -411,  -411,   312,   423,   501,   484,   485,   808,
     320,   320,   320,   320,   320,    48,    48,    48,    48,    48,
      48,    48,   437,  -411,  -411,  -411,   312,  -411,  -411,   815,
     312,   312,  -411,   492,   103,   111,   857,  -411,  -411,  -411,
    -411,  -411,   439,   444,   452,   453,   454,   458,   459,   467,
    -411,  -411,  -411,  -411,  -411,   252,   107,    77,   307,   474,
    -411,  -411,  -411,  -411,  -411,  -411,  -411,  1046,   114,  -411,
     252,   252,   992,  -411,  -411,   504,   450,  -411,  -411,   502,
    -411,   -52,   505,   448,    42,  -411,  -411,  -411,   322,  -411,
     469,   490,  -411,   210,   210,  -411,  -411,  -411,   266,   381,
     524,  -411,   285,    90,   336,  -411,   127,   498,  -411,  -411,
     499,   562,   563,   508,   252,   252,   252,   252,   252,   252,
     252,   252,   341,   154,   174,   -19,  -411,  -411,    94,  -411,
    -411,  -411,  -411,  -411,  -411,   513,   514,   516,   519,   525,
     526,   608,   252,   252,   252,   252,   252,   252,   252,   252,
     252,   252,   252,   252,   252,   252,  -411,   618,  1046,   443,
     528,   411,   483,   531,   523,  -411,   489,  -411,   534,   604,
    -411,   535,  -411,  -411,   530,   529,   322,   322,     9,  -411,
    -411,   322,   536,   537,  -411,   942,   985,   994,   628,   670,
     680,  1003,   690,    77,  -411,  -411,   113,  -411,   539,  -411,
     495,  -411,    77,   174,  -411,   879,   272,   442,   584,  -411,
    1053,  1053,  1059,  1059,   889,   339,    97,   341,  1046,   542,
    -411,   619,  -411,  -411,    77,   147,    77,   126,  -411,  -411,
     604,   544,   494,   322,   549,  -411,   134,   148,   603,  -411,
     363,   550,   322,   322,  -411,   252,   252,   252,  -411,  -411,
    -411,    36,  -411,    77,  -411,  -411,   539,  -411,   553,   555,
     558,  -411,   564,   188,  -411,   559,  -411,   168,   565,  -411,
    -411,  -411,   567,   494,   556,  -411,   322,  -411,  -411,  -411,
     571,   172,   179,   192,   732,   742,   752,   569,   252,  -411,
    -411,  -411,   252,  -411,   640,    77,  -411,    77,  -411,    77,
    -411,  -411,   322,   375,  -411,   577,   578,   632,  -411,  -411,
    -411,   600,  -411,  -411,  -411,  -411,  -411,   180,  1046,   920,
     209,   586,  -411,   205,   191,  -411,  -411,  -411,  -411,   207,
    -411,  -411,   587,   589,   252,   583,   592,  -411,   664,  -411,
    -411,   391,   402,  -411,    48,   333,  -411,  -411,  1046,  -411,
     252,   649,  -411,  -411,  -411,   429,   864,  -411,  -411,  -411,
     931,   235,  -411,  -411,   601,   527,   533,  -411,  -411,   252,
    -411,  -411,  -411,   554,   794,   456,  -411,   606,  -411,  -411,
     568,  -411
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     3,     1,     0,     0,     0,     5,
       0,     2,     0,    14,    56,     7,     0,     0,    37,    12,
      13,    61,   233,     0,     0,    22,    40,     0,    10,     0,
      11,    54,    67,    83,     0,     0,     0,     0,     0,     0,
       0,     0,    55,    57,     0,     0,    59,     0,    60,    58,
      63,    64,    65,    66,   239,     0,     0,     0,     0,     0,
       0,    38,    40,     0,     0,     0,     0,     0,     0,   121,
       0,     0,     0,     6,    89,    68,    80,     0,     0,    75,
      77,     0,    62,    81,    54,    83,     0,     0,     0,     0,
       0,     0,     0,   236,   235,   234,     0,   211,   212,   213,
     214,   232,     0,     0,     0,     0,     0,     0,     0,    23,
      26,    54,     0,    39,     0,    84,     0,     0,     0,     0,
     120,     0,     0,   100,   101,   111,   112,     0,   110,     0,
       0,     0,     0,     0,    74,     0,     0,     0,    77,   221,
       0,     0,     0,     0,     8,     0,     0,   210,     0,   238,
     131,   132,   133,   134,   135,   136,   137,   138,     0,     0,
       0,   240,     0,     0,     0,     4,     0,    25,    43,     0,
      47,     0,    72,    71,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    79,    82,    76,     0,    86,    78,     0,
       0,     0,    73,     0,     0,     0,     0,   128,   162,   163,
     140,   141,     0,     0,     0,     0,     0,     0,     0,     0,
     129,   130,   166,   164,   165,     0,     0,     0,     0,   183,
     158,   159,   160,   161,   181,   182,   187,   207,     0,   208,
       0,     0,     0,   203,   204,     0,    15,    18,    21,    16,
      20,     0,    46,     0,     0,    41,    85,    88,     0,   119,
       0,     0,   109,    95,    96,    97,    98,    99,   102,   103,
     104,   105,   107,   106,   108,    56,     0,     0,    70,    69,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   189,     0,     0,     0,   149,   169,     0,   145,
     143,   142,   144,   157,   156,     0,   162,   163,   164,   165,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   205,     0,   202,     0,
       0,     0,     0,     0,     0,    27,     0,    44,    51,     0,
      49,     0,   114,   113,     0,     0,     0,     0,    61,    87,
      56,     0,     0,     0,   230,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   154,   153,     0,   152,     0,   147,
       0,   167,     0,     0,   188,     0,   192,   193,   190,   191,
     196,   197,   194,   195,   198,   199,   200,   201,   206,     0,
     139,     0,    17,    19,     0,     0,     0,     0,    28,    45,
       0,     0,    52,     0,     0,   118,     0,     0,     0,   127,
      61,     0,     0,     0,   233,     0,     0,     0,   173,   174,
     178,     0,   177,     0,   150,   148,     0,   168,     0,     0,
     184,   215,     0,     0,    36,     0,    29,     0,     0,    30,
      50,    48,     0,    52,   115,    56,     0,   123,   125,    92,
       0,     0,     0,   239,     0,     0,     0,     0,     0,   151,
     155,   146,     0,   233,     0,     0,    32,     0,    34,     0,
      42,    53,     0,    61,   117,     0,     0,    94,   222,   224,
     227,     0,   231,   170,   171,   172,   175,     0,   180,     0,
     239,     0,    35,     0,     0,   116,   122,    56,    56,     0,
      90,   233,     0,     0,     0,     0,   185,   218,     0,    31,
      33,    61,    61,    56,     0,   239,   225,   228,   179,   176,
       0,   220,     9,   124,   126,    61,     0,   223,   233,   233,
       0,     0,   216,    93,     0,   239,   239,   186,   233,     0,
      56,   226,   229,   239,     0,    61,   219,     0,    91,   233,
     239,   217
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -411,  -411,  -411,  -411,  -411,  -411,  -411,  -411,  -411,  -411,
     673,   681,  -411,  -411,   369,  -411,  -411,  -411,   596,  -411,
    -411,  -411,  -411,  -347,  -411,  -411,   644,  -411,  -411,  -411,
     374,  -411,  -291,   264,   -18,  -273,  -411,  -276,  -411,    76,
    -411,   625,   579,   -67,  -411,   132,  -411,  -411,  -411,  -411,
    -411,  -411,   383,  -127,  -360,  -244,  -328,   -51,  -411,  -411,
    -411,  -411,  -411,  -411,  -411,  -411,   476,  -411,  -411,  -218,
    -220,  -411,  -411,   347,  -411,   293,  -162,  -224,  -221,  -411,
    -411,  -411,  -411,  -219,   240,  -411,  -411,  -411,  -411,  -411,
    -411,  -411,  -411,  -411,  -411,  -411,  -411,  -411,  -411,  -411,
    -411,  -411,  -411,  -411,  -411,  -411,  -410,  -411,  -411,  -411
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     2,     3,     8,     7,    14,    11,    22,    13,    18,
      19,    20,   246,   249,   250,    58,    59,   109,   110,   398,
     335,   395,   397,   433,    25,    26,    61,    62,   341,   170,
     253,   255,   340,   442,    41,    21,    42,    43,    44,    45,
      46,    80,   134,    77,    47,    66,   198,    48,    49,    82,
     477,   500,   128,   129,   344,   405,   406,   121,    50,   119,
      51,   475,    52,   476,    53,   229,   159,   160,   230,   303,
     231,   232,   295,   296,   366,   367,   233,   434,   234,   235,
     298,   236,   487,   237,   149,   161,    93,   238,    94,    95,
      96,   147,   463,   521,   532,    97,   203,   501,    98,   502,
     528,    99,   503,   529,   100,   414,    54,   101,   102,   103
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     179,   247,   348,   305,   453,   297,   292,   304,   199,   311,
     310,   132,    31,    32,   345,   206,    75,    32,    73,   407,
     122,   327,   328,   333,   -83,   334,    84,    33,     1,    86,
      74,    34,    75,    32,   168,    35,    36,    37,    75,    32,
     457,    85,   112,   444,    38,   338,     4,   171,   401,   437,
     130,   123,   124,   490,     6,   368,   131,   369,   268,   269,
     270,   271,   272,   273,   274,   355,   356,   357,   358,   359,
     360,   361,   362,   365,   -83,   364,   310,   410,   125,   126,
     408,   299,   144,   300,   451,   452,    65,   409,    40,   204,
     205,   515,    78,   375,   376,   377,   378,   379,   380,   381,
     382,   383,   384,   385,   386,   387,   388,   411,   114,   440,
     169,   208,   495,   209,   196,   458,    76,    79,   535,   536,
     493,   339,   494,   187,   188,   145,   443,   127,   543,   276,
     315,   316,     9,   301,   302,   -68,    65,   210,   211,   550,
     176,   115,     5,   365,   118,   364,   177,   176,   428,   427,
      56,    57,   304,   178,    76,   429,   294,   222,   299,   191,
     300,    12,    79,   223,   224,    67,   324,   443,   370,   392,
     371,    10,   473,   130,   304,   130,   304,   176,   299,   195,
     300,   256,   293,   281,   227,   176,   294,   423,   325,   424,
      76,   282,   172,   173,   326,  -237,   454,   455,   456,    15,
     438,   130,   474,   365,   439,   364,   193,   349,   446,   197,
     301,   302,  -237,    16,   447,  -209,   136,   137,    87,    88,
      89,   435,   446,   436,   511,   512,    23,    90,   448,   363,
     301,   302,  -209,   294,    17,    87,    88,    89,    24,   488,
     525,   492,   465,   489,    90,   304,   446,   304,   468,   304,
     257,    91,   479,   446,   504,   207,   208,    55,   209,   480,
     505,    27,   465,   481,   466,   465,    29,   545,    91,   -24,
     482,   510,    76,   182,   183,   184,   278,   279,    60,   465,
     481,   509,   210,   211,   513,   518,   514,   507,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   186,   187,
     188,   530,   222,    63,   314,   315,   316,    64,   223,   224,
     207,   306,   538,   307,   539,    75,    32,    69,   187,   188,
     544,    65,   225,   123,   124,   342,   343,   226,    68,   227,
      70,   228,    71,   189,   190,   191,  -237,   210,   211,   322,
     323,   324,    72,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   190,   191,    81,  -209,   222,    83,    87,
      88,    89,   104,   308,   309,   105,    31,    32,    90,   187,
     188,   108,   315,   316,   315,   316,   106,   225,    31,    32,
     107,    33,   226,   111,   227,    34,   228,   526,    57,    35,
      36,    37,    91,    33,    31,    32,    56,    34,    38,   243,
     244,    35,    36,    37,   481,    31,    32,   323,   324,    33,
      38,   527,   116,    34,   187,   188,   117,    35,    36,    37,
      33,   120,   135,   133,    34,   139,    38,   140,    35,    36,
      37,   141,    31,    32,   408,   142,   146,    38,   143,   148,
     163,   449,    40,   162,   164,   165,   408,    33,   189,   190,
     191,    34,   166,   496,    40,    35,    36,    37,   174,    31,
      32,   175,   408,   194,    38,   200,   201,   239,   240,   523,
      40,    31,    32,   408,    33,   315,   316,   241,    34,   245,
     524,    40,    35,    36,    37,   242,    33,   248,   227,   251,
      34,    38,   252,   254,    35,    36,    37,    31,    32,   208,
     408,   209,   258,    38,   259,   260,   261,   533,    40,   322,
     323,   324,    33,   280,   275,   330,    34,   -61,   284,   390,
      35,    36,    37,   285,   331,   210,   211,   408,   337,    38,
    -237,   286,   287,   288,   548,    40,  -237,   289,   290,    39,
     180,   181,   182,   183,   184,   222,   291,    40,   346,   312,
    -209,   223,   224,    87,    88,    89,  -209,  -237,   188,    87,
      88,    89,    90,   263,   264,   265,   266,   267,    90,   347,
     426,  -237,   227,    40,   294,   350,   332,  -209,   351,   336,
      87,    88,    89,   352,   353,   354,    91,   372,  -145,    90,
    -143,  -209,    91,  -142,    87,    88,    89,  -237,   481,  -144,
     373,   391,   396,    90,   481,   541,   394,   338,   400,   404,
     402,   542,   403,    91,   363,   412,   413,  -209,   316,   431,
      87,    88,    89,   432,   441,   481,   445,    91,    74,    90,
     450,   460,   546,   462,   467,   461,   464,   313,   472,   481,
     314,   315,   316,   470,   469,   491,   551,   313,   478,   486,
     314,   315,   316,    91,   497,   498,   499,   313,   145,   508,
     314,   315,   316,   519,   516,    92,   517,   520,   522,   317,
     318,   319,   320,   531,   321,   322,   323,   324,   540,   317,
     318,   319,   320,   549,   321,   322,   323,   324,   374,   317,
     318,   319,   320,    30,   321,   322,   323,   324,   389,   313,
      28,   393,   314,   315,   316,   167,   113,   471,   418,   313,
     399,   138,   314,   315,   316,   425,   459,   202,   329,   313,
       0,     0,   314,   315,   316,     0,     0,     0,     0,     0,
       0,   317,   318,   319,   320,     0,   321,   322,   323,   324,
       0,   317,   318,   319,   320,     0,   321,   322,   323,   324,
     419,   317,   318,   319,   320,     0,   321,   322,   323,   324,
     420,   313,     0,     0,   314,   315,   316,     0,     0,     0,
     422,   313,     0,     0,   314,   315,   316,     0,     0,     0,
       0,   313,     0,     0,   314,   315,   316,     0,     0,     0,
       0,     0,     0,   317,   318,   319,   320,     0,   321,   322,
     323,   324,     0,   317,   318,   319,   320,     0,   321,   322,
     323,   324,   483,   317,   318,   319,   320,     0,   321,   322,
     323,   324,   484,   313,     0,     0,   314,   315,   316,     0,
     185,     0,   485,   186,   187,   188,     0,   185,     0,     0,
     186,   187,   188,     0,   185,     0,     0,   186,   187,   188,
       0,     0,     0,     0,     0,   317,   318,   319,   320,     0,
     321,   322,   323,   324,     0,     0,     0,     0,   189,   190,
     191,     0,     0,     0,   547,   189,   190,   191,     0,     0,
       0,   192,   189,   190,   191,     0,   185,     0,   262,   186,
     187,   188,     0,   185,     0,   277,   186,   187,   188,     0,
     150,   151,   152,   153,   154,   155,   156,   157,   313,   158,
       0,   314,   315,   316,     0,     0,     0,     0,   313,     0,
       0,   314,   315,   316,   189,   190,   191,     0,     0,     0,
       0,   189,   190,   191,     0,     0,     0,   283,     0,     0,
     317,   318,   319,   320,   534,   321,   322,   323,   324,   313,
       0,     0,   314,   315,   316,   430,   322,   323,   324,     0,
     313,     0,     0,   314,   315,   316,     0,     0,     0,     0,
       0,   313,     0,     0,   314,   315,   316,     0,     0,     0,
       0,   317,   318,   319,   320,     0,   321,   322,   323,   324,
       0,     0,   317,   318,   319,   320,   506,   321,   322,   323,
     324,     0,     0,   317,   318,   319,   320,   537,   321,   322,
     323,   324,     0,     0,   313,     0,   415,   314,   315,   316,
       0,     0,     0,   313,     0,     0,   314,   315,   316,     0,
       0,     0,   313,     0,     0,   314,   315,   316,   150,   151,
     152,   153,   154,   155,   156,   157,   317,   318,   319,   320,
       0,   321,   322,   323,   324,   317,   318,   319,   320,   416,
     321,   322,   323,   324,   317,   318,   319,   320,   417,   321,
     322,   323,   324,     0,     0,   313,     0,   421,   314,   315,
     316,     0,   313,     0,     0,   314,   315,   316,   313,     0,
       0,   314,   315,   316,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   317,   318,   319,
     320,     0,   321,   322,   323,   324,   319,   320,     0,   321,
     322,   323,   324,     0,     0,   321,   322,   323,   324
};

static const yytype_int16 yycheck[] =
{
     127,   163,   275,   227,   414,   226,   225,   227,   135,   228,
     228,    78,     3,     4,   258,   142,     3,     4,    13,   347,
      71,   240,   241,    75,    20,    77,     3,    18,    71,    47,
      25,    22,     3,     4,     3,    26,    27,    28,     3,     4,
       4,    18,    60,   403,    35,     3,    16,   114,   339,   396,
      74,     3,     4,   463,    71,    74,    80,    76,   185,   186,
     187,   188,   189,   190,   191,   284,   285,   286,   287,   288,
     289,   290,   291,   293,    20,   293,   294,   350,    30,    31,
      71,     4,    15,     6,   412,   413,    82,    78,    79,   140,
     141,   501,    79,   312,   313,   314,   315,   316,   317,   318,
     319,   320,   321,   322,   323,   324,   325,   351,    79,   400,
      79,     4,   472,     6,    79,    79,    40,    41,   528,   529,
     467,    79,   469,    33,    34,    58,   402,    79,   538,   196,
      33,    34,    12,    56,    57,    81,    82,    30,    31,   549,
      74,    65,     0,   363,    68,   363,    80,    74,   372,   370,
      10,    11,   372,    80,    78,   373,    79,    50,     4,    69,
       6,    72,    86,    56,    57,    33,    69,   443,    74,   331,
      76,    71,   445,    74,   394,    74,   396,    74,     4,    80,
       6,    80,    75,    80,    77,    74,    79,    74,    74,    76,
     114,    80,   116,   117,    80,     3,   415,   416,   417,    14,
      74,    74,   446,   423,    78,   423,   130,    80,    74,   133,
      56,    57,     3,     9,    80,    23,    84,    85,    26,    27,
      28,    74,    74,    76,   497,   498,    10,    35,    80,    75,
      56,    57,    23,    79,    72,    26,    27,    28,     7,   458,
     513,   465,    74,   462,    35,   465,    74,   467,    80,   469,
     174,    59,    80,    74,    74,     3,     4,    73,     6,    80,
      80,    72,    74,    71,    76,    74,    72,   540,    59,    71,
      78,    80,   196,    63,    64,    65,   200,   201,    19,    74,
      71,    76,    30,    31,    77,   504,    79,    78,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    32,    33,
      34,   520,    50,     7,    32,    33,    34,     7,    56,    57,
       3,     4,    77,     6,    79,     3,     4,     3,    33,    34,
     539,    82,    70,     3,     4,     3,     4,    75,    82,    77,
      79,    79,    79,    67,    68,    69,     3,    30,    31,    67,
      68,    69,    79,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    68,    69,    23,    23,    50,    81,    26,
      27,    28,     4,    56,    57,     8,     3,     4,    35,    33,
      34,    18,    33,    34,    33,    34,     8,    70,     3,     4,
      71,    18,    75,     3,    77,    22,    79,   514,    11,    26,
      27,    28,    59,    18,     3,     4,    10,    22,    35,   159,
     160,    26,    27,    28,    71,     3,     4,    68,    69,    18,
      35,    78,    20,    22,    33,    34,    20,    26,    27,    28,
      18,     3,    79,    20,    22,     3,    35,    79,    26,    27,
      28,    79,     3,     4,    71,    79,    23,    35,    79,     3,
      20,    78,    79,    72,    20,    17,    71,    18,    67,    68,
      69,    22,     3,    78,    79,    26,    27,    28,    20,     3,
       4,    21,    71,    81,    35,    20,    20,    50,    79,    78,
      79,     3,     4,    71,    18,    33,    34,    73,    22,     9,
      78,    79,    26,    27,    28,    75,    18,     4,    77,    73,
      22,    35,     3,    20,    26,    27,    28,     3,     4,     4,
      71,     6,    79,    35,     3,    21,    21,    78,    79,    67,
      68,    69,    18,    21,    77,    11,    22,    23,    79,    76,
      26,    27,    28,    79,    74,    30,    31,    71,    80,    35,
       3,    79,    79,    79,    78,    79,     3,    79,    79,    71,
      61,    62,    63,    64,    65,    50,    79,    79,    79,    75,
      23,    56,    57,    26,    27,    28,    23,     3,    34,    26,
      27,    28,    35,   180,   181,   182,   183,   184,    35,    79,
      75,     3,    77,    79,    79,    77,    74,    23,    79,    74,
      26,    27,    28,    21,    21,    77,    59,    74,    74,    35,
      74,    23,    59,    74,    26,    27,    28,     3,    71,    74,
      74,    73,    79,    35,    71,    78,    75,     3,    74,    80,
      75,    78,    82,    59,    75,    79,    79,    23,    34,    77,
      26,    27,    28,     4,    80,    71,    77,    59,    25,    35,
      80,    78,    78,    75,    75,    80,    72,    29,    82,    71,
      32,    33,    34,    76,    79,     5,    78,    29,    77,    80,
      32,    33,    34,    59,    77,    77,    24,    29,    58,    73,
      32,    33,    34,    80,    77,    71,    77,    75,     4,    61,
      62,    63,    64,    24,    66,    67,    68,    69,    77,    61,
      62,    63,    64,    77,    66,    67,    68,    69,    80,    61,
      62,    63,    64,    20,    66,    67,    68,    69,    80,    29,
      19,   332,    32,    33,    34,   109,    62,   443,    80,    29,
     336,    86,    32,    33,    34,   368,   423,   138,   242,    29,
      -1,    -1,    32,    33,    34,    -1,    -1,    -1,    -1,    -1,
      -1,    61,    62,    63,    64,    -1,    66,    67,    68,    69,
      -1,    61,    62,    63,    64,    -1,    66,    67,    68,    69,
      80,    61,    62,    63,    64,    -1,    66,    67,    68,    69,
      80,    29,    -1,    -1,    32,    33,    34,    -1,    -1,    -1,
      80,    29,    -1,    -1,    32,    33,    34,    -1,    -1,    -1,
      -1,    29,    -1,    -1,    32,    33,    34,    -1,    -1,    -1,
      -1,    -1,    -1,    61,    62,    63,    64,    -1,    66,    67,
      68,    69,    -1,    61,    62,    63,    64,    -1,    66,    67,
      68,    69,    80,    61,    62,    63,    64,    -1,    66,    67,
      68,    69,    80,    29,    -1,    -1,    32,    33,    34,    -1,
      29,    -1,    80,    32,    33,    34,    -1,    29,    -1,    -1,
      32,    33,    34,    -1,    29,    -1,    -1,    32,    33,    34,
      -1,    -1,    -1,    -1,    -1,    61,    62,    63,    64,    -1,
      66,    67,    68,    69,    -1,    -1,    -1,    -1,    67,    68,
      69,    -1,    -1,    -1,    80,    67,    68,    69,    -1,    -1,
      -1,    80,    67,    68,    69,    -1,    29,    -1,    80,    32,
      33,    34,    -1,    29,    -1,    80,    32,    33,    34,    -1,
      46,    47,    48,    49,    50,    51,    52,    53,    29,    55,
      -1,    32,    33,    34,    -1,    -1,    -1,    -1,    29,    -1,
      -1,    32,    33,    34,    67,    68,    69,    -1,    -1,    -1,
      -1,    67,    68,    69,    -1,    -1,    -1,    80,    -1,    -1,
      61,    62,    63,    64,    80,    66,    67,    68,    69,    29,
      -1,    -1,    32,    33,    34,    76,    67,    68,    69,    -1,
      29,    -1,    -1,    32,    33,    34,    -1,    -1,    -1,    -1,
      -1,    29,    -1,    -1,    32,    33,    34,    -1,    -1,    -1,
      -1,    61,    62,    63,    64,    -1,    66,    67,    68,    69,
      -1,    -1,    61,    62,    63,    64,    76,    66,    67,    68,
      69,    -1,    -1,    61,    62,    63,    64,    76,    66,    67,
      68,    69,    -1,    -1,    29,    -1,    74,    32,    33,    34,
      -1,    -1,    -1,    29,    -1,    -1,    32,    33,    34,    -1,
      -1,    -1,    29,    -1,    -1,    32,    33,    34,    46,    47,
      48,    49,    50,    51,    52,    53,    61,    62,    63,    64,
      -1,    66,    67,    68,    69,    61,    62,    63,    64,    74,
      66,    67,    68,    69,    61,    62,    63,    64,    74,    66,
      67,    68,    69,    -1,    -1,    29,    -1,    74,    32,    33,
      34,    -1,    29,    -1,    -1,    32,    33,    34,    29,    -1,
      -1,    32,    33,    34,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    61,    62,    63,
      64,    -1,    66,    67,    68,    69,    63,    64,    -1,    66,
      67,    68,    69,    -1,    -1,    66,    67,    68,    69
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    71,    84,    85,    16,     0,    71,    87,    86,    12,
      71,    89,    72,    91,    88,    14,     9,    72,    92,    93,
      94,   118,    90,    10,     7,   107,   108,    72,    94,    72,
      93,     3,     4,    18,    22,    26,    27,    28,    35,    71,
      79,   117,   119,   120,   121,   122,   123,   127,   130,   131,
     141,   143,   145,   147,   189,    73,    10,    11,    98,    99,
      19,   109,   110,     7,     7,    82,   128,   128,    82,     3,
      79,    79,    79,    13,    25,     3,   122,   126,    79,   122,
     124,    23,   132,    81,     3,    18,   117,    26,    27,    28,
      35,    59,    71,   169,   171,   172,   173,   178,   181,   184,
     187,   190,   191,   192,     4,     8,     8,    71,    18,   100,
     101,     3,   117,   109,    79,   122,    20,    20,   122,   142,
       3,   140,   140,     3,     4,    30,    31,    79,   135,   136,
      74,    80,   126,    20,   125,    79,   128,   128,   124,     3,
      79,    79,    79,    79,    15,    58,    23,   174,     3,   167,
      46,    47,    48,    49,    50,    51,    52,    53,    55,   149,
     150,   168,    72,    20,    20,    17,     3,   101,     3,    79,
     112,   126,   122,   122,    20,    21,    74,    80,    80,   136,
      61,    62,    63,    64,    65,    29,    32,    33,    34,    67,
      68,    69,    80,   122,    81,    80,    79,   122,   129,   136,
      20,    20,   125,   179,   140,   140,   136,     3,     4,     6,
      30,    31,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    50,    56,    57,    70,    75,    77,    79,   148,
     151,   153,   154,   159,   161,   162,   164,   166,   170,    50,
      79,    73,    75,   167,   167,     9,    95,   159,     4,    96,
      97,    73,     3,   113,    20,   114,    80,   122,    79,     3,
      21,    21,    80,   135,   135,   135,   135,   135,   136,   136,
     136,   136,   136,   136,   136,    77,   126,    80,   122,   122,
      21,    80,    80,    80,    79,    79,    79,    79,    79,    79,
      79,    79,   166,    75,    79,   155,   156,   161,   163,     4,
       6,    56,    57,   152,   153,   160,     4,     6,    56,    57,
     152,   166,    75,    29,    32,    33,    34,    61,    62,    63,
      64,    66,    67,    68,    69,    74,    80,   166,   166,   149,
      11,    74,    74,    75,    77,   103,    74,    80,     3,    79,
     115,   111,     3,     4,   137,   138,    79,    79,   118,    80,
      77,    79,    21,    21,    77,   166,   166,   166,   166,   166,
     166,   166,   166,    75,   152,   153,   157,   158,    74,    76,
      74,    76,    74,    74,    80,   166,   166,   166,   166,   166,
     166,   166,   166,   166,   166,   166,   166,   166,   166,    80,
      76,    73,   159,    97,    75,   104,    79,   105,   102,   113,
      74,   115,    75,    82,    80,   138,   139,   139,    71,    78,
     118,   138,    79,    79,   188,    74,    74,    74,    80,    80,
      80,    74,    80,    74,    76,   156,    75,   161,   160,   152,
      76,    77,     4,   106,   160,    74,    76,   106,    74,    78,
     115,    80,   116,   120,   137,    77,    74,    80,    80,    78,
      80,   139,   139,   189,   166,   166,   166,     4,    79,   158,
      78,    80,    75,   175,    72,    74,    76,    75,    80,    79,
      76,   116,    82,   118,   138,   144,   146,   133,    77,    80,
      80,    71,    78,    80,    80,    80,    80,   165,   166,   166,
     189,     5,   160,   106,   106,   137,    78,    77,    77,    24,
     134,   180,   182,   185,    74,    80,    76,    78,    73,    76,
      80,   118,   118,    77,    79,   189,    77,    77,   166,    80,
      75,   176,     4,    78,    78,   118,   136,    78,   183,   186,
     166,    24,   177,    78,    80,   189,   189,    76,    77,    79,
      77,    78,    78,   189,   166,   118,    78,    80,    78,    77,
     189,    78
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    83,    84,    86,    85,    88,    87,    90,    89,    91,
      92,    92,    92,    92,    92,    93,    94,    95,    95,    96,
      96,    97,    99,    98,    98,   100,   100,   102,   101,   103,
     103,   104,   104,   105,   105,   106,   106,   108,   107,   109,
     109,   111,   110,   112,   112,   113,   113,   114,   114,   114,
     115,   115,   116,   116,   117,   118,   118,   119,   119,   120,
     120,   121,   120,   120,   120,   120,   120,   122,   122,   123,
     123,   123,   123,   123,   123,   124,   124,   125,   125,   126,
     126,   127,   127,   128,   128,   128,   129,   129,   130,   131,
     132,   133,   133,   134,   134,   135,   135,   135,   135,   135,
     135,   135,   136,   136,   136,   136,   136,   136,   136,   136,
     136,   136,   136,   137,   137,   138,   138,   139,   139,   140,
     140,   142,   141,   144,   143,   146,   145,   147,   148,   148,
     148,   149,   149,   149,   149,   149,   149,   149,   149,   150,
     151,   151,   152,   152,   152,   152,   153,   154,   155,   155,
     156,   157,   157,   158,   158,   159,   160,   160,   161,   161,
     161,   161,   161,   161,   161,   161,   161,   162,   163,   163,
     164,   164,   164,   164,   164,   164,   164,   164,   164,   165,
     165,   166,   166,   166,   166,   166,   166,   166,   166,   166,
     166,   166,   166,   166,   166,   166,   166,   166,   166,   166,
     166,   166,   167,   168,   168,   169,   170,   170,   171,   173,
     172,   172,   172,   172,   172,   175,   174,   176,   176,   177,
     177,   179,   180,   178,   182,   183,   181,   185,   186,   184,
     188,   187,   189,   189,   190,   190,   190,   191,   190,   192,
     190
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     3,     0,     9,     0,     6,     0,     6,    14,
       2,     2,     1,     1,     0,     6,     6,     3,     1,     3,
       1,     1,     0,     2,     0,     2,     1,     0,     5,     3,
       3,     5,     3,     5,     3,     3,     1,     0,     2,     2,
       0,     0,     8,     1,     3,     3,     1,     0,     4,     2,
       3,     1,     0,     2,     1,     2,     0,     1,     1,     1,
       1,     0,     2,     1,     1,     1,     1,     1,     1,     5,
       5,     4,     4,     4,     3,     1,     3,     0,     2,     3,
       1,     2,     4,     0,     2,     4,     1,     3,     5,     2,
       9,     8,     0,     4,     0,     3,     3,     3,     3,     3,
       1,     1,     3,     3,     3,     3,     3,     3,     3,     3,
       1,     1,     1,     1,     1,     3,     5,     3,     1,     3,
       1,     0,    10,     0,    12,     0,    12,     7,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     4,
       1,     1,     1,     1,     1,     1,     5,     3,     3,     1,
       3,     3,     1,     1,     1,     5,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     3,     1,
       6,     6,     6,     4,     4,     6,     8,     4,     4,     3,
       1,     1,     1,     1,     4,     7,    10,     1,     3,     2,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     2,     2,     4,     3,     1,     3,     0,
       2,     1,     1,     1,     1,     0,    10,     8,     0,     4,
       0,     0,     0,    11,     0,     0,    13,     0,     0,    13,
       0,     8,     2,     0,     1,     1,     1,     0,     2,     0,
       2
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
#line 80 "./Parser/parser_main.y"
                                                                   {fprintf(fp,"\nParsing successful!\n");}
#line 1803 "./exec/y.tab.c"
    break;

  case 3: /* $@1: %empty  */
#line 84 "./Parser/parser_main.y"
                                           {fprintf(fp,"\nInit section begins\n\n");}
#line 1809 "./exec/y.tab.c"
    break;

  case 4: /* init_section: '\\' INIT_BEGIN $@1 mandatory_init set_states block_defn_section gate_defn_section '\\' INIT_END  */
#line 84 "./Parser/parser_main.y"
                                                                                                                                                                   {fprintf(fp,"\nInit section ends\n");}
#line 1815 "./exec/y.tab.c"
    break;

  case 5: /* $@2: %empty  */
#line 87 "./Parser/parser_main.y"
                                            {fprintf(fp,"\nMain section begins\n\n");}
#line 1821 "./exec/y.tab.c"
    break;

  case 6: /* main_section: '\\' MAIN_BEGIN $@2 main_stmt_list '\\' MAIN_END  */
#line 87 "./Parser/parser_main.y"
                                                                                                                    {fprintf(fp,"\nMain section ends\n");}
#line 1827 "./exec/y.tab.c"
    break;

  case 7: /* $@3: %empty  */
#line 90 "./Parser/parser_main.y"
                                             {fprintf(fp,"\nOutput section begins\n\n"); isInOutput = true; outputLevel = 1;}
#line 1833 "./exec/y.tab.c"
    break;

  case 8: /* output_section: '\\' OUTPUT_BEGIN $@3 out_main '\\' OUTPUT_END  */
#line 90 "./Parser/parser_main.y"
                                                                                                                                                        {fprintf(fp,"\nOutput section ends\n");exitOutputSymbolScope(&OutputSymbolTable,outputLevel);}
#line 1839 "./exec/y.tab.c"
    break;

  case 9: /* mandatory_init: '#' REGISTERS QUANTUM '=' NUMBER '#' REGISTERS CLASSICAL '=' NUMBER '#' ITERS '=' NUMBER  */
#line 98 "./Parser/parser_main.y"
                                                                                                                    {  fprintf(fp,"Register and iteration initialization section\n");classical_registers = yyvsp[-4].num;quantum_registers = yyvsp[-9].num;iterations = yyvsp[0].num;}
#line 1845 "./exec/y.tab.c"
    break;

  case 15: /* set_quantum_states: '#' SET QUANTUM STATES ARROW quantum_state_list  */
#line 109 "./Parser/parser_main.y"
                                                                            {fprintf(fp,"Setting initial state of quantum registers\n");}
#line 1851 "./exec/y.tab.c"
    break;

  case 16: /* set_classical_states: '#' SET CLASSICAL STATES ARROW classical_state_list  */
#line 112 "./Parser/parser_main.y"
                                                                                {fprintf(fp,"Setting initial state of classical registers\n");}
#line 1857 "./exec/y.tab.c"
    break;

  case 17: /* quantum_state_list: quantum_state_list ',' state_const  */
#line 115 "./Parser/parser_main.y"
                                                                     {if(quantum_index == quantum_registers){yyerror();return 1;}quantum_states[quantum_index++] = yyvsp[0].q;}
#line 1863 "./exec/y.tab.c"
    break;

  case 18: /* quantum_state_list: state_const  */
#line 116 "./Parser/parser_main.y"
                                          {quantum_states = (struct Quantum*)malloc(sizeof(struct Quantum)*quantum_registers);quantum_states[quantum_index++] = yyvsp[0].q;}
#line 1869 "./exec/y.tab.c"
    break;

  case 19: /* classical_state_list: classical_state_list ',' classical_state  */
#line 119 "./Parser/parser_main.y"
                                                                      {if(classical_index == classical_registers){yyerror();return 1;}classical_states[classical_index++] = yyvsp[0].num;}
#line 1875 "./exec/y.tab.c"
    break;

  case 20: /* classical_state_list: classical_state  */
#line 120 "./Parser/parser_main.y"
                                            {classical_states = (int *)malloc(sizeof(int)*classical_registers);classical_states[classical_index++] = yyvsp[0].num;}
#line 1881 "./exec/y.tab.c"
    break;

  case 21: /* classical_state: NUMBER  */
#line 123 "./Parser/parser_main.y"
                                    {yyval.num = yyvsp[0].num;}
#line 1887 "./exec/y.tab.c"
    break;

  case 22: /* $@4: %empty  */
#line 127 "./Parser/parser_main.y"
                           {fprintf(fp,"Gate definition section begins\n");}
#line 1893 "./exec/y.tab.c"
    break;

  case 23: /* gate_defn_section: $@4 gate_defn_list  */
#line 127 "./Parser/parser_main.y"
                                                                                            {fprintf(fp,"Gate definition section ends\n");}
#line 1899 "./exec/y.tab.c"
    break;

  case 27: /* $@5: %empty  */
#line 135 "./Parser/parser_main.y"
                                            {fprintf(fp,"Gate definition\n");}
#line 1905 "./exec/y.tab.c"
    break;

  case 28: /* gate_defn: GATE ID '=' rhs $@5  */
#line 135 "./Parser/parser_main.y"
                                                                                 {if(!insertInGateTable(&GateSymbolTable,yyvsp[-3].str,yyvsp[-1].rows,yyvsp[-1].cols)){yyerror();return;}}
#line 1911 "./exec/y.tab.c"
    break;

  case 29: /* rhs: '[' tuple_list ']'  */
#line 138 "./Parser/parser_main.y"
                                                {yyval.rows = yyvsp[-1].rows;yyval.cols = yyvsp[-1].cols;}
#line 1917 "./exec/y.tab.c"
    break;

  case 31: /* tuple_list: tuple_list ',' '[' id_list ']'  */
#line 141 "./Parser/parser_main.y"
                                                         {if(yyvsp[-4].cols != yyvsp[-1].cols){yyerror();return 1;}int temp; temp = yyvsp[-4].rows + 1;yyval.rows = temp;yyval.cols = yyvsp[-4].cols;}
#line 1923 "./exec/y.tab.c"
    break;

  case 32: /* tuple_list: '[' id_list ']'  */
#line 142 "./Parser/parser_main.y"
                                                         {yyval.rows = 1;yyval.cols = yyvsp[-1].cols;}
#line 1929 "./exec/y.tab.c"
    break;

  case 35: /* id_list: id_list ',' temp  */
#line 147 "./Parser/parser_main.y"
                                             {yyval.cols += 1;}
#line 1935 "./exec/y.tab.c"
    break;

  case 36: /* id_list: temp  */
#line 148 "./Parser/parser_main.y"
                                             {yyval.cols = 1;}
#line 1941 "./exec/y.tab.c"
    break;

  case 37: /* $@6: %empty  */
#line 151 "./Parser/parser_main.y"
                           {fprintf(fp,"Block definition section begins\n");}
#line 1947 "./exec/y.tab.c"
    break;

  case 38: /* block_defn_section: $@6 block_defns_list  */
#line 151 "./Parser/parser_main.y"
                                                                                               {fprintf(fp,"Block definition section ends\n");}
#line 1953 "./exec/y.tab.c"
    break;

  case 41: /* $@7: %empty  */
#line 158 "./Parser/parser_main.y"
                                                              {if(!insertInBlockTable(&BlockSymbolTable,yyvsp[-2].str,yyvsp[-1].num,head)){yyerror();return;}head = NULL;isInBlock = 1;}
#line 1959 "./exec/y.tab.c"
    break;

  case 42: /* block_defn: BLOCK block_id params target_params $@7 '[' block_body ']'  */
#line 158 "./Parser/parser_main.y"
                                                                                                                                                                                             {fprintf(fp,"Block definition\n");if(!BlockSemanticCheck(yyvsp[-6].str)){yyerror();return 1;}id_list = NULL;isInBlock = 0;}
#line 1965 "./exec/y.tab.c"
    break;

  case 43: /* params: ID  */
#line 161 "./Parser/parser_main.y"
                                                {insertInList(&head,yyvsp[0].str);yyval.num = 1;}
#line 1971 "./exec/y.tab.c"
    break;

  case 44: /* params: '(' param_id_list ')'  */
#line 162 "./Parser/parser_main.y"
                                                {yyval.num = yyvsp[-1].num;}
#line 1977 "./exec/y.tab.c"
    break;

  case 45: /* param_id_list: ID ',' param_id_list  */
#line 165 "./Parser/parser_main.y"
                                                {insertInList(&head,yyvsp[-2].str);yyval.num = 1 + yyvsp[0].num;}
#line 1983 "./exec/y.tab.c"
    break;

  case 46: /* param_id_list: ID  */
#line 166 "./Parser/parser_main.y"
                                                {insertInList(&head,yyvsp[0].str);yyval.num = 1;}
#line 1989 "./exec/y.tab.c"
    break;

  case 54: /* block_id: ID  */
#line 182 "./Parser/parser_main.y"
                                  {if(!firstLetterCapital(yyvsp[0].str)){yyerror(); return 1;} yyval.str = yyvsp[0].str;}
#line 1995 "./exec/y.tab.c"
    break;

  case 58: /* main_stmt: barrier_stmt  */
#line 195 "./Parser/parser_main.y"
                                          {fprintf(fp,"barrier statement\n");}
#line 2001 "./exec/y.tab.c"
    break;

  case 60: /* stmts: measure_stmt  */
#line 198 "./Parser/parser_main.y"
                                          {fprintf(fp,"Measure statement\n");}
#line 2007 "./exec/y.tab.c"
    break;

  case 61: /* $@8: %empty  */
#line 199 "./Parser/parser_main.y"
                          {fprintf(fp,"Conditional statement begin\n");}
#line 2013 "./exec/y.tab.c"
    break;

  case 62: /* stmts: $@8 condition_stmt  */
#line 199 "./Parser/parser_main.y"
                                                                                        {fprintf(fp,"Conditional statement end\n");}
#line 2019 "./exec/y.tab.c"
    break;

  case 63: /* stmts: for_stmt  */
#line 200 "./Parser/parser_main.y"
                                          {fprintf(fp,"For statement\n");}
#line 2025 "./exec/y.tab.c"
    break;

  case 64: /* stmts: for_lex_stmt  */
#line 201 "./Parser/parser_main.y"
                                          {fprintf(fp,"For - Lex statement\n");}
#line 2031 "./exec/y.tab.c"
    break;

  case 65: /* stmts: for_zip_stmt  */
#line 202 "./Parser/parser_main.y"
                                          {fprintf(fp,"For - Zip statement\n");}
#line 2037 "./exec/y.tab.c"
    break;

  case 66: /* stmts: while_stmt  */
#line 203 "./Parser/parser_main.y"
                                          {fprintf(fp,"while statement\n");}
#line 2043 "./exec/y.tab.c"
    break;

  case 67: /* register: NUMBER  */
#line 206 "./Parser/parser_main.y"
                                  {if(yyvsp[0].num < 0){yyerror(); return 1;} yyval.num = yyvsp[0].num;yyval.flag=0;}
#line 2049 "./exec/y.tab.c"
    break;

  case 68: /* register: ID  */
#line 207 "./Parser/parser_main.y"
                                  {if(isInBlock){insertInList(&id_list,yyvsp[0].str);}yyval.flag = 1;}
#line 2055 "./exec/y.tab.c"
    break;

  case 69: /* call_stmt: classic_control GATE quantum_control ARROW register  */
#line 212 "./Parser/parser_main.y"
                                                                              {fprintf(fp,"Pre - defined Gate call statement\n");}
#line 2061 "./exec/y.tab.c"
    break;

  case 70: /* call_stmt: classic_control ID quantum_control ARROW register  */
#line 213 "./Parser/parser_main.y"
                                                                              {fprintf(fp,"user - defined Gate call statement\n");}
#line 2067 "./exec/y.tab.c"
    break;

  case 71: /* call_stmt: GATE quantum_control ARROW register  */
#line 214 "./Parser/parser_main.y"
                                                                              {fprintf(fp,"Pre - defined Gate call statement\n");}
#line 2073 "./exec/y.tab.c"
    break;

  case 72: /* call_stmt: ID quantum_control ARROW register  */
#line 215 "./Parser/parser_main.y"
                                                                              {fprintf(fp,"User - defined Gate call statement\n");}
#line 2079 "./exec/y.tab.c"
    break;

  case 73: /* call_stmt: classic_control block_id parameters optional  */
#line 216 "./Parser/parser_main.y"
                                                                              {fprintf(fp,"Block call statement\n");if(!isInBlock){if(!BlockCallSemanticCheck(yyvsp[-2].str,yyvsp[-1].num)){yyerror();return;}}}
#line 2085 "./exec/y.tab.c"
    break;

  case 74: /* call_stmt: block_id parameters optional  */
#line 217 "./Parser/parser_main.y"
                                                                              {fprintf(fp,"Block call statement\n");if(!isInBlock){if(!BlockCallSemanticCheck(yyvsp[-2].str,yyvsp[-1].num)){yyerror();return;}}}
#line 2091 "./exec/y.tab.c"
    break;

  case 75: /* parameters: register  */
#line 220 "./Parser/parser_main.y"
                                                   {yyval.num = 1;}
#line 2097 "./exec/y.tab.c"
    break;

  case 76: /* parameters: '(' register_list ')'  */
#line 221 "./Parser/parser_main.y"
                                                   {yyval.num = yyvsp[-1].num;}
#line 2103 "./exec/y.tab.c"
    break;

  case 79: /* register_list: register_list ',' register  */
#line 228 "./Parser/parser_main.y"
                                                      {yyval.num = 1 + yyvsp[-2].num;}
#line 2109 "./exec/y.tab.c"
    break;

  case 80: /* register_list: register  */
#line 229 "./Parser/parser_main.y"
                                                      {yyval.num = 1;}
#line 2115 "./exec/y.tab.c"
    break;

  case 88: /* measure_stmt: MEASURE ':' register ARROW register  */
#line 256 "./Parser/parser_main.y"
                                                              {if((!yyvsp[-2].flag && (yyvsp[-2].num < 0 || yyvsp[-2].num >= quantum_registers)) || (!yyvsp[0].flag && (yyvsp[0].num < 0 || yyvsp[0].num >= classical_registers))){yyerror(); return 1;}}
#line 2121 "./exec/y.tab.c"
    break;

  case 117: /* range_list: range_list ',' range  */
#line 304 "./Parser/parser_main.y"
                                                   {yyval.num = 1 + yyvsp[-2].num;}
#line 2127 "./exec/y.tab.c"
    break;

  case 118: /* range_list: range  */
#line 305 "./Parser/parser_main.y"
                                                   {yyval.num = 1;}
#line 2133 "./exec/y.tab.c"
    break;

  case 119: /* var_list: var_list ',' ID  */
#line 308 "./Parser/parser_main.y"
                                             {if(isInOutput){if(getOutputSymbolEntry(&OutputSymbolTable,yyvsp[0].str,outputLevel + 1,0) != NULL){yyerror(); return 1;} else insertInOutputTable(&OutputSymbolTable,yyvsp[-1].str,outputLevel + 1, Int,true,0,0,true);} else if(!inList(&head,yyvsp[0].str)){insertInList(&head,yyvsp[0].str);} else {yyerror(); return 1;} yyval.num = 1 + yyvsp[-2].num;}
#line 2139 "./exec/y.tab.c"
    break;

  case 120: /* var_list: ID  */
#line 309 "./Parser/parser_main.y"
                                             {if(isInOutput){if(getOutputSymbolEntry(&OutputSymbolTable,yyvsp[0].str,outputLevel + 1,0) != NULL){yyerror(); return 1;} else insertInOutputTable(&OutputSymbolTable,yyvsp[0].str,outputLevel + 1, Int,true,0,0,true);} else if(!inList(&head,yyvsp[0].str)){insertInList(&head,yyvsp[0].str);} else {yyerror(); return 1;} yyval.num = 1;}
#line 2145 "./exec/y.tab.c"
    break;

  case 121: /* $@9: %empty  */
#line 312 "./Parser/parser_main.y"
                                 {if(!inList(&head,yyvsp[0].str)){insertInList(&head,yyvsp[0].str);} else {yyerror(); return 1;}}
#line 2151 "./exec/y.tab.c"
    break;

  case 122: /* for_stmt: FOR ID $@9 IN '(' range ')' '{' main_stmt_list '}'  */
#line 312 "./Parser/parser_main.y"
                                                                                                                                                              {removeTopKFromList(&head,1);}
#line 2157 "./exec/y.tab.c"
    break;

  case 123: /* $@10: %empty  */
#line 315 "./Parser/parser_main.y"
                                                                         {if(yyvsp[-5].num != yyvsp[-1].num){yyerror(); return 1;}}
#line 2163 "./exec/y.tab.c"
    break;

  case 124: /* for_lex_stmt: FOR_LEX '(' var_list ')' IN '(' range_list ')' $@10 '{' main_stmt_list '}'  */
#line 315 "./Parser/parser_main.y"
                                                                                                                                             {removeTopKFromList(&head,yyvsp[-9].num);}
#line 2169 "./exec/y.tab.c"
    break;

  case 125: /* $@11: %empty  */
#line 318 "./Parser/parser_main.y"
                                                                         {if(yyvsp[-5].num != yyvsp[-1].num){yyerror(); return 1;}}
#line 2175 "./exec/y.tab.c"
    break;

  case 126: /* for_zip_stmt: FOR_ZIP '(' var_list ')' IN '(' range_list ')' $@11 '{' main_stmt_list '}'  */
#line 318 "./Parser/parser_main.y"
                                                                                                                                             {removeTopKFromList(&head,yyvsp[-9].num);}
#line 2181 "./exec/y.tab.c"
    break;

  case 128: /* out_id: ID  */
#line 330 "./Parser/parser_main.y"
                             {yyval.out_flag = 0; yyval.str = yyvsp[0].str;}
#line 2187 "./exec/y.tab.c"
    break;

  case 129: /* out_id: COUT  */
#line 331 "./Parser/parser_main.y"
                               {yyval.out_flag = 1; yyval.type = Int; yyval.prim = false; yyval.dim = (1 << classical_registers); yyval.rows = 0;}
#line 2193 "./exec/y.tab.c"
    break;

  case 130: /* out_id: QOUT  */
#line 332 "./Parser/parser_main.y"
                               {yyval.out_flag = 2; yyval.type = State; yyval.prim = false; yyval.dim = quantum_registers; yyval.rows = 0;}
#line 2199 "./exec/y.tab.c"
    break;

  case 131: /* prim_type: INT  */
#line 335 "./Parser/parser_main.y"
                                    {yyval.type = Int; yyval.prim = true;}
#line 2205 "./exec/y.tab.c"
    break;

  case 132: /* prim_type: UINT  */
#line 336 "./Parser/parser_main.y"
                                    {yyval.type = Uint; yyval.prim = true;}
#line 2211 "./exec/y.tab.c"
    break;

  case 133: /* prim_type: FLOAT  */
#line 337 "./Parser/parser_main.y"
                                    {yyval.type = Float; yyval.prim = true;}
#line 2217 "./exec/y.tab.c"
    break;

  case 134: /* prim_type: COMPLEX  */
#line 338 "./Parser/parser_main.y"
                                    {yyval.type = Complex; yyval.prim = true;}
#line 2223 "./exec/y.tab.c"
    break;

  case 135: /* prim_type: STRING  */
#line 339 "./Parser/parser_main.y"
                                    {yyval.type = String; yyval.prim = true;}
#line 2229 "./exec/y.tab.c"
    break;

  case 136: /* prim_type: MATRIX  */
#line 340 "./Parser/parser_main.y"
                                    {yyval.type = Matrix; yyval.prim = true;}
#line 2235 "./exec/y.tab.c"
    break;

  case 137: /* prim_type: STATE  */
#line 341 "./Parser/parser_main.y"
                                    {yyval.type = State; yyval.prim = true;}
#line 2241 "./exec/y.tab.c"
    break;

  case 138: /* prim_type: BOOL  */
#line 342 "./Parser/parser_main.y"
                                    {yyval.type = Bool; yyval.prim = true;}
#line 2247 "./exec/y.tab.c"
    break;

  case 139: /* list_type: LIST '[' prim_type ']'  */
#line 345 "./Parser/parser_main.y"
                                                 {yyval.type = yyvsp[-1].type; yyval.prim = false;}
#line 2253 "./exec/y.tab.c"
    break;

  case 142: /* num: DEC  */
#line 356 "./Parser/parser_main.y"
                                    {yyval.real = yyvsp[0].real;}
#line 2259 "./exec/y.tab.c"
    break;

  case 143: /* num: NEG  */
#line 357 "./Parser/parser_main.y"
                                    {yyval.real = yyvsp[0].real;}
#line 2265 "./exec/y.tab.c"
    break;

  case 144: /* num: EXP  */
#line 358 "./Parser/parser_main.y"
                                    {yyval.real = yyvsp[0].real;}
#line 2271 "./exec/y.tab.c"
    break;

  case 145: /* num: NUMBER  */
#line 359 "./Parser/parser_main.y"
                                    {yyval.real = yyvsp[0].num;}
#line 2277 "./exec/y.tab.c"
    break;

  case 146: /* complex_const: '(' num ',' num ')'  */
#line 361 "./Parser/parser_main.y"
                                                   {yyval.cpx.real = yyvsp[-3].real; yyval.cpx.imag = yyvsp[-1].real;}
#line 2283 "./exec/y.tab.c"
    break;

  case 147: /* matrix_const: '[' row_list ']'  */
#line 364 "./Parser/parser_main.y"
                                                   {if(yyvsp[-1].rows == yyvsp[-1].cols) {yyval.rows = yyvsp[-1].rows;} else {yyerror(); return 1;}}
#line 2289 "./exec/y.tab.c"
    break;

  case 148: /* row_list: row_list ',' row  */
#line 367 "./Parser/parser_main.y"
                                                   {yyval.rows = yyvsp[-2].rows + 1; if(yyvsp[-2].cols == yyvsp[0].cols) {yyval.cols = yyvsp[-2].cols;} else {yyerror(); return 1;}}
#line 2295 "./exec/y.tab.c"
    break;

  case 149: /* row_list: row  */
#line 368 "./Parser/parser_main.y"
                                                   {yyval.rows = 1; yyval.cols = yyvsp[0].cols;}
#line 2301 "./exec/y.tab.c"
    break;

  case 150: /* row: '[' comps ']'  */
#line 371 "./Parser/parser_main.y"
                                                   {yyval.cols = yyvsp[-1].cols;}
#line 2307 "./exec/y.tab.c"
    break;

  case 151: /* comps: comps ',' compatible_const  */
#line 374 "./Parser/parser_main.y"
                                                      {yyval.cols = yyvsp[-2].cols + 1;}
#line 2313 "./exec/y.tab.c"
    break;

  case 152: /* comps: compatible_const  */
#line 375 "./Parser/parser_main.y"
                                                      {yyval.cols = 1;}
#line 2319 "./exec/y.tab.c"
    break;

  case 155: /* state_const: '{' temp ',' temp '}'  */
#line 382 "./Parser/parser_main.y"
                                                   {yyval.q.first = yyvsp[-3].cpx; yyval.q.second = yyvsp[-1].cpx;}
#line 2325 "./exec/y.tab.c"
    break;

  case 156: /* temp: complex_const  */
#line 385 "./Parser/parser_main.y"
                                          {yyval.cpx = yyvsp[0].cpx;}
#line 2331 "./exec/y.tab.c"
    break;

  case 157: /* temp: num  */
#line 386 "./Parser/parser_main.y"
                                          {yyval.cpx.real = yyvsp[0].real; yyval.cpx.imag = 0;}
#line 2337 "./exec/y.tab.c"
    break;

  case 158: /* prim_const: bool_const  */
#line 389 "./Parser/parser_main.y"
                                          {yyval.type = Bool;}
#line 2343 "./exec/y.tab.c"
    break;

  case 159: /* prim_const: complex_const  */
#line 390 "./Parser/parser_main.y"
                                          {yyval.type = Complex;}
#line 2349 "./exec/y.tab.c"
    break;

  case 160: /* prim_const: matrix_const  */
#line 391 "./Parser/parser_main.y"
                                          {yyval.type = Matrix; yyval.rows = yyvsp[0].rows;}
#line 2355 "./exec/y.tab.c"
    break;

  case 161: /* prim_const: state_const  */
#line 392 "./Parser/parser_main.y"
                                          {yyval.type = State;}
#line 2361 "./exec/y.tab.c"
    break;

  case 162: /* prim_const: NUMBER  */
#line 393 "./Parser/parser_main.y"
                                          {yyval.type = Uint;}
#line 2367 "./exec/y.tab.c"
    break;

  case 163: /* prim_const: NEG  */
#line 394 "./Parser/parser_main.y"
                                          {yyval.type = Int;}
#line 2373 "./exec/y.tab.c"
    break;

  case 164: /* prim_const: DEC  */
#line 395 "./Parser/parser_main.y"
                                          {yyval.type = Float;}
#line 2379 "./exec/y.tab.c"
    break;

  case 165: /* prim_const: EXP  */
#line 396 "./Parser/parser_main.y"
                                          {yyval.type = Float;}
#line 2385 "./exec/y.tab.c"
    break;

  case 166: /* prim_const: STRING  */
#line 397 "./Parser/parser_main.y"
                                          {yyval.type = String;}
#line 2391 "./exec/y.tab.c"
    break;

  case 167: /* vec_const: '[' vec_list ']'  */
#line 400 "./Parser/parser_main.y"
                                                  {yyval.dim = yyvsp[-1].dim; yyval.type = yyvsp[-1].type; if(yyval.type == Matrix) {yyval.rows = yyvsp[-1].rows;} else {yyval.rows = 0;} }
#line 2397 "./exec/y.tab.c"
    break;

  case 168: /* vec_list: vec_list ',' prim_const  */
#line 403 "./Parser/parser_main.y"
                                                  {temp_type = compatibleCheck(yyvsp[-2].type, yyvsp[0].type); if(temp_type != -1) {yyval.type = temp_type;} else {yyerror(); return 1;} yyval.dim = yyvsp[-2].dim + 1; if(yyval.type == Matrix){ if(yyvsp[-2].rows != yyvsp[0].rows){yyerror();return 1;}else{yyval.rows = yyvsp[-2].rows;} }}
#line 2403 "./exec/y.tab.c"
    break;

  case 169: /* vec_list: prim_const  */
#line 404 "./Parser/parser_main.y"
                                                  {yyval.type = yyvsp[0].type; yyval.dim = 1; if(yyval.type == Matrix) {yyval.rows = yyvsp[0].rows;}}
#line 2409 "./exec/y.tab.c"
    break;

  case 170: /* calls: ADD '(' out_rhs ',' out_rhs ')'  */
#line 408 "./Parser/parser_main.y"
                                                                                                                              {temp_type = compatibleCheckAdv(yyvsp[-1].type, yyvsp[-3].type, yyvsp[-1].prim, yyvsp[-3].prim, yyvsp[-1].dim, yyvsp[-3].dim); printf("%d\n", temp_type); if((!yyvsp[-3].prim) && (temp_type>= 0) && ((temp_type<=COMPATIBLE) || temp_type==Matrix || temp_type==State/*|| temp_type==String*/)) {yyval.prim = false; yyval.type = temp_type; yyval.dim = yyvsp[-3].dim;} else {yyerror(); return 1;}}
#line 2415 "./exec/y.tab.c"
    break;

  case 171: /* calls: SUB '(' out_rhs ',' out_rhs ')'  */
#line 409 "./Parser/parser_main.y"
                                                                                                                              {temp_type = compatibleCheckAdv(yyvsp[-1].type, yyvsp[-3].type, yyvsp[-1].prim, yyvsp[-3].prim, yyvsp[-1].dim, yyvsp[-3].dim); if((!yyvsp[-3].prim) && (temp_type>= 0) && ((temp_type<=COMPATIBLE) || temp_type==Matrix || temp_type==State)) {yyval.prim = false; yyval.type = temp_type; yyval.dim = yyvsp[-3].dim;} else {yyerror(); return 1;}}
#line 2421 "./exec/y.tab.c"
    break;

  case 172: /* calls: DOT '(' out_rhs ',' out_rhs ')'  */
#line 410 "./Parser/parser_main.y"
                                                                                                                              {temp_type = compatibleCheckAdv(yyvsp[-1].type, yyvsp[-3].type, yyvsp[-1].prim, yyvsp[-3].prim, yyvsp[-1].dim, yyvsp[-3].dim); if((!yyvsp[-3].prim) && (temp_type>= 0) && (temp_type<=COMPATIBLE)) {yyval.prim = true; yyval.type = temp_type; yyval.dim = yyvsp[-3].dim;} else if ((!yyvsp[-3].prim) && (!yyvsp[-1].prim) && (yyvsp[-3].type<=COMPATIBLE) && (yyvsp[-1].type==Matrix)) {yyval.prim = true; yyval.type = Matrix; yyval.dim = 0;} else if(yyvsp[-3].prim && (temp_type==State)) {yyval.prim = true; yyval.type = Complex;} else {yyerror(); return 1;}}
#line 2427 "./exec/y.tab.c"
    break;

  case 173: /* calls: STD_DEV '(' out_rhs ')'  */
#line 411 "./Parser/parser_main.y"
                                                                                                                              {if((!yyvsp[-1].prim) && ((yyvsp[-1].type==Uint) || (yyvsp[-1].type==Int) || (yyvsp[-1].type==Float))) {yyval.prim = true; yyval.type = yyvsp[-1].type; yyval.dim = yyvsp[-1].dim;} else {yyerror(); return 1;}}
#line 2433 "./exec/y.tab.c"
    break;

  case 174: /* calls: VAR '(' out_rhs ')'  */
#line 412 "./Parser/parser_main.y"
                                                                                                                              {if((!yyvsp[-1].prim) && ((yyvsp[-1].type==Uint) || (yyvsp[-1].type==Int) || (yyvsp[-1].type==Float))) {yyval.prim = true; yyval.type = yyvsp[-1].type; yyval.dim = yyvsp[-1].dim;} else {yyerror(); return 1;}}
#line 2439 "./exec/y.tab.c"
    break;

  case 175: /* calls: CONDENSE '(' out_rhs ',' NUMBER ')'  */
#line 413 "./Parser/parser_main.y"
                                                                                                                              {if((!yyvsp[-3].prim) && ((yyvsp[-3].type==Uint) || (yyvsp[-3].type==Int))) {yyval.prim = false; yyval.type = yyvsp[-3].type; yyval.dim = condenser(yyvsp[-3].dim, 1);} else {yyerror(); return 1;}}
#line 2445 "./exec/y.tab.c"
    break;

  case 176: /* calls: CONDENSE '(' out_rhs ',' '(' uint_list ')' ')'  */
#line 414 "./Parser/parser_main.y"
                                                                                                                              {if((!yyvsp[-5].prim) && ((yyvsp[-5].type==Uint) || (yyvsp[-5].type==Int))) {yyval.prim = false; yyval.type = yyvsp[-5].type; yyval.dim = condenser(yyvsp[-5].dim, yyvsp[-2].cond_count);} else {yyerror(); return 1;}}
#line 2451 "./exec/y.tab.c"
    break;

  case 177: /* calls: SUM '(' out_rhs ')'  */
#line 415 "./Parser/parser_main.y"
                                                                                                                              {if((!yyvsp[-1].prim) && ((yyvsp[-1].type<=COMPATIBLE) || yyvsp[-1].type==Matrix /*|| temp_type==String*/)) {yyval.prim = true; yyval.type = yyvsp[-1].type; yyval.dim = 0;} else {yyerror(); return 1;}}
#line 2457 "./exec/y.tab.c"
    break;

  case 178: /* calls: AVG '(' out_rhs ')'  */
#line 416 "./Parser/parser_main.y"
                                                                                                                              {if((!yyvsp[-1].prim) && ((yyvsp[-1].type<=COMPATIBLE) || yyvsp[-1].type==Matrix)) {yyval.prim = true; yyval.type = yyvsp[-1].type; yyval.dim = 0;} else {yyerror(); return 1;}}
#line 2463 "./exec/y.tab.c"
    break;

  case 179: /* uint_list: uint_list ',' out_rhs  */
#line 422 "./Parser/parser_main.y"
                                                 {if(yyvsp[-2].type <= Int) {yyval.cond_count = yyvsp[-2].cond_count + 1;} else {yyerror(); return 1;}}
#line 2469 "./exec/y.tab.c"
    break;

  case 180: /* uint_list: out_rhs  */
#line 423 "./Parser/parser_main.y"
                                                 {if(yyvsp[0].type <= Int) {yyval.cond_count = 1;} else {yyerror(); return 1;}}
#line 2475 "./exec/y.tab.c"
    break;

  case 181: /* out_rhs: prim_const  */
#line 427 "./Parser/parser_main.y"
                                                                                 {yyval.prim = true; yyval.type = yyvsp[0].type;}
#line 2481 "./exec/y.tab.c"
    break;

  case 182: /* out_rhs: vec_const  */
#line 428 "./Parser/parser_main.y"
                                                                                 {yyval.prim = false; yyval.dim = yyvsp[0].dim; yyval.type = yyvsp[0].type; if(yyval.type == Matrix) {yyval.rows = yyvsp[0].rows;} else {yyval.rows = 0;}}
#line 2487 "./exec/y.tab.c"
    break;

  case 183: /* out_rhs: out_id  */
#line 429 "./Parser/parser_main.y"
                                                                                 {if(yyval.out_flag == 0){struct OutputSymbolEntry* sample = getOutputSymbolEntry(&OutputSymbolTable,yyvsp[0].str,outputLevel,1); if(sample != NULL){yyval.prim = sample->primitive; yyval.type = sample->type; if(yyval.type == Matrix){yyval.rows = sample->matrix_dim;} if(!yyval.prim){yyval.dim = sample->dim;}} else{yyerror(); return 1;}} else if(yyval.out_flag == 1){yyval.type = Int; yyval.prim = false; yyval.dim = (1 << classical_registers); yyval.rows = 0;} else{yyval.type = State; yyval.prim = false; yyval.dim = quantum_registers; yyval.rows = 0;}}
#line 2493 "./exec/y.tab.c"
    break;

  case 184: /* out_rhs: out_id '[' out_rhs ']'  */
#line 430 "./Parser/parser_main.y"
                                                                                 {if(yyval.out_flag == 0){struct OutputSymbolEntry* sample = getOutputSymbolEntry(&OutputSymbolTable,yyvsp[-3].str,outputLevel,1); if(sample != NULL){if(yyvsp[-1].type <= Uint){if(sample->primitive) {if(sample->type==State) {yyval.type = Complex; yyval.prim = true;} else {yyerror(); return 1;}} else {yyval.type = sample->type; yyval.prim = true;}} else {yyerror(); return 1;}} else{yyerror(); return 1;}} else if(yyval.out_flag == 1){yyval.type = Uint; yyval.prim = true;} else{yyval.type = State; yyval.prim = true;}}
#line 2499 "./exec/y.tab.c"
    break;

  case 185: /* out_rhs: out_id '[' out_rhs ']' '[' out_rhs ']'  */
#line 431 "./Parser/parser_main.y"
                                                                                 {if(yyval.out_flag == 0){struct OutputSymbolEntry* sample = getOutputSymbolEntry(&OutputSymbolTable,yyvsp[-6].str,outputLevel,1); if(sample != NULL){if((yyvsp[-4].type <= Uint) && (yyvsp[-2].type <= Uint)) {if(sample->type) {if(sample->type==Matrix) {yyval.type = Complex; yyval.prim = true;} else {yyerror(); return 1;}} else if(sample->type==State) {yyval.type = Complex; yyval.prim = true;} else {yyerror(); return 1;}}} else{yyerror(); return 1;}} else if(yyval.out_flag == 1){yyerror(); return 1;} else{yyval.type = Complex; yyval.prim = true;}}
#line 2505 "./exec/y.tab.c"
    break;

  case 186: /* out_rhs: out_id '[' out_rhs ']' '[' out_rhs ']' '[' out_rhs ']'  */
#line 432 "./Parser/parser_main.y"
                                                                                 {if(yyval.out_flag == 0){struct OutputSymbolEntry* sample = getOutputSymbolEntry(&OutputSymbolTable,yyvsp[-9].str,outputLevel,1); if(sample != NULL){if((yyvsp[-7].type <= Uint) && (yyvsp[-5].type <= Uint) && (yyvsp[-3].type <= Uint)) {if(sample->primitive) {yyerror(); return 1;} else if(sample->type==Matrix) {yyval.type = Complex; yyval.prim = true;} else {yyerror(); return 1;}}} else{yyerror(); return 1;}} else{yyerror(); return 1;}}
#line 2511 "./exec/y.tab.c"
    break;

  case 187: /* out_rhs: calls  */
#line 433 "./Parser/parser_main.y"
                                                                                 {yyval.prim = yyvsp[0].prim; yyval.type = yyvsp[0].type; if(yyvsp[0].type == Matrix){yyval.rows = yyvsp[0].rows;} if(!yyval.prim){yyval.dim = yyvsp[0].dim;} printf("%d %d\n", yyval.prim, yyval.type);}
#line 2517 "./exec/y.tab.c"
    break;

  case 188: /* out_rhs: '(' out_rhs ')'  */
#line 434 "./Parser/parser_main.y"
                                                                                 {yyval.type = yyvsp[-1].type;}
#line 2523 "./exec/y.tab.c"
    break;

  case 189: /* out_rhs: '!' out_rhs  */
#line 435 "./Parser/parser_main.y"
                                                                                 {if(yyvsp[0].type==Bool && yyvsp[0].prim) {yyval.prim = true; yyval.type = Bool;} else {yyerror(); return 1;}  }
#line 2529 "./exec/y.tab.c"
    break;

  case 190: /* out_rhs: out_rhs AND out_rhs  */
#line 436 "./Parser/parser_main.y"
                                                                                 {if(yyvsp[-2].type==Bool && yyvsp[-2].prim && yyvsp[0].type==Bool && yyvsp[0].prim)  {yyval.prim = true; yyval.type = Bool;} else {yyerror(); return 1;} }
#line 2535 "./exec/y.tab.c"
    break;

  case 191: /* out_rhs: out_rhs OR out_rhs  */
#line 437 "./Parser/parser_main.y"
                                                                                 {if(yyvsp[-2].type==Bool && yyvsp[-2].prim && yyvsp[0].type==Bool && yyvsp[0].prim)  {yyval.prim = true; yyval.type = Bool;} else {yyerror(); return 1;} }
#line 2541 "./exec/y.tab.c"
    break;

  case 192: /* out_rhs: out_rhs COMP out_rhs  */
#line 438 "./Parser/parser_main.y"
                                                                                 {temp_type = compatibleCheckAdv(yyvsp[-2].type, yyvsp[0].type, yyvsp[-2].prim, yyvsp[0].prim, yyvsp[-2].dim, yyvsp[0].dim); if(temp_type != -1 && temp_type < COMPARABLE) {yyval.prim = true; yyval.type = Bool;} else {yyerror(); return 1;}  }
#line 2547 "./exec/y.tab.c"
    break;

  case 193: /* out_rhs: out_rhs EQUALITY out_rhs  */
#line 439 "./Parser/parser_main.y"
                                                                                 {temp_type = compatibleCheckAdv(yyvsp[-2].type, yyvsp[0].type, yyvsp[-2].prim, yyvsp[0].prim, yyvsp[-2].dim, yyvsp[0].dim); if(temp_type != -1 && temp_type < COMPARABLE) {yyval.prim = true; yyval.type = Bool;} else {yyerror(); return 1;}  }
#line 2553 "./exec/y.tab.c"
    break;

  case 194: /* out_rhs: out_rhs '*' out_rhs  */
#line 440 "./Parser/parser_main.y"
                                                                                                                                                                  {temp_type = compatibleCheckAdv(yyvsp[-2].type, yyvsp[0].type, yyvsp[-2].prim, yyvsp[0].prim, yyvsp[-2].dim, yyvsp[0].dim); if(yyvsp[-2].prim && (temp_type <= Complex && temp_type >= 0)) {yyval.prim = true; yyval.type = temp_type;} else if(yyvsp[-2].prim && yyvsp[0].prim && yyvsp[-2].type<=Complex && yyvsp[0].type==Matrix) {yyval.prim = true; yyval.type = Matrix;} else if ((yyvsp[-2].prim && yyvsp[0].prim) && ((yyvsp[-2].type == String && yyvsp[0].type == Uint) || (yyvsp[0].type == String && yyvsp[-2].type == Uint))) {yyval.prim = true; yyval.type = String;} else {yyerror(); return 1;}}
#line 2559 "./exec/y.tab.c"
    break;

  case 195: /* out_rhs: out_rhs '/' out_rhs  */
#line 441 "./Parser/parser_main.y"
                                                                                                                                                                  {temp_type = compatibleCheckAdv(yyvsp[-2].type, yyvsp[0].type, yyvsp[-2].prim, yyvsp[0].prim, yyvsp[-2].dim, yyvsp[0].dim); if(yyvsp[-2].prim && (temp_type <= Complex && temp_type >= 0)) {yyval.prim = true; yyval.type = temp_type;} else {yyerror(); return 1;}}
#line 2565 "./exec/y.tab.c"
    break;

  case 196: /* out_rhs: out_rhs '+' out_rhs  */
#line 442 "./Parser/parser_main.y"
                                                                                                                                                                                       {temp_type = compatibleCheckAdv(yyvsp[-2].type, yyvsp[0].type, yyvsp[-2].prim, yyvsp[0].prim, yyvsp[-2].dim, yyvsp[0].dim); if(temp_type == Matrix || temp_type == State || (temp_type <= Complex && temp_type >= 0)) {yyval.prim = yyvsp[-2].prim; yyval.type = temp_type; if(temp_type == Matrix) {yyval.rows=yyvsp[-2].rows;} yyval.dim=yyvsp[-2].dim;} else if ((yyvsp[-2].prim==true) && (yyvsp[-2].type == String)) {yyval.prim = true; yyval.type = String;} else {yyerror(); return 1;}}
#line 2571 "./exec/y.tab.c"
    break;

  case 197: /* out_rhs: out_rhs '-' out_rhs  */
#line 443 "./Parser/parser_main.y"
                                                                                                                                                                                       {temp_type = compatibleCheckAdv(yyvsp[-2].type, yyvsp[0].type, yyvsp[-2].prim, yyvsp[0].prim, yyvsp[-2].dim, yyvsp[0].dim); if(temp_type == Matrix || temp_type == State || (temp_type <= Complex && temp_type >= 0)) {yyval.prim = yyvsp[-2].prim; yyval.type = temp_type; if(temp_type == Matrix) {yyval.rows=yyvsp[-2].rows;} yyval.dim=yyvsp[-2].dim;} else {yyerror(); return 1;} }
#line 2577 "./exec/y.tab.c"
    break;

  case 198: /* out_rhs: out_rhs '@' out_rhs  */
#line 444 "./Parser/parser_main.y"
                                                                                                                                                                                       {temp_type = compatibleCheckAdv(yyvsp[-2].type, yyvsp[0].type, yyvsp[-2].prim, yyvsp[0].prim, yyvsp[-2].dim, yyvsp[0].dim); if(yyvsp[-2].prim && temp_type == Matrix) {if(yyvsp[-2].rows == yyvsp[0].rows) {yyval.prim = true; yyval.type = temp_type; yyval.rows = yyvsp[-2].rows;} else {yyerror(); return 1;}} else if(yyvsp[-2].prim && temp_type == State) {yyval.prim = true; yyval.type = Complex;} else if(!yyvsp[-2].prim && (temp_type <= COMPATIBLE) && (temp_type >= 0)) {yyval.prim = true; yyval.type = temp_type; yyval.dim = 0;} else if (yyvsp[-2].type<=COMPATIBLE && yyvsp[0].type==Matrix) {yyval.prim = true; yyval.type = Matrix; yyval.dim = 0;} else {yyerror(); return 1;}}
#line 2583 "./exec/y.tab.c"
    break;

  case 199: /* out_rhs: out_rhs '&' out_rhs  */
#line 447 "./Parser/parser_main.y"
                                                                                                                                                                  {temp_type = compatibleCheckAdv(yyvsp[-2].type, yyvsp[0].type, yyvsp[-2].prim, yyvsp[0].prim, yyvsp[-2].dim, yyvsp[0].dim); if(temp_type <= Int) {yyval.prim = yyvsp[-2].prim; yyval.type = temp_type;} else {yyerror(); return 1;}}
#line 2589 "./exec/y.tab.c"
    break;

  case 200: /* out_rhs: out_rhs '^' out_rhs  */
#line 448 "./Parser/parser_main.y"
                                                                                                                                                                  {temp_type = compatibleCheckAdv(yyvsp[-2].type, yyvsp[0].type, yyvsp[-2].prim, yyvsp[0].prim, yyvsp[-2].dim, yyvsp[0].dim); if(temp_type <= Int) {yyval.prim = yyvsp[-2].prim; yyval.type = temp_type;} else {yyerror(); return 1;}}
#line 2595 "./exec/y.tab.c"
    break;

  case 201: /* out_rhs: out_rhs '|' out_rhs  */
#line 449 "./Parser/parser_main.y"
                                                                                                                                                                  {temp_type = compatibleCheckAdv(yyvsp[-2].type, yyvsp[0].type, yyvsp[-2].prim, yyvsp[0].prim, yyvsp[-2].dim, yyvsp[0].dim); if(temp_type <= Int) {yyval.prim = yyvsp[-2].prim; yyval.type = temp_type;} else {yyerror(); return 1;}}
#line 2601 "./exec/y.tab.c"
    break;

  case 202: /* out_expr: ID '=' out_rhs  */
#line 453 "./Parser/parser_main.y"
                                                      {fprintf(fp,"expression statement\n"); if(isDeclaration){yyval.type = yyvsp[0].type; yyval.str = yyvsp[-2].str; yyval.prim = yyvsp[0].prim; if(!yyvsp[0].prim){yyval.dim = yyvsp[0].dim;} if(yyvsp[0].type == Matrix){yyval.rows = yyvsp[0].rows;} } else {struct OutputSymbolEntry* entry = getOutputSymbolEntry(&OutputSymbolTable,yyvsp[-2].str,outputLevel,1); if(entry->type != yyvsp[0].type){yyerror(); return 1;}}}
#line 2607 "./exec/y.tab.c"
    break;

  case 203: /* decl: prim_type out_expr  */
#line 456 "./Parser/parser_main.y"
                                                      {fprintf(fp,"Primitive datatype declaration statement\n"); if( (yyvsp[0].prim==false) || ((yyvsp[-1].type < COMPATIBLE) && (yyvsp[-1].type < yyvsp[0].type)) || ((yyvsp[-1].type >= COMPATIBLE) && (yyvsp[-1].type != yyvsp[0].type)) || getOutputSymbolEntry(&OutputSymbolTable,yyvsp[0].str,outputLevel,0) != NULL){yyerror(); return 1;} else {if(yyvsp[0].type == Matrix) {insertInOutputTable(&OutputSymbolTable,yyvsp[0].str,outputLevel,yyvsp[0].type,true,yyvsp[0].rows,0,false);} else {insertInOutputTable(&OutputSymbolTable,yyvsp[0].str,outputLevel,yyvsp[0].type,true,0,0,false);}}}
#line 2613 "./exec/y.tab.c"
    break;

  case 204: /* decl: list_type out_expr  */
#line 458 "./Parser/parser_main.y"
                                                      {fprintf(fp,"List datatype declaration statement\n"); if( (yyvsp[0].prim==true) || ((yyvsp[-1].type < COMPATIBLE) && (yyvsp[-1].type < yyvsp[0].type)) || ((yyvsp[-1].type >= COMPATIBLE) && (yyvsp[-1].type != yyvsp[0].type)) || getOutputSymbolEntry(&OutputSymbolTable,yyvsp[0].str,outputLevel,0) != NULL){yyerror(); return 1;} else {if(yyvsp[0].type == Matrix) {insertInOutputTable(&OutputSymbolTable,yyvsp[0].str,outputLevel,yyvsp[-1].type,false,yyvsp[0].rows,yyvsp[0].dim,false);} else {insertInOutputTable(&OutputSymbolTable,yyvsp[0].str,outputLevel,yyvsp[-1].type,false,0,yyvsp[0].dim,false);}}}
#line 2619 "./exec/y.tab.c"
    break;

  case 205: /* echo_stmt: ECHO '(' echo_list ')'  */
#line 462 "./Parser/parser_main.y"
                                                      {fprintf(fp,"Echo statement\n");}
#line 2625 "./exec/y.tab.c"
    break;

  case 208: /* save_stmt: '\\' SAVE STRING  */
#line 470 "./Parser/parser_main.y"
                                                      {fprintf(fp,"Save statement\n");}
#line 2631 "./exec/y.tab.c"
    break;

  case 209: /* $@12: %empty  */
#line 474 "./Parser/parser_main.y"
                          {fprintf(fp,"Output section conditional statement begins\n");}
#line 2637 "./exec/y.tab.c"
    break;

  case 210: /* out_control: $@12 out_cond_stmt  */
#line 474 "./Parser/parser_main.y"
                                                                                                       {fprintf(fp,"Output section conditional statement ends\n");}
#line 2643 "./exec/y.tab.c"
    break;

  case 211: /* out_control: out_for_stmt  */
#line 475 "./Parser/parser_main.y"
                                                      {fprintf(fp,"For statement in output section\n");}
#line 2649 "./exec/y.tab.c"
    break;

  case 212: /* out_control: out_for_lex_stmt  */
#line 476 "./Parser/parser_main.y"
                                                      {fprintf(fp,"For - lex statement in output section\n");}
#line 2655 "./exec/y.tab.c"
    break;

  case 213: /* out_control: out_for_zip_stmt  */
#line 477 "./Parser/parser_main.y"
                                                      {fprintf(fp,"For - zip statement in output section\n");}
#line 2661 "./exec/y.tab.c"
    break;

  case 214: /* out_control: out_while_stmt  */
#line 478 "./Parser/parser_main.y"
                                                      {fprintf(fp,"while statement in output section\n");}
#line 2667 "./exec/y.tab.c"
    break;

  case 215: /* $@13: %empty  */
#line 481 "./Parser/parser_main.y"
                                                        {outputLevel++;}
#line 2673 "./exec/y.tab.c"
    break;

  case 216: /* out_cond_stmt: CONDITION '(' out_rhs ')' '{' $@13 out_main '}' out_other_list out_other_final  */
#line 481 "./Parser/parser_main.y"
                                                                                                                     {outputLevel--;}
#line 2679 "./exec/y.tab.c"
    break;

  case 221: /* $@14: %empty  */
#line 492 "./Parser/parser_main.y"
                                 {if(getOutputSymbolEntry(&OutputSymbolTable,yyvsp[0].str,outputLevel + 1,0) != NULL){yyerror(); return 1;} else insertInOutputTable(&OutputSymbolTable,yyvsp[0].str,outputLevel + 1,Int,true,0,0,true);}
#line 2685 "./exec/y.tab.c"
    break;

  case 222: /* $@15: %empty  */
#line 492 "./Parser/parser_main.y"
                                                                                                                                                                                                                                                   {outputLevel++;}
#line 2691 "./exec/y.tab.c"
    break;

  case 223: /* out_for_stmt: FOR ID $@14 IN '(' range ')' '{' $@15 out_main '}'  */
#line 492 "./Parser/parser_main.y"
                                                                                                                                                                                                                                                                                 {exitOutputSymbolScope(&OutputSymbolTable,outputLevel); outputLevel--;}
#line 2697 "./exec/y.tab.c"
    break;

  case 224: /* $@16: %empty  */
#line 495 "./Parser/parser_main.y"
                                                                          {if(yyvsp[-5].num != yyvsp[-1].num){yyerror(); return 1;}}
#line 2703 "./exec/y.tab.c"
    break;

  case 225: /* $@17: %empty  */
#line 495 "./Parser/parser_main.y"
                                                                                                                           {outputLevel++;}
#line 2709 "./exec/y.tab.c"
    break;

  case 226: /* out_for_lex_stmt: FOR_LEX '(' var_list ')' IN '(' range_list ')' $@16 '{' $@17 out_main '}'  */
#line 495 "./Parser/parser_main.y"
                                                                                                                                                         {exitOutputSymbolScope(&OutputSymbolTable,outputLevel); outputLevel--;}
#line 2715 "./exec/y.tab.c"
    break;

  case 227: /* $@18: %empty  */
#line 498 "./Parser/parser_main.y"
                                                                          {if(yyvsp[-5].num != yyvsp[-1].num){yyerror(); return 1;}}
#line 2721 "./exec/y.tab.c"
    break;

  case 228: /* $@19: %empty  */
#line 498 "./Parser/parser_main.y"
                                                                                                                           {outputLevel++;}
#line 2727 "./exec/y.tab.c"
    break;

  case 229: /* out_for_zip_stmt: FOR_ZIP '(' var_list ')' IN '(' range_list ')' $@18 '{' $@19 out_main '}'  */
#line 498 "./Parser/parser_main.y"
                                                                                                                                                         {exitOutputSymbolScope(&OutputSymbolTable,outputLevel); outputLevel--;}
#line 2733 "./exec/y.tab.c"
    break;

  case 230: /* $@20: %empty  */
#line 501 "./Parser/parser_main.y"
                                                 {outputLevel++;}
#line 2739 "./exec/y.tab.c"
    break;

  case 231: /* out_while_stmt: WHILE '(' expr ')' '{' $@20 out_main '}'  */
#line 501 "./Parser/parser_main.y"
                                                                               {exitOutputSymbolScope(&OutputSymbolTable,outputLevel); outputLevel--;}
#line 2745 "./exec/y.tab.c"
    break;

  case 237: /* $@21: %empty  */
#line 513 "./Parser/parser_main.y"
                          {isDeclaration = false;}
#line 2751 "./exec/y.tab.c"
    break;

  case 239: /* $@22: %empty  */
#line 514 "./Parser/parser_main.y"
                          {isDeclaration = true;}
#line 2757 "./exec/y.tab.c"
    break;


#line 2761 "./exec/y.tab.c"

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

#line 516 "./Parser/parser_main.y"


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

void yyerror(){
   printf("Error\n");
   fprintf(fp,"Syntax error at line %d\n",line);
}
