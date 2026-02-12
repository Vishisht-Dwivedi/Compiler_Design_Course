%option noyywrap
%{
    #include <stdio.h>
%}

%%
"$" {
    return 0;
}
"int"|"void"|"main"|"return"|"static" {
    printf("\nIdentified keyword\n");
}
"!"|":"|";"|"\'"|"\""|","|"."|"?" {
    printf("\nIdentified Punctuation\n");
}
"+"|"*"|"-"|">"|"<"|"/"|"|"|"&" {
    printf("\nIdentified Operator\n");
}
[0-9]+\.[0-9]+ {
    printf("\nIdentified Float\n");
}
[0-9]+ {
    printf("\nIdentified Integer\n");
}
[a-zA-Z_][a-zA-Z0-9_]* {
    printf("\nIdentified Identifier\n");
}
[ \t\n]+    ;
. {
    printf("\nUnknown Token: %s\n", yytext);
}
%%
int main() {
    printf("Start entering the input string, to terminate type $: ");
    yylex();
    return 0;
}
