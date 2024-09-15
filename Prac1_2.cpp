#include <iostream>

using namespace std;

void largestWordLength(const string& str) {
    int maxLength = 0, count = 0;

    for (char ch : str) {
        if (isspace(ch)) {
            maxLength = maxLength < count ? count : maxLength;
            count = 0;
        }
        else {
            count++;
        }
    }

    maxLength = maxLength < count ? count : maxLength;

    cout << "\nThe longest word's length of the string: " << maxLength << endl;
}

int main() {
    string str;
    cout << "\nEnter the string :";
    getline(cin, str);

    largestWordLength(str);

    return 0;
}
