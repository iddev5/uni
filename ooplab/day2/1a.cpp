#include <iostream>
#include <math.h>
using namespace std;

class complex {
public:
  float x, y;

  void getdata();  
  complex operation(complex);
  float operation();
};

void complex::getdata() {
  cout << "Enter a complex number: ";
  cin >> x >> y;
}

complex complex::operation(complex c) {
  complex res;
  res.x = x + c.x;
  res.y = y + c.y;
  return res;
}

float complex::operation() {
  return sqrt(x * x + y * y);
}

int main() {
  complex c1, c2;

  c1.getdata();
  c2.getdata();

  complex res = c1.operation(c2);
  cout << "Addition result is " << res.x << " + " << res.y << "i" << endl;
  
  float mag = c1.operation();
  cout << "Magnitude of complex is " << mag << endl;
  return 0;
}
