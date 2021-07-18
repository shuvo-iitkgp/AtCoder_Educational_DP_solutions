#include <bits/stdc++.h>
using namespace std;

using lli = long long;

const int N = 2e5 + 5;

lli n, h[N];
lli a[N], bit[N];

void insert(lli p, lli v)
{
    for (; p <= n; p += p & (-p))
        bit[p] = max(v, bit[p]);
}

lli get_max(lli p)
{
    lli r = 0;
    for (; p; p -= p & (-p))
        r = max(r, bit[p]);
    return r;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> h[i];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        insert(h[i], get_max(h[i]) + a[i]);
    cout << get_max(n);
    return 0;
}