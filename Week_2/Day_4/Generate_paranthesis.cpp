#include <iostream>
#include <vector>
using namespace std;

void generate(int open, int close, int n, string curr,
              vector<string>& ans) {

    if (curr.length() == 2 * n) {
        ans.push_back(curr);
        return;
    }

    if (open < n)
        generate(open + 1, close, n, curr + '(', ans);

    if (close < open)
        generate(open, close + 1, n, curr + ')', ans);
}

vector<string> generateParenthesis(int n) {
    vector<string> ans;
    generate(0, 0, n, "", ans);
    return ans;
}

int main() {
    int n = 3;

    vector<string> result = generateParenthesis(n);

    for (string s : result)
        cout << s << endl;

    return 0;
}