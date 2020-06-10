

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
    int n;
    cin>>n;
if(n<4)
cout<<"-1"<<endl;

else
{   vector<int> ans;
    for(int i=n;i>4;i--)
    {
        if(i % 2 == 0)
        ans.pb(i);
    }
    ans.pb(2);
    ans.pb(4);

    for(int i=1;i<=n;i++)
    {
        if(i % 2 != 0)
        ans.pb(i);
    }

    for(int i=0;i<ans.size();i++)
    cout<<ans[i]<<" ";
    cout<<endl;
}
}

return 0;
}
