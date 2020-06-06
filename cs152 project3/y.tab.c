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
     FUNCTION = 258,
     BEGIN_PARAMS = 259,
     END_PARAMS = 260,
     BEGIN_LOCALS = 261,
     END_LOCALS = 262,
     BEGIN_BODY = 263,
     END_BODY = 264,
     INTEGER = 265,
     ARRAY = 266,
     OF = 267,
     IF = 268,
     THEN = 269,
     ENDIF = 270,
     ELSE = 271,
     WHILE = 272,
     DO = 273,
     FOR = 274,
     BEGINLOOP = 275,
     ENDLOOP = 276,
     CONTINUE = 277,
     READ = 278,
     WRITE = 279,
     AND = 280,
     OR = 281,
     NOT = 282,
     TRUE = 283,
     FALSE = 284,
     RETURN = 285,
     SUB = 286,
     ADD = 287,
     MULT = 288,
     DIV = 289,
     MOD = 290,
     UMINUS = 291,
     EQ = 292,
     NEQ = 293,
     LT = 294,
     GT = 295,
     LTE = 296,
     GTE = 297,
     NUMBER = 298,
     IDENT = 299,
     SEMICOLON = 300,
     COLON = 301,
     COMMA = 302,
     L_PAREN = 303,
     R_PAREN = 304,
     L_SQUARE_BRACKET = 305,
     R_SQUARE_BRACKET = 306,
     ASSIGN = 307
   };
#endif
/* Tokens.  */
#define FUNCTION 258
#define BEGIN_PARAMS 259
#define END_PARAMS 260
#define BEGIN_LOCALS 261
#define END_LOCALS 262
#define BEGIN_BODY 263
#define END_BODY 264
#define INTEGER 265
#define ARRAY 266
#define OF 267
#define IF 268
#define THEN 269
#define ENDIF 270
#define ELSE 271
#define WHILE 272
#define DO 273
#define FOR 274
#define BEGINLOOP 275
#define ENDLOOP 276
#define CONTINUE 277
#define READ 278
#define WRITE 279
#define AND 280
#define OR 281
#define NOT 282
#define TRUE 283
#define FALSE 284
#define RETURN 285
#define SUB 286
#define ADD 287
#define MULT 288
#define DIV 289
#define MOD 290
#define UMINUS 291
#define EQ 292
#define NEQ 293
#define LT 294
#define GT 295
#define LTE 296
#define GTE 297
#define NUMBER 298
#define IDENT 299
#define SEMICOLON 300
#define COLON 301
#define COMMA 302
#define L_PAREN 303
#define R_PAREN 304
#define L_SQUARE_BRACKET 305
#define R_SQUARE_BRACKET 306
#define ASSIGN 307




