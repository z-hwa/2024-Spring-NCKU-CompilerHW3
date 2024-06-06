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

#line 82 "./build/y.tab.c"

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
  YYSYMBOL_ForCondition = 71,              /* ForCondition  */
  YYSYMBOL_72_5 = 72,                      /* $@5  */
  YYSYMBOL_73_6 = 73,                      /* $@6  */
  YYSYMBOL_ExpressionStmt = 74,            /* ExpressionStmt  */
  YYSYMBOL_CompoundStmt = 75,              /* CompoundStmt  */
  YYSYMBOL_SelectionStmt = 76,             /* SelectionStmt  */
  YYSYMBOL_77_7 = 77,                      /* $@7  */
  YYSYMBOL_78_8 = 78,                      /* $@8  */
  YYSYMBOL_Selection = 79,                 /* Selection  */
  YYSYMBOL_80_9 = 80,                      /* $@9  */
  YYSYMBOL_81_10 = 81,                     /* $@10  */
  YYSYMBOL_AssignStmt = 82,                /* AssignStmt  */
  YYSYMBOL_AssignBody = 83,                /* AssignBody  */
  YYSYMBOL_84_11 = 84,                     /* $@11  */
  YYSYMBOL_85_12 = 85,                     /* $@12  */
  YYSYMBOL_86_13 = 86,                     /* $@13  */
  YYSYMBOL_Assign = 87,                    /* Assign  */
  YYSYMBOL_Assignable = 88,                /* Assignable  */
  YYSYMBOL_DefineVariableStmt = 89,        /* DefineVariableStmt  */
  YYSYMBOL_DeclaratorList = 90,            /* DeclaratorList  */
  YYSYMBOL_Declarator = 91,                /* Declarator  */
  YYSYMBOL_ArrayEles = 92,                 /* ArrayEles  */
  YYSYMBOL_ReturnStmt = 93,                /* ReturnStmt  */
  YYSYMBOL_CoutStmt = 94,                  /* CoutStmt  */
  YYSYMBOL_95_14 = 95,                     /* $@14  */
  YYSYMBOL_PrintableList = 96,             /* PrintableList  */
  YYSYMBOL_Printable = 97,                 /* Printable  */
  YYSYMBOL_Expression = 98,                /* Expression  */
  YYSYMBOL_Or = 99,                        /* Or  */
  YYSYMBOL_And = 100,                      /* And  */
  YYSYMBOL_BitwiseOr = 101,                /* BitwiseOr  */
  YYSYMBOL_BitwiseXor = 102,               /* BitwiseXor  */
  YYSYMBOL_BitwiseAnd = 103,               /* BitwiseAnd  */
  YYSYMBOL_Equality = 104,                 /* Equality  */
  YYSYMBOL_Relational = 105,               /* Relational  */
  YYSYMBOL_Shift = 106,                    /* Shift  */
  YYSYMBOL_Additive = 107,                 /* Additive  */
  YYSYMBOL_Multiplicative = 108,           /* Multiplicative  */
  YYSYMBOL_TypeCast = 109,                 /* TypeCast  */
  YYSYMBOL_Unary = 110,                    /* Unary  */
  YYSYMBOL_Post = 111,                     /* Post  */
  YYSYMBOL_Primary = 112,                  /* Primary  */
  YYSYMBOL_FunctionCall = 113,             /* FunctionCall  */
  YYSYMBOL_ArgumentList = 114,             /* ArgumentList  */
  YYSYMBOL_ArgumentListNonEmpty = 115,     /* ArgumentListNonEmpty  */
  YYSYMBOL_FunctionDefStmt = 116,          /* FunctionDefStmt  */
  YYSYMBOL_117_15 = 117,                   /* $@15  */
  YYSYMBOL_118_16 = 118,                   /* $@16  */
  YYSYMBOL_119_17 = 119,                   /* $@17  */
  YYSYMBOL_FunctionParameterStmtList = 120, /* FunctionParameterStmtList  */
  YYSYMBOL_FunctionParameterStmt = 121,    /* FunctionParameterStmt  */
  YYSYMBOL_122_18 = 122                    /* $@18  */
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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   447

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  60
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  63
/* YYNRULES -- Number of rules.  */
#define YYNRULES  143
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  253

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
       0,    63,    63,    63,    67,    71,    72,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    89,    94,   102,   105,
     102,   113,   113,   124,   126,   124,   129,   137,   138,   139,
     140,   141,   146,   147,   153,   153,   160,   160,   166,   167,
     167,   167,   173,   177,   177,   188,   188,   193,   193,   199,
     200,   203,   207,   210,   213,   216,   219,   222,   225,   228,
     231,   237,   243,   248,   252,   253,   257,   264,   271,   276,
     280,   289,   290,   291,   296,   299,   306,   306,   316,   317,
     322,   327,   333,   345,   347,   354,   355,   364,   365,   373,
     374,   382,   383,   391,   392,   400,   401,   405,   412,   413,
     420,   427,   434,   444,   445,   452,   453,   459,   468,   469,
     474,   479,   489,   490,   499,   506,   509,   516,   521,   525,
     526,   535,   547,   554,   561,   564,   571,   583,   584,   589,
     599,   611,   615,   616,   622,   625,   627,   622,   637,   638,
     639,   643,   644,   644
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
  "IterationStmt", "$@2", "$@3", "$@4", "ForCondition", "$@5", "$@6",
  "ExpressionStmt", "CompoundStmt", "SelectionStmt", "$@7", "$@8",
  "Selection", "$@9", "$@10", "AssignStmt", "AssignBody", "$@11", "$@12",
  "$@13", "Assign", "Assignable", "DefineVariableStmt", "DeclaratorList",
  "Declarator", "ArrayEles", "ReturnStmt", "CoutStmt", "$@14",
  "PrintableList", "Printable", "Expression", "Or", "And", "BitwiseOr",
  "BitwiseXor", "BitwiseAnd", "Equality", "Relational", "Shift",
  "Additive", "Multiplicative", "TypeCast", "Unary", "Post", "Primary",
  "FunctionCall", "ArgumentList", "ArgumentListNonEmpty",
  "FunctionDefStmt", "$@15", "$@16", "$@17", "FunctionParameterStmtList",
  "FunctionParameterStmt", "$@18", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-132)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-143)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      31,    55,   232,  -132,  -132,   -18,  -132,  -132,   352,    35,
      -8,   -23,   232,  -132,  -132,  -132,  -132,    48,  -132,    39,
    -132,  -132,  -132,    52,  -132,   137,   362,   100,   102,  -132,
     -22,  -132,  -132,  -132,  -132,   271,   382,   382,   382,   382,
     113,   139,   138,   156,   157,   158,    96,   103,   164,    68,
      -3,  -132,  -132,  -132,    93,  -132,  -132,     6,    18,  -132,
     362,   362,   322,  -132,  -132,  -132,  -132,    56,   131,   312,
     362,   362,   132,   133,   362,  -132,  -132,  -132,  -132,  -132,
     392,   392,   392,   392,   392,   392,   392,   392,   392,   392,
     392,   392,   392,   392,   392,   392,   392,  -132,  -132,   372,
     362,   125,  -132,   129,  -132,   140,   118,   120,   322,   322,
     322,   322,   322,   322,   322,   322,   322,   322,   322,  -132,
    -132,  -132,  -132,    50,  -132,  -132,    53,  -132,  -132,  -132,
    -132,   141,    33,   143,  -132,  -132,  -132,   144,   149,   121,
     382,  -132,   138,   156,   157,   158,    96,   103,   103,   164,
     164,   164,   164,    68,    -3,    -3,  -132,  -132,  -132,  -132,
     134,  -132,    12,  -132,  -132,   362,   136,  -132,  -132,  -132,
    -132,  -132,  -132,  -132,  -132,  -132,  -132,  -132,  -132,  -132,
    -132,    56,  -132,    50,    10,   362,    95,   337,  -132,  -132,
     142,  -132,    34,   146,  -132,   362,   322,   232,  -132,  -132,
     152,   145,   232,   232,  -132,   129,  -132,    95,   362,   162,
     362,   160,    20,  -132,   150,  -132,   232,  -132,   244,   124,
     337,  -132,   154,   372,   155,   159,  -132,   146,  -132,   172,
     362,  -132,  -132,  -132,  -132,    38,  -132,   161,   177,  -132,
     322,  -132,   168,  -132,   372,   169,   232,  -132,   296,  -132,
    -132,   187,  -132
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     0,     1,    76,     0,    21,    18,     0,     0,
       0,    43,     3,     6,    15,    14,    13,    12,    11,     0,
       7,    10,     9,     0,     8,     0,     0,     0,     0,    75,
     126,   125,   122,   123,    84,     0,     0,     0,     0,     0,
       0,    83,    85,    87,    89,    91,    93,    95,    98,   103,
     105,   108,   112,   118,   119,   127,    17,    66,     0,    64,
       0,     0,     0,     5,    36,    42,    16,     0,     0,     0,
       0,     0,     0,     0,     0,   116,   117,   114,   115,    74,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   120,   121,     0,
       0,     0,    63,     0,   132,     0,   131,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    61,
      44,    49,    62,     0,    81,    80,     0,    78,    82,    34,
      31,     0,    43,     0,    23,    29,    28,    30,     0,     0,
       0,   124,    86,    88,    90,    92,    94,    96,    97,   100,
      99,   102,   101,   104,   107,   106,   109,   110,   111,    67,
       0,   135,    66,    65,   130,     0,    45,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    39,    38,
      37,     0,    77,     0,    66,     0,     0,     0,    27,    19,
     128,   113,    68,   140,   133,     0,     0,     0,    79,    35,
       0,     0,     0,    33,    22,     0,    24,     0,     0,     0,
       0,     0,     0,   139,     0,    46,    40,    26,    45,     0,
       0,    20,     0,    73,     0,   141,   136,     0,    47,     0,
       0,    32,    25,   129,    71,     0,    69,     0,     0,   138,
       0,    41,     0,    70,     0,     0,     0,    48,    47,    72,
     143,     0,   137
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -132,  -132,  -132,     0,    -9,  -132,  -132,  -132,  -132,  -132,
    -132,  -132,  -132,  -132,  -131,    21,  -132,  -132,  -132,    51,
    -132,  -132,  -132,   -68,  -132,  -132,  -132,   -97,   -94,   -65,
    -132,   126,  -132,  -132,  -132,  -132,  -132,    58,     1,  -132,
     163,   166,   182,   153,   188,    63,    57,   147,    46,    40,
     -14,  -132,  -132,    -2,  -132,  -132,  -132,  -132,  -132,  -132,
    -132,    13,  -132
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     2,   203,    13,    14,    15,    16,    28,   207,
      27,   133,   187,   220,   134,   204,    17,   183,   123,   180,
     197,   229,    18,    19,    62,   196,   240,   120,   121,    20,
      58,    59,   235,    21,    22,    25,   126,   127,   122,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,   105,   106,    24,   101,   193,   238,
     212,   213,   237
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      23,   135,    12,    63,   136,   159,    94,    95,    96,    40,
      23,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,    75,    76,    77,    78,    99,    68,    60,    60,
      99,    -4,    99,    26,    61,    71,    73,  -126,    57,  -126,
    -126,  -126,  -126,  -126,  -126,  -126,  -126,  -126,  -126,  -126,
    -126,  -126,  -126,     4,   209,     3,   206,  -134,   181,   102,
     226,   104,   107,   100,  -126,  -126,   200,   100,   128,   100,
     137,   138,   139,  -126,  -126,    73,    56,   103,  -126,   227,
      65,   243,    64,     5,    60,     6,     7,     8,     9,   232,
     185,   210,   178,    66,   182,    10,    11,   244,     4,   215,
     124,   160,    30,    31,    32,    33,   125,    35,    36,    37,
      38,    39,    85,    86,   179,    87,    88,    89,    90,   135,
      92,    23,   136,    93,    97,    98,   191,     4,     5,   234,
       6,     7,     8,     9,   156,   157,   158,   202,   154,   155,
      10,    11,    67,   247,   149,   150,   151,   152,   147,   148,
     249,    69,   135,    70,    79,   136,    81,     5,    80,     6,
       7,     8,     9,    82,    84,    83,   194,   231,    91,    10,
      11,   129,   140,   141,   179,   162,   161,   165,   166,   190,
     164,    23,   128,   186,    23,   188,   201,   184,   137,   189,
       4,   211,   192,   195,    63,    23,   214,   216,   217,   208,
      23,    23,   219,   218,   223,    23,   225,    63,   228,   222,
      63,   224,   233,   236,    23,   241,  -142,    23,   245,   246,
       5,   137,     6,     7,     8,     9,   248,   250,   221,   163,
     252,   242,    10,    11,   199,     4,   145,     0,   153,   198,
     239,     0,    63,   142,    23,     0,   251,   143,  -128,    23,
    -128,  -128,  -128,  -128,  -128,  -128,  -128,  -128,  -128,  -128,
    -128,  -128,  -128,  -128,   144,     5,     0,     6,     7,     8,
       9,     0,   146,     0,     0,  -128,  -128,    10,    11,     0,
       0,     0,     0,     0,  -128,  -128,     0,     0,     0,  -128,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    -129,   230,  -129,  -129,  -129,  -129,  -129,  -129,  -129,  -129,
    -129,  -129,  -129,  -129,  -129,  -129,    72,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,  -129,  -129,     0,
       0,     0,     0,     0,     0,     0,  -129,  -129,     0,     0,
       0,  -129,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   130,     0,     0,     0,   131,   132,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    30,    31,
      32,    33,   119,    35,    36,    37,    38,    39,   130,     0,
       0,     0,   205,   132,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    29,     0,     0,     0,     0,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    30,    31,
      32,    33,   119,    35,    36,    37,    38,    39,    30,    31,
      32,    33,     0,    74,    36,    37,    38,    39,    30,    31,
      32,    33,     0,    35,    36,    37,    38,    39
};

