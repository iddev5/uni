#include <stdio.h>
#include <string.h>

enum { q0, q1, q2, q3, q4, q5, q6, q7, q8, R };

int dfa(char *string) {
  int state = q0;
  for (int i = 0; i < strlen(string); i++) {
    int a = string[i] == '0';
    
    switch (state) {
      case q0: state = a ? q1 : q5; break;
      case q1: state = a ? q2 : R; break;
      case q2: state = a ? q3 : R; break;
      case q3: state = a ? q3 : q4; break;
      case q4: state = a ? q3 : q4; break;
      case q5: state = a ? R : q6; break;
      case q6: state = a ? R : q7; break;
      case q7: state = a ? q8 : q7; break;
      case q8: state = a ? q8 : q7; break;
    }
  }
  return state;
}

int main() {
  char input[255];
  printf("Enter string to check: ");
  scanf("%s", input);

  int result = dfa(input);
  if (result == q4 || result == q8)
    printf("The given string is accepted\n");
  else
    printf("The given string is not accepted\n");

  return 0;
}
