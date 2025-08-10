#include <stdio.h>
#include <string.h>

enum { q0, q1, q2, q3, R };

int dfa(char *string) {
  int state = q0;
  for (int i = 0; i < strlen(string); i++) {
    switch (state) {
      case q0:
        if (string[i] == 'a') state = q1;
        else state = q0;
        break;
      case q1:
        if (string[i] == 'a') state = q2;
        else state = q1;
        break;
      case q2:
        if (string[i] == 'a') state = q3;
        else state = q2;
        break;
      case q3:
        if (string[i] == 'a') state = R;
        else state = q3;
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
  if (result != R)
    printf("The given string is accepted\n");
  else
    printf("The given string is not accepted\n");

  return 0;
}