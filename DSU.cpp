#include <bits/stdc++.h>

#define int long long
#define endl "\n"

using namespace std;

const int mxn = 2e5 + 5;

struct DSU
{
    int connected;
    int par[mxn], sz[mxn];

    void init(int n)
    {
        for (int i = 1; i <= n; i++)
        {
            par[i] = i;
            sz[i] = 1;
        }
        connected = n;
    }

    int getPar(int k)
    {
    	return par[k]=(par[k]==k?k:getPar(par[k]));
    }

    int getSize(int k)
    {
        return sz[getPar(k)];
    }

    void unite(int u, int v)
    {
        int par1 = getPar(u), par2 = getPar(v);

        if (par1 == par2)
            return;

        connected--;

        if (sz[par1] > sz[par2])
            swap(par1, par2);

        sz[par2] += sz[par1];
        sz[par1] = 0;
        par[par1] = par[par2];
    }
};

DSU dsu;

void solve()
{
    dsu.init(mxn);
    
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    srand(chrono::steady_clock::now().time_since_epoch().count());

    cout << fixed << setprecision(10) << endl;
    // int tt;
    // cin >> tt;
    // while (tt--)
    solve();
    return 0;
}
