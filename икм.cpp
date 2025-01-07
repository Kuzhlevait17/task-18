#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <windows.h>

using namespace std;

// Функция для проверки, является ли строка допустимым числом
bool isValidNumber(const string& str) {
    for (char c : str) {
        // Проверяем, является ли символ цифрой
        if (c < '0' || c > '9') {
            return false; // Если хотя бы один символ не цифра, возвращаем false
        }
    }
    return true;
}

// Функция для преобразования строки в целое число
int stringToInt(const string& str) {
    int result = 0;
    for (char c : str) {
        result = result * 10 + (c - '0'); // Преобразуем символ в число и добавляем его в результат
    }
    return result;
}

// Умножаем большое число, хранящееся в векторе, на x
// Каждая цифра числа хранится в векторе в обратном порядке (0-й элемент — младшая цифра)
void multiply(vector<int>& number, int x) {
    int carry = 0; // Переменная для хранения переноса
    for (size_t i = 0; i < number.size(); ++i) {
        int product = number[i] * x + carry; // Умножаем текущую цифру и добавляем перенос
        number[i] = product % 10;           // Сохраняем младшую цифру результата в текущую позицию
        carry = product / 10;               // Остаток записываем как перенос
    }
    // Добавляем оставшийся перенос, если он есть
    while (carry > 0) {
        number.push_back(carry % 10);
        carry /= 10;
    }
}

// Вычисляем факториал числа n
// Результат сохраняется как массив цифр (в обратном порядке)
vector<int> factorial(int n) {
    vector<int> result(1, 1); // Начинаем с факториала 1, т.е. результата 1
    for (int i = 2; i <= n; ++i) {
        multiply(result, i); // Умножаем текущее значение на i
    }
    return result;
}

// Функция вывода числа, хранящегося в векторе, в прямом порядке
void printNumber(const vector<int>& number) {
    for (int i = number.size() - 1; i >= 0; --i) {
        cout << number[i];
    }
    cout << endl;
}

// Умножаем два больших числа, представленных строками
// Это более общий метод, который будет использован для вычисления факториала Карацубы
string multiplyLargeNumbers(const string& num1, const string& num2) {
    int len1 = num1.size(), len2 = num2.size();
    vector<int> result(len1 + len2, 0); // Результат умножения: длина = сумма длин чисел

    // Умножаем каждую цифру числа num1 на каждую цифру числа num2
    for (int i = len1 - 1; i >= 0; --i) {
        for (int j = len2 - 1; j >= 0; --j) {
            int product = (num1[i] - '0') * (num2[j] - '0') + result[i + j + 1];
            result[i + j + 1] = product % 10; // Сохраняем младшую цифру
            result[i + j] += product / 10;    // Добавляем перенос
        }
    }

    // Преобразуем результат в строку
    string resultStr;
    bool leadingZero = true; // Флаг для пропуска ведущих нулей

    for (int num : result) 
    {
        if (num != 0 || !leadingZero) { // Пропускаем ведущие нули
            resultStr += (num + '0');   // Преобразуем цифру в символ и добавляем
            leadingZero = false;       // После первой цифры отключаем флаг
        }

    }

    if (resultStr.empty())
    {
            return "0"; // Если строка пустая, возвращаем "0"
    }
    return resultStr; // В противном случае возвращаем результат
}

// Вычисляем факториал числа n, используя метод Карацубы
// Функция умножает числа, разбивая их на пары
string factorialKaratsuba(int n) {
    if (n == 1) return "1"; // Базовый случай для факториала 1

    // Создаем список всех чисел от 1 до n в виде строк
    vector<string> numbers;
    for (int i = 1; i <= n; ++i) {
        string numStr;
        int temp = i;
        while (temp > 0) {
            char digit = (temp % 10) + '0'; // Получаем текущую цифру
            numStr = digit + numStr;       // Добавляем её в начало строки
            temp /= 10;                    // Убираем младшую цифру
        }
        numbers.push_back(numStr);
    }
   

    // Постепенно объединяем числа попарно
    while (numbers.size() > 1) {
        vector<string> newNumbers; // Новый уровень объединения чисел
        for (size_t i = 0; i < numbers.size(); i += 2) {
            if (i + 1 < numbers.size()) {
                // Умножаем пары чисел
                newNumbers.push_back(multiplyLargeNumbers(numbers[i], numbers[i + 1]));
            }
            else {
                // Если число без пары, добавляем его как есть
                newNumbers.push_back(numbers[i]);
            }
        }
        numbers = newNumbers; // Переходим на следующий уровень объединения
    }
    return numbers[0]; // Возвращаем результат умножения
}

// преобразование из строки в число
int customStringToInt(const string& str) 
{
    int result = 0;
    // проходимся посимвольно по строке.
    for (char c : str) {
        result = result * 10 + (c - '0'); // Преобразуем символ в число
    }
    return result;
}

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
