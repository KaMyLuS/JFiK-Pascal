/* A Bison parser, made by GNU Bison 2.7.  */

/* Skeleton implementation for Bison LALR(1) parsers in C++
   
      Copyright (C) 2002-2012 Free Software Foundation, Inc.
   
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


/* First part of user declarations.  */

/* Line 279 of lalr1.cc  */
#line 38 "pascal_parser.tab.cc"


#include "pascal_parser.tab.hh"

/* User implementation prologue.  */

/* Line 285 of lalr1.cc  */
#line 46 "pascal_parser.tab.cc"
/* Unqualified %code blocks.  */
/* Line 286 of lalr1.cc  */
#line 21 "pascal_parser.yy"

   #include <iostream>
   #include <cstdlib>
   #include <fstream>
   
   /* include for all driver functions */
   #include "Pascal_driver.hpp"
  
   /* this is silly, but I can't figure out a way around */
   static int yylex(Pascal::Pascal_Parser::semantic_type *yylval,
                    Pascal::Pascal_Scanner  &scanner,
                    Pascal::Pascal_Driver   &driver);
   


/* Line 286 of lalr1.cc  */
#line 66 "pascal_parser.tab.cc"


# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
#  endif
# endif

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* FIXME: INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (/*CONSTCOND*/ false)
# endif


/* Suppress unused-variable warnings by "using" E.  */
#define YYUSE(e) ((void) (e))

/* Enable debugging if requested.  */
#if YYDEBUG

/* A pseudo ostream that takes yydebug_ into account.  */
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)	\
do {							\
  if (yydebug_)						\
    {							\
      *yycdebug_ << Title << ' ';			\
      yy_symbol_print_ ((Type), (Value), (Location));	\
      *yycdebug_ << std::endl;				\
    }							\
} while (false)

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug_)				\
    yy_reduce_print_ (Rule);		\
} while (false)

# define YY_STACK_PRINT()		\
do {					\
  if (yydebug_)				\
    yystack_print_ ();			\
} while (false)

#else /* !YYDEBUG */

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Type, Value, Location) YYUSE(Type)
# define YY_REDUCE_PRINT(Rule)        static_cast<void>(0)
# define YY_STACK_PRINT()             static_cast<void>(0)

#endif /* !YYDEBUG */

#define yyerrok		(yyerrstatus_ = 0)
#define yyclearin	(yychar = yyempty_)

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

/* Line 353 of lalr1.cc  */
#line 5 "pascal_parser.yy"
namespace Pascal {
/* Line 353 of lalr1.cc  */
#line 162 "pascal_parser.tab.cc"

  /// Build a parser object.
  Pascal_Parser::Pascal_Parser (Pascal_Scanner  &scanner_yyarg, Pascal_Driver  &driver_yyarg)
    :
#if YYDEBUG
      yydebug_ (false),
      yycdebug_ (&std::cerr),
#endif
      scanner (scanner_yyarg),
      driver (driver_yyarg)
  {
  }

  Pascal_Parser::~Pascal_Parser ()
  {
  }

#if YYDEBUG
  /*--------------------------------.
  | Print this symbol on YYOUTPUT.  |
  `--------------------------------*/

  inline void
  Pascal_Parser::yy_symbol_value_print_ (int yytype,
			   const semantic_type* yyvaluep, const location_type* yylocationp)
  {
    YYUSE (yylocationp);
    YYUSE (yyvaluep);
    std::ostream& yyo = debug_stream ();
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    switch (yytype)
      {
         default:
	  break;
      }
  }


  void
  Pascal_Parser::yy_symbol_print_ (int yytype,
			   const semantic_type* yyvaluep, const location_type* yylocationp)
  {
    *yycdebug_ << (yytype < yyntokens_ ? "token" : "nterm")
	       << ' ' << yytname_[yytype] << " ("
	       << *yylocationp << ": ";
    yy_symbol_value_print_ (yytype, yyvaluep, yylocationp);
    *yycdebug_ << ')';
  }
#endif

  void
  Pascal_Parser::yydestruct_ (const char* yymsg,
			   int yytype, semantic_type* yyvaluep, location_type* yylocationp)
  {
    YYUSE (yylocationp);
    YYUSE (yymsg);
    YYUSE (yyvaluep);

    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

    switch (yytype)
      {
  
	default:
	  break;
      }
  }

