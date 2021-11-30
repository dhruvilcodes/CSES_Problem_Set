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

void solve()
{
    ll n;
    cin >> n;
    vector<ll> a;
    vector<ll> b;
    ll p = (n * (n + 1)) / 2;
    if (p % 2 != 0)
    {
        cout << "NO";
        return;
    }
    else
    {
        cout << "YES" << endl;

        if (n % 2 == 0)
        {
            ll p = n / 2;
            while (p > 0)
            {
                if (p % 2 == 1)
                {

                    b.push_back(n);
                    n--;
                    a.push_back(n);
                    n--;
                }
                else
                {
                    a.push_back(n);
                    n--;
                    b.push_back(n);
                    n--;
                }
                p--;
            }
        }
        else
        {
            ll p = n / 2;

            while (p > 0)
            {
                if (p % 2 == 1)
                {

                    b.push_back(n);
                    n--;
                    a.push_back(n);
                    n--;
                }
                else
                {
                    a.push_back(n);
                    n--;
                    b.push_back(n);
                    n--;
                }
                p--;
            }
            a.push_back(1);
        }
        
    }
    cout << a.size() << endl;
    for (auto x : a)
    {
        cout << x << " ";
    }
    cout << endl;
    cout << b.size() << endl;
    for (auto x : b)
    {
        cout << x << " ";
    }
    //  cout<<endl;
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