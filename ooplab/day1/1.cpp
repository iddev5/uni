#include <iostream>
using namespace std;

int main() {
  int x, y, temp;
  cout << "Enter first number: ";
  cin >> x;

  cout << "Enter second number: ";
  cin >> y;
  
  cout << "Before swapping x = " << x << " y = " << y << endl;

  temp = x;
  x = y;
  y = temp;

  cout << "After swapping x = " << x << " y = " << y;
  return 0;
}
