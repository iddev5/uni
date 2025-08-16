#include <stdio.h>
#include <string.h>

enum { q0, q1, q2};

int dfa(char *string) {
  int state = q0;
  for (int i = 0; i < strlen(string); i++) {
    int a = string[i] == 'a', b = string[i] == 'b';
    switch (state) {
      case q0: state = a ? q1 : q0; break;
      case q1: state = a ? q2 : q1; break;
      case q2: state = a ? q0 : q2; break;
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