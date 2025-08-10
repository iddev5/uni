#include <stdio.h>
#include <string.h>

enum { q0, q1, q2, q3, q4, q5, q6, q7, q8, q9, q10, q11, R };

int dfa(char *string) {
  int state = q0;
  for (int i = 0; i < strlen(string); i++) {
    int a = string[i] == 'a', b = string[i] == 'b';
    switch (state) {
      case q0:
        if (a) state = q1;
        else if (b) state = q2;
        break;
      case q1:
        if (a) state = q4;
        else if (b) state = q3;
        break;
      case q2:
        if (a) state = q3;
        else if (b) state = q5;
        break;
      case q3:
        if (a) state = q6;
        else if (b) state = q8;
        break;
      case q4:
        if (a) state = R;
        else if (b) state = q6;
        break;
      case q5:
        if (a) state = q8;
        else if (b) state = q9;
        break;
      case q6:
        if (a) state = R;
        else if (b) state = q7;
        break;
      case q7:
        if (a) state = R;
        else if (b) state = q10;
        break;
      case q8:
        if (a) state = q7;
        else if (b) state = q11;
        break;
      case q9:
        if (a) state = q11;
        else if (b) state = q9;
        break;
      case q10:
        if (a) state = R;
        else if (b) state = q10;
        break;
      case q11:
        if (a) state = q10;
        else if (b) state = q11;
        break;
      case R:
        state = R;
        break;
    }
  }
  return state;
}

int main() {
  char input[255];
  printf("Enter string to check: ");
  scanf("%s", input);

  int result = dfa(input);
  if (result == q10)
    printf("The given string is accepted\n");
  else
    printf("The given string is not accepted\n");

  return 0;
}