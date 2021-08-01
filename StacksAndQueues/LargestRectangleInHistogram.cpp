/* Largest Rectangle in Histogram
Problem Description

Given an array of integers A .
A represents a histogram i.e A[i] denotes height of the ith histogram's bar. Width of each bar is 1.
Find the area of the largest rectangle formed by the histogram.

Problem Constraints
1 <= |A| <= 100000
1 <= A[i] <= 1000000000
*/

int Solution::largestRectangleArea(vector<int> &height) {
	int n = height.size();
    vector<int> left, right;
    stack<int> s1, s2;
    
    //left
    for(int i=0; i<n; i++)
    {
        if(s1.empty())
            left.push_back(-1);
        else if(!s1.empty() && height[s1.top()] < height[i])
            left.push_back(s1.top());
        else if(!s1.empty() && height[s1.top()] >= height[i])
        {
            while(!s1.empty() && height[s1.top()] >= height[i])
                s1.pop();
            if(s1.empty())
                left.push_back(-1);
            else
                left.push_back(s1.top());
        }
        s1.push(i);
    }
    
    //right
    for(int i=n-1; i>=0; i--)
    {
        if(s2.empty())
            right.push_back(n);
        else if(!s2.empty() && height[s2.top()] < height[i])
            right.push_back(s2.top());
        else if(!s2.empty() && height[s2.top()] >= height[i])
        {
            while(!s2.empty() && height[s2.top()] >= height[i])
                s2.pop();
            if(s2.empty())
                right.push_back(n);
            else
                right.push_back(s2.top());
        }
        s2.push(i);
    }
    
    reverse(right.begin(), right.end());
    
    int area = 0;
    
    for(int i=0; i<n; i++)
    {
        int w = right[i] - left[i] - 1;
        int h = height[i];
        int temp = h*w;
        area = max(area, temp);
    }
    
    return area;
}