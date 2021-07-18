#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define pb push_back
using lli = long long;
typedef vector<lli> vl;
typedef pair<lli, lli> pll;
typedef vector<pll> vp;
const lli mod = 1e9 + 7;
void add_self(lli &a, lli b)
{
    a += b;
    if (a >= mod)
        a -= mod;
}
lli mul(lli a, lli b)
{
    return (a * b) % mod;
}
lli n;
struct M
{
    vector<vl> t;
    M()
    {
        t.resize(n, vl(n));
    }
    M operator*(const M &b) const
    {
        M c = M();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                for (int k = 0; k < n; k++)
                {
                    add_self(c.t[i][k], mul(t[i][j], b.t[j][k]));
                }
            }
        }
        return c;
    }
};
void solve()
{
    //it isn't important how he got here..its important where he goes from now.
    cin >> n;
    lli k;
    cin >> k;
    vector<vl> can(n, vl(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> can[i][j];

    M answer = M();
    for (int i = 0; i < n; i++)
    {
        answer.t[i][i] = 1;
    }
    M m = M();
    m.t = can;
    while (k)
    {
        if (k % 2)
        {
            answer = answer * m;
        }
        m = m * m;
        k /= 2;
    }
    lli total = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            add_self(total, answer.t[i][j]);
        }
    }
    cout << total << '\n';

    // vl dp(n, 1);
    // //dp[i] -> no. of ways we get to vertex 'i' so far.
    // for (lli step = 0; step < k; step++)
    // {
    //     vl new_dp(n);
    //     for (int a = 0; a < n; a++)
    //         for (lli b = 0; b < n; b++)
    //             if (can[a][b])
    //                 add_self(new_dp[b], dp[a]);
    //     dp = new_dp;
    // }
    // lli ans = 0;
    // for (int i = 0; i < n; i++)
    //     add_self(ans, dp[i]);
    // cout << ans << '\n';
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
