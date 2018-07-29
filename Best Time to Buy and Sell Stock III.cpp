class Solution {
public:
    int dp[100005][2];

    int maxProfit(vector<int>& prices)
    {
        memset(dp, 0, sizeof(dp));
        for(int iter = 1; iter < prices.size(); iter++)
        {
            for(int jter = iter-1; jter >= 0; jter--)
            {
                dp[iter][0] = max(dp[iter][0], max(dp[jter][0], prices[iter] - prices[jter]));
                if(iter >= 3 && jter >= 1 && dp[jter-1][0] > 0)
                {
                    dp[iter][1] = max(dp[iter][1], max(dp[jter][1], dp[jter-1][0]+prices[iter] - prices[jter]));
                }
            }
        }
        return max(dp[prices.size()-1][0], dp[prices.size()-1][1]);
    }
};
