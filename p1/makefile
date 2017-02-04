CC=gcc
R=
DESTDIR= /usr/local/bin
#CFLAGS=-O -DYYMAXDEPTH=900
CFLAGS=-fdiagnostics-color=never 
CPPFLAGS=-DYYMAXDEPTH=900
LDFLAGS=-static
LINT= lint -p
TAR= tar -cv

%.o : %.c cglobals.h cmanifs.h y.tab.h
	$(CC) -c -I. $(CPPFLAGS) $(CFLAGS) $< -o $@

pass1: main.o y.tab.o yylex.o expr.o ;
	$(CC) $(CPPFLAGS) $(LDFLAGS) main.o expr.o y.tab.o yylex.o -o pass1

cp install:
	cp pass1 $R$(DESTDIR)/pass1
	rm -f *.o y.tab.h y.tab.c pass1

clean:
	rm -f *.o y.tab.h y.tab.c pass1

print:  

lint: main.c yylex.c expr.c
	$(LINT) main.c yylex.c expr.c

tape:
	$(TAR) main.c yylex.c expr.c cmanifs.h cglobals.h flucid.y

all:    main.o y.tab.o yylex.o expr.o ;
	cc -s -DYYMAXDEPTH=900 main.o expr.o y.tab.o yylex.o -o pass1
	cp pass1 $R$(DESTDIR)/pass1
	rm -f *.o y.tab.h y.tab.c pass1

y.tab.c y.tab.h: flucid.y
	yacc -d flucid.y
