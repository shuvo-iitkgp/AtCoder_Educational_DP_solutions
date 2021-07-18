#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define pb push_back
using lli = long long;
typedef vector<lli> vl;
typedef pair<lli, lli> pll;
typedef vector<vl> vvl;
const lli mod = 1e9 + 7;
vvl adj;
vl dp;
vector<bool> visited;
lli dfs(lli v)
{
    if (visited[v])
        return dp[v];
    visited[v] = 1;
    if ((lli)adj[v].size() == 0)
        dp[v] = 1;
    for (auto x : adj[v])
        dp[v] = max(dp[v], dfs(x) + 1);
    return dp[v];
}
void solve()
{
    lli n, m;
    cin >> n >> m;
    adj = vvl(n);
    dp = vl(n, 0);
    visited = vector<bool>(n, false);
    for (lli i = 0; i < m; i++)
    {
        lli x, y;
        cin >> x >> y;
        adj[x - 1].push_back(y - 1);
    }
    for (lli i = 0; i < n; i++)
        if (!visited[i])
            dfs(i);
    lli ans = 0;
    for (auto x : dp)
        ans = max(ans, x);
    cout << ans - 1;
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
