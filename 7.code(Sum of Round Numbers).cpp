

#include <bits/stdc++.h> 
#define ll long long
#define ull unsigned long long
#define endl '\n'
#define pb push_back
#define mp make_pair
#define sp(x) fixed<<setprecision(x)
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

int rem,a;
vector<int> v;

vector<int> solve(int n,int i)
{
    //Base case
    if(n == 0)
    return {0};

     rem = n%10;
     a = rem * pow(10,i);
     v.pb(a);
     solve(n/10,i+1);

     return v;
}

int main()
{
    fast_io;

    int t;
    cin>>t;
    while(t--)
    {
        int n,cnt=0;
        cin>>n;
        
        solve(n,0);
        for(int j=0;j<v.size();j++)
        {
            if(v[j] != 0)
            cnt++;
        }
        cout<<cnt<<endl;
        for(int j=0;j<v.size();j++)
        if(v[j] != 0)
        cout<<v[j]<<" ";

        cout<<endl;
        v.clear();
    }
    return 0;
}
