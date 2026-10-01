#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double f(double x)
{
    return x * x * cos(2.0 * x) + 0.2;
}

int main()
{
    double a = 0.88;
    double b = 0.98;
    const double eps = 0.005;

    double c;
    double beg_value, end_value;
    int n = 0;

    do
    {
        c = (a + b) / 2.0;

        beg_value = f(a);
        end_value = f(c);

        if (beg_value * end_value <= 0)
            b = c;
        else
            a = c;

        cout << n << ": a = " << a
            << "; b = " << b
            << "; c = " << c << endl;

        cout << "beg: " << beg_value
            << " end: " << end_value << endl << endl;

        n++;

    } while (fabs(a - b) > eps);

    cout << endl << fixed << setprecision(6);
    cout << "Result: " << (a + b) / 2.0 << endl;
    cout << "Iterations: " << n << endl;

    return 0;
}