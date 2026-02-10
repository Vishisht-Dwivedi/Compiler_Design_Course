#include <stdio.h>
#include <stdlib.h>
int main() {
    char *inputStr;
    printf("Please enter the input string: ");
    scanf("%s", inputStr);
    int i=0;
    int q0=1,q1=0,q3=0;
    while(inputStr[i] != '\0'){
        int idx = inputStr[i]-'a';
        if(q0==1){
            if(idx>=0 && idx<26){
                q1=1;
                q0=0;
            } else if(inputStr[i]=='_'){
                q1=1;
                q0=0;
            } else {
                q3=1;
                q0=0;
                break;
            }
        } else {
            if(!(idx>=0 && idx<26 || inputStr[i]=='_')){
                idx = inputStr[i]-'0';
                if(!(idx>=0 && idx<=9)){
                    q3=1;
                    q0=0;
                    break;
                }
            }
        }
        i++;
    }
    if(q3==1){
        printf("\nInvalid String");
    } else {
        if(q1==1){
            printf("\nValid String");
        } else {
            printf("\nInvalid String");
        }
    }
    return 0;
}