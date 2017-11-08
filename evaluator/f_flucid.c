#include "imanifs.h"
#include "iglobals.h"

#include <stdlib.h>
void my_exit(int n);                                /* dump.c */
STPPTR ssearch (COORDS hd);     /* memory.c */
STPPTR stpsearch(long hd,STPPTR tl,STPPTR table[]); /* memory.c */
void error(STRING x,EXPRPTR y,int type,CELLUNION val); /* util.c */
void f_elt(rEXPRPTR e)
{
	COORDS  xyz;
	int time,tmp,dim;
	rSTPPTR s, t, p;
	dim = e->dim;
	s = STPSs;
	t = STPSt;
	p = STPSp;
	time = t->stphd.word;
	xyz = s->stphd.xyz;
	switch(dim){ 
	case 0: 
	        xyz.d2 = xyz.d1;
	        xyz.d3 = xyz.d2;
	        xyz.d1 = time;
		break;
	case 1: 
	        xyz.d3 = xyz.d2;
	        xyz.d2 = time;
		break;
	case 2: xyz.d3 = time;
		break;
	default: fprintf(stderr,"illegal # dimensions\n");
		my_exit(1);
	}
	s = ssearch( xyz);
	STPSpushval(s,t,p);
	eval(arg1.x);
	STPSpop;
}

void f_all(rEXPRPTR e)
{
	COORDS  xyz;
	int tmp,dim;
	rSTPPTR s, t, p;
	dim = e->dim;
	s = STPSs;
	t = STPSt;
	p = STPSp;
	xyz = s->stphd.xyz;
	switch(dim){ 
	case 0: t = stpsearch((long)xyz.d1,t->stptl,thashtab); 
		xyz.d1 = xyz.d2;
	        xyz.d2 = xyz.d3;
	        xyz.d3 = 0;
		break;
	case 1: t = stpsearch((long)xyz.d2,t->stptl,thashtab); 
	        xyz.d2 = xyz.d3;
	        xyz.d3 = 0;
		break;
 	case 2:	t = stpsearch((long)xyz.d3,t->stptl,thashtab); 
	 	xyz.d3 = 0;
		break;
	default: fprintf(stderr,"illegal # dimensions\n");
		my_exit(1);
	}
	s = ssearch( xyz);
	STPSpushval(s,t,p);
	eval(arg1.x);
	STPSpop;
}

void f_original(rEXPRPTR e)
{
	COORDS  xyz;
	int tmp,dim;
	rSTPPTR s, t, p;
	dim = e->dim;
	s = STPSs;
	t = STPSt;
	p = STPSp;
	xyz = s->stphd.xyz;
	switch(dim){
	case 0: xyz.d3 = xyz.d2;
		xyz.d2 = xyz.d1;
		xyz.d1 = 0;
		break;
	case 1: xyz.d3 = xyz.d2;
		xyz.d2 = 0;
		break;
	case 2: xyz.d3 = 0;
		break;
	}
	s = ssearch( xyz);
	STPSpushval(s,t,p);
	eval(arg1.x);
	STPSpop;
}



void f_succ(rEXPRPTR e)
{
	COORDS xyz;
	rSTPPTR s, t, p;
	int dim;
	dim=e->dim;
	s = STPSs;
	t = STPSt;
	p = STPSp;
	xyz = s->stphd.xyz;
	switch(dim){ 
	case 0: xyz.d1 = xyz.d1+1;
		break;
	case 1: xyz.d2 = xyz.d2+1;
		break;
	case 2: xyz.d3 = xyz.d3+1;
		break;
	default: fprintf(stderr,"illegal # dimensions\n");
		my_exit(1);
	}
	s = ssearch(xyz);
	STPSpushval(s,t,p);
	eval(arg1.x);
	STPSpop;
}



void f_nrest(rEXPRPTR e)
{
	COORDS xyz;
	rSTPPTR s, t, p;
	int dim;

	dim=e->dim;
	s = STPSs;
	t = STPSt;
	p = STPSp;
	xyz = s->stphd.xyz;
	switch(dim){ 
	case 0: xyz.d1 = xyz.d1-1;
		break;
	case 1: xyz.d2 = xyz.d2-1;
		break;
	case 2: xyz.d3 = xyz.d3-1;
		break;
	default: fprintf(stderr,"illegal # dimensions\n");
		my_exit(1);
	}
	s = ssearch(xyz);
	STPSpushval(s,t,p);
	eval(arg1.x);
	STPSpop;
}

