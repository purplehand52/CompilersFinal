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
     GATE_DEF = 277,
     MEASURE = 278,
     CONDITION = 279,
     OTHERWISE = 280,
     BARRIER = 281,
     FOR = 282,
     FOR_LEX = 283,
     FOR_ZIP = 284,
     COMP = 285,
     TRUE = 286,
     FALSE = 287,
     EQUALITY = 288,
     AND = 289,
     OR = 290,
     WHILE = 291,
     ADD = 292,
     SUB = 293,
     DOT = 294,
     STD_DEV = 295,
     VAR = 296,
     AVG = 297,
     CONDENSE = 298,
     SUM = 299,
     COUT = 300,
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
#define GATE_DEF 277
#define MEASURE 278
#define CONDITION 279
#define OTHERWISE 280
#define BARRIER 281
#define FOR 282
#define FOR_LEX 283
#define FOR_ZIP 284
#define COMP 285
#define TRUE 286
#define FALSE 287
#define EQUALITY 288
#define AND 289
#define OR 290
#define WHILE 291
#define ADD 292
#define SUB 293
#define DOT 294
#define STD_DEV 295
#define VAR 296
#define AVG 297
#define CONDENSE 298
#define SUM 299
#define COUT 300
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
   FILE * fp,*out;
// comment
   int yylex();
   void yyerror(char* str);
   char * IntToString(int num);
   void printForLex(int num, int usage);
   void printForZip(int num, int usage);

   int classical_registers,quantum_registers,iterations,temp_type,indent;
   int * classical_states,classical_index=0,quantum_index=0;
   int isInBlock=0;
   int outputLevel = 0;
   bool isInOutput = false;
   bool isDeclaration = false;
   int isFirst = 1;

   struct List* head = NULL;
   struct List* id_list = NULL;
   struct List2* range_list = NULL;
   struct List3* cpx_list = NULL;
   struct List3* curr = NULL;
   struct List3* cpx_head = NULL;
   struct BlockTable* BlockSymbolTable = NULL;
   struct GateTable* GateSymbolTable = NULL;
   struct Complex* gateList = NULL;

   /* Output Section */
   struct OutputSymbolEntry* OutputSymbolTable = NULL;

   bool firstLetterCapital(char *str);
   struct OutputSymbolEntry* getOutputSymbolEntry(struct OutputSymbolEntry** Head, char* id, int level, int findFlag); // declaration
   void exitOutputSymbolScope(struct OutputSymbolEntry** Head, int level);
   int insertInGateTable(struct GateTable ** Head,char * data,struct cpx* arr);
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
#line 285 "y.tab.c"

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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
<<<<<<< HEAD
#define YYLAST   1177
=======
#define YYLAST   1212
>>>>>>> temp

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  83
/* YYNNTS -- Number of nonterminals.  */
<<<<<<< HEAD
#define YYNNTS  124
/* YYNRULES -- Number of rules.  */
#define YYNRULES  260
/* YYNRULES -- Number of states.  */
#define YYNSTATES  585
=======
#define YYNNTS  123
/* YYNRULES -- Number of rules.  */
#define YYNRULES  257
/* YYNRULES -- Number of states.  */
#define YYNSTATES  578
>>>>>>> temp

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
       0,     0,     3,     4,     5,     6,    13,    14,    24,    25,
      32,    33,    40,    55,    58,    60,    63,    65,    66,    73,
      80,    84,    86,    90,    92,    94,    95,    98,    99,   102,
     104,   109,   123,   127,   133,   137,   141,   143,   144,   147,
     150,   151,   152,   161,   163,   167,   171,   173,   174,   179,
     182,   186,   188,   189,   192,   194,   197,   198,   200,   202,
     204,   206,   207,   210,   212,   214,   216,   218,   220,   222,
     228,   234,   239,   244,   249,   253,   257,   258,   261,   265,
     267,   270,   275,   279,   281,   282,   285,   290,   292,   296,
     298,   301,   305,   307,   313,   316,   317,   318,   330,   331,
     341,   342,   343,   349,   350,   354,   358,   362,   366,   370,
     372,   374,   378,   382,   386,   390,   394,   398,   402,   406,
     410,   414,   418,   422,   426,   428,   430,   432,   434,   436,
     438,   442,   448,   452,   454,   458,   460,   461,   462,   474,
     475,   488,   489,   502,   503,   512,   514,   516,   518,   520,
     522,   524,   526,   528,   530,   532,   533,   539,   541,   543,
     545,   547,   549,   551,   557,   561,   565,   567,   571,   575,
     577,   579,   581,   587,   589,   591,   593,   595,   597,   599,
     601,   603,   605,   607,   609,   613,   617,   619,   626,   633,
<<<<<<< HEAD
     640,   645,   650,   657,   666,   671,   676,   680,   682,   684,
     686,   688,   693,   701,   712,   714,   718,   721,   725,   729,
     733,   737,   741,   745,   749,   753,   757,   761,   765,   769,
     773,   776,   779,   784,   788,   790,   794,   795,   798,   800,
     802,   804,   806,   807,   808,   820,   821,   831,   832,   833,
     839,   840,   841,   842,   854,   855,   856,   870,   871,   872,
     886,   887,   896,   899,   900,   902,   904,   906,   907,   910,
     911
=======
     640,   645,   650,   657,   662,   667,   669,   671,   673,   678,
     686,   697,   699,   703,   706,   710,   714,   718,   722,   726,
     730,   734,   738,   742,   746,   750,   754,   758,   761,   764,
     769,   773,   775,   779,   780,   783,   785,   787,   789,   791,
     792,   793,   805,   806,   816,   817,   818,   824,   825,   826,
     827,   839,   840,   841,   855,   856,   857,   871,   872,   881,
     884,   885,   887,   889,   891,   892,   895,   896
>>>>>>> temp
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
      84,     0,    -1,    -1,    -1,    -1,    85,    88,    86,    90,
      87,    92,    -1,    -1,    71,    16,    89,    94,    95,   108,
     101,    71,    17,    -1,    -1,    71,    12,    91,   119,    71,
<<<<<<< HEAD
      13,    -1,    -1,    71,    14,    93,   203,    71,    15,    -1,
=======
      13,    -1,    -1,    71,    14,    93,   202,    71,    15,    -1,
>>>>>>> temp
      72,     9,    10,    73,     4,    72,     9,    11,    73,     4,
      72,     5,    73,     4,    -1,    96,    97,    -1,    97,    -1,
      97,    96,    -1,    96,    -1,    -1,    72,     7,    10,     8,
      20,    98,    -1,    72,     7,    11,     8,    20,    99,    -1,
      98,    74,   170,    -1,   170,    -1,    99,    74,   100,    -1,
     100,    -1,     4,    -1,    -1,   102,   103,    -1,    -1,   103,
     104,    -1,   104,    -1,    22,     3,    73,   105,    -1,    75,
      75,   171,    74,   171,    76,    74,    75,   171,    74,   171,
      76,    76,    -1,    77,   106,    78,    -1,   106,    74,    79,
     107,    80,    -1,    79,   107,    80,    -1,   107,    74,   171,
      -1,   171,    -1,    -1,   109,   110,    -1,   111,   110,    -1,
      -1,    -1,    19,   118,   113,   115,   112,    75,   117,    76,
      -1,     3,    -1,    79,   114,    80,    -1,     3,    74,   114,
      -1,     3,    -1,    -1,    20,    79,   116,    80,    -1,    20,
     116,    -1,     3,    74,   116,    -1,     3,    -1,    -1,   121,
     117,    -1,     3,    -1,   119,   120,    -1,    -1,   121,    -1,
     135,    -1,   124,    -1,   134,    -1,    -1,   122,   136,    -1,
     149,    -1,   152,    -1,   154,    -1,   156,    -1,     4,    -1,
       3,    -1,   128,    18,   130,    20,   143,    -1,   128,     3,
     130,    20,   143,    -1,    18,   130,    20,   143,    -1,     3,
     130,    20,   143,    -1,   128,   118,   125,   126,    -1,   118,
     125,   126,    -1,    79,   127,    80,    -1,    -1,    20,   131,
      -1,   127,    74,   143,    -1,   143,    -1,   132,    81,    -1,
      79,   133,    80,    81,    -1,   129,    74,   123,    -1,   123,
      -1,    -1,    82,   143,    -1,    82,    79,   129,    80,    -1,
     123,    -1,    79,   127,    80,    -1,   123,    -1,    70,   123,
      -1,   133,    74,   132,    -1,   132,    -1,    23,    82,   123,
      20,   123,    -1,    71,    26,    -1,    -1,    -1,    24,    79,
     144,    80,   137,    77,   119,    78,   138,   139,   141,    -1,
      -1,   139,    25,    79,   144,    80,   140,    77,   119,    78,
      -1,    -1,    -1,    25,   142,    77,   119,    78,    -1,    -1,
     143,    61,   143,    -1,   143,    62,   143,    -1,   143,    63,
     143,    -1,   143,    64,   143,    -1,   143,    65,   143,    -1,
       3,    -1,     4,    -1,   144,    30,   144,    -1,   144,    33,
     144,    -1,   144,    34,   144,    -1,   144,    35,   144,    -1,
     144,    68,   144,    -1,   144,    67,   144,    -1,   144,    69,
     144,    -1,    79,   144,    80,    -1,   144,    61,   144,    -1,
     144,    62,   144,    -1,   144,    63,   144,    -1,   144,    64,
     144,    -1,   144,    65,   144,    -1,     3,    -1,     4,    -1,
      31,    -1,    32,    -1,     4,    -1,     3,    -1,   145,    82,
     145,    -1,   145,    82,   145,    82,   145,    -1,   146,    74,
     147,    -1,   146,    -1,     3,    74,   148,    -1,     3,    -1,
      -1,    -1,    27,     3,   150,    21,    79,   146,    80,   151,
      77,   119,    78,    -1,    -1,    28,    79,   148,    80,    21,
      79,   147,    80,   153,    77,   119,    78,    -1,    -1,    29,
      79,   148,    80,    21,    79,   147,    80,   155,    77,   119,
      78,    -1,    -1,    36,    79,   144,    80,   157,    77,   119,
      78,    -1,     3,    -1,    45,    -1,    46,    -1,    47,    -1,
      48,    -1,    49,    -1,    50,    -1,    51,    -1,    52,    -1,
      53,    -1,    -1,    55,    75,   161,   159,    76,    -1,    31,
      -1,    32,    -1,    56,    -1,     6,    -1,    57,    -1,     4,
      -1,    79,   163,    74,   163,    80,    -1,    75,   166,    76,
      -1,   166,    74,   167,    -1,   167,    -1,    75,   168,    76,
      -1,   168,    74,   169,    -1,   169,    -1,   164,    -1,   163,
      -1,    77,   171,    74,   171,    78,    -1,   164,    -1,   163,
      -1,   162,    -1,   164,    -1,   165,    -1,   170,    -1,     4,
      -1,     6,    -1,    56,    -1,    57,    -1,    50,    -1,    75,
     174,    76,    -1,   174,    74,   172,    -1,   172,    -1,    37,
<<<<<<< HEAD
      79,   177,    74,   177,    80,    -1,    38,    79,   177,    74,
     177,    80,    -1,    39,    79,   177,    74,   177,    80,    -1,
      40,    79,   177,    80,    -1,    41,    79,   177,    80,    -1,
      43,    79,   177,    74,     4,    80,    -1,    43,    79,   177,
      74,    79,   176,    80,    80,    -1,    44,    79,   177,    80,
      -1,    42,    79,   177,    80,    -1,   176,    74,   177,    -1,
     177,    -1,   172,    -1,   173,    -1,   158,    -1,   158,    75,
     177,    76,    -1,   158,    75,   177,    76,    75,   177,    76,
      -1,   158,    75,   177,    76,    75,   177,    76,    75,   177,
      76,    -1,   175,    -1,    79,   177,    80,    -1,    70,   177,
      -1,   177,    34,   177,    -1,   177,    35,   177,    -1,   177,
      30,   177,    -1,   177,    33,   177,    -1,   177,    63,   177,
      -1,   177,    64,   177,    -1,   177,    61,   177,    -1,   177,
      62,   177,    -1,   177,    66,   177,    -1,   177,    67,   177,
      -1,   177,    68,   177,    -1,   177,    69,   177,    -1,     3,
      73,   177,    -1,   159,   178,    -1,   160,   178,    -1,    59,
      79,   181,    80,    -1,   181,    74,   177,    -1,   177,    -1,
      71,    58,    50,    -1,    -1,   184,   185,    -1,   192,    -1,
     195,    -1,   198,    -1,   201,    -1,    -1,    -1,    24,    79,
     177,    80,    77,   186,   203,    78,   187,   188,   190,    -1,
      -1,   188,    25,    79,   177,    80,    77,   189,   203,    78,
      -1,    -1,    -1,    25,    77,   191,   203,    78,    -1,    -1,
      -1,    -1,    27,     3,   193,    21,    79,   146,    80,    77,
     194,   203,    78,    -1,    -1,    -1,    28,    79,   148,    80,
      21,    79,   147,    80,   196,    77,   197,   203,    78,    -1,
      -1,    -1,    29,    79,   148,    80,    21,    79,   147,    80,
     199,    77,   200,   203,    78,    -1,    -1,    36,    79,   177,
      80,    77,   202,   203,    78,    -1,   203,   204,    -1,    -1,
     183,    -1,   182,    -1,   180,    -1,    -1,   205,   178,    -1,
      -1,   206,   179,    -1
=======
      79,   176,    74,   176,    80,    -1,    38,    79,   176,    74,
     176,    80,    -1,    39,    79,   176,    74,   176,    80,    -1,
      40,    79,   176,    80,    -1,    41,    79,   176,    80,    -1,
      43,    79,   176,    74,     4,    80,    -1,    44,    79,   176,
      80,    -1,    42,    79,   176,    80,    -1,   172,    -1,   173,
      -1,   158,    -1,   158,    75,   176,    76,    -1,   158,    75,
     176,    76,    75,   176,    76,    -1,   158,    75,   176,    76,
      75,   176,    76,    75,   176,    76,    -1,   175,    -1,    79,
     176,    80,    -1,    70,   176,    -1,   176,    34,   176,    -1,
     176,    35,   176,    -1,   176,    30,   176,    -1,   176,    33,
     176,    -1,   176,    63,   176,    -1,   176,    64,   176,    -1,
     176,    61,   176,    -1,   176,    62,   176,    -1,   176,    66,
     176,    -1,   176,    67,   176,    -1,   176,    68,   176,    -1,
     176,    69,   176,    -1,     3,    73,   176,    -1,   159,   177,
      -1,   160,   177,    -1,    59,    79,   180,    80,    -1,   180,
      74,   176,    -1,   176,    -1,    71,    58,    50,    -1,    -1,
     183,   184,    -1,   191,    -1,   194,    -1,   197,    -1,   200,
      -1,    -1,    -1,    24,    79,   176,    80,    77,   185,   202,
      78,   186,   187,   189,    -1,    -1,   187,    25,    79,   176,
      80,    77,   188,   202,    78,    -1,    -1,    -1,    25,    77,
     190,   202,    78,    -1,    -1,    -1,    -1,    27,     3,   192,
      21,    79,   146,    80,    77,   193,   202,    78,    -1,    -1,
      -1,    28,    79,   148,    80,    21,    79,   147,    80,   195,
      77,   196,   202,    78,    -1,    -1,    -1,    29,    79,   148,
      80,    21,    79,   147,    80,   198,    77,   199,   202,    78,
      -1,    -1,    36,    79,   176,    80,    77,   201,   202,    78,
      -1,   202,   203,    -1,    -1,   182,    -1,   181,    -1,   179,
      -1,    -1,   204,   177,    -1,    -1,   205,   178,    -1
>>>>>>> temp
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    90,    90,   123,   144,    90,   170,   170,   173,   173,
     176,   176,   184,   202,   203,   205,   206,   207,   212,   218,
     224,   232,   239,   247,   253,   257,   257,   258,   261,   262,
     265,   279,   285,   288,   289,   291,   292,   295,   295,   298,
     299,   302,   302,   335,   336,   341,   342,   345,   346,   347,
     350,   351,   354,   355,   358,   371,   372,   375,   376,   378,
     379,   380,   380,   381,   382,   383,   384,   387,   396,   408,
     420,   431,   439,   451,   468,   481,   487,   488,   491,   498,
     506,   512,   520,   527,   535,   540,   545,   552,   553,   557,
     562,   569,   575,   583,   601,   607,   608,   607,   612,   612,
     614,   617,   617,   619,   622,   628,   634,   640,   646,   652,
     660,   672,   678,   684,   690,   696,   702,   708,   714,   719,
     725,   731,   737,   743,   749,   757,   762,   766,   773,   774,
     777,   778,   781,   789,   799,   814,   831,   839,   831,   847,
     847,   859,   859,   871,   871,   881,   882,   885,   886,   887,
     888,   889,   890,   891,   892,   895,   895,   902,   903,   906,
     907,   908,   909,   911,   914,   925,   940,   953,   956,   957,
     960,   961,   964,   967,   968,   971,   976,   980,   984,   985,
<<<<<<< HEAD
     986,   987,   988,   989,   992,  1006,  1030,  1041,  1058,  1075,
    1109,  1124,  1139,  1154,  1170,  1192,  1219,  1231,  1243,  1244,
    1252,  1282,  1325,  1370,  1406,  1411,  1417,  1429,  1443,  1456,
    1470,  1484,  1506,  1520,  1552,  1576,  1633,  1656,  1679,  1705,
    1725,  1742,  1760,  1764,  1780,  1799,  1803,  1803,  1804,  1805,
    1806,  1807,  1810,  1810,  1810,  1813,  1813,  1814,  1817,  1817,
    1818,  1821,  1826,  1821,  1830,  1836,  1830,  1841,  1847,  1841,
    1853,  1853,  1858,  1859,  1862,  1863,  1864,  1865,  1865,  1866,
    1866
=======
     986,   987,   988,   989,   992,  1007,  1031,  1042,  1067,  1092,
    1131,  1154,  1171,  1211,  1238,  1294,  1295,  1303,  1333,  1376,
    1421,  1457,  1462,  1468,  1480,  1494,  1507,  1521,  1535,  1576,
    1590,  1626,  1656,  1718,  1746,  1774,  1805,  1825,  1842,  1860,
    1864,  1880,  1899,  1903,  1903,  1904,  1905,  1906,  1907,  1910,
    1910,  1910,  1913,  1913,  1914,  1917,  1917,  1918,  1921,  1926,
    1921,  1930,  1936,  1930,  1941,  1947,  1941,  1953,  1953,  1958,
    1959,  1962,  1963,  1964,  1965,  1965,  1966,  1966
>>>>>>> temp
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
  "ARROW", "IN", "GATE_DEF", "MEASURE", "CONDITION", "OTHERWISE",
  "BARRIER", "FOR", "FOR_LEX", "FOR_ZIP", "COMP", "TRUE", "FALSE",
  "EQUALITY", "AND", "OR", "WHILE", "ADD", "SUB", "DOT", "STD_DEV", "VAR",
  "AVG", "CONDENSE", "SUM", "COUT", "INT", "UINT", "FLOAT", "COMPLEX",
  "STRING", "MATRIX", "STATE", "BOOL", "IMAG", "LIST", "DEC", "EXP",
  "SAVE", "ECHO", "RETURN", "'+'", "'-'", "'*'", "'/'", "'%'", "'@'",
  "'&'", "'^'", "'|'", "'!'", "'\\\\'", "'#'", "'='", "','", "'['", "']'",
  "'{'", "'}'", "'('", "')'", "'?'", "':'", "$accept", "prgm", "@1", "@2",
  "@3", "init_section", "@4", "main_section", "@5", "output_section", "@6",
  "mandatory_init", "set_states", "set_quantum_states",
  "set_classical_states", "quantum_state_list", "classical_state_list",
  "classical_state", "gate_defn_section", "@7", "gate_defn_list",
  "gate_defn", "rhs", "tuple_list2", "id_list", "block_defn_section", "@8",
  "block_defns_list", "block_defn", "@9", "params", "param_id_list",
  "target_params", "target_param_list", "block_body", "block_id",
  "main_stmt_list", "main_stmt", "stmts", "@10", "register", "call_stmt",
  "parameters", "optional", "register_list", "classic_control",
  "quantum_control_list", "quantum_control", "target", "control_expr",
  "control_expr_list", "measure_stmt", "barrier_stmt", "condition_stmt",
  "@11", "@12", "otherwise_list", "@13", "otherwise_final", "@14",
  "simple_expr", "expr", "value", "range", "range_list", "var_list",
  "for_stmt", "@15", "@16", "for_lex_stmt", "@17", "for_zip_stmt", "@18",
  "while_stmt", "@19", "out_id", "prim_type", "list_type", "@20",
  "bool_const", "num", "complex_const", "matrix_const", "row_list", "row",
  "comps", "compatible_const", "state_const", "temp", "prim_const",
<<<<<<< HEAD
  "vec_const", "vec_list", "calls", "uint_list", "out_rhs", "out_expr",
  "decl", "echo_stmt", "echo_list", "save_stmt", "out_control", "@21",
=======
  "vec_const", "vec_list", "calls", "out_rhs", "out_expr", "decl",
  "echo_stmt", "echo_list", "save_stmt", "out_control", "@21",
>>>>>>> temp
  "out_cond_stmt", "@22", "@23", "out_other_list", "@24",
  "out_other_final", "@25", "out_for_stmt", "@26", "@27",
  "out_for_lex_stmt", "@28", "@29", "out_for_zip_stmt", "@30", "@31",
  "out_while_stmt", "@32", "out_main", "out_stmt", "@33", "@34", 0
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
       0,    83,    85,    86,    87,    84,    89,    88,    91,    90,
      93,    92,    94,    95,    95,    95,    95,    95,    96,    97,
      98,    98,    99,    99,   100,   102,   101,   101,   103,   103,
     104,   105,   105,   106,   106,   107,   107,   109,   108,   110,
     110,   112,   111,   113,   113,   114,   114,   115,   115,   115,
     116,   116,   117,   117,   118,   119,   119,   120,   120,   121,
     121,   122,   121,   121,   121,   121,   121,   123,   123,   124,
     124,   124,   124,   124,   124,   125,   126,   126,   127,   127,
     128,   128,   129,   129,   130,   130,   130,   131,   131,   132,
     132,   133,   133,   134,   135,   137,   138,   136,   140,   139,
     139,   142,   141,   141,   143,   143,   143,   143,   143,   143,
     143,   144,   144,   144,   144,   144,   144,   144,   144,   144,
     144,   144,   144,   144,   144,   144,   144,   144,   145,   145,
     146,   146,   147,   147,   148,   148,   150,   151,   149,   153,
     152,   155,   154,   157,   156,   158,   158,   159,   159,   159,
     159,   159,   159,   159,   159,   161,   160,   162,   162,   163,
     163,   163,   163,   164,   165,   166,   166,   167,   168,   168,
     169,   169,   170,   171,   171,   172,   172,   172,   172,   172,
     172,   172,   172,   172,   173,   174,   174,   175,   175,   175,
<<<<<<< HEAD
     175,   175,   175,   175,   175,   175,   176,   176,   177,   177,
     177,   177,   177,   177,   177,   177,   177,   177,   177,   177,
     177,   177,   177,   177,   177,   177,   177,   177,   177,   178,
     179,   179,   180,   181,   181,   182,   184,   183,   183,   183,
     183,   183,   186,   187,   185,   189,   188,   188,   191,   190,
     190,   193,   194,   192,   196,   197,   195,   199,   200,   198,
     202,   201,   203,   203,   204,   204,   204,   205,   204,   206,
     204
=======
     175,   175,   175,   175,   175,   176,   176,   176,   176,   176,
     176,   176,   176,   176,   176,   176,   176,   176,   176,   176,
     176,   176,   176,   176,   176,   176,   177,   178,   178,   179,
     180,   180,   181,   183,   182,   182,   182,   182,   182,   185,
     186,   184,   188,   187,   187,   190,   189,   189,   192,   193,
     191,   195,   196,   194,   198,   199,   197,   201,   200,   202,
     202,   203,   203,   203,   204,   203,   205,   203
>>>>>>> temp
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     0,     0,     6,     0,     9,     0,     6,
       0,     6,    14,     2,     1,     2,     1,     0,     6,     6,
       3,     1,     3,     1,     1,     0,     2,     0,     2,     1,
       4,    13,     3,     5,     3,     3,     1,     0,     2,     2,
       0,     0,     8,     1,     3,     3,     1,     0,     4,     2,
       3,     1,     0,     2,     1,     2,     0,     1,     1,     1,
       1,     0,     2,     1,     1,     1,     1,     1,     1,     5,
       5,     4,     4,     4,     3,     3,     0,     2,     3,     1,
       2,     4,     3,     1,     0,     2,     4,     1,     3,     1,
       2,     3,     1,     5,     2,     0,     0,    11,     0,     9,
       0,     0,     5,     0,     3,     3,     3,     3,     3,     1,
       1,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     1,     1,     1,     1,     1,     1,
       3,     5,     3,     1,     3,     1,     0,     0,    11,     0,
      12,     0,    12,     0,     8,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     0,     5,     1,     1,     1,
       1,     1,     1,     5,     3,     3,     1,     3,     3,     1,
       1,     1,     5,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     3,     1,     6,     6,     6,
<<<<<<< HEAD
       4,     4,     6,     8,     4,     4,     3,     1,     1,     1,
       1,     4,     7,    10,     1,     3,     2,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       2,     2,     4,     3,     1,     3,     0,     2,     1,     1,
       1,     1,     0,     0,    11,     0,     9,     0,     0,     5,
       0,     0,     0,    11,     0,     0,    13,     0,     0,    13,
       0,     8,     2,     0,     1,     1,     1,     0,     2,     0,
       2
=======
       4,     4,     6,     4,     4,     1,     1,     1,     4,     7,
      10,     1,     3,     2,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     2,     2,     4,
       3,     1,     3,     0,     2,     1,     1,     1,     1,     0,
       0,    11,     0,     9,     0,     0,     5,     0,     0,     0,
      11,     0,     0,    13,     0,     0,    13,     0,     8,     2,
       0,     1,     1,     1,     0,     2,     0,     2
>>>>>>> temp
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       2,     0,     0,     1,     0,     3,     6,     0,     0,     0,
       4,     0,    17,     8,     0,     0,     0,    37,    16,    14,
      56,     0,     5,     0,     0,    25,    40,     0,    13,     0,
      15,    61,    10,     0,     0,     0,     0,     0,     0,    38,
      40,     0,     0,    54,    67,    84,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    55,    57,     0,    89,    59,
<<<<<<< HEAD
       0,     0,    60,    58,    63,    64,    65,    66,   253,     0,
       0,     0,     0,     0,    26,    29,    54,     0,    39,     0,
       0,     0,     0,   136,     0,     0,     0,    68,    90,     9,
      94,    92,     0,     0,    76,     0,    62,    54,    84,     0,
      80,   259,     0,     0,     0,     7,     0,    28,    43,     0,
      47,   109,   110,     0,    85,     0,     0,     0,     0,   135,
       0,     0,   124,   125,   126,   127,     0,     0,     0,     0,
       0,    79,     0,    74,     0,     0,     0,    76,     0,     0,
       0,     0,     0,     0,   256,   255,   254,     0,   228,   229,
     230,   231,   252,     0,     0,     0,     0,    18,    21,    24,
=======
       0,     0,    60,    58,    63,    64,    65,    66,   250,     0,
       0,     0,     0,     0,    26,    29,    54,     0,    39,     0,
       0,     0,     0,   136,     0,     0,     0,    68,    90,     9,
      94,    92,     0,     0,    76,     0,    62,    54,    84,     0,
      80,   256,     0,     0,     0,     7,     0,    28,    43,     0,
      47,   109,   110,     0,    85,     0,     0,     0,     0,   135,
       0,     0,   124,   125,   126,   127,     0,     0,     0,     0,
       0,    79,     0,    74,     0,     0,     0,    76,     0,     0,
       0,     0,     0,     0,   253,   252,   251,     0,   225,   226,
     227,   228,   249,     0,     0,     0,     0,    18,    21,    24,
>>>>>>> temp
      19,    23,     0,    46,     0,     0,    41,    83,     0,     0,
       0,     0,     0,     0,    72,    71,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   143,    91,    81,     0,    75,     0,
<<<<<<< HEAD
      87,    77,     0,     0,     0,    73,   241,     0,     0,     0,
       0,    11,     0,     0,   227,     0,   258,   147,   148,   149,
     150,   151,   152,   153,   154,     0,     0,     0,   260,     0,
=======
      87,    77,     0,     0,     0,    73,   238,     0,     0,     0,
       0,    11,     0,     0,   224,     0,   255,   147,   148,   149,
     150,   151,   152,   153,   154,     0,     0,     0,   257,     0,
>>>>>>> temp
     162,   160,   159,   161,     0,   174,   173,     0,     0,     0,
       0,     0,    30,     0,    44,    51,     0,    49,     0,     0,
      86,   104,   105,   106,   107,   108,    93,     0,   134,     0,
       0,   118,   111,   112,   113,   114,   119,   120,   121,   122,
     123,   116,   115,   117,     0,    78,     0,    95,    70,    69,
       0,     0,     0,   145,   179,   180,   157,   158,     0,     0,
       0,     0,     0,     0,     0,     0,   146,   183,   181,   182,
