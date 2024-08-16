Q1.

Input:
An array arr of size N-1 containing integers in the range [1, N] with no duplicates.
Output:
The missing integer from the range [1, N].

Input: arr = [1, 2, 4, 6, 3, 7, 8]
Output: 5

--------------------Solution-------------------------------------

#include <iostream>
#include <vector>
using namespace std;

int findMissingNumber(vector<int>& arr, int N) {
    int sum_N = N * (N + 1) / 2;

    int actual_sum = 0;
    for (int num : arr) {
        actual_sum += num;
    }

    return sum_N - actual_sum;
}

int main() {
    int N;
    cout << "Enter the value of N: ";
    cin >> N;

    vector<int> arr(N-1);
    cout << "Enter the elements of the array:" << endl;
    for (int i = 0; i < N-1; ++i) {
        cin >> arr[i];
    }

    int missingNumber = findMissingNumber(arr, N);
    cout << "The missing number is: " << missingNumber << endl;

    return 0;
}


==================================Question 2===============================================================
Q2. 

Write a program that accepts n and m, and prints all prime numbers such that the sum of their digits is
also a prime number.

Input: n = 10, m = 50
Output: 11, 23, 29, 41, 43, 47

---------------------------------Solution-----------------------------------

#include <iostream>
using namespace std;

bool isPrime(int num) {
    if (num <= 1) return false;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

int sumOfDigits(int num) {
    int sum = 0;
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

void findSpecialPrimes(int n, int m) {
    for (int i = n; i <= m; i++) {
        if (isPrime(i) && isPrime(sumOfDigits(i))) {
            cout << i << " ";
        }
    }
    cout << endl;
}

int main() {
    int n, m;
    cout << "Enter the range n and m: ";
    cin >> n >> m;

    findSpecialPrimes(n, m);

    return 0;
}