void f_rest(rEXPRPTR e)
{
	COORDS xyz;
	rSTPPTR s, t, p;
	int dim;

	dim = e -> dim;
	s = STPSs;
	t = STPSt;
	p = STPSp;
	xyz = s->stphd.xyz;
	xyz.d1 = xyz.d1+1;
	s = ssearch(xyz);
	STPSpushval(s,t,p);
	eval(arg1.x);
	STPSpop;
}



void f_beside(rEXPRPTR e)
{
	COORDS  xyz;
	int tmp,dim;
	rSTPPTR s, t, p;

	dim = e->dim;
	s = STPSs;
	t = STPSt;
	p = STPSp;
	xyz = s->stphd.xyz;
	switch(dim){ 
	case 0: if(xyz.d1<=0){
		s = ssearch(xyz);
		STPSpushval(s,t,p);
		eval(arg1.x);
		STPSpop;
		} else {
		xyz.d1 = xyz.d1+1; 
		s = ssearch(xyz);
		STPSpushval(s,t,p);
		eval(arg2.x);
		STPSpop;
		}
		break;
	case 1: if(xyz.d2<=0){
		s = ssearch(xyz);
		STPSpushval(s,t,p);
		eval(arg1.x);
		STPSpop;
		} else {
		xyz.d2 = xyz.d2+1; 
		s = ssearch(xyz);
		STPSpushval(s,t,p);
		eval(arg2.x);
		STPSpop;
		}
		break;
	case 2: if(xyz.d3<=0){
		s = ssearch(xyz);
		STPSpushval(s,t,p);
		eval(arg1.x);
		STPSpop;
		} else {
		xyz.d3 = xyz.d3+1; 
		s = ssearch(xyz);
		STPSpushval(s,t,p);
		eval(arg2.x);
		STPSpop;
		}
		break;
	default: fprintf(stderr,"illegal # dimensions\n");
		my_exit(1);
	}
}
void f_aby(rEXPRPTR e)
{

}

void f_ncby(rEXPRPTR e)
{
	COORDS  xyz;
	int tmp,dim;
	rSTPPTR s, t, p;

	dim = e->dim;
	s = STPSs;
	t = STPSt;
	p = STPSp;
	xyz = s->stphd.xyz;
	switch(dim){ 
	case 0: if(xyz.d1>=0){
		xyz.d1 = xyz.d2; 
		xyz.d2 = xyz.d3; 
		xyz.d3 = xyz.d3; 
		s = ssearch(xyz);
		STPSpushval(s,t,p);
		eval(arg1.x);
		STPSpop;
		} else {
		xyz.d1 = xyz.d1+1; 
		s = ssearch(xyz);
		STPSpushval(s,t,p);
		eval(arg2.x);
		STPSpop;
		}
		break;
	case 1: if(xyz.d2>=0){
		xyz.d2 = xyz.d3; 
		xyz.d3 = xyz.d3; 
		s = ssearch(xyz);
		STPSpushval(s,t,p);
		eval(arg1.x);
		STPSpop;
		} else {
		xyz.d2 = xyz.d2+1; 
		s = ssearch(xyz);
		STPSpushval(s,t,p);
		eval(arg2.x);
		STPSpop;
		}
		break;
	case 2: if(xyz.d3>=0){
		xyz.d3 = 0; 
		s = ssearch(xyz);
		STPSpushval(s,t,p);
		eval(arg1.x);
		STPSpop;
		} else {
		xyz.d3 = xyz.d3+1; 
		s = ssearch(xyz);
		STPSpushval(s,t,p);
		eval(arg2.x);
		STPSpop;
		}
		break;
	default: fprintf(stderr,"illegal # dimensions\n");
		my_exit(1);
	}
}

void f_initial(rEXPRPTR e)
{
	COORDS  xyz;
	int tmp,dim;
	rSTPPTR s, t, p;
	dim = e->dim;
	s = STPSs;
	t = STPSt;
	p = STPSp;
	xyz = s->stphd.xyz;
	switch(dim){ 
	case 0: xyz.d1 = 0;
		break;
	case 1: xyz.d2 = 0;
		break;
	case 2: xyz.d3 = 0;
		break;
	default: fprintf(stderr,"illegal # dimensions\n");
		my_exit(1);
	}
	s = ssearch( xyz);
	STPSpushval(s,t,p);
	eval(arg1.x);
	STPSpop;
}

