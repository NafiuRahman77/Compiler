/* A Bison parser, made by GNU Bison 3.7.5.  */

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
#define YYBISON 30705

/* Bison version string.  */
#define YYBISON_VERSION "3.7.5"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "1905077.y"

#include "bits/stdc++.h"
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include "1905077_main.h"
using namespace std;

int yyparse(void);
int yylex(void);
extern FILE *yyin;
FILE *fp;
FILE *log_output;
FILE *error_output;
 int line_count=1;
 int error_count=0;
ofstream parse_tree;
SymbolTable table(11);
vector<SymbolInfo> params;
vector<SymbolInfo> vars;
vector<SymbolInfo> argumentList;
string type="";
string type_final="";  
string name="";
string name_final="";
void ParseTree(SymbolInfo* s,int t, ostream &os)
    {
        for (int i = 0; i < t; i++)
        {
            os << " ";
        }
        if (s->isToken())
            os << s->getLeftPart() << " :" << s->getRightPart() << "\t<Line: " << s->getStart() << ">\n";
        else
        os << s->getLeftPart()  << " : " << s->getRightPart() << "\t<Line: " << s->getStart()  << "-" << s->getEnd()  << ">\n";
			vector<SymbolInfo*> v=s->getChildren();
            for (SymbolInfo *si : v)
            {
                ParseTree(si,t + 1, os);
            }
        
    }

void yyerror(char *s)
{
	//write your code
}

#line 121 "y.tab.c"

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
    IF = 258,                      /* IF  */
    ELSE = 259,                    /* ELSE  */
    FOR = 260,                     /* FOR  */
    WHILE = 261,                   /* WHILE  */
    INT = 262,                     /* INT  */
    FLOAT = 263,                   /* FLOAT  */
    DOUBLE = 264,                  /* DOUBLE  */
    CHAR = 265,                    /* CHAR  */
    RETURN = 266,                  /* RETURN  */
    VOID = 267,                    /* VOID  */
    PRINTLN = 268,                 /* PRINTLN  */
    DO = 269,                      /* DO  */
    BREAK = 270,                   /* BREAK  */
    SWITCH = 271,                  /* SWITCH  */
    CASE = 272,                    /* CASE  */
    DEFAULT = 273,                 /* DEFAULT  */
    CONTINUE = 274,                /* CONTINUE  */
    ASSIGNOP = 275,                /* ASSIGNOP  */
    NOT = 276,                     /* NOT  */
    SEMICOLON = 277,               /* SEMICOLON  */
    COMMA = 278,                   /* COMMA  */
    LPAREN = 279,                  /* LPAREN  */
    RPAREN = 280,                  /* RPAREN  */
    LCURL = 281,                   /* LCURL  */
    RCURL = 282,                   /* RCURL  */
    LTHIRD = 283,                  /* LTHIRD  */
    RTHIRD = 284,                  /* RTHIRD  */
    INCOP = 285,                   /* INCOP  */
    DECOP = 286,                   /* DECOP  */
    MAIN = 287,                    /* MAIN  */
    ID = 288,                      /* ID  */
    ADDOP = 289,                   /* ADDOP  */
    MULOP = 290,                   /* MULOP  */
    RELOP = 291,                   /* RELOP  */
    LOGICOP = 292,                 /* LOGICOP  */
    CONST_INT = 293,               /* CONST_INT  */
    CONST_FLOAT = 294,             /* CONST_FLOAT  */
    LOWER_THAN_ELSE = 295          /* LOWER_THAN_ELSE  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define IF 258
#define ELSE 259
#define FOR 260
#define WHILE 261
#define INT 262
#define FLOAT 263
#define DOUBLE 264
#define CHAR 265
#define RETURN 266
#define VOID 267
#define PRINTLN 268
#define DO 269
#define BREAK 270
#define SWITCH 271
#define CASE 272
#define DEFAULT 273
#define CONTINUE 274
#define ASSIGNOP 275
#define NOT 276
#define SEMICOLON 277
#define COMMA 278
#define LPAREN 279
#define RPAREN 280
#define LCURL 281
#define RCURL 282
#define LTHIRD 283
#define RTHIRD 284
#define INCOP 285
#define DECOP 286
#define MAIN 287
#define ID 288
#define ADDOP 289
#define MULOP 290
#define RELOP 291
#define LOGICOP 292
#define CONST_INT 293
#define CONST_FLOAT 294
#define LOWER_THAN_ELSE 295

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 51 "1905077.y"

	SymbolInfo* symbol;

#line 258 "y.tab.c"

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
  YYSYMBOL_IF = 3,                         /* IF  */
  YYSYMBOL_ELSE = 4,                       /* ELSE  */
  YYSYMBOL_FOR = 5,                        /* FOR  */
  YYSYMBOL_WHILE = 6,                      /* WHILE  */
  YYSYMBOL_INT = 7,                        /* INT  */
  YYSYMBOL_FLOAT = 8,                      /* FLOAT  */
  YYSYMBOL_DOUBLE = 9,                     /* DOUBLE  */
  YYSYMBOL_CHAR = 10,                      /* CHAR  */
  YYSYMBOL_RETURN = 11,                    /* RETURN  */
  YYSYMBOL_VOID = 12,                      /* VOID  */
  YYSYMBOL_PRINTLN = 13,                   /* PRINTLN  */
  YYSYMBOL_DO = 14,                        /* DO  */
  YYSYMBOL_BREAK = 15,                     /* BREAK  */
  YYSYMBOL_SWITCH = 16,                    /* SWITCH  */
  YYSYMBOL_CASE = 17,                      /* CASE  */
  YYSYMBOL_DEFAULT = 18,                   /* DEFAULT  */
  YYSYMBOL_CONTINUE = 19,                  /* CONTINUE  */
  YYSYMBOL_ASSIGNOP = 20,                  /* ASSIGNOP  */
  YYSYMBOL_NOT = 21,                       /* NOT  */
  YYSYMBOL_SEMICOLON = 22,                 /* SEMICOLON  */
  YYSYMBOL_COMMA = 23,                     /* COMMA  */
  YYSYMBOL_LPAREN = 24,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 25,                    /* RPAREN  */
  YYSYMBOL_LCURL = 26,                     /* LCURL  */
  YYSYMBOL_RCURL = 27,                     /* RCURL  */
  YYSYMBOL_LTHIRD = 28,                    /* LTHIRD  */
  YYSYMBOL_RTHIRD = 29,                    /* RTHIRD  */
  YYSYMBOL_INCOP = 30,                     /* INCOP  */
  YYSYMBOL_DECOP = 31,                     /* DECOP  */
  YYSYMBOL_MAIN = 32,                      /* MAIN  */
  YYSYMBOL_ID = 33,                        /* ID  */
  YYSYMBOL_ADDOP = 34,                     /* ADDOP  */
  YYSYMBOL_MULOP = 35,                     /* MULOP  */
  YYSYMBOL_RELOP = 36,                     /* RELOP  */
  YYSYMBOL_LOGICOP = 37,                   /* LOGICOP  */
  YYSYMBOL_CONST_INT = 38,                 /* CONST_INT  */
  YYSYMBOL_CONST_FLOAT = 39,               /* CONST_FLOAT  */
  YYSYMBOL_LOWER_THAN_ELSE = 40,           /* LOWER_THAN_ELSE  */
  YYSYMBOL_YYACCEPT = 41,                  /* $accept  */
  YYSYMBOL_start = 42,                     /* start  */
  YYSYMBOL_program = 43,                   /* program  */
  YYSYMBOL_unit = 44,                      /* unit  */
  YYSYMBOL_func_declaration = 45,          /* func_declaration  */
  YYSYMBOL_func_definition = 46,           /* func_definition  */
  YYSYMBOL_47_1 = 47,                      /* $@1  */
  YYSYMBOL_48_2 = 48,                      /* $@2  */
  YYSYMBOL_parameter_list = 49,            /* parameter_list  */
  YYSYMBOL_compound_statement = 50,        /* compound_statement  */
  YYSYMBOL_51_3 = 51,                      /* $@3  */
  YYSYMBOL_52_4 = 52,                      /* $@4  */
  YYSYMBOL_var_declaration = 53,           /* var_declaration  */
  YYSYMBOL_type_specifier = 54,            /* type_specifier  */
  YYSYMBOL_declaration_list = 55,          /* declaration_list  */
  YYSYMBOL_statements = 56,                /* statements  */
  YYSYMBOL_statement = 57,                 /* statement  */
  YYSYMBOL_expression_statement = 58,      /* expression_statement  */
  YYSYMBOL_variable = 59,                  /* variable  */
  YYSYMBOL_expression = 60,                /* expression  */
  YYSYMBOL_logic_expression = 61,          /* logic_expression  */
  YYSYMBOL_rel_expression = 62,            /* rel_expression  */
  YYSYMBOL_simple_expression = 63,         /* simple_expression  */
  YYSYMBOL_term = 64,                      /* term  */
  YYSYMBOL_unary_expression = 65,          /* unary_expression  */
  YYSYMBOL_factor = 66,                    /* factor  */
  YYSYMBOL_argument_list = 67,             /* argument_list  */
  YYSYMBOL_arguments = 68                  /* arguments  */
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
typedef yytype_int8 yy_state_t;

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

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
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
#define YYFINAL  11
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   149

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  41
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  28
/* YYNRULES -- Number of rules.  */
#define YYNRULES  68
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  122

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   295


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
      35,    36,    37,    38,    39,    40
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    64,    64,    79,    88,    99,   109,   120,   133,   171,
     208,   208,   352,   352,   421,   436,   449,   463,   479,   479,
     504,   504,   528,   596,   609,   620,   634,   647,   659,   671,
     687,   696,   707,   716,   725,   734,   743,   752,   762,   771,
     780,   802,   812,   824,   867,   909,   922,   968,   979,  1003,
    1014,  1031,  1047,  1071,  1085,  1161,  1172,  1184,  1199,  1211,
    1287,  1298,  1309,  1321,  1332,  1345,  1356,  1368,  1383
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
  "\"end of file\"", "error", "\"invalid token\"", "IF", "ELSE", "FOR",
  "WHILE", "INT", "FLOAT", "DOUBLE", "CHAR", "RETURN", "VOID", "PRINTLN",
  "DO", "BREAK", "SWITCH", "CASE", "DEFAULT", "CONTINUE", "ASSIGNOP",
  "NOT", "SEMICOLON", "COMMA", "LPAREN", "RPAREN", "LCURL", "RCURL",
  "LTHIRD", "RTHIRD", "INCOP", "DECOP", "MAIN", "ID", "ADDOP", "MULOP",
  "RELOP", "LOGICOP", "CONST_INT", "CONST_FLOAT", "LOWER_THAN_ELSE",
  "$accept", "start", "program", "unit", "func_declaration",
  "func_definition", "$@1", "$@2", "parameter_list", "compound_statement",
  "$@3", "$@4", "var_declaration", "type_specifier", "declaration_list",
  "statements", "statement", "expression_statement", "variable",
  "expression", "logic_expression", "rel_expression", "simple_expression",
  "term", "unary_expression", "factor", "argument_list", "arguments", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295
};
#endif

