#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define MOD 1000000007


ll mod_add(ll a, ll b, ll m = MOD) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;} 
ll mod_mul(ll a, ll b, ll m = MOD) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m = MOD) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}


bool isPrime(ll n)
{
    if(n==1)
    return false;
    if(n==2 || n==3)
    return true;
    if(n%2==0 || n%3==0)
    return false;
    for(ll i=5; i*i<=n; i=i+6)
    {
    if(n % i == 0 || n % (i + 2) == 0)
        return false; 
    }
        return true;
}


ll mfastPower(ll a, ll b, ll c=MOD)
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
    cin>>n;
    ll i=0;
    ll a[n];
     for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    ll count=0;
    for(i=1;i<n;i++)
    {
        if(a[i]<a[i-1])
        {
            count+=abs(a[i]-a[i-1]);
            a[i]=a[i-1];
        }
    }

    cout<<count;


}


int main()
{
 ios_base::sync_with_stdio(false);cin.tie(NULL);


 ll t;
 t=1;
 while(t--)
{
 solve();
cout<<endl;
}



return 0;
}