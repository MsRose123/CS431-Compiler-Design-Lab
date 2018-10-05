%{
 #include<stdio.h>
%}

%token ID NUMBER
%left '+' '-'
%left '*' '/'
%left '(' ')'

%%


stmt:expr
    ;
expr: expr '+' expr
    | expr '-' expr
    | expr '*' expr
    | expr '/' expr
    | '(' expr ')'
    | NUMBER
    | ID
    ;
%%

void main()
{
printf("enter expr : \n");
yyparse();
printf("valid exp\n");
exit(0);
}
void yyerror()
{
  printf("invalid exp\n");

}
