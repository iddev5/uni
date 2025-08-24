#include <stdio.h>
#include <ctype.h>

enum { NONE, BLANK, NUM };
enum { TNUM };

int token(char *source, int n, int s0, int *start, int *end) {
    *start = s0;
    int state = NONE;
    for (int i = s0; i < n; i++) {
        switch (state) {
            case NONE:
                if (isdigit(source[i])) state = NUM;
                else if (isblank(source[i])) state = BLANK;
                break;
            case BLANK:
                state = NONE;
                *start++;
                break;
            case NUM:
                if (isdigit(source[i])) state = NUM;
                else if (isblank(source[i])) {
                    *end = i;
                    return TNUM;
                }
        }
    }
}

void interp(char *source, int n) {
    int start, end = 0;
    token(source, n, end, &start, &end);
    printf("%d %d\n", start, end);

    token(source, n, end, &start, &end);
    printf("%d %d\n", start, end);
}

int main() {
    char source[255];
    fread(source, 255, sizeof(char), stdin);

    // printf("%d", n);
    interp(source, 255);
}