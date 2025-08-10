#include <stdio.h>
#include <string.h>

enum { q0, q1, q2, q3, q4, q5, q6, q7, q8, q9, q10, q11, R };

static int lookup[][2] = {
  {q1, q2},
  {q4, q3},
  {q3, q5},
  {q6, q8},
  {R, q6},
  {q8, q9},
  {R, q7},
  {R, q10},
  {q7, q11},
  {q11, q9},
  {R, q10},
  {q10, q11},
  {R, R},
};

int dfa(char *string) {
  int state = q0;
  for (int i = 0; i < strlen(string); i++) {
    int b = string[i] == 'b';
    state = lookup[state][b];
  }
  return state;
}

int main() {
  char input[255];
  printf("Enter string to check: ");
  scanf("%s", input);

  int result = dfa(input);
  if (result == q10)
    printf("The given string is accepted\n");
  else
    printf("The given string is not accepted\n");

  return 0;
}