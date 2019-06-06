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
int jump_label = 0;
int parameters = 0;
int size_array = 0;
int is_global_variable = 1;
int *args = NULL;
char name_function[MAXNAME];
char name_called_function[MAXNAME];

#line 91 "bin/compil.tab.c" /* yacc.c:339  */

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
#line 26 "yacc/compil.y" /* yacc.c:355  */

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

#line 193 "bin/compil.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_BIN_COMPIL_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 210 "bin/compil.tab.c" /* yacc.c:358  */

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
#define YYLAST   495

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  41
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  48
/* YYNRULES -- Number of rules.  */
#define YYNRULES  136
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  307

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
       0,    96,    96,   100,   101,   105,   108,   109,   110,   111,
     115,   116,   118,   122,   123,   124,   125,   129,   134,   140,
     145,   153,   154,   158,   159,   163,   164,   168,   169,   170,
     171,   172,   176,   177,   178,   182,   188,   189,   193,   194,
     195,   199,   203,   208,   216,   224,   225,   226,   227,   231,
     232,   236,   237,   242,   241,   265,   264,   287,   288,   289,
     290,   294,   295,   296,   299,   303,   307,   308,   309,   312,
     321,   322,   325,   329,   330,   341,   351,   367,   383,   391,
     396,   398,   400,   397,   403,   404,   405,   406,   407,   408,
     409,   410,   411,   412,   413,   417,   420,   423,   426,   446,
     461,   468,   473,   472,   485,   487,   487,   499,   502,   516,
     518,   545,   547,   555,   557,   566,   569,   577,   585,   586,
     606,   621,   622,   623,   624,   626,   625,   649,   653,   657,
     658,   659,   663,   664,   668,   674,   679
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
  "Corps", "SuiteInstr", "Instr", "@3", "$@4", "TradIF", "FinTradIF",
  "FinELSE", "Exp", "EB", "@5", "TB", "@6", "FB", "M", "E", "T", "F",
  "$@7", "LValue", "Tableau", "Arguments", "ListExp", YY_NULLPTR
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

#define YYPACT_NINF -234

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-234)))

