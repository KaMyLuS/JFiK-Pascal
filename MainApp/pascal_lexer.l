%{
/* C++ string header, for string ops below */
#include <string>
/* Implementation of yyFlexScanner */ 
#include "pascal_scanner.hpp"

/* typedef to make the returns for the tokens shorter */
typedef Pascal::Pascal_Parser::token token;

/* define to keep from re-typing the same code over and over */
#define STOKEN( x ) ( new std::string( x ) )

/* define yyterminate as this instead of NULL */
#define yyterminate() return(token::END)

/* msvc2010 requires that we exclude this header file. */
#define YY_NO_UNISTD_H

%}

%option debug 
%option nodefault 
%option yyclass="Pascal_Scanner" 
%option noyywrap 
%option c++
%option yylineno

NUMBER [0-9]+
REAL_NR [0-9]+\.[0-9]*
IDENT [_a-z]+[_a-z0-9]*
STRING '[^']*'

%%

program     { 
			   std::cout << "program, linia: " << yylineno << std::endl;
               return(token::PROGRAM_P);  
            }
procedure   { 
			   std::cout << "procedure, linia: " << yylineno << std::endl;
               return(token::PROCED_P);  
            }
function    { 
			   std::cout << "function, linia: " << yylineno << std::endl;
               return(token::FUNCTION_P);  
            }
begin   	{ 
			   std::cout << "begin, linia: " << yylineno << std::endl;
               return(token::BEGIN_P);  
            }
end    		{ 
			   std::cout << "end, linia: " << yylineno << std::endl;
               return(token::END_P);  
            }
for		   	{ 
			   std::cout << "for, linia: " << yylineno << std::endl;
               return(token::FOR_P);  
            }
while    	{ 
			   std::cout << "while, linia: " << yylineno << std::endl;
               return(token::WHILE_P);  
            }
to		    { 
			   std::cout << "to, linia: " << yylineno << std::endl;
               return(token::TO_P);  
            }
downto    	{ 
			   std::cout << "downto, linia: " << yylineno << std::endl;
               return(token::DOWNTO_P);  
            }
do		    { 
			   std::cout << "do, linia: " << yylineno << std::endl;
               return(token::DO_P);  
            }
if		    { 
			   std::cout << "if, linia: " << yylineno << std::endl;
               return(token::IF_P);  
            }
then    	{ 
			   std::cout << "then, linia: " << yylineno << std::endl;
               return(token::THEN_P);  
            }
else	    { 
			   std::cout << "else, linia: " << yylineno << std::endl;
               return(token::ELSE_P);  
            }
repeat    	{ 
			   std::cout << "repeat, linia: " << yylineno << std::endl;
               return(token::REPEAT_P);  
            }
until		{ 
			   std::cout << "until, linia: " << yylineno << std::endl;
               return(token::UNTIL_P);  
            }
		
{NUMBER}	{ 
				yylval->sval = STOKEN(yytext); 
				std::cout << "number, linia: " << yylineno << ", wartosc: " << *(yylval->sval) << std::endl;
				return(token::NUMBER);  
            }
{REAL_NR}	{ 
				yylval->sval = STOKEN(yytext); 
				std::cout << "real number, linia: " << yylineno << ", wartosc: " << *(yylval->sval) << std::endl;
				return(token::REAL_NR);  
            }
var		    { 
			   std::cout << "var, linia: " << yylineno << std::endl;
               return(token::VAR_P);  
            }
const	    { 
			   std::cout << "const, linia: " << yylineno << std::endl;
               return(token::CONST_P);  
            }
integer	    { 
			   std::cout << "integer, linia: " << yylineno << std::endl;
               return(token::INT_P);  
            }
real	    { 
			   std::cout << "real, linia: " << yylineno << std::endl;
               return(token::REAL_P);  
            }
string	    { 
			   std::cout << "string_p, linia: " << yylineno << std::endl;
               return(token::STRING_P);  
            }
