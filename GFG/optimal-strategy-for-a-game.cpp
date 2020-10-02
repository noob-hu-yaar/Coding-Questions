/*
https://practice.geeksforgeeks.org/problems/optimal-strategy-for-a-game/0

You are given an array A of size N. The array contains integers and is of even length. The elements of the array represent N coin of values V1, V2, ....Vn. You play against an opponent in an alternating way.

In each turn, a player selects either the first or last coin from the row, removes it from the row permanently, and receives the value of the coin.

You need to determine the maximum possible amouint of money you can win if you go first.

Input:
The first line of input contains T denoting the number of testcases. T testcases follow. Each testcase contains two lines of input. The first line contains N denoting the size of the array. The second line contains N elements of the array.

Output:
For each testcase, in a new line, print the maximum amout.

Constraints:
1 <= T <= 100
2 <= N <= 100
1 <= Ai <= 106

Examples:
Input:
2
4
5 3 7 10
4
8 15 3 7
Output:
15
22

Explanation:
Testcase1: The user collects maximum value as 15(10 + 5)
Testcase2: The user collects maximum value as 22(7 + 15)

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
============ Note: The opponent is as clever as the user. ============

There are two choices:

The user chooses the ‘ith’ coin with value ‘Vi’:
The opponent either chooses (i+1)th coin or jth coin.
The opponent intends to choose the coin which leaves the user with minimum value.
i.e. The user can collect the value Vi + min(F(i+2, j), F(i+1, j-1) ).
coinGame1

The user chooses the ‘jth’ coin with value ‘Vj’:
The opponent either chooses ‘ith’ coin or ‘(j-1)th’ coin.
The opponent intends to choose the coin which leaves the user with minimum value,
i.e. the user can collect the value Vj + min(F(i+1, j-1), F(i, j-2) ).
*/

int dp[101][101];
int c[101]

int play(int start, int end) {
	
	if (end==start)
		return c[start];
	if (end-start == 1)
		return max(c[start], c[end]);
		
	if (dp[start][end] != -1)
		return dp[start][end];
	
	// pick first element or last element, and take max of both
	int v1 = c[start] + min(play(start+2, end), play(start+1, end-1));
	int v2 = c[end] + min(play(start, end-2), play(start+1, end-1));
	
	return dp[start][end] = max(v1, v2);
}


// ================ MORE EFFICIENT ==================
int play(int start, int end, int sum) {
	
	if (end==start)
		return sum-c[start];
	if (end-start == 1)
		return sum-min(c[start], c[end]);
		
	if (dp[start][end] != -1)
		return dp[start][end];
	
	int opp1 = play(start+1, end, sum-c[start]);
	int opp2 = play(start, end-1, sum-c[end]);
	
	dp[start][end] = max(sum-opp1, sum-opp2);
	
	return dp[start][end];
}


int main() {
	furr;
	int t; cin>>t;
	while (t--) {

		int n; cin>>n;
		for (int i=0; i<n; i++)
			cin>>c[i];

		memset(dp, -1, sizeof(dp));
		int sum=0;
		for (int i=0; i<n; i++)
			sum+=c[i];

		cout << play(0, n-1, sum) << el;
	}
}