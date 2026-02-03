#include <stdio.h>
#include <stdlib.h>

int main() {
    char alphabet[256];
    int alphabet_exists[256];
    printf("Please enter the characters of the alphabet: ");
    scanf("%26s", alphabet);
    int i = 0;
    for(int i=0; i<256; i++){
        alphabet_exists[i]=0;
    }
    while (alphabet[i] != '\0') {
        alphabet_exists[alphabet[i]-'a']++;
        i++;
    }
    char inputStr[1024];
    printf("\nPlease enter the input string: ");
    scanf("%1024s", inputStr);
    i=0;
    int q0=1,q1=0,q2=0;
    while(inputStr[i] != '\0'){
        int idx = inputStr[i]-'a';
        if(idx>256 || idx<0){
            q2 = 1;
            break;
        }
        if(q0==1){
            q0=0;
            if(alphabet_exists[idx] > 0){
                q1=1;
            } else {
                q2 = 1;
                break;
            }
        } else if(q1==1){
            if(alphabet_exists[idx] > 0){
                q1=1;
            } else {
                q2 = 1;
                break;
            }
        } 
        i++;
    }
    if(q2==1){
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
