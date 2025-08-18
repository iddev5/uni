#include <stdio.h>
#include <string.h>

enum { S, a1, a2, a3, a4, b1, b2, b3, b4, R };

int dfa(char *string) {
  int state = S;
  for (int i = 0; i < strlen(string); i++) {
    int a = string[i] == 'a';
    
    switch (state) {
      case S : state = a ? a1 : b1; break;
      case a1: state = a ? a2 : b1; break;
      case a2: state = a ? a3 : R;  break;
      case a3: state = a ? a4 : R;  break;
      case a4: state = a ? a4 : b1; break;
      case b1: state = a ? a1 : b2; break;
      case b2: state = a ? R  : b3; break;
      case b3: state = a ? R  : b4; break;
      case b4: state = a ? a1 : b4; break;  
    }
  }
  return state;
}

int main() {
  char input[255];
  printf("Enter string to check: ");
  scanf("%s", input);

  int result = dfa(input);
  if (result == S || result == a1 || result == a4 || result == b1 || result == b4)
    printf("The given string is accepted\n");
  else
    printf("The given string is not accepted\n");

  return 0;
}
