/*
https://practice.geeksforgeeks.org/problems/you-and-your-books/1

You have N stacks of books. Each stack of books has some non zero height Hi equal to the number of books on that stack ( considering all the books are identical and each book has a height of 1 unit ). In one move, you can select any number of consecutive stacks of books such that the height of each selected stack of books Hi <= K . Once such a sequence of stacks is chosen , You can collect any number of books from the chosen sequence of stacks .
What is the maximum number of books that you can collect this way ?

Input:
The first line of input contains an integer T denoting the no of test cases . Then T test cases follow. First line of each test case contains two space separated integers N and K where N is the number of stacks of books. Second line of each test case contains N space separated integers denoting the number of books Hi on each stack.

Output:
For each test case, print the maximum number of books you can collect.

Constraints:
1<=T<=105
1<=N<=105
1<=K<=109
1<=Hi<=109

Example(To be used only for expected output):
Input
2
8 1
3 2 2 3 1 1 1 3
8 2
3 2 2 3 1 1 1 3
 
Output
3
4


Explanation :
For the first test case
N = 8 , K = 1 { 3 2 2 3 1 1 1 3 }
We can collect maximum books from consecutive stacks numbered 5, 6 and 7 having height less than equal to K.

For the second test case
N = 8 , K = 2 { 3 2 2 3 1 1 1 3 }
We can collect maximum books from consecutive stacks numbered 2 and 3 having height less than equal to K.

*/

/* JUST A MODIFICATION OF KADANE'S ALGORITHM */
int max_Books(int a[], int n, int k)
{
	int allmax=0, currmax=0;
	for (int i=0; i<n; i++) {
		if (a[i]>k) {
			currmax=0;
			continue;
		}
		currmax+=a[i];
		if (currmax<0)
			currmax=0;
		allmax = max(allmax, currmax);
	}
	return allmax;
}