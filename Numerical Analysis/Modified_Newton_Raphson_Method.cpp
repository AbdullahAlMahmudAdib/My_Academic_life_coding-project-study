#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

double error_find(double c_experimental, double c_actual)
{
    return abs(c_experimental - c_actual) / c_actual;
}

double f(double x)
{
    return 3 * x - cos(x) - 1;
}

double df(double x) // First Derivative of f(x).
{
    return 3 + sin(x);
}

double dff(double x) // Second Derivative of f(x).
{
    return cos(x);
}

double Modified_Newton(double x, double ea)
{
    double error_tm = 1, c_experimental, c;
    int iter = 0;
    cout << fixed << setprecision(12);
    cout << "Iter\t\tx\t\t\tc\t\t\tError" << endl;
    while (error_tm > ea)
    {
        c_experimental = x;
        c = c_experimental - ((f(x) * df(x)) / ((df(x) * df(x)) - f(x) * dff(x)));
        error_tm = error_find(c_experimental, c);
        cout << iter << "\t\t" << x << "\t\t" << c << "\t\t" << error_tm << endl;
        if (f(c) == 0)
            break;
        x = c;
        iter++;
    }
    return c;
}

int main()
{
    double a, b, ea = 0.0000000000001;
    cin >> a >> b;
    double x = a;
    double root = Modified_Newton(x, ea);
    cout << "The root is: " << root << endl;
}
