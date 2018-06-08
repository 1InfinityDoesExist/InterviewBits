//int x[] = {-1, -1, -1, 0, 0, 1, 1, 1};
//int y[] = {-1, 0, 1, -1, 1, -1, 0, 1};

int x[] = {0, 1, 0, -1};
int y[] = {-1, 0, 1, 0};
bool search_mila(vector<string> &A, int row, int col, string B)
{
  //  cout << row << " " << col << endl;
    if(A[row][col] != B[0])
    {
        return false;
    }
    int k = 1;
    for(int dir = 0; dir < 4; dir++)
    {
        int rd , cd ;
        while( k  < B.length())
        {
             rd = row+x[dir];
             cd = col+y[dir];
            if(rd >= A.size() || rd < 0 || cd < 0 || cd >= A[0].size())
            {
                break;
            }

            if(A[rd][cd] != B[k])
            {
                break;
            }

           row = rd;
           col = cd;
        //   cout << A[row][col] << " ";
           k++;
           dir = 0;
        }
    }
    if( k == B.length())
    {
        return true;
    }

    return false;
}
int Solution::exist(vector<string> &A, string B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    int row = A.size();
    int col = A[0].size();
   // cout << row << " " <<col;
    for(int iter = 0; iter < row; iter++)
    {
        for(int jter = 0; jter < col; jter++)
        {
            if(search_mila(A, iter,jter, B))
            {
                return 1;
            }
        }
    }
    return 0;


}
