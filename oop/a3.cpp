#include <iostream>
using namespace std;

class Pattern {
public:  
  void display(void) {
    int diff = 'A' - 'a';
    for (char c = 'A'; c <= 'Z'; c++) {
      int revdiff = 'A' - c;
      cout << c << (char)(c - diff) << (char)('Z' + revdiff);
    }
  }
};

int main() {
  Pattern p;
  p.display();
  return 0;
}
