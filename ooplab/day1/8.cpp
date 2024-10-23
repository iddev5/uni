#include <iostream>
using namespace std;

float pow(float x, int y) {
  float res = x;
  while (y--)
    res *= x;
  return res;
}

int main() {
  float p, r;
  int n;

  cout << "Enter principle amount: ";
  cin >> p;

  cout << "Enter rate of interest: ";
  cin >> r;

  cout << "Enter time in years: ";
  cin >> n;

  float final = p * pow(1 + r/100.0, n);
  cout << "Compound interest is " << final - p << " and final amount is " << final << endl;

  return 0;
}
