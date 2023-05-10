#include <iostream>
#include <iomanip>
using namespace std;
    
double f(double x)
{
    return 1 / (1 + pow(x, 2));
}

int main()
{
    const int n = 11;
    double a[n], b[n], c[n], r[n], rho[n], beta[n], p[n], pp[n];
    double xL = -5, xR = 5, arg = xL, h = 1, pol;
    double x[] = { -5, -4, -3, -2, -1, 0, 1, 2, 3, 4, 5 };
    for (int i = 0; i < n; i++)
    {
        p[i] = f(x[i]);
    }


    //system setup
    b[0] = 1;
    c[0] = 0;
    r[0] = 0;
    a[n - 1] = 0;
    b[n - 1] = 1;
    c[n - 2] = 0;
    r[n - 1] = 0;
    for (int i = 1; i < n - 1; i++)
    {
        a[i] = h;
        b[i] = 4 * h;
        c[i] = h;
        r[i] = 6 * (p[i + 1] - 2 * p[i] + p[i - 1]) / h;
    }
    //solving the system
    beta[0] = b[0];
    for (int i = 1; i < n; i++)
    {
        beta[i] = b[i] - (a[i] / beta[i - 1]) * c[i - 1];
    }
    rho[0] = r[0];
    for (int i = 1; i < n; i++)
    {
        rho[i] = r[i] - (a[i] / beta[i - 1]) * rho[i - 1];
    }
    pp[n - 1] = rho[n - 1] / beta[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        pp[i] = (rho[i] - c[i] * pp[i + 1]) / beta[i];
    }
    for (int j = 0; j < n - 1; j++)
    {
        for (int i = 0; i < 10; i++)
        {
            pol = p[j] + ((p[j + 1] - p[j]) / h - 1 / 6 * h * pp[j + 1] - 1 / 3 * h * pp[j]) * (arg - x[j]) + pp[j] / 2 * pow(arg - x[j], 2)
                + (pp[j + 1] - pp[j]) / (6 * h) * pow(arg - x[j], 3);
            cout << setprecision(8) << arg << " " << pol << endl;
            arg += 0.1;
        }
    }
}
