#include <iostream>
using namespace std;

int linearSearch(int *arr, int n, int elem) {
  for (int i = 0; i < n; i++) {
    if (arr[i] == elem)
      return i;
  }
  return -1;
}

int main() {
  int n, elem;
  cout << "Enter size of array: ";
  cin >> n;
  
  int arr[n];

  cout << "Enter " << n << " elements: ";
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  cout << "Enter element to search: ";
  cin >> elem;

  int idx = linearSearch(arr, n, elem);
  if (idx == -1)
    cout << "Element not found in array" << endl;
  else 
    cout << "Element found at index: " << idx << endl;
  
  return 0;
}
