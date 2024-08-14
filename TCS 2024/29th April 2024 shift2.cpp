Q1.
  Calculate the sum of n term of fibonacci series 
input - 5
output - 7

-----------------------------------------Solution----------------------------------------------------------
#include <iostream>
using namespace std;

int fibonacciSum(int n) {
    if (n <= 0) return 0; 
    if (n == 1) return 1;
    int a = 0, b = 1;
    int sum = a + b;  
    for (int i = 2; i < n; ++i) {
        int next = a + b; 
        sum += next;     
        a = b;           
        b = next;        
    }

    return sum;
}

int main() {
    int n;
    cout << "Enter number: ";
    cin >> n;

    cout << "Sum is: " << fibonacciSum(n) << endl;
    return 0;
}

=====> Related Question:-
#include<bits/stdc++.h>
using namespace std;

  int fibonacciSum(int n){
    if(n==0 || n==1){
        return n;
    }
    return fibonacciSum(n-1)+fibonacciSum(n-2);
}


int main(){
    int n;
    cout<<"enter number: ";
    cin>>n;
    
    cout<<"Sum is: "<<fibonacciSum(n);
    return 0;
}


------------------------------<>---------------<>--------Question 3-----------------<>--------------------<>----------

Q2. Leetcode 898
  Given an integer array arr, return the number of distinct bitwise ORs of all the non-empty subarrays of arr.
The bitwise OR of a subarray is the bitwise OR of each integer in the subarray. The bitwise OR of a subarray of one integer
is that integer. A subarray is a contiguous non-empty sequence of elements within an array.

Example 1:
Input: arr = [0]
Output: 1
Explanation: There is only one possible result: 0.

-------------------------------------------Solution ----------------------------------------------------------------

class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> distinctOrs;  
        unordered_set<int> currentOrs;   

        for (int num : arr) {
            unordered_set<int> newOrs;
            newOrs.insert(num);  

            for (int prevOr : currentOrs) {
                newOrs.insert(prevOr | num);
            }

            distinctOrs.insert(newOrs.begin(), newOrs.end());
            currentOrs = newOrs;
        }

        return distinctOrs.size();
    }
};





