#include <iostream>
#include <iomanip>
using namespace std;

double f(double x)
{
    return cos(x) - x;
}

int main()
{
    double error = 1, last = 0, current = 1, iterations = 0, l, c, a;
    while (error > pow(10, -8))
    {
        a = current;
        l = f(last);
        c = f(current);
        current = (last * c - current * l) / (c - l);
        last = a;
        error = abs((current - last) / current);
        iterations++;
    }
    cout << iterations << " iterations, root is: " << setprecision(8) << current << endl;
}

