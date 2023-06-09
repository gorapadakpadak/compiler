c-- : tac.o util.a y.tab.o lex.yy.o 
	gcc -o c-- y.tab.o lex.yy.o tac.o util.a -ll

tac.o : tac.c
	gcc -c -o tac.o tac.c

y.tab.o : y.tab.c 
	gcc -c -o y.tab.o y.tab.c

lex.yy.o : lex.yy.c
	gcc -c -o lex.yy.o lex.yy.c

y.tab.c : parser.y
	yacc -d parser.y

lex.yy.c : tokenizer.l
	flex tokenizer.l

clean :
	rm -f lex.yy.o lex.yy.c y.tab.o y.tab.c y.tab.h tac.o c--

