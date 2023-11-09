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
   bool inList(struct List** Head, char* data);

#line 106 "./exec/y.tab.c"

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
  YYSYMBOL_172_12 = 172,                   /* $@12  */
  YYSYMBOL_out_cond_stmt = 173,            /* out_cond_stmt  */
  YYSYMBOL_174_13 = 174,                   /* $@13  */
  YYSYMBOL_out_other_list = 175,           /* out_other_list  */
  YYSYMBOL_out_other_final = 176,          /* out_other_final  */
  YYSYMBOL_out_for_stmt = 177,             /* out_for_stmt  */
  YYSYMBOL_178_14 = 178,                   /* $@14  */
  YYSYMBOL_179_15 = 179,                   /* $@15  */
  YYSYMBOL_out_for_lex_stmt = 180,         /* out_for_lex_stmt  */
  YYSYMBOL_181_16 = 181,                   /* $@16  */
  YYSYMBOL_182_17 = 182,                   /* $@17  */
  YYSYMBOL_out_for_zip_stmt = 183,         /* out_for_zip_stmt  */
  YYSYMBOL_184_18 = 184,                   /* $@18  */
  YYSYMBOL_185_19 = 185,                   /* $@19  */
  YYSYMBOL_out_while_stmt = 186,           /* out_while_stmt  */
  YYSYMBOL_187_20 = 187,                   /* $@20  */
  YYSYMBOL_out_main = 188,                 /* out_main  */
  YYSYMBOL_out_stmt = 189,                 /* out_stmt  */
  YYSYMBOL_190_21 = 190,                   /* $@21  */
  YYSYMBOL_191_22 = 191                    /* $@22  */
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
#define YYLAST   1146

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  83
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  109
/* YYNRULES -- Number of rules.  */
#define YYNRULES  238
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
       0,    66,    66,    70,    70,    73,    73,    76,    76,    84,
      88,    89,    90,    91,    92,    95,    98,   101,   102,   105,
     106,   109,   113,   113,   114,   117,   118,   121,   121,   124,
     125,   127,   128,   130,   131,   133,   134,   137,   137,   140,
     141,   144,   144,   147,   148,   151,   152,   155,   156,   157,
     160,   161,   164,   165,   168,   176,   177,   180,   181,   183,
     184,   185,   185,   186,   187,   188,   189,   192,   193,   198,
     199,   200,   201,   202,   203,   206,   207,   210,   211,   214,
     215,   218,   219,   222,   223,   224,   227,   228,   242,   245,
     248,   251,   252,   255,   256,   259,   260,   261,   262,   263,
     264,   265,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   282,   283,   286,   287,   290,   291,   294,
     295,   298,   298,   301,   301,   304,   304,   307,   316,   316,
     316,   318,   319,   320,   321,   322,   323,   324,   325,   328,
     335,   336,   339,   340,   341,   342,   344,   347,   350,   351,
     354,   357,   358,   361,   364,   365,   368,   369,   370,   371,
     372,   373,   374,   375,   376,   379,   382,   383,   387,   388,
     389,   390,   391,   392,   393,   394,   395,   401,   402,   406,
     407,   408,   409,   410,   411,   412,   413,   414,   415,   416,
     417,   418,   419,   420,   421,   422,   423,   424,   425,   429,
     432,   433,   434,   438,   441,   442,   446,   450,   450,   451,
     452,   453,   454,   457,   457,   460,   461,   464,   465,   468,
     468,   468,   471,   471,   471,   474,   474,   474,   477,   477,
     482,   483,   486,   487,   488,   489,   489,   490,   490
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
  "state_const", "temp", "prim_const", "vec_const", "vec_list", "calls",
  "uint_list", "out_rhs", "out_expr", "decl", "echo_stmt", "echo_list",
  "save_stmt", "out_control", "$@12", "out_cond_stmt", "$@13",
  "out_other_list", "out_other_final", "out_for_stmt", "$@14", "$@15",
  "out_for_lex_stmt", "$@16", "$@17", "out_for_zip_stmt", "$@18", "$@19",
  "out_while_stmt", "$@20", "out_main", "out_stmt", "$@21", "$@22", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-380)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-236)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -19,    41,    68,    64,  -380,  -380,    91,    83,    92,  -380,
     183,  -380,   177,   148,  -380,  -380,   225,   238,  -380,   208,
     219,     4,  -380,   223,   337,   240,   294,   314,  -380,   318,
    -380,    34,  -380,   267,   281,   372,   300,   310,   311,   104,
     356,     0,  -380,  -380,   391,   334,  -380,   107,  -380,  -380,
    -380,  -380,  -380,  -380,   206,   412,   387,   411,   351,   405,
     422,  -380,   294,   415,   419,    30,   407,   410,   356,  -380,
     434,   434,    14,  -380,  -380,  -380,  -380,   -31,   356,  -380,
     428,   363,  -380,  -380,    -9,   267,     0,   448,   375,   376,
     380,   381,    12,  -380,  -380,  -380,   439,  -380,  -380,  -380,
    -380,  -380,   460,  1076,   394,   447,   459,   463,   479,   405,
    -380,  -380,    16,  -380,   356,  -380,   356,   356,   469,   462,
    -380,    -3,    52,  -380,  -380,  -380,  -380,    14,   320,   834,
     356,   416,    59,    32,  -380,    14,   488,   492,   428,  -380,
     434,   434,    14,   245,  -380,   453,   437,  -380,   450,  -380,
    -380,  -380,  -380,  -380,  -380,  -380,  -380,  -380,   444,   460,
     517,  -380,   518,   449,   534,  -380,   468,  -380,  -380,   539,
     525,    60,  -380,  -380,   356,   467,   544,   528,   531,   854,
     370,   370,   370,   370,   370,    14,    14,    14,    14,    14,
      14,    14,   476,  -380,  -380,  -380,   356,  -380,  -380,   862,
     356,   356,  -380,   535,    76,    78,   876,  -380,  -380,  -380,
    -380,  -380,   478,   481,   482,   491,   493,   495,   500,   501,
    -380,  -380,  -380,  -380,  -380,   245,   512,    74,   301,   514,
    -380,  -380,  -380,  -380,  -380,  -380,  1052,   136,  -380,   245,
     245,   484,  -380,   490,  -380,   581,   519,  -380,  -380,   523,
    -380,    15,   527,   522,    18,  -380,  -380,  -380,   383,  -380,
     520,   536,  -380,   270,   270,  -380,  -380,  -380,   171,   127,
     570,  -380,   174,   132,   360,  -380,   144,   529,  -380,  -380,
     537,   586,   592,   543,   245,   245,   245,   245,   245,   245,
     245,   245,   374,   545,    62,  -380,  -380,  -380,  -380,  -380,
      63,  -380,  -380,   551,   554,   558,   563,   564,   566,   629,
     245,   245,   245,   245,   245,   245,   245,   245,   245,   245,
     245,   245,   245,   245,  -380,   649,  1052,   553,   361,   569,
     449,   534,   572,   565,  -380,   539,  -380,   571,   645,  -380,
     574,  -380,  -380,   573,   576,   383,   383,    20,  -380,  -380,
     383,   578,   580,  -380,   966,   985,  1009,   670,   690,   711,
    1028,   731,  -380,    81,   512,  -380,    74,    63,  -380,   903,
     230,   159,   616,  -380,  1071,  1071,  1077,  1077,   424,   259,
     181,   374,  1052,   575,  -380,   498,  -380,   647,  -380,  -380,
      74,   170,    74,   128,  -380,  -380,   645,   584,   483,   383,
     588,  -380,   151,   180,   643,  -380,   195,   589,   383,   383,
    -380,   245,   245,   245,  -380,  -380,  -380,     2,  -380,   545,
    -380,  -380,   593,   590,   597,  -380,   192,  -380,   179,   602,
     182,  -380,   600,  -380,   198,   598,  -380,  -380,  -380,   604,
     483,   594,  -380,   383,  -380,  -380,  -380,   607,   226,   229,
     291,   752,   772,   793,   605,   245,  -380,  -380,  -380,   245,
    -380,   509,  -380,   682,    74,  -380,    74,  -380,    74,  -380,
    -380,   383,   406,  -380,   611,   612,   676,  -380,  -380,  -380,
     636,  -380,  -380,  -380,  -380,  -380,   249,  1052,   925,   541,
    -380,   628,  -380,   234,   256,  -380,  -380,  -380,  -380,   289,
    -380,  -380,   630,   631,   245,   625,   639,  -380,   702,  -380,
    -380,   417,   443,  -380,    14,   555,  -380,  -380,  1052,  -380,
     245,   696,  -380,  -380,  -380,   446,   883,  -380,  -380,  -380,
     944,   293,  -380,  -380,   644,   568,   582,  -380,  -380,   245,
    -380,  -380,  -380,   595,   813,   472,  -380,   648,  -380,  -380,
     608,  -380
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     3,     1,     0,     0,     0,     5,
       0,     2,     0,    14,    56,     7,     0,     0,    37,    12,
      13,    61,   231,     0,     0,    22,    40,     0,    10,     0,
      11,    54,    67,    83,     0,     0,     0,     0,     0,     0,
       0,     0,    55,    57,     0,     0,    59,     0,    60,    58,
      63,    64,    65,    66,   237,     0,     0,     0,     0,     0,
       0,    38,    40,     0,     0,     0,     0,     0,     0,   121,
       0,     0,     0,     6,    89,    68,    80,     0,     0,    75,
      77,     0,    62,    81,    54,    83,     0,     0,     0,     0,
       0,     0,     0,   234,   233,   232,     0,   209,   210,   211,
     212,   230,     0,     0,     0,     0,     0,     0,     0,    23,
      26,    54,     0,    39,     0,    84,     0,     0,     0,     0,
     120,     0,     0,   100,   101,   111,   112,     0,   110,     0,
       0,     0,     0,     0,    74,     0,     0,     0,    77,   219,
       0,     0,     0,     0,     8,     0,     0,   208,     0,   236,
     131,   132,   133,   134,   135,   136,   137,   138,     0,     0,
       0,   238,     0,     0,     0,     4,     0,    25,    43,     0,
      47,     0,    72,    71,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    79,    82,    76,     0,    86,    78,     0,
       0,     0,    73,     0,     0,     0,     0,   128,   160,   161,
     140,   141,     0,     0,     0,     0,     0,     0,     0,     0,
     129,   130,   164,   162,   163,     0,     0,     0,     0,   180,
     156,   157,   158,   159,   179,   184,   205,     0,   206,     0,
       0,     0,   200,     0,   202,     0,    15,    18,    21,    16,
      20,     0,    46,     0,     0,    41,    85,    88,     0,   119,
       0,     0,   109,    95,    96,    97,    98,    99,   102,   103,
     104,   105,   107,   106,   108,    56,     0,     0,    70,    69,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   186,     0,     0,   149,   145,   143,   142,   144,
       0,   155,   154,     0,   160,   161,   162,   163,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   203,     0,   199,     0,     0,     0,
       0,     0,     0,     0,    27,     0,    44,    51,     0,    49,
       0,   114,   113,     0,     0,     0,     0,    61,    87,    56,
       0,     0,     0,   228,     0,     0,     0,     0,     0,     0,
       0,     0,   152,     0,     0,   147,     0,     0,   185,     0,
     189,   190,   187,   188,   193,   194,   191,   192,   195,   196,
     197,   198,   204,     0,   139,     0,   201,     0,    17,    19,
       0,     0,     0,     0,    28,    45,     0,     0,    52,     0,
       0,   118,     0,     0,     0,   127,    61,     0,     0,     0,
     231,     0,     0,     0,   171,   172,   176,     0,   175,     0,
     150,   148,     0,     0,   181,   213,     0,   167,     0,     0,
       0,    36,     0,    29,     0,     0,    30,    50,    48,     0,
      52,   115,    56,     0,   123,   125,    92,     0,     0,     0,
     237,     0,     0,     0,     0,     0,   151,   153,   146,     0,
     231,     0,   165,     0,     0,    32,     0,    34,     0,    42,
      53,     0,    61,   117,     0,     0,    94,   220,   222,   225,
       0,   229,   168,   169,   170,   173,     0,   178,     0,   237,
     166,     0,    35,     0,     0,   116,   122,    56,    56,     0,
      90,   231,     0,     0,     0,     0,   182,   216,     0,    31,
      33,    61,    61,    56,     0,   237,   223,   226,   177,   174,
       0,   218,     9,   124,   126,    61,     0,   221,   231,   231,
       0,     0,   214,    93,     0,   237,   237,   183,   231,     0,
      56,   224,   227,   237,     0,    61,   217,     0,    91,   231,
     237,   215
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -380,  -380,  -380,  -380,  -380,  -380,  -380,  -380,  -380,  -380,
     706,   708,  -380,  -380,   397,  -380,  -380,  -380,   621,  -380,
    -380,  -380,  -380,  -379,  -380,  -380,   673,  -380,  -380,  -380,
     413,  -380,  -288,   302,    77,  -261,  -380,  -340,  -380,   -12,
    -380,   655,   609,   -73,  -380,    43,  -380,  -380,  -380,  -380,
    -380,  -380,   172,  -126,  -359,  -256,  -295,   -34,  -380,  -380,
    -380,  -380,  -380,  -380,  -380,  -380,   505,  -380,  -380,  -216,
    -207,  -380,  -380,   385,  -380,  -148,  -217,  -360,  -380,  -380,
    -380,  -380,  -143,   253,  -380,  -380,  -380,  -380,  -380,  -380,
    -380,  -380,  -380,  -380,  -380,  -380,  -380,  -380,  -380,  -380,
    -380,  -380,  -380,  -380,  -380,  -338,  -380,  -380,  -380
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     2,     3,     8,     7,    14,    11,    22,    13,    18,
      19,    20,   246,   249,   250,    58,    59,   109,   110,   394,
     334,   391,   393,   430,    25,    26,    61,    62,   340,   170,
     253,   255,   339,   439,    41,    21,    42,    43,    44,    45,
      46,    80,   134,    77,    47,    66,   198,    48,    49,    82,
     476,   500,   128,   129,   343,   401,   402,   121,    50,   119,
      51,   474,    52,   475,    53,   229,   159,   160,   230,   301,
     231,   232,   294,   295,   363,   233,   431,   234,   386,   428,
     235,   486,   326,   149,   161,    93,   237,    94,    95,    96,
     147,   460,   521,   532,    97,   203,   501,    98,   502,   528,
      99,   503,   529,   100,   410,    54,   101,   102,   103
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     236,   179,   344,    75,    32,   132,   454,    31,    32,   199,
     303,   -83,   308,   434,   347,   247,   206,   123,   124,   168,
     302,   337,    33,    31,    32,   427,    34,   144,    76,    79,
      35,    36,    37,    75,    32,    75,    32,   122,    33,    38,
     441,   171,    34,   130,   125,   126,    35,    36,    37,   131,
     397,   403,     1,   115,   -83,    38,   118,     4,   440,   268,
     269,   270,   271,   272,   273,   274,    76,   296,     5,   297,
     145,   176,   450,    65,    79,    39,    67,   177,   296,    78,
     297,   455,   292,    40,   308,   309,   362,   493,   406,   494,
     332,   404,   333,   127,   407,   169,   325,   338,   405,    40,
     440,   490,    76,     9,   172,   173,   204,   205,   437,   114,
      84,   196,   495,   448,   449,   -68,    65,    73,   193,   298,
     299,   197,   489,   276,    86,    85,   176,   136,   137,    74,
     298,   299,   178,   130,   130,     6,   364,   112,   365,   195,
     256,   354,   355,   356,   357,   358,   359,   360,   361,   422,
     176,   423,   176,   300,    10,   419,   281,   420,   282,   302,
     187,   188,   257,   515,    12,   187,   188,   369,   370,   371,
     372,   373,   374,   375,   376,   377,   378,   379,   380,   381,
     382,   472,   388,   302,    76,   302,    16,   473,   278,   279,
     535,   536,   313,   314,   189,   190,   191,    15,    31,    32,
     543,   191,   435,   186,   187,   188,   436,   187,   188,  -235,
     323,   550,   456,    33,   313,   314,   324,    34,   130,   362,
      17,    35,    36,    37,   348,   443,   320,   321,   322,  -207,
      38,   444,    87,    88,    89,    23,   511,   512,   189,   190,
     191,    90,   190,   191,   432,    24,   433,   492,   207,   208,
     322,   209,   525,   461,   443,   462,   464,   302,   465,   302,
     445,   302,   312,   313,   314,    91,   404,   293,   451,   452,
     453,   300,   464,   446,    40,   210,   211,    92,   467,   545,
      27,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,    29,   313,   314,  -235,   222,    55,   320,   321,   322,
     443,   223,   224,   443,   207,   304,   478,   305,   464,   479,
     509,   -24,   487,    60,  -207,   225,   488,    87,    88,    89,
     226,    63,   227,   504,   228,    64,    90,   321,   322,   505,
     464,   210,   211,   182,   183,   184,   510,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,    56,    57,    65,
      91,   222,   263,   264,   265,   266,   267,   306,   307,    75,
      32,   518,   480,    68,   207,   208,   513,   209,   514,   481,
     538,   225,   539,   123,   124,    69,   226,   530,   227,    70,
     228,   180,   181,   182,   183,   184,   341,   342,   526,    71,
      72,   210,   211,   187,   188,   105,   544,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   313,   314,    31,
      32,   222,   242,   244,    81,    83,   104,   223,   224,   106,
      31,    32,   107,   108,    33,   111,    57,   116,    34,    56,
     117,   225,    35,    36,    37,    33,   385,   120,   227,    34,
     228,    38,   135,    35,    36,    37,    31,    32,   133,    31,
      32,   139,    38,   311,   140,   141,   312,   313,   314,   142,
     143,    33,   146,   148,    33,    34,   162,   163,    34,    35,
      36,    37,    35,    36,    37,    31,    32,   404,    38,   164,
     165,    38,   166,   175,   496,    40,    31,    32,   404,   174,
      33,   320,   321,   322,    34,   523,    40,   194,    35,    36,
      37,    33,   208,   238,   209,    34,   -61,    38,   200,    35,
      36,    37,   201,   208,   404,   209,   239,   404,    38,   241,
     243,   524,    40,   240,   533,    40,   227,   245,   210,   211,
     150,   151,   152,   153,   154,   155,   156,   157,   248,   210,
     211,   251,   252,   404,  -235,   254,   258,   259,   222,   260,
     548,    40,   261,   275,   223,   224,   280,   284,  -235,   222,
     285,   286,    40,   328,  -207,   223,   224,    87,    88,    89,
     287,  -235,   288,   426,   289,   227,    90,   300,  -207,   290,
     291,    87,    88,    89,   226,  -235,   227,   293,   300,   310,
      90,  -207,   329,   330,    87,    88,    89,   331,  -235,   345,
      91,   335,   336,    90,   188,  -207,   349,   351,    87,    88,
      89,  -235,   480,   352,    91,   346,   350,    90,  -207,   507,
     353,    87,    88,    89,   300,   366,   480,    91,  -145,   384,
      90,  -207,  -143,   527,    87,    88,    89,  -142,  -144,   480,
     367,    91,   387,    90,   392,   396,   541,   390,   337,   398,
     314,   429,   425,   480,    91,   399,   400,   408,   311,   409,
     542,   312,   313,   314,   438,   442,   480,    91,    74,   447,
     458,   457,   459,   546,   463,   466,   471,   468,   311,   480,
     469,   312,   313,   314,   477,   485,   551,   491,   497,   498,
     315,   316,   317,   318,   145,   319,   320,   321,   322,   311,
     499,   508,   312,   313,   314,   519,   522,   516,   517,   368,
     315,   316,   317,   318,   520,   319,   320,   321,   322,   311,
     531,   540,   312,   313,   314,   549,    30,    28,   389,   383,
     167,   315,   316,   317,   318,   113,   319,   320,   321,   322,
     311,   138,   470,   312,   313,   314,   327,   202,   395,   421,
     414,   315,   316,   317,   318,     0,   319,   320,   321,   322,
     311,     0,     0,   312,   313,   314,     0,     0,     0,     0,
     415,     0,   315,   316,   317,   318,     0,   319,   320,   321,
     322,   311,     0,     0,   312,   313,   314,     0,     0,     0,
       0,   416,   315,   316,   317,   318,     0,   319,   320,   321,
     322,   311,     0,     0,   312,   313,   314,     0,     0,     0,
       0,   418,     0,   315,   316,   317,   318,     0,   319,   320,
     321,   322,   311,     0,     0,   312,   313,   314,     0,     0,
       0,     0,   482,   315,   316,   317,   318,     0,   319,   320,
     321,   322,   311,     0,     0,   312,   313,   314,     0,     0,
       0,     0,   483,     0,   315,   316,   317,   318,     0,   319,
     320,   321,   322,   185,     0,     0,   186,   187,   188,     0,
       0,     0,     0,   484,   315,   316,   317,   318,     0,   319,
     320,   321,   322,   185,     0,     0,   186,   187,   188,     0,
       0,   185,     0,   547,   186,   187,   188,     0,     0,     0,
       0,   189,   190,   191,     0,   185,     0,     0,   186,   187,
     188,     0,   185,     0,   192,   186,   187,   188,     0,     0,
       0,   189,   190,   191,     0,     0,     0,     0,     0,   189,
     190,   191,   311,     0,   262,   312,   313,   314,     0,     0,
       0,     0,   277,   189,   190,   191,     0,     0,     0,     0,
     189,   190,   191,     0,   311,     0,   283,   312,   313,   314,
       0,     0,     0,   534,   315,   316,   317,   318,     0,   319,
     320,   321,   322,   311,     0,     0,   312,   313,   314,   424,
       0,     0,     0,     0,     0,     0,   315,   316,   317,   318,
       0,   319,   320,   321,   322,   311,     0,     0,   312,   313,
     314,   506,     0,     0,     0,   315,   316,   317,   318,     0,
     319,   320,   321,   322,   311,     0,     0,   312,   313,   314,
     537,     0,     0,     0,     0,     0,     0,   315,   316,   317,
     318,     0,   319,   320,   321,   322,     0,     0,   311,     0,
     411,   312,   313,   314,     0,     0,   315,   316,   317,   318,
       0,   319,   320,   321,   322,     0,     0,   311,     0,   412,
     312,   313,   314,     0,     0,     0,     0,     0,     0,     0,
     315,   316,   317,   318,     0,   319,   320,   321,   322,     0,
       0,   311,     0,   413,   312,   313,   314,     0,     0,   315,
     316,   317,   318,     0,   319,   320,   321,   322,     0,     0,
     311,     0,   417,   312,   313,   314,   311,     0,     0,   312,
     313,   314,     0,   315,   316,   317,   318,     0,   319,   320,
     321,   322,   150,   151,   152,   153,   154,   155,   156,   157,
       0,   158,     0,     0,   317,   318,     0,   319,   320,   321,
     322,     0,     0,   319,   320,   321,   322
};