static const yytype_int16 yycheck[] =
{
       2,    69,     2,    12,    69,    99,     9,    10,    11,     8,
      12,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,    36,    37,    38,    39,    20,    26,    51,    51,
      20,     0,    20,    51,    57,    57,    35,     4,    46,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,     3,    20,     0,   187,    51,     5,    41,
      40,    60,    61,    57,    31,    32,    56,    57,    67,    57,
      69,    70,    71,    40,    41,    74,    41,    59,    45,    59,
      41,    43,    34,    33,    51,    35,    36,    37,    38,   220,
      57,    57,    42,    41,    41,    45,    46,    59,     3,   196,
      44,   100,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    16,    17,   123,    12,    13,    14,    15,   187,
      52,   123,   187,    55,    31,    32,   140,     3,    33,   223,
      35,    36,    37,    38,    94,    95,    96,    42,    92,    93,
      45,    46,     5,   240,    87,    88,    89,    90,    85,    86,
     244,    51,   220,    51,    41,   220,    18,    33,    19,    35,
      36,    37,    38,     7,     6,     8,   165,    43,     4,    45,
      46,    40,    40,    40,   183,    46,    51,    59,    58,    58,
      40,   183,   181,    40,   186,    41,   185,    46,   187,    40,
       3,    45,    58,    57,   203,   197,   195,   197,    46,    57,
     202,   203,   202,    58,    42,   207,    46,   216,    58,   208,
     219,   210,    58,    58,   216,    43,    57,   219,    57,    42,
      33,   220,    35,    36,    37,    38,    58,    58,   207,   103,
      43,   230,    45,    46,   183,     3,    83,    -1,    91,   181,
     227,    -1,   251,    80,   246,    -1,   246,    81,     4,   251,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    82,    33,    -1,    35,    36,    37,
      38,    -1,    84,    -1,    -1,    31,    32,    45,    46,    -1,
      -1,    -1,    -1,    -1,    40,    41,    -1,    -1,    -1,    45,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       4,    57,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    31,    32,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    40,    41,    -1,    -1,
      -1,    45,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    41,    -1,    -1,    -1,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    41,    -1,
      -1,    -1,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    41,    -1,    -1,    -1,    -1,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    46,    47,
      48,    49,    -1,    51,    52,    53,    54,    55,    46,    47,
      48,    49,    -1,    51,    52,    53,    54,    55
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    61,    62,     0,     3,    33,    35,    36,    37,    38,
      45,    46,    63,    64,    65,    66,    67,    76,    82,    83,
      89,    93,    94,   113,   116,    95,    51,    70,    68,    41,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,    41,    46,    90,    91,
      51,    57,    84,    64,    34,    41,    41,     5,    98,    51,
      51,    57,    45,    98,    51,   110,   110,   110,   110,    41,
      19,    18,     7,     8,     6,    16,    17,    12,    13,    14,
      15,     4,    52,    55,     9,    10,    11,    31,    32,    20,
      57,   117,    41,    59,    98,   114,   115,    98,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    50,
      87,    88,    98,    78,    44,    50,    96,    97,    98,    40,
      41,    45,    46,    71,    74,    83,    89,    98,    98,    98,
      40,    40,   100,   101,   102,   103,   104,   105,   105,   106,
     106,   106,   106,   107,   108,   108,   109,   109,   109,    88,
      98,    51,    46,    91,    40,    59,    58,    87,    87,    87,
      87,    87,    87,    87,    87,    87,    87,    87,    42,    64,
      79,     5,    41,    77,    46,    57,    40,    72,    41,    40,
      58,   110,    58,   118,    98,    57,    85,    80,    97,    79,
      56,    98,    42,    63,    75,    45,    74,    69,    57,    20,
      57,    45,   120,   121,    98,    87,    63,    46,    58,    63,
      73,    75,    98,    42,    98,    46,    40,    59,    58,    81,
      57,    43,    74,    58,    88,    92,    58,   122,   119,   121,
      86,    43,    98,    43,    59,    57,    42,    87,    58,    88,
      58,    63,    43
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    60,    62,    61,    61,    63,    63,    64,    64,    64,
      64,    64,    64,    64,    64,    64,    65,    66,    68,    69,
      67,    70,    67,    72,    73,    71,    71,    74,    74,    74,
      74,    74,    75,    75,    77,    76,    78,    76,    79,    80,
      81,    79,    82,    84,    83,    85,    83,    86,    83,    87,
      87,    87,    87,    87,    87,    87,    87,    87,    87,    87,
      87,    88,    88,    89,    90,    90,    91,    91,    91,    91,
      91,    92,    92,    92,    93,    93,    95,    94,    96,    96,
      97,    97,    97,    98,    98,    99,    99,   100,   100,   101,
     101,   102,   102,   103,   103,   104,   104,   104,   105,   105,
     105,   105,   105,   106,   106,   107,   107,   107,   108,   108,
     108,   108,   109,   109,   110,   110,   110,   110,   110,   111,
     111,   111,   112,   112,   112,   112,   112,   112,   112,   112,
     113,   114,   115,   115,   117,   118,   119,   116,   120,   120,
     120,   121,   122,   121
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     0,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     2,     0,     0,
       7,     0,     6,     0,     0,     5,     4,     2,     1,     1,
       1,     1,     3,     1,     0,     6,     0,     4,     1,     0,
       0,     5,     2,     0,     3,     0,     6,     0,     9,     1,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     1,     1,     3,     1,     3,     1,     3,     4,     7,
       8,     1,     3,     0,     3,     2,     0,     5,     1,     3,
       1,     1,     1,     1,     1,     1,     3,     1,     3,     1,
       3,     1,     3,     1,     3,     1,     3,     3,     1,     3,
       3,     3,     3,     1,     3,     1,     3,     3,     1,     3,
       3,     3,     1,     4,     2,     2,     2,     2,     1,     1,
       2,     2,     1,     1,     3,     1,     1,     1,     4,     7,
       4,     1,     1,     3,     0,     0,     0,    11,     3,     1,
       0,     2,     0,     5
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
#line 63 "./compiler.y"
      { 
		pushScope();
		addFileStart_j();
	 }
#line 1421 "./build/y.tab.c"
    break;

  case 3: /* Program: $@1 GlobalStmtList  */
#line 66 "./compiler.y"
                          { dumpScope(); }
#line 1427 "./build/y.tab.c"
    break;

  case 12: /* GlobalStmt: SelectionStmt  */
#line 81 "./compiler.y"
                        {addIf_j('o');}
#line 1433 "./build/y.tab.c"
    break;

  case 17: /* JumpStmt: BREAK ';'  */
#line 94 "./compiler.y"
                    {
		printf("BREAK\n");
		addBreak_j();
	}
#line 1442 "./build/y.tab.c"
    break;

  case 18: /* $@2: %empty  */
#line 102 "./compiler.y"
                {
		printf("WHILE\n");
		addWhile_j('i');	//設置循環標記
	}
#line 1451 "./build/y.tab.c"
    break;

  case 19: /* $@3: %empty  */
#line 105 "./compiler.y"
                             {
		addWhile_j('w');	//check condition
		pushScope();
	}
#line 1460 "./build/y.tab.c"
    break;

  case 20: /* IterationStmt: WHILE $@2 '(' Expression ')' $@3 CompoundStmt  */
#line 108 "./compiler.y"
                       {
		addWhile_j('c');	//go to 循環標記
		dumpScope();
		addWhile_j('o');	//離開標記
	}
#line 1470 "./build/y.tab.c"
    break;

  case 21: /* $@4: %empty  */
#line 113 "./compiler.y"
              {
		printf("FOR\n");
		pushScope();
	}
#line 1479 "./build/y.tab.c"
    break;

  case 22: /* IterationStmt: FOR $@4 '(' ForCondition ')' CompoundStmt  */
#line 116 "./compiler.y"
                                            {
		addFor_j('c');	//go to 循環標記
		dumpScope();
		addFor_j('o');	//離開標記
	}
#line 1489 "./build/y.tab.c"
    break;

  case 23: /* $@5: %empty  */
#line 124 "./compiler.y"
                         {
		addFor_j('i');	//設置循環標記;
	}
#line 1497 "./build/y.tab.c"
    break;

  case 24: /* $@6: %empty  */
#line 126 "./compiler.y"
                         {
		addFor_j('f');	//check condition
	}
#line 1505 "./build/y.tab.c"
    break;

  case 26: /* ForCondition: VARIABLE_T IDENT ':' IDENT  */
#line 129 "./compiler.y"
                                     {
		//auto i:a	類型的for迴圈
		insert((yyvsp[-2].s_var), getVarTypeByName((yyvsp[0].s_var)), 1);
		printIDByName((yyvsp[0].s_var), 'v'); 
	}
#line 1515 "./build/y.tab.c"
    break;

  case 34: /* $@7: %empty  */
#line 153 "./compiler.y"
                               { 
		printf("IF\n");
		addIf_j('i');	//判斷條件是否為真，錯的話跳出
	}
#line 1524 "./build/y.tab.c"
    break;

  case 35: /* SelectionStmt: IF '(' Expression ')' $@7 Selection  */
#line 156 "./compiler.y"
                    {
		addIf_j('g');
		addIf_j('e');
	}
#line 1533 "./build/y.tab.c"
    break;

  case 36: /* $@8: %empty  */
#line 160 "./compiler.y"
                             {
		printf("ELSE\n");
	}
#line 1541 "./build/y.tab.c"
    break;

  case 39: /* $@9: %empty  */
#line 167 "./compiler.y"
              {pushScope();}
#line 1547 "./build/y.tab.c"
    break;

  case 40: /* $@10: %empty  */
#line 167 "./compiler.y"
                                            {dumpScope();}
#line 1553 "./build/y.tab.c"
    break;

  case 43: /* $@11: %empty  */
#line 177 "./compiler.y"
                { 
		printIDByName((yyvsp[0].s_var), 'v');	//輸出該變數資訊

		assign_var = (yyvsp[0].s_var);
		addPushLocalVar_j((yyvsp[0].s_var));	//將當前設值的變數放進stack
	}
#line 1564 "./build/y.tab.c"
    break;

  case 44: /* AssignBody: IDENT $@11 Assign  */
#line 182 "./compiler.y"
                 {
		(yyvsp[-3].object_val).type = OBJECT_TYPE_BOOL;	//設值成功，回傳bool

		//將變數設值
		addLocalVar_j((yyvsp[-2].s_var), 'y', nowDealType);
	}
#line 1575 "./build/y.tab.c"
    break;

  case 45: /* $@12: %empty  */
#line 188 "./compiler.y"
                                   {
		printIDByName((yyvsp[-3].s_var), 'v');
	}
#line 1583 "./build/y.tab.c"
    break;

  case 46: /* AssignBody: IDENT '[' Expression ']' $@12 Assign  */
#line 190 "./compiler.y"
                 {
		(yyvsp[-6].object_val).type = OBJECT_TYPE_BOOL;
	}
#line 1591 "./build/y.tab.c"
    break;

  case 47: /* $@13: %empty  */
#line 193 "./compiler.y"
                                                      {
		printIDByName((yyvsp[-6].s_var), 'v');
	}
#line 1599 "./build/y.tab.c"
    break;

  case 48: /* AssignBody: IDENT '[' Expression ']' '[' Expression ']' $@13 Assign  */
#line 195 "./compiler.y"
                 {(yyvsp[-9].object_val).type = OBJECT_TYPE_BOOL;}
#line 1605 "./build/y.tab.c"
    break;

  case 50: /* Assign: VAL_ASSIGN Assign  */
#line 200 "./compiler.y"
                           {
		printf("EQL_ASSIGN\n");
	}
#line 1613 "./build/y.tab.c"
    break;

  case 51: /* Assign: ADD_ASSIGN Assign  */
#line 203 "./compiler.y"
                           {
		printf("ADD_ASSIGN\n");
		addAssign_j(assign_var, "add");
	}
#line 1622 "./build/y.tab.c"
    break;

  case 52: /* Assign: SUB_ASSIGN Assign  */
#line 207 "./compiler.y"
                           {
		printf("SUB_ASSIGN\n");
		addAssign_j(assign_var, "sub");}
#line 1630 "./build/y.tab.c"
    break;

  case 53: /* Assign: MUL_ASSIGN Assign  */
#line 210 "./compiler.y"
                           {
		printf("MUL_ASSIGN\n");
		addAssign_j(assign_var, "mul");}
#line 1638 "./build/y.tab.c"
    break;

  case 54: /* Assign: DIV_ASSIGN Assign  */
#line 213 "./compiler.y"
                           {
		printf("DIV_ASSIGN\n");
		addAssign_j(assign_var, "div");}
#line 1646 "./build/y.tab.c"
    break;

  case 55: /* Assign: REM_ASSIGN Assign  */
#line 216 "./compiler.y"
                           {
		printf("REM_ASSIGN\n");
		addAssign_j(assign_var, "rem");}
#line 1654 "./build/y.tab.c"
    break;

  case 56: /* Assign: BAN_ASSIGN Assign  */
#line 219 "./compiler.y"
                           {
		printf("BAN_ASSIGN\n");
		addAssign_j(assign_var, "and");}
#line 1662 "./build/y.tab.c"
    break;

  case 57: /* Assign: BOR_ASSIGN Assign  */
#line 222 "./compiler.y"
                           {
		printf("BOR_ASSIGN\n");
		addAssign_j(assign_var, "or");}
#line 1670 "./build/y.tab.c"
    break;

  case 58: /* Assign: BXO_ASSIGN Assign  */
#line 225 "./compiler.y"
                           {
		printf("BXO_ASSIGN\n");
		addAssign_j(assign_var, "xor");}
#line 1678 "./build/y.tab.c"
    break;

  case 59: /* Assign: SHR_ASSIGN Assign  */
#line 228 "./compiler.y"
                           {
		printf("SHR_ASSIGN\n");
		addAssign_j(assign_var, "shr");}
#line 1686 "./build/y.tab.c"
    break;

  case 60: /* Assign: SHL_ASSIGN Assign  */
#line 231 "./compiler.y"
                           {
		printf("SHL_ASSIGN\n");
		addAssign_j(assign_var, "shl");}
#line 1694 "./build/y.tab.c"
    break;

  case 61: /* Assignable: STR_LIT  */
#line 237 "./compiler.y"
                   {
		(yyvsp[-1].object_val).type = OBJECT_TYPE_STR;
		printf("STR_LIT \"%s\"\n", (yyvsp[0].s_var));

		code("ldc \"%s\"", (yyvsp[0].s_var));
	}
#line 1705 "./build/y.tab.c"
    break;

  case 62: /* Assignable: Expression  */
#line 243 "./compiler.y"
                     { nowDealType = (yyvsp[-1].object_val).type; }
#line 1711 "./build/y.tab.c"
    break;

  case 63: /* DefineVariableStmt: VARIABLE_T DeclaratorList ';'  */
#line 248 "./compiler.y"
                                         {typeSet(false);}
#line 1717 "./build/y.tab.c"
    break;

  case 66: /* Declarator: IDENT  */
#line 257 "./compiler.y"
                {
		//普通的變數宣告
		insert((yyvsp[0].s_var), (yyvsp[-1].var_type), 0);

		//創建並添加該變數
		addLocalVar_j((yyvsp[0].s_var), 'n', OBJECT_TYPE_INT);
	}
#line 1729 "./build/y.tab.c"
    break;

  case 67: /* Declarator: IDENT VAL_ASSIGN Assignable  */
#line 264 "./compiler.y"
                                      {
		//普通的變數宣告與賦值
		insertAuto((yyvsp[-2].s_var), (yyvsp[-3].var_type), (yyvsp[-1].var_type), 0);

		//創建並添加該變數
		addLocalVar_j((yyvsp[-2].s_var), 'y', (yyvsp[-1].object_val).type);
	}
#line 1741 "./build/y.tab.c"
    break;

  case 68: /* Declarator: IDENT '[' Expression ']'  */
#line 271 "./compiler.y"
                                   {
		//陣列的變數宣告
		printf("create array: %d\n", 0);
		insert((yyvsp[-3].s_var), (yyvsp[-4].var_type), 0);
	}
#line 1751 "./build/y.tab.c"
    break;

  case 69: /* Declarator: IDENT '[' Expression ']' '[' Expression ']'  */
#line 276 "./compiler.y"
                                                      {
		//二維陣列的變數宣告
		insert((yyvsp[-6].s_var), (yyvsp[-7].var_type), 0);
	}
#line 1760 "./build/y.tab.c"
    break;

  case 70: /* Declarator: IDENT '[' Expression ']' VAL_ASSIGN '{' ArrayEles '}'  */
#line 280 "./compiler.y"
                                                                {
		//一維陣列的變數宣告與賦值
		printf("create array: %d\n", arrayFun('g'));
		arrayFun('r');
		insert((yyvsp[-7].s_var), (yyvsp[-8].var_type), 0);
	}
#line 1771 "./build/y.tab.c"
    break;

  case 71: /* ArrayEles: Assignable  */
#line 289 "./compiler.y"
                     {arrayFun('c');}
#line 1777 "./build/y.tab.c"
    break;

  case 72: /* ArrayEles: ArrayEles ',' Assignable  */
#line 290 "./compiler.y"
                                   {arrayFun('c');}
#line 1783 "./build/y.tab.c"
    break;

  case 74: /* ReturnStmt: RETURN Expression ';'  */
#line 296 "./compiler.y"
                            {
		printf("RETURN\n");
	}
#line 1791 "./build/y.tab.c"
    break;

  case 75: /* ReturnStmt: RETURN ';'  */
#line 299 "./compiler.y"
                 {
		printf("RETURN\n");
	}
#line 1799 "./build/y.tab.c"
    break;

  case 76: /* $@14: %empty  */
#line 306 "./compiler.y"
               {
		addMsg("cout");
	}
#line 1807 "./build/y.tab.c"
    break;

  case 77: /* CoutStmt: COUT $@14 SHL PrintableList ';'  */
#line 308 "./compiler.y"
                                {
		addMsg("\n");
		printMsg();
	}
#line 1816 "./build/y.tab.c"
    break;

  case 80: /* Printable: STR_LIT  */
#line 322 "./compiler.y"
              { 
		addMsg(" string");
		printf("STR_LIT \"%s\"\n", (yyvsp[0].s_var));
		
		addPrint_j((yyvsp[0].s_var));}
#line 1826 "./build/y.tab.c"
    break;

  case 81: /* Printable: ENDL  */
#line 327 "./compiler.y"
           { 
		addMsg(" string");
		printf("IDENT (name=endl, address=-1)\n"); 

		addPrint_j("\n");
	}
#line 1837 "./build/y.tab.c"
    break;

  case 82: /* Printable: Expression  */
#line 333 "./compiler.y"
                     {
		addMsg(" ");
		addMsgObj(&(yyvsp[-1].object_val));

		addPrintExp_j((yyvsp[-1].object_val).type);
	}
#line 1848 "./build/y.tab.c"
    break;

  case 84: /* Expression: STR_LIT  */
#line 347 "./compiler.y"
                  {
		printf("STR_LIT \"%s\"\n", (yyvsp[0].s_var));
		code("ldc \"%s\"", (yyvsp[0].s_var));
	}
#line 1857 "./build/y.tab.c"
    break;

  case 86: /* Or: Or LOR And  */
#line 355 "./compiler.y"
                    {
		// here is correct
		objectExpBoolean('1', &(yyvsp[-2].object_val), &(yyvsp[-1].object_val), &(yyvsp[-3].object_val));
		
		addOpByType_j("or", (yyvsp[-3].object_val).type);
	}
#line 1868 "./build/y.tab.c"
    break;

  case 88: /* And: And LAN BitwiseOr  */
#line 365 "./compiler.y"
                           {
		objectExpBoolean('2', &(yyvsp[-2].object_val), &(yyvsp[-1].object_val), &(yyvsp[-3].object_val));
		
		addOpByType_j("and", (yyvsp[-3].object_val).type);
	}
#line 1878 "./build/y.tab.c"
    break;

  case 90: /* BitwiseOr: BitwiseOr BOR BitwiseXor  */
#line 374 "./compiler.y"
                                  {
		objectExpBinary('1', &(yyvsp[-2].object_val), &(yyvsp[-1].object_val), &(yyvsp[-3].object_val));
		
		addOpByType_j("or", (yyvsp[-3].object_val).type);
	}
#line 1888 "./build/y.tab.c"
    break;

  case 92: /* BitwiseXor: BitwiseXor BXO BitwiseAnd  */
#line 383 "./compiler.y"
                                   {
		objectExpBinary('2', &(yyvsp[-2].object_val), &(yyvsp[-1].object_val), &(yyvsp[-3].object_val));
		
		addOpByType_j("xor", (yyvsp[-3].object_val).type);	
	}
#line 1898 "./build/y.tab.c"
    break;

  case 94: /* BitwiseAnd: BitwiseAnd BAN Equality  */
#line 392 "./compiler.y"
                                 {
		objectExpBinary('3', &(yyvsp[-2].object_val), &(yyvsp[-1].object_val), &(yyvsp[-3].object_val));

		addOpByType_j("and", (yyvsp[-3].object_val).type);	
	}
#line 1908 "./build/y.tab.c"
    break;

  case 96: /* Equality: Equality EQL Relational  */
#line 401 "./compiler.y"
                                 {
		objectExpBoolean('3', &(yyvsp[-2].object_val), &(yyvsp[-1].object_val), &(yyvsp[-3].object_val));
		addOpByType_j("eql", (yyvsp[-3].object_val).type);	
	}
#line 1917 "./build/y.tab.c"
    break;

  case 97: /* Equality: Equality NEQ Relational  */
#line 405 "./compiler.y"
                                 {
		objectExpBoolean('4', &(yyvsp[-2].object_val), &(yyvsp[-1].object_val), &(yyvsp[-3].object_val));
		addOpByType_j("neq", (yyvsp[-3].object_val).type);
	}
#line 1926 "./build/y.tab.c"
    break;

  case 99: /* Relational: Relational LES Shift  */
#line 413 "./compiler.y"
                              {
		printf("LES\n");

		//位元運算
		addOpByType_j("les", (yyvsp[-3].object_val).type);
		(yyvsp[-3].object_val).type = OBJECT_TYPE_BOOL;
	}
#line 1938 "./build/y.tab.c"
    break;

  case 100: /* Relational: Relational GTR Shift  */
#line 420 "./compiler.y"
                              {
		printf("GTR\n");

		//位元運算
		addOpByType_j("gtr", (yyvsp[-3].object_val).type);
		(yyvsp[-3].object_val).type = OBJECT_TYPE_BOOL;
	}
#line 1950 "./build/y.tab.c"
    break;

  case 101: /* Relational: Relational LEQ Shift  */
#line 427 "./compiler.y"
                              {
		printf("LEQ\n");

		//位元運算
		addOpByType_j("leq", (yyvsp[-3].object_val).type);
		(yyvsp[-3].object_val).type = OBJECT_TYPE_BOOL;}
#line 1961 "./build/y.tab.c"
    break;

  case 102: /* Relational: Relational GEQ Shift  */
#line 434 "./compiler.y"
                              {
		printf("GEQ\n");

		//位元運算
		addOpByType_j("geq", (yyvsp[-3].object_val).type);
		(yyvsp[-3].object_val).type = OBJECT_TYPE_BOOL;}
#line 1972 "./build/y.tab.c"
    break;

  case 104: /* Shift: Shift SHR Additive  */
#line 445 "./compiler.y"
                            {
		printf("SHR\n");
		addOpByType_j("shr", (yyvsp[-3].object_val).type);
	}
#line 1981 "./build/y.tab.c"
    break;

  case 106: /* Additive: Additive ADD Multiplicative  */
#line 453 "./compiler.y"
                                     {
		printf("ADD\n");

		//輸出 加法指令
		addOpByType_j("add", (yyvsp[-3].object_val).type);}
#line 1991 "./build/y.tab.c"
    break;

  case 107: /* Additive: Additive SUB Multiplicative  */
#line 459 "./compiler.y"
                                     {
		printf("SUB\n");
		
		//輸出 減法指令
		addOpByType_j("sub", (yyvsp[-3].object_val).type);}
#line 2001 "./build/y.tab.c"
    break;

  case 109: /* Multiplicative: Multiplicative MUL TypeCast  */
#line 469 "./compiler.y"
                                     {
		printf("MUL\n");

		//輸出 乘法指令
		addOpByType_j("mul", (yyvsp[-3].object_val).type);}
#line 2011 "./build/y.tab.c"
    break;

  case 110: /* Multiplicative: Multiplicative DIV TypeCast  */
#line 474 "./compiler.y"
                                     {
		printf("DIV\n");
		
		//輸出 除法指令
		addOpByType_j("div", (yyvsp[-3].object_val).type);}
#line 2021 "./build/y.tab.c"
    break;

  case 111: /* Multiplicative: Multiplicative REM TypeCast  */
#line 479 "./compiler.y"
                                     {
		printf("REM\n");

		//輸出 模數指令
		addOpByType_j("rem", (yyvsp[-3].object_val).type);
	}
#line 2032 "./build/y.tab.c"
    break;

  case 113: /* TypeCast: '(' VARIABLE_T ')' Unary  */
#line 490 "./compiler.y"
                                   {
		(yyvsp[-4].object_val).type = (yyvsp[-2].var_type);
		printCastInfo((yyvsp[-2].var_type));

		addCast_j((yyvsp[-2].var_type));
	}
#line 2043 "./build/y.tab.c"
    break;

  case 114: /* Unary: BNT Unary  */
#line 499 "./compiler.y"
                   {
		(yyvsp[-2].object_val).type = (yyvsp[-1].object_val).type;	//傳遞類別
		printf("BNT\n"); 

		//輸出unary negation指令
		addOpByType_j("not", (yyvsp[-2].object_val).type);
	}
#line 2055 "./build/y.tab.c"
    break;

  case 115: /* Unary: ADD Unary  */
#line 506 "./compiler.y"
                   {
		(yyvsp[-2].object_val).type = (yyvsp[-1].object_val).type;	//傳遞類別
		printf("ADD\n");}
#line 2063 "./build/y.tab.c"
    break;

  case 116: /* Unary: SUB Unary  */
#line 509 "./compiler.y"
                   {
		(yyvsp[-2].object_val).type = (yyvsp[-1].object_val).type;	//傳遞類別
		printf("NEG\n");	//輸出資訊

		//輸出unary negation指令
		addOpByType_j("neg", (yyvsp[-2].object_val).type);
	}
#line 2075 "./build/y.tab.c"
    break;

  case 117: /* Unary: NOT Unary  */
#line 516 "./compiler.y"
                   {
		(yyvsp[-2].object_val).type = (yyvsp[-1].object_val).type;	//傳遞類別
		printf("NOT\n");
		
		addOpByType_j("not", (yyvsp[-2].object_val).type);}
#line 2085 "./build/y.tab.c"
    break;

  case 120: /* Post: Primary INC_ASSIGN  */
#line 526 "./compiler.y"
                             {
		printf("INC_ASSIGN\n");

		//設值操作
		addAssign_j(assign_var, "inc");

		//將變數設值
		addLocalVar_j((yyvsp[-1].s_var), 'y', (yyvsp[-2].object_val).type);
	}
#line 2099 "./build/y.tab.c"
    break;

  case 121: /* Post: Primary DEC_ASSIGN  */
#line 535 "./compiler.y"
                             {
		printf("DEC_ASSIGN\n");
		
		//addOpByType_j("dec", $<object_val>0.type);
		addAssign_j(assign_var, "dec");

		//將變數設值
		addLocalVar_j((yyvsp[-1].s_var), 'y', (yyvsp[-2].object_val).type);
	}
#line 2113 "./build/y.tab.c"
    break;

  case 122: /* Primary: INT_LIT  */
#line 547 "./compiler.y"
             {
			(yyvsp[-1].object_val).type = OBJECT_TYPE_INT;
			printf("INT_LIT %d\n", (yyvsp[0].i_var));

			//輸出 載入整數到stack頂端
			code("ldc %d", (yyvsp[0].i_var));
		}
#line 2125 "./build/y.tab.c"
    break;

  case 123: /* Primary: FLOAT_LIT  */
#line 554 "./compiler.y"
                    {
			(yyvsp[-1].object_val).type = OBJECT_TYPE_FLOAT;
			printf("FLOAT_LIT %f\n", (yyvsp[0].f_var));

			//輸出 載入整數到stack頂端
			code("ldc %f", (yyvsp[0].f_var));
		}
#line 2137 "./build/y.tab.c"
    break;

  case 124: /* Primary: '(' Expression ')'  */
#line 561 "./compiler.y"
                         {
			(yyvsp[-3].object_val).type = (yyvsp[-2].object_val).type;
		}
#line 2145 "./build/y.tab.c"
    break;

  case 125: /* Primary: BOOL_LIT  */
#line 564 "./compiler.y"
                   {
			(yyvsp[-1].object_val).type = OBJECT_TYPE_BOOL; 
			printBool((yyvsp[0].b_var));

			//輸出 載入整數到stack頂端
			code("ldc %d", (yyvsp[0].b_var));
		}
#line 2157 "./build/y.tab.c"
    break;

  case 126: /* Primary: IDENT  */
#line 571 "./compiler.y"
                {
		//詞性修飾
		ObjectType type = getVarTypeByName((yyvsp[0].s_var));
		(yyvsp[-1].object_val).type = type;

		//輸出資訊
		printIDByName((yyvsp[0].s_var), 'v');

		//輸出 載入該變數到stack頂端
		addPushLocalVar_j((yyvsp[0].s_var));
		assign_var = (yyvsp[0].s_var);	//設置當前修改的變數名稱
	}
#line 2174 "./build/y.tab.c"
    break;

  case 128: /* Primary: IDENT '[' Expression ']'  */
#line 584 "./compiler.y"
                                   {
			ObjectType type = getVarTypeByName((yyvsp[-3].s_var));
			(yyvsp[-4].object_val).type = type;
			printIDByName((yyvsp[-3].s_var), 'v');
	}
#line 2184 "./build/y.tab.c"
    break;

  case 129: /* Primary: IDENT '[' Expression ']' '[' Expression ']'  */
#line 589 "./compiler.y"
                                                      {
		ObjectType type = getVarTypeByName((yyvsp[-6].s_var));
		(yyvsp[-7].object_val).type = type;
		printIDByName((yyvsp[-6].s_var), 'v');
	}
#line 2194 "./build/y.tab.c"
    break;

  case 130: /* FunctionCall: IDENT '(' ArgumentList ')'  */
#line 599 "./compiler.y"
                                     {
		(yyvsp[-4].object_val).type = getFuncType((yyvsp[-3].s_var));
		printIDByName((yyvsp[-3].s_var), 'f');
		printf("call: %s", (yyvsp[-3].s_var));
		printSigByName((yyvsp[-3].s_var));
		printf("\n");

		codeRaw("invokestatic Main/check(IILjava/lang/String;B)B");
	}
#line 2208 "./build/y.tab.c"
    break;

  case 134: /* $@15: %empty  */
#line 622 "./compiler.y"
                       {
		createFunction((yyvsp[-1].var_type), (yyvsp[0].s_var));
		addFunDef_j((yyvsp[0].s_var), 'n');
	}
#line 2217 "./build/y.tab.c"
    break;

  case 135: /* $@16: %empty  */
#line 625 "./compiler.y"
              {
		pushScope();
	}
#line 2225 "./build/y.tab.c"
    break;

  case 136: /* $@17: %empty  */
#line 627 "./compiler.y"
                                        {
		setFuncSig((yyvsp[-5].s_var), (yyvsp[-6].var_type));
		addFunDef_j((yyvsp[-5].s_var), 's');		//傳入函數名稱，在main.j中建立函數
	}
#line 2234 "./build/y.tab.c"
    break;

  case 137: /* FunctionDefStmt: VARIABLE_T IDENT $@15 '(' $@16 FunctionParameterStmtList ')' $@17 '{' GlobalStmtList '}'  */
#line 630 "./compiler.y"
                                 {
		addRet_j((yyvsp[-9].s_var));	//添加函數回傳
		dumpScope();
		addFunEnd_j();	//添加函數結尾
	}
#line 2244 "./build/y.tab.c"
    break;

  case 141: /* FunctionParameterStmt: VARIABLE_T IDENT  */
#line 643 "./compiler.y"
                       { insert((yyvsp[0].s_var), (yyvsp[-1].var_type), 3); }
#line 2250 "./build/y.tab.c"
    break;

  case 142: /* $@18: %empty  */
#line 644 "./compiler.y"
                       { insert((yyvsp[0].s_var), (yyvsp[-1].var_type), 4); }
#line 2256 "./build/y.tab.c"
    break;


#line 2260 "./build/y.tab.c"

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

#line 646 "./compiler.y"

/* C code section */
