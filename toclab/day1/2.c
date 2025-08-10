#include <stdio.h>
#include <string.h>

enum {
  q0,
  q1,
};

int dfa(char *string) {
  int state = q0;
  for (int i = 0; i < strlen(string); i++) {
    switch (state) {
      case q0:
        if (string[i] == '0') state = q1;
        else state = q0;
        break;
      case q1:
        if (string[i] == '0') state = q0;
        else state = q1;
        break;
    }
  }
  return state;
}

int main() {
  char input[255];
  printf("Enter string to check: ");
  scanf("%s", input);

  int result = dfa(input);
  if (result == q0)
    printf("The given string is accepted\n");
  else
    printf("The given string is not accepted\n");

  return 0;
}
