%{
#include <stdio.h>
%}

DIGIT   [0-9]
LETTER  [a-zA-Z]
ID      {LETTER}({LETTER}|{DIGIT})*
%%

"if" { printf("KEYWORD_IF\n"); }
"else" { printf("KEYWORD_ELSE\n"); }
"while" { printf("KEYWORD_WHILE\n"); }

{DIGIT}+ { printf("INTEGER(%s)\n", yytext); }
{ID} { printf("IDENTIFIER(%s)\n", yytext); }

"+" { 
    printf("PLUS\n"); 
}
"-" { 
    printf("MINUS\n"); 
}
"*" { 
    printf("MULT\n"); 
}
"/" { 
    printf("DIV\n"); 
}
"=" { 
    printf("ASSIGN\n"); 
}
";" { 
    printf("SEMICOLON\n"); 
}
[ \t\n] ;
. { 
    printf("UNKNOWN(%s)\n", yytext); 
}

%%

int main(){
    yylex();
    return 0;
}

int yywrap(){ return 1; }
