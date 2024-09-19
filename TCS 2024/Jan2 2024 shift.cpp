You are given two arrays:

E[] (representing the number of guests entering the party at every hour),
L[] (representing the number of guests leaving the party at every hour).
The goal is to find out the maximum number of guests present on the cruise at any point during the party, which lasts for T hours

5  (T = 5 hours)
5
3
7
2
8
2
1
3
5
4

===============================Solution============================

#include <iostream>
#include <vector>
using namespace std;

int maxGuests(int T, vector<int>& E, vector<int>& L) {
    int currentGuests = 0;  
    int maxGuests = 0;     

    for (int i = 0; i < T; i++) {
        currentGuests += E[i] - L[i];  
        maxGuests = max(maxGuests, currentGuests);
    }
    
    return maxGuests;  
}

int main() {
    int T;
    cin >> T; 

    vector<int> E(T), L(T);

    for (int i = 0; i < T; i++) {
        cin >> E[i];  
    }

    for (int i = 0; i < T; i++) {
        cin >> L[i];  
    }

    cout << maxGuests(T, E, L) << endl;  

    return 0;
}
