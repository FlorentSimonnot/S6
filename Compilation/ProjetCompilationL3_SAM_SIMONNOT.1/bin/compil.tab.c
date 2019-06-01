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

int yylex(void);
void yyerror(char* s);
int flag_error = 0;
int type_const = -1; 
int type_var = -1;
int type_define = -1;
int type_macro_assign = -1;
int parameters = 0;
int *i_args = NULL;
char name_function[MAXNAME];
char name_called_function[MAXNAME];

#line 84 "bin/compil.tab.c" /* yacc.c:339  */

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
#line 19 "yacc/compil.y" /* yacc.c:355  */

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

#line 186 "bin/compil.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_BIN_COMPIL_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 203 "bin/compil.tab.c" /* yacc.c:358  */

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
#define YYLAST   469

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  41
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  38
/* YYNRULES -- Number of rules.  */
#define YYNRULES  127
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  295

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
       0,    90,    90,    94,    95,    99,   102,   103,   104,   105,
     109,   110,   112,   116,   117,   118,   119,   123,   128,   134,
     139,   147,   148,   152,   153,   157,   158,   162,   163,   164,
     165,   166,   170,   171,   172,   176,   181,   182,   186,   187,
     188,   192,   196,   197,   203,   204,   210,   216,   217,   218,
     219,   223,   224,   228,   229,   233,   238,   243,   244,   245,
     246,   250,   251,   252,   256,   260,   264,   265,   266,   269,
     273,   274,   277,   281,   282,   292,   302,   318,   334,   341,
     342,   343,   344,   345,   346,   347,   348,   349,   350,   351,
     352,   353,   354,   357,   364,   371,   378,   382,   383,   385,
     386,   389,   390,   392,   393,   395,   402,   404,   413,   416,
     417,   418,   419,   435,   436,   437,   438,   439,   446,   450,
     454,   455,   456,   460,   461,   465,   469,   473
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
  "'!'", "$accept", "Prog", "DeclInclude", "DeclDefine", "LitteralDefine",
  "LitteralReel", "DeclConsts", "ListConst", "Litteral", "NombreSigne",
  "ReelSigne", "DeclVars", "Declarateurs", "Declarateur", "DeclInitVars",
  "DeclInitVar", "DeclInit", "DeclarateurTableau", "DeclFoncts",
  "DeclFonct", "EnTeteFonct", "Parametres", "ListTypVar", "Corps",
  "SuiteInstr", "Instr", "Exp", "EB", "TB", "FB", "M", "E", "T", "F",
  "LValue", "Tableau", "Arguments", "ListExp", YY_NULLPTR
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

#define YYPACT_NINF -228

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-228)))

