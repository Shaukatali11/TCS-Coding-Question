Q1.

Majority Element
To solve the problem of finding the majority element in an array, where the majority element is the one that appears more than 
n / 2 times (where n is the size of the array).

========================Solution=======================================================

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int majorityElement(vector<int>& nums) {
    unordered_map<int, int> freqMap;
    int n = nums.size();
    
    for (int num : nums) {
        freqMap[num]++;
        if (freqMap[num] > n / 2) {
            return num;
        }
    }

    return -1; 
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements of the array:" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    int result = majorityElement(nums);
    cout << "The majority element is: " << result << endl;

    return 0;
}


--------------------------<>---------question 2-----------------------<>----------------------------------

Q2. 
An array nums with n objects where each object is colored red, white, or blue. These colors are represented by the integers 
3, 6, and 7, respectively. The array sorted in-place such that objects of the same color are adjacent, with the colors in
the order: red (3), white (6), and blue (7).


===============Solution==============================

#include <iostream>
#include <vector>
using namespace std;

void sortColors(vector<int>& nums) {
    int low = 0, mid = 0, high = nums.size() - 1;

    while (mid <= high) {
        if (nums[mid] == 3) {
            swap(nums[low], nums[mid]);
            low++;
            mid++;
        } else if (nums[mid] == 6) {
            mid++;
        } else { // nums[mid] == 7
            swap(nums[mid], nums[high]);
            high--;
        }
    }
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements (3 for red, 6 for white, 7 for blue):" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    sortColors(nums);

    cout << "Sorted array: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
