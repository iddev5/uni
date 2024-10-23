#include <iostream>
using namespace std;

class Cube {
  int n;
public:
  void getdata() {
    cout << "Enter the number upto which cube is to be calculated: ";
    cin >> n;
  }

  friend void display_cubes(Cube&);
};

void display_cubes(Cube &c) {
  cout << "Cubes upto " << c.n << " are: ";
  // Take into account both positive and negative integers
  int mul = c.n > 0 ? 1 : -1;
  for (int i = 1 * mul; i * mul <= c.n * mul; i += mul)
    cout << i * i * i << " ";
  cout << endl;
}

int main() {
  Cube c;
  c.getdata();
  display_cubes(c);
}
