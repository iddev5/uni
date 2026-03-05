%{
int words=0;
%}
%%
[^ \n]* {words++;}
. {}
%%

int main(int argc, char **argv) {
	extern FILE *yyin;
	yyin = fopen(argv[1], "r");
	yylex();

	printf("No of words = %d\n", words);

	return 0;
}
