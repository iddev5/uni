#include <iostream>
using namespace std;

void printArr(int *arr, int n) {
  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
  cout << endl;
}

void insertionSort(int *arr, int n) {
  for (int i = 1; i < n; i++) {
    int elem = arr[i];
    int back=i-1, front=i;
    while (back >= 0 && elem < arr[back]) {
      arr[front] = arr[back];
      arr[back] = elem;
      back--;
      front--;
    }
  }
}

int main() {
  int n;
  cout << "Insertion sort program\nEnter size of array: ";
  cin >> n;
  
  int arr[n];

  cout << "Enter " << n << " elements: ";
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  cout << "\nBefore sorting: ";
  printArr(arr, n);

  insertionSort(arr, n);

  cout << "After sorting: ";
  printArr(arr, n);
  
  return 0;
}
