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
int type_define = -1;
int type_macro_assign = -1;
int parameters = 0;
int *args = NULL;
char name_function[MAXNAME];
char name_called_function[MAXNAME];

#line 89 "bin/compil.tab.c" /* yacc.c:339  */

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
#line 24 "yacc/compil.y" /* yacc.c:355  */

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

#line 191 "bin/compil.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_BIN_COMPIL_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 208 "bin/compil.tab.c" /* yacc.c:358  */

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
#define YYNNTS  40
/* YYNRULES -- Number of rules.  */
#define YYNRULES  129
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  297

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
       0,    94,    94,    98,    99,   103,   106,   107,   108,   109,
     113,   114,   116,   120,   121,   122,   123,   127,   132,   138,
     143,   151,   152,   156,   157,   161,   162,   166,   167,   168,
     169,   170,   174,   175,   176,   180,   185,   186,   190,   191,
     192,   196,   200,   201,   207,   208,   214,   220,   221,   222,
     223,   227,   228,   232,   233,   238,   237,   257,   256,   275,
     276,   277,   278,   282,   283,   284,   288,   292,   296,   297,
     298,   301,   310,   311,   314,   318,   319,   330,   340,   356,
     372,   379,   380,   381,   382,   383,   384,   385,   386,   387,
     388,   389,   390,   391,   392,   395,   402,   409,   416,   420,
     421,   423,   424,   427,   428,   430,   431,   433,   441,   443,
     452,   455,   456,   457,   458,   474,   475,   476,   477,   478,
     485,   489,   493,   494,   495,   499,   500,   504,   508,   512
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
  "DeclFonct", "EnTeteFonct", "$@1", "$@2", "Parametres", "ListTypVar",
  "Corps", "SuiteInstr", "Instr", "Exp", "EB", "TB", "FB", "M", "E", "T",
  "F", "LValue", "Tableau", "Arguments", "ListExp", YY_NULLPTR
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

#define YYPACT_NINF -230

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-230)))

