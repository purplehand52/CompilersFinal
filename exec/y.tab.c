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

   int yylex();
   void yyerror();

   int classical_registers,quantum_registers,iterations;
   int * classical_states,classical_index=0,quantum_index=0;
   struct Quantum* quantum_states;
   int isInBlock=0;

   struct List* head = NULL;
   struct List* id_list = NULL;
   struct BlockTable* BlockSymbolTable = NULL;
   struct GateTable* GateSymbolTable = NULL;

   /* Output Section */
   struct OutputSymbolEntry* OutputSymbolTable = NULL;

#line 99 "./exec/y.tab.c"

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
  YYSYMBOL_for_lex_stmt = 142,             /* for_lex_stmt  */
  YYSYMBOL_for_zip_stmt = 143,             /* for_zip_stmt  */
  YYSYMBOL_while_stmt = 144,               /* while_stmt  */
  YYSYMBOL_out_id = 145,                   /* out_id  */
  YYSYMBOL_prim_type = 146,                /* prim_type  */
  YYSYMBOL_list_type = 147,                /* list_type  */
  YYSYMBOL_bool_const = 148,               /* bool_const  */
  YYSYMBOL_num = 149,                      /* num  */
  YYSYMBOL_complex_const = 150,            /* complex_const  */
  YYSYMBOL_matrix_const = 151,             /* matrix_const  */
  YYSYMBOL_row_list = 152,                 /* row_list  */
  YYSYMBOL_row = 153,                      /* row  */
  YYSYMBOL_comps = 154,                    /* comps  */
  YYSYMBOL_state_const = 155,              /* state_const  */
  YYSYMBOL_temp = 156,                     /* temp  */
  YYSYMBOL_prim_const = 157,               /* prim_const  */
  YYSYMBOL_vec_const = 158,                /* vec_const  */
  YYSYMBOL_vec_list = 159,                 /* vec_list  */
  YYSYMBOL_calls = 160,                    /* calls  */
  YYSYMBOL_uint_list = 161,                /* uint_list  */
  YYSYMBOL_out_rhs = 162,                  /* out_rhs  */
  YYSYMBOL_out_expr = 163,                 /* out_expr  */
  YYSYMBOL_decl = 164,                     /* decl  */
  YYSYMBOL_echo_stmt = 165,                /* echo_stmt  */
  YYSYMBOL_echo_list = 166,                /* echo_list  */
  YYSYMBOL_save_stmt = 167,                /* save_stmt  */
  YYSYMBOL_out_control = 168,              /* out_control  */
  YYSYMBOL_169_9 = 169,                    /* $@9  */
  YYSYMBOL_out_cond_stmt = 170,            /* out_cond_stmt  */
  YYSYMBOL_out_other_list = 171,           /* out_other_list  */
  YYSYMBOL_out_other_final = 172,          /* out_other_final  */
  YYSYMBOL_out_for_stmt = 173,             /* out_for_stmt  */
  YYSYMBOL_out_for_lex_stmt = 174,         /* out_for_lex_stmt  */
  YYSYMBOL_out_for_zip_stmt = 175,         /* out_for_zip_stmt  */
  YYSYMBOL_out_while_stmt = 176,           /* out_while_stmt  */
  YYSYMBOL_out_main = 177,                 /* out_main  */
  YYSYMBOL_out_stmt = 178                  /* out_stmt  */
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
#define YYLAST   1097

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  83
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  96
/* YYNRULES -- Number of rules.  */
#define YYNRULES  224
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
       0,    59,    59,    63,    63,    66,    66,    69,    69,    77,
      81,    82,    83,    84,    85,    88,    91,    94,    95,    98,
      99,   102,   106,   106,   107,   110,   111,   114,   114,   117,
     118,   120,   121,   123,   124,   126,   127,   130,   130,   133,
     134,   137,   137,   140,   141,   144,   145,   148,   149,   150,
     153,   154,   157,   158,   161,   169,   170,   173,   174,   176,
     177,   178,   178,   179,   180,   181,   182,   185,   186,   191,
     192,   193,   194,   195,   196,   199,   200,   203,   204,   207,
     208,   211,   212,   215,   216,   217,   220,   221,   235,   238,
     241,   244,   245,   248,   249,   252,   253,   254,   255,   256,
     257,   258,   261,   262,   263,   264,   265,   266,   267,   268,
     269,   270,   271,   275,   276,   279,   280,   283,   284,   287,
     288,   291,   294,   297,   300,   309,   309,   309,   311,   312,
     313,   314,   315,   316,   317,   318,   321,   328,   329,   332,
     333,   334,   335,   337,   340,   343,   344,   347,   350,   351,
     354,   357,   358,   361,   362,   363,   364,   365,   366,   367,
     368,   369,   372,   375,   376,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   392,   393,   397,   398,   399,   400,
     401,   402,   403,   404,   405,   406,   407,   408,   409,   410,
     411,   412,   413,   414,   415,   419,   422,   423,   424,   428,
     431,   432,   436,   440,   440,   441,   442,   443,   444,   447,
     450,   451,   454,   455,   458,   461,   464,   467,   472,   473,
     476,   477,   478,   479,   480
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
  "for_stmt", "for_lex_stmt", "for_zip_stmt", "while_stmt", "out_id",
  "prim_type", "list_type", "bool_const", "num", "complex_const",
  "matrix_const", "row_list", "row", "comps", "state_const", "temp",
  "prim_const", "vec_const", "vec_list", "calls", "uint_list", "out_rhs",
  "out_expr", "decl", "echo_stmt", "echo_list", "save_stmt", "out_control",
  "$@9", "out_cond_stmt", "out_other_list", "out_other_final",
  "out_for_stmt", "out_for_lex_stmt", "out_for_zip_stmt", "out_while_stmt",
  "out_main", "out_stmt", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-356)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-143)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -41,    50,    44,     5,  -356,  -356,    71,    55,    49,  -356,
     125,  -356,   135,    80,  -356,  -356,   158,   192,  -356,   194,
     207,   163,  -356,   133,   287,   217,   216,   295,  -356,   300,
    -356,    36,  -356,   241,   291,   366,   297,   305,   309,    52,
     331,     7,  -356,  -356,   356,   321,  -356,    54,  -356,  -356,
    -356,  -356,  -356,  -356,   676,   406,   408,   409,   347,   402,
     418,  -356,   216,   411,   417,    18,   415,   420,   331,   405,
     425,   425,    28,  -356,  -356,  -356,  -356,   -33,   331,  -356,
     421,   352,  -356,  -356,    14,   241,     7,   370,   442,   372,
     376,   377,  -356,  -356,  -356,  -356,  -356,  -356,  -356,  -356,
     385,   383,    21,   460,   461,  -356,  -356,  -356,  -356,  -356,
     444,  -356,  -356,  -356,  -356,  -356,   393,   454,   465,   470,
     488,   402,  -356,  -356,    22,  -356,   331,  -356,   331,   331,
     478,   427,  -356,    -5,    13,  -356,  -356,  -356,  -356,    28,
     503,   860,   331,   419,    40,    20,  -356,    28,   479,   487,
     421,   233,   489,   425,   425,    28,   208,   233,  -356,   458,
    -356,   438,   441,  -356,   523,   456,   530,  -356,   469,  -356,
    -356,   540,   525,    62,  -356,  -356,   331,   350,   551,   536,
     537,   892,   388,   388,   388,   388,   388,    28,    28,    28,
      28,    28,    28,    28,   483,  -356,  -356,  -356,   331,  -356,
    -356,   901,   331,   331,  -356,  -356,  -356,  -356,  -356,  -356,
     477,   490,   494,   498,   501,   510,   512,   513,  -356,  -356,
    -356,  -356,  -356,   233,   504,    67,   288,   518,  -356,  -356,
    -356,  -356,  -356,  -356,  1028,   524,   120,   121,   909,   529,
    1028,   122,  -356,   190,   233,   597,   538,  -356,  -356,   549,
    -356,   143,   552,   531,    25,  -356,  -356,  -356,  -356,  -356,
     527,   534,  -356,   546,   548,  -356,   113,   113,  -356,  -356,
    -356,   154,   455,   576,  -356,    -7,    47,   375,  -356,   134,
     556,  -356,  -356,   233,   233,   233,   233,   233,   233,   233,
     233,   380,   550,   174,  -356,  -356,  -356,  -356,  -356,    94,
    -356,  -356,   560,   561,   562,   563,   564,   568,   704,   639,
     233,   233,   233,   233,   233,   233,   233,   233,   233,   233,
     233,   233,   350,   623,   624,   571,  -356,   233,  -356,   664,
    -356,  -356,   719,   573,   456,   530,   574,   579,  -356,   540,
    -356,  -356,   657,   586,   350,   585,   350,   350,    11,  -356,
    -356,   953,   962,   976,   728,   769,   778,  1019,   793,  -356,
     240,   504,  -356,    67,    94,  -356,   591,   253,   462,   635,
    -356,   314,   314,   404,   404,   507,   136,   115,   380,   592,
     595,   598,  -356,  1028,  -356,   265,   594,   672,  -356,  -356,
      67,   266,    67,   206,  -356,  -356,   606,   601,   189,   596,
    -356,  -356,   145,   164,   658,  -356,   278,   233,   233,   233,
    -356,  -356,  -356,    31,  -356,   550,  -356,  -356,   614,   616,
     625,   621,   350,   350,   431,   664,  -356,  -356,   627,   276,
    -356,   626,  -356,   166,   628,  -356,   657,  -356,   629,   189,
     350,   333,   350,   631,   633,  -356,   819,   834,   843,   632,
     702,  -356,  -356,  -356,   709,  -356,   219,   221,   659,  -356,
    -356,   466,   710,    67,  -356,    67,  -356,    67,  -356,  -356,
    -356,  -356,  -356,  -356,  -356,  -356,   694,  -356,  -356,  -356,
    -356,  -356,   235,   643,   500,   653,   655,  -356,   661,  -356,
     311,   237,   368,   371,   285,  -356,   736,   662,  -356,  -356,
    -356,  -356,   720,   741,  -356,  -356,  -356,  -356,  -356,    28,
    -356,  -356,   535,   569,   328,  -356,  -356,   397,   933,  -356,
    -356,  -356,   233,  -356,   669,   604,   884,  -356,  -356,   673,
     426,  -356,  -356,   638,  -356
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     3,     1,     0,     0,     0,     5,
       0,     2,     0,    14,    56,     7,     0,     0,    37,    12,
      13,    61,   219,     0,     0,    22,    40,     0,    10,     0,
      11,    54,    67,    83,     0,     0,     0,     0,     0,     0,
       0,     0,    55,    57,     0,     0,    59,     0,    60,    58,
      63,    64,    65,    66,   203,     0,     0,     0,     0,     0,
       0,    38,    40,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     6,    89,    68,    80,     0,     0,    75,
      77,     0,    62,    81,    54,    83,     0,     0,     0,     0,
       0,     0,   128,   129,   130,   131,   132,   133,   134,   135,
       0,     0,     0,     0,     0,   223,   224,   222,   221,   220,
       0,   205,   206,   207,   208,   218,     0,     0,     0,     0,
       0,    23,    26,    54,     0,    39,     0,    84,     0,     0,
       0,     0,   120,     0,     0,   100,   101,   111,   112,     0,
     110,     0,     0,     0,     0,     0,    74,     0,     0,     0,
      77,     0,     0,     0,     0,     0,     0,     0,     8,     0,
     196,     0,     0,   204,     0,     0,     0,     4,     0,    25,
      43,     0,    47,     0,    72,    71,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    79,    82,    76,     0,    86,
      78,     0,     0,     0,    73,   125,   157,   158,   137,   138,
       0,     0,     0,     0,     0,     0,     0,     0,   126,   127,
     161,   159,   160,     0,     0,     0,     0,   177,   153,   154,
     155,   156,   176,   180,   195,     0,     0,     0,     0,     0,
     201,     0,   202,     0,     0,     0,    15,    18,    21,    16,
      20,     0,    46,     0,     0,    41,    85,    88,   114,   113,
       0,     0,   119,     0,     0,   109,    95,    96,    97,    98,
      99,   102,   103,   104,   105,   107,   106,   108,    56,     0,
       0,    70,    69,     0,     0,     0,     0,     0,     0,     0,
       0,   182,     0,     0,   146,   142,   140,   139,   141,     0,
     152,   151,     0,   157,   158,   159,   160,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   136,     0,   199,     0,
     197,   198,     0,     0,     0,     0,     0,     0,    27,     0,
      44,    48,     0,     0,     0,     0,     0,     0,    61,    87,
      56,     0,     0,     0,     0,     0,     0,     0,     0,   149,
       0,     0,   144,     0,     0,   181,     0,   185,   186,   183,
     184,   189,   190,   187,   188,   191,   192,   193,   194,     0,
       0,     0,   219,   200,   164,     0,     0,     0,    17,    19,
       0,     0,     0,     0,    28,    45,    51,     0,    52,   115,
      56,   118,     0,     0,     0,   124,    61,     0,     0,     0,
     168,   169,   173,     0,   172,     0,   147,   145,     0,     0,
     178,     0,     0,     0,   203,     0,   162,   219,     0,     0,
      36,     0,    29,     0,     0,    30,     0,    49,     0,    52,
       0,    61,     0,     0,     0,    92,     0,     0,     0,     0,
       0,   148,   150,   143,     0,   219,     0,     0,     0,   217,
     163,   203,     0,     0,    32,     0,    34,     0,    50,    42,
      53,   116,   121,   117,    56,    56,    94,   165,   166,   167,
     170,   175,     0,     0,   203,     0,     0,   211,     0,    35,
       0,     0,    61,    61,     0,    90,     0,     0,   179,   214,
     219,   219,   213,     0,    31,    33,   122,   123,    56,     0,
     174,   171,   203,   203,     0,   209,     9,    61,     0,   215,
     216,   219,     0,    93,     0,   203,     0,    56,   212,     0,
      61,   219,    91,   203,   210
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -356,  -356,  -356,  -356,  -356,  -356,  -356,  -356,  -356,  -356,
     729,   735,  -356,  -356,   423,  -356,  -356,  -356,   634,  -356,
    -356,  -356,  -356,  -352,  -356,  -356,   697,  -356,  -356,  -356,
     424,  -356,   320,   325,    78,  -265,  -356,  -355,  -356,   -23,
    -356,   683,   650,   -58,  -356,    27,  -356,  -356,  -356,  -356,
    -356,  -356,   416,  -139,  -338,  -175,  -328,   -62,  -356,  -356,
    -356,  -356,  -356,   618,  -356,  -356,  -221,  -218,  -356,  -356,
     414,  -356,  -161,  -222,  -317,  -356,  -356,   533,  -356,  -156,
     674,  -356,  -356,  -356,  -356,  -356,  -356,  -356,  -356,  -356,
    -356,  -356,  -356,  -356,  -318,  -356
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     2,     3,     8,     7,    14,    11,    22,    13,    18,
      19,    20,   246,   249,   250,    58,    59,   121,   122,   394,
     338,   391,   393,   429,    25,    26,    61,    62,   343,   172,
     253,   255,   397,   438,    41,    21,    42,    43,    44,    45,
      46,    80,   146,    77,    47,    66,   200,    48,    49,    82,
     476,   495,   140,   141,   260,   401,   402,   133,    50,    51,
      52,    53,   227,   103,   104,   228,   300,   229,   230,   293,
     294,   360,   231,   430,   232,   330,   385,   233,   482,   234,
     105,   106,   107,   241,   108,   109,   110,   163,   502,   515,
     111,   112,   113,   114,    54,   115
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     181,   240,   261,   302,   247,   307,   399,   301,   201,   134,
      75,    32,   384,   348,    31,    32,   238,    76,    79,   403,
     144,    75,    32,    75,    32,   170,   189,   190,   341,    33,
       1,   135,   136,    34,   -83,   449,   158,    35,    36,    37,
     433,   142,   127,   439,     5,   130,    38,   143,   271,   272,
     273,   274,   275,   276,   277,    76,   -83,    84,   137,   138,
      67,   192,   193,    79,   424,    73,     4,   291,   173,   178,
     308,   295,    85,   296,   359,   179,     6,    74,   307,   159,
     189,   190,   404,     9,   439,   406,    78,   178,   332,   405,
      40,   236,   237,   180,   456,   457,    65,   126,   295,   198,
     296,   171,   471,    76,   342,   174,   175,   139,   460,   461,
     450,   148,   149,   490,   142,   491,   193,   -68,    65,   195,
     197,    12,   199,   297,   298,    86,    10,   351,   352,   353,
     354,   355,   356,   357,   358,   441,   142,   484,   124,    15,
     279,   418,   256,   419,    16,   301,   299,   379,   312,   313,
     297,   298,    17,   257,   367,   368,   369,   370,   371,   372,
     373,   374,   375,   376,   377,   378,    31,    32,    23,   312,
     313,   383,   301,   388,   301,    76,   184,   185,   186,   281,
     282,    33,   512,   513,   321,    34,   188,   189,   190,    35,
      36,    37,    31,    32,   178,   178,   327,   451,    38,    24,
     323,   324,   328,   525,   320,   321,    55,    33,   142,   492,
     493,    34,   -61,   533,   349,    35,    36,    37,   336,   442,
     337,   191,   192,   193,    38,   443,   210,   211,   212,   213,
     214,   215,   216,   217,    39,    60,   205,   206,   442,   207,
     463,   489,    40,   517,   444,   301,   466,   301,   361,   301,
     362,   446,   447,   448,    92,    93,    94,    95,    96,    97,
      98,    99,   530,   208,   209,   329,    27,   473,    40,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,    29,
     434,    31,    32,   220,   435,   311,   312,   313,   -24,   221,
     222,   205,   303,   442,   304,   442,    33,    56,    57,   485,
      34,   486,    63,   223,    35,    36,    37,    64,   224,   496,
     225,   463,   226,    38,   415,   497,   416,   505,   208,   209,
     319,   320,   321,    65,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,    75,    32,    31,    32,   220,   425,
     431,   426,   432,   310,   305,   306,   311,   312,   313,   404,
     463,    33,   464,   258,   259,    34,   445,    40,   223,    35,
      36,    37,   508,   224,   509,   225,   526,   226,    38,    69,
     518,    31,    32,    68,    31,    32,    70,   316,   317,    81,
     318,   319,   320,   321,    71,   463,    33,   504,    72,    33,
      34,   135,   136,    34,    35,    36,    37,    35,    36,    37,
      31,    32,    83,    38,   404,   521,    38,   522,   189,   190,
     116,   472,    40,   312,   313,    33,   117,   118,   119,    34,
     120,   123,    57,    35,    36,    37,   131,    56,   132,    31,
      32,   147,    38,   310,    87,   128,   311,   312,   313,   404,
     129,   145,   404,   151,    33,   152,   506,    40,    34,   507,
      40,   153,    35,    36,    37,   154,   155,    88,    89,    90,
     156,    38,   157,    87,   161,   164,    91,   162,   404,    87,
     318,   319,   320,   321,   165,   523,    40,    92,    93,    94,
      95,    96,    97,    98,    99,   166,   100,   167,   189,   190,
     101,   168,    88,    89,    90,   312,   313,   404,   176,   202,
     196,    91,   458,    87,   532,    40,   177,   203,   242,   459,
     235,   243,    92,    93,    94,    95,    96,    97,    98,    99,
     244,   100,   191,   192,   193,   101,    88,    89,    90,   319,
     320,   321,   245,   225,   248,    91,   310,   458,    87,   311,
     312,   313,   251,   252,   487,   254,    92,    93,    94,    95,
      96,    97,    98,    99,   262,   100,   283,   263,   264,   101,
     278,    88,    89,    90,   182,   183,   184,   185,   186,   284,
      91,   458,    87,   285,   319,   320,   321,   286,   499,   292,
     287,    92,    93,    94,    95,    96,    97,    98,    99,   288,
     100,   289,   290,   309,   101,    88,    89,    90,   266,   267,
     268,   269,   270,   322,    91,   326,   458,    87,   333,   344,
     190,   340,   334,   519,   345,    92,    93,    94,    95,    96,
      97,    98,    99,   335,   100,   346,   339,   347,   101,   299,
      88,    89,    90,   350,   363,  -142,  -140,  -139,  -141,    91,
     458,    87,   364,   366,   380,   381,   387,   520,   382,   390,
      92,    93,    94,    95,    96,    97,    98,    99,   392,   100,
     396,   398,   400,   101,    88,    89,    90,   420,   206,   313,
     207,   427,   421,    91,   422,   458,   428,   423,   440,    87,
     436,   437,   528,    74,    92,    93,    94,    95,    96,    97,
      98,    99,   452,   100,   208,   209,   453,   101,   455,   462,
     454,   465,    88,    89,    90,   469,   481,   467,   474,   458,
     475,    91,   480,   483,   220,   488,   534,   159,   494,   498,
     221,   222,    92,    93,    94,    95,    96,    97,    98,    99,
     500,   100,   501,   310,   503,   101,   311,   312,   313,   224,
     510,   225,   511,   299,   514,   516,   527,   102,   310,    30,
     531,   311,   312,   313,    28,   169,   468,   310,   389,   125,
     311,   312,   313,   395,   470,   314,   315,   316,   317,   150,
     318,   319,   320,   321,   239,   417,   331,   160,     0,     0,
     314,   315,   316,   317,   365,   318,   319,   320,   321,   314,
     315,   316,   317,     0,   318,   319,   320,   321,   310,   386,
     204,   311,   312,   313,     0,     0,     0,   310,   410,     0,
     311,   312,   313,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   310,     0,     0,   311,   312,   313,     0,     0,
     314,   315,   316,   317,     0,   318,   319,   320,   321,   314,
     315,   316,   317,     0,   318,   319,   320,   321,   310,   411,
       0,   311,   312,   313,   314,   315,   316,   317,   412,   318,
     319,   320,   321,   310,     0,     0,   311,   312,   313,     0,
       0,     0,   310,   414,     0,   311,   312,   313,     0,     0,
     314,   315,   316,   317,     0,   318,   319,   320,   321,   187,
       0,     0,   188,   189,   190,   314,   315,   316,   317,   477,
     318,   319,   320,   321,   314,   315,   316,   317,     0,   318,
     319,   320,   321,   310,   478,     0,   311,   312,   313,     0,
       0,   187,     0,   479,   188,   189,   190,   191,   192,   193,
     187,     0,     0,   188,   189,   190,     0,     0,   187,     0,
     194,   188,   189,   190,     0,   314,   315,   316,   317,     0,
     318,   319,   320,   321,     0,     0,     0,     0,     0,   191,
     192,   193,   187,     0,   529,   188,   189,   190,   191,   192,
     193,     0,   265,     0,     0,     0,   191,   192,   193,     0,
       0,   280,   310,     0,     0,   311,   312,   313,     0,   325,
       0,   310,     0,     0,   311,   312,   313,     0,     0,     0,
     191,   192,   193,     0,     0,   310,     0,     0,   311,   312,
     313,     0,     0,   524,   314,   315,   316,   317,     0,   318,
     319,   320,   321,   314,   315,   316,   317,   407,   318,   319,
     320,   321,     0,     0,     0,     0,   408,   314,   315,   316,
     317,     0,   318,   319,   320,   321,     0,     0,   310,     0,
     409,   311,   312,   313,     0,     0,     0,   310,     0,     0,
     311,   312,   313,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     314,   315,   316,   317,     0,   318,   319,   320,   321,   314,
     315,   316,   317,   413,   318,   319,   320,   321
};

