#include <iostream>
#include <string>

using namespace std;

void getLengthoflargest(string str) {
    int count = 0, res = 0;
    
    for(int i = 0; str[i] != '.'; i++) {
        if(str[i] == ' ') {
            res = max(res, count);
            count = 0;
        } else {
            count++;
        }
    }

    cout << max(res, count);
}

int main() {
    string str;
    getline(cin, str);
    
    getLengthoflargest(str);

    return 0;
}