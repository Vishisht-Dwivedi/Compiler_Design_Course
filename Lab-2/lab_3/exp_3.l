%option noyywrap
%{
    #include <stdio.h>
    FILE *fp;
%}
%%
"$" {
    return 0;
}
[ ]+ {
    fprintf(fp," ");
}
.|\n {
    fprintf(fp,"%s", yytext);
}
%%
int main() {
    fp = fopen("exp_3.txt", "w");
    if (fp == NULL){
        printf("File error\n");
        return 1;
    }
    yylex();
    fclose(fp);
    return 0;
}