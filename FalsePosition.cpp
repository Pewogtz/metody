#include <iostream>
#include <iomanip>
using namespace std;

double f(double x)
{
    return cos(x) - x;
}

int main()
{
    double error = 1, last, current = 0, iterations = 0, xL = 0, xR = 1, r, l;
    while (error > pow(10, -8))
    {
        last = current;
        r = f(xR);
        l = f(xL);
        current = (xL * r - xR * l) / (r - l);
        if (l * f(current) <= 0)
        {
            xR = current;
        }
        else
            xL = current;
        error = abs((current - last) / current);
        iterations++;
    }
    cout << iterations << " iterations, root is: " << setprecision(8) << current << endl;
}

