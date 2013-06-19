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

program : program_heading SCOLON block DOT END
        ;

program_heading : PROGRAM_P identifier
        ;

identifier_list : identifier_list COMMA identifier
        | identifier
        ;

block : constant_definition_part
        variable_declaration_part
        procedure_and_function_declaration_part
        statement_part
        ;

//------------------
/* blok definiowania sta³ych */
		
constant_definition_part : CONST_P constant_list
        |
        ;

constant_list : constant_list constant_definition
        | constant_definition
        ;

constant_definition : identifier EQUAL constant SCOLON
        ;

constant : non_string
        | sign non_string
        | STRING
        ;

sign : PLUS
        | MINUS
        ;

non_string : NUMBER
        | identifier
        | REAL_NR
        ;

//------------------
/* blok definiowania zmiennych */

type_denoter : REAL_P
		| INT_P
		| STRING_P
		| BOOL_P
        ;

variable_declaration_part : VAR_P variable_declaration_list SCOLON
        |
        ;

variable_declaration_list :
          variable_declaration_list SCOLON variable_declaration
        | variable_declaration
        ;

variable_declaration : identifier_list COLON type_denoter
        ;

//--------------------		
/* blok funkcji i procedur */
		
procedure_and_function_declaration_part :
          proc_or_func_declaration_list SCOLON
        |
        ;

proc_or_func_declaration_list :
          proc_or_func_declaration_list SCOLON proc_or_func_declaration
        | proc_or_func_declaration
        ;

proc_or_func_declaration : procedure_declaration
        | function_declaration
        ;

procedure_declaration : procedure_heading SCOLON procedure_block
        ;

procedure_heading : procedure_identification
        | procedure_identification formal_parameter_list
        ;

formal_parameter_list : LPAREN formal_parameter_section_list RPAREN 
		;

formal_parameter_section_list : 
          formal_parameter_section_list SCOLON formal_parameter_section
        | formal_parameter_section
        ;

formal_parameter_section : value_parameter_specification
        | variable_parameter_specification
        | procedural_parameter_specification
        | functional_parameter_specification
        ;

value_parameter_specification : identifier_list COLON identifier
        ;

variable_parameter_specification : VAR_P identifier_list COLON identifier
        ;

procedural_parameter_specification : procedure_heading ;

functional_parameter_specification : function_heading ;

procedure_identification : PROCED_P identifier ;

procedure_block : block ;

function_declaration : function_identification SCOLON function_block
        | function_heading SCOLON function_block
        ;

function_heading : FUNCTION_P identifier COLON result_type
        | FUNCTION_P identifier formal_parameter_list COLON result_type
        ;

result_type : INT_P 
		| REAL_P
		| STRING_P
		| BOOL_P
		;

function_identification : FUNCTION_P identifier ;

function_block : block ;

//-------------------------
/* blok 'program g³ówny' */

statement_part : compound_statement ;

compound_statement : BEGIN_P statement_sequence END_P ;

statement_sequence : statement_sequence SCOLON statement
        | statement
        ;

statement : open_statement
        | closed_statement
        ;

open_statement : non_labeled_open_statement
        ;

closed_statement : non_labeled_closed_statement
        ;

non_labeled_closed_statement : bind_statement
        | procedure_statement
        | compound_statement
        | closed_if_statement
        | closed_while_statement
        | closed_for_statement
        |
        ;

non_labeled_open_statement : open_if_statement
        | open_while_statement
        | open_for_statement
        ;

open_while_statement : WHILE_P boolean_expression DO_P open_statement
        ;

closed_while_statement : WHILE_P boolean_expression DO_P closed_statement
        ;

open_for_statement : FOR_P control_variable BIND initial_value direction
                        final_value DO_P open_statement
        ;

closed_for_statement : FOR_P control_variable BIND initial_value direction
                        final_value DO_P closed_statement
        ;

open_if_statement : IF_P boolean_expression THEN_P statement
        | IF_P boolean_expression THEN_P closed_statement ELSE_P open_statement
        ;

closed_if_statement : IF_P boolean_expression THEN_P closed_statement
                        ELSE_P closed_statement
        ;

bind_statement : variable_access BIND expression
        ;

variable_access : identifier
        ;

procedure_statement : identifier params
        | identifier
        ;

params : LPAREN actual_parameter_list RPAREN ;

actual_parameter_list : actual_parameter_list comma actual_parameter
        | actual_parameter
        ;

actual_parameter : expression
        | expression COLON expression
        | expression COLON expression COLON expression
        ;

control_variable : identifier ;

initial_value : expression ;

direction : TO_P
        | DOWNTO_P
        ;

final_value : expression ;

boolean_expression : expression ;

expression : simple_expression
        | simple_expression relop simple_expression
        ;

simple_expression : term
        | simple_expression addop term
        ;

term : factor
        | term mulop factor
        ;

factor : sign factor
        | exponentiation
        ;
        
exponentiation : primary
        | primary STAR exponentiation
        ;

primary : variable_access
        | unsigned_constant
        | function_designator
        | LPAREN expression RPAREN
        | NOT_P primary
        ;

unsigned_constant : unsigned_number
        | STRING
        ;

unsigned_number : unsigned_integer | unsigned_real ;

unsigned_integer : NUMBER
        ;

unsigned_real : REAL_NR
        ;

function_designator : identifier params
        ;

addop: PLUS
        | MINUS
        | OR_P
        ;

mulop : STAR
        | SLASH
        | DIV_P
        | MOD_P
        | AND_P
        ;

relop : EQUAL
        | NOTEQ
        | LT
        | GT
        | LE
        | GE
        ;

identifier : IDENT
        ;

comma : COMMA
        ;

%%


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

