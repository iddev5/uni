%{
int alpha = 0, dig = 0, ws = 0, spl = 0, lines = 0;
%}

%%
[a-zA-Z] {alpha++;}
[0-9] {dig++;}
[ \t] {ws++;}
\n {lines++;}
. {spl++;}
%%
int main(int argc, char *argv[]) {
	extern FILE *yyin;
	yyin = fopen(argv[1], "r");
	yylex();

	printf("Alphabets = %d\nDigits = %d\nWhitespace = %d\n", alpha, dig, ws);
	printf("Special characters = %d\nNo. of lines = %d\n", spl, lines);

	return 0;
}
