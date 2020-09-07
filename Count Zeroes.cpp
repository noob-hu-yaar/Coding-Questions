

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

    int n;
    cin>>n;

    int ans = 0;
    
    do
    {
        ans += (n/5);
        n = n/5; 
    }
    while( (n/5) != 0);

    cout<<ans<<endl;

return 0;
}
