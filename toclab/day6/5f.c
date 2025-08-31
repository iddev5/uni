#include <stdio.h>
#include <string.h>

enum { qs, q0, q1, q00, q01, q10, q11 };

int dfa1(char *string) {
  int state = qs;
  for (int i = 0; i < strlen(string); i++) {
    int a = string[i] == '0';
    
    switch (state) {
      case qs: state = a ? q0 : q1; break;
      case q0: state = a ? q00 : q01; break;
      case q1: state = a ? q10 : q11; break;
      case q00: case q01: case q10: case q11: state = state; break;
    }
  }
  return state;
}

int dfa2(char *string) {
  int state = qs;
  for (int i = 0; i < strlen(string); i++) {
    int a = string[i] == '0';
    
    switch (state) {
      case qs: state = a ? q0 : q1; break;
      case q0: state = a ? q00 : q01; break;
      case q1: state = a ? q10 : q11; break;
      case q00: state = a ? q00 : q01; break;
      case q01: state = a ? q10 : q11; break;
      case q10: state = a ? q00 : q01; break;
      case q11: state = a ? q10 : q11; break;
    }
  }

  return state;
}

int main() {
  char input[255];
  printf("Enter string to check: ");
  scanf("%s", input);

  int result = dfa1(input) == dfa2(input);
  if (result)
    printf("The given string is accepted\n");
  else
    printf("The given string is not accepted\n");

  return 0;
}
