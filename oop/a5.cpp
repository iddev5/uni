#include <iostream>
#include <math.h>
using namespace std;

template <typename T>
class QuadEq {
private:
    T a, b, c;
    float root1, root2;

public:
    QuadEq(T a1, T b1, T c1) {
        a = a1;
        b = b1;
        c = c1;
    }

    T getDiscriminant() {
        return b * b - 4 * a * c;
    }

    void calculateRoots() {
        T discriminant = getDiscriminant();

        float sqrtDiscriminant = sqrt(discriminant);
        root1 = (-b + sqrtDiscriminant) / (2 * a);
        root2 = (-b - sqrtDiscriminant) / (2 * a);
    }

    void printRoots() {
        cout << "Roots are: " << root1 << " and " << root2 << endl;
    }
};

int main() {
    int a, b, c;
    cout << "For equation ax^2 + bx + c\n";
    cout << "Enter value of a: ";
    cin >> a;
    cout << "Enter value of b: ";
    cin >> b;
    cout << "Enter value of c: ";
    cin >> c;

    QuadEq<int> qu(a, b, c);
    qu.calculateRoots();
    qu.printRoots();
    return 0;
}