#include <iostream>
using namespace std;

class Factorial {
  int n;
public:
  void getdata() {
    cout << "Enter the number: ";
    cin >> n;
  }  

  void display() {
    unsigned long fact = 1;
    for (int i = n; i >= 1; i--) {
      fact *= i;
    } 
    cout << "Factorial of " << n << " is " << fact << endl;
  }
};

int main() {
  Factorial f;
  f.getdata();
  f.display();
  return 0;
}