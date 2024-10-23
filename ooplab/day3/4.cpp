#include <iostream>
using namespace std;

class PrimeNum {
  int n;
public:
  void getdata() {
    cout << "Enter the number to check: ";
    cin >> n;
  }
  void display() {
    for (int i = 2; i < n / 2 + 1; i++) {
      if (n % i == 0) {
        cout << "Number " << n << " is not prime" << endl;
        return;
      }
    }
    cout << "Number " << n << " is prime" << endl;
  }
};

int main() {
  PrimeNum p;
  p.getdata();
  p.display();
  return 0;
}