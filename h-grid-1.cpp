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
int h, w;
bool grid[1010][1010];
vector<vl> dp(1010, vl(1010, -1));
int rec(int i, int j)
{
    if (i == h - 1 && j == w - 1)
        return 1;
    if (dp[i][j] != -1)
        return dp[i][j];
    if (grid[i][j])
        return 0;
    lli ways;
    if (i < h - 1 && j < w - 1)
    {
        ways = (rec(i + 1, j) % mod + rec(i, j + 1) % mod) % mod;
        return dp[i][j] = ways;
    }
    else if (i == h - 1 && j < w - 1)
    {
        ways = rec(i, j + 1) % mod;
        return dp[i][j] = ways;
    }
    else if (i < h - 1 && j == w - 1)
    {
        ways = rec(i + 1, j) % mod;
        return dp[i][j] = ways;
    }
}
void solve()
{

    cin >> h >> w;
    char c;
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            cin >> c;
            grid[i][j] = (c == '#');
        }
    }
    cout << rec(0, 0) << '\n';
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
