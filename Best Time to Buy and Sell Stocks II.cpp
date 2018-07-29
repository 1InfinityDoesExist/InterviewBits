int Solution::maxProfit(const vector<int> &A)
{
    if(A.size() == 0)
    {
        return 0;
    }
    int ans (0);
    for(int iter = 0; iter < A.size()-1; iter++)
    {
        if(A[iter+1] > A[iter])
        {
            ans = ans + (A[iter+1] - A[iter]);
        }
    }
    return ans;
}