static const yytype_int16 yycheck[] =
{
     143,   127,   258,     3,     4,    78,     4,     3,     4,   135,
     227,    20,   228,   392,   275,   163,   142,     3,     4,     3,
     227,     3,    18,     3,     4,   385,    22,    15,    40,    41,
      26,    27,    28,     3,     4,     3,     4,    71,    18,    35,
     399,   114,    22,    74,    30,    31,    26,    27,    28,    80,
     338,   346,    71,    65,    20,    35,    68,    16,   398,   185,
     186,   187,   188,   189,   190,   191,    78,     4,     0,     6,
      58,    74,   410,    82,    86,    71,    33,    80,     4,    79,
       6,    79,   225,    79,   300,   228,   293,   466,   349,   468,
      75,    71,    77,    79,   350,    79,   239,    79,    78,    79,
     440,   461,   114,    12,   116,   117,   140,   141,   396,    79,
       3,    79,   471,   408,   409,    81,    82,    13,   130,    56,
      57,   133,   460,   196,    47,    18,    74,    84,    85,    25,
      56,    57,    80,    74,    74,    71,    74,    60,    76,    80,
      80,   284,   285,   286,   287,   288,   289,   290,   291,   366,
      74,   367,    74,    79,    71,    74,    80,    76,    80,   366,
      33,    34,   174,   501,    72,    33,    34,   310,   311,   312,
     313,   314,   315,   316,   317,   318,   319,   320,   321,   322,
     323,   442,   330,   390,   196,   392,     9,   443,   200,   201,
     528,   529,    33,    34,    67,    68,    69,    14,     3,     4,
     538,    69,    74,    32,    33,    34,    78,    33,    34,     3,
      74,   549,   419,    18,    33,    34,    80,    22,    74,   426,
      72,    26,    27,    28,    80,    74,    67,    68,    69,    23,
      35,    80,    26,    27,    28,    10,   497,   498,    67,    68,
      69,    35,    68,    69,    74,     7,    76,   464,     3,     4,
      69,     6,   513,    74,    74,    76,    74,   464,    76,   466,
      80,   468,    32,    33,    34,    59,    71,    75,   411,   412,
     413,    79,    74,    78,    79,    30,    31,    71,    80,   540,
      72,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    72,    33,    34,     3,    50,    73,    67,    68,    69,
      74,    56,    57,    74,     3,     4,    80,     6,    74,    80,
      76,    71,   455,    19,    23,    70,   459,    26,    27,    28,
      75,     7,    77,    74,    79,     7,    35,    68,    69,    80,
      74,    30,    31,    63,    64,    65,    80,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    10,    11,    82,
      59,    50,   180,   181,   182,   183,   184,    56,    57,     3,
       4,   504,    71,    82,     3,     4,    77,     6,    79,    78,
      77,    70,    79,     3,     4,     3,    75,   520,    77,    79,
      79,    61,    62,    63,    64,    65,     3,     4,   514,    79,
      79,    30,    31,    33,    34,     8,   539,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    33,    34,     3,
       4,    50,   159,   160,    23,    81,     4,    56,    57,     8,
       3,     4,    71,    18,    18,     3,    11,    20,    22,    10,
      20,    70,    26,    27,    28,    18,    75,     3,    77,    22,
      79,    35,    79,    26,    27,    28,     3,     4,    20,     3,
       4,     3,    35,    29,    79,    79,    32,    33,    34,    79,
      79,    18,    23,     3,    18,    22,    72,    20,    22,    26,
      27,    28,    26,    27,    28,     3,     4,    71,    35,    20,
      17,    35,     3,    21,    78,    79,     3,     4,    71,    20,
      18,    67,    68,    69,    22,    78,    79,    81,    26,    27,
      28,    18,     4,    50,     6,    22,    23,    35,    20,    26,
      27,    28,    20,     4,    71,     6,    79,    71,    35,    75,
       3,    78,    79,    73,    78,    79,    77,     9,    30,    31,
      46,    47,    48,    49,    50,    51,    52,    53,     4,    30,
      31,    73,     3,    71,     3,    20,    79,     3,    50,    21,
      78,    79,    21,    77,    56,    57,    21,    79,     3,    50,
      79,    79,    79,    73,    23,    56,    57,    26,    27,    28,
      79,     3,    79,    75,    79,    77,    35,    79,    23,    79,
      79,    26,    27,    28,    75,     3,    77,    75,    79,    75,
      35,    23,    11,    74,    26,    27,    28,    74,     3,    79,
      59,    74,    80,    35,    34,    23,    77,    21,    26,    27,
      28,     3,    71,    21,    59,    79,    79,    35,    23,    78,
      77,    26,    27,    28,    79,    74,    71,    59,    74,    76,
      35,    23,    74,    78,    26,    27,    28,    74,    74,    71,
      74,    59,    73,    35,    79,    74,    78,    75,     3,    75,
      34,     4,    77,    71,    59,    82,    80,    79,    29,    79,
      78,    32,    33,    34,    80,    77,    71,    59,    25,    80,
      80,    78,    75,    78,    72,    75,    82,    79,    29,    71,
      76,    32,    33,    34,    77,    80,    78,     5,    77,    77,
      61,    62,    63,    64,    58,    66,    67,    68,    69,    29,
      24,    73,    32,    33,    34,    80,     4,    77,    77,    80,
      61,    62,    63,    64,    75,    66,    67,    68,    69,    29,
      24,    77,    32,    33,    34,    77,    20,    19,   331,    80,
     109,    61,    62,    63,    64,    62,    66,    67,    68,    69,
      29,    86,   440,    32,    33,    34,   241,   138,   335,   364,
      80,    61,    62,    63,    64,    -1,    66,    67,    68,    69,
      29,    -1,    -1,    32,    33,    34,    -1,    -1,    -1,    -1,
      80,    -1,    61,    62,    63,    64,    -1,    66,    67,    68,
      69,    29,    -1,    -1,    32,    33,    34,    -1,    -1,    -1,
      -1,    80,    61,    62,    63,    64,    -1,    66,    67,    68,
      69,    29,    -1,    -1,    32,    33,    34,    -1,    -1,    -1,
      -1,    80,    -1,    61,    62,    63,    64,    -1,    66,    67,
      68,    69,    29,    -1,    -1,    32,    33,    34,    -1,    -1,
      -1,    -1,    80,    61,    62,    63,    64,    -1,    66,    67,
      68,    69,    29,    -1,    -1,    32,    33,    34,    -1,    -1,
      -1,    -1,    80,    -1,    61,    62,    63,    64,    -1,    66,
      67,    68,    69,    29,    -1,    -1,    32,    33,    34,    -1,
      -1,    -1,    -1,    80,    61,    62,    63,    64,    -1,    66,
      67,    68,    69,    29,    -1,    -1,    32,    33,    34,    -1,
      -1,    29,    -1,    80,    32,    33,    34,    -1,    -1,    -1,
      -1,    67,    68,    69,    -1,    29,    -1,    -1,    32,    33,
      34,    -1,    29,    -1,    80,    32,    33,    34,    -1,    -1,
      -1,    67,    68,    69,    -1,    -1,    -1,    -1,    -1,    67,
      68,    69,    29,    -1,    80,    32,    33,    34,    -1,    -1,
      -1,    -1,    80,    67,    68,    69,    -1,    -1,    -1,    -1,
      67,    68,    69,    -1,    29,    -1,    80,    32,    33,    34,
      -1,    -1,    -1,    80,    61,    62,    63,    64,    -1,    66,
      67,    68,    69,    29,    -1,    -1,    32,    33,    34,    76,
      -1,    -1,    -1,    -1,    -1,    -1,    61,    62,    63,    64,
      -1,    66,    67,    68,    69,    29,    -1,    -1,    32,    33,
      34,    76,    -1,    -1,    -1,    61,    62,    63,    64,    -1,
      66,    67,    68,    69,    29,    -1,    -1,    32,    33,    34,
      76,    -1,    -1,    -1,    -1,    -1,    -1,    61,    62,    63,
      64,    -1,    66,    67,    68,    69,    -1,    -1,    29,    -1,
      74,    32,    33,    34,    -1,    -1,    61,    62,    63,    64,
      -1,    66,    67,    68,    69,    -1,    -1,    29,    -1,    74,
      32,    33,    34,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      61,    62,    63,    64,    -1,    66,    67,    68,    69,    -1,
      -1,    29,    -1,    74,    32,    33,    34,    -1,    -1,    61,
      62,    63,    64,    -1,    66,    67,    68,    69,    -1,    -1,
      29,    -1,    74,    32,    33,    34,    29,    -1,    -1,    32,
      33,    34,    -1,    61,    62,    63,    64,    -1,    66,    67,
      68,    69,    46,    47,    48,    49,    50,    51,    52,    53,
      -1,    55,    -1,    -1,    63,    64,    -1,    66,    67,    68,
      69,    -1,    -1,    66,    67,    68,    69
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
     141,   143,   145,   147,   188,    73,    10,    11,    98,    99,
      19,   109,   110,     7,     7,    82,   128,   128,    82,     3,
      79,    79,    79,    13,    25,     3,   122,   126,    79,   122,
     124,    23,   132,    81,     3,    18,   117,    26,    27,    28,
      35,    59,    71,   168,   170,   171,   172,   177,   180,   183,
     186,   189,   190,   191,     4,     8,     8,    71,    18,   100,
     101,     3,   117,   109,    79,   122,    20,    20,   122,   142,
       3,   140,   140,     3,     4,    30,    31,    79,   135,   136,
      74,    80,   126,    20,   125,    79,   128,   128,   124,     3,
      79,    79,    79,    79,    15,    58,    23,   173,     3,   166,
      46,    47,    48,    49,    50,    51,    52,    53,    55,   149,
     150,   167,    72,    20,    20,    17,     3,   101,     3,    79,
     112,   126,   122,   122,    20,    21,    74,    80,    80,   136,
      61,    62,    63,    64,    65,    29,    32,    33,    34,    67,
      68,    69,    80,   122,    81,    80,    79,   122,   129,   136,
      20,    20,   125,   178,   140,   140,   136,     3,     4,     6,
      30,    31,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    50,    56,    57,    70,    75,    77,    79,   148,
     151,   153,   154,   158,   160,   163,   165,   169,    50,    79,
      73,    75,   166,     3,   166,     9,    95,   158,     4,    96,
      97,    73,     3,   113,    20,   114,    80,   122,    79,     3,
      21,    21,    80,   135,   135,   135,   135,   135,   136,   136,
     136,   136,   136,   136,   136,    77,   126,    80,   122,   122,
      21,    80,    80,    80,    79,    79,    79,    79,    79,    79,
      79,    79,   165,    75,   155,   156,     4,     6,    56,    57,
      79,   152,   153,   159,     4,     6,    56,    57,   152,   165,
      75,    29,    32,    33,    34,    61,    62,    63,    64,    66,
      67,    68,    69,    74,    80,   165,   165,   149,    73,    11,
      74,    74,    75,    77,   103,    74,    80,     3,    79,   115,
     111,     3,     4,   137,   138,    79,    79,   118,    80,    77,
      79,    21,    21,    77,   165,   165,   165,   165,   165,   165,
     165,   165,   153,   157,    74,    76,    74,    74,    80,   165,
     165,   165,   165,   165,   165,   165,   165,   165,   165,   165,
     165,   165,   165,    80,    76,    75,   161,    73,   158,    97,
      75,   104,    79,   105,   102,   113,    74,   115,    75,    82,
      80,   138,   139,   139,    71,    78,   118,   138,    79,    79,
     187,    74,    74,    74,    80,    80,    80,    74,    80,    74,
      76,   156,   159,   152,    76,    77,    75,   160,   162,     4,
     106,   159,    74,    76,   106,    74,    78,   115,    80,   116,
     120,   137,    77,    74,    80,    80,    78,    80,   139,   139,
     188,   165,   165,   165,     4,    79,   153,    78,    80,    75,
     174,    74,    76,    72,    74,    76,    75,    80,    79,    76,
     116,    82,   118,   138,   144,   146,   133,    77,    80,    80,
      71,    78,    80,    80,    80,    80,   164,   165,   165,   188,
     160,     5,   159,   106,   106,   137,    78,    77,    77,    24,
     134,   179,   181,   184,    74,    80,    76,    78,    73,    76,
      80,   118,   118,    77,    79,   188,    77,    77,   165,    80,
      75,   175,     4,    78,    78,   118,   136,    78,   182,   185,
     165,    24,   176,    78,    80,   188,   188,    76,    77,    79,
      77,    78,    78,   188,   165,   118,    78,    80,    78,    77,
     188,    78
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
     156,   157,   157,   158,   159,   159,   160,   160,   160,   160,
     160,   160,   160,   160,   160,   161,   162,   162,   163,   163,
     163,   163,   163,   163,   163,   163,   163,   164,   164,   165,
     165,   165,   165,   165,   165,   165,   165,   165,   165,   165,
     165,   165,   165,   165,   165,   165,   165,   165,   165,   166,
     167,   167,   167,   168,   169,   169,   170,   172,   171,   171,
     171,   171,   171,   174,   173,   175,   175,   176,   176,   178,
     179,   177,   181,   182,   180,   184,   185,   183,   187,   186,
     188,   188,   189,   189,   189,   190,   189,   191,   189
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
       3,     3,     1,     5,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     3,     1,     6,     6,
       6,     4,     4,     6,     8,     4,     4,     3,     1,     1,
       1,     4,     7,    10,     1,     3,     2,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       2,     4,     2,     4,     3,     1,     3,     0,     2,     1,
       1,     1,     1,     0,    10,     8,     0,     4,     0,     0,
       0,    11,     0,     0,    13,     0,     0,    13,     0,     8,
       2,     0,     1,     1,     1,     0,     2,     0,     2
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
#line 66 "./Parser/parser_main.y"
                                                                   {fprintf(fp,"\nParsing successful!\n");}
#line 1788 "./exec/y.tab.c"
    break;

  case 3: /* $@1: %empty  */
#line 70 "./Parser/parser_main.y"
                                           {fprintf(fp,"\nInit section begins\n\n");}
#line 1794 "./exec/y.tab.c"
    break;

  case 4: /* init_section: '\\' INIT_BEGIN $@1 mandatory_init set_states block_defn_section gate_defn_section '\\' INIT_END  */
#line 70 "./Parser/parser_main.y"
                                                                                                                                                                   {fprintf(fp,"\nInit section ends\n");}
#line 1800 "./exec/y.tab.c"
    break;

  case 5: /* $@2: %empty  */
#line 73 "./Parser/parser_main.y"
                                            {fprintf(fp,"\nMain section begins\n\n");}
#line 1806 "./exec/y.tab.c"
    break;

  case 6: /* main_section: '\\' MAIN_BEGIN $@2 main_stmt_list '\\' MAIN_END  */
#line 73 "./Parser/parser_main.y"
                                                                                                                    {fprintf(fp,"\nMain section ends\n");}
#line 1812 "./exec/y.tab.c"
    break;

  case 7: /* $@3: %empty  */
#line 76 "./Parser/parser_main.y"
                                             {fprintf(fp,"\nOutput section begins\n\n"); isInOutput = true; outputLevel = 1;}
#line 1818 "./exec/y.tab.c"
    break;

  case 8: /* output_section: '\\' OUTPUT_BEGIN $@3 out_main '\\' OUTPUT_END  */
#line 76 "./Parser/parser_main.y"
                                                                                                                                                        {fprintf(fp,"\nOutput section ends\n");exitOutputSymbolScope(&OutputSymbolTable,outputLevel);}
#line 1824 "./exec/y.tab.c"
    break;

  case 9: /* mandatory_init: '#' REGISTERS QUANTUM '=' NUMBER '#' REGISTERS CLASSICAL '=' NUMBER '#' ITERS '=' NUMBER  */
#line 84 "./Parser/parser_main.y"
                                                                                                                    {  fprintf(fp,"Register and iteration initialization section\n");classical_registers = yyvsp[-4].num;quantum_registers = yyvsp[-9].num;iterations = yyvsp[0].num;}
#line 1830 "./exec/y.tab.c"
    break;

  case 15: /* set_quantum_states: '#' SET QUANTUM STATES ARROW quantum_state_list  */
#line 95 "./Parser/parser_main.y"
                                                                            {fprintf(fp,"Setting initial state of quantum registers\n");}
#line 1836 "./exec/y.tab.c"
    break;

  case 16: /* set_classical_states: '#' SET CLASSICAL STATES ARROW classical_state_list  */
#line 98 "./Parser/parser_main.y"
                                                                                {fprintf(fp,"Setting initial state of classical registers\n");}
#line 1842 "./exec/y.tab.c"
    break;

  case 17: /* quantum_state_list: quantum_state_list ',' state_const  */
#line 101 "./Parser/parser_main.y"
                                                                     {if(quantum_index == quantum_registers){yyerror();return;}quantum_states[quantum_index++] = yyvsp[0].q;}
#line 1848 "./exec/y.tab.c"
    break;

  case 18: /* quantum_state_list: state_const  */
#line 102 "./Parser/parser_main.y"
                                          {quantum_states = (struct Quantum*)malloc(sizeof(struct Quantum)*quantum_registers);quantum_states[quantum_index++] = yyvsp[0].q;}
#line 1854 "./exec/y.tab.c"
    break;

  case 19: /* classical_state_list: classical_state_list ',' classical_state  */
#line 105 "./Parser/parser_main.y"
                                                                      {if(classical_index == classical_registers){yyerror();return;}classical_states[classical_index++] = yyvsp[0].num;}
#line 1860 "./exec/y.tab.c"
    break;

  case 20: /* classical_state_list: classical_state  */
#line 106 "./Parser/parser_main.y"
                                            {classical_states = (int *)malloc(sizeof(int)*classical_registers);classical_states[classical_index++] = yyvsp[0].num;}
#line 1866 "./exec/y.tab.c"
    break;

  case 21: /* classical_state: NUMBER  */
#line 109 "./Parser/parser_main.y"
                                    {yyval.num = yyvsp[0].num;}
#line 1872 "./exec/y.tab.c"
    break;

  case 22: /* $@4: %empty  */
#line 113 "./Parser/parser_main.y"
                           {fprintf(fp,"Gate definition section begins\n");}
#line 1878 "./exec/y.tab.c"
    break;

  case 23: /* gate_defn_section: $@4 gate_defn_list  */
#line 113 "./Parser/parser_main.y"
                                                                                            {fprintf(fp,"Gate definition section ends\n");}
#line 1884 "./exec/y.tab.c"
    break;

  case 27: /* $@5: %empty  */
#line 121 "./Parser/parser_main.y"
                                            {fprintf(fp,"Gate definition\n");}
#line 1890 "./exec/y.tab.c"
    break;

  case 28: /* gate_defn: GATE ID '=' rhs $@5  */
#line 121 "./Parser/parser_main.y"
                                                                                 {insertInGateTable(&GateSymbolTable,yyvsp[-3].str,yyvsp[-1].rows,yyvsp[-1].cols);}
#line 1896 "./exec/y.tab.c"
    break;

  case 29: /* rhs: '[' tuple_list ']'  */
#line 124 "./Parser/parser_main.y"
                                                {yyval.rows = yyvsp[-1].rows;yyval.cols = yyvsp[-1].cols;}
#line 1902 "./exec/y.tab.c"
    break;

  case 31: /* tuple_list: tuple_list ',' '[' id_list ']'  */
#line 127 "./Parser/parser_main.y"
                                                         {if(yyvsp[-4].cols != yyvsp[-1].cols){yyerror();return;}int temp; temp = yyvsp[-4].rows + 1;yyval.rows = temp;yyval.cols = yyvsp[-4].cols;}
#line 1908 "./exec/y.tab.c"
    break;

  case 32: /* tuple_list: '[' id_list ']'  */
#line 128 "./Parser/parser_main.y"
                                                         {yyval.rows = 1;yyval.cols = yyvsp[-1].cols;}
#line 1914 "./exec/y.tab.c"
    break;

  case 35: /* id_list: id_list ',' temp  */
#line 133 "./Parser/parser_main.y"
                                             {yyval.cols += 1;}
#line 1920 "./exec/y.tab.c"
    break;

  case 36: /* id_list: temp  */
#line 134 "./Parser/parser_main.y"
                                             {yyval.cols = 1;}
#line 1926 "./exec/y.tab.c"
    break;

  case 37: /* $@6: %empty  */
#line 137 "./Parser/parser_main.y"
                           {fprintf(fp,"Block definition section begins\n");}
#line 1932 "./exec/y.tab.c"
    break;

  case 38: /* block_defn_section: $@6 block_defns_list  */
#line 137 "./Parser/parser_main.y"
                                                                                               {fprintf(fp,"Block definition section ends\n");}
#line 1938 "./exec/y.tab.c"
    break;

  case 41: /* $@7: %empty  */
#line 144 "./Parser/parser_main.y"
                                                              {insertInBlockTable(&BlockSymbolTable,yyvsp[-2].str,yyvsp[-1].num,head);head = NULL;isInBlock = 1;}
#line 1944 "./exec/y.tab.c"
    break;

  case 42: /* block_defn: BLOCK block_id params target_params $@7 '[' block_body ']'  */
#line 144 "./Parser/parser_main.y"
                                                                                                                                                                      {fprintf(fp,"Block definition\n");if(!BlockSemanticCheck(yyvsp[-6].str)){yyerror();return;}id_list = NULL;isInBlock = 0;}
#line 1950 "./exec/y.tab.c"
    break;

  case 43: /* params: ID  */
#line 147 "./Parser/parser_main.y"
                                                {insertInList(&head,yyvsp[0].str);yyval.num = 1;}
#line 1956 "./exec/y.tab.c"
    break;

  case 44: /* params: '(' param_id_list ')'  */
#line 148 "./Parser/parser_main.y"
                                                {yyval.num = yyvsp[-1].num;}
#line 1962 "./exec/y.tab.c"
    break;

  case 45: /* param_id_list: ID ',' param_id_list  */
#line 151 "./Parser/parser_main.y"
                                                {insertInList(&head,yyvsp[-2].str);yyval.num = 1 + yyvsp[0].num;}
#line 1968 "./exec/y.tab.c"
    break;

  case 46: /* param_id_list: ID  */
#line 152 "./Parser/parser_main.y"
                                                {insertInList(&head,yyvsp[0].str);yyval.num = 1;}
#line 1974 "./exec/y.tab.c"
    break;

  case 54: /* block_id: ID  */
#line 168 "./Parser/parser_main.y"
                                  {if(!firstLetterCapital(yyvsp[0].str)){yyerror(); return;} yyval.str = yyvsp[0].str;}
#line 1980 "./exec/y.tab.c"
    break;

  case 58: /* main_stmt: barrier_stmt  */
#line 181 "./Parser/parser_main.y"
                                          {fprintf(fp,"barrier statement\n");}
#line 1986 "./exec/y.tab.c"
    break;

  case 60: /* stmts: measure_stmt  */
#line 184 "./Parser/parser_main.y"
                                          {fprintf(fp,"Measure statement\n");}
#line 1992 "./exec/y.tab.c"
    break;

  case 61: /* $@8: %empty  */
#line 185 "./Parser/parser_main.y"
                          {fprintf(fp,"Conditional statement begin\n");}
#line 1998 "./exec/y.tab.c"
    break;

  case 62: /* stmts: $@8 condition_stmt  */
#line 185 "./Parser/parser_main.y"
                                                                                        {fprintf(fp,"Conditional statement end\n");}
#line 2004 "./exec/y.tab.c"
    break;

  case 63: /* stmts: for_stmt  */
#line 186 "./Parser/parser_main.y"
                                          {fprintf(fp,"For statement\n");}
#line 2010 "./exec/y.tab.c"
    break;

  case 64: /* stmts: for_lex_stmt  */
#line 187 "./Parser/parser_main.y"
                                          {fprintf(fp,"For - Lex statement\n");}
#line 2016 "./exec/y.tab.c"
    break;

  case 65: /* stmts: for_zip_stmt  */
#line 188 "./Parser/parser_main.y"
                                          {fprintf(fp,"For - Zip statement\n");}
#line 2022 "./exec/y.tab.c"
    break;

  case 66: /* stmts: while_stmt  */
#line 189 "./Parser/parser_main.y"
                                          {fprintf(fp,"while statement\n");}
#line 2028 "./exec/y.tab.c"
    break;

  case 67: /* register: NUMBER  */
#line 192 "./Parser/parser_main.y"
                                  {if(yyvsp[0].num < 0){yyerror(); return;} yyval.num = yyvsp[0].num;yyval.flag=0;}
#line 2034 "./exec/y.tab.c"
    break;

  case 68: /* register: ID  */
#line 193 "./Parser/parser_main.y"
                                  {if(isInBlock){insertInList(&id_list,yyvsp[0].str);}yyval.flag = 1;}
#line 2040 "./exec/y.tab.c"
    break;

  case 69: /* call_stmt: classic_control GATE quantum_control ARROW register  */
#line 198 "./Parser/parser_main.y"
                                                                              {fprintf(fp,"Pre - defined Gate call statement\n");}
#line 2046 "./exec/y.tab.c"
    break;

  case 70: /* call_stmt: classic_control ID quantum_control ARROW register  */
#line 199 "./Parser/parser_main.y"
                                                                              {fprintf(fp,"user - defined Gate call statement\n");}
#line 2052 "./exec/y.tab.c"
    break;

  case 71: /* call_stmt: GATE quantum_control ARROW register  */
#line 200 "./Parser/parser_main.y"
                                                                              {fprintf(fp,"Pre - defined Gate call statement\n");}
#line 2058 "./exec/y.tab.c"
    break;

  case 72: /* call_stmt: ID quantum_control ARROW register  */
#line 201 "./Parser/parser_main.y"
                                                                              {fprintf(fp,"User - defined Gate call statement\n");}
#line 2064 "./exec/y.tab.c"
    break;

  case 73: /* call_stmt: classic_control block_id parameters optional  */
#line 202 "./Parser/parser_main.y"
                                                                              {fprintf(fp,"Block call statement\n");if(!isInBlock){if(!BlockCallSemanticCheck(yyvsp[-2].str,yyvsp[-1].num)){yyerror();return;}}}
#line 2070 "./exec/y.tab.c"
    break;

  case 74: /* call_stmt: block_id parameters optional  */
#line 203 "./Parser/parser_main.y"
                                                                              {fprintf(fp,"Block call statement\n");if(!isInBlock){if(!BlockCallSemanticCheck(yyvsp[-2].str,yyvsp[-1].num)){yyerror();return;}}}
#line 2076 "./exec/y.tab.c"
    break;

  case 75: /* parameters: register  */
#line 206 "./Parser/parser_main.y"
                                                   {yyval.num = 1;}
#line 2082 "./exec/y.tab.c"
    break;

  case 76: /* parameters: '(' register_list ')'  */
#line 207 "./Parser/parser_main.y"
                                                   {yyval.num = yyvsp[-1].num;}
#line 2088 "./exec/y.tab.c"
    break;

  case 79: /* register_list: register_list ',' register  */
#line 214 "./Parser/parser_main.y"
                                                      {yyval.num = 1 + yyvsp[-2].num;}
#line 2094 "./exec/y.tab.c"
    break;

  case 80: /* register_list: register  */
#line 215 "./Parser/parser_main.y"
                                                      {yyval.num = 1;}
#line 2100 "./exec/y.tab.c"
    break;

  case 88: /* measure_stmt: MEASURE ':' register ARROW register  */
#line 242 "./Parser/parser_main.y"
                                                              {if((!yyvsp[-2].flag && (yyvsp[-2].num < 0 || yyvsp[-2].num >= quantum_registers)) || (!yyvsp[0].flag && (yyvsp[0].num < 0 || yyvsp[0].num >= classical_registers))){yyerror(); return;}}
#line 2106 "./exec/y.tab.c"
    break;

  case 117: /* range_list: range_list ',' range  */
#line 290 "./Parser/parser_main.y"
                                                   {yyval.num = 1 + yyvsp[-2].num;}
#line 2112 "./exec/y.tab.c"
    break;

  case 118: /* range_list: range  */
#line 291 "./Parser/parser_main.y"
                                                   {yyval.num = 1;}
#line 2118 "./exec/y.tab.c"
    break;

  case 119: /* var_list: var_list ',' ID  */
#line 294 "./Parser/parser_main.y"
                                             {if(isInOutput){if(getOutputSymbolEntry(&OutputSymbolTable,yyvsp[0].str,outputLevel + 1,0) != NULL){yyerror(); return;} else insertInOutputTable(&OutputSymbolTable,yyvsp[-1].str,outputLevel + 1, Int,true,0,0,true);} else if(!inList(&head,yyvsp[0].str)){insertInList(&head,yyvsp[0].str);} else {yyerror(); return;} yyval.num = 1 + yyvsp[-2].num;}
#line 2124 "./exec/y.tab.c"
    break;

  case 120: /* var_list: ID  */
#line 295 "./Parser/parser_main.y"
                                             {if(isInOutput){if(getOutputSymbolEntry(&OutputSymbolTable,yyvsp[0].str,outputLevel + 1,0) != NULL){yyerror(); return;} else insertInOutputTable(&OutputSymbolTable,yyvsp[0].str,outputLevel + 1, Int,true,0,0,true);} else if(!inList(&head,yyvsp[0].str)){insertInList(&head,yyvsp[0].str);} else {yyerror(); return;} yyval.num = 1;}
#line 2130 "./exec/y.tab.c"
    break;

  case 121: /* $@9: %empty  */
#line 298 "./Parser/parser_main.y"
                                 {if(!inList(&head,yyvsp[0].str)){insertInList(&head,yyvsp[0].str);} else {yyerror(); return;}}
#line 2136 "./exec/y.tab.c"
    break;

  case 122: /* for_stmt: FOR ID $@9 IN '(' range ')' '{' main_stmt_list '}'  */
#line 298 "./Parser/parser_main.y"
                                                                                                                                                            {removeTopKFromList(&head,1);}
#line 2142 "./exec/y.tab.c"
    break;

  case 123: /* $@10: %empty  */
#line 301 "./Parser/parser_main.y"
                                                                         {if(yyvsp[-5].num != yyvsp[-1].num){yyerror(); return;}}
#line 2148 "./exec/y.tab.c"
    break;

  case 124: /* for_lex_stmt: FOR_LEX '(' var_list ')' IN '(' range_list ')' $@10 '{' main_stmt_list '}'  */
#line 301 "./Parser/parser_main.y"
                                                                                                                                           {removeTopKFromList(&head,yyvsp[-9].num);}
#line 2154 "./exec/y.tab.c"
    break;

  case 125: /* $@11: %empty  */
#line 304 "./Parser/parser_main.y"
                                                                         {if(yyvsp[-5].num != yyvsp[-1].num){yyerror(); return;}}
#line 2160 "./exec/y.tab.c"
    break;

  case 126: /* for_zip_stmt: FOR_ZIP '(' var_list ')' IN '(' range_list ')' $@11 '{' main_stmt_list '}'  */
#line 304 "./Parser/parser_main.y"
                                                                                                                                           {removeTopKFromList(&head,yyvsp[-9].num);}
#line 2166 "./exec/y.tab.c"
    break;

  case 131: /* prim_type: INT  */
#line 318 "./Parser/parser_main.y"
                                    {yyval.type = INT;}
#line 2172 "./exec/y.tab.c"
    break;

  case 132: /* prim_type: UINT  */
#line 319 "./Parser/parser_main.y"
                                    {yyval.type = UINT;}
#line 2178 "./exec/y.tab.c"
    break;

  case 133: /* prim_type: FLOAT  */
#line 320 "./Parser/parser_main.y"
                                    {yyval.type = FLOAT;}
#line 2184 "./exec/y.tab.c"
    break;

  case 134: /* prim_type: COMPLEX  */
#line 321 "./Parser/parser_main.y"
                                    {yyval.type = COMPLEX;}
#line 2190 "./exec/y.tab.c"
    break;

  case 135: /* prim_type: STRING  */
#line 322 "./Parser/parser_main.y"
                                    {yyval.type = STRING;}
#line 2196 "./exec/y.tab.c"
    break;

  case 136: /* prim_type: MATRIX  */
#line 323 "./Parser/parser_main.y"
                                    {yyval.type = MATRIX;}
#line 2202 "./exec/y.tab.c"
    break;

  case 137: /* prim_type: STATE  */
#line 324 "./Parser/parser_main.y"
                                    {yyval.type = STATE;}
#line 2208 "./exec/y.tab.c"
    break;

  case 138: /* prim_type: BOOL  */
#line 325 "./Parser/parser_main.y"
                                    {yyval.type = BOOL;}
#line 2214 "./exec/y.tab.c"
    break;

  case 139: /* list_type: LIST '[' prim_type ']'  */
#line 328 "./Parser/parser_main.y"
                                                 {yyval.type = yyvsp[-1].type;}
#line 2220 "./exec/y.tab.c"
    break;

  case 142: /* num: DEC  */
#line 339 "./Parser/parser_main.y"
                                    {yyval.real = yyvsp[0].real;}
#line 2226 "./exec/y.tab.c"
    break;

  case 143: /* num: NEG  */
#line 340 "./Parser/parser_main.y"
                                    {yyval.real = yyvsp[0].real;}
#line 2232 "./exec/y.tab.c"
    break;

  case 144: /* num: EXP  */
#line 341 "./Parser/parser_main.y"
                                    {yyval.real = yyvsp[0].real;}
#line 2238 "./exec/y.tab.c"
    break;

  case 145: /* num: NUMBER  */
#line 342 "./Parser/parser_main.y"
                                    {yyval.real = yyvsp[0].num;}
#line 2244 "./exec/y.tab.c"
    break;

  case 146: /* complex_const: '(' num ',' num ')'  */
#line 344 "./Parser/parser_main.y"
                                                   {yyval.cpx.real = yyvsp[-3].real; yyval.cpx.imag = yyvsp[-1].real;}
#line 2250 "./exec/y.tab.c"
    break;

  case 147: /* matrix_const: '[' row_list ']'  */
#line 347 "./Parser/parser_main.y"
                                                   {if(yyvsp[-1].rows == yyvsp[-1].cols) {yyval.rows = yyvsp[-1].rows;} else {yyerror(); return;}}
#line 2256 "./exec/y.tab.c"
    break;

  case 148: /* row_list: row_list ',' row  */
#line 350 "./Parser/parser_main.y"
                                                   {yyval.rows = yyvsp[-2].rows + 1; if(yyvsp[-2].cols == yyvsp[0].cols) {yyval.cols = yyvsp[-2].cols;} else {yyerror(); return;}}
#line 2262 "./exec/y.tab.c"
    break;

  case 149: /* row_list: row  */
#line 351 "./Parser/parser_main.y"
                                                   {yyval.rows = 1; yyval.cols = yyvsp[0].cols;}
#line 2268 "./exec/y.tab.c"
    break;

  case 150: /* row: '[' comps ']'  */
#line 354 "./Parser/parser_main.y"
                                                   {yyval.cols = yyvsp[-1].cols;}
#line 2274 "./exec/y.tab.c"
    break;

  case 151: /* comps: comps ',' complex_const  */
#line 357 "./Parser/parser_main.y"
                                                   {yyval.cols = yyvsp[-2].cols + 1;}
#line 2280 "./exec/y.tab.c"
    break;

  case 152: /* comps: complex_const  */
#line 358 "./Parser/parser_main.y"
                                                   {yyval.cols = 1;}
#line 2286 "./exec/y.tab.c"
    break;

  case 153: /* state_const: '{' temp ',' temp '}'  */
#line 361 "./Parser/parser_main.y"
                                                   {yyval.q.first = yyvsp[-3].cpx; yyval.q.second = yyvsp[-1].cpx;}
#line 2292 "./exec/y.tab.c"
    break;

  case 154: /* temp: complex_const  */
#line 364 "./Parser/parser_main.y"
                                          {yyval.cpx = yyvsp[0].cpx;}
#line 2298 "./exec/y.tab.c"
    break;

  case 155: /* temp: num  */
#line 365 "./Parser/parser_main.y"
                                          {yyval.cpx.real = yyvsp[0].real; yyval.cpx.imag = 0;}
#line 2304 "./exec/y.tab.c"
    break;

  case 156: /* prim_const: bool_const  */
#line 368 "./Parser/parser_main.y"
                                          {yyval.type = Bool;}
#line 2310 "./exec/y.tab.c"
    break;

  case 157: /* prim_const: complex_const  */
#line 369 "./Parser/parser_main.y"
                                          {yyval.type = Complex;}
#line 2316 "./exec/y.tab.c"
    break;

  case 158: /* prim_const: matrix_const  */
#line 370 "./Parser/parser_main.y"
                                          {yyval.type = Matrix; yyval.rows = yyvsp[0].rows;}
#line 2322 "./exec/y.tab.c"
    break;

  case 159: /* prim_const: state_const  */
#line 371 "./Parser/parser_main.y"
                                          {yyval.type = State;}
#line 2328 "./exec/y.tab.c"
    break;

  case 160: /* prim_const: NUMBER  */
#line 372 "./Parser/parser_main.y"
                                          {yyval.type = Uint;}
#line 2334 "./exec/y.tab.c"
    break;

  case 161: /* prim_const: NEG  */
#line 373 "./Parser/parser_main.y"
                                          {yyval.type = Int;}
#line 2340 "./exec/y.tab.c"
    break;

  case 162: /* prim_const: DEC  */
#line 374 "./Parser/parser_main.y"
                                          {yyval.type = Float;}
#line 2346 "./exec/y.tab.c"
    break;

  case 163: /* prim_const: EXP  */
#line 375 "./Parser/parser_main.y"
                                          {yyval.type = Float;}
#line 2352 "./exec/y.tab.c"
    break;

  case 164: /* prim_const: STRING  */
#line 376 "./Parser/parser_main.y"
                                          {yyval.type = String;}
#line 2358 "./exec/y.tab.c"
    break;

  case 165: /* vec_const: '[' vec_list ']'  */
#line 379 "./Parser/parser_main.y"
                                                  {yyval.dim = yyvsp[-1].dim; yyval.type = yyvsp[-1].type; if(yyval.type == Matrix) {yyval.rows = yyvsp[-1].rows;} else {yyval.rows = 0;} }
#line 2364 "./exec/y.tab.c"
    break;

  case 166: /* vec_list: vec_list ',' prim_const  */
#line 382 "./Parser/parser_main.y"
                                                  {temp_type = compatibleCheck(yyvsp[-2].type, yyvsp[0].type); if(temp_type != -1) {yyval.type = temp_type;} else {yyerror(); return;} yyval.dim = yyvsp[-2].dim + 1; if(yyval.type == Matrix){ if(yyvsp[-2].rows != yyvsp[0].rows){yyerror();return;}else{yyval.rows = yyvsp[-2].rows;} }}
#line 2370 "./exec/y.tab.c"
    break;

  case 167: /* vec_list: prim_const  */
#line 383 "./Parser/parser_main.y"
                                                  {yyval.type = yyvsp[0].type; yyval.dim = 1; if(yyval.type == Matrix) {yyval.rows = yyvsp[0].rows;}}
#line 2376 "./exec/y.tab.c"
    break;

  case 168: /* calls: ADD '(' out_rhs ',' out_rhs ')'  */
#line 387 "./Parser/parser_main.y"
                                                                                                                     {temp_type = compatibleCheckAdv(yyvsp[-1].type, yyvsp[-3].type, yyvsp[-1].prim, yyvsp[-3].prim, yyvsp[-1].dim, yyvsp[-3].dim); if((!yyvsp[-3].prim) && ((temp_type<=COMPATIBLE) || temp_type==Matrix /*|| temp_type==String*/)) {yyval.prim = false; yyval.type = temp_type; yyval.dim = yyvsp[-3].dim;} else {yyerror(); return;}}
#line 2382 "./exec/y.tab.c"
    break;

  case 169: /* calls: SUB '(' out_rhs ',' out_rhs ')'  */
#line 388 "./Parser/parser_main.y"
                                                                                                                     {temp_type = compatibleCheckAdv(yyvsp[-1].type, yyvsp[-3].type, yyvsp[-1].prim, yyvsp[-3].prim, yyvsp[-1].dim, yyvsp[-3].dim); if((!yyvsp[-3].prim) && ((temp_type<=COMPATIBLE) || temp_type==Matrix)) {yyval.prim = false; yyval.type = temp_type; yyval.dim = yyvsp[-3].dim;} else {yyerror(); return;}}
#line 2388 "./exec/y.tab.c"
    break;

  case 170: /* calls: DOT '(' out_rhs ',' out_rhs ')'  */
#line 389 "./Parser/parser_main.y"
                                                                                                                     {temp_type = compatibleCheckAdv(yyvsp[-1].type, yyvsp[-3].type, yyvsp[-1].prim, yyvsp[-3].prim, yyvsp[-1].dim, yyvsp[-3].dim); if((!yyvsp[-3].prim) && (temp_type<=COMPATIBLE)) {yyval.prim = true; yyval.type = temp_type; yyval.dim = yyvsp[-3].dim;} else if ((!yyvsp[-3].prim) && (!yyvsp[-1].prim) && (yyvsp[-3].type<=COMPATIBLE) && (yyvsp[-1].type==Matrix)) {yyval.prim = true; yyval.type = Matrix; yyval.dim = 0;} else yyerror();}
#line 2394 "./exec/y.tab.c"
    break;

  case 171: /* calls: STD_DEV '(' out_rhs ')'  */
#line 390 "./Parser/parser_main.y"
                                                                                                                     {if((!yyvsp[-1].prim) && ((temp_type==Uint) || (temp_type==Int))) {yyval.prim = false; yyval.type = temp_type; yyval.dim = yyvsp[-1].dim;} else {yyerror(); return;}}
#line 2400 "./exec/y.tab.c"
    break;

  case 172: /* calls: VAR '(' out_rhs ')'  */
#line 391 "./Parser/parser_main.y"
                                                                                                                     {if((!yyvsp[-1].prim) && ((temp_type==Uint) || (temp_type==Int))) {yyval.prim = false; yyval.type = temp_type; yyval.dim = yyvsp[-1].dim;} else {yyerror(); return;}}
#line 2406 "./exec/y.tab.c"
    break;

  case 173: /* calls: CONDENSE '(' out_rhs ',' NUMBER ')'  */
#line 392 "./Parser/parser_main.y"
                                                                                                                     {if((!yyvsp[-3].prim) && ((temp_type==Uint) || (temp_type==Int))) {yyval.prim = false; yyval.type = temp_type; yyval.dim = condenser(yyvsp[-3].dim, 1);} else {yyerror(); return;}}
#line 2412 "./exec/y.tab.c"
    break;

  case 174: /* calls: CONDENSE '(' out_rhs ',' '(' uint_list ')' ')'  */
#line 393 "./Parser/parser_main.y"
                                                                                                                     {if((!yyvsp[-5].prim) && ((temp_type==Uint) || (temp_type==Int))) {yyval.prim = false; yyval.type = temp_type; yyval.dim = condenser(yyvsp[-5].dim, yyvsp[-2].cond_count);} else {yyerror(); return;}}
#line 2418 "./exec/y.tab.c"
    break;

  case 175: /* calls: SUM '(' out_rhs ')'  */
#line 394 "./Parser/parser_main.y"
                                                                                                                     {if((!yyvsp[-1].prim) && ((temp_type<=COMPATIBLE) || temp_type==Matrix /*|| temp_type==String*/)) {yyval.prim = true; yyval.type = temp_type; yyval.dim = 0;} else {yyerror(); return;}}
#line 2424 "./exec/y.tab.c"
    break;

  case 176: /* calls: AVG '(' out_rhs ')'  */
#line 395 "./Parser/parser_main.y"
                                                                                                                     {if((!yyvsp[-1].prim) && ((temp_type<=COMPATIBLE) || temp_type==Matrix)) {yyval.prim = true; yyval.type = temp_type; yyval.dim = 0;} else {yyerror(); return;}}
#line 2430 "./exec/y.tab.c"
    break;

  case 177: /* uint_list: uint_list ',' out_rhs  */
#line 401 "./Parser/parser_main.y"
                                                 {if(yyvsp[-2].type <= Int) {yyval.cond_count = yyvsp[-2].cond_count + 1;} else {yyerror(); return;}}
#line 2436 "./exec/y.tab.c"
    break;

  case 178: /* uint_list: out_rhs  */
#line 402 "./Parser/parser_main.y"
                                                 {if(yyvsp[0].type <= Int) {yyval.cond_count = 1;} else {yyerror(); return;}}
#line 2442 "./exec/y.tab.c"
    break;

  case 179: /* out_rhs: prim_const  */
#line 406 "./Parser/parser_main.y"
                                                                                 {yyval.prim = true; yyval.type = yyvsp[0].type;}
#line 2448 "./exec/y.tab.c"
    break;

  case 180: /* out_rhs: out_id  */
#line 407 "./Parser/parser_main.y"
                                                                                 {yyval.prim = yyvsp[0].prim; yyval.type = yyvsp[0].type;}
#line 2454 "./exec/y.tab.c"
    break;

  case 181: /* out_rhs: out_id '[' out_rhs ']'  */
#line 408 "./Parser/parser_main.y"
                                                                                 {if(yyvsp[-1].type <= Uint){if(yyvsp[-3].prim) {if(yyvsp[-3].type==State) {yyval.type = Complex;} else {yyerror();return;}} else {yyval.type = yyvsp[-3].type; yyval.prim = true;}}}
#line 2460 "./exec/y.tab.c"
    break;

  case 182: /* out_rhs: out_id '[' out_rhs ']' '[' out_rhs ']'  */
#line 409 "./Parser/parser_main.y"
                                                                                 {if((yyvsp[-4].type <= Uint) && (yyvsp[-2].type <= Uint)){if(yyvsp[-6].prim) {if(yyvsp[-6].type==Matrix) {yyval.type = Complex;} else {yyerror();return;}} else if(yyvsp[-6].type==State) {yyval.type = Complex;} else {yyerror(); return;}}}
#line 2466 "./exec/y.tab.c"
    break;

  case 183: /* out_rhs: out_id '[' out_rhs ']' '[' out_rhs ']' '[' out_rhs ']'  */
#line 410 "./Parser/parser_main.y"
                                                                                 {if((yyvsp[-7].type <= Uint) && (yyvsp[-5].type <= Uint) && (yyvsp[-3].type <= Uint)){if(yyvsp[-9].prim) {yyerror(); return;} else if(yyvsp[-9].type==Matrix) {yyval.type = Complex;} else yyerror();}}
#line 2472 "./exec/y.tab.c"
    break;

  case 184: /* out_rhs: calls  */
#line 411 "./Parser/parser_main.y"
                                                                                 {yyval.prim = yyvsp[0].prim; yyval.type = yyvsp[0].type; yyval.dim = yyvsp[0].dim;}
#line 2478 "./exec/y.tab.c"
    break;

  case 185: /* out_rhs: '(' out_rhs ')'  */
#line 412 "./Parser/parser_main.y"
                                                                                 {yyval.type = yyvsp[-1].type;}
#line 2484 "./exec/y.tab.c"
    break;

  case 186: /* out_rhs: '!' out_rhs  */
#line 413 "./Parser/parser_main.y"
                                                                                 {if(yyvsp[0].type==Bool && yyvsp[0].prim) {yyval.prim = true; yyval.type = Bool;} else yyerror();  }
#line 2490 "./exec/y.tab.c"
    break;

  case 187: /* out_rhs: out_rhs AND out_rhs  */
#line 414 "./Parser/parser_main.y"
                                                                                 {if(yyvsp[-2].type==Bool && yyvsp[-2].prim && yyvsp[0].type==Bool && yyvsp[0].prim)  {yyval.prim = true; yyval.type = Bool;} else yyerror(); }
#line 2496 "./exec/y.tab.c"
    break;

  case 188: /* out_rhs: out_rhs OR out_rhs  */
#line 415 "./Parser/parser_main.y"
                                                                                 {if(yyvsp[-2].type==Bool && yyvsp[-2].prim && yyvsp[0].type==Bool && yyvsp[0].prim)  {yyval.prim = true; yyval.type = Bool;} else yyerror(); }
#line 2502 "./exec/y.tab.c"
    break;

  case 189: /* out_rhs: out_rhs COMP out_rhs  */
#line 416 "./Parser/parser_main.y"
                                                                                 {temp_type = compatibleCheckAdv(yyvsp[-2].type, yyvsp[0].type, yyvsp[-2].prim, yyvsp[0].prim, yyvsp[-2].dim, yyvsp[0].dim); if(temp_type != -1 && temp_type < COMPARABLE) {yyval.prim = true; yyval.type = Bool;} else yyerror();  }
#line 2508 "./exec/y.tab.c"
    break;

  case 190: /* out_rhs: out_rhs EQUALITY out_rhs  */
#line 417 "./Parser/parser_main.y"
                                                                                 {temp_type = compatibleCheckAdv(yyvsp[-2].type, yyvsp[0].type, yyvsp[-2].prim, yyvsp[0].prim, yyvsp[-2].dim, yyvsp[0].dim); if(temp_type != -1 && temp_type < COMPARABLE) {yyval.prim = true; yyval.type = Bool;} else yyerror();  }
#line 2514 "./exec/y.tab.c"
    break;

  case 191: /* out_rhs: out_rhs '*' out_rhs  */
#line 418 "./Parser/parser_main.y"
                                                                                                                                                                  {temp_type = compatibleCheckAdv(yyvsp[-2].type, yyvsp[0].type, yyvsp[-2].prim, yyvsp[0].prim, yyvsp[-2].dim, yyvsp[0].dim); if(yyvsp[-2].prim && temp_type <= Complex) {yyval.prim = true; yyval.type = temp_type;} else if(yyvsp[-2].prim && yyvsp[0].prim && yyvsp[-2].type==Complex && yyvsp[0].type==Matrix) {yyval.prim = true; yyval.type = Matrix;} else if ((yyvsp[-2].prim && yyvsp[0].prim) && ((yyvsp[-2].type == String && yyvsp[0].type == Uint) || (yyvsp[0].type == String && yyvsp[-2].type == Uint))) {yyval.prim = true; yyval.type = String;} else yyerror();}
#line 2520 "./exec/y.tab.c"
    break;

  case 192: /* out_rhs: out_rhs '/' out_rhs  */
#line 419 "./Parser/parser_main.y"
                                                                                                                                                                  {temp_type = compatibleCheckAdv(yyvsp[-2].type, yyvsp[0].type, yyvsp[-2].prim, yyvsp[0].prim, yyvsp[-2].dim, yyvsp[0].dim); if(yyvsp[-2].prim && temp_type <= Complex) {yyval.prim = true; yyval.type = temp_type;} else yyerror();}
#line 2526 "./exec/y.tab.c"
    break;

  case 193: /* out_rhs: out_rhs '+' out_rhs  */
#line 420 "./Parser/parser_main.y"
                                                                                                                                                                  {temp_type = compatibleCheckAdv(yyvsp[-2].type, yyvsp[0].type, yyvsp[-2].prim, yyvsp[0].prim, yyvsp[-2].dim, yyvsp[0].dim); if(temp_type == Matrix || temp_type <= Complex) {yyval.prim = yyvsp[-2].prim; yyval.type = temp_type; yyval.rows=yyvsp[-2].rows; yyval.cols=yyvsp[-2].cols; yyval.dim=yyvsp[-2].dim;} else if ((yyvsp[-2].prim==true) && (yyvsp[-2].type == String)) {yyval.prim = true; yyval.type = String;} else yyerror();}
#line 2532 "./exec/y.tab.c"
    break;

  case 194: /* out_rhs: out_rhs '-' out_rhs  */
#line 421 "./Parser/parser_main.y"
                                                                                                                                                                  {temp_type = compatibleCheckAdv(yyvsp[-2].type, yyvsp[0].type, yyvsp[-2].prim, yyvsp[0].prim, yyvsp[-2].dim, yyvsp[0].dim); if(temp_type == Matrix || temp_type <= Complex) {yyval.prim = yyvsp[-2].prim; yyval.type = temp_type; yyval.rows=yyvsp[-2].rows; yyval.cols=yyvsp[-2].cols; yyval.dim=yyvsp[-2].dim;} else yyerror();}
#line 2538 "./exec/y.tab.c"
    break;

  case 195: /* out_rhs: out_rhs '@' out_rhs  */
#line 422 "./Parser/parser_main.y"
                                                                                                                                                                  {temp_type = compatibleCheckAdv(yyvsp[-2].type, yyvsp[0].type, yyvsp[-2].prim, yyvsp[0].prim, yyvsp[-2].dim, yyvsp[0].dim); if(yyvsp[-2].prim && temp_type == Matrix) {if(yyvsp[-2].rows == yyvsp[0].rows) {yyval.prim = true; yyval.type = temp_type;} else {yyerror(); return;}} else if(temp_type <= Complex) {yyval.prim = true; yyval.type = temp_type; yyval.dim = 0;} else if (yyvsp[-2].type<=COMPATIBLE && yyvsp[0].type==Matrix) {yyval.prim = true; yyval.type = Matrix; yyval.dim = 0;} else yyerror();}
#line 2544 "./exec/y.tab.c"
    break;

  case 196: /* out_rhs: out_rhs '&' out_rhs  */
#line 423 "./Parser/parser_main.y"
                                                                                                                                                                  {temp_type = compatibleCheckAdv(yyvsp[-2].type, yyvsp[0].type, yyvsp[-2].prim, yyvsp[0].prim, yyvsp[-2].dim, yyvsp[0].dim); if(yyvsp[-2].prim && temp_type <= Int) {yyval.prim = true; yyval.type = temp_type;} else yyerror();}
#line 2550 "./exec/y.tab.c"
    break;

  case 197: /* out_rhs: out_rhs '^' out_rhs  */
#line 424 "./Parser/parser_main.y"
                                                                                                                                                                  {temp_type = compatibleCheckAdv(yyvsp[-2].type, yyvsp[0].type, yyvsp[-2].prim, yyvsp[0].prim, yyvsp[-2].dim, yyvsp[0].dim); if(yyvsp[-2].prim && temp_type <= Int) {yyval.prim = true; yyval.type = temp_type;} else yyerror();}
#line 2556 "./exec/y.tab.c"
    break;

  case 198: /* out_rhs: out_rhs '|' out_rhs  */
#line 425 "./Parser/parser_main.y"
                                                                                                                                                                  {temp_type = compatibleCheckAdv(yyvsp[-2].type, yyvsp[0].type, yyvsp[-2].prim, yyvsp[0].prim, yyvsp[-2].dim, yyvsp[0].dim); if(yyvsp[-2].prim && temp_type <= Int) {yyval.prim = true; yyval.type = temp_type;} else yyerror();}
#line 2562 "./exec/y.tab.c"
    break;

  case 199: /* out_expr: ID '=' out_rhs  */
#line 429 "./Parser/parser_main.y"
                                                      {fprintf(fp,"expression statement\n"); if(isDeclaration){yyval.type = yyvsp[0].type; yyval.str = yyvsp[-2].str;} else {struct OutputSymbolEntry* entry = getOutputSymbolEntry(&OutputSymbolTable,yyvsp[-2].str,outputLevel,1); if(entry->type != yyvsp[0].type){yyerror(); return;}}}
#line 2568 "./exec/y.tab.c"
    break;

  case 200: /* decl: prim_type out_expr  */
#line 432 "./Parser/parser_main.y"
                                                      {fprintf(fp,"Primitive datatype declaration statement\n"); if( (yyvsp[0].prim==false) || (yyvsp[-1].type != yyvsp[0].type) || getOutputSymbolEntry(&OutputSymbolTable,yyvsp[0].str,outputLevel,0) != NULL){yyerror(); return;} else insertInOutputTable(&OutputSymbolTable,yyvsp[0].str,outputLevel,yyvsp[0].type,true,0,0,false);}
#line 2574 "./exec/y.tab.c"
    break;

  case 201: /* decl: list_type ID '=' vec_const  */
#line 433 "./Parser/parser_main.y"
                                                      {fprintf(fp,"List datatype declaration statement\n"); if((yyvsp[-3].type != yyvsp[-1].type) || getOutputSymbolEntry(&OutputSymbolTable,yyvsp[-2].str,outputLevel,0) != NULL){yyerror(); return;} else insertInOutputTable(&OutputSymbolTable,yyvsp[-2].str,outputLevel,yyvsp[-3].type,false,yyvsp[0].rows,yyvsp[0].dim,false);}
#line 2580 "./exec/y.tab.c"
    break;

  case 202: /* decl: list_type out_expr  */
#line 434 "./Parser/parser_main.y"
                                                      {fprintf(fp,"List datatype declaration statement\n"); if( (yyvsp[0].prim==true) || (yyvsp[-1].type!=yyvsp[0].type) ){yyerror(); return;} else insertInOutputTable(&OutputSymbolTable,yyvsp[0].str,outputLevel,yyvsp[-1].type,false,yyvsp[0].rows,yyvsp[0].dim,false);}
#line 2586 "./exec/y.tab.c"
    break;

  case 203: /* echo_stmt: ECHO '(' echo_list ')'  */
#line 438 "./Parser/parser_main.y"
                                                      {fprintf(fp,"Echo statement\n");}
#line 2592 "./exec/y.tab.c"
    break;

  case 206: /* save_stmt: '\\' SAVE STRING  */
#line 446 "./Parser/parser_main.y"
                                                      {fprintf(fp,"Save statement\n");}
#line 2598 "./exec/y.tab.c"
    break;

  case 207: /* $@12: %empty  */
#line 450 "./Parser/parser_main.y"
                          {fprintf(fp,"Output section conditional statement begins\n");}
#line 2604 "./exec/y.tab.c"
    break;

  case 208: /* out_control: $@12 out_cond_stmt  */
#line 450 "./Parser/parser_main.y"
                                                                                                       {fprintf(fp,"Output section conditional statement ends\n");}
#line 2610 "./exec/y.tab.c"
    break;

  case 209: /* out_control: out_for_stmt  */
#line 451 "./Parser/parser_main.y"
                                                      {fprintf(fp,"For statement in output section\n");}
#line 2616 "./exec/y.tab.c"
    break;

  case 210: /* out_control: out_for_lex_stmt  */
#line 452 "./Parser/parser_main.y"
                                                      {fprintf(fp,"For - lex statement in output section\n");}
#line 2622 "./exec/y.tab.c"
    break;

  case 211: /* out_control: out_for_zip_stmt  */
#line 453 "./Parser/parser_main.y"
                                                      {fprintf(fp,"For - zip statement in output section\n");}
#line 2628 "./exec/y.tab.c"
    break;

  case 212: /* out_control: out_while_stmt  */
#line 454 "./Parser/parser_main.y"
                                                      {fprintf(fp,"while statement in output section\n");}
#line 2634 "./exec/y.tab.c"
    break;

  case 213: /* $@13: %empty  */
#line 457 "./Parser/parser_main.y"
                                                        {outputLevel++;}
#line 2640 "./exec/y.tab.c"
    break;

  case 214: /* out_cond_stmt: CONDITION '(' out_rhs ')' '{' $@13 out_main '}' out_other_list out_other_final  */
#line 457 "./Parser/parser_main.y"
                                                                                                                     {outputLevel--;}
#line 2646 "./exec/y.tab.c"
    break;

  case 219: /* $@14: %empty  */
#line 468 "./Parser/parser_main.y"
                                 {if(getOutputSymbolEntry(&OutputSymbolTable,yyvsp[0].str,outputLevel + 1,0) != NULL){yyerror(); return;} else insertInOutputTable(&OutputSymbolTable,yyvsp[0].str,outputLevel + 1,Int,true,0,0,true);}
#line 2652 "./exec/y.tab.c"
    break;

  case 220: /* $@15: %empty  */
#line 468 "./Parser/parser_main.y"
                                                                                                                                                                                                                                                 {outputLevel++;}
#line 2658 "./exec/y.tab.c"
    break;

  case 221: /* out_for_stmt: FOR ID $@14 IN '(' range ')' '{' $@15 out_main '}'  */
#line 468 "./Parser/parser_main.y"
                                                                                                                                                                                                                                                                               {exitOutputSymbolScope(&OutputSymbolTable,outputLevel); outputLevel--;}
#line 2664 "./exec/y.tab.c"
    break;

  case 222: /* $@16: %empty  */
#line 471 "./Parser/parser_main.y"
                                                                          {if(yyvsp[-5].num != yyvsp[-1].num){yyerror(); return;}}
#line 2670 "./exec/y.tab.c"
    break;

  case 223: /* $@17: %empty  */
#line 471 "./Parser/parser_main.y"
                                                                                                                         {outputLevel++;}
#line 2676 "./exec/y.tab.c"
    break;

  case 224: /* out_for_lex_stmt: FOR_LEX '(' var_list ')' IN '(' range_list ')' $@16 '{' $@17 out_main '}'  */
#line 471 "./Parser/parser_main.y"
                                                                                                                                                       {exitOutputSymbolScope(&OutputSymbolTable,outputLevel); outputLevel--;}
#line 2682 "./exec/y.tab.c"
    break;

  case 225: /* $@18: %empty  */
#line 474 "./Parser/parser_main.y"
                                                                          {if(yyvsp[-5].num != yyvsp[-1].num){yyerror(); return;}}
#line 2688 "./exec/y.tab.c"
    break;

  case 226: /* $@19: %empty  */
#line 474 "./Parser/parser_main.y"
                                                                                                                         {outputLevel++;}
#line 2694 "./exec/y.tab.c"
    break;

  case 227: /* out_for_zip_stmt: FOR_ZIP '(' var_list ')' IN '(' range_list ')' $@18 '{' $@19 out_main '}'  */
#line 474 "./Parser/parser_main.y"
                                                                                                                                                       {exitOutputSymbolScope(&OutputSymbolTable,outputLevel); outputLevel--;}
#line 2700 "./exec/y.tab.c"
    break;

  case 228: /* $@20: %empty  */
#line 477 "./Parser/parser_main.y"
                                                 {outputLevel++;}
#line 2706 "./exec/y.tab.c"
    break;

  case 229: /* out_while_stmt: WHILE '(' expr ')' '{' $@20 out_main '}'  */
#line 477 "./Parser/parser_main.y"
                                                                               {exitOutputSymbolScope(&OutputSymbolTable,outputLevel); outputLevel--;}
#line 2712 "./exec/y.tab.c"
    break;

  case 235: /* $@21: %empty  */
#line 489 "./Parser/parser_main.y"
                          {isDeclaration = false;}
#line 2718 "./exec/y.tab.c"
    break;

  case 237: /* $@22: %empty  */
#line 490 "./Parser/parser_main.y"
                          {isDeclaration = true;}
#line 2724 "./exec/y.tab.c"
    break;


#line 2728 "./exec/y.tab.c"

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

#line 492 "./Parser/parser_main.y"


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
   if(*Head == NULL) return false;

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

void insertInBlockTable(struct BlockTable** Head,char * data,int len,struct List* params){
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

void insertInGateTable(struct GateTable ** Head,char * data,int rows,int cols){
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
      if(strcmp(temp->id,block_id) == 0){
         break;
      }
      temp = temp->next;
   }
   if(temp == NULL || num_params != temp->len) return 0;
   return 1;
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
