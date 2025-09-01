#include <stdio.h>
#include <string.h>

enum {
  q0, q1, q2, q3, q4, q5, q6, q7, q8, q9,
  q10, q11, q12, q13, q14, q15, q16, q17, q18, q19,
  q20, q21, q22, q23, q24, q25, q26, q27, q28, q29,
  q30, q31, q32,
  R
};

int dfa(char *string) {
  int state = q0; 

  for (int i = 0; i < (int)strlen(string); ++i) {
    int a = (string[i] = '0');

    switch (state) {
      case q0:  state = a ? q1  : q2 ; break;
      case q1:  state = a ? q1  : q3 ; break;
      case q2:  state = a ? q4  : q2 ; break;
      case q3:  state = a ? q5  : q6 ; break;
      case q4:  state = a ? q7  : q8 ; break;
      case q5:  state = a ? q9  : q10; break;
      case q6:  state = a ? q11 : q12; break;
      case q7:  state = a ? q13 : q14; break;
      case q8:  state = a ? q15 : q16; break;
      case q9:  state = a ? q17 : q18; break;
      case q10: state = a ? q19 : q20; break;
      case q11: state = a ? q21 : q22; break;
      case q12: state = a ? q23 : q24; break;
      case q13: state = a ? q25 : q26; break;
      case q14: state = a ? q27 : q28; break;
      case q15: state = a ? q29 : q30; break;
      case q16: state = a ? q31 : q32; break;

      case q17: state = a ? q1  : q3 ; break;
      case q18: state = a ? q5  : q6 ; break;
      case q19: state = a ? q9  : q10; break;
      case q20: state = a ? q11 : q12; break;
      case q21: state = a ? q17 : q18; break;
      case q22: state = a ? q19 : q20; break;
      case q23: state = a ? q21 : q22; break;
      case q24: state = a ? q23 : q24; break;

      case q25: state = a ? q25 : q26; break;
      case q26: state = a ? q27 : q28; break;
      case q27: state = a ? q29 : q30; break;
      case q28: state = a ? q31 : q32; break;
      case q29: state = a ? q13 : q14; break;
      case q30: state = a ? q15 : q16; break;
      case q31: state = a ? q7  : q8 ; break;
      case q32: state = a ? q4  : q2 ; break;

      default:
        state = R;
    }
  }

  return state;
}

int main() {
  char input[256];
  printf("Enter binary string: ");
  scanf("%s", input);

  int result = dfa(input);
  if (result >= q17 && result <= q32)
    printf("The given string is accepted\n");
  else
    printf("The given string is not accepted\n");

  return 0;
}

