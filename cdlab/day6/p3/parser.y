%{
#include <stdio.h>
#include <stdlib.h>
%}

%token NUM
%left '+' '-'
%left '*' '/'
%nonassoc UMINUS

%%

exp : exp '+' exp
	| exp '-' exp
	| exp '/' exp
	| '-' exp %prec UMINUS
	| exp '*' exp
	| '(' exp ')'
	| NUM
	;

%%

int main() {
	printf("Enter an arithmetic expression: ");
	yyparse();

	printf("Valid expression");
	return 0;
}

void yyerror() {
	printf("Invalid expression");
	exit(0);
}
