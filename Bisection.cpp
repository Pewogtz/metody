#include <iostream>
#include <iomanip>
using namespace std;

double f(double x)
{
    return cos(x) - x;
}

double df(double x)
{
    return -sin(x) - 1;
}


int main()
{
    double xL = 0, xR = 1, xM, error = 1, last = xR, iterations = 0;
    while (error > pow(10, -8))
    {
        xM = 0.5 * (xL + xR);
        if (f(xL) * f(xM) <= 0)
        {
            xR = xM;
        }
        else
            xL = xM;
        error = abs((xR - xL) / xM);
        iterations++;
    }
    cout << iterations << " iterations, root is: " << setprecision(8) << xM << endl;
}

