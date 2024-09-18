Convert a given matrix in lower triangular matrix:
Inuput:
1234
5678
9876
5432
Output
1000
5600
9870
5432

Solution:-

#include<bits/stdc++.h>
using namespace std;

void convertToLowerTriangular(vector<vector<int>>& arr, int rows, int cols) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            if(i < j) {
                arr[i][j] = 0; 
            }
        }
    }

    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl; 
    }
}

int main() {
    int rows, cols;
    cin >> rows >> cols; 

    vector<vector<int>> arr(rows, vector<int>(cols));

    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            cin >> arr[i][j];
        }
    }
    
    convertToLowerTriangular(arr, rows, cols);
    
    return 0;
}


========================================= Q2 =======================================================

Give a password string, find the minimum number of divisions such that totaLnumber of
decoded passwords are greater than length of each decoded password.
Input: S = "PLEASESAVEME" , L = 12
Output: "PSV" "LEE" "ESM" "AAE"


Solution:

  #include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> divideString(string S, int L) {
    vector<string> result;
    int n = S.size();

    for (int group_size = 1; group_size < n; ++group_size) {
        int num_groups = n / group_size;
        if (num_groups > group_size) {
            for (int i = 0; i < n; i += group_size) {
                result.push_back(S.substr(i, group_size));
            }
            break; 
        }
    }

    return result;
}

int main() {
    string S = "PLEASESAVEME";
    int L = 12;

    vector<string> groups = divideString(S, L);

    for (const string& group : groups) {
        cout << "\"" << group << "\" ";
    }
    cout << endl;

    return 0;
}



