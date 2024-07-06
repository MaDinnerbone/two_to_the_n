#include <iostream>
#include <string>
#include <ctime>
#include <algorithm>
#include <chrono>

using namespace std;

// str加法
string big_add(const string &num1, const string &num2) {
    string result;
    int carry = 0, n1 = num1.size(), n2 = num2.size();
    while (n1 > 0 || n2 > 0) {
        int digit1 = n1 > 0 ? num1[n1 - 1] - '0' : 0;
        int digit2 = n2 > 0 ? num2[n2 - 1] - '0' : 0;
        int sum = digit1 + digit2 + carry;
        result.push_back(sum % 10 + '0');
        carry = sum / 10;
        n1--; n2--;
    }
    if (carry > 0) result.push_back(carry + '0');
    reverse(result.begin(), result.end());
    return result;
}

// str乘单个数字
string big_multiply_by_digit(const string &num, int digit) {
    string result;
    int carry = 0;
    for (int i = num.size() - 1; i >= 0; --i) {
        int prod = (num[i] - '0') * digit + carry;
        result.push_back(prod % 10 + '0');
        carry = prod / 10;
    }
    if (carry > 0) result.push_back(carry + '0');
    reverse(result.begin(), result.end());
    return result;
}

// str乘法
string big_multiply(const string &num1, const string &num2) {
    string result(num1.size() + num2.size(), '0');
    for (size_t i = num1.size(); i-- > 0;) {
        for (size_t j = num2.size(); j-- > 0;) {
            int sum = (num1[i] - '0') * (num2[j] - '0') + (result[i + j + 1] - '0');
            result[i + j] += sum / 10;
            result[i + j + 1] = sum % 10 + '0';
        }
    }
    while (!result.empty() && result.front() == '0') result.erase(0, 1);
    return result;
}

// 高精度快速幂
string fast_power(const string& base, int exponent) {
    string result("1");  // 初始化 1
    string temp_base = base;  // 用局部变量存 base 
    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result = big_multiply(result, temp_base);  // 用str乘法
        }
        temp_base = big_multiply(temp_base, temp_base);  // 用str乘法
        exponent /= 2;
    }
    return result;
}

int main() {
    string  base, 
            exponent_str;

    cout << "Base (n): ";

    getline(cin, base);
    cout << "Exponent (m): ";
    cin >> exponent_str;

    int exponent = stoi(exponent_str);

    auto start = chrono::high_resolution_clock::now();

    cout << base << " raised to the power of " << exponent << " is: " << fast_power(base, exponent) << endl;

    auto end = chrono::high_resolution_clock::now();
    double time_spent = chrono::duration<double, milli>(end - start).count();

    cout << "Timer ended. Time spent: " << time_spent << " ms" << endl;

    return 0;
}