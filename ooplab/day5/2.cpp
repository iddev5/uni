#include <iostream>
using namespace std;

class Reverse {
  int num;
public:
  Reverse() {
    cout << "Enter number to reverse: ";
    cin >> num;
  }

  inline int reverse() {
    int rev = 0, copy = num;
    while (copy) {
      rev = (rev * 10) + (copy % 10);
      copy /= 10;
    }

    return rev;
  }
};

int main() {
  Reverse re;
  cout << "Reverse of the number is: " << re.reverse() << endl;

  return 0;
}
