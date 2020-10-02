/*
https://practice.geeksforgeeks.org/problems/knapsack-with-duplicate-items/0/

Given weights(wt[]) and values(val[])related to N items and the maximum capacity allowed for these items. What is the maximum value we can achieve if we can pick any weights any number of times for a total allowed weight of W?

Example 1:

Input: N = 2, W = 3
val = {1, 1}
wt = {2, 1}
Output: 3
Explaination: Pick the 2nd element for
three times.
Example 2:

Input: N = 4, W = 8
val = {1, 4, 5, 7}
wt = {1, 3, 4, 5}
Output: 11
Explaination: The optimal choice is to pick the 
2nd and 4th element.
Your Task:
You do not need to read input or print anything. Your task is to complete the function knapSack() which takes the values N, W and the arrays val[] and wt[] as input parameters and returns the maximum possible total value.

Expected Time Complexity: O(N*W)
Expected Auxiliary Space: O(W)

Constraints:
1 ≤ N, W ≤ 1000
1 ≤ val[i], wt[i] ≤ 100

*/

class Solution{
public:
int knapSack(int N, int W, int val[], int wt[])
{
	int dp[N+1][W+1];
	// fill with zero
	for (int i=0; i<=N; i++)
		dp[i][0]=0;

	for (int i=1; i<=W; i++)
		dp[0][i]=0;
	
	int ans;
	for (int i=1; i<=N; i++) {
		for (int j=1; j<=W; j++) {
			// if curr item wt is greater, don't include it
			if (wt[i-1] > j)
				dp[i][j] = dp[i-1][j];
			// else, take max of including it and not includeing it
			else {
				int include = val[i-1] + dp[i][j-wt[i-1]];
				int notinclude = dp[i-1][j];
				dp[i][j] = max(include, notinclude);
			}
		}
	}
	
	return dp[N][W];
}