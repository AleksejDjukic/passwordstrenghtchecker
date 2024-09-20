#include <iostream>
#include <cctype>
#include <string>
using namespace std;

bool containsLowercase(string password) {
    for (char c : password) {
        if (islower(c)) {  // Check if the character is a lowercase letter
            return true;
        }
    }
    return false;
}

bool containsUppercase(string password) {
    for (char c : password) {
        if (isupper(c)) {  // Check if the character is an uppercase letter
            return true;
        }
    }
    return false;
}

bool containsNumbers(string password) {
    for (char c : password) {
        if (isdigit(c)) {  // Check if the character is a digit
            return true;
        }
    }
    return false;
}

string checkPassword(string password, int size) {
    bool firstReq, secondReq, thirdReq, fourthReq;
    bool passwordReqs = true;

    firstReq = (size > 9) ? true : false;
    secondReq = (containsLowercase(password) == true) ? true : false;
    thirdReq = (containsUppercase(password) == true) ? true : false;
    fourthReq = (containsNumbers(password) == true) ? true : false;

    if (firstReq == false || secondReq == false || thirdReq == false || fourthReq == false) {
        passwordReqs = false;
        return "Password does not meet the requirements...";
    } else if (size <= 10 && passwordReqs == true) {
        return "Password is weak.";
    } else if (size > 10 && size <= 15 && passwordReqs == true) {
        return "Password is strong!";
    } else if (size > 15 && passwordReqs == true) {
        return "Password is very strong!";
    } else {
        return "Please input your password!";
    }
    return "Unexpected error.";
}

int main() {
    string password;
    cout << "Enter your password: ";
    cin >> password;
    int size = password.length();

    string result = checkPassword(password, size);
    cout << result << endl;

    return 0;
}

