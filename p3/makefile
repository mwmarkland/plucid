CC=gcc-8

R=
DESTDIR=/usr/local/bin
CFLAGS=-m32 -O -DYYMAXDEPTH=900
LINT= lint -p
TAR= tar -cv
PRINT= pr -t $1 | cat -n
inc = cmanifs.h cglobals.h

pass3: main.o y.tab.o yylex.o expr.o ;
	gcc-8 -m32 -s main.o expr.o y.tab.o yylex.o -o pass3

cp install:
	cp pass3 $R$(DESTDIR)/pass3
	rm -f *.o y.tab.h y.tab.c pass3

clean:
	rm -f *.o y.tab.h y.tab.c pass3

lint:   main.c expr.c yylex.c
	$(LINT) main.c expr.c yylex.c

tape:
	$(TAR) main.c expr.c yylex.c cmanifs.h cglobals.h tree.y

print:
	$(PRINT) main.c expr.c yylex.c cmanifs.h cglobals.h tree.y


all:    main.o y.tab.o yylex.o expr.o ;
	cc -s main.o expr.o y.tab.o yylex.o -o pass3
	cp pass3 $R$(DESTDIR)/pass3
	rm -f *.o y.tab.h y.tab.c pass3

main.o: $(inc) main.c
cmanifs.h: y.tab.h
y.tab.c y.tab.h: tree.y
	yacc -d tree.y
y.tab.o: $(inc) y.tab.h y.tab.c
yylex.o: $(inc) yylex.c
expr.o: $(inc) expr.c
