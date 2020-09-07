

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

void lps(string s)
{
    int n = s.size();

    bool dp[n][n];
    memset(dp,0,sizeof(dp));

    int length = 1, start = 0;

    for(int i=0;i<n;i++)
        dp[i][i] = 1;

    // lenght = 2;

    for(int i=0;i<n-1;i++)
    {
        if(s[i] == s[i+1])
        {
            dp[i][i+1] = 1;
            length = 2;
            start = i;
        }
    }

    // length > 2

    for(int k=3;k<=n;k++)
    {
        for(int i=0;i<n-k+1;i++)
        {
            int j = i+k-1;

            if(s[i]==s[j] && dp[i+1][j-1])
            {
                dp[i][j] = 1;

                if(k > length)
                {
                    length = k;
                    start = i;
                }
            }
        }
    }

    for(int i=start;i<=start+length-1;i++)
        cout<<s[i];

    cout<<endl;

    //return length;
}

int t;
int main()
{
    fast_io;

    cin>>t;
while(t--)
{
    string s;
    cin>>s;

    lps(s);

   // cout<<lps(s)<<endl;
}

return 0 ;
}