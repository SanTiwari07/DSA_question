#include <iostream>

using namespace std;

long long factorial(int n) {
    
    if (n == 0) {
        return 1;
    }
    
    return (long long)n * factorial(n - 1);
}

int main() {
    cout << "--- Factorial of Given No (Recursive) ---" << endl;

    int number = 5;
    cout << "The number is: " << number << endl;

    long long result = factorial(number);

    cout << "The factorial of " << number << " is: " << result << endl;
    
    number = 7;
    result = factorial(number);
    cout << "The factorial of " << number << " is: " << result << endl;

    return 0;
}
