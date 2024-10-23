#include <iostream>
#include <math.h>
using namespace std;

class complex {
public:
  float x, y;

  void getdata();  
  void display();
  void operation(complex);
  float operation();
};

void complex::getdata() {
  cout << "Enter a complex number: ";
  cin >> x >> y;
}

void complex::display() {
  cout << x << " + " << y << "i" << endl;
}

void complex::operation(complex c) {
  x += c.x;
  y += c.y;
}

float complex::operation() {
  return sqrt(x * x + y * y);
}

int main() {
  complex c1, c2;

  c1.getdata();
  c2.getdata();

  c1.operation(c2);
  cout << "Addition result is ";
  c1.display();
  
  float mag = c1.operation();
  cout << "Magnitude of complex is " << mag << endl;
  return 0;
}
