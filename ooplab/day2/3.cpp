#include <iostream>
#include <string.h>
using namespace std;

bool pallindrome(char *str, int n) {
  for (int i = 0; i < n/2 + 1; i++) {
    if (str[i] != str[n - i - 1])
      return false;
  }
  return true;
}

bool pallindrome(int num) {
  int rev = 0, numc = num;
  while (num > 0) {
    rev = (rev * 10) + (num % 10);
    num /= 10;
  }
  return rev == numc;
}

int main() {
  int num;
  char str[32];

  cout << "Enter a number to check: ";
  cin >> num;

  cout << "Enter a string to check (32-chars max): ";
  cin >> str;
  
  cout << "Number is pallindrome: " << pallindrome(num) << endl;
  cout << "String is pallindrome: " << pallindrome(str, strlen(str)) << endl;
}
