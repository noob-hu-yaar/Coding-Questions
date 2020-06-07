

#include <bits/stdc++.h> 
#define ll long long
#define ull unsigned long long
#define endl '\n'
#define pb push_back
#define mp make_pair
#define sp(x) fixed<<setprecision(x)
#define p_q priority_queue
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

int main()
{
    fast_io;

    int t;
    cin>>t;

    while(t--)
    {
        ll n,k;
        cin>>n>>k;

        ll x = k/(n-1);
        ll rem = k - (x*(n-1));

        (rem > 0) ? cout<< (x*n) + rem <<endl : cout<< (x*n) - 1 <<endl;
    }
    return 0;
}


