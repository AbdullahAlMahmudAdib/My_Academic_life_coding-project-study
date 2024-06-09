#include <bits/stdc++.h>
using namespace std;

#define ld long double

ld f(ld x)
{
    return x * x - 4;
}
ld Error(ld a, ld b)
{
    return abs((a - b) / a);
}
int iter = 0;
ld Bisection(ld a, ld b, ld error)
{
    ld c = 0;
    while (Error(a, b) > error)
    {
        c = (a + b) / 2;
        cout << iter << "\t\t" << a << "\t\t" << b << "\t\t" << c << "\t\t" << fixed << setprecision(4) << Error(a, b) << endl;
        if (f(c) == 0)
        {
            return c;
        }
        else if (f(c) * f(a) < 0)
            b = c;
        else
            a = c;
        iter++;
    }
    cout << "The root of the equation is:" << endl;
    return c;
}

int main()
{
    ld a = 3;
    ld b = 0;
    ld error = 0.01;
    cout << "Bisection Method" << endl;
    cout << "Iter"
         << "\t\ta: "
         << "\t\tb: "
         << "\t\tc: "
         << "\t\tError: " << endl;
    cout << Bisection(a, b, error) << endl;

    return 0;
}