

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
    int a[n+1];

    int x,c = 0;
    for(int i=0;i<n;i++)
    {
        cin>>x;

        if(x == 0)
        c++;
        else
        cout<<x<<" ";
    }

    for(int i=0;i<c;i++)
    cout<<0<<" ";

return 0;
}