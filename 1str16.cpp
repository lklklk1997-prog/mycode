#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

// Функция для проверки принадлежности точки области D
bool isInDomain(double x, double y) {
    // Область D - верхний полукруг радиуса 5 с центром в (0,0)
    return (x * x + y * y <= 25) && (y >= 0);
}

// Вычисление без math
double bezMath(double x) {
    double abs_x = (x >= 0) ? x : -x;
    double sqrt_abs_x = 1;
    
    // Приближенное вычисление корня через метод Ньютона
    for(int i = 0; i < 100; i++) {
        sqrt_abs_x = 0.5 * (sqrt_abs_x + abs_x / sqrt_abs_x);
    }
    
    double part1 = sqrt_abs_x / (sqrt_abs_x + 1);
    double arcsin_part = 0;
    
    // Приближенное вычисление арксинуса
    if(part1 >= -1 && part1 <= 1) {
        arcsin_part = part1 + (1/6)*pow(part1,3) + (3/40)*pow(part1,5);
    }
    
    double koren5_part = pow(x*x + 1, 1.0/5.0);
    double log_part = log(pow(2, sin(x)) + pow(abs_x, cos(x))) / log(2);
    
    return pow(arcsin_part, 5) + koren5_part + log_part;
}

// Вычисление функции с использованием math.h
double cherezMath(double x) {
    double abs_x = fabs(x);
    double sqrt_abs_x = sqrt(abs_x);
    
    double part1 = sqrt_abs_x / (sqrt_abs_x + 1);
    double arcsin_part = asin(part1);
    
    double koren5_part = pow(x*x + 1, 1.0/5.0);
    double log_part = log2(pow(2, sin(x)) + pow(abs_x, cos(x)));
    
    return pow(arcsin_part, 5) + koren5_part + log_part;
}

int main() {
    double x;
    
    cout << "Введите значение x: ";
    cin >> x;
    
    // Вычисление двумя способами
    double y1 = bezMath(x);
    double y2 = cherezMath(x);
    
    cout << fixed << setprecision(4);
    cout << "\nРезультаты вычислений:\n";
    cout << "Без math.h: y = " << y1 << endl;
    cout << "С math.h:  y = " << y2 << endl;
    
    // Проверка принадлежности области D
    bool result1 = isInDomain(x, y1);
    bool result2 = isInDomain(x, y2);
    
    cout << "\nПринадлежность области D:\n";
    cout << "Без math: " << (result1 ? "True" : "False") << endl;
    cout << "С math:  " << (result2 ? "True" : "False") << endl;
    
    return 0;
}