#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <windows.h>
#include "problemsolving.h"
using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << endl;
    cout << "--------------------------------------------------------" << endl;
    cout << "               Добро пожаловать в программу!" << endl;
    cout << "--------------------------------------------------------" << endl;
    cout << endl;
    cout << "Этот инструмент поможет вам вычислить факториал числа (n!)." << endl;
    cout << "Где n — это целое положительное число, большее или равное 3." << endl;
    cout << "Факториал числа — это произведение всех чисел от 1 до n." << endl;
    cout << "Введите число, и программа постарается вычислить значение (n!)." << endl;
    cout << endl;
    cout << "--------------------------------------------------------" << endl;
    cout << endl;

    cout << "ВАЖНАЯ ИНФОРМАЦИЯ!" << endl;
    cout << "Перед тем, как выбрать число n, обратите внимание на несколько важных моментов:" << endl;
    cout << "• Значения факториалов растут очень быстро." << endl;
    cout << "• Например, значение (8!)! содержит 168 187 цифр!" << endl;
    cout << "• Вычисление некоторых факториалов (например, (n!)!) может занять очень много времени," << endl;
    cout << "  вплоть до бесконечности, в зависимости от значения n." << endl;
    cout << "• Если программа не отобразит результат в течение 10 минут, стоит прекратить вычисления." << endl;
    cout << endl;
    cout << "Спасибо за внимание!" << endl;
    cout << "--------------------------------------------------------" << endl;
    cout << endl;

    int n;
    string input;

    bool validInput = false; // Флаг для проверки корректности ввода

    while (!validInput) {
        cout << "Введите число n (n >= 3): ";
        getline(cin, input);

        // Проверяем, является ли строка допустимым числом
        if (isValidNumber(input)) {
            // Преобразуем строку в число без использования stoi
            n = stringToInt(input);

            if (n >= 3) {
                validInput = true; // Все условия выполнены, завершаем цикл
            }
            else {
                cout << "Число должно быть больше или равно 3." << endl;
            }
        }
        else {
            cout << "Ошибка! Введите целое положительное число." << endl;
        }
    }

    // Этап 1: Вычисляем первый факториал n!
    vector<int> firstFactorial = factorial(n);
    cout << "Значение внутреннего факториала n!: ";
    printNumber(firstFactorial);

    // Преобразуем результат первого факториала в строку
    string factorialValueStr;
    for (int i = firstFactorial.size() - 1; i >= 0; --i) {
        factorialValueStr += (firstFactorial[i] + '0');
    }

    // Этап 2: Вычисляем (n!)! с использованием метода Карацубы
    cout << "Вычисляем (n!)! ..." << endl;
    int factorialAsInt = customStringToInt(factorialValueStr); // преобразуем строки в цифры.
    string result = factorialKaratsuba(factorialAsInt);
    cout << "Значение (n!)!: " << result << endl;

    return 0;
}