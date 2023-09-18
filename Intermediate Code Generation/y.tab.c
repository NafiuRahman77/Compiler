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

// Offline 4 code
FILE *asmout;
ifstream asmly;
ofstream optimizely;
// int lineNumber=0;
vector<string> lineVector(1000);
int tempCount=0;
int labelCount=0;
int currentOffset=0; // offset from BP of that particular variable
int parameterCount=0;
bool isMainDefined=false;
string currentFunc="";

void printUtilFunctions() { fprintf(asmout, "\nPRINT PROC ; PRINTS A WORD INTEGER IN AX\nLEA SI, NUMBER_STRING ; IS 00000\nADD SI, 5 ; START FROM ONE'S DIGIT\nCMP AX, 0\nJNL PRINT_LOOP\nMOV FLAG, 1\nNEG AX\nPRINT_LOOP:\nDEC SI\nMOV DX, 0 ; DX:AX = 0000:AX\nMOV CX, 10\nDIV CX\nADD DL, '0'\nMOV [SI], DL\nCMP AX, 0\nJNE PRINT_LOOP\nCMP FLAG, 0\nJNG NOT_NEGATIVE\nMOV AH, 2\nMOV DL, 45\nINT 21H\nMOV FLAG, 0\nNOT_NEGATIVE:\nMOV DX, SI\nMOV AH, 9\nINT 21H\nMOV DX, OFFSET NL ; NEWLINE\nMOV AH, 9\nINT 21H\nRET\nPRINT ENDP\n"); }

void resetCurrentOffset(){
	currentOffset=0;
}

string newTemp() {
	return "temp_"+to_string(tempCount++);
}

string newLabel() {
	return "label_"+to_string(labelCount++);
}

int ifCount=0;
int whileCount=0;
int forCount=0;

stack<int> ifCountStack;
stack<int> whileCountStack;
stack<int> forCountStack;


void yyerror(char *s)
{
	//write your code
}

#line 159 "y.tab.c"

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
#line 89 "1905077.y"

	SymbolInfo* symbol;

#line 296 "y.tab.c"

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
  YYSYMBOL_43_1 = 43,                      /* $@1  */
  YYSYMBOL_program = 44,                   /* program  */
  YYSYMBOL_unit = 45,                      /* unit  */
  YYSYMBOL_func_declaration = 46,          /* func_declaration  */
  YYSYMBOL_func_definition = 47,           /* func_definition  */
  YYSYMBOL_48_2 = 48,                      /* $@2  */
  YYSYMBOL_49_3 = 49,                      /* $@3  */
  YYSYMBOL_parameter_list = 50,            /* parameter_list  */
  YYSYMBOL_compound_statement = 51,        /* compound_statement  */
  YYSYMBOL_52_4 = 52,                      /* $@4  */
  YYSYMBOL_53_5 = 53,                      /* $@5  */
  YYSYMBOL_var_declaration = 54,           /* var_declaration  */
  YYSYMBOL_type_specifier = 55,            /* type_specifier  */
  YYSYMBOL_declaration_list = 56,          /* declaration_list  */
  YYSYMBOL_statements = 57,                /* statements  */
  YYSYMBOL_statement = 58,                 /* statement  */
  YYSYMBOL_expression_statement = 59,      /* expression_statement  */
  YYSYMBOL_variable = 60,                  /* variable  */
  YYSYMBOL_expression = 61,                /* expression  */
  YYSYMBOL_logic_expression = 62,          /* logic_expression  */
  YYSYMBOL_rel_expression = 63,            /* rel_expression  */
  YYSYMBOL_simple_expression = 64,         /* simple_expression  */
  YYSYMBOL_term = 65,                      /* term  */
  YYSYMBOL_unary_expression = 66,          /* unary_expression  */
  YYSYMBOL_factor = 67,                    /* factor  */
  YYSYMBOL_argument_list = 68,             /* argument_list  */
  YYSYMBOL_arguments = 69                  /* arguments  */
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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   149

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  41
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  29
/* YYNRULES -- Number of rules.  */
#define YYNRULES  69
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  123

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
       0,   102,   102,   102,   118,   122,   128,   133,   138,   145,
     178,   210,   210,   354,   354,   435,   443,   451,   459,   470,
     470,   496,   496,   520,   608,   616,   622,   631,   638,   645,
     652,   662,   666,   672,   676,   680,   684,   688,   697,   707,
     716,   725,   747,   757,   769,   812,   854,   867,   913,   924,
     948,   959,   976,   992,  1016,  1030,  1106,  1117,  1129,  1144,
    1156,  1232,  1243,  1254,  1266,  1277,  1290,  1301,  1313,  1328
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
  "$accept", "start", "$@1", "program", "unit", "func_declaration",
  "func_definition", "$@2", "$@3", "parameter_list", "compound_statement",
  "$@4", "$@5", "var_declaration", "type_specifier", "declaration_list",
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