#define YYTABLE_NINF -134

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -234,    18,     0,  -234,     3,   455,  -234,    12,    58,   108,
     159,   159,   158,    34,    34,   203,  -234,  -234,  -234,  -234,
      37,  -234,  -234,  -234,  -234,    45,   196,    60,   239,   240,
      69,    94,  -234,    46,  -234,   170,   101,  -234,  -234,  -234,
      98,   209,   111,   210,    97,   219,    81,   223,  -234,   114,
     153,   266,  -234,  -234,  -234,  -234,  -234,     8,  -234,  -234,
    -234,   133,    13,   137,    91,   137,  -234,    91,   112,   128,
     279,  -234,  -234,   279,  -234,   129,   140,   150,   154,   142,
    -234,   170,   178,   188,   169,   228,   280,  -234,   204,    38,
     221,  -234,  -234,   260,  -234,   244,    91,   172,  -234,  -234,
    -234,  -234,  -234,   261,    91,   182,  -234,  -234,  -234,  -234,
     235,   268,  -234,  -234,  -234,  -234,   290,   291,  -234,  -234,
    -234,   275,  -234,   277,   283,   279,   222,  -234,  -234,   308,
     313,  -234,  -234,    98,   285,   166,  -234,  -234,   383,   286,
     287,   288,     6,  -234,   295,     7,  -234,   292,  -234,  -234,
      82,  -234,  -234,   383,  -234,   294,   307,   315,   316,   312,
     328,   318,  -234,   310,  -234,  -234,    70,   389,   314,  -234,
     319,  -234,   284,   289,   399,   399,   399,   324,   293,  -234,
     331,  -234,   317,   338,   262,  -234,  -234,   353,   329,   383,
     383,   383,   383,   429,  -234,   341,    74,   181,   340,    70,
     345,   346,   349,   351,   362,   366,    19,   399,   367,    15,
    -234,   302,   371,  -234,  -234,   383,   383,   312,   328,   318,
    -234,    24,   359,  -234,  -234,   399,   399,   369,   369,   374,
     375,   377,   378,   380,   381,   342,   342,   384,   385,   415,
     417,   201,   407,  -234,   315,   316,   392,  -234,  -234,  -234,
    -234,  -234,  -234,  -234,  -234,  -234,  -234,  -234,  -234,   342,
    -234,   394,   398,   401,   405,   404,   439,  -234,   342,   399,
     399,   399,   399,   399,   166,  -234,   430,  -234,   419,   421,
     424,   426,   418,   342,   399,   399,   399,   445,   428,  -234,
     431,   435,   438,    -5,   440,  -234,  -234,   342,   342,   342,
     342,   342,  -234,  -234,  -234,  -234,  -234
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     0,     9,     1,     0,     0,     3,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    10,    11,     8,     7,
       0,    25,     5,     6,    12,     0,     0,     0,     0,     0,
       0,     0,    50,    52,    26,     0,     0,    14,    15,    13,
       0,    35,     0,     0,    35,     0,     0,     0,    40,     0,
       0,     0,    49,    16,    51,    23,    22,     0,    19,    21,
      20,     0,     0,    37,     0,    36,    29,     0,     0,     0,
       0,    27,    30,     0,    28,     0,     0,     0,     0,     0,
      24,     0,     0,     0,     0,     0,     0,    61,     0,     0,
       0,    42,    44,     0,    41,     0,     0,    35,    32,    33,
      39,    34,    38,     0,     0,     0,    17,    18,    46,    45,
       0,     0,    67,    68,    65,    59,     0,     0,    60,    43,
      57,     0,    58,     0,     0,     0,     0,    48,    47,     0,
       0,    54,    56,    35,     0,   119,   122,   124,     0,     0,
       0,     0,     0,    81,     0,     0,   123,     0,   121,    73,
       0,    71,    69,     0,    70,     0,   101,   104,   107,   109,
     111,   113,   115,     0,    66,    64,     0,     0,     0,   128,
     119,   116,     0,     0,     0,     0,     0,     0,     0,    75,
       0,    71,     0,     0,     0,   117,    72,     0,     0,     0,
       0,     0,     0,     0,   135,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      74,     0,     0,   118,    86,     0,     0,   108,   110,   112,
     114,   121,     0,    98,   127,     0,     0,   131,   131,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   120,   103,   106,     0,   136,   134,   130,
     129,   126,    93,    76,    94,    77,    78,    87,    88,     0,
      82,     0,     0,     0,     0,     0,     0,    96,     0,     0,
       0,     0,     0,     0,   119,    99,    79,    83,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    97,
       0,     0,     0,     0,     0,    85,    80,     0,     0,     0,
       0,     0,    89,    92,    90,    91,    84
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -234,  -234,  -234,  -234,   246,  -234,   420,   461,   396,  -234,
     -29,   402,   411,   -28,   408,   413,  -234,   173,  -234,   449,
    -234,  -234,  -234,   -58,  -234,  -234,  -128,  -233,  -234,  -234,
    -234,  -234,  -234,  -145,  -234,  -234,   272,  -234,   273,   299,
     300,   301,  -134,  -234,  -234,    93,   296,  -234
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,     5,    18,    23,     9,    26,    58,    59,
      24,    15,    45,    42,    47,    48,    94,    65,    31,    32,
      33,    96,   104,    88,    89,    54,   126,   154,   177,   268,
     237,   276,   296,   155,   156,   187,   157,   188,   158,   159,
     160,   161,   162,   168,   163,   169,   195,   196
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     180,    46,   257,   258,   171,   183,    60,   175,   134,    90,
     135,   136,    80,   137,    82,   138,   240,    83,     3,   185,
     236,   194,   198,   184,     4,  -100,   267,   300,     6,   204,
     205,   206,   166,   146,    34,   277,   148,    25,   121,   116,
     179,    10,    98,   176,   150,   101,   123,   153,   223,   241,
     289,   -95,   107,   211,   194,  -100,  -100,  -100,   220,    11,
    -100,    38,   238,    34,   302,   303,   304,   305,   306,   117,
     -62,   134,    49,   135,   136,   225,   137,   183,   138,    35,
     247,   248,    72,   134,    53,   135,   136,    12,   137,   182,
     138,    36,    85,    39,    -2,    50,   146,    46,    86,   148,
      87,    51,  -133,    30,    61,   226,  -132,   150,   146,    13,
     153,   148,   -34,    14,   -34,   -31,    91,   -31,    92,   150,
      93,   275,   153,   -63,   278,   279,   280,   281,   282,    95,
     103,    68,    62,    62,    69,   -53,   -55,   -53,   -55,   290,
     291,   292,   294,    13,    66,   -31,   -31,    14,   -31,   -31,
     -31,    75,   -31,   -31,   -31,   -31,    76,   -31,   -31,   -31,
     -53,   -55,    16,    16,    17,    17,    20,    81,   -31,   -31,
     110,   -31,    84,   111,    55,   -31,    56,    64,    57,   -31,
     -31,   -31,   -31,   124,    21,   -71,   -71,    67,   -71,   125,
     -71,    69,   -71,   -71,   -71,   -71,    21,   -71,   -71,   -71,
    -131,   167,   263,  -125,    28,   264,    68,    62,   -71,   -71,
      29,   -71,    30,    63,   108,   -71,    63,   227,   166,   -71,
     -71,   -71,   -71,   134,   109,   135,   136,    36,   137,    37,
     138,   112,   139,   140,   141,   142,   115,   143,   144,   145,
      40,    43,    41,    44,    62,    62,    64,    67,   146,   147,
      70,   148,    71,   118,    73,   149,    74,    19,    22,   150,
     151,   152,   153,   134,   119,   135,   136,    77,   137,    78,
     138,   127,   139,   140,   141,   142,   120,   143,   144,   145,
      40,   113,    97,   114,    40,   200,   133,   201,   146,   147,
     202,   148,   203,   122,   208,   149,   209,   129,   130,   150,
     151,   214,   153,   134,   128,   135,   136,   131,   137,   132,
     138,   164,   139,   140,   141,   142,   165,   143,   144,   145,
     249,   250,   166,   172,   173,   174,  -102,   186,   146,   147,
     181,   148,   178,  -105,   190,   149,   191,   189,   192,   150,
     151,   242,   153,   134,   193,   135,   136,   216,   137,   212,
     138,   199,   139,   140,   141,   142,  -125,   143,   144,   145,
     134,   207,   135,   136,   210,   137,   246,   138,   146,   147,
     213,   148,   215,   224,   243,   149,   228,   230,   231,   150,
     151,   232,   153,   233,   134,   146,   170,   136,   148,   137,
     197,   138,   135,   136,   234,   137,   150,   138,   235,   153,
     134,   239,   135,   136,   167,   137,   251,   138,   252,   146,
     253,   254,   148,   255,   256,   146,   259,   260,   148,   261,
     150,   262,   265,   153,   266,   146,   150,   269,   148,   153,
     134,   270,   135,   136,   271,   137,   150,   138,   272,   153,
     134,   273,   274,   136,   283,   137,   293,   138,   135,   136,
     288,   137,   284,   138,   285,   146,     7,   286,   221,   287,
     -16,   295,   -16,   297,   -16,   146,   222,   298,   148,   153,
     299,   146,   301,    79,   148,    27,   150,   106,    99,   153,
      52,   105,   150,     8,   100,   153,   102,   244,   217,   245,
     218,     0,   219,     0,     0,   229
};

