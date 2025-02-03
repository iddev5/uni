#include <iostream>
using namespace std;

/*

// Exception classes

class range {};

void func(int x) {
    if (x == 0) 
        throw range();
}

int main() {
    try {
        func(0);
    } catch (range) {
        cout << "range caught" << endl;
    }
}

*/

/*

// Rethrowing exceptions

void divide(double x, double y) {
    try {
        if (y == 0.0)
            throw y;
        else
            cout << x/y << endl;
    } catch (double err) {
        cout << "err1: throw" << endl;
        throw;
    }
}

int main() {
    try {
        divide(10.0, 0.0);
    } catch (double err2) {
        cout << "err2: " << err2 << endl;
    }
    return 0;
}

*/


/*
// One class -> another class

class B;

class A {
    int a;
public:
    A(int a): a(a) {}

    friend class B;
};

class B {
    int b;
public:
    B(int b): b(b) {}
    B(A &a): b(a.a) {}

    void out() {
        cout << b << endl;
    }
};

int main() {
    int a;
    cin >> a;
    A ob1(a);
    B ob2 = ob1;
    ob2.out();
    return 0;
}

*/

/*

// Class -> basic type

class A {
    int a;
public:
    A(int a): a(a) {}
    A() { a = 0; }

    operator int() {
        return a;
    }

    void out() {
        cout << "a = " << a << endl;
    }
};

int main() {
    A obj1(25);
    int a;
    a = obj1;
    cout << a << endl;
    return 0;
}

*/

/*
// Order of destructor calling

class A {
public:
    int a;
    A(int a) : a(a) { }
    ~A() { cout << a << " "; }
};

int main() {
    A obj1(10), obj2(20);
    return 0;
}
*/