Strong Numbers are the numbers whose sum of factorial of digits i
equal to the original number. Given a number, check if it is a Strong
Number or not.
Examples:
Input : n = 145
Output : Yes
Sum of digit factorials
1! + 4! + 5! = 1+ 24+ 120= 145
Input: n = 534
Output : No


==========================Solution:=========================

#include <iostream>
using namespace std;

int factorial(int num) {
    if (num == 0 || num == 1) {
        return 1;
    }
    return num * factorial(num - 1);
}

bool isStrong(int n) {
    int num1 = n;
    int sum = 0;
    
    while (n > 0) {
        int rem = n % 10;
        sum += factorial(rem);
        n /= 10;
    }
    
    return num1 == sum;
}

int main() {
    int n;
    cin >> n;  
    
    cout << isStrong(n) << endl;
    
    return 0;
}
