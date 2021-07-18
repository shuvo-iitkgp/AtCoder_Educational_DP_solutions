#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define pb push_back
using lli = long long;
typedef vector<lli> vl;
typedef pair<lli, lli> pll;
typedef vector<pll> vp;
//dp state -> level , the number of jumps it makes
const lli N = 1e5 + 7;
lli h[N], n, k, dp[N][101];
lli rec(lli level = 0, lli jumps = 0)
{
    if (level == n)
        return jumps == 1 ? 0 : 1e9;
    if (dp[level][jumps] != -1)
        return dp[level][jumps];
    lli ans = 1e9;
    if (jumps + 1 <= k) //springen ist möglich
        ans = min(rec(level + 1, jumps + 1), rec(level + 1, 1) + abs(h[level] - h[level - jumps]));
    else
        ans = rec(level + 1, 1) + abs(h[level] - h[level - jumps]);
    return dp[level][jumps] = ans;
}
void go()
{
    memset(dp, -1, sizeof(dp));
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> h[i];
    h[n] = 1e9;
    cout << rec() << '\n';
}
int main()
{
    ios::sync_with_stdio(0), ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    go();
    return 0;
}

// Think twice, code once.
