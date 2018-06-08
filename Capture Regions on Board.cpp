
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

bool isValid(int x, int y, int row, int col, vector<vector<char> > &board)
{
    if(x < 0 || y < 0 || x >= row || y >= col || board[x][y] == 'X' || board[x][y] == 'O')
    {
        return false;
    }
    return true;
}
void bfs(int iter, int jter, vector<vector<char> > &board)
    {

        if(board.size() == 0)
        {
            return;
        }
        int row = board.size();
        int col = board[0].size();

        queue<pair<int, int> > q;
        q.push(make_pair(iter, jter));
        while(!q.empty())
        {
            pair<int, int> p = q.front();
            q.pop();
            int x = p.first;
            int y = p.second;
            board[x][y] = 'O';
            for(int i = 0; i < 4; i++)
            {
                int new_x = x + dx[i];
                int new_y = y + dy[i];

                if(isValid(new_x, new_y, row, col, board))
                {
                    q.push(make_pair(new_x, new_y));
                }
            }
        }
        return;
    }
void Solution::solve(vector<vector<char> > &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

        if(A.size() == 0)
        {
            return;
        }
        int row = A.size();
        int col = A[0].size();
        for(int iter = 0; iter < row; iter++)
        {
            for(int jter = 0; jter < col; jter++)
            {
                if(A[iter][jter] == 'O')
                {
                    A[iter][jter] = '-';
                }
            }
        }
        //if bas one row ho ya phir bas one col ho.
        if(row == 1 || col == 1)
        {
            for(int iter = 0; iter < row; iter++)
            {
                for(int jter =0; jter < col; jter++)
                {
                    if(A[iter][jter] == '-')
                    {
                        A[iter][jter] = 'O';
                    }
                }
            }
            return;
        }
        //left wala
        for(int iter = 0; iter < row; iter++)
        {
            if(A[iter][0] == '-')
            {
                bfs(iter, 0, A);
            }
        }
        //upper wala
        for(int jter = 1; jter < col; jter++)
        {
            if(A[0][jter] == '-')
            {
                bfs(0, jter, A);
            }
        }
        // right wala
        for(int iter = 1; iter < row; iter++)
        {
            if(A[iter][col-1] == '-')
            {
                bfs(iter, col-1, A);
            }
        }
        // bottom wala
        for(int jter = 1; jter < col-1; jter++)
        {
            if(A[row-1][jter] == '-')
            {
                bfs(row-1, jter, A);
            }
        }
        //converting '-' back to X;
        for(int iter = 0; iter < row; iter++)
        {
            for(int jter = 0; jter < col; jter++)
            {
                if(A[iter][jter] == '-')
                {
                    A[iter][jter] = 'X';
                }
            }
        }
        return;

    }