<<<<<<< HEAD
       0,     0,     0,   200,   175,   176,   177,   178,   198,   199,
     204,     0,   224,     0,   225,     0,     0,   155,   220,   221,
       0,     0,     0,    20,    22,     0,     0,     0,    45,     0,
       0,    52,    82,   129,   128,     0,     0,     0,     0,    56,
      88,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   206,     0,     0,   166,   186,     0,   179,
     180,   181,   182,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   222,
       0,   219,     0,     0,     0,     0,     0,     0,    36,     0,
      32,    50,    48,     0,    52,     0,   137,   133,     0,     0,
      61,    56,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   171,   170,     0,   169,     0,   164,
       0,   184,   205,     0,   209,   210,   207,   208,   213,   214,
     211,   212,   215,   216,   217,   218,   250,   223,     0,     0,
       0,     0,   172,     0,     0,    34,     0,    42,    53,   130,
       0,     0,   139,   141,     0,   144,    61,     0,     0,     0,
       0,     0,     0,   190,   191,   195,     0,   194,     0,   167,
     165,     0,   185,   201,   253,   232,   156,     0,   163,     0,
      35,     0,     0,    56,   132,     0,     0,    96,     0,     0,
       0,     0,     0,     0,     0,     0,   168,     0,   259,   253,
       0,     0,    33,   131,    61,    56,    56,   100,   242,   244,
     247,   187,   188,   189,   192,     0,   197,     0,     0,   251,
     259,    12,     0,   138,    61,    61,   103,   253,     0,     0,
       0,     0,   202,   233,     0,   140,   142,   101,    97,   259,
     245,   248,   196,   193,     0,   237,     0,     0,     0,   243,
     253,   253,     0,   240,     0,     0,    56,   259,   259,   203,
       0,   234,     0,    98,    61,   246,   249,   238,     0,     0,
       0,   102,   253,     0,    31,    56,   259,     0,    61,   239,
     235,    99,   253,   259,   236
=======
       0,     0,     0,   197,   175,   176,   177,   178,   195,   196,
     201,     0,   221,     0,   222,     0,     0,   155,   217,   218,
       0,     0,     0,    20,    22,     0,     0,     0,    45,     0,
       0,    52,    82,   129,   128,     0,     0,     0,     0,    56,
      88,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   203,     0,     0,   166,   186,     0,   179,
     180,   181,   182,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   219,
       0,   216,     0,     0,     0,     0,     0,     0,    36,     0,
      32,    50,    48,     0,    52,     0,   137,   133,     0,     0,
      61,    56,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   171,   170,     0,   169,     0,   164,
       0,   184,   202,     0,   206,   207,   204,   205,   210,   211,
     208,   209,   212,   213,   214,   215,   247,   220,     0,     0,
       0,     0,   172,     0,     0,    34,     0,    42,    53,   130,
       0,     0,   139,   141,     0,   144,    61,     0,     0,     0,
       0,     0,     0,   190,   191,   194,     0,   193,     0,   167,
     165,     0,   185,   198,   250,   229,   156,     0,   163,     0,
      35,     0,     0,    56,   132,     0,     0,    96,     0,     0,
       0,     0,     0,     0,     0,   168,     0,   256,   250,     0,
       0,    33,   131,    61,    56,    56,   100,   239,   241,   244,
     187,   188,   189,   192,     0,     0,   248,   256,    12,     0,
     138,    61,    61,   103,   250,     0,     0,   199,   230,     0,
     140,   142,   101,    97,   256,   242,   245,     0,   234,     0,
       0,     0,   240,   250,   250,     0,   237,     0,     0,    56,
     256,   256,   200,     0,   231,     0,    98,    61,   243,   246,
     235,     0,     0,     0,   102,   250,     0,    31,    56,   256,
       0,    61,   236,   232,    99,   250,   256,   233
>>>>>>> temp
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,     7,    14,     5,     8,    10,    20,    22,
      68,    12,    17,    18,    19,   157,   160,   161,    36,    37,
      74,    75,   242,   327,   387,    25,    26,    39,    40,   248,
     110,   164,   166,   247,   393,    54,    31,    55,    56,    57,
      58,    59,    94,   133,   130,    60,   168,    80,   201,    61,
<<<<<<< HEAD
      92,    62,    63,    96,   341,   507,   526,   570,   538,   548,
     131,   127,   335,   397,   398,   120,    64,   118,   450,    65,
     485,    66,   486,    67,   274,   303,   226,   227,   382,   304,
     235,   305,   306,   355,   356,   416,   417,   307,   388,   308,
     309,   358,   310,   515,   311,   216,   228,   144,   313,   145,
     146,   147,   214,   499,   545,   553,   582,   561,   572,   148,
     280,   527,   149,   528,   550,   150,   529,   551,   151,   474,
     101,   152,   153,   154
=======
      92,    62,    63,    96,   341,   506,   523,   563,   533,   541,
     131,   127,   335,   397,   398,   120,    64,   118,   450,    65,
     485,    66,   486,    67,   274,   303,   226,   227,   382,   304,
     235,   305,   306,   355,   356,   416,   417,   307,   388,   308,
     309,   358,   310,   311,   216,   228,   144,   313,   145,   146,
     147,   214,   498,   538,   546,   575,   554,   565,   148,   280,
     524,   149,   525,   543,   150,   526,   544,   151,   474,   101,
     152,   153,   154
