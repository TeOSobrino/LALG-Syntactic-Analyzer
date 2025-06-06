BINARY=lalgc
TEST=ex.lalg
CC=gcc

flex: lexer.l
	@flex lexer.l
yacc: flex parser.y
	@yacc -d parser.y
all: yacc
	@$(CC) lex.yy.c y.tab.c -o $(BINARY) 
run: lexer.l parser.y
	@./$(BINARY) -i $(TEST) -t 
clean:
	@rm y.tab.c y.tab.h lex.yy.c $(BINARY)