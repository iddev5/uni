#include <iostream>
using namespace std;

class Converter {
  int bin;
public:
  Converter() {
    cout << "Enter number to convert: ";
    cin >> bin;
  }
  
  inline int bin2dec() {
    int dec = 0, copy = bin, mul = 1;
    while (copy) {
      int digit = copy % 10;
      dec += mul * digit;
      mul *= 2; copy /= 10;
    }
    return dec;
  }
};

int main() {
  Converter c;
  cout << "After converting: " << c.bin2dec();
  
  return 0;
}
