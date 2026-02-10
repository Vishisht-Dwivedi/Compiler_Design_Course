%option noyywrap
%{
    #include <stdio.h>
    int charCount = 0;
    int lineCount = 0;
%}

%%
"$" {
    return 0;   
}
. {
    charCount++;
}
\n {
    lineCount++;
}
%%
int main() {
    printf("Enter Input (type $ to exit): ");
    yylex();
    printf("Number of characters = %d\n", charCount);
    printf("Number of lines = %d\n", lineCount);
    return 0;
}