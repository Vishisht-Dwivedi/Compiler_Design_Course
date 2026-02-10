#include <stdio.h>

int main() {
    char s[256];
    scanf("%255s", s);
    int q0=1, q1=0;
    for(int i=0; s[i]!='\0'; i++){
        int new_q0 = 0, new_q1 = 0;
        if(q0){
            if(s[i] == '0') new_q0 = 1;
            if(s[i] == '1') {
                new_q0 = 1;
                new_q1 = 1;
            }
        }
        if(q1){
            if(s[i] == '1') new_q1 = 1;
        }
        q0=new_q0;
        q1=new_q1;
    }
    if(q1)
        printf("Accepted\n");
    else
        printf("Rejected\n");
    return 0;
}
