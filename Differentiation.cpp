#include <iostream>
#include <iomanip>
using namespace std;

double f(double x)
{
    return x * exp(x);
}

double df(double x)
{
    return exp(x) + x * exp(x);
}

double ddf(double x)
{
    return exp(x) + exp(x) + x * exp(x);
}

double dFD(double x, double h)
{
    return 1 / h * (f(x + h) - f(x));
}

double dCD(double x, double h)
{
    return 1 / (2 * h) * (f(x + h) - f(x - h));
}

double ddFD(double x, double h)
{
    return 1 / pow(h, 2) * (f(x) - 2 * f(x + h) + f(x + 2 * h));
}

double ddCD(double x, double h)
{
    return 1 / pow(h, 2) * (f(x + h) - 2 * f(x) + f(x - h));
}

double xyi(double* x, double* y, int n)
{
    double sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += x[i] * y[i];
    }
    return sum;
}

double xyij(double* x, double* y, int n)
{
    double sum = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            sum += x[i] * y[j];
        }
    }
    return sum;
}

double xs(double* x, int n)
{
    double sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += x[i];
    }
    return sum;
}

double xsq(double* x, int n)
{
    double sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += pow(x[i], 2);
    }
    return sum;
}

double lSquares(int n, double xyi, double xyij, double xsq, double x)
{
    return (n * xyi - xyij) / (n * xsq - pow(x, 2));
}

int main()
{
    double error[10], x[10], y[10], h;
    for (int i = 1; i < 11; i++)
    {
        h = i * 0.05;
        error[i - 1] = abs(df(2) - dFD(2, i * 0.05));
        x[i - 1] = log(h);
        y[i - 1] = log(error[i - 1]);   
    }
    cout << lSquares(10, xyi(x, y, 10), xyij(x, y, 10), xsq(x, 10), xs(x, 10)) << endl;
    for (int i = 1; i < 11; i++)
    {
        h = i * 0.05;
        error[i - 1] = abs(df(2) - dCD(2, i * 0.05));
        x[i - 1] = log(h);
        y[i - 1] = log(error[i - 1]);
    }
    cout << lSquares(10, xyi(x, y, 10), xyij(x, y, 10), xsq(x, 10), xs(x, 10)) << endl;
}
