#include <iostream>
using namespace std;

class Number {
  int n;
public:
  Number() {
    cout << "Enter a number to negate: ";
    cin >> n;
  }

  Number(int num) {
    n = num;
  }

  Number operator-() {
    return Number(-n);
  }

  void display() {
    cout << "Negated number is: " << n << endl;
  }
};

int main() {
  Number n;
  Number m = -n;
  m.display();
  return 0;
}
