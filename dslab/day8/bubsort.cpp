#include <iostream>
using namespace std;

void bubbleSort(int *arr, int n) {
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      if (arr[j + 1] < arr[j]) {
        int temp = arr[j + 1];
        arr[j + 1] = arr[j];
        arr[j] = temp;
      }
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
  cout << "Bubble sort program\nEnter size of array: ";
  cin >> n;
  
  int arr[n];

  cout << "Enter " << n << " elements: ";
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  cout << "\nBefore sorting: ";
  printArr(arr, n);

  bubbleSort(arr, n);

  cout << "After sorting: ";
  printArr(arr, n);
  
  return 0;
}
