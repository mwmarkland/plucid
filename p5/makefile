CC = gcc
R=
DESTDIR=/usr/local/bin
CPPFLAGS=-DYYMAXDEPTH=900
# gnu99 due to putw() use.
CFLAGS=-std=gnu99 -fdiagnostics-color=never 
LDFLAGS=-static


LINT= lint -p
TAR= tar -cv
PRINT= pr -t $1 | cat -n
inc = cmanifs.h cglobals.h

%.o : %.c cglobals.h cmanifs.h y.tab.h
	$(CC) -c -I. $(CPPFLAGS) $(CFLAGS) $< -o $@

pass5: main.o y.tab.o yylex.o expr.o ident.o;
	$(CC) $(LDFLAGS) -g main.o expr.o y.tab.o yylex.o ident.o -o pass5

cp install:
	cp pass5 $R$(DESTDIR)/pass5
	rm -f *.o y.tab.h y.tab.c pass5

clean:
	rm -f *.o y.tab.h y.tab.c pass5

lint:   main.c expr.c yylex.c ident.c
	$(LINT) main.c expr.c yylex.c ident.c

tape:
	$(TAR) main.c expr.c yylex.c ident.c cmanifs.h cglobals.h tree.y

print:
	$(PRINT) main.c expr.c yylex.c ident.c cmanifs.h cglobals.h tree.y


all:    main.o y.tab.o yylex.o expr.o ident.o ;
	cc -g main.o expr.o y.tab.o yylex.o ident.o -o pass5
	cp pass5 $R$(DESTDIR)/pass5
	rm -f *.o y.tab.h y.tab.c pass5

y.tab.c y.tab.h: tree.y
	yacc -d tree.y
