#include <stdio.h>
#include <string.h>

enum { q0, q1, q2, Rq };
enum { r0, r1, r2, r3 };

int dfa1(char *string) {
  int state = q0;
  for (int i = 0; i < strlen(string); i++) {
    int a = string[i] == 'a', b = string[i] == 'b';
    switch (state) {
      case q0:
        if (a) state = q1;
        else if (b) state = q0;
        break;
      case q1:
        if (a) state = q2;
        else if (b) state = q1;
        break;
      case q2:
        if (a) state = Rq;
        else if (b) state = q2;
        break;
      case Rq:
        state = Rq;
        break;
    }
  }
  return state;
}

int dfa2(char *string) {
  int state = r0;
  for (int i = 0; i < strlen(string); i++) {
    int a = string[i] == 'a', b = string[i] == 'b';
    switch (state) {
      case r0:
        if (a) state = r0;
        else if (b) state = r1;
        break;
      case r1:
        if (a) state = r1;
        else if (b) state = r2;
        break;
      case r2:
        if (a) state = r2;
        else if (b) state = r3;
        break;
      case r3:
        state = r3;
        break;
    }
  }
  return state;
}

int main() {
  char input[255];
  printf("Enter string to check: ");
  scanf("%s", input);

  int r1 = dfa1(input) == q2, r2 = dfa2(input) == r3;
  if (r1 * r2)
    printf("The given string is accepted\n");
  else
    printf("The given string is not accepted\n");

  return 0;
}