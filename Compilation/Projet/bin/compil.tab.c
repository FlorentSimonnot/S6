/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "yacc/compil.y" /* yacc.c:339  */

#include <stdio.h>
#include <string.h>
#include "../header/decl.h"
#include "../header/input-output.h"

/*COMMIT*/
int yylex(void);
void yyerror(char* s);
int flag_error = 0;
int flag_start = 1; 
int flag_return = 0; 
int type_const = -1; 
int type_var = -1;
int jump_label = 0;
int parameters = 0;
int dimension_array = 0;
int is_global_variable = 1;
int is_const_variable = 1;
int current_num_array = 0;
int call_num_array = 0;
int array_size[10000];
int lvalue_called_is_array = 0;
int *args = NULL;
char name_function[MAXNAME];
char name_called_function[MAXNAME];

#line 94 "bin/compil.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "compil.tab.h".  */
#ifndef YY_YY_BIN_COMPIL_TAB_H_INCLUDED
# define YY_YY_BIN_COMPIL_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    IDENT = 258,
    NUM = 259,
    CONST = 260,
    CARACTERE = 261,
    TYPE = 262,
    ADDSUB = 263,
    VOID = 264,
    READE = 265,
    READC = 266,
    PRINT = 267,
    IF = 268,
    ELSE = 269,
    WHILE = 270,
    FOR = 271,
    RETURN = 272,
    AND = 273,
    OR = 274,
    DIVSTAR = 275,
    EQ = 276,
    ORDER = 277,
    INCREMENT = 278,
    INCLUDE = 279,
    ENTETE = 280,
    FLOAT = 281,
    DO = 282,
    DEFINE = 283,
    NAME_DEFINE = 284,
    CAST = 285
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 29 "yacc/compil.y" /* yacc.c:355  */

	char *typeval;
	int intval; 
	float reelval; 
	char charval; 
	char addsubval; 
	char divstarval; 
	char identval[64];
	char eqval[2];
	char andval[2]; 
	char orval[2];
	char incrementval[2];
	char defineval[7];
	char* printval; 
	char* returnval; 
	char* ifval;
	char* elseval; 
	char* whileval; 
	char* forval;
	char* voidval;  
	char* constval;
	char* readeval; 
	char* readcval; 
	char* orderval; 
	char* includeval; 
	char* enteteval; 
	char* doval; 
	char name_defineval[MAXNAME];
    char *cast;

#line 196 "bin/compil.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_BIN_COMPIL_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 213 "bin/compil.tab.c" /* yacc.c:358  */

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
#else
typedef signed char yytype_int8;
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
# elif ! defined YYSIZE_T
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
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
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
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
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
#define YYLAST   451

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  41
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  44
/* YYNRULES -- Number of rules.  */
#define YYNRULES  121
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  284

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   285

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    40,     2,     2,     2,     2,     2,     2,
      37,    32,     2,     2,    31,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    33,
       2,    34,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    35,     2,    36,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    38,     2,    39,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    98,    98,   103,   104,   105,   106,   110,   115,   123,
     124,   128,   129,   133,   134,   135,   136,   137,   141,   142,
     143,   147,   154,   160,   164,   165,   166,   170,   174,   179,
     187,   195,   196,   197,   198,   202,   203,   207,   208,   213,
     212,   239,   238,   264,   265,   266,   267,   271,   272,   273,
     276,   280,   284,   285,   286,   289,   298,   299,   302,   306,
     307,   318,   328,   344,   360,   368,   373,   375,   377,   374,
     380,   381,   382,   383,   384,   385,   386,   387,   388,   389,
     390,   394,   397,   400,   403,   443,   458,   463,   462,   475,
     477,   477,   489,   492,   506,   508,   535,   537,   545,   547,
     556,   559,   567,   575,   576,   599,   614,   627,   628,   630,
     629,   653,   658,   657,   668,   669,   670,   674,   675,   679,
     685,   690
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENT", "NUM", "CONST", "CARACTERE",
  "TYPE", "ADDSUB", "VOID", "READE", "READC", "PRINT", "IF", "ELSE",
  "WHILE", "FOR", "RETURN", "AND", "OR", "DIVSTAR", "EQ", "ORDER",
  "INCREMENT", "INCLUDE", "ENTETE", "FLOAT", "DO", "DEFINE", "NAME_DEFINE",
  "CAST", "','", "')'", "';'", "'='", "'['", "']'", "'('", "'{'", "'}'",
  "'!'", "$accept", "Prog", "DeclConsts", "ListConst", "Litteral",
  "NombreSigne", "DeclVars", "Declarateurs", "Declarateur", "DeclInitVars",
  "DeclInitVar", "DeclInit", "DeclarateurTableau", "DeclFoncts",
  "DeclFonct", "EnTeteFonct", "$@1", "$@2", "Parametres", "ListTypVar",
  "Corps", "SuiteInstr", "Instr", "@3", "$@4", "TradIF", "FinTradIF",
  "FinELSE", "Exp", "EB", "@5", "TB", "@6", "FB", "M", "E", "T", "F",
  "$@7", "LValue", "$@8", "Tableau", "Arguments", "ListExp", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,    44,    41,    59,    61,    91,    93,    40,   123,   125,
      33
};
# endif

#define YYPACT_NINF -189

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-189)))

