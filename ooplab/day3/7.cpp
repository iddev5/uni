#include <iostream>
using namespace std;

class GCD {
  int x, y;
public:
  void getdata() {
    cout << "Enter first number: ";
    cin >> x;

    cout << "Enter second number: ";
    cin >> y;
  }
  
  void display() {
    int min = x > y ? y : x;

    for (int i = min; i > 0; i--) {
      if (x % i == 0 && y % i == 0) {
        cout << "GCD is " << i << endl;
        return;
      }
    }
  }
};

int main() {
  GCD gcd;
  gcd.getdata();
  gcd.display();
  return 0;
}