void f_noriginal(rEXPRPTR e)
{
	COORDS  xyz;
	int tmp,dim;
	rSTPPTR s, t, p;

	dim = e->dim;
	s = STPSs;
	t = STPSt;
	p = STPSp;
	xyz = s->stphd.xyz;
	switch(dim){
	case 0: xyz.d3 = xyz.d2;
		xyz.d2 = xyz.d1;
		xyz.d1 = 0;
		break;
	case 1: xyz.d3 = xyz.d2;
		xyz.d2 = 0;
		break;
	case 2: xyz.d3 = 0;
		break;
	}
	s = ssearch( xyz);
	STPSpushval(s,t,p);
	eval(arg1.x);
	STPSpop;
}

void f_rshift(rEXPRPTR e)
{
	COORDS  xyz;
	int tmp,dim;
	rSTPPTR s, t, p;

	dim = e->dim;
	s = STPSs;
	t = STPSt;
	p = STPSp;
	xyz = s->stphd.xyz;
	xyz.d1 = 0;
	xyz.d3 = xyz.d2;
	s = ssearch( xyz);
	STPSpushval(s,t,p);
	eval(arg1.x);
	STPSpop;
}


void f_lshift(rEXPRPTR e)
{

	COORDS  xyz;
	int tmp,dim;
	rSTPPTR s, t, p;

	dim = e->dim;
	s = STPSs;
	t = STPSt;
	p = STPSp;
	xyz = s->stphd.xyz;
	xyz.d1 = xyz.d2;
	xyz.d2 = xyz.d3;
	xyz.d3 = 0;
	s = ssearch( xyz);
	STPSpushval(s,t,p);
	eval(arg1.x);
	STPSpop;
}

void f_swap(rEXPRPTR e)
{
	COORDS  xyz;
	int tmp,dim;
	rSTPPTR s, t, p;

	dim = e->dim;
	s = STPSs;
	t = STPSt;
	p = STPSp;
	xyz = s->stphd.xyz;
/*
	switch(dim){ 
	case swap_t0s0: 
*/
			tmp = t->stphd.word;
			t = stpsearch((long)xyz.d1,t->stptl,thashtab); 
			xyz.d1 = tmp;
/*
			break;
	case swap_t0s1: tmp = t->stphd.word;
			t->stphd.word = xyz.d2;
			xyz.d2 = t->stphd.word;
			break;
	case swap_t0s2: tmp = t->stphd.word;
			t->stphd.word = xyz.d3;
			xyz.d3 = t->stphd.word;
			break;
	case swap_t2s3: 
	case swap_t0t1:
	case swap_t0t2:
	case swap_t1t2: break;
	case swap_s0s1: tmp = xyz.d1;
			xyz.d1 = xyz.d2;
			xyz.d2 = tmp;
			break;
	case swap_s0s2: tmp = xyz.d3;
			xyz.d1 = xyz.d3;
			xyz.d3 = tmp;
			break;
	case swap_s1s2: tmp = xyz.d2;
			xyz.d2 = xyz.d3;
			xyz.d3 = tmp;
			break;
 
	}
*/
	s = ssearch(xyz);
	STPSpushval(s,t,p);
	eval(arg1.x);
	STPSpop;
}

void f_nsby(rEXPRPTR e)
{
	COORDS  xyz;
	int tmp,dim;
	rSTPPTR s, t, p;

	dim = e->dim;
	s = STPSs;
	t = STPSt;
	p = STPSp;
	xyz = s->stphd.xyz;
	switch(dim){ 
	case 0: if(xyz.d1>=0){
		s = ssearch(xyz);
		STPSpushval(s,t,p);
		eval(arg2.x);
		STPSpop;
		} else {
		xyz.d1 = xyz.d1+1; 
		s = ssearch(xyz);
		STPSpushval(s,t,p);
		eval(arg1.x);
		STPSpop;
		}
		break;
	case 1: if(xyz.d2>=0){
		s = ssearch(xyz);
		STPSpushval(s,t,p);
		eval(arg2.x);
		STPSpop;
		} else {
		xyz.d2 = xyz.d2+1; 
		s = ssearch(xyz);
		STPSpushval(s,t,p);
		eval(arg1.x);
		STPSpop;
		}
		break;
	case 2: if(xyz.d3>=0){
		s = ssearch(xyz);
		STPSpushval(s,t,p);
		eval(arg2.x);
		STPSpop;
		} else {
		xyz.d3 = xyz.d3+1; 
		s = ssearch(xyz);
		STPSpushval(s,t,p);
		eval(arg1.x);
		STPSpop;
		}
		break;
	default: fprintf(stderr,"illegal # dimensions\n");
		my_exit(1);
	}
}