#define YYTABLE_NINF -119

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -189,    20,   233,  -189,    27,    27,   273,     8,   -24,    36,
     117,   127,    45,   341,  -189,    26,   235,    55,  -189,  -189,
    -189,    40,   152,    47,   209,   124,   250,    50,   253,  -189,
      66,    89,   304,  -189,  -189,  -189,  -189,  -189,    92,  -189,
    -189,    74,    59,   114,    84,   114,  -189,    84,   261,   153,
     317,  -189,  -189,   317,  -189,   197,    82,   145,   173,    94,
    -189,   235,    93,   128,    70,   212,   342,  -189,   195,    81,
     218,  -189,  -189,   251,  -189,   230,    84,   101,  -189,  -189,
    -189,  -189,  -189,   258,    84,   140,  -189,  -189,  -189,   259,
     266,  -189,  -189,  -189,  -189,   302,   307,  -189,  -189,  -189,
     291,  -189,   298,   343,   317,   180,  -189,  -189,   332,   336,
    -189,  -189,    40,   319,   166,  -189,  -189,   208,   320,   322,
     323,     1,  -189,   324,    28,   325,  -189,     7,  -189,  -189,
     208,  -189,   329,   345,   348,   349,   347,   359,   352,  -189,
     337,  -189,  -189,   162,   338,   339,  -189,  -189,   346,   350,
     208,   208,   208,   340,   351,  -189,   353,  -189,   344,   355,
     220,  -189,  -189,   354,   360,   208,   208,   208,   208,   248,
    -189,   356,    83,   162,   288,  -189,   357,   358,   361,   362,
     363,   364,    34,   208,   365,     5,  -189,   260,   376,  -189,
    -189,   208,   208,   347,   359,   352,  -189,   168,  -189,  -189,
     208,   208,   366,   -12,   367,   368,   369,   371,   372,   373,
     300,   300,   375,   377,   378,   379,   141,   370,  -189,   348,
     349,   380,  -189,  -189,  -189,   339,   339,  -189,  -189,  -189,
    -189,  -189,  -189,  -189,   300,  -189,   381,   382,   383,   384,
     374,   318,  -189,  -189,  -189,   300,   208,   208,   208,   208,
     208,   166,  -189,   386,  -189,   385,   387,   388,   389,   391,
     300,   208,   208,   208,   328,   392,  -189,   394,   395,   396,
     -16,   397,  -189,  -189,   300,   300,   300,   300,   300,  -189,
    -189,  -189,  -189,  -189
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       6,     0,     0,     1,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    36,    38,     0,     0,     4,     5,
       3,     0,    21,     0,     0,    21,     0,     0,     0,    26,
       0,     0,     0,    35,     6,    37,    11,    10,     0,     8,
       9,     0,     0,    23,     0,    22,    15,     0,     0,     0,
       0,    13,    16,     0,    14,     0,     0,     0,     0,     0,
      12,     0,     0,     0,     0,     0,     0,    47,     0,     0,
       0,    28,    30,     0,    27,     0,     0,    21,    18,    19,
      25,    20,    24,     0,     0,     0,     7,    32,    31,     0,
       0,    53,    54,    51,    45,     0,     0,    46,    29,    43,
       0,    44,     0,     0,     0,     0,    34,    33,     0,     0,
      40,    42,    21,     0,   104,   107,   108,     0,     0,     0,
       0,     0,    67,     0,     0,     0,    59,     0,    57,    55,
       0,    56,     0,    86,    89,    92,    94,    96,    98,   100,
     106,    52,    50,     0,     0,   116,   101,   106,     0,     0,
       0,     0,     0,     0,     0,    61,     0,    57,     0,     0,
       0,   102,    58,     0,     0,     0,     0,     0,     0,     0,
     120,     0,     0,     0,     0,   113,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    60,     0,     0,   103,
      72,     0,     0,    93,    95,    97,    99,     0,    84,   111,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   105,    88,
      91,     0,   121,   119,   110,   116,   116,    79,    62,    80,
      63,    64,    73,    74,     0,    68,     0,     0,     0,     0,
       0,     0,   115,   114,    82,     0,     0,     0,     0,     0,
       0,   104,    85,    65,    69,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    83,     0,     0,     0,
       0,     0,    71,    66,     0,     0,     0,     0,     0,    75,
      78,    76,    77,    70
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -189,  -189,   390,   403,   330,  -189,   321,   331,   -10,   393,
     398,  -189,   201,  -189,   400,  -189,  -189,  -189,   -14,  -189,
    -189,  -116,  -188,  -189,  -189,  -189,  -189,  -189,  -124,  -189,
    -189,   190,  -189,   200,   232,   244,   252,  -112,  -189,  -113,
    -189,    53,   257,  -189
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,     8,    39,    40,     6,    26,    23,    28,
      29,    74,    45,    13,    14,    15,    76,    84,    68,    69,
      35,   105,   131,   153,   245,   212,   253,   273,   132,   133,
     163,   134,   164,   135,   136,   137,   138,   139,   144,   140,
     145,   175,   171,   172
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     156,    27,   151,   159,   147,   146,   215,    17,   113,    18,
     114,   115,   160,   116,   158,   117,   277,   147,   161,   170,
       3,   143,   232,   233,   225,   143,   180,   181,   182,   113,
       7,   114,   115,    70,   116,   211,   117,    19,   152,   216,
      78,   187,    16,    81,   127,   198,   244,   130,    30,   170,
     204,    52,   147,   147,   147,   147,   196,   254,    41,   213,
      62,   155,   100,    63,    34,   127,   -81,    17,   130,    20,
     102,    89,   266,   159,    90,    42,   222,   223,   147,   147,
      46,   -20,    95,   -20,   200,    65,   279,   280,   281,   282,
     283,    66,    56,    67,    27,     4,    60,   -17,   -17,     5,
     -17,   -17,   -17,    55,   -17,   -17,   -17,   -17,    61,   -17,
     -17,   -17,    96,   -48,   201,  -117,   -49,   252,    21,    44,
      22,   -17,   255,   256,   257,   258,   259,   -17,    24,    87,
      25,   -17,   -17,   -17,   -17,    48,    42,   267,   268,   269,
     271,   103,   238,   -57,   -57,   239,   -57,   104,   -57,    64,
     -57,   -57,   -57,   -57,    75,   -57,   -57,   -57,    48,    42,
     -39,    49,   -39,   113,    88,   114,   115,   -57,   116,   113,
     117,   114,   115,   -57,   116,   221,   117,   -57,   -57,   -57,
     -57,   113,    47,   114,   115,   -39,   116,    42,   117,    44,
     118,   119,   120,   121,  -118,   122,   123,   124,    83,   127,
    -112,  -112,   130,  -109,   -41,   127,   -41,   125,   130,   113,
      49,   114,   115,   126,   116,    91,   117,   127,   128,   129,
     130,   113,    43,   114,   115,    43,   116,    94,   117,   -41,
     118,   119,   120,   121,     4,   122,   123,   124,     5,    36,
     -17,    37,   -17,    38,    42,   127,    47,   125,   130,   113,
      97,   114,   115,   126,   116,    98,   117,   127,   128,   190,
     130,   113,    99,   114,   115,    71,   116,    72,   117,    73,
     118,   119,   120,   121,    10,   122,   123,   124,   242,   243,
      11,    50,    12,    51,    53,   197,    54,   125,   130,   203,
     101,   114,   115,   126,   116,   106,   117,   127,   128,   217,
     130,   113,   107,   114,   115,    57,   116,    58,   117,   108,
     118,   119,   120,   121,   109,   122,   123,   124,    21,   113,
      77,   251,   115,   110,   116,   127,   117,   125,   130,   270,
     111,   114,   115,   126,   116,   141,   117,   127,   128,   142,
     130,    -2,    31,    92,    21,    93,   112,   176,    32,   177,
      12,   178,   184,   179,   185,   127,   143,   148,   130,   149,
     150,   154,   162,   157,   -87,   127,   -90,   167,   130,   166,
     165,   169,   168,   191,   174,   173,   188,   183,   192,   218,
      85,   219,   236,   237,    80,   240,   186,   189,   199,   205,
     206,    86,   220,   207,   208,   209,   210,   193,   224,   214,
     260,   227,   228,   226,   229,   230,   231,   234,     9,   235,
     194,   250,   241,    33,   246,   247,   248,   249,   261,   195,
     262,   263,   264,   265,    59,   272,   274,   275,   276,   278,
     202,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    79,     0,     0,     0,     0,     0,     0,
       0,    82
};

