//https://codeforces.com/contest/1352/problem/E


#include <bits/stdc++.h> 
#define ll long long
#define ull unsigned long long
#define endl '\n'
#define pb push_back
#define mp make_pair
#define sp(x) fixed<<setprecision(x)
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
        int a[n+1];
        bool count[n+1] = {};

        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            //count[i] = false;
        }

        for(int l=1;l<=n;l++)
        {
            int sum = a[l];
            for(int r=l+1;r<=n;r++)
            {
                sum += a[r];
                if(sum > n)
                break;

                count[sum] = true;
            }
        }
        int ans = 0;
        for(int i=1;i<=n;i++)
        if(count[a[i]])
        ans++;

        cout<<ans<<endl;
    }
    return 0;
}