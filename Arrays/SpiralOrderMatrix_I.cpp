/* Spiral Order Matrix I
Given a matrix of m * n elements (m rows, n columns), return all elements of the matrix in spiral order.

Example:

Given the following matrix:

[
    [ 1, 2, 3 ],
    [ 4, 5, 6 ],
    [ 7, 8, 9 ]
]
You should return

[1, 2, 3, 6, 9, 8, 7, 4, 5]
*/

vector<int> Solution::spiralOrder(const vector<vector<int>> &A)
{
	int bottom = A.size()-1, top = 0;
	int right = A[0].size()-1, left = 0;
	int dir = 0;
	vector<int> ans;

	while(top<=bottom && left<=right)
	{
		if(dir == 0)
		{
			for(int i=left; i<=right; i++)
				ans.push_back(A[top][i]);
			top++;
			dir = 1;
		}
		else if(dir == 1)
		{
			for(int i=top; i<=bottom; i++)
				ans.push_back(A[i][right]);
			right--;
			dir = 2;
		}
		else if(dir == 2)
		{
			for(int i=right; i>=left; i--)
				ans.push_back(A[bottom][i]);
			bottom--;
			dir = 3;
		}
		else if(dir == 3)
		{
			for(int i=bottom; i>=top; i--)
				ans.push_back(A[i][left]);
			left++;
			dir = 0;
		}
	}
	return ans;
}