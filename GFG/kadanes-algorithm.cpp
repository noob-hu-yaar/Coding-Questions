/*
https://practice.geeksforgeeks.org/problems/kadanes-algorithm/0/

Given an array arr of N integers. Find the contiguous sub-array with maximum sum.

Input:
The first line of input contains an integer T denoting the number of test cases. The description of T test cases follows. The first line of each test case contains a single integer N denoting the size of array. The second line contains N space-separated integers A1, A2, ..., AN denoting the elements of the array.

Output:
Print the maximum sum of the contiguous sub-array in a separate line for each test case.

Constraints:
1 ≤ T ≤ 110
1 ≤ N ≤ 106
-107 ≤ A[i] <= 107

Example:
Input
2
5
1 2 3 -2 5
4
-1 -2 -3 -4
Output
9
-1

Explanation:
Testcase 1: Max subarray sum is 9 of elements (1, 2, 3, -2, 5) which is a contiguous subarray.

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
Kadane’s Algorithm:

Initialize:
	max_so_far = INT_MIN;
	max_ending_here = 0

Loop for each element of the array
  (a) max_ending_here = max_ending_here + a[i]
  (b) if(max_so_far < max_ending_here)
			max_so_far = max_ending_here
  (c) if(max_ending_here < 0)
			max_ending_here = 0
return max_so_far
*/

/*
============== ALTERNATE ================
int kadane(int a[], int n) {
	int currmax=a[0], totmax=a[0];
	for (int i=1; i<n; i++) {
		currmax = max(a[i], currmax+a[i]);
		totmax = max(totmax, currmax);
	}
	return totmax;
}
*/
int kadane(int a[], int n) {
	int currmax=0, totmax=INT_MIN;
	for (int i=0; i<n; i++) {
		currmax += a[i];
		totmax = max(totmax, currmax);
		if (currmax < 0)
			currmax = 0;
	}
	return totmax;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t; cin>>t;
	while (t--) {
		int n; cin>>n;
		int a[n];
		for (int i=0; i<n; i++) cin>>a[i];
		cout << kadane(a, n) <<el;
	}
}