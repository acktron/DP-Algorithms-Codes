
//Longest Planderomic Subsequenceyy

#include <bits/stdc++.h>

#define int long long
#define endl "\n"
#define mod 1000000007
#define inf 0xFFFFFFFFFFFFFFFL

using namespace std;

void solve()
{
    string s;
    cin >> s;
    int n = s.size();

    vector<int> dp[n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            dp[i].push_back(0);

    for (int i = 0; i < n; i++)
        dp[i][i] = 1;

    for (int in = 2; in <= n; in++)
    {
        for (int i = 0; i < n - in + 1; i++)
        {
            int j = i + in - 1;

            if (s[i] == s[j])
                dp[i][j] = dp[i + 1][j - 1] + 2;
            else
                dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
        }
    }
    // for (auto x : dp)
    // {
    // 	for (auto u : x)
    // 		cout << u << ' ';
    // 	cout << endl;
    // }
    cout << dp[0][n - 1] << endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    srand(chrono::steady_clock::now().time_since_epoch().count());

    cout << fixed << setprecision(16) << endl;

    int tt;
    cin >> tt;
    while (tt--)
        solve();

    return 0;
}