boolean	    { 
			   std::cout << "boolean, linia: " << yylineno << std::endl;
               return(token::BOOL_P);  
            }	
true	    { 
			   std::cout << "true, linia: " << yylineno << std::endl;
               return(token::TRUE_P);  
            }	
false	    { 
			   std::cout << "false, linia: " << yylineno << std::endl;
               return(token::FALSE_P);  
            }		
array	    { 
			   std::cout << "array, linia: " << yylineno << std::endl;
               return(token::ARRAY_P);  
            }	
of		    { 
			   std::cout << "of, linia: " << yylineno << std::endl;
               return(token::OF_P);  
            }	
			
\:=		    { 
			   std::cout << ":=, linia: " << yylineno << std::endl;
               return(token::BIND);  
            }			
,		    { 
			   std::cout << "comma, linia: " << yylineno << std::endl;
               return(token::COMMA);  
            }	
;		    { 
			   std::cout << "scolon, linia: " << yylineno << std::endl;
               return(token::SCOLON);  
            }	
\.		    { 
			   std::cout << "dot, linia: " << yylineno << std::endl;
               return(token::DOT);  
            }	
\:		    { 
			   std::cout << "colon, linia: " << yylineno << std::endl;
               return(token::COLON);  
            }	
=		    { 
			   std::cout << "=, linia: " << yylineno << std::endl;
               return(token::EQUAL);  
            }
\<\>		{ 
			   std::cout << "<>, linia: " << yylineno << std::endl;
               return(token::NOTEQ);  
            }			
\>			{ 
			   std::cout << ">, linia: " << yylineno << std::endl;
               return(token::GT);  
            }
\>=			{ 
			   std::cout << ">=, linia: " << yylineno << std::endl;
               return(token::GE);  
            }	
\<			{ 
			   std::cout << "<, linia: " << yylineno << std::endl;
               return(token::LT);  
            }		
\<=			{ 
			   std::cout << "<=, linia: " << yylineno << std::endl;
               return(token::LE);  
            }	
\+			{ 
			   std::cout << "+, linia: " << yylineno << std::endl;
               return(token::PLUS);  
            }	
\-			{ 
			   std::cout << "-, linia: " << yylineno << std::endl;
               return(token::MINUS);  
            }
\/			{ 
			   std::cout << "/, linia: " << yylineno << std::endl;
               return(token::SLASH);  
            }	
\*			{ 
			   std::cout << "*, linia: " << yylineno << std::endl;
               return(token::STAR);  
            }		
div			{ 
			   std::cout << "div, linia: " << yylineno << std::endl;
               return(token::DIV_P);  
            }		
mod			{ 
			   std::cout << "mod, linia: " << yylineno << std::endl;
               return(token::MOD_P);  
            }	
\(			{ 
			   std::cout << "(, linia: " << yylineno << std::endl;
               return(token::LPAREN);  
            }	
\)			{ 
			   std::cout << "), linia: " << yylineno << std::endl;
               return(token::RPAREN);  
            }	
not			{ 
			   std::cout << "not, linia: " << yylineno << std::endl;
               return(token::NOT_P);  
            }
and			{ 
			   std::cout << "and, linia: " << yylineno << std::endl;
               return(token::AND_P);  
            }		
or			{ 
			   std::cout << "or, linia: " << yylineno << std::endl;
               return(token::OR_P);  
            }			
			
			
{IDENT}	   	{ 
				yylval->sval = STOKEN(yytext); 
				std::cout << "ident, linia: " << yylineno << ", wartosc: " << *(yylval->sval) << std::endl;
				return(token::IDENT);  
            }
{STRING}	{ 
				yylval->sval = STOKEN(yytext); 
				std::cout << "string, linia: " << yylineno << ", wartosc: " << *(yylval->sval) << std::endl;
				return(token::STRING);  
            }
			
[ \t\n]	
.			{ 
			   std::cout << "zly znak, linia: " << yylineno << " -> " << yytext << std::endl;
			   scan_passed = false;
               return(token::WRONG);  
            }
%%


