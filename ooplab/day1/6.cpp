#include <iostream>
using namespace std;

int main() {
  float farenheit;
  cout << "Enter temperature in farenheit: ";
  cin >> farenheit;

  float celcius = ((float)5 / 9) * (farenheit - 32);
  cout << "Temperature in celcius is " << celcius << endl;

  return 0;
}
