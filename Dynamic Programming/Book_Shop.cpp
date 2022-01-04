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

int dp[1001][100001];
void solve()
{
    int n, target;
    cin >> n >> target;
    int a[n], b[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
 
    for(int i=0;i<=n;i++)
    {
        dp[i][0]=0;
    
    }
    for(int i=0;i<=target;i++)
    {
        dp[0][i]=0;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=target;j++)
        {
            if(j>=a[i-1])
            {
                dp[i][j]=max(b[i-1]+dp[i-1][j-a[i-1]],dp[i-1][j]);
            }
            else 
            {
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    cout<<dp[n][target];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    t=1;
    while (t--)
    {
        solve();
        cout << endl;
    }

    return 0;
}