pascal: 
	win_bison -d -v pascal_parser.yy
	win_flex -i --outfile=pascal_lexer.yy.cc pascal_lexer.l 
	g++ -o pascal.exe pascal_driver.cpp pascal_lexer.yy.cc pascal_parser.tab.cc main.cpp ofile.cpp key.cpp ifile.cpp gen_key.cpp codec.cpp Node.cpp HTreePlain.cpp HTreeEnc.cpp HFile.cpp File.cpp Bit.cpp quicklz.c -lmpir -lfl