static const yytype_int16 yycheck[] =
{
     145,    29,   235,   236,   138,   150,    35,     1,     1,    67,
       3,     4,     4,     6,     1,     8,     1,     4,     0,   153,
       1,   166,   167,   151,    24,     1,   259,    32,    25,   174,
     175,   176,    37,    26,    26,   268,    29,     3,    96,     1,
      33,    29,    70,    37,    37,    73,   104,    40,   193,    34,
     283,    32,    81,   181,   199,    31,    32,    33,   192,     1,
      36,     1,   207,    26,   297,   298,   299,   300,   301,    31,
      32,     1,     3,     3,     4,     1,     6,   222,     8,    34,
     225,   226,     1,     1,    38,     3,     4,    29,     6,     7,
       8,    31,     1,    33,     0,     1,    26,   125,     7,    29,
       9,     7,    32,     9,     3,    31,    32,    37,    26,     1,
      40,    29,    31,     5,    33,     7,     4,     9,     6,    37,
       8,   266,    40,    32,   269,   270,   271,   272,   273,     1,
       1,    34,    35,    35,    37,     7,     7,     9,     9,   284,
     285,   286,   287,     1,    33,     3,     4,     5,     6,     7,
       8,    37,    10,    11,    12,    13,     3,    15,    16,    17,
      32,    32,     4,     4,     6,     6,     8,    34,    26,    27,
       1,    29,    35,     4,     4,    33,     6,    37,     8,    37,
      38,    39,    40,     1,    26,     3,     4,    37,     6,     7,
       8,    37,    10,    11,    12,    13,    26,    15,    16,    17,
      34,    35,     1,    37,     1,     4,    34,    35,    26,    27,
       7,    29,     9,    40,    36,    33,    43,    36,    37,    37,
      38,    39,    40,     1,    36,     3,     4,    31,     6,    33,
       8,     3,    10,    11,    12,    13,    32,    15,    16,    17,
       1,     1,     3,     3,    35,    35,    37,    37,    26,    27,
      31,    29,    33,    32,    31,    33,    33,    11,    12,    37,
      38,    39,    40,     1,     4,     3,     4,     1,     6,     3,
       8,    36,    10,    11,    12,    13,    32,    15,    16,    17,
       1,     1,     3,     3,     1,     1,     3,     3,    26,    27,
       1,    29,     3,    32,     1,    33,     3,     7,     7,    37,
      38,    39,    40,     1,    36,     3,     4,    32,     6,    32,
       8,     3,    10,    11,    12,    13,     3,    15,    16,    17,
     227,   228,    37,    37,    37,    37,    19,    33,    26,    27,
      38,    29,    37,    18,    22,    33,     8,    21,    20,    37,
      38,    39,    40,     1,    34,     3,     4,    18,     6,    32,
       8,    37,    10,    11,    12,    13,    37,    15,    16,    17,
       1,    37,     3,     4,    33,     6,     7,     8,    26,    27,
      32,    29,    19,    32,     3,    33,    36,    32,    32,    37,
      38,    32,    40,    32,     1,    26,     3,     4,    29,     6,
       1,     8,     3,     4,    32,     6,    37,     8,    32,    40,
       1,    34,     3,     4,    35,     6,    32,     8,    33,    26,
      33,    33,    29,    33,    33,    26,    32,    32,    29,     4,
      37,     4,    15,    40,    32,    26,    37,    33,    29,    40,
       1,    33,     3,     4,    33,     6,    37,     8,    33,    40,
       1,    37,     3,     4,    14,     6,     1,     8,     3,     4,
      32,     6,    33,     8,    33,    26,     1,    33,    29,    33,
       5,    33,     7,    32,     9,    26,    37,    32,    29,    40,
      32,    26,    32,    53,    29,    14,    37,    81,    70,    40,
      31,    79,    37,    28,    73,    40,    73,   215,   189,   216,
     190,    -1,   191,    -1,    -1,   199
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
      64,     4,     6,     8,    57,     1,    62,     3,    54,    55,
      53,    54,    56,     1,    63,    52,    49,    51,    36,    36,
       1,     4,     3,     1,     3,    32,     1,    31,    32,     4,
      32,    64,    32,    64,     1,     7,    67,    36,    36,     7,
       7,    32,    32,     3,     1,     3,     4,     6,     8,    10,
      11,    12,    13,    15,    16,    17,    26,    27,    29,    33,
      37,    38,    39,    40,    68,    74,    75,    77,    79,    80,
      81,    82,    83,    85,     3,     3,    37,    35,    84,    86,
       3,    83,    37,    37,    37,     1,    37,    69,    37,    33,
      74,    38,     7,    74,    67,    83,    33,    76,    78,    21,
      22,     8,    20,    34,    74,    87,    88,     1,    74,    37,
       1,     3,     1,     3,    74,    74,    74,    37,     1,     3,
      33,    67,    32,    32,    39,    19,    18,    80,    81,    82,
      83,    29,    37,    74,    32,     1,    31,    36,    36,    87,
      32,    32,    32,    32,    32,    32,     1,    71,    74,    34,
       1,    34,    39,     3,    77,    79,     7,    74,    74,    86,
      86,    32,    33,    33,    33,    33,    33,    68,    68,    32,
      32,     4,     4,     1,     4,    15,    32,    68,    70,    33,
      33,    33,    33,    37,     3,    74,    72,    68,    74,    74,
      74,    74,    74,    14,    33,    33,    33,    33,    32,    68,
      74,    74,    74,     1,    74,    33,    73,    32,    32,    32,
      32,    32,    68,    68,    68,    68,    68
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    41,    42,    43,    43,    44,    44,    44,    44,    44,
      45,    45,    46,    47,    47,    47,    47,    48,    48,    48,
      48,    49,    49,    50,    50,    51,    51,    52,    52,    52,
      52,    52,    53,    53,    53,    54,    54,    54,    55,    55,
      55,    56,    57,    57,    57,    58,    58,    58,    58,    59,
      59,    60,    60,    62,    61,    63,    61,    61,    61,    61,
      61,    64,    64,    64,    65,    65,    65,    65,    65,    66,
      67,    67,    68,    68,    68,    68,    68,    68,    68,    68,
      68,    69,    70,    68,    68,    68,    68,    68,    68,    68,
      68,    68,    68,    68,    68,    71,    72,    73,    74,    74,
      74,    74,    76,    75,    75,    78,    77,    77,    79,    79,
      80,    80,    81,    81,    82,    82,    83,    83,    83,    83,
      83,    83,    83,    83,    83,    84,    83,    83,    85,    86,
      86,    86,    87,    87,    88,    88,    88
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     5,     3,     0,     4,     4,     4,     4,     0,
       1,     1,     1,     4,     4,     4,     0,     5,     5,     3,
       3,     1,     1,     1,     2,     1,     2,     4,     4,     4,
       4,     0,     3,     3,     1,     1,     2,     2,     3,     3,
       1,     3,     1,     2,     1,     3,     3,     4,     4,     2,
       1,     2,     1,     0,     6,     0,     6,     5,     5,     5,
       5,     1,     1,     0,     4,     2,     4,     2,     2,     5,
       2,     0,     2,     1,     3,     2,     5,     5,     5,     7,
      10,     0,     0,     7,    11,     9,     3,     5,     5,    11,
      11,    11,    11,     5,     5,     0,     0,     0,     3,     6,
       3,     1,     0,     4,     1,     0,     4,     1,     3,     1,
       3,     1,     3,     1,     3,     1,     2,     2,     3,     1,
       4,     1,     1,     1,     1,     0,     5,     4,     2,     4,
       4,     0,     1,     0,     3,     1,     3
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
#line 96 "yacc/compil.y" /* yacc.c:1646  */
    {print_end();}
#line 1528 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 105 "yacc/compil.y" /* yacc.c:1646  */
    {
                                                            addMacro((yyvsp[-1].name_defineval), type_define, (yyvsp[0].intval), .0);
                                                        }
#line 1536 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 108 "yacc/compil.y" /* yacc.c:1646  */
    {addMacro((yyvsp[-1].name_defineval), type_define, 0, (yyvsp[0].reelval));}
#line 1542 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 115 "yacc/compil.y" /* yacc.c:1646  */
    {type_define = INTEGER; (yyval.intval) = (yyvsp[0].intval);}
#line 1548 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 116 "yacc/compil.y" /* yacc.c:1646  */
    {type_define = CHAR; (yyval.intval) = (yyvsp[0].charval);}
#line 1554 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 118 "yacc/compil.y" /* yacc.c:1646  */
    {type_define = REAL; (yyval.reelval) = (yyvsp[0].reelval);}
#line 1560 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 129 "yacc/compil.y" /* yacc.c:1646  */
    {
       										if(addConst((yyvsp[-2].identval), type_const, (yyvsp[0].intval), .0) == 0){
       											flag_error = 1;
       										}
       									}
#line 1570 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 134 "yacc/compil.y" /* yacc.c:1646  */
    {
                                            type_const = REAL;
                                            if(addConst((yyvsp[-2].identval), type_const, 0, (yyvsp[0].reelval)) == 0){
                                                flag_error = 1;
                                            }
                                        }
#line 1581 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 140 "yacc/compil.y" /* yacc.c:1646  */
    {
                                            if(addConst((yyvsp[-2].identval), type_const, (yyvsp[0].intval), .0) == 0){
                                                flag_error = 1;
                                            }
                                        }
#line 1591 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 145 "yacc/compil.y" /* yacc.c:1646  */
    {   type_const = REAL;
                                            if(addConst((yyvsp[-2].identval), type_const, 0, (yyvsp[0].reelval)) == 0){
                                                flag_error = 1;
                                            }
                                        }
#line 1601 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 153 "yacc/compil.y" /* yacc.c:1646  */
    {type_const = INTEGER;}
#line 1607 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 154 "yacc/compil.y" /* yacc.c:1646  */
    {type_const = CHAR;}
#line 1613 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 158 "yacc/compil.y" /* yacc.c:1646  */
    {(yyval.intval) = (yyvsp[0].intval);}
#line 1619 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 159 "yacc/compil.y" /* yacc.c:1646  */
    {if((yyvsp[-1].addsubval) == '-'){(yyval.intval) = -((yyvsp[0].intval));}}
#line 1625 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 163 "yacc/compil.y" /* yacc.c:1646  */
    {(yyval.reelval) = (yyvsp[0].reelval);}
#line 1631 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 164 "yacc/compil.y" /* yacc.c:1646  */
    {if((yyvsp[-1].addsubval) == '-') (yyval.reelval) = -((yyvsp[0].reelval));}
#line 1637 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 182 "yacc/compil.y" /* yacc.c:1646  */
    {
					if(addVar((yyvsp[0].identval), type_var, 0, 0, .0) == 0){
						flag_error = 1;
					}
                    fprintf(stdout, "     push QWORD 0\n");
				}
#line 1648 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 188 "yacc/compil.y" /* yacc.c:1646  */
    {size_array = (yyvsp[0].intval);}
#line 1654 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 203 "yacc/compil.y" /* yacc.c:1646  */
    { 
                addVar((yyvsp[(-1) - (1)].identval), type_var, 0, (yyvsp[0].intval), .0); 
                if(is_global_variable == 0)
                    fprintf(stdout, "    push QWORD %d\n", (yyval.intval));
            }
#line 1664 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 208 "yacc/compil.y" /* yacc.c:1646  */
    {
					if((yyvsp[-1].addsubval) == '-'){
						(yyval.intval) = -((yyvsp[0].intval));
					}
					addVar((yyvsp[(-1) - (2)].identval), type_var, 0, (yyval.intval), .0);
                    if(is_global_variable == 0)
                        fprintf(stdout, "    push QWORD %d\n", (yyval.intval));
				  }
#line 1677 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 216 "yacc/compil.y" /* yacc.c:1646  */
    {
					addVar((yyvsp[(-1) - (1)].identval), type_var, 0, (yyvsp[0].charval), .0);
                    if(is_global_variable == 0)
                        fprintf(stdout, "    push QWORD %d\n", (yyval.intval));
				  }
#line 1687 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 224 "yacc/compil.y" /* yacc.c:1646  */
    {(yyval.intval) = 1;}
#line 1693 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 225 "yacc/compil.y" /* yacc.c:1646  */
    {(yyval.intval) = 0;}
#line 1699 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 226 "yacc/compil.y" /* yacc.c:1646  */
    {(yyval.intval) = (yyvsp[-3].intval) + 1;}
#line 1705 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 227 "yacc/compil.y" /* yacc.c:1646  */
    {(yyval.intval) = 0;}
#line 1711 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 242 "yacc/compil.y" /* yacc.c:1646  */
    {   
                        strcpy(name_function, (yyvsp[-1].identval));
                        flag_return = 0;
                        addFun((yyvsp[-1].identval), getType((yyvsp[-2].typeval)));
                        if (flag_start) {
                            is_global_variable = 0;
                            char vars[64][64]; 
                            long vals[64];
                            get_globals_var(vars, vals);
                            print_start(get_globals_size(), vars, vals);
                            flag_start = 0;
                        }
                        fprintf(stdout, "%s:\n    push rbp\n    mov rbp, rsp\n", (yyvsp[-1].identval));
                        createStack();
                        parameters = 0;
                    }
#line 1732 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 259 "yacc/compil.y" /* yacc.c:1646  */
    {
                        int i;
                        for (i = parameters; i > 0; i--)
                            fprintf(stdout, "    push QWORD [rbp+%d]\n", (i+1) * 8);
                    }
#line 1742 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 265 "yacc/compil.y" /* yacc.c:1646  */
    {   
                        strcpy(name_function, (yyvsp[-1].identval));
                        addFun((yyvsp[-1].identval), VOIDTYPE);
                        if (flag_start) {
                            is_global_variable = 0;
                            char vars[64][64]; 
                            long vals[64];
                            get_globals_var(vars, vals);
                            print_start(get_globals_size(), vars, vals);
                            flag_start = 0;
                        }
                        fprintf(stdout, "%s:\n    push rbp\n    mov rbp, rsp\n", (yyvsp[-1].identval));
                        createStack();
                        parameters = 0;
                    }
#line 1762 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 282 "yacc/compil.y" /* yacc.c:1646  */
    {
                        int i;
                        for (i = parameters; i > 0; i--)
                            fprintf(stdout, "    push QWORD [rbp+%d]\n", (i+1) * 8);
                    }
#line 1772 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 299 "yacc/compil.y" /* yacc.c:1646  */
    {  addVar((yyvsp[0].identval), type_var, 1, 0, .0); 
                                    parameters++; 
                                    addArg(name_function, type_var);
                                 }
#line 1781 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 303 "yacc/compil.y" /* yacc.c:1646  */
    {  addVar((yyvsp[0].identval), type_var, 1, 0, .0); 
                                    parameters++; 
                                    addArg(name_function, type_var);
                                 }
#line 1790 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 312 "yacc/compil.y" /* yacc.c:1646  */
    {                
                                                    if (lookupFunction(name_function) != VOIDTYPE && flag_return == 0)
                                                        yyerror("Function is non-void and should return a value");
                                                    fprintf(stdout, "fin_%s:\n", name_function); 
                                                    remove_st_cell();
                                                }
#line 1801 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 325 "yacc/compil.y" /* yacc.c:1646  */
    {                
                        if ((yyvsp[-1].intval) != VOIDTYPE) 
                            fprintf(stdout, "    pop rcx\n");
                    }
#line 1810 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 330 "yacc/compil.y" /* yacc.c:1646  */
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
#line 1826 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 341 "yacc/compil.y" /* yacc.c:1646  */
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
#line 1841 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 352 "yacc/compil.y" /* yacc.c:1646  */
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
#line 1861 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 368 "yacc/compil.y" /* yacc.c:1646  */
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
#line 1881 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 383 "yacc/compil.y" /* yacc.c:1646  */
    {
                                        switch ((yyvsp[-2].intval)) {
                                            case INTEGER: fprintf(stdout, "    pop rsi\n    call _print_ent\n"); break;
                                            case LONG: fprintf(stdout, "    pop rsi\n    call _print_long\n"); break;
                                            case CHAR: fprintf(stdout, "    pop rsi\n    call _print_car\n"); break;
                                            case VOIDTYPE: yyerror("Can't print void value"); break;
                                        }
                                    }
#line 1894 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 392 "yacc/compil.y" /* yacc.c:1646  */
    {
            fprintf(stdout, "fin_if%d:\n", (yyvsp[-3].intval));
        }
#line 1902 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 398 "yacc/compil.y" /* yacc.c:1646  */
    {fprintf(stdout, "debut_while%d:\n", (yyval.intval) = jump_label++);}
#line 1908 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 400 "yacc/compil.y" /* yacc.c:1646  */
    {fprintf(stdout, "    pop rax\n    cmp rax, 0\n    je fin_while%d\n", (yyvsp[-3].intval));}
#line 1914 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 402 "yacc/compil.y" /* yacc.c:1646  */
    {fprintf(stdout, "    jmp debut_while%d\nfin_while%d:\n", (yyvsp[-5].intval), (yyvsp[-5].intval));}
#line 1920 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 417 "yacc/compil.y" /* yacc.c:1646  */
    {fprintf(stdout, "    pop rax\n    cmp rax,0\n    je else_no%d\n",(yyval.intval)=jump_label++);}
#line 1926 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 420 "yacc/compil.y" /* yacc.c:1646  */
    {fprintf(stdout, "    jmp fin_if%d\nelse_no%d:\n", (yyvsp[(-2) - (0)].intval),(yyvsp[(-2) - (0)].intval));}
#line 1932 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 423 "yacc/compil.y" /* yacc.c:1646  */
    {fprintf(stdout, "fin_if%d:\n", (yyvsp[(-5) - (0)].intval));}
#line 1938 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 426 "yacc/compil.y" /* yacc.c:1646  */
    {
                        if(isConstante((yyvsp[-2].identval)) == 1){flag_error = 1;}
                        (yyval.intval) = lookup((yyvsp[-2].identval), 0); 
                        if((yyval.intval) == -1){flag_error = 1;} 
                        (yyval.intval) = cast_type((yyval.intval), (yyvsp[0].intval), 0);
                        if((yyval.intval) == -1){flag_error = 1;}
                        if(globale_variable((yyvsp[-2].identval)) == 1){
                            fprintf(stdout, "    mov QWORD [%s], QWORD %d\n", (yyvsp[-2].identval), (yyvsp[0].intval));
                        }
                        else{
                            int addr[2]; 
                            get_address((yyvsp[-2].identval), addr);
                            switch (addr[1]) {
                                case 0: fprintf(stdout, "    pop QWORD [rbp-%d]\n    push QWORD [rbp-%d]\n", addr[0], addr[0]); break;
                                case 1: fprintf(stdout, "    pop QWORD [globals+%d]\n    push QWORD [globals+%d]\n", addr[0], addr[0]); break;
                                case 2: fprintf(stderr, "%s is a const variable near line %d\n", (yyvsp[-2].identval), line_num); break;
                                default: yyerror("impossible"); break;
                            }
                        }
                    }
#line 1963 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 446 "yacc/compil.y" /* yacc.c:1646  */
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
                            case 1: fprintf(stdout, "    pop QWORD [globals+%d]\n    push QWORD [globals+%d]\n", addr[0], addr[0]); break;
                            case 2: fprintf(stderr, "%s is a const variable near line %d\n", (yyvsp[-5].identval), line_num); break;
                            default: yyerror("impossible"); break;
                        }
                    }
