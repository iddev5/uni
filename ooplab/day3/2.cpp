#include <iostream>
using namespace std;

class NaturalSum {
  int n;
public:
  void getdata() {
    cout << "Enter value of N: ";
    cin >> n;
  }
  
  void display() {
    int sum = 0;
    for (int i = 1; i <= n; i++) {
      sum += i;
    }
    cout << "Sum of first N natural numbers is " << sum << endl;
  }
};

int main() {
  NaturalSum sum;
  sum.getdata();
  sum.display();
  return 0;
}