/*
https://practice.geeksforgeeks.org/problems/high-effort-vs-low-effort0213/1

You are given n days and for each day (di) you can select one of the following options:

perform no task 
perform a high effort task (hi) only if its the first day or if you chose no-task on the previous day
perform a low effort task (li)
Write a program to find the maximum amount of tasks you can perform within these n days. 


Example 1:

Input:
n = 3
hi[] = {2,8,1}
li[] = {1,2,1}
Output: 9
Explanation:
Options on 1st day: hi[0]=8, li[0]=1 or no-task
Select no-task.
Options on 2nd day: hi[1]=8, li[2]=1 or no-task
Select high-effort task as no-task was selected 
the previous day.  
Options on 3rd day: hi[2]=1, li[2]=1 or no-task
Select low-effort task as selecting high-effort 
task is only possible if you chose no-task on 
previous day.

​Example 2:

Input:
n = 5
hi[] = {3,6,8,7,6}
li[] = {1,5,4,5,3}
Output: 20
Explanation: Perform high-effort task on first 
day and low-effort task on all remaining days.
 

Your Task:
You don't need to read input or print anything. Your task is to complete the function maxAmt() which accepts an integer n and two arrays li[] and hi[] as input parameter and returns the maximum amount of tasks you can perform within these n days.


Expected Time Complexity: O(n)
Expected Auxiliary Space: O(n)


Constraints:
1 <= n <= 106

*/


class Solution {
	public:
		int maxAmt(int n , int hi[] , int li[]);
};

// ============== BOTTOM UP DP ==============

int Solution::maxAmt(int n , int hi[] , int li[]) {
	int dp[n][3]={{0}};
	dp[n-1][0] = 0;
	dp[n-1][1] = hi[n-1];
	dp[n-1][2] = li[n-1];
	for (int i=n-2; i>=0; i--) {
		dp[i][0] = max(dp[i+1][0], max(dp[i+1][1], dp[i+1][2]));
		dp[i][1] = hi[i] + max(dp[i+1][0], dp[i+1][2]);
		dp[i][2] = li[i] + max(dp[i+1][0], dp[i+1][2]);
	}
	return max(dp[0][0], max(dp[0][1], dp[0][2]));
}



// ========== ALTERNATE, MORE EFFICIENT ===========

int maxAmt(int n , int hi[] , int li[]) {
	int dp[n];
	// on first day, we can take value from high-effort also. 
	dp[0] = max(hi[0] , li[0]);
	if(n>1)
		dp[1] = max(hi[1],li[1] + dp[0]);
	for(int i = 2;i<n;i++) {
			// taking maximum value of current low-effort plus previous day value and
			//current high effort plus previous to previous day's value
			dp[i] = max(li[i] + dp[i - 1] , hi[i] + dp[i -2]);
		}
	return dp[n-1];	
}



// ================ RECURSIVE ===================

int cal(int n, int hi[], int li[], int pos, int last, int sum) {
	if (pos>=n)
		return sum;
	
	int ans = cal(n,hi,li,pos+1,1,sum);
	if (last==1)
		ans=max(ans, cal(n,hi,li,pos+1,2,sum+hi[pos]));
	ans = max(ans, cal(n,hi,li,pos+1,3,sum+li[pos]));
	return ans;
}