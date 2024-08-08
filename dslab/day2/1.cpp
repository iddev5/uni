#include <iostream>
using namespace std;

int main() {
  int n;
  cout << "Enter number of elements: ";
  cin >> n;

  int arr[n], rev[n];
  
  cout << "Enter elements: ";
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  for (int i = 0; i < n; i++)
    rev[n - i - 1] = arr[i];

  cout << "After reversing: ";
  for (int i = 0; i < n; i++)
    cout << rev[i] << " ";  

  return 0;
}
