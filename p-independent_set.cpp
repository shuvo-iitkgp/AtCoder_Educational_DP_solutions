#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define pb push_back
using lli = long long;
typedef vector<lli> vl;
typedef pair<int, int> pll;
typedef vector<pll> vp;
const lli mod = 1e9 + 7, N = 1e5 + 4;
vector<int> edges[N];
int mul(int a, int b)
{
    return (lli)a * b % mod;
}
pll dfs(int a, int parent)
{

    int all_white = 1; //means vertex can be painted black.
    int sth_is_black = 0;

    for (int b : edges[a])
    {
        if (b != parent)
        {
            pll p = dfs(b, a);
            //p.first is the no. of ways to color of subtree such that the b is black;
            int memo_all_white = all_white;
            all_white = mul(all_white, p.second);
            sth_is_black = (mul(memo_all_white, p.F) + mul(sth_is_black, p.F + p.S)) % mod;
        }
    }
    return {all_white, (all_white + sth_is_black) % mod};
}
void solve()
{
    //            [ ]
    //      [ ]        [ ]
    //   [ ]   [ ]   [ ]
    //[ ]  [ ]         [ ]

    //it isnt' important about how the color of next siblings vertex is...its just th3e back vertex i.e. important.
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        edges[a].pb(b);
        edges[b].pb(a);
    }
    pll p = dfs(1, -1);
    int answer = (p.F + p.S) % mod;
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