#define YYPACT_NINF (-75)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-21)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      46,   -75,   -75,   -75,     8,    46,   -75,   -75,   -75,   -75,
       2,   -75,   -75,     5,    -6,     7,   -15,   -75,    29,    16,
      21,    37,    30,    52,   -75,    55,    46,    60,   -75,   -75,
      47,    56,   -75,    51,   -75,    55,    57,   103,    62,   -75,
     -75,   -75,    67,    70,    71,   110,    72,   110,   -75,   110,
      28,   110,   -75,   -75,   -75,   -75,    64,    66,   -75,   -75,
     -10,    76,   -75,    65,    11,    68,   -75,   -75,   -75,   110,
      27,   110,    79,    74,    45,   -75,    87,   110,   110,   -75,
      85,   -75,   -75,   110,   -75,   -75,   -75,   110,   110,   110,
     110,    92,    27,    93,   -75,    94,   -75,   -75,    95,    98,
      97,   -75,   -75,    68,    88,   -75,   103,   110,   103,   101,
     -75,   110,   -75,   124,   105,   -75,   -75,   -75,   103,   103,
     -75,   -75
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    23,    24,    25,     0,     2,     4,     6,     7,     5,
       0,     1,     3,    28,     0,     0,     0,    22,     0,    12,
       0,    17,     0,    26,     9,     0,     0,    10,    16,    29,
       0,    18,    13,    15,     8,     0,     0,     0,     0,    14,
      11,    27,     0,     0,     0,     0,     0,     0,    41,     0,
      43,     0,    61,    62,    34,    32,     0,     0,    30,    33,
      58,     0,    45,    47,    49,    51,    53,    57,    21,     0,
       0,     0,     0,     0,    58,    56,     0,    66,     0,    55,
      28,    19,    31,     0,    63,    64,    42,     0,     0,     0,
       0,     0,     0,     0,    40,     0,    60,    68,     0,    65,
       0,    46,    48,    52,    50,    54,     0,     0,     0,     0,
      59,     0,    44,    36,     0,    38,    39,    67,     0,     0,
      37,    35
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -75,   -75,   -75,   127,   -75,   -75,   -75,   -75,   -75,   -13,
     -75,   -75,    26,    13,   -75,   -75,   -51,   -68,   -47,   -44,
     -74,    48,    44,    50,   -40,   -75,   -75,   -75
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     4,     5,     6,     7,     8,    35,    25,    20,    54,
      37,    38,    55,    56,    14,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    98,    99
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      74,    72,    92,    97,    74,    76,    82,    75,    11,   101,
      83,    79,    32,    10,     1,     2,    17,    18,    10,     3,
      84,    85,    40,    22,   107,    91,     9,    93,    21,    15,
      74,     9,    19,    16,   100,    13,    74,   117,    24,    33,
      74,    74,    74,    74,    26,    88,    27,    89,    47,    48,
     105,    49,    77,     1,     2,   113,    78,   115,     3,    29,
      50,    51,    23,   114,    74,    52,    53,   120,   121,    42,
      28,    43,    44,     1,     2,    84,    85,    45,     3,    46,
      30,    31,    34,   -20,    39,    36,    41,    47,    48,    68,
      49,    69,    31,    81,    70,    71,    73,    80,    86,    50,
      51,    94,    87,    90,    52,    53,    42,    95,    43,    44,
       1,     2,    96,    16,    45,     3,    46,   106,   108,   109,
     110,   111,    88,   116,    47,    48,   112,    49,   118,    31,
     119,    47,    12,   104,    49,   102,    50,    51,   103,     0,
       0,    52,    53,    50,    51,     0,     0,     0,    52,    53
};

static const yytype_int8 yycheck[] =
{
      47,    45,    70,    77,    51,    49,    57,    47,     0,    83,
      20,    51,    25,     0,     7,     8,    22,    23,     5,    12,
      30,    31,    35,    38,    92,    69,     0,    71,    15,    24,
      77,     5,    25,    28,    78,    33,    83,   111,    22,    26,
      87,    88,    89,    90,    23,    34,    25,    36,    21,    22,
      90,    24,    24,     7,     8,   106,    28,   108,    12,    29,
      33,    34,    33,   107,   111,    38,    39,   118,   119,     3,
      33,     5,     6,     7,     8,    30,    31,    11,    12,    13,
      28,    26,    22,    27,    33,    38,    29,    21,    22,    27,
      24,    24,    26,    27,    24,    24,    24,    33,    22,    33,
      34,    22,    37,    35,    38,    39,     3,    33,     5,     6,
       7,     8,    25,    28,    11,    12,    13,    25,    25,    25,
      25,    23,    34,    22,    21,    22,    29,    24,     4,    26,
      25,    21,     5,    89,    24,    87,    33,    34,    88,    -1,
      -1,    38,    39,    33,    34,    -1,    -1,    -1,    38,    39
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     7,     8,    12,    42,    43,    44,    45,    46,    53,
      54,     0,    44,    33,    55,    24,    28,    22,    23,    25,
      49,    54,    38,    33,    22,    48,    23,    25,    33,    29,
      28,    26,    50,    54,    22,    47,    38,    51,    52,    33,
      50,    29,     3,     5,     6,    11,    13,    21,    22,    24,
      33,    34,    38,    39,    50,    53,    54,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    27,    24,
      24,    24,    60,    24,    59,    65,    60,    24,    28,    65,
      33,    27,    57,    20,    30,    31,    22,    37,    34,    36,
      35,    60,    58,    60,    22,    33,    25,    61,    67,    68,
      60,    61,    62,    64,    63,    65,    25,    58,    25,    25,
      25,    23,    29,    57,    60,    57,    22,    61,     4,    25,
      57,    57
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    41,    42,    43,    43,    44,    44,    44,    45,    45,
      47,    46,    48,    46,    49,    49,    49,    49,    51,    50,
      52,    50,    53,    54,    54,    54,    55,    55,    55,    55,
      56,    56,    57,    57,    57,    57,    57,    57,    57,    57,
      57,    58,    58,    59,    59,    60,    60,    61,    61,    62,
      62,    63,    63,    64,    64,    65,    65,    65,    66,    66,
      66,    66,    66,    66,    66,    67,    67,    68,    68
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     6,     5,
       0,     7,     0,     6,     4,     3,     2,     1,     0,     4,
       0,     3,     3,     1,     1,     1,     3,     6,     1,     4,
       1,     2,     1,     1,     1,     7,     5,     7,     5,     5,
       3,     1,     2,     1,     4,     1,     3,     1,     3,     1,
       3,     1,     3,     1,     3,     2,     2,     1,     1,     4,
       3,     1,     1,     2,     2,     1,     0,     3,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


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

/* This macro is provided for backward compatibility. */
# ifndef YY_LOCATION_PRINT
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif


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
# ifdef YYPRINT
  if (yykind < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yykind], *yyvaluep);
# endif
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
    goto yyexhaustedlab;
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
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
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
  case 2: /* start: program  */
#line 65 "1905077.y"
        {
		//write your code in this block in all the similar blocks below
		(yyval.symbol) = new SymbolInfo((yyvsp[0].symbol)->getName(), "program");
		(yyval.symbol)->setChildren({(yyvsp[0].symbol)});
		(yyval.symbol)->setLeftPart("start");
		(yyval.symbol)->setRightPart("program");
		(yyval.symbol)->setStart((yyvsp[0].symbol)->getStart());
		(yyval.symbol)->setEnd((yyvsp[0].symbol)->getEnd());
		fprintf(log_output, "start : program\n");
		(yyval.symbol)->printParseTree(0,parse_tree);
		//ParseTree($$,0,parse_tree);
	}
#line 1411 "y.tab.c"
    break;

  case 3: /* program: program unit  */
#line 79 "1905077.y"
                      {
	    (yyval.symbol) = new SymbolInfo((yyvsp[-1].symbol)->getName()+"\n"+(yyvsp[0].symbol)->getName(),"program");
		(yyval.symbol)->setChildren({(yyvsp[-1].symbol),(yyvsp[0].symbol)});
		(yyval.symbol)->setLeftPart("program");
		(yyval.symbol)->setRightPart("program unit");
		(yyval.symbol)->setStart((yyvsp[-1].symbol)->getStart());
		(yyval.symbol)->setEnd((yyvsp[0].symbol)->getEnd());
		fprintf(log_output, "program : program unit\n");
	}
#line 1425 "y.tab.c"
    break;

  case 4: /* program: unit  */
#line 88 "1905077.y"
              {
		(yyval.symbol) = new SymbolInfo((yyvsp[0].symbol)->getName(),"program");
		(yyval.symbol)->setChildren({(yyvsp[0].symbol)});
		(yyval.symbol)->setLeftPart("program");
		(yyval.symbol)->setRightPart("unit");
		(yyval.symbol)->setStart((yyvsp[0].symbol)->getStart());
		(yyval.symbol)->setEnd((yyvsp[0].symbol)->getEnd());
		fprintf(log_output, "program : unit\n");
	}
#line 1439 "y.tab.c"
    break;

  case 5: /* unit: var_declaration  */
#line 99 "1905077.y"
                      {

		(yyval.symbol) =  new SymbolInfo((yyvsp[0].symbol)->getName(),"program");
		(yyval.symbol)->setChildren({(yyvsp[0].symbol)});
		(yyval.symbol)->setLeftPart("unit");
		(yyval.symbol)->setRightPart("var_declaration");
		(yyval.symbol)->setStart((yyvsp[0].symbol)->getStart());
		(yyval.symbol)->setEnd((yyvsp[0].symbol)->getEnd());
		fprintf(log_output, "unit : var_declaration\n");
	}
#line 1454 "y.tab.c"
    break;

  case 6: /* unit: func_declaration  */
#line 109 "1905077.y"
                       {

		(yyval.symbol) =  new SymbolInfo((yyvsp[0].symbol)->getName(),"program");

		(yyval.symbol)->setChildren({(yyvsp[0].symbol)});
		(yyval.symbol)->setLeftPart("unit");
		(yyval.symbol)->setRightPart("func_declaration");
		(yyval.symbol)->setStart((yyvsp[0].symbol)->getStart());
		(yyval.symbol)->setEnd((yyvsp[0].symbol)->getEnd());
		fprintf(log_output, "unit : func_declaration\n");
	 }
#line 1470 "y.tab.c"
    break;

  case 7: /* unit: func_definition  */
#line 120 "1905077.y"
                      {

		(yyval.symbol) =  new SymbolInfo((yyvsp[0].symbol)->getName(),"program");

		(yyval.symbol)->setChildren({(yyvsp[0].symbol)});
		(yyval.symbol)->setLeftPart("unit");
		(yyval.symbol)->setRightPart("func_definition");
		(yyval.symbol)->setStart((yyvsp[0].symbol)->getStart());
		(yyval.symbol)->setEnd((yyvsp[0].symbol)->getEnd());
		fprintf(log_output, "unit : func_definition\n");
	 }
#line 1486 "y.tab.c"
    break;

  case 8: /* func_declaration: type_specifier ID LPAREN parameter_list RPAREN SEMICOLON  */
#line 133 "1905077.y"
                                                                           {
				 
			//string returnType = $1->getName();
			//string funcName = $2->getName();
			type_final=(yyvsp[-5].symbol)->getDataType();
            name_final=(yyvsp[-4].symbol)->getName();
            
			SymbolInfo* temp = table.lookUpSymbol(type_final);
			vector<string> paramTypeList;
    		vector<string> typeAndName;
			//fprintf(error_output,"%s",name_final.c_str());
			if (temp!=nullptr)
			{
				error_count++;
				fprintf(error_output, "Line# %d: Multiple declaration of function %s\n", line_count, name_final.c_str());
			}
			else {
				vector<pair<string,string>> paramList;
                for(int i=0;i<params.size();i++){
                    paramList.push_back(make_pair(params[i].getName(), params[i].getDataType()));
                }
				
				SymbolInfo* temp=new SymbolInfo(name_final, type_final, paramList);
				temp->setDataType(type_final);
			    temp->setIsFuncDefined(false);
				table.insertSymbol(temp);
			}
			
			(yyval.symbol) = new SymbolInfo("type_specifier ID LPAREN parameter_list RPAREN SEMICOLON","func_declaration");
			fprintf(log_output, "func_declaration : type_specifier ID LPAREN parameter_list RPAREN SEMICOLON\n");

			(yyval.symbol)->setChildren({(yyvsp[-5].symbol),(yyvsp[-4].symbol),(yyvsp[-3].symbol),(yyvsp[-2].symbol),(yyvsp[-1].symbol),(yyvsp[0].symbol)});
			(yyval.symbol)->setLeftPart("func_declaration");
			(yyval.symbol)->setRightPart("type_specifier ID LPAREN parameter_list RPAREN SEMICOLON");
			(yyval.symbol)->setStart((yyvsp[-5].symbol)->getStart());
			(yyval.symbol)->setEnd((yyvsp[0].symbol)->getEnd());
            params.clear();
}
#line 1529 "y.tab.c"
    break;

  case 9: /* func_declaration: type_specifier ID LPAREN RPAREN SEMICOLON  */
