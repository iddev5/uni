#include <stdio.h>
#include <string.h>

enum { q0, q1, q2, q3, q4, q5, q6, q7, R };

int dfa(char *string) {
  int state = q0;
  for (int i = 0; i < strlen(string); i++) {
    int a = string[i] == 'a';
    
    switch (state) {
      case q0: state = a ? q1 : q0; break;
      case q1: state = a ? q2 : q0; break;
      case q2: state = a ? q3 : R;  break;
      case q3: state = a ? R  : q4; break;
      case q4: state = a ? q5 : q4; break;
      case q5: state = a ? q6 : q4; break;
      case q6: state = a ? q7 : R;  break;
      case q7: state = a ? R  : q7; break;
      case R : state = R; break;
    }
  }
  return state;
}

int main() {
  char input[255];
  printf("Enter string to check: ");
  scanf("%s", input);

  int result = dfa(input);
  if (result == q7)
    printf("The given string is accepted\n");
  else
    printf("The given string is not accepted\n");

  return 0;
}
