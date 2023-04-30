all:
	flex lexer.lex
	bison -v -d --file-prefix=y bison.y 
	gcc -o parser y.tab.c lex.yy.c  -lfl

clean: rm -f lexer parser lex.yy.c y.tab.c y.tab.h y.output