#line 171 "1905077.y"
                                                           {
				 
			//string returnType = $1->getName();
			//string funcName = $2->getName();
			type_final=(yyvsp[-4].symbol)->getDataType();
            name_final=(yyvsp[-3].symbol)->getName();
			SymbolInfo* temp = table.lookUpSymbol(name_final);
			vector<string> paramTypeList;
    		vector<string> typeAndName;
			
			if (temp!=nullptr)
			{
				error_count++;
				fprintf(error_output, "Line# %d: Multiple declaration of function %s\n", line_count, name_final.c_str());
			}
			else {
				vector<pair<string,string>> paramList;
                for(int i=0;i<params.size();i++){
                    paramList.push_back(make_pair(params[i].getName(), params[i].getDataType()));
                }
				
				SymbolInfo* temp=new SymbolInfo(name_final, type_final, paramList);
			    temp->setIsFuncDefined(false);
				temp->setDataType(type_final);
				table.insertSymbol(temp);
			}
			(yyval.symbol) = new SymbolInfo((yyvsp[-4].symbol)->getName()+" "+(yyvsp[-3].symbol)->getName()+"("+");","func_declaration");
			fprintf(log_output, "func_declaration : type_specifier ID LPAREN RPAREN SEMICOLON\n");
			(yyval.symbol)->setChildren({(yyvsp[-4].symbol), (yyvsp[-3].symbol),(yyvsp[-2].symbol),(yyvsp[-1].symbol), (yyvsp[0].symbol)});
			(yyval.symbol)->setLeftPart("func_declaration");
			(yyval.symbol)->setRightPart("type_specifier ID LPAREN RPAREN SEMICOLON");
			(yyval.symbol)->setStart((yyvsp[-4].symbol)->getStart());
			(yyval.symbol)->setEnd((yyvsp[0].symbol)->getEnd());
            params.clear();
		}
#line 1569 "y.tab.c"
    break;

  case 10: /* $@1: %empty  */
#line 208 "1905077.y"
                                                                 {
	 string functionType = (yyvsp[-4].symbol)->getName();
     string functionName = (yyvsp[-3].symbol)->getName();
	 vector<pair<string,string>> parameterList;
     //vector<string> paramPair = split($4->getSymbolName(), ",");
     vector<string> typeAndName;
	 type_final=(yyvsp[-4].symbol)->getDataType();
     name_final=(yyvsp[-3].symbol)->getName();
     

    for (int i=0;i<params.size();i++)
    {
        pair<string,string> p(params[i].getName(), params[i].getDataType());
        parameterList.push_back(p);
    }

    SymbolInfo* currentFunction = table.lookUpSymbol(functionName);
	
	if(currentFunction!=nullptr){
		
		if(currentFunction->isFunction()){
			if (currentFunction->isDefined()) // Declared and Defined
				{
					error_count++;

						fprintf(error_output, "Line# %d: Multiple definition of function %s\n", line_count, functionName.c_str());
				}
			else{
					vector<pair<string,string>> declaredList=currentFunction->getParameterList();
					if(parameterList.size()!=currentFunction->getParameterListSize()){
						error_count++;
						fprintf(error_output, "Line# %d: Conflicting types for %s\n", line_count, functionName.c_str());
					}
					else if(currentFunction->getType()!=type_final){
						error_count++;
						fprintf(error_output, "Line# %d: Conflicting types for %s\n", line_count, functionName.c_str());
					}
					else{
                        vector<pair<string, string>> declaredParameter=currentFunction->getParameterList();
                        //table.enterScope();
                        bool inconsistentReturnTypeError = false;
                        for(int i=0; i<parameterList.size(); i++)
                        {
                            
                            if(parameterList[i].second!=declaredParameter[i].second)
                                {
                                    error_count++;
                                    //string error_msg = "Inconsistent type of argument" + declaredParameter[i].first + " in parameter";
                                    fprintf(error_output, "Line# %d: Inconsistent type of argument %s in parameter\n", line_count, (declaredParameter[i].first).c_str());
                                    inconsistentReturnTypeError = true;
                                    break;
                                }
                            
                        }

                	    bool multipleParamError = false;
                	    for(int i=0; i<parameterList.size(); i++)
                	    {
                        for(int j=0; j<parameterList.size(); j++)
                        {
                            if(i==j)continue;
                            else
                            {
                                if(parameterList[i].first==parameterList[j].first)
                                {
                                    error_count++;
                                    //string error_msg = "Multiple declaration of " + parameterList[i] + " in parameter";
                                   
                        			fprintf(error_output, "Line# %d: Redefinition of parameter \'%s\'\n", line_count, (parameterList[i].first).c_str());
                                    multipleParamError = true;
                                    break;
                                }
                            }
                        }
                            if(multipleParamError)
                                break;
                        }
                        if(!inconsistentReturnTypeError || !multipleParamError){
                            
                            currentFunction->setIsFuncDefined(true);
							currentFunction->setDataType(functionType);
                         
                        }
                    }


			}
		}
		else{
			//table.enterScope();

			error_count++;
			//string msg = "Identifier '" + currentFunction->getName() + "' is not a function.";
            fprintf(error_output, "Line# %d: \'%s\' redeclared as different kind of symbol\n", line_count, currentFunction->getName().c_str());
			
		}
	}
	else{
		SymbolInfo *syminfo = new SymbolInfo(functionName, functionType, parameterList);
        syminfo->setIsFuncDefined(true);
		syminfo->setDataType(functionType);
        table.insertSymbol(syminfo);
       // table.enterScope();
	
        bool multipleParamError = false;
        for(int i=0; i<parameterList.size(); i++)
        {
            // paramInserted = symbolTable->insertSymbol(parameterList[i].getParamName(), parameterList[i].getParamType());
            for(int j=0; j<parameterList.size(); j++)
            {
                if(i==j)continue;
                else
                {
                    if(parameterList[i].first==parameterList[j].first)
                    {
                        error_count++;
                        fprintf(error_output, "Line# %d: Multiple declaration of %s in parameter\n", line_count, (parameterList[i].first).c_str());
                        multipleParamError = true; 
                        break;
                    }
                }
            }
            
        }
		if( !multipleParamError){
        syminfo->setIsFuncDefined(true);
		syminfo->setDataType(functionType);          
        }

	//fprintf(error_output,"bop bop %d %s\n", syminfo->getParameterListSize(),functionName.c_str());

	}

}
#line 1708 "y.tab.c"
    break;

  case 11: /* func_definition: type_specifier ID LPAREN parameter_list RPAREN $@1 compound_statement  */
#line 341 "1905077.y"
                    {
		(yyval.symbol)=new SymbolInfo("type_specifier ID LPAREN parameter_list RPAREN compound_statement", "func_definition");
		(yyval.symbol)->setChildren({(yyvsp[-6].symbol),(yyvsp[-5].symbol),(yyvsp[-4].symbol),(yyvsp[-3].symbol),(yyvsp[-2].symbol),(yyvsp[0].symbol)});
			(yyval.symbol)->setLeftPart("func_definition");
			(yyval.symbol)->setRightPart("type_specifier ID LPAREN parameter_list RPAREN compound_statement");
			(yyval.symbol)->setStart((yyvsp[-6].symbol)->getStart());
			(yyval.symbol)->setEnd((yyvsp[0].symbol)->getEnd());

		fprintf(log_output, "func_definition :type_specifier ID LPAREN parameter_list RPAREN compound_statement \n");

}
#line 1724 "y.tab.c"
    break;

  case 12: /* $@2: %empty  */
#line 352 "1905077.y"
                                  {
	string functionType = (yyvsp[-3].symbol)->getName();
    string functionName = (yyvsp[-2].symbol)->getName();
    
    SymbolInfo* currentFunction = table.lookUpSymbol(functionName);
	vector<pair<string,string>> parameterList;
	vector<pair<string,string>> paramPair;
    vector<string> typeAndName;
	type_final=(yyvsp[-3].symbol)->getDataType();
    name_final=(yyvsp[-2].symbol)->getName();

    for (int i=0;i<params.size();i++)
    {
        pair<string,string> p(params[i].getName(), params[i].getDataType());
        parameterList.push_back(p);
    }
	if(currentFunction!=nullptr){
			if (currentFunction->isDefined()) // Declared and Defined
				{
					error_count++;

					fprintf(error_output, "Line# %d: Multiple definition of function %s\n", line_count, functionName.c_str());
					fprintf(log_output, "Line# %d: Multiple definition of function %s\n", line_count, functionName.c_str());
				}
			else{   vector<pair<string,string>>parameterList;
					if(parameterList.size()!=currentFunction->getParameterListSize()){
						error_count++;
						fprintf(error_output, "Line# %d: Total number of arguments mismatch with declaration in function %s\n", line_count, functionName.c_str());
						fprintf(log_output, "Line# %d: Total number of arguments mismatch with declaration in function %s\n", line_count, functionName.c_str());
					}
					if(currentFunction->getType()!=functionType){
						error_count++;
						fprintf(error_output, "Line# %d: Conflicting types for %s\n", line_count, functionName.c_str());
						fprintf(log_output, "Line# %d: Conflicting types for %s\n", line_count, functionName.c_str());
					}
					if(!(parameterList.size()!=currentFunction->getParameterListSize()) && !(currentFunction->getType()!=functionType)){
						table.removeSymbol(functionName);
                    	SymbolInfo *syminfo = new SymbolInfo(functionName, functionType, parameterList);      	
                    	syminfo->setIsFuncDefined(true);
                    	table.insertSymbol(syminfo);

					}
					
					}
                   
				}
	else{

        SymbolInfo *syminfo = new SymbolInfo(functionName, functionType, parameterList);
        syminfo->setIsFuncDefined(true);
        table.insertSymbol(syminfo);			
}
		
	}
#line 1783 "y.tab.c"
    break;

  case 13: /* func_definition: type_specifier ID LPAREN RPAREN $@2 compound_statement  */
#line 405 "1905077.y"
                           {

		(yyval.symbol)=new SymbolInfo("type_specifier ID LPAREN RPAREN compound_statement", "func_definition");
		(yyval.symbol)->setChildren({(yyvsp[-5].symbol),(yyvsp[-4].symbol),(yyvsp[-3].symbol),(yyvsp[-2].symbol),(yyvsp[0].symbol)});
			(yyval.symbol)->setLeftPart("func_definition");
			(yyval.symbol)->setRightPart("type_specifier ID LPAREN RPAREN compound_statement");
			(yyval.symbol)->setStart((yyvsp[-5].symbol)->getStart());
			(yyval.symbol)->setEnd((yyvsp[0].symbol)->getEnd());

		fprintf(log_output, "func_definition :type_specifier ID LPAREN RPAREN compound_statement \n");

	}
#line 1800 "y.tab.c"
    break;

  case 14: /* parameter_list: parameter_list COMMA type_specifier ID  */
#line 421 "1905077.y"
                                                        {

			(yyval.symbol) = new SymbolInfo((yyvsp[-3].symbol)->getName() + "," + (yyvsp[-1].symbol)->getName() + " " + (yyvsp[0].symbol)->getName(), "parameter_list"); 
			SymbolInfo s((yyvsp[0].symbol)->getName(),(yyvsp[-1].symbol)->getDataType());   
			s.setDataType((yyvsp[-1].symbol)->getDataType());         
            params.push_back(s);

			(yyval.symbol)->setChildren({(yyvsp[-3].symbol),(yyvsp[-2].symbol),(yyvsp[-1].symbol),(yyvsp[0].symbol)});
			(yyval.symbol)->setLeftPart("parameter_list");
			(yyval.symbol)->setRightPart("parameter_list COMMA type_specifier ID");
			(yyval.symbol)->setStart((yyvsp[-3].symbol)->getStart());
			(yyval.symbol)->setEnd((yyvsp[0].symbol)->getEnd());

			fprintf(log_output, "parameter_list : parameter_list COMMA type_specifier ID\n");
		}
