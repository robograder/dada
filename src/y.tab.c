#ifndef lint
static const char yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93";
#endif

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20110908

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)

#define YYPREFIX "yy"

#define YYPURE 0

#line 16 "parser.y"

#include <time.h>
#include <stdlib.h> /* NULL */
#include <stdio.h>
#include "rtn.h"
#include "check.h"
#include "map.h"
#include "transform.h"
#include "machine.h"
#include "ptrlist.h"

#define YYERROR_VERBOSE 1
#define YYDEBUG 1

pRule initial_rule=NULL;

#ifndef YYBISON
int yydebug=0;
#endif

pListNode transformations = NULL;
extern int verbose;

extern void use_rtn(pRule rtn);

#line 43 "parser.y"
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union {
  double f;
  int i;
  char *s;
  pNode n;
  pOption o;
  pRule r;
  pParam p; /* superceded; pListNode is a generic list of pointer-sized 
	       scalar quantities */
  pListNode l;
  pMapAction ma;
  pMapOpt mo;
  int *pi;
  pTransCmd tc;
  pTransOpt to;
  pTransformation tr;
  pInstr c;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 71 "y.tab.c"

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

/* Parameters sent to yyerror. */
#define YYERROR_DECL() yyerror(const char *s)
#define YYERROR_CALL(msg) yyerror(msg)

extern int YYPARSE_DECL();

#define T_XFORM 257
#define T_COND 258
#define T_EXISTS 259
#define T_NUM 260
#define T_REPEAT 261
#define T_UNIQUE 262
#define T_ENUM 263
#define T_PICK 264
#define T_RESOURCE 265
#define T_LITERAL 266
#define T_IDENT 267
#define T_INTEGER 268
#define T_DEREF 269
#define T_ELLIPSIS 270
#define YYERRCODE 256
static const short yylhs[] = {                           -1,
    0,    1,    1,    1,    1,    2,    2,    2,   21,   16,
   16,   15,   14,   12,   12,   12,   13,   13,   20,   10,
   10,    9,    9,   11,   11,    8,    8,    3,    3,    4,
    5,    5,    6,    6,    6,    6,    6,    6,    6,    6,
    6,    6,    6,    6,    6,    6,    6,    6,    7,    7,
    7,   17,   17,   17,   18,   18,   19,   19,   19,   19,
   19,   19,   19,   19,   19,   19,   19,   19,   19,
};
static const short yylen[] = {                            2,
    1,    0,    2,    2,    2,    4,    5,    7,    5,    2,
    1,    3,    4,    1,    3,    0,    2,    0,    4,    2,
    1,    3,    3,    1,    3,    2,    1,    3,    1,    1,
    2,    1,    1,    3,    2,    3,    3,    2,    3,    2,
    2,    2,    3,    6,    6,    2,    2,    6,    1,    1,
    4,    0,    1,    3,    3,    2,    1,    1,    1,    2,
    3,    3,    3,    3,    3,    3,    3,    3,    3,
};
static const short yydefred[] = {                         2,
    0,    0,    0,    0,    0,    3,    4,    5,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   33,
   21,    0,   27,    0,    0,    0,    0,   49,    0,    0,
   46,   47,    0,    0,    0,    0,    0,    0,    0,    0,
   38,    0,    0,    0,   53,    0,    6,    0,    0,    0,
   42,   41,    0,   19,   20,   26,    0,    0,   10,    9,
    7,    0,    0,    0,   22,   23,    0,    0,    0,    0,
   58,   59,   57,    0,    0,    0,    0,   39,   43,   28,
   34,    0,    0,    0,   12,    0,    0,    0,   51,    0,
   60,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   54,    0,    0,    0,    0,    0,    0,   25,   61,    0,
    0,    0,    0,    0,   64,   65,   66,    8,   15,    0,
    0,   45,   44,   48,   17,   13,
};
static const short yydgoto[] = {                          1,
    2,    6,   26,   27,   28,   29,   30,   34,   31,   32,
   75,   94,  131,   95,   36,   37,   54,   55,   86,    7,
    8,
};
static const short yysindex[] = {                         0,
    0,  -66, -245, -239,   80,    0,    0,    0,  -28,  -19,
   56, -218, -215,   65,   36,   65,   65,   51,   33,   43,
   65,   65, -169,  -51,   65,   41,   -3,   65,  -31,    0,
    0,  -58,    0,  -38,   69, -215,   55,    0,   77,   65,
    0,    0, -137, -123, -120,   65,   65,   65,  -31,  -31,
    0,   88,   72,  -46,    0,   57,    0,   65,  -31, -116,
    0,    0,   33,    0,    0,    0,   94, -106,    0,    0,
    0,   27,  121,  119,    0,    0,   32,   82,  -31,   72,
    0,    0,    0,  -96,   72,  127,  -51,    0,    0,    0,
    0,   65,  133,  -89,    0, -128,   65,  -86,    0,  127,
    0,  116,   72,   72,   72,   72,   72,   72,   72,   72,
    0,  124,  -83,  -77,  149,  151,  -22,    0,    0,  318,
  139,  139,   16,   16,    0,    0,    0,    0,    0,  -77,
  135,    0,    0,    0,    0,    0,
};
static const short yyrindex[] = {                         0,
    0,  196,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  -18,  -36,
    0,    0,    0,  -26,    0,    0,  -43,    9,   31,    0,
    0,    0,    0,    0,    0,  141,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   -7,    2,
    0,    0,    0,    0,    0,    0,    0,    0,   44,    0,
    0,    0,    0,    0,    0,    0,    0,  -64,    0,    0,
    0,    0,    0,  -57,    0,    0,  -27,    0,   18,    0,
    0,    0,    0,    0,    0,  -17,    0,    0,    0,    0,
    0,    0,  -63,    0,    0,    0,    0,    0,    0,  -12,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  147,    0,    0,    0,    0,    0,   19,
  217,  250,   89,  152,    0,    0,    0,    0,    0,  147,
    0,    0,    0,    0,    0,    0,
};
static const short yygindex[] = {                         0,
    0,    0,  -10,    0,  160,  336,    0,    0,  178,    0,
    0,    0,   85,    0,    0,  176,    0,  130,  303,    0,
    0,
};
#define YYTABLESIZE 520
static const short yytable[] = {                         50,
   64,   24,   67,   39,   50,   50,   50,   50,   36,   53,
   62,   61,   87,   36,   56,   29,   36,   49,  134,   62,
   61,    9,   50,   49,   49,   50,   50,   10,   40,   13,
   60,   36,   52,   40,   36,   36,   40,   35,   14,   60,
   49,   56,   35,   49,   49,   35,   55,   90,   33,   29,
   35,   40,  110,   37,   50,   40,   50,  108,   37,   67,
   35,   37,  109,   36,   35,   36,   32,   30,   62,   61,
   96,   32,   49,   62,   61,   40,   37,   67,   88,   31,
   37,  112,   47,   40,   31,   40,   50,   50,   60,   32,
   43,   23,   35,   32,   35,   36,   36,   51,   52,   57,
   23,   30,   31,   48,   49,   49,   31,   56,   37,   44,
   37,   85,   55,   70,   45,   40,   40,   23,   21,   12,
   58,   32,   99,   32,   35,   35,   68,   21,   46,   63,
   73,   63,   30,   63,   31,   71,   31,   11,  115,  116,
   37,   37,   74,   67,   21,   76,   25,   63,   80,   89,
   91,   92,  110,   32,   32,   25,  119,  108,  107,   63,
  106,   93,  109,  110,   97,   98,   31,   31,  108,  107,
  101,  106,   25,  109,   63,  110,  113,  114,   24,  118,
  108,  107,  128,  106,  129,  109,  105,   24,  130,  132,
    3,  133,   62,  136,   62,    1,   62,  105,    4,   11,
    5,  104,   16,   14,   24,   18,   78,   63,   24,   65,
   62,   69,  104,   63,  135,   52,  111,    0,    0,    0,
    0,    0,   62,    0,   50,   50,   50,   50,   66,   50,
   50,    0,   50,   36,   36,   36,   36,   62,   36,   36,
    0,   36,   49,   49,   49,   49,    0,   49,   49,    0,
   49,    0,    0,   40,   40,   40,   40,   68,   40,   40,
    0,   40,   35,   35,   35,   35,    0,   35,   35,    0,
   35,    0,    0,    0,    0,   68,   62,    0,   37,   37,
   37,   37,    0,   37,   37,    0,   37,   68,   67,    0,
   69,   32,   32,   32,   32,    0,   32,   32,    0,   32,
    0,    0,   68,    0,   31,   31,   31,   31,   69,   31,
   31,    0,   31,    0,    0,    0,   15,   16,   17,   18,
   69,   19,   20,    0,   22,   15,   16,   17,   18,    0,
   38,   20,    0,   22,    0,   69,    0,   81,   82,   83,
   84,   68,   15,   16,   17,   18,    0,   38,   20,    0,
   22,   41,   42,    0,  110,    0,   49,   50,   63,  108,
  107,    0,  106,   59,  109,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   69,   72,    0,    0,    0,    0,
    0,   77,  100,   79,    0,  103,    0,  102,  105,    0,
    0,    0,    0,    0,    0,    0,  103,    0,    0,    0,
    0,    0,    0,  104,    0,  120,  121,  122,  123,  124,
  125,  126,  127,   59,    0,    0,    0,    0,    0,    0,
    0,   62,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  117,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   68,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   69,
};
static const short yycheck[] = {                         36,
   59,   59,   41,   14,   41,   42,   43,   44,   36,   61,
   42,   43,   59,   41,   25,   59,   44,   36,   41,   42,
   43,  267,   59,   42,   43,   62,   63,  267,   36,   58,
   62,   59,   59,   41,   62,   63,   44,   36,   58,   62,
   59,   59,   41,   62,   63,   44,   59,   58,  267,   93,
  266,   59,   37,   36,   91,   63,   93,   42,   41,   41,
   59,   44,   47,   91,   63,   93,   36,   59,   42,   43,
   44,   41,   91,   42,   43,   40,   59,   59,  125,   36,
   63,   92,   40,   91,   41,   93,  123,  124,   62,   59,
   40,   36,   91,   63,   93,  123,  124,  267,  125,   59,
   36,   93,   59,   61,  123,  124,   63,  125,   91,   77,
   93,   40,  125,   59,   82,  123,  124,   36,   63,   40,
  124,   91,   41,   93,  123,  124,   58,   63,   86,   41,
  268,   43,  124,   45,   91,   59,   93,   58,  267,  268,
  123,  124,  266,  125,   63,  266,   91,   59,   61,   93,
  267,   58,   37,  123,  124,   91,   41,   42,   43,   71,
   45,  268,   47,   37,   44,   47,  123,  124,   42,   43,
  267,   45,   91,   47,   86,   37,   44,  267,  123,  266,
   42,   43,   59,   45,  268,   47,   71,  123,  266,   41,
  257,   41,   41,   59,   43,    0,   45,   71,  265,   59,
  267,   86,  267,  267,  123,   59,   47,  266,  266,   32,
   59,   36,   86,  125,  130,  267,   87,   -1,   -1,   -1,
   -1,   -1,   71,   -1,  261,  262,  263,  264,  267,  266,
  267,   -1,  269,  261,  262,  263,  264,   86,  266,  267,
   -1,  269,  261,  262,  263,  264,   -1,  266,  267,   -1,
  269,   -1,   -1,  261,  262,  263,  264,   41,  266,  267,
   -1,  269,  261,  262,  263,  264,   -1,  266,  267,   -1,
  269,   -1,   -1,   -1,   -1,   59,  125,   -1,  261,  262,
  263,  264,   -1,  266,  267,   -1,  269,   71,  270,   -1,
   41,  261,  262,  263,  264,   -1,  266,  267,   -1,  269,
   -1,   -1,   86,   -1,  261,  262,  263,  264,   59,  266,
  267,   -1,  269,   -1,   -1,   -1,  261,  262,  263,  264,
   71,  266,  267,   -1,  269,  261,  262,  263,  264,   -1,
  266,  267,   -1,  269,   -1,   86,   -1,  266,  267,  268,
  269,  125,  261,  262,  263,  264,   -1,  266,  267,   -1,
  269,   16,   17,   -1,   37,   -1,   21,   22,  270,   42,
   43,   -1,   45,   28,   47,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  125,   40,   -1,   -1,   -1,   -1,
   -1,   46,   80,   48,   -1,  270,   -1,   85,   71,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  270,   -1,   -1,   -1,
   -1,   -1,   -1,   86,   -1,  103,  104,  105,  106,  107,
  108,  109,  110,   78,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  270,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   97,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  270,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  270,
};
#define YYFINAL 1
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 270
#if YYDEBUG
static const char *yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,"'$'","'%'",0,0,"'('","')'","'*'","'+'","','","'-'",0,"'/'",0,0,0,0,0,0,0,0,
0,0,"':'","';'",0,"'='","'>'","'?'",0,0,0,0,0,0,0,"'G'",0,0,0,0,0,"'M'",0,0,0,0,
"'R'",0,0,0,"'V'",0,0,0,0,"'['",0,"']'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,"'{'","'|'","'}'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"T_XFORM","T_COND",
"T_EXISTS","T_NUM","T_REPEAT","T_UNIQUE","T_ENUM","T_PICK","T_RESOURCE",
"T_LITERAL","T_IDENT","T_INTEGER","T_DEREF","T_ELLIPSIS",
};
static const char *yyrule[] = {
"$accept : input",
"input : rules",
"rules :",
"rules : rules rule",
"rules : rules mapping",
"rules : rules transformation",
"rule : T_IDENT ':' options ';'",
"rule : T_RESOURCE T_IDENT ':' options ';'",
"rule : T_IDENT '(' params ')' ':' options ';'",
"transformation : T_XFORM T_IDENT ':' transopts ';'",
"transopts : transopt transopts",
"transopts : transopt",
"transopt : T_LITERAL ':' transcmd",
"transcmd : transaddr T_IDENT translist ';'",
"transaddr : T_INTEGER",
"transaddr : T_INTEGER ',' T_INTEGER",
"transaddr :",
"translist : T_LITERAL translist",
"translist :",
"mapping : T_IDENT ':' mapopts ';'",
"mapopts : mapopts mapopt",
"mapopts : mapopt",
"mapopt : T_LITERAL 'M' mapaction",
"mapopt : T_LITERAL 'R' T_LITERAL",
"mapaction : T_LITERAL",
"mapaction : T_LITERAL '/' T_LITERAL",
"params : params T_IDENT",
"params : T_IDENT",
"options : option '|' options",
"options : option",
"option : atoms",
"atoms : atoms atom",
"atoms : atom",
"atom : atom2",
"atom : atom '>' T_IDENT",
"atom : T_DEREF atom",
"atom : T_IDENT 'V' atom",
"atom : T_IDENT '=' atom",
"atom : '$' T_IDENT",
"atom : '{' imperatives '}'",
"atom : '?' atom",
"atom : atom '*'",
"atom : atom '+'",
"atom : '[' options ']'",
"atom : T_REPEAT '(' atom ',' T_INTEGER ')'",
"atom : T_REPEAT '(' atom ',' T_IDENT ')'",
"atom : T_UNIQUE atom",
"atom : T_ENUM atom",
"atom : T_PICK '(' T_INTEGER ',' atom ')'",
"atom2 : T_LITERAL",
"atom2 : T_IDENT",
"atom2 : T_IDENT '(' atoms ')'",
"imperatives :",
"imperatives : imperative",
"imperatives : imperatives ';' imperative",
"imperative : T_IDENT '=' expr",
"imperative : '=' expr",
"expr : T_INTEGER",
"expr : T_LITERAL",
"expr : T_IDENT",
"expr : T_DEREF T_IDENT",
"expr : '(' expr ')'",
"expr : expr '+' expr",
"expr : expr '-' expr",
"expr : expr '*' expr",
"expr : expr '/' expr",
"expr : expr '%' expr",
"expr : expr T_ELLIPSIS expr",
"expr : expr 'V' expr",
"expr : expr 'G' expr",

};
#endif

