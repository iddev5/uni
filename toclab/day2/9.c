#include <stdio.h>
#include <string.h>

enum {
  E,
  q0,
  q1,
  q2,
  q3,
};

int dfa(char *string) {
  int state = E;
  for (int i = 0; i < strlen(string); i++) {
    switch (state) {
      case E:
        if (string[i] == 'a') state = q1;
        else state = q0;
        break;
      case q0:
        if (string[i] == 'a') state = q3;
        else state = q2;
        break;
      case q1:
        if (string[i] == 'a') state = q2;
        else state = q3;
        break;
      case q2:
        if (string[i] == 'a') state = q1;
        else state = q0;
        break;
      case q3:
        if (string[i] == 'a') state = q0;
        else state = q1;
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
  if (result == q2)
    printf("The given string is accepted\n");
  else
    printf("The given string is not accepted\n");

  return 0;
}
