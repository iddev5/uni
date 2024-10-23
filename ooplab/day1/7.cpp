#include <iostream>
using namespace std;

int main() {
  float p, r, t;

  cout << "Enter principle amount: ";
  cin >> p;

  cout << "Enter rate of interest: ";
  cin >> r;

  cout << "Enter time in years: ";
  cin >> t;

  float si = (p * r * t) / 100.0;
  cout << "Simple interest is " << si << " and final amount is " << si + p <<  endl;

  return 0;
}
