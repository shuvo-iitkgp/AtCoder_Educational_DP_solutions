#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define pb push_back
using lli = long long;
typedef vector<lli> vl;
typedef pair<lli, lli> pll;
typedef vector<pll> vp;
const lli INF = 1e9 + 7;

void solve()
{
    int n;
    cin >> n;
    vector<int> dp(3);
    //dp[i] -> total cost such that we didi activity i on the last considered day.
    for (int day = 0; day < n; day++)
    {
        vector<int> c(3);
        vector<int> new_dp(3, 0);
        for (int i = 0; i < 3; i++)
            cin >> c[i];
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                if (i != j)
                    new_dp[j] = max(new_dp[j], dp[i] + c[j]);
        dp = new_dp;
    }
    cout << max({dp[0], dp[1], dp[2]});
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
