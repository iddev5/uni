#include <stdio.h>
#include <string.h>

enum {
  q_start,
  q_0, q_1,
  q_00, q_01, q_10, q_11,
  q_000, q_001, q_010, q_011, q_100, q_101, q_110, q_111,
  q_dead
};

int dfa(char *string) {
  int state = q_start;
  for (int i = 0; i < strlen(string); i++) {
    char ch = string[i];
    int a = (ch == '0');

    switch (state) {
      case q_start: state = a ? q_0   : q_1;   break;
      case q_0:     state = a ? q_00  : q_01;  break;
      case q_1:     state = a ? q_10  : q_11;  break;

      case q_00:    state = a ? q_000 : q_001; break;
      case q_01:    state = a ? q_010 : q_011; break;
      case q_10:    state = a ? q_100 : q_101; break;
      case q_11:    state = a ? q_110 : q_111; break;

      case q_000:   state = q_dead;            break;
      case q_001:   state = a ? q_dead : q_011; break;
      case q_010:   state = a ? q_dead : q_101; break;
      case q_011:   state = a ? q_110 : q_111;  break;
      case q_100:   state = a ? q_dead : q_001; break;
      case q_101:   state = a ? q_010 : q_011;  break;
      case q_110:   state = a ? q_100 : q_101;  break;
      case q_111:   state = a ? q_110 : q_111;  break;

      case q_dead:  state = q_dead;            break;
    }
    if (state == q_dead) break;
  }
  return state;
}

int main() {
  char input[255];
  printf("Enter string to check: ");
  scanf("%254s", input);

  int result = dfa(input);
  if (result != q_dead)
    printf("The given string is accepted\n");
  else
    printf("The given string is not accepted\n");

  return 0;
}
