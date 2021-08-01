/* Nearest Smaller Element
Given an array, find the nearest smaller element G[i] for every element A[i] in the array such that the element has an index smaller than i.

More formally,

    G[i] for an element A[i] = an element A[j] such that 
    j is maximum possible AND 
    j < i AND
    A[j] < A[i]
Elements for which no smaller element exist, consider next smaller element as -1.
*/

vector<int> Solution::prevSmaller(vector<int> &A) {
    int n = A.size();
    vector<int> ans;
    stack<int> s;
    for(int i=0; i<n; i++)
    {
    	if(s.empty())
    		ans.push_back(-1);
    	else if(!s.empty() && s.top()<A[i])
    		ans.push_back(s.top());
    	else if(!s.empty() && s.top()>=A[i])
    	{
    		while(!s.empty() && s.top()>=A[i])
    			s.pop();
    		if(s.empty())
    			ans.push_back(-1);
    		else
    			ans.push_back(s.top());
    	}
    	s.push(A[i]);
    }
    return ans;
}