#include <iostream>
using namespace std;

int partition(int *arr, int lo, int hi) {
  int pivot = arr[hi];
  int i = lo-1;
  for (int j = lo; j < hi; j++) {
    if (arr[j] <= pivot) {
      i++;
      swap(arr[i], arr[j]);
    }
  }
  swap(arr[i+1], arr[hi]);
  return i+1;
}

void quickSort(int *arr, int lo, int hi) {
  if (lo < hi) {
    int mid = partition(arr, lo, hi);
    quickSort(arr, lo, mid-1);
    quickSort(arr, mid+1, hi);
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

  quickSort(arr, 0, n-1);

  cout << "After sorting: ";
  printArr(arr, n);
  
  return 0;
}
