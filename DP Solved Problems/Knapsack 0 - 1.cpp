
// Knapsack 0 - 1

#include <bits/stdc++.h>

#define int long long
#define endl "\n"
#define mod 1000000007
#define inf 0xFFFFFFFFFFFFFFFL

using namespace std;

/*
1
11 4
2 5
3 20
4 10
7 20
*/

vector<int> dp(1000000);

int Recursion(vector<pair<int, int>> &items, int n)
{
    //cout << n << endl;
    if (n == 0)
        return 0;
    int k = items.size();
    if (k == 0)
        return 0;
    vector<pair<int, int>> temp = items;

    int lw = temp[temp.size() - 1].first;
    int lc = temp[temp.size() - 1].second;
    temp.pop_back();

    if (lw > n)
        lw = lc = 0;
    dp[n] = max(lc + Recursion(temp, n - lw), Recursion(temp, n));

    // if(n == 1)
    // 	cout << dp[n] <<' ' << k << ' ' << lw << endl;
    return dp[n];
}

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> items;

    for (int i = 0; i < k; i++)
    {
        pair<int, int> temp;
        cin >> temp.first >> temp.second;
        items.push_back(temp);
    }

    vector<pair<int, int>> temp = items;

    int lw = temp[temp.size() - 1].first;
    int lc = temp[temp.size() - 1].second;
    temp.pop_back();

    if (lw > n)
        lw = 0;
    dp[n] = max(lc + Recursion(temp, n - lw), Recursion(temp, n));

    cout << dp[n] << endl;

    //buttom up only when we can use one item more than one

    dp[0] = 0;

    for (int i = 1; i <= n; i++)
    {
        dp[i] = dp[i - 1];
        for (auto x : items)
        {
            if (i - x.first >= 0)
            {
                dp[i] = max(dp[i], dp[i - x.first] + x.second);
            }
        }
    }
    // cout << dp[n] << endl;

    //buttom up DP

    int dpbu[k + 1][n + 1];

    for (int i = 0; i <= k; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 or j == 0)
            {
                dpbu[i][j] = 0;
            }
            else if (items[i - 1].first <= j)
            {
                dpbu[i][j] = max(items[i - 1].second + dpbu[i - 1][j - items[i - 1].first], dpbu[i - 1][j]);
            }
            else
                dpbu[i][j] = dpbu[i - 1][j];
        }
    }

    cout << dpbu[k][n] << endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    srand(chrono::steady_clock::now().time_since_epoch().count());

    //cout << fixed << setprecision(16) << endl;

    dp[0] = 0;
    for (int i = 0; i < dp.size(); i++)
        dp[i] = -1;
    int tt;
    cin >> tt;
    while (tt--)
        solve();

    return 0;
}
