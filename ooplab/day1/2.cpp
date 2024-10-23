#include <iostream>
using namespace std;

int main() {
  int x = 12, y = 24;
  
  cout << "Before swapping x = " << x << " y = " << y << endl;

  x = x + y;
  y = x - y;
  x = x - y;

  cout << "After swapping x = " << x << " y = " << y;
  return 0;
}
