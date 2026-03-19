%{
#include "parser.tab.h"
%}

%%

[_a-zA-Z][_a-zA-Z0-9]* return ID;

[0-9]+ return NUM;

. return yytext[0];

\n return 0;

%%
