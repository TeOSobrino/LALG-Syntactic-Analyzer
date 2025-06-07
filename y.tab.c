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
#line 1 "parser.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern int yylex();
extern int yylineno;
extern char *yytext;

// Nó da ASA
typedef struct ASTNode {
    char *type;
    char *value;
    struct ASTNode **children;
    int child_count;
    int child_capacity;
} ASTNode;

// Protótipo das Funções
void print_usage(void);
void print_options(void);
void print_invalid(char** argv, int arg_num);
ASTNode* create_node(const char* type, const char* value);
void add_child(ASTNode* parent, ASTNode* child);
void print_ast(ASTNode* node, int indent, FILE* output);
void free_ast(ASTNode* node);

void yyerror(const char *msg) {
    fprintf(stderr, "\nErro de sintaxe na linha %d próximo a '%s':\n", yylineno, yytext);
}

ASTNode* root = NULL;

#line 105 "y.tab.c"

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

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    NUM_INT = 258,                 /* NUM_INT  */
    NUM_REAL = 259,                /* NUM_REAL  */
    IDENT = 260,                   /* IDENT  */
    PROGRAM = 261,                 /* PROGRAM  */
    BEGIN_BLOCK = 262,             /* BEGIN_BLOCK  */
    END = 263,                     /* END  */
    CONST = 264,                   /* CONST  */
    VAR = 265,                     /* VAR  */
    PROCEDURE = 266,               /* PROCEDURE  */
    IF = 267,                      /* IF  */
    THEN = 268,                    /* THEN  */
    ELSE = 269,                    /* ELSE  */
    WHILE = 270,                   /* WHILE  */
    DO = 271,                      /* DO  */
    READ = 272,                    /* READ  */
    WRITE = 273,                   /* WRITE  */
    FOR = 274,                     /* FOR  */
    TO = 275,                      /* TO  */
    ASSIGN = 276,                  /* ASSIGN  */
    INTEGER = 277,                 /* INTEGER  */
    REAL = 278,                    /* REAL  */
    NE = 279,                      /* NE  */
    GE = 280,                      /* GE  */
    LE = 281,                      /* LE  */
    LOWER_THAN_ELSE = 282          /* LOWER_THAN_ELSE  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define NUM_INT 258
#define NUM_REAL 259
#define IDENT 260
#define PROGRAM 261
#define BEGIN_BLOCK 262
#define END 263
#define CONST 264
#define VAR 265
#define PROCEDURE 266
#define IF 267
#define THEN 268
#define ELSE 269
#define WHILE 270
#define DO 271
#define READ 272
#define WRITE 273
#define FOR 274
#define TO 275
#define ASSIGN 276
#define INTEGER 277
#define REAL 278
#define NE 279
#define GE 280
#define LE 281
#define LOWER_THAN_ELSE 282

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 35 "parser.y"

    int ival;
    float fval;
    char *sval;
    struct ASTNode *node;

#line 219 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_NUM_INT = 3,                    /* NUM_INT  */
  YYSYMBOL_NUM_REAL = 4,                   /* NUM_REAL  */
  YYSYMBOL_IDENT = 5,                      /* IDENT  */
  YYSYMBOL_PROGRAM = 6,                    /* PROGRAM  */
  YYSYMBOL_BEGIN_BLOCK = 7,                /* BEGIN_BLOCK  */
  YYSYMBOL_END = 8,                        /* END  */
  YYSYMBOL_CONST = 9,                      /* CONST  */
  YYSYMBOL_VAR = 10,                       /* VAR  */
  YYSYMBOL_PROCEDURE = 11,                 /* PROCEDURE  */
  YYSYMBOL_IF = 12,                        /* IF  */
  YYSYMBOL_THEN = 13,                      /* THEN  */
  YYSYMBOL_ELSE = 14,                      /* ELSE  */
  YYSYMBOL_WHILE = 15,                     /* WHILE  */
  YYSYMBOL_DO = 16,                        /* DO  */
  YYSYMBOL_READ = 17,                      /* READ  */
  YYSYMBOL_WRITE = 18,                     /* WRITE  */
  YYSYMBOL_FOR = 19,                       /* FOR  */
  YYSYMBOL_TO = 20,                        /* TO  */
  YYSYMBOL_ASSIGN = 21,                    /* ASSIGN  */
  YYSYMBOL_INTEGER = 22,                   /* INTEGER  */
  YYSYMBOL_REAL = 23,                      /* REAL  */
  YYSYMBOL_NE = 24,                        /* NE  */
  YYSYMBOL_GE = 25,                        /* GE  */
  YYSYMBOL_LE = 26,                        /* LE  */
  YYSYMBOL_LOWER_THAN_ELSE = 27,           /* LOWER_THAN_ELSE  */
  YYSYMBOL_28_ = 28,                       /* '+'  */
  YYSYMBOL_29_ = 29,                       /* '-'  */
  YYSYMBOL_30_ = 30,                       /* '*'  */
  YYSYMBOL_31_ = 31,                       /* '/'  */
  YYSYMBOL_32_ = 32,                       /* ';'  */
  YYSYMBOL_33_ = 33,                       /* '.'  */
  YYSYMBOL_34_ = 34,                       /* '='  */
  YYSYMBOL_35_ = 35,                       /* ':'  */
  YYSYMBOL_36_ = 36,                       /* ','  */
  YYSYMBOL_37_ = 37,                       /* '('  */
  YYSYMBOL_38_ = 38,                       /* ')'  */
  YYSYMBOL_39_ = 39,                       /* '>'  */
  YYSYMBOL_40_ = 40,                       /* '<'  */
  YYSYMBOL_YYACCEPT = 41,                  /* $accept  */
  YYSYMBOL_programa = 42,                  /* programa  */
  YYSYMBOL_corpo = 43,                     /* corpo  */
  YYSYMBOL_dc = 44,                        /* dc  */
  YYSYMBOL_dc_c = 45,                      /* dc_c  */
  YYSYMBOL_lista_const = 46,               /* lista_const  */
  YYSYMBOL_const_item = 47,                /* const_item  */
  YYSYMBOL_dc_v = 48,                      /* dc_v  */
  YYSYMBOL_lista_var = 49,                 /* lista_var  */
  YYSYMBOL_var_item = 50,                  /* var_item  */
  YYSYMBOL_tipo_var = 51,                  /* tipo_var  */
  YYSYMBOL_variaveis = 52,                 /* variaveis  */
  YYSYMBOL_mais_var = 53,                  /* mais_var  */
  YYSYMBOL_dc_p = 54,                      /* dc_p  */
  YYSYMBOL_proc_decl = 55,                 /* proc_decl  */
  YYSYMBOL_parametros = 56,                /* parametros  */
  YYSYMBOL_lista_par = 57,                 /* lista_par  */
  YYSYMBOL_mais_par = 58,                  /* mais_par  */
  YYSYMBOL_corpo_p = 59,                   /* corpo_p  */
  YYSYMBOL_dc_loc = 60,                    /* dc_loc  */
  YYSYMBOL_lista_arg = 61,                 /* lista_arg  */
  YYSYMBOL_argumentos = 62,                /* argumentos  */
  YYSYMBOL_mais_ident = 63,                /* mais_ident  */
  YYSYMBOL_comandos = 64,                  /* comandos  */
  YYSYMBOL_comando_lista = 65,             /* comando_lista  */
  YYSYMBOL_write_list = 66,                /* write_list  */
  YYSYMBOL_write_item = 67,                /* write_item  */
  YYSYMBOL_comando = 68,                   /* comando  */
  YYSYMBOL_condicao = 69,                  /* condicao  */
  YYSYMBOL_relacao = 70,                   /* relacao  */
  YYSYMBOL_expressao = 71,                 /* expressao  */
  YYSYMBOL_outros_termos = 72,             /* outros_termos  */
  YYSYMBOL_op_ad = 73,                     /* op_ad  */
  YYSYMBOL_termo = 74,                     /* termo  */
  YYSYMBOL_op_un = 75,                     /* op_un  */
  YYSYMBOL_mais_fatores = 76,              /* mais_fatores  */
  YYSYMBOL_op_mul = 77,                    /* op_mul  */
  YYSYMBOL_fator = 78,                     /* fator  */
  YYSYMBOL_numero = 79                     /* numero  */
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
typedef yytype_uint8 yy_state_t;

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
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   195

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  41
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  39
/* YYNRULES -- Number of rules.  */
#define YYNRULES  88
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  163

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   282


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
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      37,    38,    30,    28,    36,    29,    33,    31,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    35,    32,
      40,    34,    39,     2,     2,     2,     2,     2,     2,     2,
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
      25,    26,    27
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    63,    63,    71,    79,    87,    96,   100,   104,   109,
     112,   117,   125,   129,   138,   148,   152,   157,   160,   165,
     173,   181,   182,   186,   190,   198,   201,   205,   209,   214,
     219,   223,   231,   235,   239,   247,   251,   254,   258,   266,
     270,   274,   278,   285,   288,   292,   293,   297,   302,   305,
     312,   320,   326,   329,   335,   339,   343,   348,   358,   363,
     367,   371,   377,   383,   391,   399,   400,   401,   402,   403,
     404,   408,   419,   428,   432,   433,   437,   452,   453,   454,
     458,   467,   471,   472,   476,   479,   482,   488,   493
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
  "\"end of file\"", "error", "\"invalid token\"", "NUM_INT", "NUM_REAL",
  "IDENT", "PROGRAM", "BEGIN_BLOCK", "END", "CONST", "VAR", "PROCEDURE",
  "IF", "THEN", "ELSE", "WHILE", "DO", "READ", "WRITE", "FOR", "TO",
  "ASSIGN", "INTEGER", "REAL", "NE", "GE", "LE", "LOWER_THAN_ELSE", "'+'",
  "'-'", "'*'", "'/'", "';'", "'.'", "'='", "':'", "','", "'('", "')'",
  "'>'", "'<'", "$accept", "programa", "corpo", "dc", "dc_c",
  "lista_const", "const_item", "dc_v", "lista_var", "var_item", "tipo_var",
  "variaveis", "mais_var", "dc_p", "proc_decl", "parametros", "lista_par",
  "mais_par", "corpo_p", "dc_loc", "lista_arg", "argumentos", "mais_ident",
  "comandos", "comando_lista", "write_list", "write_item", "comando",
  "condicao", "relacao", "expressao", "outros_termos", "op_ad", "termo",
  "op_un", "mais_fatores", "op_mul", "fator", "numero", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-80)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-80)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      29,     0,    47,    61,   -80,    38,   -80,    68,     8,    56,
      84,    95,    62,     4,   -80,    64,   -80,    66,    48,    16,
      55,    76,    76,   105,    99,    -5,    66,    59,    80,    90,
      97,   131,   133,   -80,    18,     7,   115,    95,   124,   118,
     127,   159,   -80,    16,   -80,   -80,   -80,   -80,   -80,   -80,
     -80,    59,   160,   -80,   158,   -80,   -80,   154,   121,    70,
      21,    59,    50,    17,   148,   -80,    85,   106,    50,   128,
     -80,    63,   -80,   -80,   147,    86,    16,   134,   -80,   -80,
     136,   132,   -80,   125,   -80,   -80,   -80,   -80,   -80,   -80,
      59,   -80,   -80,   -80,    59,   -80,    59,    89,   -80,   135,
     137,   -80,   138,   -80,   -80,    59,   -80,   -80,   -80,     5,
     -80,   -80,   -80,   -80,   -80,   -80,     6,   140,   160,   -80,
     -80,   163,   -80,    70,   142,   -80,   -80,   -80,    21,   162,
     -80,   -80,   161,   -80,   139,   144,    95,   -80,   125,   -80,
     -80,    89,   125,    59,    86,   -80,   -80,   -80,   172,   -80,
     -80,   -80,   167,   152,    66,   125,     6,   -80,   177,   -80,
     -80,   155,   -80
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     3,     0,     1,     7,     0,     0,
       0,    15,     0,     0,     6,     0,     2,     0,     0,     0,
       0,     0,     0,     0,     0,    41,     0,    79,     0,     0,
       0,     0,     0,    45,     0,     0,    27,    15,     0,     0,
       0,     0,     5,     0,    10,    87,    88,    13,    12,     8,
      63,    79,     0,    60,     0,    77,    78,     0,     0,    73,
       0,    79,     0,     0,     0,     4,     0,     0,     0,     0,
      24,     0,    23,    14,     0,     0,     0,    33,    28,    59,
      44,     0,    61,     0,    66,    67,    68,    65,    69,    70,
      79,    74,    75,    71,    79,    84,    79,    81,    85,     0,
       0,    52,     0,    51,    53,    79,    49,    47,    18,     0,
      25,    16,    22,    21,    20,    29,     0,     0,     0,    42,
      40,    58,    64,    73,     0,    82,    83,    76,     0,     0,
      54,    55,     0,    26,     0,     0,    15,    43,     0,    72,
      86,    81,     0,    79,     0,    32,    39,    31,     0,    57,
      80,    56,     0,    37,     0,     0,     0,    34,     0,    62,
      36,     0,    38
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -80,   -80,   -80,   -80,   -80,    49,   -80,   -35,   -38,   -80,
      42,   -34,    79,   -29,   -80,   -80,    33,   -80,   -80,   -80,
     -80,    72,   -80,   -26,    83,   -80,   -80,   -79,   130,   -80,
     -48,    69,   -80,   100,   -80,    52,   -80,    67,   141
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     3,     9,    10,    11,    14,    15,    19,    37,    38,
     114,    39,    72,    42,    43,   117,   135,   157,   147,   148,
      53,    81,   119,    32,    33,   102,   103,    34,    57,    90,
      58,    93,    94,    59,    60,   127,   128,    97,    98
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      54,    70,    73,    79,   121,    21,    68,    68,    68,    12,
      36,    36,    36,    13,    78,   104,    51,    40,    68,    66,
     -79,   -79,    36,   -30,    45,    46,    95,    41,   100,   101,
       1,   108,    52,     4,    70,     2,   111,   110,    22,    69,
     -27,    71,   122,   -27,   -35,    55,    56,   115,   124,    35,
      67,    68,     5,    36,   -79,    36,    12,   132,    96,   149,
      13,     6,   -11,   151,   109,   -11,   -11,    24,    36,    44,
       7,    25,    49,    26,   -46,    70,   159,     8,    27,    45,
      46,    28,   134,    29,    30,    31,    24,    55,    56,    16,
      25,    17,    26,   -50,    20,   152,    23,    27,    91,    92,
      28,   146,    29,    30,    31,    18,    12,    24,   112,   113,
      13,    25,    -9,    26,   -48,    -9,    -9,    61,    27,   125,
     126,    28,   134,    29,    30,    31,    24,    62,   158,    35,
      25,    50,    26,    36,    63,   -19,    64,    27,   -19,   -19,
      28,    65,    29,    30,    31,    84,    85,    86,    35,   106,
     107,    71,    36,    75,   -17,    87,    74,   -17,   -17,    76,
      88,    89,    47,    48,    77,    80,    82,    83,   118,   105,
     120,   116,   136,   129,   144,   130,   131,   138,   142,   154,
     140,   143,   145,   155,   156,   161,   153,   162,   133,   160,
     137,    99,   139,   150,   123,   141
};