#line 1983 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 461 "yacc/compil.y" /* yacc.c:1646  */
    {   if(isConstante((yyvsp[-2].identval)) == 1){flag_error = 1;}
                                    (yyval.intval) = lookup((yyvsp[-2].identval), 0); 
                                    if((yyval.intval) == -1){flag_error = 1;}
                                    type_macro_assign = lookup((yyvsp[0].name_defineval), 0); 
                                    if(type_macro_assign == -1){flag_error = 1;}
                                    check_types((yyval.intval), type_macro_assign);
                                }
#line 1995 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 473 "yacc/compil.y" /* yacc.c:1646  */
    {
                if (check_types((yyvsp[0].intval), INTEGER) == 0)
                    fprintf(stderr, "Can only apply || to entier values\n"); 
                fprintf(stdout, "    pop rax\n    cmp rax,0\n    jne go_end%d\n", (yyval.intval)=jump_label++);
            }
#line 2005 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 479 "yacc/compil.y" /* yacc.c:1646  */
    {
                if (check_types((yyvsp[-3].intval), (yyvsp[0].intval)) == 0)
                    fprintf(stderr, "Can only apply || to entier values\n"); 
                fprintf(stdout, "    pop rcx\n    mov rax,rcx\ngo_end%d:\n    push rax\n",(yyvsp[-2].intval));
                (yyval.intval) = INTEGER;
            }
