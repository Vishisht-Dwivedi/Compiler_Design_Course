%{
#include <stdio.h>
#include <string.h>

/* function MUST be here */
int check_valid(char *s)
{
    int n = strlen(s);

    if(n < 5) return 1;

    for(int i=0;i<=n-5;i++)
    {
        int count=0;
        for(int j=0;j<5;j++)
            if(s[i+j]=='5') count++;

        if(count<2) return 0;
    }
    return 1;
}
%}

%%
[0-9]+  {
            if(check_valid(yytext))
                printf("ACCEPTED: %s\n",yytext);
            else
                printf("REJECTED: %s\n",yytext);
        }

\n      ;
[ \t]   ;
.       { printf("INVALID INPUT\n"); }
%%

int main()
{
    yylex();
    return 0;
}

int yywrap(){ return 1; }