#define YYTABLE_NINF -127

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -230,    35,    50,  -230,    14,   402,  -230,    55,     9,   199,
     189,   189,    83,    95,    95,   225,  -230,  -230,  -230,  -230,
      90,  -230,  -230,  -230,  -230,    76,   186,    81,   241,   245,
     120,    19,  -230,    89,  -230,   160,   131,  -230,  -230,  -230,
     106,   222,   118,   235,   -10,   240,    91,   243,  -230,   130,
     152,   274,  -230,  -230,  -230,  -230,  -230,    10,  -230,  -230,
    -230,   140,    84,   146,    93,   146,  -230,    93,   188,    96,
     279,  -230,  -230,   279,  -230,   145,   170,   184,   194,   132,
    -230,   160,   161,   207,   149,   244,   283,  -230,   234,   125,
     251,  -230,  -230,    11,  -230,  -230,   255,    93,   -22,  -230,
    -230,  -230,  -230,  -230,   256,    93,   172,  -230,  -230,  -230,
    -230,   218,   258,  -230,  -230,  -230,  -230,   254,   294,  -230,
    -230,  -230,  -230,   288,  -230,   290,   296,   279,   212,  -230,
    -230,   303,   320,  -230,  -230,   106,   287,   275,  -230,  -230,
     373,   289,   291,   297,     3,   300,   302,    40,  -230,   308,
    -230,  -230,   373,  -230,  -230,   373,  -230,   318,   322,   309,
     333,   338,   354,   343,  -230,   330,  -230,  -230,    64,   379,
      64,  -230,  -230,  -230,   310,   313,   373,   373,   373,   373,
     314,  -230,   334,  -230,   336,   252,  -230,  -230,   373,   373,
     373,   373,   373,   373,   389,  -230,   339,   159,   126,   337,
     352,   356,   359,   362,   364,   366,   368,    63,   369,   370,
      15,  -230,   292,  -230,  -230,   309,   333,   338,   354,   343,
    -230,    75,   349,  -230,  -230,   373,   373,   331,   331,  -230,
     381,   384,   388,   391,   395,   332,   332,   332,   332,   408,
     427,   229,   417,   374,  -230,  -230,  -230,  -230,  -230,  -230,
    -230,  -230,  -230,  -230,  -230,   420,  -230,   400,   403,   404,
     405,   398,   373,   332,   373,   373,   373,   373,   373,  -230,
    -230,   406,   407,   409,   410,   412,   373,   373,   373,   419,
     413,   415,   418,   421,    49,   422,  -230,   332,   332,   332,
     332,   332,  -230,  -230,  -230,  -230,  -230
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
      24,     0,     0,     0,     0,     0,     0,    63,     0,     0,
       0,    42,    46,     0,    44,    41,     0,     0,    35,    32,
      33,    39,    34,    38,     0,     0,     0,    17,    18,    48,
      47,     0,     0,    69,    70,    67,    61,     0,     0,    62,
      43,    45,    59,     0,    60,     0,     0,     0,     0,    50,
      49,     0,     0,    56,    58,    35,     0,   124,   116,   118,
       0,     0,     0,     0,     0,     0,     0,     0,   117,     0,
     115,    75,     0,    73,    71,     0,    72,     0,    98,   100,
     102,   104,   106,   108,   110,   114,    68,    66,     0,     0,
       0,   121,   111,   114,     0,     0,     0,     0,     0,     0,
       0,    77,     0,    73,     0,     0,   112,    74,     0,     0,
       0,     0,     0,     0,     0,   128,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    76,     0,   113,    86,    99,   101,   103,   105,   107,
     109,   115,     0,    95,   120,     0,     0,   124,   124,   119,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   129,   127,   123,   122,    93,    78,
      94,    79,    80,    87,    88,    81,    83,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    96,
      82,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    85,     0,     0,     0,
       0,     0,    89,    92,    90,    91,    84
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -230,  -230,  -230,  -230,   191,  -230,   396,   437,   360,  -230,
     -24,   376,   385,   -28,   382,   387,  -230,   197,  -230,   426,
    -230,  -230,  -230,   -34,  -230,  -230,   -70,  -229,  -147,  -230,
     273,   276,   272,   277,   271,  -137,  -138,     8,   299,  -230
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,     5,    18,    23,     9,    26,    58,    59,
      24,    15,    45,    42,    47,    48,    95,    65,    31,    32,
      33,    97,   105,    88,    89,    54,   128,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   171,   196,   197
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     182,    46,   173,   172,   177,   184,   253,   254,   255,   256,
      11,    60,    68,    62,    80,   120,   240,   173,   186,    -2,
      50,   195,   199,   195,    68,    62,    51,    69,    30,   205,
     206,   207,   208,    90,   270,     3,    34,   121,    12,     6,
     178,   136,    99,   137,   138,   102,   139,   223,   140,   241,
     173,   173,   173,   173,   173,   173,   220,   108,   292,   293,
     294,   295,   296,   123,   236,   136,   148,   137,   138,   150,
     139,   125,   140,   181,     4,   184,   -97,   152,   244,   245,
     155,   290,    38,   185,    10,    82,   168,    16,    83,    17,
     148,    20,    72,   150,    85,   237,  -126,    96,    25,    46,
      86,   152,    87,   -55,   155,   -55,   -97,   -97,   -97,    21,
      35,   -97,    36,   212,    39,   269,    34,   271,   272,   273,
     274,   275,   -34,    49,   -34,   -65,   117,    53,   -55,   281,
     282,   283,   285,    13,    61,   -31,   -31,    14,   -31,   -31,
     -31,    62,   -31,   -31,   -31,   -31,   104,   -31,   -31,   -31,
     111,    66,   -57,   112,   -57,    76,   118,   -64,   -31,   -31,
     225,   -31,   227,   168,    55,   -31,    56,    75,    57,   -31,
     -31,   -31,   -31,   126,    81,   -73,   -73,   -57,   -73,   127,
     -73,    84,   -73,   -73,   -73,   -73,    21,   -73,   -73,   -73,
     226,  -125,    91,    16,    92,    17,    93,   109,   -73,   -73,
      13,   -73,    19,    22,    14,   -73,   -31,    64,   -31,   -73,
     -73,   -73,   -73,   136,    94,   137,   138,    36,   139,    37,
     140,    67,   141,   142,   143,   144,    28,   145,   146,   147,
     259,    69,    29,   260,    30,   246,   247,    63,   148,   149,
      63,   150,    40,   110,    41,   151,    43,   113,    44,   152,
     153,   154,   155,   136,   129,   137,   138,    62,   139,    64,
     140,   131,   141,   142,   143,   144,   116,   145,   146,   147,
      62,    70,    67,    71,    73,    77,    74,    78,   148,   149,
      40,   150,    98,   119,   114,   151,   115,   122,   124,   152,
     153,   214,   155,   136,   130,   137,   138,    40,   139,   135,
     140,   132,   141,   142,   143,   144,   166,   145,   146,   147,
     169,   201,   170,   202,   203,   209,   204,   210,   148,   149,
     133,   150,   134,   167,   168,   151,   174,   189,   175,   152,
     153,   242,   155,   136,   176,   137,   138,   179,   139,   180,
     140,   188,   141,   142,   143,   144,   183,   145,   146,   147,
     136,   187,   137,   138,   190,   139,   243,   140,   148,   149,
     191,   150,   192,   193,   194,   151,   169,   211,   213,   152,
     153,   224,   155,   228,   136,   148,   137,   138,   150,   139,
     198,   140,   137,   138,   229,   139,   152,   140,   230,   155,
     136,   231,   137,   138,   232,   139,   233,   140,   234,   148,
     235,   238,   150,     7,   239,   148,   262,   -16,   150,   -16,
     152,   -16,   257,   155,   248,   148,   152,   249,   221,   155,
     284,   250,   137,   138,   251,   139,   222,   140,   252,   155,
       8,   258,   261,   264,   263,   268,   265,   266,   267,   276,
     277,   107,   278,   279,   280,   148,   286,   287,   150,    79,
     288,    27,   100,   289,   291,   106,   152,    52,   101,   155,
     103,   215,   217,   219,     0,   216,     0,     0,   218,   200
};

