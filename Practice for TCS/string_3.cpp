1. Count the number of words in a string:

#include <iostream>
#include <sstream>
using namespace std;

int countWords(string s) {
    stringstream ss(s);
    string word;
    int count = 0;
    while (ss >> word) {
        count++;
    }
    return count;
}

int main() {
    string s = "Hello, how are you?";
    cout << "Number of words: " << countWords(s) << endl;
    return 0;
}


2. Remove all duplicates from a string:


#include <iostream>
#include <unordered_set>
using namespace std;

string removeDuplicates(string s) {
    unordered_set<char> seen;
    string result = "";
    for (char c : s) {
        if (seen.find(c) == seen.end()) {
            seen.insert(c);
            result += c;
        }
    }
    return result;
}

int main() {
    string s = "banana";
    cout << "String after removing duplicates: " << removeDuplicates(s) << endl;
    return 0;
}



3. Find the longest substring with at most K distinct characters:

#include <iostream>
#include <unordered_map>
using namespace std;

int lengthOfLongestSubstringKDistinct(string s, int k) {
    unordered_map<char, int> charCount;
    int maxLength = 0, left = 0;
    for (int right = 0; right < s.size(); ++right) {
        charCount[s[right]]++;
        while (charCount.size() > k) {
            charCount[s[left]]--;
            if (charCount[s[left]] == 0) charCount.erase(s[left]);
            left++;
        }
        maxLength = max(maxLength, right - left + 1);
    }
    return maxLength;
}

int main() {
    string s = "eceba";
    int k = 2;
    cout << "Length of longest substring with at most " << k << " distinct characters: " << lengthOfLongestSubstringKDistinct(s, k) << endl;
    return 0;
}


4. Find all permutations of a string:

#include <iostream>
#include <vector>
using namespace std;

void permute(string s, int l, int r, vector<string>& result) {
    if (l == r) {
        result.push_back(s);
    } else {
        for (int i = l; i <= r; ++i) {
            swap(s[l], s[i]);
            permute(s, l + 1, r, result);
            swap(s[l], s[i]);
        }
    }
}

vector<string> getPermutations(string s) {
    vector<string> result;
    permute(s, 0, s.size() - 1, result);
    return result;
}

int main() {
    string s = "abc";
    vector<string> permutations = getPermutations(s);
    cout << "Permutations of " << s << " are:" << endl;
    for (string perm : permutations) {
        cout << perm << endl;
    }
    return 0;
}

