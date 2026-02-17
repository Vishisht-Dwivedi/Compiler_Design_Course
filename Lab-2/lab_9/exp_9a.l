%{
#include <stdio.h>
%}

%%
[0-9]*00 { printf("ACCEPTED: %s\n", yytext); }
[0-9]+ { printf("REJECTED: %s\n", yytext); }
\n            ;
%%

int main(){ yylex(); return 0; }
int yywrap(){ return 1; }
