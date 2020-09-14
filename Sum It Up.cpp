//https://hack.codingblocks.com/app/contests/1783/621/problem
// combination sum ii



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

int n;

void help(vector<int> &ans, vector< vector<int> > &vec, int index, vector<int> &num, int tar)
{
    if(tar == 0)
        return (vec.pb(ans));

    if(tar < 0)
        return ;
    
    for(int i=index; i<n && num[i]<=tar ;i++)
    {
        if(i==index || num[i-1]!=num[i])
        {
            ans.pb(num[i]);

            help(ans, vec, i+1, num, tar-num[i]);
            ans.pop_back();
        }
    }
}

vector< vector<int> > fun(vector<int> &num, int tar)
{
    vector<int> ans;
    vector<vector<int>> vec;

    sort(num.begin(), num.end());

    help(ans, vec, 0, num, tar);

return vec;
}

int main()
{
    fast_io;

    cin>>n;

    vector<int> num(n);

    for(int &i : num)
        cin>>i;

    int tar;
    cin>>tar;

    //cout<<<<endl;
    vector<vector<int>> bolo = fun(num, tar);

    for(int i=0;i<bolo.size();i++)
    {
        for(int j=0;j<bolo[i].size();j++)
        cout<<bolo[i][j]<<" ";
        cout<<endl;
    }

return 0;
}
