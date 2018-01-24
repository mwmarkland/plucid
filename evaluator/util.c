#include "imanifs.h"
#include "iglobals.h"

void dumpfile(char *x,EXPRPTR e);        /* dump.c */
void dumpmemry(int type,WORDCELL value); /* dump.c */
void my_exit(int n);                     /* dump.c */
void error(STRING x,EXPRPTR y,int type,CELLUNION val)
{       
	int i;
	if  (!tflags[9]) {  
		evalerr = true;
		if (newout) { 
			for (i=0; i<80; i++) fprintf(stderr,"-");
			newout = false; 
		}
		dumpfile(x,y);
		dumpmemry(type,val); 
	}
	errcount++;
        if (errcount > 2) { my_exit(1); }
}
