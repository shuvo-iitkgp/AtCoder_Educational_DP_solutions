#include <bits/stdc++.h>
using namespace std;
using lli = long long;
typedef vector<lli> vl;
const lli INF = 1e12 + 7, lim = 1e5 + 2;

vl dp(lim), weight(lim), value(lim);
void solve()
{
    //dp[i] -> for sum_value of i , the minimum weight accumulated.
    lli n, W;
    cin >> n >> W;
    lli sum_value = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> weight[i] >> value[i];
        sum_value += value[i];
    }
    for (int i = 1; i <= sum_value; i++)
        dp[i] = INF;
    dp[0] = 0;
    for (int item = 1; item <= n; item++)
    {
        for (int i = sum_value; i >= value[item]; i--)
            dp[i] = min(dp[i], dp[i - value[item]] + weight[item]);
    }
    for (int i = sum_value; i >= 0; i--)
        if (dp[i] <= W)
        {
            cout << i << '\n';
            return;
        }
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
