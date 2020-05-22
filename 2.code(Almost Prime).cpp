

#include <bits/stdc++.h> 
#define ll long long
#define ull unsigned long long
#define endl '\n'
#define pb push_back
#define mp make_pair
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

const ll n = 3001;
const ll N = 3000;
bitset<n> b;
//vector<ll> primes;


void sieve()
{
    //Setting all bits to 1
    b.set();

    b[0] = b[1] = 0; //they are not prime
    for(ll i=2;i<N;i++)
    {
        if(b[i])
        {
           // primes.pb(i);
            for(ll j=i*i;j<N;j+=i)
            {
                b[j] = 0;
            }
        }
    }
}

int main()
{
    fast_io;

    ll m,ans=0;
    cin>>m;
    sieve();

    for(ll i=2;i<=m;i++)
    {
        ll c = 0;
        if(!b[i])
        {
            for(ll j=2;j<i;j++)
            {
                if(b[j]==1 && (i%j)==0)
                c++;
            }
        }
        if(c==2)
        ans++;
    }
    cout<<ans<<endl;
    return 0;
}

