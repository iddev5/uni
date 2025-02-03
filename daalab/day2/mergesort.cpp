#include <iostream>
#include <ctime>
using namespace std;

void merge(int arr[], int lo, int hi) {
  int mid = (lo + hi) / 2;
  int l1 = lo, l2 = mid + 1;

  int i = 0;
  int *new_arr = new int[hi - lo + 1];

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

  delete[] new_arr;
}

void mergeSort(int arr[], int lo, int hi) {
  if (lo >= hi) return;
  int mid = (lo + hi) / 2;
  mergeSort(arr, lo, mid);
  mergeSort(arr, mid+1, hi);
  merge(arr, lo, hi);
}

void printArr(int arr[], int n) {
  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
  cout << endl;
}

void printName(int inp) {
  if (inp == 0) cout << "Sorted array (ascending order)";
  else if (inp == 1) cout << "Sorted array (descending order)";
  else if (inp == 2) cout << "Unsorted array";
  else cout << "Mixed array (sorted & unsorted)";
}

int main() {
  int n;
  double time[4];
  cout << "Enter size of array: ";
  cin >> n;

  int arr[n];

  for (int inp = 0; inp < 4; inp++) {
    cout << "\nCase " << inp + 1 << ": ";
    printName(inp);
    cout << ":\n";

    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++)
      cin >> arr[i];

    double start = (double)clock() / CLOCKS_PER_SEC;
    cout << "Start time: " << start << endl;

    mergeSort(arr, 0, n-1);

    double end = (double)clock() / CLOCKS_PER_SEC;
    cout << "End time: " << end << endl;

    time[inp] = end - start;
    cout << "Time taken: " << time[inp] << endl;

    cout << "After sorting: ";
    printArr(arr, n);
  }

  int min_inp = 0;
  for (int i = 1; i < 4; i++)
    if (time[i] < time[min_inp]) min_inp = i;

  cout << "After program execution, it is observed that ";
  printName(min_inp);
  cout << " takes least time" << endl;

  return 0;
}
