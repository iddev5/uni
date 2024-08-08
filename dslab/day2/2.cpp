#include <iostream>
using namespace std;

void sort(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n - i -1; j++) {
      if (arr[j] > arr[j + 1]) {
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
}

int main() {
  int n;
  cout << "Enter number of elements: ";
  cin >> n;

  int arr[n];
  
  cout << "Enter elements: ";
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  sort(arr, n);

  int first = arr[0];
  for (int i = 0; i < n;) {
    int j = i;
    while (arr[j] == first) j++;
    cout << "Occurance of " << first << " is " << j - i << endl;
    i = j;
    first = arr[i];
  }

  return 0;
}
