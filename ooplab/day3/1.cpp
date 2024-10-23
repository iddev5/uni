#include <iostream>
using namespace std;

class NaturalNumbers {
public:
  void display() {
    for (int i = 1; i <= 10; i++) {
      cout << i << " ";
    }
  }
};

int main() {
  NaturalNumbers nn;
  cout << "First 10 natural numbers are: " << endl;
  nn.display();
  cout << endl;
  return 0;
}