
// Minimum Edit Distance

#include <bits/stdc++.h>

#define int long long
#define endl "\n"
#define mod 1000000007
#define inf 0xFFFFFFFFFFFFFFFL

using namespace std;

void solve()
{
    string a, b;
    cin >> b >> a;

    int n = a.size(), m = b.size();

    vector<int> dp[n + 1];

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            dp[i].push_back(-1);
            if (j == 0)
                dp[i][j] = i;
            if (i == 0)
                dp[i][j] = j;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[i - 1] == b[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
        }
    }
    // for (int i = 0; i <= n; i++)
    // {
    // 	for (int j = 0; j <= m; j++)
    // 		cout << dp[i][j] << ' ';
    // 	cout << endl;
    // }
    cout << dp[n][m] << endl;
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