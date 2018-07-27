int Solution::search(const vector<int> &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    int len = A.size();
    int low = 0;
    int high = A.size()-1;
    while(low <= high)
    {
        int mid = low + (high - low)/2;
        if(A[mid] == B)
        {
            return mid;
        }
        if(A[low] <= A[mid])
        {
            if(B >= A[low] && B < A[mid])
            {
                high = mid-1;
            }
            else
            {
                low = mid+1;
            }
        }
        else
        {
            if(B > A[mid] && B <= A[high])
            {
                low = mid+1;
            }
            else
            {
                high = mid-1;
            }
        }
    }
    return A[low] == B ? low : -1;
}
