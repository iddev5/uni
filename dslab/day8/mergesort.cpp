#include <iostream>
using namespace std;

void merge(int *arr, int lo, int hi) {
  int mid = (lo + hi) / 2;
  int l1 = lo, l2 = mid+1;

  int i = 0;
  int *new_arr = new int[hi-lo+1];

  while (l1 <= mid && l2 <= hi) {
    if (arr[l1] < arr[l2])
      new_arr[i++] = arr[l1++];
    else
      new_arr[i++] = arr[l2++];
  }

  while (l1 <= mid)
    new_arr[i++] = arr[l1++];

  while (l2 <= hi)
    new_arr[i++] = arr[l2++];

  for (i = 0; i < hi - lo + 1; i++)
    arr[lo + i] = new_arr[i]; 
}

void mergeSort(int *arr, int lo, int hi) {
  if (lo < hi) {
    int mid = (lo + hi) / 2;
    mergeSort(arr, lo, mid);
    mergeSort(arr, mid+1, hi);
    merge(arr, lo, hi);
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

  mergeSort(arr, 0, n-1);

  cout << "After sorting: ";
  printArr(arr, n);
  
  return 0;
}
