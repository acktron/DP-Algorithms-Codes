
//Cutting Rod Dynamic Programming

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
    vector<int> v(n), dp[n];
    vector<int> dp2(k + 1, 0);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    for (int i = 0; i < n; i++)
        for (int j = 0; j <= k; j++)
            dp[i].push_back(0);

    //Using 2d DP

    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            if (i == 0)
            {
                if (i + 1 <= j)
                    dp[i][j] = dp[i][j - (i + 1)] + v[i];
            }
            else if (i + 1 <= j)
                dp[i][j] = max(dp[i - 1][j], dp[i][j - (i + 1)] + v[i]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    cout << dp[n - 1][k] << endl;

    //Using 1d DP
    for (int i = 1; i <= k; i++)
    {
        for (int j = 0; j < n; j++)
            if (j + 1 <= i)
                dp2[i] = max(dp2[i], dp2[i - (j + 1)] + v[j]);
    }
    cout << dp2[k] << endl;
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