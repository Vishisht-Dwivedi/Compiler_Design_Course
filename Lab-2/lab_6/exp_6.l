%{
#include <stdio.h>
    FILE *yyin;
    FILE *yyout;
%}

%%
[ \t\n\r\f\v]+ { 
    fprintf(yyout, " ");
}
. { 
    fputc(yytext[0], yyout); 
}
%%

int main()
{
    yyin = fopen("input.txt", "r");
    if(!yyin){
        printf("Cannot open input file\n");
        return 1;
    }
    yyout = fopen("output.txt", "w");
    if(!yyout){
        printf("Cannot create output file\n");
        return 1;
    }
    yylex();
    fclose(yyin);
    fclose(yyout);
    printf("File copied successfully into output.txt (spaces normalized)\n");
    return 0;
}

int yywrap(){
    return 1;
}
