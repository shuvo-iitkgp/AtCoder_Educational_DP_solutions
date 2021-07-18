#include <bits/stdc++.h>
using namespace std;
using lli = long long;
//dp[i][j] = the score for the subarray [i, j]
const lli N = 405, INF = 1e18 + 3;
lli dp[N][N], a[N];
unordered_map<lli, lli> sum;
lli n;
lli rec(lli i = 0, lli j = n - 1)
{
    if (i == j)
    {
        // cout << "( " << i << " ," << j << ") = " << 0 << '\n';
        return dp[i][j] = 0;
    }
    if (j == (i + 1))
    {
        // cout << "( " << i << " ," << j << ") = " << a[i] + a[j] << '\n';
        return dp[i][j] = a[i] + a[j];
    }
    if (dp[i][j] != -1)
    {
        // cout << "( " << i << " ," << j << ") = " << dp[i][j] << '\n';
        return dp[i][j];
    }
    lli ans = INF;
    for (lli k = i; k < j; k++)
    {
        lli p = rec(i, k) + rec(k + 1, j) + sum[j] - sum[i - 1];
        ans = min(p, ans);
    }
    // cout << "( " << i << " ," << j << ") = " << ans << '\n';
    return dp[i][j] = ans;
}
void solve()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum[i] = i ? sum[i - 1] + a[i] : a[i];
    }
    memset(dp, -1, sizeof(dp));
    cout << rec() << '\n';
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << dp[i][j] << ' ';
        cout << '\n';
    }
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
