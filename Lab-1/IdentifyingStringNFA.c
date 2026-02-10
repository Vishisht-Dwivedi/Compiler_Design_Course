#include <stdio.h>
#include <string.h>

#define MAX 256

int main() {
    char alphabet[MAX];
    int alphabet_exists[256] = {0};
    printf("Enter alphabet: ");
    scanf("%255s", alphabet);
    for (int i = 0; alphabet[i] != '\0'; i++) {
        alphabet_exists[(unsigned char)alphabet[i]] = 1;
    }
    char input[MAX];
    printf("Enter input string: ");
    scanf("%255s", input);
    int q0 = 1;
    int q1 = 0;

    for (int i = 0; input[i] != '\0'; i++) {
        int c = (unsigned char)input[i];
        if (!alphabet_exists[c]) {
            q0 = q1 = 0;
            break;
        }
        int new_q0 = 0;
        int new_q1 = 0;
        if (q0){
            new_q0 = 1;
            new_q1 = 1;
        }
        if (q1){
            new_q1 = 1;
        }
        q0 = new_q0;
        q1 = new_q1;
    }
    if (q1)
        printf("Valid String\n");
    else
        printf("Invalid String\n");
    return 0;
}
