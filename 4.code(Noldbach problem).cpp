

#include <bits/stdc++.h> 
#define ll long long
#define ull unsigned long long
#define endl '\n'
#define pb push_back
#define mp make_pair
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

const int n = 1e4+1;
const int N = 10000;
bitset<n> b;
vector<int> primes;


void sieve()
{
    //Setting all bits to 1
    b.set();

    b[0] = b[1] = 0; //they are not prime
    for(ll i=2;i<N;i++)
    {
        if(b[i])
        {
            primes.pb(i);
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

    int m,k,M;
    cin>>m>>k;
    sieve();

    int j = m;
    while(j>0)
    {
        if(b[j] == 1)
        {
            M = j;
            break;
        }
        else
        j--;
    }//prime number <= input.

    //Find location of M in primes[]
    int x;
    for(int i=0;i<M;i++)
    {
        if(primes[i] == M)
        {
            x = i;
            break;
        }
    }

    int K=0;
    for(int i=0;i<=x;i++)
    {
        for(int j=i-1;j>0;j--)
        {
            if( (primes[j] + primes[j-1] + 1) == primes[i])
            K++;
        }
    }

    if(K >= k)
    cout<<"YES"<<endl;
    else
    cout<<"NO"<<endl;

    return 0;
}
