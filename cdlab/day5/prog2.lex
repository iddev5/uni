%{
int flag = 0;
%}
single_line \/\/[^\n]*
begin \/\*
end \*\/
%%

{single_line} {}
{begin}       { flag = 1; }
{end}         { flag = 0; }
.|\n { if (flag == 0) printf("%s", yytext); }

%%

int main(int argc, char *argv[]) {
	extern FILE *yyin;
    yyin = fopen(argv[1], "r");    
    yylex();
    return 0;
}
