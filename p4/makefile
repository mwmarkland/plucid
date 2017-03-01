CC = gcc
R=
DESTDIR=/usr/local/bin
CPPFLAGS=-DYYMAXDEPTH=900
CFLAGS=-std=c99 -fdiagnostics-color=never 
LDFLAGS=-static


LINT= lint -p
TAR= tar -cv
PRINT= pr -t $1 | cat -n
inc = cmanifs.h cglobals.h

%.o : %.c cglobals.h cmanifs.h y.tab.h
	$(CC) -c -I. $(CPPFLAGS) $(CFLAGS) $< -o $@

pass4: main.o y.tab.o yylex.o expr.o walk.o;
	$(CC)  $(LDFLAGS) main.o expr.o y.tab.o yylex.o walk.o -o pass4

cp install:
	cp pass4 $R$(DESTDIR)/pass4
	rm -f *.o y.tab.h y.tab.c pass4

clean:
	rm -f *.o y.tab.h y.tab.c pass4

lint:   main.c expr.c yylex.c walk.c
	$(LINT) main.c expr.c yylex.c walk.c

tape:
	$(TAR) main.c expr.c yylex.c walk.c cmanifs.h cglobals.h tree.y

print:
	$(PRINT) main.c expr.c yylex.c walk.c cmanifs.h cglobals.h tree.y


all:    main.o y.tab.o yylex.o expr.o walk.o ;
	cc  -g main.o expr.o y.tab.o yylex.o walk.o -o pass4
	cp pass4 $R$(DESTDIR)/pass4
	rm -f *.o y.tab.h y.tab.c pass4

y.tab.c y.tab.h: tree.y
	yacc -d tree.y
