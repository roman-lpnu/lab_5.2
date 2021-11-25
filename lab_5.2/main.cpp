// Лабораторна робота No 5.2
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;


double A(const double x, const int n);

double S(const double x, const double eps, int &n) {
    n = 0;//вираз залежить від умови завдання
    double a = M_PI/ 2;//вираз залежить від умови завдання
    double s = a;
    while (abs(a) >= eps) {
        a = A(x, n);
        s += a;
        n++;
    }
    return s;
}

int main() {
    double xp, xk, x, dx, eps, s = 0;
    int n = 0;
    cout << "xp = ";
    cin >> xp;
    cout << "xk = ";
    cin >> xk;
    cout << "dx = ";
    cin >> dx;
    cout << "eps = ";
    cin >> eps;
    cout << fixed;
    cout << "-------------------------------------------------" << endl;
    cout << "|" << setw(5) << "x" << "     |"
         << setw(10) << "exp(x)" << "   |"
         << setw(7) << "S" << "      |"
         << setw(5) << "n" << "   |" <<
         endl;
    cout << "-------------------------------------------------" << endl;
    x = xp;
    while (x <= xk) {
        s = S(x, eps, n);
        cout << "|" << setw(7) << setprecision(2) << x << " |"
             << setw(10) << setprecision(5) << (M_PI/ 2) - atan(x) << " |"
             << setw(10) << setprecision(5) << s << " |"
             << setw(5) << n << " |"
             << endl;
        x += dx;
    }
    cout << "-------------------------------------------------" << endl;
    return 0;
}


double A(const double x, const int n) {
    double R = (pow(-1, n + 1) * pow(x, 2 * n + 1)) / (2 * n + 1);//вираз залежить від умови завдання
    return R;
}