#include <iostream>
#include <cmath>
using namespace std;

double vichisl_y(double x) {
    if (x < -1) {
        return pow(x, 6) * log10(pow(6, x) - pow(abs(x - 5), x));
    } else if (x >= -1 && x < 1) {
        return sin(x / (1 - 2 * pow(x, 2)));
    } else {
        return asin(1 / pow(x, 4));
    }
}

int main() {
    double x;
    cout << "Введите значение x: ";
    cin >> x;

    double y = vichisl_y(x);
    cout << "Значение функции y(x) = " << y << endl;

    return 0;
}