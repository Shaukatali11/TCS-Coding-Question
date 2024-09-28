1. Count the number of occurrences of a specific character:

#include <iostream>
using namespace std;

int countCharOccurrences(string s, char ch) {
    int count = 0;
    for (char c : s) {
        if (c == ch) count++;
    }
    return count;
}

int main() {
    string sentence = "Welcome to TCS for Prime";
    char ch = 'e';
    cout << "Number of occurrences of '" << ch << "': " << countCharOccurrences(sentence, ch) << endl;
    return 0;
}


2. Capitalize the first letter of each word:

#include <iostream>
#include <sstream>
using namespace std;

string capitalizeFirstLetter(string sentence) {
    stringstream ss(sentence);
    string word, result = "";
    while (ss >> word) {
        word[0] = toupper(word[0]);
        result += word + " ";
    }
    result.pop_back(); 
    return result;
}

int main() {
    string sentence = "welcome to tcs for prime";
    cout << "Capitalized sentence: " << capitalizeFirstLetter(sentence) << endl;
    return 0;
}


3. Find the shortest word in the sentence:

#include <iostream>
#include <sstream>
using namespace std;

string shortestWord(string sentence) {
    stringstream ss(sentence);
    string word, shortest;
    ss >> shortest; // Initialize with the first word
    while (ss >> word) {
        if (word.length() < shortest.length()) {
            shortest = word;
        }
    }
    return shortest;
}

int main() {
    string sentence = "Welcome to TCS for Prime";
    cout << "Shortest word: " << shortestWord(sentence) << endl;
    return 0;
}

4. Find the longest word:

#include <iostream>
#include <sstream>
using namespace std;

string longestWord(string sentence) {
    stringstream ss(sentence);
    string word, longest;
    while (ss >> word) {
        if (word.length() > longest.length()) {
            longest = word;
        }
    }
    return longest;
}

int main() {
    string sentence = "Welcome to TCS for Prime";
    cout << "Longest word: " << longestWord(sentence) << endl;
    return 0;
}


