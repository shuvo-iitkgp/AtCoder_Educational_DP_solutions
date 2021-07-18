#include <bits/stdc++.h>
using namespace std;
using lli = long long;
int dp[3001][3001];
vector<pair<int, char>> mp;
string s, t;
int rec(int i, int j)
{
    if (i == (int)s.length() || j == (int)t.length())
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    if (s[i] == t[j])
    {
        int k = rec(i + 1, j + 1) + 1;
        mp.push_back({k, s[i]});
        return dp[i][j] = k;
    }
    return dp[i][j] = max(rec(i + 1, j), rec(i, j + 1));
}

int main()
{
    cin >> s >> t;
    memset(dp, -1, sizeof(dp));
    int tot = rec(0, 0);
    // for (int i = 0; i < (int)s.length(); i++)
    // {
    //     for (int j = 0; j < (int)t.length(); j++)
    //     {
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }

    int i = 0, j = 0;
    while (tot)
    {
        if (s[i] == t[j])
        {
            cout << s[i];
            i++;
            j++;
            tot--;
        }
        else if (dp[i + 1][j] > dp[i][j + 1])
            i++;
        else
            j++;
    }
}