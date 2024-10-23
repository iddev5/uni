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
  int n, sum;
  cout << "Enter number of elements: ";
  cin >> n;

  int arr[n];
  
  cout << "Enter elements: ";
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  cout << "Enter sum to find: ";
  cin >> sum;

  sort(arr, n);

  int count = 0, lo = 0, hi = n - 1;
  while (lo < hi) {
    int s = arr[lo] + arr[hi];
    if (sum == s) {
      cout << "Found pair (" << arr[lo] << ", " << arr[hi] << ")\n";
      count++;
      lo++;
    }
    else if  (s > sum) hi--;
    else lo++;
  }

  cout << "Total number of pairs is " << count << endl;

  return 0;
}
