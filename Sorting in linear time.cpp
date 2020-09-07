// Dutch National Flag Algo/ 3 pointer method

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
    vector<int> a(n);

    for(int &i : a)
    cin>>i;

    int low = 0,mid = 0,high = n-1;

    while(mid <= high)
    {
        if(a[mid] == 1)
        mid++;

        else if(a[mid] == 0)
        {
            swap(a[low],a[mid]);
            mid++,low++;
        }

        else if(a[mid] == 2)
        {
            swap(a[mid],a[high]);
            high--;
        }
    }

    for(int i=0;i<n;i++)
    cout<<a[i]<<" ";

    return 0;
}


// time = O(n)
// space = O(1)
// Sort an array of 0s, 1s and 2s