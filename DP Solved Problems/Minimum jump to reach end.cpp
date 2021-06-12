
//Minimum jump to reach end

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
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    vector<int> dp(n, INT_MAX), places(n, -1);

    dp[0] = 0;

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if ((v[j] + j) - i >= 0)
            {
                if (dp[i] > dp[j] + 1)
                {
                    dp[i] = dp[j] + 1, places[i] = j;
                }
            }
        }
    }

    // for (auto x : dp)
    // 	cout << x << ' ';
    // cout << endl;
    // for (auto x : places)
    // 	cout << x << ' ';
    cout << dp[n - 1] << ' ' << places[n - 1] << endl;
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