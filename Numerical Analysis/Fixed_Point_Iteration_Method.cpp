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

double g(double x)
{
    return (cos(x) + 1) / 3;
}

double Fixed_Point(double x, double ea)
{
    double error_tm = 1, c_experimental, c;
    int iter = 0;
    cout << fixed << setprecision(12);
    cout << "Iter\t\tx\t\t\tc\t\t\tError" << endl;
    while (error_tm > ea)
    {
        c_experimental = x;
        c = g(x);
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
    double x = 3.2, ea = 0.0000000000001;
    double root = Fixed_Point(x, ea);
    cout << "The root is: " << root << endl;
}
