#include <bits/stdc++.h>
#include <iostream>

using namespace std;
// first contest of leetcode 2025 byweekly contest
bool hasMatch(string s, string p)
{
    if (p[0] == '*' && s[0] == p[1])
        return true;
    int n = s.size();
    int m = p.size();
    int pos = p.find('*');
    
    string prefix = p.substr(0, pos);
    string suffix = p.substr(pos + 1);

    int prefixLength = prefix.length();
    int suffixLength = suffix.length();

    for (int i = 0; i <= n - prefixLength - suffixLength; i++)
    {
        if (s.substr(i, prefixLength) == prefix &&
            s.substr(n - suffixLength) == suffix)
        {
            return true;
        }
    }

    return false;
}



int main()
{
    string s = "kvb";
    string p = "k*v";
    cout << hasMatch(s, p) << endl;

    return 0;
}

