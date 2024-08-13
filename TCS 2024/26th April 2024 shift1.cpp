Q1. 
Find a Subarray with Given Sum (Including Negative Numbers)
Problem Statement:
Given an array of integers (which can include negative numbers), find a continuous subarray that sums to a given number S. If there are multiple subarrays, return all subarray.

<><><><><>------------------------------------ ---------------- SOLUTION  -----------------------------------------------------------------------------<><><><><><>----------

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> findSubarrayWithSum(const vector<int>& arr, int S) {
    unordered_map<int, int> sumMap;
    int currentSum = 0;

    for (int i = 0; i < arr.size(); ++i) {
        currentSum += arr[i];

        if (currentSum == S) {
            return vector<int>(arr.begin(), arr.begin() + i + 1);
        }

        if (sumMap.find(currentSum - S) != sumMap.end()) {
            int startIndex = sumMap[currentSum - S] + 1;
            return vector<int>(arr.begin() + startIndex, arr.begin() + i + 1);
        }

        sumMap[currentSum] = i;
    }

    return vector<int>();
}

void printVector(const vector<int>& vec) {
    for (int num : vec) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    int n, S;
    
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector<int> arr(n);
    
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cout << "Enter the desired sum S: ";
    cin >> S;

    vector<int> result = findSubarrayWithSum(arr, S);

    if (!result.empty()) {
        cout << "Subarray with sum " << S << " is: ";
        printVector(result);
    } else {
        cout << "No subarray with sum " << S << " found." << endl;
    }

    return 0;
}

--------------------------<>--------------------------------<>------------qUESTION 2 -------------------------<>---------------------------------------<>--------------------------------

Q2. Leetcode 62

There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner
(i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.
Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the bottom-right corner.
The test cases are generated so that the answer will be less than or equal to 2 * 109.
Example 1:
Input: m = 3, n = 7
Output: 28


<><><><><>----------------------------------SOLUTION-----------------------------------------<><><>><><><>-------------------------------------------

#include <iostream>
#include <vector>
using namespace std;

int uniquePaths(int m, int n) {
    vector<vector<int>> dp(m, vector<int>(n, 1));

    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }

    return dp[m - 1][n - 1];
}

int main() {
    int m, n;

    cout << "Enter the number of rows (m): ";
    cin >> m;
    cout << "Enter the number of columns (n): ";
    cin >> n;

    int result = uniquePaths(m, n);
    cout << "Number of unique paths: " << result << endl;

    return 0;
}






