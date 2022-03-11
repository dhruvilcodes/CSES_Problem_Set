#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define MOD 1000000007
#define all(x) (x).begin(), (x).end()
#define endl "\n"

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

ll build_tree(vector<ll> &tree, vector<ll> &a, ll si, ll ei, ll ci)
{
    if (si == ei)
    {
        return tree[ci] = a[si];
    }
    ll mid = (si + ei) / 2;
    return tree[ci] = min(build_tree(tree, a, si, mid, 2 * ci + 1), build_tree(tree, a, mid + 1, ei, 2 * ci + 2));
}

ll rangeMaxQuery(vector<ll> &tree, ll si, ll ei, ll l, ll r, ll ci)
{
    if (ei < l or si > r)
    {
        return INT_MAX;
    }
    if (l <= si and ei <= r)
    {
        return tree[ci];
    }
    ll mid = (si + ei) / 2;

    return min(rangeMaxQuery(tree, si, mid, l, r, 2 * ci + 1) , rangeMaxQuery(tree, mid+1, ei, l, r, 2 * ci + 2));
}
    vector<ll> tree(800001, INT_MAX);
void solve()
{
    vector<ll> a;
    ll n, m;
    cin >> n >> m;
    for (ll i = 0; i < n; i++)
    {
        ll p;
        cin >> p;
        a.push_back(p);
    }

    build_tree(tree, a, 0, n - 1, 0);
    for (ll i = 0; i < m; i++)
    {
        ll p, q;
        cin >> p >> q;
        cout << rangeMaxQuery(tree, 0, n - 1, p - 1, q - 1, 0) << endl;
    }
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