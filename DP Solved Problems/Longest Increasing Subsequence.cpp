
//	Longest Increasing Subsequence

#include <bits/stdc++.h>

#define int long long
#define endl "\n"
#define mod 1000000007
#define inf 0xFFFFFFFFFFFFFFFL

using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> v(n), dp(n, 1);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    for (int i = 1; i < n; i++)
        for (int j = 0; j < i; j++)
            if (v[i] >= v[j])
                dp[i] = max(dp[i], dp[j] + 1);

    int ans = 0;
    for (int i = 0; i < n; i++)
        ans = max(ans, dp[i]);
    cout << ans << endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    srand(chrono::steady_clock::now().time_since_epoch().count());

    cout << fixed << setprecision(16) << endl;

    // int tt;
    // cin >> tt;
    // while (tt--)
    solve();

    return 0;
}