#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    double trap, simp, boole, euler, h, xL = 0, xR = 3.14159265358979323846, arg = xL;
    int n;
    for (int i = 2; i < 11; i++)
    {
        arg = xL;
        trap = 0;
        n = pow(2, i);
        h = (xR - xL) / n;
        for (int j = 0; j <= n; j++)
        {
            if (j == 0 || j == n) {
                trap += 0.5 * h * sin(arg);
            }
            else {
                trap += h * sin(arg);
            }
            arg += h;
        }
        cout << n << " " << trap << endl;
    }
    
    for (int i = 2; i < 11; i++)
    {
        arg = xL;
        simp = 0;
        n = pow(2, i);
        h = (xR - xL) / n;
        for (int j = 0; j <= n; j++)
        {
            if ((j == 0) || (j == n)) {
                simp += sin(arg);
            }
            else if (j % 2 == 0) {
                simp += 2.0 * sin(arg);
            }
            else {
                simp += 4.0 * sin(arg);
            }
            arg += h;
        }
        cout << n << " " << simp * h / 3 << endl;
    }



}
