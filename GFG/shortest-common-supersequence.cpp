/*
https://practice.geeksforgeeks.org/problems/shortest-common-supersequence/0/

Given two strings str1 and str2, find the length of the smallest string which has both, str1 and str2 as its sub-sequences.
Note: str1 and str2 can have both uppercase and lowercase letters.

Input:
The first line of input contains an integer T denoting the number of test cases. Each test case contains two space-separated strings.

Output:
For each testcase, in a new line, output the length of the required string.

Expected Time Complexity: O(Length(str1) * Length(str2)).
Expected Auxiliary Space: O(Length(str1) * Length(str2)).

Constraints:
1 <= T <= 100
1<= |str1|, |str2| <= 100

Example:
Input:
2
abcd xycd
efgh jghi
Output:
6
6
Explanation:
Test Case 1: One of the shortest answer can be abxycd, which is of length 6.
*/

#include<bits/stdc++.h>
#include<iostream>
#define el "\n"
#define ll long long int
#define pb push_back
#define u_m unordered_map
#define u_s unordered_set
#define p_q priority_queue
using namespace std;

/*
Length of Shortest Common Supersequence = ( Length of str1 + Length of str2 ) - Length of Longest Common Subsequence
*/

int dp[101][101];

int lcs(string s1, string s2, int m, int n) {
	
	if (m<0 || n<0) return 0;
	// if result exists already
	if (dp[m][n] != -1) return dp[m][n];
	
	// if last characters are equal
	if (s1[m]==s2[n])
		dp[m][n] = 1 + lcs(s1, s2, m-1, n-1);
	// otherwise
	else {
		dp[m][n] = max(lcs(s1, s2, m-1, n), lcs(s1, s2, m, n-1));
	}
	
	return dp[m][n];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t; cin>>t;
	while (t--) {
		string s1;
		string s2;
		cin>>s1>>s2;
		memset(dp, -1, sizeof(dp));
		int l1 = s1.length();
		int l2 = s2.length();
		int lc = lcs(s1, s2, l1-1, l2-1);
		int ans = l1+l2-lc;
		cout << ans <<el;
	}
}