#include <stdio.h>
#include <string.h>

enum { qS, q0, q1, q00, q01, q10, q11, q001, q010, q011, q100, q101, q110, q111, R };

int dfa(char *string) {
  int state = qS;
  for (int i = 0; i < strlen(string); i++) {
    int a = string[i] == '0';
    
    switch (state) {
      case qS:   state = a ? q0 : q1; break;
      case q0:   state = a ? q00 : q01; break;
      case q1:   state = a ? q10 : q11; break;
      case q00:  state = a ? R : q001; break;
      case q01:  state = a ? q010 : q011; break;
      case q10:  state = a ? q100 : q101; break;
      case q11:  state = a ? q110 : q111; break;
      case q001: state = a ? R : q011; break;
      case q010: state = a ? q100 : q101; break;
      case q011: state = a ? q110 : q111; break;
      case q100: state = a ? R : q101; break;
      case q101: state = a ? q110 : q111; break;
      case q110: state = a ? R : q111; break;
      case q111: state = a ? q110 : q111; break;
      case R:    state = R; break;
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
