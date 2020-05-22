

#include <bits/stdc++.h> 
#define ll long long
#define ull unsigned long long
#define endl '\n'
#define pb push_back
#define mp make_pair
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

const ll n = 100005;
const ll N = 100002;
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

    ll m;
    cin>>m;

    //vector<ll> ans(m,1);
    sieve();

    m>2 ? cout<<2 : cout<<1;
    cout<<endl;

    for(ll i=2;i<=m+1;i++)
    {
        if(b[i])
        cout<<1<<" ";
        else
        cout<<2<<" ";
    }
    return 0;

}

