#include <iostream>
using namespace std;

class PerfectNum {
public:
  int sum_divisors(int n) {
    int sum = 0;
    for (int i = 1; i <= n/2 + 1; i++) {
      if (n % i == 0)
        sum += i;
    }
    return sum;
  }
  
  void display() {
    cout << "Perfect numbers between 1 and 500 is:" << endl;
    for (int i = 2; i < 500; i++) {
      if (sum_divisors(i) == i)
        cout << i << " ";
    }
    cout << endl;
  }
};

int main() {
  PerfectNum pn;
  pn.display();
  return 0;
}