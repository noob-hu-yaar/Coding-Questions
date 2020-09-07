

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

int bs(int a[],int l,int h,int key)
{
    if(l > h)
    return -1;

    int mid = (l + h)/2;

    if(a[mid] == key)
    return mid;

    if(a[l] < a[mid])
    {
        if(key>=a[l] &&  key<=a[mid])
        {
            return bs(a,l,mid-1,key);
        }
        return bs(a,mid+1,h,key);
    }

    if(key>=a[mid] && key<=a[h])
    {
        return bs(a,mid+1,h,key);
    }

    return bs(a,l,mid-1,key);
}

int main()
{
    fast_io;

    int n;
    cin>>n;
    int a[n+1];

    for(int i=0;i<n;i++)
    cin>>a[i];

    int key;
    cin>>key;

    cout<<bs(a,0,n-1,key)<<endl;

return 0;
}