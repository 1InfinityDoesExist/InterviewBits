/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
vector<Interval> Solution::insert(vector<Interval> &intervals, Interval newInterval) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<Interval> ans;
    intervals.push_back(newInterval);
    int len = intervals.size();
    if(len == 0)
    {
        return ans;
    }
    sort(intervals.begin(), intervals.end(), [](Interval const &a, Interval const &b){return a.start < b.start;});
    stack<Interval> s;
    s.push(intervals[0]);
    for(int iter = 1; iter < intervals.size(); iter++)
    {
        Interval topper = s.top();
        if(topper.end < intervals[iter].start)
        {
            s.push(intervals[iter]);
        }
        else if(topper.end < intervals[iter].end)
        {
            topper.end = intervals[iter].end;
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
    return ans;
}
