#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define pb push_back
using lli = long long;
typedef vector<lli> vl;
typedef pair<lli, lli> pll;
typedef vector<pll> vp;
const lli mod = 1e9 + 7, N = 3004;
char cmp[N];
lli dp[N][N], pref[N][N];

void add_self(lli &a, lli b)
{

    a += b;
    if (a >= mod)
        a -= mod;
}

lli sub_self(lli a, lli b)
{
    a -= b;
    if (a < 0)
        a += mod;
    return a;
}
void solve()
{
    //dp[i][j] -> no. of ways to put numbers in prefix of size 'i'. such that th last number is '1'
    int n;
    cin >> n;
    cin >> cmp;
    dp[1][1] = 1;
    for (int len = 2; len <= n; len++)
    {
        for (int i = 1; i <= len - 1; i++)
        {
            pref[len - 1][i] = (pref[len - 1][i - 1] + dp[len - 1][i]) % mod;
        }
        for (int b = 1; b <= len; b++)
        {

            lli L, R;
            if (cmp[len - 2] == '<')
                L = 1, R = b - 1;
            else
                L = b, R = len - 1;
            if (L <= R)
                add_self(dp[len][b], sub_self(pref[len - 1][R], pref[len - 1][L - 1]));
        }
    }
    lli answer = 0;
    for (int b = 1; b <= n; b++)
        add_self(answer, dp[n][b]);
    cout << answer;
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