#define YYPACT_NINF (-76)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-22)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
     -76,    16,    46,   -76,   -76,   -76,   -76,    46,   -76,   -76,
     -76,   -76,    -7,   -76,    11,    53,     7,   -15,   -76,     5,
      23,    21,    14,    30,    34,   -76,    44,    46,    60,   -76,
     -76,    45,    57,   -76,    52,   -76,    44,    62,   103,    59,
     -76,   -76,   -76,    65,    70,    71,   110,    72,   110,   -76,
     110,    28,   110,   -76,   -76,   -76,   -76,    64,    66,   -76,
     -76,   -10,    76,   -76,    75,    -5,    67,   -76,   -76,   -76,
     110,    27,   110,    79,    74,    50,   -76,    78,   110,   110,
     -76,    85,   -76,   -76,   110,   -76,   -76,   -76,   110,   110,
     110,   110,    92,    27,    93,   -76,    94,   -76,   -76,    95,
      98,    97,   -76,   -76,    67,    88,   -76,   103,   110,   103,
     101,   -76,   110,   -76,   124,   105,   -76,   -76,   -76,   103,
     103,   -76,   -76
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,     0,     1,    24,    25,    26,     3,     5,     7,
       8,     6,     0,     4,    29,     0,     0,     0,    23,     0,
      13,     0,    18,     0,    27,    10,     0,     0,    11,    17,
      30,     0,    19,    14,    16,     9,     0,     0,     0,     0,
      15,    12,    28,     0,     0,     0,     0,     0,     0,    42,
       0,    44,     0,    62,    63,    35,    33,     0,     0,    31,
      34,    59,     0,    46,    48,    50,    52,    54,    58,    22,
       0,     0,     0,     0,     0,    59,    57,     0,    67,     0,
      56,    29,    20,    32,     0,    64,    65,    43,     0,     0,
       0,     0,     0,     0,     0,    41,     0,    61,    69,     0,
      66,     0,    47,    49,    53,    51,    55,     0,     0,     0,
       0,    60,     0,    45,    37,     0,    39,    40,    68,     0,
       0,    38,    36
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -76,   -76,   -76,   -76,   125,   -76,   -76,   -76,   -76,   -76,
      -8,   -76,   -76,    10,     6,   -76,   -76,   -52,   -69,   -48,
     -45,   -75,    47,    43,    49,   -41,   -76,   -76,   -76
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     1,     2,     7,     8,     9,    10,    36,    26,    21,
      55,    38,    39,    56,    57,    15,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    99,   100
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      75,    73,    93,    98,    75,    77,    83,    76,    12,   102,
      84,    80,    11,    12,     4,     5,     3,    11,    33,     6,
      85,    86,    22,    23,   108,    92,    14,    94,    41,    89,
      75,    90,    20,    34,   101,    16,    75,   118,    24,    17,
      75,    75,    75,    75,    27,    25,    28,    29,    48,    49,
     106,    50,    78,     4,     5,   114,    79,   116,     6,    30,
      51,    52,    31,   115,    75,    53,    54,   121,   122,    43,
      32,    44,    45,     4,     5,    18,    19,    46,     6,    47,
      85,    86,    35,    37,   -21,    40,    69,    48,    49,    70,
      50,    42,    32,    82,    71,    72,    74,    81,    87,    51,
      52,    95,    91,    97,    53,    54,    43,    96,    44,    45,
       4,     5,    88,    17,    46,     6,    47,   107,   109,   110,
     111,   112,    89,   117,    48,    49,   113,    50,   119,    32,
     120,    48,    13,   105,    50,   103,    51,    52,   104,     0,
       0,    53,    54,    51,    52,     0,     0,     0,    53,    54
};