static const yytype_int16 yycheck[] =
{
     124,    11,     1,   127,   117,   117,     1,    31,     1,    33,
       3,     4,   128,     6,     7,     8,    32,   130,   130,   143,
       0,    37,   210,   211,    36,    37,   150,   151,   152,     1,
       3,     3,     4,    47,     6,     1,     8,     1,    37,    34,
      50,   157,    34,    53,    37,   169,   234,    40,     3,   173,
     174,     1,   165,   166,   167,   168,   168,   245,     3,   183,
       1,    33,    76,     4,    38,    37,    32,    31,    40,    33,
      84,     1,   260,   197,     4,    35,   200,   201,   191,   192,
      33,    31,     1,    33,     1,     1,   274,   275,   276,   277,
     278,     7,     3,     9,   104,     1,     4,     3,     4,     5,
       6,     7,     8,    37,    10,    11,    12,    13,    34,    15,
      16,    17,    31,    32,    31,    32,    32,   241,     1,    37,
       3,    27,   246,   247,   248,   249,   250,    33,     1,    36,
       3,    37,    38,    39,    40,    34,    35,   261,   262,   263,
     264,     1,     1,     3,     4,     4,     6,     7,     8,    35,
      10,    11,    12,    13,     1,    15,    16,    17,    34,    35,
       7,    37,     9,     1,    36,     3,     4,    27,     6,     1,
       8,     3,     4,    33,     6,     7,     8,    37,    38,    39,
      40,     1,    37,     3,     4,    32,     6,    35,     8,    37,
      10,    11,    12,    13,    32,    15,    16,    17,     1,    37,
      34,    35,    40,    37,     7,    37,     9,    27,    40,     1,
      37,     3,     4,    33,     6,     3,     8,    37,    38,    39,
      40,     1,    21,     3,     4,    24,     6,    32,     8,    32,
      10,    11,    12,    13,     1,    15,    16,    17,     5,     4,
       7,     6,     9,     8,    35,    37,    37,    27,    40,     1,
      32,     3,     4,    33,     6,     4,     8,    37,    38,    39,
      40,     1,    32,     3,     4,     4,     6,     6,     8,     8,
      10,    11,    12,    13,     1,    15,    16,    17,   225,   226,
       7,    31,     9,    33,    31,    37,    33,    27,    40,     1,
      32,     3,     4,    33,     6,    36,     8,    37,    38,    39,
      40,     1,    36,     3,     4,     1,     6,     3,     8,     7,
      10,    11,    12,    13,     7,    15,    16,    17,     1,     1,
       3,     3,     4,    32,     6,    37,     8,    27,    40,     1,
      32,     3,     4,    33,     6,     3,     8,    37,    38,     3,
      40,     0,     1,     1,     1,     3,     3,     1,     7,     3,
       9,     1,     1,     3,     3,    37,    37,    37,    40,    37,
      37,    37,    33,    38,    19,    37,    18,     8,    40,    22,
      21,    34,    20,    19,    35,    37,    32,    37,    18,     3,
      59,   191,     4,     4,    53,    15,    33,    32,    32,    32,
      32,    61,   192,    32,    32,    32,    32,   165,    32,    34,
      14,    33,    33,    36,    33,    33,    33,    32,     5,    32,
     166,    37,    32,    13,    33,    33,    33,    33,    33,   167,
      33,    33,    33,    32,    34,    33,    32,    32,    32,    32,
     173,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    50,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    53
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    42,    43,     0,     1,     5,    47,     3,    44,    44,
       1,     7,     9,    54,    55,    56,    34,    31,    33,     1,
      33,     1,     3,    49,     1,     3,    48,    49,    50,    51,
       3,     1,     7,    55,    38,    61,     4,     6,     8,    45,
      46,     3,    35,    53,    37,    53,    33,    37,    34,    37,
      31,    33,     1,    31,    33,    37,     3,     1,     3,    43,
       4,    34,     1,     4,    35,     1,     7,     9,    59,    60,
      59,     4,     6,     8,    52,     1,    57,     3,    49,    50,
      48,    49,    51,     1,    58,    47,    45,    36,    36,     1,
       4,     3,     1,     3,    32,     1,    31,    32,     4,    32,
      59,    32,    59,     1,     7,    62,    36,    36,     7,     7,
      32,    32,     3,     1,     3,     4,     6,     8,    10,    11,
      12,    13,    15,    16,    17,    27,    33,    37,    38,    39,
      40,    63,    69,    70,    72,    74,    75,    76,    77,    78,
      80,     3,     3,    37,    79,    81,    78,    80,    37,    37,
      37,     1,    37,    64,    37,    33,    69,    38,     7,    69,
      62,    78,    33,    71,    73,    21,    22,     8,    20,    34,
      69,    83,    84,    37,    35,    82,     1,     3,     1,     3,
      69,    69,    69,    37,     1,     3,    33,    62,    32,    32,
      39,    19,    18,    75,    76,    77,    78,    37,    69,    32,
       1,    31,    83,     1,    69,    32,    32,    32,    32,    32,
      32,     1,    66,    69,    34,     1,    34,    39,     3,    72,
      74,     7,    69,    69,    32,    36,    36,    33,    33,    33,
      33,    33,    63,    63,    32,    32,     4,     4,     1,     4,
      15,    32,    82,    82,    63,    65,    33,    33,    33,    33,
      37,     3,    69,    67,    63,    69,    69,    69,    69,    69,
      14,    33,    33,    33,    33,    32,    63,    69,    69,    69,
       1,    69,    33,    68,    32,    32,    32,    32,    32,    63,
      63,    63,    63,    63
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    41,    42,    43,    43,    43,    43,    44,    44,    45,
      45,    46,    46,    47,    47,    47,    47,    47,    48,    48,
      48,    49,    49,    49,    50,    50,    50,    51,    52,    52,
      52,    53,    53,    53,    53,    54,    54,    55,    55,    57,
      56,    58,    56,    56,    56,    56,    56,    59,    59,    59,
      60,    60,    60,    60,    60,    61,    62,    62,    63,    63,
      63,    63,    63,    63,    63,    63,    63,    64,    65,    63,
      63,    63,    63,    63,    63,    63,    63,    63,    63,    63,
      63,    66,    67,    68,    69,    69,    69,    71,    70,    70,
      73,    72,    72,    74,    74,    75,    75,    76,    76,    77,
      77,    78,    78,    78,    78,    78,    78,    78,    78,    79,
      78,    78,    81,    80,    82,    82,    82,    83,    83,    84,
      84,    84
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     4,     4,     4,     0,     5,     3,     1,
       1,     1,     2,     4,     4,     4,     4,     0,     3,     3,
       1,     1,     2,     2,     3,     3,     1,     3,     1,     2,
       1,     3,     3,     4,     4,     2,     1,     2,     1,     0,
       6,     0,     6,     5,     5,     5,     5,     1,     1,     0,
       4,     2,     4,     2,     2,     5,     2,     0,     2,     1,
       3,     2,     5,     5,     5,     7,    10,     0,     0,     7,
      11,     9,     3,     5,     5,    11,    11,    11,    11,     5,
       5,     0,     0,     0,     3,     6,     1,     0,     4,     1,
       0,     4,     1,     3,     1,     3,     1,     3,     1,     3,
       1,     2,     2,     3,     1,     4,     1,     1,     1,     0,
       5,     4,     0,     3,     4,     4,     0,     1,     0,     3,
       1,     3
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
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
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
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
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
        case 2:
#line 98 "yacc/compil.y" /* yacc.c:1646  */
    {print_end();}
#line 1513 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 110 "yacc/compil.y" /* yacc.c:1646  */
    {
       										if(addConst((yyvsp[-2].identval), type_const, (yyvsp[0].intval), .0) == 0){
       											flag_error = 1;
       										}
       									}
#line 1523 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 115 "yacc/compil.y" /* yacc.c:1646  */
    {
                                            if(addConst((yyvsp[-2].identval), type_const, (yyvsp[0].intval), .0) == 0){
                                                flag_error = 1;
                                            }
                                        }
#line 1533 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 123 "yacc/compil.y" /* yacc.c:1646  */
    {type_const = INTEGER;}
#line 1539 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 124 "yacc/compil.y" /* yacc.c:1646  */
    {type_const = CHAR;}
#line 1545 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 128 "yacc/compil.y" /* yacc.c:1646  */
    {(yyval.intval) = (yyvsp[0].intval);}
#line 1551 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 129 "yacc/compil.y" /* yacc.c:1646  */
    {if((yyvsp[-1].addsubval) == '-'){(yyval.intval) = -((yyvsp[0].intval));}}
#line 1557 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 147 "yacc/compil.y" /* yacc.c:1646  */
    {
					if(addVar((yyvsp[0].identval), type_var, 0, 0, .0) == 0){
						flag_error = 1;
					}
                    if(is_global_variable == 0)
                        fprintf(stdout, "     push QWORD 0\n");
				}
#line 1569 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 154 "yacc/compil.y" /* yacc.c:1646  */
    {
                                    dimension_array = (yyvsp[0].intval);
                                    if(dimension_array == 1){
                                        addTab((yyvsp[-1].identval), type_var, array_size[0]);
                                    }
                                }
#line 1580 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 174 "yacc/compil.y" /* yacc.c:1646  */
    { 
                addVar((yyvsp[(-1) - (1)].identval), type_var, 0, (yyvsp[0].intval), .0); 
                if(is_global_variable == 0)
                    fprintf(stdout, "    push QWORD %d\n", (yyval.intval));
            }
#line 1590 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 179 "yacc/compil.y" /* yacc.c:1646  */
    {
					if((yyvsp[-1].addsubval) == '-'){
						(yyval.intval) = -((yyvsp[0].intval));
					}
					addVar((yyvsp[(-1) - (2)].identval), type_var, 0, (yyval.intval), .0);
                    if(is_global_variable == 0)
                        fprintf(stdout, "    push QWORD %d\n", (yyval.intval));
				  }
#line 1603 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 187 "yacc/compil.y" /* yacc.c:1646  */
    {
					addVar((yyvsp[(-1) - (1)].identval), type_var, 0, (yyvsp[0].charval), .0);
                    if(is_global_variable == 0)
                        fprintf(stdout, "    push QWORD %d\n", (yyval.intval));
				  }
#line 1613 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 195 "yacc/compil.y" /* yacc.c:1646  */
    {(yyval.intval) = 1; array_size[current_num_array] = (yyvsp[-1].intval); current_num_array++;}
#line 1619 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 196 "yacc/compil.y" /* yacc.c:1646  */
    {(yyval.intval) = 0;}
#line 1625 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 197 "yacc/compil.y" /* yacc.c:1646  */
    {(yyval.intval) = (yyvsp[-3].intval) + 1; array_size[current_num_array] = (yyvsp[-1].intval); current_num_array++;}
#line 1631 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 198 "yacc/compil.y" /* yacc.c:1646  */
    {(yyval.intval) = 0;}
#line 1637 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 213 "yacc/compil.y" /* yacc.c:1646  */
    {   
                        strcpy(name_function, (yyvsp[-1].identval));
                        flag_return = 0;
                        addFun((yyvsp[-1].identval), getType((yyvsp[-2].typeval)));
                        if (flag_start) {
                            is_global_variable = 0;
                            char vars[64][64]; 
                            long vals[64];
                            char consts[64][64];
                            long cvals[64];
                            get_globals_var(vars, vals);
                            get_globals_const(consts, cvals);
                            print_start(get_globals_vars_size(), get_globals_const_size(), vars, vals, consts, cvals);
                            flag_start = 0;
                        }
                        fprintf(stdout, "%s:\n    push rbp\n    mov rbp, rsp\n", (yyvsp[-1].identval));
                        createStack();
                        parameters = 0;
                    }
#line 1661 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 233 "yacc/compil.y" /* yacc.c:1646  */
    {
                        int i;
                        for (i = parameters; i > 0; i--)
                            fprintf(stdout, "    push QWORD [rbp+%d]\n", (i+1) * 8);
                    }
#line 1671 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 239 "yacc/compil.y" /* yacc.c:1646  */
    {   
                        strcpy(name_function, (yyvsp[-1].identval));
                        addFun((yyvsp[-1].identval), VOIDTYPE);
                        if (flag_start) {
                            is_global_variable = 0;
                            char vars[64][64]; 
                            long vals[64];
                            char consts[64][64];
                            long cvals[64];
                            get_globals_var(vars, vals);
                            get_globals_const(consts, cvals);
                            print_start(get_globals_vars_size(), get_globals_const_size(), vars, vals, consts, cvals);
                            flag_start = 0;
                        }
                        fprintf(stdout, "%s:\n    push rbp\n    mov rbp, rsp\n", (yyvsp[-1].identval));
                        createStack();
                        parameters = 0;
                    }
#line 1694 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 259 "yacc/compil.y" /* yacc.c:1646  */
    {
                        int i;
                        for (i = parameters; i > 0; i--)
                            fprintf(stdout, "    push QWORD [rbp+%d]\n", (i+1) * 8);
                    }
#line 1704 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 276 "yacc/compil.y" /* yacc.c:1646  */
    {  addVar((yyvsp[0].identval), type_var, 1, 0, .0); 
                                    parameters++; 
                                    addArg(name_function, type_var);
                                 }
#line 1713 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 280 "yacc/compil.y" /* yacc.c:1646  */
    {  addVar((yyvsp[0].identval), type_var, 1, 0, .0); 
                                    parameters++; 
                                    addArg(name_function, type_var);
                                 }
#line 1722 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 289 "yacc/compil.y" /* yacc.c:1646  */
    {                
                                                    if (lookupFunction(name_function) != VOIDTYPE && flag_return == 0)
                                                        yyerror("Function is non-void and should return a value");
                                                    fprintf(stdout, "fin_%s:\n", name_function); 
                                                    remove_st_cell();
                                                }
#line 1733 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 302 "yacc/compil.y" /* yacc.c:1646  */
    {                
                        if ((yyvsp[-1].intval) != VOIDTYPE) 
                            fprintf(stdout, "    pop rcx\n");
                    }
#line 1742 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 307 "yacc/compil.y" /* yacc.c:1646  */
    {  
                            int type_fun = lookupFunction(name_function); 
                            if(type_fun == -1)
                                flag_error = 1; 
                            if(check_types((yyvsp[-1].intval), type_fun) == 0){
                                fprintf(stderr, "The function must return a value of this type %d\n", type_fun);
                                flag_error = 1;
                            }
                            flag_return = 1;
                            fprintf(stdout, "    pop rax\n    jmp fin_%s\n", name_function);
                        }
#line 1758 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 318 "yacc/compil.y" /* yacc.c:1646  */
    {
                            int type_fun = lookupFunction(name_function); 
                            if(type_fun == -1)
                                flag_error = 1; 
                            if(check_types(VOIDTYPE, type_fun) == 0){
                                fprintf(stderr, "The function must return a void value\n");
                                flag_error = 1;
                            }
                            fprintf(stdout, "    pop rax\n    jmp fin_%s\n", name_function);
                    }
#line 1773 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 329 "yacc/compil.y" /* yacc.c:1646  */
    {
                        if (check_types(lookup((yyvsp[-2].identval), 0), INTEGER) == 0){
                            fprintf(stderr, "Reade is only for variables of type entier\n"); 
                            flag_error = 1;
                        }
                        int address[2]; 
                        get_address((yyvsp[-2].identval), address);
                        switch (address[1]) {
                            case 0: fprintf(stdout, "    mov rsi, rbp\n    sub rsi, %d\n", address[0]); break;
                            case 1: fprintf(stdout, "    mov rsi, globals\n    add rsi, %d\n", address[0]); break;
                            case 2: fprintf(stderr, "Assignment to a const variable impossible\n"); break;
                            default: fprintf(stderr, "Impossible\n"); break;
                        }
                        fprintf(stdout, "    call _reade\n");
                    }
#line 1793 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 345 "yacc/compil.y" /* yacc.c:1646  */
    {
                        if (check_types(lookup((yyvsp[-2].identval), 0), CHAR) == 0){
                            fprintf(stderr, "Readc is only for variables of type caractere\n");  
                            flag_error = 1;
                        }
                        int address[2]; 
                        get_address((yyvsp[-2].identval), address);
                        switch (address[1]) {
                            case 0: fprintf(stdout, "    mov rsi, rbp\n    sub rsi, %d\n", address[0]); break;
                            case 1: fprintf(stdout, "    mov rsi, globals\n    add rsi, %d\n", address[0]); break;
                            case 2: fprintf(stderr, "Assignment to a const variable impossible\n"); break;
                            default: fprintf(stderr, "Impossible\n"); break;
                        }
                        fprintf(stdout, "    call _reade\n");
                    }
#line 1813 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 360 "yacc/compil.y" /* yacc.c:1646  */
    {
                                        switch ((yyvsp[-2].intval)) {
                                            case INTEGER: fprintf(stdout, "    pop rsi\n    call _print_ent\n"); break;
                                            case LONG: fprintf(stdout, "    pop rsi\n    call _print_long\n"); break;
                                            case CHAR: fprintf(stdout, "    pop rsi\n    call _print_car\n"); break;
                                            case VOIDTYPE: yyerror("Can't print void value"); break;
                                        }
                                    }
#line 1826 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 369 "yacc/compil.y" /* yacc.c:1646  */
    {
            fprintf(stdout, "fin_if%d:\n", (yyvsp[-3].intval));
        }
#line 1834 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 375 "yacc/compil.y" /* yacc.c:1646  */
    {fprintf(stdout, "debut_while%d:\n", (yyval.intval) = jump_label++);}
#line 1840 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 377 "yacc/compil.y" /* yacc.c:1646  */
    {fprintf(stdout, "    pop rax\n    cmp rax, 0\n    je fin_while%d\n", (yyvsp[-3].intval));}
#line 1846 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 379 "yacc/compil.y" /* yacc.c:1646  */
    {fprintf(stdout, "    jmp debut_while%d\nfin_while%d:\n", (yyvsp[-5].intval), (yyvsp[-5].intval));}
#line 1852 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 394 "yacc/compil.y" /* yacc.c:1646  */
    {fprintf(stdout, "    pop rax\n    cmp rax,0\n    je else_no%d\n",(yyval.intval)=jump_label++);}
#line 1858 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 397 "yacc/compil.y" /* yacc.c:1646  */
    {fprintf(stdout, "    jmp fin_if%d\nelse_no%d:\n", (yyvsp[(-2) - (0)].intval),(yyvsp[(-2) - (0)].intval));}
#line 1864 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 400 "yacc/compil.y" /* yacc.c:1646  */
    {fprintf(stdout, "fin_if%d:\n", (yyvsp[(-5) - (0)].intval));}
#line 1870 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 403 "yacc/compil.y" /* yacc.c:1646  */
    {
                        if(lvalue_called_is_array == 1){
                            (yyval.intval) = lookup((yyvsp[-2].identval), 1);
                            check_types((yyval.intval), (yyvsp[0].intval));
                            int addr[2];
                            get_address((yyvsp[-2].identval), addr);
                            switch (addr[1]) {
                                case 0: fprintf(stdout, "    pop rcx\n    pop rax\n    mov rbx,8\n    imul rbx\n");
                                        fprintf(stdout, "mov rbx,rbp\n    add rax,%d\n    sub rbx,rax\n    mov [rbx], rcx\n    push QWORD [rbx]\n", addr[0]); break;
                                case 1: fprintf(stdout, "    pop rcx\n    pop rbx\n    mov [globals+rbx*8+%d], rcx\n    push QWORD [globals+rbx*8+%d]\n", addr[0], addr[0]); break;
                                case 2: fprintf(stderr, "%s is a const variable near line %d\n", (yyvsp[-2].identval), line_num); break;
                                default: yyerror("impossible"); break;
                            }
                        }
                        else{
                            if(isConstante((yyvsp[-2].identval)) == 1){flag_error = 1;}
                            (yyval.intval) = lookup((yyvsp[-2].identval), 0); 
                            if((yyval.intval) == -1){flag_error = 1;} 
                            (yyval.intval) = cast_type((yyval.intval), (yyvsp[0].intval), 0);
                            if((yyval.intval) == -1){flag_error = 1;}
                            if(globale_variable((yyvsp[-2].identval)) == 1){
                                int addr[2]; 
                                get_address((yyvsp[-2].identval), addr);
                                fprintf(stdout, "    pop rdx\n    mov QWORD [%s], QWORD rdx\n    push QWORD rdx\n", (yyvsp[-2].identval));
                            }
                            else if(globale_const((yyvsp[-2].identval)) == 1){
                                fprintf(stderr, " %s is a const variable near line %d\n", (yyvsp[-2].identval), line_num);
                            }
                            else{
                                int addr[2]; 
                                get_address((yyvsp[-2].identval), addr);
                                switch (addr[1]) {
                                    case 0: fprintf(stdout, "    pop QWORD [rbp-%d]\n    push QWORD [rbp-%d]\n", addr[0], addr[0]); break;
                                    //case 1: fprintf(stdout, "    pop QWORD [globals+%d]\n    push QWORD [globals+%d]\n", addr[0], addr[0]); break;
                                    case 2: fprintf(stderr, "%s is a const variable near line %d\n", (yyvsp[-2].identval), line_num); break;
                                    default: yyerror("impossible"); break;
                                }
                            }
                        }
                    }
#line 1915 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 443 "yacc/compil.y" /* yacc.c:1646  */
    {
                        if(isConstante((yyvsp[-5].identval)) == 1){flag_error = 1;}
                        (yyval.intval) = lookup((yyvsp[-5].identval), 0); 
                        if((yyval.intval) == -1){flag_error = 1;} 
                        (yyval.intval) = cast_type((yyval.intval), (yyvsp[0].intval), getType((yyvsp[-2].typeval)));
                        if((yyval.intval) == -1){flag_error = 1;}
                        int addr[2]; 
                        get_address((yyvsp[-5].identval), addr);
                        switch (addr[1]) {
                            case 0: fprintf(stdout, "    pop QWORD [rbp-%d]\n    push QWORD [rbp-%d]\n", addr[0], addr[0]); break;
                            //case 1: fprintf(stdout, "    pop QWORD [globals+%d]\n    push QWORD [globals+%d]\n", addr[0], addr[0]); break;
                            case 2: fprintf(stderr, "%s is a const variable near line %d\n", (yyvsp[-5].identval), line_num); break;
                            default: yyerror("impossible"); break;
                        }
                    }
#line 1935 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 463 "yacc/compil.y" /* yacc.c:1646  */
    {
                if (check_types((yyvsp[0].intval), INTEGER) == 0)
                    fprintf(stderr, "Can only apply || to entier values\n"); 
                fprintf(stdout, "    pop rax\n    cmp rax,0\n    jne go_end%d\n", (yyval.intval)=jump_label++);
            }
#line 1945 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 469 "yacc/compil.y" /* yacc.c:1646  */
    {
                if (check_types((yyvsp[-3].intval), (yyvsp[0].intval)) == 0)
                    fprintf(stderr, "Can only apply || to entier values\n"); 
                fprintf(stdout, "    pop rcx\n    mov rax,rcx\ngo_end%d:\n    push rax\n",(yyvsp[-2].intval));
                (yyval.intval) = INTEGER;
            }
#line 1956 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 475 "yacc/compil.y" /* yacc.c:1646  */
    {(yyval.intval) = (yyvsp[0].intval);}
#line 1962 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 477 "yacc/compil.y" /* yacc.c:1646  */
    { 
                if (check_types((yyvsp[0].intval), INTEGER) == 0)
                    fprintf(stderr, "Can only apply && to entier values\n"); 
                fprintf(stdout, "    pop rax\n    cmp rax,0\n    je go_end%d\n",(yyval.intval)=jump_label++);
            }
#line 1972 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 483 "yacc/compil.y" /* yacc.c:1646  */
    {
                if (check_types((yyvsp[-3].intval), (yyvsp[0].intval)) == 0)
                    fprintf(stderr, "Can only apply && to entier values\n"); 
                fprintf(stdout, "    pop rcx\n    mov rax,rcx\ngo_end%d:\n    push rax\n",(yyvsp[-2].intval));          
                (yyval.intval) = INTEGER;
            }
#line 1983 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 489 "yacc/compil.y" /* yacc.c:1646  */
    {(yyval.intval) = (yyvsp[0].intval);}
#line 1989 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 493 "yacc/compil.y" /* yacc.c:1646  */
    {
            if (check_types((yyvsp[-2].intval), (yyvsp[0].intval)) == 0)
                fprintf(stderr, "Can only apply == to values of same type\n"); 
            fprintf(stdout, "    pop rcx\n    pop rax\n    cmp rax,rcx\n    mov rax,0\n");
            if (strcmp((yyvsp[-1].eqval),"==") == 0){
                fprintf(stdout, "    jne cond_eq%d\n",jump_label);
            }
            else if (strcmp((yyvsp[-1].eqval),"!=") == 0){
                fprintf(stdout, "    je cond_eq%d\n",jump_label);
            }
            fprintf(stdout, "    mov rax,1\ncond_eq%d:\n    push rax\n",jump_label++);
            (yyval.intval) = INTEGER;
        }
#line 2007 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 506 "yacc/compil.y" /* yacc.c:1646  */
    {(yyval.intval) = (yyvsp[0].intval);}
#line 2013 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 508 "yacc/compil.y" /* yacc.c:1646  */
    {
                if(check_types((yyvsp[-2].intval), (yyvsp[0].intval)) == 0)
                    fprintf(stderr, "Can only apply >=, <=, > and < to entier values\n"); 
                fprintf(stdout,"    pop rcx\n    pop rax\n    cmp rax, rcx\n    mov rax,1\n");
                if (strcmp((yyvsp[-1].orderval), ">") == 0) {
                    fprintf(stdout,"    jg cond_ord%d\n",jump_label); 
                    fprintf(stdout, "    mov rax,0\n");
                }
                else if (strcmp((yyvsp[-1].orderval), "<=") == 0) {
                    fprintf(stdout,"    jng cond_ord%d \n", jump_label);
                    fprintf(stdout,"    je cond_ord%d \n", jump_label);
                    fprintf(stdout,"    mov rax, 0 \n");
                }
                else if (strcmp((yyvsp[-1].orderval), "<") == 0) {
                    fprintf(stdout,"    mov rax, 0 \n");
                    fprintf(stdout,"    jg cond_ord%d \n", jump_label);
                    fprintf(stdout,"    je cond_ord%d \n", jump_label);
                    fprintf(stdout,"    mov rax, 1 \n");
                }
                else if (strcmp((yyvsp[-1].orderval), ">=") == 0) {
                    fprintf(stdout,"    jg cond_ord%d \n", jump_label);
                    fprintf(stdout,"    je cond_ord%d \n", jump_label);
                    fprintf(stdout,"    mov rax, 0 \n");
                }
                fprintf(stdout, "cond_ord%d:\n    push rax\n",jump_label++);
                (yyval.intval) = INTEGER;
            }
#line 2045 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 535 "yacc/compil.y" /* yacc.c:1646  */
    {(yyval.intval) = (yyvsp[0].intval);}
#line 2051 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 537 "yacc/compil.y" /* yacc.c:1646  */
    {
                        (yyval.intval) = max_type((yyvsp[-2].intval), (yyvsp[0].intval));
                        switch ((yyvsp[-1].addsubval)) {
                            case '+': fprintf(stdout, "    pop rcx\n    pop rax\n    add rax, rcx\n    push rax\n"); break;
                            case '-': fprintf(stdout, "    pop rcx\n    pop rax\n    sub rax, rcx\n    push rax\n"); break;
                        }
                        
                    }
#line 2064 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 545 "yacc/compil.y" /* yacc.c:1646  */
    {(yyval.intval) = (yyvsp[0].intval);}
#line 2070 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 547 "yacc/compil.y" /* yacc.c:1646  */
    {
                        (yyval.intval) = max_type((yyvsp[-2].intval), (yyvsp[0].intval));
                        fprintf(stdout, "    pop rcx\n    pop rax\n");
                        switch ((yyvsp[-1].divstarval)) {
                            case '*': fprintf(stdout, "    imul rcx\n    push rax\n"); break;
                            case '/': fprintf(stdout, "    mov rdx,0\n    idiv rcx\n    push rax\n"); break;
                            case '%': fprintf(stdout, "    mov rdx,0\n    idiv rcx\n    push rdx\n"); break;
                        }
                    }
#line 2084 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 556 "yacc/compil.y" /* yacc.c:1646  */
    {(yyval.intval) = (yyvsp[0].intval);}
#line 2090 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 560 "yacc/compil.y" /* yacc.c:1646  */
    {
                if (check_types((yyvsp[0].intval), INTEGER) == 0)
                    fprintf(stderr, "Can only apply - + to entier values\n"); 
                (yyval.intval) = (yyvsp[0].intval);
                if ((yyvsp[-1].addsubval) == '-')
                    fprintf(stdout, "    pop rax\n     mov rcx, -1\n    imul rcx\n   push rax\n");
            }
#line 2102 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 568 "yacc/compil.y" /* yacc.c:1646  */
    {
                if (check_types((yyvsp[0].intval), INTEGER) == 0)
                    fprintf(stderr, "Can only apply ! to entier values\n"); 
                (yyval.intval) = (yyvsp[0].intval);
                fprintf(stdout,"    pop rax\n    cmp rax, 0\n    mov rax,1\n    je if_no%d\n", jump_label);
                fprintf(stdout, "    mov rax,0\nif_no%d:\n    push rax\n", jump_label++);
            }
#line 2114 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 575 "yacc/compil.y" /* yacc.c:1646  */
    {(yyval.intval) = (yyvsp[-1].intval);}
#line 2120 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 576 "yacc/compil.y" /* yacc.c:1646  */
    {
    				(yyval.intval) = lookup((yyvsp[0].identval), 0);
    				if((yyval.intval) == -1){
    					flag_error = 1;
                    }
                    if(globale_variable((yyvsp[0].identval)) == 1){
                        fprintf(stdout, "    push QWORD [%s]\n", (yyvsp[0].identval));
                    }
                    else if(globale_const((yyvsp[0].identval)) == 1){
                        fprintf(stdout, "    push QWORD %s\n", (yyvsp[0].identval));
                    }
                    else{                       
                        int address[2]; 
                        if(get_address((yyvsp[0].identval), address) == -1)
                            flag_error = 1; 
                        switch(address[1]){
                            case 0: fprintf(stdout, "    push QWORD [rbp-%d]\n", address[0]); break;
                            //case 1: fprintf(stdout, "    push QWORD [globals+%d]\n", address[0]); break;
                            case 2: fprintf(stdout, "    push QWORD %d\n", address[0]); break;
                        }
                    }

    			}
#line 2148 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 599 "yacc/compil.y" /* yacc.c:1646  */
    {
    				(yyval.intval) = lookup((yyvsp[0].identval), 0);
    				if((yyval.intval) == -1){
    					flag_error = 1;
                    }
                    int address[2]; 
                    if(get_address((yyvsp[0].identval), address) == -1)
                        flag_error = 1; 
                    switch(address[1]){
                        case 0: fprintf(stdout, "    push QWORD [rbp-%d]\n", address[0]); break;
                        case 1: fprintf(stdout, "    push QWORD [globals+%d]\n", address[0]); break;
                        case 2: fprintf(stdout, "    push QWORD %d\n", address[0]); break;
                    }

    			}
#line 2168 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 615 "yacc/compil.y" /* yacc.c:1646  */
    {   
                    if(lvalue_called_is_array == 1){
                        (yyval.intval) = lookup((yyvsp[0].identval), 1); int addr[2]; get_address((yyvsp[0].identval), addr);
                        switch (addr[1]) {
                            case 0: fprintf(stdout, "    pop rax\n    mov rbx,8\n    imul rbx\n    mov rbx,rbp\n");
                                    fprintf(stdout, "add rax,%d\n   sub rbx,rax\n    push QWORD [rbx]\n", addr[0]); break;
                            //case 1: fprintf(stdout, "    pop rbx\n    push QWORD [globals+rbx*8+%d]\n", addr[0]); break;
                            case 2: fprintf(stderr, "%s is not an array near line %d\n", (yyvsp[0].identval), line_num); break;
                            default: yyerror("impossible"); break;
                        }
                    }
                }
#line 2185 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 627 "yacc/compil.y" /* yacc.c:1646  */
    {(yyval.intval) = INTEGER; fprintf(stdout, "    push QWORD %d\n", (yyvsp[0].intval));}
#line 2191 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 628 "yacc/compil.y" /* yacc.c:1646  */
    {(yyval.intval) = CHAR; fprintf(stdout, "    push QWORD %d\n", (yyvsp[0].charval));}
#line 2197 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 630 "yacc/compil.y" /* yacc.c:1646  */
    {
                    add_call_cell((yyvsp[0].identval));
                    args = get_func_i_arg();
                    get_func_call_name(name_called_function);
                }
#line 2207 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 638 "yacc/compil.y" /* yacc.c:1646  */
    {
                    if(((yyval.intval) = lookupFunction((yyvsp[-4].identval))) == -1)
                        flag_error = 1;
                    fprintf(stdout, "    call %s\n",(yyvsp[-4].identval));
                    check_nargs((yyvsp[-4].identval), *args);
                    int i;
                    for (i = 0; i < *args; i++){
                        fprintf(stdout, "    pop rbx\n");
                    }
                    if (lookupFunction(name_called_function) != VOIDTYPE)
                        fprintf(stdout, "    push rax\n");
                    remove_call_cell();
                    args = get_func_i_arg();
                    get_func_call_name(name_called_function);
                }
#line 2227 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 658 "yacc/compil.y" /* yacc.c:1646  */
    {call_num_array = 0; lvalue_called_is_array = 0;}
#line 2233 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 659 "yacc/compil.y" /* yacc.c:1646  */
    {
                        strcpy((yyval.identval), (yyvsp[-2].identval));
                        if(call_num_array >= 1){
                            lvalue_called_is_array = 1;
                        }
                    }
#line 2244 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 668 "yacc/compil.y" /* yacc.c:1646  */
    {call_num_array++;}
#line 2250 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 679 "yacc/compil.y" /* yacc.c:1646  */
    {
                            
                            if (check_types(get_arg_type(name_called_function, *args), (yyvsp[0].intval)) == 0)
                                fprintf(stderr, "%d argument type does not match the expected type\n", (*args));
                            (*args)++;
                        }
#line 2261 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 685 "yacc/compil.y" /* yacc.c:1646  */
    {
                    if (check_types(get_arg_type(name_called_function, *args), (yyvsp[0].intval)) == 0)
                       fprintf(stderr, "%d argument type does not match the expected type\n", (*args));
                    (*args)++; 
                }
#line 2271 "bin/compil.tab.c" /* yacc.c:1646  */
    break;


#line 2275 "bin/compil.tab.c" /* yacc.c:1646  */
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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
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

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
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
  return yyresult;
}
#line 693 "yacc/compil.y" /* yacc.c:1906  */


void yyerror(char *s){
    printf("Erreur %s near line %d \n", s, line_num);
    flag_error = 1;
}
 
int main(int argc, char* argv[]){
    option_parsing(argc, argv);
	initProg();
    yyparse();
    return flag_error;
}
