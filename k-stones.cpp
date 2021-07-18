#include <bits/stdc++.h>
using namespace std;
using lli = long long;
const lli N = 100010;
int dp[N];
int n, k;
int moves[N];
int rec(int left)
{
    if (dp[left] != -1)
        return dp[left];
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int x = moves[i];
        if (left >= x && rec(left - x) == 0)
        {
            ans = 1;
            break;
        }
    }
    return dp[left] = ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    memset(dp, -1, sizeof(dp));
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> moves[i];
    rec(k) ? cout << "First\n" : cout << "Second\n";

    return 0;
}

// Think twice, code once.
