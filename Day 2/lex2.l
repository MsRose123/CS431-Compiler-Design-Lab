%{
	#include<stdio.h>
%}

digit [0-9]
letter [a-zA-Z]

%%

[()+!#<>.;"%,{}=-]
if|else|int|float|void|char|include|stdio.h|printf|main
"({letter}|{digit})"
{digit}({digit}|{letter})*

{letter}({letter}|{digit})*  printf("%s\n",yytext);

%%

void main()
{

yyin=fopen("input.txt","r");
printf("Identifiers:\n");
yylex();

}
