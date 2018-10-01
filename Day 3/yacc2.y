%{
	#include<stdio.h>
%}

%token NUM NL

%left '+' '-'
%left '*' '/'
%left '(' ')'

%%
S:	E NL	{printf("Valid\n");}
E:	E '+' E	
 |	E '-' E 
 |	E '*' E	
 |	E '/' E 
 |	'(' E ')'	
 |	NUM	
 ;
%%
void main()
{
	yyparse();
}
int yyerror()
{
	printf("Invalid\n");
}
