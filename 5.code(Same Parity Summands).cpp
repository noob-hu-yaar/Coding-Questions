//http://codeforces.com/contest/1352/problem/B

#include <bits/stdc++.h> 
#define ll long long
#define ull unsigned long long
#define endl '\n'
#define pb push_back
#define mp make_pair
#define sp(x) fixed<<setprecision(x)
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

int odd_mila(ll n,ll k)
{
    ll rem2 = n-k;
    //Base case
    if(rem2 < 0)
    return 0;

    if( rem2 %2 != 0)//odd
    return 0;

    cout<<"YES"<<endl;
    for(int i=1;i<k;i++)
    cout<<"1"<<" ";
    cout<<(1+rem2)<<endl;

    return 1;
}

int even_mila(ll n,ll k)
{
    ll rem1 = n-2*k;
    //Base case
    if(rem1 < 0)
    return 0;

    if( rem1 %2 != 0)//odd
    return 0;

    cout<<"YES"<<endl;
    for(int i=1;i<k;i++)
    cout<<"2"<<" ";
    cout<<(2+rem1)<<endl;

    return 1;
}

int main()
{
    fast_io;
    
    int t;
    cin>>t;
    while(t--)
    {
        ll n,k;
        cin>>n>>k;

        if(odd_mila(n,k) || even_mila(n,k))
        continue;
        else
        cout<<"NO"<<endl;
    }
    return 0;
}