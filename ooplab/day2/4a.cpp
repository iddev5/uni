#include <iostream>
using namespace std;

class solid {
public:
  double volume(double r, double h) {
    return 3.14 * r * r * h;
  }

  int volume(int s) {
    return s * s * s;
  }

  double volume(double r) {
    return (4.0/3.0) * 3.14 * r * r * r;
  }
};

int main() {
  int cs;
  double sr, cyr, cyh;
  solid s;
  
  cout << "Enter radius of sphere: ";
  cin >> sr;
  cout << "Volume of sphere is " << s.volume(sr) << endl;

  cout << "Enter side of cube: ";
  cin >> cs;
  cout << "Volume of cube is " << s.volume(cs) << endl; 

  cout << "Enter radius and height of cylinder: ";
  cin >> cyr >> cyh;
  cout << "Volume of cylinder is " << s.volume(cyr, cyh) << endl;
}
