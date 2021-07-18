#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define pb push_back
using lli = long long;
typedef vector<lli> vl;
typedef pair<lli, lli> pll;
typedef vector<pll> vp;
const lli mod = 1e9 + 7, N = 1e5 + 4;
// dp[used] -> number of ways such that we used i candies so far.
void add_self(int &a, int b)
{
    a += b;
    if (a >= mod)
        a %= mod;
}
void sub_self(int &a, int b)
{
    a -= b;
    if (a < 0)
        a += mod;
}

void solve()
{

    int n, k;
    cin >> n >> k;
    vector<int> dp(k + 1);
    dp[0] = 1;
    for (int child = 0; child < n; child++)
    {
        int upto;
        cin >> upto;
        vector<int> fake(k + 1);
        for (int used = k; used >= 0; used--)
        {
            int tmp = dp[used];
            int l = used + 1;
            int r = used + min(upto, k - used);
            if (l <= r)
            {
                add_self(fake[l], tmp);
                if (r + 1 <= k)
                    sub_self(fake[r + 1], tmp);
            }
        }
        int prefix_sum = 0;
        for (int i = 0; i <= k; i++)
        {
            add_self(prefix_sum, fake[i]);
            add_self(dp[i], prefix_sum);
        }
    }

    cout << dp[k];
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
/*

3 4 
1 2 3

dp
1 2 4 5 5

fake
0 1 1 0 -2 


used = 4, 3, 2, 1, 0
tmp = 0, 0, 1, 1, 1; l = 5, 4, 3, 2, 1; r = 0, 1, 2, 3, 3


*/