
//Weighted Job Scheduling

#include <bits/stdc++.h>

#define int long long
#define endl "\n"
#define mod 1000000007
#define inf 0xFFFFFFFFFFFFFFFL

using namespace std;

bool sortbysec(const pair<int, pair<int, int>> &a, const pair<int, pair<int, int>> &b)
{
    return (a.first < b.first);
}

void solve()
{
    int n;
    cin >> n;

    vector<pair<int, pair<int, int>>> time(n);
    vector<int> profit(n), dp(n);

    for (int i = 0; i < n; i++)
    {
        cin >> time[i].second.first;
    }
    for (int i = 0; i < n; i++)
        cin >> time[i].first;
    for (int i = 0; i < n; i++)
        cin >> profit[i], time[i].second.second = profit[i];

    sort(time.begin(), time.end());

    for (int i = 0; i < n; i++)
        dp[i] = time[i].second.second;

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (time[j].first <= time[i].second.first)
            {
                dp[i] = max(dp[i], dp[j] + time[i].second.second);
            }
        }
    }

    // for (int i = 0; i < n; i++)
    // {
    // 	cout << time[i].first << ' ' << time[i].second.first << ' ' << time[i].second.second << endl;
    // }

    // for (auto x : dp)
    // 	cout << x << ' ';
    // cout << endl;

    int ans = INT_MIN;

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

    int tt;
    cin >> tt;
    while (tt--)
        solve();

    return 0;
}