void f_sby(rEXPRPTR e)
{
	COORDS  xyz;
	int tmp,dim;
	rSTPPTR s, t, p;

	dim = e->dim;
	s = STPSs;
	t = STPSt;
	p = STPSp;
	xyz = s->stphd.xyz;
	switch(dim){ 
	case 0: if(xyz.d1<=0){
		s = ssearch(xyz);
		STPSpushval(s,t,p);
		eval(arg1.x);
		STPSpop;
		} else {
		xyz.d1 = xyz.d1-1; 
		s = ssearch(xyz);
		STPSpushval(s,t,p);
		eval(arg2.x);
		STPSpop;
		}
		break;
	case 1: if(xyz.d2<=0){
		s = ssearch(xyz);
		STPSpushval(s,t,p);
		eval(arg1.x);
		STPSpop;
		} else {
		xyz.d2 = xyz.d2-1; 
		s = ssearch(xyz);
		STPSpushval(s,t,p);
		eval(arg2.x);
		STPSpop;
		}
		break;
	case 2: if(xyz.d3<=0){
		s = ssearch(xyz);
		STPSpushval(s,t,p);
		eval(arg1.x);
		STPSpop;
		} else {
		xyz.d3 = xyz.d3-1; 
		s = ssearch(xyz);
		STPSpushval(s,t,p);
		eval(arg2.x);
		STPSpop;
		}
		break;
	default: fprintf(stderr,"illegal # dimensions\n");
		my_exit(1);
	}
}

void f_cby(rEXPRPTR e)
{
	COORDS  xyz;
	int tmp,dim;
	rSTPPTR s, t, p;

	dim = e->dim;
	s = STPSs;
	t = STPSt;
	p = STPSp;
	xyz = s->stphd.xyz;
	switch (dim) {
	case 0: if(xyz.d1<=0){
		xyz.d1 = xyz.d2; 
		xyz.d2 = xyz.d3; 
		xyz.d3 = 0; 
		s = ssearch(xyz);
		STPSpushval(s,t,p);
		eval(arg1.x);
		STPSpop;
		} else {
 		xyz.d1 = xyz.d1-1; 
		s = ssearch(xyz);
		STPSpushval(s,t,p);
		eval(arg2.x);
		STPSpop;
		}
		break;
	case 2: if(xyz.d2<=0){
		xyz.d2 = xyz.d3; 
		xyz.d3 = 0; 
		s = ssearch(xyz);
		STPSpushval(s,t,p);
		eval(arg1.x);
		STPSpop;
		} else {
 		xyz.d2 = xyz.d2-1; 
		s = ssearch(xyz);
		STPSpushval(s,t,p);
		eval(arg2.x);
		STPSpop;
		}
		break;
	case 3: if(xyz.d3<=0){
		s = ssearch(xyz);
		STPSpushval(s,t,p);
		eval(arg1.x);
		STPSpop;
		} else {
 		xyz.d3 = xyz.d3-1; 
		s = ssearch(xyz);
		STPSpushval(s,t,p);
		eval(arg2.x);
		STPSpop;
		}
		break;
	}
}


void f_atspace(rEXPRPTR e)
{  
	int type;
	COORDS xyz;
	CELLUNION value;
	rSTPPTR s,t,p;

	int tmp,dim;
	dim = e->dim;
	s = STPSs;
	t = STPSt;
	p = STPSp;
	xyz = s->stphd.xyz;
	eval(arg2.x);
	D(30) fprintf(stderr,"atspace \n"); 
	switch(VStype){
	case NUMERIC: 
		tmp=(int)VSvalue.na.r;
		switch(dim){ 
			case 0: xyz.d1 = tmp;
				break;
			case 1:  
	        		xyz.d2 = tmp;
				break;
			case 2: xyz.d3 = tmp;
				break;
			default: fprintf(stderr,"illegal # dimensions\n");
				my_exit(1);
		}
		s = ssearch( xyz);
		STPSpushval(s,t,p);
		eval(arg1.x);
		type = VStype;
		value = VSvalue;
		STPSpop;
		VSpop;
		VStype = type;
		VSvalue = value;
		return;
	case EOD:     
		VStype = EOD;
		return;
	case ERROR:   
		error("right arg of @s is",e->arg3.x,ERROR,VSvalue);
		return;
	default:      
		error("right arg of @s must be numeric, not ",
		e->arg3.x,VStype,VSvalue);
		VStype = ERROR;
		return;

	}
}

