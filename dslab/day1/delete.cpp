#include <iostream>
using namespace std;

void deletion(int *arr, int len, int n) {
  for (int i = n; i < len - 1; i++) {
    arr[i] = arr[i+1];
  }
}

int main() {
  int n;
  cout << "Enter number of elements: ";
  cin >> n;

  int arr[n];
  cout << "Enter elements: ";
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  cout << "Before deletion: ";
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
  
  deletion(arr, n, 0);
  deletion(arr, n, (n-1)/2);
  deletion(arr, n, n-2);

  cout << "After deletion: ";
  for (int i = 0; i < n-3; i++) {
    cout << arr[i] << " ";
  }
}
