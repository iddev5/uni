#include <iostream>
#include <ctime>
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

void printName(int inp) {
  if (inp == 0) cout << "Sorted array (ascending order)";
  else if (inp == 1) cout << "Sorted array (descending order)";
  else if (inp == 2) cout << "Unsorted array";
  else cout << "Mixed array (sorted & unsorted)";
}

bool isSorted(int *arr, int n) {
  for (int i = 0; i < n - 2; i++)
    if (arr[i] > arr[i+1]) return false;
  return true;
}

void sort(int *arr, int n) {
  for (int i = 0; i < n - 1; i++)
    for (int j = 0; j < n - i - 1; j++)
      if (arr[j] > arr[j + 1])
        swap(arr[j], arr[j + 1]);
}

int main() {
  int n, elem;
  double time[4];
  cout << "Enter size of array: ";
  cin >> n;
  
  clock();

  int arr[n];

  for (int inp = 0; inp < 4; inp++) {
    cout << "\nCase " << inp + 1 << ": ";
    printName(inp);
    cout << ":\n";

    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++)
      cin >> arr[i];

    cout << "Enter element to search: ";
    cin >> elem;

    double start = (double)clock() / CLOCKS_PER_SEC;
    cout << "Start time: " << start << endl;

    if (!isSorted(arr, n))
      sort(arr, n);

    int idx = binarySearch(arr, n, elem);
    if (idx == -1)
      cout << "Element not found in array" << endl;
    else 
      cout << "Element found at index: " << idx << endl;

    double end = (double)clock() / CLOCKS_PER_SEC;
    cout << "End time: " << end << endl;

    time[inp] = end - start;
    cout << "Time taken: " << time[inp] << endl;
  }

  int min_inp = 0;
  for (int i = 1; i < 4; i++)
    if (time[i] < time[min_inp]) min_inp = i;

  cout << "After program execution, it is observed that ";
  printName(min_inp);
  cout << " takes least time" << endl;

  return 0;
}