#line 2016 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 485 "yacc/compil.y" /* yacc.c:1646  */
    {(yyval.intval) = (yyvsp[0].intval);}
#line 2022 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 487 "yacc/compil.y" /* yacc.c:1646  */
    { 
                if (check_types((yyvsp[0].intval), INTEGER) == 0)
                    fprintf(stderr, "Can only apply && to entier values\n"); 
                fprintf(stdout, "    pop rax\n    cmp rax,0\n    je go_end%d\n",(yyval.intval)=jump_label++);
            }
#line 2032 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 493 "yacc/compil.y" /* yacc.c:1646  */
    {
                if (check_types((yyvsp[-3].intval), (yyvsp[0].intval)) == 0)
                    fprintf(stderr, "Can only apply && to entier values\n"); 
                fprintf(stdout, "    pop rcx\n    mov rax,rcx\ngo_end%d:\n    push rax\n",(yyvsp[-2].intval));          
                (yyval.intval) = INTEGER;
            }
#line 2043 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 499 "yacc/compil.y" /* yacc.c:1646  */
    {(yyval.intval) = (yyvsp[0].intval);}
#line 2049 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 503 "yacc/compil.y" /* yacc.c:1646  */
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
#line 2067 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 516 "yacc/compil.y" /* yacc.c:1646  */
    {(yyval.intval) = (yyvsp[0].intval);}
