/* Max Non Negative SubArray
Problem Description

Given an array of integers, A of length N, find out the maximum sum sub-array of non negative numbers from A.

The sub-array should be contiguous i.e., a sub-array created by choosing the second and fourth element and skipping the third element is invalid.

Maximum sub-array is defined in terms of the sum of the elements in the sub-array.

Find and return the required subarray.

NOTE:  

If there is a tie, then compare with segment's length and return segment which has maximum length.
If there is still a tie, then return the segment with minimum starting index.

Example Input
Input 1:
 A = [1, 2, 5, -7, 2, 3]
Input 2:
 A = [10, -1, 2, 3, -4, 100]

Example Output
Output 1:
 [1, 2, 5]
Output 2:
 [100]
*/

vector<int> Solution::maxset(vector<int> &A)
{
	int i=0, l=0, r=0, L=0, R=0;
	long long int sum = 0, max = -1;

	while(i < A.size())
	{
		if(A[i] >= 0)
		{
			sum += A[i];
			r++;
		}
		else
		{
			l = i+1;
			r = i+1;
			sum = 0;
		}
		if(sum >= max)
		{
			if(R-L < r-l || max<sum)
			{
				R = r;
				L = l;
			}
			else if(l < L)
			{
				R = r;
				L = l;
			}
			max = sum;
		}
		i++;
	}

	vector<int> ans;
	for(int i=L; i<R; i++)
		ans.push_back(A[i]);
	return ans;
}