static const yytype_int16 yycheck[] =
{
     147,    29,   140,   140,     1,   152,   235,   236,   237,   238,
       1,    35,    34,    35,     4,     4,     1,   155,   155,     0,
       1,   168,   169,   170,    34,    35,     7,    37,     9,   176,
     177,   178,   179,    67,   263,     0,    26,    26,    29,    25,
      37,     1,    70,     3,     4,    73,     6,   194,     8,    34,
     188,   189,   190,   191,   192,   193,   193,    81,   287,   288,
     289,   290,   291,    97,     1,     1,    26,     3,     4,    29,
       6,   105,     8,    33,    24,   222,     1,    37,   225,   226,
      40,    32,     1,   153,    29,     1,    37,     4,     4,     6,
      26,     8,     1,    29,     1,    32,    32,     1,     3,   127,
       7,    37,     9,     7,    40,     9,    31,    32,    33,    26,
      34,    36,    31,   183,    33,   262,    26,   264,   265,   266,
     267,   268,    31,     3,    33,    32,     1,    38,    32,   276,
     277,   278,   279,     1,     3,     3,     4,     5,     6,     7,
       8,    35,    10,    11,    12,    13,     1,    15,    16,    17,
       1,    33,     7,     4,     9,     3,    31,    32,    26,    27,
       1,    29,    36,    37,     4,    33,     6,    37,     8,    37,
      38,    39,    40,     1,    34,     3,     4,    32,     6,     7,
       8,    35,    10,    11,    12,    13,    26,    15,    16,    17,
      31,    32,     4,     4,     6,     6,     8,    36,    26,    27,
       1,    29,    11,    12,     5,    33,     7,    37,     9,    37,
      38,    39,    40,     1,    26,     3,     4,    31,     6,    33,
       8,    37,    10,    11,    12,    13,     1,    15,    16,    17,
       1,    37,     7,     4,     9,   227,   228,    40,    26,    27,
      43,    29,     1,    36,     3,    33,     1,     3,     3,    37,
      38,    39,    40,     1,    36,     3,     4,    35,     6,    37,
       8,     7,    10,    11,    12,    13,    32,    15,    16,    17,
      35,    31,    37,    33,    31,     1,    33,     3,    26,    27,
       1,    29,     3,    32,     1,    33,     3,    32,    32,    37,
      38,    39,    40,     1,    36,     3,     4,     1,     6,     3,
       8,     7,    10,    11,    12,    13,     3,    15,    16,    17,
      35,     1,    37,     3,     1,     1,     3,     3,    26,    27,
      32,    29,    32,     3,    37,    33,    37,    18,    37,    37,
      38,    39,    40,     1,    37,     3,     4,    37,     6,    37,
       8,    19,    10,    11,    12,    13,    38,    15,    16,    17,
       1,    33,     3,     4,    21,     6,     7,     8,    26,    27,
      22,    29,     8,    20,    34,    33,    35,    33,    32,    37,
      38,    32,    40,    36,     1,    26,     3,     4,    29,     6,
       1,     8,     3,     4,    32,     6,    37,     8,    32,    40,
       1,    32,     3,     4,    32,     6,    32,     8,    32,    26,
      32,    32,    29,     1,    34,    26,    32,     5,    29,     7,
      37,     9,     4,    40,    33,    26,    37,    33,    29,    40,
       1,    33,     3,     4,    33,     6,    37,     8,    33,    40,
      28,     4,    15,    33,    14,    37,    33,    33,    33,    33,
      33,    81,    33,    33,    32,    26,    33,    32,    29,    53,
      32,    14,    70,    32,    32,    79,    37,    31,    73,    40,
      73,   188,   190,   192,    -1,   189,    -1,    -1,   191,   170
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
       1,     7,    60,    38,    66,     4,     6,     8,    49,    50,
      51,     3,    35,    58,    37,    58,    33,    37,    34,    37,
      31,    33,     1,    31,    33,    37,     3,     1,     3,    47,
       4,    34,     1,     4,    35,     1,     7,     9,    64,    65,
      64,     4,     6,     8,    26,    57,     1,    62,     3,    54,
      55,    53,    54,    56,     1,    63,    52,    49,    51,    36,
      36,     1,     4,     3,     1,     3,    32,     1,    31,    32,
       4,    26,    32,    64,    32,    64,     1,     7,    67,    36,
      36,     7,     7,    32,    32,     3,     1,     3,     4,     6,
       8,    10,    11,    12,    13,    15,    16,    17,    26,    27,
      29,    33,    37,    38,    39,    40,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,     3,     3,    37,    35,
      37,    78,    76,    77,    37,    37,    37,     1,    37,    37,
      37,    33,    69,    38,    69,    67,    76,    33,    19,    18,
      21,    22,     8,    20,    34,    69,    79,    80,     1,    69,
      79,     1,     3,     1,     3,    69,    69,    69,    69,     1,
       3,    33,    67,    32,    39,    71,    72,    73,    74,    75,
      76,    29,    37,    69,    32,     1,    31,    36,    36,    32,
      32,    32,    32,    32,    32,    32,     1,    32,    32,    34,
       1,    34,    39,     7,    69,    69,    78,    78,    33,    33,
      33,    33,    33,    68,    68,    68,    68,     4,     4,     1,
       4,    15,    32,    14,    33,    33,    33,    33,    37,    69,
      68,    69,    69,    69,    69,    69,    33,    33,    33,    33,
      32,    69,    69,    69,     1,    69,    33,    32,    32,    32,
      32,    32,    68,    68,    68,    68,    68
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    41,    42,    43,    43,    44,    44,    44,    44,    44,
      45,    45,    46,    47,    47,    47,    47,    48,    48,    48,
      48,    49,    49,    50,    50,    51,    51,    52,    52,    52,
      52,    52,    53,    53,    53,    54,    54,    54,    55,    55,
      55,    56,    57,    57,    57,    57,    57,    58,    58,    58,
      58,    59,    59,    60,    60,    62,    61,    63,    61,    61,
      61,    61,    61,    64,    64,    64,    65,    65,    65,    65,
      65,    66,    67,    67,    68,    68,    68,    68,    68,    68,
      68,    68,    68,    68,    68,    68,    68,    68,    68,    68,
      68,    68,    68,    68,    68,    69,    69,    69,    69,    70,
      70,    71,    71,    72,    72,    73,    73,    74,    74,    75,
      75,    76,    76,    76,    76,    76,    76,    76,    76,    76,
      76,    77,    78,    78,    78,    79,    79,    80,    80,    80
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     5,     3,     0,     4,     4,     4,     4,     0,
       1,     1,     1,     4,     4,     4,     0,     5,     5,     3,
       3,     1,     1,     1,     2,     1,     2,     4,     4,     4,
       4,     0,     3,     3,     1,     1,     2,     2,     3,     3,
       1,     3,     1,     2,     1,     2,     1,     3,     3,     4,
       4,     2,     1,     2,     1,     0,     6,     0,     6,     5,
       5,     5,     5,     1,     1,     0,     4,     2,     4,     2,
       2,     5,     2,     0,     2,     1,     3,     2,     5,     5,
       5,     5,     7,     5,    11,     9,     3,     5,     5,    11,
      11,    11,    11,     5,     5,     3,     6,     3,     1,     3,
       1,     3,     1,     3,     1,     3,     1,     3,     1,     3,
       1,     2,     2,     3,     1,     1,     1,     1,     1,     4,
       4,     2,     4,     4,     0,     1,     0,     3,     1,     3
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
#line 94 "yacc/compil.y" /* yacc.c:1646  */
    {print_end();}
#line 1511 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 103 "yacc/compil.y" /* yacc.c:1646  */
    {
                                                            addMacro((yyvsp[-1].name_defineval), type_define, (yyvsp[0].intval), .0);
                                                        }
#line 1519 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 106 "yacc/compil.y" /* yacc.c:1646  */
    {addMacro((yyvsp[-1].name_defineval), type_define, 0, (yyvsp[0].reelval));}
#line 1525 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 113 "yacc/compil.y" /* yacc.c:1646  */
    {type_define = INTEGER; (yyval.intval) = (yyvsp[0].intval);}
#line 1531 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 114 "yacc/compil.y" /* yacc.c:1646  */
    {type_define = CHAR; (yyval.intval) = (yyvsp[0].charval);}
#line 1537 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 116 "yacc/compil.y" /* yacc.c:1646  */
    {type_define = REAL; (yyval.reelval) = (yyvsp[0].reelval);}
#line 1543 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 127 "yacc/compil.y" /* yacc.c:1646  */
    {
       										if(addConst((yyvsp[-2].identval), type_const, (yyvsp[0].intval), .0) == 0){
       											flag_error = 1;
       										}
       									}
#line 1553 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 132 "yacc/compil.y" /* yacc.c:1646  */
    {
                                            type_const = REAL;
                                            if(addConst((yyvsp[-2].identval), type_const, 0, (yyvsp[0].reelval)) == 0){
                                                flag_error = 1;
                                            }
                                        }
#line 1564 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 138 "yacc/compil.y" /* yacc.c:1646  */
    {
                                            if(addConst((yyvsp[-2].identval), type_const, (yyvsp[0].intval), .0) == 0){
                                                flag_error = 1;
                                            }
                                        }
#line 1574 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 143 "yacc/compil.y" /* yacc.c:1646  */
    {   type_const = REAL;
                                            if(addConst((yyvsp[-2].identval), type_const, 0, (yyvsp[0].reelval)) == 0){
                                                flag_error = 1;
                                            }
                                        }
#line 1584 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 151 "yacc/compil.y" /* yacc.c:1646  */
    {type_const = INTEGER;}
#line 1590 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 152 "yacc/compil.y" /* yacc.c:1646  */
    {type_const = CHAR;}
#line 1596 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 156 "yacc/compil.y" /* yacc.c:1646  */
    {(yyval.intval) = (yyvsp[0].intval);}
#line 1602 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 157 "yacc/compil.y" /* yacc.c:1646  */
    {if((yyvsp[-1].addsubval) == '-'){(yyval.intval) = -((yyvsp[0].intval));}}
#line 1608 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 161 "yacc/compil.y" /* yacc.c:1646  */
    {(yyval.reelval) = (yyvsp[0].reelval);}
#line 1614 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 162 "yacc/compil.y" /* yacc.c:1646  */
    {if((yyvsp[-1].addsubval) == '-') (yyval.reelval) = -((yyvsp[0].reelval));}
#line 1620 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 180 "yacc/compil.y" /* yacc.c:1646  */
    {
					if(addVar((yyvsp[0].identval), type_var, 0, 0, .0) == 0){
						flag_error = 1;
					}
				}
#line 1630 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 200 "yacc/compil.y" /* yacc.c:1646  */
    {addVar((yyvsp[(-1) - (1)].identval), type_var, 0, (yyvsp[0].intval), .0);}
#line 1636 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 201 "yacc/compil.y" /* yacc.c:1646  */
    {
					if((yyvsp[-1].addsubval) == '-'){
						(yyval.intval) = -((yyvsp[0].intval));
					}
					addVar((yyvsp[(-1) - (2)].identval), type_var, 0, (yyval.intval), .0);
				  }
#line 1647 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 207 "yacc/compil.y" /* yacc.c:1646  */
    {addVar((yyvsp[(-1) - (1)].identval), type_var, 0, 0, (yyvsp[0].reelval));}
#line 1653 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 208 "yacc/compil.y" /* yacc.c:1646  */
    {
                    if((yyvsp[-1].addsubval) == '-'){
                        (yyval.intval) = -((yyvsp[0].reelval));
                    }
                    addVar((yyvsp[(-1) - (2)].identval), type_var, 0, 0, (yyval.intval));
                  }
#line 1664 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 214 "yacc/compil.y" /* yacc.c:1646  */
    {
					addVar((yyvsp[(-1) - (1)].identval), type_var, 0, (yyvsp[0].charval), .0);
				  }
#line 1672 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 238 "yacc/compil.y" /* yacc.c:1646  */
    {   
                        strcpy(name_function, (yyvsp[-1].identval));
                        flag_return = 0;
                        addFun((yyvsp[-1].identval), getType((yyvsp[-2].typeval)));
                        if (flag_start) {
                            print_start(get_globals_size());
                            flag_start = 0;
                        }
                        fprintf(stdout, "%s:\n    push rbp\n    mov rbp, rsp\n", (yyvsp[-1].identval));
                        createStack();
                        parameters = 0;
                    }
#line 1689 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 251 "yacc/compil.y" /* yacc.c:1646  */
    {
                        int i;
                        for (i = parameters; i > 0; i--)
                            fprintf(stdout, "    push QWORD [rbp+%d]\n", (i+1) * 8);
                    }
#line 1699 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 257 "yacc/compil.y" /* yacc.c:1646  */
    {   
                        strcpy(name_function, (yyvsp[-1].identval));
                        addFun((yyvsp[-1].identval), VOIDTYPE);
                        if (flag_start) {
                            print_start(get_globals_size()); 
                            flag_start = 0;
                        }
                        fprintf(stdout, "%s:\n    push rbp\n    mov rbp, rsp\n", (yyvsp[-1].identval));
                        createStack();
                        parameters = 0;
                    }
#line 1715 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 270 "yacc/compil.y" /* yacc.c:1646  */
    {
                        int i;
                        for (i = parameters; i > 0; i--)
                            fprintf(stdout, "    push QWORD [rbp+%d]\n", (i+1) * 8);
                    }
#line 1725 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 288 "yacc/compil.y" /* yacc.c:1646  */
    {  addVar((yyvsp[0].identval), type_var, 1, 0, .0); 
                                    parameters++; 
                                    addArg(name_function, type_var);
                                 }
#line 1734 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 292 "yacc/compil.y" /* yacc.c:1646  */
    {  addVar((yyvsp[0].identval), type_var, 1, 0, .0); 
                                    parameters++; 
                                    addArg(name_function, type_var);
                                 }
#line 1743 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 301 "yacc/compil.y" /* yacc.c:1646  */
    {                
                                                    if (lookupFunction(name_function) != VOIDTYPE && flag_return == 0)
                                                        yyerror("Function is non-void and should return a value");
                                                    fprintf(stdout, "fin_%s:\n", name_function); 
                                                    remove_st_cell();
                                                }
#line 1754 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 314 "yacc/compil.y" /* yacc.c:1646  */
    {                
                        if ((yyvsp[-1].intval) != VOIDTYPE) 
                            fprintf(stdout, "    pop rcx\n");
                    }
#line 1763 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 319 "yacc/compil.y" /* yacc.c:1646  */
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
#line 1779 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 330 "yacc/compil.y" /* yacc.c:1646  */
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
#line 1794 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 341 "yacc/compil.y" /* yacc.c:1646  */
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
#line 1814 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 357 "yacc/compil.y" /* yacc.c:1646  */
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
#line 1834 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 372 "yacc/compil.y" /* yacc.c:1646  */
    {
                                        switch ((yyvsp[-2].intval)) {
                                            case INTEGER: fprintf(stdout, "    pop rsi\n    call _print_ent\n"); break;
                                            case CHAR: fprintf(stdout, "    pop rsi\n    call _print_car\n"); break;
                                            case VOIDTYPE: yyerror("Can't print void value"); break;
                                        }
                                    }
#line 1846 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 395 "yacc/compil.y" /* yacc.c:1646  */
    {
                        if(isConstante((yyvsp[-2].identval)) == 1){flag_error = 1;}
                        (yyval.intval) = lookup((yyvsp[-2].identval), 0); 
                        if((yyval.intval) == -1){flag_error = 1;} 
                        (yyval.intval) = cast_type((yyval.intval), (yyvsp[0].intval), 0);
                        if((yyval.intval) == -1){flag_error = 1;}
                    }
#line 1858 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 402 "yacc/compil.y" /* yacc.c:1646  */
    {
                        if(isConstante((yyvsp[-5].identval)) == 1){flag_error = 1;}
                        (yyval.intval) = lookup((yyvsp[-5].identval), 0); 
                        if((yyval.intval) == -1){flag_error = 1;} 
                        (yyval.intval) = cast_type((yyval.intval), (yyvsp[0].intval), getType((yyvsp[-2].typeval)));
                        if((yyval.intval) == -1){flag_error = 1;}
                    }
#line 1870 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 409 "yacc/compil.y" /* yacc.c:1646  */
    {   if(isConstante((yyvsp[-2].identval)) == 1){flag_error = 1;}
                                    (yyval.intval) = lookup((yyvsp[-2].identval), 0); 
                                    if((yyval.intval) == -1){flag_error = 1;}
                                    type_macro_assign = lookup((yyvsp[0].name_defineval), 0); 
                                    if(type_macro_assign == -1){flag_error = 1;}
                                    check_types((yyval.intval), type_macro_assign);
                                }
#line 1882 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 416 "yacc/compil.y" /* yacc.c:1646  */
    {(yyval.intval) = (yyvsp[0].intval);}
#line 1888 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 420 "yacc/compil.y" /* yacc.c:1646  */
    {(yyval.intval) = INTEGER;}
#line 1894 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 421 "yacc/compil.y" /* yacc.c:1646  */
    {(yyval.intval) = (yyvsp[0].intval);}
#line 1900 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 423 "yacc/compil.y" /* yacc.c:1646  */
    {(yyval.intval) = INTEGER;}
#line 1906 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 424 "yacc/compil.y" /* yacc.c:1646  */
    {(yyval.intval) = (yyvsp[0].intval);}
#line 1912 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 427 "yacc/compil.y" /* yacc.c:1646  */
    {(yyval.intval) = INTEGER;}
#line 1918 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 428 "yacc/compil.y" /* yacc.c:1646  */
    {(yyval.intval) = (yyvsp[0].intval);}
#line 1924 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 430 "yacc/compil.y" /* yacc.c:1646  */
    {(yyval.intval) = INTEGER;}
#line 1930 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 431 "yacc/compil.y" /* yacc.c:1646  */
    {(yyval.intval) = (yyvsp[0].intval);}
#line 1936 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 433 "yacc/compil.y" /* yacc.c:1646  */
    {
                        (yyval.intval) = max_type((yyvsp[-2].intval), (yyvsp[0].intval));
                        switch ((yyvsp[-1].addsubval)) {
                            case '+': fprintf(stdout, "    pop rcx\n    pop rax\n    add rax, rcx\n    push rax\n"); break;
                            case '-': fprintf(stdout, "    pop rcx\n    pop rax\n    sub rax, rcx\n    push rax\n"); break;
                        }
                        
                    }
#line 1949 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 441 "yacc/compil.y" /* yacc.c:1646  */
    {(yyval.intval) = (yyvsp[0].intval);}
#line 1955 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 443 "yacc/compil.y" /* yacc.c:1646  */
    {
                        (yyval.intval) = max_type((yyvsp[-2].intval), (yyvsp[0].intval));
                        fprintf(stdout, "    pop rcx\n    pop rax\n");
                        switch ((yyvsp[-1].divstarval)) {
                            case '*': fprintf(stdout, "    imul rcx\n    push rax\n"); break;
                            case '/': fprintf(stdout, "    mov rdx,0\n    idiv rcx\n    push rax\n"); break;
                            case '%': fprintf(stdout, "    mov rdx,0\n    idiv rcx\n    push rdx\n"); break;
                        }
                    }
#line 1969 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 452 "yacc/compil.y" /* yacc.c:1646  */
    {(yyval.intval) = (yyvsp[0].intval);}
#line 1975 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 455 "yacc/compil.y" /* yacc.c:1646  */
    {(yyval.intval) = (yyvsp[0].intval);}
#line 1981 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 456 "yacc/compil.y" /* yacc.c:1646  */
    {(yyval.intval) = INTEGER;}
#line 1987 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 457 "yacc/compil.y" /* yacc.c:1646  */
    {(yyval.intval) = (yyvsp[-1].intval);}
#line 1993 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 458 "yacc/compil.y" /* yacc.c:1646  */
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
#line 2014 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 474 "yacc/compil.y" /* yacc.c:1646  */
    {if(((yyval.intval) = lookup((yyvsp[0].name_defineval), 0)) == -1){flag_error = 1;}}
#line 2020 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 475 "yacc/compil.y" /* yacc.c:1646  */
    {(yyval.intval) = INTEGER; fprintf(stdout, "    push QWORD %d\n", (yyvsp[0].intval));}
#line 2026 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 476 "yacc/compil.y" /* yacc.c:1646  */
    {(yyval.intval) = REAL;}
#line 2032 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 477 "yacc/compil.y" /* yacc.c:1646  */
    {(yyval.intval) = CHAR; fprintf(stdout, "    push QWORD %d\n", (yyvsp[0].charval));}
#line 2038 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 478 "yacc/compil.y" /* yacc.c:1646  */
    {
                                    if(((yyval.intval) = lookupFunction((yyvsp[-3].identval))) == -1)
                                        flag_error = 1;
                                    add_call_cell((yyvsp[-3].identval));
                                    args = get_func_i_arg();
                                    get_func_call_name(name_called_function);
                                }
#line 2050 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 489 "yacc/compil.y" /* yacc.c:1646  */
    {strcpy((yyval.identval), (yyvsp[-1].identval));}
#line 2056 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 127:
#line 504 "yacc/compil.y" /* yacc.c:1646  */
    {
                            //if (!check_types(get_arg_type(name_called_function, *i_args), $3))
                            //    fprintf(stderr, "%d argument type does not match the expected type\n", (*i_args)++);
                        }
#line 2065 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 128:
#line 508 "yacc/compil.y" /* yacc.c:1646  */
    {
                    //if (!check_types(get_arg_type(name_called_function, *i_args), $1))
                     //   fprintf(stderr, "%d argument type does not match the expected type\n", (*i_args)++);
                }
#line 2074 "bin/compil.tab.c" /* yacc.c:1646  */
    break;


#line 2078 "bin/compil.tab.c" /* yacc.c:1646  */
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
#line 515 "yacc/compil.y" /* yacc.c:1906  */


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
