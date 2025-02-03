#include <iostream>
#include <ctime>
using namespace std;

int partition(int *arr, int lo, int hi, int piv_index) {
    int pivot = arr[piv_index];
    int i = lo - 1;

    for (int j = lo; j <= hi; j++) {
        if (j == piv_index)
            continue;
        if (arr[j] <= pivot) {
            i++;
            if (i == piv_index)
                piv_index = j;
            swap(arr[i], arr[j]);
        }
    }
    
    swap(arr[i + 1], arr[piv_index]);
    return i + 1;
}

void quickSort(int *arr, int lo, int hi, int piv_index) {
    if (lo >= hi) return;
    int mid = partition(arr, lo, hi, piv_index);
    quickSort(arr, lo, mid - 1, mid - 1);
    quickSort(arr, mid + 1, hi, hi);
}

void printArr(int *arr, int n) {
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
  int n, pivot;
  double time[4];

  cout << "Quick sort program\nEnter size of array: ";
  cin >> n;
  
  int arr[n];

  cout << "Enter pivot index (from 0 to " << n-1 << "): ";
  cin >> pivot;

  for (int inp = 0; inp < 4; inp++) {
    cout << "\nCase " << inp << ": ";
    printName(inp);
    cout << ":\n";

    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++)
      cin >> arr[i];

    double start = (double)clock() / CLOCKS_PER_SEC;
    cout << "Start time: " << start << endl;

    quickSort(arr, 0, n-1, pivot);

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
