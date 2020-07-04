 

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
    int n,m,k;
    cin>>n>>m>>k;
    
    int to_each = n/k;
    int res = 0;
    
    if(m <= to_each)
    res = m;
    
    else if(m > to_each)
    {
        int rem = m - to_each;
        int give_each = rem/(k-1);
        if(rem%(k-1) != 0)
        {
            res = to_each - (give_each + 1);
        }
        else if(rem%(k-1) == 0)
        res = to_each - give_each;
    }
    cout<<res<<endl;
}
return 0;
}