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

int dp[100001][101];
void solve()
{
    int n, m;
    cin >> n >> m;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    if (a[0] == 0)
    {
        for (int j = 1; j <= m; j++)
        {
            dp[0][j] = 1;
        }
    }
    else
    {
        for (int j = 1; j <= m; j++)
        {
            if (j == a[0])
                dp[0][j] = 1;
            else
                dp[0][j] = 0;
        }
    }

    // for (auto x : dp[0])
    // {
    //     cout << x << " ";
    // }
    for (int i = 1; i < n; i++)
    {

        if (a[i] == 0)
        {
            for (int j = 1; j <= m; j++)
            {
                dp[i][j] = 0;
                for (int k : {j - 1, j, j + 1})
                {
                    if (k >= 1 and k <= m)
                    {
                        dp[i][j] = mod_add(dp[i][j], dp[i - 1][k]);
                    }
                }
            }
        }
        else
        {
            for (int j = 1; j <= m; j++)
            {
                dp[i][j] = 0;
                if (j == a[i])
                {
                    for (int k : {j - 1, j, j + 1})
                    {
                        if (k >= 1 and k <= m)
                        {
                            dp[i][j] = mod_add(dp[i][j], dp[i - 1][k]);
                        }
                    }
                }
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= m; i++)
    {
        ans = mod_add(ans, dp[n - 1][i]);
    }
    cout << ans;
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