#line 1820 "y.tab.c"
    break;

  case 15: /* parameter_list: parameter_list COMMA type_specifier  */
#line 436 "1905077.y"
                                                     {

			(yyval.symbol) = new SymbolInfo((yyvsp[-2].symbol)->getName() + "," + (yyvsp[0].symbol)->getName() , "parameter_list"); 
			SymbolInfo s("",(yyvsp[0].symbol)->getDataType()) ; 
			s.setDataType((yyvsp[0].symbol)->getDataType());    
            params.push_back(s);
			(yyval.symbol)->setChildren({(yyvsp[-2].symbol),(yyvsp[-1].symbol),(yyvsp[0].symbol)});
			(yyval.symbol)->setLeftPart("parameter_list");
			(yyval.symbol)->setRightPart("parameter_list COMMA type_specifier");
			(yyval.symbol)->setStart((yyvsp[-2].symbol)->getStart());
			(yyval.symbol)->setEnd((yyvsp[0].symbol)->getEnd());
			fprintf(log_output, "parameter_list : parameter_list COMMA type_specifier\n");
		}
#line 1838 "y.tab.c"
    break;

  case 16: /* parameter_list: type_specifier ID  */
#line 449 "1905077.y"
                                   {

			(yyval.symbol) = new SymbolInfo((yyvsp[-1].symbol)->getName() + " " + (yyvsp[0].symbol)->getName(), "parameter_list");    
			SymbolInfo s((yyvsp[0].symbol)->getName(),(yyvsp[-1].symbol)->getDataType()); 
			s.setDataType((yyvsp[-1].symbol)->getDataType());
            params.push_back(s);
			(yyval.symbol)->setChildren({(yyvsp[-1].symbol),(yyvsp[0].symbol)});
			(yyval.symbol)->setLeftPart("parameter_list");
			(yyval.symbol)->setRightPart("type_specifier ID");
			(yyval.symbol)->setStart((yyvsp[-1].symbol)->getStart());
			(yyval.symbol)->setEnd((yyvsp[0].symbol)->getEnd());
			//fprintf(error_output," ok %s ok %s\n ", params[0].getName().c_str(),params[0].getDataType().c_str());
			fprintf(log_output, "parameter_list : type_specifier ID\n");
		}
#line 1857 "y.tab.c"
    break;

  case 17: /* parameter_list: type_specifier  */
#line 463 "1905077.y"
                                {

			(yyval.symbol) = new SymbolInfo((yyvsp[0].symbol)->getName(), "parameter_list");
			SymbolInfo s("",(yyvsp[0].symbol)->getDataType());
			s.setDataType((yyvsp[0].symbol)->getDataType());
            params.push_back(s);
			(yyval.symbol)->setChildren({(yyvsp[0].symbol)});
			(yyval.symbol)->setLeftPart("parameter_list");
			(yyval.symbol)->setRightPart("type_specifier");
			(yyval.symbol)->setStart((yyvsp[0].symbol)->getStart());
			(yyval.symbol)->setEnd((yyvsp[0].symbol)->getEnd());
			fprintf(log_output, "parameter_list : type_specifier\n");
		}
#line 1875 "y.tab.c"
    break;

  case 18: /* $@3: %empty  */
#line 479 "1905077.y"
                          {
				table.enterScope();
				
                for(int i=0; i<params.size(); i++) {
					SymbolInfo* s=new SymbolInfo(params[i].getName(),params[i].getDataType());
					//fprintf(error_output, "debug %s %s\n", params[1].getDataType().c_str(),params[1].getName().c_str());
					s->setDataType(params[i].getDataType());
					table.insertSymbol(s);
                }
				params.clear();
                
				}
#line 1892 "y.tab.c"
    break;

  case 19: /* compound_statement: LCURL $@3 statements RCURL  */
#line 490 "1905077.y"
                                                  {
				(yyval.symbol) = new SymbolInfo("{\n }","compound_statement");
				fprintf(log_output, "compound_statement : LCURL statements RCURL\n");

				fprintf(log_output, "\n%s\n", table.printAllScopeTable().c_str());
				string allScope=table.printAllScopeTable();
				fprintf(log_output, "%s",allScope);
				(yyval.symbol)->setChildren({(yyvsp[-3].symbol),(yyvsp[-1].symbol),(yyvsp[0].symbol)});
				(yyval.symbol)->setLeftPart("compound_statement");
				(yyval.symbol)->setRightPart("LCURL statements RCURL");
				(yyval.symbol)->setStart((yyvsp[-3].symbol)->getStart());
				(yyval.symbol)->setEnd((yyvsp[0].symbol)->getEnd());
				table.exitScope();
}
#line 1911 "y.tab.c"
    break;

  case 20: /* $@4: %empty  */
#line 504 "1905077.y"
                           {
				table.enterScope();
				 
				
                for(int i=0; i<params.size(); i++) {
					SymbolInfo* s=new SymbolInfo(params[i].getName(),params[i].getDataType());
					table.insertSymbol(s);
                
				params.clear();
            	}
					
				}
#line 1928 "y.tab.c"
    break;

  case 21: /* compound_statement: LCURL $@4 RCURL  */
#line 515 "1905077.y"
                                       {
				(yyval.symbol) = new SymbolInfo("{\n}\n","compound_statement");
				fprintf(log_output, "compound_statement : LCURL RCURL\n");
          		fprintf(log_output, "%s", table.printAllScopeTable());
				(yyval.symbol)->setChildren({(yyvsp[-2].symbol),(yyvsp[0].symbol)});
				(yyval.symbol)->setLeftPart("compound_statement");
				(yyval.symbol)->setRightPart("LCURL RCURL");
				(yyval.symbol)->setStart((yyvsp[-2].symbol)->getStart());
				(yyval.symbol)->setEnd((yyvsp[0].symbol)->getEnd());
				table.exitScope();
			}
#line 1944 "y.tab.c"
    break;

  case 22: /* var_declaration: type_specifier declaration_list SEMICOLON  */
#line 528 "1905077.y"
                                                           {

            (yyval.symbol) = new SymbolInfo((string)(yyvsp[-2].symbol)->getName()+(string)" "+(string)(yyvsp[-1].symbol)->getName()+(string)";"+(string)"\n"+(string)"\n", "var_declaration");
            fprintf(log_output, "var_declaration: type_specifier declaration_list SEMICOLON\n");
			(yyval.symbol)->setChildren({(yyvsp[-2].symbol),(yyvsp[-1].symbol),(yyvsp[0].symbol)});
			(yyval.symbol)->setLeftPart("var_declaration");
			(yyval.symbol)->setRightPart("type_specifier declaration_list SEMICOLON");
			(yyval.symbol)->setStart((yyvsp[-2].symbol)->getStart());
			(yyval.symbol)->setEnd((yyvsp[0].symbol)->getEnd());
			string varType = (yyvsp[-2].symbol)->getDataType();
			string varFirst = vars[0].getName();
			if ((yyvsp[-2].symbol)->getDataType()=="void"){
				error_count++;
				fprintf(error_output, "Line# %d : Variable or field \'%s\' declared void \n", line_count, varFirst.c_str());
				
			}
			else{
                for(int i=0;i<vars.size();i++){
                    if(vars[i].isArray()){
						
                        int arraySize=vars[i].getArraySize();
                        string arrayName=vars[i].getName();
                        SymbolInfo* temp=new SymbolInfo(arrayName, varType, arraySize);
						temp->setDataType((yyvsp[-2].symbol)->getDataType());
                        bool check=table.insertSymbol(temp);
								if (!check ) {
									SymbolInfo* temp1=table.lookUpSymbol(arrayName);
                                    if((yyvsp[-2].symbol)->getDataType()!=temp1->getDataType() ){

									error_count++;
									fprintf(error_output, "Line# %d: Conflicting types for \'%s\'\n", line_count, vars[i].getName().c_str());
									}
									else{
									error_count++;
									fprintf(error_output, "Line# %d: Multiple declaration of %s\n", line_count, arrayName.c_str());
									}
							}
                            

                    }
                    else
							{
								SymbolInfo* temp=new SymbolInfo(vars[i].getName(), varType);
								temp->setDataType((yyvsp[-2].symbol)->getDataType());
								bool check=table.insertSymbol(temp);
								if (!check ) {

									SymbolInfo* temp1=table.lookUpSymbol(vars[i].getName());
                                    if((yyvsp[-2].symbol)->getDataType()!=temp1->getDataType()){

									error_count++;
									fprintf(error_output, "Line# %d: Conflicting types for \'%s\'\n", line_count, vars[i].getName().c_str());
									}
									else{
									error_count++;
									fprintf(error_output, "Line# %d: Multiple declaration of %s\n", line_count, vars[i].getName().c_str());
									}
							}
								
							}
                }
				
			}
			
            vars.clear();
}
#line 2015 "y.tab.c"
    break;

  case 23: /* type_specifier: INT  */
#line 596 "1905077.y"
                     {

					(yyval.symbol) = new SymbolInfo( "int","type_specifier");
					string s="int";
                    (yyval.symbol)->setDataType("int");
                    type="int";
					(yyval.symbol)->setChildren({(yyvsp[0].symbol)});
					(yyval.symbol)->setLeftPart("type_specifier");
					(yyval.symbol)->setRightPart("INT");
					(yyval.symbol)->setStart((yyvsp[0].symbol)->getStart());
					(yyval.symbol)->setEnd((yyvsp[0].symbol)->getEnd());
				    fprintf(log_output, "type_specifier : INT \n");
		}
#line 2033 "y.tab.c"
    break;

  case 24: /* type_specifier: FLOAT  */
#line 609 "1905077.y"
                       {
					(yyval.symbol) = new SymbolInfo( "float","type_specifier");
                   (yyval.symbol)->setDataType("float");
                   type="float";
				   (yyval.symbol)->setChildren({(yyvsp[0].symbol)});
					(yyval.symbol)->setLeftPart("type_specifier");
					(yyval.symbol)->setRightPart("FLOAT");
					(yyval.symbol)->setStart((yyvsp[0].symbol)->getStart());
					(yyval.symbol)->setEnd((yyvsp[0].symbol)->getEnd());
                   fprintf(log_output, "type_specifier : FLOAT \n");
		}
#line 2049 "y.tab.c"
    break;

  case 25: /* type_specifier: VOID  */
#line 620 "1905077.y"
                      {
					(yyval.symbol) = new SymbolInfo( "void","type_specifier");
                    (yyval.symbol)->setDataType("void");
                    type="void";
					(yyval.symbol)->setChildren({(yyvsp[0].symbol)});
					(yyval.symbol)->setLeftPart("type_specifier");
					(yyval.symbol)->setRightPart("VOID");
					(yyval.symbol)->setStart((yyvsp[0].symbol)->getStart());
					(yyval.symbol)->setEnd((yyvsp[0].symbol)->getEnd());
                    fprintf(log_output, "type_specifier : VOID \n");
		}
#line 2065 "y.tab.c"
    break;

  case 26: /* declaration_list: declaration_list COMMA ID  */
#line 634 "1905077.y"
                                            {

					(yyval.symbol) = new SymbolInfo( (yyvsp[0].symbol)->getName(), "declaration_list");
					SymbolInfo s( (yyvsp[0].symbol)->getName(), "declaration_list");
                    vars.push_back(s);
                    //name = $3->getName();
					(yyval.symbol)->setChildren({(yyvsp[-2].symbol),(yyvsp[-1].symbol),(yyvsp[0].symbol)});
					(yyval.symbol)->setLeftPart("declaration_list");
					(yyval.symbol)->setRightPart("declaration_list COMMA ID");
					(yyval.symbol)->setStart((yyvsp[-2].symbol)->getStart());
					(yyval.symbol)->setEnd((yyvsp[0].symbol)->getEnd());
					fprintf(log_output, "declaration_list : declaration_list COMMA ID\n");
			}
#line 2083 "y.tab.c"
    break;

  case 27: /* declaration_list: declaration_list COMMA ID LTHIRD CONST_INT RTHIRD  */