static const yytype_uint8 yycheck[] =
{
      26,    35,    37,    51,    83,     1,     1,     1,     1,     1,
       5,     5,     5,     5,    43,    63,    21,     1,     1,     1,
       3,     4,     5,     7,     3,     4,     5,    11,    62,    63,
       1,    69,    37,    33,    68,     6,    74,    71,    34,    32,
      35,    36,    90,    38,    38,    28,    29,    76,    96,     1,
      32,     1,     5,     5,    37,     5,     1,   105,    37,   138,
       5,     0,     7,   142,     1,    10,    11,     1,     5,    20,
      32,     5,    23,     7,     8,   109,   155,     9,    12,     3,
       4,    15,   116,    17,    18,    19,     1,    28,    29,    33,
       5,     7,     7,     8,    32,   143,    32,    12,    28,    29,
      15,   136,    17,    18,    19,    10,     1,     1,    22,    23,
       5,     5,     7,     7,     8,    10,    11,    37,    12,    30,
      31,    15,   156,    17,    18,    19,     1,    37,   154,     1,
       5,    32,     7,     5,    37,     7,     5,    12,    10,    11,
      15,     8,    17,    18,    19,    24,    25,    26,     1,    66,
      67,    36,     5,    35,     7,    34,    32,    10,    11,    32,
      39,    40,    21,    22,     5,     5,     8,    13,    32,    21,
      38,    37,    32,    38,    35,    38,    38,    14,    16,     7,
      38,    20,    38,    16,    32,     8,   144,    32,   109,   156,
     118,    61,   123,   141,    94,   128
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,     6,    42,    33,     5,     0,    32,     9,    43,
      44,    45,     1,     5,    46,    47,    33,     7,    10,    48,
      32,     1,    34,    32,     1,     5,     7,    12,    15,    17,
      18,    19,    64,    65,    68,     1,     5,    49,    50,    52,
       1,    11,    54,    55,    46,     3,     4,    79,    79,    46,
      32,    21,    37,    61,    64,    28,    29,    69,    71,    74,
      75,    37,    37,    37,     5,     8,     1,    32,     1,    32,
      52,    36,    53,    48,    32,    35,    32,     5,    54,    71,
       5,    62,     8,    13,    24,    25,    26,    34,    39,    40,
      70,    28,    29,    72,    73,     5,    37,    78,    79,    69,
      52,    52,    66,    67,    71,    21,    65,    65,    49,     1,
      52,    49,    22,    23,    51,    54,    37,    56,    32,    63,
      38,    68,    71,    74,    71,    30,    31,    76,    77,    38,
      38,    38,    71,    53,    52,    57,    32,    62,    14,    72,
      38,    78,    16,    20,    35,    38,    48,    59,    60,    68,
      76,    68,    71,    51,     7,    16,    32,    58,    64,    68,
      57,     8,    32
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    41,    42,    42,    43,    44,    45,    45,    46,    46,
      46,    46,    47,    47,    48,    48,    49,    49,    49,    49,
      50,    51,    51,    52,    52,    53,    53,    53,    54,    54,
      54,    55,    56,    56,    57,    57,    58,    58,    59,    60,
      61,    61,    62,    63,    63,    64,    64,    65,    65,    65,
      65,    66,    67,    67,    68,    68,    68,    68,    68,    68,
      68,    68,    68,    68,    69,    70,    70,    70,    70,    70,
      70,    71,    72,    72,    73,    73,    74,    75,    75,    75,
      76,    76,    77,    77,    78,    78,    78,    79,    79
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     5,     2,     4,     3,     2,     0,     3,     2,
       3,     2,     3,     3,     3,     0,     3,     2,     3,     2,
       3,     1,     1,     2,     2,     2,     3,     0,     2,     3,
       0,     5,     3,     0,     4,     0,     2,     0,     5,     1,
       3,     0,     2,     2,     0,     1,     0,     3,     2,     3,
       2,     1,     1,     1,     4,     4,     6,     6,     4,     3,
       2,     3,     8,     2,     3,     1,     1,     1,     1,     1,
       1,     2,     3,     0,     1,     1,     3,     1,     1,     0,
       3,     0,     1,     1,     1,     1,     3,     1,     1
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
  case 2: /* programa: PROGRAM IDENT ';' corpo '.'  */
#line 63 "parser.y"
                                {
        (yyval.node) = create_node("PROGRAMA", (yyvsp[-3].sval));
        add_child((yyval.node), (yyvsp[-1].node));
        root = (yyval.node);
        ASTNode* no_fim = create_node("FIM_PROGRAMA", NULL);
        add_child((yyval.node), no_fim); // coloca o nó fim como filho do início
        printf("Análise sintática concluída com sucesso.\n");
    }
#line 1399 "y.tab.c"
    break;

  case 3: /* programa: error '.'  */
#line 71 "parser.y"
                {
        fprintf(stderr,"\tErro na inicialização do programa. Linha %d : Erro de sintaxe.\n", yylineno);
        yyerrok;
        (yyval.node) = create_node("ERROR_PROGRAM", NULL);
    }
#line 1409 "y.tab.c"
    break;

  case 4: /* corpo: dc BEGIN_BLOCK comandos END  */
#line 79 "parser.y"
                                {
        (yyval.node) = create_node("CORPO", NULL);
        add_child((yyval.node), (yyvsp[-3].node));
        add_child((yyval.node), (yyvsp[-1].node));
    }
#line 1419 "y.tab.c"
    break;

  case 5: /* dc: dc_c dc_v dc_p  */
#line 87 "parser.y"
                   {
        (yyval.node) = create_node("DECLARAÇÕES", NULL);
        if ((yyvsp[-2].node)) add_child((yyval.node), (yyvsp[-2].node));
        if ((yyvsp[-1].node)) add_child((yyval.node), (yyvsp[-1].node));
        if ((yyvsp[0].node)) add_child((yyval.node), (yyvsp[0].node));
    }
#line 1430 "y.tab.c"
    break;

  case 6: /* dc_c: CONST lista_const  */
#line 96 "parser.y"
                      {
        (yyval.node) = create_node("DECL_CONST", NULL);
        add_child((yyval.node), (yyvsp[0].node));
    }
#line 1439 "y.tab.c"
    break;

  case 7: /* dc_c: %empty  */
#line 100 "parser.y"
                  { (yyval.node) = NULL; }
#line 1445 "y.tab.c"
    break;

  case 8: /* lista_const: const_item ';' lista_const  */
#line 104 "parser.y"
                               {
        (yyval.node) = create_node("CONST_LIST", NULL);
        add_child((yyval.node), (yyvsp[-2].node));
        if ((yyvsp[0].node)) add_child((yyval.node), (yyvsp[0].node));
    }
#line 1455 "y.tab.c"
    break;

  case 9: /* lista_const: const_item ';'  */
#line 109 "parser.y"
                     {
        (yyval.node) = (yyvsp[-1].node);
    }
#line 1463 "y.tab.c"
    break;

  case 10: /* lista_const: error ';' lista_const  */
#line 112 "parser.y"
                            {
        fprintf(stderr, "\tErro em declaração de constante. Linha %d : Erro de sintaxe.\n", yylineno);
        yyerrok;
        (yyval.node) = (yyvsp[0].node);
    }
#line 1473 "y.tab.c"
    break;

  case 11: /* lista_const: error ';'  */
#line 117 "parser.y"
                {
        fprintf(stderr, "\tErro em declaração de constante. Linha %d : Erro de sintaxe.\n", yylineno);
        yyerrok;
        (yyval.node) = NULL;
    }
#line 1483 "y.tab.c"
    break;

  case 12: /* const_item: IDENT '=' numero  */
#line 125 "parser.y"
                     {
        (yyval.node) = create_node("CONST_ASSIGN", (yyvsp[-2].sval));
        add_child((yyval.node), (yyvsp[0].node));
    }
#line 1492 "y.tab.c"
    break;

  case 13: /* const_item: IDENT error numero  */
#line 129 "parser.y"
                         {
        fprintf(stderr, "\tErro na atribuição de constante: esperado '='. Linha %d : Erro de sintaxe.\n", yylineno);
        yyerrok;
        (yyval.node) = create_node("CONST_ASSIGN", (yyvsp[-2].sval));
        add_child((yyval.node), (yyvsp[0].node));
    }
#line 1503 "y.tab.c"
    break;

  case 14: /* dc_v: VAR lista_var dc_v  */
#line 138 "parser.y"
                       {
        if ((yyvsp[0].node)) {
            (yyval.node) = create_node("DECLARAÇÃO_VARS", NULL);
            add_child((yyval.node), (yyvsp[-1].node));
            add_child((yyval.node), (yyvsp[0].node));
        } else {
            (yyval.node) = create_node("DECLARAÇÃO_VARS", NULL);
            add_child((yyval.node), (yyvsp[-1].node));
        }
    }
#line 1518 "y.tab.c"
    break;

  case 15: /* dc_v: %empty  */
#line 148 "parser.y"
                  { (yyval.node) = NULL; }
#line 1524 "y.tab.c"
    break;

  case 16: /* lista_var: var_item ';' lista_var  */
#line 152 "parser.y"
                           {
        (yyval.node) = create_node("LISTA_VAR", NULL);
        add_child((yyval.node), (yyvsp[-2].node));
        if ((yyvsp[0].node)) add_child((yyval.node), (yyvsp[0].node));
    }
#line 1534 "y.tab.c"
    break;

  case 17: /* lista_var: var_item ';'  */
#line 157 "parser.y"
                   {
        (yyval.node) = (yyvsp[-1].node);
    }
#line 1542 "y.tab.c"
    break;

  case 18: /* lista_var: error ';' lista_var  */
#line 160 "parser.y"
                          {
        fprintf(stderr, "\tErro em declaração de variável. Linha %d : Erro de sintaxe.\n", yylineno);
        yyerrok;
        (yyval.node) = (yyvsp[0].node);
    }
#line 1552 "y.tab.c"
    break;

  case 19: /* lista_var: error ';'  */
#line 165 "parser.y"
                {
        fprintf(stderr, "\tErro em declaração de variável. Linha %d : Erro de sintaxe.\n", yylineno);
        yyerrok;
        (yyval.node) = NULL;
    }
#line 1562 "y.tab.c"
    break;

  case 20: /* var_item: variaveis ':' tipo_var  */
#line 173 "parser.y"
                           {
        (yyval.node) = create_node("LISTA_VARS", NULL);
        add_child((yyval.node), (yyvsp[-2].node));
        add_child((yyval.node), (yyvsp[0].node));
    }
#line 1572 "y.tab.c"
    break;

  case 21: /* tipo_var: REAL  */
#line 181 "parser.y"
         { (yyval.node) = create_node("TIPO", "real"); }
#line 1578 "y.tab.c"
    break;

  case 22: /* tipo_var: INTEGER  */
#line 182 "parser.y"
              { (yyval.node) = create_node("TIPO", "integer"); }
#line 1584 "y.tab.c"
    break;

  case 23: /* variaveis: IDENT mais_var  */
#line 186 "parser.y"
                   {
        (yyval.node) = create_node("VARIÁVEL", (yyvsp[-1].sval));
        if ((yyvsp[0].node)) add_child((yyval.node), (yyvsp[0].node));
    }
#line 1593 "y.tab.c"
    break;

  case 24: /* variaveis: error variaveis  */
#line 190 "parser.y"
                      { // Recuperação para token inválido depois de comando
        fprintf(stderr, "\tErro em declaração de variável: esperado IDENT. Linha %d : Erro de sintaxe.\n", yylineno);
        yyerrok; 
        (yyval.node) = (yyvsp[0].node);
    }
#line 1603 "y.tab.c"
    break;

  case 25: /* mais_var: ',' variaveis  */
#line 198 "parser.y"
                  {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1611 "y.tab.c"
    break;

  case 26: /* mais_var: ',' error mais_var  */
#line 201 "parser.y"
                         { // Recuperação de erro: identificador inválido depois de ','
        fprintf(stderr, "\tErro em declaração de variável: esperado IDENT após ','. Linha %d : Erro de sintaxe.\n", yylineno);
        yyerrok; 
    }
#line 1620 "y.tab.c"
    break;

  case 27: /* mais_var: %empty  */
#line 205 "parser.y"
                  { (yyval.node) = NULL; }
#line 1626 "y.tab.c"
    break;

  case 28: /* dc_p: proc_decl dc_p  */
#line 209 "parser.y"
                   {
        (yyval.node) = create_node("PROC_LIST", NULL);
        add_child((yyval.node), (yyvsp[-1].node));
        if ((yyvsp[0].node)) add_child((yyval.node), (yyvsp[0].node));
    }
#line 1636 "y.tab.c"
    break;

  case 29: /* dc_p: error ';' dc_p  */
#line 214 "parser.y"
                     {
        fprintf(stderr, "\tErro em declaração de procedimento. Tentando recuperar. Linha %d : Erro de sintaxe.\n", yylineno);
        yyerrok;
        (yyval.node) = (yyvsp[0].node);
    }
#line 1646 "y.tab.c"
    break;

  case 30: /* dc_p: %empty  */
#line 219 "parser.y"
                  { (yyval.node) = NULL; }
#line 1652 "y.tab.c"
    break;

  case 31: /* proc_decl: PROCEDURE IDENT parametros ';' corpo_p  */
#line 223 "parser.y"
                                           {
        (yyval.node) = create_node("PROCEDURE", (yyvsp[-3].sval));
        if ((yyvsp[-2].node)) add_child((yyval.node), (yyvsp[-2].node));
        add_child((yyval.node), (yyvsp[0].node));
    }
#line 1662 "y.tab.c"
    break;

  case 32: /* parametros: '(' lista_par ')'  */
#line 231 "parser.y"
                      {
        (yyval.node) = create_node("PARAMETERS", NULL);
        if ((yyvsp[-1].node)) add_child((yyval.node), (yyvsp[-1].node));
    }
#line 1671 "y.tab.c"
    break;

  case 33: /* parametros: %empty  */
#line 235 "parser.y"
                  { (yyval.node) = NULL; }
#line 1677 "y.tab.c"
    break;

  case 34: /* lista_par: variaveis ':' tipo_var mais_par  */
#line 239 "parser.y"
                                    {
        (yyval.node) = create_node("PARAM_LIST", NULL);
        ASTNode* param = create_node("PARAMETER", NULL);
        add_child(param, (yyvsp[-3].node));
        add_child(param, (yyvsp[-1].node));
        add_child((yyval.node), param);
        if ((yyvsp[0].node)) add_child((yyval.node), (yyvsp[0].node));
    }
#line 1690 "y.tab.c"
    break;

  case 35: /* lista_par: %empty  */
#line 247 "parser.y"
                  { (yyval.node) = NULL; }
#line 1696 "y.tab.c"
    break;

  case 36: /* mais_par: ';' lista_par  */
#line 251 "parser.y"
                  {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1704 "y.tab.c"
    break;

  case 37: /* mais_par: %empty  */
#line 254 "parser.y"
                  { (yyval.node) = NULL; }
#line 1710 "y.tab.c"
    break;

  case 38: /* corpo_p: dc_loc BEGIN_BLOCK comandos END ';'  */
#line 258 "parser.y"
                                        {
        (yyval.node) = create_node("CORPO_BLOCO", NULL);
        if ((yyvsp[-4].node)) add_child((yyval.node), (yyvsp[-4].node));
        add_child((yyval.node), (yyvsp[-2].node));
    }
#line 1720 "y.tab.c"
    break;

  case 39: /* dc_loc: dc_v  */
#line 266 "parser.y"
         { (yyval.node) = (yyvsp[0].node); }
#line 1726 "y.tab.c"
    break;

  case 40: /* lista_arg: '(' argumentos ')'  */
#line 270 "parser.y"
                       {
        (yyval.node) = create_node("ARGUMENTS", NULL);
        if ((yyvsp[-1].node)) add_child((yyval.node), (yyvsp[-1].node));
    }
#line 1735 "y.tab.c"
    break;

  case 41: /* lista_arg: %empty  */
#line 274 "parser.y"
                  { (yyval.node) = NULL; }
#line 1741 "y.tab.c"
    break;

  case 42: /* argumentos: IDENT mais_ident  */
#line 278 "parser.y"
                     {
        (yyval.node) = create_node("ARG_LIST", (yyvsp[-1].sval));
        if ((yyvsp[0].node)) add_child((yyval.node), (yyvsp[0].node));
    }
#line 1750 "y.tab.c"
    break;

  case 43: /* mais_ident: ';' argumentos  */
#line 285 "parser.y"
                   {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1758 "y.tab.c"
    break;

  case 44: /* mais_ident: %empty  */
#line 288 "parser.y"
                  { (yyval.node) = NULL; }
#line 1764 "y.tab.c"
    break;

  case 45: /* comandos: comando_lista  */
#line 292 "parser.y"
                  { (yyval.node) = (yyvsp[0].node); }
#line 1770 "y.tab.c"
    break;

  case 46: /* comandos: %empty  */
#line 293 "parser.y"
                  { (yyval.node) = NULL; }
#line 1776 "y.tab.c"
    break;

  case 47: /* comando_lista: comando ';' comando_lista  */
#line 297 "parser.y"
                              { // Exige ; entre comandos
        (yyval.node) = create_node("LISTA_CMDS", NULL);
        add_child((yyval.node), (yyvsp[-2].node));
        if ((yyvsp[0].node)) add_child((yyval.node), (yyvsp[0].node));
    }
#line 1786 "y.tab.c"
    break;

  case 48: /* comando_lista: comando ';'  */
#line 302 "parser.y"
                  { // Ultimo comando com ;
        (yyval.node) = (yyvsp[-1].node);
    }
#line 1794 "y.tab.c"
    break;

  case 49: /* comando_lista: comando error comando_lista  */
#line 305 "parser.y"
                                  { // Erro: falta ;
        fprintf(stderr, "\tErro de terminação: esperado ';' após comando. Linha %d : Erro de sintaxe.\n", yylineno);
        yyerrok; // Descarta um token inválido e tenta recuperar
        (yyval.node) = create_node("LISTA_CMDS", NULL);
        add_child((yyval.node), (yyvsp[-2].node)); // Adiciona o comando que está sendo parseado
        if ((yyvsp[0].node)) add_child((yyval.node), (yyvsp[0].node)); // Adiciona o resto da lista
    }
#line 1806 "y.tab.c"
    break;

  case 50: /* comando_lista: comando error  */
#line 312 "parser.y"
                    { // Erro: falta ;
        fprintf(stderr, "\tErro de terminação: esperado ';' após comando. Linha %d : Erro de sintaxe.\n", yylineno);
        yyerrok;
        (yyval.node) = (yyvsp[-1].node);
    }
#line 1816 "y.tab.c"
    break;

  case 51: /* write_list: write_item  */
#line 320 "parser.y"
               {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1824 "y.tab.c"
    break;

  case 52: /* write_item: variaveis  */
#line 326 "parser.y"
              {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1832 "y.tab.c"
    break;

  case 53: /* write_item: expressao  */
#line 329 "parser.y"
                {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1840 "y.tab.c"
    break;

  case 54: /* comando: READ '(' variaveis ')'  */
#line 335 "parser.y"
                           {
        (yyval.node) = create_node("read", NULL);
        add_child((yyval.node), (yyvsp[-1].node));
    }
#line 1849 "y.tab.c"
    break;

  case 55: /* comando: WRITE '(' write_list ')'  */
#line 339 "parser.y"
                               {
        (yyval.node) = create_node("write", NULL);
        add_child((yyval.node), (yyvsp[-1].node));
    }
#line 1858 "y.tab.c"
    break;

  case 56: /* comando: WHILE '(' condicao ')' DO comando  */
#line 343 "parser.y"
                                        {
        (yyval.node) = create_node("while", NULL);
        add_child((yyval.node), (yyvsp[-3].node));
        add_child((yyval.node), (yyvsp[0].node));
    }
#line 1868 "y.tab.c"
    break;

  case 57: /* comando: IF condicao THEN comando ELSE comando  */
#line 348 "parser.y"
                                            {
        (yyval.node) = create_node("if", NULL);
        add_child((yyval.node), (yyvsp[-4].node)); // Condição
        add_child((yyval.node), (yyvsp[-2].node)); // bloco após o then

        // nó de else
        ASTNode* else_node = create_node("else", NULL);
        add_child(else_node, (yyvsp[0].node)); // boloco após o else
        add_child((yyval.node), else_node); // coloca o nó else como filho do nó if
    }
#line 1883 "y.tab.c"
    break;

  case 58: /* comando: IF condicao THEN comando  */
#line 358 "parser.y"
                                                     {
        (yyval.node) = create_node("if", NULL);
        add_child((yyval.node), (yyvsp[-2].node));
        add_child((yyval.node), (yyvsp[0].node));
    }
#line 1893 "y.tab.c"
    break;

  case 59: /* comando: IDENT ASSIGN expressao  */
#line 363 "parser.y"
                             {
        (yyval.node) = create_node("assign", (yyvsp[-2].sval));
        add_child((yyval.node), (yyvsp[0].node));
    }
#line 1902 "y.tab.c"
    break;

  case 60: /* comando: IDENT lista_arg  */
#line 367 "parser.y"
                      {
        (yyval.node) = create_node("call", (yyvsp[-1].sval));
        if ((yyvsp[0].node)) add_child((yyval.node), (yyvsp[0].node));
    }
#line 1911 "y.tab.c"
    break;

  case 61: /* comando: BEGIN_BLOCK comandos END  */
#line 371 "parser.y"
                               {
        (yyval.node) = create_node("bloco", NULL);
        if ((yyvsp[-1].node)) add_child((yyval.node), (yyvsp[-1].node));
        ASTNode* end_block_node = create_node("fim_bloco", NULL);
        add_child((yyval.node), end_block_node); 
    }
#line 1922 "y.tab.c"
    break;

  case 62: /* comando: FOR IDENT ASSIGN expressao TO expressao DO comando  */
#line 377 "parser.y"
                                                         {
        (yyval.node) = create_node("for", (yyvsp[-6].sval));
        add_child((yyval.node), (yyvsp[-4].node));
        add_child((yyval.node), (yyvsp[-2].node));
        add_child((yyval.node), (yyvsp[0].node));
    }
#line 1933 "y.tab.c"
    break;

  case 63: /* comando: error ';'  */
#line 383 "parser.y"
                {
        fprintf(stderr, "\tErro em comando. Linha %d : Erro de sintaxe.\n", yylineno); 
        yyerrok;
        (yyval.node) = create_node("ERROR_STMT", NULL);
    }
#line 1943 "y.tab.c"
    break;

  case 64: /* condicao: expressao relacao expressao  */
#line 391 "parser.y"
                                {
        (yyval.node) = (yyvsp[-1].node);
        add_child((yyval.node), (yyvsp[-2].node));
        add_child((yyval.node), (yyvsp[0].node));
    }
#line 1953 "y.tab.c"
    break;

  case 65: /* relacao: '='  */
#line 399 "parser.y"
        { (yyval.node) = create_node("=", NULL); }
#line 1959 "y.tab.c"
    break;

  case 66: /* relacao: NE  */
#line 400 "parser.y"
         { (yyval.node) = create_node("!=", NULL); }
#line 1965 "y.tab.c"
    break;

  case 67: /* relacao: GE  */
#line 401 "parser.y"
         { (yyval.node) = create_node(">=", NULL); }
#line 1971 "y.tab.c"
    break;

  case 68: /* relacao: LE  */
#line 402 "parser.y"
         { (yyval.node) = create_node("<=", NULL); }
#line 1977 "y.tab.c"
    break;

  case 69: /* relacao: '>'  */
#line 403 "parser.y"
          { (yyval.node) = create_node(">", NULL); }
#line 1983 "y.tab.c"
    break;

  case 70: /* relacao: '<'  */
#line 404 "parser.y"
          { (yyval.node) = create_node("<", NULL); }
#line 1989 "y.tab.c"
    break;

  case 71: /* expressao: termo outros_termos  */
#line 408 "parser.y"
                        {
        if ((yyvsp[0].node)) {
            add_child((yyvsp[0].node), (yyvsp[-1].node));
            (yyval.node) = (yyvsp[0].node);
        } else {
            (yyval.node) = (yyvsp[-1].node);
        }
    }
#line 2002 "y.tab.c"
    break;

  case 72: /* outros_termos: op_ad termo outros_termos  */
#line 419 "parser.y"
                              {
        add_child((yyvsp[-2].node), (yyvsp[-1].node));
        if ((yyvsp[0].node)) {
            add_child((yyvsp[0].node), (yyvsp[-2].node));
            (yyval.node) = (yyvsp[0].node);
        } else {
            (yyval.node) = (yyvsp[-2].node);
        }
    }
#line 2016 "y.tab.c"
    break;

  case 73: /* outros_termos: %empty  */
#line 428 "parser.y"
                  { (yyval.node) = NULL; }
#line 2022 "y.tab.c"
    break;

  case 74: /* op_ad: '+'  */
#line 432 "parser.y"
        { (yyval.node) = create_node("+", NULL); }
#line 2028 "y.tab.c"
    break;

  case 75: /* op_ad: '-'  */
#line 433 "parser.y"
          { (yyval.node) = create_node("-", NULL); }
#line 2034 "y.tab.c"
    break;

  case 76: /* termo: op_un fator mais_fatores  */
#line 437 "parser.y"
                             {
        ASTNode* result = (yyvsp[-1].node);
        if ((yyvsp[-2].node)) {
            add_child((yyvsp[-2].node), (yyvsp[-1].node));
            result = (yyvsp[-2].node);
        }
        if ((yyvsp[0].node)) {
            add_child((yyvsp[0].node), result);
            result = (yyvsp[0].node);
        }
        (yyval.node) = result;
    }
#line 2051 "y.tab.c"
    break;

  case 77: /* op_un: '+'  */
#line 452 "parser.y"
        { (yyval.node) = create_node("unary+", NULL); }
#line 2057 "y.tab.c"
    break;

  case 78: /* op_un: '-'  */
#line 453 "parser.y"
          { (yyval.node) = create_node("unary-", NULL); }
#line 2063 "y.tab.c"
    break;

  case 79: /* op_un: %empty  */
#line 454 "parser.y"
                  { (yyval.node) = NULL; }
#line 2069 "y.tab.c"
    break;

  case 80: /* mais_fatores: op_mul fator mais_fatores  */
#line 458 "parser.y"
                              {
        add_child((yyvsp[-2].node), (yyvsp[-1].node));
        if ((yyvsp[0].node)) {
            add_child((yyvsp[0].node), (yyvsp[-2].node));
            (yyval.node) = (yyvsp[0].node);
        } else {
            (yyval.node) = (yyvsp[-2].node);
        }
    }
#line 2083 "y.tab.c"
    break;

  case 81: /* mais_fatores: %empty  */
#line 467 "parser.y"
                  { (yyval.node) = NULL; }
#line 2089 "y.tab.c"
    break;

  case 82: /* op_mul: '*'  */
#line 471 "parser.y"
        { (yyval.node) = create_node("*", NULL); }
#line 2095 "y.tab.c"
    break;

  case 83: /* op_mul: '/'  */
#line 472 "parser.y"
          { (yyval.node) = create_node("/", NULL); }
#line 2101 "y.tab.c"
    break;

  case 84: /* fator: IDENT  */
#line 476 "parser.y"
          {
        (yyval.node) = create_node("identificador", (yyvsp[0].sval));
    }
#line 2109 "y.tab.c"
    break;

  case 85: /* fator: numero  */
#line 479 "parser.y"
             {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2117 "y.tab.c"
    break;

  case 86: /* fator: '(' expressao ')'  */
#line 482 "parser.y"
                        {
        (yyval.node) = (yyvsp[-1].node);
    }
#line 2125 "y.tab.c"
    break;

  case 87: /* numero: NUM_INT  */
#line 488 "parser.y"
            {
        char buffer[32];
        snprintf(buffer, sizeof(buffer), "%d", (yyvsp[0].ival));
        (yyval.node) = create_node("integer", buffer);
    }
#line 2135 "y.tab.c"
    break;

  case 88: /* numero: NUM_REAL  */
#line 493 "parser.y"
               {
        char buffer[32];
        snprintf(buffer, sizeof(buffer), "%.2f", (yyvsp[0].fval));
        (yyval.node) = create_node("real", buffer);
    }
#line 2145 "y.tab.c"
    break;


#line 2149 "y.tab.c"

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

#line 500 "parser.y"


// Implementação da árvore sintática abstrata
ASTNode* create_node(const char* type, const char* value) {
    ASTNode* node = malloc(sizeof(ASTNode));
    if (!node) {
        perror("Falha ao alocar memória para o nó da AST");
        exit(EXIT_FAILURE);
    }
    node->type = strdup(type);
    node->value = value ? strdup(value) : NULL;
    node->children = NULL;
    node->child_count = 0;
    node->child_capacity = 0;
    return node;
}

void add_child(ASTNode* parent, ASTNode* child) {
    if (!parent || !child) return;
    
    if (parent->child_count >= parent->child_capacity) {
        parent->child_capacity = parent->child_capacity == 0 ? 4 : parent->child_capacity * 2;
        parent->children = realloc(parent->children, parent->child_capacity * sizeof(ASTNode*));
        if (!parent->children) {
            perror("Falha ao realocar memória para os filhos do nó");
            exit(EXIT_FAILURE);
        }
    }
    
    parent->children[parent->child_count++] = child;
}

void print_ast(ASTNode* node, int indent, FILE* output) {
    if (!node) return;
    
    for (int i = 0; i < indent; i++) fprintf(output, "  ");
    fprintf(output, "%s", node->type);
    if (node->value) fprintf(output, ": %s", node->value);
    fprintf(output, "\n");
    
    for (int i = 0; i < node->child_count; i++) {
        print_ast(node->children[i], indent + 1, output);
    }
}

void free_ast(ASTNode* node) {
    if (!node) return;
    
    for (int i = 0; i < node->child_count; i++) {
        free_ast(node->children[i]);
    }
    
    free(node->type);
    free(node->value);
    free(node->children);
    free(node);
}

void print_usage(void)
{
  printf("lalgc: Compilador de Pascal Simplificado (LALG).\n\tElaborado por Téo Sobrino Alves & Miller Anacleto Rocha.\n\tDisciplina SCC0217 - Compiladores, 2025.\n\nModos de Uso:\n\t./lalgc <opções> <arquivo_lalg>\n\t\tExemplo simples: ./lalgc -i <arquivo_lalg>\nUse a opção -h para ver o menu completo de opções.\n\n");
}

void print_options(void)
{
    printf("Opções:\n\t-h, --help\t\tImprime este menu de ajuda e termina.\n");
    printf("\t-i, --input <arquivo> \tIdentifica o arquivo de entrada.\n");
    printf("\t-t --tree [arquivo] \tImprime a árvore sintática abstrata. Caso nenhum arquivo seja fornecido, imprime em stdout.\n\n");
}

void print_invalid(char** argv, int arg_num)
{
    printf("Opção '%s' inválida.\n\tAjuda: ./lalgc -h ou --help\n\tmodo de uso: ./lalgc -i nome_arquivo_lalg\n\n", argv[arg_num]);
}

FILE* parse_argv(char** argv, int argc, int arg_num, FILE* tester)
{
    if(arg_num > argc) return NULL;
    if(argv[arg_num][0] == '-'){
        if(argv[arg_num][1] == 'h' || (argv[arg_num][1] == '-' && argv[arg_num][2] == 'h')){ //Menu de ajuda
            print_usage();
            print_options();
            exit(0);
        }
        if(argv[arg_num][1] == 'i' || (argv[arg_num][1] == '-' && argv[arg_num][2] == 'i')){//entrada
            tester = fopen(argv[arg_num+1], "r");
            if(!tester){ 
            fprintf(stderr, "\tNão foi possível abrir o arquivo '%s'.\n", argv[arg_num+1]);
            exit(1);
            }
            return tester;
        }
        if(argv[arg_num][1] == 't' || (argv[arg_num][1] == '-' && argv[arg_num][2] == 't')){ //saída
            if (arg_num + 1 < argc && argv[arg_num+1][0] != '-') {
                 tester = fopen(argv[arg_num+1], "w+");
                 if(!tester){
                    fprintf(stderr, "\tNão foi possível abrir o arquivo de saída '%s'.\n", argv[arg_num+1]);
                    return stdout; // saída se torna stdout
                }
            } else {
                tester = stdout;
            }
            return tester;
        }     
        else{
            print_invalid(argv, arg_num);
            exit(1);
        }
    }
    else{
        print_invalid(argv, arg_num);
        exit(1);
    }
}

int main(int argc, char** argv) {

    FILE* input = NULL;
    FILE* output = NULL;
    FILE* tester;
    extern FILE* yyin;
    int arg_num = 1;

    if(argc < 2){
        print_usage();
        exit(1);
    }
    else{
        while(arg_num < argc){   
            if(argv[arg_num][0] == '-') {
                if(argv[arg_num][1] == 'i' || (argv[arg_num][1] == '-' && argv[arg_num][2]=='i')){
                    if(arg_num + 1 < argc) {
                        input = fopen(argv[arg_num+1], "r");
                        if(!input) {
                            fprintf(stderr, "\tNão foi possível abrir o arquivo de entrada '%s'.\n", argv[arg_num+1]);
                            exit(1);
                        }
                        arg_num += 2;
                    } else {
                        print_invalid(argv, arg_num);
                        exit(1);
                    }
                } 
                else if(argv[arg_num][1] == 't' || (argv[arg_num][1] == '-' && argv[arg_num][2]=='t')){
                    if(arg_num + 1 < argc && argv[arg_num+1][0] != '-') {
                        output = fopen(argv[arg_num+1], "w+");
                        if(!output) {
                            fprintf(stderr, "\tNão foi possível abrir o arquivo de saída '%s'. Usando stdout.\n", argv[arg_num+1]);
                            output = stdout;
                        }
                        arg_num += 2;
                    } else {
                        output = stdout;
                        arg_num++;
                    }
                }
                else if(argv[arg_num][1] == 'h' || (argv[arg_num][1] == '-' && argv[arg_num][2]=='h')) {
                    print_usage();
                    print_options();
                    exit(0);
                }
                else {
                    print_invalid(argv, arg_num);
                    exit(1);
                }
            } else {
                print_invalid(argv, arg_num);
                exit(1);
            }
        }
    }

    if(input == NULL){
        fprintf(stderr, "\tNenhum arquivo de entrada especificado. Use a opção -i.\n");
        print_usage();
        exit(1);
    }

    yyin = input;
    printf("Iniciando análise sintática...\n");
    
    yyparse();
    
    fclose(input);
    
    if (root && output) {
        printf("Imprimindo a Árvore Sintática Abstrata...\n");
        print_ast(root, 0, output);
        if (output != stdout) {
            fclose(output);
        }
    }
    
    free_ast(root);

    return 0;
}
