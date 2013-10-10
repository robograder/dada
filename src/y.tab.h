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
extern YYSTYPE yylval;
