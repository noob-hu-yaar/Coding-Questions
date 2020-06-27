

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

int t;
int main()
{
    fast_io;

    cin>>t;

while(t--)
{
    int n,x;
    cin>>n>>x;
    int a[n+1],odd = 0;

    for(int i=0;i<n;i++)
    {
        cin>>a[i];

        if(a[i] & 1)
        odd++;
    }

    if(odd == 0)
    cout<<"No";
    else if( (odd%2==0) && x==n )
    cout<<"No";
    else if( odd==n && x%2==0)
    cout<<"No";
    else
    cout<<"Yes";

    cout<<endl;
}

return 0;
}
