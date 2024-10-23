#include <iostream>
using namespace std;

int main() {
  int l, b;
  cout << "Enter length of rectangle: ";
  cin >> l;

  cout << "Enter breadth of rectangle: ";
  cin >> b;

  cout << "Area of rectangle is " << l * b << endl;
  cout << "Perimeter of rectangle is " << 2 * (l + b) << endl;

  return 0;
}
