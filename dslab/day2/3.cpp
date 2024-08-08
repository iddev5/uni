#include <iostream>
using namespace std;

int main() {
  int n1;
  cout << "Enter number of elements for first array: ";
  cin >> n1;

  int arr1[n1];
  
  cout << "Enter elements for first array: ";
  for (int i = 0; i < n1; i++)
    cin >> arr1[i];
  
  int n2;
  cout << "Enter number of elements for second array: ";
  cin >> n2;

  int arr2[n2];
  
  cout << "Enter elements for second array: ";
  for (int i = 0; i < n2; i++)
    cin >> arr2[i];

  int merged[n1+n2]; 

  for (int i = 0; i < n1; i++)
    merged[i] = arr1[i];

  for (int i = 0; i < n2; i++)
    merged[n1+i] = arr2[i];

  cout << "After merging: ";
  for (int i = 0; i < n1+n2; i++)
    cout << merged[i] << " ";  

  return 0;
}
