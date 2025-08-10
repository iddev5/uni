#include <stdio.h>
#include <string.h>

enum { q0, q1, q2, q3, q4, q5, R };

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
        if (a) state = q1;
        else if (b) state = q3;
        break;
      case q2:
        if (a) state = q3;
        else if (b) state = q4;
        break;
      case q3:
        if (a) state = q3;
        else if (b) state = q5;
        break;
      case q4:
        if (a) state = q5;
        else if (b) state = R;
        break;
      case q5:
        if (a) state = q5;
        else if (b) state = R;
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
  if (result == q5)
    printf("The given string is accepted\n");
  else
    printf("The given string is not accepted\n");

  return 0;
}