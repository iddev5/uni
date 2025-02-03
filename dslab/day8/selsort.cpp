#include <iostream>
using namespace std;

void selectionSort(int *arr, int n) {
  for (int i = 0; i < n; i++) {
    int sorted = arr[i], si = i, sn = sorted;
    for (int j = i + 1; j < n; j++) {
      if (arr[j] < sn) {
        si = j;
        sn = arr[j];
      }
    }
    if (sn != sorted) {
      arr[i] = arr[si];
      arr[si] = sorted;
    }
  }
}

void printArr(int *arr, int n) {
  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
  cout << endl;
}

int main() {
  int n;
  cout << "Selection sort program\nEnter size of array: ";
  cin >> n;
  
  int arr[n];

  cout << "Enter " << n << " elements: ";
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  cout << "\nBefore sorting: ";
  printArr(arr, n);

  selectionSort(arr, n);

  cout << "After sorting: ";
  printArr(arr, n);
  
  return 0;
}
