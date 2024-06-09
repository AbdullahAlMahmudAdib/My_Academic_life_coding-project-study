#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

double error_find(double x1, double x0)
{
    return abs(x1 - x0) / x1;
}

double f(double x)
{
    return 3 * x - cos(x) - 1;
}

double Secant(double x0, double x1, double ea)
{
    double error_tm = 1, x2;
    int iter = 0;
    cout << fixed << setprecision(12);
    cout << "Iter\t\tx0\t\t\tx1\t\t\tx2\t\t\tError" << endl;
    while (error_tm > ea)
    {
        x2 = x1 - ((x1 - x0) / (f(x1) - f(x0))) * f(x1);
        error_tm = error_find(x1, x0);
        cout << iter << "\t\t" << x0 << "\t\t" << x1 << "\t\t" << x2 << "\t\t" << error_tm << endl;
        if (f(x2) == 0)
            break;
        x0 = x1;
        x1 = x2;
        iter++;
    }
    return x2;
}

int main()
{
    double x0, x1, ea = 0.00000001;
    cin >> x0 >> x1;
    double root = Secant(x0, x1, ea);
    cout << "The root is: " << root << endl;
}
