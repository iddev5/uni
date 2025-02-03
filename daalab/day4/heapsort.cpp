#include <iostream>
#include <ctime>
using namespace std;

void heapify(int *arr, int n, int i) {
  int largest = i;
  int left = 2 * i + 1;
  int right = 2 * i + 2;

  if (left < n && arr[left] > arr[largest])
    largest = left;

  if (right < n && arr[right] > arr[largest])
    largest = right;

  if (largest != i) {
    swap(arr[largest], arr[i]);
    heapify(arr, n, largest);
  }
}

void heapSort(int *arr, int n) {
  for (int i = n / 2 - 1; i >= 0; i--)
    heapify(arr, n, i);

  for (int i = n - 1; i > 0; i--) {
    swap(arr[0], arr[i]);
    heapify(arr, i, 0);
  }
}

void printName(int inp) {
  if (inp == 0) cout << "Sorted array (ascending)";
  else if (inp == 1) cout << "Sorted array (descending)";
  else if (inp == 2) cout << "Unsorted array";
  else cout << "Mixed array (sorted & unsorted)";
}

void printArr(int *arr, int n) {
  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
  cout << endl;
}

void inputArr(int *arr, int n) {
  cout << "Enter " << n << " elements: ";
  for (int i = 0; i < n; i++)
    cin >> arr[i];
}

int main() {
  int n;
  double time[4];
  cout << "Enter number of elements: ";
  cin >> n;

  cout << "Program started at: " << (double)clock() / CLOCKS_PER_SEC << endl;

  int arr[n];
  for (int inp = 0; inp < 4; inp++) {
    cout << "\nCase " << inp + 1 << ": ";
    printName(inp);
    cout << ":\n";

    inputArr(arr, n);

    cout << "Before sorting: ";
    printArr(arr, n);

    double start = (double)clock() / CLOCKS_PER_SEC;
    cout << "Starting time: " << start << endl;

    heapSort(arr, n);

    double end = (double)clock() / CLOCKS_PER_SEC;
    cout << "End time: " << end << endl;

    time[inp] = end - start;
    cout << "Time taken: " << time[inp] << " seconds" << endl;

    cout << "After sorting: ";
    printArr(arr, n);
  }

  int min_inp = 0, max_inp = 0;
  for (int i = 1; i < 4; i++)
    if (time[i] < time[min_inp]) 
      min_inp = i;
    else if (time[i] > time[max_inp])
      max_inp = i;

  cout << "\nAfter execution, it was concluded that minimum time is taken by ";
  printName(min_inp);
  cout << " that is " << time[min_inp] << " seconds" << endl;

  cout << "After execution, it was concluded that maximum time is taken by ";
  printName(max_inp);
  cout << " that is " << time[max_inp] << " seconds" << endl;

  return 0;
}