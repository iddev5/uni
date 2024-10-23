#include <iostream>
using namespace std;

class SumDigits {
  int n;
public:
  void getdata() {
    cout << "Enter number to sum the digits: ";
    cin >> n;
  }
  
  void display() {
    int num = n, sum = 0;
    while (num) {
      int rem = num % 10;
      sum += rem;
      num /= 10;
    }

    cout << "Sum of digits is " << sum << endl;
  }
};

int main() {
  SumDigits sd;
  sd.getdata();
  sd.display();
  return 0;
}