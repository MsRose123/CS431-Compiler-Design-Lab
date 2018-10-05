%{
#include<stdio.h>
#include<stdlib.h>
%}
%token DIGIT LETTER


%%

stmt:A
     ;
A: LETTER B
 ;
B: LETTER B
 | DIGIT B
 | LETTER
 | DIGIT
 ;


%%


void main()
{
printf("enter string \n");
yyparse();
printf("valid\n");
exit(0);
}
void yyerror()
{
printf("invalid\n");
exit(0);
}

