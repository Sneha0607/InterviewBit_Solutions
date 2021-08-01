/* Rain Water Trapped
Problem Description
Given an integer array A of non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.
Problem Constraints
1 <= |A| <= 100000
*/

int Solution::trap(const vector<int> &A)
{
    int n = A.size();
    int left[n];
    int right[n];
    int ans = 0;
    left[0] = A[0], right[n - 1] = A[n - 1];
    for (int i = 1; i < n; i++)
        left[i] = max(left[i - 1], A[i]);
    for (int i = n - 2; i >= 0; i--)
        right[i] = max(right[i + 1], A[i]);
    for (int i = 0; i < n; i++)
        ans += min(left[i], right[i]) - A[i];
    return ans;
}