>>>>>>> temp
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
<<<<<<< HEAD
#define YYPACT_NINF -447
static const yytype_int16 yypact[] =
{
    -447,    50,   -16,  -447,    71,  -447,  -447,    20,    97,   110,
    -447,   128,   136,  -447,    85,   206,   218,  -447,   190,   198,
    -447,   266,  -447,   209,    65,   214,   268,   283,  -447,   293,
    -447,   473,  -447,   302,   300,   308,   264,   319,   340,  -447,
     268,   335,   344,     3,  -447,   269,   276,   357,   285,   299,
     312,   292,    21,    16,   316,  -447,  -447,   353,  -447,  -447,
      34,   306,  -447,  -447,  -447,  -447,  -447,  -447,  -447,   324,
     377,   378,   385,   400,   319,  -447,  -447,    29,  -447,    22,
     386,   392,   292,  -447,   411,   411,    13,  -447,  -447,  -447,
    -447,  -447,   -31,   295,   395,   337,  -447,    31,   269,   316,
    -447,   410,   408,   342,   422,  -447,   355,  -447,  -447,   426,
     421,  -447,  -447,   292,   309,   295,   295,   425,   428,   368,
     370,   388,  -447,  -447,  -447,  -447,    13,   640,    16,   389,
     -26,   309,    27,  -447,    13,   446,   458,   395,   482,   415,
     416,   420,   424,    24,  -447,  -447,  -447,   463,  -447,  -447,
    -447,  -447,  -447,   501,  1112,   495,    23,   437,  -447,  -447,
     450,  -447,    91,   452,   440,    30,  -447,  -447,    -2,   295,
     295,   295,   295,   295,   309,   309,   292,   448,   411,   507,
     508,   664,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,  -447,  -447,  -447,   295,  -447,   295,
    -447,  -447,   684,   295,   295,  -447,  -447,   411,   411,   189,
     189,  -447,   480,   454,  -447,   464,  -447,  -447,  -447,  -447,
    -447,  -447,  -447,  -447,  -447,   459,   501,   501,  -447,   465,
    -447,  -447,  -447,  -447,    64,  -447,  -447,   467,   342,   422,
     470,   469,  -447,   426,  -447,   468,   547,  -447,   476,   292,
    -447,   148,   148,  -447,  -447,  -447,  -447,   301,  -447,   474,
     477,  -447,   600,    81,   520,  -447,   298,   298,   168,   168,
     168,    84,   120,   314,   481,   309,   117,  -447,   309,   309,
     536,   484,   486,  -447,  -447,  -447,  -447,  -447,   483,   488,
     490,   498,   499,   506,   512,   514,  -447,  -447,  -447,  -447,
     189,   504,   280,   505,  -447,  -447,  -447,  -447,  -447,  -447,
    -447,   704,  1088,   130,  -447,   189,   189,  -447,  -447,  -447,
     582,   521,    23,  -447,  -447,    23,    23,   122,  -447,   547,
     518,   489,  -447,  -447,  -447,   517,   523,   301,   301,  -447,
    -447,   529,   528,   587,   589,   189,   189,   189,   189,   189,
     189,   189,   189,   341,    32,   187,  -447,  -447,   191,   537,
     538,   539,   540,   724,   189,   189,   189,   189,   189,   189,
     189,   189,   189,   189,   189,   189,   189,   541,   189,  -447,
     744,  1088,    93,   544,    64,   542,   548,   135,  -447,   564,
    -447,  -447,  -447,   550,   489,   301,  -447,   549,   569,   570,
     274,  -447,   301,   574,   576,  1004,  1024,  1046,   764,   784,
     804,  1066,   824,    23,  -447,  -447,   195,  -447,   552,  -447,
     515,  -447,  -447,   944,   624,   188,   617,  -447,   184,   184,
    1108,  1108,   390,   207,   171,   341,  -447,  1088,   579,   585,
     657,   583,  -447,    23,    23,  -447,    23,  -447,  -447,   584,
     588,   301,  -447,  -447,   638,  -447,   311,   596,   301,   301,
     189,   189,   189,  -447,  -447,  -447,    14,  -447,    23,  -447,
    -447,   552,  -447,   603,  -447,  -447,  -447,   607,  -447,   605,
    -447,   164,   301,  -447,  -447,   608,   609,  -447,   610,   602,
     604,   844,   864,   884,   615,   189,  -447,   189,   427,  -447,
     696,   614,  -447,  -447,   365,  -447,  -447,  -447,  -447,  -447,
    -447,  -447,  -447,  -447,  -447,   180,  1088,   964,   648,  -447,
     546,  -447,   635,  -447,   382,   404,   686,  -447,   636,   639,
     189,   632,   646,  -447,    23,  -447,  -447,   643,  -447,   560,
    -447,  -447,  1088,  -447,   189,  -447,   641,    13,   647,  -447,
    -447,  -447,   984,   698,    23,   904,  -447,   573,   601,  -447,
     202,  -447,   654,  -447,   444,  -447,  -447,  -447,   189,   659,
     663,  -447,  -447,   924,  -447,  -447,   612,   665,   461,  -447,
    -447,  -447,  -447,   618,  -447
=======
#define YYPACT_NINF -455
static const yytype_int16 yypact[] =
{
    -455,    40,   -34,  -455,    27,  -455,  -455,   -21,    -4,    72,
    -455,    99,    61,  -455,    80,   156,   166,  -455,   117,   121,
    -455,   184,  -455,   139,   243,   137,   204,   220,  -455,   269,
    -455,   492,  -455,   228,   263,   272,   214,   265,   289,  -455,
     204,   285,   291,    28,  -455,   221,   234,   325,   256,   273,
     274,   152,    26,    32,   275,  -455,  -455,   324,  -455,  -455,
      31,   270,  -455,  -455,  -455,  -455,  -455,  -455,  -455,   284,
     342,   344,   348,   363,   265,  -455,  -455,     6,  -455,    22,
     358,   367,   152,  -455,   374,   374,    15,  -455,  -455,  -455,
    -455,  -455,   -29,   257,   368,   304,  -455,     4,   221,   275,
    -455,   643,   385,   314,   391,  -455,   323,  -455,  -455,   395,
     379,  -455,  -455,   152,    81,   257,   257,   383,   381,   333,
     328,   329,  -455,  -455,  -455,  -455,    15,   660,    32,   331,
      60,    81,    24,  -455,    15,   393,   401,   368,   426,   351,
     352,   353,   355,    18,  -455,  -455,  -455,   416,  -455,  -455,
    -455,  -455,  -455,   438,  1133,   432,    25,   370,  -455,  -455,
     371,  -455,   -22,   378,   376,     8,  -455,  -455,   141,   257,
     257,   257,   257,   257,    81,    81,   152,   375,   374,   436,
     440,   670,    15,    15,    15,    15,    15,    15,    15,    15,
      15,    15,    15,    15,  -455,  -455,  -455,   257,  -455,   257,
    -455,  -455,   711,   257,   257,  -455,  -455,   374,   374,   225,
     225,  -455,   415,   387,  -455,   396,  -455,  -455,  -455,  -455,
    -455,  -455,  -455,  -455,  -455,   398,   438,   438,  -455,   399,
    -455,  -455,  -455,  -455,    17,  -455,  -455,   403,   314,   391,
     405,   402,  -455,   395,  -455,   404,   467,  -455,   407,   152,
    -455,   242,   242,  -455,  -455,  -455,  -455,   306,  -455,   408,
     409,  -455,   337,   264,   451,  -455,    85,    85,   183,   183,
     183,    37,    44,   292,   414,    81,   145,  -455,    81,    81,
     472,   420,   421,  -455,  -455,  -455,  -455,  -455,   424,   428,
     429,   430,   433,   439,   446,   453,  -455,  -455,  -455,  -455,
     225,   498,   280,   458,  -455,  -455,  -455,  -455,  -455,  -455,
    -455,   721,  1096,   146,  -455,   225,   225,  -455,  -455,  -455,
     490,   425,    25,  -455,  -455,    25,    25,    48,  -455,   467,
     431,   513,  -455,  -455,  -455,   457,   464,   306,   306,  -455,
    -455,   461,   466,   525,   526,   225,   225,   225,   225,   225,
     225,   225,   225,   307,   135,     1,  -455,  -455,   168,   476,
     478,   485,   487,   731,   225,   225,   225,   225,   225,   225,
     225,   225,   225,   225,   225,   225,   225,   488,   225,  -455,
     772,  1096,  1144,   494,    17,   496,   506,   150,  -455,   491,
    -455,  -455,  -455,   511,   513,   306,  -455,   508,   509,   510,
     311,  -455,   306,   493,   512,  1027,  1036,  1078,   782,   792,
     833,  1087,   843,    25,  -455,  -455,   203,  -455,   519,  -455,
     547,  -455,  -455,   965,   489,   382,   560,  -455,  1103,  1103,
     167,   167,  1143,   169,   172,   307,  -455,  1096,   521,   520,
     595,   522,  -455,    25,    25,  -455,    25,  -455,  -455,   523,
     524,   306,  -455,  -455,   581,  -455,   340,   528,   306,   306,
     225,   225,   225,  -455,  -455,  -455,   606,  -455,    25,  -455,
    -455,   519,  -455,   544,  -455,  -455,  -455,   542,  -455,   549,
    -455,   165,   306,  -455,  -455,   543,   546,  -455,   552,   554,
     556,   853,   894,   904,   565,  -455,   225,   219,  -455,   633,
     566,  -455,  -455,   357,  -455,  -455,  -455,  -455,  -455,  -455,
    -455,  -455,  -455,  -455,   976,   589,  -455,   540,  -455,   573,
    -455,   397,   419,   624,  -455,   574,   575,   578,  -455,    25,
    -455,  -455,   576,  -455,   557,  -455,  -455,   225,  -455,   586,
      15,   584,  -455,  -455,  -455,  1016,   639,    25,   914,  -455,
     585,   603,  -455,   132,  -455,   592,  -455,   435,  -455,  -455,
    -455,   225,   593,   588,  -455,  -455,   955,  -455,  -455,   614,
     598,   456,  -455,  -455,  -455,  -455,   630,  -455
>>>>>>> temp
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
<<<<<<< HEAD
    -447,  -447,  -447,  -447,  -447,  -447,  -447,  -447,  -447,  -447,
    -447,  -447,  -447,   717,   723,  -447,  -447,   511,  -447,  -447,
    -447,   669,  -447,  -447,   310,  -447,  -447,   715,  -447,  -447,
    -447,   519,  -447,  -235,   366,   -14,  -332,  -447,  -317,  -447,
     -42,  -447,   662,   626,   577,  -447,  -447,   -24,  -447,   -18,
    -447,  -447,  -447,  -447,  -447,  -447,  -447,  -447,  -447,  -447,
     -74,  -126,  -382,  -255,  -334,   -75,  -447,  -447,  -447,  -447,
    -447,  -447,  -447,  -447,  -447,  -447,   387,  -447,  -447,  -447,
    -219,  -155,  -447,  -447,   362,  -447,   307,  -100,  -150,  -289,
    -447,  -447,  -447,  -447,  -188,   100,  -447,  -447,  -447,  -447,
    -447,  -447,  -447,  -447,  -447,  -447,  -447,  -447,  -447,  -447,
    -447,  -447,  -447,  -447,  -447,  -447,  -447,  -447,  -447,  -447,
    -446,  -447,  -447,  -447
=======
    -455,  -455,  -455,  -455,  -455,  -455,  -455,  -455,  -455,  -455,
    -455,  -455,  -455,   657,   659,  -455,  -455,   441,  -455,  -455,
    -455,   604,  -455,  -455,   236,  -455,  -455,   644,  -455,  -455,
    -455,   443,  -455,  -236,   293,    -6,  -309,  -455,  -314,  -455,
     -44,  -455,   597,   551,   484,  -455,  -455,    71,  -455,   -37,
    -455,  -455,  -455,  -455,  -455,  -455,  -455,  -455,  -455,  -455,
     -74,  -126,  -382,  -255,  -334,   -71,  -455,  -455,  -455,  -455,
    -455,  -455,  -455,  -455,  -455,  -455,   309,  -455,  -455,  -455,
    -219,  -155,  -455,  -455,   279,  -455,   230,  -100,  -150,  -289,
    -455,  -455,  -455,  -188,   119,  -455,  -455,  -455,  -455,  -455,
    -455,  -455,  -455,  -455,  -455,  -455,  -455,  -455,  -455,  -455,
    -455,  -455,  -455,  -455,  -455,  -455,  -455,  -455,  -455,  -454,
    -455,  -455,  -455
>>>>>>> temp
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
<<<<<<< HEAD
#define YYTABLE_NINF -258
static const yytype_int16 yytable[] =
{
     181,   236,   336,   158,   399,   114,   237,   400,   202,    88,
     121,   330,   357,   449,   394,   321,   122,   123,   494,    87,
      44,    81,   312,   -84,    77,   111,   112,   230,   498,   231,
      87,    44,   108,   245,    89,    91,   230,    97,   231,   211,
     117,   174,   175,   128,   124,   125,    99,    90,   197,   129,
       3,   -84,    98,   520,   198,     4,   262,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   230,   456,
     231,   167,   249,   135,   136,    34,    35,   394,   250,   232,
     233,   539,   212,   321,   -68,    79,    51,     6,   232,   233,
     200,     9,   126,   495,   391,   251,   252,   253,   254,   255,
     503,   113,   234,   258,   557,   558,   199,   413,   109,   246,
     195,   234,   353,    79,   363,   184,   185,   484,   184,   185,
     232,   233,    13,   275,   489,   490,   576,   380,   381,   278,
     279,   472,   281,   282,   256,   414,   583,    15,   323,   217,
     218,   219,   220,   221,   222,   223,   224,   457,   191,   192,
     193,   504,   192,   193,   184,   185,    21,   405,   406,   407,
     408,   409,   410,   411,   412,   441,   240,   236,   241,    11,
     236,   236,   385,   524,   525,   386,   423,   424,   425,   426,
     427,   428,   429,   430,   431,   432,   433,   434,   435,   193,
     437,   197,   283,   284,   414,   285,   389,   340,   182,   415,
     390,   183,   184,   185,   378,   367,   368,   332,    16,   444,
     379,   171,   172,   173,   365,   445,    23,   366,   367,   368,
     286,   287,   367,   368,   564,    24,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   191,   192,   193,   444,   297,
     376,   367,   368,   578,   502,   298,   299,   371,   372,   414,
     373,   374,   375,   376,   530,   374,   375,   376,   415,   300,
     531,   418,    27,   419,   301,   420,   156,   421,   302,   468,
      29,   469,   491,   492,   493,   375,   376,    43,    44,   567,
      32,   568,    33,   283,   359,   -27,   360,    38,   236,   236,
      41,   236,    45,   479,   480,    87,    44,    46,   111,   112,
      42,    47,    48,    49,   333,   334,    69,   516,    70,   517,
      50,   286,   287,   415,    43,    44,    71,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   318,   319,   182,    45,
     297,   183,   184,   185,    46,    72,   361,   362,    47,    48,
      49,    73,   542,    76,    51,   454,    35,    50,   184,   185,
     300,    79,   455,    53,    34,   301,   552,   156,    82,   302,
      83,   188,   189,   190,    84,   191,   192,   193,    43,    44,
     169,   170,   171,   172,   173,   367,   368,    95,    85,   236,
     573,    51,   454,    45,   546,    43,    44,   100,    46,   487,
      53,    86,    47,    48,    49,    93,   102,   103,   104,   236,
      45,    50,   105,   106,   562,    46,   115,    43,    44,    47,
      48,    49,   116,  -257,   119,   132,   134,   155,    50,   156,
     365,   555,    45,   366,   367,   368,   159,    46,   162,   163,
    -257,    47,    48,    49,  -226,    51,   454,   138,   139,   140,
      50,   165,   178,   523,    53,   176,   141,    43,    44,   177,
     179,  -226,    51,   454,   138,   139,   140,   374,   375,   376,
     535,    53,    45,   141,    43,    44,   203,    46,   180,   142,
     196,    47,    48,    49,    51,   454,    43,    44,   204,    45,
      50,   143,   536,    53,    46,   206,   142,   213,    47,    48,
      49,    45,    43,    44,   207,   208,    46,    50,   518,   209,
      47,    48,    49,   210,   215,   519,   229,    45,   284,    50,
     285,   238,    46,   -61,    51,   454,    47,    48,    49,   284,
     244,   285,   571,    53,   239,    50,   243,   257,   259,   260,
     314,    51,   454,   315,   317,   286,   287,   316,   320,   581,
      53,   322,   329,    51,    52,   325,   286,   287,   326,  -257,
     245,   331,    53,   337,   297,   185,   338,   342,   339,    51,
     298,   299,   345,  -257,   343,   297,   344,   346,    53,   347,
    -226,   298,   299,   138,   139,   140,  -257,   348,   349,   354,
     364,   156,   141,   234,  -226,   350,   383,   138,   139,   140,
     471,   351,   156,   352,   234,   384,   141,  -226,   392,   395,
     138,   139,   140,   396,  -257,   142,   401,   402,   403,   141,
     404,  -162,  -160,  -159,  -161,  -257,   440,   518,   436,   142,
     442,  -257,   443,   451,   533,  -226,   447,   413,   138,   139,
     140,   518,   142,   183,   184,   185,  -226,   141,   549,   138,
     139,   140,  -226,   446,   518,   138,   139,   140,   141,   452,
     453,   565,   368,   458,   141,   459,   475,   366,   367,   368,
     142,   476,   477,   478,    90,   483,   482,   191,   192,   193,
     182,   142,   518,   183,   184,   185,   488,   142,   497,   566,
     500,   501,   509,   518,   510,   505,   506,   508,   522,   518,
     579,   374,   375,   376,   182,   514,   584,   183,   184,   185,
     521,   186,   187,   188,   189,   190,   212,   191,   192,   193,
     534,   537,   543,   540,   182,   554,   541,   183,   184,   185,
     194,   544,   547,   560,   556,   186,   187,   188,   189,   190,
     569,   191,   192,   193,   365,   574,    30,   366,   367,   368,
     575,    28,   580,   107,   261,   186,   187,   188,   189,   190,
     324,   191,   192,   193,   365,    78,   481,   366,   367,   368,
     448,   137,   328,   205,   277,   369,   370,   371,   372,   439,
     373,   374,   375,   376,   365,   496,   276,   366,   367,   368,
     470,     0,     0,     0,   377,   369,   370,   371,   372,     0,
     373,   374,   375,   376,   365,     0,     0,   366,   367,   368,
       0,     0,     0,     0,   422,   369,   370,   371,   372,     0,
     373,   374,   375,   376,   365,     0,     0,   366,   367,   368,
       0,     0,     0,     0,   438,   369,   370,   371,   372,     0,
     373,   374,   375,   376,   365,     0,     0,   366,   367,   368,
       0,     0,     0,     0,   463,   369,   370,   371,   372,     0,
     373,   374,   375,   376,   365,     0,     0,   366,   367,   368,
       0,     0,     0,     0,   464,   369,   370,   371,   372,     0,
     373,   374,   375,   376,   365,     0,     0,   366,   367,   368,
       0,     0,     0,     0,   465,   369,   370,   371,   372,     0,
     373,   374,   375,   376,   365,     0,     0,   366,   367,   368,
       0,     0,     0,     0,   467,   369,   370,   371,   372,     0,
     373,   374,   375,   376,   365,     0,     0,   366,   367,   368,
       0,     0,     0,     0,   511,   369,   370,   371,   372,     0,
     373,   374,   375,   376,   182,     0,     0,   183,   184,   185,
       0,     0,     0,     0,   512,   369,   370,   371,   372,     0,
     373,   374,   375,   376,   365,     0,     0,   366,   367,   368,
       0,     0,     0,     0,   513,   186,   187,   188,   189,   190,
       0,   191,   192,   193,   365,     0,     0,   366,   367,   368,
       0,     0,     0,     0,   563,   369,   370,   371,   372,     0,
     373,   374,   375,   376,   365,     0,     0,   366,   367,   368,
       0,     0,     0,     0,   577,   369,   370,   371,   372,     0,
     373,   374,   375,   376,   365,     0,     0,   366,   367,   368,
     473,     0,     0,     0,     0,   369,   370,   371,   372,     0,
     373,   374,   375,   376,   365,     0,     0,   366,   367,   368,
     532,     0,     0,     0,     0,   369,   370,   371,   372,     0,
     373,   374,   375,   376,   365,     0,     0,   366,   367,   368,
     559,     0,     0,     0,     0,   369,   370,   371,   372,     0,
     373,   374,   375,   376,     0,     0,   365,     0,   460,   366,
     367,   368,     0,     0,     0,   369,   370,   371,   372,     0,
     373,   374,   375,   376,     0,     0,   365,     0,   461,   366,
     367,   368,     0,     0,     0,     0,     0,   369,   370,   371,
     372,     0,   373,   374,   375,   376,     0,     0,   365,     0,
     462,   366,   367,   368,     0,     0,     0,   369,   370,   371,
     372,     0,   373,   374,   375,   376,     0,     0,   365,     0,
     466,   366,   367,   368,     0,     0,     0,     0,     0,   369,
     370,   371,   372,     0,   373,   374,   375,   376,   217,   218,
     219,   220,   221,   222,   223,   224,     0,   225,     0,     0,
       0,     0,     0,     0,   373,   374,   375,   376
=======
#define YYTABLE_NINF -255
static const yytype_int16 yytable[] =
{
     181,   236,   336,   158,   399,   114,   237,    88,   202,   108,
     330,   245,   357,   449,   121,   321,    91,   394,   122,   123,
     497,   230,   312,   231,   -84,   111,   112,    87,    44,   230,
     400,   231,    77,   211,    97,    87,    44,     4,   117,    89,
       3,   174,   175,     6,   517,   128,   124,   125,   -84,    98,
       9,   129,    90,   240,    99,   241,   262,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,    11,   167,
     534,   184,   185,   232,   233,   418,   212,   419,   184,   185,
     394,   232,   233,   321,    13,   109,    79,   246,   200,   550,
     551,   195,   456,   391,   126,   251,   252,   253,   254,   255,
     502,   113,    51,   199,   234,   192,   193,   258,    15,   -68,
      79,   569,   353,   193,   363,   182,    81,   484,   183,   184,
     185,   576,   389,   275,   489,   490,   390,   380,   381,   278,
     279,   472,   256,    16,   197,   414,   281,   282,   323,   230,
     198,   231,   169,   170,   171,   172,   173,   457,   188,   189,
     190,    21,   191,   192,   193,    87,    44,   405,   406,   407,
     408,   409,   410,   411,   412,   441,    23,   236,   135,   136,
     236,   236,   385,    24,   503,   386,   423,   424,   425,   426,
     427,   428,   429,   430,   431,   432,   433,   434,   435,    27,
     437,   232,   233,    29,   414,   521,   522,   365,    32,   415,
     366,   367,   368,   367,   368,   332,   367,   368,   -27,   560,
     413,   561,    33,   182,   234,   249,   183,   184,   185,   197,
     378,   250,  -254,    38,   444,   340,   379,    41,   283,   284,
     445,   285,    69,   373,   374,   375,   376,   375,   376,   444,
     557,   376,   420,  -223,   421,   501,   138,   139,   140,   414,
     191,   192,   193,    34,    35,   141,   286,   287,   415,   571,
     111,   112,   288,   289,   290,   291,   292,   293,   294,   295,
     296,    70,   491,   492,   493,   297,    42,   468,   142,   469,
      71,   298,   299,   283,   359,    72,   360,    73,   236,   236,
     515,   236,    76,   479,   480,   300,    35,   516,   184,   185,
     301,    34,   156,    79,   302,   171,   172,   173,   514,   333,
     334,   286,   287,   415,    43,    44,    82,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   184,   185,    83,    45,
     297,   191,   192,   193,    46,    84,   361,   362,    47,    48,
      49,   367,   368,    43,    44,   318,   319,    50,    95,   545,
     300,   100,    85,    86,    93,   301,   102,   156,    45,   302,
      43,    44,   103,    46,   104,   105,   106,    47,    48,    49,
     183,   184,   185,   566,   236,    45,    50,   119,   115,   539,
      46,    51,   454,   134,    47,    48,    49,   116,   132,   455,
      53,   156,   236,    50,   155,   159,   162,   555,   163,   165,
      43,    44,   177,   176,   191,   192,   193,   178,   179,   180,
      51,   454,   196,   203,   548,    45,   367,   368,   487,    53,
      46,   204,    43,    44,    47,    48,    49,    51,   454,   206,
     207,   208,   209,    50,   210,   520,    53,    45,    43,    44,
     213,   215,    46,   229,   238,   239,    47,    48,    49,   374,
     375,   376,   243,    45,   257,    50,   244,   259,    46,    43,
      44,   260,    47,    48,    49,   314,   315,    51,   454,   316,
     245,    50,   320,   317,    45,   530,    53,   322,   329,    46,
     325,   326,   331,    47,    48,    49,   185,   337,   338,    51,
     454,   339,    50,   342,   383,    43,    44,   531,    53,   384,
     343,   344,   284,   345,   285,    51,   454,   346,   347,   348,
      45,   392,   349,   564,    53,    46,    43,    44,   350,    47,
      48,    49,   366,   367,   368,   351,    51,   454,    50,   286,
     287,    45,   352,   364,   574,    53,    46,   -61,   401,   395,
      47,    48,    49,  -254,   396,   402,   403,   404,   297,    50,
    -162,   284,  -160,   285,   298,   299,   374,   375,   376,  -159,
    -254,  -161,    51,    52,  -223,   436,   440,   138,   139,   140,
     446,    53,   458,   354,   442,   156,   141,   234,   286,   287,
     443,  -223,   451,    51,   138,   139,   140,   447,  -254,   452,
     453,   459,    53,   141,   413,   368,   476,   297,   475,   142,
     477,   483,   478,   298,   299,   482,  -254,    90,   488,  -223,
     494,   515,   138,   139,   140,   499,   142,  -254,   528,   496,
     504,   141,   471,   505,   156,   500,   234,  -223,   515,   507,
     138,   139,   140,  -254,   508,   542,   509,   518,  -223,   141,
     519,   138,   139,   140,   142,   513,  -254,   212,   529,   532,
     141,   535,   536,   537,  -223,   540,   515,   138,   139,   140,
     547,   549,   142,   558,   553,   568,   141,  -223,   562,   567,
     138,   139,   140,   142,   515,   573,    30,    28,   107,   141,
     324,   559,   481,   276,    78,   515,   328,   448,   205,   142,
     182,   439,   572,   183,   184,   185,   137,   470,   495,     0,
     182,   515,   142,   183,   184,   185,     0,     0,   577,     0,
       0,     0,     0,     0,   143,     0,     0,     0,     0,     0,
       0,   186,   187,   188,   189,   190,     0,   191,   192,   193,
       0,   186,   187,   188,   189,   190,     0,   191,   192,   193,
     194,   182,     0,     0,   183,   184,   185,     0,     0,     0,
     261,   365,     0,     0,   366,   367,   368,     0,     0,     0,
       0,   365,     0,     0,   366,   367,   368,     0,     0,     0,
       0,     0,   186,   187,   188,   189,   190,     0,   191,   192,
     193,     0,   369,   370,   371,   372,     0,   373,   374,   375,
     376,   277,   369,   370,   371,   372,     0,   373,   374,   375,
     376,   377,   365,     0,     0,   366,   367,   368,     0,     0,
       0,   422,   365,     0,     0,   366,   367,   368,     0,     0,
       0,     0,   365,     0,     0,   366,   367,   368,     0,     0,
       0,     0,     0,   369,   370,   371,   372,     0,   373,   374,
     375,   376,     0,   369,   370,   371,   372,     0,   373,   374,
     375,   376,   438,   369,   370,   371,   372,     0,   373,   374,
     375,   376,   463,   365,     0,     0,   366,   367,   368,     0,
       0,     0,   464,   365,     0,     0,   366,   367,   368,     0,
       0,     0,     0,   365,     0,     0,   366,   367,   368,     0,
       0,     0,     0,     0,   369,   370,   371,   372,     0,   373,
     374,   375,   376,     0,   369,   370,   371,   372,     0,   373,
     374,   375,   376,   465,   369,   370,   371,   372,     0,   373,
     374,   375,   376,   467,   365,     0,     0,   366,   367,   368,
       0,     0,     0,   510,   365,     0,     0,   366,   367,   368,
       0,     0,     0,     0,   182,     0,     0,   183,   184,   185,
       0,     0,     0,     0,     0,   369,   370,   371,   372,     0,
     373,   374,   375,   376,     0,   369,   370,   371,   372,     0,
     373,   374,   375,   376,   511,   186,   187,   188,   189,   190,
       0,   191,   192,   193,   512,   365,     0,     0,   366,   367,
     368,     0,     0,     0,   556,   365,     0,     0,   366,   367,
     368,     0,     0,     0,     0,     0,   365,     0,     0,   366,
     367,   368,     0,     0,     0,     0,   369,   370,   371,   372,
       0,   373,   374,   375,   376,     0,   369,   370,   371,   372,
       0,   373,   374,   375,   376,   570,     0,   369,   370,   371,
     372,   473,   373,   374,   375,   376,   365,     0,     0,   366,
     367,   368,   527,     0,     0,     0,     0,   365,     0,     0,
     366,   367,   368,     0,     0,     0,   365,     0,     0,   366,
     367,   368,     0,     0,     0,     0,     0,   369,   370,   371,
     372,     0,   373,   374,   375,   376,     0,     0,   369,   370,
     371,   372,   552,   373,   374,   375,   376,   369,   370,   371,
     372,   460,   373,   374,   375,   376,     0,     0,   365,     0,
     461,   366,   367,   368,     0,     0,     0,   365,     0,     0,
     366,   367,   368,     0,     0,     0,   365,     0,     0,   366,
     367,   368,     0,   365,     0,     0,   366,   367,   368,   369,
     370,   371,   372,     0,   373,   374,   375,   376,   369,   370,
     371,   372,   462,   373,   374,   375,   376,   369,   370,   371,
     372,   466,   373,   374,   375,   376,   371,   372,     0,   373,
     374,   375,   376,   365,     0,     0,   366,   367,   368,   217,
     218,   219,   220,   221,   222,   223,   224,     0,   225,     0,
     217,   218,   219,   220,   221,   222,   223,   224,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     374,   375,   376
>>>>>>> temp
};

static const yytype_int16 yycheck[] =
{
<<<<<<< HEAD
     126,   156,   257,   103,   338,    79,   156,   339,   134,    51,
      85,   246,   301,   395,   331,   234,     3,     4,     4,     3,
       4,    45,   210,    20,    38,     3,     4,     4,   474,     6,
       3,     4,     3,     3,    13,    53,     4,     3,     6,    15,
      82,   115,   116,    74,    31,    32,    60,    26,    74,    80,
       0,    20,    18,   499,    80,    71,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,     4,   401,
       6,   113,    74,    97,    98,    10,    11,   394,    80,    56,
      57,   527,    58,   302,    81,    82,    70,    16,    56,    57,
     132,    71,    79,    79,   329,   169,   170,   171,   172,   173,
     482,    79,    79,   178,   550,   551,    79,    75,    79,    79,
     128,    79,   300,    82,   302,    34,    35,   451,    34,    35,
      56,    57,    12,   197,   458,   459,   572,   315,   316,   203,
     204,   420,   207,   208,   176,   354,   582,     9,   238,    46,
      47,    48,    49,    50,    51,    52,    53,   402,    67,    68,
      69,   483,    68,    69,    34,    35,    71,   345,   346,   347,
     348,   349,   350,   351,   352,   384,    75,   322,    77,    72,
     325,   326,   322,   505,   506,   325,   364,   365,   366,   367,
     368,   369,   370,   371,   372,   373,   374,   375,   376,    69,
     378,    74,     3,     4,   413,     6,    74,    80,    30,   354,
      78,    33,    34,    35,    74,    34,    35,   249,    72,    74,
      80,    63,    64,    65,    30,    80,    10,    33,    34,    35,
      31,    32,    34,    35,   556,     7,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    67,    68,    69,    74,    50,
      69,    34,    35,   575,    80,    56,    57,    63,    64,   468,
      66,    67,    68,    69,    74,    67,    68,    69,   413,    70,
      80,    74,    72,    76,    75,    74,    77,    76,    79,    74,
      72,    76,   460,   461,   462,    68,    69,     3,     4,    77,
      14,    79,    73,     3,     4,    71,     6,    19,   443,   444,
       7,   446,    18,   443,   444,     3,     4,    23,     3,     4,
       7,    27,    28,    29,     3,     4,     4,   495,     8,   497,
      36,    31,    32,   468,     3,     4,     8,    37,    38,    39,
      40,    41,    42,    43,    44,    45,   226,   227,    30,    18,
      50,    33,    34,    35,    23,    71,    56,    57,    27,    28,
      29,    22,   530,     3,    70,    71,    11,    36,    34,    35,
      70,    82,    78,    79,    10,    75,   544,    77,    82,    79,
       3,    63,    64,    65,    79,    67,    68,    69,     3,     4,
      61,    62,    63,    64,    65,    34,    35,    24,    79,   534,
     568,    70,    71,    18,   534,     3,     4,    81,    23,    78,
      79,    79,    27,    28,    29,    79,    72,    20,    20,   554,
      18,    36,    17,     3,   554,    23,    20,     3,     4,    27,
      28,    29,    20,     3,     3,    20,    79,     9,    36,    77,
      30,   547,    18,    33,    34,    35,     4,    23,    73,     3,
       3,    27,    28,    29,    24,    70,    71,    27,    28,    29,
      36,    20,    74,    78,    79,    20,    36,     3,     4,    21,
      80,    24,    70,    71,    27,    28,    29,    67,    68,    69,
      78,    79,    18,    36,     3,     4,    20,    23,    80,    59,
      81,    27,    28,    29,    70,    71,     3,     4,    20,    18,
      36,    71,    78,    79,    23,     3,    59,    24,    27,    28,
      29,    18,     3,     4,    79,    79,    23,    36,    71,    79,
      27,    28,    29,    79,     3,    78,    11,    18,     4,    36,
       6,    74,    23,    24,    70,    71,    27,    28,    29,     4,
      80,     6,    78,    79,    74,    36,    74,    79,    21,    21,
      50,    70,    71,    79,    75,    31,    32,    73,    73,    78,
      79,    74,    74,    70,    71,    75,    31,    32,    79,     3,
       3,    75,    79,    79,    50,    35,    79,    21,    77,    70,
      56,    57,    79,     3,    80,    50,    80,    79,    79,    79,
      24,    56,    57,    27,    28,    29,     3,    79,    79,    75,
      75,    77,    36,    79,    24,    79,     4,    27,    28,    29,
      75,    79,    77,    79,    79,    74,    36,    24,    80,    82,
      27,    28,    29,    80,     3,    59,    77,    79,    21,    36,
      21,    74,    74,    74,    74,     3,    72,    71,    77,    59,
      78,     3,    74,    74,    78,    24,    76,    75,    27,    28,
      29,    71,    59,    33,    34,    35,    24,    36,    78,    27,
      28,    29,    24,    79,    71,    27,    28,    29,    36,    80,
      80,    78,    35,    79,    36,    79,    77,    33,    34,    35,
      59,    76,     5,    80,    26,    77,    82,    67,    68,    69,
      30,    59,    71,    33,    34,    35,    80,    59,    75,    78,
      73,    76,    80,    71,    80,    77,    77,    77,    74,    71,
      78,    67,    68,    69,    30,    80,    78,    33,    34,    35,
       4,    61,    62,    63,    64,    65,    58,    67,    68,    69,
      75,    25,    80,    77,    30,    74,    77,    33,    34,    35,
      80,    75,    79,    25,    77,    61,    62,    63,    64,    65,
      76,    67,    68,    69,    30,    76,    19,    33,    34,    35,
      77,    18,    77,    74,    80,    61,    62,    63,    64,    65,
     239,    67,    68,    69,    30,    40,   446,    33,    34,    35,
     394,    99,   243,   137,    80,    61,    62,    63,    64,   382,
      66,    67,    68,    69,    30,   468,   199,    33,    34,    35,
     418,    -1,    -1,    -1,    80,    61,    62,    63,    64,    -1,
      66,    67,    68,    69,    30,    -1,    -1,    33,    34,    35,
      -1,    -1,    -1,    -1,    80,    61,    62,    63,    64,    -1,
      66,    67,    68,    69,    30,    -1,    -1,    33,    34,    35,
      -1,    -1,    -1,    -1,    80,    61,    62,    63,    64,    -1,
      66,    67,    68,    69,    30,    -1,    -1,    33,    34,    35,
      -1,    -1,    -1,    -1,    80,    61,    62,    63,    64,    -1,
      66,    67,    68,    69,    30,    -1,    -1,    33,    34,    35,
      -1,    -1,    -1,    -1,    80,    61,    62,    63,    64,    -1,
      66,    67,    68,    69,    30,    -1,    -1,    33,    34,    35,
      -1,    -1,    -1,    -1,    80,    61,    62,    63,    64,    -1,
      66,    67,    68,    69,    30,    -1,    -1,    33,    34,    35,
      -1,    -1,    -1,    -1,    80,    61,    62,    63,    64,    -1,
      66,    67,    68,    69,    30,    -1,    -1,    33,    34,    35,
      -1,    -1,    -1,    -1,    80,    61,    62,    63,    64,    -1,
      66,    67,    68,    69,    30,    -1,    -1,    33,    34,    35,
      -1,    -1,    -1,    -1,    80,    61,    62,    63,    64,    -1,
      66,    67,    68,    69,    30,    -1,    -1,    33,    34,    35,
      -1,    -1,    -1,    -1,    80,    61,    62,    63,    64,    65,
      -1,    67,    68,    69,    30,    -1,    -1,    33,    34,    35,
      -1,    -1,    -1,    -1,    80,    61,    62,    63,    64,    -1,
      66,    67,    68,    69,    30,    -1,    -1,    33,    34,    35,
      -1,    -1,    -1,    -1,    80,    61,    62,    63,    64,    -1,
      66,    67,    68,    69,    30,    -1,    -1,    33,    34,    35,
      76,    -1,    -1,    -1,    -1,    61,    62,    63,    64,    -1,
      66,    67,    68,    69,    30,    -1,    -1,    33,    34,    35,
      76,    -1,    -1,    -1,    -1,    61,    62,    63,    64,    -1,
      66,    67,    68,    69,    30,    -1,    -1,    33,    34,    35,
      76,    -1,    -1,    -1,    -1,    61,    62,    63,    64,    -1,
      66,    67,    68,    69,    -1,    -1,    30,    -1,    74,    33,
      34,    35,    -1,    -1,    -1,    61,    62,    63,    64,    -1,
      66,    67,    68,    69,    -1,    -1,    30,    -1,    74,    33,
      34,    35,    -1,    -1,    -1,    -1,    -1,    61,    62,    63,
      64,    -1,    66,    67,    68,    69,    -1,    -1,    30,    -1,
      74,    33,    34,    35,    -1,    -1,    -1,    61,    62,    63,
      64,    -1,    66,    67,    68,    69,    -1,    -1,    30,    -1,
      74,    33,    34,    35,    -1,    -1,    -1,    -1,    -1,    61,
      62,    63,    64,    -1,    66,    67,    68,    69,    46,    47,
      48,    49,    50,    51,    52,    53,    -1,    55,    -1,    -1,
      -1,    -1,    -1,    -1,    66,    67,    68,    69
=======
     126,   156,   257,   103,   338,    79,   156,    51,   134,     3,
     246,     3,   301,   395,    85,   234,    53,   331,     3,     4,
     474,     4,   210,     6,    20,     3,     4,     3,     4,     4,
     339,     6,    38,    15,     3,     3,     4,    71,    82,    13,
       0,   115,   116,    16,   498,    74,    31,    32,    20,    18,
      71,    80,    26,    75,    60,    77,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,    72,   113,
     524,    34,    35,    56,    57,    74,    58,    76,    34,    35,
     394,    56,    57,   302,    12,    79,    82,    79,   132,   543,
     544,   128,   401,   329,    79,   169,   170,   171,   172,   173,
     482,    79,    70,    79,    79,    68,    69,   178,     9,    81,
      82,   565,   300,    69,   302,    30,    45,   451,    33,    34,
      35,   575,    74,   197,   458,   459,    78,   315,   316,   203,
     204,   420,   176,    72,    74,   354,   207,   208,   238,     4,
      80,     6,    61,    62,    63,    64,    65,   402,    63,    64,
      65,    71,    67,    68,    69,     3,     4,   345,   346,   347,
     348,   349,   350,   351,   352,   384,    10,   322,    97,    98,
     325,   326,   322,     7,   483,   325,   364,   365,   366,   367,
     368,   369,   370,   371,   372,   373,   374,   375,   376,    72,
     378,    56,    57,    72,   413,   504,   505,    30,    14,   354,
      33,    34,    35,    34,    35,   249,    34,    35,    71,    77,
      75,    79,    73,    30,    79,    74,    33,    34,    35,    74,
      74,    80,     3,    19,    74,    80,    80,     7,     3,     4,
      80,     6,     4,    66,    67,    68,    69,    68,    69,    74,
     549,    69,    74,    24,    76,    80,    27,    28,    29,   468,
      67,    68,    69,    10,    11,    36,    31,    32,   413,   568,
       3,     4,    37,    38,    39,    40,    41,    42,    43,    44,
      45,     8,   460,   461,   462,    50,     7,    74,    59,    76,
       8,    56,    57,     3,     4,    71,     6,    22,   443,   444,
      71,   446,     3,   443,   444,    70,    11,    78,    34,    35,
      75,    10,    77,    82,    79,    63,    64,    65,   496,     3,
       4,    31,    32,   468,     3,     4,    82,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    34,    35,     3,    18,
      50,    67,    68,    69,    23,    79,    56,    57,    27,    28,
      29,    34,    35,     3,     4,   226,   227,    36,    24,   537,
      70,    81,    79,    79,    79,    75,    72,    77,    18,    79,
       3,     4,    20,    23,    20,    17,     3,    27,    28,    29,
      33,    34,    35,   561,   529,    18,    36,     3,    20,   529,
      23,    70,    71,    79,    27,    28,    29,    20,    20,    78,
      79,    77,   547,    36,     9,     4,    73,   547,     3,    20,
       3,     4,    21,    20,    67,    68,    69,    74,    80,    80,
      70,    71,    81,    20,   540,    18,    34,    35,    78,    79,
      23,    20,     3,     4,    27,    28,    29,    70,    71,     3,
      79,    79,    79,    36,    79,    78,    79,    18,     3,     4,
      24,     3,    23,    11,    74,    74,    27,    28,    29,    67,
      68,    69,    74,    18,    79,    36,    80,    21,    23,     3,
       4,    21,    27,    28,    29,    50,    79,    70,    71,    73,
       3,    36,    73,    75,    18,    78,    79,    74,    74,    23,
      75,    79,    75,    27,    28,    29,    35,    79,    79,    70,
      71,    77,    36,    21,     4,     3,     4,    78,    79,    74,
      80,    80,     4,    79,     6,    70,    71,    79,    79,    79,
      18,    80,    79,    78,    79,    23,     3,     4,    79,    27,
      28,    29,    33,    34,    35,    79,    70,    71,    36,    31,
      32,    18,    79,    75,    78,    79,    23,    24,    77,    82,
      27,    28,    29,     3,    80,    79,    21,    21,    50,    36,
      74,     4,    74,     6,    56,    57,    67,    68,    69,    74,
       3,    74,    70,    71,    24,    77,    72,    27,    28,    29,
      79,    79,    79,    75,    78,    77,    36,    79,    31,    32,
      74,    24,    74,    70,    27,    28,    29,    76,     3,    80,
      80,    79,    79,    36,    75,    35,    76,    50,    77,    59,
       5,    77,    80,    56,    57,    82,     3,    26,    80,    24,
       4,    71,    27,    28,    29,    73,    59,     3,    78,    75,
      77,    36,    75,    77,    77,    76,    79,    24,    71,    77,
      27,    28,    29,     3,    80,    78,    80,     4,    24,    36,
      74,    27,    28,    29,    59,    80,     3,    58,    75,    25,
      36,    77,    77,    75,    24,    79,    71,    27,    28,    29,
      74,    77,    59,    78,    25,    77,    36,    24,    76,    76,
      27,    28,    29,    59,    71,    77,    19,    18,    74,    36,
     239,    78,   446,   199,    40,    71,   243,   394,   137,    59,
      30,   382,    78,    33,    34,    35,    99,   418,   468,    -1,
      30,    71,    59,    33,    34,    35,    -1,    -1,    78,    -1,
      -1,    -1,    -1,    -1,    71,    -1,    -1,    -1,    -1,    -1,
      -1,    61,    62,    63,    64,    65,    -1,    67,    68,    69,
      -1,    61,    62,    63,    64,    65,    -1,    67,    68,    69,
      80,    30,    -1,    -1,    33,    34,    35,    -1,    -1,    -1,
      80,    30,    -1,    -1,    33,    34,    35,    -1,    -1,    -1,
      -1,    30,    -1,    -1,    33,    34,    35,    -1,    -1,    -1,
      -1,    -1,    61,    62,    63,    64,    65,    -1,    67,    68,
      69,    -1,    61,    62,    63,    64,    -1,    66,    67,    68,
      69,    80,    61,    62,    63,    64,    -1,    66,    67,    68,
      69,    80,    30,    -1,    -1,    33,    34,    35,    -1,    -1,
      -1,    80,    30,    -1,    -1,    33,    34,    35,    -1,    -1,
      -1,    -1,    30,    -1,    -1,    33,    34,    35,    -1,    -1,
      -1,    -1,    -1,    61,    62,    63,    64,    -1,    66,    67,
      68,    69,    -1,    61,    62,    63,    64,    -1,    66,    67,
      68,    69,    80,    61,    62,    63,    64,    -1,    66,    67,
      68,    69,    80,    30,    -1,    -1,    33,    34,    35,    -1,
      -1,    -1,    80,    30,    -1,    -1,    33,    34,    35,    -1,
      -1,    -1,    -1,    30,    -1,    -1,    33,    34,    35,    -1,
      -1,    -1,    -1,    -1,    61,    62,    63,    64,    -1,    66,
      67,    68,    69,    -1,    61,    62,    63,    64,    -1,    66,
      67,    68,    69,    80,    61,    62,    63,    64,    -1,    66,
      67,    68,    69,    80,    30,    -1,    -1,    33,    34,    35,
      -1,    -1,    -1,    80,    30,    -1,    -1,    33,    34,    35,
      -1,    -1,    -1,    -1,    30,    -1,    -1,    33,    34,    35,
      -1,    -1,    -1,    -1,    -1,    61,    62,    63,    64,    -1,
      66,    67,    68,    69,    -1,    61,    62,    63,    64,    -1,
      66,    67,    68,    69,    80,    61,    62,    63,    64,    65,
      -1,    67,    68,    69,    80,    30,    -1,    -1,    33,    34,
      35,    -1,    -1,    -1,    80,    30,    -1,    -1,    33,    34,
      35,    -1,    -1,    -1,    -1,    -1,    30,    -1,    -1,    33,
      34,    35,    -1,    -1,    -1,    -1,    61,    62,    63,    64,
      -1,    66,    67,    68,    69,    -1,    61,    62,    63,    64,
      -1,    66,    67,    68,    69,    80,    -1,    61,    62,    63,
      64,    76,    66,    67,    68,    69,    30,    -1,    -1,    33,
      34,    35,    76,    -1,    -1,    -1,    -1,    30,    -1,    -1,
      33,    34,    35,    -1,    -1,    -1,    30,    -1,    -1,    33,
      34,    35,    -1,    -1,    -1,    -1,    -1,    61,    62,    63,
      64,    -1,    66,    67,    68,    69,    -1,    -1,    61,    62,
      63,    64,    76,    66,    67,    68,    69,    61,    62,    63,
      64,    74,    66,    67,    68,    69,    -1,    -1,    30,    -1,
      74,    33,    34,    35,    -1,    -1,    -1,    30,    -1,    -1,
      33,    34,    35,    -1,    -1,    -1,    30,    -1,    -1,    33,
      34,    35,    -1,    30,    -1,    -1,    33,    34,    35,    61,
      62,    63,    64,    -1,    66,    67,    68,    69,    61,    62,
      63,    64,    74,    66,    67,    68,    69,    61,    62,    63,
      64,    74,    66,    67,    68,    69,    63,    64,    -1,    66,
      67,    68,    69,    30,    -1,    -1,    33,    34,    35,    46,
      47,    48,    49,    50,    51,    52,    53,    -1,    55,    -1,
      46,    47,    48,    49,    50,    51,    52,    53,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      67,    68,    69
>>>>>>> temp
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    84,    85,     0,    71,    88,    16,    86,    89,    71,
      90,    72,    94,    12,    87,     9,    72,    95,    96,    97,
      91,    71,    92,    10,     7,   108,   109,    72,    97,    72,
      96,   119,    14,    73,    10,    11,   101,   102,    19,   110,
     111,     7,     7,     3,     4,    18,    23,    27,    28,    29,
      36,    70,    71,    79,   118,   120,   121,   122,   123,   124,
     128,   132,   134,   135,   149,   152,   154,   156,    93,     4,
       8,     8,    71,    22,   103,   104,     3,   118,   110,    82,
     130,   130,    82,     3,    79,    79,    79,     3,   123,    13,
      26,   132,   133,    79,   125,    24,   136,     3,    18,   118,
<<<<<<< HEAD
      81,   203,    72,    20,    20,    17,     3,   104,     3,    79,
     113,     3,     4,    79,   143,    20,    20,   123,   150,     3,
     148,   148,     3,     4,    31,    32,    79,   144,    74,    80,
     127,   143,    20,   126,    79,   130,   130,   125,    27,    28,
      29,    36,    59,    71,   180,   182,   183,   184,   192,   195,
     198,   201,   204,   205,   206,     9,    77,    98,   170,     4,
=======
      81,   202,    72,    20,    20,    17,     3,   104,     3,    79,
     113,     3,     4,    79,   143,    20,    20,   123,   150,     3,
     148,   148,     3,     4,    31,    32,    79,   144,    74,    80,
     127,   143,    20,   126,    79,   130,   130,   125,    27,    28,
      29,    36,    59,    71,   179,   181,   182,   183,   191,   194,
     197,   200,   203,   204,   205,     9,    77,    98,   170,     4,
>>>>>>> temp
      99,   100,    73,     3,   114,    20,   115,   123,   129,    61,
      62,    63,    64,    65,   143,   143,    20,    21,    74,    80,
      80,   144,    30,    33,    34,    35,    61,    62,    63,    64,
      65,    67,    68,    69,    80,   132,    81,    74,    80,    79,
     123,   131,   144,    20,    20,   126,     3,    79,    79,    79,
<<<<<<< HEAD
      79,    15,    58,    24,   185,     3,   178,    46,    47,    48,
      49,    50,    51,    52,    53,    55,   159,   160,   179,    11,
=======
      79,    15,    58,    24,   184,     3,   177,    46,    47,    48,
      49,    50,    51,    52,    53,    55,   159,   160,   178,    11,
>>>>>>> temp
       4,     6,    56,    57,    79,   163,   164,   171,    74,    74,
      75,    77,   105,    74,    80,     3,    79,   116,   112,    74,
      80,   143,   143,   143,   143,   143,   123,    79,   148,    21,
      21,    80,   144,   144,   144,   144,   144,   144,   144,   144,
     144,   144,   144,   144,   157,   143,   127,    80,   143,   143,
<<<<<<< HEAD
     193,   148,   148,     3,     4,     6,    31,    32,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    50,    56,    57,
      70,    75,    79,   158,   162,   164,   165,   170,   172,   173,
     175,   177,   177,   181,    50,    79,    73,    75,   178,   178,
      73,   163,    74,   170,   100,    75,    79,   106,   114,    74,
     116,    75,   123,     3,     4,   145,   146,    79,    79,    77,
      80,   137,    21,    80,    80,    79,    79,    79,    79,    79,
      79,    79,    79,   177,    75,   166,   167,   172,   174,     4,
       6,    56,    57,   177,    75,    30,    33,    34,    35,    61,
      62,    63,    64,    66,    67,    68,    69,    80,    74,    80,
     177,   177,   161,     4,    74,   171,   171,   107,   171,    74,
      78,   116,    80,   117,   121,    82,    80,   146,   147,   147,
     119,    77,    79,    21,    21,   177,   177,   177,   177,   177,
     177,   177,   177,    75,   163,   164,   168,   169,    74,    76,
      74,    76,    80,   177,   177,   177,   177,   177,   177,   177,
     177,   177,   177,   177,   177,   177,    77,   177,    80,   159,
      72,   163,    78,    74,    74,    80,    79,    76,   117,   145,
     151,    74,    80,    80,    71,    78,   119,   146,    79,    79,
      74,    74,    74,    80,    80,    80,    74,    80,    74,    76,
     167,    75,   172,    76,   202,    77,    76,     5,    80,   171,
     171,   107,    82,    77,   147,   153,   155,    78,    80,   147,
     147,   177,   177,   177,     4,    79,   169,    75,   203,   186,
      73,    76,    80,   145,   119,    77,    77,   138,    77,    80,
      80,    80,    80,    80,    80,   176,   177,   177,    71,    78,
     203,     4,    74,    78,   119,   119,   139,   194,   196,   199,
      74,    80,    76,    78,    75,    78,    78,    25,   141,   203,
      77,    77,   177,    80,    75,   187,   171,    79,   142,    78,
     197,   200,   177,   188,    74,   144,    77,   203,   203,    76,
      25,   190,   171,    80,   119,    78,    78,    77,    79,    76,
     140,    78,   191,   177,    76,    77,   203,    80,   119,    78,
      77,    78,   189,   203,    78
=======
     192,   148,   148,     3,     4,     6,    31,    32,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    50,    56,    57,
      70,    75,    79,   158,   162,   164,   165,   170,   172,   173,
     175,   176,   176,   180,    50,    79,    73,    75,   177,   177,
      73,   163,    74,   170,   100,    75,    79,   106,   114,    74,
     116,    75,   123,     3,     4,   145,   146,    79,    79,    77,
      80,   137,    21,    80,    80,    79,    79,    79,    79,    79,
      79,    79,    79,   176,    75,   166,   167,   172,   174,     4,
       6,    56,    57,   176,    75,    30,    33,    34,    35,    61,
      62,    63,    64,    66,    67,    68,    69,    80,    74,    80,
     176,   176,   161,     4,    74,   171,   171,   107,   171,    74,
      78,   116,    80,   117,   121,    82,    80,   146,   147,   147,
     119,    77,    79,    21,    21,   176,   176,   176,   176,   176,
     176,   176,   176,    75,   163,   164,   168,   169,    74,    76,
      74,    76,    80,   176,   176,   176,   176,   176,   176,   176,
     176,   176,   176,   176,   176,   176,    77,   176,    80,   159,
      72,   163,    78,    74,    74,    80,    79,    76,   117,   145,
     151,    74,    80,    80,    71,    78,   119,   146,    79,    79,
      74,    74,    74,    80,    80,    80,    74,    80,    74,    76,
     167,    75,   172,    76,   201,    77,    76,     5,    80,   171,
     171,   107,    82,    77,   147,   153,   155,    78,    80,   147,
     147,   176,   176,   176,     4,   169,    75,   202,   185,    73,
      76,    80,   145,   119,    77,    77,   138,    77,    80,    80,
      80,    80,    80,    80,   176,    71,    78,   202,     4,    74,
      78,   119,   119,   139,   193,   195,   198,    76,    78,    75,
      78,    78,    25,   141,   202,    77,    77,    75,   186,   171,
      79,   142,    78,   196,   199,   176,   187,    74,   144,    77,
     202,   202,    76,    25,   189,   171,    80,   119,    78,    78,
      77,    79,    76,   140,    78,   190,   176,    76,    77,   202,
      80,   119,    78,    77,    78,   188,   202,    78
>>>>>>> temp
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
#line 90 "./Parser/parser_main.y"
    { fprintf(out,"#include<iostream>\n"
                                        "#include<vector>\n"
                                        "#include\"complex.h\"\n"
                                        "#include\"matrix.h\"\n"
                                        "#include\"type.h\"\n"
                                        "#include\"state.h\"\n"
                                        "#include\"list_func.h\"\n"
                                        "#include<math.h>\n\n"
                                        "using namespace std;\n\n");

                            fprintf(out,"Matrix X = Matrix(2);\n"
                                          "Matrix Y = Matrix(2);\n"
                                          "Matrix Z = Matrix(2);\n"
                                          "Matrix H = Matrix(2);\n"
                                          "int initializeGate(Matrix x,Complex a,Complex b,Complex c,Complex d){\n"
                                                "\tx.set_entry(0,0,a);\n"
                                                "\tx.set_entry(0,1,b);\n"
                                                "\tx.set_entry(1,0,c);\n"
                                                "\tx.set_entry(1,1,d);\n"
                                                "\tif(x.is_unitary()) return 1;\n"
                                                "\treturn 0;\n"
                                          "}\n\n"
                                    );

                            struct GateTable* temp = GateSymbolTable;
                            while(temp != NULL){
                                 fprintf(out,"if(!initializeGate(%s,Complex(%f,%f),Complex(%f,%f),Complex(%f,%f),Complex(%f,%f))) return 0;\n",
                                 temp->id,temp->arr[0].real,temp->arr[0].imag,temp->arr[1].real,temp->arr[1].imag,temp->arr[2].real,temp->arr[2].imag,temp->arr[3].real,temp->arr[3].imag);
                                 temp = temp->next;
                            }

                          }
    break;

  case 3:
#line 123 "./Parser/parser_main.y"
    {
                              fprintf(out,"\nint main(){\nfor(int i=0; i<quantum_registers; i++) {quantum_register_dict[i] = i;}\n");
                              fprintf(out,"initializeGate(X,Complex(0,0),Complex(1,0),Complex(1,0),Complex(0,0));\n");
                              fprintf(out,"initializeGate(Y,Complex(0,0),Complex(0,-1),Complex(0,1),Complex(0,0));\n");
                              fprintf(out,"initializeGate(Z,Complex(1,0),Complex(0,0),Complex(0,0),Complex(-1,0));\n");
                              fprintf(out,"initializeGate(H,Complex(1/sqrt(2),0),Complex(1/sqrt(2),0),Complex(1/sqrt(2),0),Complex(-1/sqrt(2),0));\n");
                              fprintf(out,"FILE *result = fopen(\"result.csv\",\"w\");\n");
                              fprintf(out,"for(int iters=0;iters < num_iterations;iters++){\n");
                              fprintf(out,"q_output = StateVec(%d, q);\n"
                                          "for(int i=0;i<%d;i++){\n"
                                             "\t\tc_output[i] = c_output_original[i];\n"
                                          "}\n"
                                          "for(int i=0;i<%d;i++){\n"
                                             "\t\tquantum_register_dict[i] = i;\n"
                                          "}\n"
                                          "quantum_registers = quantum_registers_original;\n"
                                          "op = Matrix(1 << quantum_registers);\n",
                                          quantum_registers, classical_registers,quantum_registers
                                     );
                          }
    break;

  case 4:
#line 144 "./Parser/parser_main.y"
    {
                              fprintf(out,"for(int i=0;i<classical_registers;i++){\n"
                                          "c_master[i] += c_output[i];\n"
                                          "}\n"
                                     );
                              fprintf(out,"fprintf(result,\"Iteration #%%d:\\n\",iters+1);\n");
                              fprintf(out,"fprintf(result,\"Classical Outputs: \");");
                              fprintf(out,"for(int i=0;i<%d-1;i++){\n"
                                             "\t\tfprintf(result,\"%%d, \",c_output[i]);\n"
                                          "}\n",classical_registers);
                              fprintf(out,"fprintf(result,\"%%d\\n\",c_output[%d-1]);\n",classical_registers);
                              fprintf(out,"fprintf(result,\"Quantum Outputs: \"\);");
                              fprintf(out,"for(int i=0;i< (1 << quantum_registers) ;i++){\n"
                                             "\t\tfprintf(result,\"(%%f, %%f), \",q_output.get_value(i).get_real(),q_output.get_value(i).get_imag());\n"
                                          "}\n"
                                          "fprintf(result,\"\\n\\n\");");
                              //fprintf(out,"fprintf(result,\"(%%f, %%f)\",q_output.get_value(%d-1).get_real(),q_output.get_value(%d-1).get_imag());",quantum_registers,quantum_registers);
                              
                              fprintf(out,"}\n");
                              fprintf(out,"fclose(result);\n");
                           }
    break;

  case 5:
#line 166 "./Parser/parser_main.y"
    {fprintf(out,"}\n");fprintf(fp,"\nParsing successful!\n");}
    break;

  case 6:
#line 170 "./Parser/parser_main.y"
    {fprintf(fp,"\nInit section begins\n\n");}
    break;

  case 7:
#line 170 "./Parser/parser_main.y"
    {fprintf(fp,"\nInit section ends\n");(yyval).str = (yyvsp[(5) - (9)]).str;}
    break;

  case 8:
#line 173 "./Parser/parser_main.y"
    {fprintf(fp,"\nMain section begins\n\n");}
    break;

  case 9:
#line 173 "./Parser/parser_main.y"
    {fprintf(fp,"\nMain section ends\n");}
    break;

  case 10:
#line 176 "./Parser/parser_main.y"
    {fprintf(fp,"\nOutput section begins\n\n"); isInOutput = true; outputLevel = 1;}
    break;

  case 11:
#line 176 "./Parser/parser_main.y"
    {fprintf(fp,"\nOutput section ends\n");exitOutputSymbolScope(&OutputSymbolTable,outputLevel);}
    break;

  case 12:
#line 184 "./Parser/parser_main.y"
    {  fprintf(fp,"Register and iteration initialization section\n");
                                                                                                                        classical_registers = (yyvsp[(10) - (14)]).num;
                                                                                                                        quantum_registers = (yyvsp[(5) - (14)]).num;
                                                                                                                        iterations = (yyvsp[(14) - (14)]).num;

                                                                                                                        fprintf(out,"int num_iterations = %d;\n", iterations);
                                                                                                                        fprintf(out,"int quantum_registers = %d;\n", quantum_registers);
                                                                                                                        fprintf(out,"int quantum_registers_original = %d;\n", quantum_registers);
                                                                                                                        fprintf(out,"int classical_registers = %d;\n\n", classical_registers);
                                                                                                                        fprintf(out,"int quantum_register_dict[%d];\n", quantum_registers);
                                                                                                                        fprintf(out,"Matrix op = Matrix(1<<quantum_registers)\n;");
                                                                                                                        fprintf(out, "int quantum_register_map(int i){\n");
                                                                                                                        fprintf(out, "if( (i>= %d) || (i<0) || (quantum_register_dict[i] == -1))\n", quantum_registers);           
                                                                                                                        fprintf(out, "{throw std::runtime_error(\"Semantic Error: Invalid quantum register access\");}\n");
                                                                                                                        fprintf(out, "return quantum_register_dict[i];\n}\n");                                                                                                                     }
    break;

  case 13:
#line 202 "./Parser/parser_main.y"
    { fprintf(out,(yyvsp[(1) - (2)]).str);fprintf(out,(yyvsp[(2) - (2)]).str);}
    break;

  case 14:
#line 203 "./Parser/parser_main.y"
    {fprintf(out,(yyvsp[(1) - (1)]).str);fprintf(out,"StateVec q_output = StateVec(%d);\nStateVec q_output_original = StateVec(%d);\n",
                                                                     quantum_registers);}
    break;

  case 15:
#line 205 "./Parser/parser_main.y"
    { fprintf(out,(yyvsp[(1) - (2)]).str);fprintf(out,(yyvsp[(2) - (2)]).str);}
    break;

  case 16:
#line 206 "./Parser/parser_main.y"
    {fprintf(out,"int c_output[%d]={ 0 };\nint c_output_original[%d]={ 0 };\nvector<unsigned int> c_master(%d, 0);\n",classical_registers,classical_registers);}
    break;

  case 17:
#line 207 "./Parser/parser_main.y"
    { fprintf(out,"int c_output[%d]={ 0 };\nint c_output_original[%d]={ 0 };\nvector<unsigned int> c_master(%d, 0);\n",classical_registers,classical_registers);
                              fprintf(out,"StateVec q_output = StateVec(%d);\nStateVec q_output_original = StateVec(%d);\n",quantum_registers,quantum_registers);
                            }
    break;

  case 18:
#line 212 "./Parser/parser_main.y"
    { fprintf(fp,"Setting initial state of quantum registers\n");
                                                                              (yyval).str = (char *)malloc(sizeof(char)*(strlen((yyvsp[(6) - (6)]).str)*2+300));
snprintf((yyval).str,strlen((yyvsp[(6) - (6)]).str)*2+300,"struct Quantum q[%d] = {%s};\nStateVec q_output_original = StateVec(%d,q);\nStateVec q_output = StateVec(%d,q);\n", quantum_registers,(yyvsp[(6) - (6)]).str, quantum_registers,quantum_registers);
                                                                            }
    break;

  case 19:
#line 218 "./Parser/parser_main.y"
    {   fprintf(fp,"Setting initial state of classical registers\n");
                                                                                    (yyval).str = (char *)malloc(sizeof(char)*(strlen((yyvsp[(6) - (6)]).str)*2+200));
                                                                                    snprintf((yyval).str,strlen((yyvsp[(6) - (6)]).str)*2+200,"int c_output[%d] = {%s};\nint c_output_original[%d] = {%s};\nvector<unsigned int> c_master(%d, 0);\n", classical_registers,(yyvsp[(6) - (6)]).str, classical_registers,(yyvsp[(6) - (6)]).str,classical_registers);
                                                                                }
    break;

  case 20:
#line 224 "./Parser/parser_main.y"
    {  if(quantum_index == quantum_registers){
                                                                           yyerror("semantic error: quantum registers out of bounds");
                                                                           return 1;
                                                                        }  
                                                                        (yyval).str = (char *)malloc(sizeof(char)*(strlen((yyvsp[(1) - (3)]).str)+110+2));
                                                                        snprintf((yyval).str,strlen((yyvsp[(1) - (3)]).str)+110+2,"%s,Quantum(Complex(%f,%f),Complex(%f,%f))",(yyvsp[(1) - (3)]).str,(yyvsp[(3) - (3)]).q.first.real,(yyvsp[(3) - (3)]).q.first.imag,(yyvsp[(3) - (3)]).q.second.real,(yyvsp[(3) - (3)]).q.second.imag);
                                                                        quantum_index++;
                                                                     }
    break;

  case 21:
#line 232 "./Parser/parser_main.y"
    {  
                                                                        (yyval).str = (char *)malloc(sizeof(char)*110);
                                                                        snprintf((yyval).str,110,"Quantum(Complex(%f,%f),Complex(%f,%f))",(yyvsp[(1) - (1)]).q.first.real,(yyvsp[(1) - (1)]).q.first.imag,(yyvsp[(1) - (1)]).q.second.real,(yyvsp[(1) - (1)]).q.second.imag);
                                                                        quantum_index = 1;
                                                                     }
    break;

  case 22:
#line 239 "./Parser/parser_main.y"
    { if(classical_index == classical_registers){
                                                                           yyerror("semantic error: classical registers out of bounds");
                                                                           return 1;
                                                                        }
                                                                        (yyval).str = (char *)malloc(sizeof(char)*(strlen((yyvsp[(1) - (3)]).str)+20+2));
                                                                        snprintf((yyval).str,strlen((yyvsp[(1) - (3)]).str)+20+2,"%s,%d",(yyvsp[(1) - (3)]).str,(yyvsp[(3) - (3)]).num);
                                                                        classical_index++;
                                                                     }
    break;

  case 23:
#line 247 "./Parser/parser_main.y"
    {  (yyval).str = (char *)malloc(sizeof(char)*20);
                                                                        snprintf((yyval).str,20,"%d",(yyvsp[(1) - (1)]).num);
                                                                        classical_index  = 1;
                                                                     }
    break;

  case 24:
#line 253 "./Parser/parser_main.y"
    {(yyval).num = (yyvsp[(1) - (1)]).num;}
    break;

  case 25:
#line 257 "./Parser/parser_main.y"
    {fprintf(fp,"Gate definition section begins\n");}
    break;

  case 26:
#line 257 "./Parser/parser_main.y"
    {fprintf(fp,"Gate definition section ends\n");}
    break;

  case 30:
#line 265 "./Parser/parser_main.y"
    { fprintf(fp,"Gate definition\n");
                                                   struct cpx arr[4];
                                                   for(int i=0;i<4;i++){
                                                      arr[i].real = (yyvsp[(4) - (4)]).gates[i].real;
                                                      arr[i].imag = (yyvsp[(4) - (4)]).gates[i].imag;
                                                   }
                                                   if(!insertInGateTable(&GateSymbolTable,(yyvsp[(2) - (4)]).str,arr)){
                                                      yyerror("semantic error: gate definition requires square matrix");
                                                      return 1;
                                                   }
                                                   fprintf(out,"Matrix %s = Matrix(%d);\n", (yyvsp[(2) - (4)]).str, 2);
                                                 }
    break;

  case 31:
#line 279 "./Parser/parser_main.y"
    {
                                                                                       (yyval).gates[0] = (yyvsp[(3) - (13)]).cpx;
                                                                                       (yyval).gates[1] = (yyvsp[(5) - (13)]).cpx;   
                                                                                       (yyval).gates[2] = (yyvsp[(9) - (13)]).cpx;
                                                                                       (yyval).gates[3] = (yyvsp[(11) - (13)]).cpx;
                                                                                     }
    break;

  case 35:
#line 291 "./Parser/parser_main.y"
    {(yyval).cols += 1;}
    break;

  case 36:
#line 292 "./Parser/parser_main.y"
    {(yyval).cols = 1;}
    break;

  case 37:
#line 295 "./Parser/parser_main.y"
    {fprintf(fp,"Block definition section begins\n");}
    break;

  case 38:
#line 295 "./Parser/parser_main.y"
    {fprintf(fp,"Block definition section ends\n");}
    break;

  case 41:
#line 302 "./Parser/parser_main.y"
    {  if(!insertInBlockTable(&BlockSymbolTable,(yyvsp[(2) - (4)]).str,(yyvsp[(3) - (4)]).num,head)){
                                                                     yyerror("semantic error: incorrect block definition");
                                                                     return 1;
                                                                  }

                                                                  fprintf(out,"Matrix %s(", (yyvsp[(2) - (4)]).str);
                                                                  
                                                                  if(head!=NULL){
                                                                  struct List* temp = head;
                                                                     while(temp->next!=NULL){
                                                                        fprintf(out, "int %s, ",temp->id);
                                                                        temp = temp->next;
                                                                     }   
                                                                     fprintf(out, "int %s",temp->id);
                                                                  }

                                                                  fprintf(out,"){\n");

                                                                  //free($2.str);
                                                                  head = NULL;
                                                                  isInBlock = 1;
                                                               }
    break;

  case 42:
#line 324 "./Parser/parser_main.y"
    {  fprintf(fp,"Block definition\n");
                                                                  if(!BlockSemanticCheck((yyvsp[(2) - (8)]).str)){
                                                                     yyerror("semantic error: incorrect block definition");
                                                                     return 1;
                                                                  }
                                                                  id_list = NULL;
                                                                  isInBlock = 0;
                                                                  fprintf(out, "return op;\n}\n");
                                                               }
    break;

  case 43:
#line 335 "./Parser/parser_main.y"
    {insertInList(&head,(yyvsp[(1) - (1)]).str);(yyval).num = 1; }
    break;

  case 44:
#line 336 "./Parser/parser_main.y"
    {
                                                   (yyval).num = (yyvsp[(2) - (3)]).num;                                              
                                                }
    break;

  case 45:
#line 341 "./Parser/parser_main.y"
    {insertInList(&head,(yyvsp[(1) - (3)]).str);(yyval).num = 1 + (yyvsp[(3) - (3)]).num;}
    break;

  case 46:
#line 342 "./Parser/parser_main.y"
    {insertInList(&head,(yyvsp[(1) - (1)]).str);(yyval).num = 1;}
    break;

  case 54:
#line 358 "./Parser/parser_main.y"
    {  if(!firstLetterCapital((yyvsp[(1) - (1)]).str)){
                                       yyerror("lexical error: block identifiers start with uppercase letter");
                                       return 1;
                                    } 
                                    (yyval).str = (yyvsp[(1) - (1)]).str;
                                 }
    break;

  case 58:
#line 376 "./Parser/parser_main.y"
    {fprintf(fp,"barrier statement\n");}
    break;

  case 60:
#line 379 "./Parser/parser_main.y"
    {fprintf(fp,"Measure statement\n");}
    break;

  case 61:
#line 380 "./Parser/parser_main.y"
    {fprintf(fp,"Conditional statement begin\n");}
    break;

  case 62:
#line 380 "./Parser/parser_main.y"
    {fprintf(fp,"Conditional statement end\n");}
    break;

  case 63:
#line 381 "./Parser/parser_main.y"
    {fprintf(fp,"For statement\n");}
    break;

  case 64:
#line 382 "./Parser/parser_main.y"
    {fprintf(fp,"For - Lex statement\n");}
    break;

  case 65:
#line 383 "./Parser/parser_main.y"
    {fprintf(fp,"For - Zip statement\n");}
    break;

  case 66:
#line 384 "./Parser/parser_main.y"
    {fprintf(fp,"while statement\n");}
    break;

  case 67:
#line 387 "./Parser/parser_main.y"
    { if((yyvsp[(1) - (1)]).num < 0){
                                       yyerror("semantic error: register numbers are non-negative");
                                       return 1;
                                    } 
                                    (yyval).num = (yyvsp[(1) - (1)]).num;
                                    (yyval).flag=0;
                                    (yyval).str = (char *)malloc(sizeof(char)*20);
                                    snprintf((yyval).str,20,"%d",(yyvsp[(1) - (1)]).num);
                                 }
    break;

  case 68:
#line 396 "./Parser/parser_main.y"
    {
                                    if(isInBlock){insertInList(&id_list,(yyvsp[(1) - (1)]).str);}
                                    (yyval).flag = 1;
                                    assignString((yyval).str,(yyvsp[(1) - (1)]).str);
                                    if(!isInOutput && !isInBlock) {
                                       if(!inList(&head,(yyvsp[(1) - (1)]).str)) {yyerror("semantic error: variable used without declaration (1)"); return 1;}
                                    }
                                 }
    break;

  case 69:
#line 408 "./Parser/parser_main.y"
    {
                                                                                 fprintf(fp,"Pre - defined Gate call statement\n");
                                                                                 if(1){
                                                                                    fprintf(out, "if(%s) {\n", (yyvsp[(1) - (5)]).str);
                                                                                    fprintf(out, "op = %s.kronecker_control_fill(%s, quantum_register_map(%s), quantum_registers) * op;\n", (yyvsp[(2) - (5)]).str, (yyvsp[(3) - (5)]).str, (yyvsp[(5) - (5)]).str);
                                                                                    fprintf(out, "}\n");
                                                                                 }
                                                                                 free((yyvsp[(1) - (5)]).str);
                                                                                 free((yyvsp[(2) - (5)]).str);
                                                                                 free((yyvsp[(3) - (5)]).str);
                                                                                 free((yyvsp[(5) - (5)]).str);
                                                                              }
    break;

  case 70:
#line 420 "./Parser/parser_main.y"
    {fprintf(fp,"user - defined Gate call statement\n");
                                                                                 if(1){
                                                                                    fprintf(out, "if(%s) {\n", (yyvsp[(1) - (5)]).str);
                                                                                    fprintf(out, "op = %s.kronecker_control_fill(%s, quantum_register_map(%s), quantum_registers) * op;\n", (yyvsp[(2) - (5)]).str, (yyvsp[(3) - (5)]).str, (yyvsp[(5) - (5)]).str);
                                                                                    fprintf(out, "}\n");
                                                                                 }
                                                                                 free((yyvsp[(1) - (5)]).str);
                                                                                 free((yyvsp[(2) - (5)]).str);
                                                                                 free((yyvsp[(3) - (5)]).str);
                                                                                 free((yyvsp[(5) - (5)]).str);                                                                                 free((yyvsp[(5) - (5)]).str);
                                                                              }
    break;

  case 71:
#line 431 "./Parser/parser_main.y"
    {fprintf(fp,"Pre - defined Gate call statement\n");
                                                                                 if(1){
                                                                                    fprintf(out, "op = %s.kronecker_control_fill(%s, quantum_register_map(%s), quantum_registers) * op;\n", (yyvsp[(1) - (4)]).str, (yyvsp[(2) - (4)]).str, (yyvsp[(4) - (4)]).str);
                                                                                 }
                                                                                 free((yyvsp[(1) - (4)]).str);
                                                                                 free((yyvsp[(2) - (4)]).str);
                                                                                 free((yyvsp[(4) - (4)]).str);    
                                                                              }
    break;

  case 72:
#line 439 "./Parser/parser_main.y"
    {fprintf(fp,"User - defined Gate call statement\n");
                                                                                 if(!BlockCallSemanticCheck((yyvsp[(1) - (4)]).str,(yyvsp[(2) - (4)]).num)){
                                                                                    yyerror("semantic error: block not defined");
                                                                                    return 1;
                                                                                 }
                                                                                 if(1){
                                                                                    fprintf(out, "op = %s.kronecker_control_fill(%s, quantum_register_map(%s), quantum_registers) * op;\n", (yyvsp[(1) - (4)]).str, (yyvsp[(2) - (4)]).str, (yyvsp[(4) - (4)]).str);
                                                                                 }
                                                                                 free((yyvsp[(1) - (4)]).str);
                                                                                 free((yyvsp[(2) - (4)]).str);
                                                                                 free((yyvsp[(4) - (4)]).str);                                                                                   
                                                                              }
    break;

  case 73:
#line 451 "./Parser/parser_main.y"
    {  fprintf(fp,"Block call statement\n");
                                                                                 if(!isInBlock){
                                                                                    if(!BlockCallSemanticCheck((yyvsp[(2) - (4)]).str,(yyvsp[(3) - (4)]).num)){
                                                                                       yyerror("semantic error: block not defined");
                                                                                       free((yyvsp[(1) - (4)]).str);
                                                                                       free((yyvsp[(2) - (4)]).str);
                                                                                       free((yyvsp[(3) - (4)]).str);
                                                                                       return 1;
                                                                                    }
                                                                                    fprintf(out, "if(%s) {\n", (yyvsp[(1) - (4)]).str);
                                                                                    fprintf(out, "op = %s(%s);\n", (yyvsp[(2) - (4)]).str, (yyvsp[(3) - (4)]).str);
                                                                                    fprintf(out, "}\n");
                                                                                    free((yyvsp[(1) - (4)]).str);
                                                                                    free((yyvsp[(2) - (4)]).str);
                                                                                    free((yyvsp[(3) - (4)]).str);
                                                                                 }
                                                                              }
    break;

  case 74:
#line 468 "./Parser/parser_main.y"
    {  fprintf(fp,"Block call statement\n");
                                                                                 if(!isInBlock){
                                                                                    if(!BlockCallSemanticCheck((yyvsp[(1) - (3)]).str,(yyvsp[(2) - (3)]).num)){
                                                                                       yyerror("semantic error: block not defined");
                                                                                       return 1;
                                                                                    }
                                                                                    fprintf(out, "op = %s(%s);\n", (yyvsp[(1) - (3)]).str, (yyvsp[(2) - (3)]).str);
                                                                                    free((yyvsp[(1) - (3)]).str);
                                                                                    free((yyvsp[(2) - (3)]).str);
                                                                                 }
                                                                              }
    break;

  case 75:
#line 481 "./Parser/parser_main.y"
    {
                                                      (yyval).num = (yyvsp[(2) - (3)]).num; 
                                                      (yyval).str = (yyvsp[(2) - (3)]).str;
                                                   }
    break;

  case 78:
#line 491 "./Parser/parser_main.y"
    {
                                                         (yyval).num = 1 + (yyvsp[(1) - (3)]).num; 
                                                         (yyval).str = (char *)malloc(sizeof(char)*(strlen((yyvsp[(1) - (3)]).str)+strlen((yyvsp[(3) - (3)]).str)+3));
                                                         snprintf((yyval).str,strlen((yyvsp[(1) - (3)]).str)+strlen((yyvsp[(3) - (3)]).str)+3,"%s, %s",(yyvsp[(1) - (3)]).str,(yyvsp[(3) - (3)]).str);
                                                         free((yyvsp[(3) - (3)]).str);
                                                         free((yyvsp[(1) - (3)]).str);
                                                         }
    break;

  case 79:
#line 498 "./Parser/parser_main.y"
    { 
                                                         (yyval).num = 1; 
                                                         (yyval).str = (char *)malloc(sizeof(char)*(strlen((yyvsp[(1) - (1)]).str)+1));
                                                         snprintf((yyval).str,strlen((yyvsp[(1) - (1)]).str)+1,"%s",(yyvsp[(1) - (1)]).str);
                                                         free((yyvsp[(1) - (1)]).str);
                                                      }
    break;

  case 80:
#line 506 "./Parser/parser_main.y"
    {
                                                               (yyval).str = (char *)malloc(sizeof(char)*(strlen((yyvsp[(1) - (2)]).str)+1));
                                                               snprintf((yyval).str,strlen((yyvsp[(1) - (2)]).str)+1,"%s",(yyvsp[(1) - (2)]).str); 
                                                               // assignString($$.str,$1.str); 
                                                               free((yyvsp[(1) - (2)]).str); 
                                                            }
    break;

  case 81:
#line 512 "./Parser/parser_main.y"
    {
                                                               (yyval).str = (char *)malloc(sizeof(char)*(strlen((yyvsp[(2) - (4)]).str)+1));
                                                               snprintf((yyval).str,strlen((yyvsp[(2) - (4)]).str)+1,"%s",(yyvsp[(2) - (4)]).str);
                                                               // assignString($$.str,$2.str);
                                                               free((yyvsp[(2) - (4)]).str);
                                                            }
    break;

  case 82:
#line 520 "./Parser/parser_main.y"
    {
                                                                (yyval).num = 1 + (yyvsp[(1) - (3)]).num;
                                                                (yyval).str = (char *)malloc(sizeof(char)*(strlen((yyvsp[(1) - (3)]).str)+strlen((yyvsp[(3) - (3)]).str)+29));
                                                                snprintf((yyval).str,strlen((yyvsp[(1) - (3)]).str)+strlen((yyvsp[(3) - (3)]).str)+29,"%s|(1<<quantum_register_map(%s))",(yyvsp[(1) - (3)]).str,(yyvsp[(3) - (3)]).str);
                                                                free((yyvsp[(3) - (3)]).str);
                                                                free((yyvsp[(1) - (3)]).str);
                                                             }
    break;

  case 83:
#line 527 "./Parser/parser_main.y"
    { 
                                                                (yyval).num = 1; 
                                                                (yyval).str = (char *)malloc(sizeof(char)*(strlen((yyvsp[(1) - (1)]).str)+28));
                                                                snprintf((yyval).str,strlen((yyvsp[(1) - (1)]).str)+28,"(1<<quantum_register_map(%s))",(yyvsp[(1) - (1)]).str);
                                                                free((yyvsp[(1) - (1)]).str);
                                                            }
    break;

  case 84:
#line 535 "./Parser/parser_main.y"
    {
                                                                  (yyval).str = (char*) malloc(sizeof(char)*2);
                                                                  (yyval).str[0] = '0';
                                                                  (yyval).str[1] = '\0';
                                                               }
    break;

  case 85:
#line 540 "./Parser/parser_main.y"
    {
                                                                  (yyval).str = (char *)malloc(sizeof(char)*(strlen((yyvsp[(2) - (2)]).str)+28));
                                                                  snprintf((yyval).str,strlen((yyvsp[(2) - (2)]).str)+28,"(1<<quantum_register_map(%s))",(yyvsp[(2) - (2)]).str);
                                                                  free((yyvsp[(2) - (2)]).str);
                                                               }
    break;

  case 86:
#line 545 "./Parser/parser_main.y"
    {
                                                                  (yyval).str = (char *)malloc(sizeof(char)*(strlen((yyvsp[(3) - (4)]).str)+1));
                                                                  snprintf((yyval).str,strlen((yyvsp[(3) - (4)]).str)+1,"%s",(yyvsp[(3) - (4)]).str);
                                                                  free((yyvsp[(3) - (4)]).str);
                                                               }
    break;

  case 87:
#line 552 "./Parser/parser_main.y"
    {free((yyvsp[(1) - (1)]).str);}
    break;

  case 88:
#line 553 "./Parser/parser_main.y"
    {free((yyvsp[(2) - (3)]).str);}
    break;

  case 89:
#line 557 "./Parser/parser_main.y"
    {
                                                                        (yyval).str = (char *)malloc(sizeof(char)*(strlen((yyvsp[(1) - (1)]).str)+11));
                                                                        snprintf((yyval).str,strlen((yyvsp[(1) - (1)]).str)+11,"c_output[%s]",(yyvsp[(1) - (1)]).str);
                                                                        free((yyvsp[(1) - (1)]).str);
                                                                     }
    break;

  case 90:
#line 562 "./Parser/parser_main.y"
    {
                                                                        (yyval).str = (char *)malloc(sizeof(char)*(strlen((yyvsp[(2) - (2)]).str)+12));
                                                                        snprintf((yyval).str,strlen((yyvsp[(2) - (2)]).str)+12,"!c_output[%s]",(yyvsp[(2) - (2)]).str);
                                                                        free((yyvsp[(2) - (2)]).str);
                                                                     }
    break;

  case 91:
#line 569 "./Parser/parser_main.y"
    {
                                                                        (yyval).str = (char *)malloc(sizeof(char)*(strlen((yyvsp[(1) - (3)]).str)+strlen((yyvsp[(3) - (3)]).str)+7));
                                                                        snprintf((yyval).str,strlen((yyvsp[(1) - (3)]).str)+strlen((yyvsp[(3) - (3)]).str)+7,"%s && (%s)",(yyvsp[(1) - (3)]).str,(yyvsp[(3) - (3)]).str);
                                                                        free((yyvsp[(1) - (3)]).str);
                                                                        free((yyvsp[(3) - (3)]).str);    
                                                                     }
    break;

  case 92:
#line 575 "./Parser/parser_main.y"
    {
                                                                        (yyval).str = (char *)malloc(sizeof(char)*(strlen((yyvsp[(1) - (1)]).str)+3));
                                                                        snprintf((yyval).str,strlen((yyvsp[(1) - (1)]).str)+3,"(%s)",(yyvsp[(1) - (1)]).str);
                                                                        free((yyvsp[(1) - (1)]).str);
                                                                     }
    break;

  case 93:
#line 583 "./Parser/parser_main.y"
    {
                           if((!(yyvsp[(3) - (5)]).flag && ((yyvsp[(3) - (5)]).num < 0 || (yyvsp[(3) - (5)]).num >= quantum_registers)) || (!(yyvsp[(5) - (5)]).flag && ((yyvsp[(5) - (5)]).num < 0 || (yyvsp[(5) - (5)]).num >= classical_registers))){
                              yyerror("semantic error: register number out of bounds"); 
                              free((yyvsp[(3) - (5)]).str); 
                              free((yyvsp[(5) - (5)]).str);
                              return 1;
                           }
                           fprintf(out,"q_output = q_output.transform(op);\n");
                           fprintf(out,"c_output[%s] = q_output.measure_prob(quantum_register_map(%s));\n", (yyvsp[(5) - (5)]).str, (yyvsp[(3) - (5)]).str);        
                           fprintf(out, "quantum_registers--;\n");                                                                  
                           fprintf(out, "op = Matrix(1<<quantum_registers);\n");                                                    /* renewed op matrix */
                           fprintf(out, "quantum_register_dict[%s] = -1;\n", (yyvsp[(3) - (5)]).str);
                           fprintf(out, "for(int i=%s+1; i<%d; i++){quantum_register_dict[i]--;}\n", (yyvsp[(3) - (5)]).str, quantum_registers);     /* shifting mapping */
                           free((yyvsp[(3) - (5)]).str);
                           free((yyvsp[(5) - (5)]).str);
                        }
    break;

  case 94:
#line 601 "./Parser/parser_main.y"
    {
                                             fprintf(out,"q_output = q_output.transform(op);\n");
                                             fprintf(out, "op = Matrix(1<<quantum_registers);\n");
                                          }
    break;

  case 95:
#line 607 "./Parser/parser_main.y"
    {fprintf(out,"if(%s){\n",(yyvsp[(3) - (4)]).str); free((yyvsp[(3) - (4)]).str);}
    break;

  case 96:
#line 608 "./Parser/parser_main.y"
    {fprintf(out,"}\n");}
    break;

  case 98:
#line 612 "./Parser/parser_main.y"
    {fprintf(out,"else if(%s){\n",(yyvsp[(4) - (5)]).str); free((yyvsp[(4) - (5)]).str);}
    break;

  case 99:
#line 613 "./Parser/parser_main.y"
    {fprintf(out,"}\n");}
    break;

  case 101:
#line 617 "./Parser/parser_main.y"
    {fprintf(out,"else{\n");}
    break;

  case 102:
#line 618 "./Parser/parser_main.y"
    {fprintf(out,"}\n");}
    break;

  case 104:
#line 622 "./Parser/parser_main.y"
    {
                                                                        (yyval).str = (char *)malloc(sizeof(char)*(strlen((yyvsp[(1) - (3)]).str)+strlen((yyvsp[(3) - (3)]).str)+4));
                                                                        snprintf((yyval).str,strlen((yyvsp[(1) - (3)]).str)+strlen((yyvsp[(3) - (3)]).str)+4,"%s + %s",(yyvsp[(1) - (3)]).str,(yyvsp[(3) - (3)]).str);
                                                                        free((yyvsp[(1) - (3)]).str);
                                                                        free((yyvsp[(3) - (3)]).str);           
                                                                     }
    break;

  case 105:
#line 628 "./Parser/parser_main.y"
    {
                                                                        (yyval).str = (char *)malloc(sizeof(char)*(strlen((yyvsp[(1) - (3)]).str)+strlen((yyvsp[(3) - (3)]).str)+4));
                                                                        snprintf((yyval).str,strlen((yyvsp[(1) - (3)]).str)+strlen((yyvsp[(3) - (3)]).str)+4,"%s - %s",(yyvsp[(1) - (3)]).str,(yyvsp[(3) - (3)]).str);
                                                                        free((yyvsp[(1) - (3)]).str);
                                                                        free((yyvsp[(3) - (3)]).str);           
                                                                     }
    break;

  case 106:
#line 634 "./Parser/parser_main.y"
    {
                                                                        (yyval).str = (char *)malloc(sizeof(char)*(strlen((yyvsp[(1) - (3)]).str)+strlen((yyvsp[(3) - (3)]).str)+4));
                                                                        snprintf((yyval).str,strlen((yyvsp[(1) - (3)]).str)+strlen((yyvsp[(3) - (3)]).str)+4,"%s * %s",(yyvsp[(1) - (3)]).str,(yyvsp[(3) - (3)]).str);
                                                                        free((yyvsp[(1) - (3)]).str);
                                                                        free((yyvsp[(3) - (3)]).str);           
                                                                     }
    break;

  case 107:
#line 640 "./Parser/parser_main.y"
    {
                                                                        (yyval).str = (char *)malloc(sizeof(char)*(strlen((yyvsp[(1) - (3)]).str)+strlen((yyvsp[(3) - (3)]).str)+4));
                                                                        snprintf((yyval).str,strlen((yyvsp[(1) - (3)]).str)+strlen((yyvsp[(3) - (3)]).str)+4,"%s / %s",(yyvsp[(1) - (3)]).str,(yyvsp[(3) - (3)]).str);
                                                                        free((yyvsp[(1) - (3)]).str);
                                                                        free((yyvsp[(3) - (3)]).str);           
                                                                     }
    break;

  case 108:
#line 646 "./Parser/parser_main.y"
    {
                                                                        (yyval).str = (char *)malloc(sizeof(char)*(strlen((yyvsp[(1) - (3)]).str)+strlen((yyvsp[(3) - (3)]).str)+4));
                                                                        snprintf((yyval).str,strlen((yyvsp[(1) - (3)]).str)+strlen((yyvsp[(3) - (3)]).str)+4,"%s %% %s",(yyvsp[(1) - (3)]).str,(yyvsp[(3) - (3)]).str);
                                                                        free((yyvsp[(1) - (3)]).str);
                                                                        free((yyvsp[(3) - (3)]).str);           
                                                                     }
    break;

  case 109:
#line 652 "./Parser/parser_main.y"
    {
                                                                        if(!isInOutput) {
                                                                           if(!isInBlock && !inList(&head,(yyvsp[(1) - (1)]).str)) {yyerror("semantic error: variable used without declaration (2)"); free((yyvsp[(1) - (1)]).str); return 1;}
                                                                           (yyval).str = (char *)malloc(sizeof(char)*(strlen((yyvsp[(1) - (1)]).str)+1));
                                                                           snprintf((yyval).str,strlen((yyvsp[(1) - (1)]).str)+1,"%s",(yyvsp[(1) - (1)]).str);
                                                                           free((yyvsp[(1) - (1)]).str);  
                                                                        }  
                                                                     }
    break;

  case 110:
#line 660 "./Parser/parser_main.y"
    {
                                                                        (yyval).str = (char *)malloc(sizeof(char)*20);
                                                                        snprintf((yyval).str,20,"%d",(yyvsp[(1) - (1)]).num);
                                                                     }
    break;

  case 111:
#line 672 "./Parser/parser_main.y"
    {
                                                                        (yyval).str = (char *)malloc(sizeof(char)*(strlen((yyvsp[(1) - (3)]).str)+strlen((yyvsp[(2) - (3)]).str)+strlen((yyvsp[(3) - (3)]).str)+3));
                                                                        snprintf((yyval).str,strlen((yyvsp[(1) - (3)]).str)+strlen((yyvsp[(2) - (3)]).str)+strlen((yyvsp[(3) - (3)]).str)+5,"%s %s %s",(yyvsp[(1) - (3)]).str,(yyvsp[(2) - (3)]).str,(yyvsp[(3) - (3)]).str);
                                                                        free((yyvsp[(1) - (3)]).str);
                                                                        free((yyvsp[(3) - (3)]).str);           
                                                                     }
    break;

  case 112:
#line 678 "./Parser/parser_main.y"
    {
                                                                        (yyval).str = (char *)malloc(sizeof(char)*(strlen((yyvsp[(1) - (3)]).str)+strlen((yyvsp[(3) - (3)]).str)+5));
                                                                        snprintf((yyval).str,strlen((yyvsp[(1) - (3)]).str)+strlen((yyvsp[(3) - (3)]).str)+5,"%s == %s",(yyvsp[(1) - (3)]).str,(yyvsp[(3) - (3)]).str);
                                                                        free((yyvsp[(1) - (3)]).str);
                                                                        free((yyvsp[(3) - (3)]).str);           
                                                                     }
    break;

  case 113:
#line 684 "./Parser/parser_main.y"
    {
                                                                        (yyval).str = (char *)malloc(sizeof(char)*(strlen((yyvsp[(1) - (3)]).str)+strlen((yyvsp[(3) - (3)]).str)+5));
                                                                        snprintf((yyval).str,strlen((yyvsp[(1) - (3)]).str)+strlen((yyvsp[(3) - (3)]).str)+5,"%s && %s",(yyvsp[(1) - (3)]).str,(yyvsp[(3) - (3)]).str);
                                                                        free((yyvsp[(1) - (3)]).str);
                                                                        free((yyvsp[(3) - (3)]).str);           
                                                                     }
    break;

  case 114:
#line 690 "./Parser/parser_main.y"
    {
                                                                        (yyval).str = (char *)malloc(sizeof(char)*(strlen((yyvsp[(1) - (3)]).str)+strlen((yyvsp[(3) - (3)]).str)+5));
                                                                        snprintf((yyval).str,strlen((yyvsp[(1) - (3)]).str)+strlen((yyvsp[(3) - (3)]).str)+5,"%s || %s",(yyvsp[(1) - (3)]).str,(yyvsp[(3) - (3)]).str);
                                                                        free((yyvsp[(1) - (3)]).str);
                                                                        free((yyvsp[(3) - (3)]).str);           
                                                                     }
    break;

  case 115:
#line 696 "./Parser/parser_main.y"
    {
                                                                        (yyval).str = (char *)malloc(sizeof(char)*(strlen((yyvsp[(1) - (3)]).str)+strlen((yyvsp[(3) - (3)]).str)+4));
                                                                        snprintf((yyval).str,strlen((yyvsp[(1) - (3)]).str)+strlen((yyvsp[(3) - (3)]).str)+4,"%s ^ %s",(yyvsp[(1) - (3)]).str,(yyvsp[(3) - (3)]).str);
                                                                        free((yyvsp[(1) - (3)]).str);
                                                                        free((yyvsp[(3) - (3)]).str);           
                                                                     }
    break;

  case 116:
#line 702 "./Parser/parser_main.y"
    {
                                                                        (yyval).str = (char *)malloc(sizeof(char)*(strlen((yyvsp[(1) - (3)]).str)+strlen((yyvsp[(3) - (3)]).str)+4));
                                                                        snprintf((yyval).str,strlen((yyvsp[(1) - (3)]).str)+strlen((yyvsp[(3) - (3)]).str)+4,"%s & %s",(yyvsp[(1) - (3)]).str,(yyvsp[(3) - (3)]).str);
                                                                        free((yyvsp[(1) - (3)]).str);
                                                                        free((yyvsp[(3) - (3)]).str);           
                                                                     }
    break;

  case 117:
#line 708 "./Parser/parser_main.y"
    {
                                                                        (yyval).str = (char *)malloc(sizeof(char)*(strlen((yyvsp[(1) - (3)]).str)+strlen((yyvsp[(3) - (3)]).str)+4));
                                                                        snprintf((yyval).str,strlen((yyvsp[(1) - (3)]).str)+strlen((yyvsp[(3) - (3)]).str)+4,"%s | %s",(yyvsp[(1) - (3)]).str,(yyvsp[(3) - (3)]).str);
                                                                        free((yyvsp[(1) - (3)]).str);
                                                                        free((yyvsp[(3) - (3)]).str);           
                                                                     }
    break;

  case 118:
#line 714 "./Parser/parser_main.y"
    {
                                                                        (yyval).str = (char *)malloc(sizeof(char)*(strlen((yyvsp[(1) - (3)]).str)+3));
                                                                        snprintf((yyval).str,strlen((yyvsp[(1) - (3)]).str)+3,"(%s)",(yyvsp[(1) - (3)]).str);
                                                                        free((yyvsp[(1) - (3)]).str);          
                                                                     }
    break;

  case 119:
#line 719 "./Parser/parser_main.y"
    {
                                                                        (yyval).str = (char *)malloc(sizeof(char)*(strlen((yyvsp[(1) - (3)]).str)+strlen((yyvsp[(3) - (3)]).str)+4));
                                                                        snprintf((yyval).str,strlen((yyvsp[(1) - (3)]).str)+strlen((yyvsp[(3) - (3)]).str)+4,"%s + %s",(yyvsp[(1) - (3)]).str,(yyvsp[(3) - (3)]).str);
                                                                        free((yyvsp[(1) - (3)]).str);
                                                                        free((yyvsp[(3) - (3)]).str);           
                                                                     }
    break;

  case 120:
#line 725 "./Parser/parser_main.y"
    {
                                                                        (yyval).str = (char *)malloc(sizeof(char)*(strlen((yyvsp[(1) - (3)]).str)+strlen((yyvsp[(3) - (3)]).str)+4));
                                                                        snprintf((yyval).str,strlen((yyvsp[(1) - (3)]).str)+strlen((yyvsp[(3) - (3)]).str)+4,"%s - %s",(yyvsp[(1) - (3)]).str,(yyvsp[(3) - (3)]).str);
                                                                        free((yyvsp[(1) - (3)]).str);
                                                                        free((yyvsp[(3) - (3)]).str);           
                                                                     }
    break;

  case 121:
#line 731 "./Parser/parser_main.y"
    {
                                                                        (yyval).str = (char *)malloc(sizeof(char)*(strlen((yyvsp[(1) - (3)]).str)+strlen((yyvsp[(3) - (3)]).str)+4));
                                                                        snprintf((yyval).str,strlen((yyvsp[(1) - (3)]).str)+strlen((yyvsp[(3) - (3)]).str)+4,"%s * %s",(yyvsp[(1) - (3)]).str,(yyvsp[(3) - (3)]).str);
                                                                        free((yyvsp[(1) - (3)]).str);
                                                                        free((yyvsp[(3) - (3)]).str);           
                                                                     }
    break;

  case 122:
#line 737 "./Parser/parser_main.y"
    {
                                                                        (yyval).str = (char *)malloc(sizeof(char)*(strlen((yyvsp[(1) - (3)]).str)+strlen((yyvsp[(3) - (3)]).str)+4));
                                                                        snprintf((yyval).str,strlen((yyvsp[(1) - (3)]).str)+strlen((yyvsp[(3) - (3)]).str)+4,"%s / %s",(yyvsp[(1) - (3)]).str,(yyvsp[(3) - (3)]).str);
                                                                        free((yyvsp[(1) - (3)]).str);
                                                                        free((yyvsp[(3) - (3)]).str);           
                                                                     }
    break;

  case 123:
#line 743 "./Parser/parser_main.y"
    {
                                                                        (yyval).str = (char *)malloc(sizeof(char)*(strlen((yyvsp[(1) - (3)]).str)+strlen((yyvsp[(3) - (3)]).str)+4));
                                                                        snprintf((yyval).str,strlen((yyvsp[(1) - (3)]).str)+strlen((yyvsp[(3) - (3)]).str)+4,"%s %% %s",(yyvsp[(1) - (3)]).str,(yyvsp[(3) - (3)]).str);
                                                                        free((yyvsp[(1) - (3)]).str);
                                                                        free((yyvsp[(3) - (3)]).str);           
                                                                     }
    break;

  case 124:
#line 749 "./Parser/parser_main.y"
    {
                                                                        if(!isInOutput) {
                                                                           if(!isInBlock && !inList(&head,(yyvsp[(1) - (1)]).str)) {yyerror("semantic error: variable used without declaration (2)"); free((yyvsp[(1) - (1)]).str); return 1;}
                                                                           (yyval).str = (char *)malloc(sizeof(char)*(strlen((yyvsp[(1) - (1)]).str)+1));
                                                                           snprintf((yyval).str,strlen((yyvsp[(1) - (1)]).str)+1,"%s",(yyvsp[(1) - (1)]).str);
                                                                           free((yyvsp[(1) - (1)]).str);  
                                                                        }  
                                                                     }
    break;

  case 125:
#line 757 "./Parser/parser_main.y"
    {
                                                                              (yyval).str = (char *)malloc(sizeof(char)*20);
                                                                        snprintf((yyval).str,20,"%d",(yyvsp[(1) - (1)]).num);
                                                                     }
    break;

  case 126:
#line 762 "./Parser/parser_main.y"
    {
                                                                        (yyval).str = (char *)malloc(sizeof(char)*(2));
                                                                        snprintf((yyval).str,1,"1");        
                                                                     }
    break;

  case 127:
#line 766 "./Parser/parser_main.y"
    {
                                                                        (yyval).str = (char *)malloc(sizeof(char)*(2));
                                                                        snprintf((yyval).str,1,"0");       
                                                                     }
    break;

  case 128:
#line 773 "./Parser/parser_main.y"
    {(yyval).str = IntToString((yyvsp[(1) - (1)]).num);}
    break;

  case 129:
#line 774 "./Parser/parser_main.y"
    {(yyval).str = (yyvsp[(1) - (1)]).str;}
    break;

  case 130:
#line 777 "./Parser/parser_main.y"
    {(yyval).start = (yyvsp[(1) - (3)]).str; (yyval).end = (yyvsp[(3) - (3)]).str; (yyval).step = IntToString(1);}
    break;

  case 131:
#line 778 "./Parser/parser_main.y"
    {(yyval).start = (yyvsp[(1) - (5)]).str; (yyval).end = (yyvsp[(3) - (5)]).str; (yyval).step = (yyvsp[(5) - (5)]).str;}
    break;

  case 132:
#line 781 "./Parser/parser_main.y"
    {  (yyval).num = 1 + (yyvsp[(3) - (3)]).num;
                                                      struct List2* newNode = (struct List2*)malloc(sizeof(struct List2));
                                                      newNode->start = (yyvsp[(1) - (3)]).start;
                                                      newNode->end = (yyvsp[(1) - (3)]).end;
                                                      newNode->step = (yyvsp[(1) - (3)]).step;
                                                      newNode->next = range_list;
                                                      range_list = newNode;
                                                   }
    break;

  case 133:
#line 789 "./Parser/parser_main.y"
    {  (yyval).num = 1;
                                                      struct List2* newNode = (struct List2*)malloc(sizeof(struct List2));
                                                      newNode->start = (yyvsp[(1) - (1)]).start;
                                                      newNode->end = (yyvsp[(1) - (1)]).end;
                                                      newNode->step = (yyvsp[(1) - (1)]).step;
                                                      newNode->next = NULL;
                                                      range_list = newNode;
                                                   }
    break;

  case 134:
#line 799 "./Parser/parser_main.y"
    {  if(isInOutput){
                                                   if(getOutputSymbolEntry(&OutputSymbolTable,(yyvsp[(1) - (3)]).str,outputLevel + 1,1) == NULL){
                                                      yyerror("semantic error: variable used without declaration (3)");
                                                      return 1;
                                                   }
                                                }     
                                                if(!inList(&head,(yyvsp[(1) - (3)]).str)){
                                                   insertInList(&head,(yyvsp[(1) - (3)]).str);
                                                } 
                                                else {
                                                   yyerror("semantic error: loop variable redeclaration");
                                                   return 1;
                                                } 
                                                (yyval).num = 1 + (yyvsp[(3) - (3)]).num;
                                             }
    break;

  case 135:
#line 814 "./Parser/parser_main.y"
    {  if(isInOutput){
                                                   if(getOutputSymbolEntry(&OutputSymbolTable,(yyvsp[(1) - (1)]).str,outputLevel + 1,1) == NULL){
                                                      yyerror("semantic error: variable redeclaration");
                                                      return 1;
                                                   }
                                                } 
                                                if(!inList(&head,(yyvsp[(1) - (1)]).str)){
                                                   insertInList(&head,(yyvsp[(1) - (1)]).str);
                                                } 
                                                else{
                                                   yyerror("semantic error: loop variable redeclaration");
                                                   return 1;
                                                } 
                                                (yyval).num = 1;
                                             }
    break;

  case 136:
#line 831 "./Parser/parser_main.y"
    {  if(!inList(&head,(yyvsp[(2) - (2)]).str)){
                                                                              insertInList(&head,(yyvsp[(2) - (2)]).str);
                                                                           } 
                                                                           else{
                                                                              yyerror("semantic error: loop variable redeclaration"); 
                                                                              return 1;
                                                                           }
                                                                        }
    break;

  case 137:
#line 839 "./Parser/parser_main.y"
    {   
                                                                           fprintf(out,"for(int %s = %s;%s < %s;%s += %s){\n",(yyvsp[(2) - (7)]).str,(yyvsp[(6) - (7)]).start,(yyvsp[(2) - (7)]).str,(yyvsp[(6) - (7)]).end,(yyvsp[(2) - (7)]).str,(yyvsp[(6) - (7)]).step);  }
    break;

  case 138:
#line 841 "./Parser/parser_main.y"
    {
                                                                           fprintf(out,"}\n");
                                                                           removeTopKFromList(&head,1);
                                                                        }
    break;

  case 139:
#line 847 "./Parser/parser_main.y"
    { if((yyvsp[(3) - (8)]).num != (yyvsp[(7) - (8)]).num){
                                                                              yyerror("semantic error: mismatch in loop variables and ranges"); 
                                                                              return 1;
                                                                           }
                                                                           printForLex((yyvsp[(3) - (8)]).num, 1);
                                                                         }
    break;

  case 140:
#line 853 "./Parser/parser_main.y"
    {
                                                                           printForLex((yyvsp[(3) - (12)]).num, 0);
                                                                           removeTopKFromList(&head,(yyvsp[(3) - (12)]).num);
                                                                        }
    break;

  case 141:
#line 859 "./Parser/parser_main.y"
    { if((yyvsp[(3) - (8)]).num != (yyvsp[(7) - (8)]).num){
                                                                              yyerror("semantic error: mismatch in loop variables and ranges"); 
                                                                              return 1;
                                                                           }
                                                                           printForZip((yyvsp[(3) - (8)]).num, 1);
                                                                         }
    break;

  case 142:
#line 865 "./Parser/parser_main.y"
    {
                                                      removeTopKFromList(&head,(yyvsp[(3) - (12)]).num); 
                                                      printForZip((yyvsp[(3) - (12)]).num, 0);
                                                 }
    break;

  case 143:
#line 871 "./Parser/parser_main.y"
    {fprintf(out,"while(%s){\n",(yyvsp[(3) - (4)]).str);}
    break;

  case 144:
#line 872 "./Parser/parser_main.y"
    {fprintf(out,"}\n");}
    break;

  case 145:
#line 881 "./Parser/parser_main.y"
    {(yyval).out_flag = 0; (yyval).str = (yyvsp[(1) - (1)]).str;}
    break;

  case 146:
#line 882 "./Parser/parser_main.y"
    {(yyval).out_flag = 1; (yyval).type = Uint; (yyval).prim = false; (yyval).dim = (classical_registers); (yyval).rows = 0; (yyval).str = (char *)malloc(sizeof(char)*(9));strcpy((yyval).str,"c_master");}
    break;

  case 147:
#line 885 "./Parser/parser_main.y"
    {(yyval).type = Int; (yyval).prim = true;fprintf(out,"int ");}
    break;

  case 148:
#line 886 "./Parser/parser_main.y"
    {(yyval).type = Uint; (yyval).prim = true;fprintf(out,"unsigned int ");}
    break;

  case 149:
#line 887 "./Parser/parser_main.y"
    {(yyval).type = Float; (yyval).prim = true;fprintf(out,"float ");}
    break;

  case 150:
#line 888 "./Parser/parser_main.y"
    {(yyval).type = Complex; (yyval).prim = true;fprintf(out,"Complex ");}
    break;

  case 151:
#line 889 "./Parser/parser_main.y"
    {(yyval).type = String; (yyval).prim = true;fprintf(out,"string ");}
    break;

  case 152:
#line 890 "./Parser/parser_main.y"
    {(yyval).type = Matrix; (yyval).prim = true;fprintf(out,"Matrix ");}
    break;

  case 153:
#line 891 "./Parser/parser_main.y"
    {(yyval).type = State; (yyval).prim = true;fprintf(out,"StateVec ");}
    break;

  case 154:
#line 892 "./Parser/parser_main.y"
    {(yyval).type = Bool; (yyval).prim = true;fprintf(out,"bool ");}
    break;

  case 155:
#line 895 "./Parser/parser_main.y"
    {fprintf(out,"vector<");}
    break;

  case 156:
#line 895 "./Parser/parser_main.y"
    {(yyval).type = (yyvsp[(4) - (5)]).type; (yyval).prim = false;fprintf(out,">");}
    break;

  case 157:
#line 902 "./Parser/parser_main.y"
    {(yyval).num = 1;}
    break;

  case 158:
#line 903 "./Parser/parser_main.y"
    {(yyval).num = 0;}
    break;

  case 159:
#line 906 "./Parser/parser_main.y"
    {(yyval).real = (yyvsp[(1) - (1)]).real;}
    break;

  case 160:
#line 907 "./Parser/parser_main.y"
    {(yyval).real = (yyvsp[(1) - (1)]).real;}
    break;

  case 161:
#line 908 "./Parser/parser_main.y"
    {(yyval).real = (yyvsp[(1) - (1)]).real;}
    break;

  case 162:
#line 909 "./Parser/parser_main.y"
    {(yyval).real = (yyvsp[(1) - (1)]).num;}
    break;

  case 163:
#line 911 "./Parser/parser_main.y"
    {(yyval).cpx.real = (yyvsp[(2) - (5)]).real; (yyval).cpx.imag = (yyvsp[(4) - (5)]).real;}
    break;

  case 164:
#line 914 "./Parser/parser_main.y"
    { if((yyvsp[(2) - (3)]).rows == (yyvsp[(2) - (3)]).cols) {
                                                         (yyval).rows = (yyvsp[(2) - (3)]).rows;
                                                     } 
                                                     else{
                                                         yyerror("semantic error: only square matrices permitted"); 
                                                         return 1;
                                                     }
                                                     isFirst = 1;
                                                   }
    break;

  case 165:
#line 925 "./Parser/parser_main.y"
    {  (yyval).rows = (yyvsp[(1) - (3)]).rows + 1; 
                                                      if((yyvsp[(1) - (3)]).cols == (yyvsp[(3) - (3)]).cols){
                                                         (yyval).cols = (yyvsp[(1) - (3)]).cols;
                                                      } 
                                                      else{
                                                         yyerror("semantic error: rows of different length cannot form matrix"); 
                                                         return 1;
                                                      }
                                                      struct List3* temp = cpx_list;
                                                      while(temp->next != NULL){
                                                         temp = temp->next;
                                                      }
                                                      curr->next = cpx_list;
                                                      curr = temp;
                                                   }
    break;

  case 166:
#line 940 "./Parser/parser_main.y"
    {  (yyval).rows = 1; (yyval).cols = (yyvsp[(1) - (1)]).cols;
                                                         struct List3* temp = cpx_list;
                                                         while(temp->next != NULL){
                                                            temp = temp->next;
                                                         }
                                                         curr = temp;
                                                         if(isFirst){
                                                            cpx_head = cpx_list;
                                                            isFirst = 0;
                                                         }
                                                      }
    break;

  case 167:
#line 953 "./Parser/parser_main.y"
    {(yyval).cols = (yyvsp[(2) - (3)]).cols;}
    break;

  case 168:
#line 956 "./Parser/parser_main.y"
    {(yyval).cols = (yyvsp[(1) - (3)]).cols + 1;}
    break;

  case 169:
#line 957 "./Parser/parser_main.y"
    {(yyval).cols = 1;}
    break;

  case 172:
#line 964 "./Parser/parser_main.y"
    {(yyval).q.first = (yyvsp[(2) - (5)]).cpx; (yyval).q.second = (yyvsp[(4) - (5)]).cpx;}
    break;

  case 173:
#line 967 "./Parser/parser_main.y"
    {(yyval).cpx = (yyvsp[(1) - (1)]).cpx;}
    break;

  case 174:
#line 968 "./Parser/parser_main.y"
    {(yyval).cpx.real = (yyvsp[(1) - (1)]).real; (yyval).cpx.imag = 0;}
    break;

  case 175:
#line 971 "./Parser/parser_main.y"
    {  (yyval).type = Bool;
                                             (yyval).str = (char *)malloc(sizeof(char)*6);
                                             if((yyval).num)snprintf((yyval).str,6,"true");
                                             else snprintf((yyval).str,6,"false");
                                          }
    break;

  case 176:
#line 976 "./Parser/parser_main.y"
    {  (yyval).type = Complex;
                                             (yyval).str = (char *)malloc(sizeof(char)*120);
                                             snprintf((yyval).str,120,"Complex(%f,%f)",(yyvsp[(1) - (1)]).cpx.real,(yyvsp[(1) - (1)]).cpx.imag);
                                          }
    break;

  case 177:
#line 980 "./Parser/parser_main.y"
    {  (yyval).type = Matrix; 
                                             (yyval).rows = (yyvsp[(1) - (1)]).rows;
                                             (yyval).str = (char *)malloc(sizeof(char)*((yyval).rows*(yyval).rows*50));
                                          }
    break;

  case 178:
#line 984 "./Parser/parser_main.y"
    {(yyval).type = State;}
    break;

  case 179:
#line 985 "./Parser/parser_main.y"
    {(yyval).type = Uint;(yyval).str = (char *)malloc(sizeof(char)*20);snprintf((yyval).str,20,"%d",(yyvsp[(1) - (1)]).num);}
    break;

  case 180:
#line 986 "./Parser/parser_main.y"
    {(yyval).type = Int;(yyval).str = (char *)malloc(sizeof(char)*20);snprintf((yyval).str,20,"%d",(yyvsp[(1) - (1)]).num);}
    break;

  case 181:
#line 987 "./Parser/parser_main.y"
    {(yyval).type = Float;(yyval).str = (char *)malloc(sizeof(char)*20);snprintf((yyval).str,20,"%f",(yyvsp[(1) - (1)]).real);}
    break;

  case 182:
#line 988 "./Parser/parser_main.y"
    {(yyval).type = Float;(yyval).str = (char *)malloc(sizeof(char)*20);snprintf((yyval).str,20,"%f",(yyvsp[(1) - (1)]).real);}
    break;

  case 183:
#line 989 "./Parser/parser_main.y"
    {(yyval).type = String;(yyval).str = (char *)malloc(sizeof(char)*(strlen((yyvsp[(1) - (1)]).str)+1));snprintf((yyval).str,strlen((yyvsp[(1) - (1)]).str)+1,"%s",(yyvsp[(1) - (1)]).str);}
    break;

  case 184:
#line 992 "./Parser/parser_main.y"
    {  (yyval).dim = (yyvsp[(2) - (3)]).dim; 
                                                   (yyval).type = (yyvsp[(2) - (3)]).type; 
<<<<<<< HEAD
=======
                                                   (yyval).veconst = 1;
>>>>>>> temp
                                                   if((yyval).type == Matrix){
                                                      (yyval).rows = (yyvsp[(2) - (3)]).rows;
                                                   } 
                                                   else{
                                                      (yyval).rows = 0;
                                                   } 
                                                   (yyval).str = (char *)malloc(sizeof(char)*(strlen((yyvsp[(2) - (3)]).str)+3));
                                                   snprintf((yyval).str,strlen((yyvsp[(2) - (3)]).str)+3,"{%s}",(yyvsp[(2) - (3)]).str);
                                                   free((yyvsp[(2) - (3)]).str);
                                                }
    break;

  case 185:
<<<<<<< HEAD
#line 1006 "./Parser/parser_main.y"
=======
#line 1007 "./Parser/parser_main.y"
>>>>>>> temp
    {  temp_type = compatibleCheck((yyvsp[(1) - (3)]).type, (yyvsp[(3) - (3)]).type); 
                                                      if(temp_type != -1){
                                                         (yyval).type = temp_type;
                                                      } 
                                                      else{
                                                         yyerror("semantic error: incompatible types in list"); 
                                                         return 1;
                                                      } 
                                                      (yyval).dim = (yyvsp[(1) - (3)]).dim + 1; 
                                                      if((yyval).type == Matrix){
                                                         if((yyvsp[(1) - (3)]).rows != (yyvsp[(3) - (3)]).rows){
                                                            yyerror("semantic error: incompatible matrix dimensions in list");
                                                            return 1;
                                                         }
                                                         else{
                                                            (yyval).rows = (yyvsp[(1) - (3)]).rows;
                                                         } 
                                                      }
                                                      insertInList(&head,(yyvsp[(3) - (3)]).str);
                                                      (yyval).str = (char *)malloc(sizeof(char)*(strlen((yyvsp[(1) - (3)]).str)+strlen((yyvsp[(3) - (3)]).str)+2));
                                                      snprintf((yyval).str,strlen((yyvsp[(1) - (3)]).str)+strlen((yyvsp[(3) - (3)]).str)+2,"%s,%s",(yyvsp[(1) - (3)]).str,(yyvsp[(3) - (3)]).str);
                                                      free((yyvsp[(1) - (3)]).str);
                                                      free((yyvsp[(3) - (3)]).str);
                                                   }
    break;

  case 186:
<<<<<<< HEAD
#line 1030 "./Parser/parser_main.y"
=======
#line 1031 "./Parser/parser_main.y"
>>>>>>> temp
    {  (yyval).type = (yyvsp[(1) - (1)]).type; (yyval).dim = 1; 
                                                      if((yyval).type == Matrix){
                                                         (yyval).rows = (yyvsp[(1) - (1)]).rows;
                                                      }
                                                      (yyval).str = (yyvsp[(1) - (1)]).str;
                                                      head = NULL;
                                                      insertInList(&head,(yyvsp[(1) - (1)]).str);
                                                   }
    break;

  case 187:
<<<<<<< HEAD
#line 1042 "./Parser/parser_main.y"
=======
#line 1043 "./Parser/parser_main.y"
>>>>>>> temp
    {
                        temp_type = compatibleCheckAdv((yyvsp[(5) - (6)]).type, (yyvsp[(3) - (6)]).type, (yyvsp[(5) - (6)]).prim, (yyvsp[(3) - (6)]).prim, (yyvsp[(5) - (6)]).dim, (yyvsp[(3) - (6)]).dim); 
                        if((!(yyvsp[(3) - (6)]).prim) && (temp_type>= 0) && ((temp_type<=COMPATIBLE) || temp_type==Matrix || temp_type==State)){
                           (yyval).prim = false; 
                           (yyval).type = temp_type; 
                           (yyval).dim = (yyvsp[(3) - (6)]).dim;
                        } 
                        else{
                           yyerror("semantic error: incompatible operands");
                           return 1;
                        }
<<<<<<< HEAD
                        (yyval).str = (char *)malloc(sizeof(char)*(strlen((yyvsp[(5) - (6)]).str)+strlen((yyvsp[(3) - (6)]).str)+strlen((yyvsp[(1) - (6)]).str)+4));
                        snprintf((yyval).str,strlen((yyvsp[(5) - (6)]).str)+strlen((yyvsp[(3) - (6)]).str)+strlen((yyvsp[(1) - (6)]).str)+4,"%s(%s,%s)",(yyvsp[(1) - (6)]).str,(yyvsp[(3) - (6)]).str,(yyvsp[(5) - (6)]).str);
                        free((yyvsp[(3) - (6)]).str);
                        free((yyvsp[(5) - (6)]).str);
=======
                        if((yyvsp[(3) - (6)]).veconst == 0 && (yyvsp[(5) - (6)]).veconst == 0)
                        {
                           (yyval).str = (char *)malloc(sizeof(char)*(strlen((yyvsp[(5) - (6)]).str)+strlen((yyvsp[(3) - (6)]).str)+strlen((yyvsp[(1) - (6)]).str)+4));
                           snprintf((yyval).str,strlen((yyvsp[(5) - (6)]).str)+strlen((yyvsp[(3) - (6)]).str)+8+4,"addLists(%s,%s)",(yyvsp[(1) - (6)]).str,(yyvsp[(3) - (6)]).str,(yyvsp[(5) - (6)]).str);
                           free((yyvsp[(3) - (6)]).str);
                           free((yyvsp[(5) - (6)]).str);
                        }
                        else
                        {
                           yyerror("semantic error : initialize first, cannot directly pass as argument");
                           return 1;
                        }
>>>>>>> temp
                     }
    break;

  case 188:
<<<<<<< HEAD
#line 1059 "./Parser/parser_main.y"
=======
#line 1068 "./Parser/parser_main.y"
>>>>>>> temp
    {
                        temp_type = compatibleCheckAdv((yyvsp[(5) - (6)]).type, (yyvsp[(3) - (6)]).type, (yyvsp[(5) - (6)]).prim, (yyvsp[(3) - (6)]).prim, (yyvsp[(5) - (6)]).dim, (yyvsp[(3) - (6)]).dim); 
                        if((!(yyvsp[(3) - (6)]).prim) && (temp_type>= 0) && ((temp_type<=COMPATIBLE) || temp_type==Matrix || temp_type==State)){
                           (yyval).prim = false; 
                           (yyval).type = temp_type; 
                           (yyval).dim = (yyvsp[(3) - (6)]).dim;
                        } 
                        else{
                           yyerror("semantic error: incompatible operands"); 
                           return 1;
                        }
<<<<<<< HEAD
                        (yyval).str = (char *)malloc(sizeof(char)*(strlen((yyvsp[(5) - (6)]).str)+strlen((yyvsp[(3) - (6)]).str)+strlen((yyvsp[(1) - (6)]).str)+4));
                        snprintf((yyval).str,strlen((yyvsp[(5) - (6)]).str)+strlen((yyvsp[(3) - (6)]).str)+strlen((yyvsp[(1) - (6)]).str)+4,"%s(%s,%s)",(yyvsp[(1) - (6)]).str,(yyvsp[(3) - (6)]).str,(yyvsp[(5) - (6)]).str);
                        free((yyvsp[(3) - (6)]).str);
                        free((yyvsp[(5) - (6)]).str);
=======
                        if((yyvsp[(3) - (6)]).veconst == 0 && (yyvsp[(5) - (6)]).veconst == 0)
                        {
                           (yyval).str = (char *)malloc(sizeof(char)*(strlen((yyvsp[(5) - (6)]).str)+strlen((yyvsp[(3) - (6)]).str)+strlen((yyvsp[(1) - (6)]).str)+4));
                           snprintf((yyval).str,strlen((yyvsp[(5) - (6)]).str)+strlen((yyvsp[(3) - (6)]).str)+8+4,"subLists(%s,%s)",(yyvsp[(1) - (6)]).str,(yyvsp[(3) - (6)]).str,(yyvsp[(5) - (6)]).str);
                           free((yyvsp[(3) - (6)]).str);
                           free((yyvsp[(5) - (6)]).str);
                        }
                        else
                        {
                           yyerror("semantic error : initialize first, cannot directly pass as argument");
                           return 1;
                        }
>>>>>>> temp
                     }
    break;

  case 189:
<<<<<<< HEAD
#line 1076 "./Parser/parser_main.y"
=======
#line 1093 "./Parser/parser_main.y"
>>>>>>> temp
    {
                        temp_type = compatibleCheckAdv((yyvsp[(5) - (6)]).type, (yyvsp[(3) - (6)]).type, (yyvsp[(5) - (6)]).prim, (yyvsp[(3) - (6)]).prim, (yyvsp[(5) - (6)]).dim, (yyvsp[(3) - (6)]).dim); 
                        if((!(yyvsp[(3) - (6)]).prim) && (temp_type>= 0) && (temp_type<=COMPATIBLE)){
                           (yyval).prim = true; 
                           (yyval).type = temp_type; 
                           (yyval).dim = (yyvsp[(3) - (6)]).dim;
                        } 
                        else if((!(yyvsp[(3) - (6)]).prim) && (!(yyvsp[(5) - (6)]).prim) && ((yyvsp[(3) - (6)]).type<=COMPATIBLE) && ((yyvsp[(5) - (6)]).type==Matrix)){
                           (yyval).prim = true; 
                           (yyval).type = Matrix; 
                           (yyval).dim = 0;
                        } 
                        else if((yyvsp[(3) - (6)]).prim && (temp_type==State)){
                           (yyval).prim = true; 
                           (yyval).type = Complex;
                        } 
                        else{
                           yyerror("semantic error: incompatible operands"); 
                           return 1;
                        }
<<<<<<< HEAD
                        if((yyvsp[(3) - (6)]).type != Complex){
=======
                        if((yyvsp[(3) - (6)]).type != Complex && (((yyvsp[(3) - (6)]).veconst == 0 && (yyvsp[(5) - (6)]).veconst == 0))){
>>>>>>> temp
                           (yyval).str = (char *)malloc(sizeof(char)*(strlen((yyvsp[(5) - (6)]).str)+strlen((yyvsp[(3) - (6)]).str)+strlen((yyvsp[(1) - (6)]).str)+4));
                           snprintf((yyval).str,strlen((yyvsp[(5) - (6)]).str)+strlen((yyvsp[(3) - (6)]).str)+strlen((yyvsp[(1) - (6)]).str)+4,"%s(%s,%s)",(yyvsp[(1) - (6)]).str,(yyvsp[(3) - (6)]).str,(yyvsp[(5) - (6)]).str);
                           free((yyvsp[(3) - (6)]).str);
                           free((yyvsp[(5) - (6)]).str);
                        } 
<<<<<<< HEAD
                        else{
=======
                        else if((yyvsp[(3) - (6)]).veconst == 0 && (yyvsp[(5) - (6)]).veconst == 0){
>>>>>>> temp
                           (yyval).str = (char *)malloc(sizeof(char)*(strlen((yyvsp[(5) - (6)]).str)+strlen((yyvsp[(3) - (6)]).str)+24));
                           snprintf((yyval).str,strlen((yyvsp[(5) - (6)]).str)+strlen((yyvsp[(3) - (6)]).str)+24,"dotProductComplex(%s,%s)",(yyvsp[(3) - (6)]).str,(yyvsp[(5) - (6)]).str);
                           free((yyvsp[(3) - (6)]).str);
                           free((yyvsp[(5) - (6)]).str);
                        }
<<<<<<< HEAD
=======
                        else
                        {
                           yyerror("semantic error : initialize first, cannot directly pass as argument");
                           return 1;
                        }
>>>>>>> temp
                     }
    break;

  case 190:
<<<<<<< HEAD
#line 1110 "./Parser/parser_main.y"
=======
#line 1132 "./Parser/parser_main.y"
>>>>>>> temp
    {
                        if((!(yyvsp[(3) - (4)]).prim) && (((yyvsp[(3) - (4)]).type==Uint) || ((yyvsp[(3) - (4)]).type==Int) || ((yyvsp[(3) - (4)]).type==Float))){
                           (yyval).prim = true; 
                           (yyval).type = (yyvsp[(3) - (4)]).type; 
                           (yyval).dim = (yyvsp[(3) - (4)]).dim;
                        } 
                        else{
                           yyerror("semantic error: incompatible operands"); 
                           return 1;
                        }
<<<<<<< HEAD
                        (yyval).str = (char *)malloc(sizeof(char)*(strlen((yyvsp[(3) - (4)]).str)+strlen((yyvsp[(1) - (4)]).str)+3));
                        snprintf((yyval).str,strlen((yyvsp[(3) - (4)]).str)+strlen((yyvsp[(1) - (4)]).str)+3,"%s(%s)",(yyvsp[(1) - (4)]).str,(yyvsp[(3) - (4)]).str);
                        free((yyvsp[(3) - (4)]).str);
=======
                        if(((yyvsp[(3) - (4)]).veconst == 0))
                        {
                        (yyval).str = (char *)malloc(sizeof(char)*(strlen((yyvsp[(3) - (4)]).str)+strlen((yyvsp[(1) - (4)]).str)+3));
                        snprintf((yyval).str,strlen((yyvsp[(3) - (4)]).str)+strlen((yyvsp[(1) - (4)]).str)+3,"%s(%s)",(yyvsp[(1) - (4)]).str,(yyvsp[(3) - (4)]).str);
                        free((yyvsp[(3) - (4)]).str);
                        }
                        else
                        {
yyerror("semantic error : initialize first, cannot directly pass as argument");
                           return 1;
                        }
>>>>>>> temp
                     }
    break;

  case 191:
<<<<<<< HEAD
#line 1125 "./Parser/parser_main.y"
=======
#line 1155 "./Parser/parser_main.y"
>>>>>>> temp
    {
                        if((!(yyvsp[(3) - (4)]).prim) && (((yyvsp[(3) - (4)]).type==Uint) || ((yyvsp[(3) - (4)]).type==Int) || ((yyvsp[(3) - (4)]).type==Float))){
                           (yyval).prim = true; 
                           (yyval).type = (yyvsp[(3) - (4)]).type; 
                           (yyval).dim = (yyvsp[(3) - (4)]).dim;
                        } 
                        else{
                           yyerror("semantic error: incompatible operands");
                           return 1;
                        }
<<<<<<< HEAD
                        (yyval).str = (char *)malloc(sizeof(char)*(strlen((yyvsp[(3) - (4)]).str)+strlen((yyvsp[(1) - (4)]).str)+3));
                        snprintf((yyval).str,strlen((yyvsp[(3) - (4)]).str)+strlen((yyvsp[(1) - (4)]).str)+3,"%s(%s)",(yyvsp[(1) - (4)]).str,(yyvsp[(3) - (4)]).str);
                        free((yyvsp[(3) - (4)]).str);
                     }
    break;

  case 192:
#line 1140 "./Parser/parser_main.y"
=======
                        if(((yyvsp[(3) - (4)]).veconst == 0))
                        {                     (yyval).str = (char *)malloc(sizeof(char)*(strlen((yyvsp[(3) - (4)]).str)+strlen((yyvsp[(1) - (4)]).str)+3));
                        snprintf((yyval).str,strlen((yyvsp[(3) - (4)]).str)+strlen((yyvsp[(1) - (4)]).str)+3,"%s(%s)",(yyvsp[(1) - (4)]).str,(yyvsp[(3) - (4)]).str);
                        free((yyvsp[(3) - (4)]).str);
                     }
                     }
    break;

  case 192:
#line 1172 "./Parser/parser_main.y"
>>>>>>> temp
    { 
                        if((!(yyvsp[(3) - (6)]).prim) && (((yyvsp[(3) - (6)]).type==Uint) || ((yyvsp[(3) - (6)]).type==Int))){
                           (yyval).prim = false; 
                           (yyval).type = (yyvsp[(3) - (6)]).type;
                           (yyval).dim = condenser((yyvsp[(3) - (6)]).dim, 1);
                        } 
                        else{
                           yyerror("semantic error: incompatible operands"); 
                           return 1;
                        }
<<<<<<< HEAD
                        (yyval).str = (char *)malloc(sizeof(char)*(strlen((yyvsp[(1) - (6)]).str)+strlen((yyvsp[(3) - (6)]).str)+23));
                        snprintf((yyval).str,strlen((yyvsp[(1) - (6)]).str)+strlen((yyvsp[(3) - (6)]).str)+23,"%s(%s,1<<%d)",(yyvsp[(1) - (6)]).str,(yyvsp[(3) - (6)]).str,(yyvsp[(5) - (6)]).num);
                        free((yyvsp[(3) - (6)]).str);
=======
                        if(((yyvsp[(3) - (6)]).veconst == 0))
                        {
                           (yyval).str = (char *)malloc(sizeof(char)*(strlen((yyvsp[(1) - (6)]).str)+strlen((yyvsp[(3) - (6)]).str)+23));
                        snprintf((yyval).str,strlen((yyvsp[(1) - (6)]).str)+strlen((yyvsp[(3) - (6)]).str)+23,"%s(%s,1<<%d)",(yyvsp[(1) - (6)]).str,(yyvsp[(3) - (6)]).str,(yyvsp[(5) - (6)]).num);
                        free((yyvsp[(3) - (6)]).str);
                        }
                        else
                        {
                           yyerror("semantic error : initialize first, cannot directly pass as argument");
                           return 1;
                        }
                        
>>>>>>> temp
                     }
    break;

  case 193:
<<<<<<< HEAD
#line 1155 "./Parser/parser_main.y"
    {
                        if((!(yyvsp[(3) - (8)]).prim) && (((yyvsp[(3) - (8)]).type==Uint) || ((yyvsp[(3) - (8)]).type==Int))){
                           (yyval).prim = false; 
                           (yyval).type = (yyvsp[(3) - (8)]).type; 
                           (yyval).dim = condenser((yyvsp[(3) - (8)]).dim, (yyvsp[(6) - (8)]).cond_count);
                        } 
                        else{
                           yyerror("semantic error: incompatible operands"); 
                           return 1;
                        }
                        (yyval).str = (char *)malloc(sizeof(char)*(strlen((yyvsp[(1) - (8)]).str)+strlen((yyvsp[(3) - (8)]).str)+strlen((yyvsp[(6) - (8)]).str)));
                        snprintf((yyval).str,strlen((yyvsp[(1) - (8)]).str)+strlen((yyvsp[(3) - (8)]).str)+20,"%s(%s,(%s))",(yyvsp[(1) - (8)]).str,(yyvsp[(3) - (8)]).str,(yyvsp[(6) - (8)]).str);
                        free((yyvsp[(3) - (8)]).str);
                        free((yyvsp[(6) - (8)]).str);
                     }
    break;

  case 194:
#line 1171 "./Parser/parser_main.y"
=======
#line 1212 "./Parser/parser_main.y"
>>>>>>> temp
    {
                        if((!(yyvsp[(3) - (4)]).prim) && (((yyvsp[(3) - (4)]).type<=COMPATIBLE) || (yyvsp[(3) - (4)]).type==Matrix)){
                           (yyval).prim = true; 
                           (yyval).type = (yyvsp[(3) - (4)]).type; 
                           (yyval).dim = 0;
                        } 
                        else{
                           yyerror("semantic error: incompatible operands"); 
                           return 1;
                        }
<<<<<<< HEAD
                        if((yyvsp[(3) - (4)]).type == Complex){
=======
                        if((yyvsp[(3) - (4)]).type == Complex && ((yyvsp[(3) - (4)]).veconst == 0)){
>>>>>>> temp
                           (yyval).str = (char *)malloc(sizeof(char)*(strlen((yyvsp[(3) - (4)]).str)+24));
                           snprintf((yyval).str,strlen((yyvsp[(3) - (4)]).str)+24,"sumComplex(%s)",(yyvsp[(3) - (4)]).str);
                           free((yyvsp[(3) - (4)]).str);
                        } 
<<<<<<< HEAD
                        else{
=======
                        else if ((yyvsp[(3) - (4)]).veconst == 0){
>>>>>>> temp
                           (yyval).str = (char *)malloc(sizeof(char)*(strlen((yyvsp[(3) - (4)]).str)+strlen((yyvsp[(1) - (4)]).str)+3));
                           snprintf((yyval).str,strlen((yyvsp[(3) - (4)]).str)+strlen((yyvsp[(1) - (4)]).str)+3,"%s(%s)",(yyvsp[(1) - (4)]).str,(yyvsp[(3) - (4)]).str);
                           free((yyvsp[(3) - (4)]).str);
                        }
<<<<<<< HEAD
=======
                        else
                        {
                           yyerror("semantic error : initialize first, cannot directly pass as argument");
                           return 1;
                        }
                     }
    break;

  case 194:
#line 1239 "./Parser/parser_main.y"
    {
                        if((!(yyvsp[(3) - (4)]).prim) && (((yyvsp[(3) - (4)]).type<=COMPATIBLE) || (yyvsp[(3) - (4)]).type==Matrix)){
                           (yyval).prim = true; 
                           (yyval).type = (yyvsp[(3) - (4)]).type; 
                           (yyval).dim = 0;
                        } 
                        else{
                           yyerror("semantic error: incompatible operands"); 
                           return 1;
                        }
                        if((yyvsp[(3) - (4)]).type == Complex && ((yyvsp[(3) - (4)]).veconst == 0)){
                           (yyval).str = (char *)malloc(sizeof(char)*(strlen((yyvsp[(3) - (4)]).str)+24));
                           snprintf((yyval).str,strlen((yyvsp[(3) - (4)]).str)+24,"meanComplex(%s)",(yyvsp[(3) - (4)]).str);
                           free((yyvsp[(3) - (4)]).str);
                        } 
                        else if(((yyvsp[(3) - (4)]).veconst == 0)){
                           (yyval).str = (char *)malloc(sizeof(char)*(strlen((yyvsp[(3) - (4)]).str)+strlen((yyvsp[(1) - (4)]).str)+3));
                           snprintf((yyval).str,strlen((yyvsp[(3) - (4)]).str)+strlen((yyvsp[(1) - (4)]).str)+3,"%s(%s)",(yyvsp[(1) - (4)]).str,(yyvsp[(3) - (4)]).str);
                           free((yyvsp[(3) - (4)]).str);
                        }
                        else
                        {
                           yyerror("semantic error : initialize first, cannot directly pass as argument");
                           return 1;
                        }
>>>>>>> temp
                     }
    break;

  case 195:
<<<<<<< HEAD
#line 1193 "./Parser/parser_main.y"
    {
                        if((!(yyvsp[(3) - (4)]).prim) && (((yyvsp[(3) - (4)]).type<=COMPATIBLE) || (yyvsp[(3) - (4)]).type==Matrix)){
                           (yyval).prim = true; 
                           (yyval).type = (yyvsp[(3) - (4)]).type; 
                           (yyval).dim = 0;
                        } 
                        else{
                           yyerror("semantic error: incompatible operands"); 
                           return 1;
                        }
                        if((yyvsp[(3) - (4)]).type == Complex){
                           (yyval).str = (char *)malloc(sizeof(char)*(strlen((yyvsp[(3) - (4)]).str)+24));
                           snprintf((yyval).str,strlen((yyvsp[(3) - (4)]).str)+24,"meanComplex(%s)",(yyvsp[(3) - (4)]).str);
                           free((yyvsp[(3) - (4)]).str);
                        } 
                        else{
                           (yyval).str = (char *)malloc(sizeof(char)*(strlen((yyvsp[(3) - (4)]).str)+strlen((yyvsp[(1) - (4)]).str)+3));
                           snprintf((yyval).str,strlen((yyvsp[(3) - (4)]).str)+strlen((yyvsp[(1) - (4)]).str)+3,"%s(%s)",(yyvsp[(1) - (4)]).str,(yyvsp[(3) - (4)]).str);
                           free((yyvsp[(3) - (4)]).str);
                        }
                     }
    break;

  case 196:
#line 1219 "./Parser/parser_main.y"
    { if((yyvsp[(1) - (3)]).type <= Int){
                                                      (yyval).cond_count = (yyvsp[(1) - (3)]).cond_count + 1;
                                                   } 
                                                   else{
                                                      yyerror("semantic error: only integer elements permitted"); 
                                                      return 1;
                                                   }
                                                   (yyval).str = (char *)malloc(sizeof(char)*(strlen((yyvsp[(1) - (3)]).str)+strlen((yyvsp[(3) - (3)]).str)+2));
                                                   snprintf((yyval).str,strlen((yyvsp[(1) - (3)]).str)+strlen((yyvsp[(3) - (3)]).str)+2,"%s,%s",(yyvsp[(1) - (3)]).str,(yyvsp[(3) - (3)]).str);
                                                   free((yyvsp[(1) - (3)]).str);
                                                   free((yyvsp[(3) - (3)]).str);
                                                 }
    break;

  case 197:
#line 1231 "./Parser/parser_main.y"
    { if((yyvsp[(1) - (1)]).type <= Int){
                                                      (yyval).cond_count = 1;
                                                   } 
                                                   else{
                                                      yyerror("semantic error: only integer elements permitted"); 
                                                      return 1;
                                                   }
                                                   (yyval).str = (yyvsp[(1) - (1)]).str;
                                                 }
    break;

  case 198:
#line 1243 "./Parser/parser_main.y"
    { (yyval).prim = true; (yyval).type = (yyvsp[(1) - (1)]).type;(yyval).str = (yyvsp[(1) - (1)]).str;}
    break;

  case 199:
#line 1244 "./Parser/parser_main.y"
=======
#line 1294 "./Parser/parser_main.y"
    { (yyval).prim = true; (yyval).type = (yyvsp[(1) - (1)]).type;(yyval).str = (yyvsp[(1) - (1)]).str;}
    break;

  case 196:
#line 1295 "./Parser/parser_main.y"
>>>>>>> temp
    { (yyval).prim = false; (yyval).dim = (yyvsp[(1) - (1)]).dim; 
                                                  (yyval).type = (yyvsp[(1) - (1)]).type; 
                                                  if((yyval).type == Matrix){
                                                      (yyval).rows = (yyvsp[(1) - (1)]).rows;
                                                  } 
                                                  else (yyval).rows = 0;
                                                  (yyval).str = (yyvsp[(1) - (1)]).str;
                                                }
    break;

<<<<<<< HEAD
  case 200:
#line 1252 "./Parser/parser_main.y"
=======
  case 197:
#line 1303 "./Parser/parser_main.y"
>>>>>>> temp
    {  if((yyval).out_flag == 0){
                                                      struct OutputSymbolEntry* sample = getOutputSymbolEntry(&OutputSymbolTable,(yyvsp[(1) - (1)]).str,outputLevel,1); 
                                                      if(sample != NULL){
                                                         (yyval).prim = sample->primitive; 
                                                         (yyval).type = sample->type; 
                                                         if((yyval).type == Matrix){
                                                            (yyval).rows = sample->matrix_dim;
                                                         } 
                                                         if(!(yyval).prim){
                                                            (yyval).dim = sample->dim;
                                                         }
                                                      } 
                                                      else{
                                                         yyerror("semantic error: variable not declared"); 
                                                         return 1;
                                                      }
                                                   } 
                                                   else if((yyval).out_flag == 1){
                                                      (yyval).type = Uint; (yyval).prim = false; 
                                                      (yyval).dim = (classical_registers); 
                                                      (yyval).rows = 0;
                                                   } 
                                                   else{
                                                      (yyval).type = State; 
                                                      (yyval).prim = false; 
                                                      (yyval).dim = quantum_registers; 
                                                      (yyval).rows = 0;
                                                   }
                                                   (yyval).str = (yyvsp[(1) - (1)]).str;
                                                }
    break;

<<<<<<< HEAD
  case 201:
#line 1282 "./Parser/parser_main.y"
=======
  case 198:
#line 1333 "./Parser/parser_main.y"
>>>>>>> temp
    {
                                                   if((yyval).out_flag == 0){
                                                      struct OutputSymbolEntry* sample = getOutputSymbolEntry(&OutputSymbolTable,(yyvsp[(1) - (4)]).str,outputLevel,1); 
                                                      if(sample != NULL){
                                                         if((yyvsp[(3) - (4)]).type <= Uint){
                                                            if(sample->primitive){
                                                               if(sample->type==State){
                                                                  (yyval).type = Complex; 
                                                                  (yyval).prim = true;
                                                               } 
                                                               else{
                                                                  yyerror("semantic error"); 
                                                                  return 1;
                                                               }
                                                            }
                                                            else{
                                                               (yyval).type = sample->type; 
                                                               (yyval).prim = true;
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
                                                   else if((yyval).out_flag == 1){
                                                      (yyval).type = Uint; 
                                                      (yyval).prim = true;
                                                   } 
                                                   else{
                                                      (yyval).type = State; 
                                                      (yyval).prim = true;
                                                   }
                                                   (yyval).str = (char *)malloc(sizeof(char)*(strlen((yyvsp[(1) - (4)]).str)+strlen((yyvsp[(3) - (4)]).str)+3)); 
                                                   snprintf((yyval).str,strlen((yyvsp[(1) - (4)]).str)+strlen((yyvsp[(3) - (4)]).str)+3,"%s[%s]",(yyvsp[(1) - (4)]).str,(yyvsp[(3) - (4)]).str); 
                                                   free((yyvsp[(1) - (4)]).str);
                                                   free((yyvsp[(3) - (4)]).str);
                                                }
    break;

<<<<<<< HEAD
  case 202:
#line 1326 "./Parser/parser_main.y"
=======
  case 199:
#line 1377 "./Parser/parser_main.y"
>>>>>>> temp
    {
                                                   if((yyval).out_flag == 0){
                                                      struct OutputSymbolEntry* sample = getOutputSymbolEntry(&OutputSymbolTable,(yyvsp[(1) - (7)]).str,outputLevel,1); 
                                                      if(sample != NULL){
                                                         if(((yyvsp[(3) - (7)]).type <= Uint) && ((yyvsp[(5) - (7)]).type <= Uint)){
                                                            if(sample->type) {
                                                               if(sample->type==Matrix){
                                                                  (yyval).type = Complex; 
                                                                  (yyval).prim = true;
                                                               } 
                                                               else{
                                                                  yyerror("semantic error: variable not declared"); 
                                                                  return 1;
                                                               }
                                                            } 
                                                            else if(sample->type==State){
                                                               (yyval).type = Complex; 
                                                               (yyval).prim = true;
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
                                                   else if((yyval).out_flag == 1){
                                                      yyerror("semantic error 5");
                                                      return 1;
                                                   } 
                                                   else{
                                                      (yyval).type = Complex; 
                                                      (yyval).prim = true;
                                                   }
                                                   (yyval).str = (char *)malloc(sizeof(char)*(strlen((yyvsp[(1) - (7)]).str)+strlen((yyvsp[(3) - (7)]).str)+strlen((yyvsp[(6) - (7)]).str)+5)); 
                                                   snprintf((yyval).str,strlen((yyvsp[(1) - (7)]).str)+strlen((yyvsp[(3) - (7)]).str)+strlen((yyvsp[(6) - (7)]).str)+5,"%s[%s][%s]",(yyvsp[(1) - (7)]).str,(yyvsp[(3) - (7)]).str,(yyvsp[(6) - (7)]).str);    
                                                   free((yyvsp[(1) - (7)]).str);
                                                   free((yyvsp[(3) - (7)]).str);
                                                   free((yyvsp[(6) - (7)]).str);                                                
                                                }
    break;

<<<<<<< HEAD
  case 203:
#line 1371 "./Parser/parser_main.y"
=======
  case 200:
#line 1422 "./Parser/parser_main.y"
>>>>>>> temp
    {
                                                   if((yyval).out_flag == 0){
                                                      struct OutputSymbolEntry* sample = getOutputSymbolEntry(&OutputSymbolTable,(yyvsp[(1) - (10)]).str,outputLevel,1); 
                                                      if(sample != NULL){
                                                         if(((yyvsp[(3) - (10)]).type <= Uint) && ((yyvsp[(5) - (10)]).type <= Uint) && ((yyvsp[(7) - (10)]).type <= Uint)){
                                                            if(sample->primitive){
                                                               yyerror("semantic error: variable not declared"); 
                                                               return 1;
                                                            } 
                                                            else if(sample->type==Matrix){
                                                               (yyval).type = Complex; 
                                                               (yyval).prim = true;
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
                                                   (yyval).str = (char *)malloc(sizeof(char)*(strlen((yyvsp[(1) - (10)]).str)+strlen((yyvsp[(3) - (10)]).str)+strlen((yyvsp[(6) - (10)]).str)+strlen((yyvsp[(9) - (10)]).str)+5)); 
                                                   snprintf((yyval).str,strlen((yyvsp[(1) - (10)]).str)+strlen((yyvsp[(3) - (10)]).str)+strlen((yyvsp[(6) - (10)]).str)+5,"%s[%s][%s][%s]",(yyvsp[(1) - (10)]).str,(yyvsp[(3) - (10)]).str,(yyvsp[(6) - (10)]).str, (yyvsp[(9) - (10)]).str);    
                                                   free((yyvsp[(1) - (10)]).str);
                                                   free((yyvsp[(3) - (10)]).str);
                                                   free((yyvsp[(6) - (10)]).str); 
                                                   free((yyvsp[(9) - (10)]).str);
                                                }
    break;

<<<<<<< HEAD
  case 204:
#line 1406 "./Parser/parser_main.y"
=======
  case 201:
#line 1457 "./Parser/parser_main.y"
>>>>>>> temp
    {  (yyval).prim = (yyvsp[(1) - (1)]).prim; 
                                                      (yyval).type = (yyvsp[(1) - (1)]).type; 
                                                      if((yyvsp[(1) - (1)]).type == Matrix) (yyval).rows = (yyvsp[(1) - (1)]).rows; 
                                                      if(!(yyval).prim) (yyval).dim = (yyvsp[(1) - (1)]).dim; 
                                                   }
    break;

<<<<<<< HEAD
  case 205:
#line 1411 "./Parser/parser_main.y"
=======
  case 202:
#line 1462 "./Parser/parser_main.y"
>>>>>>> temp
    {   (yyval).type = (yyvsp[(2) - (3)]).type;
                                                      (yyval).prim = (yyvsp[(2) - (3)]).prim;
                                                      (yyval).str = (char *)malloc(sizeof(char)*(strlen((yyvsp[(2) - (3)]).str)+3));
                                                      snprintf((yyval).str,strlen((yyvsp[(2) - (3)]).str)+3,"(%s)",(yyvsp[(2) - (3)]).str);
                                                      free((yyvsp[(2) - (3)]).str);
                                                  }
    break;

<<<<<<< HEAD
  case 206:
#line 1417 "./Parser/parser_main.y"
=======
  case 203:
#line 1468 "./Parser/parser_main.y"
>>>>>>> temp
    {  if((yyvsp[(2) - (2)]).type==Bool && (yyvsp[(2) - (2)]).prim){
                                                         (yyval).prim = true; 
                                                         (yyval).type = Bool;
                                                      } 
                                                      else{
                                                         yyerror("semantic error 9"); 
                                                         return 1;
                                                      }  
                                                      (yyval).str = (char *)malloc(sizeof(char)*(strlen((yyvsp[(2) - (2)]).str)+1));
                                                      snprintf((yyval).str,strlen((yyvsp[(2) - (2)]).str)+2,"!%s",(yyvsp[(2) - (2)]).str);
                                                      free((yyvsp[(2) - (2)]).str);
                                                   }
    break;

<<<<<<< HEAD
  case 207:
#line 1429 "./Parser/parser_main.y"
=======
  case 204:
#line 1480 "./Parser/parser_main.y"
>>>>>>> temp
    {  if((yyvsp[(1) - (3)]).type==Bool && (yyvsp[(1) - (3)]).prim && (yyvsp[(3) - (3)]).type==Bool && (yyvsp[(3) - (3)]).prim){
                                                         (yyval).prim = true; 
                                                         (yyval).type = Bool;
                                                      } 
                                                      else{
                                                         yyerror("semantic error 10"); 
                                                         return 1;
                                                      } 
                                                      (yyval).str = (char *)malloc(sizeof(char)*(strlen((yyvsp[(1) - (3)]).str)+strlen((yyvsp[(3) - (3)]).str)+5));
                                                      snprintf((yyval).str,strlen((yyvsp[(1) - (3)]).str)+strlen((yyvsp[(3) - (3)]).str)+5,"%s && %s",(yyvsp[(1) - (3)]).str,(yyvsp[(3) - (3)]).str);
                                                      free((yyvsp[(1) - (3)]).str);
                                                      free((yyvsp[(3) - (3)]).str);

                                                   }
    break;

<<<<<<< HEAD
  case 208:
#line 1443 "./Parser/parser_main.y"
=======
  case 205:
#line 1494 "./Parser/parser_main.y"
>>>>>>> temp
    {  if((yyvsp[(1) - (3)]).type==Bool && (yyvsp[(1) - (3)]).prim && (yyvsp[(3) - (3)]).type==Bool && (yyvsp[(3) - (3)]).prim){
                                                      (yyval).prim = true; 
                                                      (yyval).type = Bool;
                                                   } 
                                                   else{
                                                      yyerror("semantic error 11"); 
                                                      return 1;
                                                   } 
                                                      (yyval).str = (char *)malloc(sizeof(char)*(strlen((yyvsp[(1) - (3)]).str)+strlen((yyvsp[(3) - (3)]).str)+5));
                                                      snprintf((yyval).str,strlen((yyvsp[(1) - (3)]).str)+strlen((yyvsp[(3) - (3)]).str)+5,"%s || %s",(yyvsp[(1) - (3)]).str,(yyvsp[(3) - (3)]).str);
                                                      free((yyvsp[(1) - (3)]).str);
                                                      free((yyvsp[(3) - (3)]).str);
                                                }
    break;

<<<<<<< HEAD
  case 209:
#line 1456 "./Parser/parser_main.y"
=======
  case 206:
#line 1507 "./Parser/parser_main.y"
>>>>>>> temp
    {  temp_type = compatibleCheckAdv((yyvsp[(1) - (3)]).type, (yyvsp[(3) - (3)]).type, (yyvsp[(1) - (3)]).prim, (yyvsp[(3) - (3)]).prim, (yyvsp[(1) - (3)]).dim, (yyvsp[(3) - (3)]).dim); 
                                                   if(temp_type != -1 && temp_type < COMPARABLE){
                                                      (yyval).prim = true; 
                                                      (yyval).type = Bool;
                                                   } 
                                                   else{
                                                      yyerror("semantic error 12"); 
                                                      return 1;
                                                   }
                                                      (yyval).str = (char *)malloc(sizeof(char)*(strlen((yyvsp[(1) - (3)]).str)+strlen((yyvsp[(3) - (3)]).str)+strlen((yyvsp[(2) - (3)]).str)+3));
                                                      snprintf((yyval).str,strlen((yyvsp[(1) - (3)]).str)+strlen((yyvsp[(3) - (3)]).str)+strlen((yyvsp[(2) - (3)]).str)+3,"%s %s %s",(yyvsp[(1) - (3)]).str,(yyvsp[(2) - (3)]).str,(yyvsp[(3) - (3)]).str);
                                                      free((yyvsp[(1) - (3)]).str);
                                                      free((yyvsp[(3) - (3)]).str);
                                                }
    break;

<<<<<<< HEAD
  case 210:
#line 1470 "./Parser/parser_main.y"
=======
  case 207:
#line 1521 "./Parser/parser_main.y"
>>>>>>> temp
    { temp_type = compatibleCheckAdv((yyvsp[(1) - (3)]).type, (yyvsp[(3) - (3)]).type, (yyvsp[(1) - (3)]).prim, (yyvsp[(3) - (3)]).prim, (yyvsp[(1) - (3)]).dim, (yyvsp[(3) - (3)]).dim); 
                                                      if(temp_type != -1 && temp_type < COMPARABLE){
                                                         (yyval).prim = true; 
                                                         (yyval).type = Bool;
                                                      } 
                                                      else{
                                                         yyerror("semantic error 13"); 
                                                         return 1;
                                                      } 
                                                      (yyval).str = (char *)malloc(sizeof(char)*(strlen((yyvsp[(1) - (3)]).str)+strlen((yyvsp[(3) - (3)]).str)+strlen((yyvsp[(2) - (3)]).str)+3));
                                                      snprintf((yyval).str,strlen((yyvsp[(1) - (3)]).str)+strlen((yyvsp[(3) - (3)]).str)+strlen((yyvsp[(2) - (3)]).str)+3,"%s %s %s",(yyvsp[(1) - (3)]).str,(yyvsp[(2) - (3)]).str,(yyvsp[(3) - (3)]).str);
                                                      free((yyvsp[(1) - (3)]).str);
                                                      free((yyvsp[(3) - (3)]).str); 
                                                   }
    break;

<<<<<<< HEAD
  case 211:
#line 1484 "./Parser/parser_main.y"
    {  temp_type = compatibleCheckAdv((yyvsp[(1) - (3)]).type, (yyvsp[(3) - (3)]).type, (yyvsp[(1) - (3)]).prim, (yyvsp[(3) - (3)]).prim, (yyvsp[(1) - (3)]).dim, (yyvsp[(3) - (3)]).dim); 
                                                      if((yyvsp[(1) - (3)]).prim && (temp_type <= Complex && temp_type >= 0)){
                                                         (yyval).prim = true; 
                                                         (yyval).type = temp_type;
                                                      } 
=======
  case 208:
#line 1535 "./Parser/parser_main.y"
    {  temp_type = compatibleCheckAdv((yyvsp[(1) - (3)]).type, (yyvsp[(3) - (3)]).type, (yyvsp[(1) - (3)]).prim, (yyvsp[(3) - (3)]).prim, (yyvsp[(1) - (3)]).dim, (yyvsp[(3) - (3)]).dim);
                                                      int f = 0;
                                                      if (((yyvsp[(1) - (3)]).prim && (yyvsp[(3) - (3)]).prim) && (((yyvsp[(1) - (3)]).type == String && (yyvsp[(3) - (3)]).type == Uint) || ((yyvsp[(3) - (3)]).type == String && (yyvsp[(1) - (3)]).type == Uint))) {
                                                         (yyval).prim = true; 
                                                         (yyval).type = String;
                                                         f = 1;
                                                      }
>>>>>>> temp
                                                      else if((yyvsp[(1) - (3)]).prim && (yyvsp[(3) - (3)]).prim && (yyvsp[(1) - (3)]).type<=Complex && (yyvsp[(3) - (3)]).type==Matrix){
                                                         (yyval).prim = true; 
                                                         (yyval).type = Matrix;
                                                      } 
<<<<<<< HEAD
                                                      else if (((yyvsp[(1) - (3)]).prim && (yyvsp[(3) - (3)]).prim) && (((yyvsp[(1) - (3)]).type == String && (yyvsp[(3) - (3)]).type == Uint) || ((yyvsp[(3) - (3)]).type == String && (yyvsp[(1) - (3)]).type == Uint))) {
                                                         (yyval).prim = true; 
                                                         (yyval).type = String;
=======
                                                      else if((yyvsp[(1) - (3)]).prim && (temp_type <= Complex && temp_type >= 0)){
                                                         (yyval).prim = true; 
                                                         (yyval).type = temp_type;
>>>>>>> temp
                                                      } 
                                                      else{
                                                         yyerror("semantic error 14"); 
                                                         return 1;
                                                      }
<<<<<<< HEAD
                                                      (yyval).str = (char *)malloc(sizeof(char)*(strlen((yyvsp[(1) - (3)]).str)+strlen((yyvsp[(3) - (3)]).str)+4));
                                                      snprintf((yyval).str,strlen((yyvsp[(1) - (3)]).str)+strlen((yyvsp[(3) - (3)]).str)+4,"%s * %s",(yyvsp[(1) - (3)]).str,(yyvsp[(3) - (3)]).str);
                                                      free((yyvsp[(1) - (3)]).str);
                                                      free((yyvsp[(3) - (3)]).str);
                                                   }
    break;

  case 212:
#line 1506 "./Parser/parser_main.y"
=======
                                                      if(f == 0)
                                                      {
                                                         (yyval).str = (char *)malloc(sizeof(char)*(strlen((yyvsp[(1) - (3)]).str)+strlen((yyvsp[(3) - (3)]).str)+4));
                                                         snprintf((yyval).str,strlen((yyvsp[(1) - (3)]).str)+strlen((yyvsp[(3) - (3)]).str)+4,"%s * %s",(yyvsp[(1) - (3)]).str,(yyvsp[(3) - (3)]).str);
                                                         free((yyvsp[(1) - (3)]).str);
                                                         free((yyvsp[(3) - (3)]).str);
                                                      }
                                                      else if((yyvsp[(1) - (3)]).type == String && (yyvsp[(3) - (3)]).type == Uint)
                                                      {
                                                         (yyval).str = (char *)malloc(sizeof(char)*(strlen((yyvsp[(1) - (3)]).str)+strlen((yyvsp[(3) - (3)]).str)+16));
                                                         snprintf((yyval).str,strlen((yyvsp[(1) - (3)]).str)+strlen((yyvsp[(3) - (3)]).str)+16,"repeatString(%s,%s)",(yyvsp[(1) - (3)]).str,(yyvsp[(3) - (3)]).str);
                                                         free((yyvsp[(1) - (3)]).str);
                                                         free((yyvsp[(3) - (3)]).str);
                                                      }
                                                      else if((yyvsp[(3) - (3)]).type == String && (yyvsp[(1) - (3)]).type == Uint)
                                                      {
                                                         (yyval).str = (char *)malloc(sizeof(char)*(strlen((yyvsp[(3) - (3)]).str)+strlen((yyvsp[(1) - (3)]).str)+16));
                                                         snprintf((yyval).str,strlen((yyvsp[(3) - (3)]).str)+strlen((yyvsp[(1) - (3)]).str)+16,"repeatString(%s,%s)",(yyvsp[(3) - (3)]).str,(yyvsp[(1) - (3)]).str);
                                                         free((yyvsp[(1) - (3)]).str);
                                                         free((yyvsp[(3) - (3)]).str);
                                                      }
                                                   }
    break;

  case 209:
#line 1576 "./Parser/parser_main.y"
>>>>>>> temp
    {  temp_type = compatibleCheckAdv((yyvsp[(1) - (3)]).type, (yyvsp[(3) - (3)]).type, (yyvsp[(1) - (3)]).prim, (yyvsp[(3) - (3)]).prim, (yyvsp[(1) - (3)]).dim, (yyvsp[(3) - (3)]).dim); 
                                                      if((yyvsp[(1) - (3)]).prim && (temp_type <= Complex && temp_type >= 0)){
                                                         (yyval).prim = true; 
                                                         (yyval).type = temp_type;
                                                      } 
                                                      else{
                                                         yyerror("semantic error 15"); 
                                                         return 1;
                                                      }
                                                      (yyval).str = (char *)malloc(sizeof(char)*(strlen((yyvsp[(1) - (3)]).str)+strlen((yyvsp[(3) - (3)]).str)+4));
                                                      snprintf((yyval).str,strlen((yyvsp[(1) - (3)]).str)+strlen((yyvsp[(3) - (3)]).str)+4,"%s / %s",(yyvsp[(1) - (3)]).str,(yyvsp[(3) - (3)]).str);
                                                      free((yyvsp[(1) - (3)]).str);
                                                      free((yyvsp[(3) - (3)]).str);
                                                   }
    break;

<<<<<<< HEAD
  case 213:
#line 1521 "./Parser/parser_main.y"
=======
  case 210:
#line 1591 "./Parser/parser_main.y"
>>>>>>> temp
    {  temp_type = compatibleCheckAdv((yyvsp[(1) - (3)]).type, (yyvsp[(3) - (3)]).type, (yyvsp[(1) - (3)]).prim, (yyvsp[(3) - (3)]).prim, (yyvsp[(1) - (3)]).dim, (yyvsp[(3) - (3)]).dim); 
                                                      if(temp_type == Matrix || temp_type == State || (temp_type <= Complex && temp_type >= 0)){
                                                         (yyval).prim = (yyvsp[(1) - (3)]).prim; 
                                                         (yyval).type = temp_type; 
                                                         if(temp_type == Matrix){
                                                            (yyval).rows=(yyvsp[(1) - (3)]).rows;
                                                         } 
                                                         (yyval).dim=(yyvsp[(1) - (3)]).dim;
                                                      } 
                                                      else if (((yyvsp[(1) - (3)]).prim==true) && ((yyvsp[(1) - (3)]).type == String)){
                                                         (yyval).prim = true; 
                                                         (yyval).type = String;
                                                      } 
                                                      else{
                                                         yyerror("semantic error 16");
                                                         return 1;
                                                      }
                                                      if((yyvsp[(1) - (3)]).prim){
                                                         (yyval).str = (char *)malloc(sizeof(char)*(strlen((yyvsp[(1) - (3)]).str)+strlen((yyvsp[(3) - (3)]).str)+4));
                                                         snprintf((yyval).str,strlen((yyvsp[(1) - (3)]).str)+strlen((yyvsp[(3) - (3)]).str)+4,"%s + %s",(yyvsp[(1) - (3)]).str,(yyvsp[(3) - (3)]).str);
                                                         free((yyvsp[(1) - (3)]).str);
                                                         free((yyvsp[(3) - (3)]).str);
                                                      } 
<<<<<<< HEAD
                                                      else{
                                                         (yyval).str = (char *)malloc(sizeof(char)*(strlen((yyvsp[(1) - (3)]).str)+strlen((yyvsp[(3) - (3)]).str)+12));
                                                         snprintf((yyval).str,strlen((yyvsp[(1) - (3)]).str)+strlen((yyvsp[(3) - (3)]).str)+12,"addLists(%s,%s)",(yyvsp[(1) - (3)]).str,(yyvsp[(3) - (3)]).str);
                                                         free((yyvsp[(1) - (3)]).str);
                                                         free((yyvsp[(3) - (3)]).str);

=======
                                                      else if((yyvsp[(1) - (3)]).veconst == 0 && (yyvsp[(3) - (3)]).veconst == 0){
                                                         (yyval).str = (char *)malloc(sizeof(char)*(strlen((yyvsp[(1) - (3)]).str)+strlen((yyvsp[(3) - (3)]).str)+12));
                                                         snprintf((yyval).str,strlen((yyvsp[(1) - (3)]).str)+strlen((yyvsp[(3) - (3)]).str)+12,"add(%s,%s)",(yyvsp[(1) - (3)]).str,(yyvsp[(3) - (3)]).str);
                                                         free((yyvsp[(1) - (3)]).str);
                                                         free((yyvsp[(3) - (3)]).str);
                                                      }
                                                      else 
                                                      {
                                                         yyerror("semantic error : initialize first, cannot directly pass as argument");
                                                         return 1;
>>>>>>> temp
                                                      }
                                                   }
    break;

<<<<<<< HEAD
  case 214:
#line 1552 "./Parser/parser_main.y"
=======
  case 211:
#line 1626 "./Parser/parser_main.y"
>>>>>>> temp
    {  temp_type = compatibleCheckAdv((yyvsp[(1) - (3)]).type, (yyvsp[(3) - (3)]).type, (yyvsp[(1) - (3)]).prim, (yyvsp[(3) - (3)]).prim, (yyvsp[(1) - (3)]).dim, (yyvsp[(3) - (3)]).dim); 
                                                      if(temp_type == Matrix || temp_type == State || (temp_type <= Complex && temp_type >= 0)){
                                                         (yyval).prim = (yyvsp[(1) - (3)]).prim; 
                                                         (yyval).type = temp_type; 
                                                         if(temp_type == Matrix) (yyval).rows=(yyvsp[(1) - (3)]).rows; 
                                                         (yyval).dim=(yyvsp[(1) - (3)]).dim;
                                                      } 
                                                      else{
                                                         yyerror("semantic error 17");
                                                         return 1;
                                                      } 
                                                      if((yyvsp[(1) - (3)]).prim){
                                                         (yyval).str = (char *)malloc(sizeof(char)*(strlen((yyvsp[(1) - (3)]).str)+strlen((yyvsp[(3) - (3)]).str)+4));
                                                         snprintf((yyval).str,strlen((yyvsp[(1) - (3)]).str)+strlen((yyvsp[(3) - (3)]).str)+4,"%s - %s",(yyvsp[(1) - (3)]).str,(yyvsp[(3) - (3)]).str);
                                                         free((yyvsp[(1) - (3)]).str);
                                                         free((yyvsp[(3) - (3)]).str);
                                                      } 
<<<<<<< HEAD
                                                      else{
                                                         (yyval).str = (char *)malloc(sizeof(char)*(strlen((yyvsp[(1) - (3)]).str)+strlen((yyvsp[(3) - (3)]).str)+12));
                                                         snprintf((yyval).str,strlen((yyvsp[(1) - (3)]).str)+strlen((yyvsp[(3) - (3)]).str)+12,"subLists(%s,%s)",(yyvsp[(1) - (3)]).str,(yyvsp[(3) - (3)]).str);
                                                         free((yyvsp[(1) - (3)]).str);
                                                         free((yyvsp[(3) - (3)]).str);
=======
                                                      else if((yyvsp[(1) - (3)]).veconst == 0 && (yyvsp[(3) - (3)]).veconst == 0){
                                                         (yyval).str = (char *)malloc(sizeof(char)*(strlen((yyvsp[(1) - (3)]).str)+strlen((yyvsp[(3) - (3)]).str)+12));
                                                         snprintf((yyval).str,strlen((yyvsp[(1) - (3)]).str)+strlen((yyvsp[(3) - (3)]).str)+12,"sub(%s,%s)",(yyvsp[(1) - (3)]).str,(yyvsp[(3) - (3)]).str);
                                                         free((yyvsp[(1) - (3)]).str);
                                                         free((yyvsp[(3) - (3)]).str);
                                                      }
                                                      else
                                                      {
                                                         /* Cannot initialize */
                                                         yyerror("semantic error : initialize first, cannot directly pass as argument");
                                                         return 1;
>>>>>>> temp
                                                      }                                                      
                                                   }
    break;

<<<<<<< HEAD
  case 215:
#line 1576 "./Parser/parser_main.y"
=======
  case 212:
#line 1656 "./Parser/parser_main.y"
>>>>>>> temp
    {  temp_type = compatibleCheckAdv((yyvsp[(1) - (3)]).type, (yyvsp[(3) - (3)]).type, (yyvsp[(1) - (3)]).prim, (yyvsp[(3) - (3)]).prim, (yyvsp[(1) - (3)]).dim, (yyvsp[(3) - (3)]).dim); 
                                                      if((yyvsp[(1) - (3)]).prim && temp_type == Matrix){
                                                         if((yyvsp[(1) - (3)]).rows == (yyvsp[(3) - (3)]).rows){
                                                            (yyval).prim = true; 
                                                            (yyval).type = temp_type; 
                                                            (yyval).rows = (yyvsp[(1) - (3)]).rows;
                                                         } 
                                                         else{
                                                            yyerror("semantic error 18"); 
                                                            return 1;
                                                         }
                                                      } 
                                                      else if((yyvsp[(1) - (3)]).prim && temp_type == State){
                                                         (yyval).prim = true; 
                                                         (yyval).type = Complex;
                                                      } 
                                                      else if(!(yyvsp[(1) - (3)]).prim && (temp_type <= COMPATIBLE) && (temp_type >= 0)){
                                                         (yyval).prim = true; 
<<<<<<< HEAD
                                                         (yyval).type = temp_type; 
=======
                                                         (yyval).type = Float; 
>>>>>>> temp
                                                         (yyval).dim = 0;
                                                      } 
                                                      else if((yyvsp[(1) - (3)]).type==Complex && (yyvsp[(3) - (3)]).type==Matrix){
                                                         (yyval).prim = true; 
                                                         (yyval).type = Matrix; 
                                                         (yyval).dim = 0;
                                                      } 
                                                      else{
                                                         yyerror("semantic error 19"); 
                                                         return 1;
                                                      }
                                                      if((yyvsp[(1) - (3)]).prim && temp_type == Matrix)
                                                      {
                                                         (yyval).str = (char *)malloc(sizeof(char)*(strlen((yyvsp[(1) - (3)]).str)+strlen((yyvsp[(3) - (3)]).str)+4));
                                                         snprintf((yyval).str,strlen((yyvsp[(1) - (3)]).str)+strlen((yyvsp[(3) - (3)]).str)+4,"%s * %s",(yyvsp[(1) - (3)]).str,(yyvsp[(3) - (3)]).str);
                                                         free((yyvsp[(1) - (3)]).str);
                                                         free((yyvsp[(3) - (3)]).str);
                                                      } 
<<<<<<< HEAD
                                                      else if(!(yyvsp[(1) - (3)]).prim && temp_type <= Float){
                                                         (yyval).str = (char *)malloc(sizeof(char)*(strlen((yyvsp[(1) - (3)]).str)+strlen((yyvsp[(3) - (3)]).str)+14));
                                                         snprintf((yyval).str,strlen((yyvsp[(1) - (3)]).str)+strlen((yyvsp[(3) - (3)]).str)+14,"dotProduct(%s,%s)",(yyvsp[(1) - (3)]).str,(yyvsp[(3) - (3)]).str);
                                                         free((yyvsp[(1) - (3)]).str);
                                                         free((yyvsp[(3) - (3)]).str);
                                                      }
                                                      else if(!(yyvsp[(1) - (3)]).prim && temp_type == Complex)
=======
                                                      else if((!(yyvsp[(1) - (3)]).prim && temp_type <= Float) && ((yyvsp[(1) - (3)]).veconst == 0 && (yyvsp[(3) - (3)]).veconst == 0)){
                                                         (yyval).str = (char *)malloc(sizeof(char)*(strlen((yyvsp[(1) - (3)]).str)+strlen((yyvsp[(3) - (3)]).str)+14));
                                                         snprintf((yyval).str,strlen((yyvsp[(1) - (3)]).str)+strlen((yyvsp[(3) - (3)]).str)+14,"dot(%s,%s)",(yyvsp[(1) - (3)]).str,(yyvsp[(3) - (3)]).str);
                                                         free((yyvsp[(1) - (3)]).str);
                                                         free((yyvsp[(3) - (3)]).str);
                                                      }
                                                      else if(!(yyvsp[(1) - (3)]).prim && temp_type == Complex  && ((yyvsp[(1) - (3)]).veconst == 0 && (yyvsp[(3) - (3)]).veconst == 0))
>>>>>>> temp
                                                      {
                                                         (yyval).str = (char *)malloc(sizeof(char)*(strlen((yyvsp[(1) - (3)]).str)+strlen((yyvsp[(3) - (3)]).str)+21));
                                                         snprintf((yyval).str,strlen((yyvsp[(1) - (3)]).str)+strlen((yyvsp[(3) - (3)]).str)+21,"dotProductComplex(%s,%s)",(yyvsp[(1) - (3)]).str,(yyvsp[(3) - (3)]).str);
                                                         free((yyvsp[(1) - (3)]).str);
                                                         free((yyvsp[(3) - (3)]).str);
                                                      } 
<<<<<<< HEAD
                                                      else if(!(yyvsp[(1) - (3)]).prim && !(yyvsp[(3) - (3)]).prim && ((yyvsp[(1) - (3)]).type == Complex) && ((yyvsp[(3) - (3)]).type == Matrix)){
=======
                                                      else if(!(yyvsp[(1) - (3)]).prim && !(yyvsp[(3) - (3)]).prim && ((yyvsp[(1) - (3)]).type == Complex) && ((yyvsp[(3) - (3)]).type == Matrix)  && ((yyvsp[(1) - (3)]).veconst == 0 && (yyvsp[(3) - (3)]).veconst == 0)){
>>>>>>> temp
                                                         (yyval).str = (char *)malloc(sizeof(char)*(strlen((yyvsp[(1) - (3)]).str)+strlen((yyvsp[(3) - (3)]).str)+19));
                                                         snprintf((yyval).str,strlen((yyvsp[(1) - (3)]).str)+strlen((yyvsp[(3) - (3)]).str)+19,"dotProductCross(%s,%s)",(yyvsp[(1) - (3)]).str,(yyvsp[(3) - (3)]).str);
                                                         free((yyvsp[(1) - (3)]).str);
                                                         free((yyvsp[(3) - (3)]).str);
                                                      }
<<<<<<< HEAD
                                                   }
    break;

  case 216:
#line 1634 "./Parser/parser_main.y"
=======
                                                      else
                                                      {
                                                         yyerror("semantic error : initialize first, cannot directly pass as argument");
                                                         return 1;
                                                      }
                                                   }
    break;

  case 213:
#line 1719 "./Parser/parser_main.y"
>>>>>>> temp
    {  temp_type = compatibleCheckAdv((yyvsp[(1) - (3)]).type, (yyvsp[(3) - (3)]).type, (yyvsp[(1) - (3)]).prim, (yyvsp[(3) - (3)]).prim, (yyvsp[(1) - (3)]).dim, (yyvsp[(3) - (3)]).dim); 
                                                      if(temp_type <= Int){
                                                         (yyval).prim = (yyvsp[(1) - (3)]).prim; 
                                                         (yyval).type = temp_type;
                                                      } 
                                                      else{
                                                         yyerror("semantic error: incompatible operands"); 
                                                         return 1;
                                                      }
                                                      if((yyvsp[(1) - (3)]).prim){
                                                         (yyval).str = (char *)malloc(sizeof(char)*(strlen((yyvsp[(1) - (3)]).str)+strlen((yyvsp[(3) - (3)]).str)+4));
                                                         snprintf((yyval).str,strlen((yyvsp[(1) - (3)]).str)+strlen((yyvsp[(3) - (3)]).str)+4,"%s & %s",(yyvsp[(1) - (3)]).str,(yyvsp[(3) - (3)]).str);
                                                         free((yyvsp[(1) - (3)]).str);
                                                         free((yyvsp[(3) - (3)]).str);
                                                      } 
<<<<<<< HEAD
                                                      else{
=======
                                                      else if((yyvsp[(1) - (3)]).veconst == 0 && (yyvsp[(3) - (3)]).veconst == 0){
>>>>>>> temp
                                                         (yyval).str = (char *)malloc(sizeof(char)*(strlen((yyvsp[(1) - (3)]).str)+strlen((yyvsp[(3) - (3)]).str)+14));
                                                         snprintf((yyval).str,strlen((yyvsp[(1) - (3)]).str)+strlen((yyvsp[(3) - (3)]).str)+14,"bitwiseAnd(%s,%s)",(yyvsp[(1) - (3)]).str,(yyvsp[(3) - (3)]).str);
                                                         free((yyvsp[(1) - (3)]).str);
                                                         free((yyvsp[(3) - (3)]).str);
                                                      }
<<<<<<< HEAD
                                                   }
    break;

  case 217:
#line 1657 "./Parser/parser_main.y"
=======
                                                      else
                                                      {
                                                         yyerror("semantic error : initialize first, cannot directly pass as argument");
                                                         return 1;
                                                      }
                                                   }
    break;

  case 214:
#line 1747 "./Parser/parser_main.y"
>>>>>>> temp
    {  temp_type = compatibleCheckAdv((yyvsp[(1) - (3)]).type, (yyvsp[(3) - (3)]).type, (yyvsp[(1) - (3)]).prim, (yyvsp[(3) - (3)]).prim, (yyvsp[(1) - (3)]).dim, (yyvsp[(3) - (3)]).dim); 
                                                      if(temp_type <= Int){
                                                         (yyval).prim = (yyvsp[(1) - (3)]).prim; 
                                                         (yyval).type = temp_type;
                                                      } 
                                                      else{
                                                         yyerror("semantic error: incompatible operands"); 
                                                         return 1;
                                                      }
                                                      if((yyvsp[(1) - (3)]).prim){
                                                         (yyval).str = (char *)malloc(sizeof(char)*(strlen((yyvsp[(1) - (3)]).str)+strlen((yyvsp[(3) - (3)]).str)+4));
                                                         snprintf((yyval).str,strlen((yyvsp[(1) - (3)]).str)+strlen((yyvsp[(3) - (3)]).str)+4,"%s ^ %s",(yyvsp[(1) - (3)]).str,(yyvsp[(3) - (3)]).str);
                                                         free((yyvsp[(1) - (3)]).str);
                                                         free((yyvsp[(3) - (3)]).str);
                                                      } 
<<<<<<< HEAD
                                                      else{
=======
                                                      else if((yyvsp[(1) - (3)]).veconst == 0 && (yyvsp[(3) - (3)]).veconst == 0){
>>>>>>> temp
                                                         (yyval).str = (char *)malloc(sizeof(char)*(strlen((yyvsp[(1) - (3)]).str)+strlen((yyvsp[(3) - (3)]).str)+14));
                                                         snprintf((yyval).str,strlen((yyvsp[(1) - (3)]).str)+strlen((yyvsp[(3) - (3)]).str)+14,"bitwiseXor(%s,%s)",(yyvsp[(1) - (3)]).str,(yyvsp[(3) - (3)]).str);
                                                         free((yyvsp[(1) - (3)]).str);
                                                         free((yyvsp[(3) - (3)]).str);
<<<<<<< HEAD
                                                      }                                                     
                                                   }
    break;

  case 218:
#line 1680 "./Parser/parser_main.y"
=======
                                                      }   
                                                      else
                                                      {
                                                         yyerror("semantic error : initialize first, cannot directly pass as argument");
                                                         return 1;
                                                      }                                                  
                                                   }
    break;

  case 215:
#line 1775 "./Parser/parser_main.y"
>>>>>>> temp
    { temp_type = compatibleCheckAdv((yyvsp[(1) - (3)]).type, (yyvsp[(3) - (3)]).type, (yyvsp[(1) - (3)]).prim, (yyvsp[(3) - (3)]).prim, (yyvsp[(1) - (3)]).dim, (yyvsp[(3) - (3)]).dim); 
                                                      if(temp_type <= Int){
                                                         (yyval).prim = (yyvsp[(1) - (3)]).prim; 
                                                         (yyval).type = temp_type;
                                                      } 
                                                      else{
                                                         yyerror("semantic error: incompatible operands"); 
                                                         return 1;
                                                      }
                                                      if((yyvsp[(1) - (3)]).prim){
                                                         (yyval).str = (char *)malloc(sizeof(char)*(strlen((yyvsp[(1) - (3)]).str)+strlen((yyvsp[(3) - (3)]).str)+4));
                                                         snprintf((yyval).str,strlen((yyvsp[(1) - (3)]).str)+strlen((yyvsp[(3) - (3)]).str)+4,"%s | %s",(yyvsp[(1) - (3)]).str,(yyvsp[(3) - (3)]).str);
                                                         free((yyvsp[(1) - (3)]).str);
                                                         free((yyvsp[(3) - (3)]).str);
                                                      } 
<<<<<<< HEAD
                                                      else{
=======
                                                      else if ((yyvsp[(1) - (3)]).veconst == 0 && (yyvsp[(3) - (3)]).veconst == 0){
>>>>>>> temp
                                                         (yyval).str = (char *)malloc(sizeof(char)*(strlen((yyvsp[(1) - (3)]).str)+strlen((yyvsp[(3) - (3)]).str)+13));
                                                         snprintf((yyval).str,strlen((yyvsp[(1) - (3)]).str)+strlen((yyvsp[(3) - (3)]).str)+13,"bitwiseOr(%s,%s)",(yyvsp[(1) - (3)]).str,(yyvsp[(3) - (3)]).str);
                                                         free((yyvsp[(1) - (3)]).str);
                                                         free((yyvsp[(3) - (3)]).str);
                                                      }
<<<<<<< HEAD
                                                   }
    break;

  case 219:
#line 1705 "./Parser/parser_main.y"
=======
                                                      else
                                                      {
                                                         yyerror("semantic error : initialize first, cannot directly pass as argument");
                                                         return 1;
                                                      }
                                                   }
    break;

  case 216:
#line 1805 "./Parser/parser_main.y"
>>>>>>> temp
    {  fprintf(fp,"expression statement\n"); 
                                                      if(isDeclaration){
                                                         (yyval).type = (yyvsp[(3) - (3)]).type; 
                                                         assignString((yyval).str,(yyvsp[(1) - (3)]).str);
                                                         (yyval).prim = (yyvsp[(3) - (3)]).prim; 
                                                         if(!(yyvsp[(3) - (3)]).prim) (yyval).dim = (yyvsp[(3) - (3)]).dim; 
                                                         if((yyvsp[(3) - (3)]).type == Matrix) (yyval).rows = (yyvsp[(3) - (3)]).rows; 
                                                      } 
                                                      else{
                                                         struct OutputSymbolEntry* entry = getOutputSymbolEntry(&OutputSymbolTable,(yyvsp[(1) - (3)]).str,outputLevel,1); if(entry->type != (yyvsp[(3) - (3)]).type){
                                                            yyerror("semantic error 20"); 
                                                            return 1;
                                                         }
                                                      }
                                                      
                                                      (yyval).str2 = (char *)malloc(sizeof(char)*(strlen((yyvsp[(1) - (3)]).str)+strlen((yyvsp[(3) - (3)]).str)+5));
                                                      snprintf((yyval).str2,strlen((yyvsp[(1) - (3)]).str)+strlen((yyvsp[(3) - (3)]).str)+10,"%s = %s;",(yyvsp[(1) - (3)]).str,(yyvsp[(3) - (3)]).str);
                                                   }
    break;

<<<<<<< HEAD
  case 220:
#line 1725 "./Parser/parser_main.y"
=======
  case 217:
#line 1825 "./Parser/parser_main.y"
>>>>>>> temp
    {  fprintf(fp,"Primitive datatype declaration statement\n"); 
                                                      if(getOutputSymbolEntry(&OutputSymbolTable,(yyvsp[(2) - (2)]).str,outputLevel,0) != NULL){
                                                         yyerror("semantic error: variable redeclaration"); 
                                                         return 1;
                                                      } 
                                                      else if(((yyvsp[(2) - (2)]).prim==false) || (((yyvsp[(1) - (2)]).type < COMPATIBLE) && ((yyvsp[(1) - (2)]).type < (yyvsp[(2) - (2)]).type)) || (((yyvsp[(1) - (2)]).type >= COMPATIBLE) && ((yyvsp[(1) - (2)]).type != (yyvsp[(2) - (2)]).type))){
                                                         yyerror("semantic error: incompatible types"); 
                                                         return 1;
                                                      } 
                                                      else{
                                                         if((yyvsp[(2) - (2)]).type == Matrix) insertInOutputTable(&OutputSymbolTable,(yyvsp[(2) - (2)]).str,outputLevel,(yyvsp[(2) - (2)]).type,true,(yyvsp[(2) - (2)]).rows,0,false);
                                                         else insertInOutputTable(&OutputSymbolTable,(yyvsp[(2) - (2)]).str,outputLevel,(yyvsp[(2) - (2)]).type,true,0,0,false);
                                                      }
                                                      // printing declaration statements to cpp file
                                                      fprintf(out,"%s\n",(yyvsp[(2) - (2)]).str2);
                                                   }
    break;

<<<<<<< HEAD
  case 221:
#line 1742 "./Parser/parser_main.y"
=======
  case 218:
#line 1842 "./Parser/parser_main.y"
>>>>>>> temp
    {  fprintf(fp,"List datatype declaration statement\n"); 
                                                      if(getOutputSymbolEntry(&OutputSymbolTable,(yyvsp[(2) - (2)]).str,outputLevel,0) != NULL){
                                                         yyerror("semantic error: variable redeclaration"); 
                                                         return 1;
                                                      } 
                        else if(((yyvsp[(2) - (2)]).prim==true) || (((yyvsp[(1) - (2)]).type < COMPATIBLE) && ((yyvsp[(1) - (2)]).type < (yyvsp[(2) - (2)]).type)) || (((yyvsp[(1) - (2)]).type >= COMPATIBLE) && ((yyvsp[(1) - (2)]).type != (yyvsp[(2) - (2)]).type))){
                                                         yyerror("semantic error: incompatible types"); 
                                                         return 1;
                                                      } 
                                                      else{
                                                         if((yyvsp[(2) - (2)]).type == Matrix)insertInOutputTable(&OutputSymbolTable,(yyvsp[(2) - (2)]).str,outputLevel,(yyvsp[(1) - (2)]).type,false,(yyvsp[(2) - (2)]).rows,(yyvsp[(2) - (2)]).dim,false); 
                                                         else insertInOutputTable(&OutputSymbolTable,(yyvsp[(2) - (2)]).str,outputLevel,(yyvsp[(1) - (2)]).type,false,0,(yyvsp[(2) - (2)]).dim,false);
                                                      }
                                                      fprintf(out,"%s\n",(yyvsp[(2) - (2)]).str2);
                                                   }
    break;

<<<<<<< HEAD
  case 222:
#line 1760 "./Parser/parser_main.y"
=======
  case 219:
#line 1860 "./Parser/parser_main.y"
>>>>>>> temp
    {  fprintf(fp,"Echo statement\n");
                                                      }
    break;

<<<<<<< HEAD
  case 223:
#line 1764 "./Parser/parser_main.y"
=======
  case 220:
#line 1864 "./Parser/parser_main.y"
>>>>>>> temp
    {  
                                                         if((yyvsp[(3) - (3)]).prim){
                                                            if((yyval).type == Bool){
                                                               fprintf(out,"cout<<(%s);",(yyvsp[(3) - (3)]).str);
                                                            }
                                                            else{
                                                               fprintf(out,"cout<<%s;",(yyvsp[(3) - (3)]).str);
                                                            }
                                                         }
                                                         else{
                                                               fprintf(out,"for(int i=0;i<%d;i++){\n"
                                                                           "\tcout<<%s[i]<<\" \";"
                                                                           "}\n"
                                                               , (yyvsp[(3) - (3)]).dim, (yyvsp[(3) - (3)]).str);
                                                         }
                                                      }
    break;

<<<<<<< HEAD
  case 224:
#line 1780 "./Parser/parser_main.y"
=======
  case 221:
#line 1880 "./Parser/parser_main.y"
>>>>>>> temp
    {    
                                                         if((yyvsp[(1) - (1)]).prim){
                                                            if((yyval).type == Bool){
                                                               fprintf(out,"cout<<(%s);",(yyvsp[(1) - (1)]).str);
                                                            }
                                                            else{
                                                               fprintf(out,"cout<<%s;",(yyvsp[(1) - (1)]).str);
                                                            }                                                            
                                                         }
                                                         else{
                                                            fprintf(out,"for(int i=0;i<%d;i++){\n"
                                                                        "\tcout<<%s[i]<<\" \";"
                                                                        "}\n", (yyvsp[(1) - (1)]).dim, (yyvsp[(1) - (1)]).str
                                                                   );
                                                         }
                                                      }
    break;

<<<<<<< HEAD
  case 225:
#line 1799 "./Parser/parser_main.y"
    {fprintf(fp,"Save statement\n");}
    break;

  case 226:
#line 1803 "./Parser/parser_main.y"
    {fprintf(fp,"Output section conditional statement begins\n");}
    break;

  case 227:
#line 1803 "./Parser/parser_main.y"
    {fprintf(fp,"Output section conditional statement ends\n");}
    break;

  case 228:
#line 1804 "./Parser/parser_main.y"
    {fprintf(fp,"For statement in output section\n");}
    break;

  case 229:
#line 1805 "./Parser/parser_main.y"
    {fprintf(fp,"For - lex statement in output section\n");}
    break;

  case 230:
#line 1806 "./Parser/parser_main.y"
    {fprintf(fp,"For - zip statement in output section\n");}
    break;

  case 231:
#line 1807 "./Parser/parser_main.y"
    {fprintf(fp,"while statement in output section\n");}
    break;

  case 232:
#line 1810 "./Parser/parser_main.y"
    {outputLevel++;fprintf(out,"if(%s){\n",(yyvsp[(3) - (5)]).str);}
    break;

  case 233:
#line 1810 "./Parser/parser_main.y"
=======
  case 222:
#line 1899 "./Parser/parser_main.y"
    {fprintf(fp,"Save statement\n");}
    break;

  case 223:
#line 1903 "./Parser/parser_main.y"
    {fprintf(fp,"Output section conditional statement begins\n");}
    break;

  case 224:
#line 1903 "./Parser/parser_main.y"
    {fprintf(fp,"Output section conditional statement ends\n");}
    break;

  case 225:
#line 1904 "./Parser/parser_main.y"
    {fprintf(fp,"For statement in output section\n");}
    break;

  case 226:
#line 1905 "./Parser/parser_main.y"
    {fprintf(fp,"For - lex statement in output section\n");}
    break;

  case 227:
#line 1906 "./Parser/parser_main.y"
    {fprintf(fp,"For - zip statement in output section\n");}
    break;

  case 228:
#line 1907 "./Parser/parser_main.y"
    {fprintf(fp,"while statement in output section\n");}
    break;

  case 229:
#line 1910 "./Parser/parser_main.y"
    {outputLevel++;fprintf(out,"if(%s){\n",(yyvsp[(3) - (5)]).str);}
    break;

  case 230:
#line 1910 "./Parser/parser_main.y"
    {fprintf(out,"}\n");outputLevel--;}
    break;

  case 232:
#line 1913 "./Parser/parser_main.y"
    {outputLevel++;fprintf(out,"else if(%s){\n",(yyvsp[(4) - (6)]).str);}
    break;

  case 233:
#line 1913 "./Parser/parser_main.y"
>>>>>>> temp
    {fprintf(out,"}\n");outputLevel--;}
    break;

  case 235:
<<<<<<< HEAD
#line 1813 "./Parser/parser_main.y"
    {outputLevel++;fprintf(out,"else if(%s){\n",(yyvsp[(4) - (6)]).str);}
    break;

  case 236:
#line 1813 "./Parser/parser_main.y"
    {fprintf(out,"}\n");outputLevel--;}
    break;

  case 238:
#line 1817 "./Parser/parser_main.y"
    {outputLevel++;fprintf(out,"else{\n");}
    break;

  case 239:
#line 1817 "./Parser/parser_main.y"
    {outputLevel--;fprintf(out,"}\n");}
    break;

  case 241:
#line 1821 "./Parser/parser_main.y"
=======
#line 1917 "./Parser/parser_main.y"
    {outputLevel++;fprintf(out,"else{\n");}
    break;

  case 236:
#line 1917 "./Parser/parser_main.y"
    {outputLevel--;fprintf(out,"}\n");}
    break;

  case 238:
#line 1921 "./Parser/parser_main.y"
>>>>>>> temp
    {  if(getOutputSymbolEntry(&OutputSymbolTable,(yyvsp[(2) - (2)]).str,outputLevel + 1,1) == NULL){
                                       yyerror("semantic error: variable used without declaration (4)"); 
                                       return 1;
                                    }
                                 }
    break;

<<<<<<< HEAD
  case 242:
#line 1826 "./Parser/parser_main.y"
    {outputLevel++;fprintf(out,"for(%s = %s;%s < %s;%s += %s){\n",(yyvsp[(2) - (8)]).str,(yyvsp[(6) - (8)]).start,(yyvsp[(2) - (8)]).str,(yyvsp[(6) - (8)]).end,(yyvsp[(2) - (8)]).str,(yyvsp[(6) - (8)]).step);}
    break;

  case 243:
#line 1827 "./Parser/parser_main.y"
    {fprintf(out,"}\n");exitOutputSymbolScope(&OutputSymbolTable,outputLevel);outputLevel--;}
    break;

  case 244:
#line 1830 "./Parser/parser_main.y"
=======
  case 239:
#line 1926 "./Parser/parser_main.y"
    {outputLevel++;fprintf(out,"for(%s = %s;%s < %s;%s += %s){\n",(yyvsp[(2) - (8)]).str,(yyvsp[(6) - (8)]).start,(yyvsp[(2) - (8)]).str,(yyvsp[(6) - (8)]).end,(yyvsp[(2) - (8)]).str,(yyvsp[(6) - (8)]).step);}
    break;

  case 240:
#line 1927 "./Parser/parser_main.y"
    {fprintf(out,"}\n");exitOutputSymbolScope(&OutputSymbolTable,outputLevel);outputLevel--;}
    break;

  case 241:
#line 1930 "./Parser/parser_main.y"
>>>>>>> temp
    {   if((yyvsp[(3) - (8)]).num != (yyvsp[(7) - (8)]).num){
                                                                                 yyerror("semantic error: mismatch in loop variables and ranges"); 
                                                                                 return 1;
                                                                              }
                                                                              printForLex((yyvsp[(3) - (8)]).num, 2);
                                                                          }
    break;

<<<<<<< HEAD
  case 245:
#line 1836 "./Parser/parser_main.y"
    {outputLevel++;}
    break;

  case 246:
#line 1836 "./Parser/parser_main.y"
=======
  case 242:
#line 1936 "./Parser/parser_main.y"
    {outputLevel++;}
    break;

  case 243:
#line 1936 "./Parser/parser_main.y"
>>>>>>> temp
    {   printForLex((yyvsp[(3) - (13)]).num, 0);
                                                                              exitOutputSymbolScope(&OutputSymbolTable,outputLevel);
                                                                              outputLevel--;}
    break;

<<<<<<< HEAD
  case 247:
#line 1841 "./Parser/parser_main.y"
=======
  case 244:
#line 1941 "./Parser/parser_main.y"
>>>>>>> temp
    {   if((yyvsp[(3) - (8)]).num != (yyvsp[(7) - (8)]).num){
                                                                                 yyerror("semantic error: mismatch in loop variables and ranges"); 
                                                                                 return 1;
                                                                              }
                                                                              printForZip((yyvsp[(3) - (8)]).num, 2);
                                                                          }
    break;

<<<<<<< HEAD
  case 248:
#line 1847 "./Parser/parser_main.y"
    {outputLevel++;}
    break;

  case 249:
#line 1848 "./Parser/parser_main.y"
=======
  case 245:
#line 1947 "./Parser/parser_main.y"
    {outputLevel++;}
    break;

  case 246:
#line 1948 "./Parser/parser_main.y"
>>>>>>> temp
    {exitOutputSymbolScope(&OutputSymbolTable,outputLevel); outputLevel--; 
                                                         printForZip((yyvsp[(3) - (13)]).num, 0);
                                                      }
    break;

<<<<<<< HEAD
  case 250:
#line 1853 "./Parser/parser_main.y"
    {outputLevel++;fprintf(out,"while(%s){\n",(yyvsp[(3) - (5)]).str);}
    break;

  case 251:
#line 1853 "./Parser/parser_main.y"
    {fprintf(out,"}\n");exitOutputSymbolScope(&OutputSymbolTable,outputLevel); outputLevel--;}
    break;

  case 257:
#line 1865 "./Parser/parser_main.y"
    {isDeclaration = false;}
    break;

  case 258:
#line 1865 "./Parser/parser_main.y"
    {fprintf(out,"%s\n",(yyvsp[(2) - (2)]).str2);}
    break;

  case 259:
#line 1866 "./Parser/parser_main.y"
=======
  case 247:
#line 1953 "./Parser/parser_main.y"
    {outputLevel++;fprintf(out,"while(%s){\n",(yyvsp[(3) - (5)]).str);}
    break;

  case 248:
#line 1953 "./Parser/parser_main.y"
    {fprintf(out,"}\n");exitOutputSymbolScope(&OutputSymbolTable,outputLevel); outputLevel--;}
    break;

  case 254:
#line 1965 "./Parser/parser_main.y"
    {isDeclaration = false;}
    break;

  case 255:
#line 1965 "./Parser/parser_main.y"
    {fprintf(out,"%s\n",(yyvsp[(2) - (2)]).str2);}
    break;

  case 256:
#line 1966 "./Parser/parser_main.y"
>>>>>>> temp
    {isDeclaration = true;}
    break;


/* Line 1267 of yacc.c.  */
<<<<<<< HEAD
#line 4553 "y.tab.c"
=======
#line 4604 "y.tab.c"
>>>>>>> temp
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


<<<<<<< HEAD
#line 1868 "./Parser/parser_main.y"
=======
#line 1968 "./Parser/parser_main.y"
>>>>>>> temp


void printForZip(int num, int usage){
   if(usage == 0){
      fprintf(out, "}\n");
      return;
   }

   struct List* temp = head;
   struct List2* temp2 = range_list;
   fprintf(out, "for(");
   if(usage==1) {fprintf(out, "int ");}
   for(int i=0;i<num;i++){
      fprintf(out, "%s = %s",temp->id,temp2->start);
      if(i<num-1){fprintf(out, ", ");}
      temp = temp->next;
      temp2 = temp2->next;
   }
   fprintf(out, ";");

   temp = head;
   temp2= range_list;
   for(int i=0;i<num;i++){
      fprintf(out, "%s < %s",temp->id,temp2->end);
      if(i<num-1){fprintf(out, " && ");}
      temp = temp->next;
      temp2 = temp2->next;
   }
   fprintf(out, ";");

   temp = head;
   temp2= range_list;
   for(int i=0;i<num;i++){
      fprintf(out, "%s += %s",temp->id,temp2->end);
      if(i<num-1){fprintf(out, ", ");}
      temp = temp->next;
      temp2 = temp2->next;
   }
   fprintf(out, "){\n");

}

/* usage is 1 for main, 2 for output and 0 for closing*/
void printForLex(int num, int usage){
   if(usage){
      struct List* temp = head;
      struct List2* temp2 = range_list;
      int x = outputLevel-1;
      for(int i=0;i<num;i++){
         for(int j=0;j<x;j++){
            fprintf(out,"\t");
         }
         x++;
         if(usage==1){ fprintf(out,"for(int %s = %s;%s < %s;%s += %s){\n",temp->id,temp2->start,temp->id,temp2->end,temp->id,temp2->step);}
         else if(usage==2){ fprintf(out,"for(%s = %s;%s < %s;%s += %s){\n",temp->id,temp2->start,temp->id,temp2->end,temp->id,temp2->step);}
         temp = temp->next;
         temp2 = temp2->next;
      }
      indent = x;
   }
   else {
      int x = indent-1;
      for(int i=0;i<num;i++){
         for(int j=0;j<x;j++){
            fprintf(out,"\t");
         }
         x--;
         fprintf(out,"}\n");
      }
   }
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
   str1[strlen(str2)] = '\0';
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
   newNode->id = (char *)malloc(sizeof(char)*strlen(data)+1);
   for(int i=0;i<strlen(data);i++){
      newNode->id[i] = data[i];
   }
   newNode->id[strlen(data)] = '\0';
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

int insertInGateTable(struct GateTable ** Head,char * data,struct cpx * arr){
   struct GateTable* temp = *Head;
   while(temp != NULL){
      if(strcmp(temp->id,data) == 0){
         return 0;
      }
      temp = temp->next;
   }
   struct GateTable* newNode = (struct GateTable*)malloc(sizeof(struct GateTable));
   newNode->id = (char *)malloc(sizeof(char)*(strlen(data)+1));
   for(int i=0;i<strlen(data);i++){
      newNode->id[i] = data[i];
   }
   newNode->id[strlen(data)] = '\0';

   struct cpx *temp2 = (struct cpx *)malloc(sizeof(struct cpx)*4);
   for(int i=0;i<4;i++){
      temp2[i] = arr[i];
   }
   newNode->arr = temp2;

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
      for(int i=0;i<4;i++){
         printf("(%f, %f) ",temp->arr[i].real,temp->arr[i].imag);
      }
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
   newNode->id = (char *)malloc(sizeof(char)*(strlen(id)+1));
   for(int i=0;i<strlen(id);i++){
      newNode->id[i] = id[i];
   }
   newNode->id[strlen(id)] = '\0';

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

  return yyparse();
}

void yyerror(char* err){
   printf("At line %d: %s\n", line, err);
   fprintf(fp,"At line %d: %s\n",line, err);
}

