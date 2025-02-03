#include <iostream>
#include <ctime>
using namespace std;

void bubbleSort(int *arr, int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      if (arr[j+1] < arr[j]) {
        swap(arr[j+1], arr[j]);
      }
    }
  }
}

void insertionSort(int *arr, int n) {
  for (int i = 1; i < n; i++) {
    int elem = arr[i];
    int back = i - 1, front = i;
    while (back >= 0 && elem < arr[back]) {
      arr[front] = arr[back];
      arr[back] = elem;
      back--;
      front--;
    }
  }
}

void selectionSort(int *arr, int n) {
  for (int i = 0; i < n; i++) {
    int sorted = arr[i], si = i, sn = sorted;
    for (int j = i + 1; j < n; j++) {
      if (arr[j] < sn) {
        sn = arr[j];
        si = j;
      }
    }
    if (sn != sorted) {
      arr[i] = arr[si];
      arr[si] = sorted;
    }
  }
}

void heapify(int *arr, int n, int i) {
  int largest = i;
  int left = 2 * i + 1, right = 2 * i + 2;

  if (left < n && arr[left] > arr[largest])
    largest = left;
  if (right < n && arr[right] > arr[largest])
    largest = right;

  if (largest != i) {
    swap(arr[i], arr[largest]);
    heapify(arr, n, largest);
  }
}

void heapSort(int *arr, int n) {
  for (int i = n/2-1; i >= 0; i--)
    heapify(arr, n, i);

  for (int i = n - 1; i > 0; i--) {
    swap(arr[0], arr[i]);
    heapify(arr, i, 0);
  }
}

void printArr(int *arr, int n) {
  for (int i = 0; i < n; i++) 
    cout << arr[i] << " ";
  cout << endl;
}

void copyArr(int *new_arr, int *arr, int n) {
  for (int i = 0; i < n; i++)
    new_arr[i] = arr[i];
}

void algoName(int inp) {
  if (inp == 0) cout << "Bubble sort";
  else if (inp == 1) cout << "Insertion sort";
  else if (inp == 2) cout << "Selection sort";
  else cout << "Heap sort";
}

void performSort(int n) {
  cout << "\nFor " << n << " elements:\nEnter elements: ";
  
  int arr[n];
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  for (int inp = 0; inp < 4; inp++) {
    cout << "\nAlgorithm " << inp + 1 << ": ";
    algoName(inp);
    cout << ":" << endl;

    int new_arr[n];
    copyArr(new_arr, arr, n);

    cout << "Before sorting: ";
    printArr(new_arr, n);
  
    double start = (double)clock() / CLOCKS_PER_SEC;
    cout << "Starting time: " << start << endl;
  
    if (inp == 0) bubbleSort(new_arr, n);
    else if (inp == 1) insertionSort(new_arr, n);
    else if (inp == 2) selectionSort(new_arr, n);
    else heapSort(new_arr, n);

    double end = (double)clock() / CLOCKS_PER_SEC;
    cout << "End time: " << end << endl;

    cout << "Time taken: " << (end - start) << " seconds" << endl;
    cout << "After sorting: ";
    printArr(new_arr, n);
  }
}

int main() {
  cout << "Comparision of sorting algorithms:" << endl;
  for (int i = 1; i <= 4; i++)
    performSort(5*i);

  return 0;
}
