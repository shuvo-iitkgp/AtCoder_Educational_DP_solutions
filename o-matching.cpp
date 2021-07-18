#include <bits/stdc++.h>
using namespace std;
using lli = long long;
const lli mod = 1e9 + 7, N = 22;
lli grid[N][N], dp[N][1 << N];
int n;
lli rec(int level = 0, int mask = 0)
{
    if (level == n)
        return mask == (1LL << n) - 1 ? 1 : 0;
    if (dp[level][mask] != -1)
        return dp[level][mask];
    dp[level][mask] = 0;
    for (int i = 0; i < n; i++)
    {
        if (grid[level][i] && (mask & (1LL << i)) == 0)
            dp[level][mask] = (dp[level][mask] + rec(level + 1, mask | (1LL << i))) % mod;
    }
    return dp[level][mask];
}

void solve()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> grid[i][j];
    memset(dp, -1, sizeof(dp));

    cout << rec() << '\n';
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}

// Think twice, code once.