static const yytype_int16 yycheck[] =
{
     139,   157,   177,   225,   165,   226,   344,   225,   147,    71,
       3,     4,   329,   278,     3,     4,   155,    40,    41,   347,
      78,     3,     4,     3,     4,     3,    33,    34,     3,    18,
      71,     3,     4,    22,    20,     4,    15,    26,    27,    28,
     392,    74,    65,   398,     0,    68,    35,    80,   187,   188,
     189,   190,   191,   192,   193,    78,    20,     3,    30,    31,
      33,    68,    69,    86,   382,    13,    16,   223,   126,    74,
     226,     4,    18,     6,   292,    80,    71,    25,   299,    58,
      33,    34,    71,    12,   439,   350,    79,    74,   244,    78,
      79,   153,   154,    80,   422,   423,    82,    79,     4,    79,
       6,    79,   440,   126,    79,   128,   129,    79,   425,   427,
      79,    84,    85,   465,    74,   467,    69,    81,    82,   142,
      80,    72,   145,    56,    57,    47,    71,   283,   284,   285,
     286,   287,   288,   289,   290,   400,    74,   455,    60,    14,
     198,   363,    80,   364,     9,   363,    79,   322,    33,    34,
      56,    57,    72,   176,   310,   311,   312,   313,   314,   315,
     316,   317,   318,   319,   320,   321,     3,     4,    10,    33,
      34,   327,   390,   334,   392,   198,    63,    64,    65,   202,
     203,    18,   500,   501,    69,    22,    32,    33,    34,    26,
      27,    28,     3,     4,    74,    74,    74,   415,    35,     7,
      80,    80,    80,   521,    68,    69,    73,    18,    74,   474,
     475,    22,    23,   531,    80,    26,    27,    28,    75,    74,
      77,    67,    68,    69,    35,    80,    36,    37,    38,    39,
      40,    41,    42,    43,    71,    19,     3,     4,    74,     6,
      74,   463,    79,   508,    80,   463,    80,   465,    74,   467,
      76,   407,   408,   409,    46,    47,    48,    49,    50,    51,
      52,    53,   527,    30,    31,    75,    72,   442,    79,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    72,
      74,     3,     4,    50,    78,    32,    33,    34,    71,    56,
      57,     3,     4,    74,     6,    74,    18,    10,    11,    80,
      22,    80,     7,    70,    26,    27,    28,     7,    75,    74,
      77,    74,    79,    35,    74,    80,    76,    80,    30,    31,
      67,    68,    69,    82,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,     3,     4,     3,     4,    50,    74,
      74,    76,    76,    29,    56,    57,    32,    33,    34,    71,
      74,    18,    76,     3,     4,    22,    78,    79,    70,    26,
      27,    28,    77,    75,    79,    77,   522,    79,    35,     3,
     509,     3,     4,    82,     3,     4,    79,    63,    64,    23,
      66,    67,    68,    69,    79,    74,    18,    76,    79,    18,
      22,     3,     4,    22,    26,    27,    28,    26,    27,    28,
       3,     4,    81,    35,    71,    77,    35,    79,    33,    34,
       4,    78,    79,    33,    34,    18,     8,     8,    71,    22,
      18,     3,    11,    26,    27,    28,    21,    10,     3,     3,
       4,    79,    35,    29,     3,    20,    32,    33,    34,    71,
      20,    20,    71,    73,    18,     3,    78,    79,    22,    78,
      79,    79,    26,    27,    28,    79,    79,    26,    27,    28,
      75,    35,    79,     3,     3,    72,    35,    23,    71,     3,
      66,    67,    68,    69,    20,    78,    79,    46,    47,    48,
      49,    50,    51,    52,    53,    20,    55,    17,    33,    34,
      59,     3,    26,    27,    28,    33,    34,    71,    20,    20,
      81,    35,    71,     3,    78,    79,    79,    20,    50,    78,
      21,    73,    46,    47,    48,    49,    50,    51,    52,    53,
      79,    55,    67,    68,    69,    59,    26,    27,    28,    67,
      68,    69,     9,    77,     4,    35,    29,    71,     3,    32,
      33,    34,    73,     3,    78,    20,    46,    47,    48,    49,
      50,    51,    52,    53,     3,    55,    79,    21,    21,    59,
      77,    26,    27,    28,    61,    62,    63,    64,    65,    79,
      35,    71,     3,    79,    67,    68,    69,    79,    78,    75,
      79,    46,    47,    48,    49,    50,    51,    52,    53,    79,
      55,    79,    79,    75,    59,    26,    27,    28,   182,   183,
     184,   185,   186,    79,    35,    76,    71,     3,    11,    82,
      34,    80,    74,    78,    80,    46,    47,    48,    49,    50,
      51,    52,    53,    74,    55,    79,    74,    79,    59,    79,
      26,    27,    28,    77,    74,    74,    74,    74,    74,    35,
      71,     3,    74,     4,    21,    21,    73,    78,    77,    75,
      46,    47,    48,    49,    50,    51,    52,    53,    79,    55,
       3,    75,    77,    59,    26,    27,    28,    76,     4,    34,
       6,    77,    80,    35,    79,    71,     4,    79,    82,     3,
      74,    80,    78,    25,    46,    47,    48,    49,    50,    51,
      52,    53,    78,    55,    30,    31,    80,    59,    77,    72,
      75,    75,    26,    27,    28,    76,     4,    79,    77,    71,
      77,    35,    80,     4,    50,     5,    78,    58,    24,    76,
      56,    57,    46,    47,    48,    49,    50,    51,    52,    53,
      77,    55,    77,    29,    73,    59,    32,    33,    34,    75,
       4,    77,    80,    79,    24,     4,    77,    71,    29,    20,
      77,    32,    33,    34,    19,   121,   436,    29,   335,    62,
      32,    33,    34,   339,   439,    61,    62,    63,    64,    86,
      66,    67,    68,    69,   156,   361,   243,   103,    -1,    -1,
      61,    62,    63,    64,    80,    66,    67,    68,    69,    61,
      62,    63,    64,    -1,    66,    67,    68,    69,    29,    80,
     150,    32,    33,    34,    -1,    -1,    -1,    29,    80,    -1,
      32,    33,    34,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    29,    -1,    -1,    32,    33,    34,    -1,    -1,
      61,    62,    63,    64,    -1,    66,    67,    68,    69,    61,
      62,    63,    64,    -1,    66,    67,    68,    69,    29,    80,
      -1,    32,    33,    34,    61,    62,    63,    64,    80,    66,
      67,    68,    69,    29,    -1,    -1,    32,    33,    34,    -1,
      -1,    -1,    29,    80,    -1,    32,    33,    34,    -1,    -1,
      61,    62,    63,    64,    -1,    66,    67,    68,    69,    29,
      -1,    -1,    32,    33,    34,    61,    62,    63,    64,    80,
      66,    67,    68,    69,    61,    62,    63,    64,    -1,    66,
      67,    68,    69,    29,    80,    -1,    32,    33,    34,    -1,
      -1,    29,    -1,    80,    32,    33,    34,    67,    68,    69,
      29,    -1,    -1,    32,    33,    34,    -1,    -1,    29,    -1,
      80,    32,    33,    34,    -1,    61,    62,    63,    64,    -1,
      66,    67,    68,    69,    -1,    -1,    -1,    -1,    -1,    67,
      68,    69,    29,    -1,    80,    32,    33,    34,    67,    68,
      69,    -1,    80,    -1,    -1,    -1,    67,    68,    69,    -1,
      -1,    80,    29,    -1,    -1,    32,    33,    34,    -1,    80,
      -1,    29,    -1,    -1,    32,    33,    34,    -1,    -1,    -1,
      67,    68,    69,    -1,    -1,    29,    -1,    -1,    32,    33,
      34,    -1,    -1,    80,    61,    62,    63,    64,    -1,    66,
      67,    68,    69,    61,    62,    63,    64,    74,    66,    67,
      68,    69,    -1,    -1,    -1,    -1,    74,    61,    62,    63,
      64,    -1,    66,    67,    68,    69,    -1,    -1,    29,    -1,
      74,    32,    33,    34,    -1,    -1,    -1,    29,    -1,    -1,
      32,    33,    34,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      61,    62,    63,    64,    -1,    66,    67,    68,    69,    61,
      62,    63,    64,    74,    66,    67,    68,    69
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
     141,   142,   143,   144,   177,    73,    10,    11,    98,    99,
      19,   109,   110,     7,     7,    82,   128,   128,    82,     3,
      79,    79,    79,    13,    25,     3,   122,   126,    79,   122,
     124,    23,   132,    81,     3,    18,   117,     3,    26,    27,
      28,    35,    46,    47,    48,    49,    50,    51,    52,    53,
      55,    59,    71,   146,   147,   163,   164,   165,   167,   168,
     169,   173,   174,   175,   176,   178,     4,     8,     8,    71,
      18,   100,   101,     3,   117,   109,    79,   122,    20,    20,
     122,    21,     3,   140,   140,     3,     4,    30,    31,    79,
     135,   136,    74,    80,   126,    20,   125,    79,   128,   128,
     124,    73,     3,    79,    79,    79,    75,    79,    15,    58,
     163,     3,    23,   170,    72,    20,    20,    17,     3,   101,
       3,    79,   112,   126,   122,   122,    20,    79,    74,    80,
      80,   136,    61,    62,    63,    64,    65,    29,    32,    33,
      34,    67,    68,    69,    80,   122,    81,    80,    79,   122,
     129,   136,    20,    20,   125,     3,     4,     6,    30,    31,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      50,    56,    57,    70,    75,    77,    79,   145,   148,   150,
     151,   155,   157,   160,   162,    21,   140,   140,   136,   146,
     162,   166,    50,    73,    79,     9,    95,   155,     4,    96,
      97,    73,     3,   113,    20,   114,    80,   122,     3,     4,
     137,   138,     3,    21,    21,    80,   135,   135,   135,   135,
     135,   136,   136,   136,   136,   136,   136,   136,    77,   126,
      80,   122,   122,    79,    79,    79,    79,    79,    79,    79,
      79,   162,    75,   152,   153,     4,     6,    56,    57,    79,
     149,   150,   156,     4,     6,    56,    57,   149,   162,    75,
      29,    32,    33,    34,    61,    62,    63,    64,    66,    67,
      68,    69,    79,    80,    80,    80,    76,    74,    80,    75,
     158,   160,   162,    11,    74,    74,    75,    77,   103,    74,
      80,     3,    79,   111,    82,    80,    79,    79,   118,    80,
      77,   162,   162,   162,   162,   162,   162,   162,   162,   150,
     154,    74,    76,    74,    74,    80,     4,   162,   162,   162,
     162,   162,   162,   162,   162,   162,   162,   162,   162,   138,
      21,    21,    77,   162,   157,   159,    80,    73,   155,    97,
      75,   104,    79,   105,   102,   113,     3,   115,    75,   137,
      77,   138,   139,   139,    71,    78,   118,    74,    74,    74,
      80,    80,    80,    74,    80,    74,    76,   153,   156,   149,
      76,    80,    79,    79,   177,    74,    76,    77,     4,   106,
     156,    74,    76,   106,    74,    78,    74,    80,   116,   120,
      82,   118,    74,    80,    80,    78,   162,   162,   162,     4,
      79,   150,    78,    80,    75,    77,   139,   139,    71,    78,
     157,   177,    72,    74,    76,    75,    80,    79,   115,    76,
     116,   137,    78,   138,    77,    77,   133,    80,    80,    80,
      80,     4,   161,     4,   177,    80,    80,    78,     5,   156,
     106,   106,   118,   118,    24,   134,    74,    80,    76,    78,
      77,    77,   171,    73,    76,    80,    78,    78,    77,    79,
       4,    80,   177,   177,    24,   172,     4,   118,   136,    78,
      78,    77,    79,    78,    80,   177,   162,    77,    78,    80,
     118,    77,    78,   177,    78
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
     140,   141,   142,   143,   144,   145,   145,   145,   146,   146,
     146,   146,   146,   146,   146,   146,   147,   148,   148,   149,
     149,   149,   149,   150,   151,   152,   152,   153,   154,   154,
     155,   156,   156,   157,   157,   157,   157,   157,   157,   157,
     157,   157,   158,   159,   159,   160,   160,   160,   160,   160,
     160,   160,   160,   160,   161,   161,   162,   162,   162,   162,
     162,   162,   162,   162,   162,   162,   162,   162,   162,   162,
     162,   162,   162,   162,   162,   163,   164,   164,   164,   165,
     166,   166,   167,   169,   168,   168,   168,   168,   168,   170,
     171,   171,   172,   172,   173,   174,   175,   176,   177,   177,
     178,   178,   178,   178,   178
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     3,     0,     9,     0,     6,     0,     6,    14,
       2,     2,     1,     1,     0,     6,     6,     3,     1,     3,
       1,     1,     0,     2,     0,     2,     1,     0,     5,     3,
       3,     5,     3,     5,     3,     3,     1,     0,     2,     2,
       0,     0,     8,     1,     3,     3,     1,     0,     2,     4,
       3,     1,     0,     2,     1,     2,     0,     1,     1,     1,
       1,     0,     2,     1,     1,     1,     1,     1,     1,     5,
       5,     4,     4,     4,     3,     1,     3,     0,     2,     3,
       1,     2,     4,     0,     2,     4,     1,     3,     5,     2,
       9,     8,     0,     4,     0,     3,     3,     3,     3,     3,
       1,     1,     3,     3,     3,     3,     3,     3,     3,     3,
       1,     1,     1,     1,     1,     3,     5,     3,     1,     3,
       1,     9,    11,    11,     7,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     4,     1,     1,     1,
       1,     1,     1,     5,     3,     3,     1,     3,     3,     1,
       5,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     3,     1,     6,     6,     6,     4,     4,
       6,     8,     4,     4,     3,     1,     1,     1,     4,     7,
       1,     3,     2,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     2,     4,     4,     4,
       3,     1,     3,     0,     2,     1,     1,     1,     1,     9,
       8,     0,     4,     0,     9,    11,    11,     7,     2,     0,
       1,     1,     1,     1,     1
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
#line 59 "./Parser/parser_main.y"
                                                                   {fprintf(fp,"\nParsing successful!\n");printBlockTable();}
#line 1746 "./exec/y.tab.c"
    break;

  case 3: /* $@1: %empty  */
#line 63 "./Parser/parser_main.y"
                                           {fprintf(fp,"\nInit section begins\n\n");}
#line 1752 "./exec/y.tab.c"
    break;

  case 4: /* init_section: '\\' INIT_BEGIN $@1 mandatory_init set_states block_defn_section gate_defn_section '\\' INIT_END  */
#line 63 "./Parser/parser_main.y"
                                                                                                                                                                   {fprintf(fp,"\nInit section ends\n");}
#line 1758 "./exec/y.tab.c"
    break;

  case 5: /* $@2: %empty  */
#line 66 "./Parser/parser_main.y"
                                            {fprintf(fp,"\nMain section begins\n\n");}
#line 1764 "./exec/y.tab.c"
    break;

  case 6: /* main_section: '\\' MAIN_BEGIN $@2 main_stmt_list '\\' MAIN_END  */
#line 66 "./Parser/parser_main.y"
                                                                                                                    {fprintf(fp,"\nMain section ends\n");}
#line 1770 "./exec/y.tab.c"
    break;

  case 7: /* $@3: %empty  */
#line 69 "./Parser/parser_main.y"
                                             {fprintf(fp,"\nOutput section begins\n\n");}
#line 1776 "./exec/y.tab.c"
    break;

  case 8: /* output_section: '\\' OUTPUT_BEGIN $@3 out_main '\\' OUTPUT_END  */
#line 69 "./Parser/parser_main.y"
                                                                                                                   {fprintf(fp,"\nOutput section ends\n");}
#line 1782 "./exec/y.tab.c"
    break;

  case 9: /* mandatory_init: '#' REGISTERS QUANTUM '=' NUMBER '#' REGISTERS CLASSICAL '=' NUMBER '#' ITERS '=' NUMBER  */
#line 77 "./Parser/parser_main.y"
                                                                                                                    {  fprintf(fp,"Register and iteration initialization section\n");classical_registers = yyvsp[-4].num;quantum_registers = yyvsp[-9].num;iterations = yyvsp[0].num;}
#line 1788 "./exec/y.tab.c"
    break;

  case 15: /* set_quantum_states: '#' SET QUANTUM STATES ARROW quantum_state_list  */
#line 88 "./Parser/parser_main.y"
                                                                            {fprintf(fp,"Setting initial state of quantum registers\n");}
#line 1794 "./exec/y.tab.c"
    break;

  case 16: /* set_classical_states: '#' SET CLASSICAL STATES ARROW classical_state_list  */
#line 91 "./Parser/parser_main.y"
                                                                                {fprintf(fp,"Setting initial state of classical registers\n");}
#line 1800 "./exec/y.tab.c"
    break;

  case 17: /* quantum_state_list: quantum_state_list ',' state_const  */
#line 94 "./Parser/parser_main.y"
                                                                     {if(quantum_index == quantum_registers){yyerror();return;}quantum_states[quantum_index++] = yyvsp[0].q;}
#line 1806 "./exec/y.tab.c"
    break;

  case 18: /* quantum_state_list: state_const  */
#line 95 "./Parser/parser_main.y"
                                          {quantum_states = (struct Quantum*)malloc(sizeof(struct Quantum)*quantum_registers);quantum_states[quantum_index++] = yyvsp[0].q;}
#line 1812 "./exec/y.tab.c"
    break;

  case 19: /* classical_state_list: classical_state_list ',' classical_state  */
#line 98 "./Parser/parser_main.y"
                                                                      {if(classical_index == classical_registers){yyerror();return;}classical_states[classical_index++] = yyvsp[0].num;}
#line 1818 "./exec/y.tab.c"
    break;

  case 20: /* classical_state_list: classical_state  */
#line 99 "./Parser/parser_main.y"
                                            {classical_states = (int *)malloc(sizeof(int)*classical_registers);classical_states[classical_index++] = yyvsp[0].num;}
#line 1824 "./exec/y.tab.c"
    break;

  case 21: /* classical_state: NUMBER  */
#line 102 "./Parser/parser_main.y"
                                    {yyval.num = yyvsp[0].num;}
#line 1830 "./exec/y.tab.c"
    break;

  case 22: /* $@4: %empty  */
#line 106 "./Parser/parser_main.y"
                           {fprintf(fp,"Gate definition section begins\n");}
#line 1836 "./exec/y.tab.c"
    break;

  case 23: /* gate_defn_section: $@4 gate_defn_list  */
#line 106 "./Parser/parser_main.y"
                                                                                            {fprintf(fp,"Gate definition section ends\n");}
#line 1842 "./exec/y.tab.c"
    break;

  case 27: /* $@5: %empty  */
#line 114 "./Parser/parser_main.y"
                                            {fprintf(fp,"Gate definition\n");}
#line 1848 "./exec/y.tab.c"
    break;

  case 28: /* gate_defn: GATE ID '=' rhs $@5  */
#line 114 "./Parser/parser_main.y"
                                                                                 {insertInGateTable(&GateSymbolTable,yyvsp[-3].str,yyvsp[-1].rows,yyvsp[-1].cols);}
#line 1854 "./exec/y.tab.c"
    break;

  case 29: /* rhs: '[' tuple_list ']'  */
#line 117 "./Parser/parser_main.y"
                                                {yyval.rows = yyvsp[-1].rows;yyval.cols = yyvsp[-1].cols;}
#line 1860 "./exec/y.tab.c"
    break;

  case 31: /* tuple_list: tuple_list ',' '[' id_list ']'  */
#line 120 "./Parser/parser_main.y"
                                                         {if(yyvsp[-4].cols != yyvsp[-1].cols){yyerror();return;}int temp; temp = yyvsp[-4].rows + 1;yyval.rows = temp;yyval.cols = yyvsp[-4].cols;}
#line 1866 "./exec/y.tab.c"
    break;

  case 32: /* tuple_list: '[' id_list ']'  */
#line 121 "./Parser/parser_main.y"
                                                         {yyval.rows = 1;yyval.cols = yyvsp[-1].cols;}
#line 1872 "./exec/y.tab.c"
    break;

  case 35: /* id_list: id_list ',' temp  */
#line 126 "./Parser/parser_main.y"
                                             {yyval.cols += 1;}
#line 1878 "./exec/y.tab.c"
    break;

  case 36: /* id_list: temp  */
#line 127 "./Parser/parser_main.y"
                                             {yyval.cols = 1;}
#line 1884 "./exec/y.tab.c"
    break;

  case 37: /* $@6: %empty  */
#line 130 "./Parser/parser_main.y"
                           {fprintf(fp,"Block definition section begins\n");}
#line 1890 "./exec/y.tab.c"
    break;

  case 38: /* block_defn_section: $@6 block_defns_list  */
#line 130 "./Parser/parser_main.y"
                                                                                               {fprintf(fp,"Block definition section ends\n");}
#line 1896 "./exec/y.tab.c"
    break;

  case 41: /* $@7: %empty  */
#line 137 "./Parser/parser_main.y"
                                                              {insertInBlockTable(&BlockSymbolTable,yyvsp[-2].str,yyvsp[-1].num,head);head = NULL;isInBlock = 1;}
#line 1902 "./exec/y.tab.c"
    break;

  case 42: /* block_defn: BLOCK block_id params target_params $@7 '[' block_body ']'  */
#line 137 "./Parser/parser_main.y"
                                                                                                                                                                      {fprintf(fp,"Block definition\n");if(!BlockSemanticCheck(yyvsp[-6].str)){yyerror();return;}id_list = NULL;isInBlock = 0;}
#line 1908 "./exec/y.tab.c"
    break;

  case 43: /* params: ID  */
#line 140 "./Parser/parser_main.y"
                                                {insertInList(&head,yyvsp[0].str);yyval.num = 1;}
#line 1914 "./exec/y.tab.c"
    break;

  case 44: /* params: '(' param_id_list ')'  */
#line 141 "./Parser/parser_main.y"
                                                {yyval.num = yyvsp[-1].num;}
#line 1920 "./exec/y.tab.c"
    break;

  case 45: /* param_id_list: ID ',' param_id_list  */
#line 144 "./Parser/parser_main.y"
                                                {insertInList(&head,yyvsp[-2].str);yyval.num = 1 + yyvsp[0].num;}
#line 1926 "./exec/y.tab.c"
    break;

  case 46: /* param_id_list: ID  */
#line 145 "./Parser/parser_main.y"
                                                {insertInList(&head,yyvsp[0].str);yyval.num = 1;}
#line 1932 "./exec/y.tab.c"
    break;

  case 54: /* block_id: ID  */
#line 161 "./Parser/parser_main.y"
                                  {yyval = yyvsp[0];}
#line 1938 "./exec/y.tab.c"
    break;

  case 58: /* main_stmt: barrier_stmt  */
#line 174 "./Parser/parser_main.y"
                                          {fprintf(fp,"barrier statement\n");}
#line 1944 "./exec/y.tab.c"
    break;

  case 60: /* stmts: measure_stmt  */
#line 177 "./Parser/parser_main.y"
                                          {fprintf(fp,"Measure statement\n");}
#line 1950 "./exec/y.tab.c"
    break;

  case 61: /* $@8: %empty  */
#line 178 "./Parser/parser_main.y"
                          {fprintf(fp,"Conditional statement begin\n");}
#line 1956 "./exec/y.tab.c"
    break;

  case 62: /* stmts: $@8 condition_stmt  */
#line 178 "./Parser/parser_main.y"
                                                                                        {fprintf(fp,"Conditional statement end\n");}
#line 1962 "./exec/y.tab.c"
    break;

  case 63: /* stmts: for_stmt  */
#line 179 "./Parser/parser_main.y"
                                          {fprintf(fp,"For statement\n");}
#line 1968 "./exec/y.tab.c"
    break;

  case 64: /* stmts: for_lex_stmt  */
#line 180 "./Parser/parser_main.y"
                                          {fprintf(fp,"For - Lex statement\n");}
#line 1974 "./exec/y.tab.c"
    break;

  case 65: /* stmts: for_zip_stmt  */
#line 181 "./Parser/parser_main.y"
                                          {fprintf(fp,"For - Zip statement\n");}
#line 1980 "./exec/y.tab.c"
    break;

  case 66: /* stmts: while_stmt  */
#line 182 "./Parser/parser_main.y"
                                          {fprintf(fp,"while statement\n");}
#line 1986 "./exec/y.tab.c"
    break;

  case 68: /* register: ID  */
#line 186 "./Parser/parser_main.y"
                                  {if(isInBlock){insertInList(&id_list,yyvsp[0].str);}}
#line 1992 "./exec/y.tab.c"
    break;

  case 69: /* call_stmt: classic_control GATE quantum_control ARROW register  */
#line 191 "./Parser/parser_main.y"
                                                                              {fprintf(fp,"Pre - defined Gate call statement\n");}
#line 1998 "./exec/y.tab.c"
    break;

  case 70: /* call_stmt: classic_control ID quantum_control ARROW register  */
#line 192 "./Parser/parser_main.y"
                                                                              {fprintf(fp,"user - defined Gate call statement\n");}
#line 2004 "./exec/y.tab.c"
    break;

  case 71: /* call_stmt: GATE quantum_control ARROW register  */
#line 193 "./Parser/parser_main.y"
                                                                              {fprintf(fp,"Pre - defined Gate call statement\n");}
#line 2010 "./exec/y.tab.c"
    break;

  case 72: /* call_stmt: ID quantum_control ARROW register  */
#line 194 "./Parser/parser_main.y"
                                                                              {fprintf(fp,"User - defined Gate call statement\n");}
#line 2016 "./exec/y.tab.c"
    break;

  case 73: /* call_stmt: classic_control block_id parameters optional  */
#line 195 "./Parser/parser_main.y"
                                                                              {fprintf(fp,"Block call statement\n");if(!isInBlock){if(!BlockCallSemanticCheck(yyvsp[-2].str,yyvsp[-1].num)){yyerror();return;}}}
#line 2022 "./exec/y.tab.c"
    break;

  case 74: /* call_stmt: block_id parameters optional  */
#line 196 "./Parser/parser_main.y"
                                                                              {fprintf(fp,"Block call statement\n");if(!isInBlock){if(!BlockCallSemanticCheck(yyvsp[-2].str,yyvsp[-1].num)){yyerror();return;}}}
#line 2028 "./exec/y.tab.c"
    break;

  case 75: /* parameters: register  */
#line 199 "./Parser/parser_main.y"
                                                   {yyval.num = 1;}
#line 2034 "./exec/y.tab.c"
    break;

  case 76: /* parameters: '(' register_list ')'  */
#line 200 "./Parser/parser_main.y"
                                                   {yyval.num = yyvsp[-1].num;}
#line 2040 "./exec/y.tab.c"
    break;

  case 79: /* register_list: register_list ',' register  */
#line 207 "./Parser/parser_main.y"
                                                      {yyval.num = 1 + yyvsp[-2].num;}
#line 2046 "./exec/y.tab.c"
    break;

  case 80: /* register_list: register  */
#line 208 "./Parser/parser_main.y"
                                                      {yyval.num = 1;}
#line 2052 "./exec/y.tab.c"
    break;

  case 139: /* num: DEC  */
#line 332 "./Parser/parser_main.y"
                                    {yyval.real = yyvsp[0].real;}
#line 2058 "./exec/y.tab.c"
    break;

  case 140: /* num: NEG  */
#line 333 "./Parser/parser_main.y"
                                    {yyval.real = yyvsp[0].real;}
#line 2064 "./exec/y.tab.c"
    break;

  case 141: /* num: EXP  */
#line 334 "./Parser/parser_main.y"
                                    {yyval.real = yyvsp[0].real;}
#line 2070 "./exec/y.tab.c"
    break;

  case 142: /* num: NUMBER  */
#line 335 "./Parser/parser_main.y"
                                    {yyval.real = yyvsp[0].num;}
#line 2076 "./exec/y.tab.c"
    break;

  case 143: /* complex_const: '(' num ',' num ')'  */
#line 337 "./Parser/parser_main.y"
                                                   {yyval.cpx.real = yyvsp[-3].real; yyval.cpx.imag = yyvsp[-1].real;}
#line 2082 "./exec/y.tab.c"
    break;

  case 150: /* state_const: '{' temp ',' temp '}'  */
#line 354 "./Parser/parser_main.y"
                                                   {yyval.q.first = yyvsp[-3].cpx; yyval.q.second = yyvsp[-1].cpx;}
#line 2088 "./exec/y.tab.c"
    break;

  case 151: /* temp: complex_const  */
#line 357 "./Parser/parser_main.y"
                                          {yyval.cpx = yyvsp[0].cpx;}
#line 2094 "./exec/y.tab.c"
    break;

  case 152: /* temp: num  */
#line 358 "./Parser/parser_main.y"
                                          {yyval.cpx.real = yyvsp[0].real; yyval.cpx.imag = 0;}
#line 2100 "./exec/y.tab.c"
    break;

  case 153: /* prim_const: bool_const  */
#line 361 "./Parser/parser_main.y"
                                     {yyval.type = Bool;}
#line 2106 "./exec/y.tab.c"
    break;

  case 154: /* prim_const: complex_const  */
#line 362 "./Parser/parser_main.y"
                                        {yyval.type = Complex;}
#line 2112 "./exec/y.tab.c"
    break;

  case 155: /* prim_const: matrix_const  */
#line 363 "./Parser/parser_main.y"
                                       {yyval.type = Matrix;}
#line 2118 "./exec/y.tab.c"
    break;

  case 156: /* prim_const: state_const  */
#line 364 "./Parser/parser_main.y"
                                      {yyval.type = State;}
#line 2124 "./exec/y.tab.c"
    break;

  case 157: /* prim_const: NUMBER  */
#line 365 "./Parser/parser_main.y"
                                 {yyval.type = Uint;}
#line 2130 "./exec/y.tab.c"
    break;

  case 158: /* prim_const: NEG  */
#line 366 "./Parser/parser_main.y"
                              {yyval.type = Int;}
#line 2136 "./exec/y.tab.c"
    break;

  case 159: /* prim_const: DEC  */
#line 367 "./Parser/parser_main.y"
                              {yyval.type = Float;}
#line 2142 "./exec/y.tab.c"
    break;

  case 160: /* prim_const: EXP  */
#line 368 "./Parser/parser_main.y"
                              {yyval.type = Float;}
#line 2148 "./exec/y.tab.c"
    break;

  case 161: /* prim_const: STRING  */
#line 369 "./Parser/parser_main.y"
                                 {yyval.type = String;}
#line 2154 "./exec/y.tab.c"
    break;

  case 163: /* vec_list: vec_list ',' prim_const  */
#line 375 "./Parser/parser_main.y"
                                                  {/* Compatibility needs to be checked */}
#line 2160 "./exec/y.tab.c"
    break;

  case 164: /* vec_list: prim_const  */
#line 376 "./Parser/parser_main.y"
                                     {yyval.type = yyvsp[0].type;}
#line 2166 "./exec/y.tab.c"
    break;

  case 195: /* out_expr: ID '=' out_rhs  */
#line 419 "./Parser/parser_main.y"
                                                      {fprintf(fp,"expression statement\n");}
#line 2172 "./exec/y.tab.c"
    break;

  case 196: /* decl: prim_type out_expr  */
#line 422 "./Parser/parser_main.y"
                                                      {fprintf(fp,"Primitive datatype declaration statement\n");}
#line 2178 "./exec/y.tab.c"
    break;

  case 197: /* decl: list_type ID '=' vec_const  */
#line 423 "./Parser/parser_main.y"
                                                      {fprintf(fp,"List datatype declaration statement\n");}
#line 2184 "./exec/y.tab.c"
    break;

  case 198: /* decl: list_type ID '=' calls  */
#line 424 "./Parser/parser_main.y"
                                                      {fprintf(fp,"List datatype declaration statement\n");}
#line 2190 "./exec/y.tab.c"
    break;

  case 199: /* echo_stmt: ECHO '(' echo_list ')'  */
#line 428 "./Parser/parser_main.y"
                                                      {fprintf(fp,"Echo statement\n");}
#line 2196 "./exec/y.tab.c"
    break;

  case 202: /* save_stmt: '\\' SAVE STRING  */
#line 436 "./Parser/parser_main.y"
                                                      {fprintf(fp,"Save statement\n");}
#line 2202 "./exec/y.tab.c"
    break;

  case 203: /* $@9: %empty  */
#line 440 "./Parser/parser_main.y"
                          {fprintf(fp,"Output section conditional statement begins\n");}
#line 2208 "./exec/y.tab.c"
    break;

  case 204: /* out_control: $@9 out_cond_stmt  */
#line 440 "./Parser/parser_main.y"
                                                                                                       {fprintf(fp,"Output section conditional statement ends\n");}
#line 2214 "./exec/y.tab.c"
    break;

  case 205: /* out_control: out_for_stmt  */
#line 441 "./Parser/parser_main.y"
                                                      {fprintf(fp,"For statement in output section\n");}
#line 2220 "./exec/y.tab.c"
    break;

  case 206: /* out_control: out_for_lex_stmt  */
#line 442 "./Parser/parser_main.y"
                                                      {fprintf(fp,"For - lex statement in output section\n");}
#line 2226 "./exec/y.tab.c"
    break;

  case 207: /* out_control: out_for_zip_stmt  */
#line 443 "./Parser/parser_main.y"
                                                      {fprintf(fp,"For - zip statement in output section\n");}
#line 2232 "./exec/y.tab.c"
    break;

  case 208: /* out_control: out_while_stmt  */
#line 444 "./Parser/parser_main.y"
                                                      {fprintf(fp,"while statement in output section\n");}
#line 2238 "./exec/y.tab.c"
    break;


#line 2242 "./exec/y.tab.c"

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

#line 482 "./Parser/parser_main.y"


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
