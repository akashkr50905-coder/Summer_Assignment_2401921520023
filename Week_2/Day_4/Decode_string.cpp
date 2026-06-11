#include <iostream>
#include <string>
using namespace std;

string solve(string &s, int &i) {
    string result = "";

    while (i < s.length() && s[i] != ']') {

        if (isalpha(s[i])) {
            result += s[i];
            i++;
        }
        else {
            int num = 0;

            while (i < s.length() && isdigit(s[i])) {
                num = num * 10 + (s[i] - '0');
                i++;
            }

            i++;

            string decoded = solve(s, i);

            i++;

            while (num--) {
                result += decoded;
            }
        }
    }

    return result;
}

string decodeString(string s) {
    int i = 0;
    return solve(s, i);
}

int main() {
    string s = "3[a2[c]]";
    cout << decodeString(s);

    return 0;
}