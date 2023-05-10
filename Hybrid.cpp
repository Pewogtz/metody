#include <iostream>
#include <iomanip>
using namespace std;

double f(double x)
{
    return pow(x, 2) - 2 * x - 2;
}

double df(double x)
{
    return 2 * x - 2;
}

int main()
{
    double error = 1, last, current = 0, iterations = 0, xL = 0, xR = 3, xM, currentDerivative, currentValue, lt, rt, nStep = 0, bStep = 0;
    while (error > pow(10, -8))
    {
        last = current;
        currentDerivative = df(current);
        currentValue = f(current);
        lt = (current - xL) * currentDerivative - currentValue;
        rt = (current - xR) * currentDerivative - currentValue;
        if (lt * rt < 0)
        {
            current -= currentValue / currentDerivative;
            error = abs((current - last) / current);
            nStep++;
        }
        else
        {
            xM = 0.5 * (xL + xR);
            current = xM;
            if (f(xL) * f(current) <= 0)
            {
                xR = xM;
            }
            else
                xL = xM;
            error = abs((xR - xL) / xM);
            bStep++;
        }
        iterations++;
    }
    cout << iterations << " iterations, root is: " << setprecision(8) << current << " Newston steps: " << nStep << "; Bisection steps: " << bStep << endl;
}

