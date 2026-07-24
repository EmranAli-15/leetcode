#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    stack<char> ch;
    int calculate(string s) {
        return 3;
    }
};

int main()
{
    Solution s1, s2, s3;
    cout << s1.calculate("1 + 1") << endl;
    cout << s2.calculate(" 2-1 + 2 ") << endl;
    cout << s3.calculate("(1+(4+5+2)-3)+(6+8)") << endl;
    return 0;
}
