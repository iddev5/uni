#include <iostream>
using namespace std;

int binarySearch(int *arr, int n, int elem) {
  int high = n-1, low = 0;
  while (low <= high) {
    int mid = (low + high) / 2;
    if (arr[mid] > elem) high = mid - 1;
    else if (arr[mid] < elem) low = mid + 1;
    else return mid;
  }
  return -1;
}

int main() {
  int n, elem;
  cout << "Enter size of sorted array: ";
  cin >> n;
  
  int arr[n];

  cout << "Enter " << n << " sorted elements: ";
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  cout << "Enter element to search: ";
  cin >> elem;

  int idx = binarySearch(arr, n, elem);
  if (idx == -1)
    cout << "Element not found in array" << endl;
  else 
    cout << "Element found at index: " << idx << endl;
   
  return 0;
}