static const yytype_int8 yycheck[] =
{
      48,    46,    71,    78,    52,    50,    58,    48,     2,    84,
      20,    52,     2,     7,     7,     8,     0,     7,    26,    12,
      30,    31,    16,    38,    93,    70,    33,    72,    36,    34,
      78,    36,    25,    27,    79,    24,    84,   112,    33,    28,
      88,    89,    90,    91,    23,    22,    25,    33,    21,    22,
      91,    24,    24,     7,     8,   107,    28,   109,    12,    29,
      33,    34,    28,   108,   112,    38,    39,   119,   120,     3,
      26,     5,     6,     7,     8,    22,    23,    11,    12,    13,
      30,    31,    22,    38,    27,    33,    27,    21,    22,    24,
      24,    29,    26,    27,    24,    24,    24,    33,    22,    33,
      34,    22,    35,    25,    38,    39,     3,    33,     5,     6,
       7,     8,    37,    28,    11,    12,    13,    25,    25,    25,
      25,    23,    34,    22,    21,    22,    29,    24,     4,    26,
      25,    21,     7,    90,    24,    88,    33,    34,    89,    -1,
      -1,    38,    39,    33,    34,    -1,    -1,    -1,    38,    39
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    42,    43,     0,     7,     8,    12,    44,    45,    46,
      47,    54,    55,    45,    33,    56,    24,    28,    22,    23,
      25,    50,    55,    38,    33,    22,    49,    23,    25,    33,
      29,    28,    26,    51,    55,    22,    48,    38,    52,    53,
      33,    51,    29,     3,     5,     6,    11,    13,    21,    22,
      24,    33,    34,    38,    39,    51,    54,    55,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    27,
      24,    24,    24,    61,    24,    60,    66,    61,    24,    28,
      66,    33,    27,    58,    20,    30,    31,    22,    37,    34,
      36,    35,    61,    59,    61,    22,    33,    25,    62,    68,
      69,    61,    62,    63,    65,    64,    66,    25,    59,    25,
      25,    25,    23,    29,    58,    61,    58,    22,    62,     4,
      25,    58,    58
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    41,    43,    42,    44,    44,    45,    45,    45,    46,
      46,    48,    47,    49,    47,    50,    50,    50,    50,    52,
      51,    53,    51,    54,    55,    55,    55,    56,    56,    56,
      56,    57,    57,    58,    58,    58,    58,    58,    58,    58,
      58,    58,    59,    59,    60,    60,    61,    61,    62,    62,
      63,    63,    64,    64,    65,    65,    66,    66,    66,    67,
      67,    67,    67,    67,    67,    67,    68,    68,    69,    69
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     2,     1,     1,     1,     1,     6,
       5,     0,     7,     0,     6,     4,     3,     2,     1,     0,
       4,     0,     3,     3,     1,     1,     1,     3,     6,     1,
       4,     1,     2,     1,     1,     1,     7,     5,     7,     5,
       5,     3,     1,     2,     1,     4,     1,     3,     1,     3,
       1,     3,     1,     3,     1,     3,     2,     2,     1,     1,
       4,     3,     1,     1,     2,     2,     1,     0,     3,     1
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
  case 2: /* $@1: %empty  */
#line 102 "1905077.y"
       {
		fprintf(asmout, ".MODEL SMALL\n");
		fprintf(asmout, "\n.STACK 400H\n");
		fprintf(asmout, "\n.DATA\n\n");
		fprintf(asmout, "\n.CODE\n\tFLAG DB 0\n\tNL DB 13,10,\"$\"\n\tNUMBER_STRING DB \"00000$\" \n");
}
#line 1435 "y.tab.c"
    break;

  case 3: /* start: $@1 program  */
#line 108 "1905077.y"
        {
		//write your code in this block in all the similar blocks below
		(yyval.symbol) = new SymbolInfo("", "program");		
		fprintf(log_output, "start : program\n");
		printUtilFunctions();
		if(isMainDefined) fprintf(asmout, "END MAIN\n");
		
	}
#line 1448 "y.tab.c"
    break;

  case 4: /* program: program unit  */
#line 118 "1905077.y"
                      {
	    (yyval.symbol) = new SymbolInfo("","program");	
		fprintf(log_output, "program : program unit\n");
	}
#line 1457 "y.tab.c"
    break;

  case 5: /* program: unit  */
#line 122 "1905077.y"
              {
		(yyval.symbol) = new SymbolInfo("","program");
		fprintf(log_output, "program : unit\n");
	}
#line 1466 "y.tab.c"
    break;

  case 6: /* unit: var_declaration  */
#line 128 "1905077.y"
                      {

		(yyval.symbol) =  new SymbolInfo("","program");
		fprintf(log_output, "unit : var_declaration\n");
	}
#line 1476 "y.tab.c"
    break;

  case 7: /* unit: func_declaration  */
#line 133 "1905077.y"
                       {

		(yyval.symbol) =  new SymbolInfo("","program");
		fprintf(log_output, "unit : func_declaration\n");
	 }
#line 1486 "y.tab.c"
    break;

  case 8: /* unit: func_definition  */
#line 138 "1905077.y"
                      {

		(yyval.symbol) =  new SymbolInfo("","program");
		fprintf(log_output, "unit : func_definition\n");
	 }
#line 1496 "y.tab.c"
    break;

  case 9: /* func_declaration: type_specifier ID LPAREN parameter_list RPAREN SEMICOLON  */
#line 145 "1905077.y"
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
			
			(yyval.symbol) = new SymbolInfo("","func_declaration");
			fprintf(log_output, "func_declaration : type_specifier ID LPAREN parameter_list RPAREN SEMICOLON\n");

           	params.clear();
}
#line 1534 "y.tab.c"
    break;

  case 10: /* func_declaration: type_specifier ID LPAREN RPAREN SEMICOLON  */
#line 178 "1905077.y"
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
			(yyval.symbol) = new SymbolInfo("","func_declaration");
			fprintf(log_output, "func_declaration : type_specifier ID LPAREN RPAREN SEMICOLON\n");
            params.clear();
		}
#line 1569 "y.tab.c"
    break;

  case 11: /* $@2: %empty  */
