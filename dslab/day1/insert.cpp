#include <iostream>
using namespace std;

void insert(int *arr, int len, int elem, int n) {
  for (; len >= n; len--) {
    arr[len + 1] = arr[len];
    if (len == n) {
      arr[n] = elem;
      return;
      }
  }
}

int main() {
  int n;
  cout << "Enter number of elements: ";
  cin >> n;

  int arr[n+3];
  cout << "Enter elements: ";
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  cout << "Before inserting: ";
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
  
  insert(arr, n+3, 100, 0);
  insert(arr, n+3, 50, (n+3)/2);
  insert(arr, n+3, -100, n+2);

  cout << "After inserting: ";
  for (int i = 0; i < n+3; i++) {
    cout << arr[i] << " ";
  }
}
