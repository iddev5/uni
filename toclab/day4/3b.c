#include <stdio.h>
#include <string.h>

enum { q0, q1, q2, q3, q4 };

int dfa(char *string) {
  int state = q0;
  for (int i = 0; i < strlen(string); i++) {
    int a = string[i] == 'a', b = string[i] == 'b';
    switch (state) {
      case q0: state = q1; break;
      case q1: state = q2; break;
      case q2: state = q3; break;
      case q3: state = q4; break;
      case q4: state = q0; break;
    }
  }
  return state;
}

int main() {
  char input[255];
  printf("Enter string to check: ");
  scanf("%s", input);

  int result = dfa(input);
  if (result != q0)
    printf("The given string is accepted\n");
  else
    printf("The given string is not accepted\n");

  return 0;
}