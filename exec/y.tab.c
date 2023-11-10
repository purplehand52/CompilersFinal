/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     ID = 258,
     NUMBER = 259,
     ITERS = 260,
     NEG = 261,
     SET = 262,
     STATES = 263,
     REGISTERS = 264,
     QUANTUM = 265,
     CLASSICAL = 266,
     MAIN_BEGIN = 267,
     MAIN_END = 268,
     OUTPUT_BEGIN = 269,
     OUTPUT_END = 270,
     INIT_BEGIN = 271,
     INIT_END = 272,
     GATE = 273,
     BLOCK = 274,
     ARROW = 275,
     IN = 276,
     MEASURE = 277,
     CONDITION = 278,
     OTHERWISE = 279,
     BARRIER = 280,
     FOR = 281,
     FOR_LEX = 282,
     FOR_ZIP = 283,
     COMP = 284,
     TRUE = 285,
     FALSE = 286,
     EQUALITY = 287,
     AND = 288,
     OR = 289,
     WHILE = 290,
     ADD = 291,
     SUB = 292,
     DOT = 293,
     STD_DEV = 294,
     VAR = 295,
     AVG = 296,
     CONDENSE = 297,
     SUM = 298,
     COUT = 299,
     QOUT = 300,
     INT = 301,
     UINT = 302,
     FLOAT = 303,
     COMPLEX = 304,
     STRING = 305,
     MATRIX = 306,
     STATE = 307,
     BOOL = 308,
     IMAG = 309,
     LIST = 310,
     DEC = 311,
     EXP = 312,
     SAVE = 313,
     ECHO = 314,
     RETURN = 315
   };
#endif
/* Tokens.  */
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




