#include<bits/stdc++.h>
using namespace std;

int main()
{
    string strs[] = {"flower","flow","flight"};
    size_t size = sizeof(strs) / sizeof(strs[0]);
    int len = 200;

    for(string a:strs)
    {
        if(a.size() < len) len = a.size();
    }

    string ans = "";

    for(int i=0; i<len; i++)
    {
        char s = strs[0][i];
        int flag = 1;

        for(int j=1; j<size; j++)
        {
            if(strs[j][i] != s) flag = 0;
        }

        if(!flag) break;
        ans += s;
    }


    cout << ans;
    return 0;
}
