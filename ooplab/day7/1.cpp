#include <iostream>
using namespace std;

class Mammal {
public:
  void say() {
    cout << "I am a Mammal" << endl;
  }
};

class MarineAnimal {
public:
  void say() {
    cout << "I am a Marine Animal" << endl;
  }  
};

class BlueWhale: public Mammal, public MarineAnimal {
public:
  void say() {
    cout << "I belong to both the categories" << endl;
  }
};

int main() {
  Mammal m;
  MarineAnimal ma;
  BlueWhale bw;

  cout << "Function of mammal: ";
  m.say();

  cout << "\nFunction of marine animal: ";
  ma.say();

  cout << "\nFunction of blue whale: ";
  bw.say();

  cout << "Function of parents from blue whale:" << endl;
  bw.Mammal::say();
  bw.MarineAnimal::say();

  return 0;
}
