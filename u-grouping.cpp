#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define pb push_back
using lli = long long;
typedef vector<lli> vl;
typedef pair<lli, lli> pll;
typedef vector<pll> vp;
const lli mod = 1e9 + 7, INF = 1e18;
vl pre;
//pre[mask] = score of group containg mask rabbits.
vl dp;
void rec(int i, const vl &not_taken, lli score_so_far, int mask, int group)
{
    if (i == (int)not_taken.size())
    {
        dp[mask] = max(dp[mask], score_so_far + pre[group]);
        return;
    }
    rec(i + 1, not_taken, score_so_far, mask, group);
    rec(i + 1, not_taken, score_so_far, mask ^ (1 << not_taken[i]),
        group ^ (1 << not_taken[i]));
}
void solve()
{
    int n;
    cin >> n;
    vector<vl> in(n, vl(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> in[i][j];
    pre.resize(1 << n);
    for (int mask = 0; mask < (1 << n); mask++)
    {
        for (int i = 0; i < n; i++)
        {
            if (mask & (1 << i))
            {
                for (int j = i + 1; j < n; j++)
                {
                    if (mask & (1 << j))
                    {
                        pre[mask] += in[i][j];
                    }
                }
            }
        }
    }
    dp.resize(1 << n, -INF);
    dp[0] = 0;
    for (int mask = 0; mask < (1 << n); ++mask)
    {
        vl not_taken;
        for (int i = 0; i < n; i++)
        {
            if (!(mask & (1 << i)))
                not_taken.pb(i);
        }
        rec(0, not_taken, dp[mask], mask, 0);
    }

    cout << dp[(1 << n) - 1] << '\n';
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
