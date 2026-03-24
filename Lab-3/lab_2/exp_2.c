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
int commonPrefix(char *a, char *b) {
    int i = 0;
    while (a[i] && b[i] && a[i] == b[i]) i++;
    return i;
}
void leftFactoring() {
    printf("\nGrammar after Left Factoring:\n");

    for (int i = 0; i < n; i++) {
        char A = productions[i][0];
        char *rhs = productions[i] + 2;

        char parts[MAX][MAX];
        int count = 0;

        char *token = strtok(rhs, "|");
        while (token != NULL) {
            strcpy(parts[count++], token);
            token = strtok(NULL, "|");
        }

        int prefixLen = commonPrefix(parts[0], parts[1]);

        if (count > 1 && prefixLen > 0) {
            char prefix[MAX];
            strncpy(prefix, parts[0], prefixLen);
            prefix[prefixLen] = '\0';

            printf("%c -> %s%c'\n", A, prefix, A);

            printf("%c' -> ", A);
            for (int j = 0; j < count; j++) {
                printf("%s", parts[j] + prefixLen);
                if (j != count - 1) printf(" | ");
            }
            printf("\n");
        } else {
            printf("%s\n", productions[i]);
        }
    }
}
void findFirst(char c, int index) {
    if (!isupper(c)) {
        addToSet(first[index], c);
        return;
    }
    for (int i = 0; i < n; i++) {
        if (productions[i][0] == c) {
            findFirst(productions[i][2], index);
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
                    }
                } else {
                    if (productions[i][0] != c)
                        findFollow(productions[i][0], index);
                }
            }
        }
    }
}

int main() {
    printf("Enter number of productions: ");
    scanf("%d", &n);
    printf("Enter productions (Example: A=ab|ac):\n");
    for (int i = 0; i < n; i++) {
        scanf("%s", productions[i]);
        first[i][0] = '\0';
        follow[i][0] = '\0';
    }
    leftFactoring();
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