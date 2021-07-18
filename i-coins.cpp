#include <bits/stdc++.h>
using namespace std;
using lli = long double;

#define pb push_back
typedef vector<lli> vl;
typedef pair<lli, lli> pll;
typedef vector<pll> vp;
const lli mod = 1e9 + 7;
vector<vl> dp(3001, vl(3001, -1));
vl p;
int n;
lli rec(int level, int count) //i -> level ; count-> no. of heads
{
    if (level == n)
    {
        if (count > n / 2)
            return 1;
        return 0;
    }
    if (dp[level][count] > -0.9)
        return dp[level][count];
    return dp[level][count] = p[level] * rec(level + 1, count + 1) + (1 - p[level]) * rec(level + 1, count);
}
void solve()
{
    // n-> positiv odd no.
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        lli x;
        cin >> x;
        p.pb(x);
    }
    cout << fixed << setprecision(10) << rec(0, 0) << '\n';
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