#line 2073 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 518 "yacc/compil.y" /* yacc.c:1646  */
    {
                if (check_types((yyvsp[-2].intval), (yyvsp[0].intval)) == 1)
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
#line 2105 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 545 "yacc/compil.y" /* yacc.c:1646  */
    {(yyval.intval) = (yyvsp[0].intval);}
#line 2111 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 547 "yacc/compil.y" /* yacc.c:1646  */
    {
                        (yyval.intval) = max_type((yyvsp[-2].intval), (yyvsp[0].intval));
                        switch ((yyvsp[-1].addsubval)) {
                            case '+': fprintf(stdout, "    pop rcx\n    pop rax\n    add rax, rcx\n    push rax\n"); break;
                            case '-': fprintf(stdout, "    pop rcx\n    pop rax\n    sub rax, rcx\n    push rax\n"); break;
                        }
                        
                    }
#line 2124 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 555 "yacc/compil.y" /* yacc.c:1646  */
    {(yyval.intval) = (yyvsp[0].intval);}
#line 2130 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 557 "yacc/compil.y" /* yacc.c:1646  */
    {
                        (yyval.intval) = max_type((yyvsp[-2].intval), (yyvsp[0].intval));
                        fprintf(stdout, "    pop rcx\n    pop rax\n");
                        switch ((yyvsp[-1].divstarval)) {
                            case '*': fprintf(stdout, "    imul rcx\n    push rax\n"); break;
                            case '/': fprintf(stdout, "    mov rdx,0\n    idiv rcx\n    push rax\n"); break;
                            case '%': fprintf(stdout, "    mov rdx,0\n    idiv rcx\n    push rdx\n"); break;
                        }
                    }
#line 2144 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 566 "yacc/compil.y" /* yacc.c:1646  */
    {(yyval.intval) = (yyvsp[0].intval);}
#line 2150 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 570 "yacc/compil.y" /* yacc.c:1646  */
    {
                if (check_types((yyvsp[0].intval), INTEGER) == 0)
                    fprintf(stderr, "Can only apply - + to entier values\n"); 
                (yyval.intval) = (yyvsp[0].intval);
                if ((yyvsp[-1].addsubval) == '-')
                    fprintf(stdout, "    pop rax\n     mov rcx, -1\n    imul rcx\n   push rax\n");
            }
#line 2162 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 578 "yacc/compil.y" /* yacc.c:1646  */
    {
                if (check_types((yyvsp[0].intval), INTEGER) == 0)
                    fprintf(stderr, "Can only apply ! to entier values\n"); 
                (yyval.intval) = (yyvsp[0].intval);
                fprintf(stdout,"    pop rax\n    cmp rax, 0\n    mov rax,1\n    je if_no%d\n", jump_label);
                fprintf(stdout, "    mov rax,0\nif_no%d:\n    push rax\n", jump_label++);
            }
#line 2174 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 585 "yacc/compil.y" /* yacc.c:1646  */
    {(yyval.intval) = (yyvsp[-1].intval);}
#line 2180 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 586 "yacc/compil.y" /* yacc.c:1646  */
    {
    				(yyval.intval) = lookup((yyvsp[0].identval), 0);
    				if((yyval.intval) == -1){
    					flag_error = 1;
                    }
                    if(globale_variable((yyvsp[0].identval)) == 1){
                            fprintf(stdout, "    push QWORD [%s]\n", (yyvsp[0].identval));
                    }
                    else{                       
                        int address[2]; 
                        if(get_address((yyvsp[0].identval), address) == -1)
                            flag_error = 1; 
                        switch(address[1]){
                            case 0: fprintf(stdout, "    push QWORD [rbp-%d]\n", address[0]); break;
                            case 1: fprintf(stdout, "    push QWORD [globals+%d]\n", address[0]); break;
                            case 2: fprintf(stdout, "    push QWORD %d\n", address[0]); break;
                        }
                    }

    			}
#line 2205 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 606 "yacc/compil.y" /* yacc.c:1646  */
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
#line 2225 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 621 "yacc/compil.y" /* yacc.c:1646  */
    {if(((yyval.intval) = lookup((yyvsp[0].name_defineval), 0)) == -1){flag_error = 1;}}
#line 2231 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 122:
#line 622 "yacc/compil.y" /* yacc.c:1646  */
    {(yyval.intval) = INTEGER; fprintf(stdout, "    push QWORD %d\n", (yyvsp[0].intval));}
#line 2237 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 123:
#line 623 "yacc/compil.y" /* yacc.c:1646  */
    {(yyval.intval) = REAL;}
#line 2243 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 124:
#line 624 "yacc/compil.y" /* yacc.c:1646  */
    {(yyval.intval) = CHAR; fprintf(stdout, "    push QWORD %d\n", (yyvsp[0].charval));}
#line 2249 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 125:
#line 626 "yacc/compil.y" /* yacc.c:1646  */
    {
                    add_call_cell((yyvsp[0].identval));
                    args = get_func_i_arg();
                    get_func_call_name(name_called_function);
                }
#line 2259 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 126:
#line 634 "yacc/compil.y" /* yacc.c:1646  */
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
#line 2279 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 128:
#line 653 "yacc/compil.y" /* yacc.c:1646  */
    {strcpy((yyval.identval), (yyvsp[-1].identval));}
#line 2285 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 134:
#line 668 "yacc/compil.y" /* yacc.c:1646  */
    {
                            
                            if (!check_types(get_arg_type(name_called_function, *args), (yyvsp[0].intval)))
                                fprintf(stderr, "%d argument type does not match the expected type\n", (*args));
                            (*args)++;
                        }
#line 2296 "bin/compil.tab.c" /* yacc.c:1646  */
    break;

  case 135:
#line 674 "yacc/compil.y" /* yacc.c:1646  */
    {
                    if (!check_types(get_arg_type(name_called_function, *args), (yyvsp[0].intval)))
                       fprintf(stderr, "%d argument type does not match the expected type\n", (*args));
                    (*args)++; 
                }
#line 2306 "bin/compil.tab.c" /* yacc.c:1646  */
    break;


#line 2310 "bin/compil.tab.c" /* yacc.c:1646  */
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
#line 682 "yacc/compil.y" /* yacc.c:1906  */


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
