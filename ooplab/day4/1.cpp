#include <iostream>
using namespace std;

class NaturalInput {
  int n;
  int *arr;
public:
  friend class NaturalSum;
  
  NaturalInput(int size) {
    n = size;
    arr = new int[size];
  }

  void getdata() {
    for (int i = 0; i < n; i++)
      cin >> arr[i];
  }
};

class NaturalSum {
public:
  int getsum(NaturalInput &ni) {
    int sum = 0;
    for (int i = 0; i < ni.n; i++) {
      int num = ni.arr[i];
      if (num > 0 && num % 2 != 0)
        sum += num;
    }
    return sum;
  }
};


int main() {
  int size;
  
  cout << "Enter size of array: ";
  cin >> size;

  NaturalInput ni(size);
  cout << "Enter " << size << " numbers: ";
  ni.getdata();

  NaturalSum ns;
  cout << "Sum of odd natural numbers is: " << ns.getsum(ni);
}
