Q1.
  A chocolate factory is packing chocolates into the packets. The chocolate packets here represent an array arrt of N number of integer values. The task is to find the empty 
packets(O) of chocolate and push it to the end of the conveyor belt(array).
For Example: N=7 and arr=[4,5,0,1,9,0,5,0] There are 3 empty packets in the given set. These 3 empty packets represented as O should be pushed towards the end of the array.

  ====================Solution================================
  Basically we need to iterate array and all zero should be at the end of array.

#include<bits/stdc++.h>
using namespace std;

void shiftAllzeroAtEnd(int arr[],int s){
    vector<int>ans;
    for(int i=0;i<s;i++){
        if(arr[i]>0){
            ans.push_back(arr[i]);
        }
    }
    for(int i=0;i<s;i++){
        if(arr[i]<=0){
            ans.push_back(arr[i]);
        }
    }
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}
int main(){
    int n;
    cout<<"enter number of element:";
    cin>>n;
    
    int arr[n];
    cout<<"push element into the array:";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int s=sizeof(arr)/sizeof(arr[0]);
    
    shiftAllzeroAtEnd(arr,s);
    return 0;
}



