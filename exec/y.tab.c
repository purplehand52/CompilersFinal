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

   struct List* head = NULL,*head2=NULL;
   struct BlockTable* BlockSymbolTable = NULL;
   struct GateTable* GateSymbolTable = NULL;

#line 93 "./exec/y.tab.c"

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
  YYSYMBOL_for_lex_stmt = 141,             /* for_lex_stmt  */
  YYSYMBOL_for_zip_stmt = 142,             /* for_zip_stmt  */
  YYSYMBOL_while_stmt = 143,               /* while_stmt  */
  YYSYMBOL_out_id = 144,                   /* out_id  */
  YYSYMBOL_prim_type = 145,                /* prim_type  */
  YYSYMBOL_list_type = 146,                /* list_type  */
  YYSYMBOL_bool_const = 147,               /* bool_const  */
  YYSYMBOL_num = 148,                      /* num  */
  YYSYMBOL_complex_const = 149,            /* complex_const  */
  YYSYMBOL_matrix_const = 150,             /* matrix_const  */
  YYSYMBOL_row_list = 151,                 /* row_list  */
  YYSYMBOL_row = 152,                      /* row  */
  YYSYMBOL_comps = 153,                    /* comps  */
  YYSYMBOL_state_const = 154,              /* state_const  */
  YYSYMBOL_temp = 155,                     /* temp  */
  YYSYMBOL_prim_const = 156,               /* prim_const  */
  YYSYMBOL_vec_const = 157,                /* vec_const  */
  YYSYMBOL_vec_list = 158,                 /* vec_list  */
  YYSYMBOL_calls = 159,                    /* calls  */
  YYSYMBOL_uint_list = 160,                /* uint_list  */
  YYSYMBOL_out_rhs = 161,                  /* out_rhs  */
  YYSYMBOL_out_expr = 162,                 /* out_expr  */
  YYSYMBOL_decl = 163,                     /* decl  */
  YYSYMBOL_echo_stmt = 164,                /* echo_stmt  */
  YYSYMBOL_echo_list = 165,                /* echo_list  */
  YYSYMBOL_save_stmt = 166,                /* save_stmt  */
  YYSYMBOL_out_control = 167,              /* out_control  */
  YYSYMBOL_168_8 = 168,                    /* $@8  */
  YYSYMBOL_out_cond_stmt = 169,            /* out_cond_stmt  */
  YYSYMBOL_out_other_list = 170,           /* out_other_list  */
  YYSYMBOL_out_other_final = 171,          /* out_other_final  */
  YYSYMBOL_out_for_stmt = 172,             /* out_for_stmt  */
  YYSYMBOL_out_for_lex_stmt = 173,         /* out_for_lex_stmt  */
  YYSYMBOL_out_for_zip_stmt = 174,         /* out_for_zip_stmt  */
  YYSYMBOL_out_while_stmt = 175,           /* out_while_stmt  */
  YYSYMBOL_out_main = 176,                 /* out_main  */
  YYSYMBOL_out_stmt = 177                  /* out_stmt  */
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
#define YYLAST   1115

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  83
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  95
/* YYNRULES -- Number of rules.  */
#define YYNRULES  223
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  534

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
       0,    53,    53,    57,    57,    60,    60,    63,    63,    71,
      75,    76,    77,    78,    79,    82,    85,    88,    89,    92,
      93,    96,   100,   100,   101,   104,   105,   108,   108,   111,
     112,   114,   115,   117,   118,   120,   121,   124,   124,   127,
     128,   131,   134,   135,   138,   139,   142,   143,   144,   147,
     148,   151,   152,   155,   163,   164,   167,   168,   170,   171,
     172,   172,   173,   174,   175,   176,   179,   180,   185,   186,
     187,   188,   189,   190,   193,   194,   197,   198,   201,   202,
     205,   206,   209,   210,   211,   214,   215,   229,   232,   235,
     238,   239,   242,   243,   246,   247,   248,   249,   250,   251,
     252,   255,   256,   257,   258,   259,   260,   261,   262,   263,
     264,   265,   269,   270,   273,   274,   277,   278,   281,   282,
     285,   288,   291,   294,   303,   303,   303,   305,   306,   307,
     308,   309,   310,   311,   312,   315,   322,   323,   326,   327,
     328,   329,   331,   334,   337,   338,   341,   344,   345,   348,
     351,   352,   355,   356,   357,   358,   359,   360,   361,   362,
     363,   366,   369,   370,   374,   375,   376,   377,   378,   379,
     380,   381,   382,   386,   387,   391,   392,   393,   394,   395,
     396,   397,   398,   399,   400,   401,   402,   403,   404,   405,
     406,   407,   408,   409,   413,   416,   417,   418,   422,   425,
     426,   430,   434,   434,   435,   436,   437,   438,   441,   444,
     445,   448,   449,   452,   455,   458,   461,   466,   467,   470,
     471,   472,   473,   474
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
  "block_defn_section", "$@6", "block_defns_list", "block_defn", "params",
  "param_id_list", "target_params", "target_param_list", "block_body",
  "block_id", "main_stmt_list", "main_stmt", "stmts", "$@7", "register",
  "call_stmt", "parameters", "optional", "register_list",
  "classic_control", "quantum_control", "target", "measure_stmt",
  "barrier_stmt", "condition_stmt", "otherwise_list", "otherwise_final",
  "arithmetic_expr", "expr", "value", "range", "range_list", "var_list",
  "for_stmt", "for_lex_stmt", "for_zip_stmt", "while_stmt", "out_id",
  "prim_type", "list_type", "bool_const", "num", "complex_const",
  "matrix_const", "row_list", "row", "comps", "state_const", "temp",
  "prim_const", "vec_const", "vec_list", "calls", "uint_list", "out_rhs",
  "out_expr", "decl", "echo_stmt", "echo_list", "save_stmt", "out_control",
  "$@8", "out_cond_stmt", "out_other_list", "out_other_final",
  "out_for_stmt", "out_for_lex_stmt", "out_for_zip_stmt", "out_while_stmt",
  "out_main", "out_stmt", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-376)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-142)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -31,    52,    43,    14,  -376,  -376,    87,    34,    46,  -376,
     108,  -376,   127,    76,  -376,  -376,   129,   183,  -376,   125,
     148,    11,  -376,   160,   194,   153,   226,   258,  -376,   273,
    -376,    35,  -376,   202,   209,   239,   215,   219,   228,    31,
     351,    17,  -376,  -376,   301,   257,  -376,    27,  -376,  -376,
    -376,  -376,  -376,  -376,   703,   343,   354,   362,   280,   364,
     371,  -376,   226,   372,   384,    19,   365,   378,   351,   381,
     400,   400,    28,  -376,  -376,  -376,  -376,   -38,   351,  -376,
     385,   327,  -376,  -376,    -1,   202,    17,   335,   406,   331,
     342,   344,  -376,  -376,  -376,  -376,  -376,  -376,  -376,  -376,
     339,   346,    26,   419,   423,  -376,  -376,  -376,  -376,  -376,
     421,  -376,  -376,  -376,  -376,  -376,   357,   426,   436,   441,
     460,   364,  -376,  -376,    25,  -376,   351,  -376,   351,   351,
     445,   390,  -376,     3,    23,  -376,  -376,  -376,  -376,    28,
     253,   150,   351,   391,    40,    21,  -376,    28,   453,   457,
     385,   233,   458,   400,   400,    28,   794,   233,  -376,   428,
    -376,   407,   402,  -376,   473,   408,   480,  -376,   417,  -376,
    -376,   488,   472,    41,  -376,  -376,   351,   375,   492,   482,
     483,   887,   377,   377,   377,   377,   377,    28,    28,    28,
      28,    28,    28,    28,   438,  -376,  -376,  -376,   351,  -376,
    -376,   919,   351,   351,  -376,  -376,  -376,  -376,  -376,  -376,
     439,   440,   442,   446,   447,   449,   450,   451,  -376,  -376,
    -376,  -376,  -376,   233,   463,    56,   289,   465,  -376,  -376,
    -376,  -376,  -376,  -376,  1029,   462,    45,   113,   928,   474,
    1029,   114,  -376,   730,   233,   506,   478,  -376,  -376,   479,
    -376,    69,   485,   481,    32,   487,  -376,  -376,  -376,  -376,
     490,   484,  -376,   475,   494,  -376,   197,   197,  -376,  -376,
    -376,   254,   140,   526,  -376,   134,   107,   224,  -376,   115,
     486,  -376,  -376,   233,   233,   233,   233,   233,   233,   233,
     233,   356,   505,     0,  -376,  -376,  -376,  -376,  -376,    67,
    -376,  -376,   501,   512,   513,   514,   516,   520,   731,   591,
     233,   233,   233,   233,   233,   233,   233,   233,   233,   233,
     233,   233,   375,   575,   576,   521,  -376,   233,  -376,   382,
    -376,  -376,   746,   534,   408,   480,   524,   531,  -376,   488,
    -376,  -376,   600,   448,   375,   532,   375,   375,   188,  -376,
    -376,   960,   977,   986,   755,   796,   805,  1003,   820,  -376,
      75,   463,  -376,    56,    67,  -376,   543,   367,   268,   587,
    -376,  1046,  1046,   468,   468,   537,   144,   152,   356,   542,
     544,   549,  -376,  1029,  -376,   164,   552,   626,  -376,  -376,
      56,   223,    56,   -17,  -376,  -376,   557,   553,   556,   448,
     558,  -376,  -376,   151,   154,   610,  -376,   278,   233,   233,
     233,  -376,  -376,  -376,    22,  -376,   505,  -376,  -376,   560,
     559,   566,   567,   375,   375,   461,   382,  -376,  -376,   570,
     235,  -376,   578,  -376,   155,   577,  -376,   600,  -376,  -376,
    -376,   375,   349,   375,   580,   582,  -376,   846,   861,   870,
     583,   651,  -376,  -376,  -376,   660,  -376,   167,   175,   607,
    -376,  -376,   496,   661,    56,  -376,    56,  -376,    56,  -376,
    -376,  -376,  -376,  -376,  -376,   643,  -376,  -376,  -376,  -376,
    -376,   176,   592,   530,   595,   596,  -376,   601,  -376,   274,
     205,   369,   389,   281,  -376,   671,   598,  -376,  -376,  -376,
    -376,   652,   675,  -376,  -376,  -376,  -376,  -376,    28,  -376,
    -376,   565,   599,   284,  -376,  -376,   415,   936,  -376,  -376,
    -376,   233,  -376,   611,   634,   911,  -376,  -376,   613,   427,
    -376,  -376,   668,  -376
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     3,     1,     0,     0,     0,     5,
       0,     2,     0,    14,    55,     7,     0,     0,    37,    12,
      13,    60,   218,     0,     0,    22,    40,     0,    10,     0,
      11,    53,    66,    82,     0,     0,     0,     0,     0,     0,
       0,     0,    54,    56,     0,     0,    58,     0,    59,    57,
      62,    63,    64,    65,   202,     0,     0,     0,     0,     0,
       0,    38,    40,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     6,    88,    67,    79,     0,     0,    74,
      76,     0,    61,    80,    53,    82,     0,     0,     0,     0,
       0,     0,   127,   128,   129,   130,   131,   132,   133,   134,
       0,     0,     0,     0,     0,   222,   223,   221,   220,   219,
       0,   204,   205,   206,   207,   217,     0,     0,     0,     0,
       0,    23,    26,    53,     0,    39,     0,    83,     0,     0,
       0,     0,   119,     0,     0,    99,   100,   110,   111,     0,
     109,     0,     0,     0,     0,     0,    73,     0,     0,     0,
      76,     0,     0,     0,     0,     0,     0,     0,     8,     0,
     195,     0,     0,   203,     0,     0,     0,     4,     0,    25,
      42,     0,    46,     0,    71,    70,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    78,    81,    75,     0,    85,
      77,     0,     0,     0,    72,   124,   156,   157,   136,   137,
       0,     0,     0,     0,     0,     0,     0,     0,   125,   126,
     160,   158,   159,     0,     0,     0,     0,   176,   152,   153,
     154,   155,   175,   179,   194,     0,     0,     0,     0,     0,
     200,     0,   201,     0,     0,     0,    15,    18,    21,    16,
      20,     0,    45,     0,     0,     0,    84,    87,   113,   112,
       0,     0,   118,     0,     0,   108,    94,    95,    96,    97,
      98,   101,   102,   103,   104,   106,   105,   107,    55,     0,
       0,    69,    68,     0,     0,     0,     0,     0,     0,     0,
       0,   181,     0,     0,   145,   141,   139,   138,   140,     0,
     151,   150,     0,   156,   157,   158,   159,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   135,     0,   198,     0,
     196,   197,     0,     0,     0,     0,     0,     0,    27,     0,
      43,    47,     0,    51,     0,     0,     0,     0,    60,    86,
      55,     0,     0,     0,     0,     0,     0,     0,     0,   148,
       0,     0,   143,     0,     0,   180,     0,   184,   185,   182,
     183,   188,   189,   186,   187,   190,   191,   192,   193,     0,
       0,     0,   218,   199,   163,     0,     0,     0,    17,    19,
       0,     0,     0,     0,    28,    44,    50,     0,     0,    51,
     114,    55,   117,     0,     0,     0,   123,    60,     0,     0,
       0,   167,   168,   172,     0,   171,     0,   146,   144,     0,
       0,   177,     0,     0,     0,   202,     0,   161,   218,     0,
       0,    36,     0,    29,     0,     0,    30,     0,    48,    41,
      52,     0,    60,     0,     0,     0,    91,     0,     0,     0,
       0,     0,   147,   149,   142,     0,   218,     0,     0,     0,
     216,   162,   202,     0,     0,    32,     0,    34,     0,    49,
     115,   120,   116,    55,    55,    93,   164,   165,   166,   169,
     174,     0,     0,   202,     0,     0,   210,     0,    35,     0,
       0,    60,    60,     0,    89,     0,     0,   178,   213,   218,
     218,   212,     0,    31,    33,   121,   122,    55,     0,   173,
     170,   202,   202,     0,   208,     9,    60,     0,   214,   215,
     218,     0,    92,     0,   202,     0,    55,   211,     0,    60,
     218,    90,   202,   209
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -376,  -376,  -376,  -376,  -376,  -376,  -376,  -376,  -376,  -376,
     672,   678,  -376,  -376,   363,  -376,  -376,  -376,   579,  -376,
    -376,  -376,  -376,  -375,  -376,  -376,   629,  -376,  -376,   360,
    -376,   264,   303,   -13,  -275,  -376,  -330,  -376,    24,  -376,
     618,   561,   -60,  -376,    -6,  -376,  -376,  -376,  -376,  -376,
    -376,   158,  -139,  -335,  -175,  -337,   -59,  -376,  -376,  -376,
    -376,  -376,   551,  -376,  -376,  -219,  -220,  -376,  -376,   347,
    -376,  -159,  -221,  -318,  -376,  -376,   466,  -376,  -156,   619,
    -376,  -376,  -376,  -376,  -376,  -376,  -376,  -376,  -376,  -376,
    -376,  -376,  -376,  -319,  -376
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     2,     3,     8,     7,    14,    11,    22,    13,    18,
      19,    20,   246,   249,   250,    58,    59,   121,   122,   394,
     338,   391,   393,   430,    25,    26,    61,    62,   172,   253,
     255,   397,   398,    41,    21,    42,    43,    44,    45,    46,
      80,   146,    77,    47,    66,   200,    48,    49,    82,   475,
     494,   140,   141,   260,   402,   403,   133,    50,    51,    52,
      53,   227,   103,   104,   228,   300,   229,   230,   293,   294,
     360,   231,   431,   232,   330,   385,   233,   481,   234,   105,
     106,   107,   241,   108,   109,   110,   163,   501,   514,   111,
     112,   113,   114,    54,   115
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     181,   240,   261,   348,   302,   301,   247,   307,   201,   400,
     404,   384,   134,   399,    31,    32,   238,   434,   144,   -82,
      75,    32,    75,    32,    75,    32,   450,    67,   170,    33,
      84,   135,   136,    34,    86,   341,   142,    35,    36,    37,
       1,   158,   143,     5,    73,    85,    38,   124,   271,   272,
     273,   274,   275,   276,   277,   -82,    74,   435,   137,   138,
     295,   436,   296,   425,    76,    79,   173,   291,     4,   399,
     308,   295,   359,   296,   361,   407,   362,   178,   148,   149,
     307,    65,    39,   179,   159,     6,   457,   458,   332,   127,
      40,   489,   130,   490,   236,   237,    78,   178,   126,     9,
     198,   451,    76,   180,   171,    10,   470,   139,   461,   462,
      79,   342,   297,   298,   142,   142,   -67,    65,    12,   178,
     197,   256,    15,   297,   298,   323,   442,   351,   352,   353,
     354,   355,   356,   357,   358,   299,    16,   483,   279,    23,
     189,   190,   419,   301,   336,   420,   337,   379,    17,   416,
      76,   417,   174,   175,   367,   368,   369,   370,   371,   372,
     373,   374,   375,   376,   377,   378,   195,   189,   190,   199,
     301,   383,   301,   189,   190,   388,   193,   312,   313,   187,
     511,   512,   188,   189,   190,   312,   313,   178,   327,   142,
      24,    31,    32,   324,   328,   349,   452,    27,   491,   492,
     257,   524,   192,   193,    56,    57,    33,   191,   192,   193,
      34,   532,   320,   321,    35,    36,    37,   191,   192,   193,
      29,   321,    76,    38,   -24,   443,   281,   282,   443,   464,
     194,   444,   516,    55,   445,   467,   205,   206,   426,   207,
     427,   443,    69,   488,   301,    60,   301,   484,   301,   443,
     495,   529,   447,   448,   449,   485,   496,   189,   190,   405,
     184,   185,   186,   208,   209,    63,   406,    40,   472,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   464,
      64,    31,    32,   220,    65,   504,   188,   189,   190,   221,
     222,    68,   205,   303,    70,   304,    33,   432,    71,   433,
      34,   312,   313,   223,    35,    36,    37,    72,   224,   464,
     225,   465,   226,    38,   182,   183,   184,   185,   186,   208,
     209,   191,   192,   193,    81,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   319,   320,   321,    83,   220,
     266,   267,   268,   269,   270,   305,   306,   116,   464,   405,
     503,   119,    31,    32,    75,    32,   446,    40,   507,   223,
     508,   520,   117,   521,   224,   525,   225,    33,   226,   517,
     118,    34,    31,    32,   123,    35,    36,    37,   258,   259,
     135,   136,   120,    57,    38,   128,   206,    33,   207,   312,
     313,    34,    31,    32,    56,    35,    36,    37,   129,   311,
     312,   313,   131,   132,    38,   145,   147,    33,   151,   152,
     153,    34,   208,   209,   156,    35,    36,    37,    31,    32,
     405,   154,    87,   155,    38,   157,   161,   471,    40,   164,
      31,    32,   220,    33,   319,   320,   321,    34,   221,   222,
     405,    35,    36,    37,   162,    33,   165,   505,    40,    34,
      38,    31,    32,    35,    36,    37,   166,   224,   167,   225,
     405,   299,    38,   168,    87,   176,    33,   506,    40,   177,
      34,   -60,   196,   202,    35,    36,    37,   203,   242,   235,
     243,   244,   245,    38,   248,   225,   405,    88,    89,    90,
     251,   252,   254,   522,    40,   262,    91,   310,   405,    87,
     311,   312,   313,   263,   264,   531,    40,    92,    93,    94,
      95,    96,    97,    98,    99,   278,   100,   333,   283,   284,
     101,   285,    88,    89,    90,   286,   287,    40,   288,   289,
     290,    91,   459,    87,   318,   319,   320,   321,   292,   460,
     309,   322,    92,    93,    94,    95,    96,    97,    98,    99,
     326,   100,   334,   335,   346,   101,    88,    89,    90,   339,
     190,   340,   343,   350,   345,    91,   310,   459,    87,   311,
     312,   313,   344,   347,   486,   363,    92,    93,    94,    95,
      96,    97,    98,    99,   299,   100,  -141,  -139,  -138,   101,
    -140,    88,    89,    90,   364,   366,   380,   381,   382,   390,
      91,   459,    87,   396,   319,   320,   321,   387,   498,   401,
     392,    92,    93,    94,    95,    96,    97,    98,    99,   421,
     100,   313,   422,   423,   101,    88,    89,    90,   424,   428,
     429,   437,   439,   438,    91,    74,   459,    87,   453,   454,
     441,   455,   463,   518,   456,    92,    93,    94,    95,    96,
      97,    98,    99,   466,   100,   480,   468,   473,   101,   474,
      88,    89,    90,   479,   482,   159,   487,   493,   497,    91,
     459,    87,   499,   500,   502,   509,   513,   519,   510,   515,
      92,    93,    94,    95,    96,    97,    98,    99,   526,   100,
     530,   125,    30,   101,    88,    89,    90,    28,   389,   395,
     169,   469,   440,    91,   150,   459,    87,   239,   418,   331,
       0,   204,   527,     0,    92,    93,    94,    95,    96,    97,
      98,    99,   160,   100,     0,     0,     0,   101,     0,    88,
      89,    90,     0,     0,     0,     0,     0,     0,    91,   459,
       0,     0,     0,     0,     0,     0,   533,     0,     0,    92,
      93,    94,    95,    96,    97,    98,    99,     0,   100,     0,
     310,     0,   101,   311,   312,   313,   210,   211,   212,   213,
     214,   215,   216,   217,   102,   310,     0,     0,   311,   312,
     313,     0,     0,     0,   310,     0,     0,   311,   312,   313,
       0,     0,   314,   315,   316,   317,     0,   318,   319,   320,
     321,     0,     0,     0,     0,   329,     0,   314,   315,   316,
     317,   365,   318,   319,   320,   321,   314,   315,   316,   317,
       0,   318,   319,   320,   321,   310,   386,     0,   311,   312,
     313,     0,     0,     0,   310,   411,     0,   311,   312,   313,
      92,    93,    94,    95,    96,    97,    98,    99,     0,   310,
       0,     0,   311,   312,   313,     0,     0,   314,   315,   316,
     317,     0,   318,   319,   320,   321,   314,   315,   316,   317,
       0,   318,   319,   320,   321,   310,   412,     0,   311,   312,
     313,   314,   315,   316,   317,   413,   318,   319,   320,   321,
     310,     0,     0,   311,   312,   313,     0,     0,     0,   310,
     415,     0,   311,   312,   313,     0,     0,   314,   315,   316,
     317,     0,   318,   319,   320,   321,   187,     0,     0,   188,
     189,   190,   314,   315,   316,   317,   476,   318,   319,   320,
     321,   314,   315,   316,   317,     0,   318,   319,   320,   321,
     310,   477,     0,   311,   312,   313,     0,     0,   187,     0,
     478,   188,   189,   190,   191,   192,   193,   187,     0,     0,
     188,   189,   190,     0,     0,   187,     0,   265,   188,   189,
     190,     0,   314,   315,   316,   317,     0,   318,   319,   320,
     321,     0,     0,     0,     0,     0,   191,   192,   193,   310,
       0,   528,   311,   312,   313,   191,   192,   193,     0,   280,
       0,     0,     0,   191,   192,   193,   310,     0,   325,   311,
     312,   313,     0,     0,     0,   310,   523,     0,   311,   312,
     313,   314,   315,   316,   317,     0,   318,   319,   320,   321,
       0,     0,   310,     0,   408,   311,   312,   313,   314,   315,
     316,   317,     0,   318,   319,   320,   321,   314,   315,   316,
     317,   409,   318,   319,   320,   321,     0,     0,   310,     0,
     410,   311,   312,   313,   314,   315,   316,   317,     0,   318,
     319,   320,   321,     0,     0,   310,     0,   414,   311,   312,
     313,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     314,   315,   316,   317,     0,   318,   319,   320,   321,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   316,
     317,     0,   318,   319,   320,   321
};

static const yytype_int16 yycheck[] =
{
     139,   157,   177,   278,   225,   225,   165,   226,   147,   344,
     347,   329,    71,   343,     3,     4,   155,   392,    78,    20,
       3,     4,     3,     4,     3,     4,     4,    33,     3,    18,
       3,     3,     4,    22,    47,     3,    74,    26,    27,    28,
      71,    15,    80,     0,    13,    18,    35,    60,   187,   188,
     189,   190,   191,   192,   193,    20,    25,    74,    30,    31,
       4,    78,     6,   382,    40,    41,   126,   223,    16,   399,
     226,     4,   292,     6,    74,   350,    76,    74,    84,    85,
     299,    82,    71,    80,    58,    71,   423,   424,   244,    65,
      79,   466,    68,   468,   153,   154,    79,    74,    79,    12,
      79,    79,    78,    80,    79,    71,   441,    79,   426,   428,
      86,    79,    56,    57,    74,    74,    81,    82,    72,    74,
      80,    80,    14,    56,    57,    80,   401,   283,   284,   285,
     286,   287,   288,   289,   290,    79,     9,   456,   198,    10,
      33,    34,   363,   363,    75,   364,    77,   322,    72,    74,
     126,    76,   128,   129,   310,   311,   312,   313,   314,   315,
     316,   317,   318,   319,   320,   321,   142,    33,    34,   145,
     390,   327,   392,    33,    34,   334,    69,    33,    34,    29,
     499,   500,    32,    33,    34,    33,    34,    74,    74,    74,
       7,     3,     4,    80,    80,    80,   416,    72,   473,   474,
     176,   520,    68,    69,    10,    11,    18,    67,    68,    69,
      22,   530,    68,    69,    26,    27,    28,    67,    68,    69,
      72,    69,   198,    35,    71,    74,   202,   203,    74,    74,
      80,    80,   507,    73,    80,    80,     3,     4,    74,     6,
      76,    74,     3,   464,   464,    19,   466,    80,   468,    74,
      74,   526,   408,   409,   410,    80,    80,    33,    34,    71,
      63,    64,    65,    30,    31,     7,    78,    79,   443,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    74,
       7,     3,     4,    50,    82,    80,    32,    33,    34,    56,
      57,    82,     3,     4,    79,     6,    18,    74,    79,    76,
      22,    33,    34,    70,    26,    27,    28,    79,    75,    74,
      77,    76,    79,    35,    61,    62,    63,    64,    65,    30,
      31,    67,    68,    69,    23,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    67,    68,    69,    81,    50,
     182,   183,   184,   185,   186,    56,    57,     4,    74,    71,
      76,    71,     3,     4,     3,     4,    78,    79,    77,    70,
      79,    77,     8,    79,    75,   521,    77,    18,    79,   508,
       8,    22,     3,     4,     3,    26,    27,    28,     3,     4,
       3,     4,    18,    11,    35,    20,     4,    18,     6,    33,
      34,    22,     3,     4,    10,    26,    27,    28,    20,    32,
      33,    34,    21,     3,    35,    20,    79,    18,    73,     3,
      79,    22,    30,    31,    75,    26,    27,    28,     3,     4,
      71,    79,     3,    79,    35,    79,     3,    78,    79,    72,
       3,     4,    50,    18,    67,    68,    69,    22,    56,    57,
      71,    26,    27,    28,    23,    18,    20,    78,    79,    22,
      35,     3,     4,    26,    27,    28,    20,    75,    17,    77,
      71,    79,    35,     3,     3,    20,    18,    78,    79,    79,
      22,    23,    81,    20,    26,    27,    28,    20,    50,    21,
      73,    79,     9,    35,     4,    77,    71,    26,    27,    28,
      73,     3,    20,    78,    79,     3,    35,    29,    71,     3,
      32,    33,    34,    21,    21,    78,    79,    46,    47,    48,
      49,    50,    51,    52,    53,    77,    55,    11,    79,    79,
      59,    79,    26,    27,    28,    79,    79,    79,    79,    79,
      79,    35,    71,     3,    66,    67,    68,    69,    75,    78,
      75,    79,    46,    47,    48,    49,    50,    51,    52,    53,
      76,    55,    74,    74,    79,    59,    26,    27,    28,    74,
      34,    80,    75,    77,    80,    35,    29,    71,     3,    32,
      33,    34,    82,    79,    78,    74,    46,    47,    48,    49,
      50,    51,    52,    53,    79,    55,    74,    74,    74,    59,
      74,    26,    27,    28,    74,     4,    21,    21,    77,    75,
      35,    71,     3,     3,    67,    68,    69,    73,    78,    77,
      79,    46,    47,    48,    49,    50,    51,    52,    53,    76,
      55,    34,    80,    79,    59,    26,    27,    28,    79,    77,
       4,    74,    76,    80,    35,    25,    71,     3,    78,    80,
      82,    75,    72,    78,    77,    46,    47,    48,    49,    50,
      51,    52,    53,    75,    55,     4,    79,    77,    59,    77,
      26,    27,    28,    80,     4,    58,     5,    24,    76,    35,
      71,     3,    77,    77,    73,     4,    24,    78,    80,     4,
      46,    47,    48,    49,    50,    51,    52,    53,    77,    55,
      77,    62,    20,    59,    26,    27,    28,    19,   335,   339,
     121,   437,   399,    35,    86,    71,     3,   156,   361,   243,
      -1,   150,    78,    -1,    46,    47,    48,    49,    50,    51,
      52,    53,   103,    55,    -1,    -1,    -1,    59,    -1,    26,
      27,    28,    -1,    -1,    -1,    -1,    -1,    -1,    35,    71,
      -1,    -1,    -1,    -1,    -1,    -1,    78,    -1,    -1,    46,
      47,    48,    49,    50,    51,    52,    53,    -1,    55,    -1,
      29,    -1,    59,    32,    33,    34,    36,    37,    38,    39,
      40,    41,    42,    43,    71,    29,    -1,    -1,    32,    33,
      34,    -1,    -1,    -1,    29,    -1,    -1,    32,    33,    34,
      -1,    -1,    61,    62,    63,    64,    -1,    66,    67,    68,
      69,    -1,    -1,    -1,    -1,    75,    -1,    61,    62,    63,
      64,    80,    66,    67,    68,    69,    61,    62,    63,    64,
      -1,    66,    67,    68,    69,    29,    80,    -1,    32,    33,
      34,    -1,    -1,    -1,    29,    80,    -1,    32,    33,    34,
      46,    47,    48,    49,    50,    51,    52,    53,    -1,    29,
      -1,    -1,    32,    33,    34,    -1,    -1,    61,    62,    63,
      64,    -1,    66,    67,    68,    69,    61,    62,    63,    64,
      -1,    66,    67,    68,    69,    29,    80,    -1,    32,    33,
      34,    61,    62,    63,    64,    80,    66,    67,    68,    69,
      29,    -1,    -1,    32,    33,    34,    -1,    -1,    -1,    29,
      80,    -1,    32,    33,    34,    -1,    -1,    61,    62,    63,
      64,    -1,    66,    67,    68,    69,    29,    -1,    -1,    32,
      33,    34,    61,    62,    63,    64,    80,    66,    67,    68,
      69,    61,    62,    63,    64,    -1,    66,    67,    68,    69,
      29,    80,    -1,    32,    33,    34,    -1,    -1,    29,    -1,
      80,    32,    33,    34,    67,    68,    69,    29,    -1,    -1,
      32,    33,    34,    -1,    -1,    29,    -1,    80,    32,    33,
      34,    -1,    61,    62,    63,    64,    -1,    66,    67,    68,
      69,    -1,    -1,    -1,    -1,    -1,    67,    68,    69,    29,
      -1,    80,    32,    33,    34,    67,    68,    69,    -1,    80,
      -1,    -1,    -1,    67,    68,    69,    29,    -1,    80,    32,
      33,    34,    -1,    -1,    -1,    29,    80,    -1,    32,    33,
      34,    61,    62,    63,    64,    -1,    66,    67,    68,    69,
      -1,    -1,    29,    -1,    74,    32,    33,    34,    61,    62,
      63,    64,    -1,    66,    67,    68,    69,    61,    62,    63,
      64,    74,    66,    67,    68,    69,    -1,    -1,    29,    -1,
      74,    32,    33,    34,    61,    62,    63,    64,    -1,    66,
      67,    68,    69,    -1,    -1,    29,    -1,    74,    32,    33,
      34,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      61,    62,    63,    64,    -1,    66,    67,    68,    69,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,
      64,    -1,    66,    67,    68,    69
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    71,    84,    85,    16,     0,    71,    87,    86,    12,
      71,    89,    72,    91,    88,    14,     9,    72,    92,    93,
      94,   117,    90,    10,     7,   107,   108,    72,    94,    72,
      93,     3,     4,    18,    22,    26,    27,    28,    35,    71,
      79,   116,   118,   119,   120,   121,   122,   126,   129,   130,
     140,   141,   142,   143,   176,    73,    10,    11,    98,    99,
      19,   109,   110,     7,     7,    82,   127,   127,    82,     3,
      79,    79,    79,    13,    25,     3,   121,   125,    79,   121,
     123,    23,   131,    81,     3,    18,   116,     3,    26,    27,
      28,    35,    46,    47,    48,    49,    50,    51,    52,    53,
      55,    59,    71,   145,   146,   162,   163,   164,   166,   167,
     168,   172,   173,   174,   175,   177,     4,     8,     8,    71,
      18,   100,   101,     3,   116,   109,    79,   121,    20,    20,
     121,    21,     3,   139,   139,     3,     4,    30,    31,    79,
     134,   135,    74,    80,   125,    20,   124,    79,   127,   127,
     123,    73,     3,    79,    79,    79,    75,    79,    15,    58,
     162,     3,    23,   169,    72,    20,    20,    17,     3,   101,
       3,    79,   111,   125,   121,   121,    20,    79,    74,    80,
      80,   135,    61,    62,    63,    64,    65,    29,    32,    33,
      34,    67,    68,    69,    80,   121,    81,    80,    79,   121,
     128,   135,    20,    20,   124,     3,     4,     6,    30,    31,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      50,    56,    57,    70,    75,    77,    79,   144,   147,   149,
     150,   154,   156,   159,   161,    21,   139,   139,   135,   145,
     161,   165,    50,    73,    79,     9,    95,   154,     4,    96,
      97,    73,     3,   112,    20,   113,    80,   121,     3,     4,
     136,   137,     3,    21,    21,    80,   134,   134,   134,   134,
     134,   135,   135,   135,   135,   135,   135,   135,    77,   125,
      80,   121,   121,    79,    79,    79,    79,    79,    79,    79,
      79,   161,    75,   151,   152,     4,     6,    56,    57,    79,
     148,   149,   155,     4,     6,    56,    57,   148,   161,    75,
      29,    32,    33,    34,    61,    62,    63,    64,    66,    67,
      68,    69,    79,    80,    80,    80,    76,    74,    80,    75,
     157,   159,   161,    11,    74,    74,    75,    77,   103,    74,
      80,     3,    79,    75,    82,    80,    79,    79,   117,    80,
      77,   161,   161,   161,   161,   161,   161,   161,   161,   149,
     153,    74,    76,    74,    74,    80,     4,   161,   161,   161,
     161,   161,   161,   161,   161,   161,   161,   161,   161,   137,
      21,    21,    77,   161,   156,   158,    80,    73,   154,    97,
      75,   104,    79,   105,   102,   112,     3,   114,   115,   119,
     136,    77,   137,   138,   138,    71,    78,   117,    74,    74,
      74,    80,    80,    80,    74,    80,    74,    76,   152,   155,
     148,    76,    80,    79,    79,   176,    74,    76,    77,     4,
     106,   155,    74,    76,   106,    74,    78,    74,    80,    76,
     115,    82,   117,    74,    80,    80,    78,   161,   161,   161,
       4,    79,   149,    78,    80,    75,    77,   138,   138,    71,
      78,   156,   176,    72,    74,    76,    75,    80,    79,   114,
     136,    78,   137,    77,    77,   132,    80,    80,    80,    80,
       4,   160,     4,   176,    80,    80,    78,     5,   155,   106,
     106,   117,   117,    24,   133,    74,    80,    76,    78,    77,
      77,   170,    73,    76,    80,    78,    78,    77,    79,     4,
      80,   176,   176,    24,   171,     4,   117,   135,    78,    78,
      77,    79,    78,    80,   176,   161,    77,    78,    80,   117,
      77,    78,   176,    78
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    83,    84,    86,    85,    88,    87,    90,    89,    91,
      92,    92,    92,    92,    92,    93,    94,    95,    95,    96,
      96,    97,    99,    98,    98,   100,   100,   102,   101,   103,
     103,   104,   104,   105,   105,   106,   106,   108,   107,   109,
     109,   110,   111,   111,   112,   112,   113,   113,   113,   114,
     114,   115,   115,   116,   117,   117,   118,   118,   119,   119,
     120,   119,   119,   119,   119,   119,   121,   121,   122,   122,
     122,   122,   122,   122,   123,   123,   124,   124,   125,   125,
     126,   126,   127,   127,   127,   128,   128,   129,   130,   131,
     132,   132,   133,   133,   134,   134,   134,   134,   134,   134,
     134,   135,   135,   135,   135,   135,   135,   135,   135,   135,
     135,   135,   136,   136,   137,   137,   138,   138,   139,   139,
     140,   141,   142,   143,   144,   144,   144,   145,   145,   145,
     145,   145,   145,   145,   145,   146,   147,   147,   148,   148,
     148,   148,   149,   150,   151,   151,   152,   153,   153,   154,
     155,   155,   156,   156,   156,   156,   156,   156,   156,   156,
     156,   157,   158,   158,   159,   159,   159,   159,   159,   159,
     159,   159,   159,   160,   160,   161,   161,   161,   161,   161,
     161,   161,   161,   161,   161,   161,   161,   161,   161,   161,
     161,   161,   161,   161,   162,   163,   163,   163,   164,   165,
     165,   166,   168,   167,   167,   167,   167,   167,   169,   170,
     170,   171,   171,   172,   173,   174,   175,   176,   176,   177,
     177,   177,   177,   177
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     3,     0,     9,     0,     6,     0,     6,    14,
       2,     2,     1,     1,     0,     6,     6,     3,     1,     3,
       1,     1,     0,     2,     0,     2,     1,     0,     5,     3,
       3,     5,     3,     5,     3,     3,     1,     0,     2,     2,
       0,     7,     1,     3,     3,     1,     0,     2,     4,     3,
       1,     0,     2,     1,     2,     0,     1,     1,     1,     1,
       0,     2,     1,     1,     1,     1,     1,     1,     5,     5,
       4,     4,     4,     3,     1,     3,     0,     2,     3,     1,
       2,     4,     0,     2,     4,     1,     3,     5,     2,     9,
       8,     0,     4,     0,     3,     3,     3,     3,     3,     1,
       1,     3,     3,     3,     3,     3,     3,     3,     3,     1,
       1,     1,     1,     1,     3,     5,     3,     1,     3,     1,
       9,    11,    11,     7,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     4,     1,     1,     1,     1,
       1,     1,     5,     3,     3,     1,     3,     3,     1,     5,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     3,     1,     6,     6,     6,     4,     4,     6,
       8,     4,     4,     3,     1,     1,     1,     4,     7,     1,
       3,     2,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     2,     4,     4,     4,     3,
       1,     3,     0,     2,     1,     1,     1,     1,     9,     8,
       0,     4,     0,     9,    11,    11,     7,     2,     0,     1,
       1,     1,     1,     1
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
#line 53 "./Parser/parser_main.y"
                                                                   {fprintf(fp,"\nParsing successful!\n");printBlockTable();printGateTable(&GateSymbolTable);}
#line 1743 "./exec/y.tab.c"
    break;

  case 3: /* $@1: %empty  */
#line 57 "./Parser/parser_main.y"
                                           {fprintf(fp,"\nInit section begins\n\n");}
#line 1749 "./exec/y.tab.c"
    break;

  case 4: /* init_section: '\\' INIT_BEGIN $@1 mandatory_init set_states block_defn_section gate_defn_section '\\' INIT_END  */
#line 57 "./Parser/parser_main.y"
                                                                                                                                                                   {fprintf(fp,"\nInit section ends\n");}
#line 1755 "./exec/y.tab.c"
    break;

  case 5: /* $@2: %empty  */
#line 60 "./Parser/parser_main.y"
                                            {fprintf(fp,"\nMain section begins\n\n");}
#line 1761 "./exec/y.tab.c"
    break;

  case 6: /* main_section: '\\' MAIN_BEGIN $@2 main_stmt_list '\\' MAIN_END  */
#line 60 "./Parser/parser_main.y"
                                                                                                                    {fprintf(fp,"\nMain section ends\n");}
#line 1767 "./exec/y.tab.c"
    break;

  case 7: /* $@3: %empty  */
#line 63 "./Parser/parser_main.y"
                                             {fprintf(fp,"\nOutput section begins\n\n");}
#line 1773 "./exec/y.tab.c"
    break;

  case 8: /* output_section: '\\' OUTPUT_BEGIN $@3 out_main '\\' OUTPUT_END  */
#line 63 "./Parser/parser_main.y"
                                                                                                                   {fprintf(fp,"\nOutput section ends\n");}
#line 1779 "./exec/y.tab.c"
    break;

  case 9: /* mandatory_init: '#' REGISTERS QUANTUM '=' NUMBER '#' REGISTERS CLASSICAL '=' NUMBER '#' ITERS '=' NUMBER  */
#line 71 "./Parser/parser_main.y"
                                                                                                                    {  fprintf(fp,"Register and iteration initialization section\n");classical_registers = yyvsp[-4].num;quantum_registers = yyvsp[-9].num;iterations = yyvsp[0].num;}
#line 1785 "./exec/y.tab.c"
    break;

  case 15: /* set_quantum_states: '#' SET QUANTUM STATES ARROW quantum_state_list  */
#line 82 "./Parser/parser_main.y"
                                                                            {fprintf(fp,"Setting initial state of quantum registers\n");}
#line 1791 "./exec/y.tab.c"
    break;

  case 16: /* set_classical_states: '#' SET CLASSICAL STATES ARROW classical_state_list  */
#line 85 "./Parser/parser_main.y"
                                                                                {fprintf(fp,"Setting initial state of classical registers\n");}
#line 1797 "./exec/y.tab.c"
    break;

  case 17: /* quantum_state_list: quantum_state_list ',' state_const  */
#line 88 "./Parser/parser_main.y"
                                                                     {if(quantum_index == quantum_registers){yyerror();return;}quantum_states[quantum_index++] = yyvsp[0].q;}
#line 1803 "./exec/y.tab.c"
    break;

  case 18: /* quantum_state_list: state_const  */
#line 89 "./Parser/parser_main.y"
                                          {quantum_states = (struct Quantum*)malloc(sizeof(struct Quantum)*quantum_registers);quantum_states[quantum_index++] = yyvsp[0].q;}
#line 1809 "./exec/y.tab.c"
    break;

  case 19: /* classical_state_list: classical_state_list ',' classical_state  */
#line 92 "./Parser/parser_main.y"
                                                                      {if(classical_index == classical_registers){yyerror();return;}classical_states[classical_index++] = yyvsp[0].num;}
#line 1815 "./exec/y.tab.c"
    break;

  case 20: /* classical_state_list: classical_state  */
#line 93 "./Parser/parser_main.y"
                                            {classical_states = (int *)malloc(sizeof(int)*classical_registers);classical_states[classical_index++] = yyvsp[0].num;}
#line 1821 "./exec/y.tab.c"
    break;

  case 21: /* classical_state: NUMBER  */
#line 96 "./Parser/parser_main.y"
                                    {yyval.num = yyvsp[0].num;}
#line 1827 "./exec/y.tab.c"
    break;

  case 22: /* $@4: %empty  */
#line 100 "./Parser/parser_main.y"
                           {fprintf(fp,"Gate definition section begins\n");}
#line 1833 "./exec/y.tab.c"
    break;

  case 23: /* gate_defn_section: $@4 gate_defn_list  */
#line 100 "./Parser/parser_main.y"
                                                                                            {fprintf(fp,"Gate definition section ends\n");}
#line 1839 "./exec/y.tab.c"
    break;

  case 27: /* $@5: %empty  */
#line 108 "./Parser/parser_main.y"
                                            {fprintf(fp,"Gate definition\n");}
#line 1845 "./exec/y.tab.c"
    break;

  case 28: /* gate_defn: GATE ID '=' rhs $@5  */
#line 108 "./Parser/parser_main.y"
                                                                                 {insertInGateTable(&GateSymbolTable,yyvsp[-3].str,yyvsp[-1].rows,yyvsp[-1].cols);}
#line 1851 "./exec/y.tab.c"
    break;

  case 29: /* rhs: '[' tuple_list ']'  */
#line 111 "./Parser/parser_main.y"
                                                {yyval.rows = yyvsp[-1].rows;yyval.cols = yyvsp[-1].cols;}
#line 1857 "./exec/y.tab.c"
    break;

  case 31: /* tuple_list: tuple_list ',' '[' id_list ']'  */
#line 114 "./Parser/parser_main.y"
                                                         {if(yyvsp[-4].cols != yyvsp[-1].cols){yyerror();return;}int temp; temp = yyvsp[-4].rows + 1;yyval.rows = temp;yyval.cols = yyvsp[-4].cols;}
#line 1863 "./exec/y.tab.c"
    break;

  case 32: /* tuple_list: '[' id_list ']'  */
#line 115 "./Parser/parser_main.y"
                                                         {yyval.rows = 1;yyval.cols = yyvsp[-1].cols;}
#line 1869 "./exec/y.tab.c"
    break;

  case 35: /* id_list: id_list ',' temp  */
#line 120 "./Parser/parser_main.y"
                                             {yyval.cols += 1;}
#line 1875 "./exec/y.tab.c"
    break;

  case 36: /* id_list: temp  */
#line 121 "./Parser/parser_main.y"
                                             {yyval.cols = 1;}
#line 1881 "./exec/y.tab.c"
    break;

  case 37: /* $@6: %empty  */
#line 124 "./Parser/parser_main.y"
                           {fprintf(fp,"Block definition section begins\n");}
#line 1887 "./exec/y.tab.c"
    break;

  case 38: /* block_defn_section: $@6 block_defns_list  */
#line 124 "./Parser/parser_main.y"
                                                                                               {fprintf(fp,"Block definition section ends\n");}
#line 1893 "./exec/y.tab.c"
    break;

  case 41: /* block_defn: BLOCK block_id params target_params '[' block_body ']'  */
#line 131 "./Parser/parser_main.y"
                                                                                 {fprintf(fp,"Block definition\n");insertInBlockTable(&BlockSymbolTable,yyvsp[-5].str,head,head2);head = NULL;head2=NULL;}
#line 1899 "./exec/y.tab.c"
    break;

  case 42: /* params: ID  */
#line 134 "./Parser/parser_main.y"
                                                {insertInList(&head,yyvsp[0].str);}
#line 1905 "./exec/y.tab.c"
    break;

  case 44: /* param_id_list: ID ',' param_id_list  */
#line 138 "./Parser/parser_main.y"
                                                {insertInList(&head,yyvsp[-2].str);}
#line 1911 "./exec/y.tab.c"
    break;

  case 45: /* param_id_list: ID  */
#line 139 "./Parser/parser_main.y"
                                                {insertInList(&head,yyvsp[0].str);}
#line 1917 "./exec/y.tab.c"
    break;

  case 47: /* target_params: ARROW ID  */
#line 143 "./Parser/parser_main.y"
                                                 {insertInList(&head2,yyvsp[0].str);}
#line 1923 "./exec/y.tab.c"
    break;

  case 49: /* target_param_list: ID ',' target_param_list  */
#line 147 "./Parser/parser_main.y"
                                                      {insertInList(&head2,yyvsp[-2].str);}
#line 1929 "./exec/y.tab.c"
    break;

  case 50: /* target_param_list: ID  */
#line 148 "./Parser/parser_main.y"
                                                      {insertInList(&head2,yyvsp[0].str);}
#line 1935 "./exec/y.tab.c"
    break;

  case 53: /* block_id: ID  */
#line 155 "./Parser/parser_main.y"
                                  {yyval = yyvsp[0];}
#line 1941 "./exec/y.tab.c"
    break;

  case 57: /* main_stmt: barrier_stmt  */
#line 168 "./Parser/parser_main.y"
                                          {fprintf(fp,"barrier statement\n");}
#line 1947 "./exec/y.tab.c"
    break;

  case 59: /* stmts: measure_stmt  */
#line 171 "./Parser/parser_main.y"
                                          {fprintf(fp,"Measure statement\n");}
#line 1953 "./exec/y.tab.c"
    break;

  case 60: /* $@7: %empty  */
#line 172 "./Parser/parser_main.y"
                          {fprintf(fp,"Conditional statement begin\n");}
#line 1959 "./exec/y.tab.c"
    break;

  case 61: /* stmts: $@7 condition_stmt  */
#line 172 "./Parser/parser_main.y"
                                                                                        {fprintf(fp,"Conditional statement end\n");}
#line 1965 "./exec/y.tab.c"
    break;

  case 62: /* stmts: for_stmt  */
#line 173 "./Parser/parser_main.y"
                                          {fprintf(fp,"For statement\n");}
#line 1971 "./exec/y.tab.c"
    break;

  case 63: /* stmts: for_lex_stmt  */
#line 174 "./Parser/parser_main.y"
                                          {fprintf(fp,"For - Lex statement\n");}
#line 1977 "./exec/y.tab.c"
    break;

  case 64: /* stmts: for_zip_stmt  */
#line 175 "./Parser/parser_main.y"
                                          {fprintf(fp,"For - Zip statement\n");}
#line 1983 "./exec/y.tab.c"
    break;

  case 65: /* stmts: while_stmt  */
#line 176 "./Parser/parser_main.y"
                                          {fprintf(fp,"while statement\n");}
#line 1989 "./exec/y.tab.c"
    break;

  case 68: /* call_stmt: classic_control GATE quantum_control ARROW register  */
#line 185 "./Parser/parser_main.y"
                                                                              {fprintf(fp,"Pre - defined Gate call statement\n");}
#line 1995 "./exec/y.tab.c"
    break;

  case 69: /* call_stmt: classic_control ID quantum_control ARROW register  */
#line 186 "./Parser/parser_main.y"
                                                                              {fprintf(fp,"user - defined Gate call statement\n");}
#line 2001 "./exec/y.tab.c"
    break;

  case 70: /* call_stmt: GATE quantum_control ARROW register  */
#line 187 "./Parser/parser_main.y"
                                                                              {fprintf(fp,"Pre - defined Gate call statement\n");}
#line 2007 "./exec/y.tab.c"
    break;

  case 71: /* call_stmt: ID quantum_control ARROW register  */
#line 188 "./Parser/parser_main.y"
                                                                              {fprintf(fp,"User - defined Gate call statement\n");}
#line 2013 "./exec/y.tab.c"
    break;

  case 72: /* call_stmt: classic_control block_id parameters optional  */
#line 189 "./Parser/parser_main.y"
                                                                              {fprintf(fp,"Block call statement\n");}
#line 2019 "./exec/y.tab.c"
    break;

  case 73: /* call_stmt: block_id parameters optional  */
#line 190 "./Parser/parser_main.y"
                                                                              {fprintf(fp,"Block call statement\n");}
#line 2025 "./exec/y.tab.c"
    break;

  case 138: /* num: DEC  */
#line 326 "./Parser/parser_main.y"
                                    {yyval.real = yyvsp[0].real;}
#line 2031 "./exec/y.tab.c"
    break;

  case 139: /* num: NEG  */
#line 327 "./Parser/parser_main.y"
                                    {yyval.real = yyvsp[0].real;}
#line 2037 "./exec/y.tab.c"
    break;

  case 140: /* num: EXP  */
#line 328 "./Parser/parser_main.y"
                                    {yyval.real = yyvsp[0].real;}
#line 2043 "./exec/y.tab.c"
    break;

  case 141: /* num: NUMBER  */
#line 329 "./Parser/parser_main.y"
                                    {yyval.real = yyvsp[0].num;}
#line 2049 "./exec/y.tab.c"
    break;

  case 142: /* complex_const: '(' num ',' num ')'  */
#line 331 "./Parser/parser_main.y"
                                                   {yyval.cpx.real = yyvsp[-3].real; yyval.cpx.imag = yyvsp[-1].real;}
#line 2055 "./exec/y.tab.c"
    break;

  case 149: /* state_const: '{' temp ',' temp '}'  */
#line 348 "./Parser/parser_main.y"
                                                   {yyval.q.first = yyvsp[-3].cpx; yyval.q.second = yyvsp[-1].cpx;}
#line 2061 "./exec/y.tab.c"
    break;

  case 150: /* temp: complex_const  */
#line 351 "./Parser/parser_main.y"
                                          {yyval.cpx = yyvsp[0].cpx;}
#line 2067 "./exec/y.tab.c"
    break;

  case 151: /* temp: num  */
#line 352 "./Parser/parser_main.y"
                                          {yyval.cpx.real = yyvsp[0].real; yyval.cpx.imag = 0;}
#line 2073 "./exec/y.tab.c"
    break;

  case 194: /* out_expr: ID '=' out_rhs  */
#line 413 "./Parser/parser_main.y"
                                                      {fprintf(fp,"expression statement\n");}
#line 2079 "./exec/y.tab.c"
    break;

  case 195: /* decl: prim_type out_expr  */
#line 416 "./Parser/parser_main.y"
                                                      {fprintf(fp,"Primitive datatype declaration statement\n");}
#line 2085 "./exec/y.tab.c"
    break;

  case 196: /* decl: list_type ID '=' vec_const  */
#line 417 "./Parser/parser_main.y"
                                                      {fprintf(fp,"List datatype declaration statement\n");}
#line 2091 "./exec/y.tab.c"
    break;

  case 197: /* decl: list_type ID '=' calls  */
#line 418 "./Parser/parser_main.y"
                                                      {fprintf(fp,"List datatype declaration statement\n");}
#line 2097 "./exec/y.tab.c"
    break;

  case 198: /* echo_stmt: ECHO '(' echo_list ')'  */
#line 422 "./Parser/parser_main.y"
                                                      {fprintf(fp,"Echo statement\n");}
#line 2103 "./exec/y.tab.c"
    break;

  case 201: /* save_stmt: '\\' SAVE STRING  */
#line 430 "./Parser/parser_main.y"
                                                      {fprintf(fp,"Save statement\n");}
#line 2109 "./exec/y.tab.c"
    break;

  case 202: /* $@8: %empty  */
#line 434 "./Parser/parser_main.y"
                          {fprintf(fp,"Output section conditional statement begins\n");}
#line 2115 "./exec/y.tab.c"
    break;

  case 203: /* out_control: $@8 out_cond_stmt  */
#line 434 "./Parser/parser_main.y"
                                                                                                       {fprintf(fp,"Output section conditional statement ends\n");}
#line 2121 "./exec/y.tab.c"
    break;

  case 204: /* out_control: out_for_stmt  */
#line 435 "./Parser/parser_main.y"
                                                      {fprintf(fp,"For statement in output section\n");}
#line 2127 "./exec/y.tab.c"
    break;

  case 205: /* out_control: out_for_lex_stmt  */
#line 436 "./Parser/parser_main.y"
                                                      {fprintf(fp,"For - lex statement in output section\n");}
#line 2133 "./exec/y.tab.c"
    break;

  case 206: /* out_control: out_for_zip_stmt  */
#line 437 "./Parser/parser_main.y"
                                                      {fprintf(fp,"For - zip statement in output section\n");}
#line 2139 "./exec/y.tab.c"
    break;

  case 207: /* out_control: out_while_stmt  */
#line 438 "./Parser/parser_main.y"
                                                      {fprintf(fp,"while statement in output section\n");}
#line 2145 "./exec/y.tab.c"
    break;


#line 2149 "./exec/y.tab.c"

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

#line 476 "./Parser/parser_main.y"


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

void printList(struct List** head){
   struct List* temp = *head;
   while(temp!=NULL){
      printf("%s ",temp->id);
      temp = temp->next;
   }
   printf("\n");
}

void insertInBlockTable(struct BlockTable** Head,char * data,struct List* params,struct List* target_params){
   struct BlockTable* temp = *Head;
   while(temp != NULL){
      if(strcmp(temp->id,data) == 0){
         printf("Block already defined\n");
         return;
      }
      temp = temp->next;
   }
   struct BlockTable* newNode = (struct BlockTable*)malloc(sizeof(struct BlockTable));
   newNode->id = (char *)malloc(sizeof(char)*strlen(data));
   for(int i=0;i<strlen(data);i++){
      newNode->id[i] = data[i];
   }
   newNode->params = params;
   newNode->target_params = target_params;
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
   int x=1;
   while(temp != NULL){
      printf("%d. \n",x++);
      printf("%s \n",temp->id);
      printList(&(temp->params));
      printList(&(temp->target_params));
      temp = temp->next;
   }
}

void insertInGateTable(struct GateTable ** Head,char * data,int rows,int cols){
   struct GateTable* temp = *Head;
   while(temp != NULL){
      if(strcmp(temp->id,data) == 0){
         printf("Block already defined\n");
         return;
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
}

void printGateTable(struct GateTable ** GateSymbolTable){
   struct GateTable* temp = *GateSymbolTable;
   while(temp != NULL){
      printf("%s ",temp->id);
      printf("%d %d\n",temp->rows,temp->cols);
      temp = temp->next;
   }
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
   fprintf(fp,"Syntax error at line %d\n",line);
}
