#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define pb push_back
using lli = long long;
typedef vector<lli> vl;
typedef vector<vl> vvl;
typedef pair<lli, lli> pll;
typedef vector<pll> vp;
const lli mod = 1e9 + 7;
void add_self(lli &a, lli b)
{
    a += b;
    if (a >= mod)
        a -= mod;
}
void solve()
{
    string K;
    cin >> K;
    lli D;
    cin >> D;
    int len = (int)K.length();
    vvl dp(D, vl(2));
    dp[0][0] = 1;
    for (int where = 0; where < len; ++where)
    {
        vvl new_dp(D, vl(2));
        for (int sum = 0; sum < D; ++sum)
        {
            for (bool sm_already : {false, true})
            {
                for (lli digit = 0; digit < 10; ++digit)
                {
                    if (digit > K[where] - '0' && !sm_already)
                        break;
                    add_self(new_dp[(sum + digit) % D][sm_already || (digit < K[where] - '0')], dp[sum][sm_already]);
                }
            }
        }
        dp = new_dp;
    }
    int answer = dp[0][false] + dp[0][true] % mod;
    answer--;
    if (answer == -1)
        answer = mod - 1;
    cout << answer << '\n';
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
