/*
https://practice.geeksforgeeks.org/problems/gold-mine-problem/0/

Given a gold mine (M) of n*m dimensions. Each field in this mine contains a positive integer which is the amount of gold in tons. Initially the miner is at first column but can be at any row. He can move only (right->,right up /,right down\) that is from a given cell, the miner can move to the cell diagonally up towards the right or right or diagonally down towards the right. Your task is to find out maximum amount of gold which he can collect.

Examples:

Input : M[][] = {{1, 3, 3},
				 {2, 1, 4},
				 {0, 6, 4}};
Output : 12 
{(1,0)->(2,1)->(2,2)}

Input: M[][] = {{1, 3, 1, 5},
				{2, 2, 4, 1},
				{5, 0, 2, 3},
				{0, 6, 1, 2}};
Output : 16
(2,0) -> (1,1) -> (1,2) -> (0,3) OR
(2,0) -> (3,1) -> (2,2) -> (2,3)


Input:
The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. Each test case contains an integer n and m denoting the size of the matrix. Then in the next line are n*m space separated values of the matrix.

Output:
For each test case in a new line print an integer denoting the max gold the miner could collect.

Constraints:
1<=T<=100
1<=n,m<=20
1<=M[][]<=100

Example:
Input:
2
3 3 
1 3 3 2 1 4 0 6 4
2 2
1 2 3 4
Output:
12
7

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

int dp[21][21];
int a[21][21];

// 	=============== BOTTOM UP APPROACH =================
int collect_bottom_up(int R, int C) {
	// R, and C are index of last row and last col;
	R--, C--;
	int dp[R+1][C+1];

	for (int j=C; j>=0; j--) {
		for (int i=R; i>=0; i--) {
			int x=0, y=0, z=0;
			if (i-1>=0 && j+1<=C) x=dp[i-1][j+1];
			if (j+1<=C) y=dp[i][j+1];
			if (i+1<=R && j+1<=C) z=dp[i+1][j+1];
			dp[i][j] = a[i][j] + max(x, max(y,z));
		}
	}

	int ans=0;
	for (int i=0; i<=R; i++)
		ans = max(ans, dp[i][0]);

	return ans;
}


// 	=============== MEMORIZATION APPROACH =================

int collect(int r, int c, int N, int M) {
	if (r>=N || r<0 || c>=M || c<0) return 0;
	if (dp[r][c]!=-1) return dp[r][c];

	int max_ = 0;
	max_=max(max_, collect(r-1,c+1,N,M));
	max_=max(max_, collect(r,c+1,N,M));
	max_=max(max_, collect(r+1,c+1,N,M));
	
	dp[r][c] = a[r][c] + max_;
	return dp[r][c];
}

int collect_recursively(int N, int M) {
	int max_coins=0;
	for (int i=0; i<N; i++) {
		memset(dp, -1, sizeof(dp));
		max_coins = max(max_coins, collect(i, 0, N, M));
	}
	return max_coins;
}

// ================ MAIN FUNCTION ===============
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t; cin>>t;
	while (t--) {
		int n,m; cin>>n>>m;
		for (int i=0; i<n; i++) {
			for (int j=0; j<m; j++)
				cin>>a[i][j];
		}
		// int ans = collect_recursively(n,m);
		int ans = collect_bottom_up(n,m);
		cout << ans << endl;
	}
}