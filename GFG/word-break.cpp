/*
https://practice.geeksforgeeks.org/problems/word-break/0

Given an input string and a dictionary of words, find out if the input string can be segmented into a space-separated sequence of dictionary words. See following examples for more details.

Consider the following dictionary
{ i, like, sam, sung, samsung, mobile, ice,
  cream, icecream, man, go, mango}

Input:  ilike
Output: Yes
The string can be segmented as "i like".

Input:  ilikesamsung
Output: Yes
The string can be segmented as "i like samsung" or "i like sam sung".

Input:
First line is integer T denoting number of test cases. 1<=T<=100.
Every test case has 3 lines.
First line is N number of words in dictionary. 1<=N<=12.
Second line contains N strings denoting the words of dictionary. Length of each word is less than 15.
Third line contains a string S of length less than 1000.

Output:
Print 1 is possible to break words, else print 0.

Example:
Input:
2
12
i like sam sung samsung mobile ice cream icecream man go mango
ilike
12
i like sam sung samsung mobile ice cream icecream man go mango
idontlike
Output:
1
0

*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool word_break_iterative(vector<string> &dict, string key);
int  word_break_memorization(unordered_set<string> &dict, string key, int n);
bool word_break_dp(unordered_set<string> &dict, string key);

int main()
{
	int t;cin>>t;
	while (t--) {
		int n; cin>>n;
		unordered_set<string> dict;
		string s, key;
		for (int i=0; i<n; i++) {
			cin>>s;
			dict.insert(s);
		}
		cin>>key;
		
		// memset(dp, -1, sizeof(dp));
		// int ans = word_break_memorization(dict, key, 0);
		bool ans = word_break_dp(dict, key);
		cout << ans << endl;
	}
	return 0;
}


// ===================== BOTTOM-UP =======================

bool word_break_dp(unordered_set<string> &dict, string key) {
	bool dp[key.length()+1] = { false };
	dp[0]=true;

	for (int i=1; i<=key.length(); i++) {
		for (int j=0; j<i; j++) {
			string temp = key.substr(j, i-j);
			if (dict.count(temp) && dp[j]==true)
				dp[i] = true;
		}
	}
	return dp[key.length()];
}



// ===================== RECURSION + CACHING ======================
int dp[1002];
int word_break_memorization(unordered_set<string> &dict, string key, int n) {
	if (n >= key.length())
		return 1;
	if (dp[n] != -1)
		return dp[n];

	for (int i=n+1; i<=key.length(); i++) {
		if (dict.count(key.substr(n, i-n))) {
			if (word_break_memorization(dict, key, i))
				return dp[n] = 1;
		}
	}
	return dp[n]=0;
}



/*
=================== ITERATIVE APPROACH ======================

bool word_break_iterative(vector<string> &dict, string key) {

	unordered_map<string, bool> m;
	vector<string>::iterator k;
	int i1=0, i2=0, l=key.length();
	vector<string> found;
	
	for (i1=0; i1<l; ) {
		int currfoundsize = found.size();
		for (i2=i1; i2<l; ) {
			string s = key.substr(i1, i2-i1+1);
			int currfoundsize2 = found.size();
			// if found in the map
			if (m.count(s)) {
				// cout<<"found: "<<s<<" from "<<i1<<" to "<<i2<<endl;
				i2++; i1=i2;
				found.push_back(s);
			}
			else {
				// not found in map
				for (k=dict.begin(); k!=dict.end(); k++) {
					if (*k == s) {
						// cout<<"found: "<<s<<" from "<<i1<<" to "<<i2<<endl;
						found.push_back(s);
						m[s] = true;
						i2++; i1=i2;
					}
				}	 
			}
			// increment only if key not found
			if (found.size() == currfoundsize2) i2++;
		}
		// increment only if key not found
		if (found.size() == currfoundsize) i1++;
	}
	string temp = "";
	// cout << "found vecor: ";
	for (k=found.begin(); k!=found.end(); k++) {
		temp = temp + *k;
		// cout << *k;
	}
	// cout << endl << "temp: "<<temp<< endl;
	return (temp==key);
}

*/