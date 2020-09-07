//https://www.hackerrank.com/contests/gs-codesprint/challenges/bank-accounts



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

ll t;
int main()
{
    fast_io;

    cin>>t;
while(t--)
{
        int n;
        int k;
        int x;
        int d;
        cin >> n >> k >> x >> d;

        vector<int> p(n);

        for(int &i : p)
        cin>>i;

        double op1 = 0, op2 = d;

        for(int i=0;i<p.size();i++)
        op1 += max(k*1.0, (x*p[i]*1.0)/100);

        op2 < op1 ? cout<<"upfront"<<endl : cout<<"fee"<<endl;
}

return 0;
}
