#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define MOD 1000000007
#pragma GCC optimize("Ofast")
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

void solve()
{
    string a;
    cin >> a;
    unordered_map<char, ll> mp;
    char b[a.size()];
    for (auto x : a)
    {
        mp[x]++;
    }
    ll check = 0;
    for (auto x : mp)
    {
        if ((x.second) % 2 == 1 and check == 0)
        {
            b[a.size() / 2] = x.first;
            check = 1;
        }
        else if ((x.second) % 2 == 1)
        {
            cout << "NO SOLUTION";
            return;
        }
    }

    ll l = 0;
    ll r = a.size() - 1;
    for (auto x : mp)
    {
        for (ll i = 0; i < x.second / 2; i++)
        {
            b[l] = x.first;
            l++;
            b[r] = x.first;
            r--;
        }
    }
    for(auto x:b)
    {
        cout<<x;
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