#include <iostream>
using namespace std;
#include "complex.h"

int main()
{
    Complex a(5, 1), b(2, 13), c,d,f(-1,5), g(1,-3),h(-5,-1),j;
    const Complex e(1,3), i(2,3);
    c = 10;
    j = e + i;
    cout << j << endl;
    j = e - i;
    cout << j << endl;
    j = e / i;
    cout << j << endl;
    cout << e.abs() << endl;
    cout << e.conj() << endl;
    cout << a.conj() << endl;
    cout << "Faza:" << endl;
    cout << a.phase() << endl;
    cout << f.phase() << endl;
    cout << g.phase() << endl;
    cout << h.phase() << endl;
    cout << e.phase() << endl;
    d = a/b;
    cout << d << endl;
    a/=b;
    cout << a << endl;
    b = 2/a;
    cout << b << endl;
    b = 2 - a;
    cout << b << endl;
    cout << c << endl;
    c = -a;
    cout << c << endl;
    c = a + b;
    c = c - Complex(10);
    cout << c << endl;
    c = 10 - a;
    (c -= b) -= 10;
    cout << c << endl;
}
