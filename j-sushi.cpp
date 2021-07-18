#include <bits/stdc++.h>
using namespace std;
using ld = long double;
const int N = 301;

int n;
ld dp[N][N][N]; // -> expected no. of operations to get to state (a, b, c)
ld rec(int a, int b, int c)
{
    if (dp[a][b][c] > -1)
        return dp[a][b][c];
    ld ans = 0.0, sum = 1.0 * (a + b + c);

    ans += a > 0 ? rec(a - 1, b, c) * ((ld)1.0 * a / sum) : 0;
    ans += b > 0 ? rec(a + 1, b - 1, c) * (ld)b / sum : 0;
    ans += c > 0 ? rec(a, b + 1, c - 1) * (ld)c / sum : 0;
    if (sum > 0)
        ans += (ld)n / sum;
    return dp[a][b][c] = ans;
}
void go()
{
    cin >> n;
    vector<int> cnt(4, 0);
    for (int i = 0; i < n; i++)
    {
        int c;
        cin >> c;
        cnt[c]++;
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < N; k++)
            {
                dp[i][j][k] = -1;
            }
        }
    }
    cout << fixed << setprecision(10) << rec(cnt[1], cnt[2], cnt[3]) << "\n";
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
