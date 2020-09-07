

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

int bs(int a[],int low,int high)
{
   
while(low <= high)
{

	int mid = (low + high)/2;

    if(low == high)
    return a[low];

    
    if(mid%2 == 0)
    {
        if(a[mid] == a[mid+1])
        low = mid + 2;

        else
        high = mid;
    }

    else
    {
        if(a[mid] == a[mid-1])
        low = mid + 1;
        
        else
        high = mid - 1;
    }
}

return -1;
}


int main()
{
    fast_io;

    int n;
    cin>>n;
    int a[n+1];

    for(int i=0;i<n;i++)
    cin>>a[i];

   cout<< bs(a,0,n-1)<<endl;

    return 0;
}