#line 647 "1905077.y"
                                                                     {
					(yyval.symbol) = new SymbolInfo( (yyvsp[-3].symbol)->getName() ,"declaration_list");
                    int size=stoi((yyvsp[-1].symbol)->getName());
					SymbolInfo s( (yyvsp[-3].symbol)->getName(), "declaration_list", size );
                    vars.push_back(s);
					(yyval.symbol)->setChildren({(yyvsp[-5].symbol),(yyvsp[-4].symbol),(yyvsp[-3].symbol),(yyvsp[-2].symbol),(yyvsp[-1].symbol),(yyvsp[0].symbol)});
					(yyval.symbol)->setLeftPart("declaration_list");
					(yyval.symbol)->setRightPart("declaration_list COMMA ID LTHIRD CONST_INT RTHIRD");
					(yyval.symbol)->setStart((yyvsp[-5].symbol)->getStart());
					(yyval.symbol)->setEnd((yyvsp[0].symbol)->getEnd());
					fprintf(log_output, "declaration_list : declaration_list COMMA ID LTHIRD CONST_INT RTHIRD\n",  line_count);
					}
#line 2100 "y.tab.c"
    break;

  case 28: /* declaration_list: ID  */
#line 659 "1905077.y"
                      {
					(yyval.symbol) = new SymbolInfo((yyvsp[0].symbol)->getName(), "declaration_list");
					SymbolInfo s( (yyvsp[0].symbol)->getName(), "declaration_list");
                    vars.push_back(s);
					(yyval.symbol)->setChildren({(yyvsp[0].symbol)});
					(yyval.symbol)->setLeftPart("declaration_list");
					(yyval.symbol)->setRightPart("ID");
					(yyval.symbol)->setStart((yyvsp[0].symbol)->getStart());
					(yyval.symbol)->setEnd((yyvsp[0].symbol)->getEnd());
                    name = (yyvsp[0].symbol)->getName();
					fprintf(log_output, "declaration_list : ID\n");
					}
#line 2117 "y.tab.c"
    break;

  case 29: /* declaration_list: ID LTHIRD CONST_INT RTHIRD  */
#line 671 "1905077.y"
                                              {
					(yyval.symbol) = new SymbolInfo((yyvsp[-3].symbol)->getName(),	"declaration_list");
                    int size=stoi((yyvsp[-1].symbol)->getName());
					//fprintf(error_output,"sizeeee %d", size);
					SymbolInfo s( (yyvsp[-3].symbol)->getName(), "declaration_list", size );
                    vars.push_back(s);
                    name = (yyvsp[-3].symbol)->getName();
					(yyval.symbol)->setChildren({(yyvsp[-3].symbol),(yyvsp[-2].symbol),(yyvsp[-1].symbol),(yyvsp[0].symbol)});
					(yyval.symbol)->setLeftPart("declaration_list");
					(yyval.symbol)->setRightPart("ID LTHIRD CONST_INT RTHIRD");
					(yyval.symbol)->setStart((yyvsp[-3].symbol)->getStart());
					(yyval.symbol)->setEnd((yyvsp[0].symbol)->getEnd());
					fprintf(log_output, "declaration_list : COMMA ID LTHIRD CONST_INT RTHIRD\n");
		  }
#line 2136 "y.tab.c"
    break;

  case 30: /* statements: statement  */
#line 687 "1905077.y"
                      {
					(yyval.symbol) = new SymbolInfo((string)(yyvsp[0].symbol)->getName(), "statements");
					(yyval.symbol)->setChildren({(yyvsp[0].symbol)});
					(yyval.symbol)->setLeftPart("statements");
					(yyval.symbol)->setRightPart("statement");
					(yyval.symbol)->setStart((yyvsp[0].symbol)->getStart());
					(yyval.symbol)->setEnd((yyvsp[0].symbol)->getEnd());
					fprintf(log_output, "statements : statement\n");
			}
#line 2150 "y.tab.c"
    break;

  case 31: /* statements: statements statement  */
#line 696 "1905077.y"
                                 {
					(yyval.symbol) = new SymbolInfo((yyvsp[-1].symbol)->getName() + " " + (yyvsp[0].symbol)->getName(), "statements");
					(yyval.symbol)->setChildren({(yyvsp[-1].symbol),(yyvsp[0].symbol)});
					(yyval.symbol)->setLeftPart("statements");
					(yyval.symbol)->setRightPart("statements statement");
					(yyval.symbol)->setStart((yyvsp[-1].symbol)->getStart());
					(yyval.symbol)->setEnd((yyvsp[0].symbol)->getEnd());	
					fprintf(log_output, "statements : statements statement\n");	
	   }
#line 2164 "y.tab.c"
    break;

  case 32: /* statement: var_declaration  */
#line 707 "1905077.y"
                           {
		(yyval.symbol)=new SymbolInfo((string)(yyvsp[0].symbol)->getName(), "statement");
		(yyval.symbol)->setChildren({(yyvsp[0].symbol)});
		(yyval.symbol)->setLeftPart("statement");
		(yyval.symbol)->setRightPart("var_declaration");
		(yyval.symbol)->setStart((yyvsp[0].symbol)->getStart());
		(yyval.symbol)->setEnd((yyvsp[0].symbol)->getEnd());
		fprintf(log_output, "statement : var_declaration\n");	
}
#line 2178 "y.tab.c"
    break;

  case 33: /* statement: expression_statement  */
#line 716 "1905077.y"
                                {
		(yyval.symbol)=new SymbolInfo((string)(yyvsp[0].symbol)->getName(), "statement");
		(yyval.symbol)->setChildren({(yyvsp[0].symbol)});
		(yyval.symbol)->setLeftPart("statement");
		(yyval.symbol)->setRightPart("expression_statement");
		(yyval.symbol)->setStart((yyvsp[0].symbol)->getStart());
		(yyval.symbol)->setEnd((yyvsp[0].symbol)->getEnd());
		fprintf(log_output, "statement : expression_statement\n");		
	  }
#line 2192 "y.tab.c"
    break;

  case 34: /* statement: compound_statement  */
#line 725 "1905077.y"
                              {
		(yyval.symbol) = new SymbolInfo((string)(yyvsp[0].symbol)->getName(), "statement");
		(yyval.symbol)->setChildren({(yyvsp[0].symbol)});
		(yyval.symbol)->setLeftPart("statement");
		(yyval.symbol)->setRightPart("compound_statement");
		(yyval.symbol)->setStart((yyvsp[0].symbol)->getStart());
		(yyval.symbol)->setEnd((yyvsp[0].symbol)->getEnd());
		fprintf(log_output, "statement : compound_statement\n");
	  }
#line 2206 "y.tab.c"
    break;

  case 35: /* statement: FOR LPAREN expression_statement expression_statement expression RPAREN statement  */
#line 734 "1905077.y"
                                                                                            {
		(yyval.symbol) = new SymbolInfo("for("+(yyvsp[-4].symbol)->getName()+(yyvsp[-3].symbol)->getName()+(yyvsp[-2].symbol)->getName()+")"+(yyvsp[0].symbol)->getName(), "statement");
		(yyval.symbol)->setChildren({(yyvsp[-6].symbol), (yyvsp[-5].symbol), (yyvsp[-4].symbol), (yyvsp[-3].symbol), (yyvsp[-2].symbol), (yyvsp[-1].symbol), (yyvsp[0].symbol)});
		(yyval.symbol)->setLeftPart("statement");
		(yyval.symbol)->setRightPart("FOR LPAREN expression_statement expression_statement expression RPAREN statement");
		(yyval.symbol)->setStart((yyvsp[-6].symbol)->getStart());
		(yyval.symbol)->setEnd((yyvsp[0].symbol)->getEnd());
		fprintf(log_output, "statement : FOR LPAREN expression_statement expression_statement expression RPAREN statement\n");
	  }
#line 2220 "y.tab.c"
    break;

  case 36: /* statement: IF LPAREN expression RPAREN statement  */
#line 743 "1905077.y"
                                                                        {
		(yyval.symbol) = new SymbolInfo("if("+(yyvsp[-2].symbol)->getName()+")"+(yyvsp[0].symbol)->getName(), "statement");
		(yyval.symbol)->setChildren({(yyvsp[-4].symbol), (yyvsp[-3].symbol), (yyvsp[-2].symbol), (yyvsp[-1].symbol), (yyvsp[0].symbol)});
		(yyval.symbol)->setLeftPart("statement");
		(yyval.symbol)->setRightPart("IF LPAREN expression RPAREN statement");
		(yyval.symbol)->setStart((yyvsp[-4].symbol)->getStart());
		(yyval.symbol)->setEnd((yyvsp[0].symbol)->getEnd());
		fprintf(log_output, "statement : IF LPAREN expression RPAREN statement\n");
	  }
#line 2234 "y.tab.c"
    break;

  case 37: /* statement: IF LPAREN expression RPAREN statement ELSE statement  */
#line 752 "1905077.y"
                                                                {

		(yyval.symbol) = new SymbolInfo("if("+(yyvsp[-4].symbol)->getName()+")"+(yyvsp[-2].symbol)->getName()+ "else\n"+(yyvsp[0].symbol)->getName(), "statement");
		(yyval.symbol)->setChildren({(yyvsp[-6].symbol), (yyvsp[-5].symbol), (yyvsp[-4].symbol), (yyvsp[-3].symbol), (yyvsp[-2].symbol), (yyvsp[-1].symbol), (yyvsp[0].symbol)});
		(yyval.symbol)->setLeftPart("statement");
		(yyval.symbol)->setRightPart("IF LPAREN expression RPAREN statement ELSE statement");
		(yyval.symbol)->setStart((yyvsp[-6].symbol)->getStart());
		(yyval.symbol)->setEnd((yyvsp[0].symbol)->getEnd());
		fprintf(log_output, "statement : IF LPAREN expression RPAREN statement ELSE statement\n");
	  }
#line 2249 "y.tab.c"
    break;

  case 38: /* statement: WHILE LPAREN expression RPAREN statement  */
#line 762 "1905077.y"
                                                    {
		(yyval.symbol) = new SymbolInfo("while("+(yyvsp[-2].symbol)->getName()+")"+(yyvsp[0].symbol)->getName(), "statement");
		(yyval.symbol)->setChildren({(yyvsp[-4].symbol), (yyvsp[-3].symbol), (yyvsp[-2].symbol), (yyvsp[-1].symbol), (yyvsp[0].symbol)});
		(yyval.symbol)->setLeftPart("statement");
		(yyval.symbol)->setRightPart("WHILE LPAREN expression RPAREN statement");
		(yyval.symbol)->setStart((yyvsp[-4].symbol)->getStart());
		(yyval.symbol)->setEnd((yyvsp[0].symbol)->getEnd());
		fprintf(log_output, "statement : WHILE LPAREN expression RPAREN statement\n");
	  }
#line 2263 "y.tab.c"
    break;

  case 39: /* statement: PRINTLN LPAREN ID RPAREN SEMICOLON  */
#line 771 "1905077.y"
                                              {
		(yyval.symbol) = new SymbolInfo((string)"\t"+(string)"println"+(string)"("+(string)(yyvsp[-2].symbol)->getName()+(string)")"+(string)";"+(string)"\n", "statement");
		(yyval.symbol)->setChildren({(yyvsp[-4].symbol), (yyvsp[-3].symbol), (yyvsp[-2].symbol), (yyvsp[-1].symbol), (yyvsp[0].symbol)});
		(yyval.symbol)->setLeftPart("statement");
		(yyval.symbol)->setRightPart("PRINTLN LPAREN ID RPAREN SEMICOLON");
		(yyval.symbol)->setStart((yyvsp[-4].symbol)->getStart());
		(yyval.symbol)->setEnd((yyvsp[0].symbol)->getEnd());
		fprintf(log_output, "statement : PRINTLN LPAREN ID RPAREN SEMICOLON\n");
	  }
#line 2277 "y.tab.c"
    break;

  case 40: /* statement: RETURN expression SEMICOLON  */
