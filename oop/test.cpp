#include <iostream>
using namespace std;

void swap(int x, int y) {
  int temp;
  temp = x;
  x = y;
  y = temp;
  cout << "After swapping " << x << y << endl;
}

void swap(float a, float b) {
  a = a + b;
  b = a - b;
  a = a - b;
  cout << "After " << a << b << endl;
}

int main() {
  int x, y;
  int a, b;

  cin >> x >> y;
  cin >> a >> b;

  swap(x, y);
  swap(a, b);
}
