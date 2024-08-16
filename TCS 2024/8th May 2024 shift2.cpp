Q1.

You are given a list of integers. Your task is to replace each element in the list based on the following rules:

If the element is divisible by 3, replace it with the string "Three".
If the element is divisible by 5, replace it with the string "Five".
If the element is divisible by both 3 and 5, replace it with the string "ThreeFive".
If the element does not satisfy any of the above conditions, keep the element as it is.

Input:
[2, 3, 4, 5]

Output:
[2, "Three", 4, "Five"]

  =======================Solution ===================================

#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> replaceElements(vector<int> &arr) {
    vector<string> result;

    for (int num : arr) {
        if (num % 3 == 0 && num % 5 == 0) {
            result.push_back("ThreeFive");
        } else if (num % 3 == 0) {
            result.push_back("Three");
        } else if (num % 5 == 0) {
            result.push_back("Five");
        } else {
            result.push_back(to_string(num));
        }
    }

    return result;
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<string> result = replaceElements(arr);

    cout << "Output: ";
    for (const string &s : result) {
        cout << s << " ";
    }
    cout << endl;

    return 0;
}

-----------------------------------<>--Question --<>----------------------------------------
Q2.
Task 1- print the collatz sequence upto ending with 1 the sequence should be in the following way
if the number is even:
if the number is Odd:
This sequence should end until the last element of sequence is 1
Task-2
For the given integer from it should calculate the sequence Of each k value I.e,
Calculate the maximum length of sequence list of each k value and return the maximum length of the sequence list of the k value
and the k value itself
Task-3
For the given integer from I.n it should calculate the sequence of each k value (e,
Calculate the maximum value of the each sequence within the sequence list of each k value
and return the maximum value of the sequence list of the k value and those k value itself
Input: 5
Output:
16,3
Input: O
Output: Error!
Input: xyza
output: Error!
Input:-13
Output: Error!
Input: 5.5

  -----------------------Solution -----------------------------------------

  #include <iostream>
#include <cmath>
#include <limits>
#include <cstdlib>
#include <sstream>
using namespace std;

// Function to compute the Collatz sequence for a given integer
vector<int> collatzSequence(int k) {
    vector<int> sequence;
    while (k != 1) {
        sequence.push_back(k);
        if (k % 2 == 0) {
            k /= 2;
        } else {
            k = 3 * k + 1;
        }
    }
    sequence.push_back(1);
    return sequence;
}

// Function to find the maximum length of Collatz sequence from 1 to n
pair<int, int> maxLengthCollatz(int n) {
    int maxLength = 0;
    int maxK = 0;

    for (int i = 1; i <= n; i++) {
        vector<int> seq = collatzSequence(i);
        if (seq.size() > maxLength) {
            maxLength = seq.size();
            maxK = i;
        }
    }

    return {maxLength, maxK};
}

// Function to find the maximum value in Collatz sequence from 1 to n
pair<int, int> maxValueCollatz(int n) {
    int maxValue = 0;
    int maxK = 0;

    for (int i = 1; i <= n; i++) {
        vector<int> seq = collatzSequence(i);
        int currentMax = *max_element(seq.begin(), seq.end());
        if (currentMax > maxValue) {
            maxValue = currentMax;
            maxK = i;
        }
    }

    return {maxValue, maxK};
}

int main() {
    string input;
    cout << "Enter a positive integer: ";
    cin >> input;

    // Validate input
    stringstream ss(input);
    int n;
    if (!(ss >> n) || n <= 0) {
        cout << "Error!" << endl;
        return 1;
    }

    cout << "Collatz sequence for " << n << ": ";
    vector<int> sequence = collatzSequence(n);
    for (int num : sequence) {
        cout << num << " ";
    }
    cout << endl;

    pair<int, int> maxLength = maxLengthCollatz(n);
    cout << "Maximum length of Collatz sequence: " << maxLength.first << ", k = " << maxLength.second << endl;

    pair<int, int> maxValue = maxValueCollatz(n);
    cout << "Maximum value in Collatz sequence: " << maxValue.first << ", k = " << maxValue.second << endl;

    return 0;
}


  
