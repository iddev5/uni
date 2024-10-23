#include <iostream>
#include <math.h>
using namespace std;

struct complex {
  float x, y;
};

struct complex operation(struct complex c1, struct complex c2) {
  struct complex res;
  res.x = c1.x + c2.x;
  res.y = c1.y + c2.y;
  return res;
}

float operation(struct complex c) {
  return sqrt(c.x * c.x + c.y * c.y);
}

int main() {
  struct complex c1, c2;

  cout << "Enter first complex number: ";
  cin >> c1.x >> c1.y;

  cout << "Enter second complex number: ";
  cin >> c2.x >> c2.y;

  struct complex res = operation(c1, c2);
  cout << "Addition result is " << res.x << " + " << res.y << "i" << endl;
  
  float mag = operation(c1);
  cout << "Magnitude of complex is " << mag << endl;
  return 0;
}
