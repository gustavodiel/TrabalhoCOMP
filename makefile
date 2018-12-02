make:
	flex gram.l
	bison -d gram.y
	gcc Initializers.c Boolean.c Helpers.c gram.c gram.tab.c -o compilador

run:
	./compilador tests/a.c
	./compilador tests/b.c
	./compilador tests/c.c
	./compilador tests/d.c
	./compilador tests/d.c
	./compilador tests/f.c

clean:
	rm -f tests/*.j
	rm -f gram.tab.*
	rm -f lex.yy.c

all:
	make
	make run
