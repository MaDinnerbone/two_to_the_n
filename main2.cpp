/* two_to_the_n - A C++ program that computes 2 to the NTH power, 
 * where n is very large
 * 
 * Copyright (C) 2024  Dinnerb0ne<tomma_2022@outlook.com>
 * github: MaDinnerbone https://github.com/MaDinnerbone/two_to_the_n
 * 
 * This agreement follows the MIT LICENSE and is in force by law
 * LICENSE file : two_to_the_n/LICENSE
 * 
*/


#include <iostream>
#include <string>
#include <cstdio>
#include <ctime>
#include <algorithm>

std::string multiply_by_two(const std::string& num) {
    std::string result;
    int carry = 0; // 初始化进位为0
    for (size_t i = 0; i < num.size(); ++i) {
        int digit = (num[num.size() - 1 - i] - '0') * 2 + carry;
        result += (digit % 10) + '0'; // 乘2后得到的个位数加到结果字符串的前面
        carry = digit / 10; // 计算新的进位
    }
    if (carry > 0) {
        result += (carry + '0'); // 如果有进位，加到结果字符串的前面
    }
    std::reverse(result.begin(), result.end()); // 反转字符串,得到正确的顺序
    return result;
}

std::string power_of_two_to_string(int n) {
    std::string result = "1";
    for (int i = 0; i < n; ++i) {
        result = multiply_by_two(result);
    }
    return result;
}

int main() {
    int input;
    std::cout << "Please input n (2^n) : ";
    std::cin >> input;

    printf("Your input is : %d\n", input);

    clock_t start = clock();

    std::string power_of_two = power_of_two_to_string(input);
    std::cout << "2^" << input << " = " << power_of_two << std::endl;

    clock_t end = clock();
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC * 1000; // 注意这里是CLOCKS_PER_SEC，不需要除以1000
    std::cout << "Timer ended. Time spent: " << time_spent << " ms" << std::endl;

    system("pause");
    return 0;
}