/* Copy the first part of user declarations.  */
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
   void insertInGateTable(struct GateTable ** Head,char * data,int rows,int cols);
   void insertInBlockTable(struct BlockTable** Head,char * data,int len,struct List* params);
   void insertInOutputTable(struct OutputSymbolEntry** Head, char* id, int level, int type, bool primitive, int matrix_dim, int dim, bool isLoopId);
   int BlockCallSemanticCheck(char *block_id,int num_params);
   int BlockSemanticCheck(char *block_id);
   void insertInList(struct List** Head,char * data);
   bool inList(struct List** Head, char* data);
   void removeTopKFromList(struct List** Head, int k);
   int compatibleCheck(int t1, int t2);
   int compatibleCheckAdv(int t1, int t2, int p1, int p2, int d1, int d2);
   int condenser(int size, int lim);


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 274 "./exec/y.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

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
/* YYNRULES -- Number of states.  */
#define YYNSTATES  552

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   315

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
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
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     7,     8,    18,    19,    26,    27,    34,
      49,    52,    55,    57,    59,    60,    67,    74,    78,    80,
      84,    86,    88,    89,    92,    93,    96,    98,    99,   105,
     109,   113,   119,   123,   129,   133,   137,   139,   140,   143,
     146,   147,   148,   157,   159,   163,   167,   169,   170,   175,
     178,   182,   184,   185,   188,   190,   193,   194,   196,   198,
     200,   202,   203,   206,   208,   210,   212,   214,   216,   218,
     224,   230,   235,   240,   245,   249,   251,   255,   256,   259,
     263,   265,   268,   273,   274,   277,   282,   284,   288,   294,
     297,   307,   316,   317,   322,   323,   327,   331,   335,   339,
     343,   345,   347,   351,   355,   359,   363,   367,   371,   375,
     379,   381,   383,   385,   387,   389,   393,   399,   403,   405,
     409,   411,   412,   423,   424,   437,   438,   451,   459,   461,
     463,   465,   467,   469,   471,   473,   475,   477,   479,   481,
     486,   488,   490,   492,   494,   496,   498,   504,   508,   512,
     514,   518,   522,   524,   526,   528,   534,   536,   538,   540,
     542,   544,   546,   548,   550,   552,   554,   556,   560,   564,
     566,   573,   580,   587,   592,   597,   604,   613,   618,   623,
     627,   629,   631,   633,   635,   640,   648,   659,   661,   665,
     668,   672,   676,   680,   684,   688,   692,   696,   700,   704,
     708,   712,   716,   720,   723,   726,   731,   735,   737,   741,
     742,   745,   747,   749,   751,   753,   754,   765,   774,   775,
     780,   781,   782,   783,   795,   796,   797,   811,   812,   813,
     827,   828,   837,   840,   841,   843,   845,   847,   848,   851,
     852
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
      84,     0,    -1,    85,    87,    89,    -1,    -1,    71,    16,
      86,    91,    92,   107,    98,    71,    17,    -1,    -1,    71,
      12,    88,   118,    71,    13,    -1,    -1,    71,    14,    90,
     189,    71,    15,    -1,    72,     9,    10,    73,     4,    72,
       9,    11,    73,     4,    72,     5,    73,     4,    -1,    93,
      94,    -1,    94,    93,    -1,    93,    -1,    94,    -1,    -1,
      72,     7,    10,     8,    20,    95,    -1,    72,     7,    11,
       8,    20,    96,    -1,    95,    74,   159,    -1,   159,    -1,
      96,    74,    97,    -1,    97,    -1,     4,    -1,    -1,    99,
     100,    -1,    -1,   100,   101,    -1,   101,    -1,    -1,    18,
       3,    73,   103,   102,    -1,    75,   104,    76,    -1,    77,
     105,    78,    -1,   104,    74,    75,   106,    76,    -1,    75,
     106,    76,    -1,   105,    74,    79,   106,    80,    -1,    79,
     106,    80,    -1,   106,    74,   160,    -1,   160,    -1,    -1,
     108,   109,    -1,   110,   109,    -1,    -1,    -1,    19,   117,
     112,   114,   111,    75,   116,    76,    -1,     3,    -1,    79,
     113,    80,    -1,     3,    74,   113,    -1,     3,    -1,    -1,
      20,    79,   115,    80,    -1,    20,   115,    -1,     3,    74,
     115,    -1,     3,    -1,    -1,   120,   116,    -1,     3,    -1,
     118,   119,    -1,    -1,   120,    -1,   131,    -1,   123,    -1,
     130,    -1,    -1,   121,   132,    -1,   141,    -1,   143,    -1,
     145,    -1,   147,    -1,     4,    -1,     3,    -1,   127,    18,
     128,    20,   122,    -1,   127,     3,   128,    20,   122,    -1,
      18,   128,    20,   122,    -1,     3,   128,    20,   122,    -1,
     127,   117,   124,   125,    -1,   117,   124,   125,    -1,   122,
      -1,    79,   126,    80,    -1,    -1,    20,   129,    -1,   126,
      74,   122,    -1,   122,    -1,   122,    81,    -1,    79,   126,
      80,    81,    -1,    -1,    82,   122,    -1,    82,    79,   126,
      80,    -1,   122,    -1,    79,   126,    80,    -1,    22,    82,
     122,    20,   122,    -1,    71,    25,    -1,    23,    79,   136,
      80,    77,   118,    78,   133,   134,    -1,   133,    24,    79,
     136,    80,    77,   118,    78,    -1,    -1,    24,    77,   118,
      78,    -1,    -1,   135,    61,   135,    -1,   135,    62,   135,
      -1,   135,    63,   135,    -1,   135,    64,   135,    -1,   135,
      65,   135,    -1,     3,    -1,     4,    -1,   136,    29,   136,
      -1,   136,    32,   136,    -1,   136,    33,   136,    -1,   136,
      34,   136,    -1,   136,    68,   136,    -1,   136,    67,   136,
      -1,   136,    69,   136,    -1,    79,   136,    80,    -1,   135,
      -1,    30,    -1,    31,    -1,     4,    -1,     3,    -1,   137,
      82,   137,    -1,   137,    82,   137,    82,   137,    -1,   139,
      74,   138,    -1,   138,    -1,   140,    74,     3,    -1,     3,
      -1,    -1,    26,     3,   142,    21,    79,   138,    80,    77,
     118,    78,    -1,    -1,    27,    79,   140,    80,    21,    79,
     139,    80,   144,    77,   118,    78,    -1,    -1,    28,    79,
     140,    80,    21,    79,   139,    80,   146,    77,   118,    78,
      -1,    35,    79,   136,    80,    77,   118,    78,    -1,     3,
      -1,    44,    -1,    45,    -1,    46,    -1,    47,    -1,    48,
      -1,    49,    -1,    50,    -1,    51,    -1,    52,    -1,    53,
      -1,    55,    75,   149,    76,    -1,    30,    -1,    31,    -1,
      56,    -1,     6,    -1,    57,    -1,     4,    -1,    79,   152,
      74,   152,    80,    -1,    75,   155,    76,    -1,   155,    74,
     156,    -1,   156,    -1,    75,   157,    76,    -1,   157,    74,
     158,    -1,   158,    -1,   153,    -1,   152,    -1,    77,   160,
      74,   160,    78,    -1,   153,    -1,   152,    -1,   151,    -1,
     153,    -1,   154,    -1,   159,    -1,     4,    -1,     6,    -1,
      56,    -1,    57,    -1,    50,    -1,    75,   163,    76,    -1,
     163,    74,   161,    -1,   161,    -1,    36,    79,   166,    74,
     166,    80,    -1,    37,    79,   166,    74,   166,    80,    -1,
      38,    79,   166,    74,   166,    80,    -1,    39,    79,   166,
      80,    -1,    40,    79,   166,    80,    -1,    42,    79,   166,
      74,     4,    80,    -1,    42,    79,   166,    74,    79,   165,
      80,    80,    -1,    43,    79,   166,    80,    -1,    41,    79,
     166,    80,    -1,   165,    74,   166,    -1,   166,    -1,   161,
      -1,   162,    -1,   148,    -1,   148,    75,   166,    76,    -1,
     148,    75,   166,    76,    75,   166,    76,    -1,   148,    75,
     166,    76,    75,   166,    76,    75,   166,    76,    -1,   164,
      -1,    79,   166,    80,    -1,    70,   166,    -1,   166,    33,
     166,    -1,   166,    34,   166,    -1,   166,    29,   166,    -1,
     166,    32,   166,    -1,   166,    63,   166,    -1,   166,    64,
     166,    -1,   166,    61,   166,    -1,   166,    62,   166,    -1,
     166,    66,   166,    -1,   166,    67,   166,    -1,   166,    68,
     166,    -1,   166,    69,   166,    -1,     3,    73,   166,    -1,
     149,   167,    -1,   150,   167,    -1,    59,    79,   170,    80,
      -1,   170,    74,   166,    -1,   166,    -1,    71,    58,    50,
      -1,    -1,   173,   174,    -1,   178,    -1,   181,    -1,   184,
      -1,   187,    -1,    -1,    23,    79,   166,    80,    77,   175,
     189,    78,   176,   177,    -1,   176,    24,    79,   166,    80,
      77,   189,    78,    -1,    -1,    24,    77,   189,    78,    -1,
      -1,    -1,    -1,    26,     3,   179,    21,    79,   138,    80,
      77,   180,   189,    78,    -1,    -1,    -1,    27,    79,   140,
      80,    21,    79,   139,    80,   182,    77,   183,   189,    78,
      -1,    -1,    -1,    28,    79,   140,    80,    21,    79,   139,
      80,   185,    77,   186,   189,    78,    -1,    -1,    35,    79,
     136,    80,    77,   188,   189,    78,    -1,   189,   190,    -1,
      -1,   172,    -1,   171,    -1,   169,    -1,    -1,   191,   167,
      -1,    -1,   192,   168,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    79,    79,    83,    83,    86,    86,    89,    89,    97,
     101,   102,   103,   104,   105,   108,   111,   114,   115,   118,
     119,   122,   126,   126,   127,   130,   131,   134,   134,   137,
     138,   140,   141,   143,   144,   146,   147,   150,   150,   153,
     154,   157,   157,   160,   161,   164,   165,   168,   169,   170,
     173,   174,   177,   178,   181,   189,   190,   193,   194,   196,
     197,   198,   198,   199,   200,   201,   202,   205,   206,   211,
     212,   213,   214,   215,   216,   219,   220,   223,   224,   227,
     228,   231,   232,   235,   236,   237,   240,   241,   255,   258,
     261,   264,   265,   268,   269,   272,   273,   274,   275,   276,
     277,   278,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   295,   296,   299,   300,   303,   304,   307,
     308,   311,   311,   314,   314,   317,   317,   320,   329,   330,
     331,   334,   335,   336,   337,   338,   339,   340,   341,   344,
     351,   352,   355,   356,   357,   358,   360,   363,   366,   367,
     370,   373,   374,   377,   378,   381,   384,   385,   388,   389,
     390,   391,   392,   393,   394,   395,   396,   399,   402,   403,
     407,   408,   409,   410,   411,   412,   413,   414,   415,   421,
     422,   426,   427,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   438,   439,   440,   441,   442,   443,   446,
     447,   448,   452,   455,   457,   461,   464,   465,   469,   473,
     473,   474,   475,   476,   477,   480,   480,   483,   484,   487,
     488,   491,   491,   491,   494,   494,   494,   497,   497,   497,
     500,   500,   505,   506,   509,   510,   511,   512,   512,   513,
     513
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ID", "NUMBER", "ITERS", "NEG", "SET",
  "STATES", "REGISTERS", "QUANTUM", "CLASSICAL", "MAIN_BEGIN", "MAIN_END",
  "OUTPUT_BEGIN", "OUTPUT_END", "INIT_BEGIN", "INIT_END", "GATE", "BLOCK",
  "ARROW", "IN", "MEASURE", "CONDITION", "OTHERWISE", "BARRIER", "FOR",
  "FOR_LEX", "FOR_ZIP", "COMP", "TRUE", "FALSE", "EQUALITY", "AND", "OR",
  "WHILE", "ADD", "SUB", "DOT", "STD_DEV", "VAR", "AVG", "CONDENSE", "SUM",
  "COUT", "QOUT", "INT", "UINT", "FLOAT", "COMPLEX", "STRING", "MATRIX",
  "STATE", "BOOL", "IMAG", "LIST", "DEC", "EXP", "SAVE", "ECHO", "RETURN",
  "'+'", "'-'", "'*'", "'/'", "'%'", "'@'", "'&'", "'^'", "'|'", "'!'",
  "'\\\\'", "'#'", "'='", "','", "'['", "']'", "'{'", "'}'", "'('", "')'",
  "'?'", "':'", "$accept", "prgm", "init_section", "@1", "main_section",
  "@2", "output_section", "@3", "mandatory_init", "set_states",
  "set_quantum_states", "set_classical_states", "quantum_state_list",
  "classical_state_list", "classical_state", "gate_defn_section", "@4",
  "gate_defn_list", "gate_defn", "@5", "rhs", "tuple_list", "tuple_list2",
  "id_list", "block_defn_section", "@6", "block_defns_list", "block_defn",
  "@7", "params", "param_id_list", "target_params", "target_param_list",
  "block_body", "block_id", "main_stmt_list", "main_stmt", "stmts", "@8",
  "register", "call_stmt", "parameters", "optional", "register_list",
  "classic_control", "quantum_control", "target", "measure_stmt",
  "barrier_stmt", "condition_stmt", "otherwise_list", "otherwise_final",
  "arithmetic_expr", "expr", "value", "range", "range_list", "var_list",
  "for_stmt", "@9", "for_lex_stmt", "@10", "for_zip_stmt", "@11",
  "while_stmt", "out_id", "prim_type", "list_type", "bool_const", "num",
  "complex_const", "matrix_const", "row_list", "row", "comps",
  "compatible_const", "state_const", "temp", "prim_const", "vec_const",
  "vec_list", "calls", "uint_list", "out_rhs", "out_expr", "decl",
  "echo_stmt", "echo_list", "save_stmt", "out_control", "@12",
  "out_cond_stmt", "@13", "out_other_list", "out_other_final",
  "out_for_stmt", "@14", "@15", "out_for_lex_stmt", "@16", "@17",
  "out_for_zip_stmt", "@18", "@19", "out_while_stmt", "@20", "out_main",
  "out_stmt", "@21", "@22", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,    43,    45,    42,    47,    37,    64,    38,    94,   124,
      33,    92,    35,    61,    44,    91,    93,   123,   125,    40,
      41,    63,    58
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
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

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
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

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
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

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     8,     7,    14,    11,    22,    13,    18,
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

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -411
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

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -238
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

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
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

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
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



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 79 "./Parser/parser_main.y"
    {fprintf(fp,"\nParsing successful!\n");}
    break;

  case 3:
