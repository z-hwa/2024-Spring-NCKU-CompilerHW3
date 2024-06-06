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
#line 2 "./compiler.y"

    #include "compiler_common.h"
    #include "compiler_util.h"
    #include "main.h"

    int yydebug = 1;

	char* assign_var;	//用於為變數設值的時候，紀錄當前設定的變數名稱
	ObjectType nowDealType;	//用於變數設值的時候，紀錄值的類型，用於判斷變數與值類型是否相同

	int array_ct = 0;	//用於紀錄連續的陣列變數宣告
	int para_ct	=0;	//紀錄參數數量的變數
	Object* para[100];	//紀錄參數的型態

	int isMain = 0;	//確認現在是不是在main中

#line 88 "./build/y.tab.c"

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

#include "y.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_COUT = 3,                       /* COUT  */
  YYSYMBOL_SHR = 4,                        /* SHR  */
  YYSYMBOL_SHL = 5,                        /* SHL  */
  YYSYMBOL_BAN = 6,                        /* BAN  */
  YYSYMBOL_BOR = 7,                        /* BOR  */
  YYSYMBOL_BXO = 8,                        /* BXO  */
  YYSYMBOL_MUL = 9,                        /* MUL  */
  YYSYMBOL_DIV = 10,                       /* DIV  */
  YYSYMBOL_REM = 11,                       /* REM  */
  YYSYMBOL_GTR = 12,                       /* GTR  */
  YYSYMBOL_LES = 13,                       /* LES  */
  YYSYMBOL_GEQ = 14,                       /* GEQ  */
  YYSYMBOL_LEQ = 15,                       /* LEQ  */
  YYSYMBOL_EQL = 16,                       /* EQL  */
  YYSYMBOL_NEQ = 17,                       /* NEQ  */
  YYSYMBOL_LAN = 18,                       /* LAN  */
  YYSYMBOL_LOR = 19,                       /* LOR  */
  YYSYMBOL_VAL_ASSIGN = 20,                /* VAL_ASSIGN  */
  YYSYMBOL_ADD_ASSIGN = 21,                /* ADD_ASSIGN  */
  YYSYMBOL_SUB_ASSIGN = 22,                /* SUB_ASSIGN  */
  YYSYMBOL_MUL_ASSIGN = 23,                /* MUL_ASSIGN  */
  YYSYMBOL_DIV_ASSIGN = 24,                /* DIV_ASSIGN  */
  YYSYMBOL_REM_ASSIGN = 25,                /* REM_ASSIGN  */
  YYSYMBOL_BAN_ASSIGN = 26,                /* BAN_ASSIGN  */
  YYSYMBOL_BOR_ASSIGN = 27,                /* BOR_ASSIGN  */
  YYSYMBOL_BXO_ASSIGN = 28,                /* BXO_ASSIGN  */
  YYSYMBOL_SHR_ASSIGN = 29,                /* SHR_ASSIGN  */
  YYSYMBOL_SHL_ASSIGN = 30,                /* SHL_ASSIGN  */
  YYSYMBOL_INC_ASSIGN = 31,                /* INC_ASSIGN  */
  YYSYMBOL_DEC_ASSIGN = 32,                /* DEC_ASSIGN  */
  YYSYMBOL_IF = 33,                        /* IF  */
  YYSYMBOL_ELSE = 34,                      /* ELSE  */
  YYSYMBOL_FOR = 35,                       /* FOR  */
  YYSYMBOL_WHILE = 36,                     /* WHILE  */
  YYSYMBOL_RETURN = 37,                    /* RETURN  */
  YYSYMBOL_BREAK = 38,                     /* BREAK  */
  YYSYMBOL_CONTINUE = 39,                  /* CONTINUE  */
  YYSYMBOL_40_ = 40,                       /* ')'  */
  YYSYMBOL_41_ = 41,                       /* ';'  */
  YYSYMBOL_42_ = 42,                       /* '{'  */
  YYSYMBOL_43_ = 43,                       /* '}'  */
  YYSYMBOL_ENDL = 44,                      /* ENDL  */
  YYSYMBOL_VARIABLE_T = 45,                /* VARIABLE_T  */
  YYSYMBOL_IDENT = 46,                     /* IDENT  */
  YYSYMBOL_BOOL_LIT = 47,                  /* BOOL_LIT  */
  YYSYMBOL_INT_LIT = 48,                   /* INT_LIT  */
  YYSYMBOL_FLOAT_LIT = 49,                 /* FLOAT_LIT  */
  YYSYMBOL_STR_LIT = 50,                   /* STR_LIT  */
  YYSYMBOL_51_ = 51,                       /* '('  */
  YYSYMBOL_SUB = 52,                       /* SUB  */
  YYSYMBOL_NOT = 53,                       /* NOT  */
  YYSYMBOL_BNT = 54,                       /* BNT  */
  YYSYMBOL_ADD = 55,                       /* ADD  */
  YYSYMBOL_56_ = 56,                       /* ':'  */
  YYSYMBOL_57_ = 57,                       /* '['  */
  YYSYMBOL_58_ = 58,                       /* ']'  */
  YYSYMBOL_59_ = 59,                       /* ','  */
  YYSYMBOL_YYACCEPT = 60,                  /* $accept  */
  YYSYMBOL_Program = 61,                   /* Program  */
  YYSYMBOL_62_1 = 62,                      /* $@1  */
  YYSYMBOL_GlobalStmtList = 63,            /* GlobalStmtList  */
  YYSYMBOL_GlobalStmt = 64,                /* GlobalStmt  */
  YYSYMBOL_FunctionCallStmt = 65,          /* FunctionCallStmt  */
  YYSYMBOL_JumpStmt = 66,                  /* JumpStmt  */
  YYSYMBOL_IterationStmt = 67,             /* IterationStmt  */
  YYSYMBOL_68_2 = 68,                      /* $@2  */
  YYSYMBOL_69_3 = 69,                      /* $@3  */
  YYSYMBOL_70_4 = 70,                      /* $@4  */
  YYSYMBOL_71_5 = 71,                      /* $@5  */
  YYSYMBOL_ForCondition = 72,              /* ForCondition  */
  YYSYMBOL_73_6 = 73,                      /* $@6  */
  YYSYMBOL_74_7 = 74,                      /* $@7  */
  YYSYMBOL_ExpressionStmt = 75,            /* ExpressionStmt  */
  YYSYMBOL_CompoundStmt = 76,              /* CompoundStmt  */
  YYSYMBOL_SelectionStmt = 77,             /* SelectionStmt  */
  YYSYMBOL_78_8 = 78,                      /* $@8  */
  YYSYMBOL_79_9 = 79,                      /* $@9  */
  YYSYMBOL_Selection = 80,                 /* Selection  */
  YYSYMBOL_81_10 = 81,                     /* $@10  */
  YYSYMBOL_82_11 = 82,                     /* $@11  */
  YYSYMBOL_AssignStmt = 83,                /* AssignStmt  */
  YYSYMBOL_AssignBody = 84,                /* AssignBody  */
  YYSYMBOL_85_12 = 85,                     /* $@12  */
  YYSYMBOL_86_13 = 86,                     /* @13  */
  YYSYMBOL_AssignList = 87,                /* AssignList  */
  YYSYMBOL_88_14 = 88,                     /* $@14  */
  YYSYMBOL_89_15 = 89,                     /* $@15  */
  YYSYMBOL_Assign = 90,                    /* Assign  */
  YYSYMBOL_Assignable = 91,                /* Assignable  */
  YYSYMBOL_DefineVariableStmt = 92,        /* DefineVariableStmt  */
  YYSYMBOL_DeclaratorList = 93,            /* DeclaratorList  */
  YYSYMBOL_Declarator = 94,                /* Declarator  */
  YYSYMBOL_95_16 = 95,                     /* $@16  */
  YYSYMBOL_ArrayEles = 96,                 /* ArrayEles  */
  YYSYMBOL_97_17 = 97,                     /* @17  */
  YYSYMBOL_98_18 = 98,                     /* @18  */
  YYSYMBOL_ReturnStmt = 99,                /* ReturnStmt  */
  YYSYMBOL_CoutStmt = 100,                 /* CoutStmt  */
  YYSYMBOL_101_19 = 101,                   /* $@19  */
  YYSYMBOL_PrintableList = 102,            /* PrintableList  */
  YYSYMBOL_Printable = 103,                /* Printable  */
  YYSYMBOL_Expression = 104,               /* Expression  */
  YYSYMBOL_Or = 105,                       /* Or  */
  YYSYMBOL_And = 106,                      /* And  */
  YYSYMBOL_BitwiseOr = 107,                /* BitwiseOr  */
  YYSYMBOL_BitwiseXor = 108,               /* BitwiseXor  */
  YYSYMBOL_BitwiseAnd = 109,               /* BitwiseAnd  */
  YYSYMBOL_Equality = 110,                 /* Equality  */
  YYSYMBOL_Relational = 111,               /* Relational  */
  YYSYMBOL_Shift = 112,                    /* Shift  */
  YYSYMBOL_Additive = 113,                 /* Additive  */
  YYSYMBOL_Multiplicative = 114,           /* Multiplicative  */
  YYSYMBOL_TypeCast = 115,                 /* TypeCast  */
  YYSYMBOL_Unary = 116,                    /* Unary  */
  YYSYMBOL_Post = 117,                     /* Post  */
  YYSYMBOL_Primary = 118,                  /* Primary  */
  YYSYMBOL_119_20 = 119,                   /* @20  */
  YYSYMBOL_List = 120,                     /* List  */
  YYSYMBOL_FunctionCall = 121,             /* FunctionCall  */
  YYSYMBOL_ArgumentList = 122,             /* ArgumentList  */
  YYSYMBOL_ArgumentListNonEmpty = 123,     /* ArgumentListNonEmpty  */
  YYSYMBOL_FunctionDefStmt = 124,          /* FunctionDefStmt  */
  YYSYMBOL_125_21 = 125,                   /* $@21  */
  YYSYMBOL_126_22 = 126,                   /* $@22  */
  YYSYMBOL_127_23 = 127,                   /* $@23  */
  YYSYMBOL_FunctionParameterStmtList = 128, /* FunctionParameterStmtList  */
  YYSYMBOL_FunctionParameterStmt = 129,    /* FunctionParameterStmt  */
  YYSYMBOL_130_24 = 130                    /* $@24  */
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
typedef yytype_int16 yy_state_t;

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
#define YYLAST   350

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  60
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  71
/* YYNRULES -- Number of rules.  */
#define YYNRULES  152
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  257

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   305


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
      51,    40,     2,     2,    59,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    56,    41,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    57,     2,    58,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    42,     2,    43,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    44,    45,    46,    47,    48,
      49,    50,    52,    53,    54,    55
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    69,    69,    69,    73,    77,    78,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    95,   100,   108,   111,
     108,   119,   122,   119,   132,   134,   132,   142,   150,   151,
     152,   153,   154,   159,   160,   166,   166,   173,   173,   179,
     180,   180,   180,   186,   190,   190,   201,   201,   211,   211,
     217,   217,   231,   232,   235,   239,   242,   245,   248,   251,
     254,   257,   260,   263,   269,   276,   281,   285,   286,   290,
     297,   304,   313,   330,   330,   344,   344,   351,   351,   358,
     363,   367,   371,   379,   379,   389,   390,   395,   400,   406,
     418,   420,   427,   428,   437,   438,   446,   447,   455,   456,
     464,   465,   473,   474,   478,   485,   486,   493,   500,   507,
     517,   518,   525,   526,   532,   541,   542,   547,   552,   562,
     563,   572,   579,   582,   589,   594,   598,   599,   608,   620,
     627,   634,   637,   644,   656,   657,   657,   667,   674,   691,
     703,   707,   708,   714,   720,   724,   714,   748,   749,   750,
     754,   760,   760
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
  "\"end of file\"", "error", "\"invalid token\"", "COUT", "SHR", "SHL",
  "BAN", "BOR", "BXO", "MUL", "DIV", "REM", "GTR", "LES", "GEQ", "LEQ",
  "EQL", "NEQ", "LAN", "LOR", "VAL_ASSIGN", "ADD_ASSIGN", "SUB_ASSIGN",
  "MUL_ASSIGN", "DIV_ASSIGN", "REM_ASSIGN", "BAN_ASSIGN", "BOR_ASSIGN",
  "BXO_ASSIGN", "SHR_ASSIGN", "SHL_ASSIGN", "INC_ASSIGN", "DEC_ASSIGN",
  "IF", "ELSE", "FOR", "WHILE", "RETURN", "BREAK", "CONTINUE", "')'",
  "';'", "'{'", "'}'", "ENDL", "VARIABLE_T", "IDENT", "BOOL_LIT",
  "INT_LIT", "FLOAT_LIT", "STR_LIT", "'('", "SUB", "NOT", "BNT", "ADD",
  "':'", "'['", "']'", "','", "$accept", "Program", "$@1",
  "GlobalStmtList", "GlobalStmt", "FunctionCallStmt", "JumpStmt",
  "IterationStmt", "$@2", "$@3", "$@4", "$@5", "ForCondition", "$@6",
  "$@7", "ExpressionStmt", "CompoundStmt", "SelectionStmt", "$@8", "$@9",
  "Selection", "$@10", "$@11", "AssignStmt", "AssignBody", "$@12", "@13",
  "AssignList", "$@14", "$@15", "Assign", "Assignable",
  "DefineVariableStmt", "DeclaratorList", "Declarator", "$@16",
  "ArrayEles", "@17", "@18", "ReturnStmt", "CoutStmt", "$@19",
  "PrintableList", "Printable", "Expression", "Or", "And", "BitwiseOr",
  "BitwiseXor", "BitwiseAnd", "Equality", "Relational", "Shift",
  "Additive", "Multiplicative", "TypeCast", "Unary", "Post", "Primary",
  "@20", "List", "FunctionCall", "ArgumentList", "ArgumentListNonEmpty",
  "FunctionDefStmt", "$@21", "$@22", "$@23", "FunctionParameterStmtList",
  "FunctionParameterStmt", "$@24", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-184)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-152)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -184,     9,    98,  -184,  -184,   -28,  -184,  -184,   119,    12,
      34,    69,    98,  -184,  -184,  -184,  -184,    43,  -184,    46,
    -184,  -184,  -184,    66,  -184,   122,   272,    73,    78,  -184,
      71,  -184,  -184,  -184,  -184,   262,   137,   137,   137,   137,
      91,   118,   141,   156,   170,   173,   102,   127,   176,    23,
      22,  -184,  -184,  -184,   126,  -184,  -184,    38,    50,  -184,
     272,  -184,   209,  -184,  -184,  -184,  -184,   251,   153,   224,
     272,  -184,   154,   155,   272,  -184,  -184,  -184,  -184,  -184,
     292,   292,   292,   292,   292,   292,   292,   292,   292,   292,
     292,   292,   292,   292,   292,   292,   292,  -184,  -184,   282,
     272,   146,  -184,   158,  -184,   159,   142,   272,   209,   209,
     209,   209,   209,   209,   209,   209,   209,   209,   209,  -184,
    -184,  -184,  -184,    19,  -184,  -184,    74,  -184,  -184,  -184,
    -184,   161,    31,   162,  -184,  -184,  -184,   168,   177,   272,
     137,  -184,   141,   156,   170,   173,   102,   127,   127,   176,
     176,   176,   176,    23,    22,    22,  -184,  -184,  -184,  -184,
     152,  -184,    10,  -184,  -184,   272,  -184,   164,  -184,  -184,
    -184,  -184,  -184,  -184,  -184,  -184,  -184,  -184,  -184,  -184,
    -184,  -184,   251,  -184,    19,    40,  -184,  -184,   239,  -184,
    -184,   165,  -184,  -184,    54,   174,  -184,   167,    98,  -184,
    -184,   179,    48,   158,  -184,    48,   169,   272,   193,   181,
      58,  -184,   272,   209,    98,  -184,    98,    98,  -184,   239,
    -184,   272,   182,   199,   187,  -184,   174,   188,  -184,   204,
      67,  -184,   190,  -184,   -35,   194,   208,  -184,  -184,  -184,
    -184,  -184,    49,   282,   195,    98,   209,  -184,  -184,  -184,
    -184,    98,  -184,   282,   211,  -184,  -184
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,    82,     1,    83,     0,    21,    18,     0,     0,
       0,    44,     3,     6,    15,    14,    13,    12,    11,     0,
       7,    10,     9,     0,     8,     0,     0,     0,     0,    81,
     133,   132,   129,   130,    91,     0,     0,     0,     0,     0,
       0,    90,    92,    94,    96,    98,   100,   102,   105,   110,
     112,   115,   119,   125,   126,   134,    17,    69,     0,    67,
       0,    46,     0,     5,    37,    43,    16,     0,     0,     0,
       0,   135,     0,     0,     0,   123,   124,   121,   122,    80,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   127,   128,     0,
       0,     0,    66,     0,   141,     0,   140,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    64,
      45,    52,    65,    82,    88,    87,     0,    85,    89,    35,
      32,     0,    44,     0,    24,    30,    29,    31,     0,     0,
       0,   131,    93,    95,    97,    99,   101,   103,   104,   107,
     106,   109,   108,   111,   114,   113,   116,   117,   118,    70,
       0,   144,    69,    68,   139,     0,    47,     0,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    40,
      39,    38,     0,    84,    82,    69,    46,    22,     0,    28,
      19,     0,   136,   120,    71,   149,   142,    48,    82,    86,
      36,     0,    82,     0,    25,    82,   137,     0,     0,     0,
       0,   148,     0,     0,    41,    27,    82,    34,    23,     0,
      20,     0,     0,     0,   150,   145,     0,     0,    49,     0,
       0,    26,     0,    72,    75,     0,     0,   147,    50,    42,
      33,   138,     0,     0,     0,    82,     0,    74,    77,    76,
     152,    82,    51,     0,    10,    78,   146
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -184,  -184,  -184,     0,    -9,  -184,  -184,  -184,  -184,  -184,
    -184,  -184,  -184,  -184,  -184,  -183,    47,  -184,  -184,  -184,
      82,  -184,  -184,  -184,   -65,  -184,  -184,  -184,  -184,  -184,
     -97,   -98,   -63,  -184,   178,  -184,  -184,  -184,  -184,    16,
    -184,  -184,  -184,    86,    -1,  -184,   202,   215,   201,   259,
     264,    76,    63,   258,    84,    52,   -10,  -184,  -184,  -184,
    -184,    -2,  -184,  -184,  -184,  -184,  -184,  -184,  -184,   124,
    -184
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     2,   217,    13,    14,    15,    16,    28,   205,
      27,   202,   133,   188,   219,   134,   218,    17,   184,   123,
     181,   198,   229,    18,    19,    62,   107,   166,   213,   246,
     120,   121,    20,    58,    59,   208,   242,   243,   253,    21,
      22,    25,   126,   127,   122,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,   139,
     192,    55,   105,   106,    24,   101,   195,   236,   210,   211,
     235
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      23,   159,    12,    63,   135,   204,   136,    40,   -79,     3,
      23,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,     4,    26,   -79,    68,    75,    76,    77,    78,
      99,    94,    95,    96,    73,  -133,   231,  -133,  -133,  -133,
    -133,  -133,  -133,  -133,  -133,  -133,  -133,  -133,  -133,  -133,
    -133,     4,     5,    56,     6,     7,     8,     9,    99,   104,
      99,   179,  -133,  -133,    10,    11,   128,   100,   137,   138,
       4,  -133,  -133,    73,   -73,    92,  -133,    64,    93,   182,
      57,     5,    60,     6,     7,     8,     9,    65,   186,  -143,
     216,   102,   247,    10,    11,   100,   201,   100,   225,   160,
       5,     4,     6,     7,     8,     9,   167,    66,   248,   103,
     240,   207,    10,    11,   180,   183,   228,   226,    85,    86,
      60,    23,    60,   135,    69,   136,    61,    67,    71,    70,
     193,     5,    79,     6,     7,     8,     9,    80,   191,    87,
      88,    89,    90,    10,    11,   249,   156,   157,   158,   252,
     149,   150,   151,   152,   135,   255,   136,    97,    98,    81,
      29,   147,   148,    82,   196,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,   180,   154,   155,    83,    84,
      91,   128,    23,    30,    31,    32,    33,   137,    74,    36,
      37,    38,    39,   129,   140,   141,    23,   161,   214,   164,
      23,   165,   187,    23,   162,    63,   222,   185,    63,   189,
     194,   227,    23,   223,    23,    23,   230,   190,   137,   209,
     232,    63,   197,   206,   212,   215,   221,   224,    23,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     233,   234,    63,    23,  -151,   251,   238,   239,   241,    23,
     245,   244,   220,   250,   256,    30,    31,    32,    33,   119,
      35,    36,    37,    38,    39,   130,   200,   254,   199,   131,
     132,    31,    32,    33,    34,    35,    36,    37,    38,    39,
     130,   163,   142,   144,   203,   132,    31,    32,    33,    34,
      35,    36,    37,    38,    39,   124,   143,    30,    31,    32,
      33,   125,    35,    36,    37,    38,    39,    72,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    30,    31,
      32,    33,   119,    35,    36,    37,    38,    39,    30,    31,
      32,    33,   145,    35,    36,    37,    38,    39,   146,   153,
     237
};

