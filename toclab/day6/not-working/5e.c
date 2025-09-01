#include <stdio.h>
#include <string.h>

enum { qS, q0, q1, q0_2, q1_2, q0_3, q1_3, q0_4_0, q0_4_1, q1_4_0, q1_4_1, q0_5_0, q0_5_1, q1_5_0, q1_5_1, R };

int dfa(char *string) {
  int state = qS;
  int length = 0;
  for (int i = 0; i < strlen(string); i++) {
    int a = string[i] == '0';
    length++;
    
    switch (state) {
      case qS:   state = a ? q0 : q1; break;
      case q0:   state = q0_2; break;
      case q1:   state = q1_2; break;
      case q0_2: state = q0_3; break;
      case q1_2: state = q1_3; break;
      case q0_3: state = a ? q0_4_0 : q0_4_1; break;
      case q1_3: state = a ? q1_4_0 : q1_4_1; break;
      case q0_4_0: state = q0_5_0; break;
      case q0_4_1: state = q0_5_1; break;
      case q1_4_0: state = q1_5_0; break;
      case q1_4_1: state = q1_5_1; break;
      case q0_5_0: state = q0_5_0; break;
      case q0_5_1: state = q0_5_1; break;
      case q1_5_0: state = q1_5_0; break;
      case q1_5_1: state = q1_5_1; break;
      case R:    state = R; break;
    }
    
    // Reject if string ends with length < 5
    if (i == strlen(string) - 1 && length < 5) {
      state = R;
    }
  }
  return state;
}

int main() {
  char input[255];
  printf("Enter string to check: ");
  scanf("%s", input);

  int result = dfa(input);
  if (result == q0_5_1 || result == q1_5_0)
    printf("The given string is accepted\n");
  else
    printf("The given string is not accepted\n");

  return 0;
}
