Q1. 
  You are given two integers x and y. The task is to find the number that is closest to x and is divisible by y. If there are 
two numbers equidistant from x, the one with the smaller absolute value should be chosen.

  Input:
x = 13
y = 3
Output: 12

Input:
x = 13
y = 2
Output: 12

--------------------------Solution-----------------------------------------------------

  #include <iostream>
#include <cmath>
using namespace std;

int closestDivisible(int x, int y) {
    // Find the quotient when x is divided by y
    int quotient = x / y;

    // Two possible candidates
    int n1 = y * quotient;      // Closest number on the lower side
    int n2 = y * (quotient + 1); // Closest number on the upper side

    // Compare the difference between x and n1, x and n2
    if (abs(x - n1) < abs(x - n2)) {
        return n1;
    } else {
        return n2;
    }
}

int main() {
    int x = 13;
    int y = 3;

    int result = closestDivisible(x, y);
    cout << "The number closest to " << x << " and divisible by " << y << " is: " << result << endl;

    return 0;
}

=========================Question 2==================================================
Q2. 
  Write a program that generates a password adhering to the following conditions:
• The password must consist of at least 8 characters.
• It must contain at least one integer.
• It must contain at least one special character from the set {'#', '@; }
• It must contain at least one uppercase letter and one lowercase letter.
• Each character in the password should be incremented by the number of times specified by the
second input.
Your program should take two inputs:
I.A string representing the initial password.
2.An integer representing the number of times each character should be incremented.
Your program should then generate and output the modified password.
Example I:
Inputl: werV432@
Input2: 2
Output: ygtX653#
  
==============Solution =====================================


#include <iostream>
#include <string>
#include <cctype>
using namespace std;

bool isValidPassword(const string& password) {
    if (password.length() < 8) return false;

    bool hasLower = false, hasUpper = false, hasDigit = false, hasSpecial = false;
    string specialChars = "#$@&*";

    for (char c : password) {
        if (islower(c)) hasLower = true;
        if (isupper(c)) hasUpper = true;
        if (isdigit(c)) hasDigit = true;
        if (specialChars.find(c) != string::npos) hasSpecial = true;
    }

    return hasLower && hasUpper && hasDigit && hasSpecial;
}

char incrementChar(char c, int increment) {
    if (isalnum(c)) {
        if (isdigit(c)) {
            return ((c - '0' + increment) % 10) + '0';
        } else if (isalpha(c)) {
            if (islower(c)) {
                return ((c - 'a' + increment) % 26) + 'a';
            } else {
                return ((c - 'A' + increment) % 26) + 'A';
            }
        }
    }
    return c;  // No change for special characters
}

string generatePassword(const string& initialPassword, int increment) {
    string modifiedPassword = "";

    for (char c : initialPassword) {
        modifiedPassword += incrementChar(c, increment);
    }

    return modifiedPassword;
}

int main() {
    string initialPassword;
    int increment;

    cout << "Enter the initial password: ";
    cin >> initialPassword;
    cout << "Enter the increment value: ";
    cin >> increment;

    if (!isValidPassword(initialPassword)) {
        cout << "Invalid initial password. Please provide a valid password that meets all criteria." << endl;
        return 1;
    }

    string newPassword = generatePassword(initialPassword, increment);
    cout << "Generated password: " << newPassword << endl;

    return 0;
}
