#include "cmanifs.h"
#include "cglobals.h"


void pass1(EXPRPTR e)
{
  output(e);
}

EXPRPTR stripstring(char s[])
{
  int n;
  STRING strsave();
  EXPRPTR connode();
  for (n=0; (isalpha(*s)|| *s == '@'); s++) { n++; }
  s++;
  return(connode(strsave("string"),s));
}

float stripcode(char s[])
{ 
  if (strcmp(s,"swap_t0s0")) return(1.0);
  if (strcmp(s,"swap_t0s1")) return(2.0);
  if (strcmp(s,"swap_t0s2")) return(3.0);
  if (strcmp(s,"swap_t1s1")) return(4.0);
  if (strcmp(s,"swap_t1s2")) return(5.0);
  if (strcmp(s,"swap_t2s3")) return(6.0);
  if (strcmp(s,"swap_t0t1")) return(7.0);
  if (strcmp(s,"swap_t0t2")) return(8.0);
  if (strcmp(s,"swap_t0t3")) return(9.0);
  if (strcmp(s,"swap_t1t2")) return(10.0);
  if (strcmp(s,"swap_t1t3")) return(11.0);
  if (strcmp(s,"swap_t2t3")) return(12.0);
  if (strcmp(s,"swap_s0s1")) return(13.0);
  if (strcmp(s,"swap_s0s2")) return(14.0);
  if (strcmp(s,"swap_s0s3")) return(15.0);
  if (strcmp(s,"swap_s1s2")) return(16.0);
  if (strcmp(s,"swap_s1s3")) return(17.0);
  if (strcmp(s,"swap_s2s3")) return(18.0);
  return(999.0);
}

float stripn(char s[])
{
  int n;
  float mknumber();
  EXPRPTR f_connode();
  for (n=0; (isalpha(*s)|| *s == '@'); s++) { n++; }
  return(mknumber(s));
}

EXPRPTR stripnumb(char s[])
{
  int n;
  float mknumber();
  EXPRPTR f_connode();
  for (n=0; (isalpha(*s)|| *s == '@'); s++) { n++; }
  return(f_connode(mknumber(s)));
}

float mknumber(char s[])
{
  int i;
  float n;
  n = 0;
  for (i=0; s[i] >= '0' && s[i] <='9'; i++)
    n = 10 * n + s[i] -'0';
  return(n);
}

STRING stripname(char s[])
{
  STRING strsave();
  char buff[20];
  int n;
  for (n=0; (isalpha(*s)|| *s == '@'); s++) { buff[n]= *s; n++; }
  buff[n]='\0';
  return(strsave(buff));
}

EXPRPTR filenode(int first_line,int cursor_position)
{

  EXPRPTR p;
  p = (EXPRPTR) calloc(1, sizeof(EXPR4));
  p->f = F_FILE;
  p->arg1.s = in_files[in_index].in_name;
  p->arg2.i = first_line;
  p->arg3.i = in_files[in_index].in_line;
  p->arg4.i = cursor_position;
  return(p);
}

EXPRPTR connode(char *s1,char *s2)
{

  EXPRPTR p;
  p = (EXPRPTR) calloc(1, sizeof(EXPR2));
  p->f = F_CONST;
  p->arg1.s = s1;
  p->arg2.s = s2;
  return(p);
}

EXPRPTR lu_connode(STRING s1, float n)
{

  EXPRPTR p;
  p = (EXPRPTR) calloc(1, sizeof(EXPR2));
  p->f =      F_CONST;
  p->arg1.s = s1;
  p->arg2.r = (float) n;
  return(p);
}

EXPRPTR f_connode(float n)
{

  EXPRPTR p;
  p = (EXPRPTR) calloc(1, sizeof(EXPR2));
  p->f =      F_CONST;
  p->arg1.s = "numb";
  p->arg2.r = (float) n;
  return(p);
}

EXPRPTR varnode(int name,int argcount,EXPRPTR exprlist, EXPRPTR file)
{

  EXPRPTR p;
  p = (EXPRPTR) calloc(1,sizeof(EXPR4));
  p->f =      F_VAR;
  p->arg1.s = name;
  p->arg2.i = argcount;
  p->arg3.x = exprlist;
  p->arg4.x = file;
  return(p);
}

