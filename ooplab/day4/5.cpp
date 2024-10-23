#include <iostream>
using namespace std;

class Room {
  int w, h, l;

  int area, volume;
public:
  Room(int w1, int h1, int l1) {
    w = w1; h = h1; l = l1;
  }

  Room(Room &r) {
    w = r.w;
    h = r.h;
    l = r.l;
    calculate_area_volume();
  }

  void calculate_area_volume() {
    area = 2 * (l*w + w*h + l*h); 
    volume = w * h * l;
  }

  int get_area() {
    return area;
  }
};

int main() {
  int w, h, l;
  cout << "Enter width, height and length of room: ";
  cin >> w >> h >> l;

  Room r1(w, h, l);

  Room r2(r1);
  cout << "Area of another room using copy constructor is: " << r2.get_area() << endl;

  return 0;
}