#line 210 "1905077.y"
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

	}
	fprintf(asmout, "\n%s PROC\n", functionName.c_str());
	fprintf(asmout, "\tPUSH BP\n\tMOV BP, SP\n");


}
#line 1708 "y.tab.c"
    break;

  case 12: /* func_definition: type_specifier ID LPAREN parameter_list RPAREN $@2 compound_statement  */
#line 343 "1905077.y"
                    {
		(yyval.symbol)=new SymbolInfo("", "func_definition");
		fprintf(log_output, "func_definition :type_specifier ID LPAREN parameter_list RPAREN compound_statement \n");
		resetCurrentOffset();
		fprintf(asmout, "%s_EXIT:\n", (yyvsp[-5].symbol)->getName().c_str());
		fprintf(asmout, "\tMOV SP, BP ; Restoring SP\n");
		fprintf(asmout, "\tPOP BP\n");
		fprintf(asmout, "\tRET %d\n", 2*parameterCount);
		fprintf(asmout, "%s ENDP\n", (yyvsp[-5].symbol)->getName().c_str());

}
#line 1724 "y.tab.c"
    break;

  case 13: /* $@3: %empty  */
#line 354 "1905077.y"
                                  {
	   string functionType = (yyvsp[-3].symbol)->getName();
       string functionName = (yyvsp[-2].symbol)->getName();  
	   if(functionName == "main") isMainDefined=true;  
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
	fprintf(asmout, "\n%s PROC\n", functionName.c_str());
	if(functionName=="main") {
		fprintf(asmout, "\tMOV AX, @DATA\n\tMOV DS, AX\n");
	}
	fprintf(asmout, "PUSH BP\nMOV BP, SP\n");


	}
#line 1789 "y.tab.c"
    break;

  case 14: /* func_definition: type_specifier ID LPAREN RPAREN $@3 compound_statement  */
#line 413 "1905077.y"
                           {

			(yyval.symbol)=new SymbolInfo("", "func_definition");

			fprintf(log_output, "func_definition :type_specifier ID LPAREN RPAREN compound_statement \n");
			resetCurrentOffset();
			fprintf(asmout, "%s_EXIT:\n", (yyvsp[-4].symbol)->getName().c_str());
			fprintf(asmout, "\tMOV SP, BP ; Restoring SP\n");
			fprintf(asmout, "\tPOP BP\n");
			if((yyvsp[-4].symbol)->getName()=="main") {
				fprintf(asmout, "\tMOV AH, 4CH\n\tINT 21H\n");
			} else {
				fprintf(asmout, "\tRET\n");
			}

			fprintf(asmout, "%s ENDP\n", (yyvsp[-4].symbol)->getName().c_str());

		}
#line 1812 "y.tab.c"
    break;

  case 15: /* parameter_list: parameter_list COMMA type_specifier ID  */
#line 435 "1905077.y"
                                                        {

			(yyval.symbol) = new SymbolInfo((yyvsp[-3].symbol)->getName() + "," + (yyvsp[-1].symbol)->getName() + " " + (yyvsp[0].symbol)->getName(), "parameter_list"); 
			SymbolInfo s((yyvsp[0].symbol)->getName(),(yyvsp[-1].symbol)->getDataType());   
			s.setDataType((yyvsp[-1].symbol)->getDataType());         
            params.push_back(s);
			fprintf(log_output, "parameter_list : parameter_list COMMA type_specifier ID\n");
		}
#line 1825 "y.tab.c"
    break;

  case 16: /* parameter_list: parameter_list COMMA type_specifier  */
#line 443 "1905077.y"
                                                     {

			(yyval.symbol) = new SymbolInfo((yyvsp[-2].symbol)->getName() + "," + (yyvsp[0].symbol)->getName() , "parameter_list"); 
			SymbolInfo s("",(yyvsp[0].symbol)->getDataType()) ; 
			s.setDataType((yyvsp[0].symbol)->getDataType());    
            params.push_back(s);
			fprintf(log_output, "parameter_list : parameter_list COMMA type_specifier\n");
		}
#line 1838 "y.tab.c"
    break;

  case 17: /* parameter_list: type_specifier ID  */
#line 451 "1905077.y"
                                   {

			(yyval.symbol) = new SymbolInfo((yyvsp[-1].symbol)->getName() + " " + (yyvsp[0].symbol)->getName(), "parameter_list");    
			SymbolInfo s((yyvsp[0].symbol)->getName(),(yyvsp[-1].symbol)->getDataType()); 
			s.setDataType((yyvsp[-1].symbol)->getDataType());
            params.push_back(s);
			fprintf(log_output, "parameter_list : type_specifier ID\n");
		}
#line 1851 "y.tab.c"
    break;

  case 18: /* parameter_list: type_specifier  */
#line 459 "1905077.y"
                                {

			(yyval.symbol) = new SymbolInfo((yyvsp[0].symbol)->getName(), "parameter_list");
			SymbolInfo s("",(yyvsp[0].symbol)->getDataType());
			s.setDataType((yyvsp[0].symbol)->getDataType());
            params.push_back(s);
			fprintf(log_output, "parameter_list : type_specifier\n");
		}
