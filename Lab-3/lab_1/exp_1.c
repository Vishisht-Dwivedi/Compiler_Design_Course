#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 20
char productions[MAX][MAX];
char first[MAX][MAX], follow[MAX][MAX];
int n;
void addToSet(char *set, char c) {
    if (!strchr(set, c)) {
        int len = strlen(set);
        set[len] = c;
        set[len + 1] = '\0';
    }
}
void findFirst(char c, int index) {
    if (!isupper(c)) {
        addToSet(first[index], c);
        return;
    }

    for (int i = 0; i < n; i++) {
        if (productions[i][0] == c) {
            if (productions[i][2] == '$') {
                addToSet(first[index], '$');
            } else {
                findFirst(productions[i][2], index);
            }
        }
    }
}
void findFollow(char c, int index) {
    if (productions[0][0] == c)
        addToSet(follow[index], '$');
    for (int i = 0; i < n; i++) {
        for (int j = 2; j < strlen(productions[i]); j++) {
            if (productions[i][j] == c) {
                if (productions[i][j + 1] != '\0') {
                    if (!isupper(productions[i][j + 1])) {
                        addToSet(follow[index], productions[i][j + 1]);
                    } else {
                        int k;
                        for (k = 0; k < n; k++) {
                            if (productions[k][0] == productions[i][j + 1]) {
                                strcat(follow[index], first[k]);
                            }
                        }
                    }
                } else {
                    if (productions[i][0] != c)
                        findFollow(productions[i][0], index);
                }
            }
        }
    }
}
void removeLeftRecursion() {
    printf("\nGrammar after removing left recursion:\n");
    for (int i = 0; i < n; i++) {
        char A = productions[i][0];
        char alpha[MAX][MAX], beta[MAX][MAX];
        int a = 0, b = 0;
        char *rhs = productions[i] + 2;
        char *token = strtok(rhs, "|");
        while (token != NULL) {
            if (token[0] == A) {
                strcpy(alpha[a++], token + 1);
            } else {
                strcpy(beta[b++], token);
            }
            token = strtok(NULL, "|");
        }
        if (a == 0) {
            printf("%s\n", productions[i]);
        } else {
            printf("%c -> ", A);
            for (int j = 0; j < b; j++) {
                printf("%s%c' ", beta[j], A);
                if (j != b - 1) printf("| ");
            }
            printf("\n");
            printf("%c' -> ", A);
            for (int j = 0; j < a; j++) {
                printf("%s%c' ", alpha[j], A);
                if (j != a - 1) printf("| ");
            }
            printf("| ε\n");
        }
    }
}

int main() {
    printf("Enter number of productions: ");
    scanf("%d", &n);
    printf("Enter productions (Example: A=Ab|c):\n");
    for (int i = 0; i < n; i++) {
        scanf("%s", productions[i]);
        first[i][0] = '\0';
        follow[i][0] = '\0';
    }
    removeLeftRecursion();
    for (int i = 0; i < n; i++) {
        findFirst(productions[i][0], i);
    }
    for (int i = 0; i < n; i++) {
        findFollow(productions[i][0], i);
    }
    printf("\nFIRST sets:\n");
    for (int i = 0; i < n; i++) {
        printf("FIRST(%c) = { %s }\n", productions[i][0], first[i]);
    }
    printf("\nFOLLOW sets:\n");
    for (int i = 0; i < n; i++) {
        printf("FOLLOW(%c) = { %s }\n", productions[i][0], follow[i]);
    }
    return 0;
}