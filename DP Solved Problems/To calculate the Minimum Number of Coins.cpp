
// To calculate the Minimum Number of Coins

#include <bits/stdc++.h>

#define int long long
#define endl "\n"
#define mod 1000000007
#define inf 0xFFFFFFFFFFFFFFFL

using namespace std;

const int mxn = 1e6 + 5;

int dp[mxn], dp2[mxn], dp3[mxn];
vector<int> coins;

int recursive(int n)
{
    if (dp2[n] == -1)
        dp2[n] = inf;
    for (auto x : coins)
        if (n - x >= 0)
        {
            dp2[n] = min(dp2[n], recursive(n - x) + 1);
        }

    return dp2[n];
}

int Top_Down(int n)
{
    if (dp[n] == -1)
    {
        dp[n] = inf;
        for (auto x : coins)
            if (n - x >= 0)
            {
                dp[n] = min(dp[n], Top_Down(n - x) + 1);
            }
    }
    return dp[n];
}

void solve()
{
    int n, k;
    cin >> k >> n;

    for (int i = 0; i < k; i++)
    {
        int x;
        cin >> x;
        coins.push_back(x);
    }

    cout << recursive(n) << endl;
    int TopOne = Top_Down(n);
    if (TopOne == inf)
        cout << -1 << endl;
    else
        cout << TopOne << endl;

    // buttom up
    for (int i = 1; i <= n; i++)
    {
        if (dp3[i] == -1)
            dp3[i] = inf;
        for (auto x : coins)
        {
            if (i - x >= 0)
                dp3[i] = min(dp3[i], dp3[i - x] + 1);
        }
    }
    if (dp3[n] == inf)
        cout << -1 << endl;
    else
        cout << dp3[n] << endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    srand(chrono::steady_clock::now().time_since_epoch().count());

    cout << fixed << setprecision(16) << endl;

    dp[0] = dp2[0] = dp3[0] = 0;

    for (int i = 1; i < mxn; i++)
        dp[i] = dp2[i] = dp3[i] = -1;
    // int tt;
    // cin >> tt;
    // while (tt--)
    solve();

    return 0;
}