/* Copy the first part of user declarations.  */
#line 2 "mini_l.y"

 #include <iostream>
 #include <stdio.h>
 #include <stdlib.h>
 #include <string>
 #include <string.h>
 #include <fstream>
 #include <sstream>
 #include <map>
 #include <stack>
 #include <vector>

 using namespace std;

 void yyerror(const char *msg);
 int yylex(void);
 extern int currLine;
 extern int currPos;
 extern FILE * yyin;

 enum symbol_type {INT, INTARRAY, FUNC};

 struct Func 
 {
   string name;
   Func(): name() {}
   Func(string n) 
   : name(n) {}
 };

 struct Sym 
 {
   int val;
   int size;
   string name;
   symbol_type type; 
   Sym():val(0),size(0),name(),type() {}
   Sym(int v, int s, string n, symbol_type t) 
   :val(v), size(s), name(n), type(t) {}
 };

 stack <string> ident_stack;
 stack <string> var_stack;
 stack <int> var_type_stack;
 stack <char*> var_index_stack;
 stack <string> exp_stack;
 stack <string> param_stack;
 stack <string> label_stack;
 
 string make_temp();
 string make_label();

 void check_add_symbol(Sym sym);
 void check_add_func(Func func);
 void check_symbol(string name);
 void check_func(string name);
 void check_array_size(int size);
 
 map <string, Sym> symbol_table;
 map <string, Func> func_table;

 int temp_cnt = 0;
 int label_cnt = 0;
 int param_cnt = 0;
 bool main_exists = 0;
 bool error_detection = true;


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 70 "mini_l.y"
{
  int int_val;
  char *char_val;

  struct attributes {
    char name[255];
    char index[255];
    int type;
    int val;
    int size_attr;
  } attr;
}
/* Line 193 of yacc.c.  */
#line 281 "y.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 294 "y.tab.c"

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
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   175

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  53
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  42
/* YYNRULES -- Number of rules.  */
#define YYNRULES  82
/* YYNRULES -- Number of states.  */
#define YYNSTATES  167

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   307

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      45,    46,    47,    48,    49,    50,    51,    52
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     6,     9,    10,    11,    26,    30,
      31,    35,    36,    40,    42,    46,    48,    55,    65,    67,
      69,    71,    73,    75,    77,    79,    81,    83,    87,    88,
      95,    96,    97,   107,   108,   115,   116,   124,   125,   126,
     127,   144,   147,   150,   152,   155,   157,   161,   163,   167,
     169,   173,   175,   178,   182,   184,   186,   190,   192,   194,
     196,   198,   200,   202,   206,   210,   212,   216,   220,   224,
     226,   229,   231,   233,   235,   237,   241,   246,   250,   252,
     256,   258,   263
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      54,     0,    -1,    55,    -1,    -1,    56,    55,    -1,    -1,
      -1,     3,    44,    57,    45,     4,    59,    58,     5,     6,
      59,     7,     8,    60,     9,    -1,    61,    45,    59,    -1,
      -1,    64,    45,    60,    -1,    -1,    62,    46,    63,    -1,
      44,    -1,    44,    47,    62,    -1,    10,    -1,    11,    50,
      43,    51,    12,    10,    -1,    11,    50,    43,    51,    50,
      43,    51,    12,    10,    -1,    65,    -1,    66,    -1,    70,
      -1,    72,    -1,    74,    -1,    78,    -1,    79,    -1,    80,
      -1,    81,    -1,    94,    52,    88,    -1,    -1,    13,    83,
      14,    67,    60,    15,    -1,    -1,    -1,    13,    83,    14,
      68,    60,    16,    69,    60,    15,    -1,    -1,    17,    83,
      20,    71,    60,    21,    -1,    -1,    18,    20,    73,    60,
      21,    17,    83,    -1,    -1,    -1,    -1,    19,    94,    52,
      43,    75,    45,    83,    76,    45,    94,    52,    88,    77,
      20,    60,    21,    -1,    23,    82,    -1,    24,    82,    -1,
      22,    -1,    30,    88,    -1,    94,    -1,    94,    47,    82,
      -1,    84,    -1,    83,    26,    84,    -1,    85,    -1,    84,
      25,    85,    -1,    86,    -1,    27,    86,    -1,    88,    87,
      88,    -1,    28,    -1,    29,    -1,    48,    83,    49,    -1,
      37,    -1,    38,    -1,    39,    -1,    40,    -1,    41,    -1,
      42,    -1,    88,    32,    89,    -1,    88,    31,    89,    -1,
      89,    -1,    89,    33,    90,    -1,    89,    34,    90,    -1,
      89,    35,    90,    -1,    90,    -1,    31,    91,    -1,    91,
      -1,    92,    -1,    94,    -1,    43,    -1,    48,    88,    49,
      -1,    44,    48,    93,    49,    -1,    44,    48,    49,    -1,
      88,    -1,    88,    47,    93,    -1,    44,    -1,    44,    50,
      88,    51,    -1,    44,    50,    88,    51,    50,    88,    51,
      -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   148,   148,   157,   159,   164,   173,   163,   202,   203,
     207,   208,   212,   216,   221,   229,   242,   257,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   292,   313,   312,
     333,   345,   332,   367,   366,   401,   400,   422,   429,   446,
     421,   469,   497,   525,   542,   554,   560,   569,   573,   586,
     590,   603,   607,   619,   629,   639,   649,   656,   657,   658,
     659,   660,   661,   665,   675,   685,   693,   703,   713,   723,
     731,   743,   749,   753,   774,   786,   793,   811,   825,   829,
     836,   849,   878
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "FUNCTION", "BEGIN_PARAMS", "END_PARAMS",
  "BEGIN_LOCALS", "END_LOCALS", "BEGIN_BODY", "END_BODY", "INTEGER",
  "ARRAY", "OF", "IF", "THEN", "ENDIF", "ELSE", "WHILE", "DO", "FOR",
  "BEGINLOOP", "ENDLOOP", "CONTINUE", "READ", "WRITE", "AND", "OR", "NOT",
  "TRUE", "FALSE", "RETURN", "SUB", "ADD", "MULT", "DIV", "MOD", "UMINUS",
  "EQ", "NEQ", "LT", "GT", "LTE", "GTE", "NUMBER", "IDENT", "SEMICOLON",
  "COLON", "COMMA", "L_PAREN", "R_PAREN", "L_SQUARE_BRACKET",
  "R_SQUARE_BRACKET", "ASSIGN", "$accept", "prog_start", "Program",
  "Function", "@1", "@2", "Declaration_loop", "Statement_loop",
  "Declaration", "Identifier_loop", "Declaration_branch", "Statement",
  "Statement1", "Statement2", "@3", "@4", "@5", "Statement3", "@6",
  "Statement4", "@7", "Statement5", "@8", "@9", "@10", "Statement6",
  "Statement7", "Statement8", "Statement9", "Var_loop", "Bool_Expr",
  "Relation_And_Expr", "Relation_Expr", "Relation_Expr_branch", "Comp",
  "Expression", "Multiplicative_Expr", "Term", "Term_branch",
  "TermIdentifier", "TermExpression_loop", "Var", 0
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
     305,   306,   307
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    53,    54,    55,    55,    57,    58,    56,    59,    59,
      60,    60,    61,    62,    62,    63,    63,    63,    64,    64,
      64,    64,    64,    64,    64,    64,    64,    65,    67,    66,
      68,    69,    66,    71,    70,    73,    72,    75,    76,    77,
      74,    78,    79,    80,    81,    82,    82,    83,    83,    84,
      84,    85,    85,    86,    86,    86,    86,    87,    87,    87,
      87,    87,    87,    88,    88,    88,    89,    89,    89,    89,
      90,    90,    90,    91,    91,    91,    92,    92,    93,    93,
      94,    94,    94
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     0,     2,     0,     0,    14,     3,     0,
       3,     0,     3,     1,     3,     1,     6,     9,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     0,     6,
       0,     0,     9,     0,     6,     0,     7,     0,     0,     0,
      16,     2,     2,     1,     2,     1,     3,     1,     3,     1,
       3,     1,     2,     3,     1,     1,     3,     1,     1,     1,
       1,     1,     1,     3,     3,     1,     3,     3,     3,     1,
       2,     1,     1,     1,     1,     3,     4,     3,     1,     3,
       1,     4,     7
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     0,     2,     3,     5,     1,     4,     0,     0,
       9,    13,     6,     0,     0,     0,     0,     9,     0,    14,
       0,     8,    15,     0,    12,     9,     0,     0,     0,     0,
       0,    11,     0,     0,     0,     0,     0,     0,    43,     0,
       0,     0,    80,     0,     0,    18,    19,    20,    21,    22,
      23,    24,    25,    26,     0,    16,     0,     0,    54,    55,
       0,    74,    80,     0,     0,    47,    49,    51,     0,    65,
      69,    71,    72,    73,     0,    35,     0,    41,    45,    42,
       0,    44,     0,     7,    11,     0,     0,    52,    70,     0,
       0,     0,    28,     0,     0,     0,     0,    57,    58,    59,
      60,    61,    62,     0,     0,     0,     0,    33,    11,     0,
       0,     0,     0,    10,    27,     0,    77,    78,     0,    56,
      75,    11,    11,    48,    50,    64,    63,    53,    66,    67,
      68,    11,     0,    37,    46,    81,    17,     0,    76,     0,
       0,     0,     0,     0,     0,    79,    29,    31,    34,     0,
       0,     0,    11,    36,    38,    82,     0,     0,    32,     0,
       0,     0,    39,     0,    11,     0,    40
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     4,     8,    16,    12,    43,    13,    14,
      24,    44,    45,    46,   121,   122,   152,    47,   131,    48,
     108,    49,   143,   157,   163,    50,    51,    52,    53,    77,
      64,    65,    66,    67,   103,    68,    69,    70,    71,    72,
     118,    73
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -78
static const yytype_int16 yypact[] =
{
      14,   -25,    30,   -78,    14,   -78,   -78,   -78,    22,    44,
      28,    35,   -78,    41,    53,    28,   101,    28,    50,   -78,
     111,   -78,   -78,    68,   -78,    28,    77,   119,    76,   123,
      -8,     3,   122,    91,     8,     8,   121,    99,   -78,    99,
      99,    26,    92,   135,   100,   -78,   -78,   -78,   -78,   -78,
     -78,   -78,   -78,   -78,    94,   -78,    96,    37,   -78,   -78,
      49,   -78,   -10,     8,    -3,   124,   -78,   -78,    98,    61,
     -78,   -78,   -78,   -78,    29,   -78,   102,   -78,   103,   -78,
      26,    72,    26,   -78,     3,    26,   136,   -78,   -78,    40,
     -21,    70,   137,     8,     8,    26,    26,   -78,   -78,   -78,
     -78,   -78,   -78,    26,    26,    26,    26,   -78,     3,   108,
      99,    27,   -19,   -78,    72,   142,   -78,    31,   106,   -78,
     -78,     3,     3,   124,   -78,    61,    61,    72,   -78,   -78,
     -78,     3,   138,   -78,   -78,   107,   -78,    26,   -78,   141,
     144,   140,   145,   113,    26,   -78,   -78,   -78,   -78,     8,
       8,   -17,     3,   139,   139,   -78,   148,   125,   -78,    99,
     112,    26,    72,   146,     3,   147,   -78
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -78,   -78,   163,   -78,   -78,   -78,    -7,   -77,   -78,   154,
     -78,   -78,   -78,   -78,   -78,   -78,   -78,   -78,   -78,   -78,
     -78,   -78,   -78,   -78,   -78,   -78,   -78,   -78,   -78,   -37,
     -34,    78,    79,   115,   -78,   -39,    18,    19,   114,   -78,
      38,   -31
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -31
static const yytype_int16 yytable[] =
{
      54,    74,    81,    79,    32,    93,    76,   113,    78,    78,
      21,    92,    95,    96,    95,    96,    34,     1,    27,     5,
      35,    36,    37,    93,    91,    38,    39,    40,   119,    90,
       6,   132,   135,    41,   155,    57,    58,    59,    89,    60,
      82,   111,    33,   112,   139,   140,   114,    42,    10,   107,
     117,    61,    62,    54,   141,    93,    63,    60,    95,    96,
      22,    23,    95,    96,   127,    58,    59,     9,    60,    61,
      62,    60,    11,   134,    80,   156,   120,    54,   137,    78,
      61,    62,    15,    61,    62,    63,    17,   165,    80,   116,
      54,    54,    61,    42,   104,   105,   106,    80,   117,    18,
      54,    95,    96,    95,    96,   151,    20,    97,    98,    99,
     100,   101,   102,   125,   126,   153,   154,    25,    26,   120,
      28,    54,   162,   128,   129,   130,    29,    30,   160,    95,
      96,    31,    55,    54,    56,    97,    98,    99,   100,   101,
     102,    75,    82,    42,    83,    84,    85,    86,   115,    94,
     110,   133,   136,   -30,   109,   138,   146,   144,   150,   142,
     147,   148,   149,   158,   161,    93,   164,     7,   166,    19,
     159,   123,    87,   124,    88,   145
};

static const yytype_uint8 yycheck[] =
{
      31,    35,    41,    40,    12,    26,    37,    84,    39,    40,
      17,    14,    31,    32,    31,    32,    13,     3,    25,    44,
      17,    18,    19,    26,    63,    22,    23,    24,    49,    63,
       0,   108,    51,    30,    51,    27,    28,    29,    48,    31,
      50,    80,    50,    82,   121,   122,    85,    44,     4,    20,
      89,    43,    44,    84,   131,    26,    48,    31,    31,    32,
      10,    11,    31,    32,   103,    28,    29,    45,    31,    43,
      44,    31,    44,   110,    48,   152,    49,   108,    47,   110,
      43,    44,    47,    43,    44,    48,    45,   164,    48,    49,
     121,   122,    43,    44,    33,    34,    35,    48,   137,    46,
     131,    31,    32,    31,    32,   144,     5,    37,    38,    39,
      40,    41,    42,    95,    96,   149,   150,     6,    50,    49,
      43,   152,   161,   104,   105,   106,     7,    51,   159,    31,
      32,     8,    10,   164,    43,    37,    38,    39,    40,    41,
      42,    20,    50,    44,     9,    45,    52,    51,    12,    25,
      47,    43,    10,    16,    52,    49,    15,    50,    45,    21,
      16,    21,    17,    15,    52,    26,    20,     4,    21,    15,
      45,    93,    57,    94,    60,   137
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    54,    55,    56,    44,     0,    55,    57,    45,
       4,    44,    59,    61,    62,    47,    58,    45,    46,    62,
       5,    59,    10,    11,    63,     6,    50,    59,    43,     7,
      51,     8,    12,    50,    13,    17,    18,    19,    22,    23,
      24,    30,    44,    60,    64,    65,    66,    70,    72,    74,
      78,    79,    80,    81,    94,    10,    43,    27,    28,    29,
      31,    43,    44,    48,    83,    84,    85,    86,    88,    89,
      90,    91,    92,    94,    83,    20,    94,    82,    94,    82,
      48,    88,    50,     9,    45,    52,    51,    86,    91,    48,
      83,    88,    14,    26,    25,    31,    32,    37,    38,    39,
      40,    41,    42,    87,    33,    34,    35,    20,    73,    52,
      47,    88,    88,    60,    88,    12,    49,    88,    93,    49,
      49,    67,    68,    84,    85,    89,    89,    88,    90,    90,
      90,    71,    60,    43,    82,    51,    10,    47,    49,    60,
      60,    60,    21,    75,    50,    93,    15,    16,    21,    17,
      45,    88,    69,    83,    83,    51,    60,    76,    15,    45,
      94,    52,    88,    77,    20,    60,    21
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
#line 149 "mini_l.y"
    {
            if(!main_exists)
            {
                  yyerror("Main is not declared.");
            }
      ;}
    break;

  case 5:
#line 164 "mini_l.y"
    {
            Func f((yyvsp[(2) - (2)].char_val));
            check_add_func(f);
            if(error_detection)
            {
                  cout << "func " << string((yyvsp[(2) - (2)].char_val)) << endl;
            }
      ;}
    break;

  case 6:
#line 173 "mini_l.y"
    {
            while (!param_stack.empty())
            {
                  if(error_detection)
                  {
                        cout << "= " << param_stack.top() << ", " << "$" << param_cnt << endl;
                  }
                  param_cnt++;
                  param_stack.pop();
            }
            param_cnt = 0;
      ;}
    break;

  case 7:
#line 186 "mini_l.y"
    {
            if(error_detection)
            {
                  cout << "endfunc" << "\n" << endl;
            }
            symbol_table.clear();
            if (strcmp((yyvsp[(2) - (14)].char_val), "main") == 0) {
                  main_exists = 1;      
            }
            while (!param_stack.empty()) {
                  param_stack.pop();
            }
      ;}
    break;

  case 13:
#line 217 "mini_l.y"
    {
            ident_stack.push((yyvsp[(1) - (1)].char_val));
            param_stack.push((yyvsp[(1) - (1)].char_val));
      ;}
    break;

  case 14:
#line 222 "mini_l.y"
    {
            ident_stack.push((yyvsp[(1) - (3)].char_val));
            param_stack.push((yyvsp[(1) - (3)].char_val));
      ;}
    break;

  case 15:
#line 230 "mini_l.y"
    {
            while(!ident_stack.empty()) {
                  string temp = ident_stack.top();
                  Sym sym(0,0,temp,INT); 
                  check_add_symbol(sym);
                  if(error_detection)
                  {
                        cout << ". " << temp << endl;
                  }
                  ident_stack.pop(); 
            }
      ;}
    break;

  case 16:
#line 243 "mini_l.y"
    {
            while(!ident_stack.empty()) 
            {
                  string temp = ident_stack.top();
                  check_array_size((yyvsp[(3) - (6)].int_val));
                  Sym sym(0,(yyvsp[(3) - (6)].int_val),temp,INTARRAY);
                  check_add_symbol(sym);
                  if(error_detection)
                  {
                        cout << ".[] " << temp << ", " << (yyvsp[(3) - (6)].int_val) << endl;
                  }
                  ident_stack.pop(); 
            }
      ;}
    break;

  case 17:
#line 258 "mini_l.y"
    {
            while(!ident_stack.empty()) 
            {
                  string temp = ident_stack.top();
                  check_array_size((yyvsp[(3) - (9)].int_val));
                  check_array_size((yyvsp[(6) - (9)].int_val));
                  Sym sym(0,(yyvsp[(3) - (9)].int_val),temp,INTARRAY);
                  check_add_symbol(sym);
                  if(error_detection)
                  {
                        cout << ".[] " << temp << ", " << (yyvsp[(3) - (9)].int_val) << endl;
                  }
                  ident_stack.pop(); 
            }
      ;}
    break;

  case 26:
#line 285 "mini_l.y"
    {
            (yyval.attr).val = (yyvsp[(1) - (1)].attr).val;
            strcpy((yyval.attr).name,(yyvsp[(1) - (1)].attr).name);
      ;}
    break;

  case 27:
#line 293 "mini_l.y"
    {
            if ((yyvsp[(1) - (3)].attr).type == 0) 
            {
                  if(error_detection)
                  {
                        cout << "= " << const_cast<char*>((yyvsp[(1) - (3)].attr).name) << ", " << const_cast<char*>((yyvsp[(3) - (3)].attr).name) << endl;
                  }
            }
            else 
            {
                  if(error_detection)
                  {
                        cout << "[]= " << const_cast<char*>((yyvsp[(1) - (3)].attr).name) << ", " << const_cast<char*>((yyvsp[(1) - (3)].attr).index) << ", " << const_cast<char*>((yyvsp[(3) - (3)].attr).name) << endl;
                  }
            } 
      ;}
    break;

  case 28:
#line 313 "mini_l.y"
    {
            string IfTure = make_label();
            string EndIf = make_label();
            label_stack.push(EndIf); 
            if(error_detection)
            {
                  cout << "?:= " << IfTure << ", " << const_cast<char*>((yyvsp[(2) - (3)].attr).name) << endl;
                  cout << ":= " << EndIf << endl;
                  cout << ": " << IfTure << endl;
            }
      ;}
    break;

  case 29:
#line 325 "mini_l.y"
    {
            if(error_detection)
            {
                  cout << ": " << label_stack.top() << endl;
            }
            label_stack.pop();
      ;}
    break;

  case 30:
#line 333 "mini_l.y"
    {
            string IfTure = make_label();
            string IfFalse = make_label();
            label_stack.push(IfFalse); 
            if(error_detection)
            {
                  cout << "?:= " << IfTure << ", " << const_cast<char*>((yyvsp[(2) - (3)].attr).name) << endl;
                  cout << ":= " << IfFalse << endl;
                  cout << ": " << IfTure << endl;
            }
      ;}
    break;

  case 31:
#line 345 "mini_l.y"
    {
            string EndIf = make_label(); 
            if(error_detection)
            {
                  cout << ":= " << EndIf << endl;
                  cout << ": " << label_stack.top() << endl;
            }
            label_stack.pop();
            label_stack.push(EndIf);
      ;}
    break;

  case 32:
#line 356 "mini_l.y"
    {
            if(error_detection)
            {
                  cout << ": " << label_stack.top() << endl;
            }
            label_stack.pop();
      ;}
    break;

  case 33:
#line 367 "mini_l.y"
    {
            string conditional = make_label();
            string end = make_label();
            string start = make_label();

            if(error_detection)
            {
                  cout << ": " << start << endl;
                  cout << "?:= " << conditional << ", " << const_cast<char*>((yyvsp[(2) - (3)].attr).name) << endl;
                  cout << ":= " << end << endl;
                  cout << ": " << conditional << endl;
            }

            label_stack.push(start);
            label_stack.push(end);
      ;}
    break;

  case 34:
#line 384 "mini_l.y"
    {
            string end = label_stack.top();
            label_stack.pop();

            string start = label_stack.top();
            label_stack.pop();

            if(error_detection)
            {
                  cout << ":= " << start << endl;
                  cout << ": " << end << endl;
            }
      ;}
    break;

  case 35:
#line 401 "mini_l.y"
    {
            string start = make_label();
            label_stack.push(start);
            if(error_detection)
            {
                  cout << ": " << start << endl;
            }
      ;}
    break;

  case 36:
#line 410 "mini_l.y"
    {
            string start = label_stack.top();
            if(error_detection)
            {
                  cout << "?:= " << start << ", " << const_cast<char*>((yyvsp[(7) - (7)].attr).name) << endl;
            }
            label_stack.pop(); 
      ;}
    break;

  case 37:
#line 422 "mini_l.y"
    {
            if(error_detection)
            {
                  cout << "= " << const_cast<char*>((yyvsp[(2) - (4)].attr).name) << ", " << (yyvsp[(4) - (4)].int_val) << endl;
            }
      ;}
    break;

  case 38:
#line 429 "mini_l.y"
    {
            string conditional = make_label();
            string end = make_label();
            string start = make_label();

            if(error_detection)
            {
                  cout << ": " << start << endl;
                  cout << "?:= " << conditional << ", " << const_cast<char*>((yyvsp[(2) - (7)].attr).name) << endl;
                  cout << ":= " << end << endl;
                  cout << ": " << conditional << endl;
            }

            label_stack.push(start);
            label_stack.push(end);
      ;}
    break;

  case 39:
#line 446 "mini_l.y"
    {
            if(error_detection)
            {
                  cout << "= " << const_cast<char*>((yyvsp[(10) - (12)].attr).name) << ", " << const_cast<char*>((yyvsp[(12) - (12)].attr).name) << endl;
            }
      ;}
    break;

  case 40:
#line 453 "mini_l.y"
    {
            string end = label_stack.top();
            label_stack.pop();

            string start = label_stack.top();
            label_stack.pop();

            if(error_detection)
            {
                  cout << ":= " << start << endl;
                  cout << ": " << end << endl;
            }
      ;}
    break;

  case 41:
#line 470 "mini_l.y"
    {
            while (!var_stack.empty()) {
                  if (var_type_stack.top() == 0) 
                  {
                        if(error_detection)
                        {
                              cout << ".< " << var_stack.top() << endl;
                        }
                        var_stack.pop();
                        var_type_stack.pop();
                        var_index_stack.pop();
                  }
                  else 
                  {
                        if(error_detection)
                        {
                              cout << ".[]< " << var_stack.top() << ", " << var_index_stack.top() << endl;
                        }
                        var_stack.pop();
                        var_type_stack.pop();
                        var_index_stack.pop();
                  }
            }
      ;}
    break;

  case 42:
#line 498 "mini_l.y"
    {
            while (!var_stack.empty()) {
                  if (var_type_stack.top() == 0) 
                  {
                        if(error_detection)
                        {
                              cout << ".< " << var_stack.top() << endl;
                        }
                        var_stack.pop();
                        var_type_stack.pop();
                        var_index_stack.pop();
                  }
                  else 
                  {
                        if(error_detection)
                        {
                              cout << ".[]< " << var_stack.top() << ", " << var_index_stack.top() << endl;
                        }
                        var_stack.pop();
                        var_type_stack.pop();
                        var_index_stack.pop();
                  }
            }
      ;}
    break;

  case 43:
#line 526 "mini_l.y"
    {
            if (!label_stack.empty()) 
            {
                  if(error_detection)
                  {
                        cout << ":= " << label_stack.top() << endl;
                  }
            }
            else 
            {
                  yyerror("Continue statement not within a loop.");
            }
      ;}
    break;

  case 44:
#line 543 "mini_l.y"
    {
            (yyval.attr).val = (yyvsp[(2) - (2)].attr).val;
            strcpy((yyval.attr).name,(yyvsp[(2) - (2)].attr).name);
            if(error_detection)
            {
                  cout << "ret " << const_cast<char*>((yyvsp[(2) - (2)].attr).name) << endl;
            }
      ;}
    break;

  case 45:
#line 555 "mini_l.y"
    {
            var_stack.push((yyvsp[(1) - (1)].attr).name);
            var_type_stack.push((yyvsp[(1) - (1)].attr).type);
            var_index_stack.push((yyvsp[(1) - (1)].attr).index);
      ;}
    break;

  case 46:
#line 561 "mini_l.y"
    {
            var_stack.push((yyvsp[(1) - (3)].attr).name);
            var_type_stack.push((yyvsp[(1) - (3)].attr).type);
            var_index_stack.push((yyvsp[(1) - (3)].attr).index);
      ;}
    break;

  case 47:
#line 570 "mini_l.y"
    {
            strcpy((yyval.attr).name, (yyvsp[(1) - (1)].attr).name);
      ;}
    break;

  case 48:
#line 574 "mini_l.y"
    {
            string temp = make_temp();
            strcpy((yyval.attr).name, temp.c_str());
            if(error_detection)
            {
                  cout << ". " << temp << endl;
                  cout << "|| " << temp << ", " << const_cast<char*>((yyvsp[(1) - (3)].attr).name) << ", " << const_cast<char*>((yyvsp[(3) - (3)].attr).name) << endl;
            }
      ;}
    break;

  case 49:
#line 587 "mini_l.y"
    {
            strcpy((yyval.attr).name, (yyvsp[(1) - (1)].attr).name);
      ;}
    break;

  case 50:
#line 591 "mini_l.y"
    {
            string temp = make_temp();
            strcpy((yyval.attr).name, temp.c_str());
            if(error_detection)
            {
                  cout << ". " << temp << endl;
                  cout << "&& " << temp << ", " << const_cast<char*>((yyvsp[(1) - (3)].attr).name) << ", " << const_cast<char*>((yyvsp[(3) - (3)].attr).name) << endl;
            }
      ;}
    break;

  case 51:
#line 604 "mini_l.y"
    {
            strcpy((yyval.attr).name, (yyvsp[(1) - (1)].attr).name);
      ;}
    break;

  case 52:
#line 608 "mini_l.y"
    {
            string temp = make_temp();
            strcpy((yyval.attr).name, temp.c_str());
            if(error_detection)
            {
                  cout << "! " << temp << const_cast<char*>((yyvsp[(2) - (2)].attr).name) << endl;
            }
      ;}
    break;

  case 53:
#line 620 "mini_l.y"
    {
            string temp = make_temp();
            strcpy((yyval.attr).name, temp.c_str());
            if(error_detection)
            {
                  cout << ". " << temp << endl;
                  cout << (yyvsp[(2) - (3)].char_val) << " " << temp << ", " << const_cast<char*>((yyvsp[(1) - (3)].attr).name) << ", " << const_cast<char*>((yyvsp[(3) - (3)].attr).name) << endl;
            }
      ;}
    break;

  case 54:
#line 630 "mini_l.y"
    {
            string temp = make_temp();
            strcpy((yyval.attr).name, temp.c_str());
            if(error_detection)
            {
                  cout << ". " << temp << endl;
                  cout << "= " << temp << ", " << "1" << endl;
            }
      ;}
    break;

  case 55:
#line 640 "mini_l.y"
    {
            string temp = make_temp();
            strcpy((yyval.attr).name, temp.c_str());
            if(error_detection)
            {
                  cout << ". " << temp << endl;
                  cout << "= " << temp << ", " << "0" << endl;
            }
      ;}
    break;

  case 56:
#line 650 "mini_l.y"
    {
            strcpy((yyval.attr).name, (yyvsp[(2) - (3)].attr).name);
      ;}
    break;

  case 57:
#line 656 "mini_l.y"
    { (yyval.char_val) = const_cast<char*>("=="); ;}
    break;

  case 58:
#line 657 "mini_l.y"
    { (yyval.char_val) = const_cast<char*>("!="); ;}
    break;

  case 59:
#line 658 "mini_l.y"
    { (yyval.char_val) = const_cast<char*>("<"); ;}
    break;

  case 60:
#line 659 "mini_l.y"
    { (yyval.char_val) = const_cast<char*>(">"); ;}
    break;

  case 61:
#line 660 "mini_l.y"
    { (yyval.char_val) = const_cast<char*>("<="); ;}
    break;

  case 62:
#line 661 "mini_l.y"
    { (yyval.char_val) = const_cast<char*>(">="); ;}
    break;

  case 63:
#line 666 "mini_l.y"
    {
            string temp = make_temp();
            strcpy((yyval.attr).name, temp.c_str());
            if(error_detection)
            {
                  cout << ". " << temp << endl;
                  cout << "+ " << temp << ", " << const_cast<char*>((yyvsp[(1) - (3)].attr).name) << ", " << const_cast<char*>((yyvsp[(3) - (3)].attr).name) << endl;
            }
      ;}
    break;

  case 64:
#line 676 "mini_l.y"
    {
            string temp = make_temp();
            strcpy((yyval.attr).name, temp.c_str());
            if(error_detection)
            {
                  cout << ". " << temp << endl;
                  cout << "- " << temp << ", " << const_cast<char*>((yyvsp[(1) - (3)].attr).name) << ", " << const_cast<char*>((yyvsp[(3) - (3)].attr).name) << endl;
            }
      ;}
    break;

  case 65:
#line 686 "mini_l.y"
    {
            strcpy((yyval.attr).name,(yyvsp[(1) - (1)].attr).name);
            (yyval.attr).type = (yyvsp[(1) - (1)].attr).type;
      ;}
    break;

  case 66:
#line 694 "mini_l.y"
    {
            string temp = make_temp();
            strcpy((yyval.attr).name, temp.c_str());
            if(error_detection)
            {
                  cout << ". " << temp << endl;
                  cout << "* " << temp << ", " << const_cast<char*>((yyvsp[(1) - (3)].attr).name) << ", " << const_cast<char*>((yyvsp[(3) - (3)].attr).name) << endl;
            }
      ;}
    break;

  case 67:
#line 704 "mini_l.y"
    {
            string temp = make_temp();
            strcpy((yyval.attr).name, temp.c_str());
            if(error_detection)
            {
                  cout << ". " << temp << endl;
                  cout << "/ " << temp << ", " << const_cast<char*>((yyvsp[(1) - (3)].attr).name) << ", " << const_cast<char*>((yyvsp[(3) - (3)].attr).name) << endl;
            }
      ;}
    break;

  case 68:
#line 714 "mini_l.y"
    {
            string temp = make_temp();
            strcpy((yyval.attr).name, temp.c_str());
            if(error_detection)
            {     
                  cout << ". " << temp << endl;
                  cout << "% " << temp << ", " << const_cast<char*>((yyvsp[(1) - (3)].attr).name) << ", " << const_cast<char*>((yyvsp[(3) - (3)].attr).name) << endl;
            }
      ;}
    break;

  case 69:
#line 724 "mini_l.y"
    {
            strcpy((yyval.attr).name,(yyvsp[(1) - (1)].attr).name);
            (yyval.attr).type = (yyvsp[(1) - (1)].attr).type;
      ;}
    break;

  case 70:
#line 732 "mini_l.y"
    {
            (yyval.attr).val = (yyvsp[(2) - (2)].attr).val * -1;
            (yyval.attr).type = (yyvsp[(2) - (2)].attr).type;
            string temp = make_temp();
            strcpy((yyval.attr).name,temp.c_str());
            if(error_detection)
            {
                  cout << ". " << temp << endl;
                  cout << "- " << temp <<  ", " << "0" << ", " << const_cast<char*>((yyvsp[(2) - (2)].attr).name) << endl;
            }
      ;}
    break;

  case 71:
#line 744 "mini_l.y"
    {
            strcpy((yyval.attr).name,(yyvsp[(1) - (1)].attr).name);
            (yyval.attr).val = (yyvsp[(1) - (1)].attr).val;
            (yyval.attr).type = (yyvsp[(1) - (1)].attr).type;
      ;}
    break;

  case 73:
#line 754 "mini_l.y"
    {
            (yyval.attr).val = (yyvsp[(1) - (1)].attr).val;
            (yyval.attr).type = (yyvsp[(1) - (1)].attr).type;
            string temp = make_temp();
            strcpy((yyval.attr).name,temp.c_str());
            if ((yyvsp[(1) - (1)].attr).type != 1) {
                  if(error_detection)
                  {
                        cout << ". " << temp << endl;
                        cout << "= " << temp <<  ", " << const_cast<char*>((yyvsp[(1) - (1)].attr).name) << endl;
                  }
            }
            else if ((yyvsp[(1) - (1)].attr).type == 1) { 
                  if(error_detection)
                  {
                        cout << ". " << temp << endl;
                        cout << "=[] " << temp << ", " << const_cast<char*>((yyvsp[(1) - (1)].attr).name) << ", " << const_cast<char*>((yyvsp[(1) - (1)].attr).index) << endl;
                  }
            }
      ;}
    break;

  case 74:
#line 775 "mini_l.y"
    {
            (yyval.attr).val = (yyvsp[(1) - (1)].int_val);
            (yyval.attr).type = 0;    
            string temp = make_temp();
            strcpy((yyval.attr).name, temp.c_str());
            if(error_detection)
            {
                  cout << ". " << temp << endl;
                  cout << "= " << temp <<  ", " << (yyvsp[(1) - (1)].int_val) << endl;
            }
      ;}
    break;

  case 75:
#line 787 "mini_l.y"
    {
            strcpy((yyval.attr).name, (yyvsp[(2) - (3)].attr).name);
      ;}
    break;

  case 76:
#line 794 "mini_l.y"
    {
            check_func(const_cast<char*>((yyvsp[(1) - (4)].char_val)));
            while (!exp_stack.empty()){
                  if(error_detection)
                  {
                        cout << "param " << exp_stack.top() << endl;
                  }
                  exp_stack.pop();
            }
            string temp = make_temp();
            strcpy((yyval.attr).name,temp.c_str());
            if(error_detection)
            {
                  cout << ". " << temp << endl;
                  cout << "call " << const_cast<char*>((yyvsp[(1) - (4)].char_val)) << ", " << temp << endl;
            }
      ;}
    break;

  case 77:
#line 812 "mini_l.y"
    {
            check_func(const_cast<char*>((yyvsp[(1) - (3)].char_val)));
            string temp = make_temp();
            if(error_detection)
            {
                  cout << ". " << temp << endl;
                  cout << "call " << const_cast<char*>((yyvsp[(1) - (3)].char_val)) << ", " << temp << endl;
            }
            strcpy((yyval.attr).name,temp.c_str());
      ;}
    break;

  case 78:
#line 826 "mini_l.y"
    {
            exp_stack.push((yyvsp[(1) - (1)].attr).name);
      ;}
    break;

  case 79:
#line 830 "mini_l.y"
    {
            exp_stack.push((yyvsp[(1) - (3)].attr).name);
      ;}
    break;

  case 80:
#line 837 "mini_l.y"
    {
            check_symbol((yyvsp[(1) - (1)].char_val));
            if(symbol_table[(yyvsp[(1) - (1)].char_val)].type == INTARRAY) 
            {
                  yyerror("Incompatible datatype.");
            }
            else 
            {
                  strcpy((yyval.attr).name,(yyvsp[(1) - (1)].char_val));
                  (yyval.attr).type = 0;
            }
      ;}
    break;

  case 81:
#line 850 "mini_l.y"
    {
            check_symbol((yyvsp[(1) - (4)].char_val));
            if(symbol_table[(yyvsp[(1) - (4)].char_val)].type == INT) 
            {
                  yyerror("Incompatible datatype.");
            }
            else 
            {
                  if ((yyvsp[(3) - (4)].attr).type == 1) 
                  {
                        string temp = make_temp();
                        (yyval.attr).type = 1;
                        strcpy((yyval.attr).name, (yyvsp[(1) - (4)].char_val));
                        strcpy((yyval.attr).index, temp.c_str());
                        if(error_detection)
                        {
                              cout << ". " << temp << endl; 
                              cout << "=[] " << temp << ", " << const_cast<char*>((yyvsp[(3) - (4)].attr).name) << ", " << const_cast<char*>((yyvsp[(3) - (4)].attr).index) << endl;
                        }
                  }
                  else 
                  {
                        strcpy((yyval.attr).name, (yyvsp[(1) - (4)].char_val));
                        (yyval.attr).type = 1;
                        strcpy((yyval.attr).index, (yyvsp[(3) - (4)].attr).name);
                  }
            }
      ;}
    break;

  case 82:
#line 879 "mini_l.y"
    {
            check_symbol((yyvsp[(1) - (7)].char_val));
            if(symbol_table[(yyvsp[(1) - (7)].char_val)].type == INT) 
            {
                  yyerror("Incompatible datatype.");
            }
            else 
            {
                  if ((yyvsp[(3) - (7)].attr).type == 1) 
                  {
                        string temp = make_temp();
                        (yyval.attr).type = 1;
                        strcpy((yyval.attr).name, (yyvsp[(1) - (7)].char_val));
                        strcpy((yyval.attr).index, temp.c_str());
                        if(error_detection)
                        {
                              cout << ". " << temp << endl; 
                              cout << "=[] " << temp << ", " << const_cast<char*>((yyvsp[(3) - (7)].attr).name) << ", " << const_cast<char*>((yyvsp[(3) - (7)].attr).index) << endl;
                        }
                  }
                  else 
                  {
                        strcpy((yyval.attr).name, (yyvsp[(1) - (7)].char_val));
                        (yyval.attr).type = 1;
                        strcpy((yyval.attr).index, (yyvsp[(3) - (7)].attr).name);
                  }
            }
      ;}
    break;


/* Line 1267 of yacc.c.  */
#line 2500 "y.tab.c"
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


#line 909 "mini_l.y"


int main(int argc, char **argv) {
   if (argc > 1) {
      yyin = fopen(argv[1], "r");
      if (yyin == NULL){
         printf("syntax: %s filename\n", argv[0]);
      }//end if
   }//end if
   yyparse(); // Calls yylex() for tokens.
   return 0;
}

void yyerror(const char *msg) {
   printf("Error Line %d: %s\n", currLine, msg);
   error_detection = false;
}

void yyerror(string message) {
  cout << "Error line " << currLine << ": " << message << endl;
  error_detection = false;
}

string make_temp() {
  stringstream ss;
  ss << temp_cnt++;
  string temp = "__temp__" + ss.str();
  return temp;
}

string make_label() {
  stringstream ss;
  ss << label_cnt++;
  string temp = "__label__" + ss.str();
  return temp;
}

void check_add_symbol(Sym s) {
  if (symbol_table.find(s.name) == symbol_table.end()) {
    symbol_table[s.name] = s;
  }
  else {
    string error = "Symbol \"" + s.name + "\" is multiply-defined." ;
    yyerror(error);
  }
}

void check_add_func(Func f) {
  if (func_table.find(f.name) == func_table.end()) {
    func_table[f.name] = f;
  }
  else {
    string error = "Function \"" + f.name + "\" is multiply-defined.";
    yyerror(error);
  }
}

void check_symbol(string name) {
  if(symbol_table.find(name) == symbol_table.end()) {
    string error = "Used variable \"" + name + "\" was not previously declared.";
    yyerror(error);
  }
}

void check_func(string name) {
  if(func_table.find(name) == func_table.end()) {
    string error = "Function \"" + name + "\" was not previously declared.";
    yyerror(error);
  }
}

void check_array_size(int size) {
  if(size <= 0) {
    string error = "The size of array can not equal or less than 0.";
    yyerror(error);
  }
}

