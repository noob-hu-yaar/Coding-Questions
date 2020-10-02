/*
https://practice.geeksforgeeks.org/problems/reach-a-given-score/0

Consider a game where a player can score 3 or 5 or 10 points in a move. Given a total score n, find the number of distinct combinations to reach the given score.

Input:
The first line of input contains an integer T denoting the number of test cases. T test cases follow. The first line of each test case is n.

Output:
For each testcase, in a new line, print the number of ways/combinations to reach the given score.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

Constraints:
1 ≤ T ≤ 100
1 ≤ n ≤ 1000

Example:
Input:
3
8
20
13

Output:
1
4
2

Explanation
For 1st example when n = 8
{ 3, 5 } and {5, 3} are the two possible permutations but these represent the same cobmination. Hence output is 1.

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

// just a slight variation of classic coin change problem

int coinchange(int N) {
	int coins[]={3,5,10};
	int dp[N+1]={0};
	dp[0]=1;
	
	for (int i=0; i<3; i++) {
		for (int j=coins[i]; j<=N; j++) {
			// add the result without including curr coin
			dp[j] += dp[j-coins[i]];
		}
	}
	return dp[N];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t; cin>>t;
	while (t--) {
		int n; cin>>n;
		cout<<coinchange(n)<<el;
	}
}