int      yydebug;
int      yynerrs;

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 500
#define YYMAXDEPTH  500
#endif
#endif

#define YYINITSTACKSIZE 500

typedef struct {
    unsigned stacksize;
    short    *s_base;
    short    *s_mark;
    short    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;
/* variables for the parser stack */
static YYSTACKDATA yystack;
#line 294 "parser.y"

extern int cur_line;
extern char cur_file[1024];

yyerror(char *s)
{
  fprintf(stderr, "%s:%i: %s\n", cur_file, cur_line, s);
};

#if 0

int strtoseed(char *s)
{
    int r=0;
    if(atoi(s))return atoi(s);
    while(*s) { r+=*(s++); }
    return r;
};

main(int argc, char *argv[])
{
  int i;

  char *rseed=NULL; /* a random seed, in string form */

  for(i=1; i<argc; i++) {
    if(*(argv[i])=='-')
      switch(argv[i][1]) {
      case 'd': dump_rtn = 1;
      case 'i': inhibit = 1; break;
      case 'o': outfile=fopen(argv[++i], "w"); break;
      case 'p': old_probability=1; break;
      case 'r': rseed = argv[++i]; break;
      case 's': start_symbol = argv[++i]; break;
      case 't': trace=1; break;
      case 'v': verbose = 1; break;
      case 'y': yydebug=1; break;
      };
  };
  srandom(rseed?strtoseed(rseed):time(NULL));
  yyparse();
};

#endif
#line 472 "y.tab.c"

#if YYDEBUG
#include <stdio.h>		/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    short *newss;
    YYSTYPE *newvs;

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return -1;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = data->s_mark - data->s_base;
    newss = (short *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return -1;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return -1;

    data->l_base = newvs;
    data->l_mark = newvs + i;

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab

int
YYPARSE_DECL()
{
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack)) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = YYLEX) < 0) yychar = 0;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
        {
            goto yyoverflow;
        }
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;

    yyerror("syntax error");

    goto yyerrlab;

yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yystack.s_mark]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
                {
                    goto yyoverflow;
                }
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
                --yystack.s_mark;
                --yystack.l_mark;
            }
        }
    }
    else
    {
        if (yychar == 0) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
    switch (yyn)
    {
case 1:
#line 111 "parser.y"
	{ use_rtn(yystack.l_mark[0].r);
  /* if(dump_rtn) { 
                 dump_rules($1); 
		 dump_mappings(mappings); 
		 dump_transformations(transformations);
	       }
	       check_rtn($1);
               rule_base = $1;
	       if(start_symbol) {
		 initial_rule=rule_find($1, start_symbol);
		 if(!initial_rule) {
		   fprintf(stderr, "rule \"%s\" does not exist.\n", 
			   start_symbol);
		   exit(1);
		 };
	       };
	       if(!inhibit) fprintf(outfile, "%s\n", 
				    resolve_rule($1, initial_rule)); */}
break;
case 2:
#line 131 "parser.y"
	{ yyval.r = NULL; }
break;
case 3:
#line 132 "parser.y"
	{ 
/*	              if(initial_rule==NULL) {
			initial_rule = $2;
			if(verbose)fprintf(stderr, "Start symbol == %s\n", 
				initial_rule->symbol);
		      };*/
		      /* FIXME: add check for duplicate rules here */
	              yyval.r = rule_insert(yystack.l_mark[-1].r, yystack.l_mark[0].r); 
		    }
break;
case 4:
#line 141 "parser.y"
	{ yyval.r = yystack.l_mark[-1].r; /* mappings != rules */ }
break;
case 5:
#line 142 "parser.y"
	{ yyval.r = yystack.l_mark[-1].r; /* mappings != rules */ }
break;
case 6:
#line 145 "parser.y"
	{ pRule r = rule_new(yystack.l_mark[-3].s, yystack.l_mark[-1].o, NULL); 
                                if(initial_rule==NULL) {
           			  initial_rule = r;
			          if(verbose)
                                    fprintf(stderr, "Start symbol == %s\n", 
				                    r->symbol);
		                };
			        yyval.r = r;
			      }
break;
case 7:
#line 154 "parser.y"
	{ pRule r = rule_new(yystack.l_mark[-3].s, yystack.l_mark[-1].o, NULL); 
			                   yyval.r = r;
			                 }
break;
case 8:
#line 157 "parser.y"
	{ pRule r = rule_new(yystack.l_mark[-6].s, yystack.l_mark[-1].o, yystack.l_mark[-4].p); 
					       yyval.r = r;
					     }
break;
case 9:
#line 162 "parser.y"
	{ 
  transformations = list_cons(new_transformation(yystack.l_mark[-3].s, yystack.l_mark[-1].l), transformations); 
/*  fprintf(stderr, "Transformation: %s\n", 
	 ((pTransformation)transformations->data)->name);*/
}
break;
case 10:
#line 169 "parser.y"
	{ yyval.l = list_cons(yystack.l_mark[-1].to, yystack.l_mark[0].l); }
break;
case 11:
#line 170 "parser.y"
	{ yyval.l = list_cons(yystack.l_mark[0].to, NULL); }
break;
case 12:
#line 173 "parser.y"
	{ yyval.to = new_transopt(yystack.l_mark[-2].s, yystack.l_mark[0].tc);
/*				   fprintf(stderr, "xform option: %s", $1);*/
				 }
break;
case 13:
#line 178 "parser.y"
	{ yyval.tc = new_transcmd(yystack.l_mark[-3].pi, yystack.l_mark[-2].s, yystack.l_mark[-1].l); }
break;
case 14:
#line 181 "parser.y"
	{ yyval.pi = new_addr_range(yystack.l_mark[0].i, yystack.l_mark[0].i); }
break;
case 15:
#line 182 "parser.y"
	{ yyval.pi = new_addr_range(yystack.l_mark[-2].i, yystack.l_mark[0].i); }
break;
case 16:
#line 183 "parser.y"
	{ yyval.pi = NULL; }
break;
case 17:
#line 186 "parser.y"
	{ yyval.l = list_cons((void *)yystack.l_mark[-1].s, yystack.l_mark[0].l); }
break;
case 18:
#line 187 "parser.y"
	{ yyval.l = NULL; }
break;
case 19:
#line 190 "parser.y"
	{ mappings = map_cons(yystack.l_mark[-3].s, yystack.l_mark[-1].mo, mappings); }
break;
case 20:
#line 193 "parser.y"
	{ yyval.mo = mapopt_concat(yystack.l_mark[-1].mo, yystack.l_mark[0].mo); }
break;
case 21:
#line 194 "parser.y"
	{ yyval.mo = yystack.l_mark[0].mo; }
break;
case 22:
#line 197 "parser.y"
	{ yyval.mo = mapopt_cons(yystack.l_mark[-2].s, yystack.l_mark[0].ma, NULL); }
break;
case 23:
#line 198 "parser.y"
	{ 
    yyval.mo = mapopt_cons(yystack.l_mark[-2].s, new_replace_action(yystack.l_mark[0].s),
		     mapopt_cons(yystack.l_mark[0].s, new_replace_action(yystack.l_mark[-2].s), NULL));
  }
break;
case 24:
#line 204 "parser.y"
	{ yyval.ma = new_replace_action(yystack.l_mark[0].s); }
break;
case 25:
#line 205 "parser.y"
	{ yyval.ma = new_subst_action(yystack.l_mark[-2].s, yystack.l_mark[0].s); }
break;
case 26:
#line 208 "parser.y"
	{ yyval.p = list_append(yystack.l_mark[-1].p, list_cons((void *)yystack.l_mark[0].s, NULL)); }
break;
case 27:
#line 209 "parser.y"
	{ yyval.p = list_cons((void *)yystack.l_mark[0].s, NULL); }
break;
case 28:
#line 212 "parser.y"
	{ yyval.o = option_append(yystack.l_mark[-2].o, yystack.l_mark[0].o); }
break;
case 29:
#line 213 "parser.y"
	{ yyval.o = yystack.l_mark[0].o; }
break;
case 30:
#line 216 "parser.y"
	{ yyval.o = option_cons(yystack.l_mark[0].n, NULL); }
break;
case 31:
#line 219 "parser.y"
	{ yyval.n = node_append(yystack.l_mark[-1].n, yystack.l_mark[0].n); }
break;
case 32:
#line 220 "parser.y"
	{ yyval.n = yystack.l_mark[0].n; }
break;
case 33:
#line 223 "parser.y"
	{ yyval.n = yystack.l_mark[0].n; }
break;
case 34:
#line 224 "parser.y"
	{ pNode n = node_cons(mapping, yystack.l_mark[0].s, NULL);
			  n->params = yystack.l_mark[-2].n;
			  yyval.n = n;
			}
break;
case 35:
#line 228 "parser.y"
	{ pNode n = node_cons(deref, NULL, NULL); 
		     n->params=yystack.l_mark[0].n; yyval.n=n; }
break;
case 36:
#line 230 "parser.y"
	{ pNode n = node_cons(var_conddef, yystack.l_mark[-2].s, NULL);
			 n->params = yystack.l_mark[0].n;
			 yyval.n = n;
		       }
break;
case 37:
#line 234 "parser.y"
	{ pNode n = node_cons(var_def, yystack.l_mark[-2].s, NULL);
			 n->params = yystack.l_mark[0].n;
			 yyval.n = n;
		       }
break;
case 38:
#line 238 "parser.y"
	{ yyval.n = node_cons(var_ref, yystack.l_mark[0].s, NULL); }
break;
case 39:
#line 239 "parser.y"
	{ yyval.n = node_cons(code, (char *)yystack.l_mark[-1].c, NULL); }
break;
case 40:
#line 240 "parser.y"
	{ pNode n = node_cons(silence, NULL, NULL); n->params=yystack.l_mark[0].n; 
		 yyval.n = n; }
break;
case 41:
#line 242 "parser.y"
	{ pNode n = node_cons(star, NULL, NULL); n->params=yystack.l_mark[-1].n; yyval.n=n; }
break;
case 42:
#line 243 "parser.y"
	{ pNode n = node_cons(plus, NULL, NULL); n->params=yystack.l_mark[-1].n; yyval.n=n; }
break;
case 43:
#line 244 "parser.y"
	{ pNode n = node_cons(choice, (char *)yystack.l_mark[-1].o, NULL);
                        n->last_choice = -1; yyval.n=n; }
break;
case 44:
#line 246 "parser.y"
	{ 
      pNode n = node_cons(repeat_const, NULL, NULL);
      n->params = yystack.l_mark[-3].n; n->int_param = yystack.l_mark[-1].i;
      yyval.n=n; }
break;
case 45:
#line 250 "parser.y"
	{ 
      pNode n = node_cons(repeat_var, NULL, NULL);
      n->params = yystack.l_mark[-3].n; n->data = yystack.l_mark[-1].s;
      yyval.n=n; }
break;
case 46:
#line 254 "parser.y"
	{ pNode n=yystack.l_mark[0].n; n->mode = unique; yyval.n=n; }
break;
case 47:
#line 255 "parser.y"
	{ pNode n=yystack.l_mark[0].n; n->mode = enumerate; yyval.n=n; }
break;
case 48:
#line 256 "parser.y"
	{ pNode n=yystack.l_mark[-1].n; n->mode = pick; 
                                          n->pick_num=yystack.l_mark[-3].i; yyval.n=n; }
break;
case 49:
#line 260 "parser.y"
	{ yyval.n = node_cons(literal, yystack.l_mark[0].s, NULL); }
break;
case 50:
#line 261 "parser.y"
	{ yyval.n = node_cons(symbol, yystack.l_mark[0].s, NULL); }
break;
case 51:
#line 262 "parser.y"
	{ pNode n = node_cons(symbol, yystack.l_mark[-3].s, NULL);
			      n->params = yystack.l_mark[-1].n;
			      yyval.n = n;
			    }
break;
case 52:
#line 269 "parser.y"
	{ yyval.c = NULL; }
break;
case 53:
#line 270 "parser.y"
	{ yyval.c = yystack.l_mark[0].c; }
break;
case 54:
#line 271 "parser.y"
	{ yyval.c = icat(yystack.l_mark[-2].c, yystack.l_mark[0].c); }
break;
case 55:
#line 274 "parser.y"
	{ yyval.c = icat(yystack.l_mark[0].c, e_set(yystack.l_mark[-2].s)); }
break;
case 56:
#line 275 "parser.y"
	{ yyval.c = icat(yystack.l_mark[0].c, e_simple(EMIT)); }
break;
case 57:
#line 278 "parser.y"
	{ yyval.c = e_push_int(yystack.l_mark[0].i); }
break;
case 58:
#line 279 "parser.y"
	{ yyval.c = e_push_str(yystack.l_mark[0].s); }
break;
case 59:
#line 280 "parser.y"
	{ yyval.c = e_pushv(yystack.l_mark[0].s); }
break;
case 60:
#line 281 "parser.y"
	{ yyval.c = e_invoke(yystack.l_mark[0].s); }
break;
case 61:
#line 282 "parser.y"
	{ yyval.c = yystack.l_mark[-1].c; }
break;
case 62:
#line 283 "parser.y"
	{ yyval.c = icat(yystack.l_mark[-2].c, icat(yystack.l_mark[0].c, e_simple(ADD))); }
break;
case 63:
#line 284 "parser.y"
	{ yyval.c = icat(yystack.l_mark[-2].c, icat(yystack.l_mark[0].c, e_simple(SUB))); }
break;
case 64:
#line 285 "parser.y"
	{ yyval.c = icat(yystack.l_mark[-2].c, icat(yystack.l_mark[0].c, e_simple(MUL))); }
break;
case 65:
#line 286 "parser.y"
	{ yyval.c = icat(yystack.l_mark[-2].c, icat(yystack.l_mark[0].c, e_simple(DIV))); }
break;
case 66:
#line 287 "parser.y"
	{ yyval.c = icat(yystack.l_mark[-2].c, icat(yystack.l_mark[0].c, e_simple(MOD))); }
break;
case 67:
#line 288 "parser.y"
	{ yyval.c = icat(yystack.l_mark[-2].c, icat(yystack.l_mark[0].c, e_simple(RANDOM))); }
break;
case 68:
#line 289 "parser.y"
	{ yyval.c = icat(yystack.l_mark[-2].c, icat(yystack.l_mark[0].c, e_simple(LESSER))); }
break;
case 69:
#line 290 "parser.y"
	{ yyval.c = icat(yystack.l_mark[-2].c, icat(yystack.l_mark[0].c, e_simple(GREATER))); }
break;
#line 1022 "y.tab.c"
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
        if (yychar < 0)
        {
            if ((yychar = YYLEX) < 0) yychar = 0;
#if YYDEBUG
            if (yydebug)
            {
                yys = 0;
                if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
                if (!yys) yys = "illegal-symbol";
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == 0) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yystack.s_mark, yystate);
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
    {
        goto yyoverflow;
    }
    *++yystack.s_mark = (short) yystate;
    *++yystack.l_mark = yyval;
    goto yyloop;

yyoverflow:
    yyerror("yacc stack overflow");

yyabort:
    yyfreestack(&yystack);
    return (1);

yyaccept:
    yyfreestack(&yystack);
    return (0);
}
