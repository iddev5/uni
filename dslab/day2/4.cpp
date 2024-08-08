#include <iostream>
using namespace std;

int main() {
  int n;
  cout << "Enter number of elements: ";
  cin >> n;

  int arr[n];
  
  cout << "Enter elements: ";
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  int sum;
  cout << "Enter sum to find: ";
  cin >> sum;

  int pair = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (arr[i] + arr[j] == sum) 
        pair++;
    }    
  }

  cout << "No of pairs found is " << pair << endl;

  return 0;
}
