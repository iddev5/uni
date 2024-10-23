#include <iostream>
#include <string>
using namespace std;

class Country {
public:
  string name;
  string capital;
  int no_of_states;
};

class State: public Country {
  string name_of_state;
  string state_capital;
  float size_area;
public:
  State(string n1, string c1, int nos, string ns, string sc, float sa) {
    name = n1;
    capital = c1;
    no_of_states = nos;
    name_of_state = ns;
    state_capital = sc;
    size_area = sa;
  }

  void display() {
    cout << "Name of country: " << name << endl;
    cout << "Capital of country: " << capital << endl;
    cout << "Number of states: " << no_of_states << endl;
    cout << "Name of state: " << name_of_state << endl;
    cout << "Capital of state: " << state_capital << endl;
    cout << "Size of state: " << size_area << endl;
  }
};

int main() {
  string name, capital, state, state_cap;
  int num_states;
  float size;

  cout << "Enter name of country: ";
  cin >> name;

  cout << "Enter capital of country: ";
  cin >> capital;

  cout << "Enter number of states: ";
  cin >> num_states;

  cout << "Enter name of state: ";
  cin >> state;

  cout << "Enter capital of state: ";
  cin >> state_cap;

  cout << "Enter size of state: ";
  cin >> size;

  State st(name, capital, num_states, state, state_cap, size);
  st.display();

  return 0;
}