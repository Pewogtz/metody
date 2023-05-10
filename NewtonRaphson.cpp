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
    double error = 1, last, current = 0, iterations = 0;
    while (error > pow(10, -8))
    {
        last = current;
        current -= f(current) / df(current);
        error = abs((current - last) / current);
        iterations++;
    }
    cout << iterations << " iterations, root is: " << setprecision(8) << current << endl;
}

