/*
https://practice.geeksforgeeks.org/problems/special-matrix/0/

You are given a matrix having N rows and M columns. The special property of this matrix is that some of the cells of this matrix are blocked
i.e. they cannot be reached. Now you have to start from the cell (1,1) and reach the end (N,M) provided during the journey you can move horizontally right from the current cell or vertically down from the current cell.
Can you answer the number of ways you can traverse the matrix obeying the above constraints starting from (1,1) and ending at (N,M).

Output your answer modulo 10^9+7.
 

Input :
The first line contains T, the number of test cases. Then T test cases follow.
Each test case consists of two lines.
The first line contains  three integers N,M and K denoting the number of rows, the number of columns and the number of blocked cells in the matrix respectively. The next line contains space separated 2*K integers denoting the positions of the blocked cells in the form R1 C1 R2 C2 R3 C3…..RK CK.
 

Output :
For each test case output the the number of ways modulo 10^9+7 in a new line.
 

Constraints :
1<=T<=100
1<=N<=1000
1<=M<=1000
1<=K<N*M
1<=Ri<=N
1<=Ci<=M
It is guaranteed that the cell (1,1) will never be blocked.
 

Example
Input
1
3 3 2
1 2 3 2
Output :   
1
 

Explanation :
For the above test case there is only one path from (1,1) to(3,3) which is
(1,1)->(2,1)->(2,2)->(2,3)->(3,3)

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

int M[1001][1001];
int R,C;

int ways() {

	int dp[R+1][C+1];
	int mod=1000000007;

	for (int i=R; i>=0; i--) {
		for (int j=C; j>=0; j--) {
			if (i==R && j==C && M[i][j]!=-1) {
				dp[i][j]=1;
				continue;
			}
			if (M[i][j]==-1)
				dp[i][j]=0;
			else {
				int a=0,b=0;
				if (j+1<=C) a=dp[i][j+1]%mod;
				if (i+1<=R) b=dp[i+1][j]%mod;
				dp[i][j]=(a+b)%mod;
			}
		}
	}
	
	return dp[0][0];
}


int main() {
	furr;
	int t; cin>>t;
	while (t--) {
		int K;
		cin>>R>>C>>K;
		R--, C--;
		memset(M, 0, sizeof(M));
		for (int i=0; i<K; i++) {
			int r,c;
			cin>>r>>c;
			M[r-1][c-1]=-1;
		}
		
		cout << ways() << el;
	}
}