

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

int fun(int n,vector<int> v)
{
    int i = 0,j = n-1;
    int area = 0;

    while(i < j)
    {
        area = max(area, min(v[i],v[j])*(j-i));

        if(v[i] < v[j])
        i++;
        else
        j--;
    }

return area;
}

int main()
{
    fast_io;

    int n;
    cin>>n;
    vector<int> v(n);
    for(int &i : v)
    cin>>i;

    cout<<fun(n,v)<<endl;

return 0;
}