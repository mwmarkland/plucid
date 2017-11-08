#include "imanifs.h"
#include "iglobals.h"
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
