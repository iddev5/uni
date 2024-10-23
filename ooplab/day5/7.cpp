#include <iostream>
using namespace std;

class Number {
  int n;
public:
  Number() {
    cout << "Enter a number to increment (postfix): ";
    cin >> n;
  }

  Number(int num) {
    n = num;
  }

  Number operator++(int) {
    return Number(n++);
  }

  int get() {
    return n;
  }
};

int main() {
  Number n;
  Number m = n++;
  cout << "The number became: " << n.get() << endl;
  cout << "The return value of operator: " << m.get() << endl;
  return 0;
}
