#include <stdio.h>
#include <string.h>

enum { q0, A1, A2, A3, A4, B1, B2, B3, B4, ACC, REJ };

int dfa(char *string) {
    int state = q0;
    int len = strlen(string);

    for (int i = 0; i < len; i++) {
        char c = string[i];
        if (c != '0' && c != '1') return REJ;

        switch (state) {
            case q0: // first symbol
                state = (c == '0') ? A1 : B1;
                break;

            // ==== First symbol was 0 (A states) ====
            case A1: state = A2; break;
            case A2: state = A3; break;
            case A3: state = (c == '0') ? REJ : ACC; break; // 4th from right = 0 → reject
            case A4: state = (c == '0') ? REJ : ACC; break;

            // ==== First symbol was 1 (B states) ====
            case B1: state = B2; break;
            case B2: state = B3; break;
            case B3: state = (c == '1') ? REJ : ACC; break; // 4th from right = 1 → reject
            case B4: state = (c == '1') ? REJ : ACC; break;

            case ACC: state = ACC; break; // once accepted, stay
            case REJ: state = REJ; break; // once rejected, stay
        }
    }

    // Length check
    if (len < 5) return REJ;
    return state;
}

int main() {
    char input[255];
    printf("Enter string to check: ");
    scanf("%s", input);

    int result = dfa(input);

    if (result == ACC)
        printf("The given string is accepted\n");
    else
        printf("The given string is not accepted\n");

    return 0;
}

