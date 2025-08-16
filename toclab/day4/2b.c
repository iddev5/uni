#include <stdio.h>
#include <string.h>

enum { q0, q1, q2, q3, q4, q5, q6, R };

int dfa(char *string) {
  int state = q0;
  for (int i = 0; i < strlen(string); i++) {
    int a = string[i] == 'a', b = string[i] == 'b';
    switch (state) {
      case q0: state = a ? q1 : R; break;
      case q1: state = a ? R : q2; break;
      case q2: state = a ? R : q3; break;
      case q3: state = a ? q4 : q3; break;
      case q4: state = a ? q5 : R; break;
      case q5: state = a ? q6 : R; break;
      case q6: state = a ? q6 : R; break;
      case R: state = R; break;
    }
  }
  return state;
}

int main() {
  char input[255];
  printf("Enter string to check: ");
  scanf("%s", input);

  int result = dfa(input);
  if (result == q6)
    printf("The given string is accepted\n");
  else
    printf("The given string is not accepted\n");

  return 0;
}