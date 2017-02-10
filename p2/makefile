CC=gcc
CFLAGS=-fdiagnostics-color=never 
CPPFLAGS=-DYYMAXDEPTH=900
LDFLAGS=-static

DESTDIR=/usr/local/bin
inc = cmanifs.h cglobals.h

%.o : %.c cglobals.h cmanifs.h y.tab.h
	$(CC) -c -I. $(CPPFLAGS) $(CFLAGS) $< -o $@

pass2: main.o y.tab.o yylex.o expr.o ;
	$(CC) $(CPPFLAGS) $(LDFLAGS) main.o expr.o y.tab.o yylex.o -o pass2

all:    main.o y.tab.o yylex.o expr.o ;
	gcc -std=c99 --static main.o expr.o y.tab.o yylex.o -o pass2
	cp pass2 $R$(DESTDIR)/pass2
	rm -f *.o y.tab.h y.tab.c pass2

clean:
	rm -f *.o y.tab.h y.tab.c pass2

y.tab.c y.tab.h: tree.y
	yacc -d tree.y
