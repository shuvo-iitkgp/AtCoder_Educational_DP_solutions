#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define pb push_back
using lli = long long;
typedef vector<lli> vl;
typedef pair<lli, lli> pll;
typedef vector<pll> vp;
const lli N = 1e5 + 7;
lli n;
lli dp[N], h[N];
void go()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> h[i];
    dp[0] = 0;
    dp[1] = abs(h[1] - h[0]);
    for (int i = 2; i < n; i++)
    {
        dp[i] = min(abs(h[i] - h[i - 1]) + dp[i - 1], abs(h[i] - h[i - 2]) + dp[i - 2]);
    }
    cout << dp[n - 1] << '\n';
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    go();
    return 0;
}

// Think twice, code once.
