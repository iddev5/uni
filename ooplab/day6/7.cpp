#include <iostream>
#include <string>
using namespace std;

class Media {
protected:
  string title;
  int price;
public:
  Media(string t, int p) {
    title = t;
    price = p;
  }

  virtual void display() = 0;
};

class Book: public Media {
  int num_pages;
public:
  Book(string title, int price, int pages):
    Media(title, price)
  {
    num_pages = pages;
  }

  void display() {
    cout << "In class Book:" << endl;
    cout << "Title: " << title << endl;
    cout << "Price: " << price << endl;
    cout << "Number of pages: " << num_pages << endl << endl;
  }
};

class Tape: public Media {
  int time_playing;
public:
  Tape(string title, int price, int time):
    Media(title, price) 
  {
    time_playing = time;
  }

  void display() {
    cout << "In class Tape:" << endl;
    cout << "Title: " << title << endl;
    cout << "Price: " << price << endl;
    cout << "Time of playing: " << time_playing << endl;
  }
};

int main() {
  string title;
  int price, pages, time;

  cout << "Enter title of media: ";
  cin >> title;

  cout << "Enter price: ";
  cin >> price;

  cout << "Enter no of pages in book: ";
  cin >> pages;

  cout << "Enter time of playing tape: ";
  cin >> time;

  Book b(title, price, pages);
  Tape t(title, price, time);

  Media *m = &b;
  m->display();

  m = &t;
  m->display();

  return 0;
}