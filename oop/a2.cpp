#include <iostream>
#include <math.h>
using namespace std;

int main() {
  int n;
  cout << "Enter no of inputs: ";
  cin >> n;

  float sum = 0, num[n];
  cout << "Enter inputs: ";
  for (int  i = 0; i < n; i++) {
    cin >> num[i];
    sum += num[i];
  }

  float mean = sum / n;
  float var = 0;
  for (int  i =0; i < n; i++)
    var += (num[i] - mean) * (num[i] - mean);
  var /= n - 1;

  cout << "Variance is: " << var << endl;
  cout << "Standard deviation is: " << sqrt(var) << endl;
  return 0;
}
