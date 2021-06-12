
//Longest Common Subsecquence

#include <bits/stdc++.h>

#define int long long
#define endl "\n"
#define mod 1000000007
#define inf 0xFFFFFFFFFFFFFFFL

using namespace std;

void solve()
{

    int n, m;
    cin >> n >> m;
    string a, b;
    cin >> a >> b;

    n = a.size(), m = b.size();

    int dp[n + 1][m + 1];

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (i == 0 or j == 0)
                dp[i][j] = 0;
            else if (a[i - 1] == b[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    string ans = "";

    int k = n, l = m;

    while (k > 0 or l > 0)
    {
        if (a[k - 1] == b[l - 1])
        {
            ans += a[k - 1];
            k--, l--;
        }
        else
        {
            if (dp[k][l] == dp[k - 1][l])
                k--;
            else
                l--;
        }
    }

    reverse(ans.begin(), ans.end());
    cout << ans << ' ' << dp[n][m] << endl;
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