#define YYTABLE_NINF -125

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -228,    98,   103,  -228,    63,   402,  -228,   105,    94,   199,
      80,    80,    83,   138,   138,   225,  -228,  -228,  -228,  -228,
     136,  -228,  -228,  -228,  -228,   133,   120,    81,   216,   230,
     171,    19,  -228,   143,  -228,   160,   204,  -228,  -228,  -228,
     156,   200,   169,   205,   -10,   213,    91,   226,  -228,   184,
     227,   269,  -228,  -228,  -228,  -228,  -228,     9,  -228,  -228,
    -228,   202,    11,   208,    93,   208,  -228,    93,   188,    96,
     270,  -228,  -228,   270,  -228,   145,   217,   224,   229,   132,
    -228,   160,   247,   258,    70,   298,   273,  -228,   279,    32,
     284,  -228,  -228,    10,  -228,  -228,     7,   285,   253,  -228,
    -228,  -228,  -228,  -228,    78,   288,   172,  -228,  -228,  -228,
    -228,   286,   287,  -228,  -228,  -228,  -228,   299,   308,  -228,
    -228,  -228,  -228,  -228,  -228,  -228,   274,   270,   212,  -228,
    -228,   321,   323,   156,   290,   245,  -228,  -228,   373,   291,
     297,   300,     3,   302,   304,    40,  -228,   313,  -228,  -228,
     373,  -228,  -228,   373,  -228,   327,   335,   328,   341,   342,
     355,   346,  -228,   333,  -228,  -228,    64,   379,    64,  -228,
    -228,  -228,   283,   296,   373,   373,   373,   373,   309,  -228,
     338,  -228,   336,   252,  -228,  -228,   373,   373,   373,   373,
     373,   373,   389,  -228,   352,   125,     1,   337,   356,   359,
     362,   364,   366,   368,   369,    84,   372,   378,    15,  -228,
     292,  -228,  -228,   328,   341,   342,   355,   346,  -228,    75,
     349,  -228,  -228,   373,   373,   371,   371,  -228,   381,   384,
     388,   391,   395,   332,   332,   332,   332,   427,   428,   159,
     418,   403,  -228,  -228,  -228,  -228,  -228,  -228,  -228,  -228,
    -228,  -228,  -228,   420,  -228,   404,   405,   406,   407,   399,
     373,   332,   373,   373,   373,   373,   373,  -228,  -228,   408,
     409,   410,   411,   414,   373,   373,   373,   419,   416,   415,
     421,   422,   118,   423,  -228,   332,   332,   332,   332,   332,
    -228,  -228,  -228,  -228,  -228
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     0,     9,     1,     0,     0,     3,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    10,    11,     8,     7,
       0,    25,     5,     6,    12,     0,     0,     0,     0,     0,
       0,     0,    52,    54,    26,     0,     0,    14,    15,    13,
       0,    35,     0,     0,    35,     0,     0,     0,    40,     0,
       0,     0,    51,    16,    53,    23,    22,     0,    19,    21,
      20,     0,     0,    37,     0,    36,    29,     0,     0,     0,
       0,    27,    30,     0,    28,     0,     0,     0,     0,     0,
      24,     0,     0,     0,     0,     0,     0,    61,     0,     0,
       0,    42,    46,     0,    44,    41,     0,     0,    35,    32,
      33,    39,    34,    38,     0,     0,     0,    17,    18,    48,
      47,     0,     0,    67,    68,    65,    59,     0,     0,    60,
      43,    45,    57,    55,    58,    56,     0,     0,     0,    50,
      49,     0,     0,    35,     0,   122,   114,   116,     0,     0,
       0,     0,     0,     0,     0,     0,   115,     0,   113,    73,
       0,    71,    69,     0,    70,     0,    96,    98,   100,   102,
     104,   106,   108,   112,    66,    64,     0,     0,     0,   119,
     109,   112,     0,     0,     0,     0,     0,     0,     0,    75,
       0,    71,     0,     0,   110,    72,     0,     0,     0,     0,
       0,     0,     0,   126,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    74,
       0,   111,    84,    97,    99,   101,   103,   105,   107,   113,
       0,    93,   118,     0,     0,   122,   122,   117,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   127,   125,   121,   120,    91,    76,    92,    77,
      78,    85,    86,    79,    81,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    94,    80,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    83,     0,     0,     0,     0,     0,
      87,    90,    88,    89,    82
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -228,  -228,  -228,  -228,   236,  -228,   397,   437,   376,  -228,
     -24,   382,   385,   -28,   390,   392,  -228,   150,  -228,   431,
    -228,   128,  -228,  -228,   -68,  -227,  -145,  -228,   266,   276,
     278,   275,   277,  -135,  -136,    88,   301,  -228
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,     5,    18,    23,     9,    26,    58,    59,
      24,    15,    45,    42,    47,    48,    95,    65,    31,    32,
      33,    88,    89,    54,   128,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   169,   194,   195
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     180,    46,   171,   170,   175,   182,   251,   252,   253,   254,
     113,    60,    82,    80,   120,    83,   238,   171,   184,    -2,
      50,   193,   197,   193,    68,    62,    51,    69,    30,   203,
     204,   205,   206,   117,   268,    34,   121,   225,   166,   122,
     176,   134,    99,   135,   136,   102,   137,   221,   138,   239,
     171,   171,   171,   171,   171,   171,   218,   108,   290,   291,
     292,   293,   294,   118,   -62,   134,   146,   135,   136,   148,
     137,   111,   138,   179,   112,   182,   -95,   150,   242,   243,
     153,   113,    38,   183,    16,   234,    17,    16,     6,    17,
     146,    20,    72,   148,    85,    11,  -124,    96,     3,    46,
      86,   150,    87,    86,   153,    87,   -95,   -95,   -95,    21,
     124,   -95,    36,   210,    39,   267,   235,   269,   270,   271,
     272,   273,   -34,    12,   -34,   -63,   223,     4,   -63,   279,
     280,   281,   283,    13,    10,   -31,   -31,    14,   -31,   -31,
     -31,    25,   -31,   -31,   -31,   -31,   104,   -31,   -31,   -31,
     288,    36,    86,    37,    87,   166,   224,  -123,   -31,   -31,
     257,   -31,    34,   258,    55,   -31,    56,    35,    57,   -31,
     -31,   -31,   -31,   126,    49,   -71,   -71,   -63,   -71,   127,
     -71,    53,   -71,   -71,   -71,   -71,    21,   -71,   -71,   -71,
      63,    62,    91,    63,    92,    90,    93,    97,   -71,   -71,
      13,   -71,    66,   105,    14,   -71,   -31,    61,   -31,   -71,
     -71,   -71,   -71,   134,    94,   135,   136,    40,   137,    41,
     138,    75,   139,   140,   141,   142,    28,   143,   144,   145,
      76,    43,    29,    44,    30,    62,    81,    64,   146,   147,
      62,   148,    67,    84,    70,   149,    71,    19,    22,   150,
     151,   152,   153,   134,    64,   135,   136,    73,   137,    74,
     138,    67,   139,   140,   141,   142,    69,   143,   144,   145,
      77,    40,    78,    98,   114,    40,   115,   133,   146,   147,
     167,   148,   168,   109,   199,   149,   200,    68,    62,   150,
     151,   212,   153,   134,   110,   135,   136,   201,   137,   202,
     138,   113,   139,   140,   141,   142,   131,   143,   144,   145,
     207,   116,   208,   244,   245,   132,   119,   123,   146,   147,
     125,   148,   129,   130,   164,   149,   165,   166,   172,   150,
     151,   240,   153,   134,   173,   135,   136,   174,   137,   177,
     138,   178,   139,   140,   141,   142,   187,   143,   144,   145,
     134,   181,   135,   136,   186,   137,   241,   138,   146,   147,
     185,   148,   188,   190,   189,   149,   191,   192,   211,   150,
     151,   209,   153,   226,   134,   146,   135,   136,   148,   137,
     196,   138,   135,   136,   222,   137,   150,   138,   227,   153,
     134,   228,   135,   136,   229,   137,   230,   138,   231,   146,
     232,   233,   148,     7,   236,   146,   167,   -16,   148,   -16,
     150,   -16,   237,   153,   246,   146,   150,   247,   219,   153,
     282,   248,   135,   136,   249,   137,   220,   138,   250,   153,
       8,   255,   256,   259,   261,   260,   266,   262,   263,   264,
     265,   274,   275,   276,   277,   146,   278,   285,   148,   284,
      79,    27,   213,   286,   287,   289,   150,   107,   101,   153,
     100,   106,    52,   214,   216,   103,   215,   217,     0,   198
};

