/*
https://practice.geeksforgeeks.org/problems/sum-of-all-substrings-of-a-number/0

Given an integer S represented as a string, the task is to get the sum of all possible sub-strings of this string.

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case contains a string S that represents a number.

Output:
For each test case, in a new line, print the required result.

Constraints:
1 <= T <= 100
1 <= S <= 1012

Example:
Input:
2
1234
421

Output:
1670
491

Explanation:
Testcase1:
Sum = 1 + 2 + 3 + 4 + 12 + 23 + 34 + 123 + 234 + 1234
		= 1670

Testcase2:
Sum = 4 + 2 + 1 + 42 + 21 + 421
		= 491

*/

#include<bits/stdc++.h>
#include<iostream>
#define furr ios_base::sync_with_stdio(false); cin.tie(NULL)
#define el "\n"
#define ll long long int
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define u_m unordered_map
#define u_s unordered_set
#define p_q priority_queue
using namespace std;

/*
We can write summation of all substrings on basis of digit at which they are ending in that case,
Sum of all substrings = sumofdigit[0] + sumofdigit[1] + sumofdigit[2] … + sumofdigit[n-1]  where n is length of string.

Where sumofdigit[i] stores sum of all substring ending at ith index digit, in above example,

Example : num = "1234"
sumofdigit[0] = 1 = 1
sumofdigit[1] = 2 + 12  = 14
sumofdigit[2] = 3 + 23  + 123 = 149
sumofdigit[3] = 4 + 34  + 234 + 1234  = 1506
Result = 1670
Now we can get the relation between sumofdigit values and can solve the question iteratively. Each sumofdigit can be represented in terms of previous value as shown below,

For above example,
sumofdigit[3] = 4 + 34 + 234 + 1234
		   = 4 + 30 + 4 + 230 + 4 + 1230 + 4
		   = 4*4 + 10*(3 + 23 +123)
		   = 4*4 + 10*(sumofdigit[2])
In general, 
sumofdigit[i]  =  (i+1)*num[i] + 10*sumofdigit[i-1]
Using above relation we can solve the problem in linear time. 
*/

int main() {
	furr;
	int t; cin>>t;
	while (t--) {
		string s; cin>>s;
		ll n=s.length();
		
		ll dp[n+1]; dp[0]=s[0]-'0';
		ll ans=dp[0];
		for (ll i=1; i<n; i++) {
			dp[i]=(i+1)*(s[i]-'0') + 10*dp[i-1];
			ans+=dp[i];
		}
		cout<<ans<<el;
	}
}