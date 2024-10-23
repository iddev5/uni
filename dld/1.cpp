#include <iostream>
#include <cstring>
using namespace std;

int main() {
  char bin[32], gray[32];
  cout << "Enter binary number: ";
  cin >> bin;

  gray[0] = bin[0];
  for (int i = 1; i < strlen(bin); i++) {
    gray[i] = (bin[i - 1] - '0') ^ (bin[i] - '0') + '0';
  }

  cout << gray << endl;

  return 0;
  
}
