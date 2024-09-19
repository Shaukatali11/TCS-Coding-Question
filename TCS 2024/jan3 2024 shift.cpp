You are given an m x n integer grid accounts where accounts[i][j] is the amount of money the i​​​​​​​​​​​th​​​​ customer has in the j​​​​​​​​​​​th​​​​ bank. Return the wealth that the richest customer has.

A customer's wealth is the amount of money they have in all their bank accounts. The richest customer is the customer that has the maximum wealth.

 

Example 1:

Input: accounts = [[1,2,3],[3,2,1]]
Output: 6
Explanation:
1st customer has wealth = 1 + 2 + 3 = 6
2nd customer has wealth = 3 + 2 + 1 = 6
Both customers are considered the richest with a wealth of 6 each, so return 6.


=======================================Solution:==================

#include <iostream>
#include <vector>
using namespace std;


    int maximumWealth(vector<vector<int>>& accounts) {
        int reachManWealth = 0;
        int rows = accounts.size();
        
        for (int i = 0; i < rows; i++) {
            int sum = 0;
            for (int j = 0; j < accounts[i].size(); j++) {
                sum += accounts[i][j];
            }
            reachManWealth = max(reachManWealth, sum);
        }
        
        return reachManWealth;
    }


int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> accounts(n, vector<int>(m));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> accounts[i][j];
        }
    }
    
   
    cout << maximumWealth(accounts) << endl;
    
    return 0;
}
