#include<cmath>
#include<ctime>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<iostream>

std::string multiplyByTwo(const std::string& num) {
    std::string result = "0";
    for (size_t i = 0; i < num.size(); ++i) {
        int digit = (num[i] - '0') * 2;
        result += (digit % 10) + '0';  // Store the last digit of the result
        if (digit >= 10) {
            result[num.size() - i - 1] += 1;  // Carry over to the next digit
        }
    }
    return result;
}

std::string powerOfTwoToString(int n) {
    if (n == 0) return "1";
    std::string result = "2";
    while (n > 1) {
        result = multiplyByTwo(result);
        --n;
    }
    return result;
}

int main() {
    int input;
    std::cout << "Please input n (2^n) : ";
    std::cin >> input;

	printf("Your input is : &d\n", input);
	
	
	clock_t start = clock();

    std::cout << "2^" << input << " = \n" << powerOfTwoToString(input) << std::endl;
	
	clock_t end = clock();
	
	printf("\n\n\n");
	
	double time_spent = (double)(end - start) / CLOCKS_PER_SEC / 1000;
    std::cout << "Timer ended. Time spent: " << time_spent << " ms" << std::endl;
	system("pause");
    return 0;
}