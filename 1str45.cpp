#include <iostream>
#include <cmath>
using namespace std;

// Функция для поиска элементов
void findElements(int** array, int rows, int cols, int limit) {
    int count = 0; // счетчик подходящих элементов
    
    cout << "\nНайденные элементы:\n";
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            // Проверяем условия:
            // 1. Элемент неотрицательный
            // 2. Модуль разности индексов меньше заданного числа
            if(array[i][j] >= 0 && abs(i - j) < limit) {
                cout << "Элемент [" << i << "][" << j << "] = " << array[i][j] << endl;
                count++;
            }
        }
    }
    
    cout << "\nКоличество подходящих элементов: " << count << endl;
}

int main() {
    // Запрашиваем размеры массива
    int rows, cols;
    cout << "Введите количество строк: ";
    cin >> rows;
    
    cout << "Введите количество столбцов: ";
    cin >> cols;
    
    // Создаем динамический двумерный массив
    int** matrix = new int*[rows];
    for(int i = 0; i < rows; i++) {
        matrix[i] = new int[cols];
    }
    
    // Заполняем массив значениями
    cout << "\nВведите элементы массива:\n";
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            cout << "Элемент [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }
    
    // Вводим ограничение для разности индексов
    int limit;
    cout << "\nВведите ограничение для разности индексов: ";
    cin >> limit;
    
    // Вызываем функцию поиска
    findElements(matrix, rows, cols, limit);
    
    // Освобождаем выделенную память
    for(int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
    
    return 0;
}