#line 83 "./Parser/parser_main.y"
    {fprintf(fp,"\nInit section begins\n\n");}
    break;

  case 4:
#line 83 "./Parser/parser_main.y"
    {fprintf(fp,"\nInit section ends\n");}
    break;

  case 5:
#line 86 "./Parser/parser_main.y"
    {fprintf(fp,"\nMain section begins\n\n");}
    break;

  case 6:
#line 86 "./Parser/parser_main.y"
    {fprintf(fp,"\nMain section ends\n");}
    break;

  case 7:
#line 89 "./Parser/parser_main.y"
    {fprintf(fp,"\nOutput section begins\n\n"); isInOutput = true; outputLevel = 1;}
    break;

  case 8:
#line 89 "./Parser/parser_main.y"
    {fprintf(fp,"\nOutput section ends\n");exitOutputSymbolScope(&OutputSymbolTable,outputLevel);}
    break;

  case 9:
#line 97 "./Parser/parser_main.y"
    {  fprintf(fp,"Register and iteration initialization section\n");classical_registers = (yyvsp[(10) - (14)]).num;quantum_registers = (yyvsp[(5) - (14)]).num;iterations = (yyvsp[(14) - (14)]).num;}
    break;

  case 15:
#line 108 "./Parser/parser_main.y"
    {fprintf(fp,"Setting initial state of quantum registers\n");}
    break;

  case 16:
#line 111 "./Parser/parser_main.y"
    {fprintf(fp,"Setting initial state of classical registers\n");}
    break;

  case 17:
#line 114 "./Parser/parser_main.y"
    {if(quantum_index == quantum_registers){yyerror();return 1;}quantum_states[quantum_index++] = (yyvsp[(3) - (3)]).q;}
    break;

  case 18:
#line 115 "./Parser/parser_main.y"
    {quantum_states = (struct Quantum*)malloc(sizeof(struct Quantum)*quantum_registers);quantum_states[quantum_index++] = (yyvsp[(1) - (1)]).q;}
    break;

  case 19:
#line 118 "./Parser/parser_main.y"
    {if(classical_index == classical_registers){yyerror();return 1;}classical_states[classical_index++] = (yyvsp[(3) - (3)]).num;}
    break;

  case 20:
#line 119 "./Parser/parser_main.y"
    {classical_states = (int *)malloc(sizeof(int)*classical_registers);classical_states[classical_index++] = (yyvsp[(1) - (1)]).num;}
    break;

  case 21:
#line 122 "./Parser/parser_main.y"
    {(yyval).num = (yyvsp[(1) - (1)]).num;}
    break;

  case 22:
#line 126 "./Parser/parser_main.y"
    {fprintf(fp,"Gate definition section begins\n");}
    break;

  case 23:
#line 126 "./Parser/parser_main.y"
    {fprintf(fp,"Gate definition section ends\n");}
    break;

  case 27:
#line 134 "./Parser/parser_main.y"
    {fprintf(fp,"Gate definition\n");}
    break;

  case 28:
#line 134 "./Parser/parser_main.y"
    {insertInGateTable(&GateSymbolTable,(yyvsp[(2) - (5)]).str,(yyvsp[(4) - (5)]).rows,(yyvsp[(4) - (5)]).cols);}
    break;

  case 29:
#line 137 "./Parser/parser_main.y"
    {(yyval).rows = (yyvsp[(2) - (3)]).rows;(yyval).cols = (yyvsp[(2) - (3)]).cols;}
    break;

  case 31:
#line 140 "./Parser/parser_main.y"
    {if((yyvsp[(1) - (5)]).cols != (yyvsp[(4) - (5)]).cols){yyerror();return 1;}int temp; temp = (yyvsp[(1) - (5)]).rows + 1;(yyval).rows = temp;(yyval).cols = (yyvsp[(1) - (5)]).cols;}
    break;

  case 32:
#line 141 "./Parser/parser_main.y"
    {(yyval).rows = 1;(yyval).cols = (yyvsp[(2) - (3)]).cols;}
    break;

  case 35:
#line 146 "./Parser/parser_main.y"
    {(yyval).cols += 1;}
    break;

  case 36:
#line 147 "./Parser/parser_main.y"
    {(yyval).cols = 1;}
    break;

  case 37:
#line 150 "./Parser/parser_main.y"
    {fprintf(fp,"Block definition section begins\n");}
    break;

  case 38:
#line 150 "./Parser/parser_main.y"
    {fprintf(fp,"Block definition section ends\n");}
    break;

  case 41:
#line 157 "./Parser/parser_main.y"
    {insertInBlockTable(&BlockSymbolTable,(yyvsp[(2) - (4)]).str,(yyvsp[(3) - (4)]).num,head);head = NULL;isInBlock = 1;}
    break;

  case 42:
#line 157 "./Parser/parser_main.y"
    {fprintf(fp,"Block definition\n");if(!BlockSemanticCheck((yyvsp[(2) - (8)]).str)){yyerror();return 1;}id_list = NULL;isInBlock = 0;}
    break;

  case 43:
#line 160 "./Parser/parser_main.y"
    {insertInList(&head,(yyvsp[(1) - (1)]).str);(yyval).num = 1;}
    break;

  case 44:
#line 161 "./Parser/parser_main.y"
    {(yyval).num = (yyvsp[(2) - (3)]).num;}
    break;

  case 45:
#line 164 "./Parser/parser_main.y"
    {insertInList(&head,(yyvsp[(1) - (3)]).str);(yyval).num = 1 + (yyvsp[(3) - (3)]).num;}
    break;

  case 46:
#line 165 "./Parser/parser_main.y"
    {insertInList(&head,(yyvsp[(1) - (1)]).str);(yyval).num = 1;}
    break;

  case 54:
#line 181 "./Parser/parser_main.y"
    {if(!firstLetterCapital((yyvsp[(1) - (1)]).str)){yyerror(); return 1;} (yyval).str = (yyvsp[(1) - (1)]).str;}
    break;

  case 58:
#line 194 "./Parser/parser_main.y"
    {fprintf(fp,"barrier statement\n");}
    break;

  case 60:
#line 197 "./Parser/parser_main.y"
    {fprintf(fp,"Measure statement\n");}
    break;

  case 61:
#line 198 "./Parser/parser_main.y"
    {fprintf(fp,"Conditional statement begin\n");}
    break;

  case 62:
#line 198 "./Parser/parser_main.y"
    {fprintf(fp,"Conditional statement end\n");}
    break;

  case 63:
#line 199 "./Parser/parser_main.y"
    {fprintf(fp,"For statement\n");}
    break;

  case 64:
#line 200 "./Parser/parser_main.y"
    {fprintf(fp,"For - Lex statement\n");}
    break;

  case 65:
#line 201 "./Parser/parser_main.y"
    {fprintf(fp,"For - Zip statement\n");}
    break;

  case 66:
#line 202 "./Parser/parser_main.y"
    {fprintf(fp,"while statement\n");}
    break;

  case 67:
#line 205 "./Parser/parser_main.y"
    {if((yyvsp[(1) - (1)]).num < 0){yyerror(); return 1;} (yyval).num = (yyvsp[(1) - (1)]).num;(yyval).flag=0;}
    break;

  case 68:
#line 206 "./Parser/parser_main.y"
    {if(isInBlock){insertInList(&id_list,(yyvsp[(1) - (1)]).str);}(yyval).flag = 1;}
    break;

  case 69:
#line 211 "./Parser/parser_main.y"
    {fprintf(fp,"Pre - defined Gate call statement\n");}
    break;

  case 70:
#line 212 "./Parser/parser_main.y"
    {fprintf(fp,"user - defined Gate call statement\n");}
    break;

  case 71:
#line 213 "./Parser/parser_main.y"
    {fprintf(fp,"Pre - defined Gate call statement\n");}
    break;

  case 72:
#line 214 "./Parser/parser_main.y"
    {fprintf(fp,"User - defined Gate call statement\n");}
    break;

  case 73:
#line 215 "./Parser/parser_main.y"
    {fprintf(fp,"Block call statement\n");if(!isInBlock){if(!BlockCallSemanticCheck((yyvsp[(2) - (4)]).str,(yyvsp[(3) - (4)]).num)){yyerror();return 1;}}}
    break;

  case 74:
#line 216 "./Parser/parser_main.y"
    {fprintf(fp,"Block call statement\n");if(!isInBlock){if(!BlockCallSemanticCheck((yyvsp[(1) - (3)]).str,(yyvsp[(2) - (3)]).num)){yyerror();return 1;}}}
    break;

  case 75:
#line 219 "./Parser/parser_main.y"
    {(yyval).num = 1;}
    break;

  case 76:
#line 220 "./Parser/parser_main.y"
    {(yyval).num = (yyvsp[(2) - (3)]).num;}
    break;

  case 79:
#line 227 "./Parser/parser_main.y"
    {(yyval).num = 1 + (yyvsp[(1) - (3)]).num;}
    break;

  case 80:
#line 228 "./Parser/parser_main.y"
    {(yyval).num = 1;}
    break;

  case 88:
#line 255 "./Parser/parser_main.y"
    {if((!(yyvsp[(3) - (5)]).flag && ((yyvsp[(3) - (5)]).num < 0 || (yyvsp[(3) - (5)]).num >= quantum_registers)) || (!(yyvsp[(5) - (5)]).flag && ((yyvsp[(5) - (5)]).num < 0 || (yyvsp[(5) - (5)]).num >= classical_registers))){yyerror(); return 1;}}
    break;

  case 117:
#line 303 "./Parser/parser_main.y"
    {(yyval).num = 1 + (yyvsp[(1) - (3)]).num;}
    break;

  case 118:
#line 304 "./Parser/parser_main.y"
    {(yyval).num = 1;}
    break;

  case 119:
#line 307 "./Parser/parser_main.y"
    {if(isInOutput){if(getOutputSymbolEntry(&OutputSymbolTable,(yyvsp[(3) - (3)]).str,outputLevel + 1,0) != NULL){yyerror(); return 1;} else insertInOutputTable(&OutputSymbolTable,(yyvsp[(2) - (3)]).str,outputLevel + 1, Int,true,0,0,true);} else if(!inList(&head,(yyvsp[(3) - (3)]).str)){insertInList(&head,(yyvsp[(3) - (3)]).str);} else {yyerror(); return 1;} (yyval).num = 1 + (yyvsp[(1) - (3)]).num;}
    break;

  case 120:
#line 308 "./Parser/parser_main.y"
    {if(isInOutput){if(getOutputSymbolEntry(&OutputSymbolTable,(yyvsp[(1) - (1)]).str,outputLevel + 1,0) != NULL){yyerror(); return 1;} else insertInOutputTable(&OutputSymbolTable,(yyvsp[(1) - (1)]).str,outputLevel + 1, Int,true,0,0,true);} else if(!inList(&head,(yyvsp[(1) - (1)]).str)){insertInList(&head,(yyvsp[(1) - (1)]).str);} else {yyerror(); return 1;} (yyval).num = 1;}
    break;

  case 121:
#line 311 "./Parser/parser_main.y"
    {if(!inList(&head,(yyvsp[(2) - (2)]).str)){insertInList(&head,(yyvsp[(2) - (2)]).str);} else {yyerror(); return 1;}}
    break;

  case 122:
#line 311 "./Parser/parser_main.y"
    {removeTopKFromList(&head,1);}
    break;

  case 123:
#line 314 "./Parser/parser_main.y"
    {if((yyvsp[(3) - (8)]).num != (yyvsp[(7) - (8)]).num){yyerror(); return 1;}}
    break;

  case 124:
#line 314 "./Parser/parser_main.y"
    {removeTopKFromList(&head,(yyvsp[(3) - (12)]).num);}
    break;

  case 125:
#line 317 "./Parser/parser_main.y"
    {if((yyvsp[(3) - (8)]).num != (yyvsp[(7) - (8)]).num){yyerror(); return 1;}}
    break;

  case 126:
#line 317 "./Parser/parser_main.y"
    {removeTopKFromList(&head,(yyvsp[(3) - (12)]).num);}
    break;

  case 128:
#line 329 "./Parser/parser_main.y"
    {(yyval).out_flag = 0; (yyval).str = (yyvsp[(1) - (1)]).str;}
    break;

  case 129:
#line 330 "./Parser/parser_main.y"
    {(yyval).out_flag = 1; (yyval).type = Int; (yyval).prim = false; (yyval).dim = (1 << classical_registers); (yyval).rows = 0;}
    break;

  case 130:
#line 331 "./Parser/parser_main.y"
    {(yyval).out_flag = 2; (yyval).type = State; (yyval).prim = false; (yyval).dim = quantum_registers; (yyval).rows = 0;}
    break;

  case 131:
#line 334 "./Parser/parser_main.y"
    {(yyval).type = Int; (yyval).prim = true;}
    break;

  case 132:
#line 335 "./Parser/parser_main.y"
    {(yyval).type = Uint; (yyval).prim = true;}
    break;

  case 133:
#line 336 "./Parser/parser_main.y"
    {(yyval).type = Float; (yyval).prim = true;}
    break;

  case 134:
#line 337 "./Parser/parser_main.y"
    {(yyval).type = Complex; (yyval).prim = true;}
    break;

  case 135:
#line 338 "./Parser/parser_main.y"
    {(yyval).type = String; (yyval).prim = true;}
    break;

  case 136:
#line 339 "./Parser/parser_main.y"
    {(yyval).type = Matrix; (yyval).prim = true;}
    break;

  case 137:
#line 340 "./Parser/parser_main.y"
    {(yyval).type = State; (yyval).prim = true;}
    break;

  case 138:
#line 341 "./Parser/parser_main.y"
    {(yyval).type = Bool; (yyval).prim = true;}
    break;

  case 139:
#line 344 "./Parser/parser_main.y"
    {(yyval).type = (yyvsp[(3) - (4)]).type; (yyval).prim = false;}
    break;

  case 142:
#line 355 "./Parser/parser_main.y"
    {(yyval).real = (yyvsp[(1) - (1)]).real;}
    break;

  case 143:
#line 356 "./Parser/parser_main.y"
    {(yyval).real = (yyvsp[(1) - (1)]).real;}
    break;

  case 144:
#line 357 "./Parser/parser_main.y"
    {(yyval).real = (yyvsp[(1) - (1)]).real;}
    break;

  case 145:
#line 358 "./Parser/parser_main.y"
    {(yyval).real = (yyvsp[(1) - (1)]).num;}
    break;

  case 146:
#line 360 "./Parser/parser_main.y"
    {(yyval).cpx.real = (yyvsp[(2) - (5)]).real; (yyval).cpx.imag = (yyvsp[(4) - (5)]).real;}
    break;

  case 147:
#line 363 "./Parser/parser_main.y"
    {if((yyvsp[(2) - (3)]).rows == (yyvsp[(2) - (3)]).cols) {(yyval).rows = (yyvsp[(2) - (3)]).rows;} else {yyerror(); return 1;}}
    break;

  case 148:
#line 366 "./Parser/parser_main.y"
    {(yyval).rows = (yyvsp[(1) - (3)]).rows + 1; if((yyvsp[(1) - (3)]).cols == (yyvsp[(3) - (3)]).cols) {(yyval).cols = (yyvsp[(1) - (3)]).cols;} else {yyerror(); return 1;}}
    break;

  case 149:
#line 367 "./Parser/parser_main.y"
    {(yyval).rows = 1; (yyval).cols = (yyvsp[(1) - (1)]).cols;}
    break;

  case 150:
#line 370 "./Parser/parser_main.y"
    {(yyval).cols = (yyvsp[(2) - (3)]).cols;}
    break;

  case 151:
#line 373 "./Parser/parser_main.y"
    {(yyval).cols = (yyvsp[(1) - (3)]).cols + 1;}
    break;

  case 152:
#line 374 "./Parser/parser_main.y"
    {(yyval).cols = 1;}
    break;

  case 155:
#line 381 "./Parser/parser_main.y"
    {(yyval).q.first = (yyvsp[(2) - (5)]).cpx; (yyval).q.second = (yyvsp[(4) - (5)]).cpx;}
    break;

  case 156:
#line 384 "./Parser/parser_main.y"
    {(yyval).cpx = (yyvsp[(1) - (1)]).cpx;}
    break;

  case 157:
#line 385 "./Parser/parser_main.y"
    {(yyval).cpx.real = (yyvsp[(1) - (1)]).real; (yyval).cpx.imag = 0;}
    break;

  case 158:
#line 388 "./Parser/parser_main.y"
    {(yyval).type = Bool;}
    break;

  case 159:
#line 389 "./Parser/parser_main.y"
    {(yyval).type = Complex;}
    break;

  case 160:
#line 390 "./Parser/parser_main.y"
    {(yyval).type = Matrix; (yyval).rows = (yyvsp[(1) - (1)]).rows;}
    break;

  case 161:
#line 391 "./Parser/parser_main.y"
    {(yyval).type = State;}
    break;

  case 162:
#line 392 "./Parser/parser_main.y"
    {(yyval).type = Uint;}
    break;

  case 163:
#line 393 "./Parser/parser_main.y"
    {(yyval).type = Int;}
    break;

  case 164:
#line 394 "./Parser/parser_main.y"
    {(yyval).type = Float;}
    break;

  case 165:
#line 395 "./Parser/parser_main.y"
    {(yyval).type = Float;}
    break;

  case 166:
#line 396 "./Parser/parser_main.y"
    {(yyval).type = String;}
    break;

  case 167:
#line 399 "./Parser/parser_main.y"
    {(yyval).dim = (yyvsp[(2) - (3)]).dim; (yyval).type = (yyvsp[(2) - (3)]).type; if((yyval).type == Matrix) {(yyval).rows = (yyvsp[(2) - (3)]).rows;} else {(yyval).rows = 0;} }
    break;

  case 168:
#line 402 "./Parser/parser_main.y"
    {temp_type = compatibleCheck((yyvsp[(1) - (3)]).type, (yyvsp[(3) - (3)]).type); if(temp_type != -1) {(yyval).type = temp_type;} else {yyerror(); return 1;} (yyval).dim = (yyvsp[(1) - (3)]).dim + 1; if((yyval).type == Matrix){ if((yyvsp[(1) - (3)]).rows != (yyvsp[(3) - (3)]).rows){yyerror();return 1;}else{(yyval).rows = (yyvsp[(1) - (3)]).rows;} }}
    break;

  case 169:
#line 403 "./Parser/parser_main.y"
    {(yyval).type = (yyvsp[(1) - (1)]).type; (yyval).dim = 1; if((yyval).type == Matrix) {(yyval).rows = (yyvsp[(1) - (1)]).rows;}}
    break;

  case 170:
#line 407 "./Parser/parser_main.y"
    {temp_type = compatibleCheckAdv((yyvsp[(5) - (6)]).type, (yyvsp[(3) - (6)]).type, (yyvsp[(5) - (6)]).prim, (yyvsp[(3) - (6)]).prim, (yyvsp[(5) - (6)]).dim, (yyvsp[(3) - (6)]).dim); printf("%d\n", temp_type); if((!(yyvsp[(3) - (6)]).prim) && (temp_type>= 0) && ((temp_type<=COMPATIBLE) || temp_type==Matrix || temp_type==State/*|| temp_type==String*/)) {(yyval).prim = false; (yyval).type = temp_type; (yyval).dim = (yyvsp[(3) - (6)]).dim;} else {yyerror(); return 1;}}
    break;

  case 171:
#line 408 "./Parser/parser_main.y"
    {temp_type = compatibleCheckAdv((yyvsp[(5) - (6)]).type, (yyvsp[(3) - (6)]).type, (yyvsp[(5) - (6)]).prim, (yyvsp[(3) - (6)]).prim, (yyvsp[(5) - (6)]).dim, (yyvsp[(3) - (6)]).dim); if((!(yyvsp[(3) - (6)]).prim) && (temp_type>= 0) && ((temp_type<=COMPATIBLE) || temp_type==Matrix || temp_type==State)) {(yyval).prim = false; (yyval).type = temp_type; (yyval).dim = (yyvsp[(3) - (6)]).dim;} else {yyerror(); return 1;}}
    break;

  case 172:
#line 409 "./Parser/parser_main.y"
    {temp_type = compatibleCheckAdv((yyvsp[(5) - (6)]).type, (yyvsp[(3) - (6)]).type, (yyvsp[(5) - (6)]).prim, (yyvsp[(3) - (6)]).prim, (yyvsp[(5) - (6)]).dim, (yyvsp[(3) - (6)]).dim); if((!(yyvsp[(3) - (6)]).prim) && (temp_type>= 0) && (temp_type<=COMPATIBLE)) {(yyval).prim = true; (yyval).type = temp_type; (yyval).dim = (yyvsp[(3) - (6)]).dim;} else if ((!(yyvsp[(3) - (6)]).prim) && (!(yyvsp[(5) - (6)]).prim) && ((yyvsp[(3) - (6)]).type<=COMPATIBLE) && ((yyvsp[(5) - (6)]).type==Matrix)) {(yyval).prim = true; (yyval).type = Matrix; (yyval).dim = 0;} else if((yyvsp[(3) - (6)]).prim && (temp_type==State)) {(yyval).prim = true; (yyval).type = Complex;} else {yyerror(); return 1;}}
    break;

  case 173:
#line 410 "./Parser/parser_main.y"
    {if((!(yyvsp[(3) - (4)]).prim) && (((yyvsp[(3) - (4)]).type==Uint) || ((yyvsp[(3) - (4)]).type==Int) || ((yyvsp[(3) - (4)]).type==Float))) {(yyval).prim = true; (yyval).type = (yyvsp[(3) - (4)]).type; (yyval).dim = (yyvsp[(3) - (4)]).dim;} else {yyerror(); return 1;}}
    break;

  case 174:
#line 411 "./Parser/parser_main.y"
    {if((!(yyvsp[(3) - (4)]).prim) && (((yyvsp[(3) - (4)]).type==Uint) || ((yyvsp[(3) - (4)]).type==Int) || ((yyvsp[(3) - (4)]).type==Float))) {(yyval).prim = true; (yyval).type = (yyvsp[(3) - (4)]).type; (yyval).dim = (yyvsp[(3) - (4)]).dim;} else {yyerror(); return 1;}}
    break;

  case 175:
#line 412 "./Parser/parser_main.y"
    {if((!(yyvsp[(3) - (6)]).prim) && (((yyvsp[(3) - (6)]).type==Uint) || ((yyvsp[(3) - (6)]).type==Int))) {(yyval).prim = false; (yyval).type = (yyvsp[(3) - (6)]).type; (yyval).dim = condenser((yyvsp[(3) - (6)]).dim, 1);} else {yyerror(); return 1;}}
    break;

  case 176:
#line 413 "./Parser/parser_main.y"
    {if((!(yyvsp[(3) - (8)]).prim) && (((yyvsp[(3) - (8)]).type==Uint) || ((yyvsp[(3) - (8)]).type==Int))) {(yyval).prim = false; (yyval).type = (yyvsp[(3) - (8)]).type; (yyval).dim = condenser((yyvsp[(3) - (8)]).dim, (yyvsp[(6) - (8)]).cond_count);} else {yyerror(); return 1;}}
    break;

  case 177:
#line 414 "./Parser/parser_main.y"
    {if((!(yyvsp[(3) - (4)]).prim) && (((yyvsp[(3) - (4)]).type<=COMPATIBLE) || (yyvsp[(3) - (4)]).type==Matrix /*|| temp_type==String*/)) {(yyval).prim = true; (yyval).type = (yyvsp[(3) - (4)]).type; (yyval).dim = 0;} else {yyerror(); return 1;}}
    break;

  case 178:
#line 415 "./Parser/parser_main.y"
    {if((!(yyvsp[(3) - (4)]).prim) && (((yyvsp[(3) - (4)]).type<=COMPATIBLE) || (yyvsp[(3) - (4)]).type==Matrix)) {(yyval).prim = true; (yyval).type = (yyvsp[(3) - (4)]).type; (yyval).dim = 0;} else {yyerror(); return 1;}}
    break;

  case 179:
#line 421 "./Parser/parser_main.y"
    {if((yyvsp[(1) - (3)]).type <= Int) {(yyval).cond_count = (yyvsp[(1) - (3)]).cond_count + 1;} else {yyerror(); return 1;}}
    break;

  case 180:
#line 422 "./Parser/parser_main.y"
    {if((yyvsp[(1) - (1)]).type <= Int) {(yyval).cond_count = 1;} else {yyerror(); return 1;}}
    break;

  case 181:
#line 426 "./Parser/parser_main.y"
    {(yyval).prim = true; (yyval).type = (yyvsp[(1) - (1)]).type;}
    break;

  case 182:
#line 427 "./Parser/parser_main.y"
    {(yyval).prim = false; (yyval).dim = (yyvsp[(1) - (1)]).dim; (yyval).type = (yyvsp[(1) - (1)]).type; if((yyval).type == Matrix) {(yyval).rows = (yyvsp[(1) - (1)]).rows;} else {(yyval).rows = 0;}}
    break;

  case 183:
#line 428 "./Parser/parser_main.y"
    {if((yyval).out_flag == 0){struct OutputSymbolEntry* sample = getOutputSymbolEntry(&OutputSymbolTable,(yyvsp[(1) - (1)]).str,outputLevel,1); if(sample != NULL){(yyval).prim = sample->primitive; (yyval).type = sample->type; if((yyval).type == Matrix){(yyval).rows = sample->matrix_dim;} if(!(yyval).prim){(yyval).dim = sample->dim;}} else{yyerror(); return 1;}} else if((yyval).out_flag == 1){(yyval).type = Int; (yyval).prim = false; (yyval).dim = (1 << classical_registers); (yyval).rows = 0;} else{(yyval).type = State; (yyval).prim = false; (yyval).dim = quantum_registers; (yyval).rows = 0;}}
    break;

  case 184:
#line 429 "./Parser/parser_main.y"
    {if((yyval).out_flag == 0){struct OutputSymbolEntry* sample = getOutputSymbolEntry(&OutputSymbolTable,(yyvsp[(1) - (4)]).str,outputLevel,1); if(sample != NULL){if((yyvsp[(3) - (4)]).type <= Uint){if(sample->primitive) {if(sample->type==State) {(yyval).type = Complex; (yyval).prim = true;} else {yyerror(); return 1;}} else {(yyval).type = sample->type; (yyval).prim = true;}} else {yyerror(); return 1;}} else{yyerror(); return 1;}} else if((yyval).out_flag == 1){(yyval).type = Uint; (yyval).prim = true;} else{(yyval).type = State; (yyval).prim = true;}}
    break;

  case 185:
#line 430 "./Parser/parser_main.y"
    {if((yyval).out_flag == 0){struct OutputSymbolEntry* sample = getOutputSymbolEntry(&OutputSymbolTable,(yyvsp[(1) - (7)]).str,outputLevel,1); if(sample != NULL){if(((yyvsp[(3) - (7)]).type <= Uint) && ((yyvsp[(5) - (7)]).type <= Uint)) {if(sample->type) {if(sample->type==Matrix) {(yyval).type = Complex; (yyval).prim = true;} else {yyerror(); return 1;}} else if(sample->type==State) {(yyval).type = Complex; (yyval).prim = true;} else {yyerror(); return 1;}}} else{yyerror(); return 1;}} else if((yyval).out_flag == 1){yyerror(); return 1;} else{(yyval).type = Complex; (yyval).prim = true;}}
    break;

  case 186:
#line 431 "./Parser/parser_main.y"
    {if((yyval).out_flag == 0){struct OutputSymbolEntry* sample = getOutputSymbolEntry(&OutputSymbolTable,(yyvsp[(1) - (10)]).str,outputLevel,1); if(sample != NULL){if(((yyvsp[(3) - (10)]).type <= Uint) && ((yyvsp[(5) - (10)]).type <= Uint) && ((yyvsp[(7) - (10)]).type <= Uint)) {if(sample->primitive) {yyerror(); return 1;} else if(sample->type==Matrix) {(yyval).type = Complex; (yyval).prim = true;} else {yyerror(); return 1;}}} else{yyerror(); return 1;}} else{yyerror(); return 1;}}
    break;

  case 187:
#line 432 "./Parser/parser_main.y"
    {(yyval).prim = (yyvsp[(1) - (1)]).prim; (yyval).type = (yyvsp[(1) - (1)]).type; if((yyvsp[(1) - (1)]).type == Matrix){(yyval).rows = (yyvsp[(1) - (1)]).rows;} if(!(yyval).prim){(yyval).dim = (yyvsp[(1) - (1)]).dim;} printf("%d %d\n", (yyval).prim, (yyval).type);}
    break;

  case 188:
#line 433 "./Parser/parser_main.y"
    {(yyval).type = (yyvsp[(2) - (3)]).type;}
    break;

  case 189:
