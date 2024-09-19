Given an integer array Arr of size N, the task is to find the count of elements whose value is greater than all of its prior elements. The first element of the array should always be considered in the count.

Input:
The first line contains a single integer N (the size of the array).
The second line contains N space-separated integers representing the elements of the array.
Output:
Output the count of elements that are greater than all of their previous elements.

6
7 4 8 2 9 3
3

=========================Solution:-==================================================================================

  void maxPreviousCount(vector<int>&arr,int n){
    int maxPre=arr[0];
    int count=1;
    
    for(int i=0;i<n;i++){
        if(arr[i]>maxPre){
            count++;
            maxPre=arr[i];
        }
    }
    cout<<count;
}

int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    maxPreviousCount(arr,n);
    return 0;
}



