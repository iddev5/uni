#include <iostream>
using namespace std;

class Second;

class First {
  int x;
public:
  First() {
    cout << "Enter input for first class: ";
    cin >> x;
  }

  friend int add(First &, Second &); 
};

class Second {
  int x;
public:
  Second() {
    cout << "Enter input for second class: ";
    cin >> x;
  }
  
  friend int add(First &, Second &); 
};

int add(First &ob1, Second &ob2) {
  return ob1.x + ob2.x;
}

int main() {
  First x1;
  Second x2;

  int res = add(x1, x2);
  cout << "Addition result is " << res << endl;
}