#line 1864 "y.tab.c"
    break;

  case 19: /* $@4: %empty  */
#line 470 "1905077.y"
                          {
				table.enterScope();
				parameterCount= params.size();
                for(int i=0; i<params.size(); i++) {
					SymbolInfo* s=new SymbolInfo(params[i].getName(),params[i].getDataType());
					s->setStackOffset((params.size()-i-1)*2+4); // 2 for BP, 2 for ret address
					s->setGlobal(false);
					s->setDataType(params[i].getDataType());
					table.insertSymbol(s);
                }
				params.clear();
                
				}
#line 1882 "y.tab.c"
    break;

  case 20: /* compound_statement: LCURL $@4 statements RCURL  */
#line 482 "1905077.y"
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
#line 1901 "y.tab.c"
    break;

  case 21: /* $@5: %empty  */
#line 496 "1905077.y"
                           {
				table.enterScope();	
				parameterCount= params.size();		
                for(int i=0; i<params.size(); i++) {
				SymbolInfo* s=new SymbolInfo(params[i].getName(),params[i].getDataType());
				s->setStackOffset((params.size()-i-1)*2+4); // 2 for BP, 2 for ret address
				s->setGlobal(false);
				table.insertSymbol(s);	
            	}
				params.clear();
					
				}
#line 1918 "y.tab.c"
    break;

  case 22: /* compound_statement: LCURL $@5 RCURL  */
#line 507 "1905077.y"
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
#line 1934 "y.tab.c"
    break;

  case 23: /* var_declaration: type_specifier declaration_list SEMICOLON  */
#line 520 "1905077.y"
                                                           {

            (yyval.symbol) = new SymbolInfo("", "var_declaration");
            fprintf(log_output, "var_declaration: type_specifier declaration_list SEMICOLON\n");
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
					else{
						if(1==table.getCurrentScopeTable()->getID()) { // global
							fprintf(asmout, "%s DW %d DUP(?) ; %s[%d] decl\n", arrayName.c_str(), arraySize, arrayName.c_str(), arraySize);
						}
						else{
							for(int j=0; j<arraySize; j++){
								fprintf(asmout, "PUSH AX ; %s[%d] decl\n", arrayName.c_str(), arraySize-1-j);
								currentOffset-=2;
							}
							SymbolInfo* temp= table.lookUpSymbol(arrayName);
							temp->setStackOffset(currentOffset); // arrayName[arraySize - 1] is at currentOffset[BP]
							temp->setGlobal(false);
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
						else{
							if(1==table.getCurrentScopeTable()->getID()) { // global
								fprintf(asmout, "%s DW ? ; %s decl\n", vars[i].getName().c_str(), vars[i].getName().c_str());
							}
							else{
								fprintf(asmout, "PUSH AX ; %s decl\n", vars[i].getName().c_str());
								currentOffset-=2;
								SymbolInfo* temp= table.lookUpSymbol(vars[i].getName());
								temp->setStackOffset(currentOffset);
								temp->setGlobal(false);
							}
						}
					}
			}
				
			}
			
            vars.clear();
}
#line 2025 "y.tab.c"
    break;

  case 24: /* type_specifier: INT  */
#line 608 "1905077.y"
                     {

					(yyval.symbol) = new SymbolInfo( "int","type_specifier");
					string s="int";
                    (yyval.symbol)->setDataType("int");
                    type="int";
				    fprintf(log_output, "type_specifier : INT \n");
		}
#line 2038 "y.tab.c"
    break;

  case 25: /* type_specifier: FLOAT  */
#line 616 "1905077.y"
                       {
					(yyval.symbol) = new SymbolInfo( "float","type_specifier");
                   	(yyval.symbol)->setDataType("float");
                  	type="float";
                   	fprintf(log_output, "type_specifier : FLOAT \n");
		}
#line 2049 "y.tab.c"
    break;

  case 26: /* type_specifier: VOID  */
#line 622 "1905077.y"
                      {
					(yyval.symbol) = new SymbolInfo( "void","type_specifier");
                   	(yyval.symbol)->setDataType("void");
                    type="void";
                    fprintf(log_output, "type_specifier : VOID \n");
		}
#line 2060 "y.tab.c"
    break;

  case 27: /* declaration_list: declaration_list COMMA ID  */
#line 631 "1905077.y"
                                            {

					(yyval.symbol) = new SymbolInfo( (yyvsp[0].symbol)->getName(), "declaration_list");
					SymbolInfo s( (yyvsp[0].symbol)->getName(), "declaration_list");
                    vars.push_back(s);
					fprintf(log_output, "declaration_list : declaration_list COMMA ID\n");
			}
#line 2072 "y.tab.c"
    break;

  case 28: /* declaration_list: declaration_list COMMA ID LTHIRD CONST_INT RTHIRD  */
