/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_BUILD_Y_TAB_H_INCLUDED
# define YY_YY_BUILD_Y_TAB_H_INCLUDED
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
    COUT = 258,                    /* COUT  */
    SHR = 259,                     /* SHR  */
    SHL = 260,                     /* SHL  */
    BAN = 261,                     /* BAN  */
    BOR = 262,                     /* BOR  */
    BXO = 263,                     /* BXO  */
    MUL = 264,                     /* MUL  */
    DIV = 265,                     /* DIV  */
    REM = 266,                     /* REM  */
    GTR = 267,                     /* GTR  */
    LES = 268,                     /* LES  */
    GEQ = 269,                     /* GEQ  */
    LEQ = 270,                     /* LEQ  */
    EQL = 271,                     /* EQL  */
    NEQ = 272,                     /* NEQ  */
    LAN = 273,                     /* LAN  */
    LOR = 274,                     /* LOR  */
    VAL_ASSIGN = 275,              /* VAL_ASSIGN  */
    ADD_ASSIGN = 276,              /* ADD_ASSIGN  */
    SUB_ASSIGN = 277,              /* SUB_ASSIGN  */
    MUL_ASSIGN = 278,              /* MUL_ASSIGN  */
    DIV_ASSIGN = 279,              /* DIV_ASSIGN  */
    REM_ASSIGN = 280,              /* REM_ASSIGN  */
    BAN_ASSIGN = 281,              /* BAN_ASSIGN  */
    BOR_ASSIGN = 282,              /* BOR_ASSIGN  */
    BXO_ASSIGN = 283,              /* BXO_ASSIGN  */
    SHR_ASSIGN = 284,              /* SHR_ASSIGN  */
    SHL_ASSIGN = 285,              /* SHL_ASSIGN  */
    INC_ASSIGN = 286,              /* INC_ASSIGN  */
    DEC_ASSIGN = 287,              /* DEC_ASSIGN  */
    IF = 288,                      /* IF  */
    ELSE = 289,                    /* ELSE  */
    FOR = 290,                     /* FOR  */
    WHILE = 291,                   /* WHILE  */
    RETURN = 292,                  /* RETURN  */
    BREAK = 293,                   /* BREAK  */
    CONTINUE = 294,                /* CONTINUE  */
    ENDL = 295,                    /* ENDL  */
    VARIABLE_T = 296,              /* VARIABLE_T  */
    IDENT = 297,                   /* IDENT  */
    BOOL_LIT = 298,                /* BOOL_LIT  */
    INT_LIT = 299,                 /* INT_LIT  */
    FLOAT_LIT = 300,               /* FLOAT_LIT  */
    STR_LIT = 301,                 /* STR_LIT  */
    SUB = 302,                     /* SUB  */
    NOT = 303,                     /* NOT  */
    BNT = 304,                     /* BNT  */
    ADD = 305                      /* ADD  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define COUT 258
#define SHR 259
#define SHL 260
#define BAN 261
#define BOR 262
#define BXO 263
#define MUL 264
#define DIV 265
#define REM 266
#define GTR 267
#define LES 268
#define GEQ 269
#define LEQ 270
#define EQL 271
#define NEQ 272
#define LAN 273
#define LOR 274
#define VAL_ASSIGN 275
#define ADD_ASSIGN 276
#define SUB_ASSIGN 277
#define MUL_ASSIGN 278
#define DIV_ASSIGN 279
#define REM_ASSIGN 280
#define BAN_ASSIGN 281
#define BOR_ASSIGN 282
#define BXO_ASSIGN 283
#define SHR_ASSIGN 284
#define SHL_ASSIGN 285
#define INC_ASSIGN 286
#define DEC_ASSIGN 287
#define IF 288
#define ELSE 289
#define FOR 290
#define WHILE 291
#define RETURN 292
#define BREAK 293
#define CONTINUE 294
#define ENDL 295
#define VARIABLE_T 296
#define IDENT 297
#define BOOL_LIT 298
#define INT_LIT 299
#define FLOAT_LIT 300
#define STR_LIT 301
#define SUB 302
#define NOT 303
#define BNT 304
#define ADD 305

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 22 "./compiler.y"

    ObjectType var_type;
    bool b_var;
    int i_var;
    float f_var;
    char *s_var;

    Object object_val;

#line 177 "./build/y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_BUILD_Y_TAB_H_INCLUDED  */
