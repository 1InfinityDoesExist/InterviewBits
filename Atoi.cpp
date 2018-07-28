int Solution::atoi(const string A) {
    bool isNeg = false;
    if(A.length() >= 2 && A[0] == '-')
    {
        isNeg = true;
    }
    if(A[0] == ' ')
    {
        return 0;
    }
    if(isNeg)
    {
        string ans = "";
        for(string::size_type iter = 1; iter < A.length(); iter++)
        {
            if(isdigit(A[iter]))
            {
                ans = ans + A[iter];
            }
            else if(A[iter] == ' ')
            {
                if(ans.length() != 0)
                {
                    break;
                }
                else
                {
                    return 0;
                }
            }
            else if(isalpha(A[iter]))
            {
                if(ans.length() != 0)
                {
                    break;
                }
                else
                {
                    return 0;
                }
            }
        }
        if(ans.length() > 9)
        {
            /*reverse(ans.begin(), ans.end());
            string st = "";
            for(int iter = 0; iter < 9; iter++)
            {
                st = st + ans[iter];
            }
            reverse(st.begin(), st.end());
            return stoi(st) * -1;*/
            return INT_MIN;
        }
        else
        {
            return stoi(ans) * -1;
        }
    }
    else
    {
        string ans = "";
        for(string::size_type iter = 0; iter < A.length(); iter++)
        {
            if(isdigit(A[iter]))
            {
                ans = ans + A[iter];
            }
            else if(A[iter] == ' ')
            {
                if(ans.length() != 0)
                {
                    break;
                }
                else
                {
                    return 0;
                }
            }
            else if(isalpha(A[iter]))
            {
                if(ans.length() != 0)
                {
                    break;
                }
                else
                {
                    return 0;
                }
            }
        }
       if(ans.length() > 9)
        {
           /* reverse(ans.begin(), ans.end());
            string st = "";
            for(int iter = 0; iter < 9; iter++)
            {
                st = st + ans[iter];
            }
            reverse(st.begin(), st.end());
            return stoi(st);*/
            return INT_MAX;
        }
        else
        {
            return stoi(ans);
        }
    }
}
