#include<bits/stdc++.h>
using namespace std;


class Solution
{
public:
    string simplifyPath(string path)
    {
        int len = path.size();
        stack<char>ans;

        char ch, last_one;
        int n;

        int dots = 0;

        for(int i=0; i<len; i++)
        {
            char l = path[i];

            if(ans.empty())
            {
                ans.push(l);
                continue;
            }
            if(!ans.empty()) ch = ans.top();

            if(l != '/')
            {
                ans.push(l);
                if(l == '.') dots++;
                else dots = 0;
            }

            if(l == '/')
            {
                if(dots == 1)
                {
                    char one = ans.top();
                    ans.pop();
                    char two = ans.top();

                    if(two != '/')
                    {
                        ans.push(one);
                        ans.push('/');
                    }

                    dots = 0;
                }
                else if(dots == 2)
                {

                    char one, two;
                    one = ans.top();
                    ans.pop();
                    two = ans.top();
                    ans.pop();

                    char is_slash = ans.top();
                    if(is_slash != '/')
                    {
                        ans.push(two);
                        ans.push(one);
                        ans.push(l);
                        continue;
                    }

                    ans.pop();

                    if(ans.empty())
                    {
                        dots = 0;
                        ans.push('/');
                        continue;
                    }

                    char slash = ans.top();

                    while(slash != '/')
                    {
                        ans.pop();
                        slash = ans.top();
                    }

                    dots = 0;
                }
                else if(ch == '/') continue;
                else
                {
                    ans.push(l);
                    last_one = l;
                    dots = 0;
                }
            }

        }

        if(dots == 1)
        {
            char one = ans.top();
            ans.pop();
            char two = ans.top();

            if(two != '/')
            {
                ans.push(one);
                ans.push('/');
            }

            dots = 0;
        }
        else if(dots == 2)
        {

            char one, two;
            one = ans.top();
            ans.pop();
            two = ans.top();
            ans.pop();

            char is_slash = ans.top();
            if(is_slash != '/')
            {
                ans.push(two);
                ans.push(one);
            }
            else
            {
                ans.pop();

            if(ans.empty())
            {
                dots = 0;
                ans.push('/');
            }

            char slash = ans.top();

            while(slash != '/')
            {
                ans.pop();
                slash = ans.top();
            }

            dots = 0;
            }
        }

        string a = "";
        if(ans.empty()) return "/";



        int ans_size = ans.size()-1;
        for(int i = ans_size; i>=0 ; i--)
        {
            char t = ans.top();

            if(i == ans_size && t == '/')
            {
                ans.pop();
                continue;
            }

            ans.pop();
            a+=t;
        }

        reverse(a.begin(), a.end());
        if(a.size() == 0) a+="/";
        return a;
    }
};


int main()
{
    Solution s1, s2, s3, s4, s5, s6, s7, s8, s9;

    cout << s1.simplifyPath("/home/") << endl;
    cout << s2.simplifyPath("/home//foo/") << endl;
    cout << s3.simplifyPath("/home/user/Documents/../Pictures") << endl;
    cout << s4.simplifyPath("/../") << endl;
    cout << s5.simplifyPath("/.../a/../b/c/../d/./") << endl;
    cout << s6.simplifyPath("/hello../world") << endl;
    cout << s7.simplifyPath("/a//b////c/d//././/..") << endl;
    cout << s8.simplifyPath("/hello./world/") << endl;
    cout << s9.simplifyPath("/a//b..") << endl;

    return 0;
}
