#include <stdio.h>
#include <string.h>

enum { q0, q1 };
enum { r0, r1, r2, R };

int dfa1(char *string) {
  int state = q0;
  for (int i = 0; i < strlen(string); i++) {
    switch (state) {
      case q0:
        if (string[i] == 'a') state = q1;
        else state = q0;
        break;
      case q1:
        state = q1;
        break;
      }
  }
  return state;
}

int dfa2(char *string) {
  int state = r0;
  for (int i = 0; i < strlen(string); i++) {
    switch (state) {
      case r0:
        if (string[i] == 'a') state = r0;
        else state  = r1;
        break;
      case r1:
        if (string[i] == 'a') state = r1;
        else state = r2;
        break;
      case r2:
        if (string[i] == 'a') state = r2;
        else state = R;
      case R:
        state = R; break;
    }
  }
  return state;
}

int main() {
  char input[255];
  printf("Enter string to check: ");
  scanf("%s", input);

  int result = dfa1(input) == q1 && dfa2(input) == r2;
  if (result)
    printf("The given string is accepted\n");
  else
    printf("The given string is not accepted\n");

  return 0;
}