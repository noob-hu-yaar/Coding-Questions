

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

    int t;
    cin>>t;
while(t--)
{
        int n;
        cin>>n;
        int a[n+1];
        for(int i=0;i<n;i++)
        cin>>a[i];

        int l = 0,r = n-1,prev[2] = {},total[2] = {},moves = 0;
        bool whose = 0;

        while(l <= r)
        {
            int sum = 0;
            if(whose == 0)
            {
                //Alice enter
                bool done = 0;
                for(int i=l;i<=r;i++)
                {
                    if(sum > prev[1])
                    {
                        done = 1;
                        l = i;
                        break;
                    }
                    else
                    sum += a[i];
                }
                if(!done)
                l = r+1;
            }

            if(whose == 1)
            {
                //Bob enter
                bool done = 0;
                for(int i=r;i>=l;i--)
                {
                    if(sum > prev[0])
                    {
                        done = 1;
                        r = i;
                        break;
                    }
                    else
                    sum += a[i];
                }
                if(!done)
                r = l-1;
            }
            prev[whose] = sum;
            total[whose] += sum;
            moves++;
            whose = !whose;
        }
        cout<<moves <<" "<<total[0]<<" "<<total[1]<<endl;
}
return 0;
}
