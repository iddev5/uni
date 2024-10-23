#include <iostream>
using namespace std;

class Shape {
public:
  int get_area() {
    return 0;
  }
};

class Rectangle: Shape {
protected:
  int length, width;
public:
  Rectangle(int l, int w) {
    length = l;
    width = w;
  }
  int get_area() {
    return length * width;
  }
};

class Box: public Rectangle {
  int height;
public:
  Box(int l, int b, int h):
    Rectangle(l, b)
  {
    height = h;
  }
  int get_area() {
    return 2*(length*width + width*height + height*length);
  }
};

int main() {
  int l, w, h;

  cout << "Enter length: ";
  cin >> l;

  cout << "Enter breadth: ";
  cin >> w;

  cout << "Enter height: ";
  cin >> h;

  Shape sh;
  Rectangle rect(l, w);
  Box bx(l, w, h);

  cout << "Area of shape class: " << sh.get_area() << "\n\n";
  cout << "Area of rectangle class: " << rect.get_area() << "\n\n";
  cout << "Area of box class: " << bx.get_area() << endl;

  return 0;
}
