

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

    vector<string> a;
    string x,word1,word2;

    for(int i=0;i<n;i++)
    {
        cin>>x;
        a.pb(x);
    }

    cin>>word1>>word2;

    int w1,w2;
    w1 = w2 = -1;
    bool w1_mila = 0, w2_mila = 0;
    int ans = n+1;

    for(int i=0;i<n;i++)
    {
        if(a[i] == word1)
        {
            w1 = i;
            w1_mila = 1;
        }

        else if(a[i] == word2)
        {
            w2 = i;
            w2_mila = 1;
        }

        if(w1_mila && w2_mila)
        {
            ans = min(ans, abs(w1-w2));
        }
    }

    cout<<ans<<endl;

return 0;
}