static const yytype_int16 yycheck[] =
{
     145,    29,   138,   138,     1,   150,   233,   234,   235,   236,
       3,    35,     1,     4,     4,     4,     1,   153,   153,     0,
       1,   166,   167,   168,    34,    35,     7,    37,     9,   174,
     175,   176,   177,     1,   261,    26,    26,    36,    37,    32,
      37,     1,    70,     3,     4,    73,     6,   192,     8,    34,
     186,   187,   188,   189,   190,   191,   191,    81,   285,   286,
     287,   288,   289,    31,    32,     1,    26,     3,     4,    29,
       6,     1,     8,    33,     4,   220,     1,    37,   223,   224,
      40,     3,     1,   151,     4,     1,     6,     4,    25,     6,
      26,     8,     1,    29,     1,     1,    32,     1,     0,   127,
       7,    37,     9,     7,    40,     9,    31,    32,    33,    26,
      32,    36,    31,   181,    33,   260,    32,   262,   263,   264,
     265,   266,    31,    29,    33,    32,     1,    24,    32,   274,
     275,   276,   277,     1,    29,     3,     4,     5,     6,     7,
       8,     3,    10,    11,    12,    13,     1,    15,    16,    17,
      32,    31,     7,    33,     9,    37,    31,    32,    26,    27,
       1,    29,    26,     4,     4,    33,     6,    34,     8,    37,
      38,    39,    40,     1,     3,     3,     4,    32,     6,     7,
       8,    38,    10,    11,    12,    13,    26,    15,    16,    17,
      40,    35,     4,    43,     6,    67,     8,    69,    26,    27,
       1,    29,    33,    75,     5,    33,     7,     3,     9,    37,
      38,    39,    40,     1,    26,     3,     4,     1,     6,     3,
       8,    37,    10,    11,    12,    13,     1,    15,    16,    17,
       3,     1,     7,     3,     9,    35,    34,    37,    26,    27,
      35,    29,    37,    35,    31,    33,    33,    11,    12,    37,
      38,    39,    40,     1,    37,     3,     4,    31,     6,    33,
       8,    37,    10,    11,    12,    13,    37,    15,    16,    17,
       1,     1,     3,     3,     1,     1,     3,     3,    26,    27,
      35,    29,    37,    36,     1,    33,     3,    34,    35,    37,
      38,    39,    40,     1,    36,     3,     4,     1,     6,     3,
       8,     3,    10,    11,    12,    13,     7,    15,    16,    17,
       1,    32,     3,   225,   226,     7,    32,    32,    26,    27,
      32,    29,    36,    36,     3,    33,     3,    37,    37,    37,
      38,    39,    40,     1,    37,     3,     4,    37,     6,    37,
       8,    37,    10,    11,    12,    13,    18,    15,    16,    17,
       1,    38,     3,     4,    19,     6,     7,     8,    26,    27,
      33,    29,    21,     8,    22,    33,    20,    34,    32,    37,
      38,    33,    40,    36,     1,    26,     3,     4,    29,     6,
       1,     8,     3,     4,    32,     6,    37,     8,    32,    40,
       1,    32,     3,     4,    32,     6,    32,     8,    32,    26,
      32,    32,    29,     1,    32,    26,    35,     5,    29,     7,
      37,     9,    34,    40,    33,    26,    37,    33,    29,    40,
       1,    33,     3,     4,    33,     6,    37,     8,    33,    40,
      28,     4,     4,    15,    14,    32,    37,    33,    33,    33,
      33,    33,    33,    33,    33,    26,    32,    32,    29,    33,
      53,    14,   186,    32,    32,    32,    37,    81,    73,    40,
      70,    79,    31,   187,   189,    73,   188,   190,    -1,   168
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    42,    43,     0,    24,    44,    25,     1,    28,    47,
      29,     1,    29,     1,     5,    52,     4,     6,    45,    45,
       8,    26,    45,    46,    51,     3,    48,    48,     1,     7,
       9,    59,    60,    61,    26,    34,    31,    33,     1,    33,
       1,     3,    54,     1,     3,    53,    54,    55,    56,     3,
       1,     7,    60,    38,    64,     4,     6,     8,    49,    50,
      51,     3,    35,    58,    37,    58,    33,    37,    34,    37,
      31,    33,     1,    31,    33,    37,     3,     1,     3,    47,
       4,    34,     1,     4,    35,     1,     7,     9,    62,    63,
      62,     4,     6,     8,    26,    57,     1,    62,     3,    54,
      55,    53,    54,    56,     1,    62,    52,    49,    51,    36,
      36,     1,     4,     3,     1,     3,    32,     1,    31,    32,
       4,    26,    32,    32,    32,    32,     1,     7,    65,    36,
      36,     7,     7,     3,     1,     3,     4,     6,     8,    10,
      11,    12,    13,    15,    16,    17,    26,    27,    29,    33,
      37,    38,    39,    40,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,     3,     3,    37,    35,    37,    76,
      74,    75,    37,    37,    37,     1,    37,    37,    37,    33,
      67,    38,    67,    65,    74,    33,    19,    18,    21,    22,
       8,    20,    34,    67,    77,    78,     1,    67,    77,     1,
       3,     1,     3,    67,    67,    67,    67,     1,     3,    33,
      65,    32,    39,    69,    70,    71,    72,    73,    74,    29,
      37,    67,    32,     1,    31,    36,    36,    32,    32,    32,
      32,    32,    32,    32,     1,    32,    32,    34,     1,    34,
      39,     7,    67,    67,    76,    76,    33,    33,    33,    33,
      33,    66,    66,    66,    66,     4,     4,     1,     4,    15,
      32,    14,    33,    33,    33,    33,    37,    67,    66,    67,
      67,    67,    67,    67,    33,    33,    33,    33,    32,    67,
      67,    67,     1,    67,    33,    32,    32,    32,    32,    32,
      66,    66,    66,    66,    66
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    41,    42,    43,    43,    44,    44,    44,    44,    44,
      45,    45,    46,    47,    47,    47,    47,    48,    48,    48,
      48,    49,    49,    50,    50,    51,    51,    52,    52,    52,
      52,    52,    53,    53,    53,    54,    54,    54,    55,    55,
      55,    56,    57,    57,    57,    57,    57,    58,    58,    58,
      58,    59,    59,    60,    60,    61,    61,    61,    61,    61,
      61,    62,    62,    62,    63,    63,    63,    63,    63,    64,
      65,    65,    66,    66,    66,    66,    66,    66,    66,    66,
      66,    66,    66,    66,    66,    66,    66,    66,    66,    66,
      66,    66,    66,    67,    67,    67,    67,    68,    68,    69,
      69,    70,    70,    71,    71,    72,    72,    73,    73,    74,
      74,    74,    74,    74,    74,    74,    74,    74,    74,    75,
      76,    76,    76,    77,    77,    78,    78,    78
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     5,     3,     0,     4,     4,     4,     4,     0,
       1,     1,     1,     4,     4,     4,     0,     5,     5,     3,
       3,     1,     1,     1,     2,     1,     2,     4,     4,     4,
       4,     0,     3,     3,     1,     1,     2,     2,     3,     3,
       1,     3,     1,     2,     1,     2,     1,     3,     3,     4,
       4,     2,     1,     2,     1,     5,     5,     5,     5,     5,
       5,     1,     1,     0,     4,     2,     4,     2,     2,     5,
       2,     0,     2,     1,     3,     2,     5,     5,     5,     5,
       7,     5,    11,     9,     3,     5,     5,    11,    11,    11,
      11,     5,     5,     3,     6,     3,     1,     3,     1,     3,
       1,     3,     1,     3,     1,     3,     1,     3,     1,     2,
       2,     3,     1,     1,     1,     1,     1,     4,     4,     2,
       4,     4,     0,     1,     0,     3,     1,     3
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
        case 5:
#line 99 "yacc/compil.y" /* yacc.c:1646  */
    {
                                                            addMacro((yyvsp[-1].name_defineval), type_define, (yyvsp[0].intval), .0);
                                                        }
#line 1508 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 102 "yacc/compil.y" /* yacc.c:1646  */
    {addMacro((yyvsp[-1].name_defineval), type_define, 0, (yyvsp[0].reelval));}
#line 1514 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 109 "yacc/compil.y" /* yacc.c:1646  */
    {type_define = INTEGER; (yyval.intval) = (yyvsp[0].intval);}
#line 1520 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 110 "yacc/compil.y" /* yacc.c:1646  */
    {type_define = CHAR; (yyval.intval) = (yyvsp[0].charval);}
#line 1526 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 112 "yacc/compil.y" /* yacc.c:1646  */
    {type_define = REAL; (yyval.reelval) = (yyvsp[0].reelval);}
#line 1532 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 123 "yacc/compil.y" /* yacc.c:1646  */
    {
       										if(addConst((yyvsp[-2].identval), type_const, (yyvsp[0].intval), .0) == 0){
       											flag_error = 1;
       										}
       									}
#line 1542 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 128 "yacc/compil.y" /* yacc.c:1646  */
    {
                                            type_const = REAL;
                                            if(addConst((yyvsp[-2].identval), type_const, 0, (yyvsp[0].reelval)) == 0){
                                                flag_error = 1;
                                            }
                                        }
#line 1553 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 134 "yacc/compil.y" /* yacc.c:1646  */
    {
                                            if(addConst((yyvsp[-2].identval), type_const, (yyvsp[0].intval), .0) == 0){
                                                flag_error = 1;
                                            }
                                        }
#line 1563 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 139 "yacc/compil.y" /* yacc.c:1646  */
    {   type_const = REAL;
                                            if(addConst((yyvsp[-2].identval), type_const, 0, (yyvsp[0].reelval)) == 0){
                                                flag_error = 1;
                                            }
                                        }
#line 1573 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 147 "yacc/compil.y" /* yacc.c:1646  */
    {type_const = INTEGER;}
#line 1579 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 148 "yacc/compil.y" /* yacc.c:1646  */
    {type_const = CHAR;}
#line 1585 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 152 "yacc/compil.y" /* yacc.c:1646  */
    {(yyval.intval) = (yyvsp[0].intval);}
#line 1591 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 153 "yacc/compil.y" /* yacc.c:1646  */
    {if((yyvsp[-1].addsubval) == '-'){(yyval.intval) = -((yyvsp[0].intval));}}
#line 1597 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 157 "yacc/compil.y" /* yacc.c:1646  */
    {(yyval.reelval) = (yyvsp[0].reelval);}
#line 1603 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 158 "yacc/compil.y" /* yacc.c:1646  */
    {if((yyvsp[-1].addsubval) == '-') (yyval.reelval) = -((yyvsp[0].reelval));}
#line 1609 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 176 "yacc/compil.y" /* yacc.c:1646  */
    {
					if(addVar((yyvsp[0].identval), type_var, 0, 0, .0) == 0){
						flag_error = 1;
					}
				}
#line 1619 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 196 "yacc/compil.y" /* yacc.c:1646  */
    {addVar((yyvsp[(-1) - (1)].identval), type_var, 0, (yyvsp[0].intval), .0);}
#line 1625 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 197 "yacc/compil.y" /* yacc.c:1646  */
    {
					if((yyvsp[-1].addsubval) == '-'){
						(yyval.intval) = -((yyvsp[0].intval));
					}
					addVar((yyvsp[(-1) - (2)].identval), type_var, 0, (yyval.intval), .0);
				  }
#line 1636 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 203 "yacc/compil.y" /* yacc.c:1646  */
    {addVar((yyvsp[(-1) - (1)].identval), type_var, 0, 0, (yyvsp[0].reelval));}
#line 1642 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 204 "yacc/compil.y" /* yacc.c:1646  */
    {
                    if((yyvsp[-1].addsubval) == '-'){
                        (yyval.intval) = -((yyvsp[0].reelval));
                    }
                    addVar((yyvsp[(-1) - (2)].identval), type_var, 0, 0, (yyval.intval));
                  }
#line 1653 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 210 "yacc/compil.y" /* yacc.c:1646  */
    {
					addVar((yyvsp[(-1) - (1)].identval), type_var, 0, (yyvsp[0].charval), .0);
				  }
#line 1661 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 233 "yacc/compil.y" /* yacc.c:1646  */
    {   strcpy(name_function, (yyvsp[-3].identval));
                                            addFun((yyvsp[-3].identval), getType((yyvsp[-4].typeval)));
                                            createStack();
                                            parameters = 0;
                                        }
#line 1671 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 238 "yacc/compil.y" /* yacc.c:1646  */
    {   
                                            strcpy(name_function, (yyvsp[-3].identval));
                                            addFun((yyvsp[-3].identval), VOIDTYPE);
                                            parameters = 0;
                                        }
#line 1681 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 256 "yacc/compil.y" /* yacc.c:1646  */
    {  addVar((yyvsp[0].identval), type_var, 1, 0, .0); 
                                    parameters++; 
                                    /*addArg(name_function, type_var);*/
                                 }
#line 1690 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 260 "yacc/compil.y" /* yacc.c:1646  */
    {  addVar((yyvsp[0].identval), type_var, 1, 0, .0); 
                                    parameters++; 
                                    /*addArg(name_function, type_var);*/
                                 }
#line 1699 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 277 "yacc/compil.y" /* yacc.c:1646  */
    {                
                        if ((yyvsp[-1].intval) != VOIDTYPE) 
                            fprintf(stdout, "    pop rcx\n");
                    }
#line 1708 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 282 "yacc/compil.y" /* yacc.c:1646  */
    {  
                            int type_fun = lookupFunction(name_function); 
                            if(type_fun == -1)
                                flag_error = 1; 
                            if(check_types((yyvsp[-1].intval), type_fun) == 0){
                                fprintf(stderr, "The function must return a value of this type %d\n", type_fun);
                                flag_error = 1;
                            }
                            fprintf(stdout, "    pop rax\n    jmp fin_%s\n", name_function);
                        }
#line 1723 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 292 "yacc/compil.y" /* yacc.c:1646  */
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
#line 1738 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 303 "yacc/compil.y" /* yacc.c:1646  */
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
#line 1758 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 319 "yacc/compil.y" /* yacc.c:1646  */
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
#line 1778 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 334 "yacc/compil.y" /* yacc.c:1646  */
    {
                                        switch ((yyvsp[-2].intval)) {
                                            case INTEGER: fprintf(stdout, "    pop rsi\n    call _print_ent\n"); break;
                                            case CHAR: fprintf(stdout, "    pop rsi\n    call _print_car\n"); break;
                                            case VOIDTYPE: yyerror("Can't print void value"); break;
                                        }
                                    }
#line 1790 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 357 "yacc/compil.y" /* yacc.c:1646  */
    {
                        if(isConstante((yyvsp[-2].identval)) == 1){flag_error = 1;}
                        (yyval.intval) = lookup((yyvsp[-2].identval), 0); 
                        if((yyval.intval) == -1){flag_error = 1;} 
                        (yyval.intval) = cast_type((yyval.intval), (yyvsp[0].intval), 0);
                        if((yyval.intval) == -1){flag_error = 1;}
                    }
#line 1802 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 364 "yacc/compil.y" /* yacc.c:1646  */
    {
                        if(isConstante((yyvsp[-5].identval)) == 1){flag_error = 1;}
                        (yyval.intval) = lookup((yyvsp[-5].identval), 0); 
                        if((yyval.intval) == -1){flag_error = 1;} 
                        (yyval.intval) = cast_type((yyval.intval), (yyvsp[0].intval), getType((yyvsp[-2].typeval)));
                        if((yyval.intval) == -1){flag_error = 1;}
                    }
#line 1814 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 371 "yacc/compil.y" /* yacc.c:1646  */
    {   if(isConstante((yyvsp[-2].identval)) == 1){flag_error = 1;}
                                    (yyval.intval) = lookup((yyvsp[-2].identval), 0); 
                                    if((yyval.intval) == -1){flag_error = 1;}
                                    type_macro_assign = lookup((yyvsp[0].name_defineval), 0); 
                                    if(type_macro_assign == -1){flag_error = 1;}
                                    check_types((yyval.intval), type_macro_assign);
                                }
#line 1826 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 378 "yacc/compil.y" /* yacc.c:1646  */
    {(yyval.intval) = (yyvsp[0].intval);}
#line 1832 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 382 "yacc/compil.y" /* yacc.c:1646  */
    {(yyval.intval) = INTEGER;}
#line 1838 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 383 "yacc/compil.y" /* yacc.c:1646  */
    {(yyval.intval) = (yyvsp[0].intval);}
#line 1844 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 385 "yacc/compil.y" /* yacc.c:1646  */
    {(yyval.intval) = INTEGER;}
#line 1850 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 386 "yacc/compil.y" /* yacc.c:1646  */
    {(yyval.intval) = (yyvsp[0].intval);}
#line 1856 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 389 "yacc/compil.y" /* yacc.c:1646  */
    {(yyval.intval) = INTEGER;}
#line 1862 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 390 "yacc/compil.y" /* yacc.c:1646  */
    {(yyval.intval) = (yyvsp[0].intval);}
#line 1868 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 392 "yacc/compil.y" /* yacc.c:1646  */
    {(yyval.intval) = INTEGER;}
#line 1874 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 393 "yacc/compil.y" /* yacc.c:1646  */
    {(yyval.intval) = (yyvsp[0].intval);}
#line 1880 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 395 "yacc/compil.y" /* yacc.c:1646  */
    {
                        (yyval.intval) = max_type((yyvsp[-2].intval), (yyvsp[0].intval));
                        switch ((yyvsp[-1].addsubval)) {
                            case '+': fprintf(stdout, "    pop rcx\n    pop rax\n    add rax, rcx\n    push rax\n"); break;
                            case '-': fprintf(stdout, "    pop rcx\n    pop rax\n    sub rax, rcx\n    push rax\n"); break;
                        }
                    }
#line 1892 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 402 "yacc/compil.y" /* yacc.c:1646  */
    {(yyval.intval) = (yyvsp[0].intval);}
#line 1898 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 404 "yacc/compil.y" /* yacc.c:1646  */
    {
                        (yyval.intval) = max_type((yyvsp[-2].intval), (yyvsp[0].intval));
                        fprintf(stdout, "    pop rcx\n    pop rax\n");
                        switch ((yyvsp[-1].divstarval)) {
                            case '*': fprintf(stdout, "    imul rcx\n    push rax\n"); break;
                            case '/': fprintf(stdout, "    mov rdx,0\n    idiv rcx\n    push rax\n"); break;
                            case '%': fprintf(stdout, "    mov rdx,0\n    idiv rcx\n    push rdx\n"); break;
                        }
                    }
#line 1912 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 413 "yacc/compil.y" /* yacc.c:1646  */
    {(yyval.intval) = (yyvsp[0].intval);}
#line 1918 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 416 "yacc/compil.y" /* yacc.c:1646  */
    {(yyval.intval) = (yyvsp[0].intval);}
#line 1924 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 417 "yacc/compil.y" /* yacc.c:1646  */
    {(yyval.intval) = INTEGER;}
#line 1930 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 418 "yacc/compil.y" /* yacc.c:1646  */
    {(yyval.intval) = (yyvsp[-1].intval);}
#line 1936 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 419 "yacc/compil.y" /* yacc.c:1646  */
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
                        default: fprintf(stderr, "Impossible\n"); break;
                    }

    			}
