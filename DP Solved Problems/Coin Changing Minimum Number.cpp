
// Coin Changing Minimum Number

#include <bits/stdc++.h>

#define int long long
#define endl "\n"
#define mod 1000000007
#define inf 0xFFFFFFFFFFFFFFFL

using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> dp[n], v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    for (int i = 0; i < n; i++)
        for (int j = 0; j <= k; j++)
            dp[i].push_back(INT_MAX);

    dp[0][0] = 0;
    for (int i = 1; i <= k; i++)
    {
        if (i >= v[0])
            if (dp[0][i - v[0]] >= 0 and dp[0][i - v[0]] != INT_MAX)
                dp[0][i] = dp[0][i - v[0]] + 1;
    }

    for (int i = 1; i < n; i++)
    {
        dp[i][0] = 0;
        for (int j = 1; j <= k; j++)
        {
            if (j >= v[i] and dp[i][j - v[i]] != INT_MAX)
                dp[i][j] = min(dp[i - 1][j], dp[i][j - v[i]] + 1);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    // for (int i = 0; i < n; i++)
    // {
    // 	for (int j = 0; j <= k; j++)
    // 		cout << dp[i][j] << ' ';
    // 	cout << endl;
    // }
    if (dp[n - 1][k] == INT_MAX)
        dp[n - 1][k] = -1;
    cout << dp[n - 1][k] << endl;
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