#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    // Константы
    const double g = 9.8;    // ускорение свободного падения, м/с²
    const double v_sound = 330;  // скорость звука, м/с
    
    double t, h, t_sound;
    
    // ввод
    cout << "Введите общее время (в секундах) от момента падения камня до момента слышимости удара: ";
    cin >> t;
    
    // Используем формулу: sqrt(2h/g) + h/v_sound = t
    // После преобразований получаем: 0.003h² + 0.45sqrt(h) - t = 0
    
    // Вводим замену y = sqrt(h)
    double a = 0.003;
    double b = 0.45;
    double c = -t;
    
    // Решаем квадратное уравнение ay² + by + c = 0
    double D = b*b - 4*a*c;
    if (D < 0) {
        cout << "Ошибка: невозможно рассчитать глубину шахты" << endl;
        return 1;
    }
    
    double y1 = (-b + sqrt(D)) / (2*a);
    h = y1 * y1;  // Возвращаем замену
    

    
    //вывод
    cout << endl;
    cout << "Результаты расчета:" << endl;
    cout << fixed << setprecision(2);
    cout << "Глубина шахты: " << h << " метров" << endl;

    
    return 0;
}