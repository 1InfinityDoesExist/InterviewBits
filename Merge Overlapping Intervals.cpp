/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
vector<Interval> Solution::merge(vector<Interval> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<Interval> ans;
    int len = A.size();
    if(len == 0)
    {
        return ans;
    }
    sort(A.begin(), A.end(), [](Interval const &a, Interval const &b){return a.start < b.start;});
    stack<Interval> s;
    s.push(A[0]);
    for(int iter = 1; iter < A.size(); iter++)
    {
        Interval topper = s.top();
        if(topper.end < A[iter].start)
        {
            s.push(A[iter]);
        }
        else if(topper.end < A[iter].end)
        {
            topper.end = A[iter].end;
            s.pop();
            s.push(topper);
        }
    }
    while(!s.empty())
    {
        ans.push_back(s.top());
        s.pop();
    }
    reverse(ans.begin(), ans.end());
}
