all:
	flex lexer.lexer
	gcc lex.yy.c -lfl