# include <iostream>
# include <string>
# include <sstream>
# include <vector>
# include "problemsolving.h"
using namespace std;

// ������� ��� ��������, �������� �� ������ ���������� ������
bool isValidNumber(const string& str) {
    for (char c : str) {
        // ���������, �������� �� ������ ������
        if (c < '0' || c > '9') {
            return false; // ���� ���� �� ���� ������ �� �����, ���������� false
        }
    }
    return true;
}

// ������� ��� �������������� ������ � ����� �����
int stringToInt(const string& str) {
    int result = 0;
    for (char c : str) {
        result = result * 10 + (c - '0'); // ����������� ������ � ����� � ��������� ��� � ���������
    }
    return result;
}

// �������� ������� �����, ���������� � �������, �� x
// ������ ����� ����� �������� � ������� � �������� ������� (0-� ������� � ������� �����)
void multiply(vector<int>& number, int x) {
    int carry = 0; // ���������� ��� �������� ��������
    for (size_t i = 0; i < number.size(); ++i) {
        int product = number[i] * x + carry; // �������� ������� ����� � ��������� �������
        number[i] = product % 10;           // ��������� ������� ����� ���������� � ������� �������
        carry = product / 10;               // ������� ���������� ��� �������
    }
    // ��������� ���������� �������, ���� �� ����
    while (carry > 0) {
        number.push_back(carry % 10);
        carry /= 10;
    }
}

// ��������� ��������� ����� n
// ��������� ����������� ��� ������ ���� (� �������� �������)
vector<int> factorial(int n) 
{
    vector<int> result(1, 1); // �������� � ���������� 1, �.�. ���������� 1
    for (int i = 2; i <= n; ++i) {
        multiply(result, i); // �������� ������� �������� �� i
    }
    return result;
}

// ������� ������ �����, ����������� � �������, � ������ �������
void printNumber(const vector<int>& number) {
    for (int i = number.size() - 1; i >= 0; --i) {
        cout << number[i];
    }
    cout << endl;
}

// �������� ��� ������� �����, �������������� ��������
// ��� ����� ����� �����, ������� ����� ����������� ��� ���������� ���������� ��������
string multiplyLargeNumbers(const string& num1, const string& num2) {
    int len1 = num1.size(), len2 = num2.size();
    vector<int> result(len1 + len2, 0); // ��������� ���������: ����� = ����� ���� �����

    // �������� ������ ����� ����� num1 �� ������ ����� ����� num2
    for (int i = len1 - 1; i >= 0; --i) {
        for (int j = len2 - 1; j >= 0; --j) {
            int product = (num1[i] - '0') * (num2[j] - '0') + result[i + j + 1];
            result[i + j + 1] = product % 10; // ��������� ������� �����
            result[i + j] += product / 10;    // ��������� �������
        }
    }

    // ����������� ��������� � ������
    string resultStr;
    bool leadingZero = true; // ���� ��� �������� ������� �����

    for (int num : result)
    {
        if (num != 0 || !leadingZero) { // ���������� ������� ����
            resultStr += (num + '0');   // ����������� ����� � ������ � ���������
            leadingZero = false;       // ����� ������ ����� ��������� ����
        }

    }

    if (resultStr.empty())
    {
        return "0"; // ���� ������ ������, ���������� "0"
    }
    return resultStr; // � ��������� ������ ���������� ���������
}

// ��������� ��������� ����� n, ��������� ����� ��������
// ������� �������� �����, �������� �� �� ����
string factorialKaratsuba(int n) {
    if (n == 1) return "1"; // ������� ������ ��� ���������� 1

    // ������� ������ ���� ����� �� 1 �� n � ���� �����
    vector<string> numbers;
    for (int i = 1; i <= n; ++i) {
        string numStr;
        int temp = i;
        while (temp > 0) {
            char digit = (temp % 10) + '0'; // �������� ������� �����
            numStr = digit + numStr;       // ��������� � � ������ ������
            temp /= 10;                    // ������� ������� �����
        }
        numbers.push_back(numStr);
    }


    // ���������� ���������� ����� �������
    while (numbers.size() > 1) {
        vector<string> newNumbers; // ����� ������� ����������� �����
        for (size_t i = 0; i < numbers.size(); i += 2) {
            if (i + 1 < numbers.size()) {
                // �������� ���� �����
                newNumbers.push_back(multiplyLargeNumbers(numbers[i], numbers[i + 1]));
            }
            else {
                // ���� ����� ��� ����, ��������� ��� ��� ����
                newNumbers.push_back(numbers[i]);
            }
        }
        numbers = newNumbers; // ��������� �� ��������� ������� �����������
    }
    return numbers[0]; // ���������� ��������� ���������
}

// �������������� �� ������ � �����
int customStringToInt(const string& str)
{
    int result = 0;
    // ���������� ����������� �� ������.
    for (char c : str) {
        result = result * 10 + (c - '0'); // ����������� ������ � �����
    }
    return result;
}