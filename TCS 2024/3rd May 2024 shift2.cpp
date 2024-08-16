Q1. 
  A person has a collection of shoes of different sizes, with each shoe being either a left shoe (L) or a right shoe (R). 
The goal is to determine the number of pairs of shoes that can be formed. A pair is defined as a left shoe (L) and a right shoe
(R) of the same size.

Input:
n = 8
shoes[] = {"7L", "7R", "7L", "8R", "6L", "8L", "6R"}

Output:
3

===================Solution========================================

#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
using namespace std;

int countShoePairs(const vector<string> &shoes) {
    unordered_map<string, int> leftShoes;
    unordered_map<string, int> rightShoes;
    int pairs = 0;

    for (const string &shoe : shoes) {
        string size = shoe.substr(0, shoe.size() - 1);
        char type = shoe.back();

        if (type == 'L') {
            if (rightShoes[size] > 0) {
                pairs++;
                rightShoes[size]--;
            } else {
                leftShoes[size]++;
            }
        } else if (type == 'R') {
            if (leftShoes[size] > 0) {
                pairs++;
                leftShoes[size]--;
            } else {
                rightShoes[size]++;
            }
        }
    }

    return pairs;
}

int main() {
    int n = 8;
    vector<string> shoes = {"7L", "7R", "7L", "8R", "6L", "8L", "6R"};

    int result = countShoePairs(shoes);
    cout << "Number of pairs: " << result << endl;

    return 0;
}

------------------------------<>------------Question-2--------------<>----------------------------------------
Q2. in a company there are employees and their efficiency is given in aryay_årr' (can be negative) you need to find the
maximum efficiency of 3 employees. The efficiency of 3 employees will be calculated by multiplying their individual efficiencies 
from the given array.

Example 1:
Input:
arr = [3, -2, -8, 4, 1]

Output:
64

-------------------------------Solution-------------------------------------------

  #include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int maxProductOfThree(vector<int>& arr) {
    // Sort the array
    sort(arr.begin(), arr.end());

    int n = arr.size();

    // Calculate the maximum product of the three largest numbers
    int maxProduct1 = arr[n - 1] * arr[n - 2] * arr[n - 3];

    // Calculate the maximum product of the two smallest numbers and the largest number
    int maxProduct2 = arr[0] * arr[1] * arr[n - 1];

    // Return the maximum of the two products
    return max(maxProduct1, maxProduct2);
}

int main() {
    int n;
    cout << "Enter the number of employees: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the efficiency of employees:" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    int result = maxProductOfThree(arr);
    cout << "Maximum efficiency of 3 employees: " << result << endl;

    return 0;
}

