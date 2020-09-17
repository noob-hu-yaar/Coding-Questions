

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

void fun()
{
    int n;
    cin>>n;

    //vector<int> a(n);
    int a[n+1];
    int freq[101] = {};

    for(int i=0;i<n;i++)
        {
            cin>>a[i];
            freq[ a[i] ]++;
        }

    //for(int i=0;i<101;i++)
        

    int ans = 0;

    for(int i=0;i<101;i++)
    {
        if(freq[i] != 0)
            freq[i]--;

        else
        {
            ans += i;
            break;
        }
    }

    for(int i=0;i<101;i++)
    {
        if(freq[i] != 0)
            freq[i]--;

        else
        {
            ans += i;
            break;
        }
    }

    cout<<ans<<endl;
}

int main()
{
    fast_io;
    
    int t;
    cin>>t;
    while(t--)
        fun();

    return  0;
}
