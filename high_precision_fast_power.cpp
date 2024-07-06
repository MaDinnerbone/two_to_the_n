#include <iostream>
#include <string>
#include <ctime>
#include <algorithm>

using namespace std;

// str反转
void reverse_str(string &s) {
    int n = s.size();
    for (int i = 0; i < n / 2; i++) {
        swap(s[i], s[n - i - 1]);
    }
}

// str加法
string big_add(string num1, string num2) {

    int carry = 0;
    int n1 = num1.size(), n2 = num2.size();
    string result;
    
    while (n1 > 0 || n2 > 0) {

        int digit1 = n1 > 0 ? num1[n1 - 1] - '0' : 0;
        int digit2 = n2 > 0 ? num2[n2 - 1] - '0' : 0;
        int sum = digit1 + digit2 + carry;

        result.push_back(sum % 10 + '0');
        carry = sum / 10;
        
        n1--;
        n2--;
    }
    
    if (carry > 0) {result.push_back(carry + '0');}
    
    reverse_str(result);
    return result;
}

// str乘单个数字
string big_multiply_by_digit(string num, int digit) {
    int carry = 0;
    string result;
    
    for (char &ch : num) {
        int prod = (ch - '0') * digit + carry;
        ch = prod % 10 + '0';
        carry = prod / 10;
    }
    
    if (carry > 0) { num.push_back(carry + '0');}
    
    return num;
}

string big_multiply(string num1, string num2) {
    string result(num1.size() + num2.size(), '0');
    
    // 从个位逐位乘
    for (int i = num1.size() - 1; i >= 0; i--) {
        for (int j = num2.size() - 1; j >= 0; j--) {
            int sum = (num1[i] - '0') * (num2[j] - '0') + (result[i + j + 1] - '0');
            result[i + j] += sum / 10;
            result[i + j + 1] = (sum) % 10 + '0';
        }
    }

    while (result.size() > 1 && result[0] == '0') {
        result.erase(0, 1);
    }// 去0
    
    reverse_str(result);
    return result;
}

// 高精度快速幂
string fast_power(string base, int exponent) {
    string result("1");
    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result = big_multiply(result, base); // 使用字符串乘法
        }
        base = big_multiply(base, base); // 使用字符串乘法
        exponent /= 2;
    }
    return result;
}

int main() {
    string base;
    int exponent;
    cout << "Base (n): ";
    cin >> base;
    cout << "Exponent (m): ";
    cin >> exponent;
    
    clock_t start = clock();

    cout << base << " raised to the power of " << exponent << " is: " << fast_power(base, exponent) << endl;
    
    clock_t end = clock();
    double time_spent = static_cast<double>(end - start) / CLOCKS_PER_SEC; // 直接用 CLOCKS_PER_SEC
    std::cout << "Timer ended. Time spent: " << time_spent << " ms" << std::endl;

    return 0;
}