#line 638 "1905077.y"
                                                                     {
					(yyval.symbol) = new SymbolInfo( (yyvsp[-3].symbol)->getName() ,"declaration_list");
                    int size=stoi((yyvsp[-1].symbol)->getName());
					SymbolInfo s( (yyvsp[-3].symbol)->getName(), "declaration_list", size );
                    vars.push_back(s);
					fprintf(log_output, "declaration_list : declaration_list COMMA ID LTHIRD CONST_INT RTHIRD\n",  line_count);
					}
#line 2084 "y.tab.c"
    break;

  case 29: /* declaration_list: ID  */
#line 645 "1905077.y"
                      {
					(yyval.symbol) = new SymbolInfo((yyvsp[0].symbol)->getName(), "declaration_list");
					SymbolInfo s( (yyvsp[0].symbol)->getName(), "declaration_list");
                    vars.push_back(s);
                    name = (yyvsp[0].symbol)->getName();
					fprintf(log_output, "declaration_list : ID\n");
					}
#line 2096 "y.tab.c"
    break;

  case 30: /* declaration_list: ID LTHIRD CONST_INT RTHIRD  */
#line 652 "1905077.y"
                                              {
					(yyval.symbol) = new SymbolInfo((yyvsp[-3].symbol)->getName(),	"declaration_list");
                    int size=stoi((yyvsp[-1].symbol)->getName());
					SymbolInfo s( (yyvsp[-3].symbol)->getName(), "declaration_list", size );
                    vars.push_back(s);
                    name = (yyvsp[-3].symbol)->getName();			
					fprintf(log_output, "declaration_list : COMMA ID LTHIRD CONST_INT RTHIRD\n");
		  }
#line 2109 "y.tab.c"
    break;

  case 31: /* statements: statement  */
#line 662 "1905077.y"
                      {
					(yyval.symbol) = new SymbolInfo((string)(yyvsp[0].symbol)->getName(), "statements");
					fprintf(log_output, "statements : statement\n");
			}
#line 2118 "y.tab.c"
    break;

  case 32: /* statements: statements statement  */
#line 666 "1905077.y"
                                 {
					(yyval.symbol) = new SymbolInfo((yyvsp[-1].symbol)->getName() + " " + (yyvsp[0].symbol)->getName(), "statements");
					fprintf(log_output, "statements : statements statement\n");	
	   }
#line 2127 "y.tab.c"
    break;

  case 33: /* statement: var_declaration  */
#line 672 "1905077.y"
                           {
		(yyval.symbol)=new SymbolInfo((string)(yyvsp[0].symbol)->getName(), "statement");
		fprintf(log_output, "statement : var_declaration\n");	
}
#line 2136 "y.tab.c"
    break;

  case 34: /* statement: expression_statement  */
#line 676 "1905077.y"
                                {
		(yyval.symbol)=new SymbolInfo((string)(yyvsp[0].symbol)->getName(), "statement");
		fprintf(log_output, "statement : expression_statement\n");		
	  }
#line 2145 "y.tab.c"
    break;

  case 35: /* statement: compound_statement  */
#line 680 "1905077.y"
                              {
		(yyval.symbol) = new SymbolInfo((string)(yyvsp[0].symbol)->getName(), "statement");
		fprintf(log_output, "statement : compound_statement\n");
	  }
#line 2154 "y.tab.c"
    break;

  case 36: /* statement: FOR LPAREN expression_statement expression_statement expression RPAREN statement  */
#line 684 "1905077.y"
                                                                                            {
		(yyval.symbol) = new SymbolInfo("for("+(yyvsp[-4].symbol)->getName()+(yyvsp[-3].symbol)->getName()+(yyvsp[-2].symbol)->getName()+")"+(yyvsp[0].symbol)->getName(), "statement");
		fprintf(log_output, "statement : FOR LPAREN expression_statement expression_statement expression RPAREN statement\n");
	  }
#line 2163 "y.tab.c"
    break;

  case 37: /* statement: IF LPAREN expression RPAREN statement  */
#line 688 "1905077.y"
                                                                        {
		(yyval.symbol) = new SymbolInfo("if("+(yyvsp[-2].symbol)->getName()+")"+(yyvsp[0].symbol)->getName(), "statement");
		(yyval.symbol)->setChildren({(yyvsp[-4].symbol), (yyvsp[-3].symbol), (yyvsp[-2].symbol), (yyvsp[-1].symbol), (yyvsp[0].symbol)});
		(yyval.symbol)->setLeftPart("statement");
		(yyval.symbol)->setRightPart("IF LPAREN expression RPAREN statement");
		(yyval.symbol)->setStart((yyvsp[-4].symbol)->getStart());
		(yyval.symbol)->setEnd((yyvsp[0].symbol)->getEnd());
		fprintf(log_output, "statement : IF LPAREN expression RPAREN statement\n");
	  }
#line 2177 "y.tab.c"
    break;

  case 38: /* statement: IF LPAREN expression RPAREN statement ELSE statement  */