  void
  Pascal_Parser::yypop_ (unsigned int n)
  {
    yystate_stack_.pop (n);
    yysemantic_stack_.pop (n);
    yylocation_stack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  Pascal_Parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  Pascal_Parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  Pascal_Parser::debug_level_type
  Pascal_Parser::debug_level () const
  {
    return yydebug_;
  }

  void
  Pascal_Parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif

  inline bool
  Pascal_Parser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  inline bool
  Pascal_Parser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  Pascal_Parser::parse ()
  {
    /// Lookahead and lookahead in internal form.
    int yychar = yyempty_;
    int yytoken = 0;

    // State.
    int yyn;
    int yylen = 0;
    int yystate = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// Semantic value of the lookahead.
    static semantic_type yyval_default;
    semantic_type yylval = yyval_default;
    /// Location of the lookahead.
    location_type yylloc;
    /// The locations where the error started and ended.
    location_type yyerror_range[3];

    /// $$.
    semantic_type yyval;
    /// @$.
    location_type yyloc;

    int yyresult;

    // FIXME: This shoud be completely indented.  It is not yet to
    // avoid gratuitous conflicts when merging into the master branch.
    try
      {
    YYCDEBUG << "Starting parse" << std::endl;


    /* Initialize the stacks.  The initial state will be pushed in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystate_stack_ = state_stack_type (0);
    yysemantic_stack_ = semantic_stack_type (0);
    yylocation_stack_ = location_stack_type (0);
    yysemantic_stack_.push (yylval);
    yylocation_stack_.push (yylloc);

    /* New state.  */
  yynewstate:
    yystate_stack_.push (yystate);
    YYCDEBUG << "Entering state " << yystate << std::endl;

    /* Accept?  */
    if (yystate == yyfinal_)
      goto yyacceptlab;

    goto yybackup;

    /* Backup.  */
  yybackup:

    /* Try to take a decision without lookahead.  */
    yyn = yypact_[yystate];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    /* Read a lookahead token.  */
    if (yychar == yyempty_)
      {
        YYCDEBUG << "Reading a token: ";
        yychar = yylex (&yylval, scanner, driver);
      }

    /* Convert token to internal form.  */
    if (yychar <= yyeof_)
      {
	yychar = yytoken = yyeof_;
	YYCDEBUG << "Now at end of input." << std::endl;
      }
    else
      {
	yytoken = yytranslate_ (yychar);
	YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
      }

    /* If the proper action on seeing token YYTOKEN is to reduce or to
       detect an error, take that action.  */
    yyn += yytoken;
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yytoken)
      goto yydefault;

    /* Reduce or error.  */
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
	if (yy_table_value_is_error_ (yyn))
	  goto yyerrlab;
	yyn = -yyn;
	goto yyreduce;
      }

    /* Shift the lookahead token.  */
    YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

    /* Discard the token being shifted.  */
    yychar = yyempty_;

    yysemantic_stack_.push (yylval);
    yylocation_stack_.push (yylloc);

    /* Count tokens shifted since error; after three, turn off error
       status.  */
    if (yyerrstatus_)
      --yyerrstatus_;

    yystate = yyn;
    goto yynewstate;

  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[yystate];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;

  /*-----------------------------.
  | yyreduce -- Do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    /* If YYLEN is nonzero, implement the default value of the action:
       `$$ = $1'.  Otherwise, use the top of the stack.

       Otherwise, the following line sets YYVAL to garbage.
       This behavior is undocumented and Bison
       users should not rely upon it.  */
    if (yylen)
      yyval = yysemantic_stack_[yylen - 1];
    else
      yyval = yysemantic_stack_[0];

    // Compute the default @$.
    {
      slice<location_type, location_stack_type> slice (yylocation_stack_, yylen);
      YYLLOC_DEFAULT (yyloc, slice, yylen);
    }

    // Perform the reduction.
    YY_REDUCE_PRINT (yyn);
    switch (yyn)
      {
        
/* Line 670 of lalr1.cc  */
#line 436 "pascal_parser.tab.cc"
      default:
        break;
      }

    /* User semantic actions sometimes alter yychar, and that requires
       that yytoken be updated with the new translation.  We take the
       approach of translating immediately before every use of yytoken.
       One alternative is translating here after every semantic action,
       but that translation would be missed if the semantic action
       invokes YYABORT, YYACCEPT, or YYERROR immediately after altering
       yychar.  In the case of YYABORT or YYACCEPT, an incorrect
       destructor might then be invoked immediately.  In the case of
       YYERROR, subsequent parser actions might lead to an incorrect
       destructor call or verbose syntax error message before the
       lookahead is translated.  */
    YY_SYMBOL_PRINT ("-> $$ =", yyr1_[yyn], &yyval, &yyloc);

    yypop_ (yylen);
    yylen = 0;
    YY_STACK_PRINT ();

    yysemantic_stack_.push (yyval);
    yylocation_stack_.push (yyloc);

    /* Shift the result of the reduction.  */
    yyn = yyr1_[yyn];
    yystate = yypgoto_[yyn - yyntokens_] + yystate_stack_[0];
    if (0 <= yystate && yystate <= yylast_
	&& yycheck_[yystate] == yystate_stack_[0])
      yystate = yytable_[yystate];
    else
      yystate = yydefgoto_[yyn - yyntokens_];
    goto yynewstate;

  /*------------------------------------.
  | yyerrlab -- here on detecting error |
  `------------------------------------*/
  yyerrlab:
    /* Make sure we have latest lookahead translation.  See comments at
       user semantic actions for why this is necessary.  */
    yytoken = yytranslate_ (yychar);

    /* If not already recovering from an error, report this error.  */
    if (!yyerrstatus_)
      {
	++yynerrs_;
	if (yychar == yyempty_)
	  yytoken = yyempty_;
	error (yylloc, yysyntax_error_ (yystate, yytoken));
      }

    yyerror_range[1] = yylloc;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */
        if (yychar <= yyeof_)
          {
            /* Return failure if at end of input.  */
            if (yychar == yyeof_)
              YYABORT;
          }
        else
          {
            yydestruct_ ("Error: discarding", yytoken, &yylval, &yylloc);
            yychar = yyempty_;
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
    if (false)
      goto yyerrorlab;

    yyerror_range[1] = yylocation_stack_[yylen - 1];
    /* Do not reclaim the symbols of the rule which action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    yystate = yystate_stack_[0];
    goto yyerrlab1;

  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;	/* Each real token shifted decrements this.  */

    for (;;)
      {
	yyn = yypact_[yystate];
	if (!yy_pact_value_is_default_ (yyn))
	{
	  yyn += yyterror_;
	  if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yyterror_)
	    {
	      yyn = yytable_[yyn];
	      if (0 < yyn)
		break;
	    }
	}

	/* Pop the current state because it cannot handle the error token.  */
	if (yystate_stack_.height () == 1)
	  YYABORT;

	yyerror_range[1] = yylocation_stack_[0];
	yydestruct_ ("Error: popping",
		     yystos_[yystate],
		     &yysemantic_stack_[0], &yylocation_stack_[0]);
	yypop_ ();
	yystate = yystate_stack_[0];
	YY_STACK_PRINT ();
      }

    yyerror_range[2] = yylloc;
    // Using YYLLOC is tempting, but would change the location of
    // the lookahead.  YYLOC is available though.
    YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
    yysemantic_stack_.push (yylval);
    yylocation_stack_.push (yyloc);

    /* Shift the error token.  */
    YY_SYMBOL_PRINT ("Shifting", yystos_[yyn],
		     &yysemantic_stack_[0], &yylocation_stack_[0]);

    yystate = yyn;
    goto yynewstate;

    /* Accept.  */
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;

    /* Abort.  */
  yyabortlab:
    yyresult = 1;
    goto yyreturn;

  yyreturn:
    if (yychar != yyempty_)
      {
        /* Make sure we have latest lookahead translation.  See comments
           at user semantic actions for why this is necessary.  */
        yytoken = yytranslate_ (yychar);
        yydestruct_ ("Cleanup: discarding lookahead", yytoken, &yylval,
                     &yylloc);
      }

    /* Do not reclaim the symbols of the rule which action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (1 < yystate_stack_.height ())
      {
        yydestruct_ ("Cleanup: popping",
                     yystos_[yystate_stack_[0]],
                     &yysemantic_stack_[0],
                     &yylocation_stack_[0]);
        yypop_ ();
      }

    return yyresult;
    }
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack"
                 << std::endl;
        // Do not try to display the values of the reclaimed symbols,
        // as their printer might throw an exception.
        if (yychar != yyempty_)
          {
            /* Make sure we have latest lookahead translation.  See
               comments at user semantic actions for why this is
               necessary.  */
            yytoken = yytranslate_ (yychar);
            yydestruct_ (YY_NULL, yytoken, &yylval, &yylloc);
          }

        while (1 < yystate_stack_.height ())
          {
            yydestruct_ (YY_NULL,
                         yystos_[yystate_stack_[0]],
                         &yysemantic_stack_[0],
                         &yylocation_stack_[0]);
            yypop_ ();
          }
        throw;
      }
  }

  // Generate an error message.
  std::string
  Pascal_Parser::yysyntax_error_ (int, int)
  {
    return YY_("syntax error");
  }


  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
  const short int Pascal_Parser::yypact_ninf_ = -148;
  const short int
  Pascal_Parser::yypact_[] =
  {
        24,     0,    41,    26,  -148,  -148,  -148,    43,     0,    34,
      76,     0,  -148,    69,   107,     0,    82,  -148,    56,  -148,
     -17,    74,  -148,  -148,     0,     0,   104,    81,  -148,  -148,
      98,    67,  -148,   102,   103,  -148,  -148,  -148,  -148,  -148,
     106,    64,  -148,  -148,     0,    87,     0,  -148,   -18,   125,
    -148,  -148,    82,    43,    17,  -148,    43,    43,  -148,  -148,
    -148,  -148,  -148,  -148,  -148,  -148,  -148,    94,   108,     0,
      52,    52,  -148,     4,  -148,  -148,  -148,  -148,  -148,  -148,
    -148,  -148,  -148,  -148,  -148,  -148,   111,  -148,   -19,  -148,
    -148,  -148,     0,     0,    19,  -148,   -22,  -148,  -148,  -148,
    -148,  -148,  -148,  -148,  -148,  -148,  -148,  -148,  -148,  -148,
    -148,    94,   114,  -148,  -148,  -148,  -148,    52,    14,    52,
    -148,   135,  -148,    86,    33,  -148,  -148,   105,  -148,  -148,
    -148,  -148,  -148,    99,   138,  -148,   125,    52,    52,  -148,
     -18,    31,     0,    17,  -148,  -148,    52,   109,  -148,  -148,
     125,  -148,  -148,  -148,  -148,  -148,  -148,  -148,  -148,  -148,
      52,    52,  -148,  -148,  -148,  -148,  -148,    52,    14,  -148,
     125,  -148,  -148,    -8,  -148,   117,     0,  -148,  -148,    79,
    -148,  -148,  -148,  -148,    33,     3,  -148,  -148,  -148,   139,
    -148,  -148,    52,    52,  -148,  -148,  -148,    52,   125,  -148,
     119,   144,  -148,  -148,  -148,    52,   125,  -148,  -148,  -148
  };

  /* YYDEFACT[S] -- default reduction number in state S.  Performed when
     YYTABLE doesn't specify something else to do.  Zero means the
     default is an error.  */
  const unsigned char
  Pascal_Parser::yydefact_[] =
  {
         0,     0,     0,     0,   138,     3,     1,     8,     0,     0,
      25,     7,    10,     0,     0,     0,    30,     9,     0,     2,
       0,     0,    27,     5,     0,     0,     0,     0,    32,    33,
       0,    36,    34,     0,     0,    17,    19,    14,    15,    16,
       0,     0,    12,    18,     0,     0,    24,    49,    59,    75,
       6,    61,    29,     8,     0,    37,     8,     8,    11,    13,
       4,    21,    20,    22,    23,    28,    26,     0,     0,     0,
       0,     0,    71,     0,    64,    65,    66,    68,    67,    77,
      73,    78,    74,    76,    72,    69,     0,    70,    89,    31,
      50,    35,     0,     0,     0,    47,     0,    40,    41,    42,
      43,    44,    48,    60,    52,    51,    55,    56,    57,    58,
      53,     0,     0,    96,   121,   122,   118,     0,     0,     0,
     112,     0,   101,   102,   104,   106,   109,   110,   113,   117,
     119,   120,   114,    87,     0,    62,    75,     0,     0,    88,
       0,     0,     0,     0,    38,    54,     0,     0,   116,   108,
      75,   132,   133,   135,   137,   134,   136,   124,   125,   126,
       0,     0,   128,   127,   129,   130,   131,     0,     0,   123,
      75,    63,    86,     0,    92,    93,     0,    45,    39,     0,
      97,   115,    79,    80,   105,   103,   107,   111,    83,    66,
     139,    90,     0,     0,    46,    98,    99,     0,    75,    91,
      94,     0,   100,    84,    85,     0,    75,    95,    81,    82
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  Pascal_Parser::yypgoto_[] =
  {
      -148,  -148,  -148,   -49,     8,  -148,  -148,   146,  -148,   142,
     120,  -148,  -148,  -148,   116,  -148,  -148,   112,  -148,   -50,
     132,  -148,    22,  -148,  -148,  -148,  -148,  -148,  -148,  -148,
     -46,    55,  -148,   110,  -148,   145,  -148,  -134,  -147,  -144,
    -148,  -148,  -148,  -148,  -148,  -148,  -148,  -148,  -148,   -48,
    -148,    35,  -148,   -20,  -148,  -148,  -148,  -148,   113,   -88,
       9,    13,  -110,     6,    58,  -148,  -148,  -148,  -148,  -148,
    -148,  -148,  -148,    -1,  -148
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  Pascal_Parser::yydefgoto_[] =
  {
        -1,     2,     3,    20,   103,    10,    11,    12,    40,   119,
      42,    65,    16,    21,    22,    26,    27,    28,    29,    30,
      68,    96,    97,    98,    99,   100,   101,    31,    91,    32,
      33,   110,    34,   104,    50,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,   120,
      87,   139,   173,   174,   112,   179,   197,   201,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     160,   167,   161,   133,   192
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If YYTABLE_NINF_, syntax error.  */
  const signed char Pascal_Parser::yytable_ninf_ = -88;
  const short int
  Pascal_Parser::yytable_[] =
  {
         5,    86,   171,   182,    95,    94,   183,    13,   102,   149,
      13,   135,   143,   -87,    23,     9,    44,    43,    67,    45,
       4,    24,    92,    47,    48,   190,   189,     1,   144,   147,
     138,    54,   114,   115,     4,   116,   188,     4,   136,    93,
      43,     6,   191,    60,   141,    23,   157,   158,    88,   172,
     175,   203,    44,    23,   204,   142,   159,   186,   180,   208,
       7,    90,   209,   117,    44,   118,     8,   176,   113,    14,
     114,   115,     4,   116,    35,    36,     4,    37,   162,   163,
     164,   165,    35,    36,     4,   166,    24,    25,    86,   195,
     196,   140,    23,    95,    94,    38,    39,   102,    15,    38,
      39,   117,    86,   118,   175,   200,    18,    19,    46,   202,
      49,    61,    62,    63,    64,    52,    54,   207,   106,   107,
     108,   109,    86,   151,   152,   153,   154,   155,   156,   157,
     158,    49,    53,    69,    70,    88,    56,    57,    71,   159,
      58,   177,    23,   137,   111,     4,   146,   150,   138,    88,
      86,   168,   170,   193,   198,   205,   206,    17,    86,   181,
      41,    59,    66,    55,    89,   178,   145,   105,   169,    88,
     185,    51,   199,   184,   187,   194,   148,     0,     0,     0,
       0,     0,     0,     0,   134,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    88,     0,     0,
       0,     0,     0,     0,     0,    88
  };

  /* YYCHECK.  */
  const short int
  Pascal_Parser::yycheck_[] =
  {
         1,    49,   136,   150,    54,    54,   150,     8,    54,   119,
      11,     7,    34,    32,    15,     7,    33,    18,    36,    36,
      20,     4,     5,    24,    25,    33,   170,     3,    50,   117,
      49,    49,    18,    19,    20,    21,   170,    20,    34,    22,
      41,     0,    50,    44,    93,    46,    43,    44,    49,   137,
     138,   198,    33,    54,   198,    36,    53,   167,   146,   206,
      34,    53,   206,    49,    33,    51,    23,    36,    69,    35,
      18,    19,    20,    21,    18,    19,    20,    21,    45,    46,
      47,    48,    18,    19,    20,    52,     4,     5,   136,    10,
      11,    92,    93,   143,   143,    43,    44,   143,    22,    43,
      44,    49,   150,    51,   192,   193,    37,     0,    34,   197,
       6,    24,    25,    26,    27,    34,    49,   205,    24,    25,
      26,    27,   170,    37,    38,    39,    40,    41,    42,    43,
      44,     6,    34,     8,     9,   136,    34,    34,    13,    53,
      34,   142,   143,    32,    36,    20,    32,    12,    49,   150,
     198,    46,    14,    36,    15,    36,    12,    11,   206,    50,
      18,    41,    46,    31,    52,   143,   111,    57,   133,   170,
     161,    26,   192,   160,   168,   176,   118,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    71,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   198,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   206
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned char
  Pascal_Parser::yystos_[] =
  {
         0,     3,    56,    57,    20,   128,     0,    34,    23,    59,
      60,    61,    62,   128,    35,    22,    67,    62,    37,     0,
      58,    68,    69,   128,     4,     5,    70,    71,    72,    73,
      74,    82,    84,    85,    87,    18,    19,    21,    43,    44,
      63,    64,    65,   128,    33,    36,    34,   128,   128,     6,
      89,    90,    34,    34,    49,    75,    34,    34,    34,    65,
     128,    24,    25,    26,    27,    66,    69,    36,    75,     8,
       9,    13,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   128,    72,
      59,    83,     5,    22,    58,    74,    76,    77,    78,    79,
      80,    81,    85,    59,    88,    88,    24,    25,    26,    27,
      86,    36,   109,   128,    18,    19,    21,    49,    51,    64,
     104,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   128,   113,     7,    34,    32,    49,   106,
     128,    58,    36,    34,    50,    86,    32,   114,   119,   117,
      12,    37,    38,    39,    40,    41,    42,    43,    44,    53,
     125,   127,    45,    46,    47,    48,    52,   126,    46,   106,
      14,    92,   114,   107,   108,   114,    36,   128,    77,   110,
     114,    50,    93,    94,   116,   115,   117,   118,    92,    94,
      33,    50,   129,    36,   128,    10,    11,   111,    15,   108,
     114,   112,   114,    93,    94,    36,    12,   114,    93,    94
  };

#if YYDEBUG
  /* TOKEN_NUMBER_[YYLEX-NUM] -- Internal symbol number corresponding
     to YYLEX-NUM.  */
  const unsigned short int
  Pascal_Parser::yytoken_number_[] =
  {
         0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned char
  Pascal_Parser::yyr1_[] =
  {
         0,    55,    56,    57,    58,    58,    59,    60,    60,    61,
      61,    62,    63,    63,    63,    64,    64,    65,    65,    65,
      66,    66,    66,    66,    67,    67,    68,    68,    69,    70,
      70,    71,    71,    72,    72,    73,    74,    74,    75,    76,
      76,    77,    77,    77,    77,    78,    79,    80,    81,    82,
      83,    84,    84,    85,    85,    86,    86,    86,    86,    87,
      88,    89,    90,    91,    91,    92,    92,    93,    94,    95,
      95,    95,    95,    95,    95,    95,    96,    96,    96,    97,
      98,    99,   100,   101,   101,   102,   103,   104,   105,   105,
     106,   107,   107,   108,   108,   108,   109,   110,   111,   111,
     112,   113,   114,   114,   115,   115,   116,   116,   117,   117,
     118,   118,   119,   119,   119,   119,   119,   120,   120,   121,
     121,   122,   123,   124,   125,   125,   125,   126,   126,   126,
     126,   126,   127,   127,   127,   127,   127,   127,   128,   129
  };

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
  const unsigned char
  Pascal_Parser::yyr2_[] =
  {
         0,     2,     5,     2,     3,     1,     4,     2,     0,     2,
       1,     4,     1,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     0,     3,     1,     3,     2,
       0,     3,     1,     1,     1,     3,     1,     2,     3,     3,
       1,     1,     1,     1,     1,     3,     4,     1,     1,     2,
       1,     3,     3,     4,     5,     1,     1,     1,     1,     2,
       1,     1,     3,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     0,     1,     1,     1,     4,
       4,     8,     8,     4,     6,     6,     3,     1,     2,     1,
       3,     3,     1,     1,     3,     5,     1,     1,     1,     1,
       1,     1,     1,     3,     1,     3,     1,     3,     2,     1,
       1,     3,     1,     1,     1,     3,     2,     1,     1,     1,
       1,     1,     1,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1
  };

#if YYDEBUG
  /* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
     First, the terminals, then, starting at \a yyntokens_, nonterminals.  */
  const char*
  const Pascal_Parser::yytname_[] =
  {
    "\"end of file\"", "error", "$undefined", "PROGRAM_P", "PROCED_P",
  "FUNCTION_P", "BEGIN_P", "END_P", "FOR_P", "WHILE_P", "TO_P", "DOWNTO_P",
  "DO_P", "IF_P", "THEN_P", "ELSE_P", "REPEAT_P", "UNTIL_P", "NUMBER",
  "REAL_NR", "IDENT", "STRING", "VAR_P", "CONST_P", "INT_P", "REAL_P",
  "STRING_P", "BOOL_P", "TRUE_P", "FALSE_P", "ARRAY_P", "OF_P", "BIND",
  "COMMA", "SCOLON", "DOT", "COLON", "EQUAL", "NOTEQ", "GT", "GE", "LT",
  "LE", "PLUS", "MINUS", "SLASH", "STAR", "DIV_P", "MOD_P", "LPAREN",
  "RPAREN", "NOT_P", "AND_P", "OR_P", "WRONG", "$accept", "program",
  "program_heading", "identifier_list", "block",
  "constant_definition_part", "constant_list", "constant_definition",
  "constant", "sign", "non_string", "type_denoter",
  "variable_declaration_part", "variable_declaration_list",
  "variable_declaration", "procedure_and_function_declaration_part",
  "proc_or_func_declaration_list", "proc_or_func_declaration",
  "procedure_declaration", "procedure_heading", "formal_parameter_list",
  "formal_parameter_section_list", "formal_parameter_section",
  "value_parameter_specification", "variable_parameter_specification",
  "procedural_parameter_specification",
  "functional_parameter_specification", "procedure_identification",
  "procedure_block", "function_declaration", "function_heading",
  "result_type", "function_identification", "function_block",
  "statement_part", "compound_statement", "statement_sequence",
  "statement", "open_statement", "closed_statement",
  "non_labeled_closed_statement", "non_labeled_open_statement",
  "open_while_statement", "closed_while_statement", "open_for_statement",
  "closed_for_statement", "open_if_statement", "closed_if_statement",
  "bind_statement", "variable_access", "procedure_statement", "params",
  "actual_parameter_list", "actual_parameter", "control_variable",
  "initial_value", "direction", "final_value", "boolean_expression",
  "expression", "simple_expression", "term", "factor", "exponentiation",
  "primary", "unsigned_constant", "unsigned_number", "unsigned_integer",
  "unsigned_real", "function_designator", "addop", "mulop", "relop",
  "identifier", "comma", YY_NULL
  };


  /* YYRHS -- A `-1'-separated list of the rules' RHS.  */
  const Pascal_Parser::rhs_number_type
  Pascal_Parser::yyrhs_[] =
  {
        56,     0,    -1,    57,    34,    59,    35,     0,    -1,     3,
     128,    -1,    58,    33,   128,    -1,   128,    -1,    60,    67,
      70,    89,    -1,    23,    61,    -1,    -1,    61,    62,    -1,
      62,    -1,   128,    37,    63,    34,    -1,    65,    -1,    64,
      65,    -1,    21,    -1,    43,    -1,    44,    -1,    18,    -1,
     128,    -1,    19,    -1,    25,    -1,    24,    -1,    26,    -1,
      27,    -1,    22,    68,    34,    -1,    -1,    68,    34,    69,
      -1,    69,    -1,    58,    36,    66,    -1,    71,    34,    -1,
      -1,    71,    34,    72,    -1,    72,    -1,    73,    -1,    84,
      -1,    74,    34,    83,    -1,    82,    -1,    82,    75,    -1,
      49,    76,    50,    -1,    76,    34,    77,    -1,    77,    -1,
      78,    -1,    79,    -1,    80,    -1,    81,    -1,    58,    36,
     128,    -1,    22,    58,    36,   128,    -1,    74,    -1,    85,
      -1,     4,   128,    -1,    59,    -1,    87,    34,    88,    -1,
      85,    34,    88,    -1,     5,   128,    36,    86,    -1,     5,
     128,    75,    36,    86,    -1,    24,    -1,    25,    -1,    26,
      -1,    27,    -1,     5,   128,    -1,    59,    -1,    90,    -1,
       6,    91,     7,    -1,    91,    34,    92,    -1,    92,    -1,
      93,    -1,    94,    -1,    96,    -1,    95,    -1,   103,    -1,
     105,    -1,    90,    -1,   102,    -1,    98,    -1,   100,    -1,
      -1,   101,    -1,    97,    -1,    99,    -1,     9,   113,    12,
      93,    -1,     9,   113,    12,    94,    -1,     8,   109,    32,
     110,   111,   112,    12,    93,    -1,     8,   109,    32,   110,
     111,   112,    12,    94,    -1,    13,   113,    14,    92,    -1,
      13,   113,    14,    94,    15,    93,    -1,    13,   113,    14,
      94,    15,    94,    -1,   104,    32,   114,    -1,   128,    -1,
     128,   106,    -1,   128,    -1,    49,   107,    50,    -1,   107,
     129,   108,    -1,   108,    -1,   114,    -1,   114,    36,   114,
      -1,   114,    36,   114,    36,   114,    -1,   128,    -1,   114,
      -1,    10,    -1,    11,    -1,   114,    -1,   114,    -1,   115,
      -1,   115,   127,   115,    -1,   116,    -1,   115,   125,   116,
      -1,   117,    -1,   116,   126,   117,    -1,    64,   117,    -1,
     118,    -1,   119,    -1,   119,    46,   118,    -1,   104,    -1,
     120,    -1,   124,    -1,    49,   114,    50,    -1,    51,   119,
      -1,   121,    -1,    21,    -1,   122,    -1,   123,    -1,    18,
      -1,    19,    -1,   128,   106,    -1,    43,    -1,    44,    -1,
      53,    -1,    46,    -1,    45,    -1,    47,    -1,    48,    -1,
      52,    -1,    37,    -1,    38,    -1,    41,    -1,    39,    -1,
      42,    -1,    40,    -1,    20,    -1,    33,    -1
  };

  /* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
     YYRHS.  */
  const unsigned short int
  Pascal_Parser::yyprhs_[] =
  {
         0,     0,     3,     9,    12,    16,    18,    23,    26,    27,
      30,    32,    37,    39,    42,    44,    46,    48,    50,    52,
      54,    56,    58,    60,    62,    66,    67,    71,    73,    77,
      80,    81,    85,    87,    89,    91,    95,    97,   100,   104,
     108,   110,   112,   114,   116,   118,   122,   127,   129,   131,
     134,   136,   140,   144,   149,   155,   157,   159,   161,   163,
     166,   168,   170,   174,   178,   180,   182,   184,   186,   188,
     190,   192,   194,   196,   198,   200,   201,   203,   205,   207,
     212,   217,   226,   235,   240,   247,   254,   258,   260,   263,
     265,   269,   273,   275,   277,   281,   287,   289,   291,   293,
     295,   297,   299,   301,   305,   307,   311,   313,   317,   320,
     322,   324,   328,   330,   332,   334,   338,   341,   343,   345,
     347,   349,   351,   353,   356,   358,   360,   362,   364,   366,
     368,   370,   372,   374,   376,   378,   380,   382,   384,   386
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  Pascal_Parser::yyrline_[] =
  {
         0,   100,   100,   103,   106,   107,   110,   119,   120,   123,
     124,   127,   130,   131,   132,   135,   136,   139,   140,   141,
     147,   148,   149,   150,   153,   154,   158,   159,   162,   169,
     170,   174,   175,   178,   179,   182,   185,   186,   189,   193,
     194,   197,   198,   199,   200,   203,   206,   209,   211,   213,
     215,   217,   218,   221,   222,   225,   226,   227,   228,   231,
     233,   238,   240,   242,   243,   246,   247,   250,   253,   256,
     257,   258,   259,   260,   261,   262,   265,   266,   267,   270,
     273,   276,   280,   284,   285,   288,   292,   295,   298,   299,
     302,   304,   305,   308,   309,   310,   313,   315,   317,   318,
     321,   323,   325,   326,   329,   330,   333,   334,   337,   338,
     341,   342,   345,   346,   347,   348,   349,   352,   353,   356,
     356,   358,   361,   364,   367,   368,   369,   372,   373,   374,
     375,   376,   379,   380,   381,   382,   383,   384,   387,   390
  };

  // Print the state stack on the debug stream.
  void
  Pascal_Parser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (state_stack_type::const_iterator i = yystate_stack_.begin ();
	 i != yystate_stack_.end (); ++i)
      *yycdebug_ << ' ' << *i;
    *yycdebug_ << std::endl;
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  Pascal_Parser::yy_reduce_print_ (int yyrule)
  {
    unsigned int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    /* Print the symbols being reduced, and their result.  */
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
	       << " (line " << yylno << "):" << std::endl;
    /* The symbols being reduced.  */
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
		       yyrhs_[yyprhs_[yyrule] + yyi],
		       &(yysemantic_stack_[(yynrhs) - (yyi + 1)]),
		       &(yylocation_stack_[(yynrhs) - (yyi + 1)]));
  }
#endif // YYDEBUG

  /* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
  Pascal_Parser::token_number_type
  Pascal_Parser::yytranslate_ (int t)
  {
    static
    const token_number_type
    translate_table[] =
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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int Pascal_Parser::yyeof_ = 0;
  const int Pascal_Parser::yylast_ = 205;
  const int Pascal_Parser::yynnts_ = 75;
  const int Pascal_Parser::yyempty_ = -2;
  const int Pascal_Parser::yyfinal_ = 6;
  const int Pascal_Parser::yyterror_ = 1;
  const int Pascal_Parser::yyerrcode_ = 256;
  const int Pascal_Parser::yyntokens_ = 55;

  const unsigned int Pascal_Parser::yyuser_token_number_max_ = 309;
  const Pascal_Parser::token_number_type Pascal_Parser::yyundef_token_ = 2;

/* Line 1141 of lalr1.cc  */
#line 5 "pascal_parser.yy"
} // Pascal
/* Line 1141 of lalr1.cc  */
#line 1091 "pascal_parser.tab.cc"
/* Line 1142 of lalr1.cc  */
#line 393 "pascal_parser.yy"



void Pascal::Pascal_Parser::error( const Pascal::Pascal_Parser::location_type &l,
                           const std::string &err_message)
{
   std::cout << "Blad! " << err_message << ", linia: " << scanner.get_lineno() << "\n"; 
}

/* include for access to scanner.yylex */
#include "Pascal_scanner.hpp"
static int yylex(Pascal::Pascal_Parser::semantic_type *yylval,
                 Pascal::Pascal_Scanner  &scanner,
                 Pascal::Pascal_Driver   &driver)
{
   return( scanner.yylex(yylval) );
}

