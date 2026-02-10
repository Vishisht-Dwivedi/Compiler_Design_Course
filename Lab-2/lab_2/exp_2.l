%option noyywrap
%{
    #include <stdio.h>
%}
%%
"$" {
    return 0;
}
[ ]+ {
    printf(" ");
}
.|\n {
    printf("%s", yytext);
}
%%
int main() {
    printf("Enter Input (type $ to exit): ");
    yylex();
    return 0;
}