vector<int> Solution::dNums(vector<int> &A, int B)
{
   vector<int> ans;
   map<int, int> mp;
   for(int iter = 0; iter < A.size(); iter++)
   {
       mp[A[iter]]++;
       if(iter-B+1 >= 0)
       {
           ans.emplace_back(mp.size());
           mp[A[iter-B+1]]--;
           if(mp[A[iter-B+1]] == 0)
           {
               mp.erase(A[iter-B+1]);
           }
       }
   }
   return ans;
}