#line 434 "./Parser/parser_main.y"
    {if((yyvsp[(2) - (2)]).type==Bool && (yyvsp[(2) - (2)]).prim) {(yyval).prim = true; (yyval).type = Bool;} else {yyerror(); return 1;}  }
    break;

  case 190:
#line 435 "./Parser/parser_main.y"
    {if((yyvsp[(1) - (3)]).type==Bool && (yyvsp[(1) - (3)]).prim && (yyvsp[(3) - (3)]).type==Bool && (yyvsp[(3) - (3)]).prim)  {(yyval).prim = true; (yyval).type = Bool;} else {yyerror(); return 1;} }
    break;

  case 191:
#line 436 "./Parser/parser_main.y"
    {if((yyvsp[(1) - (3)]).type==Bool && (yyvsp[(1) - (3)]).prim && (yyvsp[(3) - (3)]).type==Bool && (yyvsp[(3) - (3)]).prim)  {(yyval).prim = true; (yyval).type = Bool;} else {yyerror(); return 1;} }
    break;

  case 192:
#line 437 "./Parser/parser_main.y"
    {temp_type = compatibleCheckAdv((yyvsp[(1) - (3)]).type, (yyvsp[(3) - (3)]).type, (yyvsp[(1) - (3)]).prim, (yyvsp[(3) - (3)]).prim, (yyvsp[(1) - (3)]).dim, (yyvsp[(3) - (3)]).dim); if(temp_type != -1 && temp_type < COMPARABLE) {(yyval).prim = true; (yyval).type = Bool;} else {yyerror(); return 1;}  }
    break;

  case 193:
#line 438 "./Parser/parser_main.y"
    {temp_type = compatibleCheckAdv((yyvsp[(1) - (3)]).type, (yyvsp[(3) - (3)]).type, (yyvsp[(1) - (3)]).prim, (yyvsp[(3) - (3)]).prim, (yyvsp[(1) - (3)]).dim, (yyvsp[(3) - (3)]).dim); if(temp_type != -1 && temp_type < COMPARABLE) {(yyval).prim = true; (yyval).type = Bool;} else {yyerror(); return 1;}  }
    break;

  case 194:
#line 439 "./Parser/parser_main.y"
    {temp_type = compatibleCheckAdv((yyvsp[(1) - (3)]).type, (yyvsp[(3) - (3)]).type, (yyvsp[(1) - (3)]).prim, (yyvsp[(3) - (3)]).prim, (yyvsp[(1) - (3)]).dim, (yyvsp[(3) - (3)]).dim); if((yyvsp[(1) - (3)]).prim && (temp_type <= Complex && temp_type >= 0)) {(yyval).prim = true; (yyval).type = temp_type;} else if((yyvsp[(1) - (3)]).prim && (yyvsp[(3) - (3)]).prim && (yyvsp[(1) - (3)]).type<=Complex && (yyvsp[(3) - (3)]).type==Matrix) {(yyval).prim = true; (yyval).type = Matrix;} else if (((yyvsp[(1) - (3)]).prim && (yyvsp[(3) - (3)]).prim) && (((yyvsp[(1) - (3)]).type == String && (yyvsp[(3) - (3)]).type == Uint) || ((yyvsp[(3) - (3)]).type == String && (yyvsp[(1) - (3)]).type == Uint))) {(yyval).prim = true; (yyval).type = String;} else {yyerror(); return 1;}}
    break;

  case 195:
#line 440 "./Parser/parser_main.y"
    {temp_type = compatibleCheckAdv((yyvsp[(1) - (3)]).type, (yyvsp[(3) - (3)]).type, (yyvsp[(1) - (3)]).prim, (yyvsp[(3) - (3)]).prim, (yyvsp[(1) - (3)]).dim, (yyvsp[(3) - (3)]).dim); if((yyvsp[(1) - (3)]).prim && (temp_type <= Complex && temp_type >= 0)) {(yyval).prim = true; (yyval).type = temp_type;} else {yyerror(); return 1;}}
    break;

  case 196:
#line 441 "./Parser/parser_main.y"
    {temp_type = compatibleCheckAdv((yyvsp[(1) - (3)]).type, (yyvsp[(3) - (3)]).type, (yyvsp[(1) - (3)]).prim, (yyvsp[(3) - (3)]).prim, (yyvsp[(1) - (3)]).dim, (yyvsp[(3) - (3)]).dim); if(temp_type == Matrix || temp_type == State || (temp_type <= Complex && temp_type >= 0)) {(yyval).prim = (yyvsp[(1) - (3)]).prim; (yyval).type = temp_type; if(temp_type == Matrix) {(yyval).rows=(yyvsp[(1) - (3)]).rows;} (yyval).dim=(yyvsp[(1) - (3)]).dim;} else if (((yyvsp[(1) - (3)]).prim==true) && ((yyvsp[(1) - (3)]).type == String)) {(yyval).prim = true; (yyval).type = String;} else {yyerror(); return 1;}}
    break;

  case 197:
#line 442 "./Parser/parser_main.y"
    {temp_type = compatibleCheckAdv((yyvsp[(1) - (3)]).type, (yyvsp[(3) - (3)]).type, (yyvsp[(1) - (3)]).prim, (yyvsp[(3) - (3)]).prim, (yyvsp[(1) - (3)]).dim, (yyvsp[(3) - (3)]).dim); if(temp_type == Matrix || temp_type == State || (temp_type <= Complex && temp_type >= 0)) {(yyval).prim = (yyvsp[(1) - (3)]).prim; (yyval).type = temp_type; if(temp_type == Matrix) {(yyval).rows=(yyvsp[(1) - (3)]).rows;} (yyval).dim=(yyvsp[(1) - (3)]).dim;} else {yyerror(); return 1;} }
    break;

  case 198:
#line 443 "./Parser/parser_main.y"
    {temp_type = compatibleCheckAdv((yyvsp[(1) - (3)]).type, (yyvsp[(3) - (3)]).type, (yyvsp[(1) - (3)]).prim, (yyvsp[(3) - (3)]).prim, (yyvsp[(1) - (3)]).dim, (yyvsp[(3) - (3)]).dim); if((yyvsp[(1) - (3)]).prim && temp_type == Matrix) {if((yyvsp[(1) - (3)]).rows == (yyvsp[(3) - (3)]).rows) {(yyval).prim = true; (yyval).type = temp_type; (yyval).rows = (yyvsp[(1) - (3)]).rows;} else {yyerror(); return 1;}} else if((yyvsp[(1) - (3)]).prim && temp_type == State) {(yyval).prim = true; (yyval).type = Complex;} else if(!(yyvsp[(1) - (3)]).prim && (temp_type <= COMPATIBLE) && (temp_type >= 0)) {(yyval).prim = true; (yyval).type = temp_type; (yyval).dim = 0;} else if ((yyvsp[(1) - (3)]).type<=COMPATIBLE && (yyvsp[(3) - (3)]).type==Matrix) {(yyval).prim = true; (yyval).type = Matrix; (yyval).dim = 0;} else {yyerror(); return 1;}}
    break;

  case 199:
#line 446 "./Parser/parser_main.y"
    {temp_type = compatibleCheckAdv((yyvsp[(1) - (3)]).type, (yyvsp[(3) - (3)]).type, (yyvsp[(1) - (3)]).prim, (yyvsp[(3) - (3)]).prim, (yyvsp[(1) - (3)]).dim, (yyvsp[(3) - (3)]).dim); if(temp_type <= Int) {(yyval).prim = (yyvsp[(1) - (3)]).prim; (yyval).type = temp_type;} else {yyerror(); return 1;}}
    break;

  case 200:
