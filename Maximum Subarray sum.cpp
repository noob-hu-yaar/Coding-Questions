

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
    int n;
    cin>>n;
    vector<int> a(n);

    for(int &i : a)
    cin>>i;

    int best = a[0];
    int cs = a[0]>0 ? a[0] : 0;

    for(int i=1;i<n;i++)
    {
        cs += a[i];

        if(cs < 0)
            cs = 0;

        best = max(best, cs);
    }

    cout<<best<<endl;
}

return 0;
}