EXPRPTR opnode(char *name,int argcount,EXPRPTR exprlist,EXPRPTR file)
{

  EXPRPTR p;
  p = (EXPRPTR) calloc(1,sizeof(EXPR4));
  p->f =      F_OP;
  p->arg1.s = name;
  p->arg2.i = argcount;
  p->arg3.x = exprlist;
  p->arg4.x = file;
  return(p);
}

EXPRPTR wherenode(EXPRPTR expr,EXPRPTR exprlist,EXPRPTR file)
{

  EXPRPTR p;
  p = (EXPRPTR) calloc(1,sizeof(EXPR3));
  p->f =      F_WHERE;
  p->arg1.x = expr;
  p->arg2.x = exprlist;
  p->arg3.x = file;
  return(p);
}

EXPRPTR defnode(char *name,int argcount,EXPRPTR argnames,EXPRPTR expr,EXPRPTR file)
{

  EXPRPTR p;
  p = (EXPRPTR) calloc(1,sizeof(EXPR5));
  p->f =      F_DEFN;
  p->arg1.s = name;
  p->arg2.i = argcount;
  p->arg3.x = argnames;
  p->arg4.x = expr;
  p->arg5.x = file;
  return(p);
}

EXPRPTR declnode(char *name, EXPRPTR expr,EXPRPTR file)
{

  EXPRPTR p;
  p = (EXPRPTR) calloc(1,sizeof(EXPR3));
  p->f =      F_DECL;
  p->arg1.s = name;
  p->arg2.x = expr;
  p->arg3.x = file;
  return(p);
}


EXPRPTR identlistnode(EXPRPTR tail,char *name)
{

  EXPRPTR p;
  p = (EXPRPTR) calloc(1,sizeof(EXPR2));
  p->f =      F_IDENTLISTNODE;
  p->arg1.x = tail;
  p->arg2.s = name;
  return(p);
}

EXPRPTR listnode(EXPRPTR tail,EXPRPTR expr)
{

  EXPRPTR p;
  p = (EXPRPTR) calloc(1,sizeof(EXPR2));
  p->f =      F_LISTNODE;
  p->arg1.x = tail;
  p->arg2.x = expr;
  return(p);
}

EXPRPTR bodynode(EXPRPTR expr,EXPRPTR tail)
{

  EXPRPTR p;
  p = (EXPRPTR) calloc(1,sizeof(EXPR2));
  p->f =      F_BODY;
  p->arg1.x = expr;
  p->arg2.x = tail;
  return(p);
}

EXPRPTR exprlist2(EXPRPTR expr1,EXPRPTR expr2)
{

  EXPRPTR p1,p2;
  p1 = (EXPRPTR) calloc(1,sizeof(EXPR2));
  p2 = (EXPRPTR) calloc(1,sizeof(EXPR2));
  p1->f =      F_LISTNODE;
  p2->f =      F_LISTNODE;
  p1->arg1.x = NULL;
  p2->arg1.x = p1;
  p1->arg2.x = expr1;
  p2->arg2.x = expr2;
  return(p2);
}

EXPRPTR exprlist3(EXPRPTR expr1,EXPRPTR expr2,EXPRPTR expr3)
{

  EXPRPTR p1,p2,p3;
  p1 = (EXPRPTR) calloc(1,sizeof(EXPR2));
  p2 = (EXPRPTR) calloc(1,sizeof(EXPR2));
  p3 = (EXPRPTR) calloc(1,sizeof(EXPR2));
  p1->f =      F_LISTNODE;
  p2->f =      F_LISTNODE;
  p3->f =      F_LISTNODE;
  p1->arg1.x = NULL;
  p2->arg1.x = p1;
  p3->arg1.x = p2;
  p1->arg2.x = expr1;
  p2->arg2.x = expr2;
  p3->arg2.x = expr3;
  return(p3);
}


void yyerror(STRING a)
{
  fprintf(stderr,"%s\n",a);
}

void my_yyerror(STRING a, STRING b)
{
  int i;
  fprintf(stderr,"on line %d of file %s\n",
          in_files[in_index].in_line,in_files[in_index].in_name);
  for(i=0; i<=curr_length; i++){
    fprintf(stderr,"%c",linebuf[i]); }
  for(i=0; i<curr_index-1; i++){
    putc('.',stderr); }
  fprintf(stderr,"^\n%s %s\n",a,b);
  errcount++;
}
