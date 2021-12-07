#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define MOD 1000000007

ll mod_add(ll a, ll b, ll m = MOD)
{
    a = a % m;
    b = b % m;
    return (((a + b) % m) + m) % m;
}
ll mod_mul(ll a, ll b, ll m = MOD)
{
    a = a % m;
    b = b % m;
    return (((a * b) % m) + m) % m;
}
ll mod_sub(ll a, ll b, ll m = MOD)
{
    a = a % m;
    b = b % m;
    return (((a - b) % m) + m) % m;
}

bool isPrime(ll n)
{
    if (n == 1)
        return false;
    if (n == 2 || n == 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;
    for (ll i = 5; i * i <= n; i = i + 6)
    {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }
    return true;
}

ll mfastPower(ll a, ll b, ll c = MOD)
{
    ll res = 1;
    while (b > 0)
    {
        if ((b & 1) != 0)
        {
            res = ((res % c) * (a % c) % c);
        }
        a = ((a % c) * (a % c)) % c;
        b = b >> 1;
    }
    return res;
}

ll res = 0, max_dist = 0;

void dfs(ll u, vector<vector<ll>> &adj, ll p = -1, ll d = 0)
{
    if (d > max_dist)
    {
        max_dist = d;
        res = u;
    }
    for (auto x : adj[u])
    {
        if (x == p)
        {
            continue;
        }
        else
        {
            dfs(x, adj, u, d + 1);
        }
    }
}

void solve()
{
    ll n;
    cin >> n;
    vector<vector<ll>> adj(n);
    for (ll i = 0; i < n - 1; i++)
    {
        ll x, y;
        cin >> x >> y;
        x--;
        y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(0, adj);
    max_dist = 0;
    dfs(res, adj);
    cout << max_dist;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    t = 1;
    while (t--)
    {
        solve();
        cout << endl;
    }

    return 0;
}