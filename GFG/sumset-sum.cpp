/*
https://practice.geeksforgeeks.org/problems/subset-sum-problem/0/

Given a set of numbers, check whether it can be partitioned into two subsets such that the sum of elements in both subsets is same or not.

Input:
The first line contains an integer 'T' denoting the total number of test cases. Each test case constitutes of two lines. First line contains 'N', representing the number of elements in the set and the second line contains the elements of the set.

Output:
Print YES if the given set can be partioned into two subsets such that the sum of elements in both subsets is equal, else print NO.

Constraints:
1 <= T <= 100
1 <= N <= 100
0 <= arr[i] <= 1000

Example:
Input:
2
4
1 5 11 5
3
1 3 5 

Output:
YES
NO

Explanation:
Testcase 1: There exists two subsets such that {1, 5, 5} and {11}.
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*
=======================================

Approach: For the recursive approach we will consider two cases.

Consider the last element and now the required sum = target sum – value of ‘last’ element and number of elements = total elements – 1
Leave the ‘last’ element and now the required sum = target sum and number of elements = total elements – 1

=======================================
*/

int isSubsetSum(int set[], int n, int sum) {
	bool dp[n+1][sum+1];
	// If sum is 0, then answer is true always
	for (int i=0; i<=n; i++) dp[i][0]=true;
	// If sum is not 0 and set is empty, it is false
	for (int i=1; i<=sum; i++) dp[0][i]=false;

	for (int i=1; i<=n; i++) {
		for (int j=1; j<=sum; j++) {
			// if current element is greater than sum, simply don't include it
			if (set[i-1] > j) {
				dp[i][j] = dp[i-1][j];
			}
			// either include curr ele, or don't. If any condition evaluates to true,
			// it means it is possible
			else {
				dp[i][j] = dp[i-1][j] || dp[i-1][j-set[i-1]];
			}
		}
	}
	return dp[n][sum];
}

int main() {
	int t; cin>>t;
	while (t--) {
		int n; cin>>n;
		int set[n];
		for (int i=0; i<n; i++) cin>>set[i];
		int sum; cin>>sum;
		cout << isSubsetSum(set, n, sum) << endl;
	}
}