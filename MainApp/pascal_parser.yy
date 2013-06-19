%skeleton "lalr1.cc"
%require  "2.5"
%debug 
%defines 
%define namespace "Pascal"
%define parser_class_name "Pascal_Parser"

%code requires{
   namespace Pascal {
      class Pascal_Driver;
      class Pascal_Scanner;
   }
}

%lex-param   { Pascal_Scanner  &scanner  }
%parse-param { Pascal_Scanner  &scanner  }

%lex-param   { Pascal_Driver  &driver  }
%parse-param { Pascal_Driver  &driver  }

%code{
   #include <iostream>
   #include <cstdlib>
   #include <fstream>
   
   /* include for all driver functions */
   #include "Pascal_driver.hpp"
  
   /* this is silly, but I can't figure out a way around */
   static int yylex(Pascal::Pascal_Parser::semantic_type *yylval,
                    Pascal::Pascal_Scanner  &scanner,
                    Pascal::Pascal_Driver   &driver);
   
}

/* token types */
%union {
   std::string *sval;
}

%token        END    0     "end of file"
%token PROGRAM_P
%token PROCED_P
%token FUNCTION_P
%token BEGIN_P
%token END_P
%token FOR_P
%token WHILE_P
%token TO_P
%token DOWNTO_P
%token DO_P
%token IF_P
%token THEN_P
%token ELSE_P
%token REPEAT_P
%token UNTIL_P

%token <sval> NUMBER
%token <sval> REAL_NR
%token <sval> IDENT
%token <sval> STRING
%token VAR_P
%token CONST_P
%token INT_P
%token REAL_P
%token STRING_P
%token BOOL_P
%token TRUE_P
%token FALSE_P
%token ARRAY_P
%token OF_P

%token BIND
%token COMMA
%token SCOLON
%token DOT
%token COLON
%token EQUAL
%token NOTEQ
%token GT
%token GE
%token LT
%token LE
%token PLUS
%token MINUS
%token SLASH
%token STAR
%token DIV_P
%token MOD_P
%token LPAREN
%token RPAREN
%token NOT_P
%token AND_P
%token OR_P

%token WRONG

%%

program : END;

%%


void Pascal::Pascal_Parser::error( const Pascal::Pascal_Parser::location_type &l,
                           const std::string &err_message)
{
   std::cout << "Error: " << err_message << " w linii: " << scanner.get_lineno() << "\n"; 
}

/* include for access to scanner.yylex */
#include "Pascal_scanner.hpp"
static int yylex(Pascal::Pascal_Parser::semantic_type *yylval,
                 Pascal::Pascal_Scanner  &scanner,
                 Pascal::Pascal_Driver   &driver)
{
   return( scanner.yylex(yylval) );
}

