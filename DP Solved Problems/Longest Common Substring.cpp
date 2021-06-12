
//Longest Common Substring

#include <bits/stdc++.h>

#define int long long
#define endl "\n"
#define mod 1000000007
#define inf 0xFFFFFFFFFFFFFFFL

using namespace std;

void solve()
{
    string a, b;
    cin >> a >> b;
    int n = a.size(), m = b.size();

    vector<int> dp[n + 1];

    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= m; j++)
            dp[i].push_back(0);

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            if (a[i - 1] == b[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
        }

    int ans = 0, k, l;
    string anstring = "";
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            ans = max(ans, dp[i][j]);

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (dp[i][j] == ans)
            {
                k = i, l = j;
                break;
            }

    while (dp[k][l] != 0)
    {
        anstring += a[k - 1];
        k--, l--;
    }

    reverse(anstring.begin(), anstring.end());

    cout << ans << ' ' << anstring << endl;
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