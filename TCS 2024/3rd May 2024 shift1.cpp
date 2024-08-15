Q1.
Given a data warehouse in which data is stored. Now you need to find number is divisible by 9 or not.

=========================Solution===================================================

#include<bits/stdc++.h>
using namespace std;

void isDivisibleBY9(int n){
    if(n%9==0){
        cout<<"Number is divisible by 9";
    }else{
        cout<<"Number is not Divisible by 9";
    }
}
int main(){
    int n;
    cout<<"enter number from data warehouse :";
    cin>>n;
    isDivisibleBY9(n);
    return 0;
}




--------------------<>-----------------------<> Question -2 -------------------<>----------------

Q2. We are given list of number we need to return diffrence between maximum and minimum nuber diffrence.

===================Solution==================================

#include<bits/stdc++.h>
using namespace std;

void diffMaxMin(vector<int>& arr, int s){
    int maxi=arr[0];
    int mini=arr[0];
    for(int i=0; i< s ; i++){
        if(arr[i]>maxi){
            maxi=arr[i];
        }else if(arr[i]<mini){
            mini=arr[i];
        }
    }
    int diff=maxi-mini;
    cout<<"diff is : "<<diff<<endl;
}

int main(){
    int n;
    cout<<"enter number of elements: ";
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter the elements:"<<endl;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int s=arr.size();
    diffMaxMin(arr,s);
    return 0;
}
