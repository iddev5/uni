%{

%}
first [a-zA-Z_]
next [a-zA-Z0-9_]
%%
{first}{next}* {printf("Valid identifier: %s\n", yytext);}
.* {printf("Invalid identifier: %s\n", yytext);}
%%

int main(int argc, char *argv[]) {
	extern FILE *yyin;
	yyin = fopen(argv[1], "r");
	yylex();
	return 0;
}
