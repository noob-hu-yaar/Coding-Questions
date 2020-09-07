

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

bool compare(const pair<int,int>&a, const pair<int,int>&b)
{
    return (a.second < b.second);
}

int main()
{
    fast_io;

    int n;
    cin>>n;
    int s,e;
    vector< pair<int,int> > v;

    for(int i=0;i<n;i++)
    {
        cin>>s>>e;
        v.pb(mp(s,e));
    }

    sort(v.begin(),v.end(),compare);

    int res = v[0].second;
    for(int i=1;i<n;i++)
    {
        if(v[i].first < res)
        {
            cout<<"false"<<endl;
            break;
        }

        res = v[i].second;
        if(i == n-1)
        cout<<"true"<<endl;
    }

    return 0;
}