#line 780 "1905077.y"
                                       {
			(yyval.symbol) = new SymbolInfo((string)"\t"+(string)"return "+(string)(yyvsp[-1].symbol)->getName()+(string)";"+(string)"\n", "statement");
			(yyval.symbol)->setChildren({(yyvsp[-2].symbol), (yyvsp[-1].symbol), (yyvsp[0].symbol)});
			(yyval.symbol)->setLeftPart("statement");
			(yyval.symbol)->setRightPart("RETURN expression SEMICOLON");
			(yyval.symbol)->setStart((yyvsp[-2].symbol)->getStart());
			(yyval.symbol)->setEnd((yyvsp[0].symbol)->getEnd());
			fprintf(log_output, "statement : RETURN expression SEMICOLON\n");
			if((yyvsp[-1].symbol)->getDataType() == "void") {
					fprintf(error_output, "Line# %d: Void cannot be used in expression\n", line_count);
                error_count++;
                
            } 
			else if((yyvsp[-1].symbol)->getDataType()!=type_final){
			error_count++;

			//fprintf(error_output, "Line# %s: bop \n", $2->getDataType().c_str());
			fprintf(error_output, "Line# %d: Return type mismatch\n", line_count);
		}
	  }
#line 2302 "y.tab.c"
    break;

  case 41: /* expression_statement: SEMICOLON  */
#line 802 "1905077.y"
                                        {
				(yyval.symbol) = new SymbolInfo(";", "expression_statement");
				(yyval.symbol)->setChildren({(yyvsp[0].symbol)});
				(yyval.symbol)->setLeftPart("expression_statement");
				(yyval.symbol)->setRightPart("SEMICOLON");
				(yyval.symbol)->setStart((yyvsp[0].symbol)->getStart());
				(yyval.symbol)->setEnd((yyvsp[0].symbol)->getEnd());
				
				fprintf(log_output, "Line# %d: expression_statement : SEMICOLON\n%s\n", line_count, (yyval.symbol)->getName().c_str());
}
#line 2317 "y.tab.c"
    break;

  case 42: /* expression_statement: expression SEMICOLON  */
#line 812 "1905077.y"
                                               {

				(yyval.symbol) = new SymbolInfo((yyvsp[-1].symbol)->getName() + ";", "expression_statement");
				(yyval.symbol)->setChildren({(yyvsp[-1].symbol),(yyvsp[0].symbol)});
				(yyval.symbol)->setLeftPart("expression_statement");
				(yyval.symbol)->setRightPart("expression SEMICOLON");
				(yyval.symbol)->setStart((yyvsp[-1].symbol)->getStart());
				(yyval.symbol)->setEnd((yyvsp[0].symbol)->getEnd());
				fprintf(log_output, "Line# %d: expression_statement : expression SEMICOLON\n%s\n", line_count, (yyval.symbol)->getName().c_str());
			}
#line 2332 "y.tab.c"
    break;

  case 43: /* variable: ID  */
#line 824 "1905077.y"
              {
				string returnType;
				SymbolInfo* currId = table.lookUpSymbol((yyvsp[0].symbol)->getName());
				fprintf(log_output, "variable : id\n");
				
				if (currId == nullptr)
				{
					error_count++;
					fprintf(error_output, "Line# %d: Undeclared variable \'%s\'\n", line_count, (yyvsp[0].symbol)->getName().c_str());
					fprintf(log_output, "Line# %d: Undeclared variable \'%s\'\n", line_count, (yyvsp[0].symbol)->getName().c_str());
					(yyval.symbol) = new SymbolInfo((yyvsp[0].symbol)->getName(),"variable");
					(yyval.symbol)->setChildren({(yyvsp[0].symbol)});
					(yyval.symbol)->setLeftPart("variable");
					(yyval.symbol)->setRightPart("ID");
					(yyval.symbol)->setStart((yyvsp[0].symbol)->getStart());
					(yyval.symbol)->setEnd((yyvsp[0].symbol)->getEnd());
					}
				else
				{
					if(currId->isArray()){
					error_count++;
					//fprintf(error_output, "Line# %d: type mismatch(not variable) \'%s\'\n", line_count, $1->getName().c_str());	
					(yyval.symbol) = new SymbolInfo(currId->getName(), "variable");
					(yyval.symbol)->setDataType(currId->getDataType());	
					(yyval.symbol)->setChildren({(yyvsp[0].symbol)});
					(yyval.symbol)->setLeftPart("variable");
					(yyval.symbol)->setRightPart("ID");
					(yyval.symbol)->setStart((yyvsp[0].symbol)->getStart());
					(yyval.symbol)->setEnd((yyvsp[0].symbol)->getEnd());		
					}
					else{
					(yyval.symbol) = new SymbolInfo(currId->getName(), "variable");
					(yyval.symbol)->setDataType(currId->getDataType());
					(yyval.symbol)->setArraySize(0);
					(yyval.symbol)->setChildren({(yyvsp[0].symbol)});
					(yyval.symbol)->setLeftPart("variable");
					(yyval.symbol)->setRightPart("ID");
					(yyval.symbol)->setStart((yyvsp[0].symbol)->getStart());
					(yyval.symbol)->setEnd((yyvsp[0].symbol)->getEnd());
					}
					
				}
			}
#line 2380 "y.tab.c"
    break;

  case 44: /* variable: ID LTHIRD expression RTHIRD  */
#line 867 "1905077.y"
                                       {
		SymbolInfo *temp = table.lookUpSymbol((yyvsp[-3].symbol)->getName());
		(yyval.symbol) = new SymbolInfo((yyvsp[-3].symbol)->getName()+"["+(yyvsp[-1].symbol)->getName()+"]","variable");
		if(temp==nullptr){
			error_count++;
			fprintf(error_output, "Line# %d: Undeclared variable %s\n", line_count, (yyvsp[-3].symbol)->getName().c_str());
			fprintf(log_output, "Line# %d: Undeclared variable %s\n", line_count, (yyvsp[-3].symbol)->getName().c_str());
			
		}
		else{
			if(temp->isArray()){
				if((yyvsp[-1].symbol)->getDataType() != "int") {
				fprintf(error_output, "Line# %d: Array subscript is not an integer\n", line_count, (yyvsp[-3].symbol)->getName().c_str());
				fprintf(log_output, "Line# %d: Array subscript is not an integer", line_count, (yyvsp[-3].symbol)->getName().c_str());
                error_count++;

           		 }
				 else{
					(yyval.symbol) = new SymbolInfo((yyvsp[-3].symbol)->getName()+"["+(yyvsp[-1].symbol)->getName()+"]", "variable");
					(yyval.symbol)->setDataType(temp->getDataType());
					//$$->setArraySize(temp->getArraySize());				
				 }
				
			}
			else{
					error_count++;
					fprintf(error_output, "Line# %d: \'%s\' is not an array\n", line_count, (yyvsp[-3].symbol)->getName().c_str());
					fprintf(log_output, "Line# %d: \'%s\' is not an array\'%s\'\n", line_count, (yyvsp[-3].symbol)->getName().c_str());
					
			}

					(yyval.symbol)->setChildren({(yyvsp[-3].symbol),(yyvsp[-2].symbol),(yyvsp[-1].symbol),(yyvsp[0].symbol)});
					(yyval.symbol)->setLeftPart("variable");
					(yyval.symbol)->setRightPart("ID LTHIRD expression RTHIRD ");
					(yyval.symbol)->setStart((yyvsp[-3].symbol)->getStart());
					(yyval.symbol)->setEnd((yyvsp[0].symbol)->getEnd());

		}

	 }
#line 2425 "y.tab.c"
    break;

  case 45: /* expression: logic_expression  */
#line 909 "1905077.y"
                                {

			(yyval.symbol) = new SymbolInfo((yyvsp[0].symbol)->getName(), "expression");
			type=(yyvsp[0].symbol)->getDataType();
			(yyval.symbol)->setDataType((yyvsp[0].symbol)->getDataType());
			(yyval.symbol)->setChildren({(yyvsp[0].symbol)});
			(yyval.symbol)->setLeftPart("expression");
			(yyval.symbol)->setRightPart("logic_expression ");
			(yyval.symbol)->setStart((yyvsp[0].symbol)->getStart());
			(yyval.symbol)->setEnd((yyvsp[0].symbol)->getEnd());
			fprintf(log_output, "expression : logic_expression\n", line_count);

 }
#line 2443 "y.tab.c"
    break;

  case 46: /* expression: variable ASSIGNOP logic_expression  */
#line 922 "1905077.y"
                                                {

			(yyval.symbol) = new SymbolInfo((yyvsp[-2].symbol)->getName()+"="+(yyvsp[0].symbol)->getName(), "expression");
			if ((yyvsp[-2].symbol)->getDataType()=="void" || (yyvsp[0].symbol)->getDataType()=="void"){
				error_count++;
				fprintf(error_output, "Line# %d: Void cannot be used in expression\n", line_count);
				fprintf(log_output, "Line# %d: Void cannot be used in expression\n", line_count);
			}
			else if ((yyvsp[-2].symbol)->getDataType()!=(yyvsp[0].symbol)->getDataType()){
				string varType= (yyvsp[-2].symbol)->getDataType();
				string exprType= (yyvsp[0].symbol)->getDataType();
				
				
			    if (varType=="float" && exprType=="int") ;

				else if (varType=="int" && exprType=="float"){

				fprintf(error_output, "Line# %d: Warning: possible loss of data in assignment of FLOAT to INT\n", line_count);
				} 
				else if (varType=="void" && exprType=="int") {
				fprintf(error_output, "Line# %d: Void can't be used in an expression\n", line_count);

				}
				else {
					error_count++;
					//fprintf(error_output, "Line# %d: Type Mismatch\n", line_count);
				}
			}
			else{
				string varType= (yyvsp[-2].symbol)->getDataType();
				string exprType= (yyvsp[0].symbol)->getDataType();
				if (varType=="int" && exprType=="int") ;
				if (varType=="float" && exprType=="float") ;
				
			}
			(yyval.symbol)->setDataType((yyvsp[-2].symbol)->getDataType());
			type=(yyvsp[-2].symbol)->getDataType();
			(yyval.symbol)->setChildren({(yyvsp[-2].symbol),(yyvsp[-1].symbol),(yyvsp[0].symbol)});
			(yyval.symbol)->setLeftPart("expression");
			(yyval.symbol)->setRightPart("variable ASSIGNOP logic_expression");
			(yyval.symbol)->setStart((yyvsp[-2].symbol)->getStart());
			(yyval.symbol)->setEnd((yyvsp[0].symbol)->getEnd());
			fprintf(log_output, "expression : variable ASSIGNOP logic_expression\n");
	   }
#line 2492 "y.tab.c"
    break;

  case 47: /* logic_expression: rel_expression  */
#line 968 "1905077.y"
                                  {
			(yyval.symbol) = new SymbolInfo((yyvsp[0].symbol)->getName(), "logic_expression");
			(yyval.symbol)->setDataType((yyvsp[0].symbol)->getDataType());
			(yyval.symbol)->setArraySize((yyvsp[0].symbol)->getArraySize());
			(yyval.symbol)->setChildren({(yyvsp[0].symbol)});
			(yyval.symbol)->setLeftPart("logic_expression");
			(yyval.symbol)->setRightPart("rel_expression");
			(yyval.symbol)->setStart((yyvsp[0].symbol)->getStart());
			(yyval.symbol)->setEnd((yyvsp[0].symbol)->getEnd());
			fprintf(log_output, "logic_expression : rel_expression\n");
}
#line 2508 "y.tab.c"
    break;

  case 48: /* logic_expression: rel_expression LOGICOP rel_expression  */
