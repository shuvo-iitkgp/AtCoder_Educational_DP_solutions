#include <bits/stdc++.h>
using namespace std;
using lli = long long;
typedef vector<lli> vl;
lli dp[101][100010], w[110], v[110];

lli n, W;
//dp state = num of elemnets & weight left.
lli rec(lli level, lli left_weight)
{
    if (level == n || left_weight <= 0)
        return 0;
    if (dp[level][left_weight] != -1)
        return dp[level][left_weight];
    lli ans = 0;
    ans = rec(level + 1, left_weight);
    if (left_weight >= w[level])
        ans = max(ans, rec(level + 1, left_weight - w[level]) + v[level]);
    return dp[level][left_weight] = ans;
}
void solve()
{
    cin >> n >> W;
    for (int i = 0; i < n; i++)
        cin >> w[i] >> v[i];
    memset(dp, -1, sizeof(dp));
    cout << rec(0, W) << '\n';
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
