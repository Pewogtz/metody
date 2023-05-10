#include <iostream>
#include <iomanip>
using namespace std;

double f(double x)
{
    return exp(x);
}

double df(double x)
{
    return exp(x);
}

int main()
{
    double x[] = { -1, 0.5, 1.5, 2 }, l, lp, ha, hb, p, xL = -5, xR = 5, n = 100, step = (xR - xL) / n, arg = xL;

    while (arg <= xR)
    {
        p = 0;
        for (int j = 0; j < sizeof(x) / sizeof(double); j++)
        {
            l = 1;
            lp = 0;
            for (int i = 0; i < (sizeof(x) / sizeof(double)); i++)
            {
                if (i != j)
                {
                    l *= (arg - x[i]) / (x[j] - x[i]);
                    lp += 1 / (x[j] - x[i]); 
                }
            }
            ha = (1 - 2 * (arg - x[j]) * lp) * pow(l, 2);
            hb = (arg - x[j]) * pow(l, 2);
            p += ha * f(x[j]) + hb * df(x[j]);
        }
        cout << arg << " " << p << endl;
        arg += step;
    }



}