#line 979 "1905077.y"
                                                         {
			if ((yyvsp[-2].symbol)->getDataType()=="void" || (yyvsp[0].symbol)->getDataType()=="void"){
				error_count++;
				fprintf(error_output, "Line# %d: Void function used in expression\n", line_count);
			}
			if (((yyvsp[-2].symbol)->getDataType() != "int") || ((yyvsp[0].symbol)->getDataType() != "int"))
				{
					error_count++;
					fprintf(error_output, "Line# %d: Both type of %s should be int\n", line_count,(yyvsp[-1].symbol)->getName().c_str());
				//	fprintf(error_output, "Line# %s: Both type should be int\n", $3->getDataType().c_str());

				}

			(yyval.symbol) = new SymbolInfo((yyvsp[-2].symbol)->getName() + (yyvsp[-1].symbol)->getName() + (yyvsp[0].symbol)->getName(),	"logic_expression");
			(yyval.symbol)->setDataType("int");
			(yyval.symbol)->setChildren({(yyvsp[-2].symbol),(yyvsp[-1].symbol),(yyvsp[0].symbol)});
			(yyval.symbol)->setLeftPart("logic_expression");
			(yyval.symbol)->setRightPart("rel_expression LOGICOP rel_expression");
			(yyval.symbol)->setStart((yyvsp[-2].symbol)->getStart());
			(yyval.symbol)->setEnd((yyvsp[0].symbol)->getEnd());
			fprintf(log_output, "logic_expression : rel_expression LOGICOP rel_expression\n");
		 }
#line 2535 "y.tab.c"
    break;

  case 49: /* rel_expression: simple_expression  */
#line 1003 "1905077.y"
                                    {
			(yyval.symbol) = new SymbolInfo((yyvsp[0].symbol)->getName() ,	"rel_expression");
			(yyval.symbol)->setDataType((yyvsp[0].symbol)->getDataType());
			(yyval.symbol)->setArraySize((yyvsp[0].symbol)->getArraySize());
			(yyval.symbol)->setChildren({(yyvsp[0].symbol)});
			(yyval.symbol)->setLeftPart("rel_expression");
			(yyval.symbol)->setRightPart("simple_expression");
			(yyval.symbol)->setStart((yyvsp[0].symbol)->getStart());
			(yyval.symbol)->setEnd((yyvsp[0].symbol)->getEnd());
			fprintf(log_output, "Line# %d: rel_expression : simple_expression\n", line_count);
}
#line 2551 "y.tab.c"
    break;

  case 50: /* rel_expression: simple_expression RELOP simple_expression  */
#line 1014 "1905077.y"
                                                                {

			if ((yyvsp[-2].symbol)->getDataType()=="void" || (yyvsp[0].symbol)->getDataType()=="void"){
				error_count++;
				//fprintf(error_output, "Line# %d: Void function used in expression\n", line_count);
			}
			(yyval.symbol) = new SymbolInfo((yyvsp[-2].symbol)->getName()+(yyvsp[-1].symbol)->getName()+(yyvsp[0].symbol)->getName(), "int");
			(yyval.symbol)->setDataType("int");
			(yyval.symbol)->setChildren({(yyvsp[-2].symbol),(yyvsp[-1].symbol),(yyvsp[0].symbol)});
			(yyval.symbol)->setLeftPart("rel_expression");
			(yyval.symbol)->setRightPart("simple_expression RELOP simple_expression	");
			(yyval.symbol)->setStart((yyvsp[-2].symbol)->getStart());
			(yyval.symbol)->setEnd((yyvsp[0].symbol)->getEnd());
			fprintf(log_output, "rel_expression : simple_expression RELOP simple_expression\n", line_count);
		}
#line 2571 "y.tab.c"
    break;

  case 51: /* simple_expression: term  */
#line 1031 "1905077.y"
                         {

		    (yyval.symbol) = new SymbolInfo((yyvsp[0].symbol)->getName(), "simple_expression");
			(yyval.symbol)->setDataType((yyvsp[0].symbol)->getDataType());
			(yyval.symbol)->setArraySize((yyvsp[0].symbol)->getArraySize());
			(yyval.symbol)->setChildren({(yyvsp[0].symbol)});
			(yyval.symbol)->setLeftPart("simple_expression");
			(yyval.symbol)->setRightPart("term");
			(yyval.symbol)->setStart((yyvsp[0].symbol)->getStart());
			(yyval.symbol)->setEnd((yyvsp[0].symbol)->getEnd());
			fprintf(log_output, "Line# %d: simple_expression : term\n", line_count);


		//fprintf(error_output, "Line# %d: %s found \n",line_count, $1->getDataType().c_str() );
			
}
#line 2592 "y.tab.c"
    break;

  case 52: /* simple_expression: simple_expression ADDOP term  */
#line 1047 "1905077.y"
                                                 {

			string exprType;
			

			if( ((yyvsp[0].symbol)->getDataType()=="int") && ((yyvsp[-2].symbol)->getDataType()=="int")) exprType= "int"; 
			else exprType= "float";
			if ((yyvsp[-2].symbol)->getDataType()=="void" || (yyvsp[0].symbol)->getDataType()=="void"){
				error_count++;
				//fprintf(error_output, "Line# %d: Void function used in expression \n", line_count);
				exprType="void";
			}

			(yyval.symbol) = new SymbolInfo((yyvsp[-2].symbol)->getName()+(yyvsp[-1].symbol)->getName()+(yyvsp[0].symbol)->getName(), "simple_expression");
			(yyval.symbol)->setDataType(exprType);
			(yyval.symbol)->setChildren({(yyvsp[-2].symbol), (yyvsp[-1].symbol), (yyvsp[0].symbol)});
			(yyval.symbol)->setLeftPart("simple_expression");
			(yyval.symbol)->setRightPart("simple_expression ADDOP term");
			(yyval.symbol)->setStart((yyvsp[-2].symbol)->getStart());
			(yyval.symbol)->setEnd((yyvsp[0].symbol)->getEnd());	
			fprintf(log_output, "simple_expression : simple_expression ADDOP term\n", line_count);
		  }
#line 2619 "y.tab.c"
    break;

  case 53: /* term: unary_expression  */
#line 1071 "1905077.y"
                        {

		(yyval.symbol)=new SymbolInfo((yyvsp[0].symbol)->getName(), "term");
		(yyval.symbol)->setDataType((yyvsp[0].symbol)->getDataType());
		(yyval.symbol)->setArraySize((yyvsp[0].symbol)->getArraySize());
		(yyval.symbol)->setChildren({(yyvsp[0].symbol)});
		(yyval.symbol)->setLeftPart("term");
		(yyval.symbol)->setRightPart("unary_expression");
		(yyval.symbol)->setStart((yyvsp[0].symbol)->getStart());
		(yyval.symbol)->setEnd((yyvsp[0].symbol)->getEnd());
		
		fprintf(log_output, "term : unary_expression\n", line_count);

}
#line 2638 "y.tab.c"
    break;

  case 54: /* term: term MULOP unary_expression  */
#line 1085 "1905077.y"
                                   {

		(yyval.symbol) = new SymbolInfo((yyvsp[-2].symbol)->getName()+(yyvsp[-1].symbol)->getName()+(yyvsp[0].symbol)->getName(),"term");
		(yyval.symbol)->setChildren({(yyvsp[-2].symbol), (yyvsp[-1].symbol),(yyvsp[0].symbol)});
		(yyval.symbol)->setLeftPart("term");
		(yyval.symbol)->setRightPart("term MULOP unary_expression");
		(yyval.symbol)->setStart((yyvsp[-2].symbol)->getStart());
		(yyval.symbol)->setEnd((yyvsp[0].symbol)->getEnd());
		if((yyvsp[-1].symbol)->getName()=="%"){ 
			if(((yyvsp[-2].symbol)->getDataType()=="void") || ((yyvsp[0].symbol)->getDataType()=="void")){
				
					error_count++;
					fprintf(error_output, "Line# %d: Void cannot be used in an expression\n", line_count);
					(yyval.symbol)->setDataType("void");
				
			}
			if(((yyvsp[-2].symbol)->getDataType()=="int") && ((yyvsp[0].symbol)->getDataType()=="int")){
				if((yyvsp[0].symbol)->getName()=="0"){ 
					error_count++;
					fprintf(error_output, "Line# %d: Division by Zero\n", line_count);
				}
			}
			else { 
				error_count++;
				fprintf(error_output, "Line# %d: Operands of modulus must be integers\n", line_count);
				fprintf(log_output, "Line# %d: Operands of modulus must be integers", line_count);
				
			}
			(yyval.symbol)->setDataType("int");
			
		}
		else if((yyvsp[-1].symbol)->getName()=="/"){
			if(((yyvsp[-2].symbol)->getDataType()=="void") && ((yyvsp[0].symbol)->getDataType()=="void")){
				
					error_count++;
					//fprintf(error_output, "Line# %d: Void cannot be used in an expression\n", line_count);
				
				
			}
			if((yyvsp[0].symbol)->getName()=="0"){ 
					error_count++;
					fprintf(error_output, "Line# %d: Division by Zero\n", line_count);
				
				}
				else{
					if(((yyvsp[-2].symbol)->getDataType()=="int")&&((yyvsp[0].symbol)->getDataType()=="int")){
					(yyval.symbol)->setDataType("int");
					}
					else {
						(yyval.symbol)->setDataType("float");
					}
				}
		}
		else{
			
			if(((yyvsp[-2].symbol)->getDataType()=="int")&&((yyvsp[0].symbol)->getDataType()=="int")){
				(yyval.symbol)->setDataType("int");
			}
			else {
			(yyval.symbol)->setDataType("float");
			}
			if(((yyvsp[-2].symbol)->getDataType()=="void") || ((yyvsp[0].symbol)->getDataType()=="void")){
				
					error_count++;
					//fprintf(error_output, "Line# %d: Void cannot be used in an expression\n", line_count);
					
					(yyval.symbol)->setDataType("void");
				
			}
			
		}
		fprintf(log_output, "term : term MULOP unary_expression\n" );

	 }
#line 2717 "y.tab.c"
    break;

  case 55: /* unary_expression: ADDOP unary_expression  */
#line 1161 "1905077.y"
                                          {

			(yyval.symbol) = new SymbolInfo((yyvsp[-1].symbol)->getName()+(yyvsp[0].symbol)->getName(), "unary_expression");
			(yyval.symbol)->setDataType((yyvsp[0].symbol)->getDataType());
			(yyval.symbol)->setChildren({(yyvsp[-1].symbol),(yyvsp[0].symbol)});
			(yyval.symbol)->setLeftPart("unary_expression");
			(yyval.symbol)->setRightPart("ADDOP unary_expression");
			(yyval.symbol)->setStart((yyvsp[-1].symbol)->getStart());
			(yyval.symbol)->setEnd((yyvsp[0].symbol)->getEnd());
			fprintf(log_output, "unary_expression : ADDOP unary_expression\n");
}
#line 2733 "y.tab.c"
    break;

  case 56: /* unary_expression: NOT unary_expression  */
#line 1172 "1905077.y"
                                        {
			
			(yyval.symbol) = new SymbolInfo("!"+(yyvsp[0].symbol)->getName(), "unary_expression");
			(yyval.symbol)->setDataType((yyvsp[0].symbol)->getDataType());
			(yyval.symbol)->setDataType("int");
			(yyval.symbol)->setChildren({(yyvsp[-1].symbol),(yyvsp[0].symbol)});
			(yyval.symbol)->setLeftPart("unary_expression");
			(yyval.symbol)->setRightPart("NOT unary_expression");
			(yyval.symbol)->setStart((yyvsp[-1].symbol)->getStart());
			(yyval.symbol)->setEnd((yyvsp[0].symbol)->getEnd());
			fprintf(log_output, "unary_expression : NOT unary_expression\n");
		 }
#line 2750 "y.tab.c"
    break;

  case 57: /* unary_expression: factor  */
#line 1184 "1905077.y"
                          {

			(yyval.symbol) = new SymbolInfo((yyvsp[0].symbol)->getName(),"unary_expression");
			(yyval.symbol)->setDataType((yyvsp[0].symbol)->getDataType());
			(yyval.symbol)->setArraySize((yyvsp[0].symbol)->getArraySize());
			(yyval.symbol)->setChildren({(yyvsp[0].symbol)});
			(yyval.symbol)->setLeftPart("unary_expression");
			(yyval.symbol)->setRightPart("ADDOP unary_expression");
			(yyval.symbol)->setStart((yyvsp[0].symbol)->getStart());
			(yyval.symbol)->setEnd((yyvsp[0].symbol)->getEnd());
			fprintf(log_output, "unary_expression : factor\n");

		 }
