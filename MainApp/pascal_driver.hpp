#ifndef __PascalDRIVER_HPP__
#define __PascalDRIVER_HPP__ 1

#include <string>
#include "pascal_scanner.hpp"
#include "pascal_Parser.tab.hh"

namespace Pascal{

class Pascal_Driver{
public:
   Pascal_Driver() : chars(0),
                 words(0),
                 lines(0),
                 uppercase(0),
                 lowercase(0),
                 parser( NULL ),
                 scanner( NULL ){};

   virtual ~Pascal_Driver();

   bool parse( const char *filename );
   bool scan( const char *filename );
  

   void add_upper();
   void add_lower();
   void add_word( const std::string &c );
   void add_newline();
   void add_char();

   std::ostream& print(std::ostream &stream);
   
   Pascal::Pascal_Scanner* get_scanner()
   {
		return scanner;
   }
   
   Pascal::Pascal_Parser* get_parser()
	{
		return parser;
	}
	
private:
   int chars;
   int words;
   int lines;
   int uppercase;
   int lowercase;
   Pascal::Pascal_Parser *parser;
   Pascal::Pascal_Scanner *scanner;
};

} /* end namespace Pascal */
#endif /* END __PascalDRIVER_HPP__ */
