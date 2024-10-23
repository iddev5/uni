#include <iostream>
using namespace std;

class Factors {
  int n;
public:
  void getdata() {
    cout << "Enter number to display factors: ";
    cin >> n;
  }
  
  void display() {
    cout << "Factors of " << n << " are: ";
    for (int i = 1; i <= n; i++) {
      if (n % i == 0)
        cout << i << " ";
    }
    cout << endl;
  }
};

int main() {
  Factors f;
  f.getdata();
  f.display();
  return 0;
}