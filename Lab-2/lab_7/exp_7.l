%{
#include <stdio.h>
%}

DIGIT [0-9]
NUMBER {DIGIT}+(\.{DIGIT}+)?

%%
{NUMBER} { 
    printf("NUMBER(%s)\n", yytext); 
}
"+" { 
    printf("PLUS\n"); 
}
"-" { 
    printf("MINUS\n"); 
}
"*" { 
    printf("MULTIPLY\n"); 
}
"/" { 
    printf("DIVIDE\n"); 
}
"(" { 
    printf("LPAREN\n"); 
}
")" { 
    printf("RPAREN\n"); 
}
[ \t\n] ;
. { 
    printf("INVALID(%s)\n", yytext); 
}
%%

int main() {
    printf("Enter expression:\n");
    yylex();
    return 0;
}

int yywrap(){ return 1; }