void f_whr(EXPRPTR e)
{

	rSTPPTR s, t, p;
	register int i;
	COORDS xyz;
	int dim;
	s = STPSs;
	p = STPSp;
	t = STPSt;
	dim = e->dim;
	xyz = s->stphd.xyz;
	STPSpush;
	STPSt = t;
	STPSp = p;
	for(i=0;;i++){
	switch(dim){ 
			case 0: xyz.d1 = i;
				break;
			case 1: xyz.d2 = i;
				break;
			case 2: xyz.d3 = i;
				break;
			default: fprintf(stderr,"illegal # dimensions\n");
				my_exit(1);
			}
		STPSs = ssearch(xyz);
		eval(arg2.x);
		D(30) fprintf(stderr," whr\n"); 
		switch(VStype){
		case WORD:  
			if(VSvalue.wrd==true){
				VSpop;
				eval(arg1.x);
				STPSpop;
				return;
			}
			VSpop;
			break;
		case ERROR:
			error("right arg of whr is ",e->arg3.x,
			ERROR,VSvalue);
			VStype = ERROR;
			STPSpop;
			return;
		case EOD:
			VStype = EOD;
			STPSpop;
			return;
		default:    
			error("right arg of whr must be logical, not ",e->arg3.x,VStype,VSvalue);
			STPSpop;
			VStype = ERROR;
			return;
		}
	}
}

void f_even(rEXPRPTR e)
{  
	COORDS  space;
	int tmp,dim;
	dim = e->dim;
	space = STPSs->stphd.xyz;
	VSpush;
	VStype = NUMERIC;
	switch(dim){ 
	case 0: VSvalue.na.r = space.d1*2;
		break;
	case 1: VSvalue.na.r = space.d2*2;
		break;
	case 2: VSvalue.na.r = space.d3*2;
		break;
	default: fprintf(stderr,"illegal # dimensions\n");
		my_exit(1);
	}
}


void f_odd(rEXPRPTR e)
{  
	COORDS  space;
	int tmp,dim;
	dim = e->dim;
	space = STPSs->stphd.xyz;
	VSpush;
	VStype = NUMERIC;
	switch(dim){ 
	case 0: VSvalue.na.r = space.d1*2+1;
		break;
	case 1: VSvalue.na.r = space.d2*2+1;
		break;
	case 2: VSvalue.na.r = space.d3*2+1;
		break;
	default: fprintf(stderr,"illegal # dimensions\n");
		my_exit(1);
	}
}

void f_toggle(rEXPRPTR e)
{  
	COORDS  space;
	int tmp,dim;
	dim = e->dim;
	space = STPSs->stphd.xyz;
	VSpush;
	VStype = NUMERIC;
	switch(dim){ 
	case 0: VSvalue.na.r = space.d1;
		break;
	case 1: VSvalue.na.r = space.d2;
		break;
	case 2: VSvalue.na.r = space.d3;
		break;
	default: fprintf(stderr,"illegal # dimensions\n");
		my_exit(1);
	}
}

void f_here(rEXPRPTR e)
{  
	COORDS  space;
	int tmp,dim;
	dim = e->dim;
	space = STPSs->stphd.xyz;
	VSpush;
	VStype = NUMERIC;
	switch(dim){ 
	case 0: VSvalue.na.r = space.d1;
		break;
	case 1: VSvalue.na.r = space.d2;
		break;
	case 2: VSvalue.na.r = space.d3;
		break;
	default: fprintf(stderr,"illegal # dimensions\n");
		my_exit(1);
	}
}

void f_pred(rEXPRPTR e)
{
	COORDS xyz;
	rSTPPTR s, t, p;
	int dim;

	dim=e->dim;
	s = STPSs;
	t = STPSt;
	p = STPSp;
	xyz = s->stphd.xyz;
	switch(dim){ 
	case 0: xyz.d1 = xyz.d1-1;
		break;
	case 1: xyz.d2 = xyz.d2-1;
		break;
	case 2: xyz.d3 = xyz.d3-1;
		break;
	default: fprintf(stderr,"illegal # dimensions\n");
		my_exit(1);
	}
	s = ssearch(xyz);
	STPSpushval(s,t,p);
	eval(arg1.x);
	STPSpop;
}



