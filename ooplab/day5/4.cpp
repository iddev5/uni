#include <iostream>
using namespace std;

class Complex {
  int re, im;
public:
  Complex(int x, int y) {
    re = x; im = y;
  }

  void display() {
    cout << re << " + " << im << "i" << endl;
  }

  Complex operator-(Complex &);
};

Complex Complex::operator-(Complex &c) {
  return Complex(re - c.re, im - c.im);
}

int main() {
  int r1, r2, i1, i2;
  cout << "Enter real and imaginary part of first complex: ";
  cin >> r1 >> i1;
  
  cout << "Enter real and imaginary part of second complex: ";
  cin >> r2 >> i2;

  Complex c1(r1, i1), c2(r2, i2);

  cout << "First number is ";
  c1.display();
  cout << "Second number is ";
  c2.display();
  
  Complex c3 = c1 - c2;

  cout << "After subtraction: ";
  c3.display();

  return 0;
}
