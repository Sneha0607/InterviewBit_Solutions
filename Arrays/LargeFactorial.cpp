/* Large Factorial

Given a number A. Find the fatorial of the number.

Problem Constraints
1 <= A <= 100

Input Format
First and only argument is the integer A.

Output Format
Return a string, the factorial of A.

Example Input
Input 1:
A = 2
Input 2:
A = 3

Example Output
Output 1:
 2
Output 2:
 6
*/

string multiply(string A, string B)
{
	int m = A.size(), n = B.size();
	string res(m+n, '0');
	for(int i=m-1; i>=0; i--)
	{
		for(int j=n-1; j>=0; j--)
		{
			int prod = ((A[i]-'0')*(B[j]-'0')) + (res[i+j+1]-'0');
			res[i+j+1] = prod%10 + '0';
			res[i+j] += prod/10;
		}
	}

	for(int i=0; i<res.size(); i++)
		if(res[i] != '0')
			return res.substr(i);
	return "0";
}

string Solution::solve(int A)
{
	string ans = "1";
	for(int i=2; i<=A; i++)
		ans = multiply(to_string(i), ans);
	return ans;
}