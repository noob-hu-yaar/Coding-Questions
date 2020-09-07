
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


vector<ll> majorityElement(vector<ll>& v, ll n)
    {
        ll el1 = v[0], el2 = 0,count1 = 1,count2 = 0;
        
        for(ll i=0;i<v.size();i++)
        {
            if(v[i] == el1)
                count1++;
            else if(v[i] == el2)
                count2++;
            
            else if(count1 == 0)
            {
                el1 = v[i];
                count1++;
            }
            else if(count2 == 0)
            {
                el2 = v[i];
                count2++;
            }
            
            else
                count1--,count2--;
        }
        
        ll c1 = 0,c2 = 0;
        for(ll i=0;i<v.size();i++)
        {
            if(v[i] == el1)
                c1++;
            else if(v[i] == el2)
                c2++;
        }
        
        vector<ll> ans;
        if(c1 > v.size()/3)
            ans.push_back(el1);
        if(c2 > v.size()/3)
            ans.push_back(el2);
        
return ans;
    }

int main()
{
    fast_io;

    ll n;
    ll x;
    cin>>n;

    vector<ll> v;
    for(ll i=0;i<n;i++)
    {
        cin>>x;
        v.pb(x);
    }

    //cout<<majorityElement(v,n)<<endl;
    vector<ll> v1 = majorityElement(v,n);

    if(v1.size() != 0)
    {
    for(int i=0;i<v1.size();i++)
    cout<<v1[i]<<" ";
    }
    else
    cout<<"No Majority Elements";

return 0;
}