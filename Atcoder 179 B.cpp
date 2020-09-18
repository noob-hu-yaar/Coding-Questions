

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

    ll a,b,c,d;
    cin>>a>>b>>c>>d;

    cout<<max({a*c, a*d,b*c,b*d})<<endl;

return 0;
}
