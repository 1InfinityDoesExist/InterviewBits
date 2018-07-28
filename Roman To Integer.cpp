int Solution::romanToInt(string A) {
    map<char, int > mp;
    mp['I'] = 1;
    mp['V'] = 5;
    mp['X'] = 10;
    mp['L'] = 50;
    mp['C'] = 100;
    mp['D'] = 500;
    mp['M'] = 1000;

    int ans = 0;
    for(string::size_type iter = 0; iter < A.length()-1; iter++)
    {
        if(mp[A[iter]] >= mp[A[iter+1]])
        {
            ans = ans + mp[A[iter]];
        }
        else
        {
            ans = ans - mp[A[iter]];
        }
    }
    ans = ans + mp[A[A.length()-1]];
    return ans;
}
