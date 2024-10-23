#include <iostream>
using namespace std;

class DigitCounter {
  int n;
public:
  void getdata() {
    cout << "Enter number to count digit: ";
    cin >> n;
  }
  
  void display() {
    int num = n, count = 0;
    while (num) {
      count++;
      num /= 10;
    }

    cout << "Number of digits in " << n << " is " << count << endl;
  }
};

int main() {
  DigitCounter dc;
  dc.getdata();
  dc.display();
  return 0;
}