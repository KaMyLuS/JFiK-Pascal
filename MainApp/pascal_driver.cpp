#include <cctype>
#include <fstream>
#include <cassert>

#include "pascal_driver.hpp"

// wapascalkee 2013 APR 2 - Instead of testing for == FAIL below,
// we test for != ACCEPT (in which ACCEPT has a value of zero).
// When compiling on a MSVC 2010 platform using cygwin's Flex and Bison,
// we note that the return value from parse() is not -1 but rather +1.
// It is more likely that on different platforms the return value of zero
// will be used consistantly to indicate an accept state. Whereas, the
// value of the abort or fail state will be more likely not to be a specific
// value but rather a value that is not equal to zero.

#ifndef ACCEPT
#define ACCEPT 0
#endif

Pascal::Pascal_Driver::~Pascal_Driver(){ 
   delete(scanner);  // wapascalkee 2013 APR 2
   delete(parser);   // wapascalkee 2013 APR 2
}

bool Pascal::Pascal_Driver::parse( const char *filename ){
   //assert( filename != NULL );
   std::ifstream in_file( filename );
   /*std::cout << "plik to: " << filename << std::endl;
   std::string x;
   while(in_file >> x) std::cout << "w pliku: " << x << std::endl;*/
    if( ! in_file.good() ) 
   {
		std::cout << "Blad! Nie moge otworzyc pliku " << filename << "!" << std::endl;
		return 0;
   }
   
   delete(scanner); // wapascalkee 2013 APR 2
   scanner = new Pascal::Pascal_Scanner( &in_file );
   /* check to see if its initialized */
   assert( scanner != NULL );
   
   delete(parser); // wapascalkee 2013 APR 2
   parser = new Pascal::Pascal_Parser( (*scanner) /* scanner */, 
                               (*this) /* driver */ );
   assert( parser != NULL );
   
   if(parser->parse() != ACCEPT) // wapascalkee 2013 APR 2
   {
      std::cout << "Blad! Plik NIE przeszedl pomyslnie etapu parsowania!\n";
	  return 0;
   }
   std::cout << "Parsowanie pliku zakonczone sukcesem!\n";
   return 1;
}

bool Pascal::Pascal_Driver::scan( const char *filename ){
   assert( filename != NULL );
   std::ifstream in_file( filename );
   if( ! in_file.good() ) 
   {
		std::cout << "Blad! Nie moge otworzyc pliku " << filename << "!" << std::endl;
		return 0;
   }
   
   delete(scanner); // wapascalkee 2013 APR 2
   scanner = new Pascal::Pascal_Scanner( &in_file );
   assert( scanner != NULL );
	
    Pascal::Pascal_Parser::semantic_type yylval;
	while(scanner->yylex(&yylval));
	
	if(scanner->scanning_passed()) std::cout << "Skanowanie pliku zakonczone sukcesem!\n";
	else std::cout << "Blad! Plik NIE przeszedl pomyslnie etapu skanowania!\n";
	
	return scanner->scanning_passed();
}

void Pascal::Pascal_Driver::add_upper(){ uppercase++; chars++; words++; }

void Pascal::Pascal_Driver::add_lower(){ lowercase++; chars++; words++; }

void Pascal::Pascal_Driver::add_word( const std::string &c ){
   words++; 
   chars += c.length();
   for(std::string::const_iterator it = c.begin(); it != c.end(); ++it){
      if( islower( (*it) ) ) { lowercase++; }
      else if ( isupper( (*it) ) ) { uppercase++; }
   }
}

void Pascal::Pascal_Driver::add_newline(){ lines++; chars++; }

void Pascal::Pascal_Driver::add_char(){ chars++; }


std::ostream& Pascal::Pascal_Driver::print(std::ostream &stream){
   stream << "Uppercase: " << uppercase << "\n";
   stream << "Lowercase: " << lowercase << "\n";
   stream << "Lines: " << lines << "\n";
   stream << "Words: " << words << "\n";
   stream << "Characters: " << chars << "\n";
   return(stream);
}
