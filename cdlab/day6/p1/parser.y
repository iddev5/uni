%{
#include <stdio.h>
#include <stdlib.h>
%}

%token NUM ID
%left '+' '-'
%left '*' '/'
%nonassoc UMINUS

%%

exp : exp '+' exp
	| exp '-' exp
	| exp '/' exp
	| exp '*' exp
	| '-' exp %prec UMINUS
	| '(' exp ')'
	| NUM
	| ID
	;

%%

int main() {
	printf("Enter an expression: ");
	yyparse();

	printf("Valid expression");
	return 0;
}

void yyerror() {
	printf("Invalid expression");
	exit(0);
}
