/* Rotated Sorted Array Search
Given an array of integers A of size N and an integer B.
array A is rotated at some pivot unknown to you beforehand.
(i.e., 0 1 2 4 5 6 7  might become 4 5 6 7 0 1 2 ).
You are given a target value B to search. If found in the array, return its index, otherwise return -1.
You may assume no duplicate exists in the array.
*/

int Solution::search(const vector<int> &A, int B)
{
	int n = A.size();
	int low = 0, high = n-1;
	while(low <= high)
	{
		int mid = low + (high-low)/2;
		if(A[mid] == B)
			return mid;
		else if(A[0] <= A[mid])
		{
			//left part is sorted
			if(A[0]<=B && B<A[mid])
				high = mid-1;
			else
				low = mid+1;
		}
		else
		{
			//right part is sorted
			if(A[mid]<B && B<=A[n-1])
				low = mid+1;
			else
				high = mid-1;
		}
	}
	return -1;
}