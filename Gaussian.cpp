#include <iostream>
using namespace std;

int main()
{
    double a[] = {0, -1, -1, -1, -1 }, b[] = { 2, 2, 2, 2, 2 }, c[] = { -1, -1, -1, -1 }, r[] = { 0, 1, 2, 3, 4 }, rho[] = { 0, 0, 0, 0, 0 }, beta[] = { 0, 0, 0, 0, 0 }, x[] = {0, 0, 0, 0, 0};
    int n = sizeof(b) / sizeof(double);
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
    x[n - 1] = rho[n - 1] / beta[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        x[i] = (rho[i] - c[i] * x[i + 1]) / beta[i];
    }
    for (int i = 0; i < n; i++)
    {
        cout << x[i] << endl;
    }

}
