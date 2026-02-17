%option noyywrap
%{
    #include <stdio.h>
%}

%%
"$" {
    return 0;
}
[0-9]+\.[0-9]+ {
    printf("\nIdentified Float\n");
}
[ \t\n]+    ;
. {
    printf("\nUnknown Token: %s\n", yytext);
}
%%
int main() {
    printf("Start entering the input, to terminate type $: ");
    yylex();
    return 0;
}