#line 1957 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 435 "yacc/compil.y" /* yacc.c:1646  */
    {if(((yyval.intval) = lookup((yyvsp[0].name_defineval), 0)) == -1){flag_error = 1;}}
#line 1963 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 436 "yacc/compil.y" /* yacc.c:1646  */
    {(yyval.intval) = INTEGER; fprintf(stdout, "    push QWORD %d\n", (yyvsp[0].intval));}
#line 1969 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 437 "yacc/compil.y" /* yacc.c:1646  */
    {(yyval.intval) = REAL;}
#line 1975 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 438 "yacc/compil.y" /* yacc.c:1646  */
    {(yyval.intval) = CHAR; fprintf(stdout, "    push QWORD %d\n", (yyvsp[0].charval));}
#line 1981 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 439 "yacc/compil.y" /* yacc.c:1646  */
    {
                                    if(((yyval.intval) = lookupFunction((yyvsp[-3].identval))) == -1)
                                        flag_error = 1;
                                    //add_call_cell($1);
                                    //i_args = get_func_i_arg();
                                    //get_func_call_name(name_called_function);
                                }
#line 1993 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 450 "yacc/compil.y" /* yacc.c:1646  */
    {strcpy((yyval.identval), (yyvsp[-1].identval));}
#line 1999 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 125:
#line 465 "yacc/compil.y" /* yacc.c:1646  */
    {
                            //if (!check_types(get_arg_type(name_called_function, *i_args), $3))
                            //    fprintf(stderr, "%d argument type does not match the expected type\n", (*i_args)++);
                        }
#line 2008 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 126:
#line 469 "yacc/compil.y" /* yacc.c:1646  */
    {
                    //if (!check_types(get_arg_type(name_called_function, *i_args), $1))
                     //   fprintf(stderr, "%d argument type does not match the expected type\n", (*i_args)++);
                }
#line 2017 "bin/compil.tab.c" /* yacc.c:1646  */
    break;


#line 2021 "bin/compil.tab.c" /* yacc.c:1646  */
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
#line 476 "yacc/compil.y" /* yacc.c:1906  */

void yyerror(char *s){
    printf("Erreur %s near line %d \n", s, line_num);
    flag_error = 1;
}
 
int main(){
	initProg();
    yyparse();
    /*printf("Res = %d\n", flag_error);
    displayTable();
    displayConst();
    displayMacro();
    displayFunTable();*/
    return flag_error;
}
