

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


ll fact(ll n)
{
    if(n == 0 || n == 1)
        return 1;

    return n*fact(n-1);
}
int main()
{
    fast_io;

    ll a,b;
    cin>>a>>b;

    ll mini = min(a,b);

    cout<<fact(mini)<<endl;

return 0;
}