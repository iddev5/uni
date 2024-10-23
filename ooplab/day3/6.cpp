#include <iostream>
using namespace std;

class PrimeRange {
  int hi, lo;
public:
  void getdata() {
    cout << "Enter upper limit of range: ";
    cin >> hi;
    cout << "Enter lower limit of range: ";
    cin >> lo;
  }

  void check_prime(int num) {
    for (int i = 2; i < num / 2 + 1; i++) {
      if (num % i == 0) return;
    }
    cout << num << " ";
  }
  
  void display() {
    cout << "Prime numbers within range is: ";
    for (int i = lo; i < hi; i++) {
      check_prime(i);
    }
    cout << endl;
  }
};

int main() {
  PrimeRange pr;
  pr.getdata();
  pr.display();
  return 0;
}