#include <stdio.h>
 
int main() {
    char *input_str;
    printf("Enter the input string: ");
    scanf("%s", input_str);
    int i = 0;
    int q1=1, q2=0;
    while(input_str[i]!='\0'){
          if (!(input_str[i]-'0'>=0&&input_str[i]-'0'<= 9)){
            q1 = 0;
            q2 = 1;
            break;
        } else {
            q1 = 1;
        }
        i++;
    }
    if(q1 == 1){
        printf("All input values are numbers");
    } else {
        printf("Invalid String");
    }
    return 0;
}