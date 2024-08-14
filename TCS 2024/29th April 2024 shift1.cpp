Q1. 
  Given an integer you need to find the sum of value of that table.
    input - 10
    output - 550

----------------------------------------------------Solution----------------------------------------------------------

#include<bits/stdc++.h>
using namespace std;

int sumofAllelemtoftable(int n){
    int sum=0;
    for(int i=1;i<=10;i++){
        sum+=n*i;
    }
    return sum;
}

int main(){
    int n;
    cout<<"enter a number: "<<" ";
    cin>>n;
    cout<<sumofAllelemtoftable(n);
    return 0;
}




==================================Question -2 =====================================================================

  Q2.

  Given an array and integer k. We need to find the maximum element in each of the contigous subarray.
input - arr= [2,4,7,1,6,3] k= 3
output= 7 7 7 6

--------------------------------------------Solution------------------------------------------------------------------------

#include <iostream>
#include <vector>
using namespace std;

void findMaxElementOfEachSubArray(const vector<int>& arr, int k) {
    int n = arr.size();

    // Iterate over each starting index of the subarray
    for (int i = 0; i <= n - k; ++i) {
        int maxElem = arr[i];

        // Find the maximum element in the current subarray
        for (int j = i; j < i + k; ++j) {
            if (arr[j] > maxElem) {
                maxElem = arr[j];
            }
        }

        // Print the maximum element of the current subarray
        cout << maxElem << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements of the array:" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    int k;
    cout << "Enter integer k: ";
    cin >> k;

    findMaxElementOfEachSubArray(arr, k);

    return 0;
}
