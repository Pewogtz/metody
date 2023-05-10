#include <iostream>
#include <iomanip>
using namespace std;

double f(double x)
{
    return exp(x);
}

int main()
{
    double x[] = { -1, 0.5, 1.5, 2 }, l, p, xL = -5, xR = 5, n = 100, step = (xR - xL) / n, arg = xL;
    
    while (arg <= xR)
    {
        p = 0;
        for (int j = 0; j < sizeof(x) / sizeof(double); j++)
        {
            l = 1;
            for (int i = 0; i < (sizeof(x) / sizeof(double)); i++)
            {
                if (i != j)
                {
                    l *= (arg - x[i]) / (x[j] - x[i]);
                }
            }
            p += l * f(x[j]);
        }
        cout << arg << " " << p << endl;
        arg += step;
    }
    


}