#line 2768 "y.tab.c"
    break;

  case 58: /* factor: variable  */
#line 1199 "1905077.y"
                   {

		(yyval.symbol)=new SymbolInfo("("+(yyvsp[0].symbol)->getName()+")", "factor");
		(yyval.symbol)->setDataType((yyvsp[0].symbol)->getDataType());
		(yyval.symbol)->setArraySize((yyvsp[0].symbol)->getArraySize());
		(yyval.symbol)->setChildren({(yyvsp[0].symbol)});
		(yyval.symbol)->setLeftPart("factor");
		(yyval.symbol)->setRightPart("variable");
		(yyval.symbol)->setStart((yyvsp[0].symbol)->getStart());
		(yyval.symbol)->setEnd((yyvsp[0].symbol)->getEnd());
		fprintf(log_output, "factor : variable\n");
}
#line 2785 "y.tab.c"
    break;

  case 59: /* factor: ID LPAREN argument_list RPAREN  */
#line 1211 "1905077.y"
                                        {
		
            (yyval.symbol) = new SymbolInfo((string)(yyvsp[-3].symbol)->getName()+(string)"("+(string)(yyvsp[-1].symbol)->getName()+(string)")", "factor");
			(yyval.symbol)->setChildren({(yyvsp[-3].symbol),(yyvsp[-2].symbol),(yyvsp[-1].symbol),(yyvsp[0].symbol)});
					(yyval.symbol)->setLeftPart("factor");
					(yyval.symbol)->setRightPart("ID LPAREN argument_list RPAREN");
					(yyval.symbol)->setStart((yyvsp[-3].symbol)->getStart());
					(yyval.symbol)->setEnd((yyvsp[0].symbol)->getEnd());
			SymbolInfo* temp = table.lookUpSymbol((yyvsp[-3].symbol)->getName());
			

            if(temp == nullptr) {
                error_count++;
				fprintf(error_output, "Line# %d: Undeclared function \'%s\' \n", line_count, (yyvsp[-3].symbol)->getName().c_str());
                //$$->setDataType("float");  

            }
			else{
				if(temp->isDefined()){
					vector<pair<string,string>> declaredParameter=temp->getParameterList();
					
					if(temp->getParameterListSize()==1 && argumentList.size()==0 && declaredParameter[0].second=="void") {
                    (yyval.symbol)->setDataType(temp->getDataType());

                	}
					if(temp->getParameterListSize() > argumentList.size()) {
                    
                    error_count++;
					fprintf(error_output, "Line# %d: Too few arguments to function \'%s\'\n", line_count, temp->getName().c_str());
                   // $$->setDataType("float"); 

               		 }
					else if(temp->getParameterListSize() < argumentList.size()) {
                    
                    error_count++;

					fprintf(error_output, "Line# %d: Too many arguments to function \'%s\'\n", line_count, temp->getName().c_str());
                    //$$->setDataType("float"); 

                	}
				 	else {
                   
						bool err=false;
					
                    	for(int i=0; i<argumentList.size(); i++) {
                        if(declaredParameter[i].second != argumentList[i].getDataType()) {
                            err=true;
							fprintf(error_output, "Line# %d: Type mismatch for argument %d of \'%s\'\n", line_count, i+1,temp->getName().c_str());
                        	
                        }
						if(argumentList[i].isArray()) {
                            err=true;
							fprintf(error_output, "Line# %d: Type mismatch for argument %d of \'%s\'\n", line_count, i+1,temp->getName().c_str());
                        	
                        }
						
                    }

                    if(err) {
						error_count++;
                       // $$->setDataType("float");  

                    } else {
                        (yyval.symbol)->setDataType(temp->getDataType());
                    }
                } 
				}
				else{
				error_count++;
				fprintf(error_output, "Line# %d: Inconsistent function call\n", line_count);
                //$$->setDataType("float");  
				}
			}
			fprintf(log_output, "Line# %d: factor : ID LPAREN argument_list RPAREN\n");
			argumentList.clear();
	}
#line 2866 "y.tab.c"
    break;

  case 60: /* factor: LPAREN expression RPAREN  */
#line 1287 "1905077.y"
                                  {
		(yyval.symbol) = new SymbolInfo("("+(yyvsp[-1].symbol)->getName()+")", "factor");
		(yyval.symbol)->setDataType((yyvsp[-1].symbol)->getDataType());
		(yyval.symbol)->setChildren({(yyvsp[-2].symbol),(yyvsp[-1].symbol),(yyvsp[0].symbol)});
		(yyval.symbol)->setLeftPart("factor");
		(yyval.symbol)->setRightPart("LPAREN expression RPAREN");
		(yyval.symbol)->setStart((yyvsp[-2].symbol)->getStart());
		(yyval.symbol)->setEnd((yyvsp[0].symbol)->getEnd());
		
		fprintf(log_output, "Line# %d: factor : LPAREN expression RPAREN\n", line_count, (yyval.symbol)->getName().c_str());
	}
#line 2882 "y.tab.c"
    break;

  case 61: /* factor: CONST_INT  */
#line 1298 "1905077.y"
                    {

		(yyval.symbol) = new SymbolInfo((yyvsp[0].symbol)->getName(), "factor");
		(yyval.symbol)->setDataType("int");
		(yyval.symbol)->setChildren({(yyvsp[0].symbol)});
		(yyval.symbol)->setLeftPart("factor");
		(yyval.symbol)->setRightPart("CONST_INT");
		(yyval.symbol)->setStart((yyvsp[0].symbol)->getStart());
		(yyval.symbol)->setEnd((yyvsp[0].symbol)->getEnd());
		fprintf(log_output, "factor : CONST_INT\n");
	}
#line 2898 "y.tab.c"
    break;

  case 62: /* factor: CONST_FLOAT  */
#line 1309 "1905077.y"
                     {

		(yyval.symbol) = new SymbolInfo((yyvsp[0].symbol)->getName(), "factor");

		(yyval.symbol)->setDataType("float");
		(yyval.symbol)->setChildren({(yyvsp[0].symbol)});
		(yyval.symbol)->setLeftPart("factor");
		(yyval.symbol)->setRightPart("CONST_FLOAT");
		(yyval.symbol)->setStart((yyvsp[0].symbol)->getStart());
		(yyval.symbol)->setEnd((yyvsp[0].symbol)->getEnd());
		fprintf(log_output, "factor : CONST_FLOAT\n");
	}
#line 2915 "y.tab.c"
    break;

  case 63: /* factor: variable INCOP  */
#line 1321 "1905077.y"
                         {

		(yyval.symbol) = new SymbolInfo((yyvsp[-1].symbol)->getName()+"++","variable");
		(yyval.symbol)->setDataType((yyvsp[-1].symbol)->getDataType());
		(yyval.symbol)->setChildren({(yyvsp[-1].symbol),(yyvsp[0].symbol)});
		(yyval.symbol)->setLeftPart("factor");
		(yyval.symbol)->setRightPart("variable INCOP");
		(yyval.symbol)->setStart((yyvsp[-1].symbol)->getStart());
		(yyval.symbol)->setEnd((yyvsp[0].symbol)->getEnd());
		fprintf(log_output, "factor : variable INCOP\n");
	}
#line 2931 "y.tab.c"
    break;

  case 64: /* factor: variable DECOP  */
#line 1332 "1905077.y"
                        {

		(yyval.symbol) = new SymbolInfo((yyvsp[-1].symbol)->getName()+"++","variable");
		(yyval.symbol)->setDataType((yyvsp[-1].symbol)->getDataType());
		(yyval.symbol)->setChildren({(yyvsp[-1].symbol),(yyvsp[0].symbol)});
		(yyval.symbol)->setLeftPart("factor");
		(yyval.symbol)->setRightPart("variable DECOP");
		(yyval.symbol)->setStart((yyvsp[-1].symbol)->getStart());
		(yyval.symbol)->setEnd((yyvsp[0].symbol)->getEnd());
		fprintf(log_output, "factor : variable DECOP\n");
	}
#line 2947 "y.tab.c"
    break;

  case 65: /* argument_list: arguments  */
#line 1345 "1905077.y"
                         {

				(yyval.symbol) = new SymbolInfo((yyvsp[0].symbol)->getName(), "argument_list");

				fprintf(log_output, "argument_list : arguments\n");
				(yyval.symbol)->setChildren({(yyvsp[0].symbol)});
				(yyval.symbol)->setLeftPart("argument_list");
				(yyval.symbol)->setRightPart("arguments");
				(yyval.symbol)->setStart((yyvsp[0].symbol)->getStart());
				(yyval.symbol)->setEnd((yyvsp[0].symbol)->getEnd());
}
#line 2963 "y.tab.c"
    break;

  case 66: /* argument_list: %empty  */
#line 1356 "1905077.y"
                           {

				(yyval.symbol)=new SymbolInfo("", "argument_list");
				(yyval.symbol)->setChildren({});
				(yyval.symbol)->setLeftPart("argument_list");
				(yyval.symbol)->setRightPart("");
				(yyval.symbol)->setStart(line_count);
				(yyval.symbol)->setEnd(line_count);
				fprintf(log_output, "argument_list : \n");
			  }
#line 2978 "y.tab.c"
    break;

  case 67: /* arguments: arguments COMMA logic_expression  */
#line 1368 "1905077.y"
                                            {

				(yyval.symbol) = new SymbolInfo((yyvsp[-2].symbol)->getName()+","+(yyvsp[0].symbol)->getName(), "arguments");
				fprintf(log_output, "arguments : arguments COMMA logic_expression\n");
				//$$->setDataType($3->getDataType());
				SymbolInfo s("",(yyvsp[0].symbol)->getDataType());
				s.setDataType((yyvsp[0].symbol)->getDataType());
				s.setArraySize((yyvsp[0].symbol)->getArraySize());
				(yyval.symbol)->setChildren({(yyvsp[-2].symbol),(yyvsp[-1].symbol),(yyvsp[0].symbol)});
				(yyval.symbol)->setLeftPart("arguments");
				(yyval.symbol)->setRightPart("arguments COMMA logic_expression");
				(yyval.symbol)->setStart((yyvsp[-2].symbol)->getStart());
				(yyval.symbol)->setEnd((yyvsp[0].symbol)->getEnd());
				argumentList.push_back(s);
}
#line 2998 "y.tab.c"
    break;

  case 68: /* arguments: logic_expression  */
#line 1383 "1905077.y"
                                {
				(yyval.symbol) = new SymbolInfo((yyvsp[0].symbol)->getName(), "arguments");
				//$$->setDataType($1->getDataType());
				fprintf(log_output, "arguments : logic_expression\n");
				SymbolInfo s("",(yyvsp[0].symbol)->getDataType());
				s.setDataType((yyvsp[0].symbol)->getDataType());
				s.setArraySize((yyvsp[0].symbol)->getArraySize());
				(yyval.symbol)->setChildren({(yyvsp[0].symbol)});
				(yyval.symbol)->setLeftPart("arguments");
				(yyval.symbol)->setRightPart("logic_expression");
				(yyval.symbol)->setStart((yyvsp[0].symbol)->getStart());
				(yyval.symbol)->setEnd((yyvsp[0].symbol)->getEnd());
				argumentList.push_back(s);
		  }
#line 3017 "y.tab.c"
    break;


#line 3021 "y.tab.c"

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
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturn;
#endif


/*-------------------------------------------------------.
| yyreturn -- parsing is finished, clean up and return.  |
`-------------------------------------------------------*/
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 1400 "1905077.y"

int main(int argc,char *argv[])
{

	if((fp=fopen(argv[1],"r"))==NULL)
	{
		printf("Cannot Open Input File.\n");
		exit(1);
	}

	log_output= fopen("log_output.txt","w");
	error_output= fopen("error_output.txt","w");
	parse_tree.open("parse_tree.txt",ios::out);


	yyin=fp;
	yyparse();
	
	
	fclose(log_output);
	fclose(error_output);
	parse_tree.close();
	
	return 0;
}