static const yytype_uint8 yycheck[] =
{
       2,    99,     2,    12,    69,   188,    69,     8,    43,     0,
      12,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,     3,    51,    59,    26,    36,    37,    38,    39,
      20,     9,    10,    11,    35,     4,   219,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,     3,    33,    41,    35,    36,    37,    38,    20,    60,
      20,    42,    31,    32,    45,    46,    67,    57,    69,    70,
       3,    40,    41,    74,    20,    52,    45,    34,    55,     5,
      46,    33,    51,    35,    36,    37,    38,    41,    57,    51,
      42,    41,    43,    45,    46,    57,    56,    57,    40,   100,
      33,     3,    35,    36,    37,    38,   107,    41,    59,    59,
      43,    57,    45,    46,   123,    41,   213,    59,    16,    17,
      51,   123,    51,   188,    51,   188,    57,     5,    57,    51,
     140,    33,    41,    35,    36,    37,    38,    19,   139,    12,
      13,    14,    15,    45,    46,   243,    94,    95,    96,   246,
      87,    88,    89,    90,   219,   253,   219,    31,    32,    18,
      41,    85,    86,     7,   165,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,   184,    92,    93,     8,     6,
       4,   182,   184,    46,    47,    48,    49,   188,    51,    52,
      53,    54,    55,    40,    40,    40,   198,    51,   198,    40,
     202,    59,    40,   205,    46,   214,   207,    46,   217,    41,
      58,   212,   214,    20,   216,   217,   216,    40,   219,    45,
     221,   230,    58,    58,    57,    46,    57,    46,   230,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      58,    42,   251,   245,    57,   245,    58,    43,    58,   251,
      42,    57,   205,    58,    43,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    41,   184,   251,   182,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      41,   103,    80,    82,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    44,    81,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    46,    47,
      48,    49,    83,    51,    52,    53,    54,    55,    84,    91,
     226
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    61,    62,     0,     3,    33,    35,    36,    37,    38,
      45,    46,    63,    64,    65,    66,    67,    77,    83,    84,
      92,    99,   100,   121,   124,   101,    51,    70,    68,    41,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   121,    41,    46,    93,    94,
      51,    57,    85,    64,    34,    41,    41,     5,   104,    51,
      51,    57,    45,   104,    51,   116,   116,   116,   116,    41,
      19,    18,     7,     8,     6,    16,    17,    12,    13,    14,
      15,     4,    52,    55,     9,    10,    11,    31,    32,    20,
      57,   125,    41,    59,   104,   122,   123,    86,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    50,
      90,    91,   104,    79,    44,    50,   102,   103,   104,    40,
      41,    45,    46,    72,    75,    84,    92,   104,   104,   119,
      40,    40,   106,   107,   108,   109,   110,   111,   111,   112,
     112,   112,   112,   113,   114,   114,   115,   115,   115,    91,
     104,    51,    46,    94,    40,    59,    87,   104,    90,    90,
      90,    90,    90,    90,    90,    90,    90,    90,    90,    42,
      64,    80,     5,    41,    78,    46,    57,    40,    73,    41,
      40,   104,   120,   116,    58,   126,   104,    58,    81,   103,
      80,    56,    71,    45,    75,    69,    58,    57,    95,    45,
     128,   129,    57,    88,    63,    46,    42,    63,    76,    74,
      76,    57,   104,    20,    46,    40,    59,   104,    90,    82,
      63,    75,   104,    58,    42,   130,   127,   129,    58,    43,
      43,    58,    96,    97,    57,    42,    89,    43,    59,    91,
      58,    63,    90,    98,    99,    91,    43
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    60,    62,    61,    61,    63,    63,    64,    64,    64,
      64,    64,    64,    64,    64,    64,    65,    66,    68,    69,
      67,    70,    71,    67,    73,    74,    72,    72,    75,    75,
      75,    75,    75,    76,    76,    78,    77,    79,    77,    80,
      81,    82,    80,    83,    85,    84,    86,    84,    88,    87,
      89,    87,    90,    90,    90,    90,    90,    90,    90,    90,
      90,    90,    90,    90,    91,    91,    92,    93,    93,    94,
      94,    94,    94,    95,    94,    97,    96,    98,    96,    96,
      99,    99,    99,   101,   100,   102,   102,   103,   103,   103,
     104,   104,   105,   105,   106,   106,   107,   107,   108,   108,
     109,   109,   110,   110,   110,   111,   111,   111,   111,   111,
     112,   112,   113,   113,   113,   114,   114,   114,   114,   115,
     115,   116,   116,   116,   116,   116,   117,   117,   117,   118,
     118,   118,   118,   118,   118,   119,   118,   120,   120,   121,
     122,   123,   123,   125,   126,   127,   124,   128,   128,   128,
     129,   130,   129
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     0,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     2,     0,     0,
       7,     0,     0,     7,     0,     0,     5,     4,     2,     1,
       1,     1,     1,     3,     1,     0,     6,     0,     4,     1,
       0,     0,     5,     2,     0,     3,     0,     4,     0,     4,
       0,     7,     1,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     1,     1,     3,     1,     3,     1,
       3,     4,     7,     0,     9,     0,     2,     0,     4,     0,
       3,     2,     0,     0,     5,     1,     3,     1,     1,     1,
       1,     1,     1,     3,     1,     3,     1,     3,     1,     3,
       1,     3,     1,     3,     3,     1,     3,     3,     3,     3,
       1,     3,     1,     3,     3,     1,     3,     3,     3,     1,
       4,     2,     2,     2,     2,     1,     1,     2,     2,     1,
       1,     3,     1,     1,     1,     0,     4,     2,     5,     4,
       1,     1,     3,     0,     0,     0,    12,     3,     1,     0,
       2,     0,     5
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
#line 69 "./compiler.y"
      { 
		pushScope();
		addFileStart_j();
	 }
#line 1423 "./build/y.tab.c"
    break;

  case 3: /* Program: $@1 GlobalStmtList  */
#line 72 "./compiler.y"
                          { dumpScope(); }
#line 1429 "./build/y.tab.c"
    break;

  case 12: /* GlobalStmt: SelectionStmt  */
#line 87 "./compiler.y"
                        {addIf_j('o');}
#line 1435 "./build/y.tab.c"
    break;

  case 17: /* JumpStmt: BREAK ';'  */
#line 100 "./compiler.y"
                    {
		printf("BREAK\n");
		addBreak_j();
	}
#line 1444 "./build/y.tab.c"
    break;

  case 18: /* $@2: %empty  */
#line 108 "./compiler.y"
                {
		printf("WHILE\n");
		addWhile_j('i');	//設置循環標記
	}
#line 1453 "./build/y.tab.c"
    break;

  case 19: /* $@3: %empty  */
#line 111 "./compiler.y"
                             {
		addWhile_j('w');	//check condition
		pushScope();
	}
#line 1462 "./build/y.tab.c"
    break;

  case 20: /* IterationStmt: WHILE $@2 '(' Expression ')' $@3 CompoundStmt  */
#line 114 "./compiler.y"
                       {
		addWhile_j('c');	//go to 循環標記
		dumpScope();
		addWhile_j('o');	//離開標記
	}
#line 1472 "./build/y.tab.c"
    break;

  case 21: /* $@4: %empty  */
#line 119 "./compiler.y"
              {
		printf("FOR\n");
		pushScope();
	}
#line 1481 "./build/y.tab.c"
    break;

  case 22: /* $@5: %empty  */
#line 122 "./compiler.y"
                               {
		addFor_j('2');	//get jump, f2
	}
#line 1489 "./build/y.tab.c"
    break;

  case 23: /* IterationStmt: FOR $@4 '(' ForCondition ')' $@5 CompoundStmt  */
#line 124 "./compiler.y"
                       {
		addFor_j('3');	//f3
		dumpScope();
		addFor_j('o');	//離開標記
	}
#line 1499 "./build/y.tab.c"
    break;

  case 24: /* $@6: %empty  */
#line 132 "./compiler.y"
                         {
		addFor_j('i');	//設置循環標記;
	}
#line 1507 "./build/y.tab.c"
    break;

  case 25: /* $@7: %empty  */
#line 134 "./compiler.y"
                         {
		addFor_j('f');	//check condition

		addFor_j('1');	//f1
		addFor_j('4');	//f4
	}
#line 1518 "./build/y.tab.c"
    break;

  case 26: /* ForCondition: ExpressionStmt $@6 ExpressionStmt $@7 ExpressionStmt  */
#line 139 "./compiler.y"
                         {
		addFor_j('c');
	}
#line 1526 "./build/y.tab.c"
    break;

  case 27: /* ForCondition: VARIABLE_T IDENT ':' IDENT  */
#line 142 "./compiler.y"
                                     {
		//auto i:a	類型的for迴圈
		insert((yyvsp[-2].s_var), getVarTypeByName((yyvsp[0].s_var)), 1);
		printIDByName((yyvsp[0].s_var), 'v'); 
	}
#line 1536 "./build/y.tab.c"
    break;

  case 35: /* $@8: %empty  */
#line 166 "./compiler.y"
                               { 
		printf("IF\n");
		addIf_j('i');	//判斷條件是否為真，錯的話跳出
	}
#line 1545 "./build/y.tab.c"
    break;

  case 36: /* SelectionStmt: IF '(' Expression ')' $@8 Selection  */
#line 169 "./compiler.y"
                    {
		addIf_j('g');
		addIf_j('e');
	}
#line 1554 "./build/y.tab.c"
    break;

  case 37: /* $@9: %empty  */
#line 173 "./compiler.y"
                             {
		printf("ELSE\n");
	}
#line 1562 "./build/y.tab.c"
    break;

  case 40: /* $@10: %empty  */
#line 180 "./compiler.y"
              {pushScope();}
#line 1568 "./build/y.tab.c"
    break;

  case 41: /* $@11: %empty  */
#line 180 "./compiler.y"
                                            {dumpScope();}
#line 1574 "./build/y.tab.c"
    break;

  case 44: /* $@12: %empty  */
#line 190 "./compiler.y"
                { 
		printIDByName((yyvsp[0].s_var), 'v');	//輸出該變數資訊

		assign_var = (yyvsp[0].s_var);
		addPushLocalVar_j((yyvsp[0].s_var), ' ');	//將當前設值的變數放進stack
	}
#line 1585 "./build/y.tab.c"
    break;

  case 45: /* AssignBody: IDENT $@12 Assign  */
#line 195 "./compiler.y"
                 {
		(yyvsp[-3].object_val).type = OBJECT_TYPE_BOOL;	//設值成功，回傳bool

		//將變數設值
		addLocalVar_j((yyvsp[-2].s_var), 'y', nowDealType);
	}
#line 1596 "./build/y.tab.c"
    break;

  case 46: /* @13: %empty  */
#line 201 "./compiler.y"
                    {
		addPushLocalVar_j((yyvsp[-1].s_var), 'L');
		assign_var = (yyvsp[-1].s_var);
	}
#line 1605 "./build/y.tab.c"
    break;

  case 47: /* AssignBody: IDENT '[' @13 AssignList  */
#line 204 "./compiler.y"
                     {(yyvsp[-4].object_val).type = (yyvsp[-1].object_val).type;}
#line 1611 "./build/y.tab.c"
    break;

  case 48: /* $@14: %empty  */
#line 211 "./compiler.y"
                         {
		printIDByName(assign_var, 'v');
	}
#line 1619 "./build/y.tab.c"
    break;

  case 49: /* AssignList: Expression ']' $@14 Assign  */
#line 213 "./compiler.y"
                 {
		(yyvsp[-4].object_val).type = OBJECT_TYPE_BOOL;
		addArrayEle_j(nowDealType);
	}
#line 1628 "./build/y.tab.c"
    break;

  case 50: /* $@15: %empty  */
#line 217 "./compiler.y"
                                            {
		printIDByName(assign_var, 'v');

		codeRaw("swap");
		codeRaw("ldc 3");
		codeRaw("imul");
		codeRaw("iadd");//count index
	}
#line 1641 "./build/y.tab.c"
    break;

  case 51: /* AssignList: Expression ']' '[' Expression ']' $@15 Assign  */
#line 224 "./compiler.y"
                 {
		(yyvsp[-7].object_val).type = OBJECT_TYPE_BOOL;
		addArrayEle_j(nowDealType);
	}
#line 1650 "./build/y.tab.c"
    break;

  case 53: /* Assign: VAL_ASSIGN Assign  */
#line 232 "./compiler.y"
                           {
		printf("EQL_ASSIGN\n");
	}
#line 1658 "./build/y.tab.c"
    break;

  case 54: /* Assign: ADD_ASSIGN Assign  */
#line 235 "./compiler.y"
                           {
		printf("ADD_ASSIGN\n");
		addAssign_j(assign_var, "add");
	}
#line 1667 "./build/y.tab.c"
    break;

  case 55: /* Assign: SUB_ASSIGN Assign  */
#line 239 "./compiler.y"
                           {
		printf("SUB_ASSIGN\n");
		addAssign_j(assign_var, "sub");}
#line 1675 "./build/y.tab.c"
    break;

  case 56: /* Assign: MUL_ASSIGN Assign  */
#line 242 "./compiler.y"
                           {
		printf("MUL_ASSIGN\n");
		addAssign_j(assign_var, "mul");}
#line 1683 "./build/y.tab.c"
    break;

  case 57: /* Assign: DIV_ASSIGN Assign  */
#line 245 "./compiler.y"
                           {
		printf("DIV_ASSIGN\n");
		addAssign_j(assign_var, "div");}
#line 1691 "./build/y.tab.c"
    break;

  case 58: /* Assign: REM_ASSIGN Assign  */
#line 248 "./compiler.y"
                           {
		printf("REM_ASSIGN\n");
		addAssign_j(assign_var, "rem");}
#line 1699 "./build/y.tab.c"
    break;

  case 59: /* Assign: BAN_ASSIGN Assign  */
#line 251 "./compiler.y"
                           {
		printf("BAN_ASSIGN\n");
		addAssign_j(assign_var, "and");}
#line 1707 "./build/y.tab.c"
    break;

  case 60: /* Assign: BOR_ASSIGN Assign  */
#line 254 "./compiler.y"
                           {
		printf("BOR_ASSIGN\n");
		addAssign_j(assign_var, "or");}
#line 1715 "./build/y.tab.c"
    break;

  case 61: /* Assign: BXO_ASSIGN Assign  */
#line 257 "./compiler.y"
                           {
		printf("BXO_ASSIGN\n");
		addAssign_j(assign_var, "xor");}
#line 1723 "./build/y.tab.c"
    break;

  case 62: /* Assign: SHR_ASSIGN Assign  */
#line 260 "./compiler.y"
                           {
		printf("SHR_ASSIGN\n");
		addAssign_j(assign_var, "shr");}
#line 1731 "./build/y.tab.c"
    break;

  case 63: /* Assign: SHL_ASSIGN Assign  */
#line 263 "./compiler.y"
                           {
		printf("SHL_ASSIGN\n");
		addAssign_j(assign_var, "shl");}
#line 1739 "./build/y.tab.c"
    break;

  case 64: /* Assignable: STR_LIT  */
#line 269 "./compiler.y"
                   {
		(yyvsp[-1].object_val).type = OBJECT_TYPE_STR;
		nowDealType = OBJECT_TYPE_STR;
		printf("STR_LIT \"%s\"\n", (yyvsp[0].s_var));

		code("ldc \"%s\"", (yyvsp[0].s_var));
	}
#line 1751 "./build/y.tab.c"
    break;

  case 65: /* Assignable: Expression  */
#line 276 "./compiler.y"
                     { nowDealType = (yyvsp[-1].object_val).type; }
#line 1757 "./build/y.tab.c"
    break;

  case 66: /* DefineVariableStmt: VARIABLE_T DeclaratorList ';'  */
#line 281 "./compiler.y"
                                        {typeSet(false);}
#line 1763 "./build/y.tab.c"
    break;

  case 69: /* Declarator: IDENT  */
#line 290 "./compiler.y"
                {
		//普通的變數宣告
		insert((yyvsp[0].s_var), (yyvsp[-1].var_type), 0);

		//創建並添加該變數
		addLocalVar_j((yyvsp[0].s_var), 'n', OBJECT_TYPE_INT);
	}
#line 1775 "./build/y.tab.c"
    break;

  case 70: /* Declarator: IDENT VAL_ASSIGN Assignable  */
#line 297 "./compiler.y"
                                      {
		//普通的變數宣告與賦值
		insertAuto((yyvsp[-2].s_var), (yyvsp[-3].var_type), (yyvsp[-1].var_type), 0);

		//創建並添加該變數
		addLocalVar_j((yyvsp[-2].s_var), 'y', (yyvsp[-1].object_val).type);
	}
#line 1787 "./build/y.tab.c"
    break;

  case 71: /* Declarator: IDENT '[' Expression ']'  */
#line 304 "./compiler.y"
                                   {
		//陣列的變數宣告
		printf("create array: %d\n", 0);
		insert((yyvsp[-3].s_var), (yyvsp[-4].var_type), 0);

		codeRaw("newarray int");	//宣告陣列

		addLocalVar_j((yyvsp[-3].s_var), 'y', OBJECT_TYPE_VOID);
	}
#line 1801 "./build/y.tab.c"
    break;

  case 72: /* Declarator: IDENT '[' Expression ']' '[' Expression ']'  */
#line 313 "./compiler.y"
                                                      {
		//二維陣列的變數宣告
		insert((yyvsp[-6].s_var), (yyvsp[-7].var_type), 0);

		/*這裡的實現應該是取yacc計算出來的expression
		用於紀錄這個list的一維、二維大小，之後直接傳給java做計算
		就可以適配各種長寬的二維陣列
		
		可惜我沒有算yacc的結果，所以之後有空再弄
		不過這個list在浮點數上能不能用也是未知數*/

		codeRaw("imul");

		//創建陣列
		codeRaw("newarray int");	//宣告陣列
		addLocalVar_j((yyvsp[-6].s_var), 'y', OBJECT_TYPE_VOID);
	}
#line 1823 "./build/y.tab.c"
    break;

  case 73: /* $@16: %empty  */
#line 330 "./compiler.y"
                                   {
		codeRaw("newarray int");	//宣告陣列
	}
#line 1831 "./build/y.tab.c"
    break;

  case 74: /* Declarator: IDENT '[' Expression ']' $@16 VAL_ASSIGN '{' ArrayEles '}'  */
#line 332 "./compiler.y"
                                       {
		//一維陣列的變數宣告與賦值
		printf("create array: %d\n", array_ct);
		array_ct = 0;
		insert((yyvsp[-8].s_var), (yyvsp[-9].var_type), 0);

		//創建陣列
		addLocalVar_j((yyvsp[-8].s_var), 'y', OBJECT_TYPE_VOID);
	}
#line 1845 "./build/y.tab.c"
    break;

  case 75: /* @17: %empty  */
#line 344 "./compiler.y"
          {
		codeRaw("dup");
		code("ldc %d", array_ct);
	}
#line 1854 "./build/y.tab.c"
    break;

  case 76: /* ArrayEles: @17 Assignable  */
#line 347 "./compiler.y"
                    {
		addArrayEle_j((yyvsp[-1].object_val).type);
		array_ct++;
	}
#line 1863 "./build/y.tab.c"
    break;

  case 77: /* @18: %empty  */
#line 351 "./compiler.y"
                        {
		codeRaw("dup");
		code("ldc %d", array_ct);
	}
#line 1872 "./build/y.tab.c"
    break;

  case 78: /* ArrayEles: ArrayEles ',' @18 Assignable  */
#line 354 "./compiler.y"
                    {
		addArrayEle_j((yyvsp[-1].object_val).type);
		array_ct++;
	}
#line 1881 "./build/y.tab.c"
    break;

  case 80: /* ReturnStmt: RETURN Expression ';'  */
#line 363 "./compiler.y"
                            {
		printf("RETURN\n");
		addRet_j((yyvsp[-2].object_val).type, isMain);	//添加函數回傳
	}
#line 1890 "./build/y.tab.c"
    break;

  case 81: /* ReturnStmt: RETURN ';'  */
#line 367 "./compiler.y"
                 {
		printf("RETURN\n");
		addRet_j(OBJECT_TYPE_VOID, 0);	//添加函數回傳
	}
#line 1899 "./build/y.tab.c"
    break;

  case 82: /* ReturnStmt: %empty  */
#line 371 "./compiler.y"
          {
		printf("RETURN\n");
		addRet_j(OBJECT_TYPE_VOID, 0);	//添加函數回傳
	}
#line 1908 "./build/y.tab.c"
    break;

  case 83: /* $@19: %empty  */
#line 379 "./compiler.y"
               {
		addMsg("cout");
	}
#line 1916 "./build/y.tab.c"
    break;

  case 84: /* CoutStmt: COUT $@19 SHL PrintableList ';'  */
#line 381 "./compiler.y"
                                {
		addMsg("\n");
		printMsg();
	}
#line 1925 "./build/y.tab.c"
    break;

  case 87: /* Printable: STR_LIT  */
#line 395 "./compiler.y"
              { 
		addMsg(" string");
		printf("STR_LIT \"%s\"\n", (yyvsp[0].s_var));
		
		addPrint_j((yyvsp[0].s_var));}
#line 1935 "./build/y.tab.c"
    break;

  case 88: /* Printable: ENDL  */
#line 400 "./compiler.y"
           { 
		addMsg(" string");
		printf("IDENT (name=endl, address=-1)\n"); 

		addPrint_j("\n");
	}
#line 1946 "./build/y.tab.c"
    break;

  case 89: /* Printable: Expression  */
#line 406 "./compiler.y"
                     {
		addMsg(" ");
		addMsgObj(&(yyvsp[-1].object_val));

		addPrintExp_j((yyvsp[-1].object_val).type);
	}
#line 1957 "./build/y.tab.c"
    break;

  case 91: /* Expression: STR_LIT  */
#line 420 "./compiler.y"
                  {
		printf("STR_LIT \"%s\"\n", (yyvsp[0].s_var));
		code("ldc \"%s\"", (yyvsp[0].s_var));
	}
#line 1966 "./build/y.tab.c"
    break;

  case 93: /* Or: Or LOR And  */
#line 428 "./compiler.y"
                    {
		// here is correct
		objectExpBoolean('1', &(yyvsp[-2].object_val), &(yyvsp[-1].object_val), &(yyvsp[-3].object_val));
		
		addOpByType_j("or", (yyvsp[-3].object_val).type);
	}
#line 1977 "./build/y.tab.c"
    break;

  case 95: /* And: And LAN BitwiseOr  */
#line 438 "./compiler.y"
                           {
		objectExpBoolean('2', &(yyvsp[-2].object_val), &(yyvsp[-1].object_val), &(yyvsp[-3].object_val));
		
		addOpByType_j("and", (yyvsp[-3].object_val).type);
	}
#line 1987 "./build/y.tab.c"
    break;

  case 97: /* BitwiseOr: BitwiseOr BOR BitwiseXor  */
#line 447 "./compiler.y"
                                  {
		objectExpBinary('1', &(yyvsp[-2].object_val), &(yyvsp[-1].object_val), &(yyvsp[-3].object_val));
		
		addOpByType_j("or", (yyvsp[-3].object_val).type);
	}
#line 1997 "./build/y.tab.c"
    break;

  case 99: /* BitwiseXor: BitwiseXor BXO BitwiseAnd  */
#line 456 "./compiler.y"
                                   {
		objectExpBinary('2', &(yyvsp[-2].object_val), &(yyvsp[-1].object_val), &(yyvsp[-3].object_val));
		
		addOpByType_j("xor", (yyvsp[-3].object_val).type);	
	}
#line 2007 "./build/y.tab.c"
    break;

  case 101: /* BitwiseAnd: BitwiseAnd BAN Equality  */
#line 465 "./compiler.y"
                                 {
		objectExpBinary('3', &(yyvsp[-2].object_val), &(yyvsp[-1].object_val), &(yyvsp[-3].object_val));

		addOpByType_j("and", (yyvsp[-3].object_val).type);	
	}
#line 2017 "./build/y.tab.c"
    break;

  case 103: /* Equality: Equality EQL Relational  */
#line 474 "./compiler.y"
                                 {
		objectExpBoolean('3', &(yyvsp[-2].object_val), &(yyvsp[-1].object_val), &(yyvsp[-3].object_val));
		addOpByType_j("eql", (yyvsp[-3].object_val).type);	
	}
#line 2026 "./build/y.tab.c"
    break;

  case 104: /* Equality: Equality NEQ Relational  */
#line 478 "./compiler.y"
                                 {
		objectExpBoolean('4', &(yyvsp[-2].object_val), &(yyvsp[-1].object_val), &(yyvsp[-3].object_val));
		addOpByType_j("neq", (yyvsp[-3].object_val).type);
	}
#line 2035 "./build/y.tab.c"
    break;

  case 106: /* Relational: Relational LES Shift  */
#line 486 "./compiler.y"
                              {
		printf("LES\n");

		//位元運算
		addOpByType_j("les", (yyvsp[-3].object_val).type);
		(yyvsp[-3].object_val).type = OBJECT_TYPE_BOOL;
	}
#line 2047 "./build/y.tab.c"
    break;

  case 107: /* Relational: Relational GTR Shift  */
#line 493 "./compiler.y"
                              {
		printf("GTR\n");

		//位元運算
		addOpByType_j("gtr", (yyvsp[-3].object_val).type);
		(yyvsp[-3].object_val).type = OBJECT_TYPE_BOOL;
	}
#line 2059 "./build/y.tab.c"
    break;

  case 108: /* Relational: Relational LEQ Shift  */
#line 500 "./compiler.y"
                              {
		printf("LEQ\n");

		//位元運算
		addOpByType_j("leq", (yyvsp[-3].object_val).type);
		(yyvsp[-3].object_val).type = OBJECT_TYPE_BOOL;}
#line 2070 "./build/y.tab.c"
    break;

  case 109: /* Relational: Relational GEQ Shift  */
#line 507 "./compiler.y"
                              {
		printf("GEQ\n");

		//位元運算
		addOpByType_j("geq", (yyvsp[-3].object_val).type);
		(yyvsp[-3].object_val).type = OBJECT_TYPE_BOOL;}
#line 2081 "./build/y.tab.c"
    break;

  case 111: /* Shift: Shift SHR Additive  */
#line 518 "./compiler.y"
                            {
		printf("SHR\n");
		addOpByType_j("shr", (yyvsp[-3].object_val).type);
	}
#line 2090 "./build/y.tab.c"
    break;

  case 113: /* Additive: Additive ADD Multiplicative  */
#line 526 "./compiler.y"
                                     {
		printf("ADD\n");

		//輸出 加法指令
		addOpByType_j("add", (yyvsp[-3].object_val).type);}
#line 2100 "./build/y.tab.c"
    break;

  case 114: /* Additive: Additive SUB Multiplicative  */
#line 532 "./compiler.y"
                                     {
		printf("SUB\n");
		
		//輸出 減法指令
		addOpByType_j("sub", (yyvsp[-3].object_val).type);}
#line 2110 "./build/y.tab.c"
    break;

  case 116: /* Multiplicative: Multiplicative MUL TypeCast  */
#line 542 "./compiler.y"
                                     {
		printf("MUL\n");

		//輸出 乘法指令
		addOpByType_j("mul", (yyvsp[-3].object_val).type);}
#line 2120 "./build/y.tab.c"
    break;

  case 117: /* Multiplicative: Multiplicative DIV TypeCast  */
#line 547 "./compiler.y"
                                     {
		printf("DIV\n");
		
		//輸出 除法指令
		addOpByType_j("div", (yyvsp[-3].object_val).type);}
#line 2130 "./build/y.tab.c"
    break;

  case 118: /* Multiplicative: Multiplicative REM TypeCast  */
#line 552 "./compiler.y"
                                     {
		printf("REM\n");

		//輸出 模數指令
		addOpByType_j("rem", (yyvsp[-3].object_val).type);
	}
#line 2141 "./build/y.tab.c"
    break;

  case 120: /* TypeCast: '(' VARIABLE_T ')' Unary  */
#line 563 "./compiler.y"
                                   {
		(yyvsp[-4].object_val).type = (yyvsp[-2].var_type);
		printCastInfo((yyvsp[-2].var_type));

		addCast_j((yyvsp[-2].var_type));
	}
#line 2152 "./build/y.tab.c"
    break;

  case 121: /* Unary: BNT Unary  */
#line 572 "./compiler.y"
                   {
		(yyvsp[-2].object_val).type = (yyvsp[-1].object_val).type;	//傳遞類別
		printf("BNT\n"); 

		//輸出unary negation指令
		addOpByType_j("not", (yyvsp[-2].object_val).type);
	}
#line 2164 "./build/y.tab.c"
    break;

  case 122: /* Unary: ADD Unary  */
#line 579 "./compiler.y"
                   {
		(yyvsp[-2].object_val).type = (yyvsp[-1].object_val).type;	//傳遞類別
		printf("ADD\n");}
#line 2172 "./build/y.tab.c"
    break;

  case 123: /* Unary: SUB Unary  */
#line 582 "./compiler.y"
                   {
		(yyvsp[-2].object_val).type = (yyvsp[-1].object_val).type;	//傳遞類別
		printf("NEG\n");	//輸出資訊

		//輸出unary negation指令
		addOpByType_j("neg", (yyvsp[-2].object_val).type);
	}
#line 2184 "./build/y.tab.c"
    break;

  case 124: /* Unary: NOT Unary  */
#line 589 "./compiler.y"
                   {
		(yyvsp[-2].object_val).type = (yyvsp[-1].object_val).type;	//傳遞類別
		printf("NOT\n");
		
		addOpByType_j("not", (yyvsp[-2].object_val).type);}
#line 2194 "./build/y.tab.c"
    break;

  case 127: /* Post: Primary INC_ASSIGN  */
#line 599 "./compiler.y"
                             {
		printf("INC_ASSIGN\n");

		//設值操作
		addAssign_j(assign_var, "inc");

		//將變數設值
		addLocalVar_j((yyvsp[-1].s_var), 'y', (yyvsp[-2].object_val).type);
	}
#line 2208 "./build/y.tab.c"
    break;

  case 128: /* Post: Primary DEC_ASSIGN  */
#line 608 "./compiler.y"
                             {
		printf("DEC_ASSIGN\n");
		
		//addOpByType_j("dec", $<object_val>0.type);
		addAssign_j(assign_var, "dec");

		//將變數設值
		addLocalVar_j((yyvsp[-1].s_var), 'y', (yyvsp[-2].object_val).type);
	}
#line 2222 "./build/y.tab.c"
    break;

  case 129: /* Primary: INT_LIT  */
#line 620 "./compiler.y"
             {
			(yyvsp[-1].object_val).type = OBJECT_TYPE_INT;
			printf("INT_LIT %d\n", (yyvsp[0].i_var));

			//輸出 載入整數到stack頂端
			code("ldc %d", (yyvsp[0].i_var));
		}
#line 2234 "./build/y.tab.c"
    break;

  case 130: /* Primary: FLOAT_LIT  */
#line 627 "./compiler.y"
                    {
			(yyvsp[-1].object_val).type = OBJECT_TYPE_FLOAT;
			printf("FLOAT_LIT %f\n", (yyvsp[0].f_var));

			//輸出 載入整數到stack頂端
			code("ldc %f", (yyvsp[0].f_var));
		}
#line 2246 "./build/y.tab.c"
    break;

  case 131: /* Primary: '(' Expression ')'  */
#line 634 "./compiler.y"
                         {
			(yyvsp[-3].object_val).type = (yyvsp[-2].object_val).type;
		}
#line 2254 "./build/y.tab.c"
    break;

  case 132: /* Primary: BOOL_LIT  */
#line 637 "./compiler.y"
                   {
			(yyvsp[-1].object_val).type = OBJECT_TYPE_BOOL; 
			printBool((yyvsp[0].b_var));

			//輸出 載入整數到stack頂端
			code("ldc %d", (yyvsp[0].b_var));
		}
#line 2266 "./build/y.tab.c"
    break;

  case 133: /* Primary: IDENT  */
#line 644 "./compiler.y"
                {
		//詞性修飾
		ObjectType type = getVarTypeByName((yyvsp[0].s_var));
		(yyvsp[-1].object_val).type = type;

		//輸出資訊
		printIDByName((yyvsp[0].s_var), 'v');

		//輸出 載入該變數到stack頂端
		addPushLocalVar_j((yyvsp[0].s_var), ' ');
		assign_var = (yyvsp[0].s_var);	//設置當前修改的變數名稱
	}
#line 2283 "./build/y.tab.c"
    break;

  case 135: /* @20: %empty  */
#line 657 "./compiler.y"
                    {
		assign_var = (yyvsp[-1].s_var);

		addPushLocalVar_j((yyvsp[-1].s_var), 'L');	//取得陣列ref	
	}
#line 2293 "./build/y.tab.c"
    break;

  case 136: /* Primary: IDENT '[' @20 List  */
#line 661 "./compiler.y"
               {
		(yyvsp[-4].object_val).type = (yyvsp[-1].object_val).type;
	}
#line 2301 "./build/y.tab.c"
    break;

  case 137: /* List: Expression ']'  */
#line 667 "./compiler.y"
                         {
		ObjectType type = getVarTypeByName(assign_var);
		(yyvsp[-2].object_val).type = type;
		printIDByName(assign_var, 'v');

		addPushLocalVar_j(assign_var, 'l');
	}
#line 2313 "./build/y.tab.c"
    break;

  case 138: /* List: Expression ']' '[' Expression ']'  */
#line 674 "./compiler.y"
                                            {
		ObjectType type = getVarTypeByName(assign_var);
		(yyvsp[-5].object_val).type = type;
		printIDByName(assign_var, 'v');

		codeRaw("swap");
		codeRaw("ldc 3");
		codeRaw("imul");
		codeRaw("iadd");//count index

		addPushLocalVar_j(assign_var, 'l');
	}
#line 2330 "./build/y.tab.c"
    break;

  case 139: /* FunctionCall: IDENT '(' ArgumentList ')'  */
#line 691 "./compiler.y"
                                     {
		(yyvsp[-4].object_val).type = getFuncType((yyvsp[-3].s_var));
		printIDByName((yyvsp[-3].s_var), 'f');
		printf("call: %s", (yyvsp[-3].s_var));
		printSigByName((yyvsp[-3].s_var));
		printf("\n");

		code("invokestatic Main/%s%s", (yyvsp[-3].s_var), getSigByName((yyvsp[-3].s_var)));
	}
#line 2344 "./build/y.tab.c"
    break;

  case 143: /* $@21: %empty  */
#line 714 "./compiler.y"
                       {
		createFunction((yyvsp[-1].var_type), (yyvsp[0].s_var));
		addFunDef_j((yyvsp[0].s_var), 'n');

		if(strcmp((yyvsp[0].s_var), "main")==0) isMain = 1;
		else isMain = 0;
	}
#line 2356 "./build/y.tab.c"
    break;

  case 144: /* $@22: %empty  */
#line 720 "./compiler.y"
              {
		pushScope();

		para_ct = 0;
	}
#line 2366 "./build/y.tab.c"
    break;

  case 145: /* $@23: %empty  */
#line 724 "./compiler.y"
                                        {
		setFuncSig((yyvsp[-5].s_var), (yyvsp[-6].var_type));
		addFunDef_j((yyvsp[-5].s_var), 's');		//傳入函數名稱，在main.j中建立函數
	
		//在函數區塊，重置變數位置
		for(int i=0;i<para_ct;i++) {
			
			SymbolData* sp = para[i]->symbol;
			ObjectType type= para[i]->type;

			//創建並添加該變數
			if(type == OBJECT_TYPE_INT || type == OBJECT_TYPE_BOOL) code("iload %d", i);
			else if(type ==OBJECT_TYPE_FLOAT) code("fload %d", i);
			else if(type ==OBJECT_TYPE_STR) code("aload %d", i);

			addLocalVar_j(sp->name, 'y', type);
		}

	}
#line 2390 "./build/y.tab.c"
    break;

  case 146: /* FunctionDefStmt: VARIABLE_T IDENT $@21 '(' $@22 FunctionParameterStmtList ')' $@23 '{' GlobalStmtList ReturnStmt '}'  */
#line 742 "./compiler.y"
                                            {
		dumpScope();
		addFunEnd_j();	//添加函數結尾
	}
#line 2399 "./build/y.tab.c"
    break;

  case 150: /* FunctionParameterStmt: VARIABLE_T IDENT  */
#line 754 "./compiler.y"
                       {
		insert((yyvsp[0].s_var), (yyvsp[-1].var_type), 3);

		para[para_ct] = getObjectByName((yyvsp[0].s_var), 'v');
		para_ct++;
	}
#line 2410 "./build/y.tab.c"
    break;

  case 151: /* $@24: %empty  */
#line 760 "./compiler.y"
                       { 
		insert((yyvsp[0].s_var), (yyvsp[-1].var_type), 4);

		para[para_ct] = getObjectByName((yyvsp[0].s_var), 'v');
		para_ct++;

	}
#line 2422 "./build/y.tab.c"
    break;


#line 2426 "./build/y.tab.c"

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

#line 768 "./compiler.y"

/* C code section */
