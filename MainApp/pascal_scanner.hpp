#ifndef __PascalSCANNER_HPP__
#define __PascalSCANNER_HPP__ 1

#if ! defined(yyFlexLexerOnce)
#include <FlexLexer.h>
#endif

#undef  YY_DECL
#define YY_DECL int  Pascal::Pascal_Scanner::yylex()

#include "pascal_parser.tab.hh"

namespace Pascal
{

class Pascal_Scanner : public yyFlexLexer
{
public:
   
   Pascal_Scanner(std::istream *in) : yyFlexLexer(in),
                                  yylval(NULL), scan_passed(true){};
   
	int yylex(Pascal::Pascal_Parser::semantic_type *lval)
	{
		yylval = lval;
		int res = yylex();
		return( res ); 
	}
	
	bool scanning_passed()
	{
		return scan_passed;
	}
	
	int get_lineno()
	{
		return yylineno;
	}

private:
	int yylex();
	Pascal::Pascal_Parser::semantic_type *yylval;
	bool scan_passed;
};

} /* end namespace Pascal */

#endif /* END __PascalSCANNER_HPP__ */
