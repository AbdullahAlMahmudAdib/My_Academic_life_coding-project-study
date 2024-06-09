#include <bits/stdc++.h>
using namespace std;

#define ld long double

ld f(ld x) {
    return x * x * x - 4 * x - 5;
}

ld df(ld x) {
    return 3 * x * x - 4;
}

ld Error(ld a, ld b) {
    return abs((a - b) / a);
}

int iter = 0;

ld NewtonRaphson(ld a, ld error) {
    ld b = a - f(a) / df(a);
    cout << "________________________________________________________" << endl;
    cout << "| Iteration |     a         |     b         |   Error   |" << endl;
    cout << "|___________|_______________|_______________|___________|" << endl;
    while (Error(a, b) > error) {
        cout << fixed << setprecision(6);
        cout << "|    " << iter << "      | " << a << "      | " << b << "      | " << Error(a, b) << "  |" << endl;
        a = b;
        b = a - f(a) / df(a);
        iter++;
    }
    cout << "________________________________________________________" << endl;
    cout << "The root of the equation is: " << b << endl;
    cout << "-----------------------------------" << endl;
    return b;
}

int main() {
    ld a = 4.0; 
    ld error = 0.001;
    cout << "Newton-Raphson Method" << endl;
    NewtonRaphson(a, error);

    return 0;
}