#line 697 "1905077.y"
                                                                {

		(yyval.symbol) = new SymbolInfo("if("+(yyvsp[-4].symbol)->getName()+")"+(yyvsp[-2].symbol)->getName()+ "else\n"+(yyvsp[0].symbol)->getName(), "statement");
		(yyval.symbol)->setChildren({(yyvsp[-6].symbol), (yyvsp[-5].symbol), (yyvsp[-4].symbol), (yyvsp[-3].symbol), (yyvsp[-2].symbol), (yyvsp[-1].symbol), (yyvsp[0].symbol)});
		(yyval.symbol)->setLeftPart("statement");
		(yyval.symbol)->setRightPart("IF LPAREN expression RPAREN statement ELSE statement");
		(yyval.symbol)->setStart((yyvsp[-6].symbol)->getStart());
		(yyval.symbol)->setEnd((yyvsp[0].symbol)->getEnd());
		fprintf(log_output, "statement : IF LPAREN expression RPAREN statement ELSE statement\n");
	  }
#line 2192 "y.tab.c"
    break;

  case 39: /* statement: WHILE LPAREN expression RPAREN statement  */
#line 707 "1905077.y"
                                                    {
		(yyval.symbol) = new SymbolInfo("while("+(yyvsp[-2].symbol)->getName()+")"+(yyvsp[0].symbol)->getName(), "statement");
		(yyval.symbol)->setChildren({(yyvsp[-4].symbol), (yyvsp[-3].symbol), (yyvsp[-2].symbol), (yyvsp[-1].symbol), (yyvsp[0].symbol)});
		(yyval.symbol)->setLeftPart("statement");
		(yyval.symbol)->setRightPart("WHILE LPAREN expression RPAREN statement");
		(yyval.symbol)->setStart((yyvsp[-4].symbol)->getStart());
		(yyval.symbol)->setEnd((yyvsp[0].symbol)->getEnd());
		fprintf(log_output, "statement : WHILE LPAREN expression RPAREN statement\n");
	  }
#line 2206 "y.tab.c"
    break;

  case 40: /* statement: PRINTLN LPAREN ID RPAREN SEMICOLON  */
#line 716 "1905077.y"
                                              {
		(yyval.symbol) = new SymbolInfo((string)"\t"+(string)"println"+(string)"("+(string)(yyvsp[-2].symbol)->getName()+(string)")"+(string)";"+(string)"\n", "statement");
		(yyval.symbol)->setChildren({(yyvsp[-4].symbol), (yyvsp[-3].symbol), (yyvsp[-2].symbol), (yyvsp[-1].symbol), (yyvsp[0].symbol)});
		(yyval.symbol)->setLeftPart("statement");
		(yyval.symbol)->setRightPart("PRINTLN LPAREN ID RPAREN SEMICOLON");
		(yyval.symbol)->setStart((yyvsp[-4].symbol)->getStart());
		(yyval.symbol)->setEnd((yyvsp[0].symbol)->getEnd());
		fprintf(log_output, "statement : PRINTLN LPAREN ID RPAREN SEMICOLON\n");
	  }
#line 2220 "y.tab.c"
    break;

  case 41: /* statement: RETURN expression SEMICOLON  */
#line 725 "1905077.y"
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
#line 2245 "y.tab.c"
    break;

  case 42: /* expression_statement: SEMICOLON  */
#line 747 "1905077.y"
                                        {
				(yyval.symbol) = new SymbolInfo(";", "expression_statement");
				(yyval.symbol)->setChildren({(yyvsp[0].symbol)});
				(yyval.symbol)->setLeftPart("expression_statement");
				(yyval.symbol)->setRightPart("SEMICOLON");
				(yyval.symbol)->setStart((yyvsp[0].symbol)->getStart());
				(yyval.symbol)->setEnd((yyvsp[0].symbol)->getEnd());
				
				fprintf(log_output, "Line# %d: expression_statement : SEMICOLON\n%s\n", line_count, (yyval.symbol)->getName().c_str());
}
#line 2260 "y.tab.c"
    break;

  case 43: /* expression_statement: expression SEMICOLON  */
#line 757 "1905077.y"
                                               {

				(yyval.symbol) = new SymbolInfo((yyvsp[-1].symbol)->getName() + ";", "expression_statement");
				(yyval.symbol)->setChildren({(yyvsp[-1].symbol),(yyvsp[0].symbol)});
				(yyval.symbol)->setLeftPart("expression_statement");
				(yyval.symbol)->setRightPart("expression SEMICOLON");
				(yyval.symbol)->setStart((yyvsp[-1].symbol)->getStart());
				(yyval.symbol)->setEnd((yyvsp[0].symbol)->getEnd());
				fprintf(log_output, "Line# %d: expression_statement : expression SEMICOLON\n%s\n", line_count, (yyval.symbol)->getName().c_str());
			}
#line 2275 "y.tab.c"
    break;

  case 44: /* variable: ID  */
#line 769 "1905077.y"
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
#line 2323 "y.tab.c"
    break;

  case 45: /* variable: ID LTHIRD expression RTHIRD  */
#line 812 "1905077.y"
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
#line 2368 "y.tab.c"
    break;

  case 46: /* expression: logic_expression  */
#line 854 "1905077.y"
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
#line 2386 "y.tab.c"
    break;

  case 47: /* expression: variable ASSIGNOP logic_expression  */
#line 867 "1905077.y"
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
#line 2435 "y.tab.c"
    break;

  case 48: /* logic_expression: rel_expression  */
#line 913 "1905077.y"
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
#line 2451 "y.tab.c"
    break;

  case 49: /* logic_expression: rel_expression LOGICOP rel_expression  */
#line 924 "1905077.y"
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
#line 2478 "y.tab.c"
    break;

  case 50: /* rel_expression: simple_expression  */
#line 948 "1905077.y"
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
#line 2494 "y.tab.c"
    break;

  case 51: /* rel_expression: simple_expression RELOP simple_expression  */
#line 959 "1905077.y"
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
#line 2514 "y.tab.c"
    break;

  case 52: /* simple_expression: term  */
#line 976 "1905077.y"
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
#line 2535 "y.tab.c"
    break;

  case 53: /* simple_expression: simple_expression ADDOP term  */
#line 992 "1905077.y"
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
#line 2562 "y.tab.c"
    break;

  case 54: /* term: unary_expression  */
#line 1016 "1905077.y"
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
#line 2581 "y.tab.c"
    break;

  case 55: /* term: term MULOP unary_expression  */
#line 1030 "1905077.y"
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
#line 2660 "y.tab.c"
    break;

  case 56: /* unary_expression: ADDOP unary_expression  */
#line 1106 "1905077.y"
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
#line 2676 "y.tab.c"
    break;

  case 57: /* unary_expression: NOT unary_expression  */
#line 1117 "1905077.y"
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
#line 2693 "y.tab.c"
    break;

  case 58: /* unary_expression: factor  */
#line 1129 "1905077.y"
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
#line 2711 "y.tab.c"
    break;

  case 59: /* factor: variable  */
#line 1144 "1905077.y"
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
#line 2728 "y.tab.c"
    break;

  case 60: /* factor: ID LPAREN argument_list RPAREN  */
#line 1156 "1905077.y"
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
#line 2809 "y.tab.c"
    break;

  case 61: /* factor: LPAREN expression RPAREN  */
#line 1232 "1905077.y"
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
#line 2825 "y.tab.c"
    break;

  case 62: /* factor: CONST_INT  */
#line 1243 "1905077.y"
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
#line 2841 "y.tab.c"
    break;

  case 63: /* factor: CONST_FLOAT  */
#line 1254 "1905077.y"
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
#line 2858 "y.tab.c"
    break;

  case 64: /* factor: variable INCOP  */
#line 1266 "1905077.y"
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
#line 2874 "y.tab.c"
    break;

  case 65: /* factor: variable DECOP  */
#line 1277 "1905077.y"
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
#line 2890 "y.tab.c"
    break;

  case 66: /* argument_list: arguments  */
#line 1290 "1905077.y"
                         {

				(yyval.symbol) = new SymbolInfo((yyvsp[0].symbol)->getName(), "argument_list");

				fprintf(log_output, "argument_list : arguments\n");
				(yyval.symbol)->setChildren({(yyvsp[0].symbol)});
				(yyval.symbol)->setLeftPart("argument_list");
				(yyval.symbol)->setRightPart("arguments");
				(yyval.symbol)->setStart((yyvsp[0].symbol)->getStart());
				(yyval.symbol)->setEnd((yyvsp[0].symbol)->getEnd());
}
#line 2906 "y.tab.c"
    break;

  case 67: /* argument_list: %empty  */
#line 1301 "1905077.y"
                           {

				(yyval.symbol)=new SymbolInfo("", "argument_list");
				(yyval.symbol)->setChildren({});
				(yyval.symbol)->setLeftPart("argument_list");
				(yyval.symbol)->setRightPart("");
				(yyval.symbol)->setStart(line_count);
				(yyval.symbol)->setEnd(line_count);
				fprintf(log_output, "argument_list : \n");
			  }
#line 2921 "y.tab.c"
    break;

  case 68: /* arguments: arguments COMMA logic_expression  */
#line 1313 "1905077.y"
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
#line 2941 "y.tab.c"
    break;

  case 69: /* arguments: logic_expression  */
#line 1328 "1905077.y"
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
#line 2960 "y.tab.c"
    break;


#line 2964 "y.tab.c"

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

#line 1345 "1905077.y"

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
	asmout= fopen("code.asm","w");
	fclose(asmout);
	asmout= fopen("code.asm","a");

	yyin=fp;
	yyparse();
	
	
	fclose(log_output);
	fclose(error_output);
	parse_tree.close();
	fclose(asmout);

	return 0;
}

