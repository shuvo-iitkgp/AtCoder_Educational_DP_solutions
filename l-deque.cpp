#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define pb push_back
using lli = long long;
typedef vector<lli> vl;
typedef pair<lli, lli> pll;
typedef vector<pll> vp;
typedef vector<vector<lli>> vvl;
const lli mod = 1e9 + 7;
void solve()
{
    lli n;
    cin >> n;
    vl a(n);
    for (lli &x : a)
        cin >> x;
    vvl dp(n + 1, vl(n, -1e18));
    for (int len = 1; len <= n; len++)
        for (int l = 0; l <= n - len; l++)
            dp[len][l] = len - 1 ? max(a[l] - dp[len - 1][l + 1], a[l + len - 1] - dp[len - 1][l]) : a[l];

    cout << dp[n][0];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // lli _t;
    // cin >> _t;
    // while (_t--)
    solve();
    return 0;
}

// Think twice, code once.
