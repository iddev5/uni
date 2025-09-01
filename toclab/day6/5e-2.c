#include <stdio.h>
#include <string.h>

enum { q_start, q_0_1, q_0_01, q_0_011, q_0_0110, q_0_acc, q_0_rej, 
       q_1_0, q_1_00, q_1_001, q_1_0011, q_1_acc, q_1_rej, 
       q_reject };

// Explanation of states:
// q_start: initial state, no symbol read
// q_0_1, q_0_01, q_0_011, q_0_0110: states after reading first symbol=0, buffering next three
// q_0_acc, q_0_rej: accepting/rejecting states when condition checked for leftmost=0
// q_1_0, q_1_00, q_1_001, q_1_0011: similar for leftmost=1
// q_1_acc, q_1_rej: accept/reject states for leftmost=1
// q_reject: reject state for strings shorter than 5

int dfa(char *string) {
  int len = strlen(string);
  int state = q_start;

  for (int i = 0; i < len; i++) {
    char c = string[i];
    if (c != '0' && c != '1') return q_reject;  // only 0 and 1 allowed

    switch (state) {
      case q_start:
        if (c == '0') state = q_0_1;
        else state = q_1_0;
        break;
      
      // Leftmost symbol 0 path - buffering next 4 symbols
      case q_0_1:
        if (i < 4-1) state = (c == '0') ? q_0_01 : q_0_011;
        break;
      case q_0_01:
        if (i < 4-1) state = (c == '0') ? q_0_01 : q_0_011;
        break;
      case q_0_011:
        if (i < 4-1) state = (c == '0') ? q_0_0110 : q_0_011;
        break;
      case q_0_0110:
        if (i < 4-1) state = (c == '0') ? q_0_0110 : q_0_011;
        break;

      // From 5th character, check the 4th symbol from right (which was buffered state)
      // If different from leftmost symbol (0), accept, else reject.
      case q_0_0110:
      case q_0_01:
      case q_0_011:
      case q_0_1:
        if (i >= 4) {
          // The 4th symbol from right is string[i-4]
          if (string[i-4] != '0') state = q_0_acc;
          else state = q_0_rej;
        }
        break;

      case q_0_acc:
      case q_0_rej:
        // Stay same after acceptance or rejection
        state = state;
        break;

      // Leftmost symbol 1 path - similar buffering logic
      case q_1_0:
        if (i < 4-1) state = (c == '0') ? q_1_00 : q_1_001;
        break;
      case q_1_00:
        if (i < 4-1) state = (c == '0') ? q_1_00 : q_1_001;
        break;
      case q_1_001:
        if (i < 4-1) state = (c == '0') ? q_1_0011 : q_1_001;
        break;
      case q_1_0011:
        if (i < 4-1) state = (c == '0') ? q_1_0011 : q_1_001;
        break;

      case q_1_0011:
      case q_1_001:
      case q_1_00:
      case q_1_0:
        if (i >= 4) {
          if (string[i-4] != '1') state = q_1_acc;
          else state = q_1_rej;
        }
        break;

      case q_1_acc:
      case q_1_rej:
        state = state;
        break;

      default:
        state = q_reject;
        break;
    }
  }
  // If string length < 5, reject
  if (len < 5) return q_reject;
  
  // Final accepting states: q_0_acc, q_1_acc
  return state;
}

int main() {
  char input[255];
  printf("Enter string to check: ");
  scanf("%s", input);
  
  int result = dfa(input);
  if (result == q_0_acc || result == q_1_acc)
    printf("The given string is accepted\n");
  else
    printf("The given string is not accepted\n");
  return 0;
}

