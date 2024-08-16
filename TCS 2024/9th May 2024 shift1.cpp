Q1.
Given an integer N, determine if it is an Armstrong number. An Armstrong number (also known as a Narcissistic number) is a 
number that is equal to the sum of its own digits each raised to the power of the number of digits.

Input
An integer N.
Output
Return true if N is an Armstrong number.
Return false otherwise.

======================================Solution========================================

#include <iostream>
#include <cmath>
using namespace std;

// Function to check if a number is an Armstrong number
bool isArmstrong(int num) {
    int originalNum = num;
    int sum = 0;
    int digits = 0;

    // Count the number of digits
    while (num > 0) {
        num /= 10;
        digits++;
    }

    num = originalNum;

    // Calculate the sum of each digit raised to the power of the number of digits
    while (num > 0) {
        int digit = num % 10;
        sum += pow(digit, digits);
        num /= 10;
    }

    // Check if the sum is equal to the original number
    return sum == originalNum;
}

int main() {
    // Input array
    int arr[] = {153, 371, 1081};
    int size = sizeof(arr) / sizeof(arr[0]);

    // Check each number and print Armstrong numbers
    for (int i = 0; i < size; i++) {
        if (isArmstrong(arr[i])) {
            cout << arr[i] << " ";
        }
    }

    return 0;
}


==================================Question 2==============================================
Q2. 

Top candidate need to be printed from the given
input.
Input format:
Jonn 85 Bob 92 Alice 110 Aditya
output:
Aditya: 110
Alice: 100
John: 90


  ==========================Solution ===============================

  #include <iostream>
#include <sstream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

// Function to parse input and find the top candidates
void findTopCandidates(const string& input) {
    stringstream ss(input);
    map<string, int> candidates;
    string name;
    int score;

    // Read names and scores from the input
    while (ss >> name >> score) {
        candidates[name] = score;
    }

    // Sort candidates by scores in descending order
    vector<pair<string, int>> sortedCandidates(candidates.begin(), candidates.end());
    sort(sortedCandidates.begin(), sortedCandidates.end(), [](const pair<string, int>& a, const pair<string, int>& b) {
        return a.second > b.second;
    });

    // Print top candidates
    for (const auto& candidate : sortedCandidates) {
        cout << candidate.first << ": " << candidate.second << endl;
    }
}

int main() {
    string input;
    cout << "Enter the candidates and scores: ";
    getline(cin, input);

    findTopCandidates(input);

    return 0;
}


  
