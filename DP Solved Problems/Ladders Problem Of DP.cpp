
// Ladders Problem Of DP

#include <bits/stdc++.h>

#define int long long
#define endl "\n"
#define mod 1000000007
#define inf 0xFFFFFFFFFFFFFFFL

using namespace std;

int dp[100];
vector<int> ways(100);

// Using Top-Down Approch
int Ways(int n)
{
    if (n < 0)
        return 0;
    if (dp[n] == -1)
    {
        dp[n] = 0;
        for (auto x : ways)
        {
            if (n - x >= 0)
                dp[n] += Ways(n - x);
        }
    }
    return dp[n];
}

void solve()
{
    int n, k;
    cin >> n >> k;

    for (int i = 0; i < k; i++)
    {
        ways[i] = i + 1;
    }
    sort(ways.begin(), ways.end());
    cout << Ways(n) << endl;

    // Using Buttom Up Approach
    vector<int> dp2(100, 0);
    dp2[0] = 1;

    int prev = 0;
    for (int i = 1; i <= n; i++)
    {
        if (i <= k)
        {
            //  if numbers are not from 1 -> k or they are different
            //for (int j = 0; j < k; j++)
            // {
            // 	if (i - ways[j] >= 0)
            // 	{
            // 		dp2[i] += dp2[i - ways[j]];
            // 	}
            // 	else
            // 		break;
            // }
            prev = dp2[i - 1];
            if (i != 1)
                prev += dp2[i - 1];
            dp2[i] = prev;
        }
        else
        {
            prev = dp2[i - 1];

            prev -= dp2[i - k];

            prev += dp2[i - 1];

            dp2[i] = prev;
        }
    }

    cout << dp2[n] << endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    srand(chrono::steady_clock::now().time_since_epoch().count());

    cout << fixed << setprecision(16) << endl;

    dp[0] = 1;
    for (int i = 1; i < 100; i++)
        dp[i] = -1;
    int tt;
    cin >> tt;
    while (tt--)
        solve();

    return 0;
}