#line 447 "./Parser/parser_main.y"
    {temp_type = compatibleCheckAdv((yyvsp[(1) - (3)]).type, (yyvsp[(3) - (3)]).type, (yyvsp[(1) - (3)]).prim, (yyvsp[(3) - (3)]).prim, (yyvsp[(1) - (3)]).dim, (yyvsp[(3) - (3)]).dim); if(temp_type <= Int) {(yyval).prim = (yyvsp[(1) - (3)]).prim; (yyval).type = temp_type;} else {yyerror(); return 1;}}
    break;

  case 201:
#line 448 "./Parser/parser_main.y"
    {temp_type = compatibleCheckAdv((yyvsp[(1) - (3)]).type, (yyvsp[(3) - (3)]).type, (yyvsp[(1) - (3)]).prim, (yyvsp[(3) - (3)]).prim, (yyvsp[(1) - (3)]).dim, (yyvsp[(3) - (3)]).dim); if(temp_type <= Int) {(yyval).prim = (yyvsp[(1) - (3)]).prim; (yyval).type = temp_type;} else {yyerror(); return 1;}}
    break;

  case 202:
#line 452 "./Parser/parser_main.y"
    {fprintf(fp,"expression statement\n"); if(isDeclaration){(yyval).type = (yyvsp[(3) - (3)]).type; (yyval).str = (yyvsp[(1) - (3)]).str; (yyval).prim = (yyvsp[(3) - (3)]).prim; if(!(yyvsp[(3) - (3)]).prim){(yyval).dim = (yyvsp[(3) - (3)]).dim;} if((yyvsp[(3) - (3)]).type == Matrix){(yyval).rows = (yyvsp[(3) - (3)]).rows;} } else {struct OutputSymbolEntry* entry = getOutputSymbolEntry(&OutputSymbolTable,(yyvsp[(1) - (3)]).str,outputLevel,1); if(entry->type != (yyvsp[(3) - (3)]).type){yyerror(); return 1;}}}
    break;

  case 203:
#line 455 "./Parser/parser_main.y"
    {fprintf(fp,"Primitive datatype declaration statement\n"); if( ((yyvsp[(2) - (2)]).prim==false) || (((yyvsp[(1) - (2)]).type < COMPATIBLE) && ((yyvsp[(1) - (2)]).type < (yyvsp[(2) - (2)]).type)) || (((yyvsp[(1) - (2)]).type >= COMPATIBLE) && ((yyvsp[(1) - (2)]).type != (yyvsp[(2) - (2)]).type)) || getOutputSymbolEntry(&OutputSymbolTable,(yyvsp[(2) - (2)]).str,outputLevel,0) != NULL){yyerror(); return 1;} else {if((yyvsp[(2) - (2)]).type == Matrix) {insertInOutputTable(&OutputSymbolTable,(yyvsp[(2) - (2)]).str,outputLevel,(yyvsp[(2) - (2)]).type,true,(yyvsp[(2) - (2)]).rows,0,false);} else {insertInOutputTable(&OutputSymbolTable,(yyvsp[(2) - (2)]).str,outputLevel,(yyvsp[(2) - (2)]).type,true,0,0,false);}}}
    break;

  case 204:
#line 457 "./Parser/parser_main.y"
    {fprintf(fp,"List datatype declaration statement\n"); if( ((yyvsp[(2) - (2)]).prim==true) || (((yyvsp[(1) - (2)]).type < COMPATIBLE) && ((yyvsp[(1) - (2)]).type < (yyvsp[(2) - (2)]).type)) || (((yyvsp[(1) - (2)]).type >= COMPATIBLE) && ((yyvsp[(1) - (2)]).type != (yyvsp[(2) - (2)]).type)) || getOutputSymbolEntry(&OutputSymbolTable,(yyvsp[(2) - (2)]).str,outputLevel,0) != NULL){yyerror(); return 1;} else {if((yyvsp[(2) - (2)]).type == Matrix) {insertInOutputTable(&OutputSymbolTable,(yyvsp[(2) - (2)]).str,outputLevel,(yyvsp[(1) - (2)]).type,false,(yyvsp[(2) - (2)]).rows,(yyvsp[(2) - (2)]).dim,false);} else {insertInOutputTable(&OutputSymbolTable,(yyvsp[(2) - (2)]).str,outputLevel,(yyvsp[(1) - (2)]).type,false,0,(yyvsp[(2) - (2)]).dim,false);}}}
    break;

  case 205:
#line 461 "./Parser/parser_main.y"
    {fprintf(fp,"Echo statement\n");}
    break;

  case 208:
#line 469 "./Parser/parser_main.y"
    {fprintf(fp,"Save statement\n");}
    break;

  case 209:
#line 473 "./Parser/parser_main.y"
    {fprintf(fp,"Output section conditional statement begins\n");}
    break;

  case 210:
#line 473 "./Parser/parser_main.y"
    {fprintf(fp,"Output section conditional statement ends\n");}
    break;

  case 211:
#line 474 "./Parser/parser_main.y"
    {fprintf(fp,"For statement in output section\n");}
    break;

  case 212:
#line 475 "./Parser/parser_main.y"
    {fprintf(fp,"For - lex statement in output section\n");}
    break;

  case 213:
#line 476 "./Parser/parser_main.y"
    {fprintf(fp,"For - zip statement in output section\n");}
    break;

  case 214:
#line 477 "./Parser/parser_main.y"
    {fprintf(fp,"while statement in output section\n");}
    break;

  case 215:
#line 480 "./Parser/parser_main.y"
    {outputLevel++;}
    break;

  case 216:
#line 480 "./Parser/parser_main.y"
    {outputLevel--;}
    break;

  case 221:
#line 491 "./Parser/parser_main.y"
    {if(getOutputSymbolEntry(&OutputSymbolTable,(yyvsp[(2) - (2)]).str,outputLevel + 1,0) != NULL){yyerror(); return 1;} else insertInOutputTable(&OutputSymbolTable,(yyvsp[(2) - (2)]).str,outputLevel + 1,Int,true,0,0,true);}
    break;

  case 222:
#line 491 "./Parser/parser_main.y"
    {outputLevel++;}
    break;

  case 223:
#line 491 "./Parser/parser_main.y"
    {exitOutputSymbolScope(&OutputSymbolTable,outputLevel); outputLevel--;}
    break;

  case 224:
#line 494 "./Parser/parser_main.y"
    {if((yyvsp[(3) - (8)]).num != (yyvsp[(7) - (8)]).num){yyerror(); return 1;}}
    break;

  case 225:
#line 494 "./Parser/parser_main.y"
    {outputLevel++;}
    break;

  case 226:
#line 494 "./Parser/parser_main.y"
    {exitOutputSymbolScope(&OutputSymbolTable,outputLevel); outputLevel--;}
    break;

  case 227:
#line 497 "./Parser/parser_main.y"
    {if((yyvsp[(3) - (8)]).num != (yyvsp[(7) - (8)]).num){yyerror(); return 1;}}
    break;

  case 228:
#line 497 "./Parser/parser_main.y"
    {outputLevel++;}
    break;

  case 229:
#line 497 "./Parser/parser_main.y"
    {exitOutputSymbolScope(&OutputSymbolTable,outputLevel); outputLevel--;}
    break;

  case 230:
#line 500 "./Parser/parser_main.y"
    {outputLevel++;}
    break;

  case 231:
#line 500 "./Parser/parser_main.y"
    {exitOutputSymbolScope(&OutputSymbolTable,outputLevel); outputLevel--;}
    break;

  case 237:
#line 512 "./Parser/parser_main.y"
    {isDeclaration = false;}
    break;

  case 239:
#line 513 "./Parser/parser_main.y"
    {isDeclaration = true;}
    break;


/* Line 1267 of yacc.c.  */
#line 2887 "./exec/y.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
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

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 515 